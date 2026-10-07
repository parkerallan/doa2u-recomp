; ============================================================
; Section: PSFD00
; VA: 0x003B6C00 - 0x003B8368
; Size: 5992 bytes (5.9 KB)
; Functions: 17
; Instructions: 2077
; ============================================================


; ============================================================
; Function: sub_003B6C00
; Start: 0x003B6C00  End: 0x003B6C13  Size: 19 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_003B7A40
; ============================================================
sub_003B6C00:
  0x003B6C00  83ec0c                  sub      esp, 0xc                       
  0x003B6C03  53                      push     ebx                            
  0x003B6C04  55                      push     ebp                            
  0x003B6C05  57                      push     edi                            
  0x003B6C06  83c204                  add      edx, 4                         
  0x003B6C09  c744241006000000        mov      dword ptr [esp + 0x10], 6      
  0x003B6C11  eb04                    jmp      0x3b6c17                       
; end of function
                                        ; XREF: 0x003B6E9C (cond_jump)
  0x003B6C13  8b542414                mov      edx, dword ptr [esp + 0x14]    
                                        ; XREF: 0x003B6C11 (jump)
  0x003B6C17  8b02                    mov      eax, dword ptr [edx]           
  0x003B6C19  8b7a04                  mov      edi, dword ptr [edx + 4]       
  0x003B6C1C  83c204                  add      edx, 4                         
  0x003B6C1F  83c204                  add      edx, 4                         
  0x003B6C22  a81f                    test     al, 0x1f                       
  0x003B6C24  89542414                mov      dword ptr [esp + 0x14], edx    
  0x003B6C28  0f8583000000            jne      0x3b6cb1                       
  0x003B6C2E  bd08000000              mov      ebp, 8                         
                                        ; XREF: 0x003B6CAA (cond_jump)
  0x003B6C33  0fbf5904                movsx    ebx, word ptr [ecx + 4]        
  0x003B6C37  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6C3A  0fbf5102                movsx    edx, word ptr [ecx + 2]        
  0x003B6C3E  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003B6C41  0f1808                  prefetcht0 byte ptr [eax]                 
  0x003B6C44  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003B6C48  0fbf5906                movsx    ebx, word ptr [ecx + 6]        
  0x003B6C4C  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6C4F  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003B6C53  0fbf19                  movsx    ebx, word ptr [ecx]            
  0x003B6C56  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6C59  885001                  mov      byte ptr [eax + 1], dl         
  0x003B6C5C  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003B6C60  885002                  mov      byte ptr [eax + 2], dl         
  0x003B6C63  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003B6C67  885003                  mov      byte ptr [eax + 3], dl         
  0x003B6C6A  8818                    mov      byte ptr [eax], bl             
  0x003B6C6C  0fbf590c                movsx    ebx, word ptr [ecx + 0xc]      
  0x003B6C70  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6C73  0fbf510a                movsx    edx, word ptr [ecx + 0xa]      
  0x003B6C77  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003B6C7A  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003B6C7E  0fbf590e                movsx    ebx, word ptr [ecx + 0xe]      
  0x003B6C82  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6C85  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003B6C89  0fbf5908                movsx    ebx, word ptr [ecx + 8]        
  0x003B6C8D  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6C90  885005                  mov      byte ptr [eax + 5], dl         
  0x003B6C93  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003B6C97  885006                  mov      byte ptr [eax + 6], dl         
  0x003B6C9A  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003B6C9E  885804                  mov      byte ptr [eax + 4], bl         
  0x003B6CA1  885007                  mov      byte ptr [eax + 7], dl         
  0x003B6CA4  83c110                  add      ecx, 0x10                      
  0x003B6CA7  03c7                    add      eax, edi                       
  0x003B6CA9  4d                      dec      ebp                            
  0x003B6CAA  7587                    jne      0x3b6c33                       
  0x003B6CAC  e9e7010000              jmp      0x3b6e98                       
                                        ; XREF: 0x003B6C28 (cond_jump)
  0x003B6CB1  bd02000000              mov      ebp, 2                         
  0x003B6CB6  eb08                    jmp      0x3b6cc0                       
  0x003B6CB8  8da42400000000          lea      esp, [esp]                     
  0x003B6CBF  90                      nop                                     
                                        ; XREF: 0x003B6CB6 (jump), 0x003B6E92 (cond_jump)
  0x003B6CC0  0fbf5904                movsx    ebx, word ptr [ecx + 4]        
  0x003B6CC4  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6CC7  0fbf5102                movsx    edx, word ptr [ecx + 2]        
  0x003B6CCB  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003B6CCE  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003B6CD2  0fbf5906                movsx    ebx, word ptr [ecx + 6]        
  0x003B6CD6  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6CD9  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003B6CDD  0fbf19                  movsx    ebx, word ptr [ecx]            
  0x003B6CE0  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6CE3  885001                  mov      byte ptr [eax + 1], dl         
  0x003B6CE6  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003B6CEA  885002                  mov      byte ptr [eax + 2], dl         
  0x003B6CED  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003B6CF1  885003                  mov      byte ptr [eax + 3], dl         
  0x003B6CF4  8818                    mov      byte ptr [eax], bl             
  0x003B6CF6  0fbf590c                movsx    ebx, word ptr [ecx + 0xc]      
  0x003B6CFA  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6CFD  0fbf510a                movsx    edx, word ptr [ecx + 0xa]      
  0x003B6D01  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003B6D04  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003B6D08  0fbf590e                movsx    ebx, word ptr [ecx + 0xe]      
  0x003B6D0C  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6D0F  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003B6D13  0fbf5908                movsx    ebx, word ptr [ecx + 8]        
  0x003B6D17  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6D1A  885005                  mov      byte ptr [eax + 5], dl         
  0x003B6D1D  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003B6D21  885006                  mov      byte ptr [eax + 6], dl         
  0x003B6D24  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003B6D28  885007                  mov      byte ptr [eax + 7], dl         
  0x003B6D2B  885804                  mov      byte ptr [eax + 4], bl         
  0x003B6D2E  0fbf5914                movsx    ebx, word ptr [ecx + 0x14]     
  0x003B6D32  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6D35  0fbf5112                movsx    edx, word ptr [ecx + 0x12]     
  0x003B6D39  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003B6D3C  83c110                  add      ecx, 0x10                      
  0x003B6D3F  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003B6D43  0fbf5906                movsx    ebx, word ptr [ecx + 6]        
  0x003B6D47  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6D4A  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003B6D4E  0fbf19                  movsx    ebx, word ptr [ecx]            
  0x003B6D51  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6D54  88543801                mov      byte ptr [eax + edi + 1], dl   
  0x003B6D58  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003B6D5C  88543802                mov      byte ptr [eax + edi + 2], dl   
  0x003B6D60  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003B6D64  88543803                mov      byte ptr [eax + edi + 3], dl   
  0x003B6D68  881c38                  mov      byte ptr [eax + edi], bl       
  0x003B6D6B  0fbf590c                movsx    ebx, word ptr [ecx + 0xc]      
  0x003B6D6F  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6D72  0fbf510a                movsx    edx, word ptr [ecx + 0xa]      
  0x003B6D76  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003B6D79  03c7                    add      eax, edi                       
  0x003B6D7B  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003B6D7F  0fbf590e                movsx    ebx, word ptr [ecx + 0xe]      
  0x003B6D83  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6D86  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003B6D8A  0fbf5908                movsx    ebx, word ptr [ecx + 8]        
  0x003B6D8E  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6D91  885005                  mov      byte ptr [eax + 5], dl         
  0x003B6D94  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003B6D98  885006                  mov      byte ptr [eax + 6], dl         
  0x003B6D9B  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003B6D9F  885007                  mov      byte ptr [eax + 7], dl         
  0x003B6DA2  885804                  mov      byte ptr [eax + 4], bl         
  0x003B6DA5  0fbf5914                movsx    ebx, word ptr [ecx + 0x14]     
  0x003B6DA9  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6DAC  0fbf5112                movsx    edx, word ptr [ecx + 0x12]     
  0x003B6DB0  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003B6DB3  83c110                  add      ecx, 0x10                      
  0x003B6DB6  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003B6DBA  0fbf5906                movsx    ebx, word ptr [ecx + 6]        
  0x003B6DBE  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6DC1  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003B6DC5  0fbf19                  movsx    ebx, word ptr [ecx]            
  0x003B6DC8  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6DCB  03c7                    add      eax, edi                       
  0x003B6DCD  885001                  mov      byte ptr [eax + 1], dl         
  0x003B6DD0  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003B6DD4  8818                    mov      byte ptr [eax], bl             
  0x003B6DD6  885002                  mov      byte ptr [eax + 2], dl         
  0x003B6DD9  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003B6DDD  885003                  mov      byte ptr [eax + 3], dl         
  0x003B6DE0  0fbf590c                movsx    ebx, word ptr [ecx + 0xc]      
  0x003B6DE4  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6DE7  0fbf510a                movsx    edx, word ptr [ecx + 0xa]      
  0x003B6DEB  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003B6DEE  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003B6DF2  0fbf590e                movsx    ebx, word ptr [ecx + 0xe]      
  0x003B6DF6  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6DF9  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003B6DFD  0fbf5908                movsx    ebx, word ptr [ecx + 8]        
  0x003B6E01  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6E04  885005                  mov      byte ptr [eax + 5], dl         
  0x003B6E07  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003B6E0B  885006                  mov      byte ptr [eax + 6], dl         
  0x003B6E0E  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003B6E12  885007                  mov      byte ptr [eax + 7], dl         
  0x003B6E15  885804                  mov      byte ptr [eax + 4], bl         
  0x003B6E18  0fbf5914                movsx    ebx, word ptr [ecx + 0x14]     
  0x003B6E1C  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6E1F  0fbf5112                movsx    edx, word ptr [ecx + 0x12]     
  0x003B6E23  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003B6E26  83c110                  add      ecx, 0x10                      
  0x003B6E29  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003B6E2D  0fbf5906                movsx    ebx, word ptr [ecx + 6]        
  0x003B6E31  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6E34  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003B6E38  0fbf19                  movsx    ebx, word ptr [ecx]            
  0x003B6E3B  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6E3E  88543801                mov      byte ptr [eax + edi + 1], dl   
  0x003B6E42  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003B6E46  03c7                    add      eax, edi                       
  0x003B6E48  885002                  mov      byte ptr [eax + 2], dl         
  0x003B6E4B  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003B6E4F  885003                  mov      byte ptr [eax + 3], dl         
  0x003B6E52  8818                    mov      byte ptr [eax], bl             
  0x003B6E54  0fbf590c                movsx    ebx, word ptr [ecx + 0xc]      
  0x003B6E58  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6E5B  0fbf510a                movsx    edx, word ptr [ecx + 0xa]      
  0x003B6E5F  8a1432                  mov      dl, byte ptr [edx + esi]       
  0x003B6E62  885c240e                mov      byte ptr [esp + 0xe], bl       
  0x003B6E66  0fbf590e                movsx    ebx, word ptr [ecx + 0xe]      
  0x003B6E6A  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6E6D  885c240f                mov      byte ptr [esp + 0xf], bl       
  0x003B6E71  0fbf5908                movsx    ebx, word ptr [ecx + 8]        
  0x003B6E75  8a1c33                  mov      bl, byte ptr [ebx + esi]       
  0x003B6E78  885005                  mov      byte ptr [eax + 5], dl         
  0x003B6E7B  8a54240e                mov      dl, byte ptr [esp + 0xe]       
  0x003B6E7F  885006                  mov      byte ptr [eax + 6], dl         
  0x003B6E82  8a54240f                mov      dl, byte ptr [esp + 0xf]       
  0x003B6E86  885804                  mov      byte ptr [eax + 4], bl         
  0x003B6E89  885007                  mov      byte ptr [eax + 7], dl         
  0x003B6E8C  83c110                  add      ecx, 0x10                      
  0x003B6E8F  03c7                    add      eax, edi                       
  0x003B6E91  4d                      dec      ebp                            
  0x003B6E92  0f8528feffff            jne      0x3b6cc0                       
                                        ; XREF: 0x003B6CAC (jump)
  0x003B6E98  ff4c2410                dec      dword ptr [esp + 0x10]         
  0x003B6E9C  0f8571fdffff            jne      0x3b6c13                       
  0x003B6EA2  5f                      pop      edi                            
  0x003B6EA3  5d                      pop      ebp                            
  0x003B6EA4  5b                      pop      ebx                            
  0x003B6EA5  83c40c                  add      esp, 0xc                       
  0x003B6EA8  c3                      ret                                     
  0x003B6EA9  cc                      int3                                    
  0x003B6EAA  cc                      int3                                    
  0x003B6EAB  cc                      int3                                    
  0x003B6EAC  cc                      int3                                    
  0x003B6EAD  cc                      int3                                    
  0x003B6EAE  cc                      int3                                    
  0x003B6EAF  cc                      int3                                    

; ============================================================
; Function: sub_003B6EB0
; Start: 0x003B6EB0  End: 0x003B6F29  Size: 121 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_003B7D30
; ============================================================
sub_003B6EB0:
  0x003B6EB0  83ec0c                  sub      esp, 0xc                       
  0x003B6EB3  8b4808                  mov      ecx, dword ptr [eax + 8]       
  0x003B6EB6  53                      push     ebx                            
  0x003B6EB7  55                      push     ebp                            
  0x003B6EB8  56                      push     esi                            
  0x003B6EB9  8b7004                  mov      esi, dword ptr [eax + 4]       
  0x003B6EBC  57                      push     edi                            
  0x003B6EBD  8b38                    mov      edi, dword ptr [eax]           
  0x003B6EBF  83c204                  add      edx, 4                         
  0x003B6EC2  c744241406000000        mov      dword ptr [esp + 0x14], 6      
  0x003B6ECA  8d9b00000000            lea      ebx, [ebx]                     
                                        ; XREF: 0x003B7178 (cond_jump)
  0x003B6ED0  8b02                    mov      eax, dword ptr [edx]           
  0x003B6ED2  8b6a04                  mov      ebp, dword ptr [edx + 4]       
  0x003B6ED5  8b5c2420                mov      ebx, dword ptr [esp + 0x20]    
  0x003B6ED9  83c204                  add      edx, 4                         
  0x003B6EDC  83c204                  add      edx, 4                         
  0x003B6EDF  85db                    test     ebx, ebx                       
  0x003B6EE1  89542418                mov      dword ptr [esp + 0x18], edx    
  0x003B6EE5  7c42                    jl       0x3b6f29                       
  0x003B6EE7  dd01                    fld      qword ptr [ecx]                
  0x003B6EE9  81c680000000            add      esi, 0x80                      
  0x003B6EEF  dd18                    fstp     qword ptr [eax]                
  0x003B6EF1  03c5                    add      eax, ebp                       
  0x003B6EF3  dd4108                  fld      qword ptr [ecx + 8]            
  0x003B6EF6  dd18                    fstp     qword ptr [eax]                
  0x003B6EF8  03c5                    add      eax, ebp                       
  0x003B6EFA  dd4110                  fld      qword ptr [ecx + 0x10]         
  0x003B6EFD  dd18                    fstp     qword ptr [eax]                
  0x003B6EFF  03c5                    add      eax, ebp                       
  0x003B6F01  dd4118                  fld      qword ptr [ecx + 0x18]         
  0x003B6F04  dd18                    fstp     qword ptr [eax]                
  0x003B6F06  03c5                    add      eax, ebp                       
  0x003B6F08  dd4120                  fld      qword ptr [ecx + 0x20]         
  0x003B6F0B  dd18                    fstp     qword ptr [eax]                
  0x003B6F0D  03c5                    add      eax, ebp                       
  0x003B6F0F  dd4128                  fld      qword ptr [ecx + 0x28]         
  0x003B6F12  dd18                    fstp     qword ptr [eax]                
  0x003B6F14  03c5                    add      eax, ebp                       
  0x003B6F16  dd4130                  fld      qword ptr [ecx + 0x30]         
  0x003B6F19  83c140                  add      ecx, 0x40                      
  0x003B6F1C  dd18                    fstp     qword ptr [eax]                
  0x003B6F1E  dd41f8                  fld      qword ptr [ecx - 8]            
  0x003B6F21  dd1c28                  fstp     qword ptr [eax + ebp]          
  0x003B6F24  e93c020000              jmp      0x3b7165                       
; end of function
                                        ; XREF: 0x003B6EE5 (cond_jump)
  0x003B6F29  c744241002000000        mov      dword ptr [esp + 0x10], 2      
                                        ; XREF: 0x003B715B (cond_jump)
  0x003B6F31  0fb611                  movzx    edx, byte ptr [ecx]            
  0x003B6F34  0fbf1e                  movsx    ebx, word ptr [esi]            
  0x003B6F37  03d7                    add      edx, edi                       
  0x003B6F39  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B6F3C  8810                    mov      byte ptr [eax], dl             
  0x003B6F3E  0fb65101                movzx    edx, byte ptr [ecx + 1]        
  0x003B6F42  0fbf5e02                movsx    ebx, word ptr [esi + 2]        
  0x003B6F46  03d7                    add      edx, edi                       
  0x003B6F48  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B6F4B  885001                  mov      byte ptr [eax + 1], dl         
  0x003B6F4E  0fb65102                movzx    edx, byte ptr [ecx + 2]        
  0x003B6F52  0fbf5e04                movsx    ebx, word ptr [esi + 4]        
  0x003B6F56  03d7                    add      edx, edi                       
  0x003B6F58  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B6F5B  885002                  mov      byte ptr [eax + 2], dl         
  0x003B6F5E  0fb65103                movzx    edx, byte ptr [ecx + 3]        
  0x003B6F62  0fbf5e06                movsx    ebx, word ptr [esi + 6]        
  0x003B6F66  03d7                    add      edx, edi                       
  0x003B6F68  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B6F6B  885003                  mov      byte ptr [eax + 3], dl         
  0x003B6F6E  0fb65104                movzx    edx, byte ptr [ecx + 4]        
  0x003B6F72  0fbf5e08                movsx    ebx, word ptr [esi + 8]        
  0x003B6F76  03d7                    add      edx, edi                       
  0x003B6F78  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B6F7B  885004                  mov      byte ptr [eax + 4], dl         
  0x003B6F7E  0fb65105                movzx    edx, byte ptr [ecx + 5]        
  0x003B6F82  0fbf5e0a                movsx    ebx, word ptr [esi + 0xa]      
  0x003B6F86  03d7                    add      edx, edi                       
  0x003B6F88  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B6F8B  885005                  mov      byte ptr [eax + 5], dl         
  0x003B6F8E  0fb65106                movzx    edx, byte ptr [ecx + 6]        
  0x003B6F92  0fbf5e0c                movsx    ebx, word ptr [esi + 0xc]      
  0x003B6F96  03d7                    add      edx, edi                       
  0x003B6F98  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B6F9B  885006                  mov      byte ptr [eax + 6], dl         
  0x003B6F9E  0fb65107                movzx    edx, byte ptr [ecx + 7]        
  0x003B6FA2  0fbf5e0e                movsx    ebx, word ptr [esi + 0xe]      
  0x003B6FA6  03d7                    add      edx, edi                       
  0x003B6FA8  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B6FAB  885007                  mov      byte ptr [eax + 7], dl         
  0x003B6FAE  0fb65108                movzx    edx, byte ptr [ecx + 8]        
  0x003B6FB2  0fbf5e10                movsx    ebx, word ptr [esi + 0x10]     
  0x003B6FB6  03d7                    add      edx, edi                       
  0x003B6FB8  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B6FBB  881428                  mov      byte ptr [eax + ebp], dl       
  0x003B6FBE  0fb65109                movzx    edx, byte ptr [ecx + 9]        
  0x003B6FC2  0fbf5e12                movsx    ebx, word ptr [esi + 0x12]     
  0x003B6FC6  83c108                  add      ecx, 8                         
  0x003B6FC9  83c610                  add      esi, 0x10                      
  0x003B6FCC  03d7                    add      edx, edi                       
  0x003B6FCE  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B6FD1  88542801                mov      byte ptr [eax + ebp + 1], dl   
  0x003B6FD5  0fb65102                movzx    edx, byte ptr [ecx + 2]        
  0x003B6FD9  0fbf5e04                movsx    ebx, word ptr [esi + 4]        
  0x003B6FDD  03c5                    add      eax, ebp                       
  0x003B6FDF  03d7                    add      edx, edi                       
  0x003B6FE1  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B6FE4  885002                  mov      byte ptr [eax + 2], dl         
  0x003B6FE7  0fb65103                movzx    edx, byte ptr [ecx + 3]        
  0x003B6FEB  0fbf5e06                movsx    ebx, word ptr [esi + 6]        
  0x003B6FEF  03d7                    add      edx, edi                       
  0x003B6FF1  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B6FF4  885003                  mov      byte ptr [eax + 3], dl         
  0x003B6FF7  0fb65104                movzx    edx, byte ptr [ecx + 4]        
  0x003B6FFB  0fbf5e08                movsx    ebx, word ptr [esi + 8]        
  0x003B6FFF  03d7                    add      edx, edi                       
  0x003B7001  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B7004  885004                  mov      byte ptr [eax + 4], dl         
  0x003B7007  0fb65105                movzx    edx, byte ptr [ecx + 5]        
  0x003B700B  0fbf5e0a                movsx    ebx, word ptr [esi + 0xa]      
  0x003B700F  03d7                    add      edx, edi                       
  0x003B7011  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B7014  885005                  mov      byte ptr [eax + 5], dl         
  0x003B7017  0fb65106                movzx    edx, byte ptr [ecx + 6]        
  0x003B701B  0fbf5e0c                movsx    ebx, word ptr [esi + 0xc]      
  0x003B701F  03d7                    add      edx, edi                       
  0x003B7021  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B7024  885006                  mov      byte ptr [eax + 6], dl         
  0x003B7027  0fb65107                movzx    edx, byte ptr [ecx + 7]        
  0x003B702B  0fbf5e0e                movsx    ebx, word ptr [esi + 0xe]      
  0x003B702F  03d7                    add      edx, edi                       
  0x003B7031  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B7034  885007                  mov      byte ptr [eax + 7], dl         
  0x003B7037  0fb65108                movzx    edx, byte ptr [ecx + 8]        
  0x003B703B  0fbf5e10                movsx    ebx, word ptr [esi + 0x10]     
  0x003B703F  03d7                    add      edx, edi                       
  0x003B7041  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B7044  881428                  mov      byte ptr [eax + ebp], dl       
  0x003B7047  0fb65109                movzx    edx, byte ptr [ecx + 9]        
  0x003B704B  0fbf5e12                movsx    ebx, word ptr [esi + 0x12]     
  0x003B704F  03d7                    add      edx, edi                       
  0x003B7051  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B7054  88542801                mov      byte ptr [eax + ebp + 1], dl   
  0x003B7058  0fb6510a                movzx    edx, byte ptr [ecx + 0xa]      
  0x003B705C  0fbf5e14                movsx    ebx, word ptr [esi + 0x14]     
  0x003B7060  03d7                    add      edx, edi                       
  0x003B7062  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B7065  88542802                mov      byte ptr [eax + ebp + 2], dl   
  0x003B7069  0fb6510b                movzx    edx, byte ptr [ecx + 0xb]      
  0x003B706D  0fbf5e16                movsx    ebx, word ptr [esi + 0x16]     
  0x003B7071  83c108                  add      ecx, 8                         
  0x003B7074  83c610                  add      esi, 0x10                      
  0x003B7077  03c5                    add      eax, ebp                       
  0x003B7079  03d7                    add      edx, edi                       
  0x003B707B  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B707E  885003                  mov      byte ptr [eax + 3], dl         
  0x003B7081  0fb65104                movzx    edx, byte ptr [ecx + 4]        
  0x003B7085  0fbf5e08                movsx    ebx, word ptr [esi + 8]        
  0x003B7089  03d7                    add      edx, edi                       
  0x003B708B  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B708E  885004                  mov      byte ptr [eax + 4], dl         
  0x003B7091  0fb65105                movzx    edx, byte ptr [ecx + 5]        
  0x003B7095  0fbf5e0a                movsx    ebx, word ptr [esi + 0xa]      
  0x003B7099  03d7                    add      edx, edi                       
  0x003B709B  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B709E  885005                  mov      byte ptr [eax + 5], dl         
  0x003B70A1  0fb65106                movzx    edx, byte ptr [ecx + 6]        
  0x003B70A5  0fbf5e0c                movsx    ebx, word ptr [esi + 0xc]      
  0x003B70A9  03d7                    add      edx, edi                       
  0x003B70AB  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B70AE  885006                  mov      byte ptr [eax + 6], dl         
  0x003B70B1  0fb65107                movzx    edx, byte ptr [ecx + 7]        
  0x003B70B5  0fbf5e0e                movsx    ebx, word ptr [esi + 0xe]      
  0x003B70B9  03d7                    add      edx, edi                       
  0x003B70BB  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B70BE  885007                  mov      byte ptr [eax + 7], dl         
  0x003B70C1  0fb65108                movzx    edx, byte ptr [ecx + 8]        
  0x003B70C5  0fbf5e10                movsx    ebx, word ptr [esi + 0x10]     
  0x003B70C9  03d7                    add      edx, edi                       
  0x003B70CB  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B70CE  881428                  mov      byte ptr [eax + ebp], dl       
  0x003B70D1  0fb65109                movzx    edx, byte ptr [ecx + 9]        
  0x003B70D5  0fbf5e12                movsx    ebx, word ptr [esi + 0x12]     
  0x003B70D9  83c108                  add      ecx, 8                         
  0x003B70DC  83c610                  add      esi, 0x10                      
  0x003B70DF  03d7                    add      edx, edi                       
  0x003B70E1  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B70E4  88542801                mov      byte ptr [eax + ebp + 1], dl   
  0x003B70E8  0fb65102                movzx    edx, byte ptr [ecx + 2]        
  0x003B70EC  0fbf5e04                movsx    ebx, word ptr [esi + 4]        
  0x003B70F0  03c5                    add      eax, ebp                       
  0x003B70F2  03d7                    add      edx, edi                       
  0x003B70F4  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B70F7  885002                  mov      byte ptr [eax + 2], dl         
  0x003B70FA  0fb65103                movzx    edx, byte ptr [ecx + 3]        
  0x003B70FE  0fbf5e06                movsx    ebx, word ptr [esi + 6]        
  0x003B7102  03d7                    add      edx, edi                       
  0x003B7104  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B7107  885003                  mov      byte ptr [eax + 3], dl         
  0x003B710A  0fb65104                movzx    edx, byte ptr [ecx + 4]        
  0x003B710E  0fbf5e08                movsx    ebx, word ptr [esi + 8]        
  0x003B7112  03d7                    add      edx, edi                       
  0x003B7114  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B7117  885004                  mov      byte ptr [eax + 4], dl         
  0x003B711A  0fb65105                movzx    edx, byte ptr [ecx + 5]        
  0x003B711E  0fbf5e0a                movsx    ebx, word ptr [esi + 0xa]      
  0x003B7122  03d7                    add      edx, edi                       
  0x003B7124  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B7127  885005                  mov      byte ptr [eax + 5], dl         
  0x003B712A  0fb65106                movzx    edx, byte ptr [ecx + 6]        
  0x003B712E  0fbf5e0c                movsx    ebx, word ptr [esi + 0xc]      
  0x003B7132  03d7                    add      edx, edi                       
  0x003B7134  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B7137  885006                  mov      byte ptr [eax + 6], dl         
  0x003B713A  0fb65107                movzx    edx, byte ptr [ecx + 7]        
  0x003B713E  0fbf5e0e                movsx    ebx, word ptr [esi + 0xe]      
  0x003B7142  03d7                    add      edx, edi                       
  0x003B7144  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B7147  885007                  mov      byte ptr [eax + 7], dl         
  0x003B714A  8b542410                mov      edx, dword ptr [esp + 0x10]    
  0x003B714E  83c108                  add      ecx, 8                         
  0x003B7151  83c610                  add      esi, 0x10                      
  0x003B7154  03c5                    add      eax, ebp                       
  0x003B7156  4a                      dec      edx                            
  0x003B7157  89542410                mov      dword ptr [esp + 0x10], edx    
  0x003B715B  0f85d0fdffff            jne      0x3b6f31                       
  0x003B7161  8b542418                mov      edx, dword ptr [esp + 0x18]    
                                        ; XREF: 0x003B6F24 (jump)
  0x003B7165  8b5c2420                mov      ebx, dword ptr [esp + 0x20]    
  0x003B7169  8b442414                mov      eax, dword ptr [esp + 0x14]    
  0x003B716D  d1e3                    shl      ebx, 1                         
  0x003B716F  48                      dec      eax                            
  0x003B7170  895c2420                mov      dword ptr [esp + 0x20], ebx    
  0x003B7174  89442414                mov      dword ptr [esp + 0x14], eax    
  0x003B7178  0f8552fdffff            jne      0x3b6ed0                       
  0x003B717E  5f                      pop      edi                            
  0x003B717F  5e                      pop      esi                            
  0x003B7180  5d                      pop      ebp                            
  0x003B7181  5b                      pop      ebx                            
  0x003B7182  83c40c                  add      esp, 0xc                       
  0x003B7185  c3                      ret                                     
  0x003B7186  cc                      int3                                    
  0x003B7187  cc                      int3                                    
  0x003B7188  cc                      int3                                    
  0x003B7189  cc                      int3                                    
  0x003B718A  cc                      int3                                    
  0x003B718B  cc                      int3                                    
  0x003B718C  cc                      int3                                    
  0x003B718D  cc                      int3                                    
  0x003B718E  cc                      int3                                    
  0x003B718F  cc                      int3                                    

; ============================================================
; Function: sub_003B7190
; Start: 0x003B7190  End: 0x003B7438  Size: 680 bytes
; Detection: call_target (confidence: 0.90)
; ============================================================
sub_003B7190:
  0x003B7190  83ec10                  sub      esp, 0x10                      
  0x003B7193  8b4808                  mov      ecx, dword ptr [eax + 8]       
  0x003B7196  53                      push     ebx                            
  0x003B7197  55                      push     ebp                            
  0x003B7198  8b28                    mov      ebp, dword ptr [eax]           
  0x003B719A  56                      push     esi                            
  0x003B719B  8b700c                  mov      esi, dword ptr [eax + 0xc]     
  0x003B719E  57                      push     edi                            
  0x003B719F  8b7804                  mov      edi, dword ptr [eax + 4]       
  0x003B71A2  83c204                  add      edx, 4                         
  0x003B71A5  c744241c06000000        mov      dword ptr [esp + 0x1c], 6      
  0x003B71AD  8d4900                  lea      ecx, [ecx]                     
                                        ; XREF: 0x003B7541 (cond_jump)
  0x003B71B0  8b02                    mov      eax, dword ptr [edx]           
  0x003B71B2  8b5a04                  mov      ebx, dword ptr [edx + 4]       
  0x003B71B5  83c204                  add      edx, 4                         
  0x003B71B8  83c204                  add      edx, 4                         
  0x003B71BB  89542418                mov      dword ptr [esp + 0x18], edx    
  0x003B71BF  8b542424                mov      edx, dword ptr [esp + 0x24]    
  0x003B71C3  85d2                    test     edx, edx                       
  0x003B71C5  895c2410                mov      dword ptr [esp + 0x10], ebx    
  0x003B71C9  0f8c69020000            jl       0x3b7438                       
  0x003B71CF  81c780000000            add      edi, 0x80                      
  0x003B71D5  c744241402000000        mov      dword ptr [esp + 0x14], 2      
  0x003B71DD  8d4900                  lea      ecx, [ecx]                     
                                        ; XREF: 0x003B742D (cond_jump)
  0x003B71E0  0fb619                  movzx    ebx, byte ptr [ecx]            
  0x003B71E3  0fb616                  movzx    edx, byte ptr [esi]            
  0x003B71E6  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B71EA  d1fa                    sar      edx, 1                         
  0x003B71EC  8810                    mov      byte ptr [eax], dl             
  0x003B71EE  0fb65901                movzx    ebx, byte ptr [ecx + 1]        
  0x003B71F2  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B71F6  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B71FA  d1fa                    sar      edx, 1                         
  0x003B71FC  885001                  mov      byte ptr [eax + 1], dl         
  0x003B71FF  0fb65902                movzx    ebx, byte ptr [ecx + 2]        
  0x003B7203  0fb65602                movzx    edx, byte ptr [esi + 2]        
  0x003B7207  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B720B  d1fa                    sar      edx, 1                         
  0x003B720D  885002                  mov      byte ptr [eax + 2], dl         
  0x003B7210  0fb65903                movzx    ebx, byte ptr [ecx + 3]        
  0x003B7214  0fb65603                movzx    edx, byte ptr [esi + 3]        
  0x003B7218  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B721C  d1fa                    sar      edx, 1                         
  0x003B721E  885003                  mov      byte ptr [eax + 3], dl         
  0x003B7221  0fb65904                movzx    ebx, byte ptr [ecx + 4]        
  0x003B7225  0fb65604                movzx    edx, byte ptr [esi + 4]        
  0x003B7229  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B722D  d1fa                    sar      edx, 1                         
  0x003B722F  885004                  mov      byte ptr [eax + 4], dl         
  0x003B7232  0fb65905                movzx    ebx, byte ptr [ecx + 5]        
  0x003B7236  0fb65605                movzx    edx, byte ptr [esi + 5]        
  0x003B723A  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B723E  d1fa                    sar      edx, 1                         
  0x003B7240  885005                  mov      byte ptr [eax + 5], dl         
  0x003B7243  0fb65906                movzx    ebx, byte ptr [ecx + 6]        
  0x003B7247  0fb65606                movzx    edx, byte ptr [esi + 6]        
  0x003B724B  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B724F  d1fa                    sar      edx, 1                         
  0x003B7251  885006                  mov      byte ptr [eax + 6], dl         
  0x003B7254  0fb65907                movzx    ebx, byte ptr [ecx + 7]        
  0x003B7258  0fb65607                movzx    edx, byte ptr [esi + 7]        
  0x003B725C  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B7260  d1fa                    sar      edx, 1                         
  0x003B7262  885007                  mov      byte ptr [eax + 7], dl         
  0x003B7265  0fb65908                movzx    ebx, byte ptr [ecx + 8]        
  0x003B7269  03442410                add      eax, dword ptr [esp + 0x10]    
  0x003B726D  0fb65608                movzx    edx, byte ptr [esi + 8]        
  0x003B7271  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B7275  d1fa                    sar      edx, 1                         
  0x003B7277  8810                    mov      byte ptr [eax], dl             
  0x003B7279  0fb65909                movzx    ebx, byte ptr [ecx + 9]        
  0x003B727D  0fb65609                movzx    edx, byte ptr [esi + 9]        
  0x003B7281  83c108                  add      ecx, 8                         
  0x003B7284  83c608                  add      esi, 8                         
  0x003B7287  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B728B  d1fa                    sar      edx, 1                         
  0x003B728D  885001                  mov      byte ptr [eax + 1], dl         
  0x003B7290  0fb65902                movzx    ebx, byte ptr [ecx + 2]        
  0x003B7294  0fb65602                movzx    edx, byte ptr [esi + 2]        
  0x003B7298  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B729C  d1fa                    sar      edx, 1                         
  0x003B729E  885002                  mov      byte ptr [eax + 2], dl         
  0x003B72A1  0fb65903                movzx    ebx, byte ptr [ecx + 3]        
  0x003B72A5  0fb65603                movzx    edx, byte ptr [esi + 3]        
  0x003B72A9  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B72AD  d1fa                    sar      edx, 1                         
  0x003B72AF  885003                  mov      byte ptr [eax + 3], dl         
  0x003B72B2  0fb65904                movzx    ebx, byte ptr [ecx + 4]        
  0x003B72B6  0fb65604                movzx    edx, byte ptr [esi + 4]        
  0x003B72BA  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B72BE  d1fa                    sar      edx, 1                         
  0x003B72C0  885004                  mov      byte ptr [eax + 4], dl         
  0x003B72C3  0fb65905                movzx    ebx, byte ptr [ecx + 5]        
  0x003B72C7  0fb65605                movzx    edx, byte ptr [esi + 5]        
  0x003B72CB  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B72CF  d1fa                    sar      edx, 1                         
  0x003B72D1  885005                  mov      byte ptr [eax + 5], dl         
  0x003B72D4  0fb65906                movzx    ebx, byte ptr [ecx + 6]        
  0x003B72D8  0fb65606                movzx    edx, byte ptr [esi + 6]        
  0x003B72DC  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B72E0  d1fa                    sar      edx, 1                         
  0x003B72E2  885006                  mov      byte ptr [eax + 6], dl         
  0x003B72E5  0fb65607                movzx    edx, byte ptr [esi + 7]        
  0x003B72E9  0fb65907                movzx    ebx, byte ptr [ecx + 7]        
  0x003B72ED  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B72F1  d1fa                    sar      edx, 1                         
  0x003B72F3  885007                  mov      byte ptr [eax + 7], dl         
  0x003B72F6  0fb65908                movzx    ebx, byte ptr [ecx + 8]        
  0x003B72FA  03442410                add      eax, dword ptr [esp + 0x10]    
  0x003B72FE  0fb65608                movzx    edx, byte ptr [esi + 8]        
  0x003B7302  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B7306  d1fa                    sar      edx, 1                         
  0x003B7308  8810                    mov      byte ptr [eax], dl             
  0x003B730A  0fb65909                movzx    ebx, byte ptr [ecx + 9]        
  0x003B730E  0fb65609                movzx    edx, byte ptr [esi + 9]        
  0x003B7312  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B7316  d1fa                    sar      edx, 1                         
  0x003B7318  885001                  mov      byte ptr [eax + 1], dl         
  0x003B731B  0fb6590a                movzx    ebx, byte ptr [ecx + 0xa]      
  0x003B731F  0fb6560a                movzx    edx, byte ptr [esi + 0xa]      
  0x003B7323  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B7327  83c108                  add      ecx, 8                         
  0x003B732A  83c608                  add      esi, 8                         
  0x003B732D  d1fa                    sar      edx, 1                         
  0x003B732F  885002                  mov      byte ptr [eax + 2], dl         
  0x003B7332  0fb65903                movzx    ebx, byte ptr [ecx + 3]        
  0x003B7336  0fb65603                movzx    edx, byte ptr [esi + 3]        
  0x003B733A  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B733E  d1fa                    sar      edx, 1                         
  0x003B7340  885003                  mov      byte ptr [eax + 3], dl         
  0x003B7343  0fb65904                movzx    ebx, byte ptr [ecx + 4]        
  0x003B7347  0fb65604                movzx    edx, byte ptr [esi + 4]        
  0x003B734B  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B734F  d1fa                    sar      edx, 1                         
  0x003B7351  885004                  mov      byte ptr [eax + 4], dl         
  0x003B7354  0fb65905                movzx    ebx, byte ptr [ecx + 5]        
  0x003B7358  0fb65605                movzx    edx, byte ptr [esi + 5]        
  0x003B735C  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B7360  d1fa                    sar      edx, 1                         
  0x003B7362  885005                  mov      byte ptr [eax + 5], dl         
  0x003B7365  0fb65906                movzx    ebx, byte ptr [ecx + 6]        
  0x003B7369  0fb65606                movzx    edx, byte ptr [esi + 6]        
  0x003B736D  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B7371  d1fa                    sar      edx, 1                         
  0x003B7373  885006                  mov      byte ptr [eax + 6], dl         
  0x003B7376  0fb65907                movzx    ebx, byte ptr [ecx + 7]        
  0x003B737A  0fb65607                movzx    edx, byte ptr [esi + 7]        
  0x003B737E  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B7382  d1fa                    sar      edx, 1                         
  0x003B7384  885007                  mov      byte ptr [eax + 7], dl         
  0x003B7387  0fb65908                movzx    ebx, byte ptr [ecx + 8]        
  0x003B738B  03442410                add      eax, dword ptr [esp + 0x10]    
  0x003B738F  0fb65608                movzx    edx, byte ptr [esi + 8]        
  0x003B7393  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B7397  d1fa                    sar      edx, 1                         
  0x003B7399  8810                    mov      byte ptr [eax], dl             
  0x003B739B  0fb65909                movzx    ebx, byte ptr [ecx + 9]        
  0x003B739F  0fb65609                movzx    edx, byte ptr [esi + 9]        
  0x003B73A3  83c108                  add      ecx, 8                         
  0x003B73A6  83c608                  add      esi, 8                         
  0x003B73A9  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B73AD  d1fa                    sar      edx, 1                         
  0x003B73AF  885001                  mov      byte ptr [eax + 1], dl         
  0x003B73B2  0fb65902                movzx    ebx, byte ptr [ecx + 2]        
  0x003B73B6  0fb65602                movzx    edx, byte ptr [esi + 2]        
  0x003B73BA  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B73BE  d1fa                    sar      edx, 1                         
  0x003B73C0  885002                  mov      byte ptr [eax + 2], dl         
  0x003B73C3  0fb65903                movzx    ebx, byte ptr [ecx + 3]        
  0x003B73C7  0fb65603                movzx    edx, byte ptr [esi + 3]        
  0x003B73CB  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B73CF  d1fa                    sar      edx, 1                         
  0x003B73D1  885003                  mov      byte ptr [eax + 3], dl         
  0x003B73D4  0fb65904                movzx    ebx, byte ptr [ecx + 4]        
  0x003B73D8  0fb65604                movzx    edx, byte ptr [esi + 4]        
  0x003B73DC  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B73E0  d1fa                    sar      edx, 1                         
  0x003B73E2  885004                  mov      byte ptr [eax + 4], dl         
  0x003B73E5  0fb65605                movzx    edx, byte ptr [esi + 5]        
  0x003B73E9  0fb65905                movzx    ebx, byte ptr [ecx + 5]        
  0x003B73ED  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B73F1  d1fa                    sar      edx, 1                         
  0x003B73F3  885005                  mov      byte ptr [eax + 5], dl         
  0x003B73F6  0fb65906                movzx    ebx, byte ptr [ecx + 6]        
  0x003B73FA  0fb65606                movzx    edx, byte ptr [esi + 6]        
  0x003B73FE  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B7402  d1fa                    sar      edx, 1                         
  0x003B7404  885006                  mov      byte ptr [eax + 6], dl         
  0x003B7407  0fb65907                movzx    ebx, byte ptr [ecx + 7]        
  0x003B740B  0fb65607                movzx    edx, byte ptr [esi + 7]        
  0x003B740F  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B7413  8b5c2410                mov      ebx, dword ptr [esp + 0x10]    
  0x003B7417  d1fa                    sar      edx, 1                         
  0x003B7419  885007                  mov      byte ptr [eax + 7], dl         
  0x003B741C  8b542414                mov      edx, dword ptr [esp + 0x14]    
  0x003B7420  83c108                  add      ecx, 8                         
  0x003B7423  83c608                  add      esi, 8                         
  0x003B7426  03c3                    add      eax, ebx                       
  0x003B7428  4a                      dec      edx                            
  0x003B7429  89542414                mov      dword ptr [esp + 0x14], edx    
  0x003B742D  0f85adfdffff            jne      0x3b71e0                       
  0x003B7433  e9f2000000              jmp      0x3b752a                       
; end of function
                                        ; XREF: 0x003B71C9 (cond_jump)
  0x003B7438  c744241408000000        mov      dword ptr [esp + 0x14], 8      
                                        ; XREF: 0x003B7524 (cond_jump)
  0x003B7440  0fb619                  movzx    ebx, byte ptr [ecx]            
  0x003B7443  0fb616                  movzx    edx, byte ptr [esi]            
  0x003B7446  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B744A  0fbf1f                  movsx    ebx, word ptr [edi]            
  0x003B744D  d1fa                    sar      edx, 1                         
  0x003B744F  03d5                    add      edx, ebp                       
  0x003B7451  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B7454  8810                    mov      byte ptr [eax], dl             
  0x003B7456  0fb65901                movzx    ebx, byte ptr [ecx + 1]        
  0x003B745A  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B745E  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B7462  0fbf5f02                movsx    ebx, word ptr [edi + 2]        
  0x003B7466  d1fa                    sar      edx, 1                         
  0x003B7468  03d5                    add      edx, ebp                       
  0x003B746A  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B746D  885001                  mov      byte ptr [eax + 1], dl         
  0x003B7470  0fb65902                movzx    ebx, byte ptr [ecx + 2]        
  0x003B7474  0fb65602                movzx    edx, byte ptr [esi + 2]        
  0x003B7478  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B747C  0fbf5f04                movsx    ebx, word ptr [edi + 4]        
  0x003B7480  d1fa                    sar      edx, 1                         
  0x003B7482  03d5                    add      edx, ebp                       
  0x003B7484  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B7487  885002                  mov      byte ptr [eax + 2], dl         
  0x003B748A  0fb65903                movzx    ebx, byte ptr [ecx + 3]        
  0x003B748E  0fb65603                movzx    edx, byte ptr [esi + 3]        
  0x003B7492  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B7496  0fbf5f06                movsx    ebx, word ptr [edi + 6]        
  0x003B749A  d1fa                    sar      edx, 1                         
  0x003B749C  03d5                    add      edx, ebp                       
  0x003B749E  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B74A1  885003                  mov      byte ptr [eax + 3], dl         
  0x003B74A4  0fb65904                movzx    ebx, byte ptr [ecx + 4]        
  0x003B74A8  0fb65604                movzx    edx, byte ptr [esi + 4]        
  0x003B74AC  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B74B0  0fbf5f08                movsx    ebx, word ptr [edi + 8]        
  0x003B74B4  d1fa                    sar      edx, 1                         
  0x003B74B6  03d5                    add      edx, ebp                       
  0x003B74B8  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B74BB  885004                  mov      byte ptr [eax + 4], dl         
  0x003B74BE  0fb65905                movzx    ebx, byte ptr [ecx + 5]        
  0x003B74C2  0fb65605                movzx    edx, byte ptr [esi + 5]        
  0x003B74C6  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B74CA  0fbf5f0a                movsx    ebx, word ptr [edi + 0xa]      
  0x003B74CE  d1fa                    sar      edx, 1                         
  0x003B74D0  03d5                    add      edx, ebp                       
  0x003B74D2  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B74D5  885005                  mov      byte ptr [eax + 5], dl         
  0x003B74D8  0fb65906                movzx    ebx, byte ptr [ecx + 6]        
  0x003B74DC  0fb65606                movzx    edx, byte ptr [esi + 6]        
  0x003B74E0  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B74E4  0fbf5f0c                movsx    ebx, word ptr [edi + 0xc]      
  0x003B74E8  d1fa                    sar      edx, 1                         
  0x003B74EA  03d5                    add      edx, ebp                       
  0x003B74EC  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B74EF  885006                  mov      byte ptr [eax + 6], dl         
  0x003B74F2  0fb65907                movzx    ebx, byte ptr [ecx + 7]        
  0x003B74F6  0fb65607                movzx    edx, byte ptr [esi + 7]        
  0x003B74FA  8d541a01                lea      edx, [edx + ebx + 1]           
  0x003B74FE  0fbf5f0e                movsx    ebx, word ptr [edi + 0xe]      
  0x003B7502  d1fa                    sar      edx, 1                         
  0x003B7504  03d5                    add      edx, ebp                       
  0x003B7506  8a1413                  mov      dl, byte ptr [ebx + edx]       
  0x003B7509  8b5c2410                mov      ebx, dword ptr [esp + 0x10]    
  0x003B750D  885007                  mov      byte ptr [eax + 7], dl         
  0x003B7510  8b542414                mov      edx, dword ptr [esp + 0x14]    
  0x003B7514  83c108                  add      ecx, 8                         
  0x003B7517  83c608                  add      esi, 8                         
  0x003B751A  83c710                  add      edi, 0x10                      
  0x003B751D  03c3                    add      eax, ebx                       
  0x003B751F  4a                      dec      edx                            
  0x003B7520  89542414                mov      dword ptr [esp + 0x14], edx    
  0x003B7524  0f8516ffffff            jne      0x3b7440                       
                                        ; XREF: 0x003B7433 (jump)
  0x003B752A  8b5c2424                mov      ebx, dword ptr [esp + 0x24]    
  0x003B752E  8b44241c                mov      eax, dword ptr [esp + 0x1c]    
  0x003B7532  8b542418                mov      edx, dword ptr [esp + 0x18]    
  0x003B7536  d1e3                    shl      ebx, 1                         
  0x003B7538  48                      dec      eax                            
  0x003B7539  895c2424                mov      dword ptr [esp + 0x24], ebx    
  0x003B753D  8944241c                mov      dword ptr [esp + 0x1c], eax    
  0x003B7541  0f8569fcffff            jne      0x3b71b0                       
  0x003B7547  5f                      pop      edi                            
  0x003B7548  5e                      pop      esi                            
  0x003B7549  5d                      pop      ebp                            
  0x003B754A  5b                      pop      ebx                            
  0x003B754B  83c410                  add      esp, 0x10                      
  0x003B754E  c3                      ret                                     
  0x003B754F  cc                      int3                                    

; ============================================================
; Function: sub_003B7550
; Start: 0x003B7550  End: 0x003B7651  Size: 257 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_003B7C70
; ============================================================
sub_003B7550:
  0x003B7550  8b4c2404                mov      ecx, dword ptr [esp + 4]       
  0x003B7554  55                      push     ebp                            
  0x003B7555  8b6c240c                mov      ebp, dword ptr [esp + 0xc]     
  0x003B7559  0fbf450c                movsx    eax, word ptr [ebp + 0xc]      
  0x003B755D  99                      cdq                                     
  0x003B755E  83e207                  and      edx, 7                         
  0x003B7561  03c2                    add      eax, edx                       
  0x003B7563  8b11                    mov      edx, dword ptr [ecx]           
  0x003B7565  56                      push     esi                            
  0x003B7566  c1f803                  sar      eax, 3                         
  0x003B7569  57                      push     edi                            
  0x003B756A  8d3c00                  lea      edi, [eax + eax]               
  0x003B756D  c1e703                  shl      edi, 3                         
  0x003B7570  f6c21f                  test     dl, 0x1f                       
  0x003B7573  0f85d8000000            jne      0x3b7651                       
  0x003B7579  8b33                    mov      esi, dword ptr [ebx]           
  0x003B757B  dd0416                  fld      qword ptr [esi + edx]          
  0x003B757E  8b4d00                  mov      ecx, dword ptr [ebp]           
  0x003B7581  0f180c11                prefetcht0 byte ptr [ecx + edx]           
  0x003B7585  03ca                    add      ecx, edx                       
  0x003B7587  0f180cc1                prefetcht0 byte ptr [ecx + eax*8]         
  0x003B758B  03f2                    add      esi, edx                       
  0x003B758D  dd04c6                  fld      qword ptr [esi + eax*8]        
  0x003B7590  03f7                    add      esi, edi                       
  0x003B7592  d9c9                    fxch     st(1)                          
  0x003B7594  dd19                    fstp     qword ptr [ecx]                
  0x003B7596  dd1cc1                  fstp     qword ptr [ecx + eax*8]        
  0x003B7599  0f180c39                prefetcht0 byte ptr [ecx + edi]           
  0x003B759D  dd06                    fld      qword ptr [esi]                
  0x003B759F  03cf                    add      ecx, edi                       
  0x003B75A1  0f180cc1                prefetcht0 byte ptr [ecx + eax*8]         
  0x003B75A5  dd04c6                  fld      qword ptr [esi + eax*8]        
  0x003B75A8  03f7                    add      esi, edi                       
  0x003B75AA  d9c9                    fxch     st(1)                          
  0x003B75AC  dd19                    fstp     qword ptr [ecx]                
  0x003B75AE  dd1cc1                  fstp     qword ptr [ecx + eax*8]        
  0x003B75B1  0f180c39                prefetcht0 byte ptr [ecx + edi]           
  0x003B75B5  dd06                    fld      qword ptr [esi]                
  0x003B75B7  03cf                    add      ecx, edi                       
  0x003B75B9  0f180cc1                prefetcht0 byte ptr [ecx + eax*8]         
  0x003B75BD  dd04c6                  fld      qword ptr [esi + eax*8]        
  0x003B75C0  d9c9                    fxch     st(1)                          
  0x003B75C2  03f7                    add      esi, edi                       
  0x003B75C4  dd19                    fstp     qword ptr [ecx]                
  0x003B75C6  dd1cc1                  fstp     qword ptr [ecx + eax*8]        
  0x003B75C9  0f180c39                prefetcht0 byte ptr [ecx + edi]           
  0x003B75CD  dd04c6                  fld      qword ptr [esi + eax*8]        
  0x003B75D0  03cf                    add      ecx, edi                       
  0x003B75D2  0f180cc1                prefetcht0 byte ptr [ecx + eax*8]         
  0x003B75D6  dd06                    fld      qword ptr [esi]                
  0x003B75D8  dd19                    fstp     qword ptr [ecx]                
  0x003B75DA  8d14c1                  lea      edx, [ecx + eax*8]             
  0x003B75DD  dd1a                    fstp     qword ptr [edx]                
  0x003B75DF  8b4d04                  mov      ecx, dword ptr [ebp + 4]       
  0x003B75E2  8b542410                mov      edx, dword ptr [esp + 0x10]    
  0x003B75E6  8b32                    mov      esi, dword ptr [edx]           
  0x003B75E8  8b5304                  mov      edx, dword ptr [ebx + 4]       
  0x003B75EB  dd0432                  fld      qword ptr [edx + esi]          
  0x003B75EE  0f180c31                prefetcht0 byte ptr [ecx + esi]           
  0x003B75F2  03d6                    add      edx, esi                       
  0x003B75F4  dd04c2                  fld      qword ptr [edx + eax*8]        
  0x003B75F7  03ce                    add      ecx, esi                       
  0x003B75F9  0f180cc1                prefetcht0 byte ptr [ecx + eax*8]         
  0x003B75FD  d9c9                    fxch     st(1)                          
  0x003B75FF  dd19                    fstp     qword ptr [ecx]                
  0x003B7601  03d7                    add      edx, edi                       
  0x003B7603  dd1cc1                  fstp     qword ptr [ecx + eax*8]        
  0x003B7606  0f180c39                prefetcht0 byte ptr [ecx + edi]           
  0x003B760A  dd02                    fld      qword ptr [edx]                
  0x003B760C  03cf                    add      ecx, edi                       
  0x003B760E  dd04c2                  fld      qword ptr [edx + eax*8]        
  0x003B7611  0f180cc1                prefetcht0 byte ptr [ecx + eax*8]         
  0x003B7615  d9c9                    fxch     st(1)                          
  0x003B7617  03d7                    add      edx, edi                       
  0x003B7619  dd19                    fstp     qword ptr [ecx]                
  0x003B761B  dd1cc1                  fstp     qword ptr [ecx + eax*8]        
  0x003B761E  0f180c39                prefetcht0 byte ptr [ecx + edi]           
  0x003B7622  dd02                    fld      qword ptr [edx]                
  0x003B7624  03cf                    add      ecx, edi                       
  0x003B7626  dd04c2                  fld      qword ptr [edx + eax*8]        
  0x003B7629  0f180cc1                prefetcht0 byte ptr [ecx + eax*8]         
  0x003B762D  d9c9                    fxch     st(1)                          
  0x003B762F  03d7                    add      edx, edi                       
  0x003B7631  dd19                    fstp     qword ptr [ecx]                
  0x003B7633  dd1cc1                  fstp     qword ptr [ecx + eax*8]        
  0x003B7636  0f180c39                prefetcht0 byte ptr [ecx + edi]           
  0x003B763A  dd04c2                  fld      qword ptr [edx + eax*8]        
  0x003B763D  03cf                    add      ecx, edi                       
  0x003B763F  dd02                    fld      qword ptr [edx]                
  0x003B7641  0f180cc1                prefetcht0 byte ptr [ecx + eax*8]         
  0x003B7645  8d34c1                  lea      esi, [ecx + eax*8]             
  0x003B7648  dd19                    fstp     qword ptr [ecx]                
  0x003B764A  dd1e                    fstp     qword ptr [esi]                
  0x003B764C  e98f000000              jmp      0x3b76e0                       
; end of function
                                        ; XREF: 0x003B7573 (cond_jump)
  0x003B7651  8b0b                    mov      ecx, dword ptr [ebx]           
  0x003B7653  dd0411                  fld      qword ptr [ecx + edx]          
  0x003B7656  8b7500                  mov      esi, dword ptr [ebp]           
  0x003B7659  03ca                    add      ecx, edx                       
  0x003B765B  dd04c1                  fld      qword ptr [ecx + eax*8]        
  0x003B765E  03f2                    add      esi, edx                       
  0x003B7660  03cf                    add      ecx, edi                       
  0x003B7662  d9c9                    fxch     st(1)                          
  0x003B7664  dd1e                    fstp     qword ptr [esi]                
  0x003B7666  dd1cc6                  fstp     qword ptr [esi + eax*8]        
  0x003B7669  03f7                    add      esi, edi                       
  0x003B766B  dd01                    fld      qword ptr [ecx]                
  0x003B766D  dd04c1                  fld      qword ptr [ecx + eax*8]        
  0x003B7670  03cf                    add      ecx, edi                       
  0x003B7672  d9c9                    fxch     st(1)                          
  0x003B7674  dd1e                    fstp     qword ptr [esi]                
  0x003B7676  dd1cc6                  fstp     qword ptr [esi + eax*8]        
  0x003B7679  03f7                    add      esi, edi                       
  0x003B767B  dd01                    fld      qword ptr [ecx]                
  0x003B767D  dd04c1                  fld      qword ptr [ecx + eax*8]        
  0x003B7680  03cf                    add      ecx, edi                       
  0x003B7682  d9c9                    fxch     st(1)                          
  0x003B7684  dd1e                    fstp     qword ptr [esi]                
  0x003B7686  dd1cc6                  fstp     qword ptr [esi + eax*8]        
  0x003B7689  03f7                    add      esi, edi                       
  0x003B768B  dd04c1                  fld      qword ptr [ecx + eax*8]        
  0x003B768E  dd01                    fld      qword ptr [ecx]                
  0x003B7690  8b4c2410                mov      ecx, dword ptr [esp + 0x10]    
  0x003B7694  dd1e                    fstp     qword ptr [esi]                
  0x003B7696  dd1cc6                  fstp     qword ptr [esi + eax*8]        
  0x003B7699  8b31                    mov      esi, dword ptr [ecx]           
  0x003B769B  8b4b04                  mov      ecx, dword ptr [ebx + 4]       
  0x003B769E  dd0431                  fld      qword ptr [ecx + esi]          
  0x003B76A1  8b5504                  mov      edx, dword ptr [ebp + 4]       
  0x003B76A4  03ce                    add      ecx, esi                       
  0x003B76A6  dd04c1                  fld      qword ptr [ecx + eax*8]        
  0x003B76A9  03d6                    add      edx, esi                       
  0x003B76AB  03cf                    add      ecx, edi                       
  0x003B76AD  d9c9                    fxch     st(1)                          
  0x003B76AF  dd1a                    fstp     qword ptr [edx]                
  0x003B76B1  dd1cc2                  fstp     qword ptr [edx + eax*8]        
  0x003B76B4  03d7                    add      edx, edi                       
  0x003B76B6  dd01                    fld      qword ptr [ecx]                
  0x003B76B8  dd04c1                  fld      qword ptr [ecx + eax*8]        
  0x003B76BB  03cf                    add      ecx, edi                       
  0x003B76BD  d9c9                    fxch     st(1)                          
  0x003B76BF  dd1a                    fstp     qword ptr [edx]                
  0x003B76C1  dd1cc2                  fstp     qword ptr [edx + eax*8]        
  0x003B76C4  03d7                    add      edx, edi                       
  0x003B76C6  dd01                    fld      qword ptr [ecx]                
  0x003B76C8  dd04c1                  fld      qword ptr [ecx + eax*8]        
  0x003B76CB  03cf                    add      ecx, edi                       
  0x003B76CD  d9c9                    fxch     st(1)                          
  0x003B76CF  dd1a                    fstp     qword ptr [edx]                
  0x003B76D1  dd1cc2                  fstp     qword ptr [edx + eax*8]        
  0x003B76D4  03d7                    add      edx, edi                       
  0x003B76D6  dd04c1                  fld      qword ptr [ecx + eax*8]        
  0x003B76D9  dd01                    fld      qword ptr [ecx]                
  0x003B76DB  dd1a                    fstp     qword ptr [edx]                
  0x003B76DD  dd1cc2                  fstp     qword ptr [edx + eax*8]        
                                        ; XREF: 0x003B764C (jump)
  0x003B76E0  0fbf450e                movsx    eax, word ptr [ebp + 0xe]      
  0x003B76E4  8b4c2410                mov      ecx, dword ptr [esp + 0x10]    
  0x003B76E8  8b7104                  mov      esi, dword ptr [ecx + 4]       
  0x003B76EB  99                      cdq                                     
  0x003B76EC  83e207                  and      edx, 7                         
  0x003B76EF  03c2                    add      eax, edx                       
  0x003B76F1  8a5104                  mov      dl, byte ptr [ecx + 4]         
  0x003B76F4  c1f803                  sar      eax, 3                         
  0x003B76F7  c1e003                  shl      eax, 3                         
  0x003B76FA  f6c21f                  test     dl, 0x1f                       
  0x003B76FD  0f854b010000            jne      0x3b784e                       
  0x003B7703  8b5308                  mov      edx, dword ptr [ebx + 8]       
  0x003B7706  dd0432                  fld      qword ptr [edx + esi]          
  0x003B7709  8b4d08                  mov      ecx, dword ptr [ebp + 8]       
  0x003B770C  dd443208                fld      qword ptr [edx + esi + 8]      
  0x003B7710  0f180c31                prefetcht0 byte ptr [ecx + esi]           
  0x003B7714  03d6                    add      edx, esi                       
  0x003B7716  d9c9                    fxch     st(1)                          
  0x003B7718  dd1c31                  fstp     qword ptr [ecx + esi]          
  0x003B771B  03ce                    add      ecx, esi                       
  0x003B771D  03d0                    add      edx, eax                       
  0x003B771F  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003B7722  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003B7726  dd02                    fld      qword ptr [edx]                
  0x003B7728  03c8                    add      ecx, eax                       
  0x003B772A  dd4208                  fld      qword ptr [edx + 8]            
  0x003B772D  03d0                    add      edx, eax                       
  0x003B772F  d9c9                    fxch     st(1)                          
  0x003B7731  dd19                    fstp     qword ptr [ecx]                
  0x003B7733  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003B7736  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003B773A  dd02                    fld      qword ptr [edx]                
  0x003B773C  03c8                    add      ecx, eax                       
  0x003B773E  dd4208                  fld      qword ptr [edx + 8]            
  0x003B7741  03d0                    add      edx, eax                       
  0x003B7743  d9c9                    fxch     st(1)                          
  0x003B7745  dd19                    fstp     qword ptr [ecx]                
  0x003B7747  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003B774A  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003B774E  dd02                    fld      qword ptr [edx]                
  0x003B7750  03c8                    add      ecx, eax                       
  0x003B7752  dd4208                  fld      qword ptr [edx + 8]            
  0x003B7755  03d0                    add      edx, eax                       
  0x003B7757  d9c9                    fxch     st(1)                          
  0x003B7759  dd19                    fstp     qword ptr [ecx]                
  0x003B775B  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003B775E  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003B7762  dd02                    fld      qword ptr [edx]                
  0x003B7764  03c8                    add      ecx, eax                       
  0x003B7766  dd4208                  fld      qword ptr [edx + 8]            
  0x003B7769  03d0                    add      edx, eax                       
  0x003B776B  d9c9                    fxch     st(1)                          
  0x003B776D  dd19                    fstp     qword ptr [ecx]                
  0x003B776F  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003B7772  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003B7776  dd02                    fld      qword ptr [edx]                
  0x003B7778  03c8                    add      ecx, eax                       
  0x003B777A  dd4208                  fld      qword ptr [edx + 8]            
  0x003B777D  03d0                    add      edx, eax                       
  0x003B777F  d9c9                    fxch     st(1)                          
  0x003B7781  dd19                    fstp     qword ptr [ecx]                
  0x003B7783  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003B7786  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003B778A  dd02                    fld      qword ptr [edx]                
  0x003B778C  03c8                    add      ecx, eax                       
  0x003B778E  dd4208                  fld      qword ptr [edx + 8]            
  0x003B7791  03d0                    add      edx, eax                       
  0x003B7793  d9c9                    fxch     st(1)                          
  0x003B7795  dd19                    fstp     qword ptr [ecx]                
  0x003B7797  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003B779A  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003B779E  dd02                    fld      qword ptr [edx]                
  0x003B77A0  03c8                    add      ecx, eax                       
  0x003B77A2  dd4208                  fld      qword ptr [edx + 8]            
  0x003B77A5  03d0                    add      edx, eax                       
  0x003B77A7  d9c9                    fxch     st(1)                          
  0x003B77A9  dd19                    fstp     qword ptr [ecx]                
  0x003B77AB  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003B77AE  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003B77B2  dd02                    fld      qword ptr [edx]                
  0x003B77B4  03c8                    add      ecx, eax                       
  0x003B77B6  dd4208                  fld      qword ptr [edx + 8]            
  0x003B77B9  03d0                    add      edx, eax                       
  0x003B77BB  d9c9                    fxch     st(1)                          
  0x003B77BD  dd19                    fstp     qword ptr [ecx]                
  0x003B77BF  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003B77C2  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003B77C6  dd02                    fld      qword ptr [edx]                
  0x003B77C8  03c8                    add      ecx, eax                       
  0x003B77CA  dd4208                  fld      qword ptr [edx + 8]            
  0x003B77CD  03d0                    add      edx, eax                       
  0x003B77CF  d9c9                    fxch     st(1)                          
  0x003B77D1  dd19                    fstp     qword ptr [ecx]                
  0x003B77D3  5f                      pop      edi                            
  0x003B77D4  5e                      pop      esi                            
  0x003B77D5  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003B77D8  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003B77DC  dd02                    fld      qword ptr [edx]                
  0x003B77DE  03c8                    add      ecx, eax                       
  0x003B77E0  dd4208                  fld      qword ptr [edx + 8]            
  0x003B77E3  03d0                    add      edx, eax                       
  0x003B77E5  d9c9                    fxch     st(1)                          
  0x003B77E7  5d                      pop      ebp                            
  0x003B77E8  dd19                    fstp     qword ptr [ecx]                
  0x003B77EA  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003B77ED  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003B77F1  dd02                    fld      qword ptr [edx]                
  0x003B77F3  03c8                    add      ecx, eax                       
  0x003B77F5  dd4208                  fld      qword ptr [edx + 8]            
  0x003B77F8  03d0                    add      edx, eax                       
  0x003B77FA  d9c9                    fxch     st(1)                          
  0x003B77FC  dd19                    fstp     qword ptr [ecx]                
  0x003B77FE  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003B7801  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003B7805  dd02                    fld      qword ptr [edx]                
  0x003B7807  03c8                    add      ecx, eax                       
  0x003B7809  dd4208                  fld      qword ptr [edx + 8]            
  0x003B780C  03d0                    add      edx, eax                       
  0x003B780E  d9c9                    fxch     st(1)                          
  0x003B7810  dd19                    fstp     qword ptr [ecx]                
  0x003B7812  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003B7815  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003B7819  dd02                    fld      qword ptr [edx]                
  0x003B781B  03c8                    add      ecx, eax                       
  0x003B781D  dd4208                  fld      qword ptr [edx + 8]            
  0x003B7820  03d0                    add      edx, eax                       
  0x003B7822  d9c9                    fxch     st(1)                          
  0x003B7824  dd19                    fstp     qword ptr [ecx]                
  0x003B7826  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003B7829  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003B782D  dd02                    fld      qword ptr [edx]                
  0x003B782F  03c8                    add      ecx, eax                       
  0x003B7831  dd4208                  fld      qword ptr [edx + 8]            
  0x003B7834  03d0                    add      edx, eax                       
  0x003B7836  d9c9                    fxch     st(1)                          
  0x003B7838  dd19                    fstp     qword ptr [ecx]                
  0x003B783A  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003B783D  0f180c01                prefetcht0 byte ptr [ecx + eax]           
  0x003B7841  dd4208                  fld      qword ptr [edx + 8]            
  0x003B7844  03c8                    add      ecx, eax                       
  0x003B7846  dd02                    fld      qword ptr [edx]                
  0x003B7848  dd19                    fstp     qword ptr [ecx]                
  0x003B784A  dd5908                  fstp     qword ptr [ecx + 8]            
  0x003B784D  c3                      ret                                     
                                        ; XREF: 0x003B76FD (cond_jump)
  0x003B784E  8b4b08                  mov      ecx, dword ptr [ebx + 8]       
  0x003B7851  dd0431                  fld      qword ptr [ecx + esi]          
  0x003B7854  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x003B7857  dd443108                fld      qword ptr [ecx + esi + 8]      
  0x003B785B  03ce                    add      ecx, esi                       
  0x003B785D  03d6                    add      edx, esi                       
  0x003B785F  d9c9                    fxch     st(1)                          
  0x003B7861  dd1a                    fstp     qword ptr [edx]                
  0x003B7863  03c8                    add      ecx, eax                       
  0x003B7865  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003B7868  03d0                    add      edx, eax                       
  0x003B786A  dd01                    fld      qword ptr [ecx]                
  0x003B786C  dd4108                  fld      qword ptr [ecx + 8]            
  0x003B786F  03c8                    add      ecx, eax                       
  0x003B7871  d9c9                    fxch     st(1)                          
  0x003B7873  dd1a                    fstp     qword ptr [edx]                
  0x003B7875  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003B7878  03d0                    add      edx, eax                       
  0x003B787A  dd01                    fld      qword ptr [ecx]                
  0x003B787C  dd4108                  fld      qword ptr [ecx + 8]            
  0x003B787F  03c8                    add      ecx, eax                       
  0x003B7881  d9c9                    fxch     st(1)                          
  0x003B7883  dd1a                    fstp     qword ptr [edx]                
  0x003B7885  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003B7888  03d0                    add      edx, eax                       
  0x003B788A  dd01                    fld      qword ptr [ecx]                
  0x003B788C  dd4108                  fld      qword ptr [ecx + 8]            
  0x003B788F  03c8                    add      ecx, eax                       
  0x003B7891  d9c9                    fxch     st(1)                          
  0x003B7893  dd1a                    fstp     qword ptr [edx]                
  0x003B7895  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003B7898  03d0                    add      edx, eax                       
  0x003B789A  dd01                    fld      qword ptr [ecx]                
  0x003B789C  dd4108                  fld      qword ptr [ecx + 8]            
  0x003B789F  03c8                    add      ecx, eax                       
  0x003B78A1  d9c9                    fxch     st(1)                          
  0x003B78A3  dd1a                    fstp     qword ptr [edx]                
  0x003B78A5  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003B78A8  03d0                    add      edx, eax                       
  0x003B78AA  dd01                    fld      qword ptr [ecx]                
  0x003B78AC  dd4108                  fld      qword ptr [ecx + 8]            
  0x003B78AF  03c8                    add      ecx, eax                       
  0x003B78B1  d9c9                    fxch     st(1)                          
  0x003B78B3  dd1a                    fstp     qword ptr [edx]                
  0x003B78B5  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003B78B8  03d0                    add      edx, eax                       
  0x003B78BA  dd01                    fld      qword ptr [ecx]                
  0x003B78BC  dd4108                  fld      qword ptr [ecx + 8]            
  0x003B78BF  03c8                    add      ecx, eax                       
  0x003B78C1  d9c9                    fxch     st(1)                          
  0x003B78C3  dd1a                    fstp     qword ptr [edx]                
  0x003B78C5  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003B78C8  03d0                    add      edx, eax                       
  0x003B78CA  dd01                    fld      qword ptr [ecx]                
  0x003B78CC  dd4108                  fld      qword ptr [ecx + 8]            
  0x003B78CF  03c8                    add      ecx, eax                       
  0x003B78D1  d9c9                    fxch     st(1)                          
  0x003B78D3  dd1a                    fstp     qword ptr [edx]                
  0x003B78D5  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003B78D8  03d0                    add      edx, eax                       
  0x003B78DA  dd01                    fld      qword ptr [ecx]                
  0x003B78DC  dd4108                  fld      qword ptr [ecx + 8]            
  0x003B78DF  03c8                    add      ecx, eax                       
  0x003B78E1  d9c9                    fxch     st(1)                          
  0x003B78E3  dd1a                    fstp     qword ptr [edx]                
  0x003B78E5  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003B78E8  03d0                    add      edx, eax                       
  0x003B78EA  dd01                    fld      qword ptr [ecx]                
  0x003B78EC  dd4108                  fld      qword ptr [ecx + 8]            
  0x003B78EF  03c8                    add      ecx, eax                       
  0x003B78F1  d9c9                    fxch     st(1)                          
  0x003B78F3  dd1a                    fstp     qword ptr [edx]                
  0x003B78F5  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003B78F8  03d0                    add      edx, eax                       
  0x003B78FA  dd01                    fld      qword ptr [ecx]                
  0x003B78FC  dd4108                  fld      qword ptr [ecx + 8]            
  0x003B78FF  03c8                    add      ecx, eax                       
  0x003B7901  d9c9                    fxch     st(1)                          
  0x003B7903  dd1a                    fstp     qword ptr [edx]                
  0x003B7905  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003B7908  03d0                    add      edx, eax                       
  0x003B790A  dd01                    fld      qword ptr [ecx]                
  0x003B790C  5f                      pop      edi                            
  0x003B790D  dd4108                  fld      qword ptr [ecx + 8]            
  0x003B7910  03c8                    add      ecx, eax                       
  0x003B7912  d9c9                    fxch     st(1)                          
  0x003B7914  5e                      pop      esi                            
  0x003B7915  dd1a                    fstp     qword ptr [edx]                
  0x003B7917  5d                      pop      ebp                            
  0x003B7918  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003B791B  03d0                    add      edx, eax                       
  0x003B791D  dd01                    fld      qword ptr [ecx]                
  0x003B791F  dd4108                  fld      qword ptr [ecx + 8]            
  0x003B7922  03c8                    add      ecx, eax                       
  0x003B7924  d9c9                    fxch     st(1)                          
  0x003B7926  dd1a                    fstp     qword ptr [edx]                
  0x003B7928  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003B792B  03d0                    add      edx, eax                       
  0x003B792D  dd01                    fld      qword ptr [ecx]                
  0x003B792F  dd4108                  fld      qword ptr [ecx + 8]            
  0x003B7932  03c8                    add      ecx, eax                       
  0x003B7934  d9c9                    fxch     st(1)                          
  0x003B7936  dd1a                    fstp     qword ptr [edx]                
  0x003B7938  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003B793B  03d0                    add      edx, eax                       
  0x003B793D  dd01                    fld      qword ptr [ecx]                
  0x003B793F  dd4108                  fld      qword ptr [ecx + 8]            
  0x003B7942  03c8                    add      ecx, eax                       
  0x003B7944  d9c9                    fxch     st(1)                          
  0x003B7946  dd1a                    fstp     qword ptr [edx]                
  0x003B7948  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003B794B  03d0                    add      edx, eax                       
  0x003B794D  dd4108                  fld      qword ptr [ecx + 8]            
  0x003B7950  dd01                    fld      qword ptr [ecx]                
  0x003B7952  dd1a                    fstp     qword ptr [edx]                
  0x003B7954  dd5a08                  fstp     qword ptr [edx + 8]            
  0x003B7957  c3                      ret                                     
  0x003B7958  cc                      int3                                    
  0x003B7959  cc                      int3                                    
  0x003B795A  cc                      int3                                    
  0x003B795B  cc                      int3                                    
  0x003B795C  cc                      int3                                    
  0x003B795D  cc                      int3                                    
  0x003B795E  cc                      int3                                    
  0x003B795F  cc                      int3                                    

; ============================================================
; Function: sub_003B7960
; Start: 0x003B7960  End: 0x003B7993  Size: 51 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_003B7A40, sub_003B7AC0, sub_003B7C70
; ============================================================
sub_003B7960:
  0x003B7960  56                      push     esi                            
  0x003B7961  8bf0                    mov      esi, eax                       
  0x003B7963  8b8138030000            mov      eax, dword ptr [ecx + 0x338]   
  0x003B7969  8b893c030000            mov      ecx, dword ptr [ecx + 0x33c]   
  0x003B796F  57                      push     edi                            
  0x003B7970  0fbf7e0c                movsx    edi, word ptr [esi + 0xc]      
  0x003B7974  c1e003                  shl      eax, 3                         
  0x003B7977  0faff8                  imul     edi, eax                       
  0x003B797A  c1e103                  shl      ecx, 3                         
  0x003B797D  03f9                    add      edi, ecx                       
  0x003B797F  893a                    mov      dword ptr [edx], edi           
  0x003B7981  0fbf760e                movsx    esi, word ptr [esi + 0xe]      
  0x003B7985  03c0                    add      eax, eax                       
  0x003B7987  0faff0                  imul     esi, eax                       
  0x003B798A  8d0c4e                  lea      ecx, [esi + ecx*2]             
  0x003B798D  5f                      pop      edi                            
  0x003B798E  894a04                  mov      dword ptr [edx + 4], ecx       
  0x003B7991  5e                      pop      esi                            
  0x003B7992  c3                      ret                                     
; end of function
  0x003B7993  cc                      int3                                    
  0x003B7994  cc                      int3                                    
  0x003B7995  cc                      int3                                    
  0x003B7996  cc                      int3                                    
  0x003B7997  cc                      int3                                    
  0x003B7998  cc                      int3                                    
  0x003B7999  cc                      int3                                    
  0x003B799A  cc                      int3                                    
  0x003B799B  cc                      int3                                    
  0x003B799C  cc                      int3                                    
  0x003B799D  cc                      int3                                    
  0x003B799E  cc                      int3                                    
  0x003B799F  cc                      int3                                    

; ============================================================
; Function: sub_003B79A0
; Start: 0x003B79A0  End: 0x003B79F5  Size: 85 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_003B7C70, sub_003B7CE0
; ============================================================
sub_003B79A0:
  0x003B79A0  56                      push     esi                            
  0x003B79A1  8bb034030000            mov      esi, dword ptr [eax + 0x334]   
  0x003B79A7  ba01000000              mov      edx, 1                         
  0x003B79AC  2bd1                    sub      edx, ecx                       
  0x003B79AE  03f2                    add      esi, edx                       
  0x003B79B0  ba01000000              mov      edx, 1                         
  0x003B79B5  2bd1                    sub      edx, ecx                       
  0x003B79B7  8b883c030000            mov      ecx, dword ptr [eax + 0x33c]   
  0x003B79BD  03ca                    add      ecx, edx                       
  0x003B79BF  89b034030000            mov      dword ptr [eax + 0x334], esi   
  0x003B79C5  89883c030000            mov      dword ptr [eax + 0x33c], ecx   
  0x003B79CB  7926                    jns      0x3b79f3                       
  0x003B79CD  8b88d8010000            mov      ecx, dword ptr [eax + 0x1d8]   
  0x003B79D3  8b903c030000            mov      edx, dword ptr [eax + 0x33c]   
  0x003B79D9  8bb038030000            mov      esi, dword ptr [eax + 0x338]   
  0x003B79DF  90                      nop                                     
                                        ; XREF: 0x003B79E5 (cond_jump)
  0x003B79E0  03d1                    add      edx, ecx                       
  0x003B79E2  4e                      dec      esi                            
  0x003B79E3  85d2                    test     edx, edx                       
  0x003B79E5  7cf9                    jl       0x3b79e0                       
  0x003B79E7  89b038030000            mov      dword ptr [eax + 0x338], esi   
  0x003B79ED  89903c030000            mov      dword ptr [eax + 0x33c], edx   
                                        ; XREF: 0x003B79CB (cond_jump)
  0x003B79F3  5e                      pop      esi                            
  0x003B79F4  c3                      ret                                     
; end of function
  0x003B79F5  cc                      int3                                    
  0x003B79F6  cc                      int3                                    
  0x003B79F7  cc                      int3                                    
  0x003B79F8  cc                      int3                                    
  0x003B79F9  cc                      int3                                    
  0x003B79FA  cc                      int3                                    
  0x003B79FB  cc                      int3                                    
  0x003B79FC  cc                      int3                                    
  0x003B79FD  cc                      int3                                    
  0x003B79FE  cc                      int3                                    
  0x003B79FF  cc                      int3                                    

; ============================================================
; Function: sub_003B7A00
; Start: 0x003B7A00  End: 0x003B7A3C  Size: 60 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_003B7C70, sub_003B7CE0
; ============================================================
sub_003B7A00:
  0x003B7A00  8b883c030000            mov      ecx, dword ptr [eax + 0x33c]   
  0x003B7A06  8b90d8010000            mov      edx, dword ptr [eax + 0x1d8]   
  0x003B7A0C  41                      inc      ecx                            
  0x003B7A0D  89883c030000            mov      dword ptr [eax + 0x33c], ecx   
  0x003B7A13  3bca                    cmp      ecx, edx                       
  0x003B7A15  8b8834030000            mov      ecx, dword ptr [eax + 0x334]   
  0x003B7A1B  7c17                    jl       0x3b7a34                       
  0x003B7A1D  8b9038030000            mov      edx, dword ptr [eax + 0x338]   
  0x003B7A23  42                      inc      edx                            
  0x003B7A24  c7803c03000000000000    mov      dword ptr [eax + 0x33c], 0     
  0x003B7A2E  899038030000            mov      dword ptr [eax + 0x338], edx   
                                        ; XREF: 0x003B7A1B (cond_jump)
  0x003B7A34  41                      inc      ecx                            
  0x003B7A35  898834030000            mov      dword ptr [eax + 0x334], ecx   
  0x003B7A3B  c3                      ret                                     
; end of function
  0x003B7A3C  cc                      int3                                    
  0x003B7A3D  cc                      int3                                    
  0x003B7A3E  cc                      int3                                    
  0x003B7A3F  cc                      int3                                    

; ============================================================
; Function: sub_003B7A40
; Start: 0x003B7A40  End: 0x003B7AB2  Size: 114 bytes
; Detection: cc_boundary (confidence: 0.85)
; Calls: sub_003B6C00, sub_003B7960
; ============================================================
sub_003B7A40:
  0x003B7A40  83ec08                  sub      esp, 8                         
  0x003B7A43  53                      push     ebx                            
  0x003B7A44  8b5c2410                mov      ebx, dword ptr [esp + 0x10]    
  0x003B7A48  56                      push     esi                            
  0x003B7A49  8db394020000            lea      esi, [ebx + 0x294]             
  0x003B7A4F  57                      push     edi                            
  0x003B7A50  8d54240c                lea      edx, [esp + 0xc]               
  0x003B7A54  8bc6                    mov      eax, esi                       
  0x003B7A56  8bcb                    mov      ecx, ebx                       
  0x003B7A58  8dbb20010000            lea      edi, [ebx + 0x120]             
  0x003B7A5E  e8fdfeffff              call     0x3b7960                       ; -> sub_003B7960
  0x003B7A63  8b16                    mov      edx, dword ptr [esi]           
  0x003B7A65  0fbf4e0e                movsx    ecx, word ptr [esi + 0xe]      
  0x003B7A69  8b44240c                mov      eax, dword ptr [esp + 0xc]     
  0x003B7A6D  03d0                    add      edx, eax                       
  0x003B7A6F  895704                  mov      dword ptr [edi + 4], edx       
  0x003B7A72  8b5604                  mov      edx, dword ptr [esi + 4]       
  0x003B7A75  03d0                    add      edx, eax                       
  0x003B7A77  89570c                  mov      dword ptr [edi + 0xc], edx     
  0x003B7A7A  8b4608                  mov      eax, dword ptr [esi + 8]       
  0x003B7A7D  8b542410                mov      edx, dword ptr [esp + 0x10]    
  0x003B7A81  03c2                    add      eax, edx                       
  0x003B7A83  894714                  mov      dword ptr [edi + 0x14], eax    
  0x003B7A86  83c008                  add      eax, 8                         
  0x003B7A89  89471c                  mov      dword ptr [edi + 0x1c], eax    
  0x003B7A8C  8b4714                  mov      eax, dword ptr [edi + 0x14]    
  0x003B7A8F  8d04c8                  lea      eax, [eax + ecx*8]             
  0x003B7A92  894724                  mov      dword ptr [edi + 0x24], eax    
  0x003B7A95  83c008                  add      eax, 8                         
  0x003B7A98  89472c                  mov      dword ptr [edi + 0x2c], eax    
  0x003B7A9B  8b7340                  mov      esi, dword ptr [ebx + 0x40]    
  0x003B7A9E  8d8b80030000            lea      ecx, [ebx + 0x380]             
  0x003B7AA4  8bd7                    mov      edx, edi                       
  0x003B7AA6  e855f1ffff              call     0x3b6c00                       ; -> sub_003B6C00
  0x003B7AAB  5f                      pop      edi                            
  0x003B7AAC  5e                      pop      esi                            
  0x003B7AAD  5b                      pop      ebx                            
  0x003B7AAE  83c408                  add      esp, 8                         
  0x003B7AB1  c3                      ret                                     
; end of function
  0x003B7AB2  cc                      int3                                    
  0x003B7AB3  cc                      int3                                    
  0x003B7AB4  cc                      int3                                    
  0x003B7AB5  cc                      int3                                    
  0x003B7AB6  cc                      int3                                    
  0x003B7AB7  cc                      int3                                    
  0x003B7AB8  cc                      int3                                    
  0x003B7AB9  cc                      int3                                    
  0x003B7ABA  cc                      int3                                    
  0x003B7ABB  cc                      int3                                    
  0x003B7ABC  cc                      int3                                    
  0x003B7ABD  cc                      int3                                    
  0x003B7ABE  cc                      int3                                    
  0x003B7ABF  cc                      int3                                    

; ============================================================
; Function: sub_003B7AC0
; Start: 0x003B7AC0  End: 0x003B7C6A  Size: 426 bytes
; Detection: call_target (confidence: 0.90)
; Calls: sub_003B7960
; Called by: sub_003B7D30
; ============================================================
sub_003B7AC0:
  0x003B7AC0  83ec14                  sub      esp, 0x14                      
  0x003B7AC3  8b4c2418                mov      ecx, dword ptr [esp + 0x18]    
  0x003B7AC7  53                      push     ebx                            
  0x003B7AC8  55                      push     ebp                            
  0x003B7AC9  8bd8                    mov      ebx, eax                       
  0x003B7ACB  8b44242c                mov      eax, dword ptr [esp + 0x2c]    
  0x003B7ACF  0fbf500c                movsx    edx, word ptr [eax + 0xc]      
  0x003B7AD3  56                      push     esi                            
  0x003B7AD4  8bb19c010000            mov      esi, dword ptr [ecx + 0x19c]   
  0x003B7ADA  57                      push     edi                            
  0x003B7ADB  0fbf780e                movsx    edi, word ptr [eax + 0xe]      
  0x003B7ADF  89542410                mov      dword ptr [esp + 0x10], edx    
  0x003B7AE3  8b542430                mov      edx, dword ptr [esp + 0x30]    
  0x003B7AE7  8974241c                mov      dword ptr [esp + 0x1c], esi    
  0x003B7AEB  897c2414                mov      dword ptr [esp + 0x14], edi    
  0x003B7AEF  e86cfeffff              call     0x3b7960                       ; -> sub_003B7960
  0x003B7AF4  8b4318                  mov      eax, dword ptr [ebx + 0x18]    
  0x003B7AF7  8b5b1c                  mov      ebx, dword ptr [ebx + 0x1c]    
  0x003B7AFA  8beb                    mov      ebp, ebx                       
  0x003B7AFC  8bc8                    mov      ecx, eax                       
  0x003B7AFE  d1fd                    sar      ebp, 1                         
  0x003B7B00  0fafef                  imul     ebp, edi                       
  0x003B7B03  8b7a04                  mov      edi, dword ptr [edx + 4]       
  0x003B7B06  d1f9                    sar      ecx, 1                         
  0x003B7B08  03e9                    add      ebp, ecx                       
  0x003B7B0A  8bd3                    mov      edx, ebx                       
  0x003B7B0C  83e201                  and      edx, 1                         
  0x003B7B0F  8d0c36                  lea      ecx, [esi + esi]               
  0x003B7B12  03d1                    add      edx, ecx                       
  0x003B7B14  03ef                    add      ebp, edi                       
  0x003B7B16  8bf8                    mov      edi, eax                       
  0x003B7B18  83e701                  and      edi, 1                         
  0x003B7B1B  8d0c57                  lea      ecx, [edi + edx*2]             
  0x003B7B1E  8b148d5858f400          mov      edx, dword ptr [ecx*4 + 0xf45858] 
  0x003B7B25  89542420                mov      dword ptr [esp + 0x20], edx    
  0x003B7B29  99                      cdq                                     
  0x003B7B2A  2bc2                    sub      eax, edx                       
  0x003B7B2C  8bc8                    mov      ecx, eax                       
  0x003B7B2E  8bc3                    mov      eax, ebx                       
  0x003B7B30  99                      cdq                                     
  0x003B7B31  2bc2                    sub      eax, edx                       
  0x003B7B33  d1f8                    sar      eax, 1                         
  0x003B7B35  8bd8                    mov      ebx, eax                       
  0x003B7B37  d1fb                    sar      ebx, 1                         
  0x003B7B39  0faf5c2410              imul     ebx, dword ptr [esp + 0x10]    
  0x003B7B3E  d1f9                    sar      ecx, 1                         
  0x003B7B40  8bd1                    mov      edx, ecx                       
  0x003B7B42  d1fa                    sar      edx, 1                         
  0x003B7B44  03da                    add      ebx, edx                       
  0x003B7B46  8b542430                mov      edx, dword ptr [esp + 0x30]    
  0x003B7B4A  031a                    add      ebx, dword ptr [edx]           
  0x003B7B4C  83e001                  and      eax, 1                         
  0x003B7B4F  8d1436                  lea      edx, [esi + esi]               
  0x003B7B52  03c2                    add      eax, edx                       
  0x003B7B54  83e101                  and      ecx, 1                         
  0x003B7B57  8d0441                  lea      eax, [ecx + eax*2]             
  0x003B7B5A  8b14855858f400          mov      edx, dword ptr [eax*4 + 0xf45858] 
  0x003B7B61  8b44242c                mov      eax, dword ptr [esp + 0x2c]    
  0x003B7B65  23ce                    and      ecx, esi                       
  0x003B7B67  8b742428                mov      esi, dword ptr [esp + 0x28]    
  0x003B7B6B  81c6cc000000            add      esi, 0xcc                      
  0x003B7B71  894618                  mov      dword ptr [esi + 0x18], eax    
  0x003B7B74  8b442434                mov      eax, dword ptr [esp + 0x34]    
  0x003B7B78  89542430                mov      dword ptr [esp + 0x30], edx    
  0x003B7B7C  8b542410                mov      edx, dword ptr [esp + 0x10]    
  0x003B7B80  895620                  mov      dword ptr [esi + 0x20], edx    
  0x003B7B83  8b00                    mov      eax, dword ptr [eax]           
  0x003B7B85  03c3                    add      eax, ebx                       
  0x003B7B87  894624                  mov      dword ptr [esi + 0x24], eax    
  0x003B7B8A  03c1                    add      eax, ecx                       
  0x003B7B8C  03c2                    add      eax, edx                       
  0x003B7B8E  56                      push     esi                            
  0x003B7B8F  894c241c                mov      dword ptr [esp + 0x1c], ecx    
  0x003B7B93  894628                  mov      dword ptr [esi + 0x28], eax    
  0x003B7B96  ff542434                call     dword ptr [esp + 0x34]         
  0x003B7B9A  8b4c2430                mov      ecx, dword ptr [esp + 0x30]    
  0x003B7B9E  8b542438                mov      edx, dword ptr [esp + 0x38]    
  0x003B7BA2  83c140                  add      ecx, 0x40                      
  0x003B7BA5  894e18                  mov      dword ptr [esi + 0x18], ecx    
  0x003B7BA8  8b4204                  mov      eax, dword ptr [edx + 4]       
  0x003B7BAB  03c3                    add      eax, ebx                       
  0x003B7BAD  894624                  mov      dword ptr [esi + 0x24], eax    
  0x003B7BB0  8b4c241c                mov      ecx, dword ptr [esp + 0x1c]    
  0x003B7BB4  03c1                    add      eax, ecx                       
  0x003B7BB6  03442414                add      eax, dword ptr [esp + 0x14]    
  0x003B7BBA  56                      push     esi                            
  0x003B7BBB  894628                  mov      dword ptr [esi + 0x28], eax    
  0x003B7BBE  ff542438                call     dword ptr [esp + 0x38]         
  0x003B7BC2  8b4c241c                mov      ecx, dword ptr [esp + 0x1c]    
  0x003B7BC6  8b5c2434                mov      ebx, dword ptr [esp + 0x34]    
  0x003B7BCA  8b44243c                mov      eax, dword ptr [esp + 0x3c]    
  0x003B7BCE  8d9380000000            lea      edx, [ebx + 0x80]              
  0x003B7BD4  894e20                  mov      dword ptr [esi + 0x20], ecx    
  0x003B7BD7  895618                  mov      dword ptr [esi + 0x18], edx    
  0x003B7BDA  8b4008                  mov      eax, dword ptr [eax + 8]       
  0x003B7BDD  03c5                    add      eax, ebp                       
  0x003B7BDF  237c2424                and      edi, dword ptr [esp + 0x24]    
  0x003B7BE3  03f8                    add      edi, eax                       
  0x003B7BE5  03f9                    add      edi, ecx                       
  0x003B7BE7  897e28                  mov      dword ptr [esi + 0x28], edi    
  0x003B7BEA  8b7c2428                mov      edi, dword ptr [esp + 0x28]    
  0x003B7BEE  56                      push     esi                            
  0x003B7BEF  894624                  mov      dword ptr [esi + 0x24], eax    
  0x003B7BF2  ffd7                    call     edi                            
  0x003B7BF4  8b4624                  mov      eax, dword ptr [esi + 0x24]    
  0x003B7BF7  8b5628                  mov      edx, dword ptr [esi + 0x28]    
  0x003B7BFA  bd08000000              mov      ebp, 8                         
  0x003B7BFF  8d8bc0000000            lea      ecx, [ebx + 0xc0]              
  0x003B7C05  03c5                    add      eax, ebp                       
  0x003B7C07  03d5                    add      edx, ebp                       
  0x003B7C09  56                      push     esi                            
  0x003B7C0A  894e18                  mov      dword ptr [esi + 0x18], ecx    
  0x003B7C0D  894624                  mov      dword ptr [esi + 0x24], eax    
  0x003B7C10  895628                  mov      dword ptr [esi + 0x28], edx    
  0x003B7C13  ffd7                    call     edi                            
  0x003B7C15  8b442424                mov      eax, dword ptr [esp + 0x24]    
  0x003B7C19  8d9300010000            lea      edx, [ebx + 0x100]             
  0x003B7C1F  895618                  mov      dword ptr [esi + 0x18], edx    
  0x003B7C22  8b5624                  mov      edx, dword ptr [esi + 0x24]    
  0x003B7C25  8d0cc5f8ffffff          lea      ecx, [eax*8 - 8]               
  0x003B7C2C  03d1                    add      edx, ecx                       
  0x003B7C2E  895624                  mov      dword ptr [esi + 0x24], edx    
  0x003B7C31  8d14c5f8ffffff          lea      edx, [eax*8 - 8]               
  0x003B7C38  8b4628                  mov      eax, dword ptr [esi + 0x28]    
  0x003B7C3B  03c2                    add      eax, edx                       
  0x003B7C3D  56                      push     esi                            
  0x003B7C3E  894628                  mov      dword ptr [esi + 0x28], eax    
  0x003B7C41  ffd7                    call     edi                            
  0x003B7C43  8b5628                  mov      edx, dword ptr [esi + 0x28]    
  0x003B7C46  81c340010000            add      ebx, 0x140                     
  0x003B7C4C  895e18                  mov      dword ptr [esi + 0x18], ebx    
  0x003B7C4F  8b5e24                  mov      ebx, dword ptr [esi + 0x24]    
  0x003B7C52  03d5                    add      edx, ebp                       
  0x003B7C54  03dd                    add      ebx, ebp                       
  0x003B7C56  56                      push     esi                            
  0x003B7C57  895e24                  mov      dword ptr [esi + 0x24], ebx    
  0x003B7C5A  895628                  mov      dword ptr [esi + 0x28], edx    
  0x003B7C5D  ffd7                    call     edi                            
  0x003B7C5F  83c418                  add      esp, 0x18                      
  0x003B7C62  5f                      pop      edi                            
  0x003B7C63  5e                      pop      esi                            
  0x003B7C64  5d                      pop      ebp                            
  0x003B7C65  5b                      pop      ebx                            
  0x003B7C66  83c414                  add      esp, 0x14                      
  0x003B7C69  c3                      ret                                     
; end of function
  0x003B7C6A  cc                      int3                                    
  0x003B7C6B  cc                      int3                                    
  0x003B7C6C  cc                      int3                                    
  0x003B7C6D  cc                      int3                                    
  0x003B7C6E  cc                      int3                                    
  0x003B7C6F  cc                      int3                                    

; ============================================================
; Function: sub_003B7C70
; Start: 0x003B7C70  End: 0x003B7CD2  Size: 98 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_003B7550, sub_003B7960, sub_003B79A0, sub_003B7A00
; ============================================================
sub_003B7C70:
  0x003B7C70  55                      push     ebp                            
  0x003B7C71  8bec                    mov      ebp, esp                       
  0x003B7C73  83e4f8                  and      esp, 0xfffffff8                
  0x003B7C76  83ec0c                  sub      esp, 0xc                       
  0x003B7C79  8b4d0c                  mov      ecx, dword ptr [ebp + 0xc]     
  0x003B7C7C  53                      push     ebx                            
  0x003B7C7D  56                      push     esi                            
  0x003B7C7E  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x003B7C81  57                      push     edi                            
  0x003B7C82  8bbe34030000            mov      edi, dword ptr [esi + 0x334]   
  0x003B7C88  8bc6                    mov      eax, esi                       
  0x003B7C8A  8d9e64020000            lea      ebx, [esi + 0x264]             
  0x003B7C90  e80bfdffff              call     0x3b79a0                       ; -> sub_003B79A0
  0x003B7C95  39be34030000            cmp      dword ptr [esi + 0x334], edi   
  0x003B7C9B  7d2e                    jge      0x3b7ccb                       
  0x003B7C9D  8d4900                  lea      ecx, [ecx]                     
                                        ; XREF: 0x003B7CC9 (cond_jump)
  0x003B7CA0  8d542410                lea      edx, [esp + 0x10]              
  0x003B7CA4  8bc3                    mov      eax, ebx                       
  0x003B7CA6  8bce                    mov      ecx, esi                       
  0x003B7CA8  e8b3fcffff              call     0x3b7960                       ; -> sub_003B7960
  0x003B7CAD  8d4310                  lea      eax, [ebx + 0x10]              
  0x003B7CB0  50                      push     eax                            
  0x003B7CB1  8bc2                    mov      eax, edx                       
  0x003B7CB3  50                      push     eax                            
  0x003B7CB4  e897f8ffff              call     0x3b7550                       ; -> sub_003B7550
  0x003B7CB9  83c408                  add      esp, 8                         
  0x003B7CBC  8bc6                    mov      eax, esi                       
  0x003B7CBE  e83dfdffff              call     0x3b7a00                       ; -> sub_003B7A00
  0x003B7CC3  39be34030000            cmp      dword ptr [esi + 0x334], edi   
  0x003B7CC9  7cd5                    jl       0x3b7ca0                       
                                        ; XREF: 0x003B7C9B (cond_jump)
  0x003B7CCB  5f                      pop      edi                            
  0x003B7CCC  5e                      pop      esi                            
  0x003B7CCD  5b                      pop      ebx                            
  0x003B7CCE  8be5                    mov      esp, ebp                       
  0x003B7CD0  5d                      pop      ebp                            
  0x003B7CD1  c3                      ret                                     
; end of function
  0x003B7CD2  cc                      int3                                    
  0x003B7CD3  cc                      int3                                    
  0x003B7CD4  cc                      int3                                    
  0x003B7CD5  cc                      int3                                    
  0x003B7CD6  cc                      int3                                    
  0x003B7CD7  cc                      int3                                    
  0x003B7CD8  cc                      int3                                    
  0x003B7CD9  cc                      int3                                    
  0x003B7CDA  cc                      int3                                    
  0x003B7CDB  cc                      int3                                    
  0x003B7CDC  cc                      int3                                    
  0x003B7CDD  cc                      int3                                    
  0x003B7CDE  cc                      int3                                    
  0x003B7CDF  cc                      int3                                    

; ============================================================
; Function: sub_003B7CE0
; Start: 0x003B7CE0  End: 0x003B7D29  Size: 73 bytes
; Detection: cc_boundary (confidence: 0.85)
; Calls: sub_003B79A0, sub_003B7A00
; ============================================================
sub_003B7CE0:
  0x003B7CE0  8b4c2408                mov      ecx, dword ptr [esp + 8]       
  0x003B7CE4  53                      push     ebx                            
  0x003B7CE5  56                      push     esi                            
  0x003B7CE6  8b74240c                mov      esi, dword ptr [esp + 0xc]     
  0x003B7CEA  8b9ed4020000            mov      ebx, dword ptr [esi + 0x2d4]   
  0x003B7CF0  57                      push     edi                            
  0x003B7CF1  8bbe34030000            mov      edi, dword ptr [esi + 0x334]   
  0x003B7CF7  8bc6                    mov      eax, esi                       
  0x003B7CF9  c7864803000000000000    mov      dword ptr [esi + 0x348], 0     
  0x003B7D03  e898fcffff              call     0x3b79a0                       ; -> sub_003B79A0
  0x003B7D08  39be34030000            cmp      dword ptr [esi + 0x334], edi   
  0x003B7D0E  7d15                    jge      0x3b7d25                       
                                        ; XREF: 0x003B7D23 (cond_jump)
  0x003B7D10  56                      push     esi                            
  0x003B7D11  ffd3                    call     ebx                            
  0x003B7D13  83c404                  add      esp, 4                         
  0x003B7D16  8bc6                    mov      eax, esi                       
  0x003B7D18  e8e3fcffff              call     0x3b7a00                       ; -> sub_003B7A00
  0x003B7D1D  39be34030000            cmp      dword ptr [esi + 0x334], edi   
  0x003B7D23  7ceb                    jl       0x3b7d10                       
                                        ; XREF: 0x003B7D0E (cond_jump)
  0x003B7D25  5f                      pop      edi                            
  0x003B7D26  5e                      pop      esi                            
  0x003B7D27  5b                      pop      ebx                            
  0x003B7D28  c3                      ret                                     
; end of function
  0x003B7D29  cc                      int3                                    
  0x003B7D2A  cc                      int3                                    
  0x003B7D2B  cc                      int3                                    
  0x003B7D2C  cc                      int3                                    
  0x003B7D2D  cc                      int3                                    
  0x003B7D2E  cc                      int3                                    
  0x003B7D2F  cc                      int3                                    

; ============================================================
; Function: sub_003B7D30
; Start: 0x003B7D30  End: 0x003B7DC0  Size: 144 bytes
; Detection: cc_boundary (confidence: 0.85)
; Calls: sub_003B6EB0, sub_003B7AC0
; ============================================================
sub_003B7D30:
  0x003B7D30  83ec08                  sub      esp, 8                         
  0x003B7D33  56                      push     esi                            
  0x003B7D34  8b742410                mov      esi, dword ptr [esp + 0x10]    
  0x003B7D38  57                      push     edi                            
  0x003B7D39  8d8e64020000            lea      ecx, [esi + 0x264]             
  0x003B7D3F  51                      push     ecx                            
  0x003B7D40  8b8e18010000            mov      ecx, dword ptr [esi + 0x118]   
  0x003B7D46  8d54240c                lea      edx, [esp + 0xc]               
  0x003B7D4A  8dbe10010000            lea      edi, [esi + 0x110]             
  0x003B7D50  52                      push     edx                            
  0x003B7D51  51                      push     ecx                            
  0x003B7D52  8d86ec020000            lea      eax, [esi + 0x2ec]             
  0x003B7D58  56                      push     esi                            
  0x003B7D59  e862fdffff              call     0x3b7ac0                       ; -> sub_003B7AC0
  0x003B7D5E  8b8e94020000            mov      ecx, dword ptr [esi + 0x294]   
  0x003B7D64  8b442418                mov      eax, dword ptr [esp + 0x18]    
  0x003B7D68  03c8                    add      ecx, eax                       
  0x003B7D6A  8d9620010000            lea      edx, [esi + 0x120]             
  0x003B7D70  894a04                  mov      dword ptr [edx + 4], ecx       
  0x003B7D73  8b8e98020000            mov      ecx, dword ptr [esi + 0x298]   
  0x003B7D79  03c8                    add      ecx, eax                       
  0x003B7D7B  894a0c                  mov      dword ptr [edx + 0xc], ecx     
  0x003B7D7E  8b869c020000            mov      eax, dword ptr [esi + 0x29c]   
  0x003B7D84  8b4c241c                mov      ecx, dword ptr [esp + 0x1c]    
  0x003B7D88  03c1                    add      eax, ecx                       
  0x003B7D8A  894214                  mov      dword ptr [edx + 0x14], eax    
  0x003B7D8D  8b4a14                  mov      ecx, dword ptr [edx + 0x14]    
  0x003B7D90  83c008                  add      eax, 8                         
  0x003B7D93  89421c                  mov      dword ptr [edx + 0x1c], eax    
  0x003B7D96  0fbf86a2020000          movsx    eax, word ptr [esi + 0x2a2]    
  0x003B7D9D  8d04c1                  lea      eax, [ecx + eax*8]             
  0x003B7DA0  894224                  mov      dword ptr [edx + 0x24], eax    
  0x003B7DA3  83c008                  add      eax, 8                         
  0x003B7DA6  89422c                  mov      dword ptr [edx + 0x2c], eax    
  0x003B7DA9  8b8648030000            mov      eax, dword ptr [esi + 0x348]   
  0x003B7DAF  50                      push     eax                            
  0x003B7DB0  8bc7                    mov      eax, edi                       
  0x003B7DB2  e8f9f0ffff              call     0x3b6eb0                       ; -> sub_003B6EB0
  0x003B7DB7  83c414                  add      esp, 0x14                      
  0x003B7DBA  5f                      pop      edi                            
  0x003B7DBB  5e                      pop      esi                            
  0x003B7DBC  83c408                  add      esp, 8                         
  0x003B7DBF  c3                      ret                                     
; end of function
  0x003B7DC0  83ec08                  sub      esp, 8                         
  0x003B7DC3  56                      push     esi                            
  0x003B7DC4  8b742410                mov      esi, dword ptr [esp + 0x10]    
  0x003B7DC8  57                      push     edi                            
  0x003B7DC9  8d8e74020000            lea      ecx, [esi + 0x274]             
  0x003B7DCF  51                      push     ecx                            
  0x003B7DD0  8b8e18010000            mov      ecx, dword ptr [esi + 0x118]   
  0x003B7DD6  8d54240c                lea      edx, [esp + 0xc]               
  0x003B7DDA  8dbe10010000            lea      edi, [esi + 0x110]             
  0x003B7DE0  52                      push     edx                            
  0x003B7DE1  51                      push     ecx                            
  0x003B7DE2  8d8610030000            lea      eax, [esi + 0x310]             
  0x003B7DE8  56                      push     esi                            
  0x003B7DE9  e8d2fcffff              call     0x3b7ac0                       ; -> sub_003B7AC0
  0x003B7DEE  8b8e94020000            mov      ecx, dword ptr [esi + 0x294]   
  0x003B7DF4  8b442418                mov      eax, dword ptr [esp + 0x18]    
  0x003B7DF8  03c8                    add      ecx, eax                       
  0x003B7DFA  8d9620010000            lea      edx, [esi + 0x120]             
  0x003B7E00  894a04                  mov      dword ptr [edx + 4], ecx       
  0x003B7E03  8b8e98020000            mov      ecx, dword ptr [esi + 0x298]   
  0x003B7E09  03c8                    add      ecx, eax                       
  0x003B7E0B  894a0c                  mov      dword ptr [edx + 0xc], ecx     
  0x003B7E0E  8b869c020000            mov      eax, dword ptr [esi + 0x29c]   
  0x003B7E14  8b4c241c                mov      ecx, dword ptr [esp + 0x1c]    
  0x003B7E18  03c1                    add      eax, ecx                       
  0x003B7E1A  894214                  mov      dword ptr [edx + 0x14], eax    
  0x003B7E1D  8b4a14                  mov      ecx, dword ptr [edx + 0x14]    
  0x003B7E20  83c008                  add      eax, 8                         
  0x003B7E23  89421c                  mov      dword ptr [edx + 0x1c], eax    
  0x003B7E26  0fbf86a2020000          movsx    eax, word ptr [esi + 0x2a2]    
  0x003B7E2D  8d04c1                  lea      eax, [ecx + eax*8]             
  0x003B7E30  894224                  mov      dword ptr [edx + 0x24], eax    
  0x003B7E33  83c008                  add      eax, 8                         
  0x003B7E36  89422c                  mov      dword ptr [edx + 0x2c], eax    
  0x003B7E39  8b8648030000            mov      eax, dword ptr [esi + 0x348]   
  0x003B7E3F  50                      push     eax                            
  0x003B7E40  8bc7                    mov      eax, edi                       
  0x003B7E42  e869f0ffff              call     0x3b6eb0                       ; -> sub_003B6EB0
  0x003B7E47  83c414                  add      esp, 0x14                      
  0x003B7E4A  5f                      pop      edi                            
  0x003B7E4B  5e                      pop      esi                            
  0x003B7E4C  83c408                  add      esp, 8                         
  0x003B7E4F  c3                      ret                                     
  0x003B7E50  83ec08                  sub      esp, 8                         
  0x003B7E53  53                      push     ebx                            
  0x003B7E54  56                      push     esi                            
  0x003B7E55  8b742414                mov      esi, dword ptr [esp + 0x14]    
  0x003B7E59  8b9618010000            mov      edx, dword ptr [esi + 0x118]   
  0x003B7E5F  57                      push     edi                            
  0x003B7E60  8d9e64020000            lea      ebx, [esi + 0x264]             
  0x003B7E66  53                      push     ebx                            
  0x003B7E67  8d4c2410                lea      ecx, [esp + 0x10]              
  0x003B7E6B  8dbe10010000            lea      edi, [esi + 0x110]             
  0x003B7E71  51                      push     ecx                            
  0x003B7E72  52                      push     edx                            
  0x003B7E73  8d86ec020000            lea      eax, [esi + 0x2ec]             
  0x003B7E79  56                      push     esi                            
  0x003B7E7A  e841fcffff              call     0x3b7ac0                       ; -> sub_003B7AC0
  0x003B7E7F  8b570c                  mov      edx, dword ptr [edi + 0xc]     
  0x003B7E82  83c310                  add      ebx, 0x10                      
  0x003B7E85  53                      push     ebx                            
  0x003B7E86  8d4c2420                lea      ecx, [esp + 0x20]              
  0x003B7E8A  51                      push     ecx                            
  0x003B7E8B  52                      push     edx                            
  0x003B7E8C  8d8610030000            lea      eax, [esi + 0x310]             
  0x003B7E92  56                      push     esi                            
  0x003B7E93  e828fcffff              call     0x3b7ac0                       ; -> sub_003B7AC0
  0x003B7E98  8b8e94020000            mov      ecx, dword ptr [esi + 0x294]   
  0x003B7E9E  8b44242c                mov      eax, dword ptr [esp + 0x2c]    
  0x003B7EA2  03c8                    add      ecx, eax                       
  0x003B7EA4  8d9620010000            lea      edx, [esi + 0x120]             
  0x003B7EAA  894a04                  mov      dword ptr [edx + 4], ecx       
  0x003B7EAD  8b8e98020000            mov      ecx, dword ptr [esi + 0x298]   
  0x003B7EB3  03c8                    add      ecx, eax                       
  0x003B7EB5  894a0c                  mov      dword ptr [edx + 0xc], ecx     
  0x003B7EB8  8b869c020000            mov      eax, dword ptr [esi + 0x29c]   
  0x003B7EBE  8b4c2430                mov      ecx, dword ptr [esp + 0x30]    
  0x003B7EC2  03c1                    add      eax, ecx                       
  0x003B7EC4  894214                  mov      dword ptr [edx + 0x14], eax    
  0x003B7EC7  8b4a14                  mov      ecx, dword ptr [edx + 0x14]    
  0x003B7ECA  83c008                  add      eax, 8                         
  0x003B7ECD  89421c                  mov      dword ptr [edx + 0x1c], eax    
  0x003B7ED0  0fbf86a2020000          movsx    eax, word ptr [esi + 0x2a2]    
  0x003B7ED7  8d04c1                  lea      eax, [ecx + eax*8]             
  0x003B7EDA  894224                  mov      dword ptr [edx + 0x24], eax    
  0x003B7EDD  83c008                  add      eax, 8                         
  0x003B7EE0  89422c                  mov      dword ptr [edx + 0x2c], eax    
  0x003B7EE3  8b8648030000            mov      eax, dword ptr [esi + 0x348]   
  0x003B7EE9  50                      push     eax                            
  0x003B7EEA  8bc7                    mov      eax, edi                       
  0x003B7EEC  e89ff2ffff              call     0x3b7190                       ; -> sub_003B7190
  0x003B7EF1  83c424                  add      esp, 0x24                      
  0x003B7EF4  5f                      pop      edi                            
  0x003B7EF5  5e                      pop      esi                            
  0x003B7EF6  5b                      pop      ebx                            
  0x003B7EF7  83c408                  add      esp, 8                         
  0x003B7EFA  c3                      ret                                     
  0x003B7EFB  cc                      int3                                    
  0x003B7EFC  cc                      int3                                    
  0x003B7EFD  cc                      int3                                    
  0x003B7EFE  cc                      int3                                    
  0x003B7EFF  cc                      int3                                    

; ============================================================
; Function: sub_003B7F00
; Start: 0x003B7F00  End: 0x003B7FE4  Size: 228 bytes
; Detection: cc_boundary (confidence: 0.85)
; Calls: sub_00328D20
; ============================================================
sub_003B7F00:
  0x003B7F00  53                      push     ebx                            
  0x003B7F01  56                      push     esi                            
  0x003B7F02  8b74240c                mov      esi, dword ptr [esp + 0xc]     
  0x003B7F06  57                      push     edi                            
  0x003B7F07  8d9680060000            lea      edx, [esi + 0x680]             
  0x003B7F0D  33c0                    xor      eax, eax                       
  0x003B7F0F  8bfa                    mov      edi, edx                       
  0x003B7F11  b980010000              mov      ecx, 0x180                     
  0x003B7F16  f3ab                    rep stosd dword ptr es:[edi], eax        
  0x003B7F18  8b86e8020000            mov      eax, dword ptr [esi + 0x2e8]   
  0x003B7F1E  8d7e44                  lea      edi, [esi + 0x44]              
  0x003B7F21  8d8e800c0000            lea      ecx, [esi + 0xc80]             
  0x003B7F27  894f20                  mov      dword ptr [edi + 0x20], ecx    
  0x003B7F2A  894724                  mov      dword ptr [edi + 0x24], eax    
  0x003B7F2D  c7473000000000          mov      dword ptr [edi + 0x30], 0      
  0x003B7F34  8b8628130000            mov      eax, dword ptr [esi + 0x1328]  
  0x003B7F3A  8d8e4c030000            lea      ecx, [esi + 0x34c]             
  0x003B7F40  57                      push     edi                            
  0x003B7F41  56                      push     esi                            
  0x003B7F42  8d5e78                  lea      ebx, [esi + 0x78]              
  0x003B7F45  89472c                  mov      dword ptr [edi + 0x2c], eax    
  0x003B7F48  894f28                  mov      dword ptr [edi + 0x28], ecx    
  0x003B7F4B  89571c                  mov      dword ptr [edi + 0x1c], edx    
  0x003B7F4E  ff9618130000            call     dword ptr [esi + 0x1318]       
  0x003B7F54  8d9680070000            lea      edx, [esi + 0x780]             
  0x003B7F5A  57                      push     edi                            
  0x003B7F5B  8803                    mov      byte ptr [ebx], al             
  0x003B7F5D  56                      push     esi                            
  0x003B7F5E  89571c                  mov      dword ptr [edi + 0x1c], edx    
  0x003B7F61  ff9618130000            call     dword ptr [esi + 0x1318]       
  0x003B7F67  884301                  mov      byte ptr [ebx + 1], al         
  0x003B7F6A  8d8680080000            lea      eax, [esi + 0x880]             
  0x003B7F70  57                      push     edi                            
  0x003B7F71  56                      push     esi                            
  0x003B7F72  89471c                  mov      dword ptr [edi + 0x1c], eax    
  0x003B7F75  ff9618130000            call     dword ptr [esi + 0x1318]       
  0x003B7F7B  8d8e80090000            lea      ecx, [esi + 0x980]             
  0x003B7F81  57                      push     edi                            
  0x003B7F82  884302                  mov      byte ptr [ebx + 2], al         
  0x003B7F85  56                      push     esi                            
  0x003B7F86  894f1c                  mov      dword ptr [edi + 0x1c], ecx    
  0x003B7F89  ff9618130000            call     dword ptr [esi + 0x1318]       
  0x003B7F8F  884303                  mov      byte ptr [ebx + 3], al         
  0x003B7F92  8b962c130000            mov      edx, dword ptr [esi + 0x132c]  
  0x003B7F98  8d8650030000            lea      eax, [esi + 0x350]             
  0x003B7F9E  8d8e800a0000            lea      ecx, [esi + 0xa80]             
  0x003B7FA4  57                      push     edi                            
  0x003B7FA5  56                      push     esi                            
  0x003B7FA6  89572c                  mov      dword ptr [edi + 0x2c], edx    
  0x003B7FA9  894728                  mov      dword ptr [edi + 0x28], eax    
  0x003B7FAC  894f1c                  mov      dword ptr [edi + 0x1c], ecx    
  0x003B7FAF  ff9618130000            call     dword ptr [esi + 0x1318]       
  0x003B7FB5  884304                  mov      byte ptr [ebx + 4], al         
  0x003B7FB8  8d9654030000            lea      edx, [esi + 0x354]             
  0x003B7FBE  8d86800b0000            lea      eax, [esi + 0xb80]             
  0x003B7FC4  57                      push     edi                            
  0x003B7FC5  56                      push     esi                            
  0x003B7FC6  895728                  mov      dword ptr [edi + 0x28], edx    
  0x003B7FC9  89471c                  mov      dword ptr [edi + 0x1c], eax    
  0x003B7FCC  ff9618130000            call     dword ptr [esi + 0x1318]       
  0x003B7FD2  53                      push     ebx                            
  0x003B7FD3  884305                  mov      byte ptr [ebx + 5], al         
  0x003B7FD6  e8450df7ff              call     0x328d20                       ; -> sub_00328D20
  0x003B7FDB  83c434                  add      esp, 0x34                      
  0x003B7FDE  5f                      pop      edi                            
  0x003B7FDF  5e                      pop      esi                            
  0x003B7FE0  33c0                    xor      eax, eax                       
  0x003B7FE2  5b                      pop      ebx                            
  0x003B7FE3  c3                      ret                                     
; end of function
  0x003B7FE4  cc                      int3                                    
  0x003B7FE5  cc                      int3                                    
  0x003B7FE6  cc                      int3                                    
  0x003B7FE7  cc                      int3                                    
  0x003B7FE8  cc                      int3                                    
  0x003B7FE9  cc                      int3                                    
  0x003B7FEA  cc                      int3                                    
  0x003B7FEB  cc                      int3                                    
  0x003B7FEC  cc                      int3                                    
  0x003B7FED  cc                      int3                                    
  0x003B7FEE  cc                      int3                                    
  0x003B7FEF  cc                      int3                                    

; ============================================================
; Function: sub_003B7FF0
; Start: 0x003B7FF0  End: 0x003B807C  Size: 140 bytes
; Detection: cc_boundary (confidence: 0.85)
; Calls: sub_00328D30
; ============================================================
sub_003B7FF0:
  0x003B7FF0  51                      push     ecx                            
  0x003B7FF1  53                      push     ebx                            
  0x003B7FF2  55                      push     ebp                            
  0x003B7FF3  56                      push     esi                            
  0x003B7FF4  8b742414                mov      esi, dword ptr [esp + 0x14]    
  0x003B7FF8  8b8ee8020000            mov      ecx, dword ptr [esi + 0x2e8]   
  0x003B7FFE  57                      push     edi                            
  0x003B7FFF  8d7e44                  lea      edi, [esi + 0x44]              
  0x003B8002  8d96c00c0000            lea      edx, [esi + 0xcc0]             
  0x003B8008  894f24                  mov      dword ptr [edi + 0x24], ecx    
  0x003B800B  895720                  mov      dword ptr [edi + 0x20], edx    
  0x003B800E  c7473001000000          mov      dword ptr [edi + 0x30], 1      
  0x003B8015  8b9e48030000            mov      ebx, dword ptr [esi + 0x348]   
  0x003B801B  8d4678                  lea      eax, [esi + 0x78]              
  0x003B801E  c1e302                  shl      ebx, 2                         
  0x003B8021  89442410                mov      dword ptr [esp + 0x10], eax    
  0x003B8025  895828                  mov      dword ptr [eax + 0x28], ebx    
  0x003B8028  8d8680060000            lea      eax, [esi + 0x680]             
  0x003B802E  33ed                    xor      ebp, ebp                       
  0x003B8030  89442418                mov      dword ptr [esp + 0x18], eax    
                                        ; XREF: 0x003B8065 (cond_jump)
  0x003B8034  85db                    test     ebx, ebx                       
  0x003B8036  7d19                    jge      0x3b8051                       
  0x003B8038  8b4c2418                mov      ecx, dword ptr [esp + 0x18]    
  0x003B803C  57                      push     edi                            
  0x003B803D  56                      push     esi                            
  0x003B803E  894f1c                  mov      dword ptr [edi + 0x1c], ecx    
  0x003B8041  ff961c130000            call     dword ptr [esi + 0x131c]       
  0x003B8047  8b542418                mov      edx, dword ptr [esp + 0x18]    
  0x003B804B  83c408                  add      esp, 8                         
  0x003B804E  88042a                  mov      byte ptr [edx + ebp], al       
                                        ; XREF: 0x003B8036 (cond_jump)
  0x003B8051  8b4c2418                mov      ecx, dword ptr [esp + 0x18]    
  0x003B8055  d1e3                    shl      ebx, 1                         
  0x003B8057  45                      inc      ebp                            
  0x003B8058  81c100010000            add      ecx, 0x100                     
  0x003B805E  83fd06                  cmp      ebp, 6                         
  0x003B8061  894c2418                mov      dword ptr [esp + 0x18], ecx    
  0x003B8065  7ccd                    jl       0x3b8034                       
  0x003B8067  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003B806B  50                      push     eax                            
  0x003B806C  e8bf0cf7ff              call     0x328d30                       ; -> sub_00328D30
  0x003B8071  83c404                  add      esp, 4                         
  0x003B8074  5f                      pop      edi                            
  0x003B8075  5e                      pop      esi                            
  0x003B8076  5d                      pop      ebp                            
  0x003B8077  33c0                    xor      eax, eax                       
  0x003B8079  5b                      pop      ebx                            
  0x003B807A  59                      pop      ecx                            
  0x003B807B  c3                      ret                                     
; end of function
  0x003B807C  cc                      int3                                    
  0x003B807D  cc                      int3                                    
  0x003B807E  cc                      int3                                    
  0x003B807F  cc                      int3                                    

; ============================================================
; Function: sub_003B8080
; Start: 0x003B8080  End: 0x003B81A0  Size: 288 bytes
; Detection: cc_boundary (confidence: 0.85)
; ============================================================
sub_003B8080:
  0x003B8080  8b542404                mov      edx, dword ptr [esp + 4]       
  0x003B8084  8b4224                  mov      eax, dword ptr [edx + 0x24]    
  0x003B8087  8b4a28                  mov      ecx, dword ptr [edx + 0x28]    
  0x003B808A  53                      push     ebx                            
  0x003B808B  55                      push     ebp                            
  0x003B808C  56                      push     esi                            
  0x003B808D  8b7218                  mov      esi, dword ptr [edx + 0x18]    
  0x003B8090  57                      push     edi                            
  0x003B8091  8b7a20                  mov      edi, dword ptr [edx + 0x20]    
  0x003B8094  bd08000000              mov      ebp, 8                         
  0x003B8099  8da42400000000          lea      esp, [esp]                     
                                        ; XREF: 0x003B8195 (cond_jump)
  0x003B80A0  0fb618                  movzx    ebx, byte ptr [eax]            
  0x003B80A3  0fb611                  movzx    edx, byte ptr [ecx]            
  0x003B80A6  03d3                    add      edx, ebx                       
  0x003B80A8  0fb65801                movzx    ebx, byte ptr [eax + 1]        
  0x003B80AC  03d3                    add      edx, ebx                       
  0x003B80AE  0fb65901                movzx    ebx, byte ptr [ecx + 1]        
  0x003B80B2  8d541a02                lea      edx, [edx + ebx + 2]           
  0x003B80B6  c1fa02                  sar      edx, 2                         
  0x003B80B9  8816                    mov      byte ptr [esi], dl             
  0x003B80BB  0fb65801                movzx    ebx, byte ptr [eax + 1]        
  0x003B80BF  0fb65002                movzx    edx, byte ptr [eax + 2]        
  0x003B80C3  03d3                    add      edx, ebx                       
  0x003B80C5  0fb65901                movzx    ebx, byte ptr [ecx + 1]        
  0x003B80C9  03d3                    add      edx, ebx                       
  0x003B80CB  0fb65902                movzx    ebx, byte ptr [ecx + 2]        
  0x003B80CF  8d541a02                lea      edx, [edx + ebx + 2]           
  0x003B80D3  c1fa02                  sar      edx, 2                         
  0x003B80D6  885601                  mov      byte ptr [esi + 1], dl         
  0x003B80D9  0fb65803                movzx    ebx, byte ptr [eax + 3]        
  0x003B80DD  0fb65002                movzx    edx, byte ptr [eax + 2]        
  0x003B80E1  03d3                    add      edx, ebx                       
  0x003B80E3  0fb65902                movzx    ebx, byte ptr [ecx + 2]        
  0x003B80E7  03d3                    add      edx, ebx                       
  0x003B80E9  0fb65903                movzx    ebx, byte ptr [ecx + 3]        
  0x003B80ED  8d541a02                lea      edx, [edx + ebx + 2]           
  0x003B80F1  c1fa02                  sar      edx, 2                         
  0x003B80F4  885602                  mov      byte ptr [esi + 2], dl         
  0x003B80F7  0fb65803                movzx    ebx, byte ptr [eax + 3]        
  0x003B80FB  0fb65104                movzx    edx, byte ptr [ecx + 4]        
  0x003B80FF  03d3                    add      edx, ebx                       
  0x003B8101  0fb65804                movzx    ebx, byte ptr [eax + 4]        
  0x003B8105  03d3                    add      edx, ebx                       
  0x003B8107  0fb65903                movzx    ebx, byte ptr [ecx + 3]        
  0x003B810B  8d541a02                lea      edx, [edx + ebx + 2]           
  0x003B810F  c1fa02                  sar      edx, 2                         
  0x003B8112  885603                  mov      byte ptr [esi + 3], dl         
  0x003B8115  0fb65904                movzx    ebx, byte ptr [ecx + 4]        
  0x003B8119  0fb65005                movzx    edx, byte ptr [eax + 5]        
  0x003B811D  03d3                    add      edx, ebx                       
  0x003B811F  0fb65905                movzx    ebx, byte ptr [ecx + 5]        
  0x003B8123  03d3                    add      edx, ebx                       
  0x003B8125  0fb65804                movzx    ebx, byte ptr [eax + 4]        
  0x003B8129  8d541a02                lea      edx, [edx + ebx + 2]           
  0x003B812D  c1fa02                  sar      edx, 2                         
  0x003B8130  885604                  mov      byte ptr [esi + 4], dl         
  0x003B8133  0fb65806                movzx    ebx, byte ptr [eax + 6]        
  0x003B8137  0fb65005                movzx    edx, byte ptr [eax + 5]        
  0x003B813B  03d3                    add      edx, ebx                       
  0x003B813D  0fb65905                movzx    ebx, byte ptr [ecx + 5]        
  0x003B8141  03d3                    add      edx, ebx                       
  0x003B8143  0fb65906                movzx    ebx, byte ptr [ecx + 6]        
  0x003B8147  8d541a02                lea      edx, [edx + ebx + 2]           
  0x003B814B  c1fa02                  sar      edx, 2                         
  0x003B814E  885605                  mov      byte ptr [esi + 5], dl         
  0x003B8151  0fb65807                movzx    ebx, byte ptr [eax + 7]        
  0x003B8155  0fb65006                movzx    edx, byte ptr [eax + 6]        
  0x003B8159  03d3                    add      edx, ebx                       
  0x003B815B  0fb65906                movzx    ebx, byte ptr [ecx + 6]        
  0x003B815F  03d3                    add      edx, ebx                       
  0x003B8161  0fb65907                movzx    ebx, byte ptr [ecx + 7]        
  0x003B8165  8d541a02                lea      edx, [edx + ebx + 2]           
  0x003B8169  c1fa02                  sar      edx, 2                         
  0x003B816C  885606                  mov      byte ptr [esi + 6], dl         
  0x003B816F  0fb65808                movzx    ebx, byte ptr [eax + 8]        
  0x003B8173  0fb65108                movzx    edx, byte ptr [ecx + 8]        
  0x003B8177  03d3                    add      edx, ebx                       
  0x003B8179  0fb65807                movzx    ebx, byte ptr [eax + 7]        
  0x003B817D  03d3                    add      edx, ebx                       
  0x003B817F  0fb65907                movzx    ebx, byte ptr [ecx + 7]        
  0x003B8183  8d541a02                lea      edx, [edx + ebx + 2]           
  0x003B8187  c1fa02                  sar      edx, 2                         
  0x003B818A  885607                  mov      byte ptr [esi + 7], dl         
  0x003B818D  03c7                    add      eax, edi                       
  0x003B818F  03cf                    add      ecx, edi                       
  0x003B8191  83c608                  add      esi, 8                         
  0x003B8194  4d                      dec      ebp                            
  0x003B8195  0f8505ffffff            jne      0x3b80a0                       
  0x003B819B  5f                      pop      edi                            
  0x003B819C  5e                      pop      esi                            
  0x003B819D  5d                      pop      ebp                            
  0x003B819E  5b                      pop      ebx                            
  0x003B819F  c3                      ret                                     
; end of function
  0x003B81A0  83ec0c                  sub      esp, 0xc                       
  0x003B81A3  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003B81A7  8b4820                  mov      ecx, dword ptr [eax + 0x20]    
  0x003B81AA  8b5024                  mov      edx, dword ptr [eax + 0x24]    
  0x003B81AD  894c2410                mov      dword ptr [esp + 0x10], ecx    
  0x003B81B1  8b4828                  mov      ecx, dword ptr [eax + 0x28]    
  0x003B81B4  89542408                mov      dword ptr [esp + 8], edx       
  0x003B81B8  8b5018                  mov      edx, dword ptr [eax + 0x18]    
  0x003B81BB  53                      push     ebx                            
  0x003B81BC  894c2408                mov      dword ptr [esp + 8], ecx       
  0x003B81C0  89542404                mov      dword ptr [esp + 4], edx       
  0x003B81C4  8b44240c                mov      eax, dword ptr [esp + 0xc]     
  0x003B81C8  8b5c2408                mov      ebx, dword ptr [esp + 8]       
  0x003B81CC  8b4c2404                mov      ecx, dword ptr [esp + 4]       
  0x003B81D0  8b542414                mov      edx, dword ptr [esp + 0x14]    
  0x003B81D4  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003B81D7  0fe003                  pavgb    mm0, qword ptr [ebx]           
  0x003B81DA  0f7f01                  movq     qword ptr [ecx], mm0           
  0x003B81DD  03c2                    add      eax, edx                       
  0x003B81DF  03da                    add      ebx, edx                       
  0x003B81E1  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003B81E4  0fe003                  pavgb    mm0, qword ptr [ebx]           
  0x003B81E7  0f7f4108                movq     qword ptr [ecx + 8], mm0       
  0x003B81EB  03c2                    add      eax, edx                       
  0x003B81ED  03da                    add      ebx, edx                       
  0x003B81EF  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003B81F2  0fe003                  pavgb    mm0, qword ptr [ebx]           
  0x003B81F5  0f7f4110                movq     qword ptr [ecx + 0x10], mm0    
  0x003B81F9  03c2                    add      eax, edx                       
  0x003B81FB  03da                    add      ebx, edx                       
  0x003B81FD  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003B8200  0fe003                  pavgb    mm0, qword ptr [ebx]           
  0x003B8203  0f7f4118                movq     qword ptr [ecx + 0x18], mm0    
  0x003B8207  03c2                    add      eax, edx                       
  0x003B8209  03da                    add      ebx, edx                       
  0x003B820B  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003B820E  0fe003                  pavgb    mm0, qword ptr [ebx]           
  0x003B8211  0f7f4120                movq     qword ptr [ecx + 0x20], mm0    
  0x003B8215  03c2                    add      eax, edx                       
  0x003B8217  03da                    add      ebx, edx                       
  0x003B8219  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003B821C  0fe003                  pavgb    mm0, qword ptr [ebx]           
  0x003B821F  0f7f4128                movq     qword ptr [ecx + 0x28], mm0    
  0x003B8223  03c2                    add      eax, edx                       
  0x003B8225  03da                    add      ebx, edx                       
  0x003B8227  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003B822A  0fe003                  pavgb    mm0, qword ptr [ebx]           
  0x003B822D  0f7f4130                movq     qword ptr [ecx + 0x30], mm0    
  0x003B8231  03c2                    add      eax, edx                       
  0x003B8233  03da                    add      ebx, edx                       
  0x003B8235  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003B8238  0fe003                  pavgb    mm0, qword ptr [ebx]           
  0x003B823B  0f7f4138                movq     qword ptr [ecx + 0x38], mm0    
  0x003B823F  0f77                    emms                                    
  0x003B8241  5b                      pop      ebx                            
  0x003B8242  83c40c                  add      esp, 0xc                       
  0x003B8245  c3                      ret                                     
  0x003B8246  cc                      int3                                    
  0x003B8247  cc                      int3                                    
  0x003B8248  cc                      int3                                    
  0x003B8249  cc                      int3                                    
  0x003B824A  cc                      int3                                    
  0x003B824B  cc                      int3                                    
  0x003B824C  cc                      int3                                    
  0x003B824D  cc                      int3                                    
  0x003B824E  cc                      int3                                    
  0x003B824F  cc                      int3                                    

; ============================================================
; Function: sub_003B8250
; Start: 0x003B8250  End: 0x003B82E1  Size: 145 bytes
; Detection: cc_boundary (confidence: 0.85)
; ============================================================
sub_003B8250:
  0x003B8250  83ec08                  sub      esp, 8                         
  0x003B8253  8b44240c                mov      eax, dword ptr [esp + 0xc]     
  0x003B8257  8b4820                  mov      ecx, dword ptr [eax + 0x20]    
  0x003B825A  8b5024                  mov      edx, dword ptr [eax + 0x24]    
  0x003B825D  8b4018                  mov      eax, dword ptr [eax + 0x18]    
  0x003B8260  894c240c                mov      dword ptr [esp + 0xc], ecx     
  0x003B8264  89542404                mov      dword ptr [esp + 4], edx       
  0x003B8268  890424                  mov      dword ptr [esp], eax           
  0x003B826B  8b442404                mov      eax, dword ptr [esp + 4]       
  0x003B826F  8b0c24                  mov      ecx, dword ptr [esp]           
  0x003B8272  8b54240c                mov      edx, dword ptr [esp + 0xc]     
  0x003B8276  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003B8279  0fe04001                pavgb    mm0, qword ptr [eax + 1]       
  0x003B827D  0f7f01                  movq     qword ptr [ecx], mm0           
  0x003B8280  03c2                    add      eax, edx                       
  0x003B8282  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003B8285  0fe04001                pavgb    mm0, qword ptr [eax + 1]       
  0x003B8289  0f7f4108                movq     qword ptr [ecx + 8], mm0       
  0x003B828D  03c2                    add      eax, edx                       
  0x003B828F  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003B8292  0fe04001                pavgb    mm0, qword ptr [eax + 1]       
  0x003B8296  0f7f4110                movq     qword ptr [ecx + 0x10], mm0    
  0x003B829A  03c2                    add      eax, edx                       
  0x003B829C  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003B829F  0fe04001                pavgb    mm0, qword ptr [eax + 1]       
  0x003B82A3  0f7f4118                movq     qword ptr [ecx + 0x18], mm0    
  0x003B82A7  03c2                    add      eax, edx                       
  0x003B82A9  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003B82AC  0fe04001                pavgb    mm0, qword ptr [eax + 1]       
  0x003B82B0  0f7f4120                movq     qword ptr [ecx + 0x20], mm0    
  0x003B82B4  03c2                    add      eax, edx                       
  0x003B82B6  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003B82B9  0fe04001                pavgb    mm0, qword ptr [eax + 1]       
  0x003B82BD  0f7f4128                movq     qword ptr [ecx + 0x28], mm0    
  0x003B82C1  03c2                    add      eax, edx                       
  0x003B82C3  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003B82C6  0fe04001                pavgb    mm0, qword ptr [eax + 1]       
  0x003B82CA  0f7f4130                movq     qword ptr [ecx + 0x30], mm0    
  0x003B82CE  03c2                    add      eax, edx                       
  0x003B82D0  0f6f00                  movq     mm0, qword ptr [eax]           
  0x003B82D3  0fe04001                pavgb    mm0, qword ptr [eax + 1]       
  0x003B82D7  0f7f4138                movq     qword ptr [ecx + 0x38], mm0    
  0x003B82DB  0f77                    emms                                    
  0x003B82DD  83c408                  add      esp, 8                         
  0x003B82E0  c3                      ret                                     
; end of function
  0x003B82E1  cc                      int3                                    
  0x003B82E2  cc                      int3                                    
  0x003B82E3  cc                      int3                                    
  0x003B82E4  cc                      int3                                    
  0x003B82E5  cc                      int3                                    
  0x003B82E6  cc                      int3                                    
  0x003B82E7  cc                      int3                                    
  0x003B82E8  cc                      int3                                    
  0x003B82E9  cc                      int3                                    
  0x003B82EA  cc                      int3                                    
  0x003B82EB  cc                      int3                                    
  0x003B82EC  cc                      int3                                    
  0x003B82ED  cc                      int3                                    
  0x003B82EE  cc                      int3                                    
  0x003B82EF  cc                      int3                                    

; ============================================================
; Function: sub_003B82F0
; Start: 0x003B82F0  End: 0x003B8367  Size: 119 bytes
; Detection: cc_boundary (confidence: 0.85)
; ============================================================
sub_003B82F0:
  0x003B82F0  83ec08                  sub      esp, 8                         
  0x003B82F3  8b44240c                mov      eax, dword ptr [esp + 0xc]     
  0x003B82F7  8b4824                  mov      ecx, dword ptr [eax + 0x24]    
  0x003B82FA  8b5018                  mov      edx, dword ptr [eax + 0x18]    
  0x003B82FD  8b4020                  mov      eax, dword ptr [eax + 0x20]    
  0x003B8300  56                      push     esi                            
  0x003B8301  57                      push     edi                            
  0x003B8302  894c240c                mov      dword ptr [esp + 0xc], ecx     
  0x003B8306  89542414                mov      dword ptr [esp + 0x14], edx    
  0x003B830A  89442408                mov      dword ptr [esp + 8], eax       
  0x003B830E  8b74240c                mov      esi, dword ptr [esp + 0xc]     
  0x003B8312  8b442408                mov      eax, dword ptr [esp + 8]       
  0x003B8316  8b7c2414                mov      edi, dword ptr [esp + 0x14]    
  0x003B831A  0f6f06                  movq     mm0, qword ptr [esi]           
  0x003B831D  0f7f07                  movq     qword ptr [edi], mm0           
  0x003B8320  03f0                    add      esi, eax                       
  0x003B8322  0f6f0e                  movq     mm1, qword ptr [esi]           
  0x003B8325  0f7f4f08                movq     qword ptr [edi + 8], mm1       
  0x003B8329  03f0                    add      esi, eax                       
  0x003B832B  0f6f16                  movq     mm2, qword ptr [esi]           
  0x003B832E  0f7f5710                movq     qword ptr [edi + 0x10], mm2    
  0x003B8332  03f0                    add      esi, eax                       
  0x003B8334  0f6f1e                  movq     mm3, qword ptr [esi]           
  0x003B8337  0f7f5f18                movq     qword ptr [edi + 0x18], mm3    
  0x003B833B  03f0                    add      esi, eax                       
  0x003B833D  0f6f26                  movq     mm4, qword ptr [esi]           
  0x003B8340  0f7f6720                movq     qword ptr [edi + 0x20], mm4    
  0x003B8344  03f0                    add      esi, eax                       
  0x003B8346  0f6f2e                  movq     mm5, qword ptr [esi]           
  0x003B8349  0f7f6f28                movq     qword ptr [edi + 0x28], mm5    
  0x003B834D  03f0                    add      esi, eax                       
  0x003B834F  0f6f36                  movq     mm6, qword ptr [esi]           
  0x003B8352  0f7f7730                movq     qword ptr [edi + 0x30], mm6    
  0x003B8356  03f0                    add      esi, eax                       
  0x003B8358  0f6f3e                  movq     mm7, qword ptr [esi]           
  0x003B835B  0f7f7f38                movq     qword ptr [edi + 0x38], mm7    
  0x003B835F  0f77                    emms                                    
  0x003B8361  5f                      pop      edi                            
  0x003B8362  5e                      pop      esi                            
  0x003B8363  83c408                  add      esp, 8                         
  0x003B8366  c3                      ret                                     
; end of function
