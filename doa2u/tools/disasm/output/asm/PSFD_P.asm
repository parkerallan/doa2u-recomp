; ============================================================
; Section: PSFD_P
; VA: 0x003B65C0 - 0x003B6C00
; Size: 1600 bytes (1.6 KB)
; Functions: 0
; Instructions: 546
; ============================================================

  0x003B65C0  83ec18                  sub      esp, 0x18                      
  0x003B65C3  8b442420                mov      eax, dword ptr [esp + 0x20]    
  0x003B65C7  8b08                    mov      ecx, dword ptr [eax]           
  0x003B65C9  53                      push     ebx                            
  0x003B65CA  55                      push     ebp                            
  0x003B65CB  8b6c2424                mov      ebp, dword ptr [esp + 0x24]    
  0x003B65CF  56                      push     esi                            
  0x003B65D0  57                      push     edi                            
  0x003B65D1  8db508130000            lea      esi, [ebp + 0x1308]            
  0x003B65D7  56                      push     esi                            
  0x003B65D8  68ffffff7f              push     0x7fffffff                     
  0x003B65DD  6a01                    push     1                              
  0x003B65DF  50                      push     eax                            
  0x003B65E0  c744242801000000        mov      dword ptr [esp + 0x28], 1      
  0x003B65E8  89742424                mov      dword ptr [esp + 0x24], esi    
  0x003B65EC  ff5118                  call     dword ptr [ecx + 0x18]         
  0x003B65EF  8b3e                    mov      edi, dword ptr [esi]           
  0x003B65F1  8bf7                    mov      esi, edi                       
  0x003B65F3  83e6fc                  and      esi, 0xfffffffc                
  0x003B65F6  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B65F9  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B65FD  c1e008                  shl      eax, 8                         
  0x003B6600  0bc2                    or       eax, edx                       
  0x003B6602  2bfe                    sub      edi, esi                       
  0x003B6604  c1e703                  shl      edi, 3                         
  0x003B6607  83c410                  add      esp, 0x10                      
  0x003B660A  46                      inc      esi                            
  0x003B660B  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B660F  c1e008                  shl      eax, 8                         
  0x003B6612  0bc1                    or       eax, ecx                       
  0x003B6614  46                      inc      esi                            
  0x003B6615  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B6619  c1e008                  shl      eax, 8                         
  0x003B661C  0bc2                    or       eax, edx                       
  0x003B661E  46                      inc      esi                            
  0x003B661F  8bd8                    mov      ebx, eax                       
  0x003B6621  0fbe4601                movsx    eax, byte ptr [esi + 1]        
  0x003B6625  46                      inc      esi                            
  0x003B6626  8bcf                    mov      ecx, edi                       
  0x003B6628  d3e3                    shl      ebx, cl                        
  0x003B662A  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B662E  46                      inc      esi                            
  0x003B662F  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B6633  c1e008                  shl      eax, 8                         
  0x003B6636  0bc1                    or       eax, ecx                       
  0x003B6638  46                      inc      esi                            
  0x003B6639  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B663D  c1e008                  shl      eax, 8                         
  0x003B6640  0bc2                    or       eax, edx                       
  0x003B6642  46                      inc      esi                            
  0x003B6643  c1e008                  shl      eax, 8                         
  0x003B6646  0bc1                    or       eax, ecx                       
  0x003B6648  8b8d10130000            mov      ecx, dword ptr [ebp + 0x1310]  
  0x003B664E  03f9                    add      edi, ecx                       
  0x003B6650  8bd0                    mov      edx, eax                       
  0x003B6652  46                      inc      esi                            
  0x003B6653  83ff20                  cmp      edi, 0x20                      
  0x003B6656  8954242c                mov      dword ptr [esp + 0x2c], edx    
  0x003B665A  7c33                    jl       0x3b668f                       
  0x003B665C  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B665F  83ef20                  sub      edi, 0x20                      
  0x003B6662  8bda                    mov      ebx, edx                       
  0x003B6664  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B6668  8bcf                    mov      ecx, edi                       
  0x003B666A  d3e3                    shl      ebx, cl                        
  0x003B666C  46                      inc      esi                            
  0x003B666D  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B6671  c1e008                  shl      eax, 8                         
  0x003B6674  0bc2                    or       eax, edx                       
  0x003B6676  46                      inc      esi                            
  0x003B6677  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B667B  c1e008                  shl      eax, 8                         
  0x003B667E  0bc1                    or       eax, ecx                       
  0x003B6680  46                      inc      esi                            
  0x003B6681  c1e008                  shl      eax, 8                         
  0x003B6684  0bc2                    or       eax, edx                       
  0x003B6686  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003B668A  46                      inc      esi                            
  0x003B668B  8bd0                    mov      edx, eax                       
  0x003B668D  eb02                    jmp      0x3b6691                       
                                        ; XREF: 0x003B665A (cond_jump)
  0x003B668F  d3e3                    shl      ebx, cl                        
                                        ; XREF: 0x003B668D (jump), 0x003B6B9D (jump), 0x003B6BB0 (jump)
  0x003B6691  8bc3                    mov      eax, ebx                       
  0x003B6693  c1e809                  shr      eax, 9                         
  0x003B6696  83ff09                  cmp      edi, 9                         
  0x003B6699  89442410                mov      dword ptr [esp + 0x10], eax    
  0x003B669D  7e13                    jle      0x3b66b2                       
  0x003B669F  b929000000              mov      ecx, 0x29                      
  0x003B66A4  2bcf                    sub      ecx, edi                       
  0x003B66A6  8bc2                    mov      eax, edx                       
  0x003B66A8  d3e8                    shr      eax, cl                        
  0x003B66AA  8bc8                    mov      ecx, eax                       
  0x003B66AC  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003B66B0  0bc1                    or       eax, ecx                       
                                        ; XREF: 0x003B669D (cond_jump)
  0x003B66B2  85c0                    test     eax, eax                       
  0x003B66B4  0f84fb040000            je       0x3b6bb5                       
  0x003B66BA  8b8534030000            mov      eax, dword ptr [ebp + 0x334]   
  0x003B66C0  8944241c                mov      dword ptr [esp + 0x1c], eax    
                                        ; XREF: 0x003B6758 (cond_jump), 0x003B676A (jump)
  0x003B66C4  8bc3                    mov      eax, ebx                       
  0x003B66C6  c1e815                  shr      eax, 0x15                      
  0x003B66C9  83ff15                  cmp      edi, 0x15                      
  0x003B66CC  7e0f                    jle      0x3b66dd                       
  0x003B66CE  b935000000              mov      ecx, 0x35                      
  0x003B66D3  2bcf                    sub      ecx, edi                       
  0x003B66D5  d3ea                    shr      edx, cl                        
  0x003B66D7  0bc2                    or       eax, edx                       
  0x003B66D9  8b54242c                mov      edx, dword ptr [esp + 0x2c]    
                                        ; XREF: 0x003B66CC (cond_jump)
  0x003B66DD  a980ffffff              test     eax, 0xffffff80                
  0x003B66E2  7510                    jne      0x3b66f4                       
  0x003B66E4  8b0dc45df600            mov      ecx, dword ptr [0xf65dc4]      
  0x003B66EA  0fbf0441                movsx    eax, word ptr [ecx + eax*2]    
  0x003B66EE  89442410                mov      dword ptr [esp + 0x10], eax    
  0x003B66F2  eb11                    jmp      0x3b6705                       
                                        ; XREF: 0x003B66E2 (cond_jump)
  0x003B66F4  8b0dc05df600            mov      ecx, dword ptr [0xf65dc0]      
  0x003B66FA  c1e806                  shr      eax, 6                         
  0x003B66FD  0fbf0441                movsx    eax, word ptr [ecx + eax*2]    
  0x003B6701  89442410                mov      dword ptr [esp + 0x10], eax    
                                        ; XREF: 0x003B66F2 (jump)
  0x003B6705  8bc8                    mov      ecx, eax                       
  0x003B6707  83e10f                  and      ecx, 0xf                       
  0x003B670A  03f9                    add      edi, ecx                       
  0x003B670C  83ff20                  cmp      edi, 0x20                      
  0x003B670F  7c37                    jl       0x3b6748                       
  0x003B6711  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B6714  83ef20                  sub      edi, 0x20                      
  0x003B6717  8bda                    mov      ebx, edx                       
  0x003B6719  8bcf                    mov      ecx, edi                       
  0x003B671B  d3e3                    shl      ebx, cl                        
  0x003B671D  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B6721  c1e008                  shl      eax, 8                         
  0x003B6724  46                      inc      esi                            
  0x003B6725  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B6729  0bc1                    or       eax, ecx                       
  0x003B672B  46                      inc      esi                            
  0x003B672C  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B6730  c1e008                  shl      eax, 8                         
  0x003B6733  0bc2                    or       eax, edx                       
  0x003B6735  46                      inc      esi                            
  0x003B6736  c1e008                  shl      eax, 8                         
  0x003B6739  0bc1                    or       eax, ecx                       
  0x003B673B  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003B673F  8bd0                    mov      edx, eax                       
  0x003B6741  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003B6745  46                      inc      esi                            
  0x003B6746  eb02                    jmp      0x3b674a                       
                                        ; XREF: 0x003B670F (cond_jump)
  0x003B6748  d3e3                    shl      ebx, cl                        
                                        ; XREF: 0x003B6746 (jump)
  0x003B674A  8bc8                    mov      ecx, eax                       
  0x003B674C  c1e902                  shr      ecx, 2                         
  0x003B674F  0fb6c9                  movzx    ecx, cl                        
  0x003B6752  c1e902                  shr      ecx, 2                         
  0x003B6755  83f922                  cmp      ecx, 0x22                      
  0x003B6758  0f8466ffffff            je       0x3b66c4                       
  0x003B675E  83f923                  cmp      ecx, 0x23                      
  0x003B6761  750c                    jne      0x3b676f                       
  0x003B6763  83853403000021          add      dword ptr [ebp + 0x334], 0x21  
  0x003B676A  e955ffffff              jmp      0x3b66c4                       
                                        ; XREF: 0x003B6761 (cond_jump)
  0x003B676F  83f924                  cmp      ecx, 0x24                      
  0x003B6772  0f843d040000            je       0x3b6bb5                       
  0x003B6778  018d34030000            add      dword ptr [ebp + 0x334], ecx   
  0x003B677E  8b8d34030000            mov      ecx, dword ptr [ebp + 0x334]   
  0x003B6784  c1e80a                  shr      eax, 0xa                       
  0x003B6787  898544030000            mov      dword ptr [ebp + 0x344], eax   
  0x003B678D  3b8d40030000            cmp      ecx, dword ptr [ebp + 0x340]   
  0x003B6793  0f8f1c040000            jg       0x3b6bb5                       
  0x003B6799  2b4c241c                sub      ecx, dword ptr [esp + 0x1c]    
  0x003B679D  8b853c030000            mov      eax, dword ptr [ebp + 0x33c]   
  0x003B67A3  03c1                    add      eax, ecx                       
  0x003B67A5  894c2410                mov      dword ptr [esp + 0x10], ecx    
  0x003B67A9  8bc8                    mov      ecx, eax                       
  0x003B67AB  89853c030000            mov      dword ptr [ebp + 0x33c], eax   
  0x003B67B1  8b85d8010000            mov      eax, dword ptr [ebp + 0x1d8]   
  0x003B67B7  3bc8                    cmp      ecx, eax                       
  0x003B67B9  7c1f                    jl       0x3b67da                       
  0x003B67BB  eb03                    jmp      0x3b67c0                       
  0x003B67BD  8d4900                  lea      ecx, [ecx]                     
                                        ; XREF: 0x003B67BB (jump), 0x003B67D8 (cond_jump)
  0x003B67C0  29853c030000            sub      dword ptr [ebp + 0x33c], eax   
  0x003B67C6  ff8538030000            inc      dword ptr [ebp + 0x338]        
  0x003B67CC  8b8d3c030000            mov      ecx, dword ptr [ebp + 0x33c]   
  0x003B67D2  3b8dd8010000            cmp      ecx, dword ptr [ebp + 0x1d8]   
  0x003B67D8  7de6                    jge      0x3b67c0                       
                                        ; XREF: 0x003B67B9 (cond_jump)
  0x003B67DA  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003B67DE  83f8fe                  cmp      eax, -2                        
  0x003B67E1  0f84ce030000            je       0x3b6bb5                       
  0x003B67E7  8b4c2418                mov      ecx, dword ptr [esp + 0x18]    
  0x003B67EB  85c9                    test     ecx, ecx                       
  0x003B67ED  7526                    jne      0x3b6815                       
  0x003B67EF  83f801                  cmp      eax, 1                         
  0x003B67F2  7621                    jbe      0x3b6815                       
  0x003B67F4  50                      push     eax                            
  0x003B67F5  55                      push     ebp                            
  0x003B67F6  ff95c4020000            call     dword ptr [ebp + 0x2c4]        
  0x003B67FC  8d95ec020000            lea      edx, [ebp + 0x2ec]             
  0x003B6802  52                      push     edx                            
  0x003B6803  e8d8f4ffff              call     0x3b5ce0                       ; -> sub_003B5CE0
  0x003B6808  55                      push     ebp                            
  0x003B6809  e8f2f4ffff              call     0x3b5d00                       ; -> sub_003B5D00
  0x003B680E  8b54243c                mov      edx, dword ptr [esp + 0x3c]    
  0x003B6812  83c410                  add      esp, 0x10                      
                                        ; XREF: 0x003B67ED (cond_jump), 0x003B67F2 (cond_jump)
  0x003B6815  f6854403000020          test     byte ptr [ebp + 0x344], 0x20   
  0x003B681C  7575                    jne      0x3b6893                       
  0x003B681E  8bc3                    mov      eax, ebx                       
  0x003B6820  c1e81b                  shr      eax, 0x1b                      
  0x003B6823  83ff1b                  cmp      edi, 0x1b                      
  0x003B6826  89442410                mov      dword ptr [esp + 0x10], eax    
  0x003B682A  7e13                    jle      0x3b683f                       
  0x003B682C  b93b000000              mov      ecx, 0x3b                      
  0x003B6831  2bcf                    sub      ecx, edi                       
  0x003B6833  8bc2                    mov      eax, edx                       
  0x003B6835  d3e8                    shr      eax, cl                        
  0x003B6837  8bc8                    mov      ecx, eax                       
  0x003B6839  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003B683D  0bc1                    or       eax, ecx                       
                                        ; XREF: 0x003B682A (cond_jump)
  0x003B683F  8b0dac5df600            mov      ecx, dword ptr [0xf65dac]      
  0x003B6845  0fbf0441                movsx    eax, word ptr [ecx + eax*2]    
  0x003B6849  8bc8                    mov      ecx, eax                       
  0x003B684B  c1e908                  shr      ecx, 8                         
  0x003B684E  898d44030000            mov      dword ptr [ebp + 0x344], ecx   
  0x003B6854  0fb6c8                  movzx    ecx, al                        
  0x003B6857  03f9                    add      edi, ecx                       
  0x003B6859  83ff20                  cmp      edi, 0x20                      
  0x003B685C  7c33                    jl       0x3b6891                       
  0x003B685E  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B6861  83ef20                  sub      edi, 0x20                      
  0x003B6864  8bda                    mov      ebx, edx                       
  0x003B6866  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B686A  8bcf                    mov      ecx, edi                       
  0x003B686C  d3e3                    shl      ebx, cl                        
  0x003B686E  46                      inc      esi                            
  0x003B686F  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B6873  c1e008                  shl      eax, 8                         
  0x003B6876  0bc2                    or       eax, edx                       
  0x003B6878  46                      inc      esi                            
  0x003B6879  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B687D  c1e008                  shl      eax, 8                         
  0x003B6880  0bc1                    or       eax, ecx                       
  0x003B6882  46                      inc      esi                            
  0x003B6883  c1e008                  shl      eax, 8                         
  0x003B6886  0bc2                    or       eax, edx                       
  0x003B6888  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003B688C  46                      inc      esi                            
  0x003B688D  8bd0                    mov      edx, eax                       
  0x003B688F  eb02                    jmp      0x3b6893                       
                                        ; XREF: 0x003B685C (cond_jump)
  0x003B6891  d3e3                    shl      ebx, cl                        
                                        ; XREF: 0x003B681C (cond_jump), 0x003B688F (jump)
  0x003B6893  f6854403000010          test     byte ptr [ebp + 0x344], 0x10   
  0x003B689A  7461                    je       0x3b68fd                       
  0x003B689C  83ff1b                  cmp      edi, 0x1b                      
  0x003B689F  7c4b                    jl       0x3b68ec                       
  0x003B68A1  83ef1b                  sub      edi, 0x1b                      
  0x003B68A4  7416                    je       0x3b68bc                       
  0x003B68A6  b905000000              mov      ecx, 5                         
  0x003B68AB  2bcf                    sub      ecx, edi                       
  0x003B68AD  8bc2                    mov      eax, edx                       
  0x003B68AF  d3e8                    shr      eax, cl                        
  0x003B68B1  8bcf                    mov      ecx, edi                       
  0x003B68B3  0bc3                    or       eax, ebx                       
  0x003B68B5  c1e81b                  shr      eax, 0x1b                      
  0x003B68B8  d3e2                    shl      edx, cl                        
  0x003B68BA  eb05                    jmp      0x3b68c1                       
                                        ; XREF: 0x003B68A4 (cond_jump)
  0x003B68BC  8bc3                    mov      eax, ebx                       
  0x003B68BE  c1e81b                  shr      eax, 0x1b                      
                                        ; XREF: 0x003B68BA (jump)
  0x003B68C1  0fbe0e                  movsx    ecx, byte ptr [esi]            
  0x003B68C4  46                      inc      esi                            
  0x003B68C5  c1e108                  shl      ecx, 8                         
  0x003B68C8  8bda                    mov      ebx, edx                       
  0x003B68CA  0fb616                  movzx    edx, byte ptr [esi]            
  0x003B68CD  0bca                    or       ecx, edx                       
  0x003B68CF  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B68D3  46                      inc      esi                            
  0x003B68D4  c1e108                  shl      ecx, 8                         
  0x003B68D7  0bca                    or       ecx, edx                       
  0x003B68D9  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B68DD  46                      inc      esi                            
  0x003B68DE  c1e108                  shl      ecx, 8                         
  0x003B68E1  0bca                    or       ecx, edx                       
  0x003B68E3  894c242c                mov      dword ptr [esp + 0x2c], ecx    
  0x003B68E7  46                      inc      esi                            
  0x003B68E8  8bd1                    mov      edx, ecx                       
  0x003B68EA  eb0b                    jmp      0x3b68f7                       
                                        ; XREF: 0x003B689F (cond_jump)
  0x003B68EC  8bc3                    mov      eax, ebx                       
  0x003B68EE  83c705                  add      edi, 5                         
  0x003B68F1  c1e81b                  shr      eax, 0x1b                      
  0x003B68F4  c1e305                  shl      ebx, 5                         
                                        ; XREF: 0x003B68EA (jump)
  0x003B68F7  8985e8020000            mov      dword ptr [ebp + 0x2e8], eax   
                                        ; XREF: 0x003B689A (cond_jump)
  0x003B68FD  f6854403000008          test     byte ptr [ebp + 0x344], 8      
  0x003B6904  7465                    je       0x3b696b                       
  0x003B6906  8d85fc020000            lea      eax, [ebp + 0x2fc]             
  0x003B690C  50                      push     eax                            
  0x003B690D  8d8d04030000            lea      ecx, [ebp + 0x304]             
  0x003B6913  89750c                  mov      dword ptr [ebp + 0xc], esi     
  0x003B6916  51                      push     ecx                            
  0x003B6917  8db5ec020000            lea      esi, [ebp + 0x2ec]             
  0x003B691D  56                      push     esi                            
  0x003B691E  55                      push     ebp                            
  0x003B691F  895d00                  mov      dword ptr [ebp], ebx           
  0x003B6922  895504                  mov      dword ptr [ebp + 4], edx       
  0x003B6925  897d08                  mov      dword ptr [ebp + 8], edi       
  0x003B6928  e8f3f3ffff              call     0x3b5d20                       ; -> sub_003B5D20
  0x003B692D  8d9500030000            lea      edx, [ebp + 0x300]             
  0x003B6933  52                      push     edx                            
  0x003B6934  89442430                mov      dword ptr [esp + 0x30], eax    
  0x003B6938  8d8508030000            lea      eax, [ebp + 0x308]             
  0x003B693E  50                      push     eax                            
  0x003B693F  56                      push     esi                            
  0x003B6940  55                      push     ebp                            
  0x003B6941  e8daf3ffff              call     0x3b5d20                       ; -> sub_003B5D20
  0x003B6946  8b4d04                  mov      ecx, dword ptr [ebp + 4]       
  0x003B6949  8b5d00                  mov      ebx, dword ptr [ebp]           
  0x003B694C  8b7d08                  mov      edi, dword ptr [ebp + 8]       
  0x003B694F  8b750c                  mov      esi, dword ptr [ebp + 0xc]     
  0x003B6952  894c244c                mov      dword ptr [esp + 0x4c], ecx    
  0x003B6956  8b4c243c                mov      ecx, dword ptr [esp + 0x3c]    
  0x003B695A  83c420                  add      esp, 0x20                      
  0x003B695D  0bc1                    or       eax, ecx                       
  0x003B695F  0f8550020000            jne      0x3b6bb5                       
  0x003B6965  8b54242c                mov      edx, dword ptr [esp + 0x2c]    
  0x003B6969  eb0f                    jmp      0x3b697a                       
                                        ; XREF: 0x003B6904 (cond_jump)
  0x003B696B  8d85ec020000            lea      eax, [ebp + 0x2ec]             
  0x003B6971  50                      push     eax                            
  0x003B6972  e869f3ffff              call     0x3b5ce0                       ; -> sub_003B5CE0
  0x003B6977  83c404                  add      esp, 4                         
                                        ; XREF: 0x003B6969 (jump)
  0x003B697A  f6854403000002          test     byte ptr [ebp + 0x344], 2      
  0x003B6981  747a                    je       0x3b69fd                       
  0x003B6983  8bc3                    mov      eax, ebx                       
  0x003B6985  c1e817                  shr      eax, 0x17                      
  0x003B6988  83ff17                  cmp      edi, 0x17                      
  0x003B698B  89442410                mov      dword ptr [esp + 0x10], eax    
  0x003B698F  7e13                    jle      0x3b69a4                       
  0x003B6991  b937000000              mov      ecx, 0x37                      
  0x003B6996  2bcf                    sub      ecx, edi                       
  0x003B6998  8bc2                    mov      eax, edx                       
  0x003B699A  d3e8                    shr      eax, cl                        
  0x003B699C  8bc8                    mov      ecx, eax                       
  0x003B699E  8b442410                mov      eax, dword ptr [esp + 0x10]    
  0x003B69A2  0bc1                    or       eax, ecx                       
                                        ; XREF: 0x003B698F (cond_jump)
  0x003B69A4  8b0dd45df600            mov      ecx, dword ptr [0xf65dd4]      
  0x003B69AA  0fbf0441                movsx    eax, word ptr [ecx + eax*2]    
  0x003B69AE  8bc8                    mov      ecx, eax                       
  0x003B69B0  83e1f0                  and      ecx, 0xfffffff0                
  0x003B69B3  c1e110                  shl      ecx, 0x10                      
  0x003B69B6  898d48030000            mov      dword ptr [ebp + 0x348], ecx   
  0x003B69BC  0fb6c8                  movzx    ecx, al                        
  0x003B69BF  03f9                    add      edi, ecx                       
  0x003B69C1  83ff20                  cmp      edi, 0x20                      
  0x003B69C4  7c33                    jl       0x3b69f9                       
  0x003B69C6  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B69C9  83ef20                  sub      edi, 0x20                      
  0x003B69CC  8bda                    mov      ebx, edx                       
  0x003B69CE  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B69D2  8bcf                    mov      ecx, edi                       
  0x003B69D4  d3e3                    shl      ebx, cl                        
  0x003B69D6  46                      inc      esi                            
  0x003B69D7  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B69DB  c1e008                  shl      eax, 8                         
  0x003B69DE  0bc2                    or       eax, edx                       
  0x003B69E0  46                      inc      esi                            
  0x003B69E1  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B69E5  c1e008                  shl      eax, 8                         
  0x003B69E8  0bc1                    or       eax, ecx                       
  0x003B69EA  46                      inc      esi                            
  0x003B69EB  c1e008                  shl      eax, 8                         
  0x003B69EE  0bc2                    or       eax, edx                       
  0x003B69F0  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003B69F4  46                      inc      esi                            
  0x003B69F5  8bd0                    mov      edx, eax                       
  0x003B69F7  eb0e                    jmp      0x3b6a07                       
                                        ; XREF: 0x003B69C4 (cond_jump)
  0x003B69F9  d3e3                    shl      ebx, cl                        
  0x003B69FB  eb0a                    jmp      0x3b6a07                       
                                        ; XREF: 0x003B6981 (cond_jump)
  0x003B69FD  c7854803000000000000    mov      dword ptr [ebp + 0x348], 0     
                                        ; XREF: 0x003B69F7 (jump), 0x003B69FB (jump)
  0x003B6A07  f6854403000001          test     byte ptr [ebp + 0x344], 1      
  0x003B6A0E  895d00                  mov      dword ptr [ebp], ebx           
  0x003B6A11  895504                  mov      dword ptr [ebp + 4], edx       
  0x003B6A14  897d08                  mov      dword ptr [ebp + 8], edi       
  0x003B6A17  89750c                  mov      dword ptr [ebp + 0xc], esi     
  0x003B6A1A  7410                    je       0x3b6a2c                       
  0x003B6A1C  55                      push     ebp                            
  0x003B6A1D  ff95c8020000            call     dword ptr [ebp + 0x2c8]        
  0x003B6A23  55                      push     ebp                            
  0x003B6A24  ff95d0020000            call     dword ptr [ebp + 0x2d0]        
  0x003B6A2A  eb21                    jmp      0x3b6a4d                       
                                        ; XREF: 0x003B6A1A (cond_jump)
  0x003B6A2C  8b8548030000            mov      eax, dword ptr [ebp + 0x348]   
  0x003B6A32  85c0                    test     eax, eax                       
  0x003B6A34  740a                    je       0x3b6a40                       
  0x003B6A36  55                      push     ebp                            
  0x003B6A37  ff95cc020000            call     dword ptr [ebp + 0x2cc]        
  0x003B6A3D  83c404                  add      esp, 4                         
                                        ; XREF: 0x003B6A34 (cond_jump)
  0x003B6A40  55                      push     ebp                            
  0x003B6A41  ff95dc020000            call     dword ptr [ebp + 0x2dc]        
  0x003B6A47  55                      push     ebp                            
  0x003B6A48  e8b3f2ffff              call     0x3b5d00                       ; -> sub_003B5D00
                                        ; XREF: 0x003B6A2A (jump)
  0x003B6A4D  8b8d24130000            mov      ecx, dword ptr [ebp + 0x1324]  
  0x003B6A53  83c408                  add      esp, 8                         
  0x003B6A56  49                      dec      ecx                            
  0x003B6A57  8bc1                    mov      eax, ecx                       
  0x003B6A59  85c0                    test     eax, eax                       
  0x003B6A5B  898d24130000            mov      dword ptr [ebp + 0x1324], ecx  
  0x003B6A61  7f1c                    jg       0x3b6a7f                       
  0x003B6A63  8b8db4010000            mov      ecx, dword ptr [ebp + 0x1b4]   
  0x003B6A69  8b85ac010000            mov      eax, dword ptr [ebp + 0x1ac]   
  0x003B6A6F  51                      push     ecx                            
  0x003B6A70  898524130000            mov      dword ptr [ebp + 0x1324], eax  
  0x003B6A76  ff95b0010000            call     dword ptr [ebp + 0x1b0]        
  0x003B6A7C  83c404                  add      esp, 4                         
                                        ; XREF: 0x003B6A61 (cond_jump)
  0x003B6A7F  8b7d08                  mov      edi, dword ptr [ebp + 8]       
  0x003B6A82  8b5504                  mov      edx, dword ptr [ebp + 4]       
  0x003B6A85  8b750c                  mov      esi, dword ptr [ebp + 0xc]     
  0x003B6A88  8b5d00                  mov      ebx, dword ptr [ebp]           
  0x003B6A8B  8bc7                    mov      eax, edi                       
  0x003B6A8D  83e007                  and      eax, 7                         
  0x003B6A90  8bcf                    mov      ecx, edi                       
  0x003B6A92  2bc8                    sub      ecx, eax                       
  0x003B6A94  83c107                  add      ecx, 7                         
  0x003B6A97  8954242c                mov      dword ptr [esp + 0x2c], edx    
  0x003B6A9B  8944241c                mov      dword ptr [esp + 0x1c], eax    
  0x003B6A9F  8b442414                mov      eax, dword ptr [esp + 0x14]    
  0x003B6AA3  8b10                    mov      edx, dword ptr [eax]           
  0x003B6AA5  c1f903                  sar      ecx, 3                         
  0x003B6AA8  2bca                    sub      ecx, edx                       
  0x003B6AAA  8b950c130000            mov      edx, dword ptr [ebp + 0x130c]  
  0x003B6AB0  8d4c31f8                lea      ecx, [ecx + esi - 8]           
  0x003B6AB4  2bd1                    sub      edx, ecx                       
  0x003B6AB6  81fa00080000            cmp      edx, 0x800                     
  0x003B6ABC  0f8fe2000000            jg       0x3b6ba4                       
  0x003B6AC2  8d542420                lea      edx, [esp + 0x20]              
  0x003B6AC6  52                      push     edx                            
  0x003B6AC7  50                      push     eax                            
  0x003B6AC8  51                      push     ecx                            
  0x003B6AC9  50                      push     eax                            
  0x003B6ACA  e8a105f5ff              call     0x307070                       ; -> sub_00307070
  0x003B6ACF  8b7c2424                mov      edi, dword ptr [esp + 0x24]    
  0x003B6AD3  8b742440                mov      esi, dword ptr [esp + 0x40]    
  0x003B6AD7  8b06                    mov      eax, dword ptr [esi]           
  0x003B6AD9  57                      push     edi                            
  0x003B6ADA  6a00                    push     0                              
  0x003B6ADC  56                      push     esi                            
  0x003B6ADD  ff5020                  call     dword ptr [eax + 0x20]         
  0x003B6AE0  8b0e                    mov      ecx, dword ptr [esi]           
  0x003B6AE2  8d54243c                lea      edx, [esp + 0x3c]              
  0x003B6AE6  52                      push     edx                            
  0x003B6AE7  6a01                    push     1                              
  0x003B6AE9  56                      push     esi                            
  0x003B6AEA  ff511c                  call     dword ptr [ecx + 0x1c]         
  0x003B6AED  8b06                    mov      eax, dword ptr [esi]           
  0x003B6AEF  57                      push     edi                            
  0x003B6AF0  68ffffff7f              push     0x7fffffff                     
  0x003B6AF5  6a01                    push     1                              
  0x003B6AF7  56                      push     esi                            
  0x003B6AF8  ff5018                  call     dword ptr [eax + 0x18]         
  0x003B6AFB  8b3f                    mov      edi, dword ptr [edi]           
  0x003B6AFD  8bf7                    mov      esi, edi                       
  0x003B6AFF  83e6fc                  and      esi, 0xfffffffc                
  0x003B6B02  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B6B05  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B6B09  c1e008                  shl      eax, 8                         
  0x003B6B0C  0bc1                    or       eax, ecx                       
  0x003B6B0E  2bfe                    sub      edi, esi                       
  0x003B6B10  c1e703                  shl      edi, 3                         
  0x003B6B13  83c438                  add      esp, 0x38                      
  0x003B6B16  46                      inc      esi                            
  0x003B6B17  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B6B1B  c1e008                  shl      eax, 8                         
  0x003B6B1E  0bc2                    or       eax, edx                       
  0x003B6B20  46                      inc      esi                            
  0x003B6B21  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B6B25  c1e008                  shl      eax, 8                         
  0x003B6B28  0bc1                    or       eax, ecx                       
  0x003B6B2A  46                      inc      esi                            
  0x003B6B2B  8bd8                    mov      ebx, eax                       
  0x003B6B2D  0fbe4601                movsx    eax, byte ptr [esi + 1]        
  0x003B6B31  46                      inc      esi                            
  0x003B6B32  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B6B36  8bcf                    mov      ecx, edi                       
  0x003B6B38  d3e3                    shl      ebx, cl                        
  0x003B6B3A  46                      inc      esi                            
  0x003B6B3B  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B6B3F  c1e008                  shl      eax, 8                         
  0x003B6B42  0bc2                    or       eax, edx                       
  0x003B6B44  46                      inc      esi                            
  0x003B6B45  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B6B49  c1e008                  shl      eax, 8                         
  0x003B6B4C  0bc1                    or       eax, ecx                       
  0x003B6B4E  8b4c241c                mov      ecx, dword ptr [esp + 0x1c]    
  0x003B6B52  46                      inc      esi                            
  0x003B6B53  c1e008                  shl      eax, 8                         
  0x003B6B56  0bc2                    or       eax, edx                       
  0x003B6B58  03f9                    add      edi, ecx                       
  0x003B6B5A  46                      inc      esi                            
  0x003B6B5B  83ff20                  cmp      edi, 0x20                      
  0x003B6B5E  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003B6B62  7c3e                    jl       0x3b6ba2                       
  0x003B6B64  8bd8                    mov      ebx, eax                       
  0x003B6B66  0fbe06                  movsx    eax, byte ptr [esi]            
  0x003B6B69  83ef20                  sub      edi, 0x20                      
  0x003B6B6C  8bcf                    mov      ecx, edi                       
  0x003B6B6E  d3e3                    shl      ebx, cl                        
  0x003B6B70  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B6B74  46                      inc      esi                            
  0x003B6B75  0fb65601                movzx    edx, byte ptr [esi + 1]        
  0x003B6B79  c1e008                  shl      eax, 8                         
  0x003B6B7C  0bc1                    or       eax, ecx                       
  0x003B6B7E  46                      inc      esi                            
  0x003B6B7F  0fb64e01                movzx    ecx, byte ptr [esi + 1]        
  0x003B6B83  c1e008                  shl      eax, 8                         
  0x003B6B86  0bc2                    or       eax, edx                       
  0x003B6B88  46                      inc      esi                            
  0x003B6B89  c1e008                  shl      eax, 8                         
  0x003B6B8C  0bc1                    or       eax, ecx                       
  0x003B6B8E  8944242c                mov      dword ptr [esp + 0x2c], eax    
  0x003B6B92  46                      inc      esi                            
  0x003B6B93  c744241800000000        mov      dword ptr [esp + 0x18], 0      
  0x003B6B9B  8bd0                    mov      edx, eax                       
  0x003B6B9D  e9effaffff              jmp      0x3b6691                       
                                        ; XREF: 0x003B6B62 (cond_jump)
  0x003B6BA2  d3e3                    shl      ebx, cl                        
                                        ; XREF: 0x003B6ABC (cond_jump)
  0x003B6BA4  8b54242c                mov      edx, dword ptr [esp + 0x2c]    
  0x003B6BA8  c744241800000000        mov      dword ptr [esp + 0x18], 0      
  0x003B6BB0  e9dcfaffff              jmp      0x3b6691                       
                                        ; XREF: 0x003B66B4 (cond_jump), 0x003B6772 (cond_jump), 0x003B6793 (cond_jump), 0x003B67E1 (cond_jump), 0x003B695F (cond_jump)
  0x003B6BB5  8b5c2414                mov      ebx, dword ptr [esp + 0x14]    
  0x003B6BB9  8b2b                    mov      ebp, dword ptr [ebx]           
  0x003B6BBB  83c707                  add      edi, 7                         
  0x003B6BBE  8d542420                lea      edx, [esp + 0x20]              
  0x003B6BC2  52                      push     edx                            
  0x003B6BC3  c1ff03                  sar      edi, 3                         
  0x003B6BC6  2bfd                    sub      edi, ebp                       
  0x003B6BC8  53                      push     ebx                            
  0x003B6BC9  8d4437f8                lea      eax, [edi + esi - 8]           
  0x003B6BCD  50                      push     eax                            
  0x003B6BCE  53                      push     ebx                            
  0x003B6BCF  e89c04f5ff              call     0x307070                       ; -> sub_00307070
  0x003B6BD4  8b742440                mov      esi, dword ptr [esp + 0x40]    
  0x003B6BD8  8b0e                    mov      ecx, dword ptr [esi]           
  0x003B6BDA  53                      push     ebx                            
  0x003B6BDB  6a00                    push     0                              
  0x003B6BDD  56                      push     esi                            
  0x003B6BDE  ff5120                  call     dword ptr [ecx + 0x20]         
  0x003B6BE1  8b16                    mov      edx, dword ptr [esi]           
  0x003B6BE3  8d44243c                lea      eax, [esp + 0x3c]              
  0x003B6BE7  50                      push     eax                            
  0x003B6BE8  6a01                    push     1                              
  0x003B6BEA  56                      push     esi                            
  0x003B6BEB  ff521c                  call     dword ptr [edx + 0x1c]         
  0x003B6BEE  56                      push     esi                            
  0x003B6BEF  e80c8bf6ff              call     0x31f700                       ; -> sub_0031F700
  0x003B6BF4  83c42c                  add      esp, 0x2c                      
  0x003B6BF7  5f                      pop      edi                            
  0x003B6BF8  5e                      pop      esi                            
  0x003B6BF9  5d                      pop      ebp                            
  0x003B6BFA  5b                      pop      ebx                            
  0x003B6BFB  83c418                  add      esp, 0x18                      
  0x003B6BFE  c3                      ret                                     
