; ============================================================
; Section: PSFD_I
; VA: 0x003B58A0 - 0x003B5CC4
; Size: 1060 bytes (1.0 KB)
; Functions: 0
; Instructions: 376
; ============================================================

  0x003B58A0  83ec10                  sub      esp, 0x10                      
  0x003B58A3  53                      push     ebx                            
  0x003B58A4  8b5c241c                mov      ebx, dword ptr [esp + 0x1c]    
  0x003B58A8  8b03                    mov      eax, dword ptr [ebx]           
  0x003B58AA  55                      push     ebp                            
  0x003B58AB  56                      push     esi                            
  0x003B58AC  8b742420                mov      esi, dword ptr [esp + 0x20]    
  0x003B58B0  57                      push     edi                            
  0x003B58B1  8dbe08130000            lea      edi, [esi + 0x1308]            
  0x003B58B7  57                      push     edi                            
  0x003B58B8  68ffffff7f              push     0x7fffffff                     
  0x003B58BD  6a01                    push     1                              
  0x003B58BF  53                      push     ebx                            
  0x003B58C0  897c2420                mov      dword ptr [esp + 0x20], edi    
  0x003B58C4  ff5018                  call     dword ptr [eax + 0x18]         
  0x003B58C7  8b17                    mov      edx, dword ptr [edi]           
  0x003B58C9  8bc2                    mov      eax, edx                       
  0x003B58CB  83e0fc                  and      eax, 0xfffffffc                
  0x003B58CE  0fbe08                  movsx    ecx, byte ptr [eax]            
  0x003B58D1  0fb67801                movzx    edi, byte ptr [eax + 1]        
  0x003B58D5  c1e108                  shl      ecx, 8                         
  0x003B58D8  0bcf                    or       ecx, edi                       
  0x003B58DA  2bd0                    sub      edx, eax                       
  0x003B58DC  c1e203                  shl      edx, 3                         
  0x003B58DF  83c410                  add      esp, 0x10                      
  0x003B58E2  40                      inc      eax                            
  0x003B58E3  0fb67801                movzx    edi, byte ptr [eax + 1]        
  0x003B58E7  c1e108                  shl      ecx, 8                         
  0x003B58EA  0bcf                    or       ecx, edi                       
  0x003B58EC  40                      inc      eax                            
  0x003B58ED  0fb67801                movzx    edi, byte ptr [eax + 1]        
  0x003B58F1  c1e108                  shl      ecx, 8                         
  0x003B58F4  0bcf                    or       ecx, edi                       
  0x003B58F6  40                      inc      eax                            
  0x003B58F7  8bf9                    mov      edi, ecx                       
  0x003B58F9  40                      inc      eax                            
  0x003B58FA  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B58FE  8bca                    mov      ecx, edx                       
  0x003B5900  d3e7                    shl      edi, cl                        
  0x003B5902  0fbe08                  movsx    ecx, byte ptr [eax]            
  0x003B5905  c1e108                  shl      ecx, 8                         
  0x003B5908  0bcd                    or       ecx, ebp                       
  0x003B590A  40                      inc      eax                            
  0x003B590B  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B590F  40                      inc      eax                            
  0x003B5910  c1e108                  shl      ecx, 8                         
  0x003B5913  0bcd                    or       ecx, ebp                       
  0x003B5915  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B5919  40                      inc      eax                            
  0x003B591A  c1e108                  shl      ecx, 8                         
  0x003B591D  0bcd                    or       ecx, ebp                       
  0x003B591F  8be9                    mov      ebp, ecx                       
  0x003B5921  8b8e10130000            mov      ecx, dword ptr [esi + 0x1310]  
  0x003B5927  03d1                    add      edx, ecx                       
  0x003B5929  40                      inc      eax                            
  0x003B592A  83fa20                  cmp      edx, 0x20                      
  0x003B592D  7c2f                    jl       0x3b595e                       
  0x003B592F  83ea20                  sub      edx, 0x20                      
  0x003B5932  8bfd                    mov      edi, ebp                       
  0x003B5934  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B5938  8bca                    mov      ecx, edx                       
  0x003B593A  d3e7                    shl      edi, cl                        
  0x003B593C  0fbe08                  movsx    ecx, byte ptr [eax]            
  0x003B593F  40                      inc      eax                            
  0x003B5940  c1e108                  shl      ecx, 8                         
  0x003B5943  0bcd                    or       ecx, ebp                       
  0x003B5945  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B5949  40                      inc      eax                            
  0x003B594A  c1e108                  shl      ecx, 8                         
  0x003B594D  0bcd                    or       ecx, ebp                       
  0x003B594F  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B5953  40                      inc      eax                            
  0x003B5954  c1e108                  shl      ecx, 8                         
  0x003B5957  0bcd                    or       ecx, ebp                       
  0x003B5959  8be9                    mov      ebp, ecx                       
  0x003B595B  40                      inc      eax                            
  0x003B595C  eb08                    jmp      0x3b5966                       
                                        ; XREF: 0x003B592D (cond_jump), 0x003B5C3F (cond_jump)
  0x003B595E  d3e7                    shl      edi, cl                        
  0x003B5960  eb04                    jmp      0x3b5966                       
                                        ; XREF: 0x003B5B9C (cond_jump)
  0x003B5962  8b5c2428                mov      ebx, dword ptr [esp + 0x28]    
                                        ; XREF: 0x003B595C (jump), 0x003B5960 (jump), 0x003B5C72 (jump)
  0x003B5966  8bcf                    mov      ecx, edi                       
  0x003B5968  c1e909                  shr      ecx, 9                         
  0x003B596B  83fa09                  cmp      edx, 9                         
  0x003B596E  894c2424                mov      dword ptr [esp + 0x24], ecx    
  0x003B5972  7e15                    jle      0x3b5989                       
  0x003B5974  b929000000              mov      ecx, 0x29                      
  0x003B5979  2bca                    sub      ecx, edx                       
  0x003B597B  8bdd                    mov      ebx, ebp                       
  0x003B597D  d3eb                    shr      ebx, cl                        
  0x003B597F  8b4c2424                mov      ecx, dword ptr [esp + 0x24]    
  0x003B5983  0bcb                    or       ecx, ebx                       
  0x003B5985  8b5c2428                mov      ebx, dword ptr [esp + 0x28]    
                                        ; XREF: 0x003B5972 (cond_jump)
  0x003B5989  85c9                    test     ecx, ecx                       
  0x003B598B  0f84ea020000            je       0x3b5c7b                       
  0x003B5991  8b8e34030000            mov      ecx, dword ptr [esi + 0x334]   
  0x003B5997  894c2414                mov      dword ptr [esp + 0x14], ecx    
  0x003B599B  eb03                    jmp      0x3b59a0                       
  0x003B599D  8d4900                  lea      ecx, [ecx]                     
                                        ; XREF: 0x003B599B (jump), 0x003B5A27 (cond_jump), 0x003B5A39 (jump)
  0x003B59A0  8bcf                    mov      ecx, edi                       
  0x003B59A2  c1e914                  shr      ecx, 0x14                      
  0x003B59A5  83fa14                  cmp      edx, 0x14                      
  0x003B59A8  894c2424                mov      dword ptr [esp + 0x24], ecx    
  0x003B59AC  7e11                    jle      0x3b59bf                       
  0x003B59AE  b934000000              mov      ecx, 0x34                      
  0x003B59B3  2bca                    sub      ecx, edx                       
  0x003B59B5  8bdd                    mov      ebx, ebp                       
  0x003B59B7  d3eb                    shr      ebx, cl                        
  0x003B59B9  8b4c2424                mov      ecx, dword ptr [esp + 0x24]    
  0x003B59BD  0bcb                    or       ecx, ebx                       
                                        ; XREF: 0x003B59AC (cond_jump)
  0x003B59BF  f7c100ffffff            test     ecx, 0xffffff00                
  0x003B59C5  7508                    jne      0x3b59cf                       
  0x003B59C7  8b1ddc5df600            mov      ebx, dword ptr [0xf65ddc]      
  0x003B59CD  eb09                    jmp      0x3b59d8                       
                                        ; XREF: 0x003B59C5 (cond_jump)
  0x003B59CF  8b1dbc5df600            mov      ebx, dword ptr [0xf65dbc]      
  0x003B59D5  c1e906                  shr      ecx, 6                         
                                        ; XREF: 0x003B59CD (jump)
  0x003B59D8  0fbf1c4b                movsx    ebx, word ptr [ebx + ecx*2]    
  0x003B59DC  8bcb                    mov      ecx, ebx                       
  0x003B59DE  83e10f                  and      ecx, 0xf                       
  0x003B59E1  03d1                    add      edx, ecx                       
  0x003B59E3  83fa20                  cmp      edx, 0x20                      
  0x003B59E6  7c2f                    jl       0x3b5a17                       
  0x003B59E8  83ea20                  sub      edx, 0x20                      
  0x003B59EB  8bfd                    mov      edi, ebp                       
  0x003B59ED  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B59F1  8bca                    mov      ecx, edx                       
  0x003B59F3  d3e7                    shl      edi, cl                        
  0x003B59F5  0fbe08                  movsx    ecx, byte ptr [eax]            
  0x003B59F8  40                      inc      eax                            
  0x003B59F9  c1e108                  shl      ecx, 8                         
  0x003B59FC  0bcd                    or       ecx, ebp                       
  0x003B59FE  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B5A02  40                      inc      eax                            
  0x003B5A03  c1e108                  shl      ecx, 8                         
  0x003B5A06  0bcd                    or       ecx, ebp                       
  0x003B5A08  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B5A0C  40                      inc      eax                            
  0x003B5A0D  c1e108                  shl      ecx, 8                         
  0x003B5A10  0bcd                    or       ecx, ebp                       
  0x003B5A12  8be9                    mov      ebp, ecx                       
  0x003B5A14  40                      inc      eax                            
  0x003B5A15  eb02                    jmp      0x3b5a19                       
                                        ; XREF: 0x003B59E6 (cond_jump)
  0x003B5A17  d3e7                    shl      edi, cl                        
                                        ; XREF: 0x003B5A15 (jump)
  0x003B5A19  8bcb                    mov      ecx, ebx                       
  0x003B5A1B  c1e902                  shr      ecx, 2                         
  0x003B5A1E  0fb6c9                  movzx    ecx, cl                        
  0x003B5A21  c1e902                  shr      ecx, 2                         
  0x003B5A24  83f922                  cmp      ecx, 0x22                      
  0x003B5A27  0f8473ffffff            je       0x3b59a0                       
  0x003B5A2D  83f923                  cmp      ecx, 0x23                      
  0x003B5A30  750c                    jne      0x3b5a3e                       
  0x003B5A32  83863403000021          add      dword ptr [esi + 0x334], 0x21  
  0x003B5A39  e962ffffff              jmp      0x3b59a0                       
                                        ; XREF: 0x003B5A30 (cond_jump)
  0x003B5A3E  83f924                  cmp      ecx, 0x24                      
  0x003B5A41  0f8430020000            je       0x3b5c77                       
  0x003B5A47  018e34030000            add      dword ptr [esi + 0x334], ecx   
  0x003B5A4D  8b8e34030000            mov      ecx, dword ptr [esi + 0x334]   
  0x003B5A53  c1eb0a                  shr      ebx, 0xa                       
  0x003B5A56  899e44030000            mov      dword ptr [esi + 0x344], ebx   
  0x003B5A5C  3b8e40030000            cmp      ecx, dword ptr [esi + 0x340]   
  0x003B5A62  0f8f0f020000            jg       0x3b5c77                       
  0x003B5A68  2b4c2414                sub      ecx, dword ptr [esp + 0x14]    
  0x003B5A6C  8b9e3c030000            mov      ebx, dword ptr [esi + 0x33c]   
  0x003B5A72  03d9                    add      ebx, ecx                       
  0x003B5A74  894c2424                mov      dword ptr [esp + 0x24], ecx    
  0x003B5A78  8b8ed8010000            mov      ecx, dword ptr [esi + 0x1d8]   
  0x003B5A7E  3bd9                    cmp      ebx, ecx                       
  0x003B5A80  899e3c030000            mov      dword ptr [esi + 0x33c], ebx   
  0x003B5A86  7c22                    jl       0x3b5aaa                       
  0x003B5A88  eb06                    jmp      0x3b5a90                       
  0x003B5A8A  8d9b00000000            lea      ebx, [ebx]                     
                                        ; XREF: 0x003B5A88 (jump), 0x003B5AA8 (cond_jump)
  0x003B5A90  298e3c030000            sub      dword ptr [esi + 0x33c], ecx   
  0x003B5A96  ff8638030000            inc      dword ptr [esi + 0x338]        
  0x003B5A9C  8b9e3c030000            mov      ebx, dword ptr [esi + 0x33c]   
  0x003B5AA2  3b9ed8010000            cmp      ebx, dword ptr [esi + 0x1d8]   
  0x003B5AA8  7de6                    jge      0x3b5a90                       
                                        ; XREF: 0x003B5A86 (cond_jump)
  0x003B5AAA  837c2424fe              cmp      dword ptr [esp + 0x24], -2     
  0x003B5AAF  0f84c2010000            je       0x3b5c77                       
  0x003B5AB5  f6864403000010          test     byte ptr [esi + 0x344], 0x10   
  0x003B5ABC  745d                    je       0x3b5b1b                       
  0x003B5ABE  83fa1b                  cmp      edx, 0x1b                      
  0x003B5AC1  7c47                    jl       0x3b5b0a                       
  0x003B5AC3  83ea1b                  sub      edx, 0x1b                      
  0x003B5AC6  7416                    je       0x3b5ade                       
  0x003B5AC8  b905000000              mov      ecx, 5                         
  0x003B5ACD  2bca                    sub      ecx, edx                       
  0x003B5ACF  8bdd                    mov      ebx, ebp                       
  0x003B5AD1  d3eb                    shr      ebx, cl                        
  0x003B5AD3  8bca                    mov      ecx, edx                       
  0x003B5AD5  0bdf                    or       ebx, edi                       
  0x003B5AD7  c1eb1b                  shr      ebx, 0x1b                      
  0x003B5ADA  d3e5                    shl      ebp, cl                        
  0x003B5ADC  eb05                    jmp      0x3b5ae3                       
                                        ; XREF: 0x003B5AC6 (cond_jump)
  0x003B5ADE  8bdf                    mov      ebx, edi                       
  0x003B5AE0  c1eb1b                  shr      ebx, 0x1b                      
                                        ; XREF: 0x003B5ADC (jump)
  0x003B5AE3  0fbe08                  movsx    ecx, byte ptr [eax]            
  0x003B5AE6  40                      inc      eax                            
  0x003B5AE7  c1e108                  shl      ecx, 8                         
  0x003B5AEA  8bfd                    mov      edi, ebp                       
  0x003B5AEC  0fb628                  movzx    ebp, byte ptr [eax]            
  0x003B5AEF  0bcd                    or       ecx, ebp                       
  0x003B5AF1  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B5AF5  40                      inc      eax                            
  0x003B5AF6  c1e108                  shl      ecx, 8                         
  0x003B5AF9  0bcd                    or       ecx, ebp                       
  0x003B5AFB  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B5AFF  40                      inc      eax                            
  0x003B5B00  c1e108                  shl      ecx, 8                         
  0x003B5B03  0bcd                    or       ecx, ebp                       
  0x003B5B05  8be9                    mov      ebp, ecx                       
  0x003B5B07  40                      inc      eax                            
  0x003B5B08  eb0b                    jmp      0x3b5b15                       
                                        ; XREF: 0x003B5AC1 (cond_jump)
  0x003B5B0A  8bdf                    mov      ebx, edi                       
  0x003B5B0C  83c205                  add      edx, 5                         
  0x003B5B0F  c1eb1b                  shr      ebx, 0x1b                      
  0x003B5B12  c1e705                  shl      edi, 5                         
                                        ; XREF: 0x003B5B08 (jump)
  0x003B5B15  899ee8020000            mov      dword ptr [esi + 0x2e8], ebx   
                                        ; XREF: 0x003B5ABC (cond_jump)
  0x003B5B1B  56                      push     esi                            
  0x003B5B1C  893e                    mov      dword ptr [esi], edi           
  0x003B5B1E  896e04                  mov      dword ptr [esi + 4], ebp       
  0x003B5B21  895608                  mov      dword ptr [esi + 8], edx       
  0x003B5B24  89460c                  mov      dword ptr [esi + 0xc], eax     
  0x003B5B27  ff96c8020000            call     dword ptr [esi + 0x2c8]        
  0x003B5B2D  56                      push     esi                            
  0x003B5B2E  ff96d0020000            call     dword ptr [esi + 0x2d0]        
  0x003B5B34  8b8e24130000            mov      ecx, dword ptr [esi + 0x1324]  
  0x003B5B3A  83c408                  add      esp, 8                         
  0x003B5B3D  49                      dec      ecx                            
  0x003B5B3E  8bc1                    mov      eax, ecx                       
  0x003B5B40  85c0                    test     eax, eax                       
  0x003B5B42  898e24130000            mov      dword ptr [esi + 0x1324], ecx  
  0x003B5B48  7f1c                    jg       0x3b5b66                       
  0x003B5B4A  8b86b4010000            mov      eax, dword ptr [esi + 0x1b4]   
  0x003B5B50  8b96ac010000            mov      edx, dword ptr [esi + 0x1ac]   
  0x003B5B56  50                      push     eax                            
  0x003B5B57  899624130000            mov      dword ptr [esi + 0x1324], edx  
  0x003B5B5D  ff96b0010000            call     dword ptr [esi + 0x1b0]        
  0x003B5B63  83c404                  add      esp, 4                         
                                        ; XREF: 0x003B5B48 (cond_jump)
  0x003B5B66  8b5608                  mov      edx, dword ptr [esi + 8]       
  0x003B5B69  8b460c                  mov      eax, dword ptr [esi + 0xc]     
  0x003B5B6C  8b3e                    mov      edi, dword ptr [esi]           
  0x003B5B6E  8b6e04                  mov      ebp, dword ptr [esi + 4]       
  0x003B5B71  8bca                    mov      ecx, edx                       
  0x003B5B73  83e107                  and      ecx, 7                         
  0x003B5B76  8bda                    mov      ebx, edx                       
  0x003B5B78  2bd9                    sub      ebx, ecx                       
  0x003B5B7A  83c307                  add      ebx, 7                         
  0x003B5B7D  c1fb03                  sar      ebx, 3                         
  0x003B5B80  894c2424                mov      dword ptr [esp + 0x24], ecx    
  0x003B5B84  8b4c2410                mov      ecx, dword ptr [esp + 0x10]    
  0x003B5B88  2b19                    sub      ebx, dword ptr [ecx]           
  0x003B5B8A  8d4c03f8                lea      ecx, [ebx + eax - 8]           
  0x003B5B8E  8b9e0c130000            mov      ebx, dword ptr [esi + 0x130c]  
  0x003B5B94  2bd9                    sub      ebx, ecx                       
  0x003B5B96  81fb00080000            cmp      ebx, 0x800                     
  0x003B5B9C  0f8fc0fdffff            jg       0x3b5962                       
  0x003B5BA2  8b7c2410                mov      edi, dword ptr [esp + 0x10]    
  0x003B5BA6  8d542418                lea      edx, [esp + 0x18]              
  0x003B5BAA  52                      push     edx                            
  0x003B5BAB  57                      push     edi                            
  0x003B5BAC  51                      push     ecx                            
  0x003B5BAD  57                      push     edi                            
  0x003B5BAE  e8bd14f5ff              call     0x307070                       ; -> sub_00307070
  0x003B5BB3  8b5c2438                mov      ebx, dword ptr [esp + 0x38]    
  0x003B5BB7  8b03                    mov      eax, dword ptr [ebx]           
  0x003B5BB9  57                      push     edi                            
  0x003B5BBA  6a00                    push     0                              
  0x003B5BBC  53                      push     ebx                            
  0x003B5BBD  ff5020                  call     dword ptr [eax + 0x20]         
  0x003B5BC0  8b0b                    mov      ecx, dword ptr [ebx]           
  0x003B5BC2  8d542434                lea      edx, [esp + 0x34]              
  0x003B5BC6  52                      push     edx                            
  0x003B5BC7  6a01                    push     1                              
  0x003B5BC9  53                      push     ebx                            
  0x003B5BCA  ff511c                  call     dword ptr [ecx + 0x1c]         
  0x003B5BCD  8b03                    mov      eax, dword ptr [ebx]           
  0x003B5BCF  57                      push     edi                            
  0x003B5BD0  68ffffff7f              push     0x7fffffff                     
  0x003B5BD5  6a01                    push     1                              
  0x003B5BD7  53                      push     ebx                            
  0x003B5BD8  ff5018                  call     dword ptr [eax + 0x18]         
  0x003B5BDB  8b17                    mov      edx, dword ptr [edi]           
  0x003B5BDD  8bc2                    mov      eax, edx                       
  0x003B5BDF  83e0fc                  and      eax, 0xfffffffc                
  0x003B5BE2  0fbe08                  movsx    ecx, byte ptr [eax]            
  0x003B5BE5  0fb67801                movzx    edi, byte ptr [eax + 1]        
  0x003B5BE9  c1e108                  shl      ecx, 8                         
  0x003B5BEC  0bcf                    or       ecx, edi                       
  0x003B5BEE  2bd0                    sub      edx, eax                       
  0x003B5BF0  c1e203                  shl      edx, 3                         
  0x003B5BF3  83c438                  add      esp, 0x38                      
  0x003B5BF6  40                      inc      eax                            
  0x003B5BF7  0fb67801                movzx    edi, byte ptr [eax + 1]        
  0x003B5BFB  c1e108                  shl      ecx, 8                         
  0x003B5BFE  0bcf                    or       ecx, edi                       
  0x003B5C00  40                      inc      eax                            
  0x003B5C01  0fb67801                movzx    edi, byte ptr [eax + 1]        
  0x003B5C05  c1e108                  shl      ecx, 8                         
  0x003B5C08  0bcf                    or       ecx, edi                       
  0x003B5C0A  40                      inc      eax                            
  0x003B5C0B  8bf9                    mov      edi, ecx                       
  0x003B5C0D  40                      inc      eax                            
  0x003B5C0E  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B5C12  8bca                    mov      ecx, edx                       
  0x003B5C14  d3e7                    shl      edi, cl                        
  0x003B5C16  0fbe08                  movsx    ecx, byte ptr [eax]            
  0x003B5C19  c1e108                  shl      ecx, 8                         
  0x003B5C1C  0bcd                    or       ecx, ebp                       
  0x003B5C1E  40                      inc      eax                            
  0x003B5C1F  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B5C23  40                      inc      eax                            
  0x003B5C24  c1e108                  shl      ecx, 8                         
  0x003B5C27  0bcd                    or       ecx, ebp                       
  0x003B5C29  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B5C2D  40                      inc      eax                            
  0x003B5C2E  c1e108                  shl      ecx, 8                         
  0x003B5C31  0bcd                    or       ecx, ebp                       
  0x003B5C33  8be9                    mov      ebp, ecx                       
  0x003B5C35  8b4c2424                mov      ecx, dword ptr [esp + 0x24]    
  0x003B5C39  03d1                    add      edx, ecx                       
  0x003B5C3B  40                      inc      eax                            
  0x003B5C3C  83fa20                  cmp      edx, 0x20                      
  0x003B5C3F  0f8c19fdffff            jl       0x3b595e                       
  0x003B5C45  83ea20                  sub      edx, 0x20                      
  0x003B5C48  8bfd                    mov      edi, ebp                       
  0x003B5C4A  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B5C4E  8bca                    mov      ecx, edx                       
  0x003B5C50  d3e7                    shl      edi, cl                        
  0x003B5C52  0fbe08                  movsx    ecx, byte ptr [eax]            
  0x003B5C55  40                      inc      eax                            
  0x003B5C56  c1e108                  shl      ecx, 8                         
  0x003B5C59  0bcd                    or       ecx, ebp                       
  0x003B5C5B  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B5C5F  40                      inc      eax                            
  0x003B5C60  c1e108                  shl      ecx, 8                         
  0x003B5C63  0bcd                    or       ecx, ebp                       
  0x003B5C65  0fb66801                movzx    ebp, byte ptr [eax + 1]        
  0x003B5C69  40                      inc      eax                            
  0x003B5C6A  c1e108                  shl      ecx, 8                         
  0x003B5C6D  0bcd                    or       ecx, ebp                       
  0x003B5C6F  8be9                    mov      ebp, ecx                       
  0x003B5C71  40                      inc      eax                            
  0x003B5C72  e9effcffff              jmp      0x3b5966                       
                                        ; XREF: 0x003B5A41 (cond_jump), 0x003B5A62 (cond_jump), 0x003B5AAF (cond_jump)
  0x003B5C77  8b5c2428                mov      ebx, dword ptr [esp + 0x28]    
                                        ; XREF: 0x003B598B (cond_jump)
  0x003B5C7B  8b742410                mov      esi, dword ptr [esp + 0x10]    
  0x003B5C7F  8b3e                    mov      edi, dword ptr [esi]           
  0x003B5C81  83c207                  add      edx, 7                         
  0x003B5C84  c1fa03                  sar      edx, 3                         
  0x003B5C87  8d4c2418                lea      ecx, [esp + 0x18]              
  0x003B5C8B  51                      push     ecx                            
  0x003B5C8C  2bd7                    sub      edx, edi                       
  0x003B5C8E  56                      push     esi                            
  0x003B5C8F  8d5402f8                lea      edx, [edx + eax - 8]           
  0x003B5C93  52                      push     edx                            
  0x003B5C94  56                      push     esi                            
  0x003B5C95  e8d613f5ff              call     0x307070                       ; -> sub_00307070
  0x003B5C9A  8b03                    mov      eax, dword ptr [ebx]           
  0x003B5C9C  56                      push     esi                            
  0x003B5C9D  6a00                    push     0                              
  0x003B5C9F  53                      push     ebx                            
  0x003B5CA0  ff5020                  call     dword ptr [eax + 0x20]         
  0x003B5CA3  8b0b                    mov      ecx, dword ptr [ebx]           
  0x003B5CA5  8d542434                lea      edx, [esp + 0x34]              
  0x003B5CA9  52                      push     edx                            
  0x003B5CAA  6a01                    push     1                              
  0x003B5CAC  53                      push     ebx                            
  0x003B5CAD  ff511c                  call     dword ptr [ecx + 0x1c]         
  0x003B5CB0  53                      push     ebx                            
  0x003B5CB1  e84a9af6ff              call     0x31f700                       ; -> sub_0031F700
  0x003B5CB6  83c42c                  add      esp, 0x2c                      
  0x003B5CB9  5f                      pop      edi                            
  0x003B5CBA  5e                      pop      esi                            
  0x003B5CBB  5d                      pop      ebp                            
  0x003B5CBC  5b                      pop      ebx                            
  0x003B5CBD  83c410                  add      esp, 0x10                      
  0x003B5CC0  c3                      ret                                     
  0x003B5CC1  0000                    add      byte ptr [eax], al             
