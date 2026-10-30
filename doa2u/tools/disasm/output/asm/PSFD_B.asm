; ============================================================
; Section: PSFD_B
; VA: 0x003B96C0 - 0x003B9F84
; Size: 2244 bytes (2.2 KB)
; Functions: 4
; Instructions: 788
; ============================================================


; ============================================================
; Function: sub_003B96C0
; Start: 0x003B96C0  End: 0x003B96D3  Size: 19 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_00323010, sub_003B98C0
; ============================================================
sub_003B96C0:
  0x003B96C0  8b442404                mov      eax, dword ptr [esp + 4]       
  0x003B96C4  33c9                    xor      ecx, ecx                       
  0x003B96C6  894810                  mov      dword ptr [eax + 0x10], ecx    
  0x003B96C9  894814                  mov      dword ptr [eax + 0x14], ecx    
  0x003B96CC  894818                  mov      dword ptr [eax + 0x18], ecx    
  0x003B96CF  89481c                  mov      dword ptr [eax + 0x1c], ecx    
  0x003B96D2  c3                      ret                                     
; end of function
  0x003B96D3  cc                      int3                                    
  0x003B96D4  cc                      int3                                    
  0x003B96D5  cc                      int3                                    
  0x003B96D6  cc                      int3                                    
  0x003B96D7  cc                      int3                                    
  0x003B96D8  cc                      int3                                    
  0x003B96D9  cc                      int3                                    
  0x003B96DA  cc                      int3                                    
  0x003B96DB  cc                      int3                                    
  0x003B96DC  cc                      int3                                    
  0x003B96DD  cc                      int3                                    
  0x003B96DE  cc                      int3                                    
  0x003B96DF  cc                      int3                                    

; ============================================================
; Function: sub_003B96E0
; Start: 0x003B96E0  End: 0x003B96FC  Size: 28 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_00323010, sub_003B98C0
; ============================================================
sub_003B96E0:
  0x003B96E0  8b442404                mov      eax, dword ptr [esp + 4]       
  0x003B96E4  b900040000              mov      ecx, 0x400                     
  0x003B96E9  89884c030000            mov      dword ptr [eax + 0x34c], ecx   
  0x003B96EF  898854030000            mov      dword ptr [eax + 0x354], ecx   
  0x003B96F5  898850030000            mov      dword ptr [eax + 0x350], ecx   
  0x003B96FB  c3                      ret                                     
; end of function
  0x003B96FC  cc                      int3                                    
  0x003B96FD  cc                      int3                                    
  0x003B96FE  cc                      int3                                    
  0x003B96FF  cc                      int3                                    

; ============================================================
; Function: sub_003B9700
; Start: 0x003B9700  End: 0x003B98B3  Size: 435 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_003B98C0
; ============================================================
sub_003B9700:
  0x003B9700  83ec08                  sub      esp, 8                         
  0x003B9703  8b44240c                mov      eax, dword ptr [esp + 0xc]     
  0x003B9707  8b500c                  mov      edx, dword ptr [eax + 0xc]     
  0x003B970A  53                      push     ebx                            
  0x003B970B  55                      push     ebp                            
  0x003B970C  8b6804                  mov      ebp, dword ptr [eax + 4]       
  0x003B970F  56                      push     esi                            
  0x003B9710  8b7008                  mov      esi, dword ptr [eax + 8]       
  0x003B9713  57                      push     edi                            
  0x003B9714  8b38                    mov      edi, dword ptr [eax]           
  0x003B9716  8bdf                    mov      ebx, edi                       
  0x003B9718  c1eb15                  shr      ebx, 0x15                      
  0x003B971B  83fe15                  cmp      esi, 0x15                      
  0x003B971E  c744241400000000        mov      dword ptr [esp + 0x14], 0      
  0x003B9726  7e11                    jle      0x3b9739                       
  0x003B9728  b935000000              mov      ecx, 0x35                      
  0x003B972D  2bce                    sub      ecx, esi                       
  0x003B972F  8bc5                    mov      eax, ebp                       
  0x003B9731  d3e8                    shr      eax, cl                        
  0x003B9733  0bd8                    or       ebx, eax                       
  0x003B9735  8b44241c                mov      eax, dword ptr [esp + 0x1c]    
                                        ; XREF: 0x003B9726 (cond_jump)
  0x003B9739  f7c380ffffff            test     ebx, 0xffffff80                
  0x003B973F  7508                    jne      0x3b9749                       
  0x003B9741  8b0d20c2f600            mov      ecx, dword ptr [0xf6c220]      
  0x003B9747  eb09                    jmp      0x3b9752                       
                                        ; XREF: 0x003B973F (cond_jump)
  0x003B9749  8b0de8c1f600            mov      ecx, dword ptr [0xf6c1e8]      
  0x003B974F  c1eb06                  shr      ebx, 6                         
                                        ; XREF: 0x003B9747 (jump)
  0x003B9752  0fbf0c59                movsx    ecx, word ptr [ecx + ebx*2]    
  0x003B9756  0fbed9                  movsx    ebx, cl                        
  0x003B9759  83fb7f                  cmp      ebx, 0x7f                      
  0x003B975C  895c241c                mov      dword ptr [esp + 0x1c], ebx    
  0x003B9760  750d                    jne      0x3b976f                       
  0x003B9762  c7442414ffffffff        mov      dword ptr [esp + 0x14], 0xffffffff 
  0x003B976A  e92d010000              jmp      0x3b989c                       
                                        ; XREF: 0x003B9760 (cond_jump)
  0x003B976F  c1e908                  shr      ecx, 8                         
  0x003B9772  0fb6c9                  movzx    ecx, cl                        
  0x003B9775  03f1                    add      esi, ecx                       
  0x003B9777  83fe20                  cmp      esi, 0x20                      
  0x003B977A  7c2f                    jl       0x3b97ab                       
  0x003B977C  83ee20                  sub      esi, 0x20                      
  0x003B977F  8bfd                    mov      edi, ebp                       
  0x003B9781  0fb66a01                movzx    ebp, byte ptr [edx + 1]        
  0x003B9785  8bce                    mov      ecx, esi                       
  0x003B9787  d3e7                    shl      edi, cl                        
  0x003B9789  0fbe0a                  movsx    ecx, byte ptr [edx]            
  0x003B978C  42                      inc      edx                            
  0x003B978D  c1e108                  shl      ecx, 8                         
  0x003B9790  0bcd                    or       ecx, ebp                       
  0x003B9792  0fb66a01                movzx    ebp, byte ptr [edx + 1]        
  0x003B9796  42                      inc      edx                            
  0x003B9797  c1e108                  shl      ecx, 8                         
  0x003B979A  0bcd                    or       ecx, ebp                       
  0x003B979C  0fb66a01                movzx    ebp, byte ptr [edx + 1]        
  0x003B97A0  42                      inc      edx                            
  0x003B97A1  c1e108                  shl      ecx, 8                         
  0x003B97A4  0bcd                    or       ecx, ebp                       
  0x003B97A6  8be9                    mov      ebp, ecx                       
  0x003B97A8  42                      inc      edx                            
  0x003B97A9  eb02                    jmp      0x3b97ad                       
                                        ; XREF: 0x003B977A (cond_jump)
  0x003B97AB  d3e7                    shl      edi, cl                        
                                        ; XREF: 0x003B97A9 (jump)
  0x003B97AD  85db                    test     ebx, ebx                       
  0x003B97AF  7511                    jne      0x3b97c2                       
  0x003B97B1  8b4c2428                mov      ecx, dword ptr [esp + 0x28]    
  0x003B97B5  8b19                    mov      ebx, dword ptr [ecx]           
  0x003B97B7  8b4c2424                mov      ecx, dword ptr [esp + 0x24]    
  0x003B97BB  8919                    mov      dword ptr [ecx], ebx           
  0x003B97BD  e9cf000000              jmp      0x3b9891                       
                                        ; XREF: 0x003B97AF (cond_jump)
  0x003B97C2  8b4c2420                mov      ecx, dword ptr [esp + 0x20]    
  0x003B97C6  8b5904                  mov      ebx, dword ptr [ecx + 4]       
  0x003B97C9  85db                    test     ebx, ebx                       
  0x003B97CB  0f8494000000            je       0x3b9865                       
  0x003B97D1  b920000000              mov      ecx, 0x20                      
  0x003B97D6  2bcb                    sub      ecx, ebx                       
  0x003B97D8  3bf1                    cmp      esi, ecx                       
  0x003B97DA  894c2410                mov      dword ptr [esp + 0x10], ecx    
  0x003B97DE  7c49                    jl       0x3b9829                       
  0x003B97E0  8d741ee0                lea      esi, [esi + ebx - 0x20]        
  0x003B97E4  85f6                    test     esi, esi                       
  0x003B97E6  7416                    je       0x3b97fe                       
  0x003B97E8  8bcb                    mov      ecx, ebx                       
  0x003B97EA  2bce                    sub      ecx, esi                       
  0x003B97EC  8bdd                    mov      ebx, ebp                       
  0x003B97EE  d3eb                    shr      ebx, cl                        
  0x003B97F0  8b4c2410                mov      ecx, dword ptr [esp + 0x10]    
  0x003B97F4  0bdf                    or       ebx, edi                       
  0x003B97F6  d3eb                    shr      ebx, cl                        
  0x003B97F8  8bce                    mov      ecx, esi                       
  0x003B97FA  d3e5                    shl      ebp, cl                        
  0x003B97FC  eb04                    jmp      0x3b9802                       
                                        ; XREF: 0x003B97E6 (cond_jump)
  0x003B97FE  8bdf                    mov      ebx, edi                       
  0x003B9800  d3eb                    shr      ebx, cl                        
                                        ; XREF: 0x003B97FC (jump)
  0x003B9802  0fbe0a                  movsx    ecx, byte ptr [edx]            
  0x003B9805  42                      inc      edx                            
  0x003B9806  c1e108                  shl      ecx, 8                         
  0x003B9809  8bfd                    mov      edi, ebp                       
  0x003B980B  0fb62a                  movzx    ebp, byte ptr [edx]            
  0x003B980E  0bcd                    or       ecx, ebp                       
  0x003B9810  0fb66a01                movzx    ebp, byte ptr [edx + 1]        
  0x003B9814  42                      inc      edx                            
  0x003B9815  c1e108                  shl      ecx, 8                         
  0x003B9818  0bcd                    or       ecx, ebp                       
  0x003B981A  0fb66a01                movzx    ebp, byte ptr [edx + 1]        
  0x003B981E  42                      inc      edx                            
  0x003B981F  c1e108                  shl      ecx, 8                         
  0x003B9822  0bcd                    or       ecx, ebp                       
  0x003B9824  8be9                    mov      ebp, ecx                       
  0x003B9826  42                      inc      edx                            
  0x003B9827  eb0f                    jmp      0x3b9838                       
                                        ; XREF: 0x003B97DE (cond_jump)
  0x003B9829  03f3                    add      esi, ebx                       
  0x003B982B  8bdf                    mov      ebx, edi                       
  0x003B982D  d3eb                    shr      ebx, cl                        
  0x003B982F  8b4c2420                mov      ecx, dword ptr [esp + 0x20]    
  0x003B9833  8b4904                  mov      ecx, dword ptr [ecx + 4]       
  0x003B9836  d3e7                    shl      edi, cl                        
                                        ; XREF: 0x003B9827 (jump)
  0x003B9838  8b4c2420                mov      ecx, dword ptr [esp + 0x20]    
  0x003B983C  8b490c                  mov      ecx, dword ptr [ecx + 0xc]     
  0x003B983F  2bcb                    sub      ecx, ebx                       
  0x003B9841  8b5c241c                mov      ebx, dword ptr [esp + 0x1c]    
  0x003B9845  49                      dec      ecx                            
  0x003B9846  894c2410                mov      dword ptr [esp + 0x10], ecx    
  0x003B984A  8b4c2420                mov      ecx, dword ptr [esp + 0x20]    
  0x003B984E  8b4904                  mov      ecx, dword ptr [ecx + 4]       
  0x003B9851  d3e3                    shl      ebx, cl                        
  0x003B9853  8b4c2410                mov      ecx, dword ptr [esp + 0x10]    
  0x003B9857  85db                    test     ebx, ebx                       
  0x003B9859  7e04                    jle      0x3b985f                       
  0x003B985B  2bd9                    sub      ebx, ecx                       
  0x003B985D  eb02                    jmp      0x3b9861                       
                                        ; XREF: 0x003B9859 (cond_jump)
  0x003B985F  03d9                    add      ebx, ecx                       
                                        ; XREF: 0x003B985D (jump)
  0x003B9861  895c241c                mov      dword ptr [esp + 0x1c], ebx    
                                        ; XREF: 0x003B97CB (cond_jump)
  0x003B9865  8b4c2428                mov      ecx, dword ptr [esp + 0x28]    
  0x003B9869  8b19                    mov      ebx, dword ptr [ecx]           
  0x003B986B  035c241c                add      ebx, dword ptr [esp + 0x1c]    
  0x003B986F  8b4c2420                mov      ecx, dword ptr [esp + 0x20]    
  0x003B9873  8b4908                  mov      ecx, dword ptr [ecx + 8]       
  0x003B9876  d3e3                    shl      ebx, cl                        
  0x003B9878  8b4c2420                mov      ecx, dword ptr [esp + 0x20]    
  0x003B987C  8b4908                  mov      ecx, dword ptr [ecx + 8]       
  0x003B987F  d3fb                    sar      ebx, cl                        
  0x003B9881  8b4c2424                mov      ecx, dword ptr [esp + 0x24]    
  0x003B9885  8919                    mov      dword ptr [ecx], ebx           
  0x003B9887  8b4c2428                mov      ecx, dword ptr [esp + 0x28]    
  0x003B988B  8919                    mov      dword ptr [ecx], ebx           
  0x003B988D  8b4c2424                mov      ecx, dword ptr [esp + 0x24]    
                                        ; XREF: 0x003B97BD (jump)
  0x003B9891  8b5c2420                mov      ebx, dword ptr [esp + 0x20]    
  0x003B9895  833b00                  cmp      dword ptr [ebx], 0             
  0x003B9898  7402                    je       0x3b989c                       
  0x003B989A  d121                    shl      dword ptr [ecx], 1             
                                        ; XREF: 0x003B976A (jump), 0x003B9898 (cond_jump)
  0x003B989C  8938                    mov      dword ptr [eax], edi           
  0x003B989E  5f                      pop      edi                            
  0x003B989F  897008                  mov      dword ptr [eax + 8], esi       
  0x003B98A2  5e                      pop      esi                            
  0x003B98A3  896804                  mov      dword ptr [eax + 4], ebp       
  0x003B98A6  5d                      pop      ebp                            
  0x003B98A7  89500c                  mov      dword ptr [eax + 0xc], edx     
  0x003B98AA  8b442408                mov      eax, dword ptr [esp + 8]       
  0x003B98AE  5b                      pop      ebx                            
  0x003B98AF  83c408                  add      esp, 8                         
  0x003B98B2  c3                      ret                                     
; end of function
  0x003B98B3  cc                      int3                                    
  0x003B98B4  cc                      int3                                    
  0x003B98B5  cc                      int3                                    
  0x003B98B6  cc                      int3                                    
  0x003B98B7  cc                      int3                                    
  0x003B98B8  cc                      int3                                    
  0x003B98B9  cc                      int3                                    
  0x003B98BA  cc                      int3                                    
  0x003B98BB  cc                      int3                                    
  0x003B98BC  cc                      int3                                    
  0x003B98BD  cc                      int3                                    
  0x003B98BE  cc                      int3                                    
  0x003B98BF  cc                      int3                                    

; ============================================================
; Function: sub_003B98C0
; Start: 0x003B98C0  End: 0x003B9F82  Size: 1730 bytes
; Detection: cc_boundary (confidence: 0.85)
; Calls: sub_0030A7F0, sub_00322ED0, sub_003B96C0, sub_003B96E0, sub_003B9700
; ============================================================
sub_003B98C0:
  0x003B98C0  83ec18                  sub      esp, 0x18                      
  0x003B98C3  8b442420                mov      eax, dword ptr [esp + 0x20]    
  0x003B98C7  8b08                    mov      ecx, dword ptr [eax]           
  0x003B98C9  53                      push     ebx                            
  0x003B98CA  55                      push     ebp                            
  0x003B98CB  56                      push     esi                            
  0x003B98CC  57                      push     edi                            
  0x003B98CD  8b7c242c                mov      edi, dword ptr [esp + 0x2c]    
  0x003B98D1  8db708130000            lea      esi, [edi + 0x1308]            
  0x003B98D7  56                      push     esi                            
  0x003B98D8  68ffffff7f              push     0x7fffffff                     
  0x003B98DD  6a01                    push     1                              
  0x003B98DF  50                      push     eax                            
  0x003B98E0  c744242801000000        mov      dword ptr [esp + 0x28], 1      
  0x003B98E8  89742424                mov      dword ptr [esp + 0x24], esi    
  0x003B98EC  ff5118                  call     dword ptr [ecx + 0x18]         
  0x003B98EF  8b2e                    mov      ebp, dword ptr [esi]           
  0x003B98F1  8bf5                    mov      esi, ebp                       
  0x003B98F3  83e6fc                  and      esi, 0xfffffffc                
  0x003B98F6  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B98F9  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B98FD  c1e008                  shl      eax, 8                         
  0x003B9900  0bc2                    or       eax, edx                       
  0x003B9902  2bee                    sub      ebp, esi                       
  0x003B9904  c1e503                  shl      ebp, 3                         
  0x003B9907  83c410                  add      esp, 0x10                      
  0x003B990A  46                      inc      esi                            
  0x003B990B  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B990F  c1e008                  shl      eax, 8                         
  0x003B9912  0bc1                    or       eax, ecx                       
  0x003B9914  46                      inc      esi                            
  0x003B9915  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B9919  c1e008                  shl      eax, 8                         
  0x003B991C  0bc2                    or       eax, edx                       
  0x003B991E  46                      inc      esi                            
  0x003B991F  8bd8                    mov      ebx, eax                       
  0x003B9921  0fbe4601                movsx    eax, byte ptr [esi + 1]        
  0x003B9925  46                      inc      esi                            
  0x003B9926  8bcd                    mov      ecx, ebp                       
  0x003B9928  d3e3                    shl      ebx, cl                        
  0x003B992A  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B992E  46                      inc      esi                            
  0x003B992F  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B9933  c1e008                  shl      eax, 8                         
  0x003B9936  0bc1                    or       eax, ecx                       
  0x003B9938  46                      inc      esi                            
  0x003B9939  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B993D  c1e008                  shl      eax, 8                         
  0x003B9940  0bc2                    or       eax, edx                       
  0x003B9942  46                      inc      esi                            
  0x003B9943  c1e008                  shl      eax, 8                         
  0x003B9946  0bc1                    or       eax, ecx                       
  0x003B9948  8b8f10130000            mov      ecx, dword ptr [edi + 0x1310]  
  0x003B994E  03e9                    add      ebp, ecx                       
  0x003B9950  8bd0                    mov      edx, eax                       
  0x003B9952  46                      inc      esi                            
  0x003B9953  83fd20                  cmp      ebp, 0x20                      
  0x003B9956  8954242c                mov      dword ptr [esp + 0x2c], edx    
  0x003B995A  7c33                    jl       0x3b998f                       
  0x003B995C  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B995F  83ed20                  sub      ebp, 0x20                      
  0x003B9962  8bda                    mov      ebx, edx                       
  0x003B9964  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B9968  8bcd                    mov      ecx, ebp                       
  0x003B996A  d3e3                    shl      ebx, cl                        
  0x003B996C  46                      inc      esi                            
  0x003B996D  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B9971  c1e008                  shl      eax, 8                         
  0x003B9974  0bc2                    or       eax, edx                       
  0x003B9976  46                      inc      esi                            
  0x003B9977  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B997B  c1e008                  shl      eax, 8                         
  0x003B997E  0bc1                    or       eax, ecx                       
  0x003B9980  46                      inc      esi                            
  0x003B9981  c1e008                  shl      eax, 8                         
  0x003B9984  0bc2                    or       eax, edx                       
  0x003B9986  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003B998A  46                      inc      esi                            
  0x003B998B  8bd0                    mov      edx, eax                       
  0x003B998D  eb02                    jmp      0x3b9991                       
                                        ; XREF: 0x003B995A (cond_jump)
  0x003B998F  d3e3                    shl      ebx, cl                        
                                        ; XREF: 0x003B998D (jump), 0x003B9F20 (jump), 0x003B9F33 (jump)
  0x003B9991  8bc3                    mov      eax, ebx                       
  0x003B9993  c1e809                  shr      eax, 9                         
  0x003B9996  83fd09                  cmp      ebp, 9                         
  0x003B9999  89442410                mov      dword ptr [esp + 0x10], eax    
  0x003B999D  7e13                    jle      0x3b99b2                       
  0x003B999F  b929000000              mov      ecx, 0x29                      
  0x003B99A4  2bcd                    sub      ecx, ebp                       
  0x003B99A6  8bc2                    mov      eax, edx                       
  0x003B99A8  d3e8                    shr      eax, cl                        
  0x003B99AA  8bc8                    mov      ecx, eax                       
  0x003B99AC  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003B99B0  0bc1                    or       eax, ecx                       
                                        ; XREF: 0x003B999D (cond_jump)
  0x003B99B2  85c0                    test     eax, eax                       
  0x003B99B4  0f847e050000            je       0x3b9f38                       
  0x003B99BA  8b8734030000            mov      eax, dword ptr [edi + 0x334]   
  0x003B99C0  8944241c                mov      dword ptr [esp + 0x1c], eax    
                                        ; XREF: 0x003B9A58 (cond_jump), 0x003B9A6A (jump)
  0x003B99C4  8bc3                    mov      eax, ebx                       
  0x003B99C6  c1e815                  shr      eax, 0x15                      
  0x003B99C9  83fd15                  cmp      ebp, 0x15                      
  0x003B99CC  7e0f                    jle      0x3b99dd                       
  0x003B99CE  b935000000              mov      ecx, 0x35                      
  0x003B99D3  2bcd                    sub      ecx, ebp                       
  0x003B99D5  d3ea                    shr      edx, cl                        
  0x003B99D7  0bc2                    or       eax, edx                       
  0x003B99D9  8b54242c                mov      edx, dword ptr [esp + 0x2c]    
                                        ; XREF: 0x003B99CC (cond_jump)
  0x003B99DD  a980ffffff              test     eax, 0xffffff80                
  0x003B99E2  7510                    jne      0x3b99f4                       
  0x003B99E4  8b0df4c1f600            mov      ecx, dword ptr [0xf6c1f4]      
  0x003B99EA  0fbf0441                movsx    eax, word ptr [ecx + eax*2]    
  0x003B99EE  89442410                mov      dword ptr [esp + 0x10], eax    
  0x003B99F2  eb11                    jmp      0x3b9a05                       
                                        ; XREF: 0x003B99E2 (cond_jump)
  0x003B99F4  8b0df0c1f600            mov      ecx, dword ptr [0xf6c1f0]      
  0x003B99FA  c1e806                  shr      eax, 6                         
  0x003B99FD  0fbf0441                movsx    eax, word ptr [ecx + eax*2]    
  0x003B9A01  89442410                mov      dword ptr [esp + 0x10], eax    
                                        ; XREF: 0x003B99F2 (jump)
  0x003B9A05  8bc8                    mov      ecx, eax                       
  0x003B9A07  83e10f                  and      ecx, 0xf                       
  0x003B9A0A  03e9                    add      ebp, ecx                       
  0x003B9A0C  83fd20                  cmp      ebp, 0x20                      
  0x003B9A0F  7c37                    jl       0x3b9a48                       
  0x003B9A11  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B9A14  83ed20                  sub      ebp, 0x20                      
  0x003B9A17  8bda                    mov      ebx, edx                       
  0x003B9A19  8bcd                    mov      ecx, ebp                       
  0x003B9A1B  d3e3                    shl      ebx, cl                        
  0x003B9A1D  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B9A21  c1e008                  shl      eax, 8                         
  0x003B9A24  46                      inc      esi                            
  0x003B9A25  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B9A29  0bc1                    or       eax, ecx                       
  0x003B9A2B  46                      inc      esi                            
  0x003B9A2C  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B9A30  c1e008                  shl      eax, 8                         
  0x003B9A33  0bc2                    or       eax, edx                       
  0x003B9A35  46                      inc      esi                            
  0x003B9A36  c1e008                  shl      eax, 8                         
  0x003B9A39  0bc1                    or       eax, ecx                       
  0x003B9A3B  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003B9A3F  8bd0                    mov      edx, eax                       
  0x003B9A41  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003B9A45  46                      inc      esi                            
  0x003B9A46  eb02                    jmp      0x3b9a4a                       
                                        ; XREF: 0x003B9A0F (cond_jump)
  0x003B9A48  d3e3                    shl      ebx, cl                        
                                        ; XREF: 0x003B9A46 (jump)
  0x003B9A4A  8bc8                    mov      ecx, eax                       
  0x003B9A4C  c1e902                  shr      ecx, 2                         
  0x003B9A4F  0fb6c9                  movzx    ecx, cl                        
  0x003B9A52  c1e902                  shr      ecx, 2                         
  0x003B9A55  83f922                  cmp      ecx, 0x22                      
  0x003B9A58  0f8466ffffff            je       0x3b99c4                       
  0x003B9A5E  83f923                  cmp      ecx, 0x23                      
  0x003B9A61  750c                    jne      0x3b9a6f                       
  0x003B9A63  83873403000021          add      dword ptr [edi + 0x334], 0x21  
  0x003B9A6A  e955ffffff              jmp      0x3b99c4                       
                                        ; XREF: 0x003B9A61 (cond_jump)
  0x003B9A6F  83f924                  cmp      ecx, 0x24                      
  0x003B9A72  0f84c0040000            je       0x3b9f38                       
  0x003B9A78  018f34030000            add      dword ptr [edi + 0x334], ecx   
  0x003B9A7E  8b8f34030000            mov      ecx, dword ptr [edi + 0x334]   
  0x003B9A84  c1e80a                  shr      eax, 0xa                       
  0x003B9A87  898744030000            mov      dword ptr [edi + 0x344], eax   
  0x003B9A8D  3b8f40030000            cmp      ecx, dword ptr [edi + 0x340]   
  0x003B9A93  0f8f9f040000            jg       0x3b9f38                       
  0x003B9A99  2b4c241c                sub      ecx, dword ptr [esp + 0x1c]    
  0x003B9A9D  8b873c030000            mov      eax, dword ptr [edi + 0x33c]   
  0x003B9AA3  03c1                    add      eax, ecx                       
  0x003B9AA5  894c2410                mov      dword ptr [esp + 0x10], ecx    
  0x003B9AA9  8bc8                    mov      ecx, eax                       
  0x003B9AAB  89873c030000            mov      dword ptr [edi + 0x33c], eax   
  0x003B9AB1  8b87d8010000            mov      eax, dword ptr [edi + 0x1d8]   
  0x003B9AB7  3bc8                    cmp      ecx, eax                       
  0x003B9AB9  7c1f                    jl       0x3b9ada                       
  0x003B9ABB  eb03                    jmp      0x3b9ac0                       
  0x003B9ABD  8d4900                  lea      ecx, [ecx]                     
                                        ; XREF: 0x003B9ABB (jump), 0x003B9AD8 (cond_jump)
  0x003B9AC0  29873c030000            sub      dword ptr [edi + 0x33c], eax   
  0x003B9AC6  ff8738030000            inc      dword ptr [edi + 0x338]        
  0x003B9ACC  8b8f3c030000            mov      ecx, dword ptr [edi + 0x33c]   
  0x003B9AD2  3b8fd8010000            cmp      ecx, dword ptr [edi + 0x1d8]   
  0x003B9AD8  7de6                    jge      0x3b9ac0                       
                                        ; XREF: 0x003B9AB9 (cond_jump)
  0x003B9ADA  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003B9ADE  83f8fe                  cmp      eax, -2                        
  0x003B9AE1  0f8451040000            je       0x3b9f38                       
  0x003B9AE7  8b4c2418                mov      ecx, dword ptr [esp + 0x18]    
  0x003B9AEB  85c9                    test     ecx, ecx                       
  0x003B9AED  751a                    jne      0x3b9b09                       
  0x003B9AEF  83f801                  cmp      eax, 1                         
  0x003B9AF2  7615                    jbe      0x3b9b09                       
  0x003B9AF4  50                      push     eax                            
  0x003B9AF5  57                      push     edi                            
  0x003B9AF6  ff97c4020000            call     dword ptr [edi + 0x2c4]        
  0x003B9AFC  57                      push     edi                            
  0x003B9AFD  e8defbffff              call     0x3b96e0                       ; -> sub_003B96E0
  0x003B9B02  8b542438                mov      edx, dword ptr [esp + 0x38]    
  0x003B9B06  83c40c                  add      esp, 0xc                       
                                        ; XREF: 0x003B9AED (cond_jump), 0x003B9AF2 (cond_jump)
  0x003B9B09  f6874403000020          test     byte ptr [edi + 0x344], 0x20   
  0x003B9B10  7575                    jne      0x3b9b87                       
  0x003B9B12  8bc3                    mov      eax, ebx                       
  0x003B9B14  c1e81a                  shr      eax, 0x1a                      
  0x003B9B17  83fd1a                  cmp      ebp, 0x1a                      
  0x003B9B1A  89442410                mov      dword ptr [esp + 0x10], eax    
  0x003B9B1E  7e13                    jle      0x3b9b33                       
  0x003B9B20  b93a000000              mov      ecx, 0x3a                      
  0x003B9B25  2bcd                    sub      ecx, ebp                       
  0x003B9B27  8bc2                    mov      eax, edx                       
  0x003B9B29  d3e8                    shr      eax, cl                        
  0x003B9B2B  8bc8                    mov      ecx, eax                       
  0x003B9B2D  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003B9B31  0bc1                    or       eax, ecx                       
                                        ; XREF: 0x003B9B1E (cond_jump)
  0x003B9B33  8b0d08c2f600            mov      ecx, dword ptr [0xf6c208]      
  0x003B9B39  0fbf0441                movsx    eax, word ptr [ecx + eax*2]    
  0x003B9B3D  8bc8                    mov      ecx, eax                       
  0x003B9B3F  c1e908                  shr      ecx, 8                         
  0x003B9B42  898f44030000            mov      dword ptr [edi + 0x344], ecx   
  0x003B9B48  0fb6c8                  movzx    ecx, al                        
  0x003B9B4B  03e9                    add      ebp, ecx                       
  0x003B9B4D  83fd20                  cmp      ebp, 0x20                      
  0x003B9B50  7c33                    jl       0x3b9b85                       
  0x003B9B52  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B9B55  83ed20                  sub      ebp, 0x20                      
  0x003B9B58  8bda                    mov      ebx, edx                       
  0x003B9B5A  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B9B5E  8bcd                    mov      ecx, ebp                       
  0x003B9B60  d3e3                    shl      ebx, cl                        
  0x003B9B62  46                      inc      esi                            
  0x003B9B63  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B9B67  c1e008                  shl      eax, 8                         
  0x003B9B6A  0bc2                    or       eax, edx                       
  0x003B9B6C  46                      inc      esi                            
  0x003B9B6D  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B9B71  c1e008                  shl      eax, 8                         
  0x003B9B74  0bc1                    or       eax, ecx                       
  0x003B9B76  46                      inc      esi                            
  0x003B9B77  c1e008                  shl      eax, 8                         
  0x003B9B7A  0bc2                    or       eax, edx                       
  0x003B9B7C  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003B9B80  46                      inc      esi                            
  0x003B9B81  8bd0                    mov      edx, eax                       
  0x003B9B83  eb02                    jmp      0x3b9b87                       
                                        ; XREF: 0x003B9B50 (cond_jump)
  0x003B9B85  d3e3                    shl      ebx, cl                        
                                        ; XREF: 0x003B9B10 (cond_jump), 0x003B9B83 (jump)
  0x003B9B87  f6874403000010          test     byte ptr [edi + 0x344], 0x10   
  0x003B9B8E  7461                    je       0x3b9bf1                       
  0x003B9B90  83fd1b                  cmp      ebp, 0x1b                      
  0x003B9B93  7c4b                    jl       0x3b9be0                       
  0x003B9B95  83ed1b                  sub      ebp, 0x1b                      
  0x003B9B98  7416                    je       0x3b9bb0                       
  0x003B9B9A  b905000000              mov      ecx, 5                         
  0x003B9B9F  2bcd                    sub      ecx, ebp                       
  0x003B9BA1  8bc2                    mov      eax, edx                       
  0x003B9BA3  d3e8                    shr      eax, cl                        
  0x003B9BA5  8bcd                    mov      ecx, ebp                       
  0x003B9BA7  0bc3                    or       eax, ebx                       
  0x003B9BA9  c1e81b                  shr      eax, 0x1b                      
  0x003B9BAC  d3e2                    shl      edx, cl                        
  0x003B9BAE  eb05                    jmp      0x3b9bb5                       
                                        ; XREF: 0x003B9B98 (cond_jump)
  0x003B9BB0  8bc3                    mov      eax, ebx                       
  0x003B9BB2  c1e81b                  shr      eax, 0x1b                      
                                        ; XREF: 0x003B9BAE (jump)
  0x003B9BB5  0fbe0e                  movsx    ecx, byte ptr [esi]            
  0x003B9BB8  46                      inc      esi                            
  0x003B9BB9  c1e108                  shl      ecx, 8                         
  0x003B9BBC  8bda                    mov      ebx, edx                       
  0x003B9BBE  0fb616                  movzx    edx, byte ptr [esi]            
  0x003B9BC1  0bca                    or       ecx, edx                       
  0x003B9BC3  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B9BC7  46                      inc      esi                            
  0x003B9BC8  c1e108                  shl      ecx, 8                         
  0x003B9BCB  0bca                    or       ecx, edx                       
  0x003B9BCD  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B9BD1  46                      inc      esi                            
  0x003B9BD2  c1e108                  shl      ecx, 8                         
  0x003B9BD5  0bca                    or       ecx, edx                       
  0x003B9BD7  894c242c                mov      dword ptr [esp + 0x2c], ecx    
  0x003B9BDB  46                      inc      esi                            
  0x003B9BDC  8bd1                    mov      edx, ecx                       
  0x003B9BDE  eb0b                    jmp      0x3b9beb                       
                                        ; XREF: 0x003B9B93 (cond_jump)
  0x003B9BE0  8bc3                    mov      eax, ebx                       
  0x003B9BE2  83c505                  add      ebp, 5                         
  0x003B9BE5  c1e81b                  shr      eax, 0x1b                      
  0x003B9BE8  c1e305                  shl      ebx, 5                         
                                        ; XREF: 0x003B9BDE (jump)
  0x003B9BEB  8987e8020000            mov      dword ptr [edi + 0x2e8], eax   
                                        ; XREF: 0x003B9B8E (cond_jump)
  0x003B9BF1  f6874403000008          test     byte ptr [edi + 0x344], 8      
  0x003B9BF8  7461                    je       0x3b9c5b                       
  0x003B9BFA  8d87fc020000            lea      eax, [edi + 0x2fc]             
  0x003B9C00  50                      push     eax                            
  0x003B9C01  8d8f04030000            lea      ecx, [edi + 0x304]             
  0x003B9C07  89770c                  mov      dword ptr [edi + 0xc], esi     
  0x003B9C0A  51                      push     ecx                            
  0x003B9C0B  8db7ec020000            lea      esi, [edi + 0x2ec]             
  0x003B9C11  56                      push     esi                            
  0x003B9C12  57                      push     edi                            
  0x003B9C13  891f                    mov      dword ptr [edi], ebx           
  0x003B9C15  895704                  mov      dword ptr [edi + 4], edx       
  0x003B9C18  896f08                  mov      dword ptr [edi + 8], ebp       
  0x003B9C1B  e8e0faffff              call     0x3b9700                       ; -> sub_003B9700
  0x003B9C20  8d9700030000            lea      edx, [edi + 0x300]             
  0x003B9C26  52                      push     edx                            
  0x003B9C27  89442430                mov      dword ptr [esp + 0x30], eax    
  0x003B9C2B  8d8708030000            lea      eax, [edi + 0x308]             
  0x003B9C31  50                      push     eax                            
  0x003B9C32  56                      push     esi                            
  0x003B9C33  57                      push     edi                            
  0x003B9C34  e8c7faffff              call     0x3b9700                       ; -> sub_003B9700
  0x003B9C39  8b4f04                  mov      ecx, dword ptr [edi + 4]       
  0x003B9C3C  8b1f                    mov      ebx, dword ptr [edi]           
  0x003B9C3E  8b6f08                  mov      ebp, dword ptr [edi + 8]       
  0x003B9C41  8b770c                  mov      esi, dword ptr [edi + 0xc]     
  0x003B9C44  894c244c                mov      dword ptr [esp + 0x4c], ecx    
  0x003B9C48  8b4c243c                mov      ecx, dword ptr [esp + 0x3c]    
  0x003B9C4C  83c420                  add      esp, 0x20                      
  0x003B9C4F  0bc1                    or       eax, ecx                       
  0x003B9C51  0f85e1020000            jne      0x3b9f38                       
  0x003B9C57  8b54242c                mov      edx, dword ptr [esp + 0x2c]    
                                        ; XREF: 0x003B9BF8 (cond_jump)
  0x003B9C5B  f6874403000004          test     byte ptr [edi + 0x344], 4      
  0x003B9C62  7461                    je       0x3b9cc5                       
  0x003B9C64  895704                  mov      dword ptr [edi + 4], edx       
  0x003B9C67  8d9720030000            lea      edx, [edi + 0x320]             
  0x003B9C6D  52                      push     edx                            
  0x003B9C6E  8d8728030000            lea      eax, [edi + 0x328]             
  0x003B9C74  89770c                  mov      dword ptr [edi + 0xc], esi     
  0x003B9C77  50                      push     eax                            
  0x003B9C78  8db710030000            lea      esi, [edi + 0x310]             
  0x003B9C7E  56                      push     esi                            
  0x003B9C7F  57                      push     edi                            
  0x003B9C80  891f                    mov      dword ptr [edi], ebx           
  0x003B9C82  896f08                  mov      dword ptr [edi + 8], ebp       
  0x003B9C85  e876faffff              call     0x3b9700                       ; -> sub_003B9700
  0x003B9C8A  8d8f24030000            lea      ecx, [edi + 0x324]             
  0x003B9C90  51                      push     ecx                            
  0x003B9C91  8d972c030000            lea      edx, [edi + 0x32c]             
  0x003B9C97  52                      push     edx                            
  0x003B9C98  56                      push     esi                            
  0x003B9C99  57                      push     edi                            
  0x003B9C9A  8944243c                mov      dword ptr [esp + 0x3c], eax    
  0x003B9C9E  e85dfaffff              call     0x3b9700                       ; -> sub_003B9700
  0x003B9CA3  8b4f04                  mov      ecx, dword ptr [edi + 4]       
  0x003B9CA6  8b1f                    mov      ebx, dword ptr [edi]           
  0x003B9CA8  8b6f08                  mov      ebp, dword ptr [edi + 8]       
  0x003B9CAB  8b770c                  mov      esi, dword ptr [edi + 0xc]     
  0x003B9CAE  894c244c                mov      dword ptr [esp + 0x4c], ecx    
  0x003B9CB2  8b4c243c                mov      ecx, dword ptr [esp + 0x3c]    
  0x003B9CB6  83c420                  add      esp, 0x20                      
  0x003B9CB9  0bc1                    or       eax, ecx                       
  0x003B9CBB  0f8577020000            jne      0x3b9f38                       
  0x003B9CC1  8b54242c                mov      edx, dword ptr [esp + 0x2c]    
                                        ; XREF: 0x003B9C62 (cond_jump)
  0x003B9CC5  8b8744030000            mov      eax, dword ptr [edi + 0x344]   
  0x003B9CCB  a802                    test     al, 2                          
  0x003B9CCD  89442418                mov      dword ptr [esp + 0x18], eax    
  0x003B9CD1  0f8482000000            je       0x3b9d59                       
  0x003B9CD7  8bc3                    mov      eax, ebx                       
  0x003B9CD9  c1e817                  shr      eax, 0x17                      
  0x003B9CDC  83fd17                  cmp      ebp, 0x17                      
  0x003B9CDF  89442410                mov      dword ptr [esp + 0x10], eax    
  0x003B9CE3  7e13                    jle      0x3b9cf8                       
  0x003B9CE5  b937000000              mov      ecx, 0x37                      
  0x003B9CEA  2bcd                    sub      ecx, ebp                       
  0x003B9CEC  8bc2                    mov      eax, edx                       
  0x003B9CEE  d3e8                    shr      eax, cl                        
  0x003B9CF0  8bc8                    mov      ecx, eax                       
  0x003B9CF2  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003B9CF6  0bc1                    or       eax, ecx                       
                                        ; XREF: 0x003B9CE3 (cond_jump)
  0x003B9CF8  8b0d14c2f600            mov      ecx, dword ptr [0xf6c214]      
  0x003B9CFE  0fbf0441                movsx    eax, word ptr [ecx + eax*2]    
  0x003B9D02  8bc8                    mov      ecx, eax                       
  0x003B9D04  83e1f0                  and      ecx, 0xfffffff0                
  0x003B9D07  c1e110                  shl      ecx, 0x10                      
  0x003B9D0A  898f48030000            mov      dword ptr [edi + 0x348], ecx   
  0x003B9D10  0fb6c8                  movzx    ecx, al                        
  0x003B9D13  03e9                    add      ebp, ecx                       
  0x003B9D15  83fd20                  cmp      ebp, 0x20                      
  0x003B9D18  7c37                    jl       0x3b9d51                       
  0x003B9D1A  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B9D1D  83ed20                  sub      ebp, 0x20                      
  0x003B9D20  8bda                    mov      ebx, edx                       
  0x003B9D22  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B9D26  8bcd                    mov      ecx, ebp                       
  0x003B9D28  d3e3                    shl      ebx, cl                        
  0x003B9D2A  c1e008                  shl      eax, 8                         
  0x003B9D2D  46                      inc      esi                            
  0x003B9D2E  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B9D32  0bc2                    or       eax, edx                       
  0x003B9D34  46                      inc      esi                            
  0x003B9D35  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B9D39  c1e008                  shl      eax, 8                         
  0x003B9D3C  0bc1                    or       eax, ecx                       
  0x003B9D3E  46                      inc      esi                            
  0x003B9D3F  c1e008                  shl      eax, 8                         
  0x003B9D42  0bc2                    or       eax, edx                       
  0x003B9D44  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003B9D48  8bd0                    mov      edx, eax                       
  0x003B9D4A  8b442418                mov      eax, dword ptr [esp + 0x18]    
  0x003B9D4E  46                      inc      esi                            
  0x003B9D4F  eb12                    jmp      0x3b9d63                       
                                        ; XREF: 0x003B9D18 (cond_jump)
  0x003B9D51  8b442418                mov      eax, dword ptr [esp + 0x18]    
  0x003B9D55  d3e3                    shl      ebx, cl                        
  0x003B9D57  eb0a                    jmp      0x3b9d63                       
                                        ; XREF: 0x003B9CD1 (cond_jump)
  0x003B9D59  c7874803000000000000    mov      dword ptr [edi + 0x348], 0     
                                        ; XREF: 0x003B9D4F (jump), 0x003B9D57 (jump)
  0x003B9D63  a801                    test     al, 1                          
  0x003B9D65  891f                    mov      dword ptr [edi], ebx           
  0x003B9D67  895704                  mov      dword ptr [edi + 4], edx       
  0x003B9D6A  896f08                  mov      dword ptr [edi + 8], ebp       
  0x003B9D6D  89770c                  mov      dword ptr [edi + 0xc], esi     
  0x003B9D70  742b                    je       0x3b9d9d                       
  0x003B9D72  57                      push     edi                            
  0x003B9D73  ff97c8020000            call     dword ptr [edi + 0x2c8]        
  0x003B9D79  57                      push     edi                            
  0x003B9D7A  ff97d0020000            call     dword ptr [edi + 0x2d0]        
  0x003B9D80  8d87ec020000            lea      eax, [edi + 0x2ec]             
  0x003B9D86  50                      push     eax                            
  0x003B9D87  e834f9ffff              call     0x3b96c0                       ; -> sub_003B96C0
  0x003B9D8C  8d8f10030000            lea      ecx, [edi + 0x310]             
  0x003B9D92  51                      push     ecx                            
  0x003B9D93  e828f9ffff              call     0x3b96c0                       ; -> sub_003B96C0
  0x003B9D98  83c410                  add      esp, 0x10                      
  0x003B9D9B  eb37                    jmp      0x3b9dd4                       
                                        ; XREF: 0x003B9D70 (cond_jump)
  0x003B9D9D  c1f802                  sar      eax, 2                         
  0x003B9DA0  83e003                  and      eax, 3                         
  0x003B9DA3  8b9487d4020000          mov      edx, dword ptr [edi + eax*4 + 0x2d4] 
  0x003B9DAA  8b8748030000            mov      eax, dword ptr [edi + 0x348]   
  0x003B9DB0  85c0                    test     eax, eax                       
  0x003B9DB2  8997d4020000            mov      dword ptr [edi + 0x2d4], edx   
  0x003B9DB8  740a                    je       0x3b9dc4                       
  0x003B9DBA  57                      push     edi                            
  0x003B9DBB  ff97cc020000            call     dword ptr [edi + 0x2cc]        
  0x003B9DC1  83c404                  add      esp, 4                         
                                        ; XREF: 0x003B9DB8 (cond_jump)
  0x003B9DC4  57                      push     edi                            
  0x003B9DC5  ff97d4020000            call     dword ptr [edi + 0x2d4]        
  0x003B9DCB  57                      push     edi                            
  0x003B9DCC  e80ff9ffff              call     0x3b96e0                       ; -> sub_003B96E0
  0x003B9DD1  83c408                  add      esp, 8                         
                                        ; XREF: 0x003B9D9B (jump)
  0x003B9DD4  8b8f24130000            mov      ecx, dword ptr [edi + 0x1324]  
  0x003B9DDA  49                      dec      ecx                            
  0x003B9DDB  8bc1                    mov      eax, ecx                       
  0x003B9DDD  85c0                    test     eax, eax                       
  0x003B9DDF  898f24130000            mov      dword ptr [edi + 0x1324], ecx  
  0x003B9DE5  7f1c                    jg       0x3b9e03                       
  0x003B9DE7  8b8fb4010000            mov      ecx, dword ptr [edi + 0x1b4]   
  0x003B9DED  8b87ac010000            mov      eax, dword ptr [edi + 0x1ac]   
  0x003B9DF3  51                      push     ecx                            
  0x003B9DF4  898724130000            mov      dword ptr [edi + 0x1324], eax  
  0x003B9DFA  ff97b0010000            call     dword ptr [edi + 0x1b0]        
  0x003B9E00  83c404                  add      esp, 4                         
                                        ; XREF: 0x003B9DE5 (cond_jump)
  0x003B9E03  8b6f08                  mov      ebp, dword ptr [edi + 8]       
  0x003B9E06  8b5704                  mov      edx, dword ptr [edi + 4]       
  0x003B9E09  8b770c                  mov      esi, dword ptr [edi + 0xc]     
  0x003B9E0C  8b1f                    mov      ebx, dword ptr [edi]           
  0x003B9E0E  8bc5                    mov      eax, ebp                       
  0x003B9E10  83e007                  and      eax, 7                         
  0x003B9E13  8bcd                    mov      ecx, ebp                       
  0x003B9E15  2bc8                    sub      ecx, eax                       
  0x003B9E17  83c107                  add      ecx, 7                         
  0x003B9E1A  8954242c                mov      dword ptr [esp + 0x2c], edx    
  0x003B9E1E  8944241c                mov      dword ptr [esp + 0x1c], eax    
  0x003B9E22  8b442414                mov      eax, dword ptr [esp + 0x14]    
  0x003B9E26  8b10                    mov      edx, dword ptr [eax]           
  0x003B9E28  c1f903                  sar      ecx, 3                         
  0x003B9E2B  2bca                    sub      ecx, edx                       
  0x003B9E2D  8b970c130000            mov      edx, dword ptr [edi + 0x130c]  
  0x003B9E33  8d4c31f8                lea      ecx, [ecx + esi - 8]           
  0x003B9E37  2bd1                    sub      edx, ecx                       
  0x003B9E39  81fa00080000            cmp      edx, 0x800                     
  0x003B9E3F  0f8fe2000000            jg       0x3b9f27                       
  0x003B9E45  8d542420                lea      edx, [esp + 0x20]              
  0x003B9E49  52                      push     edx                            
  0x003B9E4A  50                      push     eax                            
  0x003B9E4B  51                      push     ecx                            
  0x003B9E4C  50                      push     eax                            
  0x003B9E4D  e89e09f5ff              call     0x30a7f0                       ; -> sub_0030A7F0
  0x003B9E52  8b5c2424                mov      ebx, dword ptr [esp + 0x24]    
  0x003B9E56  8b742440                mov      esi, dword ptr [esp + 0x40]    
  0x003B9E5A  8b06                    mov      eax, dword ptr [esi]           
  0x003B9E5C  53                      push     ebx                            
  0x003B9E5D  6a00                    push     0                              
  0x003B9E5F  56                      push     esi                            
  0x003B9E60  ff5020                  call     dword ptr [eax + 0x20]         
  0x003B9E63  8b0e                    mov      ecx, dword ptr [esi]           
  0x003B9E65  8d54243c                lea      edx, [esp + 0x3c]              
  0x003B9E69  52                      push     edx                            
  0x003B9E6A  6a01                    push     1                              
  0x003B9E6C  56                      push     esi                            
  0x003B9E6D  ff511c                  call     dword ptr [ecx + 0x1c]         
  0x003B9E70  8b06                    mov      eax, dword ptr [esi]           
  0x003B9E72  53                      push     ebx                            
  0x003B9E73  68ffffff7f              push     0x7fffffff                     
  0x003B9E78  6a01                    push     1                              
  0x003B9E7A  56                      push     esi                            
  0x003B9E7B  ff5018                  call     dword ptr [eax + 0x18]         
  0x003B9E7E  8b2b                    mov      ebp, dword ptr [ebx]           
  0x003B9E80  8bf5                    mov      esi, ebp                       
  0x003B9E82  83e6fc                  and      esi, 0xfffffffc                
  0x003B9E85  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B9E88  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B9E8C  c1e008                  shl      eax, 8                         
  0x003B9E8F  0bc1                    or       eax, ecx                       
  0x003B9E91  2bee                    sub      ebp, esi                       
  0x003B9E93  c1e503                  shl      ebp, 3                         
  0x003B9E96  83c438                  add      esp, 0x38                      
  0x003B9E99  46                      inc      esi                            
  0x003B9E9A  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B9E9E  c1e008                  shl      eax, 8                         
  0x003B9EA1  0bc2                    or       eax, edx                       
  0x003B9EA3  46                      inc      esi                            
  0x003B9EA4  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B9EA8  c1e008                  shl      eax, 8                         
  0x003B9EAB  0bc1                    or       eax, ecx                       
  0x003B9EAD  46                      inc      esi                            
  0x003B9EAE  8bd8                    mov      ebx, eax                       
  0x003B9EB0  0fbe4601                movsx    eax, byte ptr [esi + 1]        
  0x003B9EB4  46                      inc      esi                            
  0x003B9EB5  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B9EB9  8bcd                    mov      ecx, ebp                       
  0x003B9EBB  d3e3                    shl      ebx, cl                        
  0x003B9EBD  46                      inc      esi                            
  0x003B9EBE  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B9EC2  c1e008                  shl      eax, 8                         
  0x003B9EC5  0bc2                    or       eax, edx                       
  0x003B9EC7  46                      inc      esi                            
  0x003B9EC8  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B9ECC  c1e008                  shl      eax, 8                         
  0x003B9ECF  0bc1                    or       eax, ecx                       
  0x003B9ED1  8b4c241c                mov      ecx, dword ptr [esp + 0x1c]    
  0x003B9ED5  46                      inc      esi                            
  0x003B9ED6  c1e008                  shl      eax, 8                         
  0x003B9ED9  0bc2                    or       eax, edx                       
  0x003B9EDB  03e9                    add      ebp, ecx                       
  0x003B9EDD  46                      inc      esi                            
  0x003B9EDE  83fd20                  cmp      ebp, 0x20                      
  0x003B9EE1  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003B9EE5  7c3e                    jl       0x3b9f25                       
  0x003B9EE7  8bd8                    mov      ebx, eax                       
  0x003B9EE9  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B9EEC  83ed20                  sub      ebp, 0x20                      
  0x003B9EEF  8bcd                    mov      ecx, ebp                       
  0x003B9EF1  d3e3                    shl      ebx, cl                        
  0x003B9EF3  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B9EF7  46                      inc      esi                            
  0x003B9EF8  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B9EFC  c1e008                  shl      eax, 8                         
  0x003B9EFF  0bc1                    or       eax, ecx                       
  0x003B9F01  46                      inc      esi                            
  0x003B9F02  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B9F06  c1e008                  shl      eax, 8                         
  0x003B9F09  0bc2                    or       eax, edx                       
  0x003B9F0B  46                      inc      esi                            
  0x003B9F0C  c1e008                  shl      eax, 8                         
  0x003B9F0F  0bc1                    or       eax, ecx                       
  0x003B9F11  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003B9F15  46                      inc      esi                            
  0x003B9F16  c744241800000000        mov      dword ptr [esp + 0x18], 0      
  0x003B9F1E  8bd0                    mov      edx, eax                       
  0x003B9F20  e96cfaffff              jmp      0x3b9991                       
                                        ; XREF: 0x003B9EE5 (cond_jump)
  0x003B9F25  d3e3                    shl      ebx, cl                        
                                        ; XREF: 0x003B9E3F (cond_jump)
  0x003B9F27  8b54242c                mov      edx, dword ptr [esp + 0x2c]    
  0x003B9F2B  c744241800000000        mov      dword ptr [esp + 0x18], 0      
  0x003B9F33  e959faffff              jmp      0x3b9991                       
                                        ; XREF: 0x003B99B4 (cond_jump), 0x003B9A72 (cond_jump), 0x003B9A93 (cond_jump), 0x003B9AE1 (cond_jump), 0x003B9C51 (cond_jump), ... (+1 more)
  0x003B9F38  8b7c2414                mov      edi, dword ptr [esp + 0x14]    
  0x003B9F3C  8d542420                lea      edx, [esp + 0x20]              
  0x003B9F40  52                      push     edx                            
  0x003B9F41  8b17                    mov      edx, dword ptr [edi]           
  0x003B9F43  83c507                  add      ebp, 7                         
  0x003B9F46  c1fd03                  sar      ebp, 3                         
  0x003B9F49  2bea                    sub      ebp, edx                       
  0x003B9F4B  57                      push     edi                            
  0x003B9F4C  8d442ef8                lea      eax, [esi + ebp - 8]           
  0x003B9F50  50                      push     eax                            
  0x003B9F51  57                      push     edi                            
  0x003B9F52  e89908f5ff              call     0x30a7f0                       ; -> sub_0030A7F0
  0x003B9F57  8b742440                mov      esi, dword ptr [esp + 0x40]    
  0x003B9F5B  8b0e                    mov      ecx, dword ptr [esi]           
  0x003B9F5D  57                      push     edi                            
  0x003B9F5E  6a00                    push     0                              
  0x003B9F60  56                      push     esi                            
  0x003B9F61  ff5120                  call     dword ptr [ecx + 0x20]         
  0x003B9F64  8b16                    mov      edx, dword ptr [esi]           
  0x003B9F66  8d44243c                lea      eax, [esp + 0x3c]              
  0x003B9F6A  50                      push     eax                            
  0x003B9F6B  6a01                    push     1                              
  0x003B9F6D  56                      push     esi                            
  0x003B9F6E  ff521c                  call     dword ptr [edx + 0x1c]         
  0x003B9F71  56                      push     esi                            
  0x003B9F72  e8598ff6ff              call     0x322ed0                       ; -> sub_00322ED0
  0x003B9F77  83c42c                  add      esp, 0x2c                      
  0x003B9F7A  5f                      pop      edi                            
  0x003B9F7B  5e                      pop      esi                            
  0x003B9F7C  5d                      pop      ebp                            
  0x003B9F7D  5b                      pop      ebx                            
  0x003B9F7E  83c418                  add      esp, 0x18                      
  0x003B9F81  c3                      ret                                     
; end of function
  0x003B9F82  0000                    add      byte ptr [eax], al             
