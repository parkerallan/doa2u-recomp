; ============================================================
; Section: PSFD_B
; VA: 0x003B5CE0 - 0x003B65A4
; Size: 2244 bytes (2.2 KB)
; Functions: 4
; Instructions: 788
; ============================================================


; ============================================================
; Function: sub_003B5CE0
; Start: 0x003B5CE0  End: 0x003B5CF3  Size: 19 bytes
; Detection: call_target (confidence: 0.90)
; ============================================================
sub_003B5CE0:
  0x003B5CE0  8b442404                mov      eax, dword ptr [esp + 4]       
  0x003B5CE4  33c9                    xor      ecx, ecx                       
  0x003B5CE6  894810                  mov      dword ptr [eax + 0x10], ecx    
  0x003B5CE9  894814                  mov      dword ptr [eax + 0x14], ecx    
  0x003B5CEC  894818                  mov      dword ptr [eax + 0x18], ecx    
  0x003B5CEF  89481c                  mov      dword ptr [eax + 0x1c], ecx    
  0x003B5CF2  c3                      ret                                     
; end of function
  0x003B5CF3  cc                      int3                                    
  0x003B5CF4  cc                      int3                                    
  0x003B5CF5  cc                      int3                                    
  0x003B5CF6  cc                      int3                                    
  0x003B5CF7  cc                      int3                                    
  0x003B5CF8  cc                      int3                                    
  0x003B5CF9  cc                      int3                                    
  0x003B5CFA  cc                      int3                                    
  0x003B5CFB  cc                      int3                                    
  0x003B5CFC  cc                      int3                                    
  0x003B5CFD  cc                      int3                                    
  0x003B5CFE  cc                      int3                                    
  0x003B5CFF  cc                      int3                                    

; ============================================================
; Function: sub_003B5D00
; Start: 0x003B5D00  End: 0x003B5D1C  Size: 28 bytes
; Detection: call_target (confidence: 0.90)
; ============================================================
sub_003B5D00:
  0x003B5D00  8b442404                mov      eax, dword ptr [esp + 4]       
  0x003B5D04  b900040000              mov      ecx, 0x400                     
  0x003B5D09  89884c030000            mov      dword ptr [eax + 0x34c], ecx   
  0x003B5D0F  898854030000            mov      dword ptr [eax + 0x354], ecx   
  0x003B5D15  898850030000            mov      dword ptr [eax + 0x350], ecx   
  0x003B5D1B  c3                      ret                                     
; end of function
  0x003B5D1C  cc                      int3                                    
  0x003B5D1D  cc                      int3                                    
  0x003B5D1E  cc                      int3                                    
  0x003B5D1F  cc                      int3                                    

; ============================================================
; Function: sub_003B5D20
; Start: 0x003B5D20  End: 0x003B5D69  Size: 73 bytes
; Detection: call_target (confidence: 0.90)
; ============================================================
sub_003B5D20:
  0x003B5D20  83ec08                  sub      esp, 8                         
  0x003B5D23  8b44240c                mov      eax, dword ptr [esp + 0xc]     
  0x003B5D27  8b500c                  mov      edx, dword ptr [eax + 0xc]     
  0x003B5D2A  53                      push     ebx                            
  0x003B5D2B  55                      push     ebp                            
  0x003B5D2C  8b6804                  mov      ebp, dword ptr [eax + 4]       
  0x003B5D2F  56                      push     esi                            
  0x003B5D30  8b7008                  mov      esi, dword ptr [eax + 8]       
  0x003B5D33  57                      push     edi                            
  0x003B5D34  8b38                    mov      edi, dword ptr [eax]           
  0x003B5D36  8bdf                    mov      ebx, edi                       
  0x003B5D38  c1eb15                  shr      ebx, 0x15                      
  0x003B5D3B  83fe15                  cmp      esi, 0x15                      
  0x003B5D3E  c744241400000000        mov      dword ptr [esp + 0x14], 0      
  0x003B5D46  7e11                    jle      0x3b5d59                       
  0x003B5D48  b935000000              mov      ecx, 0x35                      
  0x003B5D4D  2bce                    sub      ecx, esi                       
  0x003B5D4F  8bc5                    mov      eax, ebp                       
  0x003B5D51  d3e8                    shr      eax, cl                        
  0x003B5D53  0bd8                    or       ebx, eax                       
  0x003B5D55  8b44241c                mov      eax, dword ptr [esp + 0x1c]    
                                        ; XREF: 0x003B5D46 (cond_jump)
  0x003B5D59  f7c380ffffff            test     ebx, 0xffffff80                
  0x003B5D5F  7508                    jne      0x3b5d69                       
  0x003B5D61  8b0de05df600            mov      ecx, dword ptr [0xf65de0]      
  0x003B5D67  eb09                    jmp      0x3b5d72                       
; end of function
                                        ; XREF: 0x003B5D5F (cond_jump)
  0x003B5D69  8b0da85df600            mov      ecx, dword ptr [0xf65da8]      
  0x003B5D6F  c1eb06                  shr      ebx, 6                         
                                        ; XREF: 0x003B5D67 (jump)
  0x003B5D72  0fbf0c59                movsx    ecx, word ptr [ecx + ebx*2]    
  0x003B5D76  0fbed9                  movsx    ebx, cl                        
  0x003B5D79  83fb7f                  cmp      ebx, 0x7f                      
  0x003B5D7C  895c241c                mov      dword ptr [esp + 0x1c], ebx    
  0x003B5D80  750d                    jne      0x3b5d8f                       
  0x003B5D82  c7442414ffffffff        mov      dword ptr [esp + 0x14], 0xffffffff 
  0x003B5D8A  e92d010000              jmp      0x3b5ebc                       
                                        ; XREF: 0x003B5D80 (cond_jump)
  0x003B5D8F  c1e908                  shr      ecx, 8                         
  0x003B5D92  0fb6c9                  movzx    ecx, cl                        
  0x003B5D95  03f1                    add      esi, ecx                       
  0x003B5D97  83fe20                  cmp      esi, 0x20                      
  0x003B5D9A  7c2f                    jl       0x3b5dcb                       
  0x003B5D9C  83ee20                  sub      esi, 0x20                      
  0x003B5D9F  8bfd                    mov      edi, ebp                       
  0x003B5DA1  0fb66a01                movzx    ebp, byte ptr [edx + 1]        
  0x003B5DA5  8bce                    mov      ecx, esi                       
  0x003B5DA7  d3e7                    shl      edi, cl                        
  0x003B5DA9  0fbe0a                  movsx    ecx, byte ptr [edx]            
  0x003B5DAC  42                      inc      edx                            
  0x003B5DAD  c1e108                  shl      ecx, 8                         
  0x003B5DB0  0bcd                    or       ecx, ebp                       
  0x003B5DB2  0fb66a01                movzx    ebp, byte ptr [edx + 1]        
  0x003B5DB6  42                      inc      edx                            
  0x003B5DB7  c1e108                  shl      ecx, 8                         
  0x003B5DBA  0bcd                    or       ecx, ebp                       
  0x003B5DBC  0fb66a01                movzx    ebp, byte ptr [edx + 1]        
  0x003B5DC0  42                      inc      edx                            
  0x003B5DC1  c1e108                  shl      ecx, 8                         
  0x003B5DC4  0bcd                    or       ecx, ebp                       
  0x003B5DC6  8be9                    mov      ebp, ecx                       
  0x003B5DC8  42                      inc      edx                            
  0x003B5DC9  eb02                    jmp      0x3b5dcd                       
                                        ; XREF: 0x003B5D9A (cond_jump)
  0x003B5DCB  d3e7                    shl      edi, cl                        
                                        ; XREF: 0x003B5DC9 (jump)
  0x003B5DCD  85db                    test     ebx, ebx                       
  0x003B5DCF  7511                    jne      0x3b5de2                       
  0x003B5DD1  8b4c2428                mov      ecx, dword ptr [esp + 0x28]    
  0x003B5DD5  8b19                    mov      ebx, dword ptr [ecx]           
  0x003B5DD7  8b4c2424                mov      ecx, dword ptr [esp + 0x24]    
  0x003B5DDB  8919                    mov      dword ptr [ecx], ebx           
  0x003B5DDD  e9cf000000              jmp      0x3b5eb1                       
                                        ; XREF: 0x003B5DCF (cond_jump)
  0x003B5DE2  8b4c2420                mov      ecx, dword ptr [esp + 0x20]    
  0x003B5DE6  8b5904                  mov      ebx, dword ptr [ecx + 4]       
  0x003B5DE9  85db                    test     ebx, ebx                       
  0x003B5DEB  0f8494000000            je       0x3b5e85                       
  0x003B5DF1  b920000000              mov      ecx, 0x20                      
  0x003B5DF6  2bcb                    sub      ecx, ebx                       
  0x003B5DF8  3bf1                    cmp      esi, ecx                       
  0x003B5DFA  894c2410                mov      dword ptr [esp + 0x10], ecx    
  0x003B5DFE  7c49                    jl       0x3b5e49                       
  0x003B5E00  8d741ee0                lea      esi, [esi + ebx - 0x20]        
  0x003B5E04  85f6                    test     esi, esi                       
  0x003B5E06  7416                    je       0x3b5e1e                       
  0x003B5E08  8bcb                    mov      ecx, ebx                       
  0x003B5E0A  2bce                    sub      ecx, esi                       
  0x003B5E0C  8bdd                    mov      ebx, ebp                       
  0x003B5E0E  d3eb                    shr      ebx, cl                        
  0x003B5E10  8b4c2410                mov      ecx, dword ptr [esp + 0x10]    
  0x003B5E14  0bdf                    or       ebx, edi                       
  0x003B5E16  d3eb                    shr      ebx, cl                        
  0x003B5E18  8bce                    mov      ecx, esi                       
  0x003B5E1A  d3e5                    shl      ebp, cl                        
  0x003B5E1C  eb04                    jmp      0x3b5e22                       
                                        ; XREF: 0x003B5E06 (cond_jump)
  0x003B5E1E  8bdf                    mov      ebx, edi                       
  0x003B5E20  d3eb                    shr      ebx, cl                        
                                        ; XREF: 0x003B5E1C (jump)
  0x003B5E22  0fbe0a                  movsx    ecx, byte ptr [edx]            
  0x003B5E25  42                      inc      edx                            
  0x003B5E26  c1e108                  shl      ecx, 8                         
  0x003B5E29  8bfd                    mov      edi, ebp                       
  0x003B5E2B  0fb62a                  movzx    ebp, byte ptr [edx]            
  0x003B5E2E  0bcd                    or       ecx, ebp                       
  0x003B5E30  0fb66a01                movzx    ebp, byte ptr [edx + 1]        
  0x003B5E34  42                      inc      edx                            
  0x003B5E35  c1e108                  shl      ecx, 8                         
  0x003B5E38  0bcd                    or       ecx, ebp                       
  0x003B5E3A  0fb66a01                movzx    ebp, byte ptr [edx + 1]        
  0x003B5E3E  42                      inc      edx                            
  0x003B5E3F  c1e108                  shl      ecx, 8                         
  0x003B5E42  0bcd                    or       ecx, ebp                       
  0x003B5E44  8be9                    mov      ebp, ecx                       
  0x003B5E46  42                      inc      edx                            
  0x003B5E47  eb0f                    jmp      0x3b5e58                       
                                        ; XREF: 0x003B5DFE (cond_jump)
  0x003B5E49  03f3                    add      esi, ebx                       
  0x003B5E4B  8bdf                    mov      ebx, edi                       
  0x003B5E4D  d3eb                    shr      ebx, cl                        
  0x003B5E4F  8b4c2420                mov      ecx, dword ptr [esp + 0x20]    
  0x003B5E53  8b4904                  mov      ecx, dword ptr [ecx + 4]       
  0x003B5E56  d3e7                    shl      edi, cl                        
                                        ; XREF: 0x003B5E47 (jump)
  0x003B5E58  8b4c2420                mov      ecx, dword ptr [esp + 0x20]    
  0x003B5E5C  8b490c                  mov      ecx, dword ptr [ecx + 0xc]     
  0x003B5E5F  2bcb                    sub      ecx, ebx                       
  0x003B5E61  8b5c241c                mov      ebx, dword ptr [esp + 0x1c]    
  0x003B5E65  49                      dec      ecx                            
  0x003B5E66  894c2410                mov      dword ptr [esp + 0x10], ecx    
  0x003B5E6A  8b4c2420                mov      ecx, dword ptr [esp + 0x20]    
  0x003B5E6E  8b4904                  mov      ecx, dword ptr [ecx + 4]       
  0x003B5E71  d3e3                    shl      ebx, cl                        
  0x003B5E73  8b4c2410                mov      ecx, dword ptr [esp + 0x10]    
  0x003B5E77  85db                    test     ebx, ebx                       
  0x003B5E79  7e04                    jle      0x3b5e7f                       
  0x003B5E7B  2bd9                    sub      ebx, ecx                       
  0x003B5E7D  eb02                    jmp      0x3b5e81                       
                                        ; XREF: 0x003B5E79 (cond_jump)
  0x003B5E7F  03d9                    add      ebx, ecx                       
                                        ; XREF: 0x003B5E7D (jump)
  0x003B5E81  895c241c                mov      dword ptr [esp + 0x1c], ebx    
                                        ; XREF: 0x003B5DEB (cond_jump)
  0x003B5E85  8b4c2428                mov      ecx, dword ptr [esp + 0x28]    
  0x003B5E89  8b19                    mov      ebx, dword ptr [ecx]           
  0x003B5E8B  035c241c                add      ebx, dword ptr [esp + 0x1c]    
  0x003B5E8F  8b4c2420                mov      ecx, dword ptr [esp + 0x20]    
  0x003B5E93  8b4908                  mov      ecx, dword ptr [ecx + 8]       
  0x003B5E96  d3e3                    shl      ebx, cl                        
  0x003B5E98  8b4c2420                mov      ecx, dword ptr [esp + 0x20]    
  0x003B5E9C  8b4908                  mov      ecx, dword ptr [ecx + 8]       
  0x003B5E9F  d3fb                    sar      ebx, cl                        
  0x003B5EA1  8b4c2424                mov      ecx, dword ptr [esp + 0x24]    
  0x003B5EA5  8919                    mov      dword ptr [ecx], ebx           
  0x003B5EA7  8b4c2428                mov      ecx, dword ptr [esp + 0x28]    
  0x003B5EAB  8919                    mov      dword ptr [ecx], ebx           
  0x003B5EAD  8b4c2424                mov      ecx, dword ptr [esp + 0x24]    
                                        ; XREF: 0x003B5DDD (jump)
  0x003B5EB1  8b5c2420                mov      ebx, dword ptr [esp + 0x20]    
  0x003B5EB5  833b00                  cmp      dword ptr [ebx], 0             
  0x003B5EB8  7402                    je       0x3b5ebc                       
  0x003B5EBA  d121                    shl      dword ptr [ecx], 1             
                                        ; XREF: 0x003B5D8A (jump), 0x003B5EB8 (cond_jump)
  0x003B5EBC  8938                    mov      dword ptr [eax], edi           
  0x003B5EBE  5f                      pop      edi                            
  0x003B5EBF  897008                  mov      dword ptr [eax + 8], esi       
  0x003B5EC2  5e                      pop      esi                            
  0x003B5EC3  896804                  mov      dword ptr [eax + 4], ebp       
  0x003B5EC6  5d                      pop      ebp                            
  0x003B5EC7  89500c                  mov      dword ptr [eax + 0xc], edx     
  0x003B5ECA  8b442408                mov      eax, dword ptr [esp + 8]       
  0x003B5ECE  5b                      pop      ebx                            
  0x003B5ECF  83c408                  add      esp, 8                         
  0x003B5ED2  c3                      ret                                     
  0x003B5ED3  cc                      int3                                    
  0x003B5ED4  cc                      int3                                    
  0x003B5ED5  cc                      int3                                    
  0x003B5ED6  cc                      int3                                    
  0x003B5ED7  cc                      int3                                    
  0x003B5ED8  cc                      int3                                    
  0x003B5ED9  cc                      int3                                    
  0x003B5EDA  cc                      int3                                    
  0x003B5EDB  cc                      int3                                    
  0x003B5EDC  cc                      int3                                    
  0x003B5EDD  cc                      int3                                    
  0x003B5EDE  cc                      int3                                    
  0x003B5EDF  cc                      int3                                    

; ============================================================
; Function: sub_003B5EE0
; Start: 0x003B5EE0  End: 0x003B5FAF  Size: 207 bytes
; Detection: cc_boundary (confidence: 0.85)
; ============================================================
sub_003B5EE0:
  0x003B5EE0  83ec18                  sub      esp, 0x18                      
  0x003B5EE3  8b442420                mov      eax, dword ptr [esp + 0x20]    
  0x003B5EE7  8b08                    mov      ecx, dword ptr [eax]           
  0x003B5EE9  53                      push     ebx                            
  0x003B5EEA  55                      push     ebp                            
  0x003B5EEB  56                      push     esi                            
  0x003B5EEC  57                      push     edi                            
  0x003B5EED  8b7c242c                mov      edi, dword ptr [esp + 0x2c]    
  0x003B5EF1  8db708130000            lea      esi, [edi + 0x1308]            
  0x003B5EF7  56                      push     esi                            
  0x003B5EF8  68ffffff7f              push     0x7fffffff                     
  0x003B5EFD  6a01                    push     1                              
  0x003B5EFF  50                      push     eax                            
  0x003B5F00  c744242801000000        mov      dword ptr [esp + 0x28], 1      
  0x003B5F08  89742424                mov      dword ptr [esp + 0x24], esi    
  0x003B5F0C  ff5118                  call     dword ptr [ecx + 0x18]         
  0x003B5F0F  8b2e                    mov      ebp, dword ptr [esi]           
  0x003B5F11  8bf5                    mov      esi, ebp                       
  0x003B5F13  83e6fc                  and      esi, 0xfffffffc                
  0x003B5F16  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B5F19  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B5F1D  c1e008                  shl      eax, 8                         
  0x003B5F20  0bc2                    or       eax, edx                       
  0x003B5F22  2bee                    sub      ebp, esi                       
  0x003B5F24  c1e503                  shl      ebp, 3                         
  0x003B5F27  83c410                  add      esp, 0x10                      
  0x003B5F2A  46                      inc      esi                            
  0x003B5F2B  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B5F2F  c1e008                  shl      eax, 8                         
  0x003B5F32  0bc1                    or       eax, ecx                       
  0x003B5F34  46                      inc      esi                            
  0x003B5F35  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B5F39  c1e008                  shl      eax, 8                         
  0x003B5F3C  0bc2                    or       eax, edx                       
  0x003B5F3E  46                      inc      esi                            
  0x003B5F3F  8bd8                    mov      ebx, eax                       
  0x003B5F41  0fbe4601                movsx    eax, byte ptr [esi + 1]        
  0x003B5F45  46                      inc      esi                            
  0x003B5F46  8bcd                    mov      ecx, ebp                       
  0x003B5F48  d3e3                    shl      ebx, cl                        
  0x003B5F4A  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B5F4E  46                      inc      esi                            
  0x003B5F4F  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B5F53  c1e008                  shl      eax, 8                         
  0x003B5F56  0bc1                    or       eax, ecx                       
  0x003B5F58  46                      inc      esi                            
  0x003B5F59  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B5F5D  c1e008                  shl      eax, 8                         
  0x003B5F60  0bc2                    or       eax, edx                       
  0x003B5F62  46                      inc      esi                            
  0x003B5F63  c1e008                  shl      eax, 8                         
  0x003B5F66  0bc1                    or       eax, ecx                       
  0x003B5F68  8b8f10130000            mov      ecx, dword ptr [edi + 0x1310]  
  0x003B5F6E  03e9                    add      ebp, ecx                       
  0x003B5F70  8bd0                    mov      edx, eax                       
  0x003B5F72  46                      inc      esi                            
  0x003B5F73  83fd20                  cmp      ebp, 0x20                      
  0x003B5F76  8954242c                mov      dword ptr [esp + 0x2c], edx    
  0x003B5F7A  7c33                    jl       0x3b5faf                       
  0x003B5F7C  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B5F7F  83ed20                  sub      ebp, 0x20                      
  0x003B5F82  8bda                    mov      ebx, edx                       
  0x003B5F84  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B5F88  8bcd                    mov      ecx, ebp                       
  0x003B5F8A  d3e3                    shl      ebx, cl                        
  0x003B5F8C  46                      inc      esi                            
  0x003B5F8D  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B5F91  c1e008                  shl      eax, 8                         
  0x003B5F94  0bc2                    or       eax, edx                       
  0x003B5F96  46                      inc      esi                            
  0x003B5F97  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B5F9B  c1e008                  shl      eax, 8                         
  0x003B5F9E  0bc1                    or       eax, ecx                       
  0x003B5FA0  46                      inc      esi                            
  0x003B5FA1  c1e008                  shl      eax, 8                         
  0x003B5FA4  0bc2                    or       eax, edx                       
  0x003B5FA6  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003B5FAA  46                      inc      esi                            
  0x003B5FAB  8bd0                    mov      edx, eax                       
  0x003B5FAD  eb02                    jmp      0x3b5fb1                       
; end of function
                                        ; XREF: 0x003B5F7A (cond_jump)
  0x003B5FAF  d3e3                    shl      ebx, cl                        
                                        ; XREF: 0x003B5FAD (jump), 0x003B6540 (jump), 0x003B6553 (jump)
  0x003B5FB1  8bc3                    mov      eax, ebx                       
  0x003B5FB3  c1e809                  shr      eax, 9                         
  0x003B5FB6  83fd09                  cmp      ebp, 9                         
  0x003B5FB9  89442410                mov      dword ptr [esp + 0x10], eax    
  0x003B5FBD  7e13                    jle      0x3b5fd2                       
  0x003B5FBF  b929000000              mov      ecx, 0x29                      
  0x003B5FC4  2bcd                    sub      ecx, ebp                       
  0x003B5FC6  8bc2                    mov      eax, edx                       
  0x003B5FC8  d3e8                    shr      eax, cl                        
  0x003B5FCA  8bc8                    mov      ecx, eax                       
  0x003B5FCC  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003B5FD0  0bc1                    or       eax, ecx                       
                                        ; XREF: 0x003B5FBD (cond_jump)
  0x003B5FD2  85c0                    test     eax, eax                       
  0x003B5FD4  0f847e050000            je       0x3b6558                       
  0x003B5FDA  8b8734030000            mov      eax, dword ptr [edi + 0x334]   
  0x003B5FE0  8944241c                mov      dword ptr [esp + 0x1c], eax    
                                        ; XREF: 0x003B6078 (cond_jump), 0x003B608A (jump)
  0x003B5FE4  8bc3                    mov      eax, ebx                       
  0x003B5FE6  c1e815                  shr      eax, 0x15                      
  0x003B5FE9  83fd15                  cmp      ebp, 0x15                      
  0x003B5FEC  7e0f                    jle      0x3b5ffd                       
  0x003B5FEE  b935000000              mov      ecx, 0x35                      
  0x003B5FF3  2bcd                    sub      ecx, ebp                       
  0x003B5FF5  d3ea                    shr      edx, cl                        
  0x003B5FF7  0bc2                    or       eax, edx                       
  0x003B5FF9  8b54242c                mov      edx, dword ptr [esp + 0x2c]    
                                        ; XREF: 0x003B5FEC (cond_jump)
  0x003B5FFD  a980ffffff              test     eax, 0xffffff80                
  0x003B6002  7510                    jne      0x3b6014                       
  0x003B6004  8b0db45df600            mov      ecx, dword ptr [0xf65db4]      
  0x003B600A  0fbf0441                movsx    eax, word ptr [ecx + eax*2]    
  0x003B600E  89442410                mov      dword ptr [esp + 0x10], eax    
  0x003B6012  eb11                    jmp      0x3b6025                       
                                        ; XREF: 0x003B6002 (cond_jump)
  0x003B6014  8b0db05df600            mov      ecx, dword ptr [0xf65db0]      
  0x003B601A  c1e806                  shr      eax, 6                         
  0x003B601D  0fbf0441                movsx    eax, word ptr [ecx + eax*2]    
  0x003B6021  89442410                mov      dword ptr [esp + 0x10], eax    
                                        ; XREF: 0x003B6012 (jump)
  0x003B6025  8bc8                    mov      ecx, eax                       
  0x003B6027  83e10f                  and      ecx, 0xf                       
  0x003B602A  03e9                    add      ebp, ecx                       
  0x003B602C  83fd20                  cmp      ebp, 0x20                      
  0x003B602F  7c37                    jl       0x3b6068                       
  0x003B6031  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B6034  83ed20                  sub      ebp, 0x20                      
  0x003B6037  8bda                    mov      ebx, edx                       
  0x003B6039  8bcd                    mov      ecx, ebp                       
  0x003B603B  d3e3                    shl      ebx, cl                        
  0x003B603D  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B6041  c1e008                  shl      eax, 8                         
  0x003B6044  46                      inc      esi                            
  0x003B6045  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B6049  0bc1                    or       eax, ecx                       
  0x003B604B  46                      inc      esi                            
  0x003B604C  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B6050  c1e008                  shl      eax, 8                         
  0x003B6053  0bc2                    or       eax, edx                       
  0x003B6055  46                      inc      esi                            
  0x003B6056  c1e008                  shl      eax, 8                         
  0x003B6059  0bc1                    or       eax, ecx                       
  0x003B605B  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003B605F  8bd0                    mov      edx, eax                       
  0x003B6061  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003B6065  46                      inc      esi                            
  0x003B6066  eb02                    jmp      0x3b606a                       
                                        ; XREF: 0x003B602F (cond_jump)
  0x003B6068  d3e3                    shl      ebx, cl                        
                                        ; XREF: 0x003B6066 (jump)
  0x003B606A  8bc8                    mov      ecx, eax                       
  0x003B606C  c1e902                  shr      ecx, 2                         
  0x003B606F  0fb6c9                  movzx    ecx, cl                        
  0x003B6072  c1e902                  shr      ecx, 2                         
  0x003B6075  83f922                  cmp      ecx, 0x22                      
  0x003B6078  0f8466ffffff            je       0x3b5fe4                       
  0x003B607E  83f923                  cmp      ecx, 0x23                      
  0x003B6081  750c                    jne      0x3b608f                       
  0x003B6083  83873403000021          add      dword ptr [edi + 0x334], 0x21  
  0x003B608A  e955ffffff              jmp      0x3b5fe4                       
                                        ; XREF: 0x003B6081 (cond_jump)
  0x003B608F  83f924                  cmp      ecx, 0x24                      
  0x003B6092  0f84c0040000            je       0x3b6558                       
  0x003B6098  018f34030000            add      dword ptr [edi + 0x334], ecx   
  0x003B609E  8b8f34030000            mov      ecx, dword ptr [edi + 0x334]   
  0x003B60A4  c1e80a                  shr      eax, 0xa                       
  0x003B60A7  898744030000            mov      dword ptr [edi + 0x344], eax   
  0x003B60AD  3b8f40030000            cmp      ecx, dword ptr [edi + 0x340]   
  0x003B60B3  0f8f9f040000            jg       0x3b6558                       
  0x003B60B9  2b4c241c                sub      ecx, dword ptr [esp + 0x1c]    
  0x003B60BD  8b873c030000            mov      eax, dword ptr [edi + 0x33c]   
  0x003B60C3  03c1                    add      eax, ecx                       
  0x003B60C5  894c2410                mov      dword ptr [esp + 0x10], ecx    
  0x003B60C9  8bc8                    mov      ecx, eax                       
  0x003B60CB  89873c030000            mov      dword ptr [edi + 0x33c], eax   
  0x003B60D1  8b87d8010000            mov      eax, dword ptr [edi + 0x1d8]   
  0x003B60D7  3bc8                    cmp      ecx, eax                       
  0x003B60D9  7c1f                    jl       0x3b60fa                       
  0x003B60DB  eb03                    jmp      0x3b60e0                       
  0x003B60DD  8d4900                  lea      ecx, [ecx]                     
                                        ; XREF: 0x003B60DB (jump), 0x003B60F8 (cond_jump)
  0x003B60E0  29873c030000            sub      dword ptr [edi + 0x33c], eax   
  0x003B60E6  ff8738030000            inc      dword ptr [edi + 0x338]        
  0x003B60EC  8b8f3c030000            mov      ecx, dword ptr [edi + 0x33c]   
  0x003B60F2  3b8fd8010000            cmp      ecx, dword ptr [edi + 0x1d8]   
  0x003B60F8  7de6                    jge      0x3b60e0                       
                                        ; XREF: 0x003B60D9 (cond_jump)
  0x003B60FA  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003B60FE  83f8fe                  cmp      eax, -2                        
  0x003B6101  0f8451040000            je       0x3b6558                       
  0x003B6107  8b4c2418                mov      ecx, dword ptr [esp + 0x18]    
  0x003B610B  85c9                    test     ecx, ecx                       
  0x003B610D  751a                    jne      0x3b6129                       
  0x003B610F  83f801                  cmp      eax, 1                         
  0x003B6112  7615                    jbe      0x3b6129                       
  0x003B6114  50                      push     eax                            
  0x003B6115  57                      push     edi                            
  0x003B6116  ff97c4020000            call     dword ptr [edi + 0x2c4]        
  0x003B611C  57                      push     edi                            
  0x003B611D  e8defbffff              call     0x3b5d00                       ; -> sub_003B5D00
  0x003B6122  8b542438                mov      edx, dword ptr [esp + 0x38]    
  0x003B6126  83c40c                  add      esp, 0xc                       
                                        ; XREF: 0x003B610D (cond_jump), 0x003B6112 (cond_jump)
  0x003B6129  f6874403000020          test     byte ptr [edi + 0x344], 0x20   
  0x003B6130  7575                    jne      0x3b61a7                       
  0x003B6132  8bc3                    mov      eax, ebx                       
  0x003B6134  c1e81a                  shr      eax, 0x1a                      
  0x003B6137  83fd1a                  cmp      ebp, 0x1a                      
  0x003B613A  89442410                mov      dword ptr [esp + 0x10], eax    
  0x003B613E  7e13                    jle      0x3b6153                       
  0x003B6140  b93a000000              mov      ecx, 0x3a                      
  0x003B6145  2bcd                    sub      ecx, ebp                       
  0x003B6147  8bc2                    mov      eax, edx                       
  0x003B6149  d3e8                    shr      eax, cl                        
  0x003B614B  8bc8                    mov      ecx, eax                       
  0x003B614D  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003B6151  0bc1                    or       eax, ecx                       
                                        ; XREF: 0x003B613E (cond_jump)
  0x003B6153  8b0dc85df600            mov      ecx, dword ptr [0xf65dc8]      
  0x003B6159  0fbf0441                movsx    eax, word ptr [ecx + eax*2]    
  0x003B615D  8bc8                    mov      ecx, eax                       
  0x003B615F  c1e908                  shr      ecx, 8                         
  0x003B6162  898f44030000            mov      dword ptr [edi + 0x344], ecx   
  0x003B6168  0fb6c8                  movzx    ecx, al                        
  0x003B616B  03e9                    add      ebp, ecx                       
  0x003B616D  83fd20                  cmp      ebp, 0x20                      
  0x003B6170  7c33                    jl       0x3b61a5                       
  0x003B6172  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B6175  83ed20                  sub      ebp, 0x20                      
  0x003B6178  8bda                    mov      ebx, edx                       
  0x003B617A  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B617E  8bcd                    mov      ecx, ebp                       
  0x003B6180  d3e3                    shl      ebx, cl                        
  0x003B6182  46                      inc      esi                            
  0x003B6183  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B6187  c1e008                  shl      eax, 8                         
  0x003B618A  0bc2                    or       eax, edx                       
  0x003B618C  46                      inc      esi                            
  0x003B618D  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B6191  c1e008                  shl      eax, 8                         
  0x003B6194  0bc1                    or       eax, ecx                       
  0x003B6196  46                      inc      esi                            
  0x003B6197  c1e008                  shl      eax, 8                         
  0x003B619A  0bc2                    or       eax, edx                       
  0x003B619C  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003B61A0  46                      inc      esi                            
  0x003B61A1  8bd0                    mov      edx, eax                       
  0x003B61A3  eb02                    jmp      0x3b61a7                       
                                        ; XREF: 0x003B6170 (cond_jump)
  0x003B61A5  d3e3                    shl      ebx, cl                        
                                        ; XREF: 0x003B6130 (cond_jump), 0x003B61A3 (jump)
  0x003B61A7  f6874403000010          test     byte ptr [edi + 0x344], 0x10   
  0x003B61AE  7461                    je       0x3b6211                       
  0x003B61B0  83fd1b                  cmp      ebp, 0x1b                      
  0x003B61B3  7c4b                    jl       0x3b6200                       
  0x003B61B5  83ed1b                  sub      ebp, 0x1b                      
  0x003B61B8  7416                    je       0x3b61d0                       
  0x003B61BA  b905000000              mov      ecx, 5                         
  0x003B61BF  2bcd                    sub      ecx, ebp                       
  0x003B61C1  8bc2                    mov      eax, edx                       
  0x003B61C3  d3e8                    shr      eax, cl                        
  0x003B61C5  8bcd                    mov      ecx, ebp                       
  0x003B61C7  0bc3                    or       eax, ebx                       
  0x003B61C9  c1e81b                  shr      eax, 0x1b                      
  0x003B61CC  d3e2                    shl      edx, cl                        
  0x003B61CE  eb05                    jmp      0x3b61d5                       
                                        ; XREF: 0x003B61B8 (cond_jump)
  0x003B61D0  8bc3                    mov      eax, ebx                       
  0x003B61D2  c1e81b                  shr      eax, 0x1b                      
                                        ; XREF: 0x003B61CE (jump)
  0x003B61D5  0fbe0e                  movsx    ecx, byte ptr [esi]            
  0x003B61D8  46                      inc      esi                            
  0x003B61D9  c1e108                  shl      ecx, 8                         
  0x003B61DC  8bda                    mov      ebx, edx                       
  0x003B61DE  0fb616                  movzx    edx, byte ptr [esi]            
  0x003B61E1  0bca                    or       ecx, edx                       
  0x003B61E3  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B61E7  46                      inc      esi                            
  0x003B61E8  c1e108                  shl      ecx, 8                         
  0x003B61EB  0bca                    or       ecx, edx                       
  0x003B61ED  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B61F1  46                      inc      esi                            
  0x003B61F2  c1e108                  shl      ecx, 8                         
  0x003B61F5  0bca                    or       ecx, edx                       
  0x003B61F7  894c242c                mov      dword ptr [esp + 0x2c], ecx    
  0x003B61FB  46                      inc      esi                            
  0x003B61FC  8bd1                    mov      edx, ecx                       
  0x003B61FE  eb0b                    jmp      0x3b620b                       
                                        ; XREF: 0x003B61B3 (cond_jump)
  0x003B6200  8bc3                    mov      eax, ebx                       
  0x003B6202  83c505                  add      ebp, 5                         
  0x003B6205  c1e81b                  shr      eax, 0x1b                      
  0x003B6208  c1e305                  shl      ebx, 5                         
                                        ; XREF: 0x003B61FE (jump)
  0x003B620B  8987e8020000            mov      dword ptr [edi + 0x2e8], eax   
                                        ; XREF: 0x003B61AE (cond_jump)
  0x003B6211  f6874403000008          test     byte ptr [edi + 0x344], 8      
  0x003B6218  7461                    je       0x3b627b                       
  0x003B621A  8d87fc020000            lea      eax, [edi + 0x2fc]             
  0x003B6220  50                      push     eax                            
  0x003B6221  8d8f04030000            lea      ecx, [edi + 0x304]             
  0x003B6227  89770c                  mov      dword ptr [edi + 0xc], esi     
  0x003B622A  51                      push     ecx                            
  0x003B622B  8db7ec020000            lea      esi, [edi + 0x2ec]             
  0x003B6231  56                      push     esi                            
  0x003B6232  57                      push     edi                            
  0x003B6233  891f                    mov      dword ptr [edi], ebx           
  0x003B6235  895704                  mov      dword ptr [edi + 4], edx       
  0x003B6238  896f08                  mov      dword ptr [edi + 8], ebp       
  0x003B623B  e8e0faffff              call     0x3b5d20                       ; -> sub_003B5D20
  0x003B6240  8d9700030000            lea      edx, [edi + 0x300]             
  0x003B6246  52                      push     edx                            
  0x003B6247  89442430                mov      dword ptr [esp + 0x30], eax    
  0x003B624B  8d8708030000            lea      eax, [edi + 0x308]             
  0x003B6251  50                      push     eax                            
  0x003B6252  56                      push     esi                            
  0x003B6253  57                      push     edi                            
  0x003B6254  e8c7faffff              call     0x3b5d20                       ; -> sub_003B5D20
  0x003B6259  8b4f04                  mov      ecx, dword ptr [edi + 4]       
  0x003B625C  8b1f                    mov      ebx, dword ptr [edi]           
  0x003B625E  8b6f08                  mov      ebp, dword ptr [edi + 8]       
  0x003B6261  8b770c                  mov      esi, dword ptr [edi + 0xc]     
  0x003B6264  894c244c                mov      dword ptr [esp + 0x4c], ecx    
  0x003B6268  8b4c243c                mov      ecx, dword ptr [esp + 0x3c]    
  0x003B626C  83c420                  add      esp, 0x20                      
  0x003B626F  0bc1                    or       eax, ecx                       
  0x003B6271  0f85e1020000            jne      0x3b6558                       
  0x003B6277  8b54242c                mov      edx, dword ptr [esp + 0x2c]    
                                        ; XREF: 0x003B6218 (cond_jump)
  0x003B627B  f6874403000004          test     byte ptr [edi + 0x344], 4      
  0x003B6282  7461                    je       0x3b62e5                       
  0x003B6284  895704                  mov      dword ptr [edi + 4], edx       
  0x003B6287  8d9720030000            lea      edx, [edi + 0x320]             
  0x003B628D  52                      push     edx                            
  0x003B628E  8d8728030000            lea      eax, [edi + 0x328]             
  0x003B6294  89770c                  mov      dword ptr [edi + 0xc], esi     
  0x003B6297  50                      push     eax                            
  0x003B6298  8db710030000            lea      esi, [edi + 0x310]             
  0x003B629E  56                      push     esi                            
  0x003B629F  57                      push     edi                            
  0x003B62A0  891f                    mov      dword ptr [edi], ebx           
  0x003B62A2  896f08                  mov      dword ptr [edi + 8], ebp       
  0x003B62A5  e876faffff              call     0x3b5d20                       ; -> sub_003B5D20
  0x003B62AA  8d8f24030000            lea      ecx, [edi + 0x324]             
  0x003B62B0  51                      push     ecx                            
  0x003B62B1  8d972c030000            lea      edx, [edi + 0x32c]             
  0x003B62B7  52                      push     edx                            
  0x003B62B8  56                      push     esi                            
  0x003B62B9  57                      push     edi                            
  0x003B62BA  8944243c                mov      dword ptr [esp + 0x3c], eax    
  0x003B62BE  e85dfaffff              call     0x3b5d20                       ; -> sub_003B5D20
  0x003B62C3  8b4f04                  mov      ecx, dword ptr [edi + 4]       
  0x003B62C6  8b1f                    mov      ebx, dword ptr [edi]           
  0x003B62C8  8b6f08                  mov      ebp, dword ptr [edi + 8]       
  0x003B62CB  8b770c                  mov      esi, dword ptr [edi + 0xc]     
  0x003B62CE  894c244c                mov      dword ptr [esp + 0x4c], ecx    
  0x003B62D2  8b4c243c                mov      ecx, dword ptr [esp + 0x3c]    
  0x003B62D6  83c420                  add      esp, 0x20                      
  0x003B62D9  0bc1                    or       eax, ecx                       
  0x003B62DB  0f8577020000            jne      0x3b6558                       
  0x003B62E1  8b54242c                mov      edx, dword ptr [esp + 0x2c]    
                                        ; XREF: 0x003B6282 (cond_jump)
  0x003B62E5  8b8744030000            mov      eax, dword ptr [edi + 0x344]   
  0x003B62EB  a802                    test     al, 2                          
  0x003B62ED  89442418                mov      dword ptr [esp + 0x18], eax    
  0x003B62F1  0f8482000000            je       0x3b6379                       
  0x003B62F7  8bc3                    mov      eax, ebx                       
  0x003B62F9  c1e817                  shr      eax, 0x17                      
  0x003B62FC  83fd17                  cmp      ebp, 0x17                      
  0x003B62FF  89442410                mov      dword ptr [esp + 0x10], eax    
  0x003B6303  7e13                    jle      0x3b6318                       
  0x003B6305  b937000000              mov      ecx, 0x37                      
  0x003B630A  2bcd                    sub      ecx, ebp                       
  0x003B630C  8bc2                    mov      eax, edx                       
  0x003B630E  d3e8                    shr      eax, cl                        
  0x003B6310  8bc8                    mov      ecx, eax                       
  0x003B6312  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003B6316  0bc1                    or       eax, ecx                       
                                        ; XREF: 0x003B6303 (cond_jump)
  0x003B6318  8b0dd45df600            mov      ecx, dword ptr [0xf65dd4]      
  0x003B631E  0fbf0441                movsx    eax, word ptr [ecx + eax*2]    
  0x003B6322  8bc8                    mov      ecx, eax                       
  0x003B6324  83e1f0                  and      ecx, 0xfffffff0                
  0x003B6327  c1e110                  shl      ecx, 0x10                      
  0x003B632A  898f48030000            mov      dword ptr [edi + 0x348], ecx   
  0x003B6330  0fb6c8                  movzx    ecx, al                        
  0x003B6333  03e9                    add      ebp, ecx                       
  0x003B6335  83fd20                  cmp      ebp, 0x20                      
  0x003B6338  7c37                    jl       0x3b6371                       
  0x003B633A  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B633D  83ed20                  sub      ebp, 0x20                      
  0x003B6340  8bda                    mov      ebx, edx                       
  0x003B6342  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B6346  8bcd                    mov      ecx, ebp                       
  0x003B6348  d3e3                    shl      ebx, cl                        
  0x003B634A  c1e008                  shl      eax, 8                         
  0x003B634D  46                      inc      esi                            
  0x003B634E  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B6352  0bc2                    or       eax, edx                       
  0x003B6354  46                      inc      esi                            
  0x003B6355  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B6359  c1e008                  shl      eax, 8                         
  0x003B635C  0bc1                    or       eax, ecx                       
  0x003B635E  46                      inc      esi                            
  0x003B635F  c1e008                  shl      eax, 8                         
  0x003B6362  0bc2                    or       eax, edx                       
  0x003B6364  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003B6368  8bd0                    mov      edx, eax                       
  0x003B636A  8b442418                mov      eax, dword ptr [esp + 0x18]    
  0x003B636E  46                      inc      esi                            
  0x003B636F  eb12                    jmp      0x3b6383                       
                                        ; XREF: 0x003B6338 (cond_jump)
  0x003B6371  8b442418                mov      eax, dword ptr [esp + 0x18]    
  0x003B6375  d3e3                    shl      ebx, cl                        
  0x003B6377  eb0a                    jmp      0x3b6383                       
                                        ; XREF: 0x003B62F1 (cond_jump)
  0x003B6379  c7874803000000000000    mov      dword ptr [edi + 0x348], 0     
                                        ; XREF: 0x003B636F (jump), 0x003B6377 (jump)
  0x003B6383  a801                    test     al, 1                          
  0x003B6385  891f                    mov      dword ptr [edi], ebx           
  0x003B6387  895704                  mov      dword ptr [edi + 4], edx       
  0x003B638A  896f08                  mov      dword ptr [edi + 8], ebp       
  0x003B638D  89770c                  mov      dword ptr [edi + 0xc], esi     
  0x003B6390  742b                    je       0x3b63bd                       
  0x003B6392  57                      push     edi                            
  0x003B6393  ff97c8020000            call     dword ptr [edi + 0x2c8]        
  0x003B6399  57                      push     edi                            
  0x003B639A  ff97d0020000            call     dword ptr [edi + 0x2d0]        
  0x003B63A0  8d87ec020000            lea      eax, [edi + 0x2ec]             
  0x003B63A6  50                      push     eax                            
  0x003B63A7  e834f9ffff              call     0x3b5ce0                       ; -> sub_003B5CE0
  0x003B63AC  8d8f10030000            lea      ecx, [edi + 0x310]             
  0x003B63B2  51                      push     ecx                            
  0x003B63B3  e828f9ffff              call     0x3b5ce0                       ; -> sub_003B5CE0
  0x003B63B8  83c410                  add      esp, 0x10                      
  0x003B63BB  eb37                    jmp      0x3b63f4                       
                                        ; XREF: 0x003B6390 (cond_jump)
  0x003B63BD  c1f802                  sar      eax, 2                         
  0x003B63C0  83e003                  and      eax, 3                         
  0x003B63C3  8b9487d4020000          mov      edx, dword ptr [edi + eax*4 + 0x2d4] 
  0x003B63CA  8b8748030000            mov      eax, dword ptr [edi + 0x348]   
  0x003B63D0  85c0                    test     eax, eax                       
  0x003B63D2  8997d4020000            mov      dword ptr [edi + 0x2d4], edx   
  0x003B63D8  740a                    je       0x3b63e4                       
  0x003B63DA  57                      push     edi                            
  0x003B63DB  ff97cc020000            call     dword ptr [edi + 0x2cc]        
  0x003B63E1  83c404                  add      esp, 4                         
                                        ; XREF: 0x003B63D8 (cond_jump)
  0x003B63E4  57                      push     edi                            
  0x003B63E5  ff97d4020000            call     dword ptr [edi + 0x2d4]        
  0x003B63EB  57                      push     edi                            
  0x003B63EC  e80ff9ffff              call     0x3b5d00                       ; -> sub_003B5D00
  0x003B63F1  83c408                  add      esp, 8                         
                                        ; XREF: 0x003B63BB (jump)
  0x003B63F4  8b8f24130000            mov      ecx, dword ptr [edi + 0x1324]  
  0x003B63FA  49                      dec      ecx                            
  0x003B63FB  8bc1                    mov      eax, ecx                       
  0x003B63FD  85c0                    test     eax, eax                       
  0x003B63FF  898f24130000            mov      dword ptr [edi + 0x1324], ecx  
  0x003B6405  7f1c                    jg       0x3b6423                       
  0x003B6407  8b8fb4010000            mov      ecx, dword ptr [edi + 0x1b4]   
  0x003B640D  8b87ac010000            mov      eax, dword ptr [edi + 0x1ac]   
  0x003B6413  51                      push     ecx                            
  0x003B6414  898724130000            mov      dword ptr [edi + 0x1324], eax  
  0x003B641A  ff97b0010000            call     dword ptr [edi + 0x1b0]        
  0x003B6420  83c404                  add      esp, 4                         
                                        ; XREF: 0x003B6405 (cond_jump)
  0x003B6423  8b6f08                  mov      ebp, dword ptr [edi + 8]       
  0x003B6426  8b5704                  mov      edx, dword ptr [edi + 4]       
  0x003B6429  8b770c                  mov      esi, dword ptr [edi + 0xc]     
  0x003B642C  8b1f                    mov      ebx, dword ptr [edi]           
  0x003B642E  8bc5                    mov      eax, ebp                       
  0x003B6430  83e007                  and      eax, 7                         
  0x003B6433  8bcd                    mov      ecx, ebp                       
  0x003B6435  2bc8                    sub      ecx, eax                       
  0x003B6437  83c107                  add      ecx, 7                         
  0x003B643A  8954242c                mov      dword ptr [esp + 0x2c], edx    
  0x003B643E  8944241c                mov      dword ptr [esp + 0x1c], eax    
  0x003B6442  8b442414                mov      eax, dword ptr [esp + 0x14]    
  0x003B6446  8b10                    mov      edx, dword ptr [eax]           
  0x003B6448  c1f903                  sar      ecx, 3                         
  0x003B644B  2bca                    sub      ecx, edx                       
  0x003B644D  8b970c130000            mov      edx, dword ptr [edi + 0x130c]  
  0x003B6453  8d4c31f8                lea      ecx, [ecx + esi - 8]           
  0x003B6457  2bd1                    sub      edx, ecx                       
  0x003B6459  81fa00080000            cmp      edx, 0x800                     
  0x003B645F  0f8fe2000000            jg       0x3b6547                       
  0x003B6465  8d542420                lea      edx, [esp + 0x20]              
  0x003B6469  52                      push     edx                            
  0x003B646A  50                      push     eax                            
  0x003B646B  51                      push     ecx                            
  0x003B646C  50                      push     eax                            
  0x003B646D  e8fe0bf5ff              call     0x307070                       ; -> sub_00307070
  0x003B6472  8b5c2424                mov      ebx, dword ptr [esp + 0x24]    
  0x003B6476  8b742440                mov      esi, dword ptr [esp + 0x40]    
  0x003B647A  8b06                    mov      eax, dword ptr [esi]           
  0x003B647C  53                      push     ebx                            
  0x003B647D  6a00                    push     0                              
  0x003B647F  56                      push     esi                            
  0x003B6480  ff5020                  call     dword ptr [eax + 0x20]         
  0x003B6483  8b0e                    mov      ecx, dword ptr [esi]           
  0x003B6485  8d54243c                lea      edx, [esp + 0x3c]              
  0x003B6489  52                      push     edx                            
  0x003B648A  6a01                    push     1                              
  0x003B648C  56                      push     esi                            
  0x003B648D  ff511c                  call     dword ptr [ecx + 0x1c]         
  0x003B6490  8b06                    mov      eax, dword ptr [esi]           
  0x003B6492  53                      push     ebx                            
  0x003B6493  68ffffff7f              push     0x7fffffff                     
  0x003B6498  6a01                    push     1                              
  0x003B649A  56                      push     esi                            
  0x003B649B  ff5018                  call     dword ptr [eax + 0x18]         
  0x003B649E  8b2b                    mov      ebp, dword ptr [ebx]           
  0x003B64A0  8bf5                    mov      esi, ebp                       
  0x003B64A2  83e6fc                  and      esi, 0xfffffffc                
  0x003B64A5  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B64A8  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B64AC  c1e008                  shl      eax, 8                         
  0x003B64AF  0bc1                    or       eax, ecx                       
  0x003B64B1  2bee                    sub      ebp, esi                       
  0x003B64B3  c1e503                  shl      ebp, 3                         
  0x003B64B6  83c438                  add      esp, 0x38                      
  0x003B64B9  46                      inc      esi                            
  0x003B64BA  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B64BE  c1e008                  shl      eax, 8                         
  0x003B64C1  0bc2                    or       eax, edx                       
  0x003B64C3  46                      inc      esi                            
  0x003B64C4  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B64C8  c1e008                  shl      eax, 8                         
  0x003B64CB  0bc1                    or       eax, ecx                       
  0x003B64CD  46                      inc      esi                            
  0x003B64CE  8bd8                    mov      ebx, eax                       
  0x003B64D0  0fbe4601                movsx    eax, byte ptr [esi + 1]        
  0x003B64D4  46                      inc      esi                            
  0x003B64D5  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B64D9  8bcd                    mov      ecx, ebp                       
  0x003B64DB  d3e3                    shl      ebx, cl                        
  0x003B64DD  46                      inc      esi                            
  0x003B64DE  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B64E2  c1e008                  shl      eax, 8                         
  0x003B64E5  0bc2                    or       eax, edx                       
  0x003B64E7  46                      inc      esi                            
  0x003B64E8  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B64EC  c1e008                  shl      eax, 8                         
  0x003B64EF  0bc1                    or       eax, ecx                       
  0x003B64F1  8b4c241c                mov      ecx, dword ptr [esp + 0x1c]    
  0x003B64F5  46                      inc      esi                            
  0x003B64F6  c1e008                  shl      eax, 8                         
  0x003B64F9  0bc2                    or       eax, edx                       
  0x003B64FB  03e9                    add      ebp, ecx                       
  0x003B64FD  46                      inc      esi                            
  0x003B64FE  83fd20                  cmp      ebp, 0x20                      
  0x003B6501  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003B6505  7c3e                    jl       0x3b6545                       
  0x003B6507  8bd8                    mov      ebx, eax                       
  0x003B6509  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B650C  83ed20                  sub      ebp, 0x20                      
  0x003B650F  8bcd                    mov      ecx, ebp                       
  0x003B6511  d3e3                    shl      ebx, cl                        
  0x003B6513  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B6517  46                      inc      esi                            
  0x003B6518  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B651C  c1e008                  shl      eax, 8                         
  0x003B651F  0bc1                    or       eax, ecx                       
  0x003B6521  46                      inc      esi                            
  0x003B6522  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B6526  c1e008                  shl      eax, 8                         
  0x003B6529  0bc2                    or       eax, edx                       
  0x003B652B  46                      inc      esi                            
  0x003B652C  c1e008                  shl      eax, 8                         
  0x003B652F  0bc1                    or       eax, ecx                       
  0x003B6531  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003B6535  46                      inc      esi                            
  0x003B6536  c744241800000000        mov      dword ptr [esp + 0x18], 0      
  0x003B653E  8bd0                    mov      edx, eax                       
  0x003B6540  e96cfaffff              jmp      0x3b5fb1                       
                                        ; XREF: 0x003B6505 (cond_jump)
  0x003B6545  d3e3                    shl      ebx, cl                        
                                        ; XREF: 0x003B645F (cond_jump)
  0x003B6547  8b54242c                mov      edx, dword ptr [esp + 0x2c]    
  0x003B654B  c744241800000000        mov      dword ptr [esp + 0x18], 0      
  0x003B6553  e959faffff              jmp      0x3b5fb1                       
                                        ; XREF: 0x003B5FD4 (cond_jump), 0x003B6092 (cond_jump), 0x003B60B3 (cond_jump), 0x003B6101 (cond_jump), 0x003B6271 (cond_jump), ... (+1 more)
  0x003B6558  8b7c2414                mov      edi, dword ptr [esp + 0x14]    
  0x003B655C  8d542420                lea      edx, [esp + 0x20]              
  0x003B6560  52                      push     edx                            
  0x003B6561  8b17                    mov      edx, dword ptr [edi]           
  0x003B6563  83c507                  add      ebp, 7                         
  0x003B6566  c1fd03                  sar      ebp, 3                         
  0x003B6569  2bea                    sub      ebp, edx                       
  0x003B656B  57                      push     edi                            
  0x003B656C  8d442ef8                lea      eax, [esi + ebp - 8]           
  0x003B6570  50                      push     eax                            
  0x003B6571  57                      push     edi                            
  0x003B6572  e8f90af5ff              call     0x307070                       ; -> sub_00307070
  0x003B6577  8b742440                mov      esi, dword ptr [esp + 0x40]    
  0x003B657B  8b0e                    mov      ecx, dword ptr [esi]           
  0x003B657D  57                      push     edi                            
  0x003B657E  6a00                    push     0                              
  0x003B6580  56                      push     esi                            
  0x003B6581  ff5120                  call     dword ptr [ecx + 0x20]         
  0x003B6584  8b16                    mov      edx, dword ptr [esi]           
  0x003B6586  8d44243c                lea      eax, [esp + 0x3c]              
  0x003B658A  50                      push     eax                            
  0x003B658B  6a01                    push     1                              
  0x003B658D  56                      push     esi                            
  0x003B658E  ff521c                  call     dword ptr [edx + 0x1c]         
  0x003B6591  56                      push     esi                            
  0x003B6592  e86991f6ff              call     0x31f700                       ; -> sub_0031F700
  0x003B6597  83c42c                  add      esp, 0x2c                      
  0x003B659A  5f                      pop      edi                            
  0x003B659B  5e                      pop      esi                            
  0x003B659C  5d                      pop      ebp                            
  0x003B659D  5b                      pop      ebx                            
  0x003B659E  83c418                  add      esp, 0x18                      
  0x003B65A1  c3                      ret                                     
  0x003B65A2  0000                    add      byte ptr [eax], al             
