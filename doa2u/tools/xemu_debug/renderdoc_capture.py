"""
RenderDoc frame capture helper for Burnout 3 running in xemu.

RenderDoc lets us capture the exact GPU command stream for each frame,
showing every draw call, texture binding, render state, and shader.
This is the most powerful tool for understanding the game's rendering pipeline.

## How RenderDoc + xemu Works

xemu has built-in RenderDoc API support (CONFIG_RENDERDOC). When launched
through RenderDoc, xemu's GL renderer inserts debug groups/markers and
supports frame capture at gl_debug_frame_terminator().

## Setup

1. Install RenderDoc: https://renderdoc.org/builds
2. Launch RenderDoc
3. In RenderDoc: File > Launch Application
   - Executable: C:\\emu\\xemu-win-release\\xemu.exe
   - Working Dir: C:\\emu\\xemu-win-release
   - Command line args: -s    (for GDB stub)
4. Click "Launch"
5. Let Burnout 3 boot to gameplay
6. Press F12 (or use Capture Frame button) to capture a frame
7. Double-click the captured frame in RenderDoc to analyze

## What To Look For in the Capture

### Draw Calls
- How many draw calls per frame? (our recomp does ~1400 for track geometry)
- What primitive types? (triangle strips vs triangle lists)
- How many vertices/indices per draw?
- Are there instanced draws?

### Textures
- Which textures are bound for each draw call?
- Are they from Global.txd (HUD/FX) or static.dat (track)?
- What format/dimensions?
- Mipmap levels?

### Render Targets
- Main framebuffer dimensions and format
- Any off-screen render targets (shadow maps, reflections)?
- Depth buffer format and usage

### Render States
- Blend modes (alpha blending for transparency)
- Depth test settings
- Alpha test thresholds
- Stencil operations
- Culling mode (back-face, front-face, none)

### Shaders
- xemu translates NV2A shaders to GLSL
- Vertex shader: transforms, lighting
- Fragment shader: texturing, fog, alpha test

### Matrices
- World/View/Projection matrices
- Are they per-draw-call or set once per frame?

## Automated Analysis

This script parses RenderDoc capture XML exports to extract statistics.

Usage:
    # After capturing a frame in RenderDoc:
    # 1. In RenderDoc: Tools > Export Capture As > XML
    # 2. Run this script:
    py -3 -m tools.xemu_debug.renderdoc_capture analyze <export.xml>

    # Or just use this for the capture workflow guide:
    py -3 -m tools.xemu_debug.renderdoc_capture guide
"""

import os
import sys
import json
import argparse
from pathlib import Path


def print_capture_guide():
    """Print step-by-step RenderDoc capture guide."""
    print("""
=== RenderDoc Frame Capture Guide for Burnout 3 ===

SETUP:
  1. Download RenderDoc from https://renderdoc.org/builds
  2. Install and open RenderDoc

LAUNCH:
  3. In RenderDoc: File > Launch Application
  4. Fill in:
     Executable Path:  C:\\emu\\xemu-win-release\\xemu.exe
     Working Directory: C:\\emu\\xemu-win-release
     Command Line Args: -s
     (the -s enables GDB stub so our debug tools work simultaneously)
  5. Click "Launch"
  6. Wait for Xbox boot animation and game to load

CAPTURE:
  7. Once Burnout 3 is in gameplay (driving), press F12
     - Or click "Capture Frame" in RenderDoc's toolbar
  8. A thumbnail appears in RenderDoc's capture list
  9. Double-click the thumbnail to open the frame analysis

ANALYZE:
  In the frame analysis view:

  [Event Browser]  - Left panel shows every GPU command in order
                   - Look for Draw() calls — these render geometry
                   - Look for ClearRenderTargetView — frame boundaries
                   - Look for SetTexture — texture bindings

  [Pipeline State] - Shows the full GPU state at the selected draw call
                   - Vertex Shader: transformation matrices
                   - Fragment Shader: texturing, blending
                   - Rasterizer: culling, viewport
                   - Output Merger: blend mode, depth test

  [Texture Viewer] - Shows bound textures and render targets
                   - Right-click textures to see format/dimensions
                   - Use "Resource Inspector" for texture lists

  [Mesh Viewer]    - Shows the actual geometry being drawn
                   - Input: pre-transform vertices
                   - Output: post-transform (screen space)

EXPORT:
  For automated analysis with this tool:
  10. In RenderDoc: Tools > Export Capture As > XML
  11. Save as burnout3_frame.xml
  12. Run: py -3 -m tools.xemu_debug.renderdoc_capture analyze burnout3_frame.xml

KEY THINGS TO RECORD:
  - Total draw call count
  - Render target setup (dimensions, format)
  - First draw call's pipeline state (matrices, textures, blend)
  - HUD draw calls (last few in the frame, screen-space geometry)
  - Any multi-pass rendering (same geometry drawn twice with different states)
""")


def analyze_renderdoc_export(xml_path: str):
    """Parse a RenderDoc XML export and extract rendering statistics."""
    try:
        import xml.etree.ElementTree as ET
    except ImportError:
        print("ERROR: xml.etree.ElementTree not available")
        return

    if not os.path.exists(xml_path):
        print(f"ERROR: File not found: {xml_path}")
        return

    print(f"Analyzing RenderDoc export: {xml_path}")
    print(f"File size: {os.path.getsize(xml_path) / 1024:.1f} KB")

    tree = ET.parse(xml_path)
    root = tree.getroot()

    # Count events by type
    event_counts = {}
    draw_calls = []
    textures_seen = set()
    total_vertices = 0
    total_indices = 0

    for event in root.iter():
        tag = event.tag
        event_counts[tag] = event_counts.get(tag, 0) + 1

        # Look for draw-related elements
        if 'draw' in tag.lower() or 'Draw' in tag:
            draw_info = {
                'tag': tag,
                'attribs': dict(event.attrib),
            }
            draw_calls.append(draw_info)

            # Try to extract vertex/index counts
            for attr in ['vertexCount', 'indexCount', 'instanceCount']:
                if attr in event.attrib:
                    val = int(event.attrib[attr])
                    if 'vertex' in attr.lower():
                        total_vertices += val
                    elif 'index' in attr.lower():
                        total_indices += val

    print(f"\n=== Frame Statistics ===")
    print(f"  Total XML elements: {sum(event_counts.values())}")
    print(f"  Draw calls found: {len(draw_calls)}")
    print(f"  Total vertices: {total_vertices}")
    print(f"  Total indices: {total_indices}")

    print(f"\n=== Element Types ===")
    for tag, count in sorted(event_counts.items(), key=lambda x: -x[1])[:20]:
        print(f"  {tag}: {count}")

    if draw_calls:
        print(f"\n=== First 5 Draw Calls ===")
        for i, dc in enumerate(draw_calls[:5]):
            print(f"  [{i}] {dc['tag']}: {dc['attribs']}")

    # Save summary
    summary = {
        'file': xml_path,
        'total_draw_calls': len(draw_calls),
        'total_vertices': total_vertices,
        'total_indices': total_indices,
        'element_counts': event_counts,
        'draw_calls': draw_calls[:50],  # First 50
    }

    out_path = xml_path.replace('.xml', '_analysis.json')
    with open(out_path, 'w') as f:
        json.dump(summary, f, indent=2)
    print(f"\nAnalysis saved to {out_path}")


def check_renderdoc_installed():
    """Check if RenderDoc is installed."""
    common_paths = [
        r"C:\Program Files\RenderDoc",
        r"C:\Program Files (x86)\RenderDoc",
        os.path.expandvars(r"%LOCALAPPDATA%\Programs\RenderDoc"),
    ]
    for p in common_paths:
        if os.path.exists(p):
            print(f"RenderDoc found at: {p}")
            exe = os.path.join(p, "qrenderdoc.exe")
            if os.path.exists(exe):
                return exe
    return None


def launch_renderdoc_with_xemu():
    """Launch RenderDoc with xemu configured."""
    exe = check_renderdoc_installed()
    if not exe:
        print("RenderDoc not found. Please install from https://renderdoc.org/builds")
        print("Then use the manual guide: py -3 -m tools.xemu_debug.renderdoc_capture guide")
        return

    xemu_exe = r"C:\emu\xemu-win-release\xemu.exe"
    if not os.path.exists(xemu_exe):
        print(f"xemu not found at {xemu_exe}")
        return

    print(f"Launching RenderDoc with xemu...")
    print(f"  RenderDoc: {exe}")
    print(f"  xemu: {xemu_exe}")

    # RenderDoc can be launched with a .cap file or command line
    # For now, just open RenderDoc and print instructions
    import subprocess
    subprocess.Popen([exe], cwd=os.path.dirname(exe))
    print()
    print("RenderDoc opened. Now follow the guide:")
    print("  1. File > Launch Application")
    print(f"  2. Executable: {xemu_exe}")
    print(f"  3. Working Dir: {os.path.dirname(xemu_exe)}")
    print("  4. Args: -s")
    print("  5. Launch, boot game, press F12 to capture")


def main():
    parser = argparse.ArgumentParser(description='RenderDoc helper for Burnout 3 in xemu')
    parser.add_argument('command', nargs='?', default='guide',
                        choices=['guide', 'analyze', 'launch', 'check'],
                        help='Command to run')
    parser.add_argument('file', nargs='?', help='XML export file (for analyze)')
    args = parser.parse_args()

    if args.command == 'guide':
        print_capture_guide()
    elif args.command == 'analyze':
        if not args.file:
            print("Usage: py -3 -m tools.xemu_debug.renderdoc_capture analyze <file.xml>")
            sys.exit(1)
        analyze_renderdoc_export(args.file)
    elif args.command == 'launch':
        launch_renderdoc_with_xemu()
    elif args.command == 'check':
        exe = check_renderdoc_installed()
        if not exe:
            print("RenderDoc not installed.")
            print("Download from: https://renderdoc.org/builds")


if __name__ == '__main__':
    main()
