; ============================================================
; Section: PSFD_I
; VA: 0x003B9280 - 0x003B96A4
; Size: 1060 bytes (1.0 KB)
; Functions: 0
; Instructions: 376
; ============================================================

  0x003B9280  83ec10                  sub      esp, 0x10                      
  0x003B9283  53                      push     ebx                            
  0x003B9284  8b5c241c                mov      ebx, dword ptr [esp + 0x1c]    
  0x003B9288  8b03                    mov      eax, dword ptr [ebx]           
  0x003B928A  55                      push     ebp                            
  0x003B928B  56                      push     esi                            
  0x003B928C  8b742420                mov      esi, dword ptr [esp + 0x20]    
  0x003B9290  57                      push     edi                            
  0x003B9291  8dbe08130000            lea      edi, [esi + 0x1308]            
  0x003B9297  57                      push     edi                            
  0x003B9298  68ffffff7f              push     0x7fffffff                     
  0x003B929D  6a01                    push     1                              
  0x003B929F  53                      push     ebx                            
  0x003B92A0  897c2420                mov      dword ptr [esp + 0x20], edi    
  0x003B92A4  ff5018                  call     dword ptr [eax + 0x18]         
  0x003B92A7  8b17                    mov      edx, dword ptr [edi]           
  0x003B92A9  8bc2                    mov      eax, edx                       
  0x003B92AB  83e0fc                  and      eax, 0xfffffffc                
  0x003B92AE  0fbe08                  movsx    ecx, byte ptr [eax]            
  0x003B92B1  0fb67801                movzx    edi, byte ptr [eax + 1]        
  0x003B92B5  c1e108                  shl      ecx, 8                         
  0x003B92B8  0bcf                    or       ecx, edi                       
  0x003B92BA  2bd0                    sub      edx, eax                       
  0x003B92BC  c1e203                  shl      edx, 3                         
  0x003B92BF  83c410                  add      esp, 0x10                      
  0x003B92C2  40                      inc      eax                            
  0x003B92C3  0fb67801                movzx    edi, byte ptr [eax + 1]        
  0x003B92C7  c1e108                  shl      ecx, 8                         
  0x003B92CA  0bcf                    or       ecx, edi                       
  0x003B92CC  40                      inc      eax                            
  0x003B92CD  0fb67801                movzx    edi, byte ptr [eax + 1]        
  0x003B92D1  c1e108                  shl      ecx, 8                         
  0x003B92D4  0bcf                    or       ecx, edi                       
  0x003B92D6  40                      inc      eax                            
  0x003B92D7  8bf9                    mov      edi, ecx                       
  0x003B92D9  40                      inc      eax                            
  0x003B92DA  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B92DE  8bca                    mov      ecx, edx                       
  0x003B92E0  d3e7                    shl      edi, cl                        
  0x003B92E2  0fbe08                  movsx    ecx, byte ptr [eax]            
  0x003B92E5  c1e108                  shl      ecx, 8                         
  0x003B92E8  0bcd                    or       ecx, ebp                       
  0x003B92EA  40                      inc      eax                            
  0x003B92EB  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B92EF  40                      inc      eax                            
  0x003B92F0  c1e108                  shl      ecx, 8                         
  0x003B92F3  0bcd                    or       ecx, ebp                       
  0x003B92F5  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B92F9  40                      inc      eax                            
  0x003B92FA  c1e108                  shl      ecx, 8                         
  0x003B92FD  0bcd                    or       ecx, ebp                       
  0x003B92FF  8be9                    mov      ebp, ecx                       
  0x003B9301  8b8e10130000            mov      ecx, dword ptr [esi + 0x1310]  
  0x003B9307  03d1                    add      edx, ecx                       
  0x003B9309  40                      inc      eax                            
  0x003B930A  83fa20                  cmp      edx, 0x20                      
  0x003B930D  7c2f                    jl       0x3b933e                       
  0x003B930F  83ea20                  sub      edx, 0x20                      
  0x003B9312  8bfd                    mov      edi, ebp                       
  0x003B9314  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B9318  8bca                    mov      ecx, edx                       
  0x003B931A  d3e7                    shl      edi, cl                        
  0x003B931C  0fbe08                  movsx    ecx, byte ptr [eax]            
  0x003B931F  40                      inc      eax                            
  0x003B9320  c1e108                  shl      ecx, 8                         
  0x003B9323  0bcd                    or       ecx, ebp                       
  0x003B9325  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B9329  40                      inc      eax                            
  0x003B932A  c1e108                  shl      ecx, 8                         
  0x003B932D  0bcd                    or       ecx, ebp                       
  0x003B932F  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B9333  40                      inc      eax                            
  0x003B9334  c1e108                  shl      ecx, 8                         
  0x003B9337  0bcd                    or       ecx, ebp                       
  0x003B9339  8be9                    mov      ebp, ecx                       
  0x003B933B  40                      inc      eax                            
  0x003B933C  eb08                    jmp      0x3b9346                       
                                        ; XREF: 0x003B930D (cond_jump), 0x003B961F (cond_jump)
  0x003B933E  d3e7                    shl      edi, cl                        
  0x003B9340  eb04                    jmp      0x3b9346                       
                                        ; XREF: 0x003B957C (cond_jump)
  0x003B9342  8b5c2428                mov      ebx, dword ptr [esp + 0x28]    
                                        ; XREF: 0x003B933C (jump), 0x003B9340 (jump), 0x003B9652 (jump)
  0x003B9346  8bcf                    mov      ecx, edi                       
  0x003B9348  c1e909                  shr      ecx, 9                         
  0x003B934B  83fa09                  cmp      edx, 9                         
  0x003B934E  894c2424                mov      dword ptr [esp + 0x24], ecx    
  0x003B9352  7e15                    jle      0x3b9369                       
  0x003B9354  b929000000              mov      ecx, 0x29                      
  0x003B9359  2bca                    sub      ecx, edx                       
  0x003B935B  8bdd                    mov      ebx, ebp                       
  0x003B935D  d3eb                    shr      ebx, cl                        
  0x003B935F  8b4c2424                mov      ecx, dword ptr [esp + 0x24]    
  0x003B9363  0bcb                    or       ecx, ebx                       
  0x003B9365  8b5c2428                mov      ebx, dword ptr [esp + 0x28]    
                                        ; XREF: 0x003B9352 (cond_jump)
  0x003B9369  85c9                    test     ecx, ecx                       
  0x003B936B  0f84ea020000            je       0x3b965b                       
  0x003B9371  8b8e34030000            mov      ecx, dword ptr [esi + 0x334]   
  0x003B9377  894c2414                mov      dword ptr [esp + 0x14], ecx    
  0x003B937B  eb03                    jmp      0x3b9380                       
  0x003B937D  8d4900                  lea      ecx, [ecx]                     
                                        ; XREF: 0x003B937B (jump), 0x003B9407 (cond_jump), 0x003B9419 (jump)
  0x003B9380  8bcf                    mov      ecx, edi                       
  0x003B9382  c1e914                  shr      ecx, 0x14                      
  0x003B9385  83fa14                  cmp      edx, 0x14                      
  0x003B9388  894c2424                mov      dword ptr [esp + 0x24], ecx    
  0x003B938C  7e11                    jle      0x3b939f                       
  0x003B938E  b934000000              mov      ecx, 0x34                      
  0x003B9393  2bca                    sub      ecx, edx                       
  0x003B9395  8bdd                    mov      ebx, ebp                       
  0x003B9397  d3eb                    shr      ebx, cl                        
  0x003B9399  8b4c2424                mov      ecx, dword ptr [esp + 0x24]    
  0x003B939D  0bcb                    or       ecx, ebx                       
                                        ; XREF: 0x003B938C (cond_jump)
  0x003B939F  f7c100ffffff            test     ecx, 0xffffff00                
  0x003B93A5  7508                    jne      0x3b93af                       
  0x003B93A7  8b1d1cc2f600            mov      ebx, dword ptr [0xf6c21c]      
  0x003B93AD  eb09                    jmp      0x3b93b8                       
                                        ; XREF: 0x003B93A5 (cond_jump)
  0x003B93AF  8b1dfcc1f600            mov      ebx, dword ptr [0xf6c1fc]      
  0x003B93B5  c1e906                  shr      ecx, 6                         
                                        ; XREF: 0x003B93AD (jump)
  0x003B93B8  0fbf1c4b                movsx    ebx, word ptr [ebx + ecx*2]    
  0x003B93BC  8bcb                    mov      ecx, ebx                       
  0x003B93BE  83e10f                  and      ecx, 0xf                       
  0x003B93C1  03d1                    add      edx, ecx                       
  0x003B93C3  83fa20                  cmp      edx, 0x20                      
  0x003B93C6  7c2f                    jl       0x3b93f7                       
  0x003B93C8  83ea20                  sub      edx, 0x20                      
  0x003B93CB  8bfd                    mov      edi, ebp                       
  0x003B93CD  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B93D1  8bca                    mov      ecx, edx                       
  0x003B93D3  d3e7                    shl      edi, cl                        
  0x003B93D5  0fbe08                  movsx    ecx, byte ptr [eax]            
  0x003B93D8  40                      inc      eax                            
  0x003B93D9  c1e108                  shl      ecx, 8                         
  0x003B93DC  0bcd                    or       ecx, ebp                       
  0x003B93DE  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B93E2  40                      inc      eax                            
  0x003B93E3  c1e108                  shl      ecx, 8                         
  0x003B93E6  0bcd                    or       ecx, ebp                       
  0x003B93E8  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B93EC  40                      inc      eax                            
  0x003B93ED  c1e108                  shl      ecx, 8                         
  0x003B93F0  0bcd                    or       ecx, ebp                       
  0x003B93F2  8be9                    mov      ebp, ecx                       
  0x003B93F4  40                      inc      eax                            
  0x003B93F5  eb02                    jmp      0x3b93f9                       
                                        ; XREF: 0x003B93C6 (cond_jump)
  0x003B93F7  d3e7                    shl      edi, cl                        
                                        ; XREF: 0x003B93F5 (jump)
  0x003B93F9  8bcb                    mov      ecx, ebx                       
  0x003B93FB  c1e902                  shr      ecx, 2                         
  0x003B93FE  0fb6c9                  movzx    ecx, cl                        
  0x003B9401  c1e902                  shr      ecx, 2                         
  0x003B9404  83f922                  cmp      ecx, 0x22                      
  0x003B9407  0f8473ffffff            je       0x3b9380                       
  0x003B940D  83f923                  cmp      ecx, 0x23                      
  0x003B9410  750c                    jne      0x3b941e                       
  0x003B9412  83863403000021          add      dword ptr [esi + 0x334], 0x21  
  0x003B9419  e962ffffff              jmp      0x3b9380                       
                                        ; XREF: 0x003B9410 (cond_jump)
  0x003B941E  83f924                  cmp      ecx, 0x24                      
  0x003B9421  0f8430020000            je       0x3b9657                       
  0x003B9427  018e34030000            add      dword ptr [esi + 0x334], ecx   
  0x003B942D  8b8e34030000            mov      ecx, dword ptr [esi + 0x334]   
  0x003B9433  c1eb0a                  shr      ebx, 0xa                       
  0x003B9436  899e44030000            mov      dword ptr [esi + 0x344], ebx   
  0x003B943C  3b8e40030000            cmp      ecx, dword ptr [esi + 0x340]   
  0x003B9442  0f8f0f020000            jg       0x3b9657                       
  0x003B9448  2b4c2414                sub      ecx, dword ptr [esp + 0x14]    
  0x003B944C  8b9e3c030000            mov      ebx, dword ptr [esi + 0x33c]   
  0x003B9452  03d9                    add      ebx, ecx                       
  0x003B9454  894c2424                mov      dword ptr [esp + 0x24], ecx    
  0x003B9458  8b8ed8010000            mov      ecx, dword ptr [esi + 0x1d8]   
  0x003B945E  3bd9                    cmp      ebx, ecx                       
  0x003B9460  899e3c030000            mov      dword ptr [esi + 0x33c], ebx   
  0x003B9466  7c22                    jl       0x3b948a                       
  0x003B9468  eb06                    jmp      0x3b9470                       
  0x003B946A  8d9b00000000            lea      ebx, [ebx]                     
                                        ; XREF: 0x003B9468 (jump), 0x003B9488 (cond_jump)
  0x003B9470  298e3c030000            sub      dword ptr [esi + 0x33c], ecx   
  0x003B9476  ff8638030000            inc      dword ptr [esi + 0x338]        
  0x003B947C  8b9e3c030000            mov      ebx, dword ptr [esi + 0x33c]   
  0x003B9482  3b9ed8010000            cmp      ebx, dword ptr [esi + 0x1d8]   
  0x003B9488  7de6                    jge      0x3b9470                       
                                        ; XREF: 0x003B9466 (cond_jump)
  0x003B948A  837c2424fe              cmp      dword ptr [esp + 0x24], -2     
  0x003B948F  0f84c2010000            je       0x3b9657                       
  0x003B9495  f6864403000010          test     byte ptr [esi + 0x344], 0x10   
  0x003B949C  745d                    je       0x3b94fb                       
  0x003B949E  83fa1b                  cmp      edx, 0x1b                      
  0x003B94A1  7c47                    jl       0x3b94ea                       
  0x003B94A3  83ea1b                  sub      edx, 0x1b                      
  0x003B94A6  7416                    je       0x3b94be                       
  0x003B94A8  b905000000              mov      ecx, 5                         
  0x003B94AD  2bca                    sub      ecx, edx                       
  0x003B94AF  8bdd                    mov      ebx, ebp                       
  0x003B94B1  d3eb                    shr      ebx, cl                        
  0x003B94B3  8bca                    mov      ecx, edx                       
  0x003B94B5  0bdf                    or       ebx, edi                       
  0x003B94B7  c1eb1b                  shr      ebx, 0x1b                      
  0x003B94BA  d3e5                    shl      ebp, cl                        
  0x003B94BC  eb05                    jmp      0x3b94c3                       
                                        ; XREF: 0x003B94A6 (cond_jump)
  0x003B94BE  8bdf                    mov      ebx, edi                       
  0x003B94C0  c1eb1b                  shr      ebx, 0x1b                      
                                        ; XREF: 0x003B94BC (jump)
  0x003B94C3  0fbe08                  movsx    ecx, byte ptr [eax]            
  0x003B94C6  40                      inc      eax                            
  0x003B94C7  c1e108                  shl      ecx, 8                         
  0x003B94CA  8bfd                    mov      edi, ebp                       
  0x003B94CC  0fb628                  movzx    ebp, byte ptr [eax]            
  0x003B94CF  0bcd                    or       ecx, ebp                       
  0x003B94D1  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B94D5  40                      inc      eax                            
  0x003B94D6  c1e108                  shl      ecx, 8                         
  0x003B94D9  0bcd                    or       ecx, ebp                       
  0x003B94DB  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B94DF  40                      inc      eax                            
  0x003B94E0  c1e108                  shl      ecx, 8                         
  0x003B94E3  0bcd                    or       ecx, ebp                       
  0x003B94E5  8be9                    mov      ebp, ecx                       
  0x003B94E7  40                      inc      eax                            
  0x003B94E8  eb0b                    jmp      0x3b94f5                       
                                        ; XREF: 0x003B94A1 (cond_jump)
  0x003B94EA  8bdf                    mov      ebx, edi                       
  0x003B94EC  83c205                  add      edx, 5                         
  0x003B94EF  c1eb1b                  shr      ebx, 0x1b                      
  0x003B94F2  c1e705                  shl      edi, 5                         
                                        ; XREF: 0x003B94E8 (jump)
  0x003B94F5  899ee8020000            mov      dword ptr [esi + 0x2e8], ebx   
                                        ; XREF: 0x003B949C (cond_jump)
  0x003B94FB  56                      push     esi                            
  0x003B94FC  893e                    mov      dword ptr [esi], edi           
  0x003B94FE  896e04                  mov      dword ptr [esi + 4], ebp       
  0x003B9501  895608                  mov      dword ptr [esi + 8], edx       
  0x003B9504  89460c                  mov      dword ptr [esi + 0xc], eax     
  0x003B9507  ff96c8020000            call     dword ptr [esi + 0x2c8]        
  0x003B950D  56                      push     esi                            
  0x003B950E  ff96d0020000            call     dword ptr [esi + 0x2d0]        
  0x003B9514  8b8e24130000            mov      ecx, dword ptr [esi + 0x1324]  
  0x003B951A  83c408                  add      esp, 8                         
  0x003B951D  49                      dec      ecx                            
  0x003B951E  8bc1                    mov      eax, ecx                       
  0x003B9520  85c0                    test     eax, eax                       
  0x003B9522  898e24130000            mov      dword ptr [esi + 0x1324], ecx  
  0x003B9528  7f1c                    jg       0x3b9546                       
  0x003B952A  8b86b4010000            mov      eax, dword ptr [esi + 0x1b4]   
  0x003B9530  8b96ac010000            mov      edx, dword ptr [esi + 0x1ac]   
  0x003B9536  50                      push     eax                            
  0x003B9537  899624130000            mov      dword ptr [esi + 0x1324], edx  
  0x003B953D  ff96b0010000            call     dword ptr [esi + 0x1b0]        
  0x003B9543  83c404                  add      esp, 4                         
                                        ; XREF: 0x003B9528 (cond_jump)
  0x003B9546  8b5608                  mov      edx, dword ptr [esi + 8]       
  0x003B9549  8b460c                  mov      eax, dword ptr [esi + 0xc]     
  0x003B954C  8b3e                    mov      edi, dword ptr [esi]           
  0x003B954E  8b6e04                  mov      ebp, dword ptr [esi + 4]       
  0x003B9551  8bca                    mov      ecx, edx                       
  0x003B9553  83e107                  and      ecx, 7                         
  0x003B9556  8bda                    mov      ebx, edx                       
  0x003B9558  2bd9                    sub      ebx, ecx                       
  0x003B955A  83c307                  add      ebx, 7                         
  0x003B955D  c1fb03                  sar      ebx, 3                         
  0x003B9560  894c2424                mov      dword ptr [esp + 0x24], ecx    
  0x003B9564  8b4c2410                mov      ecx, dword ptr [esp + 0x10]    
  0x003B9568  2b19                    sub      ebx, dword ptr [ecx]           
  0x003B956A  8d4c03f8                lea      ecx, [ebx + eax - 8]           
  0x003B956E  8b9e0c130000            mov      ebx, dword ptr [esi + 0x130c]  
  0x003B9574  2bd9                    sub      ebx, ecx                       
  0x003B9576  81fb00080000            cmp      ebx, 0x800                     
  0x003B957C  0f8fc0fdffff            jg       0x3b9342                       
  0x003B9582  8b7c2410                mov      edi, dword ptr [esp + 0x10]    
  0x003B9586  8d542418                lea      edx, [esp + 0x18]              
  0x003B958A  52                      push     edx                            
  0x003B958B  57                      push     edi                            
  0x003B958C  51                      push     ecx                            
  0x003B958D  57                      push     edi                            
  0x003B958E  e85d12f5ff              call     0x30a7f0                       ; -> sub_0030A7F0
  0x003B9593  8b5c2438                mov      ebx, dword ptr [esp + 0x38]    
  0x003B9597  8b03                    mov      eax, dword ptr [ebx]           
  0x003B9599  57                      push     edi                            
  0x003B959A  6a00                    push     0                              
  0x003B959C  53                      push     ebx                            
  0x003B959D  ff5020                  call     dword ptr [eax + 0x20]         
  0x003B95A0  8b0b                    mov      ecx, dword ptr [ebx]           
  0x003B95A2  8d542434                lea      edx, [esp + 0x34]              
  0x003B95A6  52                      push     edx                            
  0x003B95A7  6a01                    push     1                              
  0x003B95A9  53                      push     ebx                            
  0x003B95AA  ff511c                  call     dword ptr [ecx + 0x1c]         
  0x003B95AD  8b03                    mov      eax, dword ptr [ebx]           
  0x003B95AF  57                      push     edi                            
  0x003B95B0  68ffffff7f              push     0x7fffffff                     
  0x003B95B5  6a01                    push     1                              
  0x003B95B7  53                      push     ebx                            
  0x003B95B8  ff5018                  call     dword ptr [eax + 0x18]         
  0x003B95BB  8b17                    mov      edx, dword ptr [edi]           
  0x003B95BD  8bc2                    mov      eax, edx                       
  0x003B95BF  83e0fc                  and      eax, 0xfffffffc                
  0x003B95C2  0fbe08                  movsx    ecx, byte ptr [eax]            
  0x003B95C5  0fb67801                movzx    edi, byte ptr [eax + 1]        
  0x003B95C9  c1e108                  shl      ecx, 8                         
  0x003B95CC  0bcf                    or       ecx, edi                       
  0x003B95CE  2bd0                    sub      edx, eax                       
  0x003B95D0  c1e203                  shl      edx, 3                         
  0x003B95D3  83c438                  add      esp, 0x38                      
  0x003B95D6  40                      inc      eax                            
  0x003B95D7  0fb67801                movzx    edi, byte ptr [eax + 1]        
  0x003B95DB  c1e108                  shl      ecx, 8                         
  0x003B95DE  0bcf                    or       ecx, edi                       
  0x003B95E0  40                      inc      eax                            
  0x003B95E1  0fb67801                movzx    edi, byte ptr [eax + 1]        
  0x003B95E5  c1e108                  shl      ecx, 8                         
  0x003B95E8  0bcf                    or       ecx, edi                       
  0x003B95EA  40                      inc      eax                            
  0x003B95EB  8bf9                    mov      edi, ecx                       
  0x003B95ED  40                      inc      eax                            
  0x003B95EE  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B95F2  8bca                    mov      ecx, edx                       
  0x003B95F4  d3e7                    shl      edi, cl                        
  0x003B95F6  0fbe08                  movsx    ecx, byte ptr [eax]            
  0x003B95F9  c1e108                  shl      ecx, 8                         
  0x003B95FC  0bcd                    or       ecx, ebp                       
  0x003B95FE  40                      inc      eax                            
  0x003B95FF  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B9603  40                      inc      eax                            
  0x003B9604  c1e108                  shl      ecx, 8                         
  0x003B9607  0bcd                    or       ecx, ebp                       
  0x003B9609  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B960D  40                      inc      eax                            
  0x003B960E  c1e108                  shl      ecx, 8                         
  0x003B9611  0bcd                    or       ecx, ebp                       
  0x003B9613  8be9                    mov      ebp, ecx                       
  0x003B9615  8b4c2424                mov      ecx, dword ptr [esp + 0x24]    
  0x003B9619  03d1                    add      edx, ecx                       
  0x003B961B  40                      inc      eax                            
  0x003B961C  83fa20                  cmp      edx, 0x20                      
  0x003B961F  0f8c19fdffff            jl       0x3b933e                       
  0x003B9625  83ea20                  sub      edx, 0x20                      
  0x003B9628  8bfd                    mov      edi, ebp                       
  0x003B962A  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B962E  8bca                    mov      ecx, edx                       
  0x003B9630  d3e7                    shl      edi, cl                        
  0x003B9632  0fbe08                  movsx    ecx, byte ptr [eax]            
  0x003B9635  40                      inc      eax                            
  0x003B9636  c1e108                  shl      ecx, 8                         
  0x003B9639  0bcd                    or       ecx, ebp                       
  0x003B963B  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B963F  40                      inc      eax                            
  0x003B9640  c1e108                  shl      ecx, 8                         
  0x003B9643  0bcd                    or       ecx, ebp                       
  0x003B9645  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B9649  40                      inc      eax                            
  0x003B964A  c1e108                  shl      ecx, 8                         
  0x003B964D  0bcd                    or       ecx, ebp                       
  0x003B964F  8be9                    mov      ebp, ecx                       
  0x003B9651  40                      inc      eax                            
  0x003B9652  e9effcffff              jmp      0x3b9346                       
                                        ; XREF: 0x003B9421 (cond_jump), 0x003B9442 (cond_jump), 0x003B948F (cond_jump)
  0x003B9657  8b5c2428                mov      ebx, dword ptr [esp + 0x28]    
                                        ; XREF: 0x003B936B (cond_jump)
  0x003B965B  8b742410                mov      esi, dword ptr [esp + 0x10]    
  0x003B965F  8b3e                    mov      edi, dword ptr [esi]           
  0x003B9661  83c207                  add      edx, 7                         
  0x003B9664  c1fa03                  sar      edx, 3                         
  0x003B9667  8d4c2418                lea      ecx, [esp + 0x18]              
  0x003B966B  51                      push     ecx                            
  0x003B966C  2bd7                    sub      edx, edi                       
  0x003B966E  56                      push     esi                            
  0x003B966F  8d5402f8                lea      edx, [edx + eax - 8]           
  0x003B9673  52                      push     edx                            
  0x003B9674  56                      push     esi                            
  0x003B9675  e87611f5ff              call     0x30a7f0                       ; -> sub_0030A7F0
  0x003B967A  8b03                    mov      eax, dword ptr [ebx]           
  0x003B967C  56                      push     esi                            
  0x003B967D  6a00                    push     0                              
  0x003B967F  53                      push     ebx                            
  0x003B9680  ff5020                  call     dword ptr [eax + 0x20]         
  0x003B9683  8b0b                    mov      ecx, dword ptr [ebx]           
  0x003B9685  8d542434                lea      edx, [esp + 0x34]              
  0x003B9689  52                      push     edx                            
  0x003B968A  6a01                    push     1                              
  0x003B968C  53                      push     ebx                            
  0x003B968D  ff511c                  call     dword ptr [ecx + 0x1c]         
  0x003B9690  53                      push     ebx                            
  0x003B9691  e83a98f6ff              call     0x322ed0                       ; -> sub_00322ED0
  0x003B9696  83c42c                  add      esp, 0x2c                      
  0x003B9699  5f                      pop      edi                            
  0x003B969A  5e                      pop      esi                            
  0x003B969B  5d                      pop      ebp                            
  0x003B969C  5b                      pop      ebx                            
  0x003B969D  83c410                  add      esp, 0x10                      
  0x003B96A0  c3                      ret                                     
  0x003B96A1  0000                    add      byte ptr [eax], al             
