; ============================================================
; Section: XGRPH
; VA: 0x00361200 - 0x0036334C
; Size: 8524 bytes (8.3 KB)
; Functions: 36
; Instructions: 3145
; ============================================================


; ============================================================
; Function: sub_00361200
; Start: 0x00361200  End: 0x00361217  Size: 23 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_00361226, sub_00361239
; ============================================================
sub_00361200:
  0x00361200  8b442404                mov      eax, dword ptr [esp + 4]       
  0x00361204  83f80c                  cmp      eax, 0xc                       
  0x00361207  740e                    je       0x361217                       
  0x00361209  83f80d                  cmp      eax, 0xd                       
  0x0036120C  7605                    jbe      0x361213                       
  0x0036120E  83f80f                  cmp      eax, 0xf                       
  0x00361211  7604                    jbe      0x361217                       
                                        ; XREF: 0x0036120C (cond_jump)
  0x00361213  32c0                    xor      al, al                         
  0x00361215  eb02                    jmp      0x361219                       
; end of function
                                        ; XREF: 0x00361207 (cond_jump), 0x00361211 (cond_jump)
  0x00361217  b001                    mov      al, 1                          
                                        ; XREF: 0x00361215 (jump)
  0x00361219  c20400                  ret      4                              

; ============================================================
; Function: sub_0036121C
; Start: 0x0036121C  End: 0x00361226  Size: 10 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_00361591
; ============================================================
sub_0036121C:
  0x0036121C  51                      push     ecx                            
  0x0036121D  890c24                  mov      dword ptr [esp], ecx           
  0x00361220  0fbc0424                bsf      eax, dword ptr [esp]           
  0x00361224  59                      pop      ecx                            
  0x00361225  c3                      ret                                     
; end of function

; ============================================================
; Function: sub_00361226
; Start: 0x00361226  End: 0x00361239  Size: 19 bytes
; Detection: call_target (confidence: 0.90)
; Calls: sub_00361200
; ============================================================
sub_00361226:
  0x00361226  ff742404                push     dword ptr [esp + 4]            
  0x0036122A  e8d1ffffff              call     0x361200                       ; -> sub_00361200
  0x0036122F  f6d8                    neg      al                             
  0x00361231  1bc0                    sbb      eax, eax                       
  0x00361233  83e002                  and      eax, 2                         
  0x00361236  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00361239
; Start: 0x00361239  End: 0x003612AA  Size: 113 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00361200
; Called by: sub_003613D8, sub_00361424
; ============================================================
sub_00361239:
  0x00361239  55                      push     ebp                            
  0x0036123A  8bec                    mov      ebp, esp                       
  0x0036123C  83ec14                  sub      esp, 0x14                      
  0x0036123F  8b4d18                  mov      ecx, dword ptr [ebp + 0x18]    
  0x00361242  8a8108333600            mov      al, byte ptr [ecx + 0x363308]  
  0x00361248  33d2                    xor      edx, edx                       
  0x0036124A  8ad0                    mov      dl, al                         
  0x0036124C  53                      push     ebx                            
  0x0036124D  8a5d20                  mov      bl, byte ptr [ebp + 0x20]      
  0x00361250  56                      push     esi                            
  0x00361251  57                      push     edi                            
  0x00361252  33f6                    xor      esi, esi                       
  0x00361254  8975fc                  mov      dword ptr [ebp - 4], esi       
  0x00361257  83e23c                  and      edx, 0x3c                      
  0x0036125A  a801                    test     al, 1                          
  0x0036125C  8bfa                    mov      edi, edx                       
  0x0036125E  897dec                  mov      dword ptr [ebp - 0x14], edi    
  0x00361261  7547                    jne      0x3612aa                       
  0x00361263  51                      push     ecx                            
  0x00361264  e897ffffff              call     0x361200                       ; -> sub_00361200
  0x00361269  84c0                    test     al, al                         
  0x0036126B  753d                    jne      0x3612aa                       
  0x0036126D  33c0                    xor      eax, eax                       
  0x0036126F  394514                  cmp      dword ptr [ebp + 0x14], eax    
  0x00361272  8945f4                  mov      dword ptr [ebp - 0xc], eax     
  0x00361275  8945f8                  mov      dword ptr [ebp - 8], eax       
  0x00361278  7507                    jne      0x361281                       
  0x0036127A  c7451401000000          mov      dword ptr [ebp + 0x14], 1      
                                        ; XREF: 0x00361278 (cond_jump)
  0x00361281  8b4d1c                  mov      ecx, dword ptr [ebp + 0x1c]    
  0x00361284  3bc8                    cmp      ecx, eax                       
  0x00361286  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x00361289  750e                    jne      0x361299                       
  0x0036128B  0faff8                  imul     edi, eax                       
  0x0036128E  c1ef03                  shr      edi, 3                         
  0x00361291  83c73f                  add      edi, 0x3f                      
  0x00361294  83e7c0                  and      edi, 0xffffffc0                
  0x00361297  8bcf                    mov      ecx, edi                       
                                        ; XREF: 0x00361289 (cond_jump)
  0x00361299  894510                  mov      dword ptr [ebp + 0x10], eax    
  0x0036129C  8b450c                  mov      eax, dword ptr [ebp + 0xc]     
  0x0036129F  8945f0                  mov      dword ptr [ebp - 0x10], eax    
  0x003612A2  0fafc1                  imul     eax, ecx                       
  0x003612A5  e9bf000000              jmp      0x361369                       
; end of function
                                        ; XREF: 0x00361261 (cond_jump), 0x0036126B (cond_jump)
  0x003612AA  8b4d08                  mov      ecx, dword ptr [ebp + 8]       
  0x003612AD  e86affffff              call     0x36121c                       ; -> sub_0036121C
  0x003612B2  8b4d0c                  mov      ecx, dword ptr [ebp + 0xc]     
  0x003612B5  8945f8                  mov      dword ptr [ebp - 8], eax       
  0x003612B8  e85fffffff              call     0x36121c                       ; -> sub_0036121C
  0x003612BD  8b4d10                  mov      ecx, dword ptr [ebp + 0x10]    
  0x003612C0  8bf8                    mov      edi, eax                       
  0x003612C2  897df4                  mov      dword ptr [ebp - 0xc], edi     
  0x003612C5  e852ffffff              call     0x36121c                       ; -> sub_0036121C
  0x003612CA  ff7518                  push     dword ptr [ebp + 0x18]         
  0x003612CD  83651000                and      dword ptr [ebp + 0x10], 0      
  0x003612D1  8365f000                and      dword ptr [ebp - 0x10], 0      
  0x003612D5  8bf0                    mov      esi, eax                       
  0x003612D7  e84affffff              call     0x361226                       ; -> sub_00361226
  0x003612DC  837d1400                cmp      dword ptr [ebp + 0x14], 0      
  0x003612E0  894508                  mov      dword ptr [ebp + 8], eax       
  0x003612E3  751e                    jne      0x361303                       
  0x003612E5  3bfe                    cmp      edi, esi                       
  0x003612E7  8bcf                    mov      ecx, edi                       
  0x003612E9  7702                    ja       0x3612ed                       
  0x003612EB  8bce                    mov      ecx, esi                       
                                        ; XREF: 0x003612E9 (cond_jump)
  0x003612ED  394df8                  cmp      dword ptr [ebp - 8], ecx       
  0x003612F0  7605                    jbe      0x3612f7                       
  0x003612F2  8b4df8                  mov      ecx, dword ptr [ebp - 8]       
  0x003612F5  eb08                    jmp      0x3612ff                       
                                        ; XREF: 0x003612F0 (cond_jump)
  0x003612F7  3bfe                    cmp      edi, esi                       
  0x003612F9  8bcf                    mov      ecx, edi                       
  0x003612FB  7702                    ja       0x3612ff                       
  0x003612FD  8bce                    mov      ecx, esi                       
                                        ; XREF: 0x003612F5 (jump), 0x003612FB (cond_jump)
  0x003612FF  41                      inc      ecx                            
  0x00361300  894d14                  mov      dword ptr [ebp + 0x14], ecx    
                                        ; XREF: 0x003612E3 (cond_jump)
  0x00361303  8b4d14                  mov      ecx, dword ptr [ebp + 0x14]    
  0x00361306  85c9                    test     ecx, ecx                       
  0x00361308  8b45f8                  mov      eax, dword ptr [ebp - 8]       
  0x0036130B  897d20                  mov      dword ptr [ebp + 0x20], edi    
  0x0036130E  8bfe                    mov      edi, esi                       
  0x00361310  7442                    je       0x361354                       
  0x00361312  894d0c                  mov      dword ptr [ebp + 0xc], ecx     
                                        ; XREF: 0x00361352 (cond_jump)
  0x00361315  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x00361318  3bc2                    cmp      eax, edx                       
  0x0036131A  7602                    jbe      0x36131e                       
  0x0036131C  8bd0                    mov      edx, eax                       
                                        ; XREF: 0x0036131A (cond_jump)
  0x0036131E  8b4d08                  mov      ecx, dword ptr [ebp + 8]       
  0x00361321  394d20                  cmp      dword ptr [ebp + 0x20], ecx    
  0x00361324  7603                    jbe      0x361329                       
  0x00361326  8b4d20                  mov      ecx, dword ptr [ebp + 0x20]    
                                        ; XREF: 0x00361324 (cond_jump)
  0x00361329  03ca                    add      ecx, edx                       
  0x0036132B  33d2                    xor      edx, edx                       
  0x0036132D  42                      inc      edx                            
  0x0036132E  03cf                    add      ecx, edi                       
  0x00361330  d3e2                    shl      edx, cl                        
  0x00361332  0faf55ec                imul     edx, dword ptr [ebp - 0x14]    
  0x00361336  c1ea03                  shr      edx, 3                         
  0x00361339  0155fc                  add      dword ptr [ebp - 4], edx       
  0x0036133C  85c0                    test     eax, eax                       
  0x0036133E  7601                    jbe      0x361341                       
  0x00361340  48                      dec      eax                            
                                        ; XREF: 0x0036133E (cond_jump)
  0x00361341  837d2000                cmp      dword ptr [ebp + 0x20], 0      
  0x00361345  7603                    jbe      0x36134a                       
  0x00361347  ff4d20                  dec      dword ptr [ebp + 0x20]         
                                        ; XREF: 0x00361345 (cond_jump)
  0x0036134A  85ff                    test     edi, edi                       
  0x0036134C  7601                    jbe      0x36134f                       
  0x0036134E  4f                      dec      edi                            
                                        ; XREF: 0x0036134C (cond_jump)
  0x0036134F  ff4d0c                  dec      dword ptr [ebp + 0xc]          
  0x00361352  75c1                    jne      0x361315                       
                                        ; XREF: 0x00361310 (cond_jump)
  0x00361354  84db                    test     bl, bl                         
  0x00361356  8b4d1c                  mov      ecx, dword ptr [ebp + 0x1c]    
  0x00361359  7411                    je       0x36136c                       
  0x0036135B  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x0036135E  83c07f                  add      eax, 0x7f                      
  0x00361361  83e080                  and      eax, 0xffffff80                
  0x00361364  8d0440                  lea      eax, [eax + eax*2]             
  0x00361367  d1e0                    shl      eax, 1                         
                                        ; XREF: 0x003612A5 (jump)
  0x00361369  8945fc                  mov      dword ptr [ebp - 4], eax       
                                        ; XREF: 0x00361359 (cond_jump)
  0x0036136C  c1e604                  shl      esi, 4                         
  0x0036136F  0b75f4                  or       esi, dword ptr [ebp - 0xc]     
  0x00361372  33c0                    xor      eax, eax                       
  0x00361374  c1e604                  shl      esi, 4                         
  0x00361377  0b75f8                  or       esi, dword ptr [ebp - 8]       
  0x0036137A  5f                      pop      edi                            
  0x0036137B  c1e604                  shl      esi, 4                         
  0x0036137E  0b7514                  or       esi, dword ptr [ebp + 0x14]    
  0x00361381  c1e608                  shl      esi, 8                         
  0x00361384  0b7518                  or       esi, dword ptr [ebp + 0x18]    
  0x00361387  c1e604                  shl      esi, 4                         
  0x0036138A  384524                  cmp      byte ptr [ebp + 0x24], al      
  0x0036138D  0f95c0                  setne    al                             
  0x00361390  40                      inc      eax                            
  0x00361391  40                      inc      eax                            
  0x00361392  0bf0                    or       esi, eax                       
  0x00361394  8b4528                  mov      eax, dword ptr [ebp + 0x28]    
  0x00361397  c1e604                  shl      esi, 4                         
  0x0036139A  f6db                    neg      bl                             
  0x0036139C  1bdb                    sbb      ebx, ebx                       
  0x0036139E  83e304                  and      ebx, 4                         
  0x003613A1  0bf3                    or       esi, ebx                       
  0x003613A3  83ce09                  or       esi, 9                         
  0x003613A6  8930                    mov      dword ptr [eax], esi           
  0x003613A8  8b4510                  mov      eax, dword ptr [ebp + 0x10]    
  0x003613AB  85c0                    test     eax, eax                       
  0x003613AD  5e                      pop      esi                            
  0x003613AE  5b                      pop      ebx                            
  0x003613AF  741a                    je       0x3613cb                       
  0x003613B1  8b55f0                  mov      edx, dword ptr [ebp - 0x10]    
  0x003613B4  c1e906                  shr      ecx, 6                         
  0x003613B7  49                      dec      ecx                            
  0x003613B8  c1e10c                  shl      ecx, 0xc                       
  0x003613BB  4a                      dec      edx                            
  0x003613BC  0bca                    or       ecx, edx                       
  0x003613BE  c1e10c                  shl      ecx, 0xc                       
  0x003613C1  48                      dec      eax                            
  0x003613C2  0bc8                    or       ecx, eax                       
  0x003613C4  8b452c                  mov      eax, dword ptr [ebp + 0x2c]    
  0x003613C7  8908                    mov      dword ptr [eax], ecx           
  0x003613C9  eb06                    jmp      0x3613d1                       
                                        ; XREF: 0x003613AF (cond_jump)
  0x003613CB  8b452c                  mov      eax, dword ptr [ebp + 0x2c]    
  0x003613CE  832000                  and      dword ptr [eax], 0             
                                        ; XREF: 0x003613C9 (jump)
  0x003613D1  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x003613D4  c9                      leave                                   
  0x003613D5  c22800                  ret      0x28                           

; ============================================================
; Function: sub_003613D8
; Start: 0x003613D8  End: 0x00361424  Size: 76 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00361239
; Called by: sub_00361465
; ============================================================
sub_003613D8:
  0x003613D8  55                      push     ebp                            
  0x003613D9  8bec                    mov      ebp, esp                       
  0x003613DB  56                      push     esi                            
  0x003613DC  8b7530                  mov      esi, dword ptr [ebp + 0x30]    
  0x003613DF  57                      push     edi                            
  0x003613E0  8d4610                  lea      eax, [esi + 0x10]              
  0x003613E3  50                      push     eax                            
  0x003613E4  8d7e0c                  lea      edi, [esi + 0xc]               
  0x003613E7  57                      push     edi                            
  0x003613E8  ff7528                  push     dword ptr [ebp + 0x28]         
  0x003613EB  ff7524                  push     dword ptr [ebp + 0x24]         
  0x003613EE  ff7520                  push     dword ptr [ebp + 0x20]         
  0x003613F1  ff751c                  push     dword ptr [ebp + 0x1c]         
  0x003613F4  ff7514                  push     dword ptr [ebp + 0x14]         
  0x003613F7  ff7510                  push     dword ptr [ebp + 0x10]         
  0x003613FA  ff750c                  push     dword ptr [ebp + 0xc]          
  0x003613FD  ff7508                  push     dword ptr [ebp + 8]            
  0x00361400  e834feffff              call     0x361239                       ; -> sub_00361239
  0x00361405  f6451a01                test     byte ptr [ebp + 0x1a], 1       
  0x00361409  7403                    je       0x36140e                       
  0x0036140B  8327f7                  and      dword ptr [edi], 0xfffffff7    
                                        ; XREF: 0x00361409 (cond_jump)
  0x0036140E  8b4d2c                  mov      ecx, dword ptr [ebp + 0x2c]    
  0x00361411  83660800                and      dword ptr [esi + 8], 0         
  0x00361415  5f                      pop      edi                            
  0x00361416  c70601000400            mov      dword ptr [esi], 0x40001       
  0x0036141C  894e04                  mov      dword ptr [esi + 4], ecx       
  0x0036141F  5e                      pop      esi                            
  0x00361420  5d                      pop      ebp                            
  0x00361421  c22c00                  ret      0x2c                           
; end of function

; ============================================================
; Function: sub_00361424
; Start: 0x00361424  End: 0x00361465  Size: 65 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00361239
; Called by: sub_0005BC20, sub_00194DB0, sub_001E4860, sub_002756F0, sub_00281E90
; ============================================================
sub_00361424:
  0x00361424  55                      push     ebp                            
  0x00361425  8bec                    mov      ebp, esp                       
  0x00361427  56                      push     esi                            
  0x00361428  8b7514                  mov      esi, dword ptr [ebp + 0x14]    
  0x0036142B  8d4610                  lea      eax, [esi + 0x10]              
  0x0036142E  50                      push     eax                            
  0x0036142F  8d460c                  lea      eax, [esi + 0xc]               
  0x00361432  50                      push     eax                            
  0x00361433  6a00                    push     0                              
  0x00361435  6a00                    push     0                              
  0x00361437  ff751c                  push     dword ptr [ebp + 0x1c]         
  0x0036143A  ff7510                  push     dword ptr [ebp + 0x10]         
  0x0036143D  6a01                    push     1                              
  0x0036143F  6a01                    push     1                              
  0x00361441  ff750c                  push     dword ptr [ebp + 0xc]          
  0x00361444  ff7508                  push     dword ptr [ebp + 8]            
  0x00361447  e8edfdffff              call     0x361239                       ; -> sub_00361239
  0x0036144C  83660800                and      dword ptr [esi + 8], 0         
  0x00361450  8b4d18                  mov      ecx, dword ptr [ebp + 0x18]    
  0x00361453  83661400                and      dword ptr [esi + 0x14], 0      
  0x00361457  c70601000500            mov      dword ptr [esi], 0x50001       
  0x0036145D  894e04                  mov      dword ptr [esi + 4], ecx       
  0x00361460  5e                      pop      esi                            
  0x00361461  5d                      pop      ebp                            
  0x00361462  c21800                  ret      0x18                           
; end of function

; ============================================================
; Function: sub_00361465
; Start: 0x00361465  End: 0x0036148F  Size: 42 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_003613D8
; Called by: sub_000A75D0, sub_000A8730, sub_000A8DE0, sub_000AE160, sub_000AE1A0, sub_000AF4B0, sub_00167490, sub_001E3110, sub_00248960, sub_0026BD20 ... (+7 more)
; ============================================================
sub_00361465:
  0x00361465  55                      push     ebp                            
  0x00361466  8bec                    mov      ebp, esp                       
  0x00361468  ff7520                  push     dword ptr [ebp + 0x20]         
  0x0036146B  ff7524                  push     dword ptr [ebp + 0x24]         
  0x0036146E  6a00                    push     0                              
  0x00361470  6a00                    push     0                              
  0x00361472  ff7528                  push     dword ptr [ebp + 0x28]         
  0x00361475  ff7518                  push     dword ptr [ebp + 0x18]         
  0x00361478  ff7514                  push     dword ptr [ebp + 0x14]         
  0x0036147B  ff7510                  push     dword ptr [ebp + 0x10]         
  0x0036147E  6a01                    push     1                              
  0x00361480  ff750c                  push     dword ptr [ebp + 0xc]          
  0x00361483  ff7508                  push     dword ptr [ebp + 8]            
  0x00361486  e84dffffff              call     0x3613d8                       ; -> sub_003613D8
  0x0036148B  5d                      pop      ebp                            
  0x0036148C  c22400                  ret      0x24                           
; end of function

; ============================================================
; Function: sub_0036148F
; Start: 0x0036148F  End: 0x003614A7  Size: 24 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_001D6560, sub_001F4830
; ============================================================
sub_0036148F:
  0x0036148F  8b442414                mov      eax, dword ptr [esp + 0x14]    
  0x00361493  8b4c2418                mov      ecx, dword ptr [esp + 0x18]    
  0x00361497  83600800                and      dword ptr [eax + 8], 0         
  0x0036149B  c70001000000            mov      dword ptr [eax], 1             
  0x003614A1  894804                  mov      dword ptr [eax + 4], ecx       
  0x003614A4  c21800                  ret      0x18                           
; end of function

; ============================================================
; Function: sub_003614A7
; Start: 0x003614A7  End: 0x003614BF  Size: 24 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_00289C80
; ============================================================
sub_003614A7:
  0x003614A7  8b442414                mov      eax, dword ptr [esp + 0x14]    
  0x003614AB  8b4c2418                mov      ecx, dword ptr [esp + 0x18]    
  0x003614AF  83600800                and      dword ptr [eax + 8], 0         
  0x003614B3  c70001000100            mov      dword ptr [eax], 0x10001       
  0x003614B9  894804                  mov      dword ptr [eax + 4], ecx       
  0x003614BC  c21800                  ret      0x18                           
; end of function

; ============================================================
; Function: sub_003614BF
; Start: 0x003614BF  End: 0x003614DE  Size: 31 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_0036249D, sub_00362BEE
; ============================================================
sub_003614BF:
  0x003614BF  8bc1                    mov      eax, ecx                       
  0x003614C1  33c9                    xor      ecx, ecx                       
  0x003614C3  8908                    mov      dword ptr [eax], ecx           
  0x003614C5  894804                  mov      dword ptr [eax + 4], ecx       
  0x003614C8  894808                  mov      dword ptr [eax + 8], ecx       
  0x003614CB  89480c                  mov      dword ptr [eax + 0xc], ecx     
  0x003614CE  894810                  mov      dword ptr [eax + 0x10], ecx    
  0x003614D1  894814                  mov      dword ptr [eax + 0x14], ecx    
  0x003614D4  894818                  mov      dword ptr [eax + 0x18], ecx    
  0x003614D7  89481c                  mov      dword ptr [eax + 0x1c], ecx    
  0x003614DA  894820                  mov      dword ptr [eax + 0x20], ecx    
  0x003614DD  c3                      ret                                     
; end of function

; ============================================================
; Function: sub_003614DE
; Start: 0x003614DE  End: 0x0036153F  Size: 97 bytes
; Detection: prologue (confidence: 0.95)
; Called by: sub_0036249D, sub_00362BEE
; ============================================================
sub_003614DE:
  0x003614DE  55                      push     ebp                            
  0x003614DF  8bec                    mov      ebp, esp                       
  0x003614E1  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x003614E4  8901                    mov      dword ptr [ecx], eax           
  0x003614E6  8b450c                  mov      eax, dword ptr [ebp + 0xc]     
  0x003614E9  894104                  mov      dword ptr [ecx + 4], eax       
  0x003614EC  8b4510                  mov      eax, dword ptr [ebp + 0x10]    
  0x003614EF  33d2                    xor      edx, edx                       
  0x003614F1  894108                  mov      dword ptr [ecx + 8], eax       
  0x003614F4  33c0                    xor      eax, eax                       
  0x003614F6  56                      push     esi                            
  0x003614F7  40                      inc      eax                            
  0x003614F8  57                      push     edi                            
  0x003614F9  89510c                  mov      dword ptr [ecx + 0xc], edx     
  0x003614FC  895110                  mov      dword ptr [ecx + 0x10], edx    
  0x003614FF  895114                  mov      dword ptr [ecx + 0x14], edx    
  0x00361502  895118                  mov      dword ptr [ecx + 0x18], edx    
  0x00361505  89511c                  mov      dword ptr [ecx + 0x1c], edx    
  0x00361508  895120                  mov      dword ptr [ecx + 0x20], edx    
  0x0036150B  8bf8                    mov      edi, eax                       
                                        ; XREF: 0x00361537 (cond_jump)
  0x0036150D  33f6                    xor      esi, esi                       
  0x0036150F  3b7d08                  cmp      edi, dword ptr [ebp + 8]       
  0x00361512  7307                    jae      0x36151b                       
  0x00361514  09410c                  or       dword ptr [ecx + 0xc], eax     
  0x00361517  d1e0                    shl      eax, 1                         
  0x00361519  8bf0                    mov      esi, eax                       
                                        ; XREF: 0x00361512 (cond_jump)
  0x0036151B  3b7d0c                  cmp      edi, dword ptr [ebp + 0xc]     
  0x0036151E  7307                    jae      0x361527                       
  0x00361520  094110                  or       dword ptr [ecx + 0x10], eax    
  0x00361523  d1e0                    shl      eax, 1                         
  0x00361525  8bf0                    mov      esi, eax                       
                                        ; XREF: 0x0036151E (cond_jump)
  0x00361527  3b7d10                  cmp      edi, dword ptr [ebp + 0x10]    
  0x0036152A  7307                    jae      0x361533                       
  0x0036152C  094114                  or       dword ptr [ecx + 0x14], eax    
  0x0036152F  d1e0                    shl      eax, 1                         
  0x00361531  8bf0                    mov      esi, eax                       
                                        ; XREF: 0x0036152A (cond_jump)
  0x00361533  d1e7                    shl      edi, 1                         
  0x00361535  3bf2                    cmp      esi, edx                       
  0x00361537  75d4                    jne      0x36150d                       
  0x00361539  5f                      pop      edi                            
  0x0036153A  5e                      pop      esi                            
  0x0036153B  5d                      pop      ebp                            
  0x0036153C  c20c00                  ret      0xc                            
; end of function

; ============================================================
; Function: sub_0036153F
; Start: 0x0036153F  End: 0x00361568  Size: 41 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_00361D28, sub_00361DA9, sub_00361E7D, sub_00361F51, sub_00361FD4, sub_00362057, sub_00362123, sub_003621EF, sub_0036226A, sub_003622E5 ... (+3 more)
; ============================================================
sub_0036153F:
  0x0036153F  8b490c                  mov      ecx, dword ptr [ecx + 0xc]     
  0x00361542  33d2                    xor      edx, edx                       
  0x00361544  42                      inc      edx                            
  0x00361545  33c0                    xor      eax, eax                       
  0x00361547  3bca                    cmp      ecx, edx                       
  0x00361549  721a                    jb       0x361565                       
  0x0036154B  56                      push     esi                            
                                        ; XREF: 0x00361562 (cond_jump)
  0x0036154C  85ca                    test     edx, ecx                       
  0x0036154E  740a                    je       0x36155a                       
  0x00361550  8bf2                    mov      esi, edx                       
  0x00361552  23742408                and      esi, dword ptr [esp + 8]       
  0x00361556  0bc6                    or       eax, esi                       
  0x00361558  eb04                    jmp      0x36155e                       
                                        ; XREF: 0x0036154E (cond_jump)
  0x0036155A  d1642408                shl      dword ptr [esp + 8], 1         
                                        ; XREF: 0x00361558 (jump)
  0x0036155E  d1e2                    shl      edx, 1                         
  0x00361560  3bd1                    cmp      edx, ecx                       
  0x00361562  76e8                    jbe      0x36154c                       
  0x00361564  5e                      pop      esi                            
                                        ; XREF: 0x00361549 (cond_jump)
  0x00361565  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00361568
; Start: 0x00361568  End: 0x00361591  Size: 41 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_00361D28, sub_00361DA9, sub_00361E7D, sub_00361F51, sub_00361FD4, sub_00362057, sub_00362123, sub_003621EF, sub_0036226A, sub_003622E5 ... (+3 more)
; ============================================================
sub_00361568:
  0x00361568  8b4910                  mov      ecx, dword ptr [ecx + 0x10]    
  0x0036156B  33d2                    xor      edx, edx                       
  0x0036156D  42                      inc      edx                            
  0x0036156E  33c0                    xor      eax, eax                       
  0x00361570  3bca                    cmp      ecx, edx                       
  0x00361572  721a                    jb       0x36158e                       
  0x00361574  56                      push     esi                            
                                        ; XREF: 0x0036158B (cond_jump)
  0x00361575  85ca                    test     edx, ecx                       
  0x00361577  740a                    je       0x361583                       
  0x00361579  8bf2                    mov      esi, edx                       
  0x0036157B  23742408                and      esi, dword ptr [esp + 8]       
  0x0036157F  0bc6                    or       eax, esi                       
  0x00361581  eb04                    jmp      0x361587                       
                                        ; XREF: 0x00361577 (cond_jump)
  0x00361583  d1642408                shl      dword ptr [esp + 8], 1         
                                        ; XREF: 0x00361581 (jump)
  0x00361587  d1e2                    shl      edx, 1                         
  0x00361589  3bd1                    cmp      edx, ecx                       
  0x0036158B  76e8                    jbe      0x361575                       
  0x0036158D  5e                      pop      esi                            
                                        ; XREF: 0x00361572 (cond_jump)
  0x0036158E  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00361591
; Start: 0x00361591  End: 0x003615C9  Size: 56 bytes
; Detection: call_target (confidence: 0.90)
; Calls: sub_0036121C
; Called by: sub_00361605, sub_00361705, sub_00361803, sub_003618FC, sub_003619DF, sub_00361AF1
; ============================================================
sub_00361591:
  0x00361591  8b4c2404                mov      ecx, dword ptr [esp + 4]       
  0x00361595  56                      push     esi                            
  0x00361596  57                      push     edi                            
  0x00361597  e880fcffff              call     0x36121c                       ; -> sub_0036121C
  0x0036159C  8b4c2410                mov      ecx, dword ptr [esp + 0x10]    
  0x003615A0  8bf8                    mov      edi, eax                       
  0x003615A2  e875fcffff              call     0x36121c                       ; -> sub_0036121C
  0x003615A7  3bf8                    cmp      edi, eax                       
  0x003615A9  8bcf                    mov      ecx, edi                       
  0x003615AB  7202                    jb       0x3615af                       
  0x003615AD  8bc8                    mov      ecx, eax                       
                                        ; XREF: 0x003615AB (cond_jump)
  0x003615AF  33d2                    xor      edx, edx                       
  0x003615B1  03c9                    add      ecx, ecx                       
  0x003615B3  42                      inc      edx                            
  0x003615B4  d3e2                    shl      edx, cl                        
  0x003615B6  4a                      dec      edx                            
  0x003615B7  3bf8                    cmp      edi, eax                       
  0x003615B9  8bca                    mov      ecx, edx                       
  0x003615BB  f7d1                    not      ecx                            
  0x003615BD  760a                    jbe      0x3615c9                       
  0x003615BF  8bf1                    mov      esi, ecx                       
  0x003615C1  81ce55555555            or       esi, 0x55555555                
  0x003615C7  eb08                    jmp      0x3615d1                       
; end of function
                                        ; XREF: 0x003615BD (cond_jump)
  0x003615C9  8bf2                    mov      esi, edx                       
  0x003615CB  81e655555555            and      esi, 0x55555555                
                                        ; XREF: 0x003615C7 (jump)
  0x003615D1  3bf8                    cmp      edi, eax                       
  0x003615D3  730a                    jae      0x3615df                       
  0x003615D5  81c9aaaaaaaa            or       ecx, 0xaaaaaaaa                
  0x003615DB  8bd1                    mov      edx, ecx                       
  0x003615DD  eb06                    jmp      0x3615e5                       
                                        ; XREF: 0x003615D3 (cond_jump)
  0x003615DF  81e2aaaaaaaa            and      edx, 0xaaaaaaaa                
                                        ; XREF: 0x003615DD (jump)
  0x003615E5  8d0c38                  lea      ecx, [eax + edi]               
  0x003615E8  33c0                    xor      eax, eax                       
  0x003615EA  40                      inc      eax                            
  0x003615EB  d3e0                    shl      eax, cl                        
  0x003615ED  5f                      pop      edi                            
  0x003615EE  48                      dec      eax                            
  0x003615EF  8bc8                    mov      ecx, eax                       
  0x003615F1  23ce                    and      ecx, esi                       
  0x003615F3  8b742410                mov      esi, dword ptr [esp + 0x10]    
  0x003615F7  890e                    mov      dword ptr [esi], ecx           
  0x003615F9  8b4c2414                mov      ecx, dword ptr [esp + 0x14]    
  0x003615FD  23c2                    and      eax, edx                       
  0x003615FF  8901                    mov      dword ptr [ecx], eax           
  0x00361601  5e                      pop      esi                            
  0x00361602  c21000                  ret      0x10                           

; ============================================================
; Function: sub_00361605
; Start: 0x00361605  End: 0x00361642  Size: 61 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00361591
; Called by: sub_0036249D
; ============================================================
sub_00361605:
  0x00361605  55                      push     ebp                            
  0x00361606  8bec                    mov      ebp, esp                       
  0x00361608  83ec0c                  sub      esp, 0xc                       
  0x0036160B  53                      push     ebx                            
  0x0036160C  56                      push     esi                            
  0x0036160D  57                      push     edi                            
  0x0036160E  8d4514                  lea      eax, [ebp + 0x14]              
  0x00361611  50                      push     eax                            
  0x00361612  8d45fc                  lea      eax, [ebp - 4]                 
  0x00361615  50                      push     eax                            
  0x00361616  ff7514                  push     dword ptr [ebp + 0x14]         
  0x00361619  ff7510                  push     dword ptr [ebp + 0x10]         
  0x0036161C  e870ffffff              call     0x361591                       ; -> sub_00361591
  0x00361621  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x00361624  83e0c0                  and      eax, 0xffffffc0                
  0x00361627  8945f4                  mov      dword ptr [ebp - 0xc], eax     
  0x0036162A  8b4514                  mov      eax, dword ptr [ebp + 0x14]    
  0x0036162D  83e080                  and      eax, 0xffffff80                
  0x00361630  8945f8                  mov      dword ptr [ebp - 8], eax       
  0x00361633  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00361636  8b7d0c                  mov      edi, dword ptr [ebp + 0xc]     
  0x00361639  8b5510                  mov      edx, dword ptr [ebp + 0x10]    
  0x0036163C  33db                    xor      ebx, ebx                       
  0x0036163E  33c9                    xor      ecx, ecx                       
  0x00361640  eb03                    jmp      0x361645                       
; end of function
  0x00361642  8d4900                  lea      ecx, [ecx]                     
                                        ; XREF: 0x00361640 (jump), 0x003616E5 (cond_jump), 0x003616F6 (cond_jump)
  0x00361645  0f6f06                  movq     mm0, qword ptr [esi]           
  0x00361648  0f6f0c16                movq     mm1, qword ptr [esi + edx]     
  0x0036164C  03f2                    add      esi, edx                       
  0x0036164E  8bc3                    mov      eax, ebx                       
  0x00361650  0f6f2416                movq     mm4, qword ptr [esi + edx]     
  0x00361654  0f6f2c56                movq     mm5, qword ptr [esi + edx*2]   
  0x00361658  0bc1                    or       eax, ecx                       
  0x0036165A  0f7fe6                  movq     mm6, mm4                       
  0x0036165D  0f7fc2                  movq     mm2, mm0                       
  0x00361660  0f69f5                  punpckhwd mm6, mm5                       
  0x00361663  8d3496                  lea      esi, [esi + edx*4]             
  0x00361666  0f69d1                  punpckhwd mm2, mm1                       
  0x00361669  0f61e5                  punpcklwd mm4, mm5                       
  0x0036166C  0f6f1e                  movq     mm3, qword ptr [esi]           
  0x0036166F  0f6f2c16                movq     mm5, qword ptr [esi + edx]     
  0x00361673  0f6f3c56                movq     mm7, qword ptr [esi + edx*2]   
  0x00361677  2bf2                    sub      esi, edx                       
  0x00361679  0f61c1                  punpcklwd mm0, mm1                       
  0x0036167C  0f6f0e                  movq     mm1, qword ptr [esi]           
  0x0036167F  0f7f0407                movq     qword ptr [edi + eax], mm0     
  0x00361683  0f7f640708              movq     qword ptr [edi + eax + 8], mm4 
  0x00361688  0f7f540710              movq     qword ptr [edi + eax + 0x10], mm2 
  0x0036168D  0f7f740718              movq     qword ptr [edi + eax + 0x18], mm6 
  0x00361692  0f7fc8                  movq     mm0, mm1                       
  0x00361695  0f7fec                  movq     mm4, mm5                       
  0x00361698  0f61c3                  punpcklwd mm0, mm3                       
  0x0036169B  0f61e7                  punpcklwd mm4, mm7                       
  0x0036169E  0f69cb                  punpckhwd mm1, mm3                       
  0x003616A1  0f69ef                  punpckhwd mm5, mm7                       
  0x003616A4  0f7f440720              movq     qword ptr [edi + eax + 0x20], mm0 
  0x003616A9  0f7f640728              movq     qword ptr [edi + eax + 0x28], mm4 
  0x003616AE  0f7f4c0730              movq     qword ptr [edi + eax + 0x30], mm1 
  0x003616B3  0f7f6c0738              movq     qword ptr [edi + eax + 0x38], mm5 
  0x003616B8  2bf2                    sub      esi, edx                       
  0x003616BA  2bf2                    sub      esi, edx                       
  0x003616BC  2bf2                    sub      esi, edx                       
  0x003616BE  2bf2                    sub      esi, edx                       
  0x003616C0  2b5df4                  sub      ebx, dword ptr [ebp - 0xc]     
  0x003616C3  90                      nop                                     
  0x003616C4  90                      nop                                     
  0x003616C5  90                      nop                                     
  0x003616C6  90                      nop                                     
  0x003616C7  90                      nop                                     
  0x003616C8  90                      nop                                     
  0x003616C9  90                      nop                                     
  0x003616CA  90                      nop                                     
  0x003616CB  90                      nop                                     
  0x003616CC  90                      nop                                     
  0x003616CD  90                      nop                                     
  0x003616CE  90                      nop                                     
  0x003616CF  90                      nop                                     
  0x003616D0  90                      nop                                     
  0x003616D1  90                      nop                                     
  0x003616D2  90                      nop                                     
  0x003616D3  90                      nop                                     
  0x003616D4  90                      nop                                     
  0x003616D5  90                      nop                                     
  0x003616D6  90                      nop                                     
  0x003616D7  90                      nop                                     
  0x003616D8  90                      nop                                     
  0x003616D9  90                      nop                                     
  0x003616DA  90                      nop                                     
  0x003616DB  90                      nop                                     
  0x003616DC  90                      nop                                     
  0x003616DD  90                      nop                                     
  0x003616DE  90                      nop                                     
  0x003616DF  83c608                  add      esi, 8                         
  0x003616E2  235dfc                  and      ebx, dword ptr [ebp - 4]       
  0x003616E5  0f855affffff            jne      0x361645                       
  0x003616EB  2b4df8                  sub      ecx, dword ptr [ebp - 8]       
  0x003616EE  8d34d6                  lea      esi, [esi + edx*8]             
  0x003616F1  2bf2                    sub      esi, edx                       
  0x003616F3  234d14                  and      ecx, dword ptr [ebp + 0x14]    
  0x003616F6  0f8549ffffff            jne      0x361645                       
  0x003616FC  0f77                    emms                                    
  0x003616FE  5f                      pop      edi                            
  0x003616FF  5e                      pop      esi                            
  0x00361700  5b                      pop      ebx                            
  0x00361701  c9                      leave                                   
  0x00361702  c21000                  ret      0x10                           

; ============================================================
; Function: sub_00361705
; Start: 0x00361705  End: 0x00361803  Size: 254 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00361591
; Called by: sub_0036249D
; ============================================================
sub_00361705:
  0x00361705  55                      push     ebp                            
  0x00361706  8bec                    mov      ebp, esp                       
  0x00361708  83ec0c                  sub      esp, 0xc                       
  0x0036170B  53                      push     ebx                            
  0x0036170C  56                      push     esi                            
  0x0036170D  57                      push     edi                            
  0x0036170E  8d4514                  lea      eax, [ebp + 0x14]              
  0x00361711  50                      push     eax                            
  0x00361712  8d45fc                  lea      eax, [ebp - 4]                 
  0x00361715  50                      push     eax                            
  0x00361716  ff7514                  push     dword ptr [ebp + 0x14]         
  0x00361719  ff7510                  push     dword ptr [ebp + 0x10]         
  0x0036171C  e870feffff              call     0x361591                       ; -> sub_00361591
  0x00361721  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x00361724  83e0c0                  and      eax, 0xffffffc0                
  0x00361727  8945f4                  mov      dword ptr [ebp - 0xc], eax     
  0x0036172A  8b4514                  mov      eax, dword ptr [ebp + 0x14]    
  0x0036172D  83e080                  and      eax, 0xffffff80                
  0x00361730  8945f8                  mov      dword ptr [ebp - 8], eax       
  0x00361733  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00361736  8b7d0c                  mov      edi, dword ptr [ebp + 0xc]     
  0x00361739  8b5510                  mov      edx, dword ptr [ebp + 0x10]    
  0x0036173C  33db                    xor      ebx, ebx                       
  0x0036173E  33c9                    xor      ecx, ecx                       
  0x00361740  03d2                    add      edx, edx                       
  0x00361742  8d4900                  lea      ecx, [ecx]                     
                                        ; XREF: 0x003617E5 (cond_jump), 0x003617F6 (cond_jump)
  0x00361745  0f1006                  movups   xmm0, xmmword ptr [esi]        
  0x00361748  0f100c16                movups   xmm1, xmmword ptr [esi + edx]  
  0x0036174C  03f2                    add      esi, edx                       
  0x0036174E  8bc3                    mov      eax, ebx                       
  0x00361750  0f102416                movups   xmm4, xmmword ptr [esi + edx]  
  0x00361754  0f102c56                movups   xmm5, xmmword ptr [esi + edx*2] 
  0x00361758  0bc1                    or       eax, ecx                       
  0x0036175A  0f28f4                  movaps   xmm6, xmm4                     
  0x0036175D  0f28d0                  movaps   xmm2, xmm0                     
  0x00361760  0f15f5                  unpckhps xmm6, xmm5                     
  0x00361763  8d3496                  lea      esi, [esi + edx*4]             
  0x00361766  0f15d1                  unpckhps xmm2, xmm1                     
  0x00361769  0f14e5                  unpcklps xmm4, xmm5                     
  0x0036176C  0f101e                  movups   xmm3, xmmword ptr [esi]        
  0x0036176F  0f102c16                movups   xmm5, xmmword ptr [esi + edx]  
  0x00361773  0f103c56                movups   xmm7, xmmword ptr [esi + edx*2] 
  0x00361777  2bf2                    sub      esi, edx                       
  0x00361779  0f14c1                  unpcklps xmm0, xmm1                     
  0x0036177C  0f100e                  movups   xmm1, xmmword ptr [esi]        
  0x0036177F  0f2b0447                movntps  xmmword ptr [edi + eax*2], xmm0 
  0x00361783  0f2b644710              movntps  xmmword ptr [edi + eax*2 + 0x10], xmm4 
  0x00361788  0f2b544720              movntps  xmmword ptr [edi + eax*2 + 0x20], xmm2 
  0x0036178D  0f2b744730              movntps  xmmword ptr [edi + eax*2 + 0x30], xmm6 
  0x00361792  0f28c1                  movaps   xmm0, xmm1                     
  0x00361795  0f28e5                  movaps   xmm4, xmm5                     
  0x00361798  0f14c3                  unpcklps xmm0, xmm3                     
  0x0036179B  0f14e7                  unpcklps xmm4, xmm7                     
  0x0036179E  0f15cb                  unpckhps xmm1, xmm3                     
  0x003617A1  0f15ef                  unpckhps xmm5, xmm7                     
  0x003617A4  0f2b444740              movntps  xmmword ptr [edi + eax*2 + 0x40], xmm0 
  0x003617A9  0f2b644750              movntps  xmmword ptr [edi + eax*2 + 0x50], xmm4 
  0x003617AE  0f2b4c4760              movntps  xmmword ptr [edi + eax*2 + 0x60], xmm1 
  0x003617B3  0f2b6c4770              movntps  xmmword ptr [edi + eax*2 + 0x70], xmm5 
  0x003617B8  2bf2                    sub      esi, edx                       
  0x003617BA  2bf2                    sub      esi, edx                       
  0x003617BC  2bf2                    sub      esi, edx                       
  0x003617BE  2bf2                    sub      esi, edx                       
  0x003617C0  2b5df4                  sub      ebx, dword ptr [ebp - 0xc]     
  0x003617C3  90                      nop                                     
  0x003617C4  90                      nop                                     
  0x003617C5  90                      nop                                     
  0x003617C6  90                      nop                                     
  0x003617C7  90                      nop                                     
  0x003617C8  90                      nop                                     
  0x003617C9  90                      nop                                     
  0x003617CA  90                      nop                                     
  0x003617CB  90                      nop                                     
  0x003617CC  90                      nop                                     
  0x003617CD  90                      nop                                     
  0x003617CE  90                      nop                                     
  0x003617CF  90                      nop                                     
  0x003617D0  90                      nop                                     
  0x003617D1  90                      nop                                     
  0x003617D2  90                      nop                                     
  0x003617D3  90                      nop                                     
  0x003617D4  90                      nop                                     
  0x003617D5  90                      nop                                     
  0x003617D6  90                      nop                                     
  0x003617D7  90                      nop                                     
  0x003617D8  90                      nop                                     
  0x003617D9  90                      nop                                     
  0x003617DA  90                      nop                                     
  0x003617DB  90                      nop                                     
  0x003617DC  90                      nop                                     
  0x003617DD  90                      nop                                     
  0x003617DE  90                      nop                                     
  0x003617DF  83c610                  add      esi, 0x10                      
  0x003617E2  235dfc                  and      ebx, dword ptr [ebp - 4]       
  0x003617E5  0f855affffff            jne      0x361745                       
  0x003617EB  2b4df8                  sub      ecx, dword ptr [ebp - 8]       
  0x003617EE  8d34d6                  lea      esi, [esi + edx*8]             
  0x003617F1  2bf2                    sub      esi, edx                       
  0x003617F3  234d14                  and      ecx, dword ptr [ebp + 0x14]    
  0x003617F6  0f8549ffffff            jne      0x361745                       
  0x003617FC  5f                      pop      edi                            
  0x003617FD  5e                      pop      esi                            
  0x003617FE  5b                      pop      ebx                            
  0x003617FF  c9                      leave                                   
  0x00361800  c21000                  ret      0x10                           
; end of function

; ============================================================
; Function: sub_00361803
; Start: 0x00361803  End: 0x003618FC  Size: 249 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00361591
; Called by: sub_0036249D
; ============================================================
sub_00361803:
  0x00361803  55                      push     ebp                            
  0x00361804  8bec                    mov      ebp, esp                       
  0x00361806  83ec0c                  sub      esp, 0xc                       
  0x00361809  53                      push     ebx                            
  0x0036180A  56                      push     esi                            
  0x0036180B  57                      push     edi                            
  0x0036180C  8d4514                  lea      eax, [ebp + 0x14]              
  0x0036180F  50                      push     eax                            
  0x00361810  8d45fc                  lea      eax, [ebp - 4]                 
  0x00361813  50                      push     eax                            
  0x00361814  ff7514                  push     dword ptr [ebp + 0x14]         
  0x00361817  ff7510                  push     dword ptr [ebp + 0x10]         
  0x0036181A  e872fdffff              call     0x361591                       ; -> sub_00361591
  0x0036181F  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x00361822  83e0c0                  and      eax, 0xffffffc0                
  0x00361825  8945f4                  mov      dword ptr [ebp - 0xc], eax     
  0x00361828  8b4514                  mov      eax, dword ptr [ebp + 0x14]    
  0x0036182B  83e0e0                  and      eax, 0xffffffe0                
  0x0036182E  8945f8                  mov      dword ptr [ebp - 8], eax       
  0x00361831  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00361834  8b7d0c                  mov      edi, dword ptr [ebp + 0xc]     
  0x00361837  8b5510                  mov      edx, dword ptr [ebp + 0x10]    
  0x0036183A  33db                    xor      ebx, ebx                       
  0x0036183C  33c9                    xor      ecx, ecx                       
  0x0036183E  c1e202                  shl      edx, 2                         
  0x00361841  8bff                    mov      edi, edi                       
                                        ; XREF: 0x003618DE (cond_jump), 0x003618EF (cond_jump)
  0x00361843  8bc3                    mov      eax, ebx                       
  0x00361845  0f1006                  movups   xmm0, xmmword ptr [esi]        
  0x00361848  0f106610                movups   xmm4, xmmword ptr [esi + 0x10] 
  0x0036184C  0f101416                movups   xmm2, xmmword ptr [esi + edx]  
  0x00361850  0f10741610              movups   xmm6, xmmword ptr [esi + edx + 0x10] 
  0x00361855  0f28c8                  movaps   xmm1, xmm0                     
  0x00361858  0f28ec                  movaps   xmm5, xmm4                     
  0x0036185B  8d3456                  lea      esi, [esi + edx*2]             
  0x0036185E  0bc1                    or       eax, ecx                       
  0x00361860  0f16c2                  movlhps  xmm0, xmm2                     
  0x00361863  0f12d1                  movhlps  xmm2, xmm1                     
  0x00361866  0f16e6                  movlhps  xmm4, xmm6                     
  0x00361869  0f12f5                  movhlps  xmm6, xmm5                     
  0x0036186C  0f100e                  movups   xmm1, xmmword ptr [esi]        
  0x0036186F  0f106e10                movups   xmm5, xmmword ptr [esi + 0x10] 
  0x00361873  0f101c16                movups   xmm3, xmmword ptr [esi + edx]  
  0x00361877  0f107c1610              movups   xmm7, xmmword ptr [esi + edx + 0x10] 
  0x0036187C  0f2b0487                movntps  xmmword ptr [edi + eax*4], xmm0 
  0x00361880  0f2b548710              movntps  xmmword ptr [edi + eax*4 + 0x10], xmm2 
  0x00361885  0f2b648740              movntps  xmmword ptr [edi + eax*4 + 0x40], xmm4 
  0x0036188A  0f2b748750              movntps  xmmword ptr [edi + eax*4 + 0x50], xmm6 
  0x0036188F  0f28c1                  movaps   xmm0, xmm1                     
  0x00361892  0f28e5                  movaps   xmm4, xmm5                     
  0x00361895  0f16cb                  movlhps  xmm1, xmm3                     
  0x00361898  0f12d8                  movhlps  xmm3, xmm0                     
  0x0036189B  0f16ef                  movlhps  xmm5, xmm7                     
  0x0036189E  0f12fc                  movhlps  xmm7, xmm4                     
  0x003618A1  0f2b4c8720              movntps  xmmword ptr [edi + eax*4 + 0x20], xmm1 
  0x003618A6  0f2b5c8730              movntps  xmmword ptr [edi + eax*4 + 0x30], xmm3 
  0x003618AB  0f2b6c8760              movntps  xmmword ptr [edi + eax*4 + 0x60], xmm5 
  0x003618B0  0f2b7c8770              movntps  xmmword ptr [edi + eax*4 + 0x70], xmm7 
  0x003618B5  2bf2                    sub      esi, edx                       
  0x003618B7  2bf2                    sub      esi, edx                       
  0x003618B9  90                      nop                                     
  0x003618BA  90                      nop                                     
  0x003618BB  90                      nop                                     
  0x003618BC  90                      nop                                     
  0x003618BD  90                      nop                                     
  0x003618BE  90                      nop                                     
  0x003618BF  90                      nop                                     
  0x003618C0  90                      nop                                     
  0x003618C1  90                      nop                                     
  0x003618C2  90                      nop                                     
  0x003618C3  90                      nop                                     
  0x003618C4  90                      nop                                     
  0x003618C5  90                      nop                                     
  0x003618C6  90                      nop                                     
  0x003618C7  90                      nop                                     
  0x003618C8  90                      nop                                     
  0x003618C9  90                      nop                                     
  0x003618CA  90                      nop                                     
  0x003618CB  90                      nop                                     
  0x003618CC  90                      nop                                     
  0x003618CD  90                      nop                                     
  0x003618CE  90                      nop                                     
  0x003618CF  90                      nop                                     
  0x003618D0  90                      nop                                     
  0x003618D1  90                      nop                                     
  0x003618D2  90                      nop                                     
  0x003618D3  90                      nop                                     
  0x003618D4  90                      nop                                     
  0x003618D5  2b5df4                  sub      ebx, dword ptr [ebp - 0xc]     
  0x003618D8  83c620                  add      esi, 0x20                      
  0x003618DB  235dfc                  and      ebx, dword ptr [ebp - 4]       
  0x003618DE  0f855fffffff            jne      0x361843                       
  0x003618E4  2b4df8                  sub      ecx, dword ptr [ebp - 8]       
  0x003618E7  8d3496                  lea      esi, [esi + edx*4]             
  0x003618EA  2bf2                    sub      esi, edx                       
  0x003618EC  234d14                  and      ecx, dword ptr [ebp + 0x14]    
  0x003618EF  0f854effffff            jne      0x361843                       
  0x003618F5  5f                      pop      edi                            
  0x003618F6  5e                      pop      esi                            
  0x003618F7  5b                      pop      ebx                            
  0x003618F8  c9                      leave                                   
  0x003618F9  c21000                  ret      0x10                           
; end of function

; ============================================================
; Function: sub_003618FC
; Start: 0x003618FC  End: 0x003619DF  Size: 227 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00361591
; Called by: sub_00362BEE
; ============================================================
sub_003618FC:
  0x003618FC  55                      push     ebp                            
  0x003618FD  8bec                    mov      ebp, esp                       
  0x003618FF  83ec0c                  sub      esp, 0xc                       
  0x00361902  53                      push     ebx                            
  0x00361903  56                      push     esi                            
  0x00361904  57                      push     edi                            
  0x00361905  8d4514                  lea      eax, [ebp + 0x14]              
  0x00361908  50                      push     eax                            
  0x00361909  8d45fc                  lea      eax, [ebp - 4]                 
  0x0036190C  50                      push     eax                            
  0x0036190D  ff7514                  push     dword ptr [ebp + 0x14]         
  0x00361910  ff7510                  push     dword ptr [ebp + 0x10]         
  0x00361913  e879fcffff              call     0x361591                       ; -> sub_00361591
  0x00361918  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x0036191B  2500ffffff              and      eax, 0xffffff00                
  0x00361920  8945f4                  mov      dword ptr [ebp - 0xc], eax     
  0x00361923  8b4514                  mov      eax, dword ptr [ebp + 0x14]    
  0x00361926  83e0e0                  and      eax, 0xffffffe0                
  0x00361929  8945f8                  mov      dword ptr [ebp - 8], eax       
  0x0036192C  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x0036192F  8b7d0c                  mov      edi, dword ptr [ebp + 0xc]     
  0x00361932  8b5510                  mov      edx, dword ptr [ebp + 0x10]    
  0x00361935  33db                    xor      ebx, ebx                       
  0x00361937  33c9                    xor      ecx, ecx                       
                                        ; XREF: 0x003619BF (cond_jump), 0x003619D0 (cond_jump)
  0x00361939  8bc3                    mov      eax, ebx                       
  0x0036193B  2b5df4                  sub      ebx, dword ptr [ebp - 0xc]     
  0x0036193E  0bc1                    or       eax, ecx                       
  0x00361940  0f700406d8              pshufw   mm0, qword ptr [esi + eax], 0xd8 
  0x00361945  0f70540640d8            pshufw   mm2, qword ptr [esi + eax + 0x40], 0xd8 
  0x0036194B  0f70640610d8            pshufw   mm4, qword ptr [esi + eax + 0x10], 0xd8 
  0x00361951  0f70740650d8            pshufw   mm6, qword ptr [esi + eax + 0x50], 0xd8 
  0x00361957  0f7fc1                  movq     mm1, mm0                       
  0x0036195A  0f7fd3                  movq     mm3, mm2                       
  0x0036195D  0f62c4                  punpckldq mm0, mm4                       
  0x00361960  0f6acc                  punpckhdq mm1, mm4                       
  0x00361963  0f62d6                  punpckldq mm2, mm6                       
  0x00361966  0f6ade                  punpckhdq mm3, mm6                       
  0x00361969  0f7f07                  movq     qword ptr [edi], mm0           
  0x0036196C  0f7f5708                movq     qword ptr [edi + 8], mm2       
  0x00361970  0f7f0c17                movq     qword ptr [edi + edx], mm1     
  0x00361974  0f7f5c1708              movq     qword ptr [edi + edx + 8], mm3 
  0x00361979  03fa                    add      edi, edx                       
  0x0036197B  0f70640608d8            pshufw   mm4, qword ptr [esi + eax + 8], 0xd8 
  0x00361981  0f706c0648d8            pshufw   mm5, qword ptr [esi + eax + 0x48], 0xd8 
  0x00361987  0f70740618d8            pshufw   mm6, qword ptr [esi + eax + 0x18], 0xd8 
  0x0036198D  0f707c0658d8            pshufw   mm7, qword ptr [esi + eax + 0x58], 0xd8 
  0x00361993  0f7fe0                  movq     mm0, mm4                       
  0x00361996  0f7fe9                  movq     mm1, mm5                       
  0x00361999  0f62c6                  punpckldq mm0, mm6                       
  0x0036199C  0f6ae6                  punpckhdq mm4, mm6                       
  0x0036199F  0f62cf                  punpckldq mm1, mm7                       
  0x003619A2  0f6aef                  punpckhdq mm5, mm7                       
  0x003619A5  0f7f0417                movq     qword ptr [edi + edx], mm0     
  0x003619A9  0f7f4c1708              movq     qword ptr [edi + edx + 8], mm1 
  0x003619AE  0f7f2457                movq     qword ptr [edi + edx*2], mm4   
  0x003619B2  0f7f6c5708              movq     qword ptr [edi + edx*2 + 8], mm5 
  0x003619B7  2bfa                    sub      edi, edx                       
  0x003619B9  83c710                  add      edi, 0x10                      
  0x003619BC  235dfc                  and      ebx, dword ptr [ebp - 4]       
  0x003619BF  0f8574ffffff            jne      0x361939                       
  0x003619C5  2b4df8                  sub      ecx, dword ptr [ebp - 8]       
  0x003619C8  8d3c97                  lea      edi, [edi + edx*4]             
  0x003619CB  2bfa                    sub      edi, edx                       
  0x003619CD  234d14                  and      ecx, dword ptr [ebp + 0x14]    
  0x003619D0  0f8563ffffff            jne      0x361939                       
  0x003619D6  0f77                    emms                                    
  0x003619D8  5f                      pop      edi                            
  0x003619D9  5e                      pop      esi                            
  0x003619DA  5b                      pop      ebx                            
  0x003619DB  c9                      leave                                   
  0x003619DC  c21000                  ret      0x10                           
; end of function

; ============================================================
; Function: sub_003619DF
; Start: 0x003619DF  End: 0x00361AF1  Size: 274 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00361591
; Called by: sub_00362BEE
; ============================================================
sub_003619DF:
  0x003619DF  55                      push     ebp                            
  0x003619E0  8bec                    mov      ebp, esp                       
  0x003619E2  83ec0c                  sub      esp, 0xc                       
  0x003619E5  53                      push     ebx                            
  0x003619E6  56                      push     esi                            
  0x003619E7  57                      push     edi                            
  0x003619E8  8d4514                  lea      eax, [ebp + 0x14]              
  0x003619EB  50                      push     eax                            
  0x003619EC  8d45fc                  lea      eax, [ebp - 4]                 
  0x003619EF  50                      push     eax                            
  0x003619F0  ff7514                  push     dword ptr [ebp + 0x14]         
  0x003619F3  ff7510                  push     dword ptr [ebp + 0x10]         
  0x003619F6  e896fbffff              call     0x361591                       ; -> sub_00361591
  0x003619FB  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x003619FE  2500ffffff              and      eax, 0xffffff00                
  0x00361A03  8945f4                  mov      dword ptr [ebp - 0xc], eax     
  0x00361A06  8b4514                  mov      eax, dword ptr [ebp + 0x14]    
  0x00361A09  83e0e0                  and      eax, 0xffffffe0                
  0x00361A0C  8945f8                  mov      dword ptr [ebp - 8], eax       
  0x00361A0F  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00361A12  8b7d0c                  mov      edi, dword ptr [ebp + 0xc]     
  0x00361A15  8b5510                  mov      edx, dword ptr [ebp + 0x10]    
  0x00361A18  33db                    xor      ebx, ebx                       
  0x00361A1A  33c9                    xor      ecx, ecx                       
  0x00361A1C  03d2                    add      edx, edx                       
  0x00361A1E  90                      nop                                     
                                        ; XREF: 0x00361AD3 (cond_jump), 0x00361AE4 (cond_jump)
  0x00361A1F  8bc3                    mov      eax, ebx                       
  0x00361A21  2b5df4                  sub      ebx, dword ptr [ebp - 0xc]     
  0x00361A24  0bc1                    or       eax, ecx                       
  0x00361A26  0f280446                movaps   xmm0, xmmword ptr [esi + eax*2] 
  0x00361A2A  0f28644620              movaps   xmm4, xmmword ptr [esi + eax*2 + 0x20] 
  0x00361A2F  0f28944680000000        movaps   xmm2, xmmword ptr [esi + eax*2 + 0x80] 
  0x00361A37  0f28b446a0000000        movaps   xmm6, xmmword ptr [esi + eax*2 + 0xa0] 
  0x00361A3F  0f28c8                  movaps   xmm1, xmm0                     
  0x00361A42  0f28da                  movaps   xmm3, xmm2                     
  0x00361A45  0fc6c488                shufps   xmm0, xmm4, 0x88               
  0x00361A49  0fc6ccdd                shufps   xmm1, xmm4, 0xdd               
  0x00361A4D  0fc6d688                shufps   xmm2, xmm6, 0x88               
  0x00361A51  0fc6dedd                shufps   xmm3, xmm6, 0xdd               
  0x00361A55  0f28644610              movaps   xmm4, xmmword ptr [esi + eax*2 + 0x10] 
  0x00361A5A  0f28744630              movaps   xmm6, xmmword ptr [esi + eax*2 + 0x30] 
  0x00361A5F  0f28ac4690000000        movaps   xmm5, xmmword ptr [esi + eax*2 + 0x90] 
  0x00361A67  0f28bc46b0000000        movaps   xmm7, xmmword ptr [esi + eax*2 + 0xb0] 
  0x00361A6F  0f2b07                  movntps  xmmword ptr [edi], xmm0        
  0x00361A72  0f2b5710                movntps  xmmword ptr [edi + 0x10], xmm2 
  0x00361A76  0f2b0c17                movntps  xmmword ptr [edi + edx], xmm1  
  0x00361A7A  0f2b5c1710              movntps  xmmword ptr [edi + edx + 0x10], xmm3 
  0x00361A7F  03fa                    add      edi, edx                       
  0x00361A81  0f28c4                  movaps   xmm0, xmm4                     
  0x00361A84  0f28cd                  movaps   xmm1, xmm5                     
  0x00361A87  0fc6c688                shufps   xmm0, xmm6, 0x88               
  0x00361A8B  0fc6e6dd                shufps   xmm4, xmm6, 0xdd               
  0x00361A8F  0fc6cf88                shufps   xmm1, xmm7, 0x88               
  0x00361A93  0fc6efdd                shufps   xmm5, xmm7, 0xdd               
  0x00361A97  0f2b0417                movntps  xmmword ptr [edi + edx], xmm0  
  0x00361A9B  0f2b4c1710              movntps  xmmword ptr [edi + edx + 0x10], xmm1 
  0x00361AA0  0f2b2457                movntps  xmmword ptr [edi + edx*2], xmm4 
  0x00361AA4  0f2b6c5710              movntps  xmmword ptr [edi + edx*2 + 0x10], xmm5 
  0x00361AA9  90                      nop                                     
  0x00361AAA  90                      nop                                     
  0x00361AAB  90                      nop                                     
  0x00361AAC  90                      nop                                     
  0x00361AAD  90                      nop                                     
  0x00361AAE  90                      nop                                     
  0x00361AAF  90                      nop                                     
  0x00361AB0  90                      nop                                     
  0x00361AB1  90                      nop                                     
  0x00361AB2  90                      nop                                     
  0x00361AB3  90                      nop                                     
  0x00361AB4  90                      nop                                     
  0x00361AB5  90                      nop                                     
  0x00361AB6  90                      nop                                     
  0x00361AB7  90                      nop                                     
  0x00361AB8  90                      nop                                     
  0x00361AB9  90                      nop                                     
  0x00361ABA  90                      nop                                     
  0x00361ABB  90                      nop                                     
  0x00361ABC  90                      nop                                     
  0x00361ABD  90                      nop                                     
  0x00361ABE  90                      nop                                     
  0x00361ABF  90                      nop                                     
  0x00361AC0  90                      nop                                     
  0x00361AC1  90                      nop                                     
  0x00361AC2  90                      nop                                     
  0x00361AC3  90                      nop                                     
  0x00361AC4  90                      nop                                     
  0x00361AC5  90                      nop                                     
  0x00361AC6  90                      nop                                     
  0x00361AC7  90                      nop                                     
  0x00361AC8  90                      nop                                     
  0x00361AC9  90                      nop                                     
  0x00361ACA  90                      nop                                     
  0x00361ACB  2bfa                    sub      edi, edx                       
  0x00361ACD  83c720                  add      edi, 0x20                      
  0x00361AD0  235dfc                  and      ebx, dword ptr [ebp - 4]       
  0x00361AD3  0f8546ffffff            jne      0x361a1f                       
  0x00361AD9  2b4df8                  sub      ecx, dword ptr [ebp - 8]       
  0x00361ADC  8d3c97                  lea      edi, [edi + edx*4]             
  0x00361ADF  2bfa                    sub      edi, edx                       
  0x00361AE1  234d14                  and      ecx, dword ptr [ebp + 0x14]    
  0x00361AE4  0f8535ffffff            jne      0x361a1f                       
  0x00361AEA  5f                      pop      edi                            
  0x00361AEB  5e                      pop      esi                            
  0x00361AEC  5b                      pop      ebx                            
  0x00361AED  c9                      leave                                   
  0x00361AEE  c21000                  ret      0x10                           
; end of function

; ============================================================
; Function: sub_00361AF1
; Start: 0x00361AF1  End: 0x00361BE7  Size: 246 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00361591
; Called by: sub_00362BEE
; ============================================================
sub_00361AF1:
  0x00361AF1  55                      push     ebp                            
  0x00361AF2  8bec                    mov      ebp, esp                       
  0x00361AF4  83ec0c                  sub      esp, 0xc                       
  0x00361AF7  53                      push     ebx                            
  0x00361AF8  56                      push     esi                            
  0x00361AF9  57                      push     edi                            
  0x00361AFA  8d4514                  lea      eax, [ebp + 0x14]              
  0x00361AFD  50                      push     eax                            
  0x00361AFE  8d45fc                  lea      eax, [ebp - 4]                 
  0x00361B01  50                      push     eax                            
  0x00361B02  ff7514                  push     dword ptr [ebp + 0x14]         
  0x00361B05  ff7510                  push     dword ptr [ebp + 0x10]         
  0x00361B08  e884faffff              call     0x361591                       ; -> sub_00361591
  0x00361B0D  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x00361B10  83e0c0                  and      eax, 0xffffffc0                
  0x00361B13  8945f4                  mov      dword ptr [ebp - 0xc], eax     
  0x00361B16  8b4514                  mov      eax, dword ptr [ebp + 0x14]    
  0x00361B19  83e0e0                  and      eax, 0xffffffe0                
  0x00361B1C  8945f8                  mov      dword ptr [ebp - 8], eax       
  0x00361B1F  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00361B22  8b7d0c                  mov      edi, dword ptr [ebp + 0xc]     
  0x00361B25  8b5510                  mov      edx, dword ptr [ebp + 0x10]    
  0x00361B28  33db                    xor      ebx, ebx                       
  0x00361B2A  33c9                    xor      ecx, ecx                       
  0x00361B2C  c1e202                  shl      edx, 2                         
                                        ; XREF: 0x00361BC9 (cond_jump), 0x00361BDA (cond_jump)
  0x00361B2F  8bc3                    mov      eax, ebx                       
  0x00361B31  0bc1                    or       eax, ecx                       
  0x00361B33  2b5df4                  sub      ebx, dword ptr [ebp - 0xc]     
  0x00361B36  0f280486                movaps   xmm0, xmmword ptr [esi + eax*4] 
  0x00361B3A  0f28548610              movaps   xmm2, xmmword ptr [esi + eax*4 + 0x10] 
  0x00361B3F  0f28648640              movaps   xmm4, xmmword ptr [esi + eax*4 + 0x40] 
  0x00361B44  0f28748650              movaps   xmm6, xmmword ptr [esi + eax*4 + 0x50] 
  0x00361B49  0f28c8                  movaps   xmm1, xmm0                     
  0x00361B4C  0f28ec                  movaps   xmm5, xmm4                     
  0x00361B4F  0f16c2                  movlhps  xmm0, xmm2                     
  0x00361B52  0f12d1                  movhlps  xmm2, xmm1                     
  0x00361B55  0f16e6                  movlhps  xmm4, xmm6                     
  0x00361B58  0f12f5                  movhlps  xmm6, xmm5                     
  0x00361B5B  0f284c8620              movaps   xmm1, xmmword ptr [esi + eax*4 + 0x20] 
  0x00361B60  0f285c8630              movaps   xmm3, xmmword ptr [esi + eax*4 + 0x30] 
  0x00361B65  0f286c8660              movaps   xmm5, xmmword ptr [esi + eax*4 + 0x60] 
  0x00361B6A  0f287c8670              movaps   xmm7, xmmword ptr [esi + eax*4 + 0x70] 
  0x00361B6F  0f2b07                  movntps  xmmword ptr [edi], xmm0        
  0x00361B72  0f2b6710                movntps  xmmword ptr [edi + 0x10], xmm4 
  0x00361B76  0f2b1417                movntps  xmmword ptr [edi + edx], xmm2  
  0x00361B7A  0f2b741710              movntps  xmmword ptr [edi + edx + 0x10], xmm6 
  0x00361B7F  03fa                    add      edi, edx                       
  0x00361B81  0f28c1                  movaps   xmm0, xmm1                     
  0x00361B84  0f28e5                  movaps   xmm4, xmm5                     
  0x00361B87  0f16cb                  movlhps  xmm1, xmm3                     
  0x00361B8A  0f12d8                  movhlps  xmm3, xmm0                     
  0x00361B8D  0f16ef                  movlhps  xmm5, xmm7                     
  0x00361B90  0f12fc                  movhlps  xmm7, xmm4                     
  0x00361B93  0f2b0c17                movntps  xmmword ptr [edi + edx], xmm1  
  0x00361B97  0f2b6c1710              movntps  xmmword ptr [edi + edx + 0x10], xmm5 
  0x00361B9C  0f2b1c57                movntps  xmmword ptr [edi + edx*2], xmm3 
  0x00361BA0  0f2b7c5710              movntps  xmmword ptr [edi + edx*2 + 0x10], xmm7 
  0x00361BA5  2bfa                    sub      edi, edx                       
  0x00361BA7  90                      nop                                     
  0x00361BA8  90                      nop                                     
  0x00361BA9  90                      nop                                     
  0x00361BAA  90                      nop                                     
  0x00361BAB  90                      nop                                     
  0x00361BAC  90                      nop                                     
  0x00361BAD  90                      nop                                     
  0x00361BAE  90                      nop                                     
  0x00361BAF  90                      nop                                     
  0x00361BB0  90                      nop                                     
  0x00361BB1  90                      nop                                     
  0x00361BB2  90                      nop                                     
  0x00361BB3  90                      nop                                     
  0x00361BB4  90                      nop                                     
  0x00361BB5  90                      nop                                     
  0x00361BB6  90                      nop                                     
  0x00361BB7  90                      nop                                     
  0x00361BB8  90                      nop                                     
  0x00361BB9  90                      nop                                     
  0x00361BBA  90                      nop                                     
  0x00361BBB  90                      nop                                     
  0x00361BBC  90                      nop                                     
  0x00361BBD  90                      nop                                     
  0x00361BBE  90                      nop                                     
  0x00361BBF  90                      nop                                     
  0x00361BC0  90                      nop                                     
  0x00361BC1  90                      nop                                     
  0x00361BC2  90                      nop                                     
  0x00361BC3  83c720                  add      edi, 0x20                      
  0x00361BC6  235dfc                  and      ebx, dword ptr [ebp - 4]       
  0x00361BC9  0f8560ffffff            jne      0x361b2f                       
  0x00361BCF  2b4df8                  sub      ecx, dword ptr [ebp - 8]       
  0x00361BD2  8d3c97                  lea      edi, [edi + edx*4]             
  0x00361BD5  2bfa                    sub      edi, edx                       
  0x00361BD7  234d14                  and      ecx, dword ptr [ebp + 0x14]    
  0x00361BDA  0f854fffffff            jne      0x361b2f                       
  0x00361BE0  5f                      pop      edi                            
  0x00361BE1  5e                      pop      esi                            
  0x00361BE2  5b                      pop      ebx                            
  0x00361BE3  c9                      leave                                   
  0x00361BE4  c21000                  ret      0x10                           
; end of function

; ============================================================
; Function: sub_00361BE7
; Start: 0x00361BE7  End: 0x00361C2B  Size: 68 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_0006AFC0, sub_000AF5B0, sub_00274D70
; ============================================================
sub_00361BE7:
  0x00361BE7  8b442404                mov      eax, dword ptr [esp + 4]       
  0x00361BEB  83f82d                  cmp      eax, 0x2d                      
  0x00361BEE  7f22                    jg       0x361c12                       
  0x00361BF0  83f827                  cmp      eax, 0x27                      
  0x00361BF3  7d31                    jge      0x361c26                       
  0x00361BF5  85c0                    test     eax, eax                       
  0x00361BF7  7c14                    jl       0x361c0d                       
  0x00361BF9  83f807                  cmp      eax, 7                         
  0x00361BFC  7e28                    jle      0x361c26                       
  0x00361BFE  83f80b                  cmp      eax, 0xb                       
  0x00361C01  7423                    je       0x361c26                       
  0x00361C03  83f818                  cmp      eax, 0x18                      
  0x00361C06  7e05                    jle      0x361c0d                       
  0x00361C08  83f81a                  cmp      eax, 0x1a                      
  0x00361C0B  7e19                    jle      0x361c26                       
                                        ; XREF: 0x00361BF7 (cond_jump), 0x00361C06 (cond_jump), 0x00361C15 (cond_jump), 0x00361C1F (cond_jump), 0x00361C24 (cond_jump)
  0x00361C0D  33c0                    xor      eax, eax                       
                                        ; XREF: 0x00361C29 (jump)
  0x00361C0F  c20400                  ret      4                              
                                        ; XREF: 0x00361BEE (cond_jump)
  0x00361C12  83f832                  cmp      eax, 0x32                      
  0x00361C15  7cf6                    jl       0x361c0d                       
  0x00361C17  83f833                  cmp      eax, 0x33                      
  0x00361C1A  7e0a                    jle      0x361c26                       
  0x00361C1C  83f837                  cmp      eax, 0x37                      
  0x00361C1F  7eec                    jle      0x361c0d                       
  0x00361C21  83f83c                  cmp      eax, 0x3c                      
  0x00361C24  7fe7                    jg       0x361c0d                       
                                        ; XREF: 0x00361BF3 (cond_jump), 0x00361BFC (cond_jump), 0x00361C01 (cond_jump), 0x00361C0B (cond_jump), 0x00361C1A (cond_jump)
  0x00361C26  33c0                    xor      eax, eax                       
  0x00361C28  40                      inc      eax                            
  0x00361C29  ebe4                    jmp      0x361c0f                       
; end of function

; ============================================================
; Function: sub_00361C2B
; Start: 0x00361C2B  End: 0x00361C50  Size: 37 bytes
; Detection: call_target (confidence: 0.90)
; ============================================================
sub_00361C2B:
  0x00361C2B  8b442404                mov      eax, dword ptr [esp + 4]       
  0x00361C2F  83f841                  cmp      eax, 0x41                      
  0x00361C32  771c                    ja       0x361c50                       
  0x00361C34  0fb680651c3600          movzx    eax, byte ptr [eax + 0x361c65] 
  0x00361C3B  ff2485551c3600          jmp      dword ptr [eax*4 + 0x361c55]   
  0x00361C42  6a04                    push     4                              
  0x00361C44  eb02                    jmp      0x361c48                       
  0x00361C46  6a02                    push     2                              
                                        ; XREF: 0x00361C44 (jump)
  0x00361C48  58                      pop      eax                            
  0x00361C49  eb07                    jmp      0x361c52                       
  0x00361C4B  33c0                    xor      eax, eax                       
  0x00361C4D  40                      inc      eax                            
  0x00361C4E  eb02                    jmp      0x361c52                       
; end of function
                                        ; XREF: 0x00361C32 (cond_jump)
  0x00361C50  33c0                    xor      eax, eax                       
                                        ; XREF: 0x00361C49 (jump), 0x00361C4E (jump)
  0x00361C52  c20400                  ret      4                              
  0x00361C55  4b                      dec      ebx                            
  0x00361C56  1c36                    sbb      al, 0x36                       
  0x00361C58  00461c                  add      byte ptr [esi + 0x1c], al      
  0x00361C5B  3600421c                add      byte ptr ss:[edx + 0x1c], al   
  0x00361C5F  3600501c                add      byte ptr ss:[eax + 0x1c], dl   
  0x00361C63  360000                  add      byte ptr ss:[eax], al          
  0x00361C66  0001                    add      byte ptr [ecx], al             
  0x00361C68  0101                    add      dword ptr [ecx], eax           
  0x00361C6A  0102                    add      dword ptr [edx], eax           
  0x00361C6C  0203                    add      al, byte ptr [ebx]             
  0x00361C6E  0303                    add      eax, dword ptr [ebx]           
  0x00361C70  0003                    add      byte ptr [ebx], al             
  0x00361C72  0300                    add      eax, dword ptr [eax]           
  0x00361C74  0001                    add      byte ptr [ecx], al             
  0x00361C76  0102                    add      dword ptr [edx], eax           
  0x00361C78  0003                    add      byte ptr [ebx], al             
  0x00361C7A  0301                    add      eax, dword ptr [ecx]           
  0x00361C7C  0103                    add      dword ptr [ebx], eax           
  0x00361C7E  0001                    add      byte ptr [ecx], al             
  0x00361C80  0001                    add      byte ptr [ecx], al             
  0x00361C82  0102                    add      dword ptr [edx], eax           
  0x00361C84  0001                    add      byte ptr [ecx], al             
  0x00361C86  0303                    add      eax, dword ptr [ebx]           
  0x00361C88  0302                    add      eax, dword ptr [edx]           
  0x00361C8A  0203                    add      al, byte ptr [ebx]             
  0x00361C8C  0101                    add      dword ptr [ecx], eax           
  0x00361C8E  0102                    add      dword ptr [edx], eax           
  0x00361C90  0201                    add      al, byte ptr [ecx]             
  0x00361C92  0102                    add      dword ptr [edx], eax           
  0x00361C94  0201                    add      al, byte ptr [ecx]             
  0x00361C96  0101                    add      dword ptr [ecx], eax           
  0x00361C98  0203                    add      al, byte ptr [ebx]             
  0x00361C9A  0103                    add      dword ptr [ebx], eax           
  0x00361C9C  0101                    add      dword ptr [ecx], eax           
  0x00361C9E  0102                    add      dword ptr [edx], eax           
  0x00361CA0  0202                    add      al, byte ptr [edx]             
  0x00361CA2  0101                    add      dword ptr [ecx], eax           
  0x00361CA4  0202                    add      al, byte ptr [edx]             
  0x00361CA6  02558b                  add      dl, byte ptr [ebp - 0x75]      
  0x00361CA9  ec                      in       al, dx                         
  0x00361CAA  53                      push     ebx                            
  0x00361CAB  56                      push     esi                            
  0x00361CAC  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00361CAF  8b5e2c                  mov      ebx, dword ptr [esi + 0x2c]    
  0x00361CB2  8b4628                  mov      eax, dword ptr [esi + 0x28]    
  0x00361CB5  57                      push     edi                            
  0x00361CB6  03c3                    add      eax, ebx                       
  0x00361CB8  8d7e40                  lea      edi, [esi + 0x40]              
  0x00361CBB  50                      push     eax                            
  0x00361CBC  8bcf                    mov      ecx, edi                       
  0x00361CBE  e87cf8ffff              call     0x36153f                       ; -> sub_0036153F
  0x00361CC3  8b4e24                  mov      ecx, dword ptr [esi + 0x24]    
  0x00361CC6  894508                  mov      dword ptr [ebp + 8], eax       
  0x00361CC9  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x00361CCC  03c8                    add      ecx, eax                       
  0x00361CCE  51                      push     ecx                            
  0x00361CCF  8bcf                    mov      ecx, edi                       
  0x00361CD1  e892f8ffff              call     0x361568                       ; -> sub_00361568
  0x00361CD6  8b4e08                  mov      ecx, dword ptr [esi + 8]       
  0x00361CD9  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x00361CDC  83665800                and      dword ptr [esi + 0x58], 0      
  0x00361CE0  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x00361CE3  8b460c                  mov      eax, dword ptr [esi + 0xc]     
  0x00361CE6  034630                  add      eax, dword ptr [esi + 0x30]    
  0x00361CE9  03cb                    add      ecx, ebx                       
  0x00361CEB  0faf4604                imul     eax, dword ptr [esi + 4]       
  0x00361CEF  8d0488                  lea      eax, [eax + ecx*4]             
  0x00361CF2  8b4e18                  mov      ecx, dword ptr [esi + 0x18]    
  0x00361CF5  0306                    add      eax, dword ptr [esi]           
  0x00361CF7  8d0c91                  lea      ecx, [ecx + edx*4]             
  0x00361CFA  8b5638                  mov      edx, dword ptr [esi + 0x38]    
  0x00361CFD  85d2                    test     edx, edx                       
  0x00361CFF  7420                    je       0x361d21                       
  0x00361D01  895508                  mov      dword ptr [ebp + 8], edx       
                                        ; XREF: 0x00361D1F (cond_jump)
  0x00361D04  8b18                    mov      ebx, dword ptr [eax]           
  0x00361D06  8b565c                  mov      edx, dword ptr [esi + 0x5c]    
  0x00361D09  891c91                  mov      dword ptr [ecx + edx*4], ebx   
  0x00361D0C  8b5710                  mov      edx, dword ptr [edi + 0x10]    
  0x00361D0F  8b5f1c                  mov      ebx, dword ptr [edi + 0x1c]    
  0x00361D12  2bda                    sub      ebx, edx                       
  0x00361D14  23da                    and      ebx, edx                       
  0x00361D16  895f1c                  mov      dword ptr [edi + 0x1c], ebx    
  0x00361D19  034604                  add      eax, dword ptr [esi + 4]       
  0x00361D1C  ff4d08                  dec      dword ptr [ebp + 8]            
  0x00361D1F  75e3                    jne      0x361d04                       
                                        ; XREF: 0x00361CFF (cond_jump)
  0x00361D21  5f                      pop      edi                            
  0x00361D22  5e                      pop      esi                            
  0x00361D23  5b                      pop      ebx                            
  0x00361D24  5d                      pop      ebp                            
  0x00361D25  c20400                  ret      4                              

; ============================================================
; Function: sub_00361D28
; Start: 0x00361D28  End: 0x00361DA9  Size: 129 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_0036153F, sub_00361568
; Called by: sub_00362BEE
; ============================================================
sub_00361D28:
  0x00361D28  55                      push     ebp                            
  0x00361D29  8bec                    mov      ebp, esp                       
  0x00361D2B  53                      push     ebx                            
  0x00361D2C  56                      push     esi                            
  0x00361D2D  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00361D30  8b5e2c                  mov      ebx, dword ptr [esi + 0x2c]    
  0x00361D33  8b4608                  mov      eax, dword ptr [esi + 8]       
  0x00361D36  57                      push     edi                            
  0x00361D37  03c3                    add      eax, ebx                       
  0x00361D39  8d7e40                  lea      edi, [esi + 0x40]              
  0x00361D3C  50                      push     eax                            
  0x00361D3D  8bcf                    mov      ecx, edi                       
  0x00361D3F  e8fbf7ffff              call     0x36153f                       ; -> sub_0036153F
  0x00361D44  8b4e0c                  mov      ecx, dword ptr [esi + 0xc]     
  0x00361D47  894508                  mov      dword ptr [ebp + 8], eax       
  0x00361D4A  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x00361D4D  03c8                    add      ecx, eax                       
  0x00361D4F  51                      push     ecx                            
  0x00361D50  8bcf                    mov      ecx, edi                       
  0x00361D52  e811f8ffff              call     0x361568                       ; -> sub_00361568
  0x00361D57  8b4d08                  mov      ecx, dword ptr [ebp + 8]       
  0x00361D5A  8b5628                  mov      edx, dword ptr [esi + 0x28]    
  0x00361D5D  83665800                and      dword ptr [esi + 0x58], 0      
  0x00361D61  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x00361D64  8b06                    mov      eax, dword ptr [esi]           
  0x00361D66  8d0c88                  lea      ecx, [eax + ecx*4]             
  0x00361D69  8b4624                  mov      eax, dword ptr [esi + 0x24]    
  0x00361D6C  034630                  add      eax, dword ptr [esi + 0x30]    
  0x00361D6F  03d3                    add      edx, ebx                       
  0x00361D71  0faf4604                imul     eax, dword ptr [esi + 4]       
  0x00361D75  8d0490                  lea      eax, [eax + edx*4]             
  0x00361D78  8b5638                  mov      edx, dword ptr [esi + 0x38]    
  0x00361D7B  034618                  add      eax, dword ptr [esi + 0x18]    
  0x00361D7E  85d2                    test     edx, edx                       
  0x00361D80  7420                    je       0x361da2                       
  0x00361D82  895508                  mov      dword ptr [ebp + 8], edx       
                                        ; XREF: 0x00361DA0 (cond_jump)
  0x00361D85  8b565c                  mov      edx, dword ptr [esi + 0x5c]    
  0x00361D88  8b1491                  mov      edx, dword ptr [ecx + edx*4]   
  0x00361D8B  8910                    mov      dword ptr [eax], edx           
  0x00361D8D  8b5710                  mov      edx, dword ptr [edi + 0x10]    
  0x00361D90  8b5f1c                  mov      ebx, dword ptr [edi + 0x1c]    
  0x00361D93  2bda                    sub      ebx, edx                       
  0x00361D95  23da                    and      ebx, edx                       
  0x00361D97  895f1c                  mov      dword ptr [edi + 0x1c], ebx    
  0x00361D9A  034604                  add      eax, dword ptr [esi + 4]       
  0x00361D9D  ff4d08                  dec      dword ptr [ebp + 8]            
  0x00361DA0  75e3                    jne      0x361d85                       
                                        ; XREF: 0x00361D80 (cond_jump)
  0x00361DA2  5f                      pop      edi                            
  0x00361DA3  5e                      pop      esi                            
  0x00361DA4  5b                      pop      ebx                            
  0x00361DA5  5d                      pop      ebp                            
  0x00361DA6  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00361DA9
; Start: 0x00361DA9  End: 0x00361E7D  Size: 212 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_0036153F, sub_00361568
; Called by: sub_0036249D
; ============================================================
sub_00361DA9:
  0x00361DA9  55                      push     ebp                            
  0x00361DAA  8bec                    mov      ebp, esp                       
  0x00361DAC  51                      push     ecx                            
  0x00361DAD  51                      push     ecx                            
  0x00361DAE  53                      push     ebx                            
  0x00361DAF  56                      push     esi                            
  0x00361DB0  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00361DB3  8b462c                  mov      eax, dword ptr [esi + 0x2c]    
  0x00361DB6  8b5628                  mov      edx, dword ptr [esi + 0x28]    
  0x00361DB9  8b5e50                  mov      ebx, dword ptr [esi + 0x50]    
  0x00361DBC  57                      push     edi                            
  0x00361DBD  8b7e4c                  mov      edi, dword ptr [esi + 0x4c]    
  0x00361DC0  03d0                    add      edx, eax                       
  0x00361DC2  8d4e40                  lea      ecx, [esi + 0x40]              
  0x00361DC5  52                      push     edx                            
  0x00361DC6  897e64                  mov      dword ptr [esi + 0x64], edi    
  0x00361DC9  895e68                  mov      dword ptr [esi + 0x68], ebx    
  0x00361DCC  e86ef7ffff              call     0x36153f                       ; -> sub_0036153F
  0x00361DD1  8b4e24                  mov      ecx, dword ptr [esi + 0x24]    
  0x00361DD4  894508                  mov      dword ptr [ebp + 8], eax       
  0x00361DD7  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x00361DDA  03c8                    add      ecx, eax                       
  0x00361DDC  51                      push     ecx                            
  0x00361DDD  8d4e40                  lea      ecx, [esi + 0x40]              
  0x00361DE0  e883f7ffff              call     0x361568                       ; -> sub_00361568
  0x00361DE5  8b5634                  mov      edx, dword ptr [esi + 0x34]    
  0x00361DE8  8b4e04                  mov      ecx, dword ptr [esi + 4]       
  0x00361DEB  d16d08                  shr      dword ptr [ebp + 8], 1         
  0x00361DEE  d1ef                    shr      edi, 1                         
  0x00361DF0  897e4c                  mov      dword ptr [esi + 0x4c], edi    
  0x00361DF3  d1e2                    shl      edx, 1                         
  0x00361DF5  8bfa                    mov      edi, edx                       
  0x00361DF7  8bd1                    mov      edx, ecx                       
  0x00361DF9  2bd7                    sub      edx, edi                       
  0x00361DFB  8b7e0c                  mov      edi, dword ptr [esi + 0xc]     
  0x00361DFE  037e30                  add      edi, dword ptr [esi + 0x30]    
  0x00361E01  d1e8                    shr      eax, 1                         
  0x00361E03  0faff9                  imul     edi, ecx                       
  0x00361E06  8b4e08                  mov      ecx, dword ptr [esi + 8]       
  0x00361E09  034e2c                  add      ecx, dword ptr [esi + 0x2c]    
  0x00361E0C  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x00361E0F  8b4638                  mov      eax, dword ptr [esi + 0x38]    
  0x00361E12  8d0c4f                  lea      ecx, [edi + ecx*2]             
  0x00361E15  030e                    add      ecx, dword ptr [esi]           
  0x00361E17  8b7e18                  mov      edi, dword ptr [esi + 0x18]    
  0x00361E1A  d1eb                    shr      ebx, 1                         
  0x00361E1C  85c0                    test     eax, eax                       
  0x00361E1E  895e50                  mov      dword ptr [esi + 0x50], ebx    
  0x00361E21  7447                    je       0x361e6a                       
  0x00361E23  8945f8                  mov      dword ptr [ebp - 8], eax       
                                        ; XREF: 0x00361E68 (cond_jump)
  0x00361E26  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x00361E29  894658                  mov      dword ptr [esi + 0x58], eax    
  0x00361E2C  8b4634                  mov      eax, dword ptr [esi + 0x34]    
  0x00361E2F  d1f8                    sar      eax, 1                         
  0x00361E31  7423                    je       0x361e56                       
  0x00361E33  8945fc                  mov      dword ptr [ebp - 4], eax       
                                        ; XREF: 0x00361E54 (cond_jump)
  0x00361E36  8b465c                  mov      eax, dword ptr [esi + 0x5c]    
  0x00361E39  0b4658                  or       eax, dword ptr [esi + 0x58]    
  0x00361E3C  8b19                    mov      ebx, dword ptr [ecx]           
  0x00361E3E  891c87                  mov      dword ptr [edi + eax*4], ebx   
  0x00361E41  8b464c                  mov      eax, dword ptr [esi + 0x4c]    
  0x00361E44  8b5e58                  mov      ebx, dword ptr [esi + 0x58]    
  0x00361E47  2bd8                    sub      ebx, eax                       
  0x00361E49  23d8                    and      ebx, eax                       
  0x00361E4B  83c104                  add      ecx, 4                         
  0x00361E4E  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00361E51  895e58                  mov      dword ptr [esi + 0x58], ebx    
  0x00361E54  75e0                    jne      0x361e36                       
                                        ; XREF: 0x00361E31 (cond_jump)
  0x00361E56  8b4650                  mov      eax, dword ptr [esi + 0x50]    
  0x00361E59  8b5e5c                  mov      ebx, dword ptr [esi + 0x5c]    
  0x00361E5C  2bd8                    sub      ebx, eax                       
  0x00361E5E  23d8                    and      ebx, eax                       
  0x00361E60  03ca                    add      ecx, edx                       
  0x00361E62  ff4df8                  dec      dword ptr [ebp - 8]            
  0x00361E65  895e5c                  mov      dword ptr [esi + 0x5c], ebx    
  0x00361E68  75bc                    jne      0x361e26                       
                                        ; XREF: 0x00361E21 (cond_jump)
  0x00361E6A  8b4664                  mov      eax, dword ptr [esi + 0x64]    
  0x00361E6D  89464c                  mov      dword ptr [esi + 0x4c], eax    
  0x00361E70  8b4668                  mov      eax, dword ptr [esi + 0x68]    
  0x00361E73  5f                      pop      edi                            
  0x00361E74  894650                  mov      dword ptr [esi + 0x50], eax    
  0x00361E77  5e                      pop      esi                            
  0x00361E78  5b                      pop      ebx                            
  0x00361E79  c9                      leave                                   
  0x00361E7A  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00361E7D
; Start: 0x00361E7D  End: 0x00361F51  Size: 212 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_0036153F, sub_00361568
; Called by: sub_00362BEE
; ============================================================
sub_00361E7D:
  0x00361E7D  55                      push     ebp                            
  0x00361E7E  8bec                    mov      ebp, esp                       
  0x00361E80  51                      push     ecx                            
  0x00361E81  51                      push     ecx                            
  0x00361E82  53                      push     ebx                            
  0x00361E83  56                      push     esi                            
  0x00361E84  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00361E87  8b462c                  mov      eax, dword ptr [esi + 0x2c]    
  0x00361E8A  8b5608                  mov      edx, dword ptr [esi + 8]       
  0x00361E8D  8b5e50                  mov      ebx, dword ptr [esi + 0x50]    
  0x00361E90  57                      push     edi                            
  0x00361E91  8b7e4c                  mov      edi, dword ptr [esi + 0x4c]    
  0x00361E94  03d0                    add      edx, eax                       
  0x00361E96  8d4e40                  lea      ecx, [esi + 0x40]              
  0x00361E99  52                      push     edx                            
  0x00361E9A  897e64                  mov      dword ptr [esi + 0x64], edi    
  0x00361E9D  895e68                  mov      dword ptr [esi + 0x68], ebx    
  0x00361EA0  e89af6ffff              call     0x36153f                       ; -> sub_0036153F
  0x00361EA5  8b4e0c                  mov      ecx, dword ptr [esi + 0xc]     
  0x00361EA8  894508                  mov      dword ptr [ebp + 8], eax       
  0x00361EAB  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x00361EAE  03c8                    add      ecx, eax                       
  0x00361EB0  51                      push     ecx                            
  0x00361EB1  8d4e40                  lea      ecx, [esi + 0x40]              
  0x00361EB4  e8aff6ffff              call     0x361568                       ; -> sub_00361568
  0x00361EB9  8b4e04                  mov      ecx, dword ptr [esi + 4]       
  0x00361EBC  8b5634                  mov      edx, dword ptr [esi + 0x34]    
  0x00361EBF  d16d08                  shr      dword ptr [ebp + 8], 1         
  0x00361EC2  d1eb                    shr      ebx, 1                         
  0x00361EC4  895e50                  mov      dword ptr [esi + 0x50], ebx    
  0x00361EC7  8b5e24                  mov      ebx, dword ptr [esi + 0x24]    
  0x00361ECA  035e30                  add      ebx, dword ptr [esi + 0x30]    
  0x00361ECD  d1ef                    shr      edi, 1                         
  0x00361ECF  0fafd9                  imul     ebx, ecx                       
  0x00361ED2  d1e2                    shl      edx, 1                         
  0x00361ED4  897e4c                  mov      dword ptr [esi + 0x4c], edi    
  0x00361ED7  8bfa                    mov      edi, edx                       
  0x00361ED9  8bd1                    mov      edx, ecx                       
  0x00361EDB  8b4e28                  mov      ecx, dword ptr [esi + 0x28]    
  0x00361EDE  034e2c                  add      ecx, dword ptr [esi + 0x2c]    
  0x00361EE1  d1e8                    shr      eax, 1                         
  0x00361EE3  8d0c4b                  lea      ecx, [ebx + ecx*2]             
  0x00361EE6  034e18                  add      ecx, dword ptr [esi + 0x18]    
  0x00361EE9  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x00361EEC  8b4638                  mov      eax, dword ptr [esi + 0x38]    
  0x00361EEF  2bd7                    sub      edx, edi                       
  0x00361EF1  85c0                    test     eax, eax                       
  0x00361EF3  8b3e                    mov      edi, dword ptr [esi]           
  0x00361EF5  7447                    je       0x361f3e                       
  0x00361EF7  8945f8                  mov      dword ptr [ebp - 8], eax       
                                        ; XREF: 0x00361F3C (cond_jump)
  0x00361EFA  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x00361EFD  894658                  mov      dword ptr [esi + 0x58], eax    
  0x00361F00  8b4634                  mov      eax, dword ptr [esi + 0x34]    
  0x00361F03  d1f8                    sar      eax, 1                         
  0x00361F05  7423                    je       0x361f2a                       
  0x00361F07  8945fc                  mov      dword ptr [ebp - 4], eax       
                                        ; XREF: 0x00361F28 (cond_jump)
  0x00361F0A  8b465c                  mov      eax, dword ptr [esi + 0x5c]    
  0x00361F0D  0b4658                  or       eax, dword ptr [esi + 0x58]    
  0x00361F10  8b0487                  mov      eax, dword ptr [edi + eax*4]   
  0x00361F13  8901                    mov      dword ptr [ecx], eax           
  0x00361F15  8b464c                  mov      eax, dword ptr [esi + 0x4c]    
  0x00361F18  8b5e58                  mov      ebx, dword ptr [esi + 0x58]    
  0x00361F1B  2bd8                    sub      ebx, eax                       
  0x00361F1D  23d8                    and      ebx, eax                       
  0x00361F1F  83c104                  add      ecx, 4                         
  0x00361F22  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00361F25  895e58                  mov      dword ptr [esi + 0x58], ebx    
  0x00361F28  75e0                    jne      0x361f0a                       
                                        ; XREF: 0x00361F05 (cond_jump)
  0x00361F2A  8b4650                  mov      eax, dword ptr [esi + 0x50]    
  0x00361F2D  8b5e5c                  mov      ebx, dword ptr [esi + 0x5c]    
  0x00361F30  2bd8                    sub      ebx, eax                       
  0x00361F32  23d8                    and      ebx, eax                       
  0x00361F34  03ca                    add      ecx, edx                       
  0x00361F36  ff4df8                  dec      dword ptr [ebp - 8]            
  0x00361F39  895e5c                  mov      dword ptr [esi + 0x5c], ebx    
  0x00361F3C  75bc                    jne      0x361efa                       
                                        ; XREF: 0x00361EF5 (cond_jump)
  0x00361F3E  8b4664                  mov      eax, dword ptr [esi + 0x64]    
  0x00361F41  89464c                  mov      dword ptr [esi + 0x4c], eax    
  0x00361F44  8b4668                  mov      eax, dword ptr [esi + 0x68]    
  0x00361F47  5f                      pop      edi                            
  0x00361F48  894650                  mov      dword ptr [esi + 0x50], eax    
  0x00361F4B  5e                      pop      esi                            
  0x00361F4C  5b                      pop      ebx                            
  0x00361F4D  c9                      leave                                   
  0x00361F4E  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00361F51
; Start: 0x00361F51  End: 0x00361FD4  Size: 131 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_0036153F, sub_00361568
; Called by: sub_0036249D
; ============================================================
sub_00361F51:
  0x00361F51  55                      push     ebp                            
  0x00361F52  8bec                    mov      ebp, esp                       
  0x00361F54  53                      push     ebx                            
  0x00361F55  56                      push     esi                            
  0x00361F56  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00361F59  8b5e2c                  mov      ebx, dword ptr [esi + 0x2c]    
  0x00361F5C  8b4628                  mov      eax, dword ptr [esi + 0x28]    
  0x00361F5F  57                      push     edi                            
  0x00361F60  03c3                    add      eax, ebx                       
  0x00361F62  8d7e40                  lea      edi, [esi + 0x40]              
  0x00361F65  50                      push     eax                            
  0x00361F66  8bcf                    mov      ecx, edi                       
  0x00361F68  e8d2f5ffff              call     0x36153f                       ; -> sub_0036153F
  0x00361F6D  8b4e24                  mov      ecx, dword ptr [esi + 0x24]    
  0x00361F70  894508                  mov      dword ptr [ebp + 8], eax       
  0x00361F73  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x00361F76  03c8                    add      ecx, eax                       
  0x00361F78  51                      push     ecx                            
  0x00361F79  8bcf                    mov      ecx, edi                       
  0x00361F7B  e8e8f5ffff              call     0x361568                       ; -> sub_00361568
  0x00361F80  8b4e08                  mov      ecx, dword ptr [esi + 8]       
  0x00361F83  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x00361F86  83665800                and      dword ptr [esi + 0x58], 0      
  0x00361F8A  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x00361F8D  8b460c                  mov      eax, dword ptr [esi + 0xc]     
  0x00361F90  034630                  add      eax, dword ptr [esi + 0x30]    
  0x00361F93  03cb                    add      ecx, ebx                       
  0x00361F95  0faf4604                imul     eax, dword ptr [esi + 4]       
  0x00361F99  8d0448                  lea      eax, [eax + ecx*2]             
  0x00361F9C  8b4e18                  mov      ecx, dword ptr [esi + 0x18]    
  0x00361F9F  0306                    add      eax, dword ptr [esi]           
  0x00361FA1  8d0c51                  lea      ecx, [ecx + edx*2]             
  0x00361FA4  8b5638                  mov      edx, dword ptr [esi + 0x38]    
  0x00361FA7  85d2                    test     edx, edx                       
  0x00361FA9  7422                    je       0x361fcd                       
  0x00361FAB  895508                  mov      dword ptr [ebp + 8], edx       
                                        ; XREF: 0x00361FCB (cond_jump)
  0x00361FAE  668b18                  mov      bx, word ptr [eax]             
  0x00361FB1  8b565c                  mov      edx, dword ptr [esi + 0x5c]    
  0x00361FB4  66891c51                mov      word ptr [ecx + edx*2], bx     
  0x00361FB8  8b5710                  mov      edx, dword ptr [edi + 0x10]    
  0x00361FBB  8b5f1c                  mov      ebx, dword ptr [edi + 0x1c]    
  0x00361FBE  2bda                    sub      ebx, edx                       
  0x00361FC0  23da                    and      ebx, edx                       
  0x00361FC2  895f1c                  mov      dword ptr [edi + 0x1c], ebx    
  0x00361FC5  034604                  add      eax, dword ptr [esi + 4]       
  0x00361FC8  ff4d08                  dec      dword ptr [ebp + 8]            
  0x00361FCB  75e1                    jne      0x361fae                       
                                        ; XREF: 0x00361FA9 (cond_jump)
  0x00361FCD  5f                      pop      edi                            
  0x00361FCE  5e                      pop      esi                            
  0x00361FCF  5b                      pop      ebx                            
  0x00361FD0  5d                      pop      ebp                            
  0x00361FD1  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00361FD4
; Start: 0x00361FD4  End: 0x00362057  Size: 131 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_0036153F, sub_00361568
; Called by: sub_00362BEE
; ============================================================
sub_00361FD4:
  0x00361FD4  55                      push     ebp                            
  0x00361FD5  8bec                    mov      ebp, esp                       
  0x00361FD7  53                      push     ebx                            
  0x00361FD8  56                      push     esi                            
  0x00361FD9  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00361FDC  8b5e2c                  mov      ebx, dword ptr [esi + 0x2c]    
  0x00361FDF  8b4608                  mov      eax, dword ptr [esi + 8]       
  0x00361FE2  57                      push     edi                            
  0x00361FE3  03c3                    add      eax, ebx                       
  0x00361FE5  8d7e40                  lea      edi, [esi + 0x40]              
  0x00361FE8  50                      push     eax                            
  0x00361FE9  8bcf                    mov      ecx, edi                       
  0x00361FEB  e84ff5ffff              call     0x36153f                       ; -> sub_0036153F
  0x00361FF0  8b4e0c                  mov      ecx, dword ptr [esi + 0xc]     
  0x00361FF3  894508                  mov      dword ptr [ebp + 8], eax       
  0x00361FF6  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x00361FF9  03c8                    add      ecx, eax                       
  0x00361FFB  51                      push     ecx                            
  0x00361FFC  8bcf                    mov      ecx, edi                       
  0x00361FFE  e865f5ffff              call     0x361568                       ; -> sub_00361568
  0x00362003  8b4d08                  mov      ecx, dword ptr [ebp + 8]       
  0x00362006  8b5628                  mov      edx, dword ptr [esi + 0x28]    
  0x00362009  83665800                and      dword ptr [esi + 0x58], 0      
  0x0036200D  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x00362010  8b06                    mov      eax, dword ptr [esi]           
  0x00362012  8d0c48                  lea      ecx, [eax + ecx*2]             
  0x00362015  8b4624                  mov      eax, dword ptr [esi + 0x24]    
  0x00362018  034630                  add      eax, dword ptr [esi + 0x30]    
  0x0036201B  03d3                    add      edx, ebx                       
  0x0036201D  0faf4604                imul     eax, dword ptr [esi + 4]       
  0x00362021  8d0450                  lea      eax, [eax + edx*2]             
  0x00362024  8b5638                  mov      edx, dword ptr [esi + 0x38]    
  0x00362027  034618                  add      eax, dword ptr [esi + 0x18]    
  0x0036202A  85d2                    test     edx, edx                       
  0x0036202C  7422                    je       0x362050                       
  0x0036202E  895508                  mov      dword ptr [ebp + 8], edx       
                                        ; XREF: 0x0036204E (cond_jump)
  0x00362031  8b565c                  mov      edx, dword ptr [esi + 0x5c]    
  0x00362034  668b1451                mov      dx, word ptr [ecx + edx*2]     
  0x00362038  668910                  mov      word ptr [eax], dx             
  0x0036203B  8b5710                  mov      edx, dword ptr [edi + 0x10]    
  0x0036203E  8b5f1c                  mov      ebx, dword ptr [edi + 0x1c]    
  0x00362041  2bda                    sub      ebx, edx                       
  0x00362043  23da                    and      ebx, edx                       
  0x00362045  895f1c                  mov      dword ptr [edi + 0x1c], ebx    
  0x00362048  034604                  add      eax, dword ptr [esi + 4]       
  0x0036204B  ff4d08                  dec      dword ptr [ebp + 8]            
  0x0036204E  75e1                    jne      0x362031                       
                                        ; XREF: 0x0036202C (cond_jump)
  0x00362050  5f                      pop      edi                            
  0x00362051  5e                      pop      esi                            
  0x00362052  5b                      pop      ebx                            
  0x00362053  5d                      pop      ebp                            
  0x00362054  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00362057
; Start: 0x00362057  End: 0x00362123  Size: 204 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_0036153F, sub_00361568
; Called by: sub_0036249D
; ============================================================
sub_00362057:
  0x00362057  55                      push     ebp                            
  0x00362058  8bec                    mov      ebp, esp                       
  0x0036205A  51                      push     ecx                            
  0x0036205B  51                      push     ecx                            
  0x0036205C  53                      push     ebx                            
  0x0036205D  56                      push     esi                            
  0x0036205E  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00362061  8b462c                  mov      eax, dword ptr [esi + 0x2c]    
  0x00362064  8b5628                  mov      edx, dword ptr [esi + 0x28]    
  0x00362067  8b5e50                  mov      ebx, dword ptr [esi + 0x50]    
  0x0036206A  57                      push     edi                            
  0x0036206B  8b7e4c                  mov      edi, dword ptr [esi + 0x4c]    
  0x0036206E  03d0                    add      edx, eax                       
  0x00362070  8d4e40                  lea      ecx, [esi + 0x40]              
  0x00362073  52                      push     edx                            
  0x00362074  897e64                  mov      dword ptr [esi + 0x64], edi    
  0x00362077  895e68                  mov      dword ptr [esi + 0x68], ebx    
  0x0036207A  e8c0f4ffff              call     0x36153f                       ; -> sub_0036153F
  0x0036207F  8b4e24                  mov      ecx, dword ptr [esi + 0x24]    
  0x00362082  894508                  mov      dword ptr [ebp + 8], eax       
  0x00362085  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x00362088  03c8                    add      ecx, eax                       
  0x0036208A  51                      push     ecx                            
  0x0036208B  8d4e40                  lea      ecx, [esi + 0x40]              
  0x0036208E  e8d5f4ffff              call     0x361568                       ; -> sub_00361568
  0x00362093  8b4e0c                  mov      ecx, dword ptr [esi + 0xc]     
  0x00362096  034e30                  add      ecx, dword ptr [esi + 0x30]    
  0x00362099  d16d08                  shr      dword ptr [ebp + 8], 1         
  0x0036209C  d1ef                    shr      edi, 1                         
  0x0036209E  897e4c                  mov      dword ptr [esi + 0x4c], edi    
  0x003620A1  8b7e04                  mov      edi, dword ptr [esi + 4]       
  0x003620A4  0fafcf                  imul     ecx, edi                       
  0x003620A7  034e08                  add      ecx, dword ptr [esi + 8]       
  0x003620AA  d1e8                    shr      eax, 1                         
  0x003620AC  034e2c                  add      ecx, dword ptr [esi + 0x2c]    
  0x003620AF  8bd7                    mov      edx, edi                       
  0x003620B1  2b5634                  sub      edx, dword ptr [esi + 0x34]    
  0x003620B4  030e                    add      ecx, dword ptr [esi]           
  0x003620B6  8b7e18                  mov      edi, dword ptr [esi + 0x18]    
  0x003620B9  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x003620BC  8b4638                  mov      eax, dword ptr [esi + 0x38]    
  0x003620BF  d1eb                    shr      ebx, 1                         
  0x003620C1  85c0                    test     eax, eax                       
  0x003620C3  895e50                  mov      dword ptr [esi + 0x50], ebx    
  0x003620C6  7448                    je       0x362110                       
  0x003620C8  8945f8                  mov      dword ptr [ebp - 8], eax       
                                        ; XREF: 0x0036210E (cond_jump)
  0x003620CB  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x003620CE  894658                  mov      dword ptr [esi + 0x58], eax    
  0x003620D1  8b4634                  mov      eax, dword ptr [esi + 0x34]    
  0x003620D4  d1f8                    sar      eax, 1                         
  0x003620D6  7424                    je       0x3620fc                       
  0x003620D8  8945fc                  mov      dword ptr [ebp - 4], eax       
                                        ; XREF: 0x003620FA (cond_jump)
  0x003620DB  8b465c                  mov      eax, dword ptr [esi + 0x5c]    
  0x003620DE  0b4658                  or       eax, dword ptr [esi + 0x58]    
  0x003620E1  668b19                  mov      bx, word ptr [ecx]             
  0x003620E4  66891c47                mov      word ptr [edi + eax*2], bx     
  0x003620E8  8b464c                  mov      eax, dword ptr [esi + 0x4c]    
  0x003620EB  8b5e58                  mov      ebx, dword ptr [esi + 0x58]    
  0x003620EE  41                      inc      ecx                            
  0x003620EF  2bd8                    sub      ebx, eax                       
  0x003620F1  23d8                    and      ebx, eax                       
  0x003620F3  41                      inc      ecx                            
  0x003620F4  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x003620F7  895e58                  mov      dword ptr [esi + 0x58], ebx    
  0x003620FA  75df                    jne      0x3620db                       
                                        ; XREF: 0x003620D6 (cond_jump)
  0x003620FC  8b4650                  mov      eax, dword ptr [esi + 0x50]    
  0x003620FF  8b5e5c                  mov      ebx, dword ptr [esi + 0x5c]    
  0x00362102  2bd8                    sub      ebx, eax                       
  0x00362104  23d8                    and      ebx, eax                       
  0x00362106  03ca                    add      ecx, edx                       
  0x00362108  ff4df8                  dec      dword ptr [ebp - 8]            
  0x0036210B  895e5c                  mov      dword ptr [esi + 0x5c], ebx    
  0x0036210E  75bb                    jne      0x3620cb                       
                                        ; XREF: 0x003620C6 (cond_jump)
  0x00362110  8b4664                  mov      eax, dword ptr [esi + 0x64]    
  0x00362113  89464c                  mov      dword ptr [esi + 0x4c], eax    
  0x00362116  8b4668                  mov      eax, dword ptr [esi + 0x68]    
  0x00362119  5f                      pop      edi                            
  0x0036211A  894650                  mov      dword ptr [esi + 0x50], eax    
  0x0036211D  5e                      pop      esi                            
  0x0036211E  5b                      pop      ebx                            
  0x0036211F  c9                      leave                                   
  0x00362120  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00362123
; Start: 0x00362123  End: 0x003621EF  Size: 204 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_0036153F, sub_00361568
; Called by: sub_00362BEE
; ============================================================
sub_00362123:
  0x00362123  55                      push     ebp                            
  0x00362124  8bec                    mov      ebp, esp                       
  0x00362126  51                      push     ecx                            
  0x00362127  51                      push     ecx                            
  0x00362128  53                      push     ebx                            
  0x00362129  56                      push     esi                            
  0x0036212A  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x0036212D  8b462c                  mov      eax, dword ptr [esi + 0x2c]    
  0x00362130  8b5608                  mov      edx, dword ptr [esi + 8]       
  0x00362133  8b5e50                  mov      ebx, dword ptr [esi + 0x50]    
  0x00362136  57                      push     edi                            
  0x00362137  8b7e4c                  mov      edi, dword ptr [esi + 0x4c]    
  0x0036213A  03d0                    add      edx, eax                       
  0x0036213C  8d4e40                  lea      ecx, [esi + 0x40]              
  0x0036213F  52                      push     edx                            
  0x00362140  897e64                  mov      dword ptr [esi + 0x64], edi    
  0x00362143  895e68                  mov      dword ptr [esi + 0x68], ebx    
  0x00362146  e8f4f3ffff              call     0x36153f                       ; -> sub_0036153F
  0x0036214B  8b4e0c                  mov      ecx, dword ptr [esi + 0xc]     
  0x0036214E  894508                  mov      dword ptr [ebp + 8], eax       
  0x00362151  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x00362154  03c8                    add      ecx, eax                       
  0x00362156  51                      push     ecx                            
  0x00362157  8d4e40                  lea      ecx, [esi + 0x40]              
  0x0036215A  e809f4ffff              call     0x361568                       ; -> sub_00361568
  0x0036215F  8b4e24                  mov      ecx, dword ptr [esi + 0x24]    
  0x00362162  034e30                  add      ecx, dword ptr [esi + 0x30]    
  0x00362165  d16d08                  shr      dword ptr [ebp + 8], 1         
  0x00362168  d1ef                    shr      edi, 1                         
  0x0036216A  897e4c                  mov      dword ptr [esi + 0x4c], edi    
  0x0036216D  8b7e04                  mov      edi, dword ptr [esi + 4]       
  0x00362170  0fafcf                  imul     ecx, edi                       
  0x00362173  034e28                  add      ecx, dword ptr [esi + 0x28]    
  0x00362176  d1e8                    shr      eax, 1                         
  0x00362178  034e18                  add      ecx, dword ptr [esi + 0x18]    
  0x0036217B  d1eb                    shr      ebx, 1                         
  0x0036217D  034e2c                  add      ecx, dword ptr [esi + 0x2c]    
  0x00362180  8bd7                    mov      edx, edi                       
  0x00362182  2b5634                  sub      edx, dword ptr [esi + 0x34]    
  0x00362185  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x00362188  8b4638                  mov      eax, dword ptr [esi + 0x38]    
  0x0036218B  85c0                    test     eax, eax                       
  0x0036218D  895e50                  mov      dword ptr [esi + 0x50], ebx    
  0x00362190  8b1e                    mov      ebx, dword ptr [esi]           
  0x00362192  7448                    je       0x3621dc                       
  0x00362194  8945f8                  mov      dword ptr [ebp - 8], eax       
                                        ; XREF: 0x003621DA (cond_jump)
  0x00362197  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x0036219A  894658                  mov      dword ptr [esi + 0x58], eax    
  0x0036219D  8b4634                  mov      eax, dword ptr [esi + 0x34]    
  0x003621A0  d1f8                    sar      eax, 1                         
  0x003621A2  7424                    je       0x3621c8                       
  0x003621A4  8945fc                  mov      dword ptr [ebp - 4], eax       
                                        ; XREF: 0x003621C6 (cond_jump)
  0x003621A7  8b465c                  mov      eax, dword ptr [esi + 0x5c]    
  0x003621AA  0b4658                  or       eax, dword ptr [esi + 0x58]    
  0x003621AD  668b0443                mov      ax, word ptr [ebx + eax*2]     
  0x003621B1  668901                  mov      word ptr [ecx], ax             
  0x003621B4  8b464c                  mov      eax, dword ptr [esi + 0x4c]    
  0x003621B7  8b7e58                  mov      edi, dword ptr [esi + 0x58]    
  0x003621BA  41                      inc      ecx                            
  0x003621BB  2bf8                    sub      edi, eax                       
  0x003621BD  23f8                    and      edi, eax                       
  0x003621BF  41                      inc      ecx                            
  0x003621C0  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x003621C3  897e58                  mov      dword ptr [esi + 0x58], edi    
  0x003621C6  75df                    jne      0x3621a7                       
                                        ; XREF: 0x003621A2 (cond_jump)
  0x003621C8  8b4650                  mov      eax, dword ptr [esi + 0x50]    
  0x003621CB  8b7e5c                  mov      edi, dword ptr [esi + 0x5c]    
  0x003621CE  2bf8                    sub      edi, eax                       
  0x003621D0  23f8                    and      edi, eax                       
  0x003621D2  03ca                    add      ecx, edx                       
  0x003621D4  ff4df8                  dec      dword ptr [ebp - 8]            
  0x003621D7  897e5c                  mov      dword ptr [esi + 0x5c], edi    
  0x003621DA  75bb                    jne      0x362197                       
                                        ; XREF: 0x00362192 (cond_jump)
  0x003621DC  8b4664                  mov      eax, dword ptr [esi + 0x64]    
  0x003621DF  89464c                  mov      dword ptr [esi + 0x4c], eax    
  0x003621E2  8b4668                  mov      eax, dword ptr [esi + 0x68]    
  0x003621E5  5f                      pop      edi                            
  0x003621E6  894650                  mov      dword ptr [esi + 0x50], eax    
  0x003621E9  5e                      pop      esi                            
  0x003621EA  5b                      pop      ebx                            
  0x003621EB  c9                      leave                                   
  0x003621EC  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_003621EF
; Start: 0x003621EF  End: 0x0036226A  Size: 123 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_0036153F, sub_00361568
; Called by: sub_0036249D
; ============================================================
sub_003621EF:
  0x003621EF  55                      push     ebp                            
  0x003621F0  8bec                    mov      ebp, esp                       
  0x003621F2  53                      push     ebx                            
  0x003621F3  56                      push     esi                            
  0x003621F4  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x003621F7  8b5e2c                  mov      ebx, dword ptr [esi + 0x2c]    
  0x003621FA  8b4628                  mov      eax, dword ptr [esi + 0x28]    
  0x003621FD  57                      push     edi                            
  0x003621FE  03c3                    add      eax, ebx                       
  0x00362200  8d7e40                  lea      edi, [esi + 0x40]              
  0x00362203  50                      push     eax                            
  0x00362204  8bcf                    mov      ecx, edi                       
  0x00362206  e834f3ffff              call     0x36153f                       ; -> sub_0036153F
  0x0036220B  8b4e24                  mov      ecx, dword ptr [esi + 0x24]    
  0x0036220E  894508                  mov      dword ptr [ebp + 8], eax       
  0x00362211  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x00362214  03c8                    add      ecx, eax                       
  0x00362216  51                      push     ecx                            
  0x00362217  8bcf                    mov      ecx, edi                       
  0x00362219  e84af3ffff              call     0x361568                       ; -> sub_00361568
  0x0036221E  8b4e18                  mov      ecx, dword ptr [esi + 0x18]    
  0x00362221  8b5638                  mov      edx, dword ptr [esi + 0x38]    
  0x00362224  83665800                and      dword ptr [esi + 0x58], 0      
  0x00362228  034d08                  add      ecx, dword ptr [ebp + 8]       
  0x0036222B  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x0036222E  8b460c                  mov      eax, dword ptr [esi + 0xc]     
  0x00362231  034630                  add      eax, dword ptr [esi + 0x30]    
  0x00362234  0faf4604                imul     eax, dword ptr [esi + 4]       
  0x00362238  034608                  add      eax, dword ptr [esi + 8]       
  0x0036223B  03c3                    add      eax, ebx                       
  0x0036223D  0306                    add      eax, dword ptr [esi]           
  0x0036223F  85d2                    test     edx, edx                       
  0x00362241  7420                    je       0x362263                       
  0x00362243  895508                  mov      dword ptr [ebp + 8], edx       
                                        ; XREF: 0x00362261 (cond_jump)
  0x00362246  8a18                    mov      bl, byte ptr [eax]             
  0x00362248  8b565c                  mov      edx, dword ptr [esi + 0x5c]    
  0x0036224B  881c11                  mov      byte ptr [ecx + edx], bl       
  0x0036224E  8b5710                  mov      edx, dword ptr [edi + 0x10]    
  0x00362251  8b5f1c                  mov      ebx, dword ptr [edi + 0x1c]    
  0x00362254  2bda                    sub      ebx, edx                       
  0x00362256  23da                    and      ebx, edx                       
  0x00362258  895f1c                  mov      dword ptr [edi + 0x1c], ebx    
  0x0036225B  034604                  add      eax, dword ptr [esi + 4]       
  0x0036225E  ff4d08                  dec      dword ptr [ebp + 8]            
  0x00362261  75e3                    jne      0x362246                       
                                        ; XREF: 0x00362241 (cond_jump)
  0x00362263  5f                      pop      edi                            
  0x00362264  5e                      pop      esi                            
  0x00362265  5b                      pop      ebx                            
  0x00362266  5d                      pop      ebp                            
  0x00362267  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_0036226A
; Start: 0x0036226A  End: 0x003622E5  Size: 123 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_0036153F, sub_00361568
; Called by: sub_00362BEE
; ============================================================
sub_0036226A:
  0x0036226A  55                      push     ebp                            
  0x0036226B  8bec                    mov      ebp, esp                       
  0x0036226D  53                      push     ebx                            
  0x0036226E  56                      push     esi                            
  0x0036226F  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00362272  8b5e2c                  mov      ebx, dword ptr [esi + 0x2c]    
  0x00362275  8b4608                  mov      eax, dword ptr [esi + 8]       
  0x00362278  57                      push     edi                            
  0x00362279  03c3                    add      eax, ebx                       
  0x0036227B  8d7e40                  lea      edi, [esi + 0x40]              
  0x0036227E  50                      push     eax                            
  0x0036227F  8bcf                    mov      ecx, edi                       
  0x00362281  e8b9f2ffff              call     0x36153f                       ; -> sub_0036153F
  0x00362286  8b4e0c                  mov      ecx, dword ptr [esi + 0xc]     
  0x00362289  894508                  mov      dword ptr [ebp + 8], eax       
  0x0036228C  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x0036228F  03c8                    add      ecx, eax                       
  0x00362291  51                      push     ecx                            
  0x00362292  8bcf                    mov      ecx, edi                       
  0x00362294  e8cff2ffff              call     0x361568                       ; -> sub_00361568
  0x00362299  8b0e                    mov      ecx, dword ptr [esi]           
  0x0036229B  8b5638                  mov      edx, dword ptr [esi + 0x38]    
  0x0036229E  83665800                and      dword ptr [esi + 0x58], 0      
  0x003622A2  034d08                  add      ecx, dword ptr [ebp + 8]       
  0x003622A5  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x003622A8  8b4624                  mov      eax, dword ptr [esi + 0x24]    
  0x003622AB  034630                  add      eax, dword ptr [esi + 0x30]    
  0x003622AE  0faf4604                imul     eax, dword ptr [esi + 4]       
  0x003622B2  034628                  add      eax, dword ptr [esi + 0x28]    
  0x003622B5  034618                  add      eax, dword ptr [esi + 0x18]    
  0x003622B8  03c3                    add      eax, ebx                       
  0x003622BA  85d2                    test     edx, edx                       
  0x003622BC  7420                    je       0x3622de                       
  0x003622BE  895508                  mov      dword ptr [ebp + 8], edx       
                                        ; XREF: 0x003622DC (cond_jump)
  0x003622C1  8b565c                  mov      edx, dword ptr [esi + 0x5c]    
  0x003622C4  8a1411                  mov      dl, byte ptr [ecx + edx]       
  0x003622C7  8810                    mov      byte ptr [eax], dl             
  0x003622C9  8b5710                  mov      edx, dword ptr [edi + 0x10]    
  0x003622CC  8b5f1c                  mov      ebx, dword ptr [edi + 0x1c]    
  0x003622CF  2bda                    sub      ebx, edx                       
  0x003622D1  23da                    and      ebx, edx                       
  0x003622D3  895f1c                  mov      dword ptr [edi + 0x1c], ebx    
  0x003622D6  034604                  add      eax, dword ptr [esi + 4]       
  0x003622D9  ff4d08                  dec      dword ptr [ebp + 8]            
  0x003622DC  75e3                    jne      0x3622c1                       
                                        ; XREF: 0x003622BC (cond_jump)
  0x003622DE  5f                      pop      edi                            
  0x003622DF  5e                      pop      esi                            
  0x003622E0  5b                      pop      ebx                            
  0x003622E1  5d                      pop      ebp                            
  0x003622E2  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_003622E5
; Start: 0x003622E5  End: 0x003623C1  Size: 220 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_0036153F, sub_00361568
; Called by: sub_0036249D
; ============================================================
sub_003622E5:
  0x003622E5  55                      push     ebp                            
  0x003622E6  8bec                    mov      ebp, esp                       
  0x003622E8  51                      push     ecx                            
  0x003622E9  51                      push     ecx                            
  0x003622EA  53                      push     ebx                            
  0x003622EB  56                      push     esi                            
  0x003622EC  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x003622EF  8b462c                  mov      eax, dword ptr [esi + 0x2c]    
  0x003622F2  8b5628                  mov      edx, dword ptr [esi + 0x28]    
  0x003622F5  8b5e50                  mov      ebx, dword ptr [esi + 0x50]    
  0x003622F8  57                      push     edi                            
  0x003622F9  8b7e4c                  mov      edi, dword ptr [esi + 0x4c]    
  0x003622FC  03d0                    add      edx, eax                       
  0x003622FE  8d4e40                  lea      ecx, [esi + 0x40]              
  0x00362301  52                      push     edx                            
  0x00362302  897e64                  mov      dword ptr [esi + 0x64], edi    
  0x00362305  895e68                  mov      dword ptr [esi + 0x68], ebx    
  0x00362308  e832f2ffff              call     0x36153f                       ; -> sub_0036153F
  0x0036230D  8b4e24                  mov      ecx, dword ptr [esi + 0x24]    
  0x00362310  894508                  mov      dword ptr [ebp + 8], eax       
  0x00362313  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x00362316  03c8                    add      ecx, eax                       
  0x00362318  51                      push     ecx                            
  0x00362319  8d4e40                  lea      ecx, [esi + 0x40]              
  0x0036231C  e847f2ffff              call     0x361568                       ; -> sub_00361568
  0x00362321  8b5634                  mov      edx, dword ptr [esi + 0x34]    
  0x00362324  8b4e04                  mov      ecx, dword ptr [esi + 4]       
  0x00362327  d16d08                  shr      dword ptr [ebp + 8], 1         
  0x0036232A  d1ef                    shr      edi, 1                         
  0x0036232C  897e4c                  mov      dword ptr [esi + 0x4c], edi    
  0x0036232F  c1e202                  shl      edx, 2                         
  0x00362332  8bfa                    mov      edi, edx                       
  0x00362334  8bd1                    mov      edx, ecx                       
  0x00362336  2bd7                    sub      edx, edi                       
  0x00362338  8b7e0c                  mov      edi, dword ptr [esi + 0xc]     
  0x0036233B  037e30                  add      edi, dword ptr [esi + 0x30]    
  0x0036233E  d1e8                    shr      eax, 1                         
  0x00362340  0faff9                  imul     edi, ecx                       
  0x00362343  8b4e08                  mov      ecx, dword ptr [esi + 8]       
  0x00362346  034e2c                  add      ecx, dword ptr [esi + 0x2c]    
  0x00362349  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x0036234C  8b4638                  mov      eax, dword ptr [esi + 0x38]    
  0x0036234F  8d0c8f                  lea      ecx, [edi + ecx*4]             
  0x00362352  030e                    add      ecx, dword ptr [esi]           
  0x00362354  8b7e18                  mov      edi, dword ptr [esi + 0x18]    
  0x00362357  d1eb                    shr      ebx, 1                         
  0x00362359  85c0                    test     eax, eax                       
  0x0036235B  895e50                  mov      dword ptr [esi + 0x50], ebx    
  0x0036235E  744e                    je       0x3623ae                       
  0x00362360  8945f8                  mov      dword ptr [ebp - 8], eax       
                                        ; XREF: 0x003623AC (cond_jump)
  0x00362363  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x00362366  894658                  mov      dword ptr [esi + 0x58], eax    
  0x00362369  8b4634                  mov      eax, dword ptr [esi + 0x34]    
  0x0036236C  d1f8                    sar      eax, 1                         
  0x0036236E  742a                    je       0x36239a                       
  0x00362370  8945fc                  mov      dword ptr [ebp - 4], eax       
                                        ; XREF: 0x00362398 (cond_jump)
  0x00362373  8b465c                  mov      eax, dword ptr [esi + 0x5c]    
  0x00362376  0b4658                  or       eax, dword ptr [esi + 0x58]    
  0x00362379  8b19                    mov      ebx, dword ptr [ecx]           
  0x0036237B  891cc7                  mov      dword ptr [edi + eax*8], ebx   
  0x0036237E  8b5904                  mov      ebx, dword ptr [ecx + 4]       
  0x00362381  895cc704                mov      dword ptr [edi + eax*8 + 4], ebx 
  0x00362385  8b464c                  mov      eax, dword ptr [esi + 0x4c]    
  0x00362388  8b5e58                  mov      ebx, dword ptr [esi + 0x58]    
  0x0036238B  2bd8                    sub      ebx, eax                       
  0x0036238D  23d8                    and      ebx, eax                       
  0x0036238F  83c108                  add      ecx, 8                         
  0x00362392  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00362395  895e58                  mov      dword ptr [esi + 0x58], ebx    
  0x00362398  75d9                    jne      0x362373                       
                                        ; XREF: 0x0036236E (cond_jump)
  0x0036239A  8b4650                  mov      eax, dword ptr [esi + 0x50]    
  0x0036239D  8b5e5c                  mov      ebx, dword ptr [esi + 0x5c]    
  0x003623A0  2bd8                    sub      ebx, eax                       
  0x003623A2  23d8                    and      ebx, eax                       
  0x003623A4  03ca                    add      ecx, edx                       
  0x003623A6  ff4df8                  dec      dword ptr [ebp - 8]            
  0x003623A9  895e5c                  mov      dword ptr [esi + 0x5c], ebx    
  0x003623AC  75b5                    jne      0x362363                       
                                        ; XREF: 0x0036235E (cond_jump)
  0x003623AE  8b4664                  mov      eax, dword ptr [esi + 0x64]    
  0x003623B1  89464c                  mov      dword ptr [esi + 0x4c], eax    
  0x003623B4  8b4668                  mov      eax, dword ptr [esi + 0x68]    
  0x003623B7  5f                      pop      edi                            
  0x003623B8  894650                  mov      dword ptr [esi + 0x50], eax    
  0x003623BB  5e                      pop      esi                            
  0x003623BC  5b                      pop      ebx                            
  0x003623BD  c9                      leave                                   
  0x003623BE  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_003623C1
; Start: 0x003623C1  End: 0x0036249D  Size: 220 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_0036153F, sub_00361568
; Called by: sub_00362BEE
; ============================================================
sub_003623C1:
  0x003623C1  55                      push     ebp                            
  0x003623C2  8bec                    mov      ebp, esp                       
  0x003623C4  51                      push     ecx                            
  0x003623C5  51                      push     ecx                            
  0x003623C6  53                      push     ebx                            
  0x003623C7  56                      push     esi                            
  0x003623C8  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x003623CB  8b462c                  mov      eax, dword ptr [esi + 0x2c]    
  0x003623CE  8b5608                  mov      edx, dword ptr [esi + 8]       
  0x003623D1  8b5e50                  mov      ebx, dword ptr [esi + 0x50]    
  0x003623D4  57                      push     edi                            
  0x003623D5  8b7e4c                  mov      edi, dword ptr [esi + 0x4c]    
  0x003623D8  03d0                    add      edx, eax                       
  0x003623DA  8d4e40                  lea      ecx, [esi + 0x40]              
  0x003623DD  52                      push     edx                            
  0x003623DE  897e64                  mov      dword ptr [esi + 0x64], edi    
  0x003623E1  895e68                  mov      dword ptr [esi + 0x68], ebx    
  0x003623E4  e856f1ffff              call     0x36153f                       ; -> sub_0036153F
  0x003623E9  8b4e0c                  mov      ecx, dword ptr [esi + 0xc]     
  0x003623EC  894508                  mov      dword ptr [ebp + 8], eax       
  0x003623EF  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x003623F2  03c8                    add      ecx, eax                       
  0x003623F4  51                      push     ecx                            
  0x003623F5  8d4e40                  lea      ecx, [esi + 0x40]              
  0x003623F8  e86bf1ffff              call     0x361568                       ; -> sub_00361568
  0x003623FD  8b4e04                  mov      ecx, dword ptr [esi + 4]       
  0x00362400  8b5634                  mov      edx, dword ptr [esi + 0x34]    
  0x00362403  d16d08                  shr      dword ptr [ebp + 8], 1         
  0x00362406  d1eb                    shr      ebx, 1                         
  0x00362408  895e50                  mov      dword ptr [esi + 0x50], ebx    
  0x0036240B  8b5e24                  mov      ebx, dword ptr [esi + 0x24]    
  0x0036240E  035e30                  add      ebx, dword ptr [esi + 0x30]    
  0x00362411  d1ef                    shr      edi, 1                         
  0x00362413  0fafd9                  imul     ebx, ecx                       
  0x00362416  c1e202                  shl      edx, 2                         
  0x00362419  897e4c                  mov      dword ptr [esi + 0x4c], edi    
  0x0036241C  8bfa                    mov      edi, edx                       
  0x0036241E  8bd1                    mov      edx, ecx                       
  0x00362420  8b4e28                  mov      ecx, dword ptr [esi + 0x28]    
  0x00362423  034e2c                  add      ecx, dword ptr [esi + 0x2c]    
  0x00362426  d1e8                    shr      eax, 1                         
  0x00362428  8d0c8b                  lea      ecx, [ebx + ecx*4]             
  0x0036242B  034e18                  add      ecx, dword ptr [esi + 0x18]    
  0x0036242E  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x00362431  8b4638                  mov      eax, dword ptr [esi + 0x38]    
  0x00362434  2bd7                    sub      edx, edi                       
  0x00362436  85c0                    test     eax, eax                       
  0x00362438  8b3e                    mov      edi, dword ptr [esi]           
  0x0036243A  744e                    je       0x36248a                       
  0x0036243C  8945f8                  mov      dword ptr [ebp - 8], eax       
                                        ; XREF: 0x00362488 (cond_jump)
  0x0036243F  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x00362442  894658                  mov      dword ptr [esi + 0x58], eax    
  0x00362445  8b4634                  mov      eax, dword ptr [esi + 0x34]    
  0x00362448  d1f8                    sar      eax, 1                         
  0x0036244A  742a                    je       0x362476                       
  0x0036244C  8945fc                  mov      dword ptr [ebp - 4], eax       
                                        ; XREF: 0x00362474 (cond_jump)
  0x0036244F  8b465c                  mov      eax, dword ptr [esi + 0x5c]    
  0x00362452  0b4658                  or       eax, dword ptr [esi + 0x58]    
  0x00362455  8b1cc7                  mov      ebx, dword ptr [edi + eax*8]   
  0x00362458  8919                    mov      dword ptr [ecx], ebx           
  0x0036245A  8b44c704                mov      eax, dword ptr [edi + eax*8 + 4] 
  0x0036245E  894104                  mov      dword ptr [ecx + 4], eax       
  0x00362461  8b464c                  mov      eax, dword ptr [esi + 0x4c]    
  0x00362464  8b5e58                  mov      ebx, dword ptr [esi + 0x58]    
  0x00362467  2bd8                    sub      ebx, eax                       
  0x00362469  23d8                    and      ebx, eax                       
  0x0036246B  83c108                  add      ecx, 8                         
  0x0036246E  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00362471  895e58                  mov      dword ptr [esi + 0x58], ebx    
  0x00362474  75d9                    jne      0x36244f                       
                                        ; XREF: 0x0036244A (cond_jump)
  0x00362476  8b4650                  mov      eax, dword ptr [esi + 0x50]    
  0x00362479  8b5e5c                  mov      ebx, dword ptr [esi + 0x5c]    
  0x0036247C  2bd8                    sub      ebx, eax                       
  0x0036247E  23d8                    and      ebx, eax                       
  0x00362480  03ca                    add      ecx, edx                       
  0x00362482  ff4df8                  dec      dword ptr [ebp - 8]            
  0x00362485  895e5c                  mov      dword ptr [esi + 0x5c], ebx    
  0x00362488  75b5                    jne      0x36243f                       
                                        ; XREF: 0x0036243A (cond_jump)
  0x0036248A  8b4664                  mov      eax, dword ptr [esi + 0x64]    
  0x0036248D  89464c                  mov      dword ptr [esi + 0x4c], eax    
  0x00362490  8b4668                  mov      eax, dword ptr [esi + 0x68]    
  0x00362493  5f                      pop      edi                            
  0x00362494  894650                  mov      dword ptr [esi + 0x50], eax    
  0x00362497  5e                      pop      esi                            
  0x00362498  5b                      pop      ebx                            
  0x00362499  c9                      leave                                   
  0x0036249A  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_0036249D
; Start: 0x0036249D  End: 0x00362BEE  Size: 1873 bytes
; Detection: call_target (confidence: 0.90)
; Calls: sub_003614BF, sub_003614DE, sub_0036153F, sub_00361568, sub_00361605, sub_00361705, sub_00361803, 0x00361CA7, sub_00361DA9, sub_00361F51 ... (+3 more)
; ============================================================
sub_0036249D:
  0x0036249D  55                      push     ebp                            
  0x0036249E  8d6c24a8                lea      ebp, [esp - 0x58]              
  0x003624A2  81ec9c000000            sub      esp, 0x9c                      
  0x003624A8  53                      push     ebx                            
  0x003624A9  56                      push     esi                            
  0x003624AA  57                      push     edi                            
  0x003624AB  8b7d70                  mov      edi, dword ptr [ebp + 0x70]    
  0x003624AE  83ff02                  cmp      edi, 2                         
  0x003624B1  6a10                    push     0x10                           
  0x003624B3  5a                      pop      edx                            
  0x003624B4  6a08                    push     8                              
  0x003624B6  59                      pop      ecx                            
  0x003624B7  6a07                    push     7                              
  0x003624B9  58                      pop      eax                            
  0x003624BA  6a03                    push     3                              
  0x003624BC  8945c8                  mov      dword ptr [ebp - 0x38], eax    
  0x003624BF  8945cc                  mov      dword ptr [ebp - 0x34], eax    
  0x003624C2  8945d0                  mov      dword ptr [ebp - 0x30], eax    
  0x003624C5  8945bc                  mov      dword ptr [ebp - 0x44], eax    
  0x003624C8  8945c0                  mov      dword ptr [ebp - 0x40], eax    
  0x003624CB  58                      pop      eax                            
  0x003624CC  8955e0                  mov      dword ptr [ebp - 0x20], edx    
  0x003624CF  8955e4                  mov      dword ptr [ebp - 0x1c], edx    
  0x003624D2  894de8                  mov      dword ptr [ebp - 0x18], ecx    
  0x003624D5  894dd4                  mov      dword ptr [ebp - 0x2c], ecx    
  0x003624D8  894dd8                  mov      dword ptr [ebp - 0x28], ecx    
  0x003624DB  894ddc                  mov      dword ptr [ebp - 0x24], ecx    
  0x003624DE  8945c4                  mov      dword ptr [ebp - 0x3c], eax    
  0x003624E1  0f86e0060000            jbe      0x362bc7                       
  0x003624E7  837d7401                cmp      dword ptr [ebp + 0x74], 1      
  0x003624EB  0f86d6060000            jbe      0x362bc7                       
  0x003624F1  8b5d68                  mov      ebx, dword ptr [ebp + 0x68]    
  0x003624F4  85db                    test     ebx, ebx                       
  0x003624F6  8b757c                  mov      esi, dword ptr [ebp + 0x7c]    
  0x003624F9  756d                    jne      0x362568                       
  0x003624FB  837d7800                cmp      dword ptr [ebp + 0x78], 0      
  0x003624FF  7567                    jne      0x362568                       
  0x00362501  837d6400                cmp      dword ptr [ebp + 0x64], 0      
  0x00362505  7561                    jne      0x362568                       
  0x00362507  83fe04                  cmp      esi, 4                         
  0x0036250A  751d                    jne      0x362529                       
  0x0036250C  3bf9                    cmp      edi, ecx                       
  0x0036250E  7258                    jb       0x362568                       
  0x00362510  394d74                  cmp      dword ptr [ebp + 0x74], ecx    
  0x00362513  7253                    jb       0x362568                       
  0x00362515  ff7574                  push     dword ptr [ebp + 0x74]         
  0x00362518  57                      push     edi                            
  0x00362519  ff756c                  push     dword ptr [ebp + 0x6c]         
  0x0036251C  ff7560                  push     dword ptr [ebp + 0x60]         
  0x0036251F  e8dff2ffff              call     0x361803                       ; -> sub_00361803
  0x00362524  e9bb060000              jmp      0x362be4                       
                                        ; XREF: 0x0036250A (cond_jump)
  0x00362529  83fe02                  cmp      esi, 2                         
  0x0036252C  751d                    jne      0x36254b                       
  0x0036252E  3bfa                    cmp      edi, edx                       
  0x00362530  7236                    jb       0x362568                       
  0x00362532  394d74                  cmp      dword ptr [ebp + 0x74], ecx    
  0x00362535  7231                    jb       0x362568                       
  0x00362537  ff7574                  push     dword ptr [ebp + 0x74]         
  0x0036253A  57                      push     edi                            
  0x0036253B  ff756c                  push     dword ptr [ebp + 0x6c]         
  0x0036253E  ff7560                  push     dword ptr [ebp + 0x60]         
  0x00362541  e8bff1ffff              call     0x361705                       ; -> sub_00361705
  0x00362546  e999060000              jmp      0x362be4                       
                                        ; XREF: 0x0036252C (cond_jump)
  0x0036254B  3bfa                    cmp      edi, edx                       
  0x0036254D  7219                    jb       0x362568                       
  0x0036254F  394d74                  cmp      dword ptr [ebp + 0x74], ecx    
  0x00362552  7214                    jb       0x362568                       
  0x00362554  ff7574                  push     dword ptr [ebp + 0x74]         
  0x00362557  57                      push     edi                            
  0x00362558  ff756c                  push     dword ptr [ebp + 0x6c]         
  0x0036255B  ff7560                  push     dword ptr [ebp + 0x60]         
  0x0036255E  e8a2f0ffff              call     0x361605                       ; -> sub_00361605
  0x00362563  e97c060000              jmp      0x362be4                       
                                        ; XREF: 0x003624F9 (cond_jump), 0x003624FF (cond_jump), 0x00362505 (cond_jump), 0x0036250E (cond_jump), 0x00362513 (cond_jump), ... (+4 more)
  0x00362568  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x0036256B  e84fefffff              call     0x3614bf                       ; -> sub_003614BF
  0x00362570  8b4578                  mov      eax, dword ptr [ebp + 0x78]    
  0x00362573  85c0                    test     eax, eax                       
  0x00362575  8b5574                  mov      edx, dword ptr [ebp + 0x74]    
  0x00362578  897528                  mov      dword ptr [ebp + 0x28], esi    
  0x0036257B  89550c                  mov      dword ptr [ebp + 0xc], edx     
  0x0036257E  897d08                  mov      dword ptr [ebp + 8], edi       
  0x00362581  7508                    jne      0x36258b                       
  0x00362583  214514                  and      dword ptr [ebp + 0x14], eax    
  0x00362586  214510                  and      dword ptr [ebp + 0x10], eax    
  0x00362589  eb0b                    jmp      0x362596                       
                                        ; XREF: 0x00362581 (cond_jump)
  0x0036258B  8b08                    mov      ecx, dword ptr [eax]           
  0x0036258D  8b4004                  mov      eax, dword ptr [eax + 4]       
  0x00362590  894d14                  mov      dword ptr [ebp + 0x14], ecx    
  0x00362593  894510                  mov      dword ptr [ebp + 0x10], eax    
                                        ; XREF: 0x00362589 (jump)
  0x00362596  85db                    test     ebx, ebx                       
  0x00362598  8b456c                  mov      eax, dword ptr [ebp + 0x6c]    
  0x0036259B  894504                  mov      dword ptr [ebp + 4], eax       
  0x0036259E  8b4560                  mov      eax, dword ptr [ebp + 0x60]    
  0x003625A1  8945ec                  mov      dword ptr [ebp - 0x14], eax    
  0x003625A4  750e                    jne      0x3625b4                       
  0x003625A6  215df4                  and      dword ptr [ebp - 0xc], ebx     
  0x003625A9  215df8                  and      dword ptr [ebp - 8], ebx       
  0x003625AC  895500                  mov      dword ptr [ebp], edx           
  0x003625AF  897dfc                  mov      dword ptr [ebp - 4], edi       
  0x003625B2  eb1b                    jmp      0x3625cf                       
                                        ; XREF: 0x003625A4 (cond_jump)
  0x003625B4  8b4304                  mov      eax, dword ptr [ebx + 4]       
  0x003625B7  8b4b0c                  mov      ecx, dword ptr [ebx + 0xc]     
  0x003625BA  2bc8                    sub      ecx, eax                       
  0x003625BC  894d00                  mov      dword ptr [ebp], ecx           
  0x003625BF  8b0b                    mov      ecx, dword ptr [ebx]           
  0x003625C1  8b5b08                  mov      ebx, dword ptr [ebx + 8]       
  0x003625C4  2bd9                    sub      ebx, ecx                       
  0x003625C6  895dfc                  mov      dword ptr [ebp - 4], ebx       
  0x003625C9  894df4                  mov      dword ptr [ebp - 0xc], ecx     
  0x003625CC  8945f8                  mov      dword ptr [ebp - 8], eax       
                                        ; XREF: 0x003625B2 (jump)
  0x003625CF  8b4564                  mov      eax, dword ptr [ebp + 0x64]    
  0x003625D2  85c0                    test     eax, eax                       
  0x003625D4  7505                    jne      0x3625db                       
  0x003625D6  8bc7                    mov      eax, edi                       
  0x003625D8  0fafc6                  imul     eax, esi                       
                                        ; XREF: 0x003625D4 (cond_jump)
  0x003625DB  6a00                    push     0                              
  0x003625DD  52                      push     edx                            
  0x003625DE  57                      push     edi                            
  0x003625DF  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x003625E2  8945f0                  mov      dword ptr [ebp - 0x10], eax    
  0x003625E5  e8f4eeffff              call     0x3614de                       ; -> sub_003614DE
  0x003625EA  8b4538                  mov      eax, dword ptr [ebp + 0x38]    
  0x003625ED  894550                  mov      dword ptr [ebp + 0x50], eax    
  0x003625F0  8b453c                  mov      eax, dword ptr [ebp + 0x3c]    
  0x003625F3  894554                  mov      dword ptr [ebp + 0x54], eax    
  0x003625F6  8b4500                  mov      eax, dword ptr [ebp]           
  0x003625F9  33c9                    xor      ecx, ecx                       
  0x003625FB  3bc1                    cmp      eax, ecx                       
  0x003625FD  0f84e1050000            je       0x362be4                       
  0x00362603  394dfc                  cmp      dword ptr [ebp - 4], ecx       
  0x00362606  0f84d8050000            je       0x362be4                       
  0x0036260C  d1ee                    shr      esi, 1                         
  0x0036260E  c1e602                  shl      esi, 2                         
  0x00362611  f6451401                test     byte ptr [ebp + 0x14], 1       
  0x00362615  8b5c35c8                mov      ebx, dword ptr [ebp + esi - 0x38] 
  0x00362619  8b7c35bc                mov      edi, dword ptr [ebp + esi - 0x44] 
  0x0036261D  895d74                  mov      dword ptr [ebp + 0x74], ebx    
  0x00362620  7445                    je       0x362667                       
  0x00362622  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00362626  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x00362629  8d45ec                  lea      eax, [ebp - 0x14]              
  0x0036262C  894d18                  mov      dword ptr [ebp + 0x18], ecx    
  0x0036262F  894d1c                  mov      dword ptr [ebp + 0x1c], ecx    
  0x00362632  c7452001000000          mov      dword ptr [ebp + 0x20], 1      
  0x00362639  50                      push     eax                            
  0x0036263A  7507                    jne      0x362643                       
  0x0036263C  e866f6ffff              call     0x361ca7                       
  0x00362641  eb12                    jmp      0x362655                       
                                        ; XREF: 0x0036263A (cond_jump)
  0x00362643  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00362647  7507                    jne      0x362650                       
  0x00362649  e803f9ffff              call     0x361f51                       ; -> sub_00361F51
  0x0036264E  eb05                    jmp      0x362655                       
                                        ; XREF: 0x00362647 (cond_jump)
  0x00362650  e89afbffff              call     0x3621ef                       ; -> sub_003621EF
                                        ; XREF: 0x00362641 (jump), 0x0036264E (jump)
  0x00362655  ff45f4                  inc      dword ptr [ebp - 0xc]          
  0x00362658  ff4514                  inc      dword ptr [ebp + 0x14]         
  0x0036265B  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x0036265E  0f8480050000            je       0x362be4                       
  0x00362664  8b4500                  mov      eax, dword ptr [ebp]           
                                        ; XREF: 0x00362620 (cond_jump)
  0x00362667  f645fc01                test     byte ptr [ebp - 4], 1          
  0x0036266B  7444                    je       0x3626b1                       
  0x0036266D  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00362670  8b4dfc                  mov      ecx, dword ptr [ebp - 4]       
  0x00362673  83651c00                and      dword ptr [ebp + 0x1c], 0      
  0x00362677  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x0036267B  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x0036267E  8d45ec                  lea      eax, [ebp - 0x14]              
  0x00362681  894d18                  mov      dword ptr [ebp + 0x18], ecx    
  0x00362684  c7452001000000          mov      dword ptr [ebp + 0x20], 1      
  0x0036268B  50                      push     eax                            
  0x0036268C  7507                    jne      0x362695                       
  0x0036268E  e814f6ffff              call     0x361ca7                       
  0x00362693  eb12                    jmp      0x3626a7                       
                                        ; XREF: 0x0036268C (cond_jump)
  0x00362695  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00362699  7507                    jne      0x3626a2                       
  0x0036269B  e8b1f8ffff              call     0x361f51                       ; -> sub_00361F51
  0x003626A0  eb05                    jmp      0x3626a7                       
                                        ; XREF: 0x00362699 (cond_jump)
  0x003626A2  e848fbffff              call     0x3621ef                       ; -> sub_003621EF
                                        ; XREF: 0x00362693 (jump), 0x003626A0 (jump)
  0x003626A7  837dfc00                cmp      dword ptr [ebp - 4], 0         
  0x003626AB  0f8433050000            je       0x362be4                       
                                        ; XREF: 0x0036266B (cond_jump)
  0x003626B1  8b4d14                  mov      ecx, dword ptr [ebp + 0x14]    
  0x003626B4  8b55fc                  mov      edx, dword ptr [ebp - 4]       
  0x003626B7  8bc3                    mov      eax, ebx                       
  0x003626B9  f7d0                    not      eax                            
  0x003626BB  03d9                    add      ebx, ecx                       
  0x003626BD  03d1                    add      edx, ecx                       
  0x003626BF  23d8                    and      ebx, eax                       
  0x003626C1  23d0                    and      edx, eax                       
  0x003626C3  3bda                    cmp      ebx, edx                       
  0x003626C5  0f83c3040000            jae      0x362b8e                       
  0x003626CB  8b4d10                  mov      ecx, dword ptr [ebp + 0x10]    
  0x003626CE  8b5d00                  mov      ebx, dword ptr [ebp]           
  0x003626D1  8bc7                    mov      eax, edi                       
  0x003626D3  f7d0                    not      eax                            
  0x003626D5  03d9                    add      ebx, ecx                       
  0x003626D7  8d140f                  lea      edx, [edi + ecx]               
  0x003626DA  23d0                    and      edx, eax                       
  0x003626DC  23d8                    and      ebx, eax                       
  0x003626DE  3bd3                    cmp      edx, ebx                       
  0x003626E0  0f83a8040000            jae      0x362b8e                       
  0x003626E6  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x003626E9  3b4435e0                cmp      eax, dword ptr [ebp + esi - 0x20] 
  0x003626ED  0f829b040000            jb       0x362b8e                       
  0x003626F3  8b450c                  mov      eax, dword ptr [ebp + 0xc]     
  0x003626F6  3b4435d4                cmp      eax, dword ptr [ebp + esi - 0x2c] 
  0x003626FA  0f828e040000            jb       0x362b8e                       
  0x00362700  33db                    xor      ebx, ebx                       
  0x00362702  85f9                    test     ecx, edi                       
  0x00362704  7441                    je       0x362747                       
  0x00362706  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x00362709  f7d9                    neg      ecx                            
  0x0036270B  23cf                    and      ecx, edi                       
  0x0036270D  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00362711  894520                  mov      dword ptr [ebp + 0x20], eax    
  0x00362714  8bf1                    mov      esi, ecx                       
  0x00362716  8d45ec                  lea      eax, [ebp - 0x14]              
  0x00362719  895d18                  mov      dword ptr [ebp + 0x18], ebx    
  0x0036271C  895d1c                  mov      dword ptr [ebp + 0x1c], ebx    
  0x0036271F  897524                  mov      dword ptr [ebp + 0x24], esi    
  0x00362722  50                      push     eax                            
  0x00362723  7507                    jne      0x36272c                       
  0x00362725  e8bbfbffff              call     0x3622e5                       ; -> sub_003622E5
  0x0036272A  eb12                    jmp      0x36273e                       
                                        ; XREF: 0x00362723 (cond_jump)
  0x0036272C  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00362730  7507                    jne      0x362739                       
  0x00362732  e872f6ffff              call     0x361da9                       ; -> sub_00361DA9
  0x00362737  eb05                    jmp      0x36273e                       
                                        ; XREF: 0x00362730 (cond_jump)
  0x00362739  e819f9ffff              call     0x362057                       ; -> sub_00362057
                                        ; XREF: 0x0036272A (jump), 0x00362737 (jump)
  0x0036273E  0175f8                  add      dword ptr [ebp - 8], esi       
  0x00362741  017510                  add      dword ptr [ebp + 0x10], esi    
  0x00362744  297500                  sub      dword ptr [ebp], esi           
                                        ; XREF: 0x00362704 (cond_jump)
  0x00362747  8bc7                    mov      eax, edi                       
  0x00362749  234500                  and      eax, dword ptr [ebp]           
  0x0036274C  7438                    je       0x362786                       
  0x0036274E  294500                  sub      dword ptr [ebp], eax           
  0x00362751  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00362755  8b4d00                  mov      ecx, dword ptr [ebp]           
  0x00362758  894d1c                  mov      dword ptr [ebp + 0x1c], ecx    
  0x0036275B  8b4dfc                  mov      ecx, dword ptr [ebp - 4]       
  0x0036275E  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x00362761  8d45ec                  lea      eax, [ebp - 0x14]              
  0x00362764  895d18                  mov      dword ptr [ebp + 0x18], ebx    
  0x00362767  894d20                  mov      dword ptr [ebp + 0x20], ecx    
  0x0036276A  50                      push     eax                            
  0x0036276B  7507                    jne      0x362774                       
  0x0036276D  e873fbffff              call     0x3622e5                       ; -> sub_003622E5
  0x00362772  eb12                    jmp      0x362786                       
                                        ; XREF: 0x0036276B (cond_jump)
  0x00362774  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00362778  7507                    jne      0x362781                       
  0x0036277A  e82af6ffff              call     0x361da9                       ; -> sub_00361DA9
  0x0036277F  eb05                    jmp      0x362786                       
                                        ; XREF: 0x00362778 (cond_jump)
  0x00362781  e8d1f8ffff              call     0x362057                       ; -> sub_00362057
                                        ; XREF: 0x0036274C (cond_jump), 0x00362772 (jump), 0x0036277F (jump)
  0x00362786  8b7514                  mov      esi, dword ptr [ebp + 0x14]    
  0x00362789  857574                  test     dword ptr [ebp + 0x74], esi    
  0x0036278C  7447                    je       0x3627d5                       
  0x0036278E  8b4500                  mov      eax, dword ptr [ebp]           
  0x00362791  f7de                    neg      esi                            
  0x00362793  237574                  and      esi, dword ptr [ebp + 0x74]    
  0x00362796  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x0036279A  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x0036279D  8d45ec                  lea      eax, [ebp - 0x14]              
  0x003627A0  895d18                  mov      dword ptr [ebp + 0x18], ebx    
  0x003627A3  895d1c                  mov      dword ptr [ebp + 0x1c], ebx    
  0x003627A6  897520                  mov      dword ptr [ebp + 0x20], esi    
  0x003627A9  50                      push     eax                            
  0x003627AA  7507                    jne      0x3627b3                       
  0x003627AC  e834fbffff              call     0x3622e5                       ; -> sub_003622E5
  0x003627B1  eb12                    jmp      0x3627c5                       
                                        ; XREF: 0x003627AA (cond_jump)
  0x003627B3  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x003627B7  7507                    jne      0x3627c0                       
  0x003627B9  e8ebf5ffff              call     0x361da9                       ; -> sub_00361DA9
  0x003627BE  eb05                    jmp      0x3627c5                       
                                        ; XREF: 0x003627B7 (cond_jump)
  0x003627C0  e892f8ffff              call     0x362057                       ; -> sub_00362057
                                        ; XREF: 0x003627B1 (jump), 0x003627BE (jump)
  0x003627C5  8b7df4                  mov      edi, dword ptr [ebp - 0xc]     
  0x003627C8  017514                  add      dword ptr [ebp + 0x14], esi    
  0x003627CB  03fe                    add      edi, esi                       
  0x003627CD  2975fc                  sub      dword ptr [ebp - 4], esi       
  0x003627D0  897df4                  mov      dword ptr [ebp - 0xc], edi     
  0x003627D3  eb03                    jmp      0x3627d8                       
                                        ; XREF: 0x0036278C (cond_jump)
  0x003627D5  8b7df4                  mov      edi, dword ptr [ebp - 0xc]     
                                        ; XREF: 0x003627D3 (jump)
  0x003627D8  8b4574                  mov      eax, dword ptr [ebp + 0x74]    
  0x003627DB  2345fc                  and      eax, dword ptr [ebp - 4]       
  0x003627DE  743b                    je       0x36281b                       
  0x003627E0  2945fc                  sub      dword ptr [ebp - 4], eax       
  0x003627E3  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x003627E7  8b4dfc                  mov      ecx, dword ptr [ebp - 4]       
  0x003627EA  894520                  mov      dword ptr [ebp + 0x20], eax    
  0x003627ED  8b4500                  mov      eax, dword ptr [ebp]           
  0x003627F0  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x003627F3  8d45ec                  lea      eax, [ebp - 0x14]              
  0x003627F6  894d18                  mov      dword ptr [ebp + 0x18], ecx    
  0x003627F9  895d1c                  mov      dword ptr [ebp + 0x1c], ebx    
  0x003627FC  50                      push     eax                            
  0x003627FD  7507                    jne      0x362806                       
  0x003627FF  e8e1faffff              call     0x3622e5                       ; -> sub_003622E5
  0x00362804  eb12                    jmp      0x362818                       
                                        ; XREF: 0x003627FD (cond_jump)
  0x00362806  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x0036280A  7507                    jne      0x362813                       
  0x0036280C  e898f5ffff              call     0x361da9                       ; -> sub_00361DA9
  0x00362811  eb05                    jmp      0x362818                       
                                        ; XREF: 0x0036280A (cond_jump)
  0x00362813  e83ff8ffff              call     0x362057                       ; -> sub_00362057
                                        ; XREF: 0x00362804 (jump), 0x00362811 (jump)
  0x00362818  8b7df4                  mov      edi, dword ptr [ebp - 0xc]     
                                        ; XREF: 0x003627DE (cond_jump)
  0x0036281B  8b4538                  mov      eax, dword ptr [ebp + 0x38]    
  0x0036281E  ff7514                  push     dword ptr [ebp + 0x14]         
  0x00362821  83e0c0                  and      eax, 0xffffffc0                
  0x00362824  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00362828  89456c                  mov      dword ptr [ebp + 0x6c], eax    
  0x0036282B  8b453c                  mov      eax, dword ptr [ebp + 0x3c]    
  0x0036282E  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x00362831  0f8523010000            jne      0x36295a                       
  0x00362837  83e0e0                  and      eax, 0xffffffe0                
  0x0036283A  894574                  mov      dword ptr [ebp + 0x74], eax    
  0x0036283D  e8fdecffff              call     0x36153f                       ; -> sub_0036153F
  0x00362842  ff7510                  push     dword ptr [ebp + 0x10]         
  0x00362845  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x00362848  894564                  mov      dword ptr [ebp + 0x64], eax    
  0x0036284B  e818edffff              call     0x361568                       ; -> sub_00361568
  0x00362850  c16dfc03                shr      dword ptr [ebp - 4], 3         
  0x00362854  894578                  mov      dword ptr [ebp + 0x78], eax    
  0x00362857  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x0036285A  0faf45f8                imul     eax, dword ptr [ebp - 8]       
  0x0036285E  0345ec                  add      eax, dword ptr [ebp - 0x14]    
  0x00362861  c16d0002                shr      dword ptr [ebp], 2             
  0x00362865  8d04b8                  lea      eax, [eax + edi*4]             
  0x00362868  8945ec                  mov      dword ptr [ebp - 0x14], eax    
  0x0036286B  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x0036286E  894560                  mov      dword ptr [ebp + 0x60], eax    
  0x00362871  8b75ec                  mov      esi, dword ptr [ebp - 0x14]    
  0x00362874  8b7d04                  mov      edi, dword ptr [ebp + 4]       
  0x00362877  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x0036287A  c1e202                  shl      edx, 2                         
  0x0036287D  8b5d64                  mov      ebx, dword ptr [ebp + 0x64]    
  0x00362880  8b4d78                  mov      ecx, dword ptr [ebp + 0x78]    
  0x00362883  89757c                  mov      dword ptr [ebp + 0x7c], esi    
  0x00362886  8da42400000000          lea      esp, [esp]                     
                                        ; XREF: 0x0036292B (cond_jump), 0x0036294F (cond_jump)
  0x0036288D  8bc3                    mov      eax, ebx                       
  0x0036288F  0f1006                  movups   xmm0, xmmword ptr [esi]        
  0x00362892  0f106610                movups   xmm4, xmmword ptr [esi + 0x10] 
  0x00362896  0f101416                movups   xmm2, xmmword ptr [esi + edx]  
  0x0036289A  0f10741610              movups   xmm6, xmmword ptr [esi + edx + 0x10] 
  0x0036289F  0f28c8                  movaps   xmm1, xmm0                     
  0x003628A2  0f28ec                  movaps   xmm5, xmm4                     
  0x003628A5  8d3456                  lea      esi, [esi + edx*2]             
  0x003628A8  0bc1                    or       eax, ecx                       
  0x003628AA  0f16c2                  movlhps  xmm0, xmm2                     
  0x003628AD  0f12d1                  movhlps  xmm2, xmm1                     
  0x003628B0  0f16e6                  movlhps  xmm4, xmm6                     
  0x003628B3  0f12f5                  movhlps  xmm6, xmm5                     
  0x003628B6  0f100e                  movups   xmm1, xmmword ptr [esi]        
  0x003628B9  0f106e10                movups   xmm5, xmmword ptr [esi + 0x10] 
  0x003628BD  0f101c16                movups   xmm3, xmmword ptr [esi + edx]  
  0x003628C1  0f107c1610              movups   xmm7, xmmword ptr [esi + edx + 0x10] 
  0x003628C6  0f2b0487                movntps  xmmword ptr [edi + eax*4], xmm0 
  0x003628CA  0f2b548710              movntps  xmmword ptr [edi + eax*4 + 0x10], xmm2 
  0x003628CF  0f2b648740              movntps  xmmword ptr [edi + eax*4 + 0x40], xmm4 
  0x003628D4  0f2b748750              movntps  xmmword ptr [edi + eax*4 + 0x50], xmm6 
  0x003628D9  0f28c1                  movaps   xmm0, xmm1                     
  0x003628DC  0f28e5                  movaps   xmm4, xmm5                     
  0x003628DF  0f16cb                  movlhps  xmm1, xmm3                     
  0x003628E2  0f12d8                  movhlps  xmm3, xmm0                     
  0x003628E5  0f16ef                  movlhps  xmm5, xmm7                     
  0x003628E8  0f12fc                  movhlps  xmm7, xmm4                     
  0x003628EB  0f2b4c8720              movntps  xmmword ptr [edi + eax*4 + 0x20], xmm1 
  0x003628F0  0f2b5c8730              movntps  xmmword ptr [edi + eax*4 + 0x30], xmm3 
  0x003628F5  0f2b6c8760              movntps  xmmword ptr [edi + eax*4 + 0x60], xmm5 
  0x003628FA  0f2b7c8770              movntps  xmmword ptr [edi + eax*4 + 0x70], xmm7 
  0x003628FF  2bf2                    sub      esi, edx                       
  0x00362901  2bf2                    sub      esi, edx                       
  0x00362903  90                      nop                                     
  0x00362904  90                      nop                                     
  0x00362905  90                      nop                                     
  0x00362906  90                      nop                                     
  0x00362907  90                      nop                                     
  0x00362908  90                      nop                                     
  0x00362909  90                      nop                                     
  0x0036290A  90                      nop                                     
  0x0036290B  90                      nop                                     
  0x0036290C  90                      nop                                     
  0x0036290D  90                      nop                                     
  0x0036290E  90                      nop                                     
  0x0036290F  90                      nop                                     
  0x00362910  90                      nop                                     
  0x00362911  90                      nop                                     
  0x00362912  90                      nop                                     
  0x00362913  90                      nop                                     
  0x00362914  90                      nop                                     
  0x00362915  90                      nop                                     
  0x00362916  90                      nop                                     
  0x00362917  90                      nop                                     
  0x00362918  90                      nop                                     
  0x00362919  90                      nop                                     
  0x0036291A  90                      nop                                     
  0x0036291B  90                      nop                                     
  0x0036291C  90                      nop                                     
  0x0036291D  90                      nop                                     
  0x0036291E  90                      nop                                     
  0x0036291F  2b5d6c                  sub      ebx, dword ptr [ebp + 0x6c]    
  0x00362922  83c620                  add      esi, 0x20                      
  0x00362925  235d38                  and      ebx, dword ptr [ebp + 0x38]    
  0x00362928  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x0036292B  0f855cffffff            jne      0x36288d                       
  0x00362931  8b7560                  mov      esi, dword ptr [ebp + 0x60]    
  0x00362934  8b5d64                  mov      ebx, dword ptr [ebp + 0x64]    
  0x00362937  8975fc                  mov      dword ptr [ebp - 4], esi       
  0x0036293A  8b757c                  mov      esi, dword ptr [ebp + 0x7c]    
  0x0036293D  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x00362940  2b4d74                  sub      ecx, dword ptr [ebp + 0x74]    
  0x00362943  8d3486                  lea      esi, [esi + eax*4]             
  0x00362946  234d3c                  and      ecx, dword ptr [ebp + 0x3c]    
  0x00362949  89757c                  mov      dword ptr [ebp + 0x7c], esi    
  0x0036294C  ff4d00                  dec      dword ptr [ebp]                
  0x0036294F  0f8538ffffff            jne      0x36288d                       
  0x00362955  e98a020000              jmp      0x362be4                       
                                        ; XREF: 0x00362831 (cond_jump)
  0x0036295A  83e080                  and      eax, 0xffffff80                
  0x0036295D  894574                  mov      dword ptr [ebp + 0x74], eax    
  0x00362960  e8daebffff              call     0x36153f                       ; -> sub_0036153F
  0x00362965  ff7510                  push     dword ptr [ebp + 0x10]         
  0x00362968  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x0036296B  894564                  mov      dword ptr [ebp + 0x64], eax    
  0x0036296E  e8f5ebffff              call     0x361568                       ; -> sub_00361568
  0x00362973  c16dfc03                shr      dword ptr [ebp - 4], 3         
  0x00362977  894578                  mov      dword ptr [ebp + 0x78], eax    
  0x0036297A  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x0036297D  0faf45f8                imul     eax, dword ptr [ebp - 8]       
  0x00362981  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00362985  0f8504010000            jne      0x362a8f                       
  0x0036298B  0345ec                  add      eax, dword ptr [ebp - 0x14]    
  0x0036298E  c16d0003                shr      dword ptr [ebp], 3             
  0x00362992  8d0478                  lea      eax, [eax + edi*2]             
  0x00362995  8945ec                  mov      dword ptr [ebp - 0x14], eax    
  0x00362998  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x0036299B  894560                  mov      dword ptr [ebp + 0x60], eax    
  0x0036299E  8b75ec                  mov      esi, dword ptr [ebp - 0x14]    
  0x003629A1  8b7d04                  mov      edi, dword ptr [ebp + 4]       
  0x003629A4  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x003629A7  d1e2                    shl      edx, 1                         
  0x003629A9  8b5d64                  mov      ebx, dword ptr [ebp + 0x64]    
  0x003629AC  8b4d78                  mov      ecx, dword ptr [ebp + 0x78]    
  0x003629AF  89757c                  mov      dword ptr [ebp + 0x7c], esi    
  0x003629B2  eb09                    jmp      0x3629bd                       
  0x003629B4  8da42400000000          lea      esp, [esp]                     
  0x003629BB  8bff                    mov      edi, edi                       
                                        ; XREF: 0x003629B2 (jump), 0x00362A60 (cond_jump), 0x00362A84 (cond_jump)
  0x003629BD  0f1006                  movups   xmm0, xmmword ptr [esi]        
  0x003629C0  0f100c16                movups   xmm1, xmmword ptr [esi + edx]  
  0x003629C4  03f2                    add      esi, edx                       
  0x003629C6  8bc3                    mov      eax, ebx                       
  0x003629C8  0f102416                movups   xmm4, xmmword ptr [esi + edx]  
  0x003629CC  0f102c56                movups   xmm5, xmmword ptr [esi + edx*2] 
  0x003629D0  0bc1                    or       eax, ecx                       
  0x003629D2  0f28d0                  movaps   xmm2, xmm0                     
  0x003629D5  0f28f4                  movaps   xmm6, xmm4                     
  0x003629D8  0f15f5                  unpckhps xmm6, xmm5                     
  0x003629DB  8d3496                  lea      esi, [esi + edx*4]             
  0x003629DE  0f15d1                  unpckhps xmm2, xmm1                     
  0x003629E1  0f14e5                  unpcklps xmm4, xmm5                     
  0x003629E4  0f101e                  movups   xmm3, xmmword ptr [esi]        
  0x003629E7  0f102c16                movups   xmm5, xmmword ptr [esi + edx]  
  0x003629EB  0f103c56                movups   xmm7, xmmword ptr [esi + edx*2] 
  0x003629EF  2bf2                    sub      esi, edx                       
  0x003629F1  0f14c1                  unpcklps xmm0, xmm1                     
  0x003629F4  0f100e                  movups   xmm1, xmmword ptr [esi]        
  0x003629F7  0f2b0447                movntps  xmmword ptr [edi + eax*2], xmm0 
  0x003629FB  0f2b644710              movntps  xmmword ptr [edi + eax*2 + 0x10], xmm4 
  0x00362A00  0f2b544720              movntps  xmmword ptr [edi + eax*2 + 0x20], xmm2 
  0x00362A05  0f2b744730              movntps  xmmword ptr [edi + eax*2 + 0x30], xmm6 
  0x00362A0A  0f28c1                  movaps   xmm0, xmm1                     
  0x00362A0D  0f28e5                  movaps   xmm4, xmm5                     
  0x00362A10  0f14c3                  unpcklps xmm0, xmm3                     
  0x00362A13  0f14e7                  unpcklps xmm4, xmm7                     
  0x00362A16  0f15cb                  unpckhps xmm1, xmm3                     
  0x00362A19  0f15ef                  unpckhps xmm5, xmm7                     
  0x00362A1C  0f2b444740              movntps  xmmword ptr [edi + eax*2 + 0x40], xmm0 
  0x00362A21  0f2b644750              movntps  xmmword ptr [edi + eax*2 + 0x50], xmm4 
  0x00362A26  0f2b4c4760              movntps  xmmword ptr [edi + eax*2 + 0x60], xmm1 
  0x00362A2B  0f2b6c4770              movntps  xmmword ptr [edi + eax*2 + 0x70], xmm5 
  0x00362A30  2bf2                    sub      esi, edx                       
  0x00362A32  2bf2                    sub      esi, edx                       
  0x00362A34  2bf2                    sub      esi, edx                       
  0x00362A36  2bf2                    sub      esi, edx                       
  0x00362A38  2b5d6c                  sub      ebx, dword ptr [ebp + 0x6c]    
  0x00362A3B  90                      nop                                     
  0x00362A3C  90                      nop                                     
  0x00362A3D  90                      nop                                     
  0x00362A3E  90                      nop                                     
  0x00362A3F  90                      nop                                     
  0x00362A40  90                      nop                                     
  0x00362A41  90                      nop                                     
  0x00362A42  90                      nop                                     
  0x00362A43  90                      nop                                     
  0x00362A44  90                      nop                                     
  0x00362A45  90                      nop                                     
  0x00362A46  90                      nop                                     
  0x00362A47  90                      nop                                     
  0x00362A48  90                      nop                                     
  0x00362A49  90                      nop                                     
  0x00362A4A  90                      nop                                     
  0x00362A4B  90                      nop                                     
  0x00362A4C  90                      nop                                     
  0x00362A4D  90                      nop                                     
  0x00362A4E  90                      nop                                     
  0x00362A4F  90                      nop                                     
  0x00362A50  90                      nop                                     
  0x00362A51  90                      nop                                     
  0x00362A52  90                      nop                                     
  0x00362A53  90                      nop                                     
  0x00362A54  90                      nop                                     
  0x00362A55  90                      nop                                     
  0x00362A56  90                      nop                                     
  0x00362A57  83c610                  add      esi, 0x10                      
  0x00362A5A  235d38                  and      ebx, dword ptr [ebp + 0x38]    
  0x00362A5D  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00362A60  0f8557ffffff            jne      0x3629bd                       
  0x00362A66  8b7560                  mov      esi, dword ptr [ebp + 0x60]    
  0x00362A69  8b5d64                  mov      ebx, dword ptr [ebp + 0x64]    
  0x00362A6C  8975fc                  mov      dword ptr [ebp - 4], esi       
  0x00362A6F  8b757c                  mov      esi, dword ptr [ebp + 0x7c]    
  0x00362A72  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x00362A75  2b4d74                  sub      ecx, dword ptr [ebp + 0x74]    
  0x00362A78  8d34c6                  lea      esi, [esi + eax*8]             
  0x00362A7B  234d3c                  and      ecx, dword ptr [ebp + 0x3c]    
  0x00362A7E  89757c                  mov      dword ptr [ebp + 0x7c], esi    
  0x00362A81  ff4d00                  dec      dword ptr [ebp]                
  0x00362A84  0f8533ffffff            jne      0x3629bd                       
  0x00362A8A  e955010000              jmp      0x362be4                       
                                        ; XREF: 0x00362985 (cond_jump)
  0x00362A8F  0faf7d28                imul     edi, dword ptr [ebp + 0x28]    
  0x00362A93  037dec                  add      edi, dword ptr [ebp - 0x14]    
  0x00362A96  03f8                    add      edi, eax                       
  0x00362A98  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x00362A9B  c16d0003                shr      dword ptr [ebp], 3             
  0x00362A9F  897dec                  mov      dword ptr [ebp - 0x14], edi    
  0x00362AA2  894560                  mov      dword ptr [ebp + 0x60], eax    
  0x00362AA5  8b75ec                  mov      esi, dword ptr [ebp - 0x14]    
  0x00362AA8  8b7d04                  mov      edi, dword ptr [ebp + 4]       
  0x00362AAB  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x00362AAE  8b5d64                  mov      ebx, dword ptr [ebp + 0x64]    
  0x00362AB1  8b4d78                  mov      ecx, dword ptr [ebp + 0x78]    
  0x00362AB4  89757c                  mov      dword ptr [ebp + 0x7c], esi    
  0x00362AB7  8d9b00000000            lea      ebx, [ebx]                     
                                        ; XREF: 0x00362B60 (cond_jump), 0x00362B84 (cond_jump)
  0x00362ABD  0f6f06                  movq     mm0, qword ptr [esi]           
  0x00362AC0  0f6f0c16                movq     mm1, qword ptr [esi + edx]     
  0x00362AC4  03f2                    add      esi, edx                       
  0x00362AC6  8bc3                    mov      eax, ebx                       
  0x00362AC8  0f6f2416                movq     mm4, qword ptr [esi + edx]     
  0x00362ACC  0f6f2c56                movq     mm5, qword ptr [esi + edx*2]   
  0x00362AD0  0bc1                    or       eax, ecx                       
  0x00362AD2  0f7fc2                  movq     mm2, mm0                       
  0x00362AD5  0f7fe6                  movq     mm6, mm4                       
  0x00362AD8  0f69f5                  punpckhwd mm6, mm5                       
  0x00362ADB  8d3496                  lea      esi, [esi + edx*4]             
  0x00362ADE  0f69d1                  punpckhwd mm2, mm1                       
  0x00362AE1  0f61e5                  punpcklwd mm4, mm5                       
  0x00362AE4  0f6f1e                  movq     mm3, qword ptr [esi]           
  0x00362AE7  0f6f2c16                movq     mm5, qword ptr [esi + edx]     
  0x00362AEB  0f6f3c56                movq     mm7, qword ptr [esi + edx*2]   
  0x00362AEF  2bf2                    sub      esi, edx                       
  0x00362AF1  0f61c1                  punpcklwd mm0, mm1                       
  0x00362AF4  0f6f0e                  movq     mm1, qword ptr [esi]           
  0x00362AF7  0f7f0407                movq     qword ptr [edi + eax], mm0     
  0x00362AFB  0f7f640708              movq     qword ptr [edi + eax + 8], mm4 
  0x00362B00  0f7f540710              movq     qword ptr [edi + eax + 0x10], mm2 
  0x00362B05  0f7f740718              movq     qword ptr [edi + eax + 0x18], mm6 
  0x00362B0A  0f7fc8                  movq     mm0, mm1                       
  0x00362B0D  0f7fec                  movq     mm4, mm5                       
  0x00362B10  0f61c3                  punpcklwd mm0, mm3                       
  0x00362B13  0f61e7                  punpcklwd mm4, mm7                       
  0x00362B16  0f69cb                  punpckhwd mm1, mm3                       
  0x00362B19  0f69ef                  punpckhwd mm5, mm7                       
  0x00362B1C  0f7f440720              movq     qword ptr [edi + eax + 0x20], mm0 
  0x00362B21  0f7f640728              movq     qword ptr [edi + eax + 0x28], mm4 
  0x00362B26  0f7f4c0730              movq     qword ptr [edi + eax + 0x30], mm1 
  0x00362B2B  0f7f6c0738              movq     qword ptr [edi + eax + 0x38], mm5 
  0x00362B30  2bf2                    sub      esi, edx                       
  0x00362B32  2bf2                    sub      esi, edx                       
  0x00362B34  2bf2                    sub      esi, edx                       
  0x00362B36  2bf2                    sub      esi, edx                       
  0x00362B38  2b5d6c                  sub      ebx, dword ptr [ebp + 0x6c]    
  0x00362B3B  90                      nop                                     
  0x00362B3C  90                      nop                                     
  0x00362B3D  90                      nop                                     
  0x00362B3E  90                      nop                                     
  0x00362B3F  90                      nop                                     
  0x00362B40  90                      nop                                     
  0x00362B41  90                      nop                                     
  0x00362B42  90                      nop                                     
  0x00362B43  90                      nop                                     
  0x00362B44  90                      nop                                     
  0x00362B45  90                      nop                                     
  0x00362B46  90                      nop                                     
  0x00362B47  90                      nop                                     
  0x00362B48  90                      nop                                     
  0x00362B49  90                      nop                                     
  0x00362B4A  90                      nop                                     
  0x00362B4B  90                      nop                                     
  0x00362B4C  90                      nop                                     
  0x00362B4D  90                      nop                                     
  0x00362B4E  90                      nop                                     
  0x00362B4F  90                      nop                                     
  0x00362B50  90                      nop                                     
  0x00362B51  90                      nop                                     
  0x00362B52  90                      nop                                     
  0x00362B53  90                      nop                                     
  0x00362B54  90                      nop                                     
  0x00362B55  90                      nop                                     
  0x00362B56  90                      nop                                     
  0x00362B57  83c608                  add      esi, 8                         
  0x00362B5A  235d38                  and      ebx, dword ptr [ebp + 0x38]    
  0x00362B5D  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00362B60  0f8557ffffff            jne      0x362abd                       
  0x00362B66  8b4560                  mov      eax, dword ptr [ebp + 0x60]    
  0x00362B69  8b5d64                  mov      ebx, dword ptr [ebp + 0x64]    
  0x00362B6C  8945fc                  mov      dword ptr [ebp - 4], eax       
  0x00362B6F  8b757c                  mov      esi, dword ptr [ebp + 0x7c]    
  0x00362B72  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x00362B75  2b4d74                  sub      ecx, dword ptr [ebp + 0x74]    
  0x00362B78  8d34c6                  lea      esi, [esi + eax*8]             
  0x00362B7B  234d3c                  and      ecx, dword ptr [ebp + 0x3c]    
  0x00362B7E  89757c                  mov      dword ptr [ebp + 0x7c], esi    
  0x00362B81  ff4d00                  dec      dword ptr [ebp]                
  0x00362B84  0f8533ffffff            jne      0x362abd                       
  0x00362B8A  0f77                    emms                                    
  0x00362B8C  eb56                    jmp      0x362be4                       
                                        ; XREF: 0x003626C5 (cond_jump), 0x003626E0 (cond_jump), 0x003626ED (cond_jump), 0x003626FA (cond_jump)
  0x00362B8E  8b4500                  mov      eax, dword ptr [ebp]           
  0x00362B91  83651800                and      dword ptr [ebp + 0x18], 0      
  0x00362B95  83651c00                and      dword ptr [ebp + 0x1c], 0      
  0x00362B99  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00362B9D  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x00362BA0  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x00362BA3  894520                  mov      dword ptr [ebp + 0x20], eax    
  0x00362BA6  8d45ec                  lea      eax, [ebp - 0x14]              
  0x00362BA9  50                      push     eax                            
  0x00362BAA  7507                    jne      0x362bb3                       
  0x00362BAC  e834f7ffff              call     0x3622e5                       ; -> sub_003622E5
  0x00362BB1  eb31                    jmp      0x362be4                       
                                        ; XREF: 0x00362BAA (cond_jump)
  0x00362BB3  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00362BB7  7507                    jne      0x362bc0                       
  0x00362BB9  e8ebf1ffff              call     0x361da9                       ; -> sub_00361DA9
  0x00362BBE  eb24                    jmp      0x362be4                       
                                        ; XREF: 0x00362BB7 (cond_jump)
  0x00362BC0  e892f4ffff              call     0x362057                       ; -> sub_00362057
  0x00362BC5  eb1d                    jmp      0x362be4                       
                                        ; XREF: 0x003624E1 (cond_jump), 0x003624EB (cond_jump)
  0x00362BC7  8b7560                  mov      esi, dword ptr [ebp + 0x60]    
  0x00362BCA  8bcf                    mov      ecx, edi                       
  0x00362BCC  0faf4d74                imul     ecx, dword ptr [ebp + 0x74]    
  0x00362BD0  0faf4d7c                imul     ecx, dword ptr [ebp + 0x7c]    
  0x00362BD4  8b7d6c                  mov      edi, dword ptr [ebp + 0x6c]    
  0x00362BD7  8bd1                    mov      edx, ecx                       
  0x00362BD9  c1e902                  shr      ecx, 2                         
  0x00362BDC  f3a5                    rep movsd dword ptr es:[edi], dword ptr [esi] 
  0x00362BDE  8bca                    mov      ecx, edx                       
  0x00362BE0  23c8                    and      ecx, eax                       
  0x00362BE2  f3a4                    rep movsb byte ptr es:[edi], byte ptr [esi] 
                                        ; XREF: 0x00362524 (jump), 0x00362546 (jump), 0x00362563 (jump), 0x003625FD (cond_jump), 0x00362606 (cond_jump), ... (+8 more)
  0x00362BE4  5f                      pop      edi                            
  0x00362BE5  5e                      pop      esi                            
  0x00362BE6  5b                      pop      ebx                            
  0x00362BE7  83c558                  add      ebp, 0x58                      
  0x00362BEA  c9                      leave                                   
  0x00362BEB  c22000                  ret      0x20                           
; end of function

; ============================================================
; Function: sub_00362BEE
; Start: 0x00362BEE  End: 0x00363305  Size: 1815 bytes
; Detection: call_target (confidence: 0.90)
; Calls: sub_003614BF, sub_003614DE, sub_0036153F, sub_00361568, sub_003618FC, sub_003619DF, sub_00361AF1, sub_00361D28, sub_00361E7D, sub_00361FD4 ... (+3 more)
; ============================================================
sub_00362BEE:
  0x00362BEE  55                      push     ebp                            
  0x00362BEF  8d6c24a8                lea      ebp, [esp - 0x58]              
  0x00362BF3  81ec9c000000            sub      esp, 0x9c                      
  0x00362BF9  53                      push     ebx                            
  0x00362BFA  8b5d64                  mov      ebx, dword ptr [ebp + 0x64]    
  0x00362BFD  83fb02                  cmp      ebx, 2                         
  0x00362C00  56                      push     esi                            
  0x00362C01  57                      push     edi                            
  0x00362C02  6a10                    push     0x10                           
  0x00362C04  58                      pop      eax                            
  0x00362C05  6a08                    push     8                              
  0x00362C07  5f                      pop      edi                            
  0x00362C08  6a0f                    push     0xf                            
  0x00362C0A  59                      pop      ecx                            
  0x00362C0B  6a03                    push     3                              
  0x00362C0D  5a                      pop      edx                            
  0x00362C0E  8945e0                  mov      dword ptr [ebp - 0x20], eax    
  0x00362C11  8945e4                  mov      dword ptr [ebp - 0x1c], eax    
  0x00362C14  897de8                  mov      dword ptr [ebp - 0x18], edi    
  0x00362C17  8945d4                  mov      dword ptr [ebp - 0x2c], eax    
  0x00362C1A  8945d8                  mov      dword ptr [ebp - 0x28], eax    
  0x00362C1D  897ddc                  mov      dword ptr [ebp - 0x24], edi    
  0x00362C20  894dc8                  mov      dword ptr [ebp - 0x38], ecx    
  0x00362C23  894dcc                  mov      dword ptr [ebp - 0x34], ecx    
  0x00362C26  c745d007000000          mov      dword ptr [ebp - 0x30], 7      
  0x00362C2D  8955bc                  mov      dword ptr [ebp - 0x44], edx    
  0x00362C30  8955c0                  mov      dword ptr [ebp - 0x40], edx    
  0x00362C33  8955c4                  mov      dword ptr [ebp - 0x3c], edx    
  0x00362C36  0f86a2060000            jbe      0x3632de                       
  0x00362C3C  8b4d68                  mov      ecx, dword ptr [ebp + 0x68]    
  0x00362C3F  83f901                  cmp      ecx, 1                         
  0x00362C42  0f8696060000            jbe      0x3632de                       
  0x00362C48  8b757c                  mov      esi, dword ptr [ebp + 0x7c]    
  0x00362C4B  33d2                    xor      edx, edx                       
  0x00362C4D  39556c                  cmp      dword ptr [ebp + 0x6c], edx    
  0x00362C50  7562                    jne      0x362cb4                       
  0x00362C52  395578                  cmp      dword ptr [ebp + 0x78], edx    
  0x00362C55  755d                    jne      0x362cb4                       
  0x00362C57  395574                  cmp      dword ptr [ebp + 0x74], edx    
  0x00362C5A  7558                    jne      0x362cb4                       
  0x00362C5C  83fe04                  cmp      esi, 4                         
  0x00362C5F  751a                    jne      0x362c7b                       
  0x00362C61  3bdf                    cmp      ebx, edi                       
  0x00362C63  724f                    jb       0x362cb4                       
  0x00362C65  3bcf                    cmp      ecx, edi                       
  0x00362C67  724b                    jb       0x362cb4                       
  0x00362C69  51                      push     ecx                            
  0x00362C6A  53                      push     ebx                            
  0x00362C6B  ff7570                  push     dword ptr [ebp + 0x70]         
  0x00362C6E  ff7560                  push     dword ptr [ebp + 0x60]         
  0x00362C71  e87beeffff              call     0x361af1                       ; -> sub_00361AF1
  0x00362C76  e980060000              jmp      0x3632fb                       
                                        ; XREF: 0x00362C5F (cond_jump)
  0x00362C7B  83fe02                  cmp      esi, 2                         
  0x00362C7E  751a                    jne      0x362c9a                       
  0x00362C80  3bd8                    cmp      ebx, eax                       
  0x00362C82  7230                    jb       0x362cb4                       
  0x00362C84  3bc8                    cmp      ecx, eax                       
  0x00362C86  722c                    jb       0x362cb4                       
  0x00362C88  51                      push     ecx                            
  0x00362C89  53                      push     ebx                            
  0x00362C8A  ff7570                  push     dword ptr [ebp + 0x70]         
  0x00362C8D  ff7560                  push     dword ptr [ebp + 0x60]         
  0x00362C90  e84aedffff              call     0x3619df                       ; -> sub_003619DF
  0x00362C95  e961060000              jmp      0x3632fb                       
                                        ; XREF: 0x00362C7E (cond_jump)
  0x00362C9A  3bd8                    cmp      ebx, eax                       
  0x00362C9C  7216                    jb       0x362cb4                       
  0x00362C9E  3bc8                    cmp      ecx, eax                       
  0x00362CA0  7212                    jb       0x362cb4                       
  0x00362CA2  51                      push     ecx                            
  0x00362CA3  53                      push     ebx                            
  0x00362CA4  ff7570                  push     dword ptr [ebp + 0x70]         
  0x00362CA7  ff7560                  push     dword ptr [ebp + 0x60]         
  0x00362CAA  e84decffff              call     0x3618fc                       ; -> sub_003618FC
  0x00362CAF  e947060000              jmp      0x3632fb                       
                                        ; XREF: 0x00362C50 (cond_jump), 0x00362C55 (cond_jump), 0x00362C5A (cond_jump), 0x00362C63 (cond_jump), 0x00362C67 (cond_jump), ... (+4 more)
  0x00362CB4  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x00362CB7  e803e8ffff              call     0x3614bf                       ; -> sub_003614BF
  0x00362CBC  8b4578                  mov      eax, dword ptr [ebp + 0x78]    
  0x00362CBF  8b7d68                  mov      edi, dword ptr [ebp + 0x68]    
  0x00362CC2  33c9                    xor      ecx, ecx                       
  0x00362CC4  3bc1                    cmp      eax, ecx                       
  0x00362CC6  897528                  mov      dword ptr [ebp + 0x28], esi    
  0x00362CC9  897d0c                  mov      dword ptr [ebp + 0xc], edi     
  0x00362CCC  895d08                  mov      dword ptr [ebp + 8], ebx       
  0x00362CCF  7508                    jne      0x362cd9                       
  0x00362CD1  894d14                  mov      dword ptr [ebp + 0x14], ecx    
  0x00362CD4  894d10                  mov      dword ptr [ebp + 0x10], ecx    
  0x00362CD7  eb0b                    jmp      0x362ce4                       
                                        ; XREF: 0x00362CCF (cond_jump)
  0x00362CD9  8b10                    mov      edx, dword ptr [eax]           
  0x00362CDB  8b4004                  mov      eax, dword ptr [eax + 4]       
  0x00362CDE  895514                  mov      dword ptr [ebp + 0x14], edx    
  0x00362CE1  894510                  mov      dword ptr [ebp + 0x10], eax    
                                        ; XREF: 0x00362CD7 (jump)
  0x00362CE4  8b4570                  mov      eax, dword ptr [ebp + 0x70]    
  0x00362CE7  894504                  mov      dword ptr [ebp + 4], eax       
  0x00362CEA  8b4560                  mov      eax, dword ptr [ebp + 0x60]    
  0x00362CED  8945ec                  mov      dword ptr [ebp - 0x14], eax    
  0x00362CF0  8b456c                  mov      eax, dword ptr [ebp + 0x6c]    
  0x00362CF3  3bc1                    cmp      eax, ecx                       
  0x00362CF5  750e                    jne      0x362d05                       
  0x00362CF7  897d00                  mov      dword ptr [ebp], edi           
  0x00362CFA  895dfc                  mov      dword ptr [ebp - 4], ebx       
  0x00362CFD  894df4                  mov      dword ptr [ebp - 0xc], ecx     
  0x00362D00  894df8                  mov      dword ptr [ebp - 8], ecx       
  0x00362D03  eb1d                    jmp      0x362d22                       
                                        ; XREF: 0x00362CF5 (cond_jump)
  0x00362D05  8b4804                  mov      ecx, dword ptr [eax + 4]       
  0x00362D08  8b500c                  mov      edx, dword ptr [eax + 0xc]     
  0x00362D0B  2bd1                    sub      edx, ecx                       
  0x00362D0D  895500                  mov      dword ptr [ebp], edx           
  0x00362D10  8b10                    mov      edx, dword ptr [eax]           
  0x00362D12  8b4008                  mov      eax, dword ptr [eax + 8]       
  0x00362D15  2bc2                    sub      eax, edx                       
  0x00362D17  894df8                  mov      dword ptr [ebp - 8], ecx       
  0x00362D1A  8945fc                  mov      dword ptr [ebp - 4], eax       
  0x00362D1D  8955f4                  mov      dword ptr [ebp - 0xc], edx     
  0x00362D20  33c9                    xor      ecx, ecx                       
                                        ; XREF: 0x00362D03 (jump)
  0x00362D22  8b4574                  mov      eax, dword ptr [ebp + 0x74]    
  0x00362D25  3bc1                    cmp      eax, ecx                       
  0x00362D27  7505                    jne      0x362d2e                       
  0x00362D29  8bc3                    mov      eax, ebx                       
  0x00362D2B  0fafc6                  imul     eax, esi                       
                                        ; XREF: 0x00362D27 (cond_jump)
  0x00362D2E  51                      push     ecx                            
  0x00362D2F  57                      push     edi                            
  0x00362D30  53                      push     ebx                            
  0x00362D31  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x00362D34  8945f0                  mov      dword ptr [ebp - 0x10], eax    
  0x00362D37  e8a2e7ffff              call     0x3614de                       ; -> sub_003614DE
  0x00362D3C  8b4538                  mov      eax, dword ptr [ebp + 0x38]    
  0x00362D3F  894550                  mov      dword ptr [ebp + 0x50], eax    
  0x00362D42  8b453c                  mov      eax, dword ptr [ebp + 0x3c]    
  0x00362D45  894554                  mov      dword ptr [ebp + 0x54], eax    
  0x00362D48  8b4500                  mov      eax, dword ptr [ebp]           
  0x00362D4B  33c9                    xor      ecx, ecx                       
  0x00362D4D  3bc1                    cmp      eax, ecx                       
  0x00362D4F  0f84a6050000            je       0x3632fb                       
  0x00362D55  394dfc                  cmp      dword ptr [ebp - 4], ecx       
  0x00362D58  0f849d050000            je       0x3632fb                       
  0x00362D5E  d1ee                    shr      esi, 1                         
  0x00362D60  c1e602                  shl      esi, 2                         
  0x00362D63  f645f401                test     byte ptr [ebp - 0xc], 1        
  0x00362D67  8b5c35c8                mov      ebx, dword ptr [ebp + esi - 0x38] 
  0x00362D6B  8b7c35bc                mov      edi, dword ptr [ebp + esi - 0x44] 
  0x00362D6F  895d60                  mov      dword ptr [ebp + 0x60], ebx    
  0x00362D72  7445                    je       0x362db9                       
  0x00362D74  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00362D78  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x00362D7B  8d45ec                  lea      eax, [ebp - 0x14]              
  0x00362D7E  894d18                  mov      dword ptr [ebp + 0x18], ecx    
  0x00362D81  894d1c                  mov      dword ptr [ebp + 0x1c], ecx    
  0x00362D84  c7452001000000          mov      dword ptr [ebp + 0x20], 1      
  0x00362D8B  50                      push     eax                            
  0x00362D8C  7507                    jne      0x362d95                       
  0x00362D8E  e895efffff              call     0x361d28                       ; -> sub_00361D28
  0x00362D93  eb12                    jmp      0x362da7                       
                                        ; XREF: 0x00362D8C (cond_jump)
  0x00362D95  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00362D99  7507                    jne      0x362da2                       
  0x00362D9B  e834f2ffff              call     0x361fd4                       ; -> sub_00361FD4
  0x00362DA0  eb05                    jmp      0x362da7                       
                                        ; XREF: 0x00362D99 (cond_jump)
  0x00362DA2  e8c3f4ffff              call     0x36226a                       ; -> sub_0036226A
                                        ; XREF: 0x00362D93 (jump), 0x00362DA0 (jump)
  0x00362DA7  ff45f4                  inc      dword ptr [ebp - 0xc]          
  0x00362DAA  ff4514                  inc      dword ptr [ebp + 0x14]         
  0x00362DAD  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00362DB0  0f8445050000            je       0x3632fb                       
  0x00362DB6  8b4500                  mov      eax, dword ptr [ebp]           
                                        ; XREF: 0x00362D72 (cond_jump)
  0x00362DB9  f645fc01                test     byte ptr [ebp - 4], 1          
  0x00362DBD  7444                    je       0x362e03                       
  0x00362DBF  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00362DC2  8b4dfc                  mov      ecx, dword ptr [ebp - 4]       
  0x00362DC5  83651c00                and      dword ptr [ebp + 0x1c], 0      
  0x00362DC9  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00362DCD  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x00362DD0  8d45ec                  lea      eax, [ebp - 0x14]              
  0x00362DD3  894d18                  mov      dword ptr [ebp + 0x18], ecx    
  0x00362DD6  c7452001000000          mov      dword ptr [ebp + 0x20], 1      
  0x00362DDD  50                      push     eax                            
  0x00362DDE  7507                    jne      0x362de7                       
  0x00362DE0  e843efffff              call     0x361d28                       ; -> sub_00361D28
  0x00362DE5  eb12                    jmp      0x362df9                       
                                        ; XREF: 0x00362DDE (cond_jump)
  0x00362DE7  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00362DEB  7507                    jne      0x362df4                       
  0x00362DED  e8e2f1ffff              call     0x361fd4                       ; -> sub_00361FD4
  0x00362DF2  eb05                    jmp      0x362df9                       
                                        ; XREF: 0x00362DEB (cond_jump)
  0x00362DF4  e871f4ffff              call     0x36226a                       ; -> sub_0036226A
                                        ; XREF: 0x00362DE5 (jump), 0x00362DF2 (jump)
  0x00362DF9  837dfc00                cmp      dword ptr [ebp - 4], 0         
  0x00362DFD  0f84f8040000            je       0x3632fb                       
                                        ; XREF: 0x00362DBD (cond_jump)
  0x00362E03  8b4df4                  mov      ecx, dword ptr [ebp - 0xc]     
  0x00362E06  8b55fc                  mov      edx, dword ptr [ebp - 4]       
  0x00362E09  8bc3                    mov      eax, ebx                       
  0x00362E0B  03d9                    add      ebx, ecx                       
  0x00362E0D  f7d0                    not      eax                            
  0x00362E0F  03ca                    add      ecx, edx                       
  0x00362E11  23d8                    and      ebx, eax                       
  0x00362E13  23c8                    and      ecx, eax                       
  0x00362E15  3bd9                    cmp      ebx, ecx                       
  0x00362E17  0f8388040000            jae      0x3632a5                       
  0x00362E1D  8b4df8                  mov      ecx, dword ptr [ebp - 8]       
  0x00362E20  8b5d00                  mov      ebx, dword ptr [ebp]           
  0x00362E23  8d140f                  lea      edx, [edi + ecx]               
  0x00362E26  8bc7                    mov      eax, edi                       
  0x00362E28  f7d0                    not      eax                            
  0x00362E2A  03cb                    add      ecx, ebx                       
  0x00362E2C  23d0                    and      edx, eax                       
  0x00362E2E  23c8                    and      ecx, eax                       
  0x00362E30  3bd1                    cmp      edx, ecx                       
  0x00362E32  0f836d040000            jae      0x3632a5                       
  0x00362E38  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x00362E3B  3b4435e0                cmp      eax, dword ptr [ebp + esi - 0x20] 
  0x00362E3F  0f8260040000            jb       0x3632a5                       
  0x00362E45  8b450c                  mov      eax, dword ptr [ebp + 0xc]     
  0x00362E48  3b4435d4                cmp      eax, dword ptr [ebp + esi - 0x2c] 
  0x00362E4C  0f8253040000            jb       0x3632a5                       
  0x00362E52  8b75f8                  mov      esi, dword ptr [ebp - 8]       
  0x00362E55  33db                    xor      ebx, ebx                       
  0x00362E57  85fe                    test     esi, edi                       
  0x00362E59  743f                    je       0x362e9a                       
  0x00362E5B  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x00362E5E  f7de                    neg      esi                            
  0x00362E60  23f7                    and      esi, edi                       
  0x00362E62  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00362E66  894520                  mov      dword ptr [ebp + 0x20], eax    
  0x00362E69  8d45ec                  lea      eax, [ebp - 0x14]              
  0x00362E6C  895d18                  mov      dword ptr [ebp + 0x18], ebx    
  0x00362E6F  895d1c                  mov      dword ptr [ebp + 0x1c], ebx    
  0x00362E72  897524                  mov      dword ptr [ebp + 0x24], esi    
  0x00362E75  50                      push     eax                            
  0x00362E76  7507                    jne      0x362e7f                       
  0x00362E78  e844f5ffff              call     0x3623c1                       ; -> sub_003623C1
  0x00362E7D  eb12                    jmp      0x362e91                       
                                        ; XREF: 0x00362E76 (cond_jump)
  0x00362E7F  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00362E83  7507                    jne      0x362e8c                       
  0x00362E85  e8f3efffff              call     0x361e7d                       ; -> sub_00361E7D
  0x00362E8A  eb05                    jmp      0x362e91                       
                                        ; XREF: 0x00362E83 (cond_jump)
  0x00362E8C  e892f2ffff              call     0x362123                       ; -> sub_00362123
                                        ; XREF: 0x00362E7D (jump), 0x00362E8A (jump)
  0x00362E91  0175f8                  add      dword ptr [ebp - 8], esi       
  0x00362E94  017510                  add      dword ptr [ebp + 0x10], esi    
  0x00362E97  297500                  sub      dword ptr [ebp], esi           
                                        ; XREF: 0x00362E59 (cond_jump)
  0x00362E9A  8bc7                    mov      eax, edi                       
  0x00362E9C  234500                  and      eax, dword ptr [ebp]           
  0x00362E9F  7438                    je       0x362ed9                       
  0x00362EA1  294500                  sub      dword ptr [ebp], eax           
  0x00362EA4  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00362EA8  8b4d00                  mov      ecx, dword ptr [ebp]           
  0x00362EAB  894d1c                  mov      dword ptr [ebp + 0x1c], ecx    
  0x00362EAE  8b4dfc                  mov      ecx, dword ptr [ebp - 4]       
  0x00362EB1  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x00362EB4  8d45ec                  lea      eax, [ebp - 0x14]              
  0x00362EB7  895d18                  mov      dword ptr [ebp + 0x18], ebx    
  0x00362EBA  894d20                  mov      dword ptr [ebp + 0x20], ecx    
  0x00362EBD  50                      push     eax                            
  0x00362EBE  7507                    jne      0x362ec7                       
  0x00362EC0  e8fcf4ffff              call     0x3623c1                       ; -> sub_003623C1
  0x00362EC5  eb12                    jmp      0x362ed9                       
                                        ; XREF: 0x00362EBE (cond_jump)
  0x00362EC7  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00362ECB  7507                    jne      0x362ed4                       
  0x00362ECD  e8abefffff              call     0x361e7d                       ; -> sub_00361E7D
  0x00362ED2  eb05                    jmp      0x362ed9                       
                                        ; XREF: 0x00362ECB (cond_jump)
  0x00362ED4  e84af2ffff              call     0x362123                       ; -> sub_00362123
                                        ; XREF: 0x00362E9F (cond_jump), 0x00362EC5 (jump), 0x00362ED2 (jump)
  0x00362ED9  8b75f4                  mov      esi, dword ptr [ebp - 0xc]     
  0x00362EDC  857560                  test     dword ptr [ebp + 0x60], esi    
  0x00362EDF  7447                    je       0x362f28                       
  0x00362EE1  8b4500                  mov      eax, dword ptr [ebp]           
  0x00362EE4  f7de                    neg      esi                            
  0x00362EE6  237560                  and      esi, dword ptr [ebp + 0x60]    
  0x00362EE9  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00362EED  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x00362EF0  8d45ec                  lea      eax, [ebp - 0x14]              
  0x00362EF3  895d18                  mov      dword ptr [ebp + 0x18], ebx    
  0x00362EF6  895d1c                  mov      dword ptr [ebp + 0x1c], ebx    
  0x00362EF9  897520                  mov      dword ptr [ebp + 0x20], esi    
  0x00362EFC  50                      push     eax                            
  0x00362EFD  7507                    jne      0x362f06                       
  0x00362EFF  e8bdf4ffff              call     0x3623c1                       ; -> sub_003623C1
  0x00362F04  eb12                    jmp      0x362f18                       
                                        ; XREF: 0x00362EFD (cond_jump)
  0x00362F06  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00362F0A  7507                    jne      0x362f13                       
  0x00362F0C  e86cefffff              call     0x361e7d                       ; -> sub_00361E7D
  0x00362F11  eb05                    jmp      0x362f18                       
                                        ; XREF: 0x00362F0A (cond_jump)
  0x00362F13  e80bf2ffff              call     0x362123                       ; -> sub_00362123
                                        ; XREF: 0x00362F04 (jump), 0x00362F11 (jump)
  0x00362F18  8b7d14                  mov      edi, dword ptr [ebp + 0x14]    
  0x00362F1B  0175f4                  add      dword ptr [ebp - 0xc], esi     
  0x00362F1E  03fe                    add      edi, esi                       
  0x00362F20  2975fc                  sub      dword ptr [ebp - 4], esi       
  0x00362F23  897d14                  mov      dword ptr [ebp + 0x14], edi    
  0x00362F26  eb03                    jmp      0x362f2b                       
                                        ; XREF: 0x00362EDF (cond_jump)
  0x00362F28  8b7d14                  mov      edi, dword ptr [ebp + 0x14]    
                                        ; XREF: 0x00362F26 (jump)
  0x00362F2B  8b4560                  mov      eax, dword ptr [ebp + 0x60]    
  0x00362F2E  2345fc                  and      eax, dword ptr [ebp - 4]       
  0x00362F31  743b                    je       0x362f6e                       
  0x00362F33  2945fc                  sub      dword ptr [ebp - 4], eax       
  0x00362F36  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00362F3A  8b4dfc                  mov      ecx, dword ptr [ebp - 4]       
  0x00362F3D  894520                  mov      dword ptr [ebp + 0x20], eax    
  0x00362F40  8b4500                  mov      eax, dword ptr [ebp]           
  0x00362F43  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x00362F46  8d45ec                  lea      eax, [ebp - 0x14]              
  0x00362F49  894d18                  mov      dword ptr [ebp + 0x18], ecx    
  0x00362F4C  895d1c                  mov      dword ptr [ebp + 0x1c], ebx    
  0x00362F4F  50                      push     eax                            
  0x00362F50  7507                    jne      0x362f59                       
  0x00362F52  e86af4ffff              call     0x3623c1                       ; -> sub_003623C1
  0x00362F57  eb12                    jmp      0x362f6b                       
                                        ; XREF: 0x00362F50 (cond_jump)
  0x00362F59  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00362F5D  7507                    jne      0x362f66                       
  0x00362F5F  e819efffff              call     0x361e7d                       ; -> sub_00361E7D
  0x00362F64  eb05                    jmp      0x362f6b                       
                                        ; XREF: 0x00362F5D (cond_jump)
  0x00362F66  e8b8f1ffff              call     0x362123                       ; -> sub_00362123
                                        ; XREF: 0x00362F57 (jump), 0x00362F64 (jump)
  0x00362F6B  8b7d14                  mov      edi, dword ptr [ebp + 0x14]    
                                        ; XREF: 0x00362F31 (cond_jump)
  0x00362F6E  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00362F72  ff75f4                  push     dword ptr [ebp - 0xc]          
  0x00362F75  8b4538                  mov      eax, dword ptr [ebp + 0x38]    
  0x00362F78  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x00362F7B  0f850d010000            jne      0x36308e                       
  0x00362F81  83e0c0                  and      eax, 0xffffffc0                
  0x00362F84  894568                  mov      dword ptr [ebp + 0x68], eax    
  0x00362F87  8b453c                  mov      eax, dword ptr [ebp + 0x3c]    
  0x00362F8A  83e0e0                  and      eax, 0xffffffe0                
  0x00362F8D  894560                  mov      dword ptr [ebp + 0x60], eax    
  0x00362F90  e8aae5ffff              call     0x36153f                       ; -> sub_0036153F
  0x00362F95  ff75f8                  push     dword ptr [ebp - 8]            
  0x00362F98  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x00362F9B  89456c                  mov      dword ptr [ebp + 0x6c], eax    
  0x00362F9E  e8c5e5ffff              call     0x361568                       ; -> sub_00361568
  0x00362FA3  c16dfc03                shr      dword ptr [ebp - 4], 3         
  0x00362FA7  894578                  mov      dword ptr [ebp + 0x78], eax    
  0x00362FAA  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x00362FAD  0faf4510                imul     eax, dword ptr [ebp + 0x10]    
  0x00362FB1  034504                  add      eax, dword ptr [ebp + 4]       
  0x00362FB4  c16d0002                shr      dword ptr [ebp], 2             
  0x00362FB8  8d04b8                  lea      eax, [eax + edi*4]             
  0x00362FBB  894504                  mov      dword ptr [ebp + 4], eax       
  0x00362FBE  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x00362FC1  894570                  mov      dword ptr [ebp + 0x70], eax    
  0x00362FC4  8b75ec                  mov      esi, dword ptr [ebp - 0x14]    
  0x00362FC7  8b7d04                  mov      edi, dword ptr [ebp + 4]       
  0x00362FCA  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x00362FCD  c1e202                  shl      edx, 2                         
  0x00362FD0  8b5d6c                  mov      ebx, dword ptr [ebp + 0x6c]    
  0x00362FD3  8b4d78                  mov      ecx, dword ptr [ebp + 0x78]    
  0x00362FD6  897d74                  mov      dword ptr [ebp + 0x74], edi    
  0x00362FD9  eb03                    jmp      0x362fde                       
  0x00362FDB  8d4900                  lea      ecx, [ecx]                     
                                        ; XREF: 0x00362FD9 (jump), 0x0036305F (cond_jump), 0x00363083 (cond_jump)
  0x00362FDE  8bc3                    mov      eax, ebx                       
  0x00362FE0  0bc1                    or       eax, ecx                       
  0x00362FE2  2b5d68                  sub      ebx, dword ptr [ebp + 0x68]    
  0x00362FE5  0f280486                movaps   xmm0, xmmword ptr [esi + eax*4] 
  0x00362FE9  0f28548610              movaps   xmm2, xmmword ptr [esi + eax*4 + 0x10] 
  0x00362FEE  0f28648640              movaps   xmm4, xmmword ptr [esi + eax*4 + 0x40] 
  0x00362FF3  0f28748650              movaps   xmm6, xmmword ptr [esi + eax*4 + 0x50] 
  0x00362FF8  0f28c8                  movaps   xmm1, xmm0                     
  0x00362FFB  0f28ec                  movaps   xmm5, xmm4                     
  0x00362FFE  0f16c2                  movlhps  xmm0, xmm2                     
  0x00363001  0f12d1                  movhlps  xmm2, xmm1                     
  0x00363004  0f16e6                  movlhps  xmm4, xmm6                     
  0x00363007  0f12f5                  movhlps  xmm6, xmm5                     
  0x0036300A  0f284c8620              movaps   xmm1, xmmword ptr [esi + eax*4 + 0x20] 
  0x0036300F  0f285c8630              movaps   xmm3, xmmword ptr [esi + eax*4 + 0x30] 
  0x00363014  0f286c8660              movaps   xmm5, xmmword ptr [esi + eax*4 + 0x60] 
  0x00363019  0f287c8670              movaps   xmm7, xmmword ptr [esi + eax*4 + 0x70] 
  0x0036301E  0f1107                  movups   xmmword ptr [edi], xmm0        
  0x00363021  0f116710                movups   xmmword ptr [edi + 0x10], xmm4 
  0x00363025  0f111417                movups   xmmword ptr [edi + edx], xmm2  
  0x00363029  0f11741710              movups   xmmword ptr [edi + edx + 0x10], xmm6 
  0x0036302E  03fa                    add      edi, edx                       
  0x00363030  0f28c1                  movaps   xmm0, xmm1                     
  0x00363033  0f28e5                  movaps   xmm4, xmm5                     
  0x00363036  0f16cb                  movlhps  xmm1, xmm3                     
  0x00363039  0f12d8                  movhlps  xmm3, xmm0                     
  0x0036303C  0f16ef                  movlhps  xmm5, xmm7                     
  0x0036303F  0f12fc                  movhlps  xmm7, xmm4                     
  0x00363042  0f110c17                movups   xmmword ptr [edi + edx], xmm1  
  0x00363046  0f116c1710              movups   xmmword ptr [edi + edx + 0x10], xmm5 
  0x0036304B  0f111c57                movups   xmmword ptr [edi + edx*2], xmm3 
  0x0036304F  0f117c5710              movups   xmmword ptr [edi + edx*2 + 0x10], xmm7 
  0x00363054  2bfa                    sub      edi, edx                       
  0x00363056  83c720                  add      edi, 0x20                      
  0x00363059  235d38                  and      ebx, dword ptr [ebp + 0x38]    
  0x0036305C  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x0036305F  0f8579ffffff            jne      0x362fde                       
  0x00363065  8b4570                  mov      eax, dword ptr [ebp + 0x70]    
  0x00363068  8b5d6c                  mov      ebx, dword ptr [ebp + 0x6c]    
  0x0036306B  8945fc                  mov      dword ptr [ebp - 4], eax       
  0x0036306E  8b7d74                  mov      edi, dword ptr [ebp + 0x74]    
  0x00363071  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x00363074  2b4d60                  sub      ecx, dword ptr [ebp + 0x60]    
  0x00363077  8d3c87                  lea      edi, [edi + eax*4]             
  0x0036307A  234d3c                  and      ecx, dword ptr [ebp + 0x3c]    
  0x0036307D  897d74                  mov      dword ptr [ebp + 0x74], edi    
  0x00363080  ff4d00                  dec      dword ptr [ebp]                
  0x00363083  0f8555ffffff            jne      0x362fde                       
  0x00363089  e96d020000              jmp      0x3632fb                       
                                        ; XREF: 0x00362F7B (cond_jump)
  0x0036308E  2500ffffff              and      eax, 0xffffff00                
  0x00363093  894568                  mov      dword ptr [ebp + 0x68], eax    
  0x00363096  8b453c                  mov      eax, dword ptr [ebp + 0x3c]    
  0x00363099  83e0e0                  and      eax, 0xffffffe0                
  0x0036309C  894560                  mov      dword ptr [ebp + 0x60], eax    
  0x0036309F  e89be4ffff              call     0x36153f                       ; -> sub_0036153F
  0x003630A4  ff75f8                  push     dword ptr [ebp - 8]            
  0x003630A7  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x003630AA  89456c                  mov      dword ptr [ebp + 0x6c], eax    
  0x003630AD  e8b6e4ffff              call     0x361568                       ; -> sub_00361568
  0x003630B2  c16dfc04                shr      dword ptr [ebp - 4], 4         
  0x003630B6  894578                  mov      dword ptr [ebp + 0x78], eax    
  0x003630B9  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x003630BC  0faf4510                imul     eax, dword ptr [ebp + 0x10]    
  0x003630C0  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x003630C4  0f85f8000000            jne      0x3631c2                       
  0x003630CA  034504                  add      eax, dword ptr [ebp + 4]       
  0x003630CD  c16d0002                shr      dword ptr [ebp], 2             
  0x003630D1  8d0478                  lea      eax, [eax + edi*2]             
  0x003630D4  894504                  mov      dword ptr [ebp + 4], eax       
  0x003630D7  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x003630DA  894570                  mov      dword ptr [ebp + 0x70], eax    
  0x003630DD  8b75ec                  mov      esi, dword ptr [ebp - 0x14]    
  0x003630E0  8b7d04                  mov      edi, dword ptr [ebp + 4]       
  0x003630E3  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x003630E6  d1e2                    shl      edx, 1                         
  0x003630E8  8b5d6c                  mov      ebx, dword ptr [ebp + 0x6c]    
  0x003630EB  8b4d78                  mov      ecx, dword ptr [ebp + 0x78]    
  0x003630EE  897d74                  mov      dword ptr [ebp + 0x74], edi    
  0x003630F1  eb0b                    jmp      0x3630fe                       
  0x003630F3  8da42400000000          lea      esp, [esp]                     
  0x003630FA  8d642400                lea      esp, [esp]                     
                                        ; XREF: 0x003630F1 (jump), 0x00363193 (cond_jump), 0x003631B7 (cond_jump)
  0x003630FE  8bc3                    mov      eax, ebx                       
  0x00363100  2b5d68                  sub      ebx, dword ptr [ebp + 0x68]    
  0x00363103  0bc1                    or       eax, ecx                       
  0x00363105  0f280446                movaps   xmm0, xmmword ptr [esi + eax*2] 
  0x00363109  0f28644620              movaps   xmm4, xmmword ptr [esi + eax*2 + 0x20] 
  0x0036310E  0f28944680000000        movaps   xmm2, xmmword ptr [esi + eax*2 + 0x80] 
  0x00363116  0f28b446a0000000        movaps   xmm6, xmmword ptr [esi + eax*2 + 0xa0] 
  0x0036311E  0f28c8                  movaps   xmm1, xmm0                     
  0x00363121  0f28da                  movaps   xmm3, xmm2                     
  0x00363124  0fc6c488                shufps   xmm0, xmm4, 0x88               
  0x00363128  0fc6ccdd                shufps   xmm1, xmm4, 0xdd               
  0x0036312C  0fc6d688                shufps   xmm2, xmm6, 0x88               
  0x00363130  0fc6dedd                shufps   xmm3, xmm6, 0xdd               
  0x00363134  0f28644610              movaps   xmm4, xmmword ptr [esi + eax*2 + 0x10] 
  0x00363139  0f28744630              movaps   xmm6, xmmword ptr [esi + eax*2 + 0x30] 
  0x0036313E  0f28ac4690000000        movaps   xmm5, xmmword ptr [esi + eax*2 + 0x90] 
  0x00363146  0f28bc46b0000000        movaps   xmm7, xmmword ptr [esi + eax*2 + 0xb0] 
  0x0036314E  0f1107                  movups   xmmword ptr [edi], xmm0        
  0x00363151  0f115710                movups   xmmword ptr [edi + 0x10], xmm2 
  0x00363155  0f110c17                movups   xmmword ptr [edi + edx], xmm1  
  0x00363159  0f115c1710              movups   xmmword ptr [edi + edx + 0x10], xmm3 
  0x0036315E  03fa                    add      edi, edx                       
  0x00363160  0f28c4                  movaps   xmm0, xmm4                     
  0x00363163  0f28cd                  movaps   xmm1, xmm5                     
  0x00363166  0fc6c688                shufps   xmm0, xmm6, 0x88               
  0x0036316A  0fc6e6dd                shufps   xmm4, xmm6, 0xdd               
  0x0036316E  0fc6cf88                shufps   xmm1, xmm7, 0x88               
  0x00363172  0fc6efdd                shufps   xmm5, xmm7, 0xdd               
  0x00363176  0f110417                movups   xmmword ptr [edi + edx], xmm0  
  0x0036317A  0f114c1710              movups   xmmword ptr [edi + edx + 0x10], xmm1 
  0x0036317F  0f112457                movups   xmmword ptr [edi + edx*2], xmm4 
  0x00363183  0f116c5710              movups   xmmword ptr [edi + edx*2 + 0x10], xmm5 
  0x00363188  2bfa                    sub      edi, edx                       
  0x0036318A  83c720                  add      edi, 0x20                      
  0x0036318D  235d38                  and      ebx, dword ptr [ebp + 0x38]    
  0x00363190  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00363193  0f8565ffffff            jne      0x3630fe                       
  0x00363199  8b4570                  mov      eax, dword ptr [ebp + 0x70]    
  0x0036319C  8b5d6c                  mov      ebx, dword ptr [ebp + 0x6c]    
  0x0036319F  8945fc                  mov      dword ptr [ebp - 4], eax       
  0x003631A2  8b7d74                  mov      edi, dword ptr [ebp + 0x74]    
  0x003631A5  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x003631A8  2b4d60                  sub      ecx, dword ptr [ebp + 0x60]    
  0x003631AB  8d3c87                  lea      edi, [edi + eax*4]             
  0x003631AE  234d3c                  and      ecx, dword ptr [ebp + 0x3c]    
  0x003631B1  897d74                  mov      dword ptr [ebp + 0x74], edi    
  0x003631B4  ff4d00                  dec      dword ptr [ebp]                
  0x003631B7  0f8541ffffff            jne      0x3630fe                       
  0x003631BD  e939010000              jmp      0x3632fb                       
                                        ; XREF: 0x003630C4 (cond_jump)
  0x003631C2  0faf7d28                imul     edi, dword ptr [ebp + 0x28]    
  0x003631C6  037d04                  add      edi, dword ptr [ebp + 4]       
  0x003631C9  03f8                    add      edi, eax                       
  0x003631CB  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x003631CE  c16d0002                shr      dword ptr [ebp], 2             
  0x003631D2  897d04                  mov      dword ptr [ebp + 4], edi       
  0x003631D5  894570                  mov      dword ptr [ebp + 0x70], eax    
  0x003631D8  8b75ec                  mov      esi, dword ptr [ebp - 0x14]    
  0x003631DB  8b7d04                  mov      edi, dword ptr [ebp + 4]       
  0x003631DE  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x003631E1  8b5d6c                  mov      ebx, dword ptr [ebp + 0x6c]    
  0x003631E4  8b4d78                  mov      ecx, dword ptr [ebp + 0x78]    
  0x003631E7  897d74                  mov      dword ptr [ebp + 0x74], edi    
  0x003631EA  8d642400                lea      esp, [esp]                     
                                        ; XREF: 0x00363277 (cond_jump), 0x0036329B (cond_jump)
  0x003631EE  8bc3                    mov      eax, ebx                       
  0x003631F0  2b5d68                  sub      ebx, dword ptr [ebp + 0x68]    
  0x003631F3  0bc1                    or       eax, ecx                       
  0x003631F5  0f700406d8              pshufw   mm0, qword ptr [esi + eax], 0xd8 
  0x003631FA  0f70540640d8            pshufw   mm2, qword ptr [esi + eax + 0x40], 0xd8 
  0x00363200  0f70640610d8            pshufw   mm4, qword ptr [esi + eax + 0x10], 0xd8 
  0x00363206  0f70740650d8            pshufw   mm6, qword ptr [esi + eax + 0x50], 0xd8 
  0x0036320C  0f7fc1                  movq     mm1, mm0                       
  0x0036320F  0f7fd3                  movq     mm3, mm2                       
  0x00363212  0f62c4                  punpckldq mm0, mm4                       
  0x00363215  0f6acc                  punpckhdq mm1, mm4                       
  0x00363218  0f62d6                  punpckldq mm2, mm6                       
  0x0036321B  0f6ade                  punpckhdq mm3, mm6                       
  0x0036321E  0f7f07                  movq     qword ptr [edi], mm0           
  0x00363221  0f7f5708                movq     qword ptr [edi + 8], mm2       
  0x00363225  0f7f0c17                movq     qword ptr [edi + edx], mm1     
  0x00363229  0f7f5c1708              movq     qword ptr [edi + edx + 8], mm3 
  0x0036322E  03fa                    add      edi, edx                       
  0x00363230  0f70640608d8            pshufw   mm4, qword ptr [esi + eax + 8], 0xd8 
  0x00363236  0f706c0648d8            pshufw   mm5, qword ptr [esi + eax + 0x48], 0xd8 
  0x0036323C  0f70740618d8            pshufw   mm6, qword ptr [esi + eax + 0x18], 0xd8 
  0x00363242  0f707c0658d8            pshufw   mm7, qword ptr [esi + eax + 0x58], 0xd8 
  0x00363248  0f7fe0                  movq     mm0, mm4                       
  0x0036324B  0f7fe9                  movq     mm1, mm5                       
  0x0036324E  0f62c6                  punpckldq mm0, mm6                       
  0x00363251  0f6ae6                  punpckhdq mm4, mm6                       
  0x00363254  0f62cf                  punpckldq mm1, mm7                       
  0x00363257  0f6aef                  punpckhdq mm5, mm7                       
  0x0036325A  0f7f0417                movq     qword ptr [edi + edx], mm0     
  0x0036325E  0f7f4c1708              movq     qword ptr [edi + edx + 8], mm1 
  0x00363263  0f7f2457                movq     qword ptr [edi + edx*2], mm4   
  0x00363267  0f7f6c5708              movq     qword ptr [edi + edx*2 + 8], mm5 
  0x0036326C  2bfa                    sub      edi, edx                       
  0x0036326E  83c710                  add      edi, 0x10                      
  0x00363271  235d38                  and      ebx, dword ptr [ebp + 0x38]    
  0x00363274  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00363277  0f8571ffffff            jne      0x3631ee                       
  0x0036327D  8b4570                  mov      eax, dword ptr [ebp + 0x70]    
  0x00363280  8b5d6c                  mov      ebx, dword ptr [ebp + 0x6c]    
  0x00363283  8945fc                  mov      dword ptr [ebp - 4], eax       
  0x00363286  8b7d74                  mov      edi, dword ptr [ebp + 0x74]    
  0x00363289  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x0036328C  2b4d60                  sub      ecx, dword ptr [ebp + 0x60]    
  0x0036328F  8d3c87                  lea      edi, [edi + eax*4]             
  0x00363292  234d3c                  and      ecx, dword ptr [ebp + 0x3c]    
  0x00363295  897d74                  mov      dword ptr [ebp + 0x74], edi    
  0x00363298  ff4d00                  dec      dword ptr [ebp]                
  0x0036329B  0f854dffffff            jne      0x3631ee                       
  0x003632A1  0f77                    emms                                    
  0x003632A3  eb56                    jmp      0x3632fb                       
                                        ; XREF: 0x00362E17 (cond_jump), 0x00362E32 (cond_jump), 0x00362E3F (cond_jump), 0x00362E4C (cond_jump)
  0x003632A5  8b4500                  mov      eax, dword ptr [ebp]           
  0x003632A8  83651800                and      dword ptr [ebp + 0x18], 0      
  0x003632AC  83651c00                and      dword ptr [ebp + 0x1c], 0      
  0x003632B0  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x003632B4  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x003632B7  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x003632BA  894520                  mov      dword ptr [ebp + 0x20], eax    
  0x003632BD  8d45ec                  lea      eax, [ebp - 0x14]              
  0x003632C0  50                      push     eax                            
  0x003632C1  7507                    jne      0x3632ca                       
  0x003632C3  e8f9f0ffff              call     0x3623c1                       ; -> sub_003623C1
  0x003632C8  eb31                    jmp      0x3632fb                       
                                        ; XREF: 0x003632C1 (cond_jump)
  0x003632CA  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x003632CE  7507                    jne      0x3632d7                       
  0x003632D0  e8a8ebffff              call     0x361e7d                       ; -> sub_00361E7D
  0x003632D5  eb24                    jmp      0x3632fb                       
                                        ; XREF: 0x003632CE (cond_jump)
  0x003632D7  e847eeffff              call     0x362123                       ; -> sub_00362123
  0x003632DC  eb1d                    jmp      0x3632fb                       
                                        ; XREF: 0x00362C36 (cond_jump), 0x00362C42 (cond_jump)
  0x003632DE  8b7560                  mov      esi, dword ptr [ebp + 0x60]    
  0x003632E1  8b7d70                  mov      edi, dword ptr [ebp + 0x70]    
  0x003632E4  8bcb                    mov      ecx, ebx                       
  0x003632E6  0faf4d68                imul     ecx, dword ptr [ebp + 0x68]    
  0x003632EA  0faf4d7c                imul     ecx, dword ptr [ebp + 0x7c]    
  0x003632EE  8bc1                    mov      eax, ecx                       
  0x003632F0  c1e902                  shr      ecx, 2                         
  0x003632F3  f3a5                    rep movsd dword ptr es:[edi], dword ptr [esi] 
  0x003632F5  8bc8                    mov      ecx, eax                       
  0x003632F7  23ca                    and      ecx, edx                       
  0x003632F9  f3a4                    rep movsb byte ptr es:[edi], byte ptr [esi] 
                                        ; XREF: 0x00362C76 (jump), 0x00362C95 (jump), 0x00362CAF (jump), 0x00362D4F (cond_jump), 0x00362D58 (cond_jump), ... (+8 more)
  0x003632FB  5f                      pop      edi                            
  0x003632FC  5e                      pop      esi                            
  0x003632FD  5b                      pop      ebx                            
  0x003632FE  83c558                  add      ebp, 0x58                      
  0x00363301  c9                      leave                                   
  0x00363302  c22000                  ret      0x20                           
; end of function
  0x00363305  cc                      int3                                    
  0x00363306  cc                      int3                                    
  0x00363307  cc                      int3                                    

; ============================================================
; Function: sub_00363308
; Start: 0x00363308  End: 0x0036334C  Size: 68 bytes
; Detection: cc_boundary (confidence: 0.85)
; ============================================================
sub_00363308:
  0x00363308  0909                    or       dword ptr [ecx], ecx           
  0x0036330A  11911191a1a1            adc      dword ptr [ecx - 0x5e5e6eef], edx 
  0x00363310  0000                    add      byte ptr [eax], al             
  0x00363312  0009                    add      byte ptr [ecx], cl             
  0x00363314  0400                    add      al, 0                          
  0x00363316  0808                    or       byte ptr [eax], cl             
  0x00363318  1292a20a0000            adc      dl, byte ptr [edx + 0xaa2]     
  0x0036331E  1212                    adc      dl, byte ptr [edx]             
  0x00363320  0009                    add      byte ptr [ecx], cl             
  0x00363322  110a                    adc      dword ptr [edx], ecx           
  0x00363324  92                      xchg     edx, eax                       
  0x00363325  12a20a120000            adc      ah, byte ptr [edx + 0x120a]    
  0x0036332B  0010                    add      byte ptr [eax], dl             
  0x0036332D  1000                    adc      byte ptr [eax], al             
  0x0036332F  1111                    adc      dword ptr [ecx], edx           
  0x00363331  116161                  adc      dword ptr [ecx + 0x61], esp    
  0x00363334  51                      push     ecx                            
  0x00363335  51                      push     ecx                            
  0x00363336  626252                  bound    esp, qword ptr [edx + 0x52]    
  0x00363339  52                      push     edx                            
  0x0036333A  1121                    adc      dword ptr [ecx], esp           
  0x0036333C  0012                    add      byte ptr [edx], dl             
  0x0036333E  0012                    add      byte ptr [edx], dl             
  0x00363340  1111                    adc      dword ptr [ecx], edx           
  0x00363342  2121                    and      dword ptr [ecx], esp           
  0x00363344  2112                    and      dword ptr [edx], edx           
  0x00363346  1222                    adc      ah, byte ptr [edx]             
  0x00363348  2222                    and      ah, byte ptr [edx]             
  0x0036334A  0000                    add      byte ptr [eax], al             
; end of function
