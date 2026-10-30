# Dead or Alive 2 Ultimate — Static Recompilation for Windows

Translation of the original Xbox binary of Dead or Alive 2 Ultimate into native C
that compiles and runs on Windows as a native x86-64 executable.

**Status:** Work in progress. Matches are now playable in all modes, but there are some bugs and slowdowns.

## Features
- Capped at 60 FPS
- Windowed/Borderless and 4:3/16:9 options
- Internal resolution scaling to 1440p (3x)
- Online matches and leaderboard through [Insignia](https://insignia.live/)

<img width="974" height="582" alt="Screenshot 2026-10-14 214555" src="https://github.com/user-attachments/assets/06569c91-d377-4dd4-b723-37fee6a7d98c" />

## Building

Needs Visual Studio 2022 (C11) and CMake 3.20+.

```bash
cmake -S doa2u -B doa2u/build
cmake --build doa2u/build --config Release --target doa2u
```

The binary lands in `doa2u/build/release/DOA2U.exe`.

## Running

Game files are **not** included. Copy the contents of your legally obtained Dead or Alive 2 Ultimate
disc into an `assets` folder next to `DOA2U.exe` (so that `assets/DOA2.xbe` exists).

Press the **Escape** key to open the overlay menu. This has controller mapping, video, and other settings.
Settings are saved to `doa2u_settings.ini` and `doa2u_input.ini` next to the executable.

## Credits

This project stands on the amazing work of **Ned Heller (sp00nz)**:

- [xboxrecomp](https://github.com/sp00nznet/xboxrecomp) — the static recompilation toolkit this is
  built with: the x86→C lifter, XBE parser, kernel layer, D3D8→D3D11 compat layer, and NV2A
  translator.
- [burnout3](https://github.com/sp00nznet/burnout3) — the first static recompilation of a retail
  original Xbox game, and the reference this port follows. The NV2A→D3D11 push-buffer translator
  comes from it directly.

Also relies on:

- [doa3-recomp](https://github.com/parkerallan/doa3-recomp) — the Dead or Alive 3 static
  recompilation project I made. This builds on: the D3D11 rendering/translation, video playback using pl_mpeg, overlay menu system, etc.
- [Cxbx-Reloaded](https://github.com/Cxbx-Reloaded/Cxbx-Reloaded) — used as a debugging oracle;
  Breakpointing the emulator and diffing its behaviour against ours found most of the bugs.
- [xemu](https://github.com/xemu-project/xemu) — NV2A documentation and the texture unswizzling
  algorithm.
- [Xbox Dev Wiki](https://xboxdevwiki.net) — XBE format, kernel exports, NV2A registers.

## License

Project code is MIT, following xboxrecomp. Dead or Alive 2 Ultimate and its assets are property of
Tecmo / Koei Tecmo; nothing from the game is distributed here. You need your own copy.

## Bugs & Contributing

- Come across any issues? Be sure to open an issue ticket with reproduction steps. Error logs written to `doa2u_log.txt` are also helpful.
- Pull requests are welcome.
