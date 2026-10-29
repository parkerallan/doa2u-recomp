; ============================================================
; Section: PSFD00
; VA: 0x003BA5E0 - 0x003BBD48
; Size: 5992 bytes (5.9 KB)
; Functions: 17
; Instructions: 2077
; ============================================================


; ============================================================
; Function: sub_003BA5E0
; Start: 0x003BA5E0  End: 0x003BA889  Size: 681 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_003BB420
; ============================================================
sub_003BA5E0:
  0x003BA5E0  83ec0c                  sub      esp, 0xc                       
  0x003BA5E3  53                      push     ebx                            
  0x003BA5E4  55                      push     ebp                            
  0x003BA5E5  57                      push     edi                            
  0x003BA5E6  83c204                  add      edx, 4                         
  0x003BA5E9  c744241006000000        mov      dword ptr [esp + 0x10], 6      
  0x003BA5F1  eb04                    jmp      0x3ba5f7                       
                                        ; XREF: 0x003BA87C (cond_jump)
  0x003BA5F3  8b542414                mov      edx, dword ptr [esp + 0x14]    
                                        ; XREF: 0x003BA5F1 (jump)
  0x003BA5F7  8b02                    mov      eax, dword ptr [edx]           
  0x003BA5F9  8b7a04                  mov      edi, dword ptr [edx + 4]       
  0x003BA5FC  83c204                  add      edx, 4                         
  0x003BA5FF  83c204                  add      edx, 4                         
  0x003BA602  a81f                    test     al, 0x1f                       
  0x003BA604  89542414                mov      dword ptr [esp + 0x14], edx    
  0x003BA608  0f8583000000            jne      0x3ba691                       
  0x003BA60E  bd08000000              mov      ebp, 8                         
                                        ; XREF: 0x003BA68A (cond_jump)
  0x003BA613  0fbf5904                movsx    ebx, word ptr [ecx + 4]        
  0x003BA617  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA61A  0fbf5102                movsx    edx, word ptr [ecx + 2]        
  0x003BA61E  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003BA621  0f1808                  prefetcht0 byte ptr [eax]                 
  0x003BA624  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003BA628  0fbf5906                movsx    ebx, word ptr [ecx + 6]        
  0x003BA62C  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA62F  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003BA633  0fbf19                  movsx    ebx, word ptr [ecx]            
  0x003BA636  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA639  885001                  mov      byte ptr [eax + 1], dl         
  0x003BA63C  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003BA640  885002                  mov      byte ptr [eax + 2], dl         
  0x003BA643  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003BA647  885003                  mov      byte ptr [eax + 3], dl         
  0x003BA64A  8818                    mov      byte ptr [eax], bl             
  0x003BA64C  0fbf590c                movsx    ebx, word ptr [ecx + 0xc]      
  0x003BA650  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA653  0fbf510a                movsx    edx, word ptr [ecx + 0xa]      
  0x003BA657  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003BA65A  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003BA65E  0fbf590e                movsx    ebx, word ptr [ecx + 0xe]      
  0x003BA662  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA665  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003BA669  0fbf5908                movsx    ebx, word ptr [ecx + 8]        
  0x003BA66D  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA670  885005                  mov      byte ptr [eax + 5], dl         
  0x003BA673  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003BA677  885006                  mov      byte ptr [eax + 6], dl         
  0x003BA67A  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003BA67E  885804                  mov      byte ptr [eax + 4], bl         
  0x003BA681  885007                  mov      byte ptr [eax + 7], dl         
  0x003BA684  83c110                  add      ecx, 0x10                      
  0x003BA687  03c7                    add      eax, edi                       
  0x003BA689  4d                      dec      ebp                            
  0x003BA68A  7587                    jne      0x3ba613                       
  0x003BA68C  e9e7010000              jmp      0x3ba878                       
                                        ; XREF: 0x003BA608 (cond_jump)
  0x003BA691  bd02000000              mov      ebp, 2                         
  0x003BA696  eb08                    jmp      0x3ba6a0                       
  0x003BA698  8da42400000000          lea      esp, [esp]                     
  0x003BA69F  90                      nop                                     
                                        ; XREF: 0x003BA696 (jump), 0x003BA872 (cond_jump)
  0x003BA6A0  0fbf5904                movsx    ebx, word ptr [ecx + 4]        
  0x003BA6A4  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA6A7  0fbf5102                movsx    edx, word ptr [ecx + 2]        
  0x003BA6AB  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003BA6AE  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003BA6B2  0fbf5906                movsx    ebx, word ptr [ecx + 6]        
  0x003BA6B6  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA6B9  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003BA6BD  0fbf19                  movsx    ebx, word ptr [ecx]            
  0x003BA6C0  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA6C3  885001                  mov      byte ptr [eax + 1], dl         
  0x003BA6C6  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003BA6CA  885002                  mov      byte ptr [eax + 2], dl         
  0x003BA6CD  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003BA6D1  885003                  mov      byte ptr [eax + 3], dl         
  0x003BA6D4  8818                    mov      byte ptr [eax], bl             
  0x003BA6D6  0fbf590c                movsx    ebx, word ptr [ecx + 0xc]      
  0x003BA6DA  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA6DD  0fbf510a                movsx    edx, word ptr [ecx + 0xa]      
  0x003BA6E1  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003BA6E4  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003BA6E8  0fbf590e                movsx    ebx, word ptr [ecx + 0xe]      
  0x003BA6EC  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA6EF  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003BA6F3  0fbf5908                movsx    ebx, word ptr [ecx + 8]        
  0x003BA6F7  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA6FA  885005                  mov      byte ptr [eax + 5], dl         
  0x003BA6FD  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003BA701  885006                  mov      byte ptr [eax + 6], dl         
  0x003BA704  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003BA708  885007                  mov      byte ptr [eax + 7], dl         
  0x003BA70B  885804                  mov      byte ptr [eax + 4], bl         
  0x003BA70E  0fbf5914                movsx    ebx, word ptr [ecx + 0x14]     
  0x003BA712  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA715  0fbf5112                movsx    edx, word ptr [ecx + 0x12]     
  0x003BA719  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003BA71C  83c110                  add      ecx, 0x10                      
  0x003BA71F  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003BA723  0fbf5906                movsx    ebx, word ptr [ecx + 6]        
  0x003BA727  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA72A  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003BA72E  0fbf19                  movsx    ebx, word ptr [ecx]            
  0x003BA731  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA734  88543801                mov      byte ptr [eax + edi + 1], dl   
  0x003BA738  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003BA73C  88543802                mov      byte ptr [eax + edi + 2], dl   
  0x003BA740  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003BA744  88543803                mov      byte ptr [eax + edi + 3], dl   
  0x003BA748  881c38                  mov      byte ptr [eax + edi], bl       
  0x003BA74B  0fbf590c                movsx    ebx, word ptr [ecx + 0xc]      
  0x003BA74F  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA752  0fbf510a                movsx    edx, word ptr [ecx + 0xa]      
  0x003BA756  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003BA759  03c7                    add      eax, edi                       
  0x003BA75B  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003BA75F  0fbf590e                movsx    ebx, word ptr [ecx + 0xe]      
  0x003BA763  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA766  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003BA76A  0fbf5908                movsx    ebx, word ptr [ecx + 8]        
  0x003BA76E  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA771  885005                  mov      byte ptr [eax + 5], dl         
  0x003BA774  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003BA778  885006                  mov      byte ptr [eax + 6], dl         
  0x003BA77B  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003BA77F  885007                  mov      byte ptr [eax + 7], dl         
  0x003BA782  885804                  mov      byte ptr [eax + 4], bl         
  0x003BA785  0fbf5914                movsx    ebx, word ptr [ecx + 0x14]     
  0x003BA789  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA78C  0fbf5112                movsx    edx, word ptr [ecx + 0x12]     
  0x003BA790  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003BA793  83c110                  add      ecx, 0x10                      
  0x003BA796  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003BA79A  0fbf5906                movsx    ebx, word ptr [ecx + 6]        
  0x003BA79E  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA7A1  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003BA7A5  0fbf19                  movsx    ebx, word ptr [ecx]            
  0x003BA7A8  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA7AB  03c7                    add      eax, edi                       
  0x003BA7AD  885001                  mov      byte ptr [eax + 1], dl         
  0x003BA7B0  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003BA7B4  8818                    mov      byte ptr [eax], bl             
  0x003BA7B6  885002                  mov      byte ptr [eax + 2], dl         
  0x003BA7B9  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003BA7BD  885003                  mov      byte ptr [eax + 3], dl         
  0x003BA7C0  0fbf590c                movsx    ebx, word ptr [ecx + 0xc]      
  0x003BA7C4  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA7C7  0fbf510a                movsx    edx, word ptr [ecx + 0xa]      
  0x003BA7CB  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003BA7CE  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003BA7D2  0fbf590e                movsx    ebx, word ptr [ecx + 0xe]      
  0x003BA7D6  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA7D9  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003BA7DD  0fbf5908                movsx    ebx, word ptr [ecx + 8]        
  0x003BA7E1  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA7E4  885005                  mov      byte ptr [eax + 5], dl         
  0x003BA7E7  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003BA7EB  885006                  mov      byte ptr [eax + 6], dl         
  0x003BA7EE  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003BA7F2  885007                  mov      byte ptr [eax + 7], dl         
  0x003BA7F5  885804                  mov      byte ptr [eax + 4], bl         
  0x003BA7F8  0fbf5914                movsx    ebx, word ptr [ecx + 0x14]     
  0x003BA7FC  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA7FF  0fbf5112                movsx    edx, word ptr [ecx + 0x12]     
  0x003BA803  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003BA806  83c110                  add      ecx, 0x10                      
  0x003BA809  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003BA80D  0fbf5906                movsx    ebx, word ptr [ecx + 6]        
  0x003BA811  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA814  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003BA818  0fbf19                  movsx    ebx, word ptr [ecx]            
  0x003BA81B  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA81E  88543801                mov      byte ptr [eax + edi + 1], dl   
  0x003BA822  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003BA826  03c7                    add      eax, edi                       
  0x003BA828  885002                  mov      byte ptr [eax + 2], dl         
  0x003BA82B  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003BA82F  885003                  mov      byte ptr [eax + 3], dl         
  0x003BA832  8818                    mov      byte ptr [eax], bl             
  0x003BA834  0fbf590c                movsx    ebx, word ptr [ecx + 0xc]      
  0x003BA838  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA83B  0fbf510a                movsx    edx, word ptr [ecx + 0xa]      
  0x003BA83F  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003BA842  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003BA846  0fbf590e                movsx    ebx, word ptr [ecx + 0xe]      
  0x003BA84A  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA84D  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003BA851  0fbf5908                movsx    ebx, word ptr [ecx + 8]        
  0x003BA855  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003BA858  885005                  mov      byte ptr [eax + 5], dl         
  0x003BA85B  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003BA85F  885006                  mov      byte ptr [eax + 6], dl         
  0x003BA862  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003BA866  885804                  mov      byte ptr [eax + 4], bl         
  0x003BA869  885007                  mov      byte ptr [eax + 7], dl         
  0x003BA86C  83c110                  add      ecx, 0x10                      
  0x003BA86F  03c7                    add      eax, edi                       
  0x003BA871  4d                      dec      ebp                            
  0x003BA872  0f8528feffff            jne      0x3ba6a0                       
                                        ; XREF: 0x003BA68C (jump)
  0x003BA878  ff4c2410                dec      dword ptr [esp + 0x10]         
  0x003BA87C  0f8571fdffff            jne      0x3ba5f3                       
  0x003BA882  5f                      pop      edi                            
  0x003BA883  5d                      pop      ebp                            
  0x003BA884  5b                      pop      ebx                            
  0x003BA885  83c40c                  add      esp, 0xc                       
  0x003BA888  c3                      ret                                     
; end of function
  0x003BA889  cc                      int3                                    
  0x003BA88A  cc                      int3                                    
  0x003BA88B  cc                      int3                                    
  0x003BA88C  cc                      int3                                    
  0x003BA88D  cc                      int3                                    
  0x003BA88E  cc                      int3                                    
  0x003BA88F  cc                      int3                                    

; ============================================================
; Function: sub_003BA890
; Start: 0x003BA890  End: 0x003BAB66  Size: 726 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_003BB710
; ============================================================
sub_003BA890:
  0x003BA890  83ec0c                  sub      esp, 0xc                       
  0x003BA893  8b4808                  mov      ecx, dword ptr [eax + 8]       
  0x003BA896  53                      push     ebx                            
  0x003BA897  55                      push     ebp                            
  0x003BA898  56                      push     esi                            
  0x003BA899  8b7004                  mov      esi, dword ptr [eax + 4]       
  0x003BA89C  57                      push     edi                            
  0x003BA89D  8b38                    mov      edi, dword ptr [eax]           
  0x003BA89F  83c204                  add      edx, 4                         
  0x003BA8A2  c744241406000000        mov      dword ptr [esp + 0x14], 6      
  0x003BA8AA  8d9b00000000            lea      ebx, [ebx]                     
                                        ; XREF: 0x003BAB58 (cond_jump)
  0x003BA8B0  8b02                    mov      eax, dword ptr [edx]           
  0x003BA8B2  8b6a04                  mov      ebp, dword ptr [edx + 4]       
  0x003BA8B5  8b5c2420                mov      ebx, dword ptr [esp + 0x20]    
  0x003BA8B9  83c204                  add      edx, 4                         
  0x003BA8BC  83c204                  add      edx, 4                         
  0x003BA8BF  85db                    test     ebx, ebx                       
  0x003BA8C1  89542418                mov      dword ptr [esp + 0x18], edx    
  0x003BA8C5  7c42                    jl       0x3ba909                       
  0x003BA8C7  dd01                    fld      qword ptr [ecx]                
  0x003BA8C9  81c680000000            add      esi, 0x80                      
  0x003BA8CF  dd18                    fstp     qword ptr [eax]                
  0x003BA8D1  03c5                    add      eax, ebp                       
  0x003BA8D3  dd4108                  fld      qword ptr [ecx + 8]            
  0x003BA8D6  dd18                    fstp     qword ptr [eax]                
  0x003BA8D8  03c5                    add      eax, ebp                       
  0x003BA8DA  dd4110                  fld      qword ptr [ecx + 0x10]         
  0x003BA8DD  dd18                    fstp     qword ptr [eax]                
  0x003BA8DF  03c5                    add      eax, ebp                       
  0x003BA8E1  dd4118                  fld      qword ptr [ecx + 0x18]         
  0x003BA8E4  dd18                    fstp     qword ptr [eax]                
  0x003BA8E6  03c5                    add      eax, ebp                       
  0x003BA8E8  dd4120                  fld      qword ptr [ecx + 0x20]         
  0x003BA8EB  dd18                    fstp     qword ptr [eax]                
  0x003BA8ED  03c5                    add      eax, ebp                       
  0x003BA8EF  dd4128                  fld      qword ptr [ecx + 0x28]         
  0x003BA8F2  dd18                    fstp     qword ptr [eax]                
  0x003BA8F4  03c5                    add      eax, ebp                       
  0x003BA8F6  dd4130                  fld      qword ptr [ecx + 0x30]         
  0x003BA8F9  83c140                  add      ecx, 0x40                      
  0x003BA8FC  dd18                    fstp     qword ptr [eax]                
  0x003BA8FE  dd41f8                  fld      qword ptr [ecx - 8]            
  0x003BA901  dd1c28                  fstp     qword ptr [eax + ebp]          
  0x003BA904  e93c020000              jmp      0x3bab45                       
                                        ; XREF: 0x003BA8C5 (cond_jump)
  0x003BA909  c744241002000000        mov      dword ptr [esp + 0x10], 2      
                                        ; XREF: 0x003BAB3B (cond_jump)
  0x003BA911  0fb611                  movzx    edx, byte ptr [ecx]            
  0x003BA914  0fbf1e                  movsx    ebx, word ptr [esi]            
  0x003BA917  03d7                    add      edx, edi                       
  0x003BA919  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BA91C  8810                    mov      byte ptr [eax], dl             
  0x003BA91E  0fb65101                movzx    edx, byte ptr [ecx + 1]        
  0x003BA922  0fbf5e02                movsx    ebx, word ptr [esi + 2]        
  0x003BA926  03d7                    add      edx, edi                       
  0x003BA928  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BA92B  885001                  mov      byte ptr [eax + 1], dl         
  0x003BA92E  0fb65102                movzx    edx, byte ptr [ecx + 2]        
  0x003BA932  0fbf5e04                movsx    ebx, word ptr [esi + 4]        
  0x003BA936  03d7                    add      edx, edi                       
  0x003BA938  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BA93B  885002                  mov      byte ptr [eax + 2], dl         
  0x003BA93E  0fb65103                movzx    edx, byte ptr [ecx + 3]        
  0x003BA942  0fbf5e06                movsx    ebx, word ptr [esi + 6]        
  0x003BA946  03d7                    add      edx, edi                       
  0x003BA948  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BA94B  885003                  mov      byte ptr [eax + 3], dl         
  0x003BA94E  0fb65104                movzx    edx, byte ptr [ecx + 4]        
  0x003BA952  0fbf5e08                movsx    ebx, word ptr [esi + 8]        
  0x003BA956  03d7                    add      edx, edi                       
  0x003BA958  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BA95B  885004                  mov      byte ptr [eax + 4], dl         
  0x003BA95E  0fb65105                movzx    edx, byte ptr [ecx + 5]        
  0x003BA962  0fbf5e0a                movsx    ebx, word ptr [esi + 0xa]      
  0x003BA966  03d7                    add      edx, edi                       
  0x003BA968  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BA96B  885005                  mov      byte ptr [eax + 5], dl         
  0x003BA96E  0fb65106                movzx    edx, byte ptr [ecx + 6]        
  0x003BA972  0fbf5e0c                movsx    ebx, word ptr [esi + 0xc]      
  0x003BA976  03d7                    add      edx, edi                       
  0x003BA978  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BA97B  885006                  mov      byte ptr [eax + 6], dl         
  0x003BA97E  0fb65107                movzx    edx, byte ptr [ecx + 7]        
  0x003BA982  0fbf5e0e                movsx    ebx, word ptr [esi + 0xe]      
  0x003BA986  03d7                    add      edx, edi                       
  0x003BA988  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BA98B  885007                  mov      byte ptr [eax + 7], dl         
  0x003BA98E  0fb65108                movzx    edx, byte ptr [ecx + 8]        
  0x003BA992  0fbf5e10                movsx    ebx, word ptr [esi + 0x10]     
  0x003BA996  03d7                    add      edx, edi                       
  0x003BA998  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BA99B  881428                  mov      byte ptr [eax + ebp], dl       
  0x003BA99E  0fb65109                movzx    edx, byte ptr [ecx + 9]        
  0x003BA9A2  0fbf5e12                movsx    ebx, word ptr [esi + 0x12]     
  0x003BA9A6  83c108                  add      ecx, 8                         
  0x003BA9A9  83c610                  add      esi, 0x10                      
  0x003BA9AC  03d7                    add      edx, edi                       
  0x003BA9AE  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BA9B1  88542801                mov      byte ptr [eax + ebp + 1], dl   
  0x003BA9B5  0fb65102                movzx    edx, byte ptr [ecx + 2]        
  0x003BA9B9  0fbf5e04                movsx    ebx, word ptr [esi + 4]        
  0x003BA9BD  03c5                    add      eax, ebp                       
  0x003BA9BF  03d7                    add      edx, edi                       
  0x003BA9C1  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BA9C4  885002                  mov      byte ptr [eax + 2], dl         
  0x003BA9C7  0fb65103                movzx    edx, byte ptr [ecx + 3]        
  0x003BA9CB  0fbf5e06                movsx    ebx, word ptr [esi + 6]        
  0x003BA9CF  03d7                    add      edx, edi                       
  0x003BA9D1  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BA9D4  885003                  mov      byte ptr [eax + 3], dl         
  0x003BA9D7  0fb65104                movzx    edx, byte ptr [ecx + 4]        
  0x003BA9DB  0fbf5e08                movsx    ebx, word ptr [esi + 8]        
  0x003BA9DF  03d7                    add      edx, edi                       
  0x003BA9E1  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BA9E4  885004                  mov      byte ptr [eax + 4], dl         
  0x003BA9E7  0fb65105                movzx    edx, byte ptr [ecx + 5]        
  0x003BA9EB  0fbf5e0a                movsx    ebx, word ptr [esi + 0xa]      
  0x003BA9EF  03d7                    add      edx, edi                       
  0x003BA9F1  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BA9F4  885005                  mov      byte ptr [eax + 5], dl         
  0x003BA9F7  0fb65106                movzx    edx, byte ptr [ecx + 6]        
  0x003BA9FB  0fbf5e0c                movsx    ebx, word ptr [esi + 0xc]      
  0x003BA9FF  03d7                    add      edx, edi                       
  0x003BAA01  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAA04  885006                  mov      byte ptr [eax + 6], dl         
  0x003BAA07  0fb65107                movzx    edx, byte ptr [ecx + 7]        
  0x003BAA0B  0fbf5e0e                movsx    ebx, word ptr [esi + 0xe]      
  0x003BAA0F  03d7                    add      edx, edi                       
  0x003BAA11  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAA14  885007                  mov      byte ptr [eax + 7], dl         
  0x003BAA17  0fb65108                movzx    edx, byte ptr [ecx + 8]        
  0x003BAA1B  0fbf5e10                movsx    ebx, word ptr [esi + 0x10]     
  0x003BAA1F  03d7                    add      edx, edi                       
  0x003BAA21  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAA24  881428                  mov      byte ptr [eax + ebp], dl       
  0x003BAA27  0fb65109                movzx    edx, byte ptr [ecx + 9]        
  0x003BAA2B  0fbf5e12                movsx    ebx, word ptr [esi + 0x12]     
  0x003BAA2F  03d7                    add      edx, edi                       
  0x003BAA31  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAA34  88542801                mov      byte ptr [eax + ebp + 1], dl   
  0x003BAA38  0fb6510a                movzx    edx, byte ptr [ecx + 0xa]      
  0x003BAA3C  0fbf5e14                movsx    ebx, word ptr [esi + 0x14]     
  0x003BAA40  03d7                    add      edx, edi                       
  0x003BAA42  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAA45  88542802                mov      byte ptr [eax + ebp + 2], dl   
  0x003BAA49  0fb6510b                movzx    edx, byte ptr [ecx + 0xb]      
  0x003BAA4D  0fbf5e16                movsx    ebx, word ptr [esi + 0x16]     
  0x003BAA51  83c108                  add      ecx, 8                         
  0x003BAA54  83c610                  add      esi, 0x10                      
  0x003BAA57  03c5                    add      eax, ebp                       
  0x003BAA59  03d7                    add      edx, edi                       
  0x003BAA5B  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAA5E  885003                  mov      byte ptr [eax + 3], dl         
  0x003BAA61  0fb65104                movzx    edx, byte ptr [ecx + 4]        
  0x003BAA65  0fbf5e08                movsx    ebx, word ptr [esi + 8]        
  0x003BAA69  03d7                    add      edx, edi                       
  0x003BAA6B  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAA6E  885004                  mov      byte ptr [eax + 4], dl         
  0x003BAA71  0fb65105                movzx    edx, byte ptr [ecx + 5]        
  0x003BAA75  0fbf5e0a                movsx    ebx, word ptr [esi + 0xa]      
  0x003BAA79  03d7                    add      edx, edi                       
  0x003BAA7B  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAA7E  885005                  mov      byte ptr [eax + 5], dl         
  0x003BAA81  0fb65106                movzx    edx, byte ptr [ecx + 6]        
  0x003BAA85  0fbf5e0c                movsx    ebx, word ptr [esi + 0xc]      
  0x003BAA89  03d7                    add      edx, edi                       
  0x003BAA8B  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAA8E  885006                  mov      byte ptr [eax + 6], dl         
  0x003BAA91  0fb65107                movzx    edx, byte ptr [ecx + 7]        
  0x003BAA95  0fbf5e0e                movsx    ebx, word ptr [esi + 0xe]      
  0x003BAA99  03d7                    add      edx, edi                       
  0x003BAA9B  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAA9E  885007                  mov      byte ptr [eax + 7], dl         
  0x003BAAA1  0fb65108                movzx    edx, byte ptr [ecx + 8]        
  0x003BAAA5  0fbf5e10                movsx    ebx, word ptr [esi + 0x10]     
  0x003BAAA9  03d7                    add      edx, edi                       
  0x003BAAAB  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAAAE  881428                  mov      byte ptr [eax + ebp], dl       
  0x003BAAB1  0fb65109                movzx    edx, byte ptr [ecx + 9]        
  0x003BAAB5  0fbf5e12                movsx    ebx, word ptr [esi + 0x12]     
  0x003BAAB9  83c108                  add      ecx, 8                         
  0x003BAABC  83c610                  add      esi, 0x10                      
  0x003BAABF  03d7                    add      edx, edi                       
  0x003BAAC1  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAAC4  88542801                mov      byte ptr [eax + ebp + 1], dl   
  0x003BAAC8  0fb65102                movzx    edx, byte ptr [ecx + 2]        
  0x003BAACC  0fbf5e04                movsx    ebx, word ptr [esi + 4]        
  0x003BAAD0  03c5                    add      eax, ebp                       
  0x003BAAD2  03d7                    add      edx, edi                       
  0x003BAAD4  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAAD7  885002                  mov      byte ptr [eax + 2], dl         
  0x003BAADA  0fb65103                movzx    edx, byte ptr [ecx + 3]        
  0x003BAADE  0fbf5e06                movsx    ebx, word ptr [esi + 6]        
  0x003BAAE2  03d7                    add      edx, edi                       
  0x003BAAE4  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAAE7  885003                  mov      byte ptr [eax + 3], dl         
  0x003BAAEA  0fb65104                movzx    edx, byte ptr [ecx + 4]        
  0x003BAAEE  0fbf5e08                movsx    ebx, word ptr [esi + 8]        
  0x003BAAF2  03d7                    add      edx, edi                       
  0x003BAAF4  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAAF7  885004                  mov      byte ptr [eax + 4], dl         
  0x003BAAFA  0fb65105                movzx    edx, byte ptr [ecx + 5]        
  0x003BAAFE  0fbf5e0a                movsx    ebx, word ptr [esi + 0xa]      
  0x003BAB02  03d7                    add      edx, edi                       
  0x003BAB04  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAB07  885005                  mov      byte ptr [eax + 5], dl         
  0x003BAB0A  0fb65106                movzx    edx, byte ptr [ecx + 6]        
  0x003BAB0E  0fbf5e0c                movsx    ebx, word ptr [esi + 0xc]      
  0x003BAB12  03d7                    add      edx, edi                       
  0x003BAB14  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAB17  885006                  mov      byte ptr [eax + 6], dl         
  0x003BAB1A  0fb65107                movzx    edx, byte ptr [ecx + 7]        
  0x003BAB1E  0fbf5e0e                movsx    ebx, word ptr [esi + 0xe]      
  0x003BAB22  03d7                    add      edx, edi                       
  0x003BAB24  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAB27  885007                  mov      byte ptr [eax + 7], dl         
  0x003BAB2A  8b542410                mov      edx, dword ptr [esp + 0x10]    
  0x003BAB2E  83c108                  add      ecx, 8                         
  0x003BAB31  83c610                  add      esi, 0x10                      
  0x003BAB34  03c5                    add      eax, ebp                       
  0x003BAB36  4a                      dec      edx                            
  0x003BAB37  89542410                mov      dword ptr [esp + 0x10], edx    
  0x003BAB3B  0f85d0fdffff            jne      0x3ba911                       
  0x003BAB41  8b542418                mov      edx, dword ptr [esp + 0x18]    
                                        ; XREF: 0x003BA904 (jump)
  0x003BAB45  8b5c2420                mov      ebx, dword ptr [esp + 0x20]    
  0x003BAB49  8b442414                mov      eax, dword ptr [esp + 0x14]    
  0x003BAB4D  d1e3                    shl      ebx, 1                         
  0x003BAB4F  48                      dec      eax                            
  0x003BAB50  895c2420                mov      dword ptr [esp + 0x20], ebx    
  0x003BAB54  89442414                mov      dword ptr [esp + 0x14], eax    
  0x003BAB58  0f8552fdffff            jne      0x3ba8b0                       
  0x003BAB5E  5f                      pop      edi                            
  0x003BAB5F  5e                      pop      esi                            
  0x003BAB60  5d                      pop      ebp                            
  0x003BAB61  5b                      pop      ebx                            
  0x003BAB62  83c40c                  add      esp, 0xc                       
  0x003BAB65  c3                      ret                                     
; end of function
  0x003BAB66  cc                      int3                                    
  0x003BAB67  cc                      int3                                    
  0x003BAB68  cc                      int3                                    
  0x003BAB69  cc                      int3                                    
  0x003BAB6A  cc                      int3                                    
  0x003BAB6B  cc                      int3                                    
  0x003BAB6C  cc                      int3                                    
  0x003BAB6D  cc                      int3                                    
  0x003BAB6E  cc                      int3                                    
  0x003BAB6F  cc                      int3                                    

; ============================================================
; Function: sub_003BAB70
; Start: 0x003BAB70  End: 0x003BAF2F  Size: 959 bytes
; Detection: call_target (confidence: 0.90)
; ============================================================
sub_003BAB70:
  0x003BAB70  83ec10                  sub      esp, 0x10                      
  0x003BAB73  8b4808                  mov      ecx, dword ptr [eax + 8]       
  0x003BAB76  53                      push     ebx                            
  0x003BAB77  55                      push     ebp                            
  0x003BAB78  8b28                    mov      ebp, dword ptr [eax]           
  0x003BAB7A  56                      push     esi                            
  0x003BAB7B  8b700c                  mov      esi, dword ptr [eax + 0xc]     
  0x003BAB7E  57                      push     edi                            
  0x003BAB7F  8b7804                  mov      edi, dword ptr [eax + 4]       
  0x003BAB82  83c204                  add      edx, 4                         
  0x003BAB85  c744241c06000000        mov      dword ptr [esp + 0x1c], 6      
  0x003BAB8D  8d4900                  lea      ecx, [ecx]                     
                                        ; XREF: 0x003BAF21 (cond_jump)
  0x003BAB90  8b02                    mov      eax, dword ptr [edx]           
  0x003BAB92  8b5a04                  mov      ebx, dword ptr [edx + 4]       
  0x003BAB95  83c204                  add      edx, 4                         
  0x003BAB98  83c204                  add      edx, 4                         
  0x003BAB9B  89542418                mov      dword ptr [esp + 0x18], edx    
  0x003BAB9F  8b542424                mov      edx, dword ptr [esp + 0x24]    
  0x003BABA3  85d2                    test     edx, edx                       
  0x003BABA5  895c2410                mov      dword ptr [esp + 0x10], ebx    
  0x003BABA9  0f8c69020000            jl       0x3bae18                       
  0x003BABAF  81c780000000            add      edi, 0x80                      
  0x003BABB5  c744241402000000        mov      dword ptr [esp + 0x14], 2      
  0x003BABBD  8d4900                  lea      ecx, [ecx]                     
                                        ; XREF: 0x003BAE0D (cond_jump)
  0x003BABC0  0fb619                  movzx    ebx, byte ptr [ecx]            
  0x003BABC3  0fb616                  movzx    edx, byte ptr [esi]            
  0x003BABC6  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BABCA  d1fa                    sar      edx, 1                         
  0x003BABCC  8810                    mov      byte ptr [eax], dl             
  0x003BABCE  0fb65901                movzx    ebx, byte ptr [ecx + 1]        
  0x003BABD2  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003BABD6  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BABDA  d1fa                    sar      edx, 1                         
  0x003BABDC  885001                  mov      byte ptr [eax + 1], dl         
  0x003BABDF  0fb65902                movzx    ebx, byte ptr [ecx + 2]        
  0x003BABE3  0fb65602                movzx    edx, byte ptr [esi + 2]        
  0x003BABE7  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BABEB  d1fa                    sar      edx, 1                         
  0x003BABED  885002                  mov      byte ptr [eax + 2], dl         
  0x003BABF0  0fb65903                movzx    ebx, byte ptr [ecx + 3]        
  0x003BABF4  0fb65603                movzx    edx, byte ptr [esi + 3]        
  0x003BABF8  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BABFC  d1fa                    sar      edx, 1                         
  0x003BABFE  885003                  mov      byte ptr [eax + 3], dl         
  0x003BAC01  0fb65904                movzx    ebx, byte ptr [ecx + 4]        
  0x003BAC05  0fb65604                movzx    edx, byte ptr [esi + 4]        
  0x003BAC09  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAC0D  d1fa                    sar      edx, 1                         
  0x003BAC0F  885004                  mov      byte ptr [eax + 4], dl         
  0x003BAC12  0fb65905                movzx    ebx, byte ptr [ecx + 5]        
  0x003BAC16  0fb65605                movzx    edx, byte ptr [esi + 5]        
  0x003BAC1A  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAC1E  d1fa                    sar      edx, 1                         
  0x003BAC20  885005                  mov      byte ptr [eax + 5], dl         
  0x003BAC23  0fb65906                movzx    ebx, byte ptr [ecx + 6]        
  0x003BAC27  0fb65606                movzx    edx, byte ptr [esi + 6]        
  0x003BAC2B  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAC2F  d1fa                    sar      edx, 1                         
  0x003BAC31  885006                  mov      byte ptr [eax + 6], dl         
  0x003BAC34  0fb65907                movzx    ebx, byte ptr [ecx + 7]        
  0x003BAC38  0fb65607                movzx    edx, byte ptr [esi + 7]        
  0x003BAC3C  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAC40  d1fa                    sar      edx, 1                         
  0x003BAC42  885007                  mov      byte ptr [eax + 7], dl         
  0x003BAC45  0fb65908                movzx    ebx, byte ptr [ecx + 8]        
  0x003BAC49  03442410                add      eax, dword ptr [esp + 0x10]    
  0x003BAC4D  0fb65608                movzx    edx, byte ptr [esi + 8]        
  0x003BAC51  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAC55  d1fa                    sar      edx, 1                         
  0x003BAC57  8810                    mov      byte ptr [eax], dl             
  0x003BAC59  0fb65909                movzx    ebx, byte ptr [ecx + 9]        
  0x003BAC5D  0fb65609                movzx    edx, byte ptr [esi + 9]        
  0x003BAC61  83c108                  add      ecx, 8                         
  0x003BAC64  83c608                  add      esi, 8                         
  0x003BAC67  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAC6B  d1fa                    sar      edx, 1                         
  0x003BAC6D  885001                  mov      byte ptr [eax + 1], dl         
  0x003BAC70  0fb65902                movzx    ebx, byte ptr [ecx + 2]        
  0x003BAC74  0fb65602                movzx    edx, byte ptr [esi + 2]        
  0x003BAC78  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAC7C  d1fa                    sar      edx, 1                         
  0x003BAC7E  885002                  mov      byte ptr [eax + 2], dl         
  0x003BAC81  0fb65903                movzx    ebx, byte ptr [ecx + 3]        
  0x003BAC85  0fb65603                movzx    edx, byte ptr [esi + 3]        
  0x003BAC89  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAC8D  d1fa                    sar      edx, 1                         
  0x003BAC8F  885003                  mov      byte ptr [eax + 3], dl         
  0x003BAC92  0fb65904                movzx    ebx, byte ptr [ecx + 4]        
  0x003BAC96  0fb65604                movzx    edx, byte ptr [esi + 4]        
  0x003BAC9A  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAC9E  d1fa                    sar      edx, 1                         
  0x003BACA0  885004                  mov      byte ptr [eax + 4], dl         
  0x003BACA3  0fb65905                movzx    ebx, byte ptr [ecx + 5]        
  0x003BACA7  0fb65605                movzx    edx, byte ptr [esi + 5]        
  0x003BACAB  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BACAF  d1fa                    sar      edx, 1                         
  0x003BACB1  885005                  mov      byte ptr [eax + 5], dl         
  0x003BACB4  0fb65906                movzx    ebx, byte ptr [ecx + 6]        
  0x003BACB8  0fb65606                movzx    edx, byte ptr [esi + 6]        
  0x003BACBC  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BACC0  d1fa                    sar      edx, 1                         
  0x003BACC2  885006                  mov      byte ptr [eax + 6], dl         
  0x003BACC5  0fb65607                movzx    edx, byte ptr [esi + 7]        
  0x003BACC9  0fb65907                movzx    ebx, byte ptr [ecx + 7]        
  0x003BACCD  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BACD1  d1fa                    sar      edx, 1                         
  0x003BACD3  885007                  mov      byte ptr [eax + 7], dl         
  0x003BACD6  0fb65908                movzx    ebx, byte ptr [ecx + 8]        
  0x003BACDA  03442410                add      eax, dword ptr [esp + 0x10]    
  0x003BACDE  0fb65608                movzx    edx, byte ptr [esi + 8]        
  0x003BACE2  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BACE6  d1fa                    sar      edx, 1                         
  0x003BACE8  8810                    mov      byte ptr [eax], dl             
  0x003BACEA  0fb65909                movzx    ebx, byte ptr [ecx + 9]        
  0x003BACEE  0fb65609                movzx    edx, byte ptr [esi + 9]        
  0x003BACF2  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BACF6  d1fa                    sar      edx, 1                         
  0x003BACF8  885001                  mov      byte ptr [eax + 1], dl         
  0x003BACFB  0fb6590a                movzx    ebx, byte ptr [ecx + 0xa]      
  0x003BACFF  0fb6560a                movzx    edx, byte ptr [esi + 0xa]      
  0x003BAD03  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAD07  83c108                  add      ecx, 8                         
  0x003BAD0A  83c608                  add      esi, 8                         
  0x003BAD0D  d1fa                    sar      edx, 1                         
  0x003BAD0F  885002                  mov      byte ptr [eax + 2], dl         
  0x003BAD12  0fb65903                movzx    ebx, byte ptr [ecx + 3]        
  0x003BAD16  0fb65603                movzx    edx, byte ptr [esi + 3]        
  0x003BAD1A  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAD1E  d1fa                    sar      edx, 1                         
  0x003BAD20  885003                  mov      byte ptr [eax + 3], dl         
  0x003BAD23  0fb65904                movzx    ebx, byte ptr [ecx + 4]        
  0x003BAD27  0fb65604                movzx    edx, byte ptr [esi + 4]        
  0x003BAD2B  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAD2F  d1fa                    sar      edx, 1                         
  0x003BAD31  885004                  mov      byte ptr [eax + 4], dl         
  0x003BAD34  0fb65905                movzx    ebx, byte ptr [ecx + 5]        
  0x003BAD38  0fb65605                movzx    edx, byte ptr [esi + 5]        
  0x003BAD3C  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAD40  d1fa                    sar      edx, 1                         
  0x003BAD42  885005                  mov      byte ptr [eax + 5], dl         
  0x003BAD45  0fb65906                movzx    ebx, byte ptr [ecx + 6]        
  0x003BAD49  0fb65606                movzx    edx, byte ptr [esi + 6]        
  0x003BAD4D  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAD51  d1fa                    sar      edx, 1                         
  0x003BAD53  885006                  mov      byte ptr [eax + 6], dl         
  0x003BAD56  0fb65907                movzx    ebx, byte ptr [ecx + 7]        
  0x003BAD5A  0fb65607                movzx    edx, byte ptr [esi + 7]        
  0x003BAD5E  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAD62  d1fa                    sar      edx, 1                         
  0x003BAD64  885007                  mov      byte ptr [eax + 7], dl         
  0x003BAD67  0fb65908                movzx    ebx, byte ptr [ecx + 8]        
  0x003BAD6B  03442410                add      eax, dword ptr [esp + 0x10]    
  0x003BAD6F  0fb65608                movzx    edx, byte ptr [esi + 8]        
  0x003BAD73  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAD77  d1fa                    sar      edx, 1                         
  0x003BAD79  8810                    mov      byte ptr [eax], dl             
  0x003BAD7B  0fb65909                movzx    ebx, byte ptr [ecx + 9]        
  0x003BAD7F  0fb65609                movzx    edx, byte ptr [esi + 9]        
  0x003BAD83  83c108                  add      ecx, 8                         
  0x003BAD86  83c608                  add      esi, 8                         
  0x003BAD89  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAD8D  d1fa                    sar      edx, 1                         
  0x003BAD8F  885001                  mov      byte ptr [eax + 1], dl         
  0x003BAD92  0fb65902                movzx    ebx, byte ptr [ecx + 2]        
  0x003BAD96  0fb65602                movzx    edx, byte ptr [esi + 2]        
  0x003BAD9A  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAD9E  d1fa                    sar      edx, 1                         
  0x003BADA0  885002                  mov      byte ptr [eax + 2], dl         
  0x003BADA3  0fb65903                movzx    ebx, byte ptr [ecx + 3]        
  0x003BADA7  0fb65603                movzx    edx, byte ptr [esi + 3]        
  0x003BADAB  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BADAF  d1fa                    sar      edx, 1                         
  0x003BADB1  885003                  mov      byte ptr [eax + 3], dl         
  0x003BADB4  0fb65904                movzx    ebx, byte ptr [ecx + 4]        
  0x003BADB8  0fb65604                movzx    edx, byte ptr [esi + 4]        
  0x003BADBC  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BADC0  d1fa                    sar      edx, 1                         
  0x003BADC2  885004                  mov      byte ptr [eax + 4], dl         
  0x003BADC5  0fb65605                movzx    edx, byte ptr [esi + 5]        
  0x003BADC9  0fb65905                movzx    ebx, byte ptr [ecx + 5]        
  0x003BADCD  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BADD1  d1fa                    sar      edx, 1                         
  0x003BADD3  885005                  mov      byte ptr [eax + 5], dl         
  0x003BADD6  0fb65906                movzx    ebx, byte ptr [ecx + 6]        
  0x003BADDA  0fb65606                movzx    edx, byte ptr [esi + 6]        
  0x003BADDE  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BADE2  d1fa                    sar      edx, 1                         
  0x003BADE4  885006                  mov      byte ptr [eax + 6], dl         
  0x003BADE7  0fb65907                movzx    ebx, byte ptr [ecx + 7]        
  0x003BADEB  0fb65607                movzx    edx, byte ptr [esi + 7]        
  0x003BADEF  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BADF3  8b5c2410                mov      ebx, dword ptr [esp + 0x10]    
  0x003BADF7  d1fa                    sar      edx, 1                         
  0x003BADF9  885007                  mov      byte ptr [eax + 7], dl         
  0x003BADFC  8b542414                mov      edx, dword ptr [esp + 0x14]    
  0x003BAE00  83c108                  add      ecx, 8                         
  0x003BAE03  83c608                  add      esi, 8                         
  0x003BAE06  03c3                    add      eax, ebx                       
  0x003BAE08  4a                      dec      edx                            
  0x003BAE09  89542414                mov      dword ptr [esp + 0x14], edx    
  0x003BAE0D  0f85adfdffff            jne      0x3babc0                       
  0x003BAE13  e9f2000000              jmp      0x3baf0a                       
                                        ; XREF: 0x003BABA9 (cond_jump)
  0x003BAE18  c744241408000000        mov      dword ptr [esp + 0x14], 8      
                                        ; XREF: 0x003BAF04 (cond_jump)
  0x003BAE20  0fb619                  movzx    ebx, byte ptr [ecx]            
  0x003BAE23  0fb616                  movzx    edx, byte ptr [esi]            
  0x003BAE26  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAE2A  0fbf1f                  movsx    ebx, word ptr [edi]            
  0x003BAE2D  d1fa                    sar      edx, 1                         
  0x003BAE2F  03d5                    add      edx, ebp                       
  0x003BAE31  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAE34  8810                    mov      byte ptr [eax], dl             
  0x003BAE36  0fb65901                movzx    ebx, byte ptr [ecx + 1]        
  0x003BAE3A  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003BAE3E  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAE42  0fbf5f02                movsx    ebx, word ptr [edi + 2]        
  0x003BAE46  d1fa                    sar      edx, 1                         
  0x003BAE48  03d5                    add      edx, ebp                       
  0x003BAE4A  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAE4D  885001                  mov      byte ptr [eax + 1], dl         
  0x003BAE50  0fb65902                movzx    ebx, byte ptr [ecx + 2]        
  0x003BAE54  0fb65602                movzx    edx, byte ptr [esi + 2]        
  0x003BAE58  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAE5C  0fbf5f04                movsx    ebx, word ptr [edi + 4]        
  0x003BAE60  d1fa                    sar      edx, 1                         
  0x003BAE62  03d5                    add      edx, ebp                       
  0x003BAE64  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAE67  885002                  mov      byte ptr [eax + 2], dl         
  0x003BAE6A  0fb65903                movzx    ebx, byte ptr [ecx + 3]        
  0x003BAE6E  0fb65603                movzx    edx, byte ptr [esi + 3]        
  0x003BAE72  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAE76  0fbf5f06                movsx    ebx, word ptr [edi + 6]        
  0x003BAE7A  d1fa                    sar      edx, 1                         
  0x003BAE7C  03d5                    add      edx, ebp                       
  0x003BAE7E  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAE81  885003                  mov      byte ptr [eax + 3], dl         
  0x003BAE84  0fb65904                movzx    ebx, byte ptr [ecx + 4]        
  0x003BAE88  0fb65604                movzx    edx, byte ptr [esi + 4]        
  0x003BAE8C  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAE90  0fbf5f08                movsx    ebx, word ptr [edi + 8]        
  0x003BAE94  d1fa                    sar      edx, 1                         
  0x003BAE96  03d5                    add      edx, ebp                       
  0x003BAE98  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAE9B  885004                  mov      byte ptr [eax + 4], dl         
  0x003BAE9E  0fb65905                movzx    ebx, byte ptr [ecx + 5]        
  0x003BAEA2  0fb65605                movzx    edx, byte ptr [esi + 5]        
  0x003BAEA6  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAEAA  0fbf5f0a                movsx    ebx, word ptr [edi + 0xa]      
  0x003BAEAE  d1fa                    sar      edx, 1                         
  0x003BAEB0  03d5                    add      edx, ebp                       
  0x003BAEB2  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAEB5  885005                  mov      byte ptr [eax + 5], dl         
  0x003BAEB8  0fb65906                movzx    ebx, byte ptr [ecx + 6]        
  0x003BAEBC  0fb65606                movzx    edx, byte ptr [esi + 6]        
  0x003BAEC0  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAEC4  0fbf5f0c                movsx    ebx, word ptr [edi + 0xc]      
  0x003BAEC8  d1fa                    sar      edx, 1                         
  0x003BAECA  03d5                    add      edx, ebp                       
  0x003BAECC  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAECF  885006                  mov      byte ptr [eax + 6], dl         
  0x003BAED2  0fb65907                movzx    ebx, byte ptr [ecx + 7]        
  0x003BAED6  0fb65607                movzx    edx, byte ptr [esi + 7]        
  0x003BAEDA  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003BAEDE  0fbf5f0e                movsx    ebx, word ptr [edi + 0xe]      
  0x003BAEE2  d1fa                    sar      edx, 1                         
  0x003BAEE4  03d5                    add      edx, ebp                       
  0x003BAEE6  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003BAEE9  8b5c2410                mov      ebx, dword ptr [esp + 0x10]    
  0x003BAEED  885007                  mov      byte ptr [eax + 7], dl         
  0x003BAEF0  8b542414                mov      edx, dword ptr [esp + 0x14]    
  0x003BAEF4  83c108                  add      ecx, 8                         
  0x003BAEF7  83c608                  add      esi, 8                         
  0x003BAEFA  83c710                  add      edi, 0x10                      
  0x003BAEFD  03c3                    add      eax, ebx                       
  0x003BAEFF  4a                      dec      edx                            
  0x003BAF00  89542414                mov      dword ptr [esp + 0x14], edx    
  0x003BAF04  0f8516ffffff            jne      0x3bae20                       
                                        ; XREF: 0x003BAE13 (jump)
  0x003BAF0A  8b5c2424                mov      ebx, dword ptr [esp + 0x24]    
  0x003BAF0E  8b44241c                mov      eax, dword ptr [esp + 0x1c]    
  0x003BAF12  8b542418                mov      edx, dword ptr [esp + 0x18]    
  0x003BAF16  d1e3                    shl      ebx, 1                         
  0x003BAF18  48                      dec      eax                            
  0x003BAF19  895c2424                mov      dword ptr [esp + 0x24], ebx    
  0x003BAF1D  8944241c                mov      dword ptr [esp + 0x1c], eax    
  0x003BAF21  0f8569fcffff            jne      0x3bab90                       
  0x003BAF27  5f                      pop      edi                            
  0x003BAF28  5e                      pop      esi                            
  0x003BAF29  5d                      pop      ebp                            
  0x003BAF2A  5b                      pop      ebx                            
  0x003BAF2B  83c410                  add      esp, 0x10                      
  0x003BAF2E  c3                      ret                                     
; end of function
  0x003BAF2F  cc                      int3                                    

; ============================================================
; Function: sub_003BAF30
; Start: 0x003BAF30  End: 0x003BB338  Size: 1032 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_003BB650
; ============================================================
sub_003BAF30:
  0x003BAF30  8b4c2404                mov      ecx, dword ptr [esp + 4]       
  0x003BAF34  55                      push     ebp                            
  0x003BAF35  8b6c240c                mov      ebp, dword ptr [esp + 0xc]     
  0x003BAF39  0fbf450c                movsx    eax, word ptr [ebp + 0xc]      
  0x003BAF3D  99                      cdq                                     
  0x003BAF3E  83e207                  and      edx, 7                         
  0x003BAF41  03c2                    add      eax, edx                       
  0x003BAF43  8b11                    mov      edx, dword ptr [ecx]           
  0x003BAF45  56                      push     esi                            
  0x003BAF46  c1f803                  sar      eax, 3                         
  0x003BAF49  57                      push     edi                            
  0x003BAF4A  8d3c00                  lea      edi, [eax + eax]               
  0x003BAF4D  c1e703                  shl      edi, 3                         
  0x003BAF50  f6c21f                  test     dl, 0x1f                       
  0x003BAF53  0f85d8000000            jne      0x3bb031                       
  0x003BAF59  8b33                    mov      esi, dword ptr [ebx]           
  0x003BAF5B  dd0416                  fld      qword ptr [esi + edx]          
  0x003BAF5E  8b4d00                  mov      ecx, dword ptr [ebp]           
  0x003BAF61  0f180c11                prefetcht0 byte ptr [ecx + edx]           
  0x003BAF65  03ca                    add      ecx, edx                       
  0x003BAF67  0f180cc1                prefetcht0 byte ptr [ecx + eax*8]         
  0x003BAF6B  03f2                    add      esi, edx                       
  0x003BAF6D  dd04c6                  fld      qword ptr [esi + eax*8]        
  0x003BAF70  03f7                    add      esi, edi                       
  0x003BAF72  d9c9                    fxch     st(1)                          
  0x003BAF74  dd19                    fstp     qword ptr [ecx]                
  0x003BAF76  dd1cc1                  fstp     qword ptr [ecx + eax*8]        
  0x003BAF79  0f180c39                prefetcht0 byte ptr [ecx + edi]           
  0x003BAF7D  dd06                    fld      qword ptr [esi]                
  0x003BAF7F  03cf                    add      ecx, edi                       
  0x003BAF81  0f180cc1                prefetcht0 byte ptr [ecx + eax*8]         
  0x003BAF85  dd04c6                  fld      qword ptr [esi + eax*8]        
  0x003BAF88  03f7                    add      esi, edi                       
  0x003BAF8A  d9c9                    fxch     st(1)                          
  0x003BAF8C  dd19                    fstp     qword ptr [ecx]                
  0x003BAF8E  dd1cc1                  fstp     qword ptr [ecx + eax*8]        
  0x003BAF91  0f180c39                prefetcht0 byte ptr [ecx + edi]           
  0x003BAF95  dd06                    fld      qword ptr [esi]                
  0x003BAF97  03cf                    add      ecx, edi                       
  0x003BAF99  0f180cc1                prefetcht0 byte ptr [ecx + eax*8]         
  0x003BAF9D  dd04c6                  fld      qword ptr [esi + eax*8]        
  0x003BAFA0  d9c9                    fxch     st(1)                          
  0x003BAFA2  03f7                    add      esi, edi                       
  0x003BAFA4  dd19                    fstp     qword ptr [ecx]                
  0x003BAFA6  dd1cc1                  fstp     qword ptr [ecx + eax*8]        
  0x003BAFA9  0f180c39                prefetcht0 byte ptr [ecx + edi]           
  0x003BAFAD  dd04c6                  fld      qword ptr [esi + eax*8]        
  0x003BAFB0  03cf                    add      ecx, edi                       
  0x003BAFB2  0f180cc1                prefetcht0 byte ptr [ecx + eax*8]         
  0x003BAFB6  dd06                    fld      qword ptr [esi]                
  0x003BAFB8  dd19                    fstp     qword ptr [ecx]                
  0x003BAFBA  8d14c1                  lea      edx, [ecx + eax*8]             
  0x003BAFBD  dd1a                    fstp     qword ptr [edx]                
  0x003BAFBF  8b4d04                  mov      ecx, dword ptr [ebp + 4]       
  0x003BAFC2  8b542410                mov      edx, dword ptr [esp + 0x10]    
  0x003BAFC6  8b32                    mov      esi, dword ptr [edx]           
  0x003BAFC8  8b5304                  mov      edx, dword ptr [ebx + 4]       
  0x003BAFCB  dd0432                  fld      qword ptr [edx + esi]          
  0x003BAFCE  0f180c31                prefetcht0 byte ptr [ecx + esi]           
  0x003BAFD2  03d6                    add      edx, esi                       
  0x003BAFD4  dd04c2                  fld      qword ptr [edx + eax*8]        
  0x003BAFD7  03ce                    add      ecx, esi                       
  0x003BAFD9  0f180cc1                prefetcht0 byte ptr [ecx + eax*8]         
  0x003BAFDD  d9c9                    fxch     st(1)                          
  0x003BAFDF  dd19                    fstp     qword ptr [ecx]                
  0x003BAFE1  03d7                    add      edx, edi                       
  0x003BAFE3  dd1cc1                  fstp     qword ptr [ecx + eax*8]        
  0x003BAFE6  0f180c39                prefetcht0 byte ptr [ecx + edi]           
  0x003BAFEA  dd02                    fld      qword ptr [edx]                
  0x003BAFEC  03cf                    add      ecx, edi                       
  0x003BAFEE  dd04c2                  fld      qword ptr [edx + eax*8]        
  0x003BAFF1  0f180cc1                prefetcht0 byte ptr [ecx + eax*8]         
  0x003BAFF5  d9c9                    fxch     st(1)                          
  0x003BAFF7  03d7                    add      edx, edi                       
  0x003BAFF9  dd19                    fstp     qword ptr [ecx]                
  0x003BAFFB  dd1cc1                  fstp     qword ptr [ecx + eax*8]        
  0x003BAFFE  0f180c39                prefetcht0 byte ptr [ecx + edi]           
  0x003BB002  dd02                    fld      qword ptr [edx]                
  0x003BB004  03cf                    add      ecx, edi                       
  0x003BB006  dd04c2                  fld      qword ptr [edx + eax*8]        
  0x003BB009  0f180cc1                prefetcht0 byte ptr [ecx + eax*8]         
  0x003BB00D  d9c9                    fxch     st(1)                          
  0x003BB00F  03d7                    add      edx, edi                       
  0x003BB011  dd19                    fstp     qword ptr [ecx]                
  0x003BB013  dd1cc1                  fstp     qword ptr [ecx + eax*8]        
  0x003BB016  0f180c39                prefetcht0 byte ptr [ecx + edi]           
  0x003BB01A  dd04c2                  fld      qword ptr [edx + eax*8]        
  0x003BB01D  03cf                    add      ecx, edi                       
  0x003BB01F  dd02                    fld      qword ptr [edx]                
  0x003BB021  0f180cc1                prefetcht0 byte ptr [ecx + eax*8]         
  0x003BB025  8d34c1                  lea      esi, [ecx + eax*8]             
  0x003BB028  dd19                    fstp     qword ptr [ecx]                
  0x003BB02A  dd1e                    fstp     qword ptr [esi]                
  0x003BB02C  e98f000000              jmp      0x3bb0c0                       
                                        ; XREF: 0x003BAF53 (cond_jump)
  0x003BB031  8b0b                    mov      ecx, dword ptr [ebx]           
  0x003BB033  dd0411                  fld      qword ptr [ecx + edx]          
  0x003BB036  8b7500                  mov      esi, dword ptr [ebp]           
  0x003BB039  03ca                    add      ecx, edx                       
  0x003BB03B  dd04c1                  fld      qword ptr [ecx + eax*8]        
  0x003BB03E  03f2                    add      esi, edx                       
  0x003BB040  03cf                    add      ecx, edi                       
  0x003BB042  d9c9                    fxch     st(1)                          
  0x003BB044  dd1e                    fstp     qword ptr [esi]                
  0x003BB046  dd1cc6                  fstp     qword ptr [esi + eax*8]        
  0x003BB049  03f7                    add      esi, edi                       
  0x003BB04B  dd01                    fld      qword ptr [ecx]                
  0x003BB04D  dd04c1                  fld      qword ptr [ecx + eax*8]        
  0x003BB050  03cf                    add      ecx, edi                       
  0x003BB052  d9c9                    fxch     st(1)                          
  0x003BB054  dd1e                    fstp     qword ptr [esi]                
  0x003BB056  dd1cc6                  fstp     qword ptr [esi + eax*8]        
  0x003BB059  03f7                    add      esi, edi                       
  0x003BB05B  dd01                    fld      qword ptr [ecx]                
  0x003BB05D  dd04c1                  fld      qword ptr [ecx + eax*8]        
  0x003BB060  03cf                    add      ecx, edi                       
  0x003BB062  d9c9                    fxch     st(1)                          
  0x003BB064  dd1e                    fstp     qword ptr [esi]                
  0x003BB066  dd1cc6                  fstp     qword ptr [esi + eax*8]        
  0x003BB069  03f7                    add      esi, edi                       
  0x003BB06B  dd04c1                  fld      qword ptr [ecx + eax*8]        
  0x003BB06E  dd01                    fld      qword ptr [ecx]                
  0x003BB070  8b4c2410                mov      ecx, dword ptr [esp + 0x10]    
  0x003BB074  dd1e                    fstp     qword ptr [esi]                
  0x003BB076  dd1cc6                  fstp     qword ptr [esi + eax*8]        
  0x003BB079  8b31                    mov      esi, dword ptr [ecx]           
  0x003BB07B  8b4b04                  mov      ecx, dword ptr [ebx + 4]       
  0x003BB07E  dd0431                  fld      qword ptr [ecx + esi]          
  0x003BB081  8b5504                  mov      edx, dword ptr [ebp + 4]       
  0x003BB084  03ce                    add      ecx, esi                       
  0x003BB086  dd04c1                  fld      qword ptr [ecx + eax*8]        
  0x003BB089  03d6                    add      edx, esi                       
  0x003BB08B  03cf                    add      ecx, edi                       
  0x003BB08D  d9c9                    fxch     st(1)                          
  0x003BB08F  dd1a                    fstp     qword ptr [edx]                
  0x003BB091  dd1cc2                  fstp     qword ptr [edx + eax*8]        
  0x003BB094  03d7                    add      edx, edi                       
  0x003BB096  dd01                    fld      qword ptr [ecx]                
  0x003BB098  dd04c1                  fld      qword ptr [ecx + eax*8]        
  0x003BB09B  03cf                    add      ecx, edi                       
  0x003BB09D  d9c9                    fxch     st(1)                          
  0x003BB09F  dd1a                    fstp     qword ptr [edx]                
  0x003BB0A1  dd1cc2                  fstp     qword ptr [edx + eax*8]        
  0x003BB0A4  03d7                    add      edx, edi                       
  0x003BB0A6  dd01                    fld      qword ptr [ecx]                
  0x003BB0A8  dd04c1                  fld      qword ptr [ecx + eax*8]        
  0x003BB0AB  03cf                    add      ecx, edi                       
  0x003BB0AD  d9c9                    fxch     st(1)                          
  0x003BB0AF  dd1a                    fstp     qword ptr [edx]                
  0x003BB0B1  dd1cc2                  fstp     qword ptr [edx + eax*8]        
  0x003BB0B4  03d7                    add      edx, edi                       
  0x003BB0B6  dd04c1                  fld      qword ptr [ecx + eax*8]        
  0x003BB0B9  dd01                    fld      qword ptr [ecx]                
  0x003BB0BB  dd1a                    fstp     qword ptr [edx]                
  0x003BB0BD  dd1cc2                  fstp     qword ptr [edx + eax*8]        
                                        ; XREF: 0x003BB02C (jump)
  0x003BB0C0  0fbf450e                movsx    eax, word ptr [ebp + 0xe]      
  0x003BB0C4  8b4c2410                mov      ecx, dword ptr [esp + 0x10]    
  0x003BB0C8  8b7104                  mov      esi, dword ptr [ecx + 4]       
  0x003BB0CB  99                      cdq                                     
  0x003BB0CC  83e207                  and      edx, 7                         
  0x003BB0CF  03c2                    add      eax, edx                       
  0x003BB0D1  8a5104                  mov      dl, byte ptr [ecx + 4]         
  0x003BB0D4  c1f803                  sar      eax, 3                         
  0x003BB0D7  c1e003                  shl      eax, 3                         
  0x003BB0DA  f6c21f                  test     dl, 0x1f                       
  0x003BB0DD  0f854b010000            jne      0x3bb22e                       
  0x003BB0E3  8b5308                  mov      edx, dword ptr [ebx + 8]       
  0x003BB0E6  dd0432                  fld      qword ptr [edx + esi]          
  0x003BB0E9  8b4d08                  mov      ecx, dword ptr [ebp + 8]       
  0x003BB0EC  dd443208                fld      qword ptr [edx + esi + 8]      
  0x003BB0F0  0f180c31                prefetcht0 byte ptr [ecx + esi]           
  0x003BB0F4  03d6                    add      edx, esi                       
  0x003BB0F6  d9c9                    fxch     st(1)                          
  0x003BB0F8  dd1c31                  fstp     qword ptr [ecx + esi]          
  0x003BB0FB  03ce                    add      ecx, esi                       
  0x003BB0FD  03d0                    add      edx, eax                       
  0x003BB0FF  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003BB102  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003BB106  dd02                    fld      qword ptr [edx]                
  0x003BB108  03c8                    add      ecx, eax                       
  0x003BB10A  dd4208                  fld      qword ptr [edx + 8]            
  0x003BB10D  03d0                    add      edx, eax                       
  0x003BB10F  d9c9                    fxch     st(1)                          
  0x003BB111  dd19                    fstp     qword ptr [ecx]                
  0x003BB113  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003BB116  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003BB11A  dd02                    fld      qword ptr [edx]                
  0x003BB11C  03c8                    add      ecx, eax                       
  0x003BB11E  dd4208                  fld      qword ptr [edx + 8]            
  0x003BB121  03d0                    add      edx, eax                       
  0x003BB123  d9c9                    fxch     st(1)                          
  0x003BB125  dd19                    fstp     qword ptr [ecx]                
  0x003BB127  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003BB12A  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003BB12E  dd02                    fld      qword ptr [edx]                
  0x003BB130  03c8                    add      ecx, eax                       
  0x003BB132  dd4208                  fld      qword ptr [edx + 8]            
  0x003BB135  03d0                    add      edx, eax                       
  0x003BB137  d9c9                    fxch     st(1)                          
  0x003BB139  dd19                    fstp     qword ptr [ecx]                
  0x003BB13B  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003BB13E  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003BB142  dd02                    fld      qword ptr [edx]                
  0x003BB144  03c8                    add      ecx, eax                       
  0x003BB146  dd4208                  fld      qword ptr [edx + 8]            
  0x003BB149  03d0                    add      edx, eax                       
  0x003BB14B  d9c9                    fxch     st(1)                          
  0x003BB14D  dd19                    fstp     qword ptr [ecx]                
  0x003BB14F  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003BB152  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003BB156  dd02                    fld      qword ptr [edx]                
  0x003BB158  03c8                    add      ecx, eax                       
  0x003BB15A  dd4208                  fld      qword ptr [edx + 8]            
  0x003BB15D  03d0                    add      edx, eax                       
  0x003BB15F  d9c9                    fxch     st(1)                          
  0x003BB161  dd19                    fstp     qword ptr [ecx]                
  0x003BB163  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003BB166  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003BB16A  dd02                    fld      qword ptr [edx]                
  0x003BB16C  03c8                    add      ecx, eax                       
  0x003BB16E  dd4208                  fld      qword ptr [edx + 8]            
  0x003BB171  03d0                    add      edx, eax                       
  0x003BB173  d9c9                    fxch     st(1)                          
  0x003BB175  dd19                    fstp     qword ptr [ecx]                
  0x003BB177  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003BB17A  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003BB17E  dd02                    fld      qword ptr [edx]                
  0x003BB180  03c8                    add      ecx, eax                       
  0x003BB182  dd4208                  fld      qword ptr [edx + 8]            
  0x003BB185  03d0                    add      edx, eax                       
  0x003BB187  d9c9                    fxch     st(1)                          
  0x003BB189  dd19                    fstp     qword ptr [ecx]                
  0x003BB18B  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003BB18E  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003BB192  dd02                    fld      qword ptr [edx]                
  0x003BB194  03c8                    add      ecx, eax                       
  0x003BB196  dd4208                  fld      qword ptr [edx + 8]            
  0x003BB199  03d0                    add      edx, eax                       
  0x003BB19B  d9c9                    fxch     st(1)                          
  0x003BB19D  dd19                    fstp     qword ptr [ecx]                
  0x003BB19F  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003BB1A2  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003BB1A6  dd02                    fld      qword ptr [edx]                
  0x003BB1A8  03c8                    add      ecx, eax                       
  0x003BB1AA  dd4208                  fld      qword ptr [edx + 8]            
  0x003BB1AD  03d0                    add      edx, eax                       
  0x003BB1AF  d9c9                    fxch     st(1)                          
  0x003BB1B1  dd19                    fstp     qword ptr [ecx]                
  0x003BB1B3  5f                      pop      edi                            
  0x003BB1B4  5e                      pop      esi                            
  0x003BB1B5  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003BB1B8  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003BB1BC  dd02                    fld      qword ptr [edx]                
  0x003BB1BE  03c8                    add      ecx, eax                       
  0x003BB1C0  dd4208                  fld      qword ptr [edx + 8]            
  0x003BB1C3  03d0                    add      edx, eax                       
  0x003BB1C5  d9c9                    fxch     st(1)                          
  0x003BB1C7  5d                      pop      ebp                            
  0x003BB1C8  dd19                    fstp     qword ptr [ecx]                
  0x003BB1CA  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003BB1CD  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003BB1D1  dd02                    fld      qword ptr [edx]                
  0x003BB1D3  03c8                    add      ecx, eax                       
  0x003BB1D5  dd4208                  fld      qword ptr [edx + 8]            
  0x003BB1D8  03d0                    add      edx, eax                       
  0x003BB1DA  d9c9                    fxch     st(1)                          
  0x003BB1DC  dd19                    fstp     qword ptr [ecx]                
  0x003BB1DE  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003BB1E1  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003BB1E5  dd02                    fld      qword ptr [edx]                
  0x003BB1E7  03c8                    add      ecx, eax                       
  0x003BB1E9  dd4208                  fld      qword ptr [edx + 8]            
  0x003BB1EC  03d0                    add      edx, eax                       
  0x003BB1EE  d9c9                    fxch     st(1)                          
  0x003BB1F0  dd19                    fstp     qword ptr [ecx]                
  0x003BB1F2  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003BB1F5  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003BB1F9  dd02                    fld      qword ptr [edx]                
  0x003BB1FB  03c8                    add      ecx, eax                       
  0x003BB1FD  dd4208                  fld      qword ptr [edx + 8]            
  0x003BB200  03d0                    add      edx, eax                       
  0x003BB202  d9c9                    fxch     st(1)                          
  0x003BB204  dd19                    fstp     qword ptr [ecx]                
  0x003BB206  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003BB209  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003BB20D  dd02                    fld      qword ptr [edx]                
  0x003BB20F  03c8                    add      ecx, eax                       
  0x003BB211  dd4208                  fld      qword ptr [edx + 8]            
  0x003BB214  03d0                    add      edx, eax                       
  0x003BB216  d9c9                    fxch     st(1)                          
  0x003BB218  dd19                    fstp     qword ptr [ecx]                
  0x003BB21A  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003BB21D  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003BB221  dd4208                  fld      qword ptr [edx + 8]            
  0x003BB224  03c8                    add      ecx, eax                       
  0x003BB226  dd02                    fld      qword ptr [edx]                
  0x003BB228  dd19                    fstp     qword ptr [ecx]                
  0x003BB22A  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003BB22D  c3                      ret                                     
                                        ; XREF: 0x003BB0DD (cond_jump)
  0x003BB22E  8b4b08                  mov      ecx, dword ptr [ebx + 8]       
  0x003BB231  dd0431                  fld      qword ptr [ecx + esi]          
  0x003BB234  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x003BB237  dd443108                fld      qword ptr [ecx + esi + 8]      
  0x003BB23B  03ce                    add      ecx, esi                       
  0x003BB23D  03d6                    add      edx, esi                       
  0x003BB23F  d9c9                    fxch     st(1)                          
  0x003BB241  dd1a                    fstp     qword ptr [edx]                
  0x003BB243  03c8                    add      ecx, eax                       
  0x003BB245  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003BB248  03d0                    add      edx, eax                       
  0x003BB24A  dd01                    fld      qword ptr [ecx]                
  0x003BB24C  dd4108                  fld      qword ptr [ecx + 8]            
  0x003BB24F  03c8                    add      ecx, eax                       
  0x003BB251  d9c9                    fxch     st(1)                          
  0x003BB253  dd1a                    fstp     qword ptr [edx]                
  0x003BB255  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003BB258  03d0                    add      edx, eax                       
  0x003BB25A  dd01                    fld      qword ptr [ecx]                
  0x003BB25C  dd4108                  fld      qword ptr [ecx + 8]            
  0x003BB25F  03c8                    add      ecx, eax                       
  0x003BB261  d9c9                    fxch     st(1)                          
  0x003BB263  dd1a                    fstp     qword ptr [edx]                
  0x003BB265  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003BB268  03d0                    add      edx, eax                       
  0x003BB26A  dd01                    fld      qword ptr [ecx]                
  0x003BB26C  dd4108                  fld      qword ptr [ecx + 8]            
  0x003BB26F  03c8                    add      ecx, eax                       
  0x003BB271  d9c9                    fxch     st(1)                          
  0x003BB273  dd1a                    fstp     qword ptr [edx]                
  0x003BB275  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003BB278  03d0                    add      edx, eax                       
  0x003BB27A  dd01                    fld      qword ptr [ecx]                
  0x003BB27C  dd4108                  fld      qword ptr [ecx + 8]            
  0x003BB27F  03c8                    add      ecx, eax                       
  0x003BB281  d9c9                    fxch     st(1)                          
  0x003BB283  dd1a                    fstp     qword ptr [edx]                
  0x003BB285  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003BB288  03d0                    add      edx, eax                       
  0x003BB28A  dd01                    fld      qword ptr [ecx]                
  0x003BB28C  dd4108                  fld      qword ptr [ecx + 8]            
  0x003BB28F  03c8                    add      ecx, eax                       
  0x003BB291  d9c9                    fxch     st(1)                          
  0x003BB293  dd1a                    fstp     qword ptr [edx]                
  0x003BB295  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003BB298  03d0                    add      edx, eax                       
  0x003BB29A  dd01                    fld      qword ptr [ecx]                
  0x003BB29C  dd4108                  fld      qword ptr [ecx + 8]            
  0x003BB29F  03c8                    add      ecx, eax                       
  0x003BB2A1  d9c9                    fxch     st(1)                          
  0x003BB2A3  dd1a                    fstp     qword ptr [edx]                
  0x003BB2A5  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003BB2A8  03d0                    add      edx, eax                       
  0x003BB2AA  dd01                    fld      qword ptr [ecx]                
  0x003BB2AC  dd4108                  fld      qword ptr [ecx + 8]            
  0x003BB2AF  03c8                    add      ecx, eax                       
  0x003BB2B1  d9c9                    fxch     st(1)                          
  0x003BB2B3  dd1a                    fstp     qword ptr [edx]                
  0x003BB2B5  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003BB2B8  03d0                    add      edx, eax                       
  0x003BB2BA  dd01                    fld      qword ptr [ecx]                
  0x003BB2BC  dd4108                  fld      qword ptr [ecx + 8]            
  0x003BB2BF  03c8                    add      ecx, eax                       
  0x003BB2C1  d9c9                    fxch     st(1)                          
  0x003BB2C3  dd1a                    fstp     qword ptr [edx]                
  0x003BB2C5  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003BB2C8  03d0                    add      edx, eax                       
  0x003BB2CA  dd01                    fld      qword ptr [ecx]                
  0x003BB2CC  dd4108                  fld      qword ptr [ecx + 8]            
  0x003BB2CF  03c8                    add      ecx, eax                       
  0x003BB2D1  d9c9                    fxch     st(1)                          
  0x003BB2D3  dd1a                    fstp     qword ptr [edx]                
  0x003BB2D5  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003BB2D8  03d0                    add      edx, eax                       
  0x003BB2DA  dd01                    fld      qword ptr [ecx]                
  0x003BB2DC  dd4108                  fld      qword ptr [ecx + 8]            
  0x003BB2DF  03c8                    add      ecx, eax                       
  0x003BB2E1  d9c9                    fxch     st(1)                          
  0x003BB2E3  dd1a                    fstp     qword ptr [edx]                
  0x003BB2E5  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003BB2E8  03d0                    add      edx, eax                       
  0x003BB2EA  dd01                    fld      qword ptr [ecx]                
  0x003BB2EC  5f                      pop      edi                            
  0x003BB2ED  dd4108                  fld      qword ptr [ecx + 8]            
  0x003BB2F0  03c8                    add      ecx, eax                       
  0x003BB2F2  d9c9                    fxch     st(1)                          
  0x003BB2F4  5e                      pop      esi                            
  0x003BB2F5  dd1a                    fstp     qword ptr [edx]                
  0x003BB2F7  5d                      pop      ebp                            
  0x003BB2F8  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003BB2FB  03d0                    add      edx, eax                       
  0x003BB2FD  dd01                    fld      qword ptr [ecx]                
  0x003BB2FF  dd4108                  fld      qword ptr [ecx + 8]            
  0x003BB302  03c8                    add      ecx, eax                       
  0x003BB304  d9c9                    fxch     st(1)                          
  0x003BB306  dd1a                    fstp     qword ptr [edx]                
  0x003BB308  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003BB30B  03d0                    add      edx, eax                       
  0x003BB30D  dd01                    fld      qword ptr [ecx]                
  0x003BB30F  dd4108                  fld      qword ptr [ecx + 8]            
  0x003BB312  03c8                    add      ecx, eax                       
  0x003BB314  d9c9                    fxch     st(1)                          
  0x003BB316  dd1a                    fstp     qword ptr [edx]                
  0x003BB318  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003BB31B  03d0                    add      edx, eax                       
  0x003BB31D  dd01                    fld      qword ptr [ecx]                
  0x003BB31F  dd4108                  fld      qword ptr [ecx + 8]            
  0x003BB322  03c8                    add      ecx, eax                       
  0x003BB324  d9c9                    fxch     st(1)                          
  0x003BB326  dd1a                    fstp     qword ptr [edx]                
  0x003BB328  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003BB32B  03d0                    add      edx, eax                       
  0x003BB32D  dd4108                  fld      qword ptr [ecx + 8]            
  0x003BB330  dd01                    fld      qword ptr [ecx]                
  0x003BB332  dd1a                    fstp     qword ptr [edx]                
  0x003BB334  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003BB337  c3                      ret                                     
; end of function
  0x003BB338  cc                      int3                                    
  0x003BB339  cc                      int3                                    
  0x003BB33A  cc                      int3                                    
  0x003BB33B  cc                      int3                                    
  0x003BB33C  cc                      int3                                    
  0x003BB33D  cc                      int3                                    
  0x003BB33E  cc                      int3                                    
  0x003BB33F  cc                      int3                                    

; ============================================================
; Function: sub_003BB340
; Start: 0x003BB340  End: 0x003BB373  Size: 51 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_003BB420, sub_003BB4A0, sub_003BB650
; ============================================================
sub_003BB340:
  0x003BB340  56                      push     esi                            
  0x003BB341  8bf0                    mov      esi, eax                       
  0x003BB343  8b8138030000            mov      eax, dword ptr [ecx + 0x338]   
  0x003BB349  8b893c030000            mov      ecx, dword ptr [ecx + 0x33c]   
  0x003BB34F  57                      push     edi                            
  0x003BB350  0fbf7e0c                movsx    edi, word ptr [esi + 0xc]      
  0x003BB354  c1e003                  shl      eax, 3                         
  0x003BB357  0faff8                  imul     edi, eax                       
  0x003BB35A  c1e103                  shl      ecx, 3                         
  0x003BB35D  03f9                    add      edi, ecx                       
  0x003BB35F  893a                    mov      dword ptr [edx], edi           
  0x003BB361  0fbf760e                movsx    esi, word ptr [esi + 0xe]      
  0x003BB365  03c0                    add      eax, eax                       
  0x003BB367  0faff0                  imul     esi, eax                       
  0x003BB36A  8d0c4e                  lea      ecx, [esi + ecx*2]             
  0x003BB36D  5f                      pop      edi                            
  0x003BB36E  894a04                  mov      dword ptr [edx + 4], ecx       
  0x003BB371  5e                      pop      esi                            
  0x003BB372  c3                      ret                                     
; end of function
  0x003BB373  cc                      int3                                    
  0x003BB374  cc                      int3                                    
  0x003BB375  cc                      int3                                    
  0x003BB376  cc                      int3                                    
  0x003BB377  cc                      int3                                    
  0x003BB378  cc                      int3                                    
  0x003BB379  cc                      int3                                    
  0x003BB37A  cc                      int3                                    
  0x003BB37B  cc                      int3                                    
  0x003BB37C  cc                      int3                                    
  0x003BB37D  cc                      int3                                    
  0x003BB37E  cc                      int3                                    
  0x003BB37F  cc                      int3                                    

; ============================================================
; Function: sub_003BB380
; Start: 0x003BB380  End: 0x003BB3D5  Size: 85 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_003BB650, sub_003BB6C0
; ============================================================
sub_003BB380:
  0x003BB380  56                      push     esi                            
  0x003BB381  8bb034030000            mov      esi, dword ptr [eax + 0x334]   
  0x003BB387  ba01000000              mov      edx, 1                         
  0x003BB38C  2bd1                    sub      edx, ecx                       
  0x003BB38E  03f2                    add      esi, edx                       
  0x003BB390  ba01000000              mov      edx, 1                         
  0x003BB395  2bd1                    sub      edx, ecx                       
  0x003BB397  8b883c030000            mov      ecx, dword ptr [eax + 0x33c]   
  0x003BB39D  03ca                    add      ecx, edx                       
  0x003BB39F  89b034030000            mov      dword ptr [eax + 0x334], esi   
  0x003BB3A5  89883c030000            mov      dword ptr [eax + 0x33c], ecx   
  0x003BB3AB  7926                    jns      0x3bb3d3                       
  0x003BB3AD  8b88d8010000            mov      ecx, dword ptr [eax + 0x1d8]   
  0x003BB3B3  8b903c030000            mov      edx, dword ptr [eax + 0x33c]   
  0x003BB3B9  8bb038030000            mov      esi, dword ptr [eax + 0x338]   
  0x003BB3BF  90                      nop                                     
                                        ; XREF: 0x003BB3C5 (cond_jump)
  0x003BB3C0  03d1                    add      edx, ecx                       
  0x003BB3C2  4e                      dec      esi                            
  0x003BB3C3  85d2                    test     edx, edx                       
  0x003BB3C5  7cf9                    jl       0x3bb3c0                       
  0x003BB3C7  89b038030000            mov      dword ptr [eax + 0x338], esi   
  0x003BB3CD  89903c030000            mov      dword ptr [eax + 0x33c], edx   
                                        ; XREF: 0x003BB3AB (cond_jump)
  0x003BB3D3  5e                      pop      esi                            
  0x003BB3D4  c3                      ret                                     
; end of function
  0x003BB3D5  cc                      int3                                    
  0x003BB3D6  cc                      int3                                    
  0x003BB3D7  cc                      int3                                    
  0x003BB3D8  cc                      int3                                    
  0x003BB3D9  cc                      int3                                    
  0x003BB3DA  cc                      int3                                    
  0x003BB3DB  cc                      int3                                    
  0x003BB3DC  cc                      int3                                    
  0x003BB3DD  cc                      int3                                    
  0x003BB3DE  cc                      int3                                    
  0x003BB3DF  cc                      int3                                    

; ============================================================
; Function: sub_003BB3E0
; Start: 0x003BB3E0  End: 0x003BB41C  Size: 60 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_003BB650, sub_003BB6C0
; ============================================================
sub_003BB3E0:
  0x003BB3E0  8b883c030000            mov      ecx, dword ptr [eax + 0x33c]   
  0x003BB3E6  8b90d8010000            mov      edx, dword ptr [eax + 0x1d8]   
  0x003BB3EC  41                      inc      ecx                            
  0x003BB3ED  89883c030000            mov      dword ptr [eax + 0x33c], ecx   
  0x003BB3F3  3bca                    cmp      ecx, edx                       
  0x003BB3F5  8b8834030000            mov      ecx, dword ptr [eax + 0x334]   
  0x003BB3FB  7c17                    jl       0x3bb414                       
  0x003BB3FD  8b9038030000            mov      edx, dword ptr [eax + 0x338]   
  0x003BB403  42                      inc      edx                            
  0x003BB404  c7803c03000000000000    mov      dword ptr [eax + 0x33c], 0     
  0x003BB40E  899038030000            mov      dword ptr [eax + 0x338], edx   
                                        ; XREF: 0x003BB3FB (cond_jump)
  0x003BB414  41                      inc      ecx                            
  0x003BB415  898834030000            mov      dword ptr [eax + 0x334], ecx   
  0x003BB41B  c3                      ret                                     
; end of function
  0x003BB41C  cc                      int3                                    
  0x003BB41D  cc                      int3                                    
  0x003BB41E  cc                      int3                                    
  0x003BB41F  cc                      int3                                    

; ============================================================
; Function: sub_003BB420
; Start: 0x003BB420  End: 0x003BB492  Size: 114 bytes
; Detection: cc_boundary (confidence: 0.85)
; Calls: sub_003BA5E0, sub_003BB340
; ============================================================
sub_003BB420:
  0x003BB420  83ec08                  sub      esp, 8                         
  0x003BB423  53                      push     ebx                            
  0x003BB424  8b5c2410                mov      ebx, dword ptr [esp + 0x10]    
  0x003BB428  56                      push     esi                            
  0x003BB429  8db394020000            lea      esi, [ebx + 0x294]             
  0x003BB42F  57                      push     edi                            
  0x003BB430  8d54240c                lea      edx, [esp + 0xc]               
  0x003BB434  8bc6                    mov      eax, esi                       
  0x003BB436  8bcb                    mov      ecx, ebx                       
  0x003BB438  8dbb20010000            lea      edi, [ebx + 0x120]             
  0x003BB43E  e8fdfeffff              call     0x3bb340                       ; -> sub_003BB340
  0x003BB443  8b16                    mov      edx, dword ptr [esi]           
  0x003BB445  0fbf4e0e                movsx    ecx, word ptr [esi + 0xe]      
  0x003BB449  8b44240c                mov      eax, dword ptr [esp + 0xc]     
  0x003BB44D  03d0                    add      edx, eax                       
  0x003BB44F  895704                  mov      dword ptr [edi + 4], edx       
  0x003BB452  8b5604                  mov      edx, dword ptr [esi + 4]       
  0x003BB455  03d0                    add      edx, eax                       
  0x003BB457  89570c                  mov      dword ptr [edi + 0xc], edx     
  0x003BB45A  8b4608                  mov      eax, dword ptr [esi + 8]       
  0x003BB45D  8b542410                mov      edx, dword ptr [esp + 0x10]    
  0x003BB461  03c2                    add      eax, edx                       
  0x003BB463  894714                  mov      dword ptr [edi + 0x14], eax    
  0x003BB466  83c008                  add      eax, 8                         
  0x003BB469  89471c                  mov      dword ptr [edi + 0x1c], eax    
  0x003BB46C  8b4714                  mov      eax, dword ptr [edi + 0x14]    
  0x003BB46F  8d04c8                  lea      eax, [eax + ecx*8]             
  0x003BB472  894724                  mov      dword ptr [edi + 0x24], eax    
  0x003BB475  83c008                  add      eax, 8                         
  0x003BB478  89472c                  mov      dword ptr [edi + 0x2c], eax    
  0x003BB47B  8b7340                  mov      esi, dword ptr [ebx + 0x40]    
  0x003BB47E  8d8b80030000            lea      ecx, [ebx + 0x380]             
  0x003BB484  8bd7                    mov      edx, edi                       
  0x003BB486  e855f1ffff              call     0x3ba5e0                       ; -> sub_003BA5E0
  0x003BB48B  5f                      pop      edi                            
  0x003BB48C  5e                      pop      esi                            
  0x003BB48D  5b                      pop      ebx                            
  0x003BB48E  83c408                  add      esp, 8                         
  0x003BB491  c3                      ret                                     
; end of function
  0x003BB492  cc                      int3                                    
  0x003BB493  cc                      int3                                    
  0x003BB494  cc                      int3                                    
  0x003BB495  cc                      int3                                    
  0x003BB496  cc                      int3                                    
  0x003BB497  cc                      int3                                    
  0x003BB498  cc                      int3                                    
  0x003BB499  cc                      int3                                    
  0x003BB49A  cc                      int3                                    
  0x003BB49B  cc                      int3                                    
  0x003BB49C  cc                      int3                                    
  0x003BB49D  cc                      int3                                    
  0x003BB49E  cc                      int3                                    
  0x003BB49F  cc                      int3                                    

; ============================================================
; Function: sub_003BB4A0
; Start: 0x003BB4A0  End: 0x003BB64A  Size: 426 bytes
; Detection: call_target (confidence: 0.90)
; Calls: sub_003BB340
; Called by: sub_003BB710
; ============================================================
sub_003BB4A0:
  0x003BB4A0  83ec14                  sub      esp, 0x14                      
  0x003BB4A3  8b4c2418                mov      ecx, dword ptr [esp + 0x18]    
  0x003BB4A7  53                      push     ebx                            
  0x003BB4A8  55                      push     ebp                            
  0x003BB4A9  8bd8                    mov      ebx, eax                       
  0x003BB4AB  8b44242c                mov      eax, dword ptr [esp + 0x2c]    
  0x003BB4AF  0fbf500c                movsx    edx, word ptr [eax + 0xc]      
  0x003BB4B3  56                      push     esi                            
  0x003BB4B4  8bb19c010000            mov      esi, dword ptr [ecx + 0x19c]   
  0x003BB4BA  57                      push     edi                            
  0x003BB4BB  0fbf780e                movsx    edi, word ptr [eax + 0xe]      
  0x003BB4BF  89542410                mov      dword ptr [esp + 0x10], edx    
  0x003BB4C3  8b542430                mov      edx, dword ptr [esp + 0x30]    
  0x003BB4C7  8974241c                mov      dword ptr [esp + 0x1c], esi    
  0x003BB4CB  897c2414                mov      dword ptr [esp + 0x14], edi    
  0x003BB4CF  e86cfeffff              call     0x3bb340                       ; -> sub_003BB340
  0x003BB4D4  8b4318                  mov      eax, dword ptr [ebx + 0x18]    
  0x003BB4D7  8b5b1c                  mov      ebx, dword ptr [ebx + 0x1c]    
  0x003BB4DA  8beb                    mov      ebp, ebx                       
  0x003BB4DC  8bc8                    mov      ecx, eax                       
  0x003BB4DE  d1fd                    sar      ebp, 1                         
  0x003BB4E0  0fafef                  imul     ebp, edi                       
  0x003BB4E3  8b7a04                  mov      edi, dword ptr [edx + 4]       
  0x003BB4E6  d1f9                    sar      ecx, 1                         
  0x003BB4E8  03e9                    add      ebp, ecx                       
  0x003BB4EA  8bd3                    mov      edx, ebx                       
  0x003BB4EC  83e201                  and      edx, 1                         
  0x003BB4EF  8d0c36                  lea      ecx, [esi + esi]               
  0x003BB4F2  03d1                    add      edx, ecx                       
  0x003BB4F4  03ef                    add      ebp, edi                       
  0x003BB4F6  8bf8                    mov      edi, eax                       
  0x003BB4F8  83e701                  and      edi, 1                         
  0x003BB4FB  8d0c57                  lea      ecx, [edi + edx*2]             
  0x003BB4FE  8b148d98bcf400          mov      edx, dword ptr [ecx*4 + 0xf4bc98] 
  0x003BB505  89542420                mov      dword ptr [esp + 0x20], edx    
  0x003BB509  99                      cdq                                     
  0x003BB50A  2bc2                    sub      eax, edx                       
  0x003BB50C  8bc8                    mov      ecx, eax                       
  0x003BB50E  8bc3                    mov      eax, ebx                       
  0x003BB510  99                      cdq                                     
  0x003BB511  2bc2                    sub      eax, edx                       
  0x003BB513  d1f8                    sar      eax, 1                         
  0x003BB515  8bd8                    mov      ebx, eax                       
  0x003BB517  d1fb                    sar      ebx, 1                         
  0x003BB519  0faf5c2410              imul     ebx, dword ptr [esp + 0x10]    
  0x003BB51E  d1f9                    sar      ecx, 1                         
  0x003BB520  8bd1                    mov      edx, ecx                       
  0x003BB522  d1fa                    sar      edx, 1                         
  0x003BB524  03da                    add      ebx, edx                       
  0x003BB526  8b542430                mov      edx, dword ptr [esp + 0x30]    
  0x003BB52A  031a                    add      ebx, dword ptr [edx]           
  0x003BB52C  83e001                  and      eax, 1                         
  0x003BB52F  8d1436                  lea      edx, [esi + esi]               
  0x003BB532  03c2                    add      eax, edx                       
  0x003BB534  83e101                  and      ecx, 1                         
  0x003BB537  8d0441                  lea      eax, [ecx + eax*2]             
  0x003BB53A  8b148598bcf400          mov      edx, dword ptr [eax*4 + 0xf4bc98] 
  0x003BB541  8b44242c                mov      eax, dword ptr [esp + 0x2c]    
  0x003BB545  23ce                    and      ecx, esi                       
  0x003BB547  8b742428                mov      esi, dword ptr [esp + 0x28]    
  0x003BB54B  81c6cc000000            add      esi, 0xcc                      
  0x003BB551  894618                  mov      dword ptr [esi + 0x18], eax    
  0x003BB554  8b442434                mov      eax, dword ptr [esp + 0x34]    
  0x003BB558  89542430                mov      dword ptr [esp + 0x30], edx    
  0x003BB55C  8b542410                mov      edx, dword ptr [esp + 0x10]    
  0x003BB560  895620                  mov      dword ptr [esi + 0x20], edx    
  0x003BB563  8b00                    mov      eax, dword ptr [eax]           
  0x003BB565  03c3                    add      eax, ebx                       
  0x003BB567  894624                  mov      dword ptr [esi + 0x24], eax    
  0x003BB56A  03c1                    add      eax, ecx                       
  0x003BB56C  03c2                    add      eax, edx                       
  0x003BB56E  56                      push     esi                            
  0x003BB56F  894c241c                mov      dword ptr [esp + 0x1c], ecx    
  0x003BB573  894628                  mov      dword ptr [esi + 0x28], eax    
  0x003BB576  ff542434                call     dword ptr [esp + 0x34]         
  0x003BB57A  8b4c2430                mov      ecx, dword ptr [esp + 0x30]    
  0x003BB57E  8b542438                mov      edx, dword ptr [esp + 0x38]    
  0x003BB582  83c140                  add      ecx, 0x40                      
  0x003BB585  894e18                  mov      dword ptr [esi + 0x18], ecx    
  0x003BB588  8b4204                  mov      eax, dword ptr [edx + 4]       
  0x003BB58B  03c3                    add      eax, ebx                       
  0x003BB58D  894624                  mov      dword ptr [esi + 0x24], eax    
  0x003BB590  8b4c241c                mov      ecx, dword ptr [esp + 0x1c]    
  0x003BB594  03c1                    add      eax, ecx                       
  0x003BB596  03442414                add      eax, dword ptr [esp + 0x14]    
  0x003BB59A  56                      push     esi                            
  0x003BB59B  894628                  mov      dword ptr [esi + 0x28], eax    
  0x003BB59E  ff542438                call     dword ptr [esp + 0x38]         
  0x003BB5A2  8b4c241c                mov      ecx, dword ptr [esp + 0x1c]    
  0x003BB5A6  8b5c2434                mov      ebx, dword ptr [esp + 0x34]    
  0x003BB5AA  8b44243c                mov      eax, dword ptr [esp + 0x3c]    
  0x003BB5AE  8d9380000000            lea      edx, [ebx + 0x80]              
  0x003BB5B4  894e20                  mov      dword ptr [esi + 0x20], ecx    
  0x003BB5B7  895618                  mov      dword ptr [esi + 0x18], edx    
  0x003BB5BA  8b4008                  mov      eax, dword ptr [eax + 8]       
  0x003BB5BD  03c5                    add      eax, ebp                       
  0x003BB5BF  237c2424                and      edi, dword ptr [esp + 0x24]    
  0x003BB5C3  03f8                    add      edi, eax                       
  0x003BB5C5  03f9                    add      edi, ecx                       
  0x003BB5C7  897e28                  mov      dword ptr [esi + 0x28], edi    
  0x003BB5CA  8b7c2428                mov      edi, dword ptr [esp + 0x28]    
  0x003BB5CE  56                      push     esi                            
  0x003BB5CF  894624                  mov      dword ptr [esi + 0x24], eax    
  0x003BB5D2  ffd7                    call     edi                            
  0x003BB5D4  8b4624                  mov      eax, dword ptr [esi + 0x24]    
  0x003BB5D7  8b5628                  mov      edx, dword ptr [esi + 0x28]    
  0x003BB5DA  bd08000000              mov      ebp, 8                         
  0x003BB5DF  8d8bc0000000            lea      ecx, [ebx + 0xc0]              
  0x003BB5E5  03c5                    add      eax, ebp                       
  0x003BB5E7  03d5                    add      edx, ebp                       
  0x003BB5E9  56                      push     esi                            
  0x003BB5EA  894e18                  mov      dword ptr [esi + 0x18], ecx    
  0x003BB5ED  894624                  mov      dword ptr [esi + 0x24], eax    
  0x003BB5F0  895628                  mov      dword ptr [esi + 0x28], edx    
  0x003BB5F3  ffd7                    call     edi                            
  0x003BB5F5  8b442424                mov      eax, dword ptr [esp + 0x24]    
  0x003BB5F9  8d9300010000            lea      edx, [ebx + 0x100]             
  0x003BB5FF  895618                  mov      dword ptr [esi + 0x18], edx    
  0x003BB602  8b5624                  mov      edx, dword ptr [esi + 0x24]    
  0x003BB605  8d0cc5f8ffffff          lea      ecx, [eax*8 - 8]               
  0x003BB60C  03d1                    add      edx, ecx                       
  0x003BB60E  895624                  mov      dword ptr [esi + 0x24], edx    
  0x003BB611  8d14c5f8ffffff          lea      edx, [eax*8 - 8]               
  0x003BB618  8b4628                  mov      eax, dword ptr [esi + 0x28]    
  0x003BB61B  03c2                    add      eax, edx                       
  0x003BB61D  56                      push     esi                            
  0x003BB61E  894628                  mov      dword ptr [esi + 0x28], eax    
  0x003BB621  ffd7                    call     edi                            
  0x003BB623  8b5628                  mov      edx, dword ptr [esi + 0x28]    
  0x003BB626  81c340010000            add      ebx, 0x140                     
  0x003BB62C  895e18                  mov      dword ptr [esi + 0x18], ebx    
  0x003BB62F  8b5e24                  mov      ebx, dword ptr [esi + 0x24]    
  0x003BB632  03d5                    add      edx, ebp                       
  0x003BB634  03dd                    add      ebx, ebp                       
  0x003BB636  56                      push     esi                            
  0x003BB637  895e24                  mov      dword ptr [esi + 0x24], ebx    
  0x003BB63A  895628                  mov      dword ptr [esi + 0x28], edx    
  0x003BB63D  ffd7                    call     edi                            
  0x003BB63F  83c418                  add      esp, 0x18                      
  0x003BB642  5f                      pop      edi                            
  0x003BB643  5e                      pop      esi                            
  0x003BB644  5d                      pop      ebp                            
  0x003BB645  5b                      pop      ebx                            
  0x003BB646  83c414                  add      esp, 0x14                      
  0x003BB649  c3                      ret                                     
; end of function
  0x003BB64A  cc                      int3                                    
  0x003BB64B  cc                      int3                                    
  0x003BB64C  cc                      int3                                    
  0x003BB64D  cc                      int3                                    
  0x003BB64E  cc                      int3                                    
  0x003BB64F  cc                      int3                                    

; ============================================================
; Function: sub_003BB650
; Start: 0x003BB650  End: 0x003BB6B2  Size: 98 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_003BAF30, sub_003BB340, sub_003BB380, sub_003BB3E0
; ============================================================
sub_003BB650:
  0x003BB650  55                      push     ebp                            
  0x003BB651  8bec                    mov      ebp, esp                       
  0x003BB653  83e4f8                  and      esp, 0xfffffff8                
  0x003BB656  83ec0c                  sub      esp, 0xc                       
  0x003BB659  8b4d0c                  mov      ecx, dword ptr [ebp + 0xc]     
  0x003BB65C  53                      push     ebx                            
  0x003BB65D  56                      push     esi                            
  0x003BB65E  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x003BB661  57                      push     edi                            
  0x003BB662  8bbe34030000            mov      edi, dword ptr [esi + 0x334]   
  0x003BB668  8bc6                    mov      eax, esi                       
  0x003BB66A  8d9e64020000            lea      ebx, [esi + 0x264]             
  0x003BB670  e80bfdffff              call     0x3bb380                       ; -> sub_003BB380
  0x003BB675  39be34030000            cmp      dword ptr [esi + 0x334], edi   
  0x003BB67B  7d2e                    jge      0x3bb6ab                       
  0x003BB67D  8d4900                  lea      ecx, [ecx]                     
                                        ; XREF: 0x003BB6A9 (cond_jump)
  0x003BB680  8d542410                lea      edx, [esp + 0x10]              
  0x003BB684  8bc3                    mov      eax, ebx                       
  0x003BB686  8bce                    mov      ecx, esi                       
  0x003BB688  e8b3fcffff              call     0x3bb340                       ; -> sub_003BB340
  0x003BB68D  8d4310                  lea      eax, [ebx + 0x10]              
  0x003BB690  50                      push     eax                            
  0x003BB691  8bc2                    mov      eax, edx                       
  0x003BB693  50                      push     eax                            
  0x003BB694  e897f8ffff              call     0x3baf30                       ; -> sub_003BAF30
  0x003BB699  83c408                  add      esp, 8                         
  0x003BB69C  8bc6                    mov      eax, esi                       
  0x003BB69E  e83dfdffff              call     0x3bb3e0                       ; -> sub_003BB3E0
  0x003BB6A3  39be34030000            cmp      dword ptr [esi + 0x334], edi   
  0x003BB6A9  7cd5                    jl       0x3bb680                       
                                        ; XREF: 0x003BB67B (cond_jump)
  0x003BB6AB  5f                      pop      edi                            
  0x003BB6AC  5e                      pop      esi                            
  0x003BB6AD  5b                      pop      ebx                            
  0x003BB6AE  8be5                    mov      esp, ebp                       
  0x003BB6B0  5d                      pop      ebp                            
  0x003BB6B1  c3                      ret                                     
; end of function
  0x003BB6B2  cc                      int3                                    
  0x003BB6B3  cc                      int3                                    
  0x003BB6B4  cc                      int3                                    
  0x003BB6B5  cc                      int3                                    
  0x003BB6B6  cc                      int3                                    
  0x003BB6B7  cc                      int3                                    
  0x003BB6B8  cc                      int3                                    
  0x003BB6B9  cc                      int3                                    
  0x003BB6BA  cc                      int3                                    
  0x003BB6BB  cc                      int3                                    
  0x003BB6BC  cc                      int3                                    
  0x003BB6BD  cc                      int3                                    
  0x003BB6BE  cc                      int3                                    
  0x003BB6BF  cc                      int3                                    

; ============================================================
; Function: sub_003BB6C0
; Start: 0x003BB6C0  End: 0x003BB709  Size: 73 bytes
; Detection: cc_boundary (confidence: 0.85)
; Calls: sub_003BB380, sub_003BB3E0
; ============================================================
sub_003BB6C0:
  0x003BB6C0  8b4c2408                mov      ecx, dword ptr [esp + 8]       
  0x003BB6C4  53                      push     ebx                            
  0x003BB6C5  56                      push     esi                            
  0x003BB6C6  8b74240c                mov      esi, dword ptr [esp + 0xc]     
  0x003BB6CA  8b9ed4020000            mov      ebx, dword ptr [esi + 0x2d4]   
  0x003BB6D0  57                      push     edi                            
  0x003BB6D1  8bbe34030000            mov      edi, dword ptr [esi + 0x334]   
  0x003BB6D7  8bc6                    mov      eax, esi                       
  0x003BB6D9  c7864803000000000000    mov      dword ptr [esi + 0x348], 0     
  0x003BB6E3  e898fcffff              call     0x3bb380                       ; -> sub_003BB380
  0x003BB6E8  39be34030000            cmp      dword ptr [esi + 0x334], edi   
  0x003BB6EE  7d15                    jge      0x3bb705                       
                                        ; XREF: 0x003BB703 (cond_jump)
  0x003BB6F0  56                      push     esi                            
  0x003BB6F1  ffd3                    call     ebx                            
  0x003BB6F3  83c404                  add      esp, 4                         
  0x003BB6F6  8bc6                    mov      eax, esi                       
  0x003BB6F8  e8e3fcffff              call     0x3bb3e0                       ; -> sub_003BB3E0
  0x003BB6FD  39be34030000            cmp      dword ptr [esi + 0x334], edi   
  0x003BB703  7ceb                    jl       0x3bb6f0                       
                                        ; XREF: 0x003BB6EE (cond_jump)
  0x003BB705  5f                      pop      edi                            
  0x003BB706  5e                      pop      esi                            
  0x003BB707  5b                      pop      ebx                            
  0x003BB708  c3                      ret                                     
; end of function
  0x003BB709  cc                      int3                                    
  0x003BB70A  cc                      int3                                    
  0x003BB70B  cc                      int3                                    
  0x003BB70C  cc                      int3                                    
  0x003BB70D  cc                      int3                                    
  0x003BB70E  cc                      int3                                    
  0x003BB70F  cc                      int3                                    

; ============================================================
; Function: sub_003BB710
; Start: 0x003BB710  End: 0x003BB7A0  Size: 144 bytes
; Detection: cc_boundary (confidence: 0.85)
; Calls: sub_003BA890, sub_003BB4A0
; ============================================================
sub_003BB710:
  0x003BB710  83ec08                  sub      esp, 8                         
  0x003BB713  56                      push     esi                            
  0x003BB714  8b742410                mov      esi, dword ptr [esp + 0x10]    
  0x003BB718  57                      push     edi                            
  0x003BB719  8d8e64020000            lea      ecx, [esi + 0x264]             
  0x003BB71F  51                      push     ecx                            
  0x003BB720  8b8e18010000            mov      ecx, dword ptr [esi + 0x118]   
  0x003BB726  8d54240c                lea      edx, [esp + 0xc]               
  0x003BB72A  8dbe10010000            lea      edi, [esi + 0x110]             
  0x003BB730  52                      push     edx                            
  0x003BB731  51                      push     ecx                            
  0x003BB732  8d86ec020000            lea      eax, [esi + 0x2ec]             
  0x003BB738  56                      push     esi                            
  0x003BB739  e862fdffff              call     0x3bb4a0                       ; -> sub_003BB4A0
  0x003BB73E  8b8e94020000            mov      ecx, dword ptr [esi + 0x294]   
  0x003BB744  8b442418                mov      eax, dword ptr [esp + 0x18]    
  0x003BB748  03c8                    add      ecx, eax                       
  0x003BB74A  8d9620010000            lea      edx, [esi + 0x120]             
  0x003BB750  894a04                  mov      dword ptr [edx + 4], ecx       
  0x003BB753  8b8e98020000            mov      ecx, dword ptr [esi + 0x298]   
  0x003BB759  03c8                    add      ecx, eax                       
  0x003BB75B  894a0c                  mov      dword ptr [edx + 0xc], ecx     
  0x003BB75E  8b869c020000            mov      eax, dword ptr [esi + 0x29c]   
  0x003BB764  8b4c241c                mov      ecx, dword ptr [esp + 0x1c]    
  0x003BB768  03c1                    add      eax, ecx                       
  0x003BB76A  894214                  mov      dword ptr [edx + 0x14], eax    
  0x003BB76D  8b4a14                  mov      ecx, dword ptr [edx + 0x14]    
  0x003BB770  83c008                  add      eax, 8                         
  0x003BB773  89421c                  mov      dword ptr [edx + 0x1c], eax    
  0x003BB776  0fbf86a2020000          movsx    eax, word ptr [esi + 0x2a2]    
  0x003BB77D  8d04c1                  lea      eax, [ecx + eax*8]             
  0x003BB780  894224                  mov      dword ptr [edx + 0x24], eax    
  0x003BB783  83c008                  add      eax, 8                         
  0x003BB786  89422c                  mov      dword ptr [edx + 0x2c], eax    
  0x003BB789  8b8648030000            mov      eax, dword ptr [esi + 0x348]   
  0x003BB78F  50                      push     eax                            
  0x003BB790  8bc7                    mov      eax, edi                       
  0x003BB792  e8f9f0ffff              call     0x3ba890                       ; -> sub_003BA890
  0x003BB797  83c414                  add      esp, 0x14                      
  0x003BB79A  5f                      pop      edi                            
  0x003BB79B  5e                      pop      esi                            
  0x003BB79C  83c408                  add      esp, 8                         
  0x003BB79F  c3                      ret                                     
; end of function
  0x003BB7A0  83ec08                  sub      esp, 8                         
  0x003BB7A3  56                      push     esi                            
  0x003BB7A4  8b742410                mov      esi, dword ptr [esp + 0x10]    
  0x003BB7A8  57                      push     edi                            
  0x003BB7A9  8d8e74020000            lea      ecx, [esi + 0x274]             
  0x003BB7AF  51                      push     ecx                            
  0x003BB7B0  8b8e18010000            mov      ecx, dword ptr [esi + 0x118]   
  0x003BB7B6  8d54240c                lea      edx, [esp + 0xc]               
  0x003BB7BA  8dbe10010000            lea      edi, [esi + 0x110]             
  0x003BB7C0  52                      push     edx                            
  0x003BB7C1  51                      push     ecx                            
  0x003BB7C2  8d8610030000            lea      eax, [esi + 0x310]             
  0x003BB7C8  56                      push     esi                            
  0x003BB7C9  e8d2fcffff              call     0x3bb4a0                       ; -> sub_003BB4A0
  0x003BB7CE  8b8e94020000            mov      ecx, dword ptr [esi + 0x294]   
  0x003BB7D4  8b442418                mov      eax, dword ptr [esp + 0x18]    
  0x003BB7D8  03c8                    add      ecx, eax                       
  0x003BB7DA  8d9620010000            lea      edx, [esi + 0x120]             
  0x003BB7E0  894a04                  mov      dword ptr [edx + 4], ecx       
  0x003BB7E3  8b8e98020000            mov      ecx, dword ptr [esi + 0x298]   
  0x003BB7E9  03c8                    add      ecx, eax                       
  0x003BB7EB  894a0c                  mov      dword ptr [edx + 0xc], ecx     
  0x003BB7EE  8b869c020000            mov      eax, dword ptr [esi + 0x29c]   
  0x003BB7F4  8b4c241c                mov      ecx, dword ptr [esp + 0x1c]    
  0x003BB7F8  03c1                    add      eax, ecx                       
  0x003BB7FA  894214                  mov      dword ptr [edx + 0x14], eax    
  0x003BB7FD  8b4a14                  mov      ecx, dword ptr [edx + 0x14]    
  0x003BB800  83c008                  add      eax, 8                         
  0x003BB803  89421c                  mov      dword ptr [edx + 0x1c], eax    
  0x003BB806  0fbf86a2020000          movsx    eax, word ptr [esi + 0x2a2]    
  0x003BB80D  8d04c1                  lea      eax, [ecx + eax*8]             
  0x003BB810  894224                  mov      dword ptr [edx + 0x24], eax    
  0x003BB813  83c008                  add      eax, 8                         
  0x003BB816  89422c                  mov      dword ptr [edx + 0x2c], eax    
  0x003BB819  8b8648030000            mov      eax, dword ptr [esi + 0x348]   
  0x003BB81F  50                      push     eax                            
  0x003BB820  8bc7                    mov      eax, edi                       
  0x003BB822  e869f0ffff              call     0x3ba890                       ; -> sub_003BA890
  0x003BB827  83c414                  add      esp, 0x14                      
  0x003BB82A  5f                      pop      edi                            
  0x003BB82B  5e                      pop      esi                            
  0x003BB82C  83c408                  add      esp, 8                         
  0x003BB82F  c3                      ret                                     
  0x003BB830  83ec08                  sub      esp, 8                         
  0x003BB833  53                      push     ebx                            
  0x003BB834  56                      push     esi                            
  0x003BB835  8b742414                mov      esi, dword ptr [esp + 0x14]    
  0x003BB839  8b9618010000            mov      edx, dword ptr [esi + 0x118]   
  0x003BB83F  57                      push     edi                            
  0x003BB840  8d9e64020000            lea      ebx, [esi + 0x264]             
  0x003BB846  53                      push     ebx                            
  0x003BB847  8d4c2410                lea      ecx, [esp + 0x10]              
  0x003BB84B  8dbe10010000            lea      edi, [esi + 0x110]             
  0x003BB851  51                      push     ecx                            
  0x003BB852  52                      push     edx                            
  0x003BB853  8d86ec020000            lea      eax, [esi + 0x2ec]             
  0x003BB859  56                      push     esi                            
  0x003BB85A  e841fcffff              call     0x3bb4a0                       ; -> sub_003BB4A0
  0x003BB85F  8b570c                  mov      edx, dword ptr [edi + 0xc]     
  0x003BB862  83c310                  add      ebx, 0x10                      
  0x003BB865  53                      push     ebx                            
  0x003BB866  8d4c2420                lea      ecx, [esp + 0x20]              
  0x003BB86A  51                      push     ecx                            
  0x003BB86B  52                      push     edx                            
  0x003BB86C  8d8610030000            lea      eax, [esi + 0x310]             
  0x003BB872  56                      push     esi                            
  0x003BB873  e828fcffff              call     0x3bb4a0                       ; -> sub_003BB4A0
  0x003BB878  8b8e94020000            mov      ecx, dword ptr [esi + 0x294]   
  0x003BB87E  8b44242c                mov      eax, dword ptr [esp + 0x2c]    
  0x003BB882  03c8                    add      ecx, eax                       
  0x003BB884  8d9620010000            lea      edx, [esi + 0x120]             
  0x003BB88A  894a04                  mov      dword ptr [edx + 4], ecx       
  0x003BB88D  8b8e98020000            mov      ecx, dword ptr [esi + 0x298]   
  0x003BB893  03c8                    add      ecx, eax                       
  0x003BB895  894a0c                  mov      dword ptr [edx + 0xc], ecx     
  0x003BB898  8b869c020000            mov      eax, dword ptr [esi + 0x29c]   
  0x003BB89E  8b4c2430                mov      ecx, dword ptr [esp + 0x30]    
  0x003BB8A2  03c1                    add      eax, ecx                       
  0x003BB8A4  894214                  mov      dword ptr [edx + 0x14], eax    
  0x003BB8A7  8b4a14                  mov      ecx, dword ptr [edx + 0x14]    
  0x003BB8AA  83c008                  add      eax, 8                         
  0x003BB8AD  89421c                  mov      dword ptr [edx + 0x1c], eax    
  0x003BB8B0  0fbf86a2020000          movsx    eax, word ptr [esi + 0x2a2]    
  0x003BB8B7  8d04c1                  lea      eax, [ecx + eax*8]             
  0x003BB8BA  894224                  mov      dword ptr [edx + 0x24], eax    
  0x003BB8BD  83c008                  add      eax, 8                         
  0x003BB8C0  89422c                  mov      dword ptr [edx + 0x2c], eax    
  0x003BB8C3  8b8648030000            mov      eax, dword ptr [esi + 0x348]   
  0x003BB8C9  50                      push     eax                            
  0x003BB8CA  8bc7                    mov      eax, edi                       
  0x003BB8CC  e89ff2ffff              call     0x3bab70                       ; -> sub_003BAB70
  0x003BB8D1  83c424                  add      esp, 0x24                      
  0x003BB8D4  5f                      pop      edi                            
  0x003BB8D5  5e                      pop      esi                            
  0x003BB8D6  5b                      pop      ebx                            
  0x003BB8D7  83c408                  add      esp, 8                         
  0x003BB8DA  c3                      ret                                     
  0x003BB8DB  cc                      int3                                    
  0x003BB8DC  cc                      int3                                    
  0x003BB8DD  cc                      int3                                    
  0x003BB8DE  cc                      int3                                    
  0x003BB8DF  cc                      int3                                    

; ============================================================
; Function: sub_003BB8E0
; Start: 0x003BB8E0  End: 0x003BB9C4  Size: 228 bytes
; Detection: cc_boundary (confidence: 0.85)
; Calls: sub_0032C500
; ============================================================
sub_003BB8E0:
  0x003BB8E0  53                      push     ebx                            
  0x003BB8E1  56                      push     esi                            
  0x003BB8E2  8b74240c                mov      esi, dword ptr [esp + 0xc]     
  0x003BB8E6  57                      push     edi                            
  0x003BB8E7  8d9680060000            lea      edx, [esi + 0x680]             
  0x003BB8ED  33c0                    xor      eax, eax                       
  0x003BB8EF  8bfa                    mov      edi, edx                       
  0x003BB8F1  b980010000              mov      ecx, 0x180                     
  0x003BB8F6  f3ab                    rep stosd dword ptr es:[edi], eax        
  0x003BB8F8  8b86e8020000            mov      eax, dword ptr [esi + 0x2e8]   
  0x003BB8FE  8d7e44                  lea      edi, [esi + 0x44]              
  0x003BB901  8d8e800c0000            lea      ecx, [esi + 0xc80]             
  0x003BB907  894f20                  mov      dword ptr [edi + 0x20], ecx    
  0x003BB90A  894724                  mov      dword ptr [edi + 0x24], eax    
  0x003BB90D  c7473000000000          mov      dword ptr [edi + 0x30], 0      
  0x003BB914  8b8628130000            mov      eax, dword ptr [esi + 0x1328]  
  0x003BB91A  8d8e4c030000            lea      ecx, [esi + 0x34c]             
  0x003BB920  57                      push     edi                            
  0x003BB921  56                      push     esi                            
  0x003BB922  8d5e78                  lea      ebx, [esi + 0x78]              
  0x003BB925  89472c                  mov      dword ptr [edi + 0x2c], eax    
  0x003BB928  894f28                  mov      dword ptr [edi + 0x28], ecx    
  0x003BB92B  89571c                  mov      dword ptr [edi + 0x1c], edx    
  0x003BB92E  ff9618130000            call     dword ptr [esi + 0x1318]       
  0x003BB934  8d9680070000            lea      edx, [esi + 0x780]             
  0x003BB93A  57                      push     edi                            
  0x003BB93B  8803                    mov      byte ptr [ebx], al             
  0x003BB93D  56                      push     esi                            
  0x003BB93E  89571c                  mov      dword ptr [edi + 0x1c], edx    
  0x003BB941  ff9618130000            call     dword ptr [esi + 0x1318]       
  0x003BB947  884301                  mov      byte ptr [ebx + 1], al         
  0x003BB94A  8d8680080000            lea      eax, [esi + 0x880]             
  0x003BB950  57                      push     edi                            
  0x003BB951  56                      push     esi                            
  0x003BB952  89471c                  mov      dword ptr [edi + 0x1c], eax    
  0x003BB955  ff9618130000            call     dword ptr [esi + 0x1318]       
  0x003BB95B  8d8e80090000            lea      ecx, [esi + 0x980]             
  0x003BB961  57                      push     edi                            
  0x003BB962  884302                  mov      byte ptr [ebx + 2], al         
  0x003BB965  56                      push     esi                            
  0x003BB966  894f1c                  mov      dword ptr [edi + 0x1c], ecx    
  0x003BB969  ff9618130000            call     dword ptr [esi + 0x1318]       
  0x003BB96F  884303                  mov      byte ptr [ebx + 3], al         
  0x003BB972  8b962c130000            mov      edx, dword ptr [esi + 0x132c]  
  0x003BB978  8d8650030000            lea      eax, [esi + 0x350]             
  0x003BB97E  8d8e800a0000            lea      ecx, [esi + 0xa80]             
  0x003BB984  57                      push     edi                            
  0x003BB985  56                      push     esi                            
  0x003BB986  89572c                  mov      dword ptr [edi + 0x2c], edx    
  0x003BB989  894728                  mov      dword ptr [edi + 0x28], eax    
  0x003BB98C  894f1c                  mov      dword ptr [edi + 0x1c], ecx    
  0x003BB98F  ff9618130000            call     dword ptr [esi + 0x1318]       
  0x003BB995  884304                  mov      byte ptr [ebx + 4], al         
  0x003BB998  8d9654030000            lea      edx, [esi + 0x354]             
  0x003BB99E  8d86800b0000            lea      eax, [esi + 0xb80]             
  0x003BB9A4  57                      push     edi                            
  0x003BB9A5  56                      push     esi                            
  0x003BB9A6  895728                  mov      dword ptr [edi + 0x28], edx    
  0x003BB9A9  89471c                  mov      dword ptr [edi + 0x1c], eax    
  0x003BB9AC  ff9618130000            call     dword ptr [esi + 0x1318]       
  0x003BB9B2  53                      push     ebx                            
  0x003BB9B3  884305                  mov      byte ptr [ebx + 5], al         
  0x003BB9B6  e8450bf7ff              call     0x32c500                       ; -> sub_0032C500
  0x003BB9BB  83c434                  add      esp, 0x34                      
  0x003BB9BE  5f                      pop      edi                            
  0x003BB9BF  5e                      pop      esi                            
  0x003BB9C0  33c0                    xor      eax, eax                       
  0x003BB9C2  5b                      pop      ebx                            
  0x003BB9C3  c3                      ret                                     
; end of function
  0x003BB9C4  cc                      int3                                    
  0x003BB9C5  cc                      int3                                    
  0x003BB9C6  cc                      int3                                    
  0x003BB9C7  cc                      int3                                    
  0x003BB9C8  cc                      int3                                    
  0x003BB9C9  cc                      int3                                    
  0x003BB9CA  cc                      int3                                    
  0x003BB9CB  cc                      int3                                    
  0x003BB9CC  cc                      int3                                    
  0x003BB9CD  cc                      int3                                    
  0x003BB9CE  cc                      int3                                    
  0x003BB9CF  cc                      int3                                    

; ============================================================
; Function: sub_003BB9D0
; Start: 0x003BB9D0  End: 0x003BBA5C  Size: 140 bytes
; Detection: cc_boundary (confidence: 0.85)
; Calls: sub_0032C510
; ============================================================
sub_003BB9D0:
  0x003BB9D0  51                      push     ecx                            
  0x003BB9D1  53                      push     ebx                            
  0x003BB9D2  55                      push     ebp                            
  0x003BB9D3  56                      push     esi                            
  0x003BB9D4  8b742414                mov      esi, dword ptr [esp + 0x14]    
  0x003BB9D8  8b8ee8020000            mov      ecx, dword ptr [esi + 0x2e8]   
  0x003BB9DE  57                      push     edi                            
  0x003BB9DF  8d7e44                  lea      edi, [esi + 0x44]              
  0x003BB9E2  8d96c00c0000            lea      edx, [esi + 0xcc0]             
  0x003BB9E8  894f24                  mov      dword ptr [edi + 0x24], ecx    
  0x003BB9EB  895720                  mov      dword ptr [edi + 0x20], edx    
  0x003BB9EE  c7473001000000          mov      dword ptr [edi + 0x30], 1      
  0x003BB9F5  8b9e48030000            mov      ebx, dword ptr [esi + 0x348]   
  0x003BB9FB  8d4678                  lea      eax, [esi + 0x78]              
  0x003BB9FE  c1e302                  shl      ebx, 2                         
  0x003BBA01  89442410                mov      dword ptr [esp + 0x10], eax    
  0x003BBA05  895828                  mov      dword ptr [eax + 0x28], ebx    
  0x003BBA08  8d8680060000            lea      eax, [esi + 0x680]             
  0x003BBA0E  33ed                    xor      ebp, ebp                       
  0x003BBA10  89442418                mov      dword ptr [esp + 0x18], eax    
                                        ; XREF: 0x003BBA45 (cond_jump)
  0x003BBA14  85db                    test     ebx, ebx                       
  0x003BBA16  7d19                    jge      0x3bba31                       
  0x003BBA18  8b4c2418                mov      ecx, dword ptr [esp + 0x18]    
  0x003BBA1C  57                      push     edi                            
  0x003BBA1D  56                      push     esi                            
  0x003BBA1E  894f1c                  mov      dword ptr [edi + 0x1c], ecx    
  0x003BBA21  ff961c130000            call     dword ptr [esi + 0x131c]       
  0x003BBA27  8b542418                mov      edx, dword ptr [esp + 0x18]    
  0x003BBA2B  83c408                  add      esp, 8                         
  0x003BBA2E  88042a                  mov      byte ptr [edx + ebp], al       
                                        ; XREF: 0x003BBA16 (cond_jump)
  0x003BBA31  8b4c2418                mov      ecx, dword ptr [esp + 0x18]    
  0x003BBA35  d1e3                    shl      ebx, 1                         
  0x003BBA37  45                      inc      ebp                            
  0x003BBA38  81c100010000            add      ecx, 0x100                     
  0x003BBA3E  83fd06                  cmp      ebp, 6                         
  0x003BBA41  894c2418                mov      dword ptr [esp + 0x18], ecx    
  0x003BBA45  7ccd                    jl       0x3bba14                       
  0x003BBA47  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003BBA4B  50                      push     eax                            
  0x003BBA4C  e8bf0af7ff              call     0x32c510                       ; -> sub_0032C510
  0x003BBA51  83c404                  add      esp, 4                         
  0x003BBA54  5f                      pop      edi                            
  0x003BBA55  5e                      pop      esi                            
  0x003BBA56  5d                      pop      ebp                            
  0x003BBA57  33c0                    xor      eax, eax                       
  0x003BBA59  5b                      pop      ebx                            
  0x003BBA5A  59                      pop      ecx                            
  0x003BBA5B  c3                      ret                                     
; end of function
  0x003BBA5C  cc                      int3                                    
  0x003BBA5D  cc                      int3                                    
  0x003BBA5E  cc                      int3                                    
  0x003BBA5F  cc                      int3                                    

; ============================================================
; Function: sub_003BBA60
; Start: 0x003BBA60  End: 0x003BBB80  Size: 288 bytes
; Detection: cc_boundary (confidence: 0.85)
; ============================================================
sub_003BBA60:
  0x003BBA60  8b542404                mov      edx, dword ptr [esp + 4]       
  0x003BBA64  8b4224                  mov      eax, dword ptr [edx + 0x24]    
  0x003BBA67  8b4a28                  mov      ecx, dword ptr [edx + 0x28]    
  0x003BBA6A  53                      push     ebx                            
  0x003BBA6B  55                      push     ebp                            
  0x003BBA6C  56                      push     esi                            
  0x003BBA6D  8b7218                  mov      esi, dword ptr [edx + 0x18]    
  0x003BBA70  57                      push     edi                            
  0x003BBA71  8b7a20                  mov      edi, dword ptr [edx + 0x20]    
  0x003BBA74  bd08000000              mov      ebp, 8                         
  0x003BBA79  8da42400000000          lea      esp, [esp]                     
                                        ; XREF: 0x003BBB75 (cond_jump)
  0x003BBA80  0fb618                  movzx    ebx, byte ptr [eax]            
  0x003BBA83  0fb611                  movzx    edx, byte ptr [ecx]            
  0x003BBA86  03d3                    add      edx, ebx                       
  0x003BBA88  0fb65801                movzx    ebx, byte ptr [eax + 1]        
  0x003BBA8C  03d3                    add      edx, ebx                       
  0x003BBA8E  0fb65901                movzx    ebx, byte ptr [ecx + 1]        
  0x003BBA92  8d541a02                lea      edx, [edx + ebx + 2]           
  0x003BBA96  c1fa02                  sar      edx, 2                         
  0x003BBA99  8816                    mov      byte ptr [esi], dl             
  0x003BBA9B  0fb65801                movzx    ebx, byte ptr [eax + 1]        
  0x003BBA9F  0fb65002                movzx    edx, byte ptr [eax + 2]        
  0x003BBAA3  03d3                    add      edx, ebx                       
  0x003BBAA5  0fb65901                movzx    ebx, byte ptr [ecx + 1]        
  0x003BBAA9  03d3                    add      edx, ebx                       
  0x003BBAAB  0fb65902                movzx    ebx, byte ptr [ecx + 2]        
  0x003BBAAF  8d541a02                lea      edx, [edx + ebx + 2]           
  0x003BBAB3  c1fa02                  sar      edx, 2                         
  0x003BBAB6  885601                  mov      byte ptr [esi + 1], dl         
  0x003BBAB9  0fb65803                movzx    ebx, byte ptr [eax + 3]        
  0x003BBABD  0fb65002                movzx    edx, byte ptr [eax + 2]        
  0x003BBAC1  03d3                    add      edx, ebx                       
  0x003BBAC3  0fb65902                movzx    ebx, byte ptr [ecx + 2]        
  0x003BBAC7  03d3                    add      edx, ebx                       
  0x003BBAC9  0fb65903                movzx    ebx, byte ptr [ecx + 3]        
  0x003BBACD  8d541a02                lea      edx, [edx + ebx + 2]           
  0x003BBAD1  c1fa02                  sar      edx, 2                         
  0x003BBAD4  885602                  mov      byte ptr [esi + 2], dl         
  0x003BBAD7  0fb65803                movzx    ebx, byte ptr [eax + 3]        
  0x003BBADB  0fb65104                movzx    edx, byte ptr [ecx + 4]        
  0x003BBADF  03d3                    add      edx, ebx                       
  0x003BBAE1  0fb65804                movzx    ebx, byte ptr [eax + 4]        
  0x003BBAE5  03d3                    add      edx, ebx                       
  0x003BBAE7  0fb65903                movzx    ebx, byte ptr [ecx + 3]        
  0x003BBAEB  8d541a02                lea      edx, [edx + ebx + 2]           
  0x003BBAEF  c1fa02                  sar      edx, 2                         
  0x003BBAF2  885603                  mov      byte ptr [esi + 3], dl         
  0x003BBAF5  0fb65904                movzx    ebx, byte ptr [ecx + 4]        
  0x003BBAF9  0fb65005                movzx    edx, byte ptr [eax + 5]        
  0x003BBAFD  03d3                    add      edx, ebx                       
  0x003BBAFF  0fb65905                movzx    ebx, byte ptr [ecx + 5]        
  0x003BBB03  03d3                    add      edx, ebx                       
  0x003BBB05  0fb65804                movzx    ebx, byte ptr [eax + 4]        
  0x003BBB09  8d541a02                lea      edx, [edx + ebx + 2]           
  0x003BBB0D  c1fa02                  sar      edx, 2                         
  0x003BBB10  885604                  mov      byte ptr [esi + 4], dl         
  0x003BBB13  0fb65806                movzx    ebx, byte ptr [eax + 6]        
  0x003BBB17  0fb65005                movzx    edx, byte ptr [eax + 5]        
  0x003BBB1B  03d3                    add      edx, ebx                       
  0x003BBB1D  0fb65905                movzx    ebx, byte ptr [ecx + 5]        
  0x003BBB21  03d3                    add      edx, ebx                       
  0x003BBB23  0fb65906                movzx    ebx, byte ptr [ecx + 6]        
  0x003BBB27  8d541a02                lea      edx, [edx + ebx + 2]           
  0x003BBB2B  c1fa02                  sar      edx, 2                         
  0x003BBB2E  885605                  mov      byte ptr [esi + 5], dl         
  0x003BBB31  0fb65807                movzx    ebx, byte ptr [eax + 7]        
  0x003BBB35  0fb65006                movzx    edx, byte ptr [eax + 6]        
  0x003BBB39  03d3                    add      edx, ebx                       
  0x003BBB3B  0fb65906                movzx    ebx, byte ptr [ecx + 6]        
  0x003BBB3F  03d3                    add      edx, ebx                       
  0x003BBB41  0fb65907                movzx    ebx, byte ptr [ecx + 7]        
  0x003BBB45  8d541a02                lea      edx, [edx + ebx + 2]           
  0x003BBB49  c1fa02                  sar      edx, 2                         
  0x003BBB4C  885606                  mov      byte ptr [esi + 6], dl         
  0x003BBB4F  0fb65808                movzx    ebx, byte ptr [eax + 8]        
  0x003BBB53  0fb65108                movzx    edx, byte ptr [ecx + 8]        
  0x003BBB57  03d3                    add      edx, ebx                       
  0x003BBB59  0fb65807                movzx    ebx, byte ptr [eax + 7]        
  0x003BBB5D  03d3                    add      edx, ebx                       
  0x003BBB5F  0fb65907                movzx    ebx, byte ptr [ecx + 7]        
  0x003BBB63  8d541a02                lea      edx, [edx + ebx + 2]           
  0x003BBB67  c1fa02                  sar      edx, 2                         
  0x003BBB6A  885607                  mov      byte ptr [esi + 7], dl         
  0x003BBB6D  03c7                    add      eax, edi                       
  0x003BBB6F  03cf                    add      ecx, edi                       
  0x003BBB71  83c608                  add      esi, 8                         
  0x003BBB74  4d                      dec      ebp                            
  0x003BBB75  0f8505ffffff            jne      0x3bba80                       
  0x003BBB7B  5f                      pop      edi                            
  0x003BBB7C  5e                      pop      esi                            
  0x003BBB7D  5d                      pop      ebp                            
  0x003BBB7E  5b                      pop      ebx                            
  0x003BBB7F  c3                      ret                                     
; end of function
  0x003BBB80  83ec0c                  sub      esp, 0xc                       
  0x003BBB83  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003BBB87  8b4820                  mov      ecx, dword ptr [eax + 0x20]    
  0x003BBB8A  8b5024                  mov      edx, dword ptr [eax + 0x24]    
  0x003BBB8D  894c2410                mov      dword ptr [esp + 0x10], ecx    
  0x003BBB91  8b4828                  mov      ecx, dword ptr [eax + 0x28]    
  0x003BBB94  89542408                mov      dword ptr [esp + 8], edx       
  0x003BBB98  8b5018                  mov      edx, dword ptr [eax + 0x18]    
  0x003BBB9B  53                      push     ebx                            
  0x003BBB9C  894c2408                mov      dword ptr [esp + 8], ecx       
  0x003BBBA0  89542404                mov      dword ptr [esp + 4], edx       
  0x003BBBA4  8b44240c                mov      eax, dword ptr [esp + 0xc]     
  0x003BBBA8  8b5c2408                mov      ebx, dword ptr [esp + 8]       
  0x003BBBAC  8b4c2404                mov      ecx, dword ptr [esp + 4]       
  0x003BBBB0  8b542414                mov      edx, dword ptr [esp + 0x14]    
  0x003BBBB4  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003BBBB7  0fe003                  pavgb    mm0, qword ptr [ebx]           
  0x003BBBBA  0f7f01                  movq     qword ptr [ecx], mm0           
  0x003BBBBD  03c2                    add      eax, edx                       
  0x003BBBBF  03da                    add      ebx, edx                       
  0x003BBBC1  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003BBBC4  0fe003                  pavgb    mm0, qword ptr [ebx]           
  0x003BBBC7  0f7f4108                movq     qword ptr [ecx + 8], mm0       
  0x003BBBCB  03c2                    add      eax, edx                       
  0x003BBBCD  03da                    add      ebx, edx                       
  0x003BBBCF  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003BBBD2  0fe003                  pavgb    mm0, qword ptr [ebx]           
  0x003BBBD5  0f7f4110                movq     qword ptr [ecx + 0x10], mm0    
  0x003BBBD9  03c2                    add      eax, edx                       
  0x003BBBDB  03da                    add      ebx, edx                       
  0x003BBBDD  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003BBBE0  0fe003                  pavgb    mm0, qword ptr [ebx]           
  0x003BBBE3  0f7f4118                movq     qword ptr [ecx + 0x18], mm0    
  0x003BBBE7  03c2                    add      eax, edx                       
  0x003BBBE9  03da                    add      ebx, edx                       
  0x003BBBEB  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003BBBEE  0fe003                  pavgb    mm0, qword ptr [ebx]           
  0x003BBBF1  0f7f4120                movq     qword ptr [ecx + 0x20], mm0    
  0x003BBBF5  03c2                    add      eax, edx                       
  0x003BBBF7  03da                    add      ebx, edx                       
  0x003BBBF9  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003BBBFC  0fe003                  pavgb    mm0, qword ptr [ebx]           
  0x003BBBFF  0f7f4128                movq     qword ptr [ecx + 0x28], mm0    
  0x003BBC03  03c2                    add      eax, edx                       
  0x003BBC05  03da                    add      ebx, edx                       
  0x003BBC07  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003BBC0A  0fe003                  pavgb    mm0, qword ptr [ebx]           
  0x003BBC0D  0f7f4130                movq     qword ptr [ecx + 0x30], mm0    
  0x003BBC11  03c2                    add      eax, edx                       
  0x003BBC13  03da                    add      ebx, edx                       
  0x003BBC15  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003BBC18  0fe003                  pavgb    mm0, qword ptr [ebx]           
  0x003BBC1B  0f7f4138                movq     qword ptr [ecx + 0x38], mm0    
  0x003BBC1F  0f77                    emms                                    
  0x003BBC21  5b                      pop      ebx                            
  0x003BBC22  83c40c                  add      esp, 0xc                       
  0x003BBC25  c3                      ret                                     
  0x003BBC26  cc                      int3                                    
  0x003BBC27  cc                      int3                                    
  0x003BBC28  cc                      int3                                    
  0x003BBC29  cc                      int3                                    
  0x003BBC2A  cc                      int3                                    
  0x003BBC2B  cc                      int3                                    
  0x003BBC2C  cc                      int3                                    
  0x003BBC2D  cc                      int3                                    
  0x003BBC2E  cc                      int3                                    
  0x003BBC2F  cc                      int3                                    

; ============================================================
; Function: sub_003BBC30
; Start: 0x003BBC30  End: 0x003BBCC1  Size: 145 bytes
; Detection: cc_boundary (confidence: 0.85)
; ============================================================
sub_003BBC30:
  0x003BBC30  83ec08                  sub      esp, 8                         
  0x003BBC33  8b44240c                mov      eax, dword ptr [esp + 0xc]     
  0x003BBC37  8b4820                  mov      ecx, dword ptr [eax + 0x20]    
  0x003BBC3A  8b5024                  mov      edx, dword ptr [eax + 0x24]    
  0x003BBC3D  8b4018                  mov      eax, dword ptr [eax + 0x18]    
  0x003BBC40  894c240c                mov      dword ptr [esp + 0xc], ecx     
  0x003BBC44  89542404                mov      dword ptr [esp + 4], edx       
  0x003BBC48  890424                  mov      dword ptr [esp], eax           
  0x003BBC4B  8b442404                mov      eax, dword ptr [esp + 4]       
  0x003BBC4F  8b0c24                  mov      ecx, dword ptr [esp]           
  0x003BBC52  8b54240c                mov      edx, dword ptr [esp + 0xc]     
  0x003BBC56  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003BBC59  0fe04001                pavgb    mm0, qword ptr [eax + 1]       
  0x003BBC5D  0f7f01                  movq     qword ptr [ecx], mm0           
  0x003BBC60  03c2                    add      eax, edx                       
  0x003BBC62  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003BBC65  0fe04001                pavgb    mm0, qword ptr [eax + 1]       
  0x003BBC69  0f7f4108                movq     qword ptr [ecx + 8], mm0       
  0x003BBC6D  03c2                    add      eax, edx                       
  0x003BBC6F  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003BBC72  0fe04001                pavgb    mm0, qword ptr [eax + 1]       
  0x003BBC76  0f7f4110                movq     qword ptr [ecx + 0x10], mm0    
  0x003BBC7A  03c2                    add      eax, edx                       
  0x003BBC7C  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003BBC7F  0fe04001                pavgb    mm0, qword ptr [eax + 1]       
  0x003BBC83  0f7f4118                movq     qword ptr [ecx + 0x18], mm0    
  0x003BBC87  03c2                    add      eax, edx                       
  0x003BBC89  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003BBC8C  0fe04001                pavgb    mm0, qword ptr [eax + 1]       
  0x003BBC90  0f7f4120                movq     qword ptr [ecx + 0x20], mm0    
  0x003BBC94  03c2                    add      eax, edx                       
  0x003BBC96  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003BBC99  0fe04001                pavgb    mm0, qword ptr [eax + 1]       
  0x003BBC9D  0f7f4128                movq     qword ptr [ecx + 0x28], mm0    
  0x003BBCA1  03c2                    add      eax, edx                       
  0x003BBCA3  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003BBCA6  0fe04001                pavgb    mm0, qword ptr [eax + 1]       
  0x003BBCAA  0f7f4130                movq     qword ptr [ecx + 0x30], mm0    
  0x003BBCAE  03c2                    add      eax, edx                       
  0x003BBCB0  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003BBCB3  0fe04001                pavgb    mm0, qword ptr [eax + 1]       
  0x003BBCB7  0f7f4138                movq     qword ptr [ecx + 0x38], mm0    
  0x003BBCBB  0f77                    emms                                    
  0x003BBCBD  83c408                  add      esp, 8                         
  0x003BBCC0  c3                      ret                                     
; end of function
  0x003BBCC1  cc                      int3                                    
  0x003BBCC2  cc                      int3                                    
  0x003BBCC3  cc                      int3                                    
  0x003BBCC4  cc                      int3                                    
  0x003BBCC5  cc                      int3                                    
  0x003BBCC6  cc                      int3                                    
  0x003BBCC7  cc                      int3                                    
  0x003BBCC8  cc                      int3                                    
  0x003BBCC9  cc                      int3                                    
  0x003BBCCA  cc                      int3                                    
  0x003BBCCB  cc                      int3                                    
  0x003BBCCC  cc                      int3                                    
  0x003BBCCD  cc                      int3                                    
  0x003BBCCE  cc                      int3                                    
  0x003BBCCF  cc                      int3                                    

; ============================================================
; Function: sub_003BBCD0
; Start: 0x003BBCD0  End: 0x003BBD47  Size: 119 bytes
; Detection: cc_boundary (confidence: 0.85)
; ============================================================
sub_003BBCD0:
  0x003BBCD0  83ec08                  sub      esp, 8                         
  0x003BBCD3  8b44240c                mov      eax, dword ptr [esp + 0xc]     
  0x003BBCD7  8b4824                  mov      ecx, dword ptr [eax + 0x24]    
  0x003BBCDA  8b5018                  mov      edx, dword ptr [eax + 0x18]    
  0x003BBCDD  8b4020                  mov      eax, dword ptr [eax + 0x20]    
  0x003BBCE0  56                      push     esi                            
  0x003BBCE1  57                      push     edi                            
  0x003BBCE2  894c240c                mov      dword ptr [esp + 0xc], ecx     
  0x003BBCE6  89542414                mov      dword ptr [esp + 0x14], edx    
  0x003BBCEA  89442408                mov      dword ptr [esp + 8], eax       
  0x003BBCEE  8b74240c                mov      esi, dword ptr [esp + 0xc]     
  0x003BBCF2  8b442408                mov      eax, dword ptr [esp + 8]       
  0x003BBCF6  8b7c2414                mov      edi, dword ptr [esp + 0x14]    
  0x003BBCFA  0f6f06                  movq     mm0, qword ptr [esi]           
  0x003BBCFD  0f7f07                  movq     qword ptr [edi], mm0           
  0x003BBD00  03f0                    add      esi, eax                       
  0x003BBD02  0f6f0e                  movq     mm1, qword ptr [esi]           
  0x003BBD05  0f7f4f08                movq     qword ptr [edi + 8], mm1       
  0x003BBD09  03f0                    add      esi, eax                       
  0x003BBD0B  0f6f16                  movq     mm2, qword ptr [esi]           
  0x003BBD0E  0f7f5710                movq     qword ptr [edi + 0x10], mm2    
  0x003BBD12  03f0                    add      esi, eax                       
  0x003BBD14  0f6f1e                  movq     mm3, qword ptr [esi]           
  0x003BBD17  0f7f5f18                movq     qword ptr [edi + 0x18], mm3    
  0x003BBD1B  03f0                    add      esi, eax                       
  0x003BBD1D  0f6f26                  movq     mm4, qword ptr [esi]           
  0x003BBD20  0f7f6720                movq     qword ptr [edi + 0x20], mm4    
                                        ; XREF: 0x003BBD64 (cond_jump)
  0x003BBD24  03f0                    add      esi, eax                       
  0x003BBD26  0f6f2e                  movq     mm5, qword ptr [esi]           
  0x003BBD29  0f7f6f28                movq     qword ptr [edi + 0x28], mm5    
  0x003BBD2D  03f0                    add      esi, eax                       
  0x003BBD2F  0f6f36                  movq     mm6, qword ptr [esi]           
  0x003BBD32  0f7f7730                movq     qword ptr [edi + 0x30], mm6    
  0x003BBD36  03f0                    add      esi, eax                       
  0x003BBD38  0f6f3e                  movq     mm7, qword ptr [esi]           
  0x003BBD3B  0f7f7f38                movq     qword ptr [edi + 0x38], mm7    
  0x003BBD3F  0f77                    emms                                    
  0x003BBD41  5f                      pop      edi                            
  0x003BBD42  5e                      pop      esi                            
  0x003BBD43  83c408                  add      esp, 8                         
  0x003BBD46  c3                      ret                                     
; end of function
