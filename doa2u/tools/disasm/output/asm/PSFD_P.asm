; ============================================================
; Section: PSFD_P
; VA: 0x003B9FA0 - 0x003BA5E0
; Size: 1600 bytes (1.6 KB)
; Functions: 0
; Instructions: 546
; ============================================================

  0x003B9FA0  83ec18                  sub      esp, 0x18                      
  0x003B9FA3  8b442420                mov      eax, dword ptr [esp + 0x20]    
  0x003B9FA7  8b08                    mov      ecx, dword ptr [eax]           
  0x003B9FA9  53                      push     ebx                            
  0x003B9FAA  55                      push     ebp                            
  0x003B9FAB  8b6c2424                mov      ebp, dword ptr [esp + 0x24]    
  0x003B9FAF  56                      push     esi                            
  0x003B9FB0  57                      push     edi                            
  0x003B9FB1  8db508130000            lea      esi, [ebp + 0x1308]            
  0x003B9FB7  56                      push     esi                            
  0x003B9FB8  68ffffff7f              push     0x7fffffff                     
  0x003B9FBD  6a01                    push     1                              
  0x003B9FBF  50                      push     eax                            
  0x003B9FC0  c744242801000000        mov      dword ptr [esp + 0x28], 1      
  0x003B9FC8  89742424                mov      dword ptr [esp + 0x24], esi    
  0x003B9FCC  ff5118                  call     dword ptr [ecx + 0x18]         
  0x003B9FCF  8b3e                    mov      edi, dword ptr [esi]           
  0x003B9FD1  8bf7                    mov      esi, edi                       
  0x003B9FD3  83e6fc                  and      esi, 0xfffffffc                
  0x003B9FD6  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B9FD9  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B9FDD  c1e008                  shl      eax, 8                         
  0x003B9FE0  0bc2                    or       eax, edx                       
  0x003B9FE2  2bfe                    sub      edi, esi                       
  0x003B9FE4  c1e703                  shl      edi, 3                         
  0x003B9FE7  83c410                  add      esp, 0x10                      
  0x003B9FEA  46                      inc      esi                            
  0x003B9FEB  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B9FEF  c1e008                  shl      eax, 8                         
  0x003B9FF2  0bc1                    or       eax, ecx                       
  0x003B9FF4  46                      inc      esi                            
  0x003B9FF5  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B9FF9  c1e008                  shl      eax, 8                         
  0x003B9FFC  0bc2                    or       eax, edx                       
  0x003B9FFE  46                      inc      esi                            
  0x003B9FFF  8bd8                    mov      ebx, eax                       
  0x003BA001  0fbe4601                movsx    eax, byte ptr [esi + 1]        
  0x003BA005  46                      inc      esi                            
  0x003BA006  8bcf                    mov      ecx, edi                       
  0x003BA008  d3e3                    shl      ebx, cl                        
  0x003BA00A  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003BA00E  46                      inc      esi                            
  0x003BA00F  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003BA013  c1e008                  shl      eax, 8                         
  0x003BA016  0bc1                    or       eax, ecx                       
  0x003BA018  46                      inc      esi                            
  0x003BA019  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003BA01D  c1e008                  shl      eax, 8                         
  0x003BA020  0bc2                    or       eax, edx                       
  0x003BA022  46                      inc      esi                            
  0x003BA023  c1e008                  shl      eax, 8                         
  0x003BA026  0bc1                    or       eax, ecx                       
  0x003BA028  8b8d10130000            mov      ecx, dword ptr [ebp + 0x1310]  
  0x003BA02E  03f9                    add      edi, ecx                       
  0x003BA030  8bd0                    mov      edx, eax                       
  0x003BA032  46                      inc      esi                            
  0x003BA033  83ff20                  cmp      edi, 0x20                      
  0x003BA036  8954242c                mov      dword ptr [esp + 0x2c], edx    
  0x003BA03A  7c33                    jl       0x3ba06f                       
  0x003BA03C  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003BA03F  83ef20                  sub      edi, 0x20                      
  0x003BA042  8bda                    mov      ebx, edx                       
  0x003BA044  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003BA048  8bcf                    mov      ecx, edi                       
  0x003BA04A  d3e3                    shl      ebx, cl                        
  0x003BA04C  46                      inc      esi                            
  0x003BA04D  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003BA051  c1e008                  shl      eax, 8                         
  0x003BA054  0bc2                    or       eax, edx                       
  0x003BA056  46                      inc      esi                            
  0x003BA057  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003BA05B  c1e008                  shl      eax, 8                         
  0x003BA05E  0bc1                    or       eax, ecx                       
  0x003BA060  46                      inc      esi                            
  0x003BA061  c1e008                  shl      eax, 8                         
  0x003BA064  0bc2                    or       eax, edx                       
  0x003BA066  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003BA06A  46                      inc      esi                            
  0x003BA06B  8bd0                    mov      edx, eax                       
  0x003BA06D  eb02                    jmp      0x3ba071                       
                                        ; XREF: 0x003BA03A (cond_jump)
  0x003BA06F  d3e3                    shl      ebx, cl                        
                                        ; XREF: 0x003BA06D (jump), 0x003BA57D (jump), 0x003BA590 (jump)
  0x003BA071  8bc3                    mov      eax, ebx                       
  0x003BA073  c1e809                  shr      eax, 9                         
  0x003BA076  83ff09                  cmp      edi, 9                         
  0x003BA079  89442410                mov      dword ptr [esp + 0x10], eax    
  0x003BA07D  7e13                    jle      0x3ba092                       
  0x003BA07F  b929000000              mov      ecx, 0x29                      
  0x003BA084  2bcf                    sub      ecx, edi                       
  0x003BA086  8bc2                    mov      eax, edx                       
  0x003BA088  d3e8                    shr      eax, cl                        
  0x003BA08A  8bc8                    mov      ecx, eax                       
  0x003BA08C  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003BA090  0bc1                    or       eax, ecx                       
                                        ; XREF: 0x003BA07D (cond_jump)
  0x003BA092  85c0                    test     eax, eax                       
  0x003BA094  0f84fb040000            je       0x3ba595                       
  0x003BA09A  8b8534030000            mov      eax, dword ptr [ebp + 0x334]   
  0x003BA0A0  8944241c                mov      dword ptr [esp + 0x1c], eax    
                                        ; XREF: 0x003BA138 (cond_jump), 0x003BA14A (jump)
  0x003BA0A4  8bc3                    mov      eax, ebx                       
  0x003BA0A6  c1e815                  shr      eax, 0x15                      
  0x003BA0A9  83ff15                  cmp      edi, 0x15                      
  0x003BA0AC  7e0f                    jle      0x3ba0bd                       
  0x003BA0AE  b935000000              mov      ecx, 0x35                      
  0x003BA0B3  2bcf                    sub      ecx, edi                       
  0x003BA0B5  d3ea                    shr      edx, cl                        
  0x003BA0B7  0bc2                    or       eax, edx                       
  0x003BA0B9  8b54242c                mov      edx, dword ptr [esp + 0x2c]    
                                        ; XREF: 0x003BA0AC (cond_jump)
  0x003BA0BD  a980ffffff              test     eax, 0xffffff80                
  0x003BA0C2  7510                    jne      0x3ba0d4                       
  0x003BA0C4  8b0d04c2f600            mov      ecx, dword ptr [0xf6c204]      
  0x003BA0CA  0fbf0441                movsx    eax, word ptr [ecx + eax*2]    
  0x003BA0CE  89442410                mov      dword ptr [esp + 0x10], eax    
  0x003BA0D2  eb11                    jmp      0x3ba0e5                       
                                        ; XREF: 0x003BA0C2 (cond_jump)
  0x003BA0D4  8b0d00c2f600            mov      ecx, dword ptr [0xf6c200]      
  0x003BA0DA  c1e806                  shr      eax, 6                         
  0x003BA0DD  0fbf0441                movsx    eax, word ptr [ecx + eax*2]    
  0x003BA0E1  89442410                mov      dword ptr [esp + 0x10], eax    
                                        ; XREF: 0x003BA0D2 (jump)
  0x003BA0E5  8bc8                    mov      ecx, eax                       
  0x003BA0E7  83e10f                  and      ecx, 0xf                       
  0x003BA0EA  03f9                    add      edi, ecx                       
  0x003BA0EC  83ff20                  cmp      edi, 0x20                      
  0x003BA0EF  7c37                    jl       0x3ba128                       
  0x003BA0F1  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003BA0F4  83ef20                  sub      edi, 0x20                      
  0x003BA0F7  8bda                    mov      ebx, edx                       
  0x003BA0F9  8bcf                    mov      ecx, edi                       
  0x003BA0FB  d3e3                    shl      ebx, cl                        
  0x003BA0FD  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003BA101  c1e008                  shl      eax, 8                         
  0x003BA104  46                      inc      esi                            
  0x003BA105  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003BA109  0bc1                    or       eax, ecx                       
  0x003BA10B  46                      inc      esi                            
  0x003BA10C  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003BA110  c1e008                  shl      eax, 8                         
  0x003BA113  0bc2                    or       eax, edx                       
  0x003BA115  46                      inc      esi                            
  0x003BA116  c1e008                  shl      eax, 8                         
  0x003BA119  0bc1                    or       eax, ecx                       
  0x003BA11B  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003BA11F  8bd0                    mov      edx, eax                       
  0x003BA121  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003BA125  46                      inc      esi                            
  0x003BA126  eb02                    jmp      0x3ba12a                       
                                        ; XREF: 0x003BA0EF (cond_jump)
  0x003BA128  d3e3                    shl      ebx, cl                        
                                        ; XREF: 0x003BA126 (jump)
  0x003BA12A  8bc8                    mov      ecx, eax                       
  0x003BA12C  c1e902                  shr      ecx, 2                         
  0x003BA12F  0fb6c9                  movzx    ecx, cl                        
  0x003BA132  c1e902                  shr      ecx, 2                         
  0x003BA135  83f922                  cmp      ecx, 0x22                      
  0x003BA138  0f8466ffffff            je       0x3ba0a4                       
  0x003BA13E  83f923                  cmp      ecx, 0x23                      
  0x003BA141  750c                    jne      0x3ba14f                       
  0x003BA143  83853403000021          add      dword ptr [ebp + 0x334], 0x21  
  0x003BA14A  e955ffffff              jmp      0x3ba0a4                       
                                        ; XREF: 0x003BA141 (cond_jump)
  0x003BA14F  83f924                  cmp      ecx, 0x24                      
  0x003BA152  0f843d040000            je       0x3ba595                       
  0x003BA158  018d34030000            add      dword ptr [ebp + 0x334], ecx   
  0x003BA15E  8b8d34030000            mov      ecx, dword ptr [ebp + 0x334]   
  0x003BA164  c1e80a                  shr      eax, 0xa                       
  0x003BA167  898544030000            mov      dword ptr [ebp + 0x344], eax   
  0x003BA16D  3b8d40030000            cmp      ecx, dword ptr [ebp + 0x340]   
  0x003BA173  0f8f1c040000            jg       0x3ba595                       
  0x003BA179  2b4c241c                sub      ecx, dword ptr [esp + 0x1c]    
  0x003BA17D  8b853c030000            mov      eax, dword ptr [ebp + 0x33c]   
  0x003BA183  03c1                    add      eax, ecx                       
  0x003BA185  894c2410                mov      dword ptr [esp + 0x10], ecx    
  0x003BA189  8bc8                    mov      ecx, eax                       
  0x003BA18B  89853c030000            mov      dword ptr [ebp + 0x33c], eax   
  0x003BA191  8b85d8010000            mov      eax, dword ptr [ebp + 0x1d8]   
  0x003BA197  3bc8                    cmp      ecx, eax                       
  0x003BA199  7c1f                    jl       0x3ba1ba                       
  0x003BA19B  eb03                    jmp      0x3ba1a0                       
  0x003BA19D  8d4900                  lea      ecx, [ecx]                     
                                        ; XREF: 0x003BA19B (jump), 0x003BA1B8 (cond_jump)
  0x003BA1A0  29853c030000            sub      dword ptr [ebp + 0x33c], eax   
  0x003BA1A6  ff8538030000            inc      dword ptr [ebp + 0x338]        
  0x003BA1AC  8b8d3c030000            mov      ecx, dword ptr [ebp + 0x33c]   
  0x003BA1B2  3b8dd8010000            cmp      ecx, dword ptr [ebp + 0x1d8]   
  0x003BA1B8  7de6                    jge      0x3ba1a0                       
                                        ; XREF: 0x003BA199 (cond_jump)
  0x003BA1BA  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003BA1BE  83f8fe                  cmp      eax, -2                        
  0x003BA1C1  0f84ce030000            je       0x3ba595                       
  0x003BA1C7  8b4c2418                mov      ecx, dword ptr [esp + 0x18]    
  0x003BA1CB  85c9                    test     ecx, ecx                       
  0x003BA1CD  7526                    jne      0x3ba1f5                       
  0x003BA1CF  83f801                  cmp      eax, 1                         
  0x003BA1D2  7621                    jbe      0x3ba1f5                       
  0x003BA1D4  50                      push     eax                            
  0x003BA1D5  55                      push     ebp                            
  0x003BA1D6  ff95c4020000            call     dword ptr [ebp + 0x2c4]        
  0x003BA1DC  8d95ec020000            lea      edx, [ebp + 0x2ec]             
  0x003BA1E2  52                      push     edx                            
  0x003BA1E3  e8d8f4ffff              call     0x3b96c0                       ; -> sub_003B96C0
  0x003BA1E8  55                      push     ebp                            
  0x003BA1E9  e8f2f4ffff              call     0x3b96e0                       ; -> sub_003B96E0
  0x003BA1EE  8b54243c                mov      edx, dword ptr [esp + 0x3c]    
  0x003BA1F2  83c410                  add      esp, 0x10                      
                                        ; XREF: 0x003BA1CD (cond_jump), 0x003BA1D2 (cond_jump)
  0x003BA1F5  f6854403000020          test     byte ptr [ebp + 0x344], 0x20   
  0x003BA1FC  7575                    jne      0x3ba273                       
  0x003BA1FE  8bc3                    mov      eax, ebx                       
  0x003BA200  c1e81b                  shr      eax, 0x1b                      
  0x003BA203  83ff1b                  cmp      edi, 0x1b                      
  0x003BA206  89442410                mov      dword ptr [esp + 0x10], eax    
  0x003BA20A  7e13                    jle      0x3ba21f                       
  0x003BA20C  b93b000000              mov      ecx, 0x3b                      
  0x003BA211  2bcf                    sub      ecx, edi                       
  0x003BA213  8bc2                    mov      eax, edx                       
  0x003BA215  d3e8                    shr      eax, cl                        
  0x003BA217  8bc8                    mov      ecx, eax                       
  0x003BA219  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003BA21D  0bc1                    or       eax, ecx                       
                                        ; XREF: 0x003BA20A (cond_jump)
  0x003BA21F  8b0decc1f600            mov      ecx, dword ptr [0xf6c1ec]      
  0x003BA225  0fbf0441                movsx    eax, word ptr [ecx + eax*2]    
  0x003BA229  8bc8                    mov      ecx, eax                       
  0x003BA22B  c1e908                  shr      ecx, 8                         
  0x003BA22E  898d44030000            mov      dword ptr [ebp + 0x344], ecx   
  0x003BA234  0fb6c8                  movzx    ecx, al                        
  0x003BA237  03f9                    add      edi, ecx                       
  0x003BA239  83ff20                  cmp      edi, 0x20                      
  0x003BA23C  7c33                    jl       0x3ba271                       
  0x003BA23E  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003BA241  83ef20                  sub      edi, 0x20                      
  0x003BA244  8bda                    mov      ebx, edx                       
  0x003BA246  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003BA24A  8bcf                    mov      ecx, edi                       
  0x003BA24C  d3e3                    shl      ebx, cl                        
  0x003BA24E  46                      inc      esi                            
  0x003BA24F  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003BA253  c1e008                  shl      eax, 8                         
  0x003BA256  0bc2                    or       eax, edx                       
  0x003BA258  46                      inc      esi                            
  0x003BA259  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003BA25D  c1e008                  shl      eax, 8                         
  0x003BA260  0bc1                    or       eax, ecx                       
  0x003BA262  46                      inc      esi                            
  0x003BA263  c1e008                  shl      eax, 8                         
  0x003BA266  0bc2                    or       eax, edx                       
  0x003BA268  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003BA26C  46                      inc      esi                            
  0x003BA26D  8bd0                    mov      edx, eax                       
  0x003BA26F  eb02                    jmp      0x3ba273                       
                                        ; XREF: 0x003BA23C (cond_jump)
  0x003BA271  d3e3                    shl      ebx, cl                        
                                        ; XREF: 0x003BA1FC (cond_jump), 0x003BA26F (jump)
  0x003BA273  f6854403000010          test     byte ptr [ebp + 0x344], 0x10   
  0x003BA27A  7461                    je       0x3ba2dd                       
  0x003BA27C  83ff1b                  cmp      edi, 0x1b                      
  0x003BA27F  7c4b                    jl       0x3ba2cc                       
  0x003BA281  83ef1b                  sub      edi, 0x1b                      
  0x003BA284  7416                    je       0x3ba29c                       
  0x003BA286  b905000000              mov      ecx, 5                         
  0x003BA28B  2bcf                    sub      ecx, edi                       
  0x003BA28D  8bc2                    mov      eax, edx                       
  0x003BA28F  d3e8                    shr      eax, cl                        
  0x003BA291  8bcf                    mov      ecx, edi                       
  0x003BA293  0bc3                    or       eax, ebx                       
  0x003BA295  c1e81b                  shr      eax, 0x1b                      
  0x003BA298  d3e2                    shl      edx, cl                        
  0x003BA29A  eb05                    jmp      0x3ba2a1                       
                                        ; XREF: 0x003BA284 (cond_jump)
  0x003BA29C  8bc3                    mov      eax, ebx                       
  0x003BA29E  c1e81b                  shr      eax, 0x1b                      
                                        ; XREF: 0x003BA29A (jump)
  0x003BA2A1  0fbe0e                  movsx    ecx, byte ptr [esi]            
  0x003BA2A4  46                      inc      esi                            
  0x003BA2A5  c1e108                  shl      ecx, 8                         
  0x003BA2A8  8bda                    mov      ebx, edx                       
  0x003BA2AA  0fb616                  movzx    edx, byte ptr [esi]            
  0x003BA2AD  0bca                    or       ecx, edx                       
  0x003BA2AF  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003BA2B3  46                      inc      esi                            
  0x003BA2B4  c1e108                  shl      ecx, 8                         
  0x003BA2B7  0bca                    or       ecx, edx                       
  0x003BA2B9  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003BA2BD  46                      inc      esi                            
  0x003BA2BE  c1e108                  shl      ecx, 8                         
  0x003BA2C1  0bca                    or       ecx, edx                       
  0x003BA2C3  894c242c                mov      dword ptr [esp + 0x2c], ecx    
  0x003BA2C7  46                      inc      esi                            
  0x003BA2C8  8bd1                    mov      edx, ecx                       
  0x003BA2CA  eb0b                    jmp      0x3ba2d7                       
                                        ; XREF: 0x003BA27F (cond_jump)
  0x003BA2CC  8bc3                    mov      eax, ebx                       
  0x003BA2CE  83c705                  add      edi, 5                         
  0x003BA2D1  c1e81b                  shr      eax, 0x1b                      
  0x003BA2D4  c1e305                  shl      ebx, 5                         
                                        ; XREF: 0x003BA2CA (jump)
  0x003BA2D7  8985e8020000            mov      dword ptr [ebp + 0x2e8], eax   
                                        ; XREF: 0x003BA27A (cond_jump)
  0x003BA2DD  f6854403000008          test     byte ptr [ebp + 0x344], 8      
  0x003BA2E4  7465                    je       0x3ba34b                       
  0x003BA2E6  8d85fc020000            lea      eax, [ebp + 0x2fc]             
  0x003BA2EC  50                      push     eax                            
  0x003BA2ED  8d8d04030000            lea      ecx, [ebp + 0x304]             
  0x003BA2F3  89750c                  mov      dword ptr [ebp + 0xc], esi     
  0x003BA2F6  51                      push     ecx                            
  0x003BA2F7  8db5ec020000            lea      esi, [ebp + 0x2ec]             
  0x003BA2FD  56                      push     esi                            
  0x003BA2FE  55                      push     ebp                            
  0x003BA2FF  895d00                  mov      dword ptr [ebp], ebx           
  0x003BA302  895504                  mov      dword ptr [ebp + 4], edx       
  0x003BA305  897d08                  mov      dword ptr [ebp + 8], edi       
  0x003BA308  e8f3f3ffff              call     0x3b9700                       ; -> sub_003B9700
  0x003BA30D  8d9500030000            lea      edx, [ebp + 0x300]             
  0x003BA313  52                      push     edx                            
  0x003BA314  89442430                mov      dword ptr [esp + 0x30], eax    
  0x003BA318  8d8508030000            lea      eax, [ebp + 0x308]             
  0x003BA31E  50                      push     eax                            
  0x003BA31F  56                      push     esi                            
  0x003BA320  55                      push     ebp                            
  0x003BA321  e8daf3ffff              call     0x3b9700                       ; -> sub_003B9700
  0x003BA326  8b4d04                  mov      ecx, dword ptr [ebp + 4]       
  0x003BA329  8b5d00                  mov      ebx, dword ptr [ebp]           
  0x003BA32C  8b7d08                  mov      edi, dword ptr [ebp + 8]       
  0x003BA32F  8b750c                  mov      esi, dword ptr [ebp + 0xc]     
  0x003BA332  894c244c                mov      dword ptr [esp + 0x4c], ecx    
  0x003BA336  8b4c243c                mov      ecx, dword ptr [esp + 0x3c]    
  0x003BA33A  83c420                  add      esp, 0x20                      
  0x003BA33D  0bc1                    or       eax, ecx                       
  0x003BA33F  0f8550020000            jne      0x3ba595                       
  0x003BA345  8b54242c                mov      edx, dword ptr [esp + 0x2c]    
  0x003BA349  eb0f                    jmp      0x3ba35a                       
                                        ; XREF: 0x003BA2E4 (cond_jump)
  0x003BA34B  8d85ec020000            lea      eax, [ebp + 0x2ec]             
  0x003BA351  50                      push     eax                            
  0x003BA352  e869f3ffff              call     0x3b96c0                       ; -> sub_003B96C0
  0x003BA357  83c404                  add      esp, 4                         
                                        ; XREF: 0x003BA349 (jump)
  0x003BA35A  f6854403000002          test     byte ptr [ebp + 0x344], 2      
  0x003BA361  747a                    je       0x3ba3dd                       
  0x003BA363  8bc3                    mov      eax, ebx                       
  0x003BA365  c1e817                  shr      eax, 0x17                      
  0x003BA368  83ff17                  cmp      edi, 0x17                      
  0x003BA36B  89442410                mov      dword ptr [esp + 0x10], eax    
  0x003BA36F  7e13                    jle      0x3ba384                       
  0x003BA371  b937000000              mov      ecx, 0x37                      
  0x003BA376  2bcf                    sub      ecx, edi                       
  0x003BA378  8bc2                    mov      eax, edx                       
  0x003BA37A  d3e8                    shr      eax, cl                        
  0x003BA37C  8bc8                    mov      ecx, eax                       
  0x003BA37E  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003BA382  0bc1                    or       eax, ecx                       
                                        ; XREF: 0x003BA36F (cond_jump)
  0x003BA384  8b0d14c2f600            mov      ecx, dword ptr [0xf6c214]      
  0x003BA38A  0fbf0441                movsx    eax, word ptr [ecx + eax*2]    
  0x003BA38E  8bc8                    mov      ecx, eax                       
  0x003BA390  83e1f0                  and      ecx, 0xfffffff0                
  0x003BA393  c1e110                  shl      ecx, 0x10                      
  0x003BA396  898d48030000            mov      dword ptr [ebp + 0x348], ecx   
  0x003BA39C  0fb6c8                  movzx    ecx, al                        
  0x003BA39F  03f9                    add      edi, ecx                       
  0x003BA3A1  83ff20                  cmp      edi, 0x20                      
  0x003BA3A4  7c33                    jl       0x3ba3d9                       
  0x003BA3A6  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003BA3A9  83ef20                  sub      edi, 0x20                      
  0x003BA3AC  8bda                    mov      ebx, edx                       
  0x003BA3AE  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003BA3B2  8bcf                    mov      ecx, edi                       
  0x003BA3B4  d3e3                    shl      ebx, cl                        
  0x003BA3B6  46                      inc      esi                            
  0x003BA3B7  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003BA3BB  c1e008                  shl      eax, 8                         
  0x003BA3BE  0bc2                    or       eax, edx                       
  0x003BA3C0  46                      inc      esi                            
  0x003BA3C1  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003BA3C5  c1e008                  shl      eax, 8                         
  0x003BA3C8  0bc1                    or       eax, ecx                       
  0x003BA3CA  46                      inc      esi                            
  0x003BA3CB  c1e008                  shl      eax, 8                         
  0x003BA3CE  0bc2                    or       eax, edx                       
  0x003BA3D0  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003BA3D4  46                      inc      esi                            
  0x003BA3D5  8bd0                    mov      edx, eax                       
  0x003BA3D7  eb0e                    jmp      0x3ba3e7                       
                                        ; XREF: 0x003BA3A4 (cond_jump)
  0x003BA3D9  d3e3                    shl      ebx, cl                        
  0x003BA3DB  eb0a                    jmp      0x3ba3e7                       
                                        ; XREF: 0x003BA361 (cond_jump)
  0x003BA3DD  c7854803000000000000    mov      dword ptr [ebp + 0x348], 0     
                                        ; XREF: 0x003BA3D7 (jump), 0x003BA3DB (jump)
  0x003BA3E7  f6854403000001          test     byte ptr [ebp + 0x344], 1      
  0x003BA3EE  895d00                  mov      dword ptr [ebp], ebx           
  0x003BA3F1  895504                  mov      dword ptr [ebp + 4], edx       
  0x003BA3F4  897d08                  mov      dword ptr [ebp + 8], edi       
  0x003BA3F7  89750c                  mov      dword ptr [ebp + 0xc], esi     
  0x003BA3FA  7410                    je       0x3ba40c                       
  0x003BA3FC  55                      push     ebp                            
  0x003BA3FD  ff95c8020000            call     dword ptr [ebp + 0x2c8]        
  0x003BA403  55                      push     ebp                            
  0x003BA404  ff95d0020000            call     dword ptr [ebp + 0x2d0]        
  0x003BA40A  eb21                    jmp      0x3ba42d                       
                                        ; XREF: 0x003BA3FA (cond_jump)
  0x003BA40C  8b8548030000            mov      eax, dword ptr [ebp + 0x348]   
  0x003BA412  85c0                    test     eax, eax                       
  0x003BA414  740a                    je       0x3ba420                       
  0x003BA416  55                      push     ebp                            
  0x003BA417  ff95cc020000            call     dword ptr [ebp + 0x2cc]        
  0x003BA41D  83c404                  add      esp, 4                         
                                        ; XREF: 0x003BA414 (cond_jump)
  0x003BA420  55                      push     ebp                            
  0x003BA421  ff95dc020000            call     dword ptr [ebp + 0x2dc]        
  0x003BA427  55                      push     ebp                            
  0x003BA428  e8b3f2ffff              call     0x3b96e0                       ; -> sub_003B96E0
                                        ; XREF: 0x003BA40A (jump)
  0x003BA42D  8b8d24130000            mov      ecx, dword ptr [ebp + 0x1324]  
  0x003BA433  83c408                  add      esp, 8                         
  0x003BA436  49                      dec      ecx                            
  0x003BA437  8bc1                    mov      eax, ecx                       
  0x003BA439  85c0                    test     eax, eax                       
  0x003BA43B  898d24130000            mov      dword ptr [ebp + 0x1324], ecx  
  0x003BA441  7f1c                    jg       0x3ba45f                       
  0x003BA443  8b8db4010000            mov      ecx, dword ptr [ebp + 0x1b4]   
  0x003BA449  8b85ac010000            mov      eax, dword ptr [ebp + 0x1ac]   
  0x003BA44F  51                      push     ecx                            
  0x003BA450  898524130000            mov      dword ptr [ebp + 0x1324], eax  
  0x003BA456  ff95b0010000            call     dword ptr [ebp + 0x1b0]        
  0x003BA45C  83c404                  add      esp, 4                         
                                        ; XREF: 0x003BA441 (cond_jump)
  0x003BA45F  8b7d08                  mov      edi, dword ptr [ebp + 8]       
  0x003BA462  8b5504                  mov      edx, dword ptr [ebp + 4]       
  0x003BA465  8b750c                  mov      esi, dword ptr [ebp + 0xc]     
  0x003BA468  8b5d00                  mov      ebx, dword ptr [ebp]           
  0x003BA46B  8bc7                    mov      eax, edi                       
  0x003BA46D  83e007                  and      eax, 7                         
  0x003BA470  8bcf                    mov      ecx, edi                       
  0x003BA472  2bc8                    sub      ecx, eax                       
  0x003BA474  83c107                  add      ecx, 7                         
  0x003BA477  8954242c                mov      dword ptr [esp + 0x2c], edx    
  0x003BA47B  8944241c                mov      dword ptr [esp + 0x1c], eax    
  0x003BA47F  8b442414                mov      eax, dword ptr [esp + 0x14]    
  0x003BA483  8b10                    mov      edx, dword ptr [eax]           
  0x003BA485  c1f903                  sar      ecx, 3                         
  0x003BA488  2bca                    sub      ecx, edx                       
  0x003BA48A  8b950c130000            mov      edx, dword ptr [ebp + 0x130c]  
  0x003BA490  8d4c31f8                lea      ecx, [ecx + esi - 8]           
  0x003BA494  2bd1                    sub      edx, ecx                       
  0x003BA496  81fa00080000            cmp      edx, 0x800                     
  0x003BA49C  0f8fe2000000            jg       0x3ba584                       
  0x003BA4A2  8d542420                lea      edx, [esp + 0x20]              
  0x003BA4A6  52                      push     edx                            
  0x003BA4A7  50                      push     eax                            
  0x003BA4A8  51                      push     ecx                            
  0x003BA4A9  50                      push     eax                            
  0x003BA4AA  e84103f5ff              call     0x30a7f0                       ; -> sub_0030A7F0
  0x003BA4AF  8b7c2424                mov      edi, dword ptr [esp + 0x24]    
  0x003BA4B3  8b742440                mov      esi, dword ptr [esp + 0x40]    
  0x003BA4B7  8b06                    mov      eax, dword ptr [esi]           
  0x003BA4B9  57                      push     edi                            
  0x003BA4BA  6a00                    push     0                              
  0x003BA4BC  56                      push     esi                            
  0x003BA4BD  ff5020                  call     dword ptr [eax + 0x20]         
  0x003BA4C0  8b0e                    mov      ecx, dword ptr [esi]           
  0x003BA4C2  8d54243c                lea      edx, [esp + 0x3c]              
  0x003BA4C6  52                      push     edx                            
  0x003BA4C7  6a01                    push     1                              
  0x003BA4C9  56                      push     esi                            
  0x003BA4CA  ff511c                  call     dword ptr [ecx + 0x1c]         
  0x003BA4CD  8b06                    mov      eax, dword ptr [esi]           
  0x003BA4CF  57                      push     edi                            
  0x003BA4D0  68ffffff7f              push     0x7fffffff                     
  0x003BA4D5  6a01                    push     1                              
  0x003BA4D7  56                      push     esi                            
  0x003BA4D8  ff5018                  call     dword ptr [eax + 0x18]         
  0x003BA4DB  8b3f                    mov      edi, dword ptr [edi]           
  0x003BA4DD  8bf7                    mov      esi, edi                       
  0x003BA4DF  83e6fc                  and      esi, 0xfffffffc                
  0x003BA4E2  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003BA4E5  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003BA4E9  c1e008                  shl      eax, 8                         
  0x003BA4EC  0bc1                    or       eax, ecx                       
  0x003BA4EE  2bfe                    sub      edi, esi                       
  0x003BA4F0  c1e703                  shl      edi, 3                         
  0x003BA4F3  83c438                  add      esp, 0x38                      
  0x003BA4F6  46                      inc      esi                            
  0x003BA4F7  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003BA4FB  c1e008                  shl      eax, 8                         
  0x003BA4FE  0bc2                    or       eax, edx                       
  0x003BA500  46                      inc      esi                            
  0x003BA501  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003BA505  c1e008                  shl      eax, 8                         
  0x003BA508  0bc1                    or       eax, ecx                       
  0x003BA50A  46                      inc      esi                            
  0x003BA50B  8bd8                    mov      ebx, eax                       
  0x003BA50D  0fbe4601                movsx    eax, byte ptr [esi + 1]        
  0x003BA511  46                      inc      esi                            
  0x003BA512  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003BA516  8bcf                    mov      ecx, edi                       
  0x003BA518  d3e3                    shl      ebx, cl                        
  0x003BA51A  46                      inc      esi                            
  0x003BA51B  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003BA51F  c1e008                  shl      eax, 8                         
  0x003BA522  0bc2                    or       eax, edx                       
  0x003BA524  46                      inc      esi                            
  0x003BA525  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003BA529  c1e008                  shl      eax, 8                         
  0x003BA52C  0bc1                    or       eax, ecx                       
  0x003BA52E  8b4c241c                mov      ecx, dword ptr [esp + 0x1c]    
  0x003BA532  46                      inc      esi                            
  0x003BA533  c1e008                  shl      eax, 8                         
  0x003BA536  0bc2                    or       eax, edx                       
  0x003BA538  03f9                    add      edi, ecx                       
  0x003BA53A  46                      inc      esi                            
  0x003BA53B  83ff20                  cmp      edi, 0x20                      
  0x003BA53E  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003BA542  7c3e                    jl       0x3ba582                       
  0x003BA544  8bd8                    mov      ebx, eax                       
  0x003BA546  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003BA549  83ef20                  sub      edi, 0x20                      
  0x003BA54C  8bcf                    mov      ecx, edi                       
  0x003BA54E  d3e3                    shl      ebx, cl                        
  0x003BA550  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003BA554  46                      inc      esi                            
  0x003BA555  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003BA559  c1e008                  shl      eax, 8                         
  0x003BA55C  0bc1                    or       eax, ecx                       
  0x003BA55E  46                      inc      esi                            
  0x003BA55F  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003BA563  c1e008                  shl      eax, 8                         
  0x003BA566  0bc2                    or       eax, edx                       
  0x003BA568  46                      inc      esi                            
  0x003BA569  c1e008                  shl      eax, 8                         
  0x003BA56C  0bc1                    or       eax, ecx                       
  0x003BA56E  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003BA572  46                      inc      esi                            
  0x003BA573  c744241800000000        mov      dword ptr [esp + 0x18], 0      
  0x003BA57B  8bd0                    mov      edx, eax                       
  0x003BA57D  e9effaffff              jmp      0x3ba071                       
                                        ; XREF: 0x003BA542 (cond_jump)
  0x003BA582  d3e3                    shl      ebx, cl                        
                                        ; XREF: 0x003BA49C (cond_jump)
  0x003BA584  8b54242c                mov      edx, dword ptr [esp + 0x2c]    
  0x003BA588  c744241800000000        mov      dword ptr [esp + 0x18], 0      
  0x003BA590  e9dcfaffff              jmp      0x3ba071                       
                                        ; XREF: 0x003BA094 (cond_jump), 0x003BA152 (cond_jump), 0x003BA173 (cond_jump), 0x003BA1C1 (cond_jump), 0x003BA33F (cond_jump)
  0x003BA595  8b5c2414                mov      ebx, dword ptr [esp + 0x14]    
  0x003BA599  8b2b                    mov      ebp, dword ptr [ebx]           
  0x003BA59B  83c707                  add      edi, 7                         
  0x003BA59E  8d542420                lea      edx, [esp + 0x20]              
  0x003BA5A2  52                      push     edx                            
  0x003BA5A3  c1ff03                  sar      edi, 3                         
  0x003BA5A6  2bfd                    sub      edi, ebp                       
  0x003BA5A8  53                      push     ebx                            
  0x003BA5A9  8d4437f8                lea      eax, [edi + esi - 8]           
  0x003BA5AD  50                      push     eax                            
  0x003BA5AE  53                      push     ebx                            
  0x003BA5AF  e83c02f5ff              call     0x30a7f0                       ; -> sub_0030A7F0
  0x003BA5B4  8b742440                mov      esi, dword ptr [esp + 0x40]    
  0x003BA5B8  8b0e                    mov      ecx, dword ptr [esi]           
  0x003BA5BA  53                      push     ebx                            
  0x003BA5BB  6a00                    push     0                              
  0x003BA5BD  56                      push     esi                            
  0x003BA5BE  ff5120                  call     dword ptr [ecx + 0x20]         
  0x003BA5C1  8b16                    mov      edx, dword ptr [esi]           
  0x003BA5C3  8d44243c                lea      eax, [esp + 0x3c]              
  0x003BA5C7  50                      push     eax                            
  0x003BA5C8  6a01                    push     1                              
  0x003BA5CA  56                      push     esi                            
  0x003BA5CB  ff521c                  call     dword ptr [edx + 0x1c]         
  0x003BA5CE  56                      push     esi                            
  0x003BA5CF  e8fc88f6ff              call     0x322ed0                       ; -> sub_00322ED0
  0x003BA5D4  83c42c                  add      esp, 0x2c                      
  0x003BA5D7  5f                      pop      edi                            
  0x003BA5D8  5e                      pop      esi                            
  0x003BA5D9  5d                      pop      ebp                            
  0x003BA5DA  5b                      pop      ebx                            
  0x003BA5DB  83c418                  add      esp, 0x18                      
  0x003BA5DE  c3                      ret                                     
