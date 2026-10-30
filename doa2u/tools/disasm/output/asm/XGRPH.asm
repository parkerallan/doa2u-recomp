; ============================================================
; Section: XGRPH
; VA: 0x00364BE0 - 0x00366D2C
; Size: 8524 bytes (8.3 KB)
; Functions: 36
; Instructions: 3147
; ============================================================


; ============================================================
; Function: sub_00364BE0
; Start: 0x00364BE0  End: 0x00364BFC  Size: 28 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_00364C06, sub_00364C19
; ============================================================
sub_00364BE0:
  0x00364BE0  8b442404                mov      eax, dword ptr [esp + 4]       
  0x00364BE4  83f80c                  cmp      eax, 0xc                       
  0x00364BE7  740e                    je       0x364bf7                       
  0x00364BE9  83f80d                  cmp      eax, 0xd                       
  0x00364BEC  7605                    jbe      0x364bf3                       
  0x00364BEE  83f80f                  cmp      eax, 0xf                       
  0x00364BF1  7604                    jbe      0x364bf7                       
                                        ; XREF: 0x00364BEC (cond_jump)
  0x00364BF3  32c0                    xor      al, al                         
  0x00364BF5  eb02                    jmp      0x364bf9                       
                                        ; XREF: 0x00364BE7 (cond_jump), 0x00364BF1 (cond_jump)
  0x00364BF7  b001                    mov      al, 1                          
                                        ; XREF: 0x00364BF5 (jump)
  0x00364BF9  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00364BFC
; Start: 0x00364BFC  End: 0x00364C06  Size: 10 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_00364C19, sub_00364F71
; ============================================================
sub_00364BFC:
  0x00364BFC  51                      push     ecx                            
  0x00364BFD  890c24                  mov      dword ptr [esp], ecx           
  0x00364C00  0fbc0424                bsf      eax, dword ptr [esp]           
  0x00364C04  59                      pop      ecx                            
  0x00364C05  c3                      ret                                     
; end of function

; ============================================================
; Function: sub_00364C06
; Start: 0x00364C06  End: 0x00364C19  Size: 19 bytes
; Detection: call_target (confidence: 0.90)
; Calls: sub_00364BE0
; Called by: sub_00364C19
; ============================================================
sub_00364C06:
  0x00364C06  ff742404                push     dword ptr [esp + 4]            
  0x00364C0A  e8d1ffffff              call     0x364be0                       ; -> sub_00364BE0
  0x00364C0F  f6d8                    neg      al                             
  0x00364C11  1bc0                    sbb      eax, eax                       
  0x00364C13  83e002                  and      eax, 2                         
  0x00364C16  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00364C19
; Start: 0x00364C19  End: 0x00364DB8  Size: 415 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364BE0, sub_00364BFC, sub_00364C06
; Called by: sub_00364DB8, sub_00364E04
; ============================================================
sub_00364C19:
  0x00364C19  55                      push     ebp                            
  0x00364C1A  8bec                    mov      ebp, esp                       
  0x00364C1C  83ec14                  sub      esp, 0x14                      
  0x00364C1F  8b4d18                  mov      ecx, dword ptr [ebp + 0x18]    
  0x00364C22  8a81e86c3600            mov      al, byte ptr [ecx + 0x366ce8]  
  0x00364C28  33d2                    xor      edx, edx                       
  0x00364C2A  8ad0                    mov      dl, al                         
  0x00364C2C  53                      push     ebx                            
  0x00364C2D  8a5d20                  mov      bl, byte ptr [ebp + 0x20]      
  0x00364C30  56                      push     esi                            
  0x00364C31  57                      push     edi                            
  0x00364C32  33f6                    xor      esi, esi                       
  0x00364C34  8975fc                  mov      dword ptr [ebp - 4], esi       
  0x00364C37  83e23c                  and      edx, 0x3c                      
  0x00364C3A  a801                    test     al, 1                          
  0x00364C3C  8bfa                    mov      edi, edx                       
  0x00364C3E  897dec                  mov      dword ptr [ebp - 0x14], edi    
  0x00364C41  7547                    jne      0x364c8a                       
  0x00364C43  51                      push     ecx                            
  0x00364C44  e897ffffff              call     0x364be0                       ; -> sub_00364BE0
  0x00364C49  84c0                    test     al, al                         
  0x00364C4B  753d                    jne      0x364c8a                       
  0x00364C4D  33c0                    xor      eax, eax                       
  0x00364C4F  394514                  cmp      dword ptr [ebp + 0x14], eax    
  0x00364C52  8945f4                  mov      dword ptr [ebp - 0xc], eax     
  0x00364C55  8945f8                  mov      dword ptr [ebp - 8], eax       
  0x00364C58  7507                    jne      0x364c61                       
  0x00364C5A  c7451401000000          mov      dword ptr [ebp + 0x14], 1      
                                        ; XREF: 0x00364C58 (cond_jump)
  0x00364C61  8b4d1c                  mov      ecx, dword ptr [ebp + 0x1c]    
  0x00364C64  3bc8                    cmp      ecx, eax                       
  0x00364C66  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x00364C69  750e                    jne      0x364c79                       
  0x00364C6B  0faff8                  imul     edi, eax                       
  0x00364C6E  c1ef03                  shr      edi, 3                         
  0x00364C71  83c73f                  add      edi, 0x3f                      
  0x00364C74  83e7c0                  and      edi, 0xffffffc0                
  0x00364C77  8bcf                    mov      ecx, edi                       
                                        ; XREF: 0x00364C69 (cond_jump)
  0x00364C79  894510                  mov      dword ptr [ebp + 0x10], eax    
  0x00364C7C  8b450c                  mov      eax, dword ptr [ebp + 0xc]     
  0x00364C7F  8945f0                  mov      dword ptr [ebp - 0x10], eax    
  0x00364C82  0fafc1                  imul     eax, ecx                       
  0x00364C85  e9bf000000              jmp      0x364d49                       
                                        ; XREF: 0x00364C41 (cond_jump), 0x00364C4B (cond_jump)
  0x00364C8A  8b4d08                  mov      ecx, dword ptr [ebp + 8]       
  0x00364C8D  e86affffff              call     0x364bfc                       ; -> sub_00364BFC
  0x00364C92  8b4d0c                  mov      ecx, dword ptr [ebp + 0xc]     
  0x00364C95  8945f8                  mov      dword ptr [ebp - 8], eax       
  0x00364C98  e85fffffff              call     0x364bfc                       ; -> sub_00364BFC
  0x00364C9D  8b4d10                  mov      ecx, dword ptr [ebp + 0x10]    
  0x00364CA0  8bf8                    mov      edi, eax                       
  0x00364CA2  897df4                  mov      dword ptr [ebp - 0xc], edi     
  0x00364CA5  e852ffffff              call     0x364bfc                       ; -> sub_00364BFC
  0x00364CAA  ff7518                  push     dword ptr [ebp + 0x18]         
  0x00364CAD  83651000                and      dword ptr [ebp + 0x10], 0      
  0x00364CB1  8365f000                and      dword ptr [ebp - 0x10], 0      
  0x00364CB5  8bf0                    mov      esi, eax                       
  0x00364CB7  e84affffff              call     0x364c06                       ; -> sub_00364C06
  0x00364CBC  837d1400                cmp      dword ptr [ebp + 0x14], 0      
  0x00364CC0  894508                  mov      dword ptr [ebp + 8], eax       
  0x00364CC3  751e                    jne      0x364ce3                       
  0x00364CC5  3bfe                    cmp      edi, esi                       
  0x00364CC7  8bcf                    mov      ecx, edi                       
  0x00364CC9  7702                    ja       0x364ccd                       
  0x00364CCB  8bce                    mov      ecx, esi                       
                                        ; XREF: 0x00364CC9 (cond_jump)
  0x00364CCD  394df8                  cmp      dword ptr [ebp - 8], ecx       
  0x00364CD0  7605                    jbe      0x364cd7                       
  0x00364CD2  8b4df8                  mov      ecx, dword ptr [ebp - 8]       
  0x00364CD5  eb08                    jmp      0x364cdf                       
                                        ; XREF: 0x00364CD0 (cond_jump)
  0x00364CD7  3bfe                    cmp      edi, esi                       
  0x00364CD9  8bcf                    mov      ecx, edi                       
  0x00364CDB  7702                    ja       0x364cdf                       
  0x00364CDD  8bce                    mov      ecx, esi                       
                                        ; XREF: 0x00364CD5 (jump), 0x00364CDB (cond_jump)
  0x00364CDF  41                      inc      ecx                            
  0x00364CE0  894d14                  mov      dword ptr [ebp + 0x14], ecx    
                                        ; XREF: 0x00364CC3 (cond_jump)
  0x00364CE3  8b4d14                  mov      ecx, dword ptr [ebp + 0x14]    
  0x00364CE6  85c9                    test     ecx, ecx                       
  0x00364CE8  8b45f8                  mov      eax, dword ptr [ebp - 8]       
  0x00364CEB  897d20                  mov      dword ptr [ebp + 0x20], edi    
  0x00364CEE  8bfe                    mov      edi, esi                       
  0x00364CF0  7442                    je       0x364d34                       
  0x00364CF2  894d0c                  mov      dword ptr [ebp + 0xc], ecx     
                                        ; XREF: 0x00364D32 (cond_jump)
  0x00364CF5  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x00364CF8  3bc2                    cmp      eax, edx                       
  0x00364CFA  7602                    jbe      0x364cfe                       
  0x00364CFC  8bd0                    mov      edx, eax                       
                                        ; XREF: 0x00364CFA (cond_jump)
  0x00364CFE  8b4d08                  mov      ecx, dword ptr [ebp + 8]       
  0x00364D01  394d20                  cmp      dword ptr [ebp + 0x20], ecx    
  0x00364D04  7603                    jbe      0x364d09                       
  0x00364D06  8b4d20                  mov      ecx, dword ptr [ebp + 0x20]    
                                        ; XREF: 0x00364D04 (cond_jump)
  0x00364D09  03ca                    add      ecx, edx                       
  0x00364D0B  33d2                    xor      edx, edx                       
  0x00364D0D  42                      inc      edx                            
  0x00364D0E  03cf                    add      ecx, edi                       
  0x00364D10  d3e2                    shl      edx, cl                        
  0x00364D12  0faf55ec                imul     edx, dword ptr [ebp - 0x14]    
  0x00364D16  c1ea03                  shr      edx, 3                         
  0x00364D19  0155fc                  add      dword ptr [ebp - 4], edx       
  0x00364D1C  85c0                    test     eax, eax                       
  0x00364D1E  7601                    jbe      0x364d21                       
  0x00364D20  48                      dec      eax                            
                                        ; XREF: 0x00364D1E (cond_jump)
  0x00364D21  837d2000                cmp      dword ptr [ebp + 0x20], 0      
  0x00364D25  7603                    jbe      0x364d2a                       
  0x00364D27  ff4d20                  dec      dword ptr [ebp + 0x20]         
                                        ; XREF: 0x00364D25 (cond_jump)
  0x00364D2A  85ff                    test     edi, edi                       
  0x00364D2C  7601                    jbe      0x364d2f                       
  0x00364D2E  4f                      dec      edi                            
                                        ; XREF: 0x00364D2C (cond_jump)
  0x00364D2F  ff4d0c                  dec      dword ptr [ebp + 0xc]          
  0x00364D32  75c1                    jne      0x364cf5                       
                                        ; XREF: 0x00364CF0 (cond_jump)
  0x00364D34  84db                    test     bl, bl                         
  0x00364D36  8b4d1c                  mov      ecx, dword ptr [ebp + 0x1c]    
  0x00364D39  7411                    je       0x364d4c                       
  0x00364D3B  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x00364D3E  83c07f                  add      eax, 0x7f                      
  0x00364D41  83e080                  and      eax, 0xffffff80                
  0x00364D44  8d0440                  lea      eax, [eax + eax*2]             
  0x00364D47  d1e0                    shl      eax, 1                         
                                        ; XREF: 0x00364C85 (jump)
  0x00364D49  8945fc                  mov      dword ptr [ebp - 4], eax       
                                        ; XREF: 0x00364D39 (cond_jump)
  0x00364D4C  c1e604                  shl      esi, 4                         
  0x00364D4F  0b75f4                  or       esi, dword ptr [ebp - 0xc]     
  0x00364D52  33c0                    xor      eax, eax                       
  0x00364D54  c1e604                  shl      esi, 4                         
  0x00364D57  0b75f8                  or       esi, dword ptr [ebp - 8]       
  0x00364D5A  5f                      pop      edi                            
  0x00364D5B  c1e604                  shl      esi, 4                         
  0x00364D5E  0b7514                  or       esi, dword ptr [ebp + 0x14]    
  0x00364D61  c1e608                  shl      esi, 8                         
  0x00364D64  0b7518                  or       esi, dword ptr [ebp + 0x18]    
  0x00364D67  c1e604                  shl      esi, 4                         
  0x00364D6A  384524                  cmp      byte ptr [ebp + 0x24], al      
  0x00364D6D  0f95c0                  setne    al                             
  0x00364D70  40                      inc      eax                            
  0x00364D71  40                      inc      eax                            
  0x00364D72  0bf0                    or       esi, eax                       
  0x00364D74  8b4528                  mov      eax, dword ptr [ebp + 0x28]    
  0x00364D77  c1e604                  shl      esi, 4                         
  0x00364D7A  f6db                    neg      bl                             
  0x00364D7C  1bdb                    sbb      ebx, ebx                       
  0x00364D7E  83e304                  and      ebx, 4                         
  0x00364D81  0bf3                    or       esi, ebx                       
  0x00364D83  83ce09                  or       esi, 9                         
  0x00364D86  8930                    mov      dword ptr [eax], esi           
  0x00364D88  8b4510                  mov      eax, dword ptr [ebp + 0x10]    
  0x00364D8B  85c0                    test     eax, eax                       
  0x00364D8D  5e                      pop      esi                            
  0x00364D8E  5b                      pop      ebx                            
  0x00364D8F  741a                    je       0x364dab                       
  0x00364D91  8b55f0                  mov      edx, dword ptr [ebp - 0x10]    
  0x00364D94  c1e906                  shr      ecx, 6                         
  0x00364D97  49                      dec      ecx                            
  0x00364D98  c1e10c                  shl      ecx, 0xc                       
  0x00364D9B  4a                      dec      edx                            
  0x00364D9C  0bca                    or       ecx, edx                       
  0x00364D9E  c1e10c                  shl      ecx, 0xc                       
  0x00364DA1  48                      dec      eax                            
  0x00364DA2  0bc8                    or       ecx, eax                       
  0x00364DA4  8b452c                  mov      eax, dword ptr [ebp + 0x2c]    
  0x00364DA7  8908                    mov      dword ptr [eax], ecx           
  0x00364DA9  eb06                    jmp      0x364db1                       
                                        ; XREF: 0x00364D8F (cond_jump)
  0x00364DAB  8b452c                  mov      eax, dword ptr [ebp + 0x2c]    
  0x00364DAE  832000                  and      dword ptr [eax], 0             
                                        ; XREF: 0x00364DA9 (jump)
  0x00364DB1  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x00364DB4  c9                      leave                                   
  0x00364DB5  c22800                  ret      0x28                           
; end of function

; ============================================================
; Function: sub_00364DB8
; Start: 0x00364DB8  End: 0x00364E04  Size: 76 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364C19
; Called by: sub_00364E45
; ============================================================
sub_00364DB8:
  0x00364DB8  55                      push     ebp                            
  0x00364DB9  8bec                    mov      ebp, esp                       
  0x00364DBB  56                      push     esi                            
  0x00364DBC  8b7530                  mov      esi, dword ptr [ebp + 0x30]    
  0x00364DBF  57                      push     edi                            
  0x00364DC0  8d4610                  lea      eax, [esi + 0x10]              
  0x00364DC3  50                      push     eax                            
  0x00364DC4  8d7e0c                  lea      edi, [esi + 0xc]               
  0x00364DC7  57                      push     edi                            
  0x00364DC8  ff7528                  push     dword ptr [ebp + 0x28]         
  0x00364DCB  ff7524                  push     dword ptr [ebp + 0x24]         
  0x00364DCE  ff7520                  push     dword ptr [ebp + 0x20]         
  0x00364DD1  ff751c                  push     dword ptr [ebp + 0x1c]         
  0x00364DD4  ff7514                  push     dword ptr [ebp + 0x14]         
  0x00364DD7  ff7510                  push     dword ptr [ebp + 0x10]         
  0x00364DDA  ff750c                  push     dword ptr [ebp + 0xc]          
  0x00364DDD  ff7508                  push     dword ptr [ebp + 8]            
  0x00364DE0  e834feffff              call     0x364c19                       ; -> sub_00364C19
  0x00364DE5  f6451a01                test     byte ptr [ebp + 0x1a], 1       
  0x00364DE9  7403                    je       0x364dee                       
  0x00364DEB  8327f7                  and      dword ptr [edi], 0xfffffff7    
                                        ; XREF: 0x00364DE9 (cond_jump)
  0x00364DEE  8b4d2c                  mov      ecx, dword ptr [ebp + 0x2c]    
  0x00364DF1  83660800                and      dword ptr [esi + 8], 0         
  0x00364DF5  5f                      pop      edi                            
  0x00364DF6  c70601000400            mov      dword ptr [esi], 0x40001       
  0x00364DFC  894e04                  mov      dword ptr [esi + 4], ecx       
  0x00364DFF  5e                      pop      esi                            
  0x00364E00  5d                      pop      ebp                            
  0x00364E01  c22c00                  ret      0x2c                           
; end of function

; ============================================================
; Function: sub_00364E04
; Start: 0x00364E04  End: 0x00364E45  Size: 65 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364C19
; Called by: sub_0005BF40, sub_000B0710, sub_00197AE0, sub_001E79F0, sub_002785D0, sub_0027CA40, sub_00284D70
; ============================================================
sub_00364E04:
  0x00364E04  55                      push     ebp                            
  0x00364E05  8bec                    mov      ebp, esp                       
  0x00364E07  56                      push     esi                            
  0x00364E08  8b7514                  mov      esi, dword ptr [ebp + 0x14]    
  0x00364E0B  8d4610                  lea      eax, [esi + 0x10]              
  0x00364E0E  50                      push     eax                            
  0x00364E0F  8d460c                  lea      eax, [esi + 0xc]               
  0x00364E12  50                      push     eax                            
  0x00364E13  6a00                    push     0                              
  0x00364E15  6a00                    push     0                              
  0x00364E17  ff751c                  push     dword ptr [ebp + 0x1c]         
  0x00364E1A  ff7510                  push     dword ptr [ebp + 0x10]         
  0x00364E1D  6a01                    push     1                              
  0x00364E1F  6a01                    push     1                              
  0x00364E21  ff750c                  push     dword ptr [ebp + 0xc]          
  0x00364E24  ff7508                  push     dword ptr [ebp + 8]            
  0x00364E27  e8edfdffff              call     0x364c19                       ; -> sub_00364C19
  0x00364E2C  83660800                and      dword ptr [esi + 8], 0         
  0x00364E30  8b4d18                  mov      ecx, dword ptr [ebp + 0x18]    
  0x00364E33  83661400                and      dword ptr [esi + 0x14], 0      
  0x00364E37  c70601000500            mov      dword ptr [esi], 0x50001       
  0x00364E3D  894e04                  mov      dword ptr [esi + 4], ecx       
  0x00364E40  5e                      pop      esi                            
  0x00364E41  5d                      pop      ebp                            
  0x00364E42  c21800                  ret      0x18                           
; end of function

; ============================================================
; Function: sub_00364E45
; Start: 0x00364E45  End: 0x00364E6F  Size: 42 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364DB8
; Called by: sub_000A88D0, sub_000A9A30, sub_000AA0E0, sub_000AE0B0, sub_000AF470, sub_000AF4B0, sub_000B0710, sub_000B07C0, sub_000FB9E0, sub_0016A050 ... (+18 more)
; ============================================================
sub_00364E45:
  0x00364E45  55                      push     ebp                            
  0x00364E46  8bec                    mov      ebp, esp                       
  0x00364E48  ff7520                  push     dword ptr [ebp + 0x20]         
  0x00364E4B  ff7524                  push     dword ptr [ebp + 0x24]         
  0x00364E4E  6a00                    push     0                              
  0x00364E50  6a00                    push     0                              
  0x00364E52  ff7528                  push     dword ptr [ebp + 0x28]         
  0x00364E55  ff7518                  push     dword ptr [ebp + 0x18]         
  0x00364E58  ff7514                  push     dword ptr [ebp + 0x14]         
  0x00364E5B  ff7510                  push     dword ptr [ebp + 0x10]         
  0x00364E5E  6a01                    push     1                              
  0x00364E60  ff750c                  push     dword ptr [ebp + 0xc]          
  0x00364E63  ff7508                  push     dword ptr [ebp + 8]            
  0x00364E66  e84dffffff              call     0x364db8                       ; -> sub_00364DB8
  0x00364E6B  5d                      pop      ebp                            
  0x00364E6C  c22400                  ret      0x24                           
; end of function

; ============================================================
; Function: sub_00364E6F
; Start: 0x00364E6F  End: 0x00364E87  Size: 24 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_0019D940, sub_001D9610, sub_001F6E80, sub_001F79F0, sub_001FD390
; ============================================================
sub_00364E6F:
  0x00364E6F  8b442414                mov      eax, dword ptr [esp + 0x14]    
  0x00364E73  8b4c2418                mov      ecx, dword ptr [esp + 0x18]    
  0x00364E77  83600800                and      dword ptr [eax + 8], 0         
  0x00364E7B  c70001000000            mov      dword ptr [eax], 1             
  0x00364E81  894804                  mov      dword ptr [eax + 4], ecx       
  0x00364E84  c21800                  ret      0x18                           
; end of function

; ============================================================
; Function: sub_00364E87
; Start: 0x00364E87  End: 0x00364E9F  Size: 24 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_0028CB60
; ============================================================
sub_00364E87:
  0x00364E87  8b442414                mov      eax, dword ptr [esp + 0x14]    
  0x00364E8B  8b4c2418                mov      ecx, dword ptr [esp + 0x18]    
  0x00364E8F  83600800                and      dword ptr [eax + 8], 0         
  0x00364E93  c70001000100            mov      dword ptr [eax], 0x10001       
  0x00364E99  894804                  mov      dword ptr [eax + 4], ecx       
  0x00364E9C  c21800                  ret      0x18                           
; end of function

; ============================================================
; Function: sub_00364E9F
; Start: 0x00364E9F  End: 0x00364EBE  Size: 31 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_00365E7D, sub_003665CE
; ============================================================
sub_00364E9F:
  0x00364E9F  8bc1                    mov      eax, ecx                       
  0x00364EA1  33c9                    xor      ecx, ecx                       
  0x00364EA3  8908                    mov      dword ptr [eax], ecx           
  0x00364EA5  894804                  mov      dword ptr [eax + 4], ecx       
  0x00364EA8  894808                  mov      dword ptr [eax + 8], ecx       
  0x00364EAB  89480c                  mov      dword ptr [eax + 0xc], ecx     
  0x00364EAE  894810                  mov      dword ptr [eax + 0x10], ecx    
  0x00364EB1  894814                  mov      dword ptr [eax + 0x14], ecx    
  0x00364EB4  894818                  mov      dword ptr [eax + 0x18], ecx    
  0x00364EB7  89481c                  mov      dword ptr [eax + 0x1c], ecx    
  0x00364EBA  894820                  mov      dword ptr [eax + 0x20], ecx    
  0x00364EBD  c3                      ret                                     
; end of function

; ============================================================
; Function: sub_00364EBE
; Start: 0x00364EBE  End: 0x00364F1F  Size: 97 bytes
; Detection: prologue (confidence: 0.95)
; Called by: sub_00365E7D, sub_003665CE
; ============================================================
sub_00364EBE:
  0x00364EBE  55                      push     ebp                            
  0x00364EBF  8bec                    mov      ebp, esp                       
  0x00364EC1  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x00364EC4  8901                    mov      dword ptr [ecx], eax           
  0x00364EC6  8b450c                  mov      eax, dword ptr [ebp + 0xc]     
  0x00364EC9  894104                  mov      dword ptr [ecx + 4], eax       
  0x00364ECC  8b4510                  mov      eax, dword ptr [ebp + 0x10]    
  0x00364ECF  33d2                    xor      edx, edx                       
  0x00364ED1  894108                  mov      dword ptr [ecx + 8], eax       
  0x00364ED4  33c0                    xor      eax, eax                       
  0x00364ED6  56                      push     esi                            
  0x00364ED7  40                      inc      eax                            
  0x00364ED8  57                      push     edi                            
  0x00364ED9  89510c                  mov      dword ptr [ecx + 0xc], edx     
  0x00364EDC  895110                  mov      dword ptr [ecx + 0x10], edx    
  0x00364EDF  895114                  mov      dword ptr [ecx + 0x14], edx    
  0x00364EE2  895118                  mov      dword ptr [ecx + 0x18], edx    
  0x00364EE5  89511c                  mov      dword ptr [ecx + 0x1c], edx    
  0x00364EE8  895120                  mov      dword ptr [ecx + 0x20], edx    
  0x00364EEB  8bf8                    mov      edi, eax                       
                                        ; XREF: 0x00364F17 (cond_jump)
  0x00364EED  33f6                    xor      esi, esi                       
  0x00364EEF  3b7d08                  cmp      edi, dword ptr [ebp + 8]       
  0x00364EF2  7307                    jae      0x364efb                       
  0x00364EF4  09410c                  or       dword ptr [ecx + 0xc], eax     
  0x00364EF7  d1e0                    shl      eax, 1                         
  0x00364EF9  8bf0                    mov      esi, eax                       
                                        ; XREF: 0x00364EF2 (cond_jump)
  0x00364EFB  3b7d0c                  cmp      edi, dword ptr [ebp + 0xc]     
  0x00364EFE  7307                    jae      0x364f07                       
  0x00364F00  094110                  or       dword ptr [ecx + 0x10], eax    
  0x00364F03  d1e0                    shl      eax, 1                         
  0x00364F05  8bf0                    mov      esi, eax                       
                                        ; XREF: 0x00364EFE (cond_jump)
  0x00364F07  3b7d10                  cmp      edi, dword ptr [ebp + 0x10]    
  0x00364F0A  7307                    jae      0x364f13                       
  0x00364F0C  094114                  or       dword ptr [ecx + 0x14], eax    
  0x00364F0F  d1e0                    shl      eax, 1                         
  0x00364F11  8bf0                    mov      esi, eax                       
                                        ; XREF: 0x00364F0A (cond_jump)
  0x00364F13  d1e7                    shl      edi, 1                         
  0x00364F15  3bf2                    cmp      esi, edx                       
  0x00364F17  75d4                    jne      0x364eed                       
  0x00364F19  5f                      pop      edi                            
  0x00364F1A  5e                      pop      esi                            
  0x00364F1B  5d                      pop      ebp                            
  0x00364F1C  c20c00                  ret      0xc                            
; end of function

; ============================================================
; Function: sub_00364F1F
; Start: 0x00364F1F  End: 0x00364F48  Size: 41 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_00365708, sub_00365789, sub_0036585D, sub_00365931, sub_003659B4, sub_00365A37, sub_00365B03, sub_00365BCF, sub_00365C4A, sub_00365CC5 ... (+3 more)
; ============================================================
sub_00364F1F:
  0x00364F1F  8b490c                  mov      ecx, dword ptr [ecx + 0xc]     
  0x00364F22  33d2                    xor      edx, edx                       
  0x00364F24  42                      inc      edx                            
  0x00364F25  33c0                    xor      eax, eax                       
  0x00364F27  3bca                    cmp      ecx, edx                       
  0x00364F29  721a                    jb       0x364f45                       
  0x00364F2B  56                      push     esi                            
                                        ; XREF: 0x00364F42 (cond_jump)
  0x00364F2C  85ca                    test     edx, ecx                       
  0x00364F2E  740a                    je       0x364f3a                       
  0x00364F30  8bf2                    mov      esi, edx                       
  0x00364F32  23742408                and      esi, dword ptr [esp + 8]       
  0x00364F36  0bc6                    or       eax, esi                       
  0x00364F38  eb04                    jmp      0x364f3e                       
                                        ; XREF: 0x00364F2E (cond_jump)
  0x00364F3A  d1642408                shl      dword ptr [esp + 8], 1         
                                        ; XREF: 0x00364F38 (jump)
  0x00364F3E  d1e2                    shl      edx, 1                         
  0x00364F40  3bd1                    cmp      edx, ecx                       
  0x00364F42  76e8                    jbe      0x364f2c                       
  0x00364F44  5e                      pop      esi                            
                                        ; XREF: 0x00364F29 (cond_jump)
  0x00364F45  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00364F48
; Start: 0x00364F48  End: 0x00364F71  Size: 41 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_00365708, sub_00365789, sub_0036585D, sub_00365931, sub_003659B4, sub_00365A37, sub_00365B03, sub_00365BCF, sub_00365C4A, sub_00365CC5 ... (+3 more)
; ============================================================
sub_00364F48:
  0x00364F48  8b4910                  mov      ecx, dword ptr [ecx + 0x10]    
  0x00364F4B  33d2                    xor      edx, edx                       
  0x00364F4D  42                      inc      edx                            
  0x00364F4E  33c0                    xor      eax, eax                       
  0x00364F50  3bca                    cmp      ecx, edx                       
  0x00364F52  721a                    jb       0x364f6e                       
  0x00364F54  56                      push     esi                            
                                        ; XREF: 0x00364F6B (cond_jump)
  0x00364F55  85ca                    test     edx, ecx                       
  0x00364F57  740a                    je       0x364f63                       
  0x00364F59  8bf2                    mov      esi, edx                       
  0x00364F5B  23742408                and      esi, dword ptr [esp + 8]       
  0x00364F5F  0bc6                    or       eax, esi                       
  0x00364F61  eb04                    jmp      0x364f67                       
                                        ; XREF: 0x00364F57 (cond_jump)
  0x00364F63  d1642408                shl      dword ptr [esp + 8], 1         
                                        ; XREF: 0x00364F61 (jump)
  0x00364F67  d1e2                    shl      edx, 1                         
  0x00364F69  3bd1                    cmp      edx, ecx                       
  0x00364F6B  76e8                    jbe      0x364f55                       
  0x00364F6D  5e                      pop      esi                            
                                        ; XREF: 0x00364F52 (cond_jump)
  0x00364F6E  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00364F71
; Start: 0x00364F71  End: 0x00364FE5  Size: 116 bytes
; Detection: call_target (confidence: 0.90)
; Calls: sub_00364BFC
; Called by: sub_00364FE5, sub_003650E5, sub_003651E3, sub_003652DC, sub_003653BF, sub_003654D1
; ============================================================
sub_00364F71:
  0x00364F71  8b4c2404                mov      ecx, dword ptr [esp + 4]       
  0x00364F75  56                      push     esi                            
  0x00364F76  57                      push     edi                            
  0x00364F77  e880fcffff              call     0x364bfc                       ; -> sub_00364BFC
  0x00364F7C  8b4c2410                mov      ecx, dword ptr [esp + 0x10]    
  0x00364F80  8bf8                    mov      edi, eax                       
  0x00364F82  e875fcffff              call     0x364bfc                       ; -> sub_00364BFC
  0x00364F87  3bf8                    cmp      edi, eax                       
  0x00364F89  8bcf                    mov      ecx, edi                       
  0x00364F8B  7202                    jb       0x364f8f                       
  0x00364F8D  8bc8                    mov      ecx, eax                       
                                        ; XREF: 0x00364F8B (cond_jump)
  0x00364F8F  33d2                    xor      edx, edx                       
  0x00364F91  03c9                    add      ecx, ecx                       
  0x00364F93  42                      inc      edx                            
  0x00364F94  d3e2                    shl      edx, cl                        
  0x00364F96  4a                      dec      edx                            
  0x00364F97  3bf8                    cmp      edi, eax                       
  0x00364F99  8bca                    mov      ecx, edx                       
  0x00364F9B  f7d1                    not      ecx                            
  0x00364F9D  760a                    jbe      0x364fa9                       
  0x00364F9F  8bf1                    mov      esi, ecx                       
  0x00364FA1  81ce55555555            or       esi, 0x55555555                
  0x00364FA7  eb08                    jmp      0x364fb1                       
                                        ; XREF: 0x00364F9D (cond_jump)
  0x00364FA9  8bf2                    mov      esi, edx                       
  0x00364FAB  81e655555555            and      esi, 0x55555555                
                                        ; XREF: 0x00364FA7 (jump)
  0x00364FB1  3bf8                    cmp      edi, eax                       
  0x00364FB3  730a                    jae      0x364fbf                       
  0x00364FB5  81c9aaaaaaaa            or       ecx, 0xaaaaaaaa                
  0x00364FBB  8bd1                    mov      edx, ecx                       
  0x00364FBD  eb06                    jmp      0x364fc5                       
                                        ; XREF: 0x00364FB3 (cond_jump)
  0x00364FBF  81e2aaaaaaaa            and      edx, 0xaaaaaaaa                
                                        ; XREF: 0x00364FBD (jump)
  0x00364FC5  8d0c38                  lea      ecx, [eax + edi]               
  0x00364FC8  33c0                    xor      eax, eax                       
  0x00364FCA  40                      inc      eax                            
  0x00364FCB  d3e0                    shl      eax, cl                        
  0x00364FCD  5f                      pop      edi                            
  0x00364FCE  48                      dec      eax                            
  0x00364FCF  8bc8                    mov      ecx, eax                       
  0x00364FD1  23ce                    and      ecx, esi                       
  0x00364FD3  8b742410                mov      esi, dword ptr [esp + 0x10]    
  0x00364FD7  890e                    mov      dword ptr [esi], ecx           
  0x00364FD9  8b4c2414                mov      ecx, dword ptr [esp + 0x14]    
  0x00364FDD  23c2                    and      eax, edx                       
  0x00364FDF  8901                    mov      dword ptr [ecx], eax           
  0x00364FE1  5e                      pop      esi                            
  0x00364FE2  c21000                  ret      0x10                           
; end of function

; ============================================================
; Function: sub_00364FE5
; Start: 0x00364FE5  End: 0x003650E5  Size: 256 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364F71
; Called by: sub_00365E7D
; ============================================================
sub_00364FE5:
  0x00364FE5  55                      push     ebp                            
  0x00364FE6  8bec                    mov      ebp, esp                       
  0x00364FE8  83ec0c                  sub      esp, 0xc                       
  0x00364FEB  53                      push     ebx                            
  0x00364FEC  56                      push     esi                            
  0x00364FED  57                      push     edi                            
  0x00364FEE  8d4514                  lea      eax, [ebp + 0x14]              
  0x00364FF1  50                      push     eax                            
  0x00364FF2  8d45fc                  lea      eax, [ebp - 4]                 
  0x00364FF5  50                      push     eax                            
  0x00364FF6  ff7514                  push     dword ptr [ebp + 0x14]         
  0x00364FF9  ff7510                  push     dword ptr [ebp + 0x10]         
  0x00364FFC  e870ffffff              call     0x364f71                       ; -> sub_00364F71
  0x00365001  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x00365004  83e0c0                  and      eax, 0xffffffc0                
  0x00365007  8945f4                  mov      dword ptr [ebp - 0xc], eax     
  0x0036500A  8b4514                  mov      eax, dword ptr [ebp + 0x14]    
  0x0036500D  83e080                  and      eax, 0xffffff80                
  0x00365010  8945f8                  mov      dword ptr [ebp - 8], eax       
  0x00365013  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00365016  8b7d0c                  mov      edi, dword ptr [ebp + 0xc]     
  0x00365019  8b5510                  mov      edx, dword ptr [ebp + 0x10]    
  0x0036501C  33db                    xor      ebx, ebx                       
  0x0036501E  33c9                    xor      ecx, ecx                       
  0x00365020  eb03                    jmp      0x365025                       
  0x00365022  8d4900                  lea      ecx, [ecx]                     
                                        ; XREF: 0x00365020 (jump), 0x003650C5 (cond_jump), 0x003650D6 (cond_jump)
  0x00365025  0f6f06                  movq     mm0, qword ptr [esi]           
  0x00365028  0f6f0c16                movq     mm1, qword ptr [esi + edx]     
  0x0036502C  03f2                    add      esi, edx                       
  0x0036502E  8bc3                    mov      eax, ebx                       
  0x00365030  0f6f2416                movq     mm4, qword ptr [esi + edx]     
  0x00365034  0f6f2c56                movq     mm5, qword ptr [esi + edx*2]   
  0x00365038  0bc1                    or       eax, ecx                       
  0x0036503A  0f7fe6                  movq     mm6, mm4                       
  0x0036503D  0f7fc2                  movq     mm2, mm0                       
  0x00365040  0f69f5                  punpckhwd mm6, mm5                       
  0x00365043  8d3496                  lea      esi, [esi + edx*4]             
  0x00365046  0f69d1                  punpckhwd mm2, mm1                       
  0x00365049  0f61e5                  punpcklwd mm4, mm5                       
  0x0036504C  0f6f1e                  movq     mm3, qword ptr [esi]           
  0x0036504F  0f6f2c16                movq     mm5, qword ptr [esi + edx]     
  0x00365053  0f6f3c56                movq     mm7, qword ptr [esi + edx*2]   
  0x00365057  2bf2                    sub      esi, edx                       
  0x00365059  0f61c1                  punpcklwd mm0, mm1                       
  0x0036505C  0f6f0e                  movq     mm1, qword ptr [esi]           
  0x0036505F  0f7f0407                movq     qword ptr [edi + eax], mm0     
  0x00365063  0f7f640708              movq     qword ptr [edi + eax + 8], mm4 
  0x00365068  0f7f540710              movq     qword ptr [edi + eax + 0x10], mm2 
  0x0036506D  0f7f740718              movq     qword ptr [edi + eax + 0x18], mm6 
  0x00365072  0f7fc8                  movq     mm0, mm1                       
  0x00365075  0f7fec                  movq     mm4, mm5                       
  0x00365078  0f61c3                  punpcklwd mm0, mm3                       
  0x0036507B  0f61e7                  punpcklwd mm4, mm7                       
  0x0036507E  0f69cb                  punpckhwd mm1, mm3                       
  0x00365081  0f69ef                  punpckhwd mm5, mm7                       
  0x00365084  0f7f440720              movq     qword ptr [edi + eax + 0x20], mm0 
  0x00365089  0f7f640728              movq     qword ptr [edi + eax + 0x28], mm4 
  0x0036508E  0f7f4c0730              movq     qword ptr [edi + eax + 0x30], mm1 
  0x00365093  0f7f6c0738              movq     qword ptr [edi + eax + 0x38], mm5 
  0x00365098  2bf2                    sub      esi, edx                       
  0x0036509A  2bf2                    sub      esi, edx                       
  0x0036509C  2bf2                    sub      esi, edx                       
  0x0036509E  2bf2                    sub      esi, edx                       
  0x003650A0  2b5df4                  sub      ebx, dword ptr [ebp - 0xc]     
  0x003650A3  90                      nop                                     
  0x003650A4  90                      nop                                     
  0x003650A5  90                      nop                                     
  0x003650A6  90                      nop                                     
  0x003650A7  90                      nop                                     
  0x003650A8  90                      nop                                     
  0x003650A9  90                      nop                                     
  0x003650AA  90                      nop                                     
  0x003650AB  90                      nop                                     
  0x003650AC  90                      nop                                     
  0x003650AD  90                      nop                                     
  0x003650AE  90                      nop                                     
  0x003650AF  90                      nop                                     
  0x003650B0  90                      nop                                     
  0x003650B1  90                      nop                                     
  0x003650B2  90                      nop                                     
  0x003650B3  90                      nop                                     
  0x003650B4  90                      nop                                     
  0x003650B5  90                      nop                                     
  0x003650B6  90                      nop                                     
  0x003650B7  90                      nop                                     
  0x003650B8  90                      nop                                     
  0x003650B9  90                      nop                                     
  0x003650BA  90                      nop                                     
  0x003650BB  90                      nop                                     
  0x003650BC  90                      nop                                     
  0x003650BD  90                      nop                                     
  0x003650BE  90                      nop                                     
  0x003650BF  83c608                  add      esi, 8                         
  0x003650C2  235dfc                  and      ebx, dword ptr [ebp - 4]       
  0x003650C5  0f855affffff            jne      0x365025                       
  0x003650CB  2b4df8                  sub      ecx, dword ptr [ebp - 8]       
  0x003650CE  8d34d6                  lea      esi, [esi + edx*8]             
  0x003650D1  2bf2                    sub      esi, edx                       
  0x003650D3  234d14                  and      ecx, dword ptr [ebp + 0x14]    
  0x003650D6  0f8549ffffff            jne      0x365025                       
  0x003650DC  0f77                    emms                                    
  0x003650DE  5f                      pop      edi                            
  0x003650DF  5e                      pop      esi                            
  0x003650E0  5b                      pop      ebx                            
  0x003650E1  c9                      leave                                   
  0x003650E2  c21000                  ret      0x10                           
; end of function

; ============================================================
; Function: sub_003650E5
; Start: 0x003650E5  End: 0x003651E3  Size: 254 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364F71
; Called by: sub_00365E7D
; ============================================================
sub_003650E5:
  0x003650E5  55                      push     ebp                            
  0x003650E6  8bec                    mov      ebp, esp                       
  0x003650E8  83ec0c                  sub      esp, 0xc                       
  0x003650EB  53                      push     ebx                            
  0x003650EC  56                      push     esi                            
  0x003650ED  57                      push     edi                            
  0x003650EE  8d4514                  lea      eax, [ebp + 0x14]              
  0x003650F1  50                      push     eax                            
  0x003650F2  8d45fc                  lea      eax, [ebp - 4]                 
  0x003650F5  50                      push     eax                            
  0x003650F6  ff7514                  push     dword ptr [ebp + 0x14]         
  0x003650F9  ff7510                  push     dword ptr [ebp + 0x10]         
  0x003650FC  e870feffff              call     0x364f71                       ; -> sub_00364F71
  0x00365101  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x00365104  83e0c0                  and      eax, 0xffffffc0                
  0x00365107  8945f4                  mov      dword ptr [ebp - 0xc], eax     
  0x0036510A  8b4514                  mov      eax, dword ptr [ebp + 0x14]    
  0x0036510D  83e080                  and      eax, 0xffffff80                
  0x00365110  8945f8                  mov      dword ptr [ebp - 8], eax       
  0x00365113  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00365116  8b7d0c                  mov      edi, dword ptr [ebp + 0xc]     
  0x00365119  8b5510                  mov      edx, dword ptr [ebp + 0x10]    
  0x0036511C  33db                    xor      ebx, ebx                       
  0x0036511E  33c9                    xor      ecx, ecx                       
  0x00365120  03d2                    add      edx, edx                       
  0x00365122  8d4900                  lea      ecx, [ecx]                     
                                        ; XREF: 0x003651C5 (cond_jump), 0x003651D6 (cond_jump)
  0x00365125  0f1006                  movups   xmm0, xmmword ptr [esi]        
  0x00365128  0f100c16                movups   xmm1, xmmword ptr [esi + edx]  
  0x0036512C  03f2                    add      esi, edx                       
  0x0036512E  8bc3                    mov      eax, ebx                       
  0x00365130  0f102416                movups   xmm4, xmmword ptr [esi + edx]  
  0x00365134  0f102c56                movups   xmm5, xmmword ptr [esi + edx*2] 
  0x00365138  0bc1                    or       eax, ecx                       
  0x0036513A  0f28f4                  movaps   xmm6, xmm4                     
  0x0036513D  0f28d0                  movaps   xmm2, xmm0                     
  0x00365140  0f15f5                  unpckhps xmm6, xmm5                     
  0x00365143  8d3496                  lea      esi, [esi + edx*4]             
  0x00365146  0f15d1                  unpckhps xmm2, xmm1                     
  0x00365149  0f14e5                  unpcklps xmm4, xmm5                     
  0x0036514C  0f101e                  movups   xmm3, xmmword ptr [esi]        
  0x0036514F  0f102c16                movups   xmm5, xmmword ptr [esi + edx]  
  0x00365153  0f103c56                movups   xmm7, xmmword ptr [esi + edx*2] 
  0x00365157  2bf2                    sub      esi, edx                       
  0x00365159  0f14c1                  unpcklps xmm0, xmm1                     
  0x0036515C  0f100e                  movups   xmm1, xmmword ptr [esi]        
  0x0036515F  0f2b0447                movntps  xmmword ptr [edi + eax*2], xmm0 
  0x00365163  0f2b644710              movntps  xmmword ptr [edi + eax*2 + 0x10], xmm4 
  0x00365168  0f2b544720              movntps  xmmword ptr [edi + eax*2 + 0x20], xmm2 
  0x0036516D  0f2b744730              movntps  xmmword ptr [edi + eax*2 + 0x30], xmm6 
  0x00365172  0f28c1                  movaps   xmm0, xmm1                     
  0x00365175  0f28e5                  movaps   xmm4, xmm5                     
  0x00365178  0f14c3                  unpcklps xmm0, xmm3                     
  0x0036517B  0f14e7                  unpcklps xmm4, xmm7                     
  0x0036517E  0f15cb                  unpckhps xmm1, xmm3                     
  0x00365181  0f15ef                  unpckhps xmm5, xmm7                     
  0x00365184  0f2b444740              movntps  xmmword ptr [edi + eax*2 + 0x40], xmm0 
  0x00365189  0f2b644750              movntps  xmmword ptr [edi + eax*2 + 0x50], xmm4 
  0x0036518E  0f2b4c4760              movntps  xmmword ptr [edi + eax*2 + 0x60], xmm1 
  0x00365193  0f2b6c4770              movntps  xmmword ptr [edi + eax*2 + 0x70], xmm5 
  0x00365198  2bf2                    sub      esi, edx                       
  0x0036519A  2bf2                    sub      esi, edx                       
  0x0036519C  2bf2                    sub      esi, edx                       
  0x0036519E  2bf2                    sub      esi, edx                       
  0x003651A0  2b5df4                  sub      ebx, dword ptr [ebp - 0xc]     
  0x003651A3  90                      nop                                     
  0x003651A4  90                      nop                                     
  0x003651A5  90                      nop                                     
  0x003651A6  90                      nop                                     
  0x003651A7  90                      nop                                     
  0x003651A8  90                      nop                                     
  0x003651A9  90                      nop                                     
  0x003651AA  90                      nop                                     
  0x003651AB  90                      nop                                     
  0x003651AC  90                      nop                                     
  0x003651AD  90                      nop                                     
  0x003651AE  90                      nop                                     
  0x003651AF  90                      nop                                     
  0x003651B0  90                      nop                                     
  0x003651B1  90                      nop                                     
  0x003651B2  90                      nop                                     
  0x003651B3  90                      nop                                     
  0x003651B4  90                      nop                                     
  0x003651B5  90                      nop                                     
  0x003651B6  90                      nop                                     
  0x003651B7  90                      nop                                     
  0x003651B8  90                      nop                                     
  0x003651B9  90                      nop                                     
  0x003651BA  90                      nop                                     
  0x003651BB  90                      nop                                     
  0x003651BC  90                      nop                                     
  0x003651BD  90                      nop                                     
  0x003651BE  90                      nop                                     
  0x003651BF  83c610                  add      esi, 0x10                      
  0x003651C2  235dfc                  and      ebx, dword ptr [ebp - 4]       
  0x003651C5  0f855affffff            jne      0x365125                       
  0x003651CB  2b4df8                  sub      ecx, dword ptr [ebp - 8]       
  0x003651CE  8d34d6                  lea      esi, [esi + edx*8]             
  0x003651D1  2bf2                    sub      esi, edx                       
  0x003651D3  234d14                  and      ecx, dword ptr [ebp + 0x14]    
  0x003651D6  0f8549ffffff            jne      0x365125                       
  0x003651DC  5f                      pop      edi                            
  0x003651DD  5e                      pop      esi                            
  0x003651DE  5b                      pop      ebx                            
  0x003651DF  c9                      leave                                   
  0x003651E0  c21000                  ret      0x10                           
; end of function

; ============================================================
; Function: sub_003651E3
; Start: 0x003651E3  End: 0x003652DC  Size: 249 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364F71
; Called by: sub_00365E7D
; ============================================================
sub_003651E3:
  0x003651E3  55                      push     ebp                            
  0x003651E4  8bec                    mov      ebp, esp                       
  0x003651E6  83ec0c                  sub      esp, 0xc                       
  0x003651E9  53                      push     ebx                            
  0x003651EA  56                      push     esi                            
  0x003651EB  57                      push     edi                            
  0x003651EC  8d4514                  lea      eax, [ebp + 0x14]              
  0x003651EF  50                      push     eax                            
  0x003651F0  8d45fc                  lea      eax, [ebp - 4]                 
  0x003651F3  50                      push     eax                            
  0x003651F4  ff7514                  push     dword ptr [ebp + 0x14]         
  0x003651F7  ff7510                  push     dword ptr [ebp + 0x10]         
  0x003651FA  e872fdffff              call     0x364f71                       ; -> sub_00364F71
  0x003651FF  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x00365202  83e0c0                  and      eax, 0xffffffc0                
  0x00365205  8945f4                  mov      dword ptr [ebp - 0xc], eax     
  0x00365208  8b4514                  mov      eax, dword ptr [ebp + 0x14]    
  0x0036520B  83e0e0                  and      eax, 0xffffffe0                
  0x0036520E  8945f8                  mov      dword ptr [ebp - 8], eax       
  0x00365211  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00365214  8b7d0c                  mov      edi, dword ptr [ebp + 0xc]     
  0x00365217  8b5510                  mov      edx, dword ptr [ebp + 0x10]    
  0x0036521A  33db                    xor      ebx, ebx                       
  0x0036521C  33c9                    xor      ecx, ecx                       
  0x0036521E  c1e202                  shl      edx, 2                         
  0x00365221  8bff                    mov      edi, edi                       
                                        ; XREF: 0x003652BE (cond_jump), 0x003652CF (cond_jump)
  0x00365223  8bc3                    mov      eax, ebx                       
  0x00365225  0f1006                  movups   xmm0, xmmword ptr [esi]        
  0x00365228  0f106610                movups   xmm4, xmmword ptr [esi + 0x10] 
  0x0036522C  0f101416                movups   xmm2, xmmword ptr [esi + edx]  
  0x00365230  0f10741610              movups   xmm6, xmmword ptr [esi + edx + 0x10] 
  0x00365235  0f28c8                  movaps   xmm1, xmm0                     
  0x00365238  0f28ec                  movaps   xmm5, xmm4                     
  0x0036523B  8d3456                  lea      esi, [esi + edx*2]             
  0x0036523E  0bc1                    or       eax, ecx                       
  0x00365240  0f16c2                  movlhps  xmm0, xmm2                     
  0x00365243  0f12d1                  movhlps  xmm2, xmm1                     
  0x00365246  0f16e6                  movlhps  xmm4, xmm6                     
  0x00365249  0f12f5                  movhlps  xmm6, xmm5                     
  0x0036524C  0f100e                  movups   xmm1, xmmword ptr [esi]        
  0x0036524F  0f106e10                movups   xmm5, xmmword ptr [esi + 0x10] 
  0x00365253  0f101c16                movups   xmm3, xmmword ptr [esi + edx]  
  0x00365257  0f107c1610              movups   xmm7, xmmword ptr [esi + edx + 0x10] 
  0x0036525C  0f2b0487                movntps  xmmword ptr [edi + eax*4], xmm0 
  0x00365260  0f2b548710              movntps  xmmword ptr [edi + eax*4 + 0x10], xmm2 
  0x00365265  0f2b648740              movntps  xmmword ptr [edi + eax*4 + 0x40], xmm4 
  0x0036526A  0f2b748750              movntps  xmmword ptr [edi + eax*4 + 0x50], xmm6 
  0x0036526F  0f28c1                  movaps   xmm0, xmm1                     
  0x00365272  0f28e5                  movaps   xmm4, xmm5                     
  0x00365275  0f16cb                  movlhps  xmm1, xmm3                     
  0x00365278  0f12d8                  movhlps  xmm3, xmm0                     
  0x0036527B  0f16ef                  movlhps  xmm5, xmm7                     
  0x0036527E  0f12fc                  movhlps  xmm7, xmm4                     
  0x00365281  0f2b4c8720              movntps  xmmword ptr [edi + eax*4 + 0x20], xmm1 
  0x00365286  0f2b5c8730              movntps  xmmword ptr [edi + eax*4 + 0x30], xmm3 
  0x0036528B  0f2b6c8760              movntps  xmmword ptr [edi + eax*4 + 0x60], xmm5 
  0x00365290  0f2b7c8770              movntps  xmmword ptr [edi + eax*4 + 0x70], xmm7 
  0x00365295  2bf2                    sub      esi, edx                       
  0x00365297  2bf2                    sub      esi, edx                       
  0x00365299  90                      nop                                     
  0x0036529A  90                      nop                                     
  0x0036529B  90                      nop                                     
  0x0036529C  90                      nop                                     
  0x0036529D  90                      nop                                     
  0x0036529E  90                      nop                                     
  0x0036529F  90                      nop                                     
  0x003652A0  90                      nop                                     
  0x003652A1  90                      nop                                     
  0x003652A2  90                      nop                                     
  0x003652A3  90                      nop                                     
  0x003652A4  90                      nop                                     
  0x003652A5  90                      nop                                     
  0x003652A6  90                      nop                                     
  0x003652A7  90                      nop                                     
  0x003652A8  90                      nop                                     
  0x003652A9  90                      nop                                     
  0x003652AA  90                      nop                                     
  0x003652AB  90                      nop                                     
  0x003652AC  90                      nop                                     
  0x003652AD  90                      nop                                     
  0x003652AE  90                      nop                                     
  0x003652AF  90                      nop                                     
  0x003652B0  90                      nop                                     
  0x003652B1  90                      nop                                     
  0x003652B2  90                      nop                                     
  0x003652B3  90                      nop                                     
  0x003652B4  90                      nop                                     
  0x003652B5  2b5df4                  sub      ebx, dword ptr [ebp - 0xc]     
  0x003652B8  83c620                  add      esi, 0x20                      
  0x003652BB  235dfc                  and      ebx, dword ptr [ebp - 4]       
  0x003652BE  0f855fffffff            jne      0x365223                       
  0x003652C4  2b4df8                  sub      ecx, dword ptr [ebp - 8]       
  0x003652C7  8d3496                  lea      esi, [esi + edx*4]             
  0x003652CA  2bf2                    sub      esi, edx                       
  0x003652CC  234d14                  and      ecx, dword ptr [ebp + 0x14]    
  0x003652CF  0f854effffff            jne      0x365223                       
  0x003652D5  5f                      pop      edi                            
  0x003652D6  5e                      pop      esi                            
  0x003652D7  5b                      pop      ebx                            
  0x003652D8  c9                      leave                                   
  0x003652D9  c21000                  ret      0x10                           
; end of function

; ============================================================
; Function: sub_003652DC
; Start: 0x003652DC  End: 0x003653BF  Size: 227 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364F71
; Called by: sub_003665CE
; ============================================================
sub_003652DC:
  0x003652DC  55                      push     ebp                            
  0x003652DD  8bec                    mov      ebp, esp                       
  0x003652DF  83ec0c                  sub      esp, 0xc                       
  0x003652E2  53                      push     ebx                            
  0x003652E3  56                      push     esi                            
  0x003652E4  57                      push     edi                            
  0x003652E5  8d4514                  lea      eax, [ebp + 0x14]              
  0x003652E8  50                      push     eax                            
  0x003652E9  8d45fc                  lea      eax, [ebp - 4]                 
  0x003652EC  50                      push     eax                            
  0x003652ED  ff7514                  push     dword ptr [ebp + 0x14]         
  0x003652F0  ff7510                  push     dword ptr [ebp + 0x10]         
  0x003652F3  e879fcffff              call     0x364f71                       ; -> sub_00364F71
  0x003652F8  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x003652FB  2500ffffff              and      eax, 0xffffff00                
  0x00365300  8945f4                  mov      dword ptr [ebp - 0xc], eax     
  0x00365303  8b4514                  mov      eax, dword ptr [ebp + 0x14]    
  0x00365306  83e0e0                  and      eax, 0xffffffe0                
  0x00365309  8945f8                  mov      dword ptr [ebp - 8], eax       
  0x0036530C  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x0036530F  8b7d0c                  mov      edi, dword ptr [ebp + 0xc]     
  0x00365312  8b5510                  mov      edx, dword ptr [ebp + 0x10]    
  0x00365315  33db                    xor      ebx, ebx                       
  0x00365317  33c9                    xor      ecx, ecx                       
                                        ; XREF: 0x0036539F (cond_jump), 0x003653B0 (cond_jump)
  0x00365319  8bc3                    mov      eax, ebx                       
  0x0036531B  2b5df4                  sub      ebx, dword ptr [ebp - 0xc]     
  0x0036531E  0bc1                    or       eax, ecx                       
  0x00365320  0f700406d8              pshufw   mm0, qword ptr [esi + eax], 0xd8 
  0x00365325  0f70540640d8            pshufw   mm2, qword ptr [esi + eax + 0x40], 0xd8 
  0x0036532B  0f70640610d8            pshufw   mm4, qword ptr [esi + eax + 0x10], 0xd8 
  0x00365331  0f70740650d8            pshufw   mm6, qword ptr [esi + eax + 0x50], 0xd8 
  0x00365337  0f7fc1                  movq     mm1, mm0                       
  0x0036533A  0f7fd3                  movq     mm3, mm2                       
  0x0036533D  0f62c4                  punpckldq mm0, mm4                       
  0x00365340  0f6acc                  punpckhdq mm1, mm4                       
  0x00365343  0f62d6                  punpckldq mm2, mm6                       
  0x00365346  0f6ade                  punpckhdq mm3, mm6                       
  0x00365349  0f7f07                  movq     qword ptr [edi], mm0           
  0x0036534C  0f7f5708                movq     qword ptr [edi + 8], mm2       
  0x00365350  0f7f0c17                movq     qword ptr [edi + edx], mm1     
  0x00365354  0f7f5c1708              movq     qword ptr [edi + edx + 8], mm3 
  0x00365359  03fa                    add      edi, edx                       
  0x0036535B  0f70640608d8            pshufw   mm4, qword ptr [esi + eax + 8], 0xd8 
  0x00365361  0f706c0648d8            pshufw   mm5, qword ptr [esi + eax + 0x48], 0xd8 
  0x00365367  0f70740618d8            pshufw   mm6, qword ptr [esi + eax + 0x18], 0xd8 
  0x0036536D  0f707c0658d8            pshufw   mm7, qword ptr [esi + eax + 0x58], 0xd8 
  0x00365373  0f7fe0                  movq     mm0, mm4                       
  0x00365376  0f7fe9                  movq     mm1, mm5                       
  0x00365379  0f62c6                  punpckldq mm0, mm6                       
  0x0036537C  0f6ae6                  punpckhdq mm4, mm6                       
  0x0036537F  0f62cf                  punpckldq mm1, mm7                       
  0x00365382  0f6aef                  punpckhdq mm5, mm7                       
  0x00365385  0f7f0417                movq     qword ptr [edi + edx], mm0     
  0x00365389  0f7f4c1708              movq     qword ptr [edi + edx + 8], mm1 
  0x0036538E  0f7f2457                movq     qword ptr [edi + edx*2], mm4   
  0x00365392  0f7f6c5708              movq     qword ptr [edi + edx*2 + 8], mm5 
  0x00365397  2bfa                    sub      edi, edx                       
  0x00365399  83c710                  add      edi, 0x10                      
  0x0036539C  235dfc                  and      ebx, dword ptr [ebp - 4]       
  0x0036539F  0f8574ffffff            jne      0x365319                       
  0x003653A5  2b4df8                  sub      ecx, dword ptr [ebp - 8]       
  0x003653A8  8d3c97                  lea      edi, [edi + edx*4]             
  0x003653AB  2bfa                    sub      edi, edx                       
  0x003653AD  234d14                  and      ecx, dword ptr [ebp + 0x14]    
  0x003653B0  0f8563ffffff            jne      0x365319                       
  0x003653B6  0f77                    emms                                    
  0x003653B8  5f                      pop      edi                            
  0x003653B9  5e                      pop      esi                            
  0x003653BA  5b                      pop      ebx                            
  0x003653BB  c9                      leave                                   
  0x003653BC  c21000                  ret      0x10                           
; end of function

; ============================================================
; Function: sub_003653BF
; Start: 0x003653BF  End: 0x003654D1  Size: 274 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364F71
; Called by: sub_003665CE
; ============================================================
sub_003653BF:
  0x003653BF  55                      push     ebp                            
  0x003653C0  8bec                    mov      ebp, esp                       
  0x003653C2  83ec0c                  sub      esp, 0xc                       
  0x003653C5  53                      push     ebx                            
  0x003653C6  56                      push     esi                            
  0x003653C7  57                      push     edi                            
  0x003653C8  8d4514                  lea      eax, [ebp + 0x14]              
  0x003653CB  50                      push     eax                            
  0x003653CC  8d45fc                  lea      eax, [ebp - 4]                 
  0x003653CF  50                      push     eax                            
  0x003653D0  ff7514                  push     dword ptr [ebp + 0x14]         
  0x003653D3  ff7510                  push     dword ptr [ebp + 0x10]         
  0x003653D6  e896fbffff              call     0x364f71                       ; -> sub_00364F71
  0x003653DB  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x003653DE  2500ffffff              and      eax, 0xffffff00                
  0x003653E3  8945f4                  mov      dword ptr [ebp - 0xc], eax     
  0x003653E6  8b4514                  mov      eax, dword ptr [ebp + 0x14]    
  0x003653E9  83e0e0                  and      eax, 0xffffffe0                
  0x003653EC  8945f8                  mov      dword ptr [ebp - 8], eax       
  0x003653EF  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x003653F2  8b7d0c                  mov      edi, dword ptr [ebp + 0xc]     
  0x003653F5  8b5510                  mov      edx, dword ptr [ebp + 0x10]    
  0x003653F8  33db                    xor      ebx, ebx                       
  0x003653FA  33c9                    xor      ecx, ecx                       
  0x003653FC  03d2                    add      edx, edx                       
  0x003653FE  90                      nop                                     
                                        ; XREF: 0x003654B3 (cond_jump), 0x003654C4 (cond_jump)
  0x003653FF  8bc3                    mov      eax, ebx                       
  0x00365401  2b5df4                  sub      ebx, dword ptr [ebp - 0xc]     
  0x00365404  0bc1                    or       eax, ecx                       
  0x00365406  0f280446                movaps   xmm0, xmmword ptr [esi + eax*2] 
  0x0036540A  0f28644620              movaps   xmm4, xmmword ptr [esi + eax*2 + 0x20] 
  0x0036540F  0f28944680000000        movaps   xmm2, xmmword ptr [esi + eax*2 + 0x80] 
  0x00365417  0f28b446a0000000        movaps   xmm6, xmmword ptr [esi + eax*2 + 0xa0] 
  0x0036541F  0f28c8                  movaps   xmm1, xmm0                     
  0x00365422  0f28da                  movaps   xmm3, xmm2                     
  0x00365425  0fc6c488                shufps   xmm0, xmm4, 0x88               
  0x00365429  0fc6ccdd                shufps   xmm1, xmm4, 0xdd               
  0x0036542D  0fc6d688                shufps   xmm2, xmm6, 0x88               
  0x00365431  0fc6dedd                shufps   xmm3, xmm6, 0xdd               
  0x00365435  0f28644610              movaps   xmm4, xmmword ptr [esi + eax*2 + 0x10] 
  0x0036543A  0f28744630              movaps   xmm6, xmmword ptr [esi + eax*2 + 0x30] 
  0x0036543F  0f28ac4690000000        movaps   xmm5, xmmword ptr [esi + eax*2 + 0x90] 
  0x00365447  0f28bc46b0000000        movaps   xmm7, xmmword ptr [esi + eax*2 + 0xb0] 
  0x0036544F  0f2b07                  movntps  xmmword ptr [edi], xmm0        
  0x00365452  0f2b5710                movntps  xmmword ptr [edi + 0x10], xmm2 
  0x00365456  0f2b0c17                movntps  xmmword ptr [edi + edx], xmm1  
  0x0036545A  0f2b5c1710              movntps  xmmword ptr [edi + edx + 0x10], xmm3 
  0x0036545F  03fa                    add      edi, edx                       
  0x00365461  0f28c4                  movaps   xmm0, xmm4                     
  0x00365464  0f28cd                  movaps   xmm1, xmm5                     
  0x00365467  0fc6c688                shufps   xmm0, xmm6, 0x88               
  0x0036546B  0fc6e6dd                shufps   xmm4, xmm6, 0xdd               
  0x0036546F  0fc6cf88                shufps   xmm1, xmm7, 0x88               
  0x00365473  0fc6efdd                shufps   xmm5, xmm7, 0xdd               
  0x00365477  0f2b0417                movntps  xmmword ptr [edi + edx], xmm0  
  0x0036547B  0f2b4c1710              movntps  xmmword ptr [edi + edx + 0x10], xmm1 
  0x00365480  0f2b2457                movntps  xmmword ptr [edi + edx*2], xmm4 
  0x00365484  0f2b6c5710              movntps  xmmword ptr [edi + edx*2 + 0x10], xmm5 
  0x00365489  90                      nop                                     
  0x0036548A  90                      nop                                     
  0x0036548B  90                      nop                                     
  0x0036548C  90                      nop                                     
  0x0036548D  90                      nop                                     
  0x0036548E  90                      nop                                     
  0x0036548F  90                      nop                                     
  0x00365490  90                      nop                                     
  0x00365491  90                      nop                                     
  0x00365492  90                      nop                                     
  0x00365493  90                      nop                                     
  0x00365494  90                      nop                                     
  0x00365495  90                      nop                                     
  0x00365496  90                      nop                                     
  0x00365497  90                      nop                                     
  0x00365498  90                      nop                                     
  0x00365499  90                      nop                                     
  0x0036549A  90                      nop                                     
  0x0036549B  90                      nop                                     
  0x0036549C  90                      nop                                     
  0x0036549D  90                      nop                                     
  0x0036549E  90                      nop                                     
  0x0036549F  90                      nop                                     
  0x003654A0  90                      nop                                     
  0x003654A1  90                      nop                                     
  0x003654A2  90                      nop                                     
  0x003654A3  90                      nop                                     
  0x003654A4  90                      nop                                     
  0x003654A5  90                      nop                                     
  0x003654A6  90                      nop                                     
  0x003654A7  90                      nop                                     
  0x003654A8  90                      nop                                     
  0x003654A9  90                      nop                                     
  0x003654AA  90                      nop                                     
  0x003654AB  2bfa                    sub      edi, edx                       
  0x003654AD  83c720                  add      edi, 0x20                      
  0x003654B0  235dfc                  and      ebx, dword ptr [ebp - 4]       
  0x003654B3  0f8546ffffff            jne      0x3653ff                       
  0x003654B9  2b4df8                  sub      ecx, dword ptr [ebp - 8]       
  0x003654BC  8d3c97                  lea      edi, [edi + edx*4]             
  0x003654BF  2bfa                    sub      edi, edx                       
  0x003654C1  234d14                  and      ecx, dword ptr [ebp + 0x14]    
  0x003654C4  0f8535ffffff            jne      0x3653ff                       
  0x003654CA  5f                      pop      edi                            
  0x003654CB  5e                      pop      esi                            
  0x003654CC  5b                      pop      ebx                            
  0x003654CD  c9                      leave                                   
  0x003654CE  c21000                  ret      0x10                           
; end of function

; ============================================================
; Function: sub_003654D1
; Start: 0x003654D1  End: 0x003655C7  Size: 246 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364F71
; Called by: sub_003665CE
; ============================================================
sub_003654D1:
  0x003654D1  55                      push     ebp                            
  0x003654D2  8bec                    mov      ebp, esp                       
  0x003654D4  83ec0c                  sub      esp, 0xc                       
  0x003654D7  53                      push     ebx                            
  0x003654D8  56                      push     esi                            
  0x003654D9  57                      push     edi                            
  0x003654DA  8d4514                  lea      eax, [ebp + 0x14]              
  0x003654DD  50                      push     eax                            
  0x003654DE  8d45fc                  lea      eax, [ebp - 4]                 
  0x003654E1  50                      push     eax                            
  0x003654E2  ff7514                  push     dword ptr [ebp + 0x14]         
  0x003654E5  ff7510                  push     dword ptr [ebp + 0x10]         
  0x003654E8  e884faffff              call     0x364f71                       ; -> sub_00364F71
  0x003654ED  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x003654F0  83e0c0                  and      eax, 0xffffffc0                
  0x003654F3  8945f4                  mov      dword ptr [ebp - 0xc], eax     
  0x003654F6  8b4514                  mov      eax, dword ptr [ebp + 0x14]    
  0x003654F9  83e0e0                  and      eax, 0xffffffe0                
  0x003654FC  8945f8                  mov      dword ptr [ebp - 8], eax       
  0x003654FF  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00365502  8b7d0c                  mov      edi, dword ptr [ebp + 0xc]     
  0x00365505  8b5510                  mov      edx, dword ptr [ebp + 0x10]    
  0x00365508  33db                    xor      ebx, ebx                       
  0x0036550A  33c9                    xor      ecx, ecx                       
  0x0036550C  c1e202                  shl      edx, 2                         
                                        ; XREF: 0x003655A9 (cond_jump), 0x003655BA (cond_jump)
  0x0036550F  8bc3                    mov      eax, ebx                       
  0x00365511  0bc1                    or       eax, ecx                       
  0x00365513  2b5df4                  sub      ebx, dword ptr [ebp - 0xc]     
  0x00365516  0f280486                movaps   xmm0, xmmword ptr [esi + eax*4] 
  0x0036551A  0f28548610              movaps   xmm2, xmmword ptr [esi + eax*4 + 0x10] 
  0x0036551F  0f28648640              movaps   xmm4, xmmword ptr [esi + eax*4 + 0x40] 
  0x00365524  0f28748650              movaps   xmm6, xmmword ptr [esi + eax*4 + 0x50] 
  0x00365529  0f28c8                  movaps   xmm1, xmm0                     
  0x0036552C  0f28ec                  movaps   xmm5, xmm4                     
  0x0036552F  0f16c2                  movlhps  xmm0, xmm2                     
  0x00365532  0f12d1                  movhlps  xmm2, xmm1                     
  0x00365535  0f16e6                  movlhps  xmm4, xmm6                     
  0x00365538  0f12f5                  movhlps  xmm6, xmm5                     
  0x0036553B  0f284c8620              movaps   xmm1, xmmword ptr [esi + eax*4 + 0x20] 
  0x00365540  0f285c8630              movaps   xmm3, xmmword ptr [esi + eax*4 + 0x30] 
  0x00365545  0f286c8660              movaps   xmm5, xmmword ptr [esi + eax*4 + 0x60] 
  0x0036554A  0f287c8670              movaps   xmm7, xmmword ptr [esi + eax*4 + 0x70] 
  0x0036554F  0f2b07                  movntps  xmmword ptr [edi], xmm0        
  0x00365552  0f2b6710                movntps  xmmword ptr [edi + 0x10], xmm4 
  0x00365556  0f2b1417                movntps  xmmword ptr [edi + edx], xmm2  
  0x0036555A  0f2b741710              movntps  xmmword ptr [edi + edx + 0x10], xmm6 
  0x0036555F  03fa                    add      edi, edx                       
  0x00365561  0f28c1                  movaps   xmm0, xmm1                     
  0x00365564  0f28e5                  movaps   xmm4, xmm5                     
  0x00365567  0f16cb                  movlhps  xmm1, xmm3                     
  0x0036556A  0f12d8                  movhlps  xmm3, xmm0                     
  0x0036556D  0f16ef                  movlhps  xmm5, xmm7                     
  0x00365570  0f12fc                  movhlps  xmm7, xmm4                     
  0x00365573  0f2b0c17                movntps  xmmword ptr [edi + edx], xmm1  
  0x00365577  0f2b6c1710              movntps  xmmword ptr [edi + edx + 0x10], xmm5 
  0x0036557C  0f2b1c57                movntps  xmmword ptr [edi + edx*2], xmm3 
  0x00365580  0f2b7c5710              movntps  xmmword ptr [edi + edx*2 + 0x10], xmm7 
  0x00365585  2bfa                    sub      edi, edx                       
  0x00365587  90                      nop                                     
  0x00365588  90                      nop                                     
  0x00365589  90                      nop                                     
  0x0036558A  90                      nop                                     
  0x0036558B  90                      nop                                     
  0x0036558C  90                      nop                                     
  0x0036558D  90                      nop                                     
  0x0036558E  90                      nop                                     
  0x0036558F  90                      nop                                     
  0x00365590  90                      nop                                     
  0x00365591  90                      nop                                     
  0x00365592  90                      nop                                     
  0x00365593  90                      nop                                     
  0x00365594  90                      nop                                     
  0x00365595  90                      nop                                     
  0x00365596  90                      nop                                     
  0x00365597  90                      nop                                     
  0x00365598  90                      nop                                     
  0x00365599  90                      nop                                     
  0x0036559A  90                      nop                                     
  0x0036559B  90                      nop                                     
  0x0036559C  90                      nop                                     
  0x0036559D  90                      nop                                     
  0x0036559E  90                      nop                                     
  0x0036559F  90                      nop                                     
  0x003655A0  90                      nop                                     
  0x003655A1  90                      nop                                     
  0x003655A2  90                      nop                                     
  0x003655A3  83c720                  add      edi, 0x20                      
  0x003655A6  235dfc                  and      ebx, dword ptr [ebp - 4]       
  0x003655A9  0f8560ffffff            jne      0x36550f                       
  0x003655AF  2b4df8                  sub      ecx, dword ptr [ebp - 8]       
  0x003655B2  8d3c97                  lea      edi, [edi + edx*4]             
  0x003655B5  2bfa                    sub      edi, edx                       
  0x003655B7  234d14                  and      ecx, dword ptr [ebp + 0x14]    
  0x003655BA  0f854fffffff            jne      0x36550f                       
  0x003655C0  5f                      pop      edi                            
  0x003655C1  5e                      pop      esi                            
  0x003655C2  5b                      pop      ebx                            
  0x003655C3  c9                      leave                                   
  0x003655C4  c21000                  ret      0x10                           
; end of function

; ============================================================
; Function: sub_003655C7
; Start: 0x003655C7  End: 0x0036560B  Size: 68 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_0006B340, sub_000B08C0, sub_00277420, sub_00277C50, sub_0035BE6F, sub_0035C079
; ============================================================
sub_003655C7:
  0x003655C7  8b442404                mov      eax, dword ptr [esp + 4]       
  0x003655CB  83f82d                  cmp      eax, 0x2d                      
  0x003655CE  7f22                    jg       0x3655f2                       
  0x003655D0  83f827                  cmp      eax, 0x27                      
  0x003655D3  7d31                    jge      0x365606                       
  0x003655D5  85c0                    test     eax, eax                       
  0x003655D7  7c14                    jl       0x3655ed                       
  0x003655D9  83f807                  cmp      eax, 7                         
  0x003655DC  7e28                    jle      0x365606                       
  0x003655DE  83f80b                  cmp      eax, 0xb                       
  0x003655E1  7423                    je       0x365606                       
  0x003655E3  83f818                  cmp      eax, 0x18                      
  0x003655E6  7e05                    jle      0x3655ed                       
  0x003655E8  83f81a                  cmp      eax, 0x1a                      
  0x003655EB  7e19                    jle      0x365606                       
                                        ; XREF: 0x003655D7 (cond_jump), 0x003655E6 (cond_jump), 0x003655F5 (cond_jump), 0x003655FF (cond_jump), 0x00365604 (cond_jump)
  0x003655ED  33c0                    xor      eax, eax                       
                                        ; XREF: 0x00365609 (jump)
  0x003655EF  c20400                  ret      4                              
                                        ; XREF: 0x003655CE (cond_jump)
  0x003655F2  83f832                  cmp      eax, 0x32                      
  0x003655F5  7cf6                    jl       0x3655ed                       
  0x003655F7  83f833                  cmp      eax, 0x33                      
  0x003655FA  7e0a                    jle      0x365606                       
  0x003655FC  83f837                  cmp      eax, 0x37                      
  0x003655FF  7eec                    jle      0x3655ed                       
  0x00365601  83f83c                  cmp      eax, 0x3c                      
  0x00365604  7fe7                    jg       0x3655ed                       
                                        ; XREF: 0x003655D3 (cond_jump), 0x003655DC (cond_jump), 0x003655E1 (cond_jump), 0x003655EB (cond_jump), 0x003655FA (cond_jump)
  0x00365606  33c0                    xor      eax, eax                       
  0x00365608  40                      inc      eax                            
  0x00365609  ebe4                    jmp      0x3655ef                       
; end of function

; ============================================================
; Function: sub_0036560B
; Start: 0x0036560B  End: 0x00365635  Size: 42 bytes
; Detection: call_target (confidence: 0.90)
; Called by: sub_0027DF50, sub_0035BE6F, sub_0035C079
; ============================================================
sub_0036560B:
  0x0036560B  8b442404                mov      eax, dword ptr [esp + 4]       
  0x0036560F  83f841                  cmp      eax, 0x41                      
  0x00365612  771c                    ja       0x365630                       
  0x00365614  0fb68045563600          movzx    eax, byte ptr [eax + 0x365645] 
  0x0036561B  ff248535563600          jmp      dword ptr [eax*4 + 0x365635]   
  0x00365622  6a04                    push     4                              
  0x00365624  eb02                    jmp      0x365628                       
  0x00365626  6a02                    push     2                              
                                        ; XREF: 0x00365624 (jump)
  0x00365628  58                      pop      eax                            
  0x00365629  eb07                    jmp      0x365632                       
  0x0036562B  33c0                    xor      eax, eax                       
  0x0036562D  40                      inc      eax                            
  0x0036562E  eb02                    jmp      0x365632                       
                                        ; XREF: 0x00365612 (cond_jump)
  0x00365630  33c0                    xor      eax, eax                       
                                        ; XREF: 0x00365629 (jump), 0x0036562E (jump)
  0x00365632  c20400                  ret      4                              
; end of function
  0x00365635  2b5636                  sub      edx, dword ptr [esi + 0x36]    
  0x00365638  0026                    add      byte ptr [esi], ah             
  0x0036563A  56                      push     esi                            
  0x0036563B  360022                  add      byte ptr ss:[edx], ah          
  0x0036563E  56                      push     esi                            
  0x0036563F  360030                  add      byte ptr ss:[eax], dh          
  0x00365642  56                      push     esi                            
  0x00365643  360000                  add      byte ptr ss:[eax], al          
  0x00365646  0001                    add      byte ptr [ecx], al             
  0x00365648  0101                    add      dword ptr [ecx], eax           
  0x0036564A  0102                    add      dword ptr [edx], eax           
  0x0036564C  0203                    add      al, byte ptr [ebx]             
  0x0036564E  0303                    add      eax, dword ptr [ebx]           
  0x00365650  0003                    add      byte ptr [ebx], al             
  0x00365652  0300                    add      eax, dword ptr [eax]           
  0x00365654  0001                    add      byte ptr [ecx], al             
  0x00365656  0102                    add      dword ptr [edx], eax           
  0x00365658  0003                    add      byte ptr [ebx], al             
  0x0036565A  0301                    add      eax, dword ptr [ecx]           
  0x0036565C  0103                    add      dword ptr [ebx], eax           
  0x0036565E  0001                    add      byte ptr [ecx], al             
  0x00365660  0001                    add      byte ptr [ecx], al             
  0x00365662  0102                    add      dword ptr [edx], eax           
  0x00365664  0001                    add      byte ptr [ecx], al             
  0x00365666  0303                    add      eax, dword ptr [ebx]           
  0x00365668  0302                    add      eax, dword ptr [edx]           
  0x0036566A  0203                    add      al, byte ptr [ebx]             
  0x0036566C  0101                    add      dword ptr [ecx], eax           
  0x0036566E  0102                    add      dword ptr [edx], eax           
  0x00365670  0201                    add      al, byte ptr [ecx]             
  0x00365672  0102                    add      dword ptr [edx], eax           
  0x00365674  0201                    add      al, byte ptr [ecx]             
  0x00365676  0101                    add      dword ptr [ecx], eax           
  0x00365678  0203                    add      al, byte ptr [ebx]             
  0x0036567A  0103                    add      dword ptr [ebx], eax           
  0x0036567C  0101                    add      dword ptr [ecx], eax           
  0x0036567E  0102                    add      dword ptr [edx], eax           
  0x00365680  0202                    add      al, byte ptr [edx]             
  0x00365682  0101                    add      dword ptr [ecx], eax           
  0x00365684  0202                    add      al, byte ptr [edx]             
  0x00365686  02558b                  add      dl, byte ptr [ebp - 0x75]      
  0x00365689  ec                      in       al, dx                         
  0x0036568A  53                      push     ebx                            
  0x0036568B  56                      push     esi                            
  0x0036568C  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x0036568F  8b5e2c                  mov      ebx, dword ptr [esi + 0x2c]    
  0x00365692  8b4628                  mov      eax, dword ptr [esi + 0x28]    
  0x00365695  57                      push     edi                            
  0x00365696  03c3                    add      eax, ebx                       
  0x00365698  8d7e40                  lea      edi, [esi + 0x40]              
  0x0036569B  50                      push     eax                            
  0x0036569C  8bcf                    mov      ecx, edi                       
  0x0036569E  e87cf8ffff              call     0x364f1f                       ; -> sub_00364F1F
  0x003656A3  8b4e24                  mov      ecx, dword ptr [esi + 0x24]    
  0x003656A6  894508                  mov      dword ptr [ebp + 8], eax       
  0x003656A9  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x003656AC  03c8                    add      ecx, eax                       
  0x003656AE  51                      push     ecx                            
  0x003656AF  8bcf                    mov      ecx, edi                       
  0x003656B1  e892f8ffff              call     0x364f48                       ; -> sub_00364F48
  0x003656B6  8b4e08                  mov      ecx, dword ptr [esi + 8]       
  0x003656B9  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x003656BC  83665800                and      dword ptr [esi + 0x58], 0      
  0x003656C0  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x003656C3  8b460c                  mov      eax, dword ptr [esi + 0xc]     
  0x003656C6  034630                  add      eax, dword ptr [esi + 0x30]    
  0x003656C9  03cb                    add      ecx, ebx                       
  0x003656CB  0faf4604                imul     eax, dword ptr [esi + 4]       
  0x003656CF  8d0488                  lea      eax, [eax + ecx*4]             
  0x003656D2  8b4e18                  mov      ecx, dword ptr [esi + 0x18]    
  0x003656D5  0306                    add      eax, dword ptr [esi]           
  0x003656D7  8d0c91                  lea      ecx, [ecx + edx*4]             
  0x003656DA  8b5638                  mov      edx, dword ptr [esi + 0x38]    
  0x003656DD  85d2                    test     edx, edx                       
  0x003656DF  7420                    je       0x365701                       
  0x003656E1  895508                  mov      dword ptr [ebp + 8], edx       
                                        ; XREF: 0x003656FF (cond_jump)
  0x003656E4  8b18                    mov      ebx, dword ptr [eax]           
  0x003656E6  8b565c                  mov      edx, dword ptr [esi + 0x5c]    
  0x003656E9  891c91                  mov      dword ptr [ecx + edx*4], ebx   
  0x003656EC  8b5710                  mov      edx, dword ptr [edi + 0x10]    
  0x003656EF  8b5f1c                  mov      ebx, dword ptr [edi + 0x1c]    
  0x003656F2  2bda                    sub      ebx, edx                       
  0x003656F4  23da                    and      ebx, edx                       
  0x003656F6  895f1c                  mov      dword ptr [edi + 0x1c], ebx    
  0x003656F9  034604                  add      eax, dword ptr [esi + 4]       
  0x003656FC  ff4d08                  dec      dword ptr [ebp + 8]            
  0x003656FF  75e3                    jne      0x3656e4                       
                                        ; XREF: 0x003656DF (cond_jump)
  0x00365701  5f                      pop      edi                            
  0x00365702  5e                      pop      esi                            
  0x00365703  5b                      pop      ebx                            
  0x00365704  5d                      pop      ebp                            
  0x00365705  c20400                  ret      4                              

; ============================================================
; Function: sub_00365708
; Start: 0x00365708  End: 0x00365789  Size: 129 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364F1F, sub_00364F48
; Called by: sub_003665CE
; ============================================================
sub_00365708:
  0x00365708  55                      push     ebp                            
  0x00365709  8bec                    mov      ebp, esp                       
  0x0036570B  53                      push     ebx                            
  0x0036570C  56                      push     esi                            
  0x0036570D  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00365710  8b5e2c                  mov      ebx, dword ptr [esi + 0x2c]    
  0x00365713  8b4608                  mov      eax, dword ptr [esi + 8]       
  0x00365716  57                      push     edi                            
  0x00365717  03c3                    add      eax, ebx                       
  0x00365719  8d7e40                  lea      edi, [esi + 0x40]              
  0x0036571C  50                      push     eax                            
  0x0036571D  8bcf                    mov      ecx, edi                       
  0x0036571F  e8fbf7ffff              call     0x364f1f                       ; -> sub_00364F1F
  0x00365724  8b4e0c                  mov      ecx, dword ptr [esi + 0xc]     
  0x00365727  894508                  mov      dword ptr [ebp + 8], eax       
  0x0036572A  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x0036572D  03c8                    add      ecx, eax                       
  0x0036572F  51                      push     ecx                            
  0x00365730  8bcf                    mov      ecx, edi                       
  0x00365732  e811f8ffff              call     0x364f48                       ; -> sub_00364F48
  0x00365737  8b4d08                  mov      ecx, dword ptr [ebp + 8]       
  0x0036573A  8b5628                  mov      edx, dword ptr [esi + 0x28]    
  0x0036573D  83665800                and      dword ptr [esi + 0x58], 0      
  0x00365741  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x00365744  8b06                    mov      eax, dword ptr [esi]           
  0x00365746  8d0c88                  lea      ecx, [eax + ecx*4]             
  0x00365749  8b4624                  mov      eax, dword ptr [esi + 0x24]    
  0x0036574C  034630                  add      eax, dword ptr [esi + 0x30]    
  0x0036574F  03d3                    add      edx, ebx                       
  0x00365751  0faf4604                imul     eax, dword ptr [esi + 4]       
  0x00365755  8d0490                  lea      eax, [eax + edx*4]             
  0x00365758  8b5638                  mov      edx, dword ptr [esi + 0x38]    
  0x0036575B  034618                  add      eax, dword ptr [esi + 0x18]    
  0x0036575E  85d2                    test     edx, edx                       
  0x00365760  7420                    je       0x365782                       
  0x00365762  895508                  mov      dword ptr [ebp + 8], edx       
                                        ; XREF: 0x00365780 (cond_jump)
  0x00365765  8b565c                  mov      edx, dword ptr [esi + 0x5c]    
  0x00365768  8b1491                  mov      edx, dword ptr [ecx + edx*4]   
  0x0036576B  8910                    mov      dword ptr [eax], edx           
  0x0036576D  8b5710                  mov      edx, dword ptr [edi + 0x10]    
  0x00365770  8b5f1c                  mov      ebx, dword ptr [edi + 0x1c]    
  0x00365773  2bda                    sub      ebx, edx                       
  0x00365775  23da                    and      ebx, edx                       
  0x00365777  895f1c                  mov      dword ptr [edi + 0x1c], ebx    
  0x0036577A  034604                  add      eax, dword ptr [esi + 4]       
  0x0036577D  ff4d08                  dec      dword ptr [ebp + 8]            
  0x00365780  75e3                    jne      0x365765                       
                                        ; XREF: 0x00365760 (cond_jump)
  0x00365782  5f                      pop      edi                            
  0x00365783  5e                      pop      esi                            
  0x00365784  5b                      pop      ebx                            
  0x00365785  5d                      pop      ebp                            
  0x00365786  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00365789
; Start: 0x00365789  End: 0x0036585D  Size: 212 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364F1F, sub_00364F48
; Called by: sub_00365E7D
; ============================================================
sub_00365789:
  0x00365789  55                      push     ebp                            
  0x0036578A  8bec                    mov      ebp, esp                       
  0x0036578C  51                      push     ecx                            
  0x0036578D  51                      push     ecx                            
  0x0036578E  53                      push     ebx                            
  0x0036578F  56                      push     esi                            
  0x00365790  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00365793  8b462c                  mov      eax, dword ptr [esi + 0x2c]    
  0x00365796  8b5628                  mov      edx, dword ptr [esi + 0x28]    
  0x00365799  8b5e50                  mov      ebx, dword ptr [esi + 0x50]    
  0x0036579C  57                      push     edi                            
  0x0036579D  8b7e4c                  mov      edi, dword ptr [esi + 0x4c]    
  0x003657A0  03d0                    add      edx, eax                       
  0x003657A2  8d4e40                  lea      ecx, [esi + 0x40]              
  0x003657A5  52                      push     edx                            
  0x003657A6  897e64                  mov      dword ptr [esi + 0x64], edi    
  0x003657A9  895e68                  mov      dword ptr [esi + 0x68], ebx    
  0x003657AC  e86ef7ffff              call     0x364f1f                       ; -> sub_00364F1F
  0x003657B1  8b4e24                  mov      ecx, dword ptr [esi + 0x24]    
  0x003657B4  894508                  mov      dword ptr [ebp + 8], eax       
  0x003657B7  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x003657BA  03c8                    add      ecx, eax                       
  0x003657BC  51                      push     ecx                            
  0x003657BD  8d4e40                  lea      ecx, [esi + 0x40]              
  0x003657C0  e883f7ffff              call     0x364f48                       ; -> sub_00364F48
  0x003657C5  8b5634                  mov      edx, dword ptr [esi + 0x34]    
  0x003657C8  8b4e04                  mov      ecx, dword ptr [esi + 4]       
  0x003657CB  d16d08                  shr      dword ptr [ebp + 8], 1         
  0x003657CE  d1ef                    shr      edi, 1                         
  0x003657D0  897e4c                  mov      dword ptr [esi + 0x4c], edi    
  0x003657D3  d1e2                    shl      edx, 1                         
  0x003657D5  8bfa                    mov      edi, edx                       
  0x003657D7  8bd1                    mov      edx, ecx                       
  0x003657D9  2bd7                    sub      edx, edi                       
  0x003657DB  8b7e0c                  mov      edi, dword ptr [esi + 0xc]     
  0x003657DE  037e30                  add      edi, dword ptr [esi + 0x30]    
  0x003657E1  d1e8                    shr      eax, 1                         
  0x003657E3  0faff9                  imul     edi, ecx                       
  0x003657E6  8b4e08                  mov      ecx, dword ptr [esi + 8]       
  0x003657E9  034e2c                  add      ecx, dword ptr [esi + 0x2c]    
  0x003657EC  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x003657EF  8b4638                  mov      eax, dword ptr [esi + 0x38]    
  0x003657F2  8d0c4f                  lea      ecx, [edi + ecx*2]             
  0x003657F5  030e                    add      ecx, dword ptr [esi]           
  0x003657F7  8b7e18                  mov      edi, dword ptr [esi + 0x18]    
  0x003657FA  d1eb                    shr      ebx, 1                         
  0x003657FC  85c0                    test     eax, eax                       
  0x003657FE  895e50                  mov      dword ptr [esi + 0x50], ebx    
  0x00365801  7447                    je       0x36584a                       
  0x00365803  8945f8                  mov      dword ptr [ebp - 8], eax       
                                        ; XREF: 0x00365848 (cond_jump)
  0x00365806  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x00365809  894658                  mov      dword ptr [esi + 0x58], eax    
  0x0036580C  8b4634                  mov      eax, dword ptr [esi + 0x34]    
  0x0036580F  d1f8                    sar      eax, 1                         
  0x00365811  7423                    je       0x365836                       
  0x00365813  8945fc                  mov      dword ptr [ebp - 4], eax       
                                        ; XREF: 0x00365834 (cond_jump)
  0x00365816  8b465c                  mov      eax, dword ptr [esi + 0x5c]    
  0x00365819  0b4658                  or       eax, dword ptr [esi + 0x58]    
  0x0036581C  8b19                    mov      ebx, dword ptr [ecx]           
  0x0036581E  891c87                  mov      dword ptr [edi + eax*4], ebx   
  0x00365821  8b464c                  mov      eax, dword ptr [esi + 0x4c]    
  0x00365824  8b5e58                  mov      ebx, dword ptr [esi + 0x58]    
  0x00365827  2bd8                    sub      ebx, eax                       
  0x00365829  23d8                    and      ebx, eax                       
  0x0036582B  83c104                  add      ecx, 4                         
  0x0036582E  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00365831  895e58                  mov      dword ptr [esi + 0x58], ebx    
  0x00365834  75e0                    jne      0x365816                       
                                        ; XREF: 0x00365811 (cond_jump)
  0x00365836  8b4650                  mov      eax, dword ptr [esi + 0x50]    
  0x00365839  8b5e5c                  mov      ebx, dword ptr [esi + 0x5c]    
  0x0036583C  2bd8                    sub      ebx, eax                       
  0x0036583E  23d8                    and      ebx, eax                       
  0x00365840  03ca                    add      ecx, edx                       
  0x00365842  ff4df8                  dec      dword ptr [ebp - 8]            
  0x00365845  895e5c                  mov      dword ptr [esi + 0x5c], ebx    
  0x00365848  75bc                    jne      0x365806                       
                                        ; XREF: 0x00365801 (cond_jump)
  0x0036584A  8b4664                  mov      eax, dword ptr [esi + 0x64]    
  0x0036584D  89464c                  mov      dword ptr [esi + 0x4c], eax    
  0x00365850  8b4668                  mov      eax, dword ptr [esi + 0x68]    
  0x00365853  5f                      pop      edi                            
  0x00365854  894650                  mov      dword ptr [esi + 0x50], eax    
  0x00365857  5e                      pop      esi                            
  0x00365858  5b                      pop      ebx                            
  0x00365859  c9                      leave                                   
  0x0036585A  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_0036585D
; Start: 0x0036585D  End: 0x00365931  Size: 212 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364F1F, sub_00364F48
; Called by: sub_003665CE
; ============================================================
sub_0036585D:
  0x0036585D  55                      push     ebp                            
  0x0036585E  8bec                    mov      ebp, esp                       
  0x00365860  51                      push     ecx                            
  0x00365861  51                      push     ecx                            
  0x00365862  53                      push     ebx                            
  0x00365863  56                      push     esi                            
  0x00365864  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00365867  8b462c                  mov      eax, dword ptr [esi + 0x2c]    
  0x0036586A  8b5608                  mov      edx, dword ptr [esi + 8]       
  0x0036586D  8b5e50                  mov      ebx, dword ptr [esi + 0x50]    
  0x00365870  57                      push     edi                            
  0x00365871  8b7e4c                  mov      edi, dword ptr [esi + 0x4c]    
  0x00365874  03d0                    add      edx, eax                       
  0x00365876  8d4e40                  lea      ecx, [esi + 0x40]              
  0x00365879  52                      push     edx                            
  0x0036587A  897e64                  mov      dword ptr [esi + 0x64], edi    
  0x0036587D  895e68                  mov      dword ptr [esi + 0x68], ebx    
  0x00365880  e89af6ffff              call     0x364f1f                       ; -> sub_00364F1F
  0x00365885  8b4e0c                  mov      ecx, dword ptr [esi + 0xc]     
  0x00365888  894508                  mov      dword ptr [ebp + 8], eax       
  0x0036588B  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x0036588E  03c8                    add      ecx, eax                       
  0x00365890  51                      push     ecx                            
  0x00365891  8d4e40                  lea      ecx, [esi + 0x40]              
  0x00365894  e8aff6ffff              call     0x364f48                       ; -> sub_00364F48
  0x00365899  8b4e04                  mov      ecx, dword ptr [esi + 4]       
  0x0036589C  8b5634                  mov      edx, dword ptr [esi + 0x34]    
  0x0036589F  d16d08                  shr      dword ptr [ebp + 8], 1         
  0x003658A2  d1eb                    shr      ebx, 1                         
  0x003658A4  895e50                  mov      dword ptr [esi + 0x50], ebx    
  0x003658A7  8b5e24                  mov      ebx, dword ptr [esi + 0x24]    
  0x003658AA  035e30                  add      ebx, dword ptr [esi + 0x30]    
  0x003658AD  d1ef                    shr      edi, 1                         
  0x003658AF  0fafd9                  imul     ebx, ecx                       
  0x003658B2  d1e2                    shl      edx, 1                         
  0x003658B4  897e4c                  mov      dword ptr [esi + 0x4c], edi    
  0x003658B7  8bfa                    mov      edi, edx                       
  0x003658B9  8bd1                    mov      edx, ecx                       
  0x003658BB  8b4e28                  mov      ecx, dword ptr [esi + 0x28]    
  0x003658BE  034e2c                  add      ecx, dword ptr [esi + 0x2c]    
  0x003658C1  d1e8                    shr      eax, 1                         
  0x003658C3  8d0c4b                  lea      ecx, [ebx + ecx*2]             
  0x003658C6  034e18                  add      ecx, dword ptr [esi + 0x18]    
  0x003658C9  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x003658CC  8b4638                  mov      eax, dword ptr [esi + 0x38]    
  0x003658CF  2bd7                    sub      edx, edi                       
  0x003658D1  85c0                    test     eax, eax                       
  0x003658D3  8b3e                    mov      edi, dword ptr [esi]           
  0x003658D5  7447                    je       0x36591e                       
  0x003658D7  8945f8                  mov      dword ptr [ebp - 8], eax       
                                        ; XREF: 0x0036591C (cond_jump)
  0x003658DA  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x003658DD  894658                  mov      dword ptr [esi + 0x58], eax    
  0x003658E0  8b4634                  mov      eax, dword ptr [esi + 0x34]    
  0x003658E3  d1f8                    sar      eax, 1                         
  0x003658E5  7423                    je       0x36590a                       
  0x003658E7  8945fc                  mov      dword ptr [ebp - 4], eax       
                                        ; XREF: 0x00365908 (cond_jump)
  0x003658EA  8b465c                  mov      eax, dword ptr [esi + 0x5c]    
  0x003658ED  0b4658                  or       eax, dword ptr [esi + 0x58]    
  0x003658F0  8b0487                  mov      eax, dword ptr [edi + eax*4]   
  0x003658F3  8901                    mov      dword ptr [ecx], eax           
  0x003658F5  8b464c                  mov      eax, dword ptr [esi + 0x4c]    
  0x003658F8  8b5e58                  mov      ebx, dword ptr [esi + 0x58]    
  0x003658FB  2bd8                    sub      ebx, eax                       
  0x003658FD  23d8                    and      ebx, eax                       
  0x003658FF  83c104                  add      ecx, 4                         
  0x00365902  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00365905  895e58                  mov      dword ptr [esi + 0x58], ebx    
  0x00365908  75e0                    jne      0x3658ea                       
                                        ; XREF: 0x003658E5 (cond_jump)
  0x0036590A  8b4650                  mov      eax, dword ptr [esi + 0x50]    
  0x0036590D  8b5e5c                  mov      ebx, dword ptr [esi + 0x5c]    
  0x00365910  2bd8                    sub      ebx, eax                       
  0x00365912  23d8                    and      ebx, eax                       
  0x00365914  03ca                    add      ecx, edx                       
  0x00365916  ff4df8                  dec      dword ptr [ebp - 8]            
  0x00365919  895e5c                  mov      dword ptr [esi + 0x5c], ebx    
  0x0036591C  75bc                    jne      0x3658da                       
                                        ; XREF: 0x003658D5 (cond_jump)
  0x0036591E  8b4664                  mov      eax, dword ptr [esi + 0x64]    
  0x00365921  89464c                  mov      dword ptr [esi + 0x4c], eax    
  0x00365924  8b4668                  mov      eax, dword ptr [esi + 0x68]    
  0x00365927  5f                      pop      edi                            
  0x00365928  894650                  mov      dword ptr [esi + 0x50], eax    
  0x0036592B  5e                      pop      esi                            
  0x0036592C  5b                      pop      ebx                            
  0x0036592D  c9                      leave                                   
  0x0036592E  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00365931
; Start: 0x00365931  End: 0x003659B4  Size: 131 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364F1F, sub_00364F48
; Called by: sub_00365E7D
; ============================================================
sub_00365931:
  0x00365931  55                      push     ebp                            
  0x00365932  8bec                    mov      ebp, esp                       
  0x00365934  53                      push     ebx                            
  0x00365935  56                      push     esi                            
  0x00365936  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00365939  8b5e2c                  mov      ebx, dword ptr [esi + 0x2c]    
  0x0036593C  8b4628                  mov      eax, dword ptr [esi + 0x28]    
  0x0036593F  57                      push     edi                            
  0x00365940  03c3                    add      eax, ebx                       
  0x00365942  8d7e40                  lea      edi, [esi + 0x40]              
  0x00365945  50                      push     eax                            
  0x00365946  8bcf                    mov      ecx, edi                       
  0x00365948  e8d2f5ffff              call     0x364f1f                       ; -> sub_00364F1F
  0x0036594D  8b4e24                  mov      ecx, dword ptr [esi + 0x24]    
  0x00365950  894508                  mov      dword ptr [ebp + 8], eax       
  0x00365953  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x00365956  03c8                    add      ecx, eax                       
  0x00365958  51                      push     ecx                            
  0x00365959  8bcf                    mov      ecx, edi                       
  0x0036595B  e8e8f5ffff              call     0x364f48                       ; -> sub_00364F48
  0x00365960  8b4e08                  mov      ecx, dword ptr [esi + 8]       
  0x00365963  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x00365966  83665800                and      dword ptr [esi + 0x58], 0      
  0x0036596A  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x0036596D  8b460c                  mov      eax, dword ptr [esi + 0xc]     
  0x00365970  034630                  add      eax, dword ptr [esi + 0x30]    
  0x00365973  03cb                    add      ecx, ebx                       
  0x00365975  0faf4604                imul     eax, dword ptr [esi + 4]       
  0x00365979  8d0448                  lea      eax, [eax + ecx*2]             
  0x0036597C  8b4e18                  mov      ecx, dword ptr [esi + 0x18]    
  0x0036597F  0306                    add      eax, dword ptr [esi]           
  0x00365981  8d0c51                  lea      ecx, [ecx + edx*2]             
  0x00365984  8b5638                  mov      edx, dword ptr [esi + 0x38]    
  0x00365987  85d2                    test     edx, edx                       
  0x00365989  7422                    je       0x3659ad                       
  0x0036598B  895508                  mov      dword ptr [ebp + 8], edx       
                                        ; XREF: 0x003659AB (cond_jump)
  0x0036598E  668b18                  mov      bx, word ptr [eax]             
  0x00365991  8b565c                  mov      edx, dword ptr [esi + 0x5c]    
  0x00365994  66891c51                mov      word ptr [ecx + edx*2], bx     
  0x00365998  8b5710                  mov      edx, dword ptr [edi + 0x10]    
  0x0036599B  8b5f1c                  mov      ebx, dword ptr [edi + 0x1c]    
  0x0036599E  2bda                    sub      ebx, edx                       
  0x003659A0  23da                    and      ebx, edx                       
  0x003659A2  895f1c                  mov      dword ptr [edi + 0x1c], ebx    
  0x003659A5  034604                  add      eax, dword ptr [esi + 4]       
  0x003659A8  ff4d08                  dec      dword ptr [ebp + 8]            
  0x003659AB  75e1                    jne      0x36598e                       
                                        ; XREF: 0x00365989 (cond_jump)
  0x003659AD  5f                      pop      edi                            
  0x003659AE  5e                      pop      esi                            
  0x003659AF  5b                      pop      ebx                            
  0x003659B0  5d                      pop      ebp                            
  0x003659B1  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_003659B4
; Start: 0x003659B4  End: 0x00365A37  Size: 131 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364F1F, sub_00364F48
; Called by: sub_003665CE
; ============================================================
sub_003659B4:
  0x003659B4  55                      push     ebp                            
  0x003659B5  8bec                    mov      ebp, esp                       
  0x003659B7  53                      push     ebx                            
  0x003659B8  56                      push     esi                            
  0x003659B9  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x003659BC  8b5e2c                  mov      ebx, dword ptr [esi + 0x2c]    
  0x003659BF  8b4608                  mov      eax, dword ptr [esi + 8]       
  0x003659C2  57                      push     edi                            
  0x003659C3  03c3                    add      eax, ebx                       
  0x003659C5  8d7e40                  lea      edi, [esi + 0x40]              
  0x003659C8  50                      push     eax                            
  0x003659C9  8bcf                    mov      ecx, edi                       
  0x003659CB  e84ff5ffff              call     0x364f1f                       ; -> sub_00364F1F
  0x003659D0  8b4e0c                  mov      ecx, dword ptr [esi + 0xc]     
  0x003659D3  894508                  mov      dword ptr [ebp + 8], eax       
  0x003659D6  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x003659D9  03c8                    add      ecx, eax                       
  0x003659DB  51                      push     ecx                            
  0x003659DC  8bcf                    mov      ecx, edi                       
  0x003659DE  e865f5ffff              call     0x364f48                       ; -> sub_00364F48
  0x003659E3  8b4d08                  mov      ecx, dword ptr [ebp + 8]       
  0x003659E6  8b5628                  mov      edx, dword ptr [esi + 0x28]    
  0x003659E9  83665800                and      dword ptr [esi + 0x58], 0      
  0x003659ED  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x003659F0  8b06                    mov      eax, dword ptr [esi]           
  0x003659F2  8d0c48                  lea      ecx, [eax + ecx*2]             
  0x003659F5  8b4624                  mov      eax, dword ptr [esi + 0x24]    
  0x003659F8  034630                  add      eax, dword ptr [esi + 0x30]    
  0x003659FB  03d3                    add      edx, ebx                       
  0x003659FD  0faf4604                imul     eax, dword ptr [esi + 4]       
  0x00365A01  8d0450                  lea      eax, [eax + edx*2]             
  0x00365A04  8b5638                  mov      edx, dword ptr [esi + 0x38]    
  0x00365A07  034618                  add      eax, dword ptr [esi + 0x18]    
  0x00365A0A  85d2                    test     edx, edx                       
  0x00365A0C  7422                    je       0x365a30                       
  0x00365A0E  895508                  mov      dword ptr [ebp + 8], edx       
                                        ; XREF: 0x00365A2E (cond_jump)
  0x00365A11  8b565c                  mov      edx, dword ptr [esi + 0x5c]    
  0x00365A14  668b1451                mov      dx, word ptr [ecx + edx*2]     
  0x00365A18  668910                  mov      word ptr [eax], dx             
  0x00365A1B  8b5710                  mov      edx, dword ptr [edi + 0x10]    
  0x00365A1E  8b5f1c                  mov      ebx, dword ptr [edi + 0x1c]    
  0x00365A21  2bda                    sub      ebx, edx                       
  0x00365A23  23da                    and      ebx, edx                       
  0x00365A25  895f1c                  mov      dword ptr [edi + 0x1c], ebx    
  0x00365A28  034604                  add      eax, dword ptr [esi + 4]       
  0x00365A2B  ff4d08                  dec      dword ptr [ebp + 8]            
  0x00365A2E  75e1                    jne      0x365a11                       
                                        ; XREF: 0x00365A0C (cond_jump)
  0x00365A30  5f                      pop      edi                            
  0x00365A31  5e                      pop      esi                            
  0x00365A32  5b                      pop      ebx                            
  0x00365A33  5d                      pop      ebp                            
  0x00365A34  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00365A37
; Start: 0x00365A37  End: 0x00365B03  Size: 204 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364F1F, sub_00364F48
; Called by: sub_00365E7D
; ============================================================
sub_00365A37:
  0x00365A37  55                      push     ebp                            
  0x00365A38  8bec                    mov      ebp, esp                       
  0x00365A3A  51                      push     ecx                            
  0x00365A3B  51                      push     ecx                            
  0x00365A3C  53                      push     ebx                            
  0x00365A3D  56                      push     esi                            
  0x00365A3E  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00365A41  8b462c                  mov      eax, dword ptr [esi + 0x2c]    
  0x00365A44  8b5628                  mov      edx, dword ptr [esi + 0x28]    
  0x00365A47  8b5e50                  mov      ebx, dword ptr [esi + 0x50]    
  0x00365A4A  57                      push     edi                            
  0x00365A4B  8b7e4c                  mov      edi, dword ptr [esi + 0x4c]    
  0x00365A4E  03d0                    add      edx, eax                       
  0x00365A50  8d4e40                  lea      ecx, [esi + 0x40]              
  0x00365A53  52                      push     edx                            
  0x00365A54  897e64                  mov      dword ptr [esi + 0x64], edi    
  0x00365A57  895e68                  mov      dword ptr [esi + 0x68], ebx    
  0x00365A5A  e8c0f4ffff              call     0x364f1f                       ; -> sub_00364F1F
  0x00365A5F  8b4e24                  mov      ecx, dword ptr [esi + 0x24]    
  0x00365A62  894508                  mov      dword ptr [ebp + 8], eax       
  0x00365A65  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x00365A68  03c8                    add      ecx, eax                       
  0x00365A6A  51                      push     ecx                            
  0x00365A6B  8d4e40                  lea      ecx, [esi + 0x40]              
  0x00365A6E  e8d5f4ffff              call     0x364f48                       ; -> sub_00364F48
  0x00365A73  8b4e0c                  mov      ecx, dword ptr [esi + 0xc]     
  0x00365A76  034e30                  add      ecx, dword ptr [esi + 0x30]    
  0x00365A79  d16d08                  shr      dword ptr [ebp + 8], 1         
  0x00365A7C  d1ef                    shr      edi, 1                         
  0x00365A7E  897e4c                  mov      dword ptr [esi + 0x4c], edi    
  0x00365A81  8b7e04                  mov      edi, dword ptr [esi + 4]       
  0x00365A84  0fafcf                  imul     ecx, edi                       
  0x00365A87  034e08                  add      ecx, dword ptr [esi + 8]       
  0x00365A8A  d1e8                    shr      eax, 1                         
  0x00365A8C  034e2c                  add      ecx, dword ptr [esi + 0x2c]    
  0x00365A8F  8bd7                    mov      edx, edi                       
  0x00365A91  2b5634                  sub      edx, dword ptr [esi + 0x34]    
  0x00365A94  030e                    add      ecx, dword ptr [esi]           
  0x00365A96  8b7e18                  mov      edi, dword ptr [esi + 0x18]    
  0x00365A99  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x00365A9C  8b4638                  mov      eax, dword ptr [esi + 0x38]    
  0x00365A9F  d1eb                    shr      ebx, 1                         
  0x00365AA1  85c0                    test     eax, eax                       
  0x00365AA3  895e50                  mov      dword ptr [esi + 0x50], ebx    
  0x00365AA6  7448                    je       0x365af0                       
  0x00365AA8  8945f8                  mov      dword ptr [ebp - 8], eax       
                                        ; XREF: 0x00365AEE (cond_jump)
  0x00365AAB  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x00365AAE  894658                  mov      dword ptr [esi + 0x58], eax    
  0x00365AB1  8b4634                  mov      eax, dword ptr [esi + 0x34]    
  0x00365AB4  d1f8                    sar      eax, 1                         
  0x00365AB6  7424                    je       0x365adc                       
  0x00365AB8  8945fc                  mov      dword ptr [ebp - 4], eax       
                                        ; XREF: 0x00365ADA (cond_jump)
  0x00365ABB  8b465c                  mov      eax, dword ptr [esi + 0x5c]    
  0x00365ABE  0b4658                  or       eax, dword ptr [esi + 0x58]    
  0x00365AC1  668b19                  mov      bx, word ptr [ecx]             
  0x00365AC4  66891c47                mov      word ptr [edi + eax*2], bx     
  0x00365AC8  8b464c                  mov      eax, dword ptr [esi + 0x4c]    
  0x00365ACB  8b5e58                  mov      ebx, dword ptr [esi + 0x58]    
  0x00365ACE  41                      inc      ecx                            
  0x00365ACF  2bd8                    sub      ebx, eax                       
  0x00365AD1  23d8                    and      ebx, eax                       
  0x00365AD3  41                      inc      ecx                            
  0x00365AD4  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00365AD7  895e58                  mov      dword ptr [esi + 0x58], ebx    
  0x00365ADA  75df                    jne      0x365abb                       
                                        ; XREF: 0x00365AB6 (cond_jump)
  0x00365ADC  8b4650                  mov      eax, dword ptr [esi + 0x50]    
  0x00365ADF  8b5e5c                  mov      ebx, dword ptr [esi + 0x5c]    
  0x00365AE2  2bd8                    sub      ebx, eax                       
  0x00365AE4  23d8                    and      ebx, eax                       
  0x00365AE6  03ca                    add      ecx, edx                       
  0x00365AE8  ff4df8                  dec      dword ptr [ebp - 8]            
  0x00365AEB  895e5c                  mov      dword ptr [esi + 0x5c], ebx    
  0x00365AEE  75bb                    jne      0x365aab                       
                                        ; XREF: 0x00365AA6 (cond_jump)
  0x00365AF0  8b4664                  mov      eax, dword ptr [esi + 0x64]    
  0x00365AF3  89464c                  mov      dword ptr [esi + 0x4c], eax    
  0x00365AF6  8b4668                  mov      eax, dword ptr [esi + 0x68]    
  0x00365AF9  5f                      pop      edi                            
  0x00365AFA  894650                  mov      dword ptr [esi + 0x50], eax    
  0x00365AFD  5e                      pop      esi                            
  0x00365AFE  5b                      pop      ebx                            
  0x00365AFF  c9                      leave                                   
  0x00365B00  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00365B03
; Start: 0x00365B03  End: 0x00365BCF  Size: 204 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364F1F, sub_00364F48
; Called by: sub_003665CE
; ============================================================
sub_00365B03:
  0x00365B03  55                      push     ebp                            
  0x00365B04  8bec                    mov      ebp, esp                       
  0x00365B06  51                      push     ecx                            
  0x00365B07  51                      push     ecx                            
  0x00365B08  53                      push     ebx                            
  0x00365B09  56                      push     esi                            
  0x00365B0A  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00365B0D  8b462c                  mov      eax, dword ptr [esi + 0x2c]    
  0x00365B10  8b5608                  mov      edx, dword ptr [esi + 8]       
  0x00365B13  8b5e50                  mov      ebx, dword ptr [esi + 0x50]    
  0x00365B16  57                      push     edi                            
  0x00365B17  8b7e4c                  mov      edi, dword ptr [esi + 0x4c]    
  0x00365B1A  03d0                    add      edx, eax                       
  0x00365B1C  8d4e40                  lea      ecx, [esi + 0x40]              
  0x00365B1F  52                      push     edx                            
  0x00365B20  897e64                  mov      dword ptr [esi + 0x64], edi    
  0x00365B23  895e68                  mov      dword ptr [esi + 0x68], ebx    
  0x00365B26  e8f4f3ffff              call     0x364f1f                       ; -> sub_00364F1F
  0x00365B2B  8b4e0c                  mov      ecx, dword ptr [esi + 0xc]     
  0x00365B2E  894508                  mov      dword ptr [ebp + 8], eax       
  0x00365B31  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x00365B34  03c8                    add      ecx, eax                       
  0x00365B36  51                      push     ecx                            
  0x00365B37  8d4e40                  lea      ecx, [esi + 0x40]              
  0x00365B3A  e809f4ffff              call     0x364f48                       ; -> sub_00364F48
  0x00365B3F  8b4e24                  mov      ecx, dword ptr [esi + 0x24]    
  0x00365B42  034e30                  add      ecx, dword ptr [esi + 0x30]    
  0x00365B45  d16d08                  shr      dword ptr [ebp + 8], 1         
  0x00365B48  d1ef                    shr      edi, 1                         
  0x00365B4A  897e4c                  mov      dword ptr [esi + 0x4c], edi    
  0x00365B4D  8b7e04                  mov      edi, dword ptr [esi + 4]       
  0x00365B50  0fafcf                  imul     ecx, edi                       
  0x00365B53  034e28                  add      ecx, dword ptr [esi + 0x28]    
  0x00365B56  d1e8                    shr      eax, 1                         
  0x00365B58  034e18                  add      ecx, dword ptr [esi + 0x18]    
  0x00365B5B  d1eb                    shr      ebx, 1                         
  0x00365B5D  034e2c                  add      ecx, dword ptr [esi + 0x2c]    
  0x00365B60  8bd7                    mov      edx, edi                       
  0x00365B62  2b5634                  sub      edx, dword ptr [esi + 0x34]    
  0x00365B65  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x00365B68  8b4638                  mov      eax, dword ptr [esi + 0x38]    
  0x00365B6B  85c0                    test     eax, eax                       
  0x00365B6D  895e50                  mov      dword ptr [esi + 0x50], ebx    
  0x00365B70  8b1e                    mov      ebx, dword ptr [esi]           
  0x00365B72  7448                    je       0x365bbc                       
  0x00365B74  8945f8                  mov      dword ptr [ebp - 8], eax       
                                        ; XREF: 0x00365BBA (cond_jump)
  0x00365B77  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x00365B7A  894658                  mov      dword ptr [esi + 0x58], eax    
  0x00365B7D  8b4634                  mov      eax, dword ptr [esi + 0x34]    
  0x00365B80  d1f8                    sar      eax, 1                         
  0x00365B82  7424                    je       0x365ba8                       
  0x00365B84  8945fc                  mov      dword ptr [ebp - 4], eax       
                                        ; XREF: 0x00365BA6 (cond_jump)
  0x00365B87  8b465c                  mov      eax, dword ptr [esi + 0x5c]    
  0x00365B8A  0b4658                  or       eax, dword ptr [esi + 0x58]    
  0x00365B8D  668b0443                mov      ax, word ptr [ebx + eax*2]     
  0x00365B91  668901                  mov      word ptr [ecx], ax             
  0x00365B94  8b464c                  mov      eax, dword ptr [esi + 0x4c]    
  0x00365B97  8b7e58                  mov      edi, dword ptr [esi + 0x58]    
  0x00365B9A  41                      inc      ecx                            
  0x00365B9B  2bf8                    sub      edi, eax                       
  0x00365B9D  23f8                    and      edi, eax                       
  0x00365B9F  41                      inc      ecx                            
  0x00365BA0  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00365BA3  897e58                  mov      dword ptr [esi + 0x58], edi    
  0x00365BA6  75df                    jne      0x365b87                       
                                        ; XREF: 0x00365B82 (cond_jump)
  0x00365BA8  8b4650                  mov      eax, dword ptr [esi + 0x50]    
  0x00365BAB  8b7e5c                  mov      edi, dword ptr [esi + 0x5c]    
  0x00365BAE  2bf8                    sub      edi, eax                       
  0x00365BB0  23f8                    and      edi, eax                       
  0x00365BB2  03ca                    add      ecx, edx                       
  0x00365BB4  ff4df8                  dec      dword ptr [ebp - 8]            
  0x00365BB7  897e5c                  mov      dword ptr [esi + 0x5c], edi    
  0x00365BBA  75bb                    jne      0x365b77                       
                                        ; XREF: 0x00365B72 (cond_jump)
  0x00365BBC  8b4664                  mov      eax, dword ptr [esi + 0x64]    
  0x00365BBF  89464c                  mov      dword ptr [esi + 0x4c], eax    
  0x00365BC2  8b4668                  mov      eax, dword ptr [esi + 0x68]    
  0x00365BC5  5f                      pop      edi                            
  0x00365BC6  894650                  mov      dword ptr [esi + 0x50], eax    
  0x00365BC9  5e                      pop      esi                            
  0x00365BCA  5b                      pop      ebx                            
  0x00365BCB  c9                      leave                                   
  0x00365BCC  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00365BCF
; Start: 0x00365BCF  End: 0x00365C4A  Size: 123 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364F1F, sub_00364F48
; Called by: sub_00365E7D
; ============================================================
sub_00365BCF:
  0x00365BCF  55                      push     ebp                            
  0x00365BD0  8bec                    mov      ebp, esp                       
  0x00365BD2  53                      push     ebx                            
  0x00365BD3  56                      push     esi                            
  0x00365BD4  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00365BD7  8b5e2c                  mov      ebx, dword ptr [esi + 0x2c]    
  0x00365BDA  8b4628                  mov      eax, dword ptr [esi + 0x28]    
  0x00365BDD  57                      push     edi                            
  0x00365BDE  03c3                    add      eax, ebx                       
  0x00365BE0  8d7e40                  lea      edi, [esi + 0x40]              
  0x00365BE3  50                      push     eax                            
  0x00365BE4  8bcf                    mov      ecx, edi                       
  0x00365BE6  e834f3ffff              call     0x364f1f                       ; -> sub_00364F1F
  0x00365BEB  8b4e24                  mov      ecx, dword ptr [esi + 0x24]    
  0x00365BEE  894508                  mov      dword ptr [ebp + 8], eax       
  0x00365BF1  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x00365BF4  03c8                    add      ecx, eax                       
  0x00365BF6  51                      push     ecx                            
  0x00365BF7  8bcf                    mov      ecx, edi                       
  0x00365BF9  e84af3ffff              call     0x364f48                       ; -> sub_00364F48
  0x00365BFE  8b4e18                  mov      ecx, dword ptr [esi + 0x18]    
  0x00365C01  8b5638                  mov      edx, dword ptr [esi + 0x38]    
  0x00365C04  83665800                and      dword ptr [esi + 0x58], 0      
  0x00365C08  034d08                  add      ecx, dword ptr [ebp + 8]       
  0x00365C0B  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x00365C0E  8b460c                  mov      eax, dword ptr [esi + 0xc]     
  0x00365C11  034630                  add      eax, dword ptr [esi + 0x30]    
  0x00365C14  0faf4604                imul     eax, dword ptr [esi + 4]       
  0x00365C18  034608                  add      eax, dword ptr [esi + 8]       
  0x00365C1B  03c3                    add      eax, ebx                       
  0x00365C1D  0306                    add      eax, dword ptr [esi]           
  0x00365C1F  85d2                    test     edx, edx                       
  0x00365C21  7420                    je       0x365c43                       
  0x00365C23  895508                  mov      dword ptr [ebp + 8], edx       
                                        ; XREF: 0x00365C41 (cond_jump)
  0x00365C26  8a18                    mov      bl, byte ptr [eax]             
  0x00365C28  8b565c                  mov      edx, dword ptr [esi + 0x5c]    
  0x00365C2B  881c11                  mov      byte ptr [ecx + edx], bl       
  0x00365C2E  8b5710                  mov      edx, dword ptr [edi + 0x10]    
  0x00365C31  8b5f1c                  mov      ebx, dword ptr [edi + 0x1c]    
  0x00365C34  2bda                    sub      ebx, edx                       
  0x00365C36  23da                    and      ebx, edx                       
  0x00365C38  895f1c                  mov      dword ptr [edi + 0x1c], ebx    
  0x00365C3B  034604                  add      eax, dword ptr [esi + 4]       
  0x00365C3E  ff4d08                  dec      dword ptr [ebp + 8]            
  0x00365C41  75e3                    jne      0x365c26                       
                                        ; XREF: 0x00365C21 (cond_jump)
  0x00365C43  5f                      pop      edi                            
  0x00365C44  5e                      pop      esi                            
  0x00365C45  5b                      pop      ebx                            
  0x00365C46  5d                      pop      ebp                            
  0x00365C47  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00365C4A
; Start: 0x00365C4A  End: 0x00365CC5  Size: 123 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364F1F, sub_00364F48
; Called by: sub_003665CE
; ============================================================
sub_00365C4A:
  0x00365C4A  55                      push     ebp                            
  0x00365C4B  8bec                    mov      ebp, esp                       
  0x00365C4D  53                      push     ebx                            
  0x00365C4E  56                      push     esi                            
  0x00365C4F  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00365C52  8b5e2c                  mov      ebx, dword ptr [esi + 0x2c]    
  0x00365C55  8b4608                  mov      eax, dword ptr [esi + 8]       
  0x00365C58  57                      push     edi                            
  0x00365C59  03c3                    add      eax, ebx                       
  0x00365C5B  8d7e40                  lea      edi, [esi + 0x40]              
  0x00365C5E  50                      push     eax                            
  0x00365C5F  8bcf                    mov      ecx, edi                       
  0x00365C61  e8b9f2ffff              call     0x364f1f                       ; -> sub_00364F1F
  0x00365C66  8b4e0c                  mov      ecx, dword ptr [esi + 0xc]     
  0x00365C69  894508                  mov      dword ptr [ebp + 8], eax       
  0x00365C6C  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x00365C6F  03c8                    add      ecx, eax                       
  0x00365C71  51                      push     ecx                            
  0x00365C72  8bcf                    mov      ecx, edi                       
  0x00365C74  e8cff2ffff              call     0x364f48                       ; -> sub_00364F48
  0x00365C79  8b0e                    mov      ecx, dword ptr [esi]           
  0x00365C7B  8b5638                  mov      edx, dword ptr [esi + 0x38]    
  0x00365C7E  83665800                and      dword ptr [esi + 0x58], 0      
  0x00365C82  034d08                  add      ecx, dword ptr [ebp + 8]       
  0x00365C85  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x00365C88  8b4624                  mov      eax, dword ptr [esi + 0x24]    
  0x00365C8B  034630                  add      eax, dword ptr [esi + 0x30]    
  0x00365C8E  0faf4604                imul     eax, dword ptr [esi + 4]       
  0x00365C92  034628                  add      eax, dword ptr [esi + 0x28]    
  0x00365C95  034618                  add      eax, dword ptr [esi + 0x18]    
  0x00365C98  03c3                    add      eax, ebx                       
  0x00365C9A  85d2                    test     edx, edx                       
  0x00365C9C  7420                    je       0x365cbe                       
  0x00365C9E  895508                  mov      dword ptr [ebp + 8], edx       
                                        ; XREF: 0x00365CBC (cond_jump)
  0x00365CA1  8b565c                  mov      edx, dword ptr [esi + 0x5c]    
  0x00365CA4  8a1411                  mov      dl, byte ptr [ecx + edx]       
  0x00365CA7  8810                    mov      byte ptr [eax], dl             
  0x00365CA9  8b5710                  mov      edx, dword ptr [edi + 0x10]    
  0x00365CAC  8b5f1c                  mov      ebx, dword ptr [edi + 0x1c]    
  0x00365CAF  2bda                    sub      ebx, edx                       
  0x00365CB1  23da                    and      ebx, edx                       
  0x00365CB3  895f1c                  mov      dword ptr [edi + 0x1c], ebx    
  0x00365CB6  034604                  add      eax, dword ptr [esi + 4]       
  0x00365CB9  ff4d08                  dec      dword ptr [ebp + 8]            
  0x00365CBC  75e3                    jne      0x365ca1                       
                                        ; XREF: 0x00365C9C (cond_jump)
  0x00365CBE  5f                      pop      edi                            
  0x00365CBF  5e                      pop      esi                            
  0x00365CC0  5b                      pop      ebx                            
  0x00365CC1  5d                      pop      ebp                            
  0x00365CC2  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00365CC5
; Start: 0x00365CC5  End: 0x00365DA1  Size: 220 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364F1F, sub_00364F48
; Called by: sub_00365E7D
; ============================================================
sub_00365CC5:
  0x00365CC5  55                      push     ebp                            
  0x00365CC6  8bec                    mov      ebp, esp                       
  0x00365CC8  51                      push     ecx                            
  0x00365CC9  51                      push     ecx                            
  0x00365CCA  53                      push     ebx                            
  0x00365CCB  56                      push     esi                            
  0x00365CCC  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00365CCF  8b462c                  mov      eax, dword ptr [esi + 0x2c]    
  0x00365CD2  8b5628                  mov      edx, dword ptr [esi + 0x28]    
  0x00365CD5  8b5e50                  mov      ebx, dword ptr [esi + 0x50]    
  0x00365CD8  57                      push     edi                            
  0x00365CD9  8b7e4c                  mov      edi, dword ptr [esi + 0x4c]    
  0x00365CDC  03d0                    add      edx, eax                       
  0x00365CDE  8d4e40                  lea      ecx, [esi + 0x40]              
  0x00365CE1  52                      push     edx                            
  0x00365CE2  897e64                  mov      dword ptr [esi + 0x64], edi    
  0x00365CE5  895e68                  mov      dword ptr [esi + 0x68], ebx    
  0x00365CE8  e832f2ffff              call     0x364f1f                       ; -> sub_00364F1F
  0x00365CED  8b4e24                  mov      ecx, dword ptr [esi + 0x24]    
  0x00365CF0  894508                  mov      dword ptr [ebp + 8], eax       
  0x00365CF3  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x00365CF6  03c8                    add      ecx, eax                       
  0x00365CF8  51                      push     ecx                            
  0x00365CF9  8d4e40                  lea      ecx, [esi + 0x40]              
  0x00365CFC  e847f2ffff              call     0x364f48                       ; -> sub_00364F48
  0x00365D01  8b5634                  mov      edx, dword ptr [esi + 0x34]    
  0x00365D04  8b4e04                  mov      ecx, dword ptr [esi + 4]       
  0x00365D07  d16d08                  shr      dword ptr [ebp + 8], 1         
  0x00365D0A  d1ef                    shr      edi, 1                         
  0x00365D0C  897e4c                  mov      dword ptr [esi + 0x4c], edi    
  0x00365D0F  c1e202                  shl      edx, 2                         
  0x00365D12  8bfa                    mov      edi, edx                       
  0x00365D14  8bd1                    mov      edx, ecx                       
  0x00365D16  2bd7                    sub      edx, edi                       
  0x00365D18  8b7e0c                  mov      edi, dword ptr [esi + 0xc]     
  0x00365D1B  037e30                  add      edi, dword ptr [esi + 0x30]    
  0x00365D1E  d1e8                    shr      eax, 1                         
  0x00365D20  0faff9                  imul     edi, ecx                       
  0x00365D23  8b4e08                  mov      ecx, dword ptr [esi + 8]       
  0x00365D26  034e2c                  add      ecx, dword ptr [esi + 0x2c]    
  0x00365D29  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x00365D2C  8b4638                  mov      eax, dword ptr [esi + 0x38]    
  0x00365D2F  8d0c8f                  lea      ecx, [edi + ecx*4]             
  0x00365D32  030e                    add      ecx, dword ptr [esi]           
  0x00365D34  8b7e18                  mov      edi, dword ptr [esi + 0x18]    
  0x00365D37  d1eb                    shr      ebx, 1                         
  0x00365D39  85c0                    test     eax, eax                       
  0x00365D3B  895e50                  mov      dword ptr [esi + 0x50], ebx    
  0x00365D3E  744e                    je       0x365d8e                       
  0x00365D40  8945f8                  mov      dword ptr [ebp - 8], eax       
                                        ; XREF: 0x00365D8C (cond_jump)
  0x00365D43  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x00365D46  894658                  mov      dword ptr [esi + 0x58], eax    
  0x00365D49  8b4634                  mov      eax, dword ptr [esi + 0x34]    
  0x00365D4C  d1f8                    sar      eax, 1                         
  0x00365D4E  742a                    je       0x365d7a                       
  0x00365D50  8945fc                  mov      dword ptr [ebp - 4], eax       
                                        ; XREF: 0x00365D78 (cond_jump)
  0x00365D53  8b465c                  mov      eax, dword ptr [esi + 0x5c]    
  0x00365D56  0b4658                  or       eax, dword ptr [esi + 0x58]    
  0x00365D59  8b19                    mov      ebx, dword ptr [ecx]           
  0x00365D5B  891cc7                  mov      dword ptr [edi + eax*8], ebx   
  0x00365D5E  8b5904                  mov      ebx, dword ptr [ecx + 4]       
  0x00365D61  895cc704                mov      dword ptr [edi + eax*8 + 4], ebx 
  0x00365D65  8b464c                  mov      eax, dword ptr [esi + 0x4c]    
  0x00365D68  8b5e58                  mov      ebx, dword ptr [esi + 0x58]    
  0x00365D6B  2bd8                    sub      ebx, eax                       
  0x00365D6D  23d8                    and      ebx, eax                       
  0x00365D6F  83c108                  add      ecx, 8                         
  0x00365D72  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00365D75  895e58                  mov      dword ptr [esi + 0x58], ebx    
  0x00365D78  75d9                    jne      0x365d53                       
                                        ; XREF: 0x00365D4E (cond_jump)
  0x00365D7A  8b4650                  mov      eax, dword ptr [esi + 0x50]    
  0x00365D7D  8b5e5c                  mov      ebx, dword ptr [esi + 0x5c]    
  0x00365D80  2bd8                    sub      ebx, eax                       
  0x00365D82  23d8                    and      ebx, eax                       
  0x00365D84  03ca                    add      ecx, edx                       
  0x00365D86  ff4df8                  dec      dword ptr [ebp - 8]            
  0x00365D89  895e5c                  mov      dword ptr [esi + 0x5c], ebx    
  0x00365D8C  75b5                    jne      0x365d43                       
                                        ; XREF: 0x00365D3E (cond_jump)
  0x00365D8E  8b4664                  mov      eax, dword ptr [esi + 0x64]    
  0x00365D91  89464c                  mov      dword ptr [esi + 0x4c], eax    
  0x00365D94  8b4668                  mov      eax, dword ptr [esi + 0x68]    
  0x00365D97  5f                      pop      edi                            
  0x00365D98  894650                  mov      dword ptr [esi + 0x50], eax    
  0x00365D9B  5e                      pop      esi                            
  0x00365D9C  5b                      pop      ebx                            
  0x00365D9D  c9                      leave                                   
  0x00365D9E  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00365DA1
; Start: 0x00365DA1  End: 0x00365E7D  Size: 220 bytes
; Detection: prologue (confidence: 0.95)
; Calls: sub_00364F1F, sub_00364F48
; Called by: sub_003665CE
; ============================================================
sub_00365DA1:
  0x00365DA1  55                      push     ebp                            
  0x00365DA2  8bec                    mov      ebp, esp                       
  0x00365DA4  51                      push     ecx                            
  0x00365DA5  51                      push     ecx                            
  0x00365DA6  53                      push     ebx                            
  0x00365DA7  56                      push     esi                            
  0x00365DA8  8b7508                  mov      esi, dword ptr [ebp + 8]       
  0x00365DAB  8b462c                  mov      eax, dword ptr [esi + 0x2c]    
  0x00365DAE  8b5608                  mov      edx, dword ptr [esi + 8]       
  0x00365DB1  8b5e50                  mov      ebx, dword ptr [esi + 0x50]    
  0x00365DB4  57                      push     edi                            
  0x00365DB5  8b7e4c                  mov      edi, dword ptr [esi + 0x4c]    
  0x00365DB8  03d0                    add      edx, eax                       
  0x00365DBA  8d4e40                  lea      ecx, [esi + 0x40]              
  0x00365DBD  52                      push     edx                            
  0x00365DBE  897e64                  mov      dword ptr [esi + 0x64], edi    
  0x00365DC1  895e68                  mov      dword ptr [esi + 0x68], ebx    
  0x00365DC4  e856f1ffff              call     0x364f1f                       ; -> sub_00364F1F
  0x00365DC9  8b4e0c                  mov      ecx, dword ptr [esi + 0xc]     
  0x00365DCC  894508                  mov      dword ptr [ebp + 8], eax       
  0x00365DCF  8b4630                  mov      eax, dword ptr [esi + 0x30]    
  0x00365DD2  03c8                    add      ecx, eax                       
  0x00365DD4  51                      push     ecx                            
  0x00365DD5  8d4e40                  lea      ecx, [esi + 0x40]              
  0x00365DD8  e86bf1ffff              call     0x364f48                       ; -> sub_00364F48
  0x00365DDD  8b4e04                  mov      ecx, dword ptr [esi + 4]       
  0x00365DE0  8b5634                  mov      edx, dword ptr [esi + 0x34]    
  0x00365DE3  d16d08                  shr      dword ptr [ebp + 8], 1         
  0x00365DE6  d1eb                    shr      ebx, 1                         
  0x00365DE8  895e50                  mov      dword ptr [esi + 0x50], ebx    
  0x00365DEB  8b5e24                  mov      ebx, dword ptr [esi + 0x24]    
  0x00365DEE  035e30                  add      ebx, dword ptr [esi + 0x30]    
  0x00365DF1  d1ef                    shr      edi, 1                         
  0x00365DF3  0fafd9                  imul     ebx, ecx                       
  0x00365DF6  c1e202                  shl      edx, 2                         
  0x00365DF9  897e4c                  mov      dword ptr [esi + 0x4c], edi    
  0x00365DFC  8bfa                    mov      edi, edx                       
  0x00365DFE  8bd1                    mov      edx, ecx                       
  0x00365E00  8b4e28                  mov      ecx, dword ptr [esi + 0x28]    
  0x00365E03  034e2c                  add      ecx, dword ptr [esi + 0x2c]    
  0x00365E06  d1e8                    shr      eax, 1                         
  0x00365E08  8d0c8b                  lea      ecx, [ebx + ecx*4]             
  0x00365E0B  034e18                  add      ecx, dword ptr [esi + 0x18]    
  0x00365E0E  89465c                  mov      dword ptr [esi + 0x5c], eax    
  0x00365E11  8b4638                  mov      eax, dword ptr [esi + 0x38]    
  0x00365E14  2bd7                    sub      edx, edi                       
  0x00365E16  85c0                    test     eax, eax                       
  0x00365E18  8b3e                    mov      edi, dword ptr [esi]           
  0x00365E1A  744e                    je       0x365e6a                       
  0x00365E1C  8945f8                  mov      dword ptr [ebp - 8], eax       
                                        ; XREF: 0x00365E68 (cond_jump)
  0x00365E1F  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x00365E22  894658                  mov      dword ptr [esi + 0x58], eax    
  0x00365E25  8b4634                  mov      eax, dword ptr [esi + 0x34]    
  0x00365E28  d1f8                    sar      eax, 1                         
  0x00365E2A  742a                    je       0x365e56                       
  0x00365E2C  8945fc                  mov      dword ptr [ebp - 4], eax       
                                        ; XREF: 0x00365E54 (cond_jump)
  0x00365E2F  8b465c                  mov      eax, dword ptr [esi + 0x5c]    
  0x00365E32  0b4658                  or       eax, dword ptr [esi + 0x58]    
  0x00365E35  8b1cc7                  mov      ebx, dword ptr [edi + eax*8]   
  0x00365E38  8919                    mov      dword ptr [ecx], ebx           
  0x00365E3A  8b44c704                mov      eax, dword ptr [edi + eax*8 + 4] 
  0x00365E3E  894104                  mov      dword ptr [ecx + 4], eax       
  0x00365E41  8b464c                  mov      eax, dword ptr [esi + 0x4c]    
  0x00365E44  8b5e58                  mov      ebx, dword ptr [esi + 0x58]    
  0x00365E47  2bd8                    sub      ebx, eax                       
  0x00365E49  23d8                    and      ebx, eax                       
  0x00365E4B  83c108                  add      ecx, 8                         
  0x00365E4E  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00365E51  895e58                  mov      dword ptr [esi + 0x58], ebx    
  0x00365E54  75d9                    jne      0x365e2f                       
                                        ; XREF: 0x00365E2A (cond_jump)
  0x00365E56  8b4650                  mov      eax, dword ptr [esi + 0x50]    
  0x00365E59  8b5e5c                  mov      ebx, dword ptr [esi + 0x5c]    
  0x00365E5C  2bd8                    sub      ebx, eax                       
  0x00365E5E  23d8                    and      ebx, eax                       
  0x00365E60  03ca                    add      ecx, edx                       
  0x00365E62  ff4df8                  dec      dword ptr [ebp - 8]            
  0x00365E65  895e5c                  mov      dword ptr [esi + 0x5c], ebx    
  0x00365E68  75b5                    jne      0x365e1f                       
                                        ; XREF: 0x00365E1A (cond_jump)
  0x00365E6A  8b4664                  mov      eax, dword ptr [esi + 0x64]    
  0x00365E6D  89464c                  mov      dword ptr [esi + 0x4c], eax    
  0x00365E70  8b4668                  mov      eax, dword ptr [esi + 0x68]    
  0x00365E73  5f                      pop      edi                            
  0x00365E74  894650                  mov      dword ptr [esi + 0x50], eax    
  0x00365E77  5e                      pop      esi                            
  0x00365E78  5b                      pop      ebx                            
  0x00365E79  c9                      leave                                   
  0x00365E7A  c20400                  ret      4                              
; end of function

; ============================================================
; Function: sub_00365E7D
; Start: 0x00365E7D  End: 0x003665CE  Size: 1873 bytes
; Detection: call_target (confidence: 0.90)
; Calls: sub_00364E9F, sub_00364EBE, sub_00364F1F, sub_00364F48, sub_00364FE5, sub_003650E5, sub_003651E3, 0x00365687, sub_00365789, sub_00365931 ... (+3 more)
; Called by: sub_0035BE6F
; ============================================================
sub_00365E7D:
  0x00365E7D  55                      push     ebp                            
  0x00365E7E  8d6c24a8                lea      ebp, [esp - 0x58]              
  0x00365E82  81ec9c000000            sub      esp, 0x9c                      
  0x00365E88  53                      push     ebx                            
  0x00365E89  56                      push     esi                            
  0x00365E8A  57                      push     edi                            
  0x00365E8B  8b7d70                  mov      edi, dword ptr [ebp + 0x70]    
  0x00365E8E  83ff02                  cmp      edi, 2                         
  0x00365E91  6a10                    push     0x10                           
  0x00365E93  5a                      pop      edx                            
  0x00365E94  6a08                    push     8                              
  0x00365E96  59                      pop      ecx                            
  0x00365E97  6a07                    push     7                              
  0x00365E99  58                      pop      eax                            
  0x00365E9A  6a03                    push     3                              
  0x00365E9C  8945c8                  mov      dword ptr [ebp - 0x38], eax    
  0x00365E9F  8945cc                  mov      dword ptr [ebp - 0x34], eax    
  0x00365EA2  8945d0                  mov      dword ptr [ebp - 0x30], eax    
  0x00365EA5  8945bc                  mov      dword ptr [ebp - 0x44], eax    
  0x00365EA8  8945c0                  mov      dword ptr [ebp - 0x40], eax    
  0x00365EAB  58                      pop      eax                            
  0x00365EAC  8955e0                  mov      dword ptr [ebp - 0x20], edx    
  0x00365EAF  8955e4                  mov      dword ptr [ebp - 0x1c], edx    
  0x00365EB2  894de8                  mov      dword ptr [ebp - 0x18], ecx    
  0x00365EB5  894dd4                  mov      dword ptr [ebp - 0x2c], ecx    
  0x00365EB8  894dd8                  mov      dword ptr [ebp - 0x28], ecx    
  0x00365EBB  894ddc                  mov      dword ptr [ebp - 0x24], ecx    
  0x00365EBE  8945c4                  mov      dword ptr [ebp - 0x3c], eax    
  0x00365EC1  0f86e0060000            jbe      0x3665a7                       
  0x00365EC7  837d7401                cmp      dword ptr [ebp + 0x74], 1      
  0x00365ECB  0f86d6060000            jbe      0x3665a7                       
  0x00365ED1  8b5d68                  mov      ebx, dword ptr [ebp + 0x68]    
  0x00365ED4  85db                    test     ebx, ebx                       
  0x00365ED6  8b757c                  mov      esi, dword ptr [ebp + 0x7c]    
  0x00365ED9  756d                    jne      0x365f48                       
  0x00365EDB  837d7800                cmp      dword ptr [ebp + 0x78], 0      
  0x00365EDF  7567                    jne      0x365f48                       
  0x00365EE1  837d6400                cmp      dword ptr [ebp + 0x64], 0      
  0x00365EE5  7561                    jne      0x365f48                       
  0x00365EE7  83fe04                  cmp      esi, 4                         
  0x00365EEA  751d                    jne      0x365f09                       
  0x00365EEC  3bf9                    cmp      edi, ecx                       
  0x00365EEE  7258                    jb       0x365f48                       
  0x00365EF0  394d74                  cmp      dword ptr [ebp + 0x74], ecx    
  0x00365EF3  7253                    jb       0x365f48                       
  0x00365EF5  ff7574                  push     dword ptr [ebp + 0x74]         
  0x00365EF8  57                      push     edi                            
  0x00365EF9  ff756c                  push     dword ptr [ebp + 0x6c]         
  0x00365EFC  ff7560                  push     dword ptr [ebp + 0x60]         
  0x00365EFF  e8dff2ffff              call     0x3651e3                       ; -> sub_003651E3
  0x00365F04  e9bb060000              jmp      0x3665c4                       
                                        ; XREF: 0x00365EEA (cond_jump)
  0x00365F09  83fe02                  cmp      esi, 2                         
  0x00365F0C  751d                    jne      0x365f2b                       
  0x00365F0E  3bfa                    cmp      edi, edx                       
  0x00365F10  7236                    jb       0x365f48                       
  0x00365F12  394d74                  cmp      dword ptr [ebp + 0x74], ecx    
  0x00365F15  7231                    jb       0x365f48                       
  0x00365F17  ff7574                  push     dword ptr [ebp + 0x74]         
  0x00365F1A  57                      push     edi                            
  0x00365F1B  ff756c                  push     dword ptr [ebp + 0x6c]         
  0x00365F1E  ff7560                  push     dword ptr [ebp + 0x60]         
  0x00365F21  e8bff1ffff              call     0x3650e5                       ; -> sub_003650E5
  0x00365F26  e999060000              jmp      0x3665c4                       
                                        ; XREF: 0x00365F0C (cond_jump)
  0x00365F2B  3bfa                    cmp      edi, edx                       
  0x00365F2D  7219                    jb       0x365f48                       
  0x00365F2F  394d74                  cmp      dword ptr [ebp + 0x74], ecx    
  0x00365F32  7214                    jb       0x365f48                       
  0x00365F34  ff7574                  push     dword ptr [ebp + 0x74]         
  0x00365F37  57                      push     edi                            
  0x00365F38  ff756c                  push     dword ptr [ebp + 0x6c]         
  0x00365F3B  ff7560                  push     dword ptr [ebp + 0x60]         
  0x00365F3E  e8a2f0ffff              call     0x364fe5                       ; -> sub_00364FE5
  0x00365F43  e97c060000              jmp      0x3665c4                       
                                        ; XREF: 0x00365ED9 (cond_jump), 0x00365EDF (cond_jump), 0x00365EE5 (cond_jump), 0x00365EEE (cond_jump), 0x00365EF3 (cond_jump), ... (+4 more)
  0x00365F48  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x00365F4B  e84fefffff              call     0x364e9f                       ; -> sub_00364E9F
  0x00365F50  8b4578                  mov      eax, dword ptr [ebp + 0x78]    
  0x00365F53  85c0                    test     eax, eax                       
  0x00365F55  8b5574                  mov      edx, dword ptr [ebp + 0x74]    
  0x00365F58  897528                  mov      dword ptr [ebp + 0x28], esi    
  0x00365F5B  89550c                  mov      dword ptr [ebp + 0xc], edx     
  0x00365F5E  897d08                  mov      dword ptr [ebp + 8], edi       
  0x00365F61  7508                    jne      0x365f6b                       
  0x00365F63  214514                  and      dword ptr [ebp + 0x14], eax    
  0x00365F66  214510                  and      dword ptr [ebp + 0x10], eax    
  0x00365F69  eb0b                    jmp      0x365f76                       
                                        ; XREF: 0x00365F61 (cond_jump)
  0x00365F6B  8b08                    mov      ecx, dword ptr [eax]           
  0x00365F6D  8b4004                  mov      eax, dword ptr [eax + 4]       
  0x00365F70  894d14                  mov      dword ptr [ebp + 0x14], ecx    
  0x00365F73  894510                  mov      dword ptr [ebp + 0x10], eax    
                                        ; XREF: 0x00365F69 (jump)
  0x00365F76  85db                    test     ebx, ebx                       
  0x00365F78  8b456c                  mov      eax, dword ptr [ebp + 0x6c]    
  0x00365F7B  894504                  mov      dword ptr [ebp + 4], eax       
  0x00365F7E  8b4560                  mov      eax, dword ptr [ebp + 0x60]    
  0x00365F81  8945ec                  mov      dword ptr [ebp - 0x14], eax    
  0x00365F84  750e                    jne      0x365f94                       
  0x00365F86  215df4                  and      dword ptr [ebp - 0xc], ebx     
  0x00365F89  215df8                  and      dword ptr [ebp - 8], ebx       
  0x00365F8C  895500                  mov      dword ptr [ebp], edx           
  0x00365F8F  897dfc                  mov      dword ptr [ebp - 4], edi       
  0x00365F92  eb1b                    jmp      0x365faf                       
                                        ; XREF: 0x00365F84 (cond_jump)
  0x00365F94  8b4304                  mov      eax, dword ptr [ebx + 4]       
  0x00365F97  8b4b0c                  mov      ecx, dword ptr [ebx + 0xc]     
  0x00365F9A  2bc8                    sub      ecx, eax                       
  0x00365F9C  894d00                  mov      dword ptr [ebp], ecx           
  0x00365F9F  8b0b                    mov      ecx, dword ptr [ebx]           
  0x00365FA1  8b5b08                  mov      ebx, dword ptr [ebx + 8]       
  0x00365FA4  2bd9                    sub      ebx, ecx                       
  0x00365FA6  895dfc                  mov      dword ptr [ebp - 4], ebx       
  0x00365FA9  894df4                  mov      dword ptr [ebp - 0xc], ecx     
  0x00365FAC  8945f8                  mov      dword ptr [ebp - 8], eax       
                                        ; XREF: 0x00365F92 (jump)
  0x00365FAF  8b4564                  mov      eax, dword ptr [ebp + 0x64]    
  0x00365FB2  85c0                    test     eax, eax                       
  0x00365FB4  7505                    jne      0x365fbb                       
  0x00365FB6  8bc7                    mov      eax, edi                       
  0x00365FB8  0fafc6                  imul     eax, esi                       
                                        ; XREF: 0x00365FB4 (cond_jump)
  0x00365FBB  6a00                    push     0                              
  0x00365FBD  52                      push     edx                            
  0x00365FBE  57                      push     edi                            
  0x00365FBF  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x00365FC2  8945f0                  mov      dword ptr [ebp - 0x10], eax    
  0x00365FC5  e8f4eeffff              call     0x364ebe                       ; -> sub_00364EBE
  0x00365FCA  8b4538                  mov      eax, dword ptr [ebp + 0x38]    
  0x00365FCD  894550                  mov      dword ptr [ebp + 0x50], eax    
  0x00365FD0  8b453c                  mov      eax, dword ptr [ebp + 0x3c]    
  0x00365FD3  894554                  mov      dword ptr [ebp + 0x54], eax    
  0x00365FD6  8b4500                  mov      eax, dword ptr [ebp]           
  0x00365FD9  33c9                    xor      ecx, ecx                       
  0x00365FDB  3bc1                    cmp      eax, ecx                       
  0x00365FDD  0f84e1050000            je       0x3665c4                       
  0x00365FE3  394dfc                  cmp      dword ptr [ebp - 4], ecx       
  0x00365FE6  0f84d8050000            je       0x3665c4                       
  0x00365FEC  d1ee                    shr      esi, 1                         
  0x00365FEE  c1e602                  shl      esi, 2                         
  0x00365FF1  f6451401                test     byte ptr [ebp + 0x14], 1       
  0x00365FF5  8b5c35c8                mov      ebx, dword ptr [ebp + esi - 0x38] 
  0x00365FF9  8b7c35bc                mov      edi, dword ptr [ebp + esi - 0x44] 
  0x00365FFD  895d74                  mov      dword ptr [ebp + 0x74], ebx    
  0x00366000  7445                    je       0x366047                       
  0x00366002  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00366006  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x00366009  8d45ec                  lea      eax, [ebp - 0x14]              
  0x0036600C  894d18                  mov      dword ptr [ebp + 0x18], ecx    
  0x0036600F  894d1c                  mov      dword ptr [ebp + 0x1c], ecx    
  0x00366012  c7452001000000          mov      dword ptr [ebp + 0x20], 1      
  0x00366019  50                      push     eax                            
  0x0036601A  7507                    jne      0x366023                       
  0x0036601C  e866f6ffff              call     0x365687                       
  0x00366021  eb12                    jmp      0x366035                       
                                        ; XREF: 0x0036601A (cond_jump)
  0x00366023  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00366027  7507                    jne      0x366030                       
  0x00366029  e803f9ffff              call     0x365931                       ; -> sub_00365931
  0x0036602E  eb05                    jmp      0x366035                       
                                        ; XREF: 0x00366027 (cond_jump)
  0x00366030  e89afbffff              call     0x365bcf                       ; -> sub_00365BCF
                                        ; XREF: 0x00366021 (jump), 0x0036602E (jump)
  0x00366035  ff45f4                  inc      dword ptr [ebp - 0xc]          
  0x00366038  ff4514                  inc      dword ptr [ebp + 0x14]         
  0x0036603B  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x0036603E  0f8480050000            je       0x3665c4                       
  0x00366044  8b4500                  mov      eax, dword ptr [ebp]           
                                        ; XREF: 0x00366000 (cond_jump)
  0x00366047  f645fc01                test     byte ptr [ebp - 4], 1          
  0x0036604B  7444                    je       0x366091                       
  0x0036604D  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00366050  8b4dfc                  mov      ecx, dword ptr [ebp - 4]       
  0x00366053  83651c00                and      dword ptr [ebp + 0x1c], 0      
  0x00366057  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x0036605B  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x0036605E  8d45ec                  lea      eax, [ebp - 0x14]              
  0x00366061  894d18                  mov      dword ptr [ebp + 0x18], ecx    
  0x00366064  c7452001000000          mov      dword ptr [ebp + 0x20], 1      
  0x0036606B  50                      push     eax                            
  0x0036606C  7507                    jne      0x366075                       
  0x0036606E  e814f6ffff              call     0x365687                       
  0x00366073  eb12                    jmp      0x366087                       
                                        ; XREF: 0x0036606C (cond_jump)
  0x00366075  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00366079  7507                    jne      0x366082                       
  0x0036607B  e8b1f8ffff              call     0x365931                       ; -> sub_00365931
  0x00366080  eb05                    jmp      0x366087                       
                                        ; XREF: 0x00366079 (cond_jump)
  0x00366082  e848fbffff              call     0x365bcf                       ; -> sub_00365BCF
                                        ; XREF: 0x00366073 (jump), 0x00366080 (jump)
  0x00366087  837dfc00                cmp      dword ptr [ebp - 4], 0         
  0x0036608B  0f8433050000            je       0x3665c4                       
                                        ; XREF: 0x0036604B (cond_jump)
  0x00366091  8b4d14                  mov      ecx, dword ptr [ebp + 0x14]    
  0x00366094  8b55fc                  mov      edx, dword ptr [ebp - 4]       
  0x00366097  8bc3                    mov      eax, ebx                       
  0x00366099  f7d0                    not      eax                            
  0x0036609B  03d9                    add      ebx, ecx                       
  0x0036609D  03d1                    add      edx, ecx                       
  0x0036609F  23d8                    and      ebx, eax                       
  0x003660A1  23d0                    and      edx, eax                       
  0x003660A3  3bda                    cmp      ebx, edx                       
  0x003660A5  0f83c3040000            jae      0x36656e                       
  0x003660AB  8b4d10                  mov      ecx, dword ptr [ebp + 0x10]    
  0x003660AE  8b5d00                  mov      ebx, dword ptr [ebp]           
  0x003660B1  8bc7                    mov      eax, edi                       
  0x003660B3  f7d0                    not      eax                            
  0x003660B5  03d9                    add      ebx, ecx                       
  0x003660B7  8d140f                  lea      edx, [edi + ecx]               
  0x003660BA  23d0                    and      edx, eax                       
  0x003660BC  23d8                    and      ebx, eax                       
  0x003660BE  3bd3                    cmp      edx, ebx                       
  0x003660C0  0f83a8040000            jae      0x36656e                       
  0x003660C6  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x003660C9  3b4435e0                cmp      eax, dword ptr [ebp + esi - 0x20] 
  0x003660CD  0f829b040000            jb       0x36656e                       
  0x003660D3  8b450c                  mov      eax, dword ptr [ebp + 0xc]     
  0x003660D6  3b4435d4                cmp      eax, dword ptr [ebp + esi - 0x2c] 
  0x003660DA  0f828e040000            jb       0x36656e                       
  0x003660E0  33db                    xor      ebx, ebx                       
  0x003660E2  85f9                    test     ecx, edi                       
  0x003660E4  7441                    je       0x366127                       
  0x003660E6  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x003660E9  f7d9                    neg      ecx                            
  0x003660EB  23cf                    and      ecx, edi                       
  0x003660ED  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x003660F1  894520                  mov      dword ptr [ebp + 0x20], eax    
  0x003660F4  8bf1                    mov      esi, ecx                       
  0x003660F6  8d45ec                  lea      eax, [ebp - 0x14]              
  0x003660F9  895d18                  mov      dword ptr [ebp + 0x18], ebx    
  0x003660FC  895d1c                  mov      dword ptr [ebp + 0x1c], ebx    
  0x003660FF  897524                  mov      dword ptr [ebp + 0x24], esi    
  0x00366102  50                      push     eax                            
  0x00366103  7507                    jne      0x36610c                       
  0x00366105  e8bbfbffff              call     0x365cc5                       ; -> sub_00365CC5
  0x0036610A  eb12                    jmp      0x36611e                       
                                        ; XREF: 0x00366103 (cond_jump)
  0x0036610C  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00366110  7507                    jne      0x366119                       
  0x00366112  e872f6ffff              call     0x365789                       ; -> sub_00365789
  0x00366117  eb05                    jmp      0x36611e                       
                                        ; XREF: 0x00366110 (cond_jump)
  0x00366119  e819f9ffff              call     0x365a37                       ; -> sub_00365A37
                                        ; XREF: 0x0036610A (jump), 0x00366117 (jump)
  0x0036611E  0175f8                  add      dword ptr [ebp - 8], esi       
  0x00366121  017510                  add      dword ptr [ebp + 0x10], esi    
  0x00366124  297500                  sub      dword ptr [ebp], esi           
                                        ; XREF: 0x003660E4 (cond_jump)
  0x00366127  8bc7                    mov      eax, edi                       
  0x00366129  234500                  and      eax, dword ptr [ebp]           
  0x0036612C  7438                    je       0x366166                       
  0x0036612E  294500                  sub      dword ptr [ebp], eax           
  0x00366131  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00366135  8b4d00                  mov      ecx, dword ptr [ebp]           
  0x00366138  894d1c                  mov      dword ptr [ebp + 0x1c], ecx    
  0x0036613B  8b4dfc                  mov      ecx, dword ptr [ebp - 4]       
  0x0036613E  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x00366141  8d45ec                  lea      eax, [ebp - 0x14]              
  0x00366144  895d18                  mov      dword ptr [ebp + 0x18], ebx    
  0x00366147  894d20                  mov      dword ptr [ebp + 0x20], ecx    
  0x0036614A  50                      push     eax                            
  0x0036614B  7507                    jne      0x366154                       
  0x0036614D  e873fbffff              call     0x365cc5                       ; -> sub_00365CC5
  0x00366152  eb12                    jmp      0x366166                       
                                        ; XREF: 0x0036614B (cond_jump)
  0x00366154  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00366158  7507                    jne      0x366161                       
  0x0036615A  e82af6ffff              call     0x365789                       ; -> sub_00365789
  0x0036615F  eb05                    jmp      0x366166                       
                                        ; XREF: 0x00366158 (cond_jump)
  0x00366161  e8d1f8ffff              call     0x365a37                       ; -> sub_00365A37
                                        ; XREF: 0x0036612C (cond_jump), 0x00366152 (jump), 0x0036615F (jump)
  0x00366166  8b7514                  mov      esi, dword ptr [ebp + 0x14]    
  0x00366169  857574                  test     dword ptr [ebp + 0x74], esi    
  0x0036616C  7447                    je       0x3661b5                       
  0x0036616E  8b4500                  mov      eax, dword ptr [ebp]           
  0x00366171  f7de                    neg      esi                            
  0x00366173  237574                  and      esi, dword ptr [ebp + 0x74]    
  0x00366176  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x0036617A  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x0036617D  8d45ec                  lea      eax, [ebp - 0x14]              
  0x00366180  895d18                  mov      dword ptr [ebp + 0x18], ebx    
  0x00366183  895d1c                  mov      dword ptr [ebp + 0x1c], ebx    
  0x00366186  897520                  mov      dword ptr [ebp + 0x20], esi    
  0x00366189  50                      push     eax                            
  0x0036618A  7507                    jne      0x366193                       
  0x0036618C  e834fbffff              call     0x365cc5                       ; -> sub_00365CC5
  0x00366191  eb12                    jmp      0x3661a5                       
                                        ; XREF: 0x0036618A (cond_jump)
  0x00366193  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00366197  7507                    jne      0x3661a0                       
  0x00366199  e8ebf5ffff              call     0x365789                       ; -> sub_00365789
  0x0036619E  eb05                    jmp      0x3661a5                       
                                        ; XREF: 0x00366197 (cond_jump)
  0x003661A0  e892f8ffff              call     0x365a37                       ; -> sub_00365A37
                                        ; XREF: 0x00366191 (jump), 0x0036619E (jump)
  0x003661A5  8b7df4                  mov      edi, dword ptr [ebp - 0xc]     
  0x003661A8  017514                  add      dword ptr [ebp + 0x14], esi    
  0x003661AB  03fe                    add      edi, esi                       
  0x003661AD  2975fc                  sub      dword ptr [ebp - 4], esi       
  0x003661B0  897df4                  mov      dword ptr [ebp - 0xc], edi     
  0x003661B3  eb03                    jmp      0x3661b8                       
                                        ; XREF: 0x0036616C (cond_jump)
  0x003661B5  8b7df4                  mov      edi, dword ptr [ebp - 0xc]     
                                        ; XREF: 0x003661B3 (jump)
  0x003661B8  8b4574                  mov      eax, dword ptr [ebp + 0x74]    
  0x003661BB  2345fc                  and      eax, dword ptr [ebp - 4]       
  0x003661BE  743b                    je       0x3661fb                       
  0x003661C0  2945fc                  sub      dword ptr [ebp - 4], eax       
  0x003661C3  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x003661C7  8b4dfc                  mov      ecx, dword ptr [ebp - 4]       
  0x003661CA  894520                  mov      dword ptr [ebp + 0x20], eax    
  0x003661CD  8b4500                  mov      eax, dword ptr [ebp]           
  0x003661D0  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x003661D3  8d45ec                  lea      eax, [ebp - 0x14]              
  0x003661D6  894d18                  mov      dword ptr [ebp + 0x18], ecx    
  0x003661D9  895d1c                  mov      dword ptr [ebp + 0x1c], ebx    
  0x003661DC  50                      push     eax                            
  0x003661DD  7507                    jne      0x3661e6                       
  0x003661DF  e8e1faffff              call     0x365cc5                       ; -> sub_00365CC5
  0x003661E4  eb12                    jmp      0x3661f8                       
                                        ; XREF: 0x003661DD (cond_jump)
  0x003661E6  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x003661EA  7507                    jne      0x3661f3                       
  0x003661EC  e898f5ffff              call     0x365789                       ; -> sub_00365789
  0x003661F1  eb05                    jmp      0x3661f8                       
                                        ; XREF: 0x003661EA (cond_jump)
  0x003661F3  e83ff8ffff              call     0x365a37                       ; -> sub_00365A37
                                        ; XREF: 0x003661E4 (jump), 0x003661F1 (jump)
  0x003661F8  8b7df4                  mov      edi, dword ptr [ebp - 0xc]     
                                        ; XREF: 0x003661BE (cond_jump)
  0x003661FB  8b4538                  mov      eax, dword ptr [ebp + 0x38]    
  0x003661FE  ff7514                  push     dword ptr [ebp + 0x14]         
  0x00366201  83e0c0                  and      eax, 0xffffffc0                
  0x00366204  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00366208  89456c                  mov      dword ptr [ebp + 0x6c], eax    
  0x0036620B  8b453c                  mov      eax, dword ptr [ebp + 0x3c]    
  0x0036620E  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x00366211  0f8523010000            jne      0x36633a                       
  0x00366217  83e0e0                  and      eax, 0xffffffe0                
  0x0036621A  894574                  mov      dword ptr [ebp + 0x74], eax    
  0x0036621D  e8fdecffff              call     0x364f1f                       ; -> sub_00364F1F
  0x00366222  ff7510                  push     dword ptr [ebp + 0x10]         
  0x00366225  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x00366228  894564                  mov      dword ptr [ebp + 0x64], eax    
  0x0036622B  e818edffff              call     0x364f48                       ; -> sub_00364F48
  0x00366230  c16dfc03                shr      dword ptr [ebp - 4], 3         
  0x00366234  894578                  mov      dword ptr [ebp + 0x78], eax    
  0x00366237  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x0036623A  0faf45f8                imul     eax, dword ptr [ebp - 8]       
  0x0036623E  0345ec                  add      eax, dword ptr [ebp - 0x14]    
  0x00366241  c16d0002                shr      dword ptr [ebp], 2             
  0x00366245  8d04b8                  lea      eax, [eax + edi*4]             
  0x00366248  8945ec                  mov      dword ptr [ebp - 0x14], eax    
  0x0036624B  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x0036624E  894560                  mov      dword ptr [ebp + 0x60], eax    
  0x00366251  8b75ec                  mov      esi, dword ptr [ebp - 0x14]    
  0x00366254  8b7d04                  mov      edi, dword ptr [ebp + 4]       
  0x00366257  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x0036625A  c1e202                  shl      edx, 2                         
  0x0036625D  8b5d64                  mov      ebx, dword ptr [ebp + 0x64]    
  0x00366260  8b4d78                  mov      ecx, dword ptr [ebp + 0x78]    
  0x00366263  89757c                  mov      dword ptr [ebp + 0x7c], esi    
  0x00366266  8da42400000000          lea      esp, [esp]                     
                                        ; XREF: 0x0036630B (cond_jump), 0x0036632F (cond_jump)
  0x0036626D  8bc3                    mov      eax, ebx                       
  0x0036626F  0f1006                  movups   xmm0, xmmword ptr [esi]        
  0x00366272  0f106610                movups   xmm4, xmmword ptr [esi + 0x10] 
  0x00366276  0f101416                movups   xmm2, xmmword ptr [esi + edx]  
  0x0036627A  0f10741610              movups   xmm6, xmmword ptr [esi + edx + 0x10] 
  0x0036627F  0f28c8                  movaps   xmm1, xmm0                     
  0x00366282  0f28ec                  movaps   xmm5, xmm4                     
  0x00366285  8d3456                  lea      esi, [esi + edx*2]             
  0x00366288  0bc1                    or       eax, ecx                       
  0x0036628A  0f16c2                  movlhps  xmm0, xmm2                     
  0x0036628D  0f12d1                  movhlps  xmm2, xmm1                     
  0x00366290  0f16e6                  movlhps  xmm4, xmm6                     
  0x00366293  0f12f5                  movhlps  xmm6, xmm5                     
  0x00366296  0f100e                  movups   xmm1, xmmword ptr [esi]        
  0x00366299  0f106e10                movups   xmm5, xmmword ptr [esi + 0x10] 
  0x0036629D  0f101c16                movups   xmm3, xmmword ptr [esi + edx]  
  0x003662A1  0f107c1610              movups   xmm7, xmmword ptr [esi + edx + 0x10] 
  0x003662A6  0f2b0487                movntps  xmmword ptr [edi + eax*4], xmm0 
  0x003662AA  0f2b548710              movntps  xmmword ptr [edi + eax*4 + 0x10], xmm2 
  0x003662AF  0f2b648740              movntps  xmmword ptr [edi + eax*4 + 0x40], xmm4 
  0x003662B4  0f2b748750              movntps  xmmword ptr [edi + eax*4 + 0x50], xmm6 
  0x003662B9  0f28c1                  movaps   xmm0, xmm1                     
  0x003662BC  0f28e5                  movaps   xmm4, xmm5                     
  0x003662BF  0f16cb                  movlhps  xmm1, xmm3                     
  0x003662C2  0f12d8                  movhlps  xmm3, xmm0                     
  0x003662C5  0f16ef                  movlhps  xmm5, xmm7                     
  0x003662C8  0f12fc                  movhlps  xmm7, xmm4                     
  0x003662CB  0f2b4c8720              movntps  xmmword ptr [edi + eax*4 + 0x20], xmm1 
  0x003662D0  0f2b5c8730              movntps  xmmword ptr [edi + eax*4 + 0x30], xmm3 
  0x003662D5  0f2b6c8760              movntps  xmmword ptr [edi + eax*4 + 0x60], xmm5 
  0x003662DA  0f2b7c8770              movntps  xmmword ptr [edi + eax*4 + 0x70], xmm7 
  0x003662DF  2bf2                    sub      esi, edx                       
  0x003662E1  2bf2                    sub      esi, edx                       
  0x003662E3  90                      nop                                     
  0x003662E4  90                      nop                                     
  0x003662E5  90                      nop                                     
  0x003662E6  90                      nop                                     
  0x003662E7  90                      nop                                     
  0x003662E8  90                      nop                                     
  0x003662E9  90                      nop                                     
  0x003662EA  90                      nop                                     
  0x003662EB  90                      nop                                     
  0x003662EC  90                      nop                                     
  0x003662ED  90                      nop                                     
  0x003662EE  90                      nop                                     
  0x003662EF  90                      nop                                     
  0x003662F0  90                      nop                                     
  0x003662F1  90                      nop                                     
  0x003662F2  90                      nop                                     
  0x003662F3  90                      nop                                     
  0x003662F4  90                      nop                                     
  0x003662F5  90                      nop                                     
  0x003662F6  90                      nop                                     
  0x003662F7  90                      nop                                     
  0x003662F8  90                      nop                                     
  0x003662F9  90                      nop                                     
  0x003662FA  90                      nop                                     
  0x003662FB  90                      nop                                     
  0x003662FC  90                      nop                                     
  0x003662FD  90                      nop                                     
  0x003662FE  90                      nop                                     
  0x003662FF  2b5d6c                  sub      ebx, dword ptr [ebp + 0x6c]    
  0x00366302  83c620                  add      esi, 0x20                      
  0x00366305  235d38                  and      ebx, dword ptr [ebp + 0x38]    
  0x00366308  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x0036630B  0f855cffffff            jne      0x36626d                       
  0x00366311  8b7560                  mov      esi, dword ptr [ebp + 0x60]    
  0x00366314  8b5d64                  mov      ebx, dword ptr [ebp + 0x64]    
  0x00366317  8975fc                  mov      dword ptr [ebp - 4], esi       
  0x0036631A  8b757c                  mov      esi, dword ptr [ebp + 0x7c]    
  0x0036631D  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x00366320  2b4d74                  sub      ecx, dword ptr [ebp + 0x74]    
  0x00366323  8d3486                  lea      esi, [esi + eax*4]             
  0x00366326  234d3c                  and      ecx, dword ptr [ebp + 0x3c]    
  0x00366329  89757c                  mov      dword ptr [ebp + 0x7c], esi    
  0x0036632C  ff4d00                  dec      dword ptr [ebp]                
  0x0036632F  0f8538ffffff            jne      0x36626d                       
  0x00366335  e98a020000              jmp      0x3665c4                       
                                        ; XREF: 0x00366211 (cond_jump)
  0x0036633A  83e080                  and      eax, 0xffffff80                
  0x0036633D  894574                  mov      dword ptr [ebp + 0x74], eax    
  0x00366340  e8daebffff              call     0x364f1f                       ; -> sub_00364F1F
  0x00366345  ff7510                  push     dword ptr [ebp + 0x10]         
  0x00366348  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x0036634B  894564                  mov      dword ptr [ebp + 0x64], eax    
  0x0036634E  e8f5ebffff              call     0x364f48                       ; -> sub_00364F48
  0x00366353  c16dfc03                shr      dword ptr [ebp - 4], 3         
  0x00366357  894578                  mov      dword ptr [ebp + 0x78], eax    
  0x0036635A  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x0036635D  0faf45f8                imul     eax, dword ptr [ebp - 8]       
  0x00366361  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00366365  0f8504010000            jne      0x36646f                       
  0x0036636B  0345ec                  add      eax, dword ptr [ebp - 0x14]    
  0x0036636E  c16d0003                shr      dword ptr [ebp], 3             
  0x00366372  8d0478                  lea      eax, [eax + edi*2]             
  0x00366375  8945ec                  mov      dword ptr [ebp - 0x14], eax    
  0x00366378  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x0036637B  894560                  mov      dword ptr [ebp + 0x60], eax    
  0x0036637E  8b75ec                  mov      esi, dword ptr [ebp - 0x14]    
  0x00366381  8b7d04                  mov      edi, dword ptr [ebp + 4]       
  0x00366384  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x00366387  d1e2                    shl      edx, 1                         
  0x00366389  8b5d64                  mov      ebx, dword ptr [ebp + 0x64]    
  0x0036638C  8b4d78                  mov      ecx, dword ptr [ebp + 0x78]    
  0x0036638F  89757c                  mov      dword ptr [ebp + 0x7c], esi    
  0x00366392  eb09                    jmp      0x36639d                       
  0x00366394  8da42400000000          lea      esp, [esp]                     
  0x0036639B  8bff                    mov      edi, edi                       
                                        ; XREF: 0x00366392 (jump), 0x00366440 (cond_jump), 0x00366464 (cond_jump)
  0x0036639D  0f1006                  movups   xmm0, xmmword ptr [esi]        
  0x003663A0  0f100c16                movups   xmm1, xmmword ptr [esi + edx]  
  0x003663A4  03f2                    add      esi, edx                       
  0x003663A6  8bc3                    mov      eax, ebx                       
  0x003663A8  0f102416                movups   xmm4, xmmword ptr [esi + edx]  
  0x003663AC  0f102c56                movups   xmm5, xmmword ptr [esi + edx*2] 
  0x003663B0  0bc1                    or       eax, ecx                       
  0x003663B2  0f28d0                  movaps   xmm2, xmm0                     
  0x003663B5  0f28f4                  movaps   xmm6, xmm4                     
  0x003663B8  0f15f5                  unpckhps xmm6, xmm5                     
  0x003663BB  8d3496                  lea      esi, [esi + edx*4]             
  0x003663BE  0f15d1                  unpckhps xmm2, xmm1                     
  0x003663C1  0f14e5                  unpcklps xmm4, xmm5                     
  0x003663C4  0f101e                  movups   xmm3, xmmword ptr [esi]        
  0x003663C7  0f102c16                movups   xmm5, xmmword ptr [esi + edx]  
  0x003663CB  0f103c56                movups   xmm7, xmmword ptr [esi + edx*2] 
  0x003663CF  2bf2                    sub      esi, edx                       
  0x003663D1  0f14c1                  unpcklps xmm0, xmm1                     
  0x003663D4  0f100e                  movups   xmm1, xmmword ptr [esi]        
  0x003663D7  0f2b0447                movntps  xmmword ptr [edi + eax*2], xmm0 
  0x003663DB  0f2b644710              movntps  xmmword ptr [edi + eax*2 + 0x10], xmm4 
  0x003663E0  0f2b544720              movntps  xmmword ptr [edi + eax*2 + 0x20], xmm2 
  0x003663E5  0f2b744730              movntps  xmmword ptr [edi + eax*2 + 0x30], xmm6 
  0x003663EA  0f28c1                  movaps   xmm0, xmm1                     
  0x003663ED  0f28e5                  movaps   xmm4, xmm5                     
  0x003663F0  0f14c3                  unpcklps xmm0, xmm3                     
  0x003663F3  0f14e7                  unpcklps xmm4, xmm7                     
  0x003663F6  0f15cb                  unpckhps xmm1, xmm3                     
  0x003663F9  0f15ef                  unpckhps xmm5, xmm7                     
  0x003663FC  0f2b444740              movntps  xmmword ptr [edi + eax*2 + 0x40], xmm0 
  0x00366401  0f2b644750              movntps  xmmword ptr [edi + eax*2 + 0x50], xmm4 
  0x00366406  0f2b4c4760              movntps  xmmword ptr [edi + eax*2 + 0x60], xmm1 
  0x0036640B  0f2b6c4770              movntps  xmmword ptr [edi + eax*2 + 0x70], xmm5 
  0x00366410  2bf2                    sub      esi, edx                       
  0x00366412  2bf2                    sub      esi, edx                       
  0x00366414  2bf2                    sub      esi, edx                       
  0x00366416  2bf2                    sub      esi, edx                       
  0x00366418  2b5d6c                  sub      ebx, dword ptr [ebp + 0x6c]    
  0x0036641B  90                      nop                                     
  0x0036641C  90                      nop                                     
  0x0036641D  90                      nop                                     
  0x0036641E  90                      nop                                     
  0x0036641F  90                      nop                                     
  0x00366420  90                      nop                                     
  0x00366421  90                      nop                                     
  0x00366422  90                      nop                                     
  0x00366423  90                      nop                                     
  0x00366424  90                      nop                                     
  0x00366425  90                      nop                                     
  0x00366426  90                      nop                                     
  0x00366427  90                      nop                                     
  0x00366428  90                      nop                                     
  0x00366429  90                      nop                                     
  0x0036642A  90                      nop                                     
  0x0036642B  90                      nop                                     
  0x0036642C  90                      nop                                     
  0x0036642D  90                      nop                                     
  0x0036642E  90                      nop                                     
  0x0036642F  90                      nop                                     
  0x00366430  90                      nop                                     
  0x00366431  90                      nop                                     
  0x00366432  90                      nop                                     
  0x00366433  90                      nop                                     
  0x00366434  90                      nop                                     
  0x00366435  90                      nop                                     
  0x00366436  90                      nop                                     
  0x00366437  83c610                  add      esi, 0x10                      
  0x0036643A  235d38                  and      ebx, dword ptr [ebp + 0x38]    
  0x0036643D  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00366440  0f8557ffffff            jne      0x36639d                       
  0x00366446  8b7560                  mov      esi, dword ptr [ebp + 0x60]    
  0x00366449  8b5d64                  mov      ebx, dword ptr [ebp + 0x64]    
  0x0036644C  8975fc                  mov      dword ptr [ebp - 4], esi       
  0x0036644F  8b757c                  mov      esi, dword ptr [ebp + 0x7c]    
  0x00366452  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x00366455  2b4d74                  sub      ecx, dword ptr [ebp + 0x74]    
  0x00366458  8d34c6                  lea      esi, [esi + eax*8]             
  0x0036645B  234d3c                  and      ecx, dword ptr [ebp + 0x3c]    
  0x0036645E  89757c                  mov      dword ptr [ebp + 0x7c], esi    
  0x00366461  ff4d00                  dec      dword ptr [ebp]                
  0x00366464  0f8533ffffff            jne      0x36639d                       
  0x0036646A  e955010000              jmp      0x3665c4                       
                                        ; XREF: 0x00366365 (cond_jump)
  0x0036646F  0faf7d28                imul     edi, dword ptr [ebp + 0x28]    
  0x00366473  037dec                  add      edi, dword ptr [ebp - 0x14]    
  0x00366476  03f8                    add      edi, eax                       
  0x00366478  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x0036647B  c16d0003                shr      dword ptr [ebp], 3             
  0x0036647F  897dec                  mov      dword ptr [ebp - 0x14], edi    
  0x00366482  894560                  mov      dword ptr [ebp + 0x60], eax    
  0x00366485  8b75ec                  mov      esi, dword ptr [ebp - 0x14]    
  0x00366488  8b7d04                  mov      edi, dword ptr [ebp + 4]       
  0x0036648B  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x0036648E  8b5d64                  mov      ebx, dword ptr [ebp + 0x64]    
  0x00366491  8b4d78                  mov      ecx, dword ptr [ebp + 0x78]    
  0x00366494  89757c                  mov      dword ptr [ebp + 0x7c], esi    
  0x00366497  8d9b00000000            lea      ebx, [ebx]                     
                                        ; XREF: 0x00366540 (cond_jump), 0x00366564 (cond_jump)
  0x0036649D  0f6f06                  movq     mm0, qword ptr [esi]           
  0x003664A0  0f6f0c16                movq     mm1, qword ptr [esi + edx]     
  0x003664A4  03f2                    add      esi, edx                       
  0x003664A6  8bc3                    mov      eax, ebx                       
  0x003664A8  0f6f2416                movq     mm4, qword ptr [esi + edx]     
  0x003664AC  0f6f2c56                movq     mm5, qword ptr [esi + edx*2]   
  0x003664B0  0bc1                    or       eax, ecx                       
  0x003664B2  0f7fc2                  movq     mm2, mm0                       
  0x003664B5  0f7fe6                  movq     mm6, mm4                       
  0x003664B8  0f69f5                  punpckhwd mm6, mm5                       
  0x003664BB  8d3496                  lea      esi, [esi + edx*4]             
  0x003664BE  0f69d1                  punpckhwd mm2, mm1                       
  0x003664C1  0f61e5                  punpcklwd mm4, mm5                       
  0x003664C4  0f6f1e                  movq     mm3, qword ptr [esi]           
  0x003664C7  0f6f2c16                movq     mm5, qword ptr [esi + edx]     
  0x003664CB  0f6f3c56                movq     mm7, qword ptr [esi + edx*2]   
  0x003664CF  2bf2                    sub      esi, edx                       
  0x003664D1  0f61c1                  punpcklwd mm0, mm1                       
  0x003664D4  0f6f0e                  movq     mm1, qword ptr [esi]           
  0x003664D7  0f7f0407                movq     qword ptr [edi + eax], mm0     
  0x003664DB  0f7f640708              movq     qword ptr [edi + eax + 8], mm4 
  0x003664E0  0f7f540710              movq     qword ptr [edi + eax + 0x10], mm2 
  0x003664E5  0f7f740718              movq     qword ptr [edi + eax + 0x18], mm6 
  0x003664EA  0f7fc8                  movq     mm0, mm1                       
  0x003664ED  0f7fec                  movq     mm4, mm5                       
  0x003664F0  0f61c3                  punpcklwd mm0, mm3                       
  0x003664F3  0f61e7                  punpcklwd mm4, mm7                       
  0x003664F6  0f69cb                  punpckhwd mm1, mm3                       
  0x003664F9  0f69ef                  punpckhwd mm5, mm7                       
  0x003664FC  0f7f440720              movq     qword ptr [edi + eax + 0x20], mm0 
  0x00366501  0f7f640728              movq     qword ptr [edi + eax + 0x28], mm4 
  0x00366506  0f7f4c0730              movq     qword ptr [edi + eax + 0x30], mm1 
  0x0036650B  0f7f6c0738              movq     qword ptr [edi + eax + 0x38], mm5 
  0x00366510  2bf2                    sub      esi, edx                       
  0x00366512  2bf2                    sub      esi, edx                       
  0x00366514  2bf2                    sub      esi, edx                       
  0x00366516  2bf2                    sub      esi, edx                       
  0x00366518  2b5d6c                  sub      ebx, dword ptr [ebp + 0x6c]    
  0x0036651B  90                      nop                                     
  0x0036651C  90                      nop                                     
  0x0036651D  90                      nop                                     
  0x0036651E  90                      nop                                     
  0x0036651F  90                      nop                                     
  0x00366520  90                      nop                                     
  0x00366521  90                      nop                                     
  0x00366522  90                      nop                                     
  0x00366523  90                      nop                                     
  0x00366524  90                      nop                                     
  0x00366525  90                      nop                                     
  0x00366526  90                      nop                                     
  0x00366527  90                      nop                                     
  0x00366528  90                      nop                                     
  0x00366529  90                      nop                                     
  0x0036652A  90                      nop                                     
  0x0036652B  90                      nop                                     
  0x0036652C  90                      nop                                     
  0x0036652D  90                      nop                                     
  0x0036652E  90                      nop                                     
  0x0036652F  90                      nop                                     
  0x00366530  90                      nop                                     
  0x00366531  90                      nop                                     
  0x00366532  90                      nop                                     
  0x00366533  90                      nop                                     
  0x00366534  90                      nop                                     
  0x00366535  90                      nop                                     
  0x00366536  90                      nop                                     
  0x00366537  83c608                  add      esi, 8                         
  0x0036653A  235d38                  and      ebx, dword ptr [ebp + 0x38]    
  0x0036653D  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00366540  0f8557ffffff            jne      0x36649d                       
  0x00366546  8b4560                  mov      eax, dword ptr [ebp + 0x60]    
  0x00366549  8b5d64                  mov      ebx, dword ptr [ebp + 0x64]    
  0x0036654C  8945fc                  mov      dword ptr [ebp - 4], eax       
  0x0036654F  8b757c                  mov      esi, dword ptr [ebp + 0x7c]    
  0x00366552  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x00366555  2b4d74                  sub      ecx, dword ptr [ebp + 0x74]    
  0x00366558  8d34c6                  lea      esi, [esi + eax*8]             
  0x0036655B  234d3c                  and      ecx, dword ptr [ebp + 0x3c]    
  0x0036655E  89757c                  mov      dword ptr [ebp + 0x7c], esi    
  0x00366561  ff4d00                  dec      dword ptr [ebp]                
  0x00366564  0f8533ffffff            jne      0x36649d                       
  0x0036656A  0f77                    emms                                    
  0x0036656C  eb56                    jmp      0x3665c4                       
                                        ; XREF: 0x003660A5 (cond_jump), 0x003660C0 (cond_jump), 0x003660CD (cond_jump), 0x003660DA (cond_jump)
  0x0036656E  8b4500                  mov      eax, dword ptr [ebp]           
  0x00366571  83651800                and      dword ptr [ebp + 0x18], 0      
  0x00366575  83651c00                and      dword ptr [ebp + 0x1c], 0      
  0x00366579  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x0036657D  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x00366580  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x00366583  894520                  mov      dword ptr [ebp + 0x20], eax    
  0x00366586  8d45ec                  lea      eax, [ebp - 0x14]              
  0x00366589  50                      push     eax                            
  0x0036658A  7507                    jne      0x366593                       
  0x0036658C  e834f7ffff              call     0x365cc5                       ; -> sub_00365CC5
  0x00366591  eb31                    jmp      0x3665c4                       
                                        ; XREF: 0x0036658A (cond_jump)
  0x00366593  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00366597  7507                    jne      0x3665a0                       
  0x00366599  e8ebf1ffff              call     0x365789                       ; -> sub_00365789
  0x0036659E  eb24                    jmp      0x3665c4                       
                                        ; XREF: 0x00366597 (cond_jump)
  0x003665A0  e892f4ffff              call     0x365a37                       ; -> sub_00365A37
  0x003665A5  eb1d                    jmp      0x3665c4                       
                                        ; XREF: 0x00365EC1 (cond_jump), 0x00365ECB (cond_jump)
  0x003665A7  8b7560                  mov      esi, dword ptr [ebp + 0x60]    
  0x003665AA  8bcf                    mov      ecx, edi                       
  0x003665AC  0faf4d74                imul     ecx, dword ptr [ebp + 0x74]    
  0x003665B0  0faf4d7c                imul     ecx, dword ptr [ebp + 0x7c]    
  0x003665B4  8b7d6c                  mov      edi, dword ptr [ebp + 0x6c]    
  0x003665B7  8bd1                    mov      edx, ecx                       
  0x003665B9  c1e902                  shr      ecx, 2                         
  0x003665BC  f3a5                    rep movsd dword ptr es:[edi], dword ptr [esi] 
  0x003665BE  8bca                    mov      ecx, edx                       
  0x003665C0  23c8                    and      ecx, eax                       
  0x003665C2  f3a4                    rep movsb byte ptr es:[edi], byte ptr [esi] 
                                        ; XREF: 0x00365F04 (jump), 0x00365F26 (jump), 0x00365F43 (jump), 0x00365FDD (cond_jump), 0x00365FE6 (cond_jump), ... (+8 more)
  0x003665C4  5f                      pop      edi                            
  0x003665C5  5e                      pop      esi                            
  0x003665C6  5b                      pop      ebx                            
  0x003665C7  83c558                  add      ebp, 0x58                      
  0x003665CA  c9                      leave                                   
  0x003665CB  c22000                  ret      0x20                           
; end of function

; ============================================================
; Function: sub_003665CE
; Start: 0x003665CE  End: 0x00366CE5  Size: 1815 bytes
; Detection: call_target (confidence: 0.90)
; Calls: sub_00364E9F, sub_00364EBE, sub_00364F1F, sub_00364F48, sub_003652DC, sub_003653BF, sub_003654D1, sub_00365708, sub_0036585D, sub_003659B4 ... (+3 more)
; Called by: sub_0035C079
; ============================================================
sub_003665CE:
  0x003665CE  55                      push     ebp                            
  0x003665CF  8d6c24a8                lea      ebp, [esp - 0x58]              
  0x003665D3  81ec9c000000            sub      esp, 0x9c                      
  0x003665D9  53                      push     ebx                            
  0x003665DA  8b5d64                  mov      ebx, dword ptr [ebp + 0x64]    
  0x003665DD  83fb02                  cmp      ebx, 2                         
  0x003665E0  56                      push     esi                            
  0x003665E1  57                      push     edi                            
  0x003665E2  6a10                    push     0x10                           
  0x003665E4  58                      pop      eax                            
  0x003665E5  6a08                    push     8                              
  0x003665E7  5f                      pop      edi                            
  0x003665E8  6a0f                    push     0xf                            
  0x003665EA  59                      pop      ecx                            
  0x003665EB  6a03                    push     3                              
  0x003665ED  5a                      pop      edx                            
  0x003665EE  8945e0                  mov      dword ptr [ebp - 0x20], eax    
  0x003665F1  8945e4                  mov      dword ptr [ebp - 0x1c], eax    
  0x003665F4  897de8                  mov      dword ptr [ebp - 0x18], edi    
  0x003665F7  8945d4                  mov      dword ptr [ebp - 0x2c], eax    
  0x003665FA  8945d8                  mov      dword ptr [ebp - 0x28], eax    
  0x003665FD  897ddc                  mov      dword ptr [ebp - 0x24], edi    
  0x00366600  894dc8                  mov      dword ptr [ebp - 0x38], ecx    
  0x00366603  894dcc                  mov      dword ptr [ebp - 0x34], ecx    
  0x00366606  c745d007000000          mov      dword ptr [ebp - 0x30], 7      
  0x0036660D  8955bc                  mov      dword ptr [ebp - 0x44], edx    
  0x00366610  8955c0                  mov      dword ptr [ebp - 0x40], edx    
  0x00366613  8955c4                  mov      dword ptr [ebp - 0x3c], edx    
  0x00366616  0f86a2060000            jbe      0x366cbe                       
  0x0036661C  8b4d68                  mov      ecx, dword ptr [ebp + 0x68]    
  0x0036661F  83f901                  cmp      ecx, 1                         
  0x00366622  0f8696060000            jbe      0x366cbe                       
  0x00366628  8b757c                  mov      esi, dword ptr [ebp + 0x7c]    
  0x0036662B  33d2                    xor      edx, edx                       
  0x0036662D  39556c                  cmp      dword ptr [ebp + 0x6c], edx    
  0x00366630  7562                    jne      0x366694                       
  0x00366632  395578                  cmp      dword ptr [ebp + 0x78], edx    
  0x00366635  755d                    jne      0x366694                       
  0x00366637  395574                  cmp      dword ptr [ebp + 0x74], edx    
  0x0036663A  7558                    jne      0x366694                       
  0x0036663C  83fe04                  cmp      esi, 4                         
  0x0036663F  751a                    jne      0x36665b                       
  0x00366641  3bdf                    cmp      ebx, edi                       
  0x00366643  724f                    jb       0x366694                       
  0x00366645  3bcf                    cmp      ecx, edi                       
  0x00366647  724b                    jb       0x366694                       
  0x00366649  51                      push     ecx                            
  0x0036664A  53                      push     ebx                            
  0x0036664B  ff7570                  push     dword ptr [ebp + 0x70]         
  0x0036664E  ff7560                  push     dword ptr [ebp + 0x60]         
  0x00366651  e87beeffff              call     0x3654d1                       ; -> sub_003654D1
  0x00366656  e980060000              jmp      0x366cdb                       
                                        ; XREF: 0x0036663F (cond_jump)
  0x0036665B  83fe02                  cmp      esi, 2                         
  0x0036665E  751a                    jne      0x36667a                       
  0x00366660  3bd8                    cmp      ebx, eax                       
  0x00366662  7230                    jb       0x366694                       
  0x00366664  3bc8                    cmp      ecx, eax                       
  0x00366666  722c                    jb       0x366694                       
  0x00366668  51                      push     ecx                            
  0x00366669  53                      push     ebx                            
  0x0036666A  ff7570                  push     dword ptr [ebp + 0x70]         
  0x0036666D  ff7560                  push     dword ptr [ebp + 0x60]         
  0x00366670  e84aedffff              call     0x3653bf                       ; -> sub_003653BF
  0x00366675  e961060000              jmp      0x366cdb                       
                                        ; XREF: 0x0036665E (cond_jump)
  0x0036667A  3bd8                    cmp      ebx, eax                       
  0x0036667C  7216                    jb       0x366694                       
  0x0036667E  3bc8                    cmp      ecx, eax                       
  0x00366680  7212                    jb       0x366694                       
  0x00366682  51                      push     ecx                            
  0x00366683  53                      push     ebx                            
  0x00366684  ff7570                  push     dword ptr [ebp + 0x70]         
  0x00366687  ff7560                  push     dword ptr [ebp + 0x60]         
  0x0036668A  e84decffff              call     0x3652dc                       ; -> sub_003652DC
  0x0036668F  e947060000              jmp      0x366cdb                       
                                        ; XREF: 0x00366630 (cond_jump), 0x00366635 (cond_jump), 0x0036663A (cond_jump), 0x00366643 (cond_jump), 0x00366647 (cond_jump), ... (+4 more)
  0x00366694  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x00366697  e803e8ffff              call     0x364e9f                       ; -> sub_00364E9F
  0x0036669C  8b4578                  mov      eax, dword ptr [ebp + 0x78]    
  0x0036669F  8b7d68                  mov      edi, dword ptr [ebp + 0x68]    
  0x003666A2  33c9                    xor      ecx, ecx                       
  0x003666A4  3bc1                    cmp      eax, ecx                       
  0x003666A6  897528                  mov      dword ptr [ebp + 0x28], esi    
  0x003666A9  897d0c                  mov      dword ptr [ebp + 0xc], edi     
  0x003666AC  895d08                  mov      dword ptr [ebp + 8], ebx       
  0x003666AF  7508                    jne      0x3666b9                       
  0x003666B1  894d14                  mov      dword ptr [ebp + 0x14], ecx    
  0x003666B4  894d10                  mov      dword ptr [ebp + 0x10], ecx    
  0x003666B7  eb0b                    jmp      0x3666c4                       
                                        ; XREF: 0x003666AF (cond_jump)
  0x003666B9  8b10                    mov      edx, dword ptr [eax]           
  0x003666BB  8b4004                  mov      eax, dword ptr [eax + 4]       
  0x003666BE  895514                  mov      dword ptr [ebp + 0x14], edx    
  0x003666C1  894510                  mov      dword ptr [ebp + 0x10], eax    
                                        ; XREF: 0x003666B7 (jump)
  0x003666C4  8b4570                  mov      eax, dword ptr [ebp + 0x70]    
  0x003666C7  894504                  mov      dword ptr [ebp + 4], eax       
  0x003666CA  8b4560                  mov      eax, dword ptr [ebp + 0x60]    
  0x003666CD  8945ec                  mov      dword ptr [ebp - 0x14], eax    
  0x003666D0  8b456c                  mov      eax, dword ptr [ebp + 0x6c]    
  0x003666D3  3bc1                    cmp      eax, ecx                       
  0x003666D5  750e                    jne      0x3666e5                       
  0x003666D7  897d00                  mov      dword ptr [ebp], edi           
  0x003666DA  895dfc                  mov      dword ptr [ebp - 4], ebx       
  0x003666DD  894df4                  mov      dword ptr [ebp - 0xc], ecx     
  0x003666E0  894df8                  mov      dword ptr [ebp - 8], ecx       
  0x003666E3  eb1d                    jmp      0x366702                       
                                        ; XREF: 0x003666D5 (cond_jump)
  0x003666E5  8b4804                  mov      ecx, dword ptr [eax + 4]       
  0x003666E8  8b500c                  mov      edx, dword ptr [eax + 0xc]     
  0x003666EB  2bd1                    sub      edx, ecx                       
  0x003666ED  895500                  mov      dword ptr [ebp], edx           
  0x003666F0  8b10                    mov      edx, dword ptr [eax]           
  0x003666F2  8b4008                  mov      eax, dword ptr [eax + 8]       
  0x003666F5  2bc2                    sub      eax, edx                       
  0x003666F7  894df8                  mov      dword ptr [ebp - 8], ecx       
  0x003666FA  8945fc                  mov      dword ptr [ebp - 4], eax       
  0x003666FD  8955f4                  mov      dword ptr [ebp - 0xc], edx     
  0x00366700  33c9                    xor      ecx, ecx                       
                                        ; XREF: 0x003666E3 (jump)
  0x00366702  8b4574                  mov      eax, dword ptr [ebp + 0x74]    
  0x00366705  3bc1                    cmp      eax, ecx                       
  0x00366707  7505                    jne      0x36670e                       
  0x00366709  8bc3                    mov      eax, ebx                       
  0x0036670B  0fafc6                  imul     eax, esi                       
                                        ; XREF: 0x00366707 (cond_jump)
  0x0036670E  51                      push     ecx                            
  0x0036670F  57                      push     edi                            
  0x00366710  53                      push     ebx                            
  0x00366711  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x00366714  8945f0                  mov      dword ptr [ebp - 0x10], eax    
  0x00366717  e8a2e7ffff              call     0x364ebe                       ; -> sub_00364EBE
  0x0036671C  8b4538                  mov      eax, dword ptr [ebp + 0x38]    
  0x0036671F  894550                  mov      dword ptr [ebp + 0x50], eax    
  0x00366722  8b453c                  mov      eax, dword ptr [ebp + 0x3c]    
  0x00366725  894554                  mov      dword ptr [ebp + 0x54], eax    
  0x00366728  8b4500                  mov      eax, dword ptr [ebp]           
  0x0036672B  33c9                    xor      ecx, ecx                       
  0x0036672D  3bc1                    cmp      eax, ecx                       
  0x0036672F  0f84a6050000            je       0x366cdb                       
  0x00366735  394dfc                  cmp      dword ptr [ebp - 4], ecx       
  0x00366738  0f849d050000            je       0x366cdb                       
  0x0036673E  d1ee                    shr      esi, 1                         
  0x00366740  c1e602                  shl      esi, 2                         
  0x00366743  f645f401                test     byte ptr [ebp - 0xc], 1        
  0x00366747  8b5c35c8                mov      ebx, dword ptr [ebp + esi - 0x38] 
  0x0036674B  8b7c35bc                mov      edi, dword ptr [ebp + esi - 0x44] 
  0x0036674F  895d60                  mov      dword ptr [ebp + 0x60], ebx    
  0x00366752  7445                    je       0x366799                       
  0x00366754  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00366758  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x0036675B  8d45ec                  lea      eax, [ebp - 0x14]              
  0x0036675E  894d18                  mov      dword ptr [ebp + 0x18], ecx    
  0x00366761  894d1c                  mov      dword ptr [ebp + 0x1c], ecx    
  0x00366764  c7452001000000          mov      dword ptr [ebp + 0x20], 1      
  0x0036676B  50                      push     eax                            
  0x0036676C  7507                    jne      0x366775                       
  0x0036676E  e895efffff              call     0x365708                       ; -> sub_00365708
  0x00366773  eb12                    jmp      0x366787                       
                                        ; XREF: 0x0036676C (cond_jump)
  0x00366775  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00366779  7507                    jne      0x366782                       
  0x0036677B  e834f2ffff              call     0x3659b4                       ; -> sub_003659B4
  0x00366780  eb05                    jmp      0x366787                       
                                        ; XREF: 0x00366779 (cond_jump)
  0x00366782  e8c3f4ffff              call     0x365c4a                       ; -> sub_00365C4A
                                        ; XREF: 0x00366773 (jump), 0x00366780 (jump)
  0x00366787  ff45f4                  inc      dword ptr [ebp - 0xc]          
  0x0036678A  ff4514                  inc      dword ptr [ebp + 0x14]         
  0x0036678D  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00366790  0f8445050000            je       0x366cdb                       
  0x00366796  8b4500                  mov      eax, dword ptr [ebp]           
                                        ; XREF: 0x00366752 (cond_jump)
  0x00366799  f645fc01                test     byte ptr [ebp - 4], 1          
  0x0036679D  7444                    je       0x3667e3                       
  0x0036679F  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x003667A2  8b4dfc                  mov      ecx, dword ptr [ebp - 4]       
  0x003667A5  83651c00                and      dword ptr [ebp + 0x1c], 0      
  0x003667A9  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x003667AD  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x003667B0  8d45ec                  lea      eax, [ebp - 0x14]              
  0x003667B3  894d18                  mov      dword ptr [ebp + 0x18], ecx    
  0x003667B6  c7452001000000          mov      dword ptr [ebp + 0x20], 1      
  0x003667BD  50                      push     eax                            
  0x003667BE  7507                    jne      0x3667c7                       
  0x003667C0  e843efffff              call     0x365708                       ; -> sub_00365708
  0x003667C5  eb12                    jmp      0x3667d9                       
                                        ; XREF: 0x003667BE (cond_jump)
  0x003667C7  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x003667CB  7507                    jne      0x3667d4                       
  0x003667CD  e8e2f1ffff              call     0x3659b4                       ; -> sub_003659B4
  0x003667D2  eb05                    jmp      0x3667d9                       
                                        ; XREF: 0x003667CB (cond_jump)
  0x003667D4  e871f4ffff              call     0x365c4a                       ; -> sub_00365C4A
                                        ; XREF: 0x003667C5 (jump), 0x003667D2 (jump)
  0x003667D9  837dfc00                cmp      dword ptr [ebp - 4], 0         
  0x003667DD  0f84f8040000            je       0x366cdb                       
                                        ; XREF: 0x0036679D (cond_jump)
  0x003667E3  8b4df4                  mov      ecx, dword ptr [ebp - 0xc]     
  0x003667E6  8b55fc                  mov      edx, dword ptr [ebp - 4]       
  0x003667E9  8bc3                    mov      eax, ebx                       
  0x003667EB  03d9                    add      ebx, ecx                       
  0x003667ED  f7d0                    not      eax                            
  0x003667EF  03ca                    add      ecx, edx                       
  0x003667F1  23d8                    and      ebx, eax                       
  0x003667F3  23c8                    and      ecx, eax                       
  0x003667F5  3bd9                    cmp      ebx, ecx                       
  0x003667F7  0f8388040000            jae      0x366c85                       
  0x003667FD  8b4df8                  mov      ecx, dword ptr [ebp - 8]       
  0x00366800  8b5d00                  mov      ebx, dword ptr [ebp]           
  0x00366803  8d140f                  lea      edx, [edi + ecx]               
  0x00366806  8bc7                    mov      eax, edi                       
  0x00366808  f7d0                    not      eax                            
  0x0036680A  03cb                    add      ecx, ebx                       
  0x0036680C  23d0                    and      edx, eax                       
  0x0036680E  23c8                    and      ecx, eax                       
  0x00366810  3bd1                    cmp      edx, ecx                       
  0x00366812  0f836d040000            jae      0x366c85                       
  0x00366818  8b4508                  mov      eax, dword ptr [ebp + 8]       
  0x0036681B  3b4435e0                cmp      eax, dword ptr [ebp + esi - 0x20] 
  0x0036681F  0f8260040000            jb       0x366c85                       
  0x00366825  8b450c                  mov      eax, dword ptr [ebp + 0xc]     
  0x00366828  3b4435d4                cmp      eax, dword ptr [ebp + esi - 0x2c] 
  0x0036682C  0f8253040000            jb       0x366c85                       
  0x00366832  8b75f8                  mov      esi, dword ptr [ebp - 8]       
  0x00366835  33db                    xor      ebx, ebx                       
  0x00366837  85fe                    test     esi, edi                       
  0x00366839  743f                    je       0x36687a                       
  0x0036683B  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x0036683E  f7de                    neg      esi                            
  0x00366840  23f7                    and      esi, edi                       
  0x00366842  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00366846  894520                  mov      dword ptr [ebp + 0x20], eax    
  0x00366849  8d45ec                  lea      eax, [ebp - 0x14]              
  0x0036684C  895d18                  mov      dword ptr [ebp + 0x18], ebx    
  0x0036684F  895d1c                  mov      dword ptr [ebp + 0x1c], ebx    
  0x00366852  897524                  mov      dword ptr [ebp + 0x24], esi    
  0x00366855  50                      push     eax                            
  0x00366856  7507                    jne      0x36685f                       
  0x00366858  e844f5ffff              call     0x365da1                       ; -> sub_00365DA1
  0x0036685D  eb12                    jmp      0x366871                       
                                        ; XREF: 0x00366856 (cond_jump)
  0x0036685F  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00366863  7507                    jne      0x36686c                       
  0x00366865  e8f3efffff              call     0x36585d                       ; -> sub_0036585D
  0x0036686A  eb05                    jmp      0x366871                       
                                        ; XREF: 0x00366863 (cond_jump)
  0x0036686C  e892f2ffff              call     0x365b03                       ; -> sub_00365B03
                                        ; XREF: 0x0036685D (jump), 0x0036686A (jump)
  0x00366871  0175f8                  add      dword ptr [ebp - 8], esi       
  0x00366874  017510                  add      dword ptr [ebp + 0x10], esi    
  0x00366877  297500                  sub      dword ptr [ebp], esi           
                                        ; XREF: 0x00366839 (cond_jump)
  0x0036687A  8bc7                    mov      eax, edi                       
  0x0036687C  234500                  and      eax, dword ptr [ebp]           
  0x0036687F  7438                    je       0x3668b9                       
  0x00366881  294500                  sub      dword ptr [ebp], eax           
  0x00366884  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00366888  8b4d00                  mov      ecx, dword ptr [ebp]           
  0x0036688B  894d1c                  mov      dword ptr [ebp + 0x1c], ecx    
  0x0036688E  8b4dfc                  mov      ecx, dword ptr [ebp - 4]       
  0x00366891  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x00366894  8d45ec                  lea      eax, [ebp - 0x14]              
  0x00366897  895d18                  mov      dword ptr [ebp + 0x18], ebx    
  0x0036689A  894d20                  mov      dword ptr [ebp + 0x20], ecx    
  0x0036689D  50                      push     eax                            
  0x0036689E  7507                    jne      0x3668a7                       
  0x003668A0  e8fcf4ffff              call     0x365da1                       ; -> sub_00365DA1
  0x003668A5  eb12                    jmp      0x3668b9                       
                                        ; XREF: 0x0036689E (cond_jump)
  0x003668A7  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x003668AB  7507                    jne      0x3668b4                       
  0x003668AD  e8abefffff              call     0x36585d                       ; -> sub_0036585D
  0x003668B2  eb05                    jmp      0x3668b9                       
                                        ; XREF: 0x003668AB (cond_jump)
  0x003668B4  e84af2ffff              call     0x365b03                       ; -> sub_00365B03
                                        ; XREF: 0x0036687F (cond_jump), 0x003668A5 (jump), 0x003668B2 (jump)
  0x003668B9  8b75f4                  mov      esi, dword ptr [ebp - 0xc]     
  0x003668BC  857560                  test     dword ptr [ebp + 0x60], esi    
  0x003668BF  7447                    je       0x366908                       
  0x003668C1  8b4500                  mov      eax, dword ptr [ebp]           
  0x003668C4  f7de                    neg      esi                            
  0x003668C6  237560                  and      esi, dword ptr [ebp + 0x60]    
  0x003668C9  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x003668CD  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x003668D0  8d45ec                  lea      eax, [ebp - 0x14]              
  0x003668D3  895d18                  mov      dword ptr [ebp + 0x18], ebx    
  0x003668D6  895d1c                  mov      dword ptr [ebp + 0x1c], ebx    
  0x003668D9  897520                  mov      dword ptr [ebp + 0x20], esi    
  0x003668DC  50                      push     eax                            
  0x003668DD  7507                    jne      0x3668e6                       
  0x003668DF  e8bdf4ffff              call     0x365da1                       ; -> sub_00365DA1
  0x003668E4  eb12                    jmp      0x3668f8                       
                                        ; XREF: 0x003668DD (cond_jump)
  0x003668E6  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x003668EA  7507                    jne      0x3668f3                       
  0x003668EC  e86cefffff              call     0x36585d                       ; -> sub_0036585D
  0x003668F1  eb05                    jmp      0x3668f8                       
                                        ; XREF: 0x003668EA (cond_jump)
  0x003668F3  e80bf2ffff              call     0x365b03                       ; -> sub_00365B03
                                        ; XREF: 0x003668E4 (jump), 0x003668F1 (jump)
  0x003668F8  8b7d14                  mov      edi, dword ptr [ebp + 0x14]    
  0x003668FB  0175f4                  add      dword ptr [ebp - 0xc], esi     
  0x003668FE  03fe                    add      edi, esi                       
  0x00366900  2975fc                  sub      dword ptr [ebp - 4], esi       
  0x00366903  897d14                  mov      dword ptr [ebp + 0x14], edi    
  0x00366906  eb03                    jmp      0x36690b                       
                                        ; XREF: 0x003668BF (cond_jump)
  0x00366908  8b7d14                  mov      edi, dword ptr [ebp + 0x14]    
                                        ; XREF: 0x00366906 (jump)
  0x0036690B  8b4560                  mov      eax, dword ptr [ebp + 0x60]    
  0x0036690E  2345fc                  and      eax, dword ptr [ebp - 4]       
  0x00366911  743b                    je       0x36694e                       
  0x00366913  2945fc                  sub      dword ptr [ebp - 4], eax       
  0x00366916  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x0036691A  8b4dfc                  mov      ecx, dword ptr [ebp - 4]       
  0x0036691D  894520                  mov      dword ptr [ebp + 0x20], eax    
  0x00366920  8b4500                  mov      eax, dword ptr [ebp]           
  0x00366923  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x00366926  8d45ec                  lea      eax, [ebp - 0x14]              
  0x00366929  894d18                  mov      dword ptr [ebp + 0x18], ecx    
  0x0036692C  895d1c                  mov      dword ptr [ebp + 0x1c], ebx    
  0x0036692F  50                      push     eax                            
  0x00366930  7507                    jne      0x366939                       
  0x00366932  e86af4ffff              call     0x365da1                       ; -> sub_00365DA1
  0x00366937  eb12                    jmp      0x36694b                       
                                        ; XREF: 0x00366930 (cond_jump)
  0x00366939  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x0036693D  7507                    jne      0x366946                       
  0x0036693F  e819efffff              call     0x36585d                       ; -> sub_0036585D
  0x00366944  eb05                    jmp      0x36694b                       
                                        ; XREF: 0x0036693D (cond_jump)
  0x00366946  e8b8f1ffff              call     0x365b03                       ; -> sub_00365B03
                                        ; XREF: 0x00366937 (jump), 0x00366944 (jump)
  0x0036694B  8b7d14                  mov      edi, dword ptr [ebp + 0x14]    
                                        ; XREF: 0x00366911 (cond_jump)
  0x0036694E  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00366952  ff75f4                  push     dword ptr [ebp - 0xc]          
  0x00366955  8b4538                  mov      eax, dword ptr [ebp + 0x38]    
  0x00366958  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x0036695B  0f850d010000            jne      0x366a6e                       
  0x00366961  83e0c0                  and      eax, 0xffffffc0                
  0x00366964  894568                  mov      dword ptr [ebp + 0x68], eax    
  0x00366967  8b453c                  mov      eax, dword ptr [ebp + 0x3c]    
  0x0036696A  83e0e0                  and      eax, 0xffffffe0                
  0x0036696D  894560                  mov      dword ptr [ebp + 0x60], eax    
  0x00366970  e8aae5ffff              call     0x364f1f                       ; -> sub_00364F1F
  0x00366975  ff75f8                  push     dword ptr [ebp - 8]            
  0x00366978  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x0036697B  89456c                  mov      dword ptr [ebp + 0x6c], eax    
  0x0036697E  e8c5e5ffff              call     0x364f48                       ; -> sub_00364F48
  0x00366983  c16dfc03                shr      dword ptr [ebp - 4], 3         
  0x00366987  894578                  mov      dword ptr [ebp + 0x78], eax    
  0x0036698A  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x0036698D  0faf4510                imul     eax, dword ptr [ebp + 0x10]    
  0x00366991  034504                  add      eax, dword ptr [ebp + 4]       
  0x00366994  c16d0002                shr      dword ptr [ebp], 2             
  0x00366998  8d04b8                  lea      eax, [eax + edi*4]             
  0x0036699B  894504                  mov      dword ptr [ebp + 4], eax       
  0x0036699E  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x003669A1  894570                  mov      dword ptr [ebp + 0x70], eax    
  0x003669A4  8b75ec                  mov      esi, dword ptr [ebp - 0x14]    
  0x003669A7  8b7d04                  mov      edi, dword ptr [ebp + 4]       
  0x003669AA  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x003669AD  c1e202                  shl      edx, 2                         
  0x003669B0  8b5d6c                  mov      ebx, dword ptr [ebp + 0x6c]    
  0x003669B3  8b4d78                  mov      ecx, dword ptr [ebp + 0x78]    
  0x003669B6  897d74                  mov      dword ptr [ebp + 0x74], edi    
  0x003669B9  eb03                    jmp      0x3669be                       
  0x003669BB  8d4900                  lea      ecx, [ecx]                     
                                        ; XREF: 0x003669B9 (jump), 0x00366A3F (cond_jump), 0x00366A63 (cond_jump)
  0x003669BE  8bc3                    mov      eax, ebx                       
  0x003669C0  0bc1                    or       eax, ecx                       
  0x003669C2  2b5d68                  sub      ebx, dword ptr [ebp + 0x68]    
  0x003669C5  0f280486                movaps   xmm0, xmmword ptr [esi + eax*4] 
  0x003669C9  0f28548610              movaps   xmm2, xmmword ptr [esi + eax*4 + 0x10] 
  0x003669CE  0f28648640              movaps   xmm4, xmmword ptr [esi + eax*4 + 0x40] 
  0x003669D3  0f28748650              movaps   xmm6, xmmword ptr [esi + eax*4 + 0x50] 
  0x003669D8  0f28c8                  movaps   xmm1, xmm0                     
  0x003669DB  0f28ec                  movaps   xmm5, xmm4                     
  0x003669DE  0f16c2                  movlhps  xmm0, xmm2                     
  0x003669E1  0f12d1                  movhlps  xmm2, xmm1                     
  0x003669E4  0f16e6                  movlhps  xmm4, xmm6                     
  0x003669E7  0f12f5                  movhlps  xmm6, xmm5                     
  0x003669EA  0f284c8620              movaps   xmm1, xmmword ptr [esi + eax*4 + 0x20] 
  0x003669EF  0f285c8630              movaps   xmm3, xmmword ptr [esi + eax*4 + 0x30] 
  0x003669F4  0f286c8660              movaps   xmm5, xmmword ptr [esi + eax*4 + 0x60] 
  0x003669F9  0f287c8670              movaps   xmm7, xmmword ptr [esi + eax*4 + 0x70] 
  0x003669FE  0f1107                  movups   xmmword ptr [edi], xmm0        
  0x00366A01  0f116710                movups   xmmword ptr [edi + 0x10], xmm4 
  0x00366A05  0f111417                movups   xmmword ptr [edi + edx], xmm2  
  0x00366A09  0f11741710              movups   xmmword ptr [edi + edx + 0x10], xmm6 
  0x00366A0E  03fa                    add      edi, edx                       
  0x00366A10  0f28c1                  movaps   xmm0, xmm1                     
  0x00366A13  0f28e5                  movaps   xmm4, xmm5                     
  0x00366A16  0f16cb                  movlhps  xmm1, xmm3                     
  0x00366A19  0f12d8                  movhlps  xmm3, xmm0                     
  0x00366A1C  0f16ef                  movlhps  xmm5, xmm7                     
  0x00366A1F  0f12fc                  movhlps  xmm7, xmm4                     
  0x00366A22  0f110c17                movups   xmmword ptr [edi + edx], xmm1  
  0x00366A26  0f116c1710              movups   xmmword ptr [edi + edx + 0x10], xmm5 
  0x00366A2B  0f111c57                movups   xmmword ptr [edi + edx*2], xmm3 
  0x00366A2F  0f117c5710              movups   xmmword ptr [edi + edx*2 + 0x10], xmm7 
  0x00366A34  2bfa                    sub      edi, edx                       
  0x00366A36  83c720                  add      edi, 0x20                      
  0x00366A39  235d38                  and      ebx, dword ptr [ebp + 0x38]    
  0x00366A3C  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00366A3F  0f8579ffffff            jne      0x3669be                       
  0x00366A45  8b4570                  mov      eax, dword ptr [ebp + 0x70]    
  0x00366A48  8b5d6c                  mov      ebx, dword ptr [ebp + 0x6c]    
  0x00366A4B  8945fc                  mov      dword ptr [ebp - 4], eax       
  0x00366A4E  8b7d74                  mov      edi, dword ptr [ebp + 0x74]    
  0x00366A51  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x00366A54  2b4d60                  sub      ecx, dword ptr [ebp + 0x60]    
  0x00366A57  8d3c87                  lea      edi, [edi + eax*4]             
  0x00366A5A  234d3c                  and      ecx, dword ptr [ebp + 0x3c]    
  0x00366A5D  897d74                  mov      dword ptr [ebp + 0x74], edi    
  0x00366A60  ff4d00                  dec      dword ptr [ebp]                
  0x00366A63  0f8555ffffff            jne      0x3669be                       
  0x00366A69  e96d020000              jmp      0x366cdb                       
                                        ; XREF: 0x0036695B (cond_jump)
  0x00366A6E  2500ffffff              and      eax, 0xffffff00                
  0x00366A73  894568                  mov      dword ptr [ebp + 0x68], eax    
  0x00366A76  8b453c                  mov      eax, dword ptr [ebp + 0x3c]    
  0x00366A79  83e0e0                  and      eax, 0xffffffe0                
  0x00366A7C  894560                  mov      dword ptr [ebp + 0x60], eax    
  0x00366A7F  e89be4ffff              call     0x364f1f                       ; -> sub_00364F1F
  0x00366A84  ff75f8                  push     dword ptr [ebp - 8]            
  0x00366A87  8d4d2c                  lea      ecx, [ebp + 0x2c]              
  0x00366A8A  89456c                  mov      dword ptr [ebp + 0x6c], eax    
  0x00366A8D  e8b6e4ffff              call     0x364f48                       ; -> sub_00364F48
  0x00366A92  c16dfc04                shr      dword ptr [ebp - 4], 4         
  0x00366A96  894578                  mov      dword ptr [ebp + 0x78], eax    
  0x00366A99  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x00366A9C  0faf4510                imul     eax, dword ptr [ebp + 0x10]    
  0x00366AA0  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00366AA4  0f85f8000000            jne      0x366ba2                       
  0x00366AAA  034504                  add      eax, dword ptr [ebp + 4]       
  0x00366AAD  c16d0002                shr      dword ptr [ebp], 2             
  0x00366AB1  8d0478                  lea      eax, [eax + edi*2]             
  0x00366AB4  894504                  mov      dword ptr [ebp + 4], eax       
  0x00366AB7  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x00366ABA  894570                  mov      dword ptr [ebp + 0x70], eax    
  0x00366ABD  8b75ec                  mov      esi, dword ptr [ebp - 0x14]    
  0x00366AC0  8b7d04                  mov      edi, dword ptr [ebp + 4]       
  0x00366AC3  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x00366AC6  d1e2                    shl      edx, 1                         
  0x00366AC8  8b5d6c                  mov      ebx, dword ptr [ebp + 0x6c]    
  0x00366ACB  8b4d78                  mov      ecx, dword ptr [ebp + 0x78]    
  0x00366ACE  897d74                  mov      dword ptr [ebp + 0x74], edi    
  0x00366AD1  eb0b                    jmp      0x366ade                       
  0x00366AD3  8da42400000000          lea      esp, [esp]                     
  0x00366ADA  8d642400                lea      esp, [esp]                     
                                        ; XREF: 0x00366AD1 (jump), 0x00366B73 (cond_jump), 0x00366B97 (cond_jump)
  0x00366ADE  8bc3                    mov      eax, ebx                       
  0x00366AE0  2b5d68                  sub      ebx, dword ptr [ebp + 0x68]    
  0x00366AE3  0bc1                    or       eax, ecx                       
  0x00366AE5  0f280446                movaps   xmm0, xmmword ptr [esi + eax*2] 
  0x00366AE9  0f28644620              movaps   xmm4, xmmword ptr [esi + eax*2 + 0x20] 
  0x00366AEE  0f28944680000000        movaps   xmm2, xmmword ptr [esi + eax*2 + 0x80] 
  0x00366AF6  0f28b446a0000000        movaps   xmm6, xmmword ptr [esi + eax*2 + 0xa0] 
  0x00366AFE  0f28c8                  movaps   xmm1, xmm0                     
  0x00366B01  0f28da                  movaps   xmm3, xmm2                     
  0x00366B04  0fc6c488                shufps   xmm0, xmm4, 0x88               
  0x00366B08  0fc6ccdd                shufps   xmm1, xmm4, 0xdd               
  0x00366B0C  0fc6d688                shufps   xmm2, xmm6, 0x88               
  0x00366B10  0fc6dedd                shufps   xmm3, xmm6, 0xdd               
  0x00366B14  0f28644610              movaps   xmm4, xmmword ptr [esi + eax*2 + 0x10] 
  0x00366B19  0f28744630              movaps   xmm6, xmmword ptr [esi + eax*2 + 0x30] 
  0x00366B1E  0f28ac4690000000        movaps   xmm5, xmmword ptr [esi + eax*2 + 0x90] 
  0x00366B26  0f28bc46b0000000        movaps   xmm7, xmmword ptr [esi + eax*2 + 0xb0] 
  0x00366B2E  0f1107                  movups   xmmword ptr [edi], xmm0        
  0x00366B31  0f115710                movups   xmmword ptr [edi + 0x10], xmm2 
  0x00366B35  0f110c17                movups   xmmword ptr [edi + edx], xmm1  
  0x00366B39  0f115c1710              movups   xmmword ptr [edi + edx + 0x10], xmm3 
  0x00366B3E  03fa                    add      edi, edx                       
  0x00366B40  0f28c4                  movaps   xmm0, xmm4                     
  0x00366B43  0f28cd                  movaps   xmm1, xmm5                     
  0x00366B46  0fc6c688                shufps   xmm0, xmm6, 0x88               
  0x00366B4A  0fc6e6dd                shufps   xmm4, xmm6, 0xdd               
  0x00366B4E  0fc6cf88                shufps   xmm1, xmm7, 0x88               
  0x00366B52  0fc6efdd                shufps   xmm5, xmm7, 0xdd               
  0x00366B56  0f110417                movups   xmmword ptr [edi + edx], xmm0  
  0x00366B5A  0f114c1710              movups   xmmword ptr [edi + edx + 0x10], xmm1 
  0x00366B5F  0f112457                movups   xmmword ptr [edi + edx*2], xmm4 
  0x00366B63  0f116c5710              movups   xmmword ptr [edi + edx*2 + 0x10], xmm5 
  0x00366B68  2bfa                    sub      edi, edx                       
  0x00366B6A  83c720                  add      edi, 0x20                      
  0x00366B6D  235d38                  and      ebx, dword ptr [ebp + 0x38]    
  0x00366B70  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00366B73  0f8565ffffff            jne      0x366ade                       
  0x00366B79  8b4570                  mov      eax, dword ptr [ebp + 0x70]    
  0x00366B7C  8b5d6c                  mov      ebx, dword ptr [ebp + 0x6c]    
  0x00366B7F  8945fc                  mov      dword ptr [ebp - 4], eax       
  0x00366B82  8b7d74                  mov      edi, dword ptr [ebp + 0x74]    
  0x00366B85  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x00366B88  2b4d60                  sub      ecx, dword ptr [ebp + 0x60]    
  0x00366B8B  8d3c87                  lea      edi, [edi + eax*4]             
  0x00366B8E  234d3c                  and      ecx, dword ptr [ebp + 0x3c]    
  0x00366B91  897d74                  mov      dword ptr [ebp + 0x74], edi    
  0x00366B94  ff4d00                  dec      dword ptr [ebp]                
  0x00366B97  0f8541ffffff            jne      0x366ade                       
  0x00366B9D  e939010000              jmp      0x366cdb                       
                                        ; XREF: 0x00366AA4 (cond_jump)
  0x00366BA2  0faf7d28                imul     edi, dword ptr [ebp + 0x28]    
  0x00366BA6  037d04                  add      edi, dword ptr [ebp + 4]       
  0x00366BA9  03f8                    add      edi, eax                       
  0x00366BAB  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x00366BAE  c16d0002                shr      dword ptr [ebp], 2             
  0x00366BB2  897d04                  mov      dword ptr [ebp + 4], edi       
  0x00366BB5  894570                  mov      dword ptr [ebp + 0x70], eax    
  0x00366BB8  8b75ec                  mov      esi, dword ptr [ebp - 0x14]    
  0x00366BBB  8b7d04                  mov      edi, dword ptr [ebp + 4]       
  0x00366BBE  8b5508                  mov      edx, dword ptr [ebp + 8]       
  0x00366BC1  8b5d6c                  mov      ebx, dword ptr [ebp + 0x6c]    
  0x00366BC4  8b4d78                  mov      ecx, dword ptr [ebp + 0x78]    
  0x00366BC7  897d74                  mov      dword ptr [ebp + 0x74], edi    
  0x00366BCA  8d642400                lea      esp, [esp]                     
                                        ; XREF: 0x00366C57 (cond_jump), 0x00366C7B (cond_jump)
  0x00366BCE  8bc3                    mov      eax, ebx                       
  0x00366BD0  2b5d68                  sub      ebx, dword ptr [ebp + 0x68]    
  0x00366BD3  0bc1                    or       eax, ecx                       
  0x00366BD5  0f700406d8              pshufw   mm0, qword ptr [esi + eax], 0xd8 
  0x00366BDA  0f70540640d8            pshufw   mm2, qword ptr [esi + eax + 0x40], 0xd8 
  0x00366BE0  0f70640610d8            pshufw   mm4, qword ptr [esi + eax + 0x10], 0xd8 
  0x00366BE6  0f70740650d8            pshufw   mm6, qword ptr [esi + eax + 0x50], 0xd8 
  0x00366BEC  0f7fc1                  movq     mm1, mm0                       
  0x00366BEF  0f7fd3                  movq     mm3, mm2                       
  0x00366BF2  0f62c4                  punpckldq mm0, mm4                       
  0x00366BF5  0f6acc                  punpckhdq mm1, mm4                       
  0x00366BF8  0f62d6                  punpckldq mm2, mm6                       
  0x00366BFB  0f6ade                  punpckhdq mm3, mm6                       
  0x00366BFE  0f7f07                  movq     qword ptr [edi], mm0           
  0x00366C01  0f7f5708                movq     qword ptr [edi + 8], mm2       
  0x00366C05  0f7f0c17                movq     qword ptr [edi + edx], mm1     
  0x00366C09  0f7f5c1708              movq     qword ptr [edi + edx + 8], mm3 
  0x00366C0E  03fa                    add      edi, edx                       
  0x00366C10  0f70640608d8            pshufw   mm4, qword ptr [esi + eax + 8], 0xd8 
  0x00366C16  0f706c0648d8            pshufw   mm5, qword ptr [esi + eax + 0x48], 0xd8 
  0x00366C1C  0f70740618d8            pshufw   mm6, qword ptr [esi + eax + 0x18], 0xd8 
  0x00366C22  0f707c0658d8            pshufw   mm7, qword ptr [esi + eax + 0x58], 0xd8 
  0x00366C28  0f7fe0                  movq     mm0, mm4                       
  0x00366C2B  0f7fe9                  movq     mm1, mm5                       
  0x00366C2E  0f62c6                  punpckldq mm0, mm6                       
  0x00366C31  0f6ae6                  punpckhdq mm4, mm6                       
  0x00366C34  0f62cf                  punpckldq mm1, mm7                       
  0x00366C37  0f6aef                  punpckhdq mm5, mm7                       
  0x00366C3A  0f7f0417                movq     qword ptr [edi + edx], mm0     
  0x00366C3E  0f7f4c1708              movq     qword ptr [edi + edx + 8], mm1 
  0x00366C43  0f7f2457                movq     qword ptr [edi + edx*2], mm4   
  0x00366C47  0f7f6c5708              movq     qword ptr [edi + edx*2 + 8], mm5 
  0x00366C4C  2bfa                    sub      edi, edx                       
  0x00366C4E  83c710                  add      edi, 0x10                      
  0x00366C51  235d38                  and      ebx, dword ptr [ebp + 0x38]    
  0x00366C54  ff4dfc                  dec      dword ptr [ebp - 4]            
  0x00366C57  0f8571ffffff            jne      0x366bce                       
  0x00366C5D  8b4570                  mov      eax, dword ptr [ebp + 0x70]    
  0x00366C60  8b5d6c                  mov      ebx, dword ptr [ebp + 0x6c]    
  0x00366C63  8945fc                  mov      dword ptr [ebp - 4], eax       
  0x00366C66  8b7d74                  mov      edi, dword ptr [ebp + 0x74]    
  0x00366C69  8b45f0                  mov      eax, dword ptr [ebp - 0x10]    
  0x00366C6C  2b4d60                  sub      ecx, dword ptr [ebp + 0x60]    
  0x00366C6F  8d3c87                  lea      edi, [edi + eax*4]             
  0x00366C72  234d3c                  and      ecx, dword ptr [ebp + 0x3c]    
  0x00366C75  897d74                  mov      dword ptr [ebp + 0x74], edi    
  0x00366C78  ff4d00                  dec      dword ptr [ebp]                
  0x00366C7B  0f854dffffff            jne      0x366bce                       
  0x00366C81  0f77                    emms                                    
  0x00366C83  eb56                    jmp      0x366cdb                       
                                        ; XREF: 0x003667F7 (cond_jump), 0x00366812 (cond_jump), 0x0036681F (cond_jump), 0x0036682C (cond_jump)
  0x00366C85  8b4500                  mov      eax, dword ptr [ebp]           
  0x00366C88  83651800                and      dword ptr [ebp + 0x18], 0      
  0x00366C8C  83651c00                and      dword ptr [ebp + 0x1c], 0      
  0x00366C90  837d2804                cmp      dword ptr [ebp + 0x28], 4      
  0x00366C94  894524                  mov      dword ptr [ebp + 0x24], eax    
  0x00366C97  8b45fc                  mov      eax, dword ptr [ebp - 4]       
  0x00366C9A  894520                  mov      dword ptr [ebp + 0x20], eax    
  0x00366C9D  8d45ec                  lea      eax, [ebp - 0x14]              
  0x00366CA0  50                      push     eax                            
  0x00366CA1  7507                    jne      0x366caa                       
  0x00366CA3  e8f9f0ffff              call     0x365da1                       ; -> sub_00365DA1
  0x00366CA8  eb31                    jmp      0x366cdb                       
                                        ; XREF: 0x00366CA1 (cond_jump)
  0x00366CAA  837d2802                cmp      dword ptr [ebp + 0x28], 2      
  0x00366CAE  7507                    jne      0x366cb7                       
  0x00366CB0  e8a8ebffff              call     0x36585d                       ; -> sub_0036585D
  0x00366CB5  eb24                    jmp      0x366cdb                       
                                        ; XREF: 0x00366CAE (cond_jump)
  0x00366CB7  e847eeffff              call     0x365b03                       ; -> sub_00365B03
  0x00366CBC  eb1d                    jmp      0x366cdb                       
                                        ; XREF: 0x00366616 (cond_jump), 0x00366622 (cond_jump)
  0x00366CBE  8b7560                  mov      esi, dword ptr [ebp + 0x60]    
  0x00366CC1  8b7d70                  mov      edi, dword ptr [ebp + 0x70]    
  0x00366CC4  8bcb                    mov      ecx, ebx                       
  0x00366CC6  0faf4d68                imul     ecx, dword ptr [ebp + 0x68]    
  0x00366CCA  0faf4d7c                imul     ecx, dword ptr [ebp + 0x7c]    
  0x00366CCE  8bc1                    mov      eax, ecx                       
  0x00366CD0  c1e902                  shr      ecx, 2                         
  0x00366CD3  f3a5                    rep movsd dword ptr es:[edi], dword ptr [esi] 
  0x00366CD5  8bc8                    mov      ecx, eax                       
  0x00366CD7  23ca                    and      ecx, edx                       
  0x00366CD9  f3a4                    rep movsb byte ptr es:[edi], byte ptr [esi] 
                                        ; XREF: 0x00366656 (jump), 0x00366675 (jump), 0x0036668F (jump), 0x0036672F (cond_jump), 0x00366738 (cond_jump), ... (+8 more)
  0x00366CDB  5f                      pop      edi                            
  0x00366CDC  5e                      pop      esi                            
  0x00366CDD  5b                      pop      ebx                            
  0x00366CDE  83c558                  add      ebp, 0x58                      
  0x00366CE1  c9                      leave                                   
  0x00366CE2  c22000                  ret      0x20                           
; end of function
  0x00366CE5  cc                      int3                                    
  0x00366CE6  cc                      int3                                    
  0x00366CE7  cc                      int3                                    

; ============================================================
; Function: sub_00366CE8
; Start: 0x00366CE8  End: 0x00366D2C  Size: 68 bytes
; Detection: cc_boundary (confidence: 0.85)
; ============================================================
sub_00366CE8:
  0x00366CE8  0909                    or       dword ptr [ecx], ecx           
  0x00366CEA  11911191a1a1            adc      dword ptr [ecx - 0x5e5e6eef], edx 
  0x00366CF0  0000                    add      byte ptr [eax], al             
  0x00366CF2  0009                    add      byte ptr [ecx], cl             
  0x00366CF4  0400                    add      al, 0                          
  0x00366CF6  0808                    or       byte ptr [eax], cl             
  0x00366CF8  1292a20a0000            adc      dl, byte ptr [edx + 0xaa2]     
  0x00366CFE  1212                    adc      dl, byte ptr [edx]             
  0x00366D00  0009                    add      byte ptr [ecx], cl             
  0x00366D02  110a                    adc      dword ptr [edx], ecx           
  0x00366D04  92                      xchg     edx, eax                       
  0x00366D05  12a20a120000            adc      ah, byte ptr [edx + 0x120a]    
  0x00366D0B  0010                    add      byte ptr [eax], dl             
  0x00366D0D  1000                    adc      byte ptr [eax], al             
  0x00366D0F  1111                    adc      dword ptr [ecx], edx           
  0x00366D11  116161                  adc      dword ptr [ecx + 0x61], esp    
  0x00366D14  51                      push     ecx                            
  0x00366D15  51                      push     ecx                            
  0x00366D16  626252                  bound    esp, qword ptr [edx + 0x52]    
  0x00366D19  52                      push     edx                            
  0x00366D1A  1121                    adc      dword ptr [ecx], esp           
  0x00366D1C  0012                    add      byte ptr [edx], dl             
  0x00366D1E  0012                    add      byte ptr [edx], dl             
  0x00366D20  1111                    adc      dword ptr [ecx], edx           
  0x00366D22  2121                    and      dword ptr [ecx], esp           
  0x00366D24  2112                    and      dword ptr [edx], edx           
  0x00366D26  1222                    adc      ah, byte ptr [edx]             
  0x00366D28  2222                    and      ah, byte ptr [edx]             
  0x00366D2A  0000                    add      byte ptr [eax], al             
; end of function
