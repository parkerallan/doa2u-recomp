; ============================================================
; Section: DOLBY
; VA: 0x01060F60 - 0x010680E0
; Size: 29056 bytes (28.4 KB)
; Functions: 0
; Instructions: 12339
; ============================================================

  0x01060F60  080c0500000000          or       byte ptr [eax], cl             
  0x01060F67  0001                    add      byte ptr [ecx], al             
  0x01060F69  0000                    add      byte ptr [eax], al             
  0x01060F6B  0001                    add      byte ptr [ecx], al             
  0x01060F6D  0000                    add      byte ptr [eax], al             
  0x01060F6F  0000                    add      byte ptr [eax], al             
  0x01060F71  0000                    add      byte ptr [eax], al             
  0x01060F73  0000                    add      byte ptr [eax], al             
  0x01060F75  0000                    add      byte ptr [eax], al             
  0x01060F77  00cc                    add      ah, cl                         
  0x01060F79  cc                      int3                                    
  0x01060F7A  cc                      int3                                    
  0x01060F7B  0000                    add      byte ptr [eax], al             
  0x01060F7D  0000                    add      byte ptr [eax], al             
  0x01060F7F  0000                    add      byte ptr [eax], al             
  0x01060F81  002400                  add      byte ptr [eax + eax], ah       
  0x01060F84  847007                  test     byte ptr [eax + 7], dh         
  0x01060F87  000400                  add      byte ptr [eax + eax], al       
  0x01060F8A  0000                    add      byte ptr [eax], al             
  0x01060F8C  847007                  test     byte ptr [eax + 7], dh         
  0x01060F8F  000500000032            add      byte ptr [0x32000000], al      
  0x01060F95  f4                      hlt                                     
  0x01060F96  07                      pop      es                             
  0x01060F97  00ff                    add      bh, bh                         
  0x01060F9A  ff00                    inc      dword ptr [eax]                
  0x01060F9C  30f4                    xor      ah, dh                         
  0x01060F9E  07                      pop      es                             
  0x01060F9F  0001                    add      byte ptr [ecx], al             
  0x01060FA1  0000                    add      byte ptr [eax], al             
  0x01060FA3  0031                    add      byte ptr [ecx], dh             
  0x01060FA5  f4                      hlt                                     
  0x01060FA6  07                      pop      es                             
  0x01060FA7  0001                    add      byte ptr [ecx], al             
  0x01060FA9  0000                    add      byte ptr [eax], al             
  0x01060FAB  00bb0005002a            add      byte ptr [ebx + 0x2a000500], bh 
  0x01060FB1  f4                      hlt                                     
  0x01060FB2  0500e00b00              add      eax, 0xbe000                   
  0x01060FB7  00b820050074            add      byte ptr [eax + 0x74000520], bh 
  0x01060FBD  fa                      cli                                     
  0x01060FBE  0a00                    or       al, byte ptr [eax]             
  0x01060FC0  1300                    adc      eax, dword ptr [eax]           
  0x01060FC2  2000                    and      byte ptr [eax], al             
  0x01060FC4  887007                  mov      byte ptr [eax + 7], dh         
  0x01060FC7  0001                    add      byte ptr [ecx], al             
  0x01060FC9  0000                    add      byte ptr [eax], al             
  0x01060FCB  0008                    add      byte ptr [eax], cl             
  0x01060FCD  0000                    add      byte ptr [eax], al             
  0x01060FCF  008870070002            add      byte ptr [eax + 0x2000770], cl 
  0x01060FD5  0000                    add      byte ptr [eax], al             
  0x01060FD7  008870070003            add      byte ptr [eax + 0x3000770], cl 
  0x01060FDD  0000                    add      byte ptr [eax], al             
  0x01060FDF  0000                    add      byte ptr [eax], al             
  0x01060FE1  f4                      hlt                                     
  0x01060FE2  56                      push     esi                            
  0x01060FE3  0000                    add      byte ptr [eax], al             
  0x01060FE5  0000                    add      byte ptr [eax], al             
  0x01060FE7  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x01060FED  0100                    add      dword ptr [eax], eax           
  0x01060FEF  0003                    add      byte ptr [ebx], al             
  0x01060FF1  0020                    add      byte ptr [eax], ah             
  0x01060FF3  004210                  add      byte ptr [edx + 0x10], al      
  0x01060FF6  0d00a20000              or       eax, 0xa200                    
  0x01060FFB  0085f4080002            add      byte ptr [ebp + 0x20008f4], al 
  0x01061001  0000                    add      byte ptr [eax], al             
  0x01061003  008ef0070007            add      byte ptr [esi + 0x70007f0], cl 
  0x01061009  0000                    add      byte ptr [eax], al             
  0x0106100B  00804101008e            add      byte ptr [eax - 0x71fffebf], al 
  0x01061011  7007                    jo       0x106101a                      
  0x01061013  0007                    add      byte ptr [edi], al             
  0x01061015  0000                    add      byte ptr [eax], al             
  0x01061017  0084f408000100          add      byte ptr [esp + esi*8 + 0x10008], al 
  0x0106101E  0000                    add      byte ptr [eax], al             
  0x01061020  1300                    adc      eax, dword ptr [eax]           
  0x01061022  2000                    and      byte ptr [eax], al             
  0x01061024  80410100                add      byte ptr [ecx + 1], 0          
  0x01061028  81850a003100000000f0    add      dword ptr [ebp + 0x31000a], 0xf0000000 
  0x01061032  44                      inc      esp                            
  0x01061033  00b3ffff0084            add      byte ptr [ebx - 0x7bff0001], dh 
  0x01061039  7007                    jo       0x1061042                      
  0x0106103B  000500000085            add      byte ptr [0x85000000], al      
  0x01061041  f4                      hlt                                     
                                        ; XREF: 0x01061039 (cond_jump)
  0x01061042  0800                    or       byte ptr [eax], al             
  0x01061044  0200                    add      al, byte ptr [eax]             
  0x01061046  0000                    add      byte ptr [eax], al             
  0x0106104A  07                      pop      es                             
  0x0106104B  0001                    add      byte ptr [ecx], al             
  0x0106104D  0000                    add      byte ptr [eax], al             
  0x0106104F  0003                    add      byte ptr [ebx], al             
  0x01061051  f4                      hlt                                     
  0x01061052  60                      pushal                                  
  0x01061053  00c0                    add      al, al                         
  0x01061055  0b00                    or       eax, dword ptr [eax]           
  0x01061057  0009                    add      byte ptr [ecx], cl             
  0x01061059  2405                    and      al, 5                          
  0x0106105B  0000                    add      byte ptr [eax], al             
  0x0106105D  f4                      hlt                                     
  0x0106105E  56                      push     esi                            
  0x0106105F  000a                    add      byte ptr [edx], cl             
  0x01061061  0000                    add      byte ptr [eax], al             
  0x01061063  0000                    add      byte ptr [eax], al             
  0x01061065  2038                    and      byte ptr [eax], bh             
  0x01061067  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x0106106D  0100                    add      dword ptr [eax], eax           
  0x0106106F  0003                    add      byte ptr [ebx], al             
  0x01061071  0020                    add      byte ptr [eax], ah             
  0x01061073  004210                  add      byte ptr [edx + 0x10], al      
  0x01061076  0d00820000              or       eax, 0x8200                    
  0x0106107B  0000                    add      byte ptr [eax], al             
  0x0106107E  56                      push     esi                            
  0x0106107F  00c1                    add      cl, al                         
  0x01061081  0b00                    or       eax, dword ptr [eax]           
  0x01061083  0003                    add      byte ptr [ebx], al             
  0x01061085  f4                      hlt                                     
  0x01061086  60                      pushal                                  
  0x01061087  0000                    add      byte ptr [eax], al             
  0x01061089  0300                    add      eax, dword ptr [eax]           
  0x0106108B  0012                    add      byte ptr [edx], dl             
  0x0106108D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106108E  050000f456              add      eax, 0x56f40000                
  0x01061093  0001                    add      byte ptr [ecx], al             
  0x01061095  0000                    add      byte ptr [eax], al             
  0x01061097  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x0106109D  0100                    add      dword ptr [eax], eax           
  0x0106109F  0003                    add      byte ptr [ebx], al             
  0x010610A1  0020                    add      byte ptr [eax], ah             
  0x010610A3  004210                  add      byte ptr [edx + 0x10], al      
  0x010610A6  0d00760000              or       eax, 0x7600                    
  0x010610AB  008ff0070002            add      byte ptr [edi + 0x20007f0], cl 
  0x010610B1  0000                    add      byte ptr [eax], al             
  0x010610B3  0000                    add      byte ptr [eax], al             
  0x010610B5  f4                      hlt                                     
  0x010610B6  60                      pushal                                  
  0x010610B7  00c0                    add      al, al                         
  0x010610B9  0b00                    or       eax, dword ptr [eax]           
  0x010610BB  0080f00b0004            add      byte ptr [eax + 0x4000bf0], al 
  0x010610C1  0300                    add      eax, dword ptr [eax]           
  0x010610C3  0000                    add      byte ptr [eax], al             
  0x010610C5  002400                  add      byte ptr [eax + eax], ah       
  0x010610C8  847007                  test     byte ptr [eax + 7], dh         
  0x010610CB  0002                    add      byte ptr [edx], al             
  0x010610CD  0000                    add      byte ptr [eax], al             
  0x010610CF  001c0c                  add      byte ptr [esp + ecx], bl       
  0x010610D2  050000f057              add      eax, 0x57f00000                
  0x010610D7  00c3                    add      bl, al                         
  0x010610D9  0b00                    or       eax, dword ptr [eax]           
  0x010610DB  000b                    add      byte ptr [ebx], cl             
  0x010610DD  f4                      hlt                                     
  0x010610DE  60                      pushal                                  
  0x010610DF  0000                    add      byte ptr [eax], al             
  0x010610E1  0300                    add      eax, dword ptr [eax]           
  0x010610E3  0017                    add      byte ptr [edi], dl             
  0x010610E5  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010610E6  050013f444              add      eax, 0x44f41300                
  0x010610EB  0005000000cd            add      byte ptr [0xcd000000], al      
  0x010610F1  40                      inc      eax                            
  0x010610F2  0100                    add      dword ptr [eax], eax           
  0x010610F4  0100                    add      dword ptr [eax], eax           
  0x010610F6  0000                    add      byte ptr [eax], al             
  0x010610F8  41                      inc      ecx                            
  0x010610F9  2a20                    sub      ah, byte ptr [eax]             
  0x010610FB  0000                    add      byte ptr [eax], al             
  0x010610FD  f4                      hlt                                     
  0x010610FE  44                      inc      esp                            
  0x010610FF  0006                    add      byte ptr [esi], al             
  0x01061101  0000                    add      byte ptr [eax], al             
  0x01061103  00cd                    add      ch, cl                         
  0x01061105  40                      inc      eax                            
  0x01061106  0100                    add      dword ptr [eax], eax           
  0x01061108  0200                    add      al, byte ptr [eax]             
  0x0106110A  0000                    add      byte ptr [eax], al             
  0x0106110C  41                      inc      ecx                            
  0x0106110D  2a20                    sub      ah, byte ptr [eax]             
  0x0106110F  0003                    add      byte ptr [ebx], al             
  0x01061111  0020                    add      byte ptr [eax], ah             
  0x01061113  000b                    add      byte ptr [ebx], cl             
  0x01061115  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01061116  050080f00b              add      eax, 0xbf08000                 
  0x0106111B  008001000003            add      byte ptr [eax + 0x3000001], al 
  0x01061121  0020                    add      byte ptr [eax], ah             
  0x01061123  004210                  add      byte ptr [edx + 0x10], al      
  0x01061126  0d00560000              or       eax, 0x5600                    
  0x0106112B  0000                    add      byte ptr [eax], al             
  0x0106112D  f4                      hlt                                     
  0x0106112E  60                      pushal                                  
  0x0106112F  00c0                    add      al, al                         
  0x01061131  0b00                    or       eax, dword ptr [eax]           
  0x01061133  0080f00b0004            add      byte ptr [eax + 0x4000bf0], al 
  0x01061139  0300                    add      eax, dword ptr [eax]           
  0x0106113B  0001                    add      byte ptr [ecx], al             
  0x0106113D  0c05                    or       al, 5                          
  0x0106113F  0000                    add      byte ptr [eax], al             
  0x01061142  56                      push     esi                            
  0x01061143  00c2                    add      dl, al                         
  0x01061145  0b00                    or       eax, dword ptr [eax]           
  0x01061147  0003                    add      byte ptr [ebx], al             
  0x01061149  f4                      hlt                                     
  0x0106114A  60                      pushal                                  
  0x0106114B  0000                    add      byte ptr [eax], al             
  0x0106114D  0300                    add      eax, dword ptr [eax]           
  0x0106114F  004fa4                  add      byte ptr [edi - 0x5c], cl      
  0x01061152  050000f456              add      eax, 0x56f40000                
  0x01061157  0002                    add      byte ptr [edx], al             
  0x01061159  0000                    add      byte ptr [eax], al             
  0x0106115B  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x01061161  0100                    add      dword ptr [eax], eax           
  0x01061163  0003                    add      byte ptr [ebx], al             
  0x01061165  0020                    add      byte ptr [eax], ah             
  0x01061167  004210                  add      byte ptr [edx + 0x10], al      
  0x0106116A  0d00450000              or       eax, 0x4500                    
  0x0106116F  0000                    add      byte ptr [eax], al             
  0x01061171  f4                      hlt                                     
  0x01061172  60                      pushal                                  
  0x01061173  00c0                    add      al, al                         
  0x01061175  0b00                    or       eax, dword ptr [eax]           
  0x01061177  008ff0070003            add      byte ptr [edi + 0x30007f0], cl 
  0x0106117D  0000                    add      byte ptr [eax], al             
  0x0106117F  0084f007000100          add      byte ptr [eax + esi*8 + 0x10007], al 
  0x01061186  0000                    add      byte ptr [eax], al             
  0x01061188  80f00b                  xor      al, 0xb                        
  0x0106118B  000403                  add      byte ptr [ebx + eax], al       
  0x0106118E  0000                    add      byte ptr [eax], al             
  0x01061190  00f4                    add      ah, dh                         
  0x01061192  60                      pushal                                  
  0x01061193  0000                    add      byte ptr [eax], al             
  0x01061195  0300                    add      eax, dword ptr [eax]           
  0x01061197  0000                    add      byte ptr [eax], al             
  0x01061199  f4                      hlt                                     
  0x0106119A  56                      push     esi                            
  0x0106119B  0003                    add      byte ptr [ebx], al             
  0x0106119D  0000                    add      byte ptr [eax], al             
  0x0106119F  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x010611A5  0100                    add      dword ptr [eax], eax           
  0x010611A7  0003                    add      byte ptr [ebx], al             
  0x010611A9  0020                    add      byte ptr [eax], ah             
  0x010611AB  004210                  add      byte ptr [edx + 0x10], al      
  0x010611AE  0d00340000              or       eax, 0x3400                    
  0x010611B3  008ff0070003            add      byte ptr [edi + 0x30007f0], cl 
  0x010611B9  0000                    add      byte ptr [eax], al             
  0x010611BB  0080f00b0004            add      byte ptr [eax + 0x4000bf0], al 
  0x010611C1  0300                    add      eax, dword ptr [eax]           
  0x010611C3  0000                    add      byte ptr [eax], al             
  0x010611C5  f4                      hlt                                     
  0x010611C6  60                      pushal                                  
  0x010611C7  0000                    add      byte ptr [eax], al             
  0x010611C9  0300                    add      eax, dword ptr [eax]           
  0x010611CB  0000                    add      byte ptr [eax], al             
  0x010611CD  f4                      hlt                                     
  0x010611CE  56                      push     esi                            
  0x010611CF  000400                  add      byte ptr [eax + eax], al       
  0x010611D2  0000                    add      byte ptr [eax], al             
  0x010611D4  80f00b                  xor      al, 0xb                        
  0x010611D7  008001000003            add      byte ptr [eax + 0x3000001], al 
  0x010611DD  0020                    add      byte ptr [eax], ah             
  0x010611DF  004210                  add      byte ptr [edx + 0x10], al      
  0x010611E2  0d00270000              or       eax, 0x2700                    
  0x010611E7  008ff0070003            add      byte ptr [edi + 0x30007f0], cl 
  0x010611ED  0000                    add      byte ptr [eax], al             
  0x010611EF  0084f007000100          add      byte ptr [eax + esi*8 + 0x10007], al 
  0x010611F6  0000                    add      byte ptr [eax], al             
  0x010611F8  80f00b                  xor      al, 0xb                        
  0x010611FB  000403                  add      byte ptr [ebx + eax], al       
  0x010611FE  0000                    add      byte ptr [eax], al             
  0x01061200  0000                    add      byte ptr [eax], al             
  0x01061202  2400                    and      al, 0                          
  0x01061204  847007                  test     byte ptr [eax + 7], dh         
  0x01061207  0003                    add      byte ptr [ebx], al             
  0x01061209  0000                    add      byte ptr [eax], al             
  0x0106120B  008ef0070001            add      byte ptr [esi + 0x10007f0], cl 
  0x01061211  0000                    add      byte ptr [eax], al             
  0x01061213  008041010085            add      byte ptr [eax - 0x7afffebf], al 
  0x01061219  46                      inc      esi                            
  0x0106121A  0100                    add      dword ptr [eax], eax           
  0x0106121C  1321                    adc      esp, dword ptr [ecx]           
  0x0106121E  2000                    and      byte ptr [eax], al             
  0x01061221  7007                    jo       0x106122a                      
  0x01061223  0001                    add      byte ptr [ecx], al             
  0x01061225  0000                    add      byte ptr [eax], al             
  0x01061227  0000                    add      byte ptr [eax], al             
  0x01061229  f4                      hlt                                     
                                        ; XREF: 0x01061221 (cond_jump)
  0x0106122A  56                      push     esi                            
  0x0106122B  000b                    add      byte ptr [ebx], cl             
  0x0106122D  0000                    add      byte ptr [eax], al             
  0x0106122F  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x01061235  0100                    add      dword ptr [eax], eax           
  0x01061237  0000                    add      byte ptr [eax], al             
  0x0106123A  56                      push     esi                            
  0x0106123B  00b3ffff0084            add      byte ptr [ebx - 0x7bff0001], dh 
  0x01061242  07                      pop      es                             
  0x01061243  000500000044            add      byte ptr [0x44000000], al      
  0x01061249  0020                    add      byte ptr [eax], ah             
  0x0106124B  008c7007000400          add      byte ptr [eax + esi*2 + 0x40007], cl 
  0x01061252  0000                    add      byte ptr [eax], al             
  0x01061254  00f4                    add      ah, dh                         
  0x01061256  44                      inc      esp                            
  0x01061257  00a0cd0a00f8            add      byte ptr [eax - 0x7fff533], ah 
  0x0106125D  1f                      pop      ds                             
  0x0106125E  0c00                    or       al, 0                          
  0x01061260  c9                      leave                                   
  0x01061261  96                      xchg     esi, eax                       
  0x01061262  050000f444              add      eax, 0x44f40000                
  0x01061267  00bbbbbb0084            add      byte ptr [ebx - 0x7bff4445], bh 
  0x0106126D  7007                    jo       0x1061276                      
  0x0106126F  0006                    add      byte ptr [esi], al             
  0x01061271  0000                    add      byte ptr [eax], al             
  0x01061273  0000                    add      byte ptr [eax], al             
  0x01061275  0c05                    or       al, 5                          
  0x01061277  00c3                    add      bl, al                         
  0x01061279  0e                      push     cs                             
  0x0106127A  0500c20e05              add      eax, 0x50ec200                 
  0x0106127F  0000                    add      byte ptr [eax], al             
  0x01061281  f4                      hlt                                     
  0x01061282  6200                    bound    eax, qword ptr [eax]           
  0x01061284  0001                    add      byte ptr [ecx], al             
  0x01061286  0000                    add      byte ptr [eax], al             
  0x01061288  009a21000001            add      byte ptr [edx + 0x1000021], bl 
  0x0106128E  3d00854001              cmp      eax, 0x1408500                 
  0x01061293  000f                    add      byte ptr [edi], cl             
  0x01061295  a5                      movsd    dword ptr es:[edi], dword ptr [esi] 
  0x01061296  0500004a20              add      eax, 0x204a0000                
  0x0106129B  0000                    add      byte ptr [eax], al             
  0x0106129D  4a                      dec      edx                            
  0x0106129E  2000                    and      byte ptr [eax], al             
  0x010612A0  91                      xchg     ecx, eax                       
  0x010612A1  da07                    fiadd    dword ptr [edi]                
  0x010612A3  0085510100ce            add      byte ptr [ebp - 0x31fffeaf], al 
  0x010612A9  1405                    adc      al, 5                          
  0x010612AB  008546010054            add      byte ptr [ebp + 0x54000146], al 
  0x010612B1  f4                      hlt                                     
  0x010612B2  0500854901              add      eax, 0x1498500                 
  0x010612B7  008ca40500854a          add      byte ptr [esp + 0x4a850005], cl 
  0x010612BE  0100                    add      dword ptr [eax], eax           
  0x010612C0  4b                      dec      ebx                            
  0x010612C1  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010612C2  0500854b01              add      eax, 0x14b8500                 
  0x010612C7  0051a4                  add      byte ptr [ecx - 0x5c], dl      
  0x010612CA  0500854c01              add      eax, 0x14c8500                 
  0x010612CF  0095a4050085            add      byte ptr [ebp - 0x7afffa5c], dl 
  0x010612D5  4d                      dec      ebp                            
  0x010612D6  0100                    add      dword ptr [eax], eax           
  0x010612D8  98                      cwde                                    
  0x010612D9  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010612DA  0500854801              add      eax, 0x1488500                 
  0x010612DF  005ba4                  add      byte ptr [ebx - 0x5c], bl      
  0x010612E2  0500854e01              add      eax, 0x14e8500                 
  0x010612E7  0087a4050085            add      byte ptr [edi - 0x7afffa5c], al 
  0x010612ED  4f                      dec      edi                            
  0x010612EE  0100                    add      dword ptr [eax], eax           
  0x010612F0  82a405004c0c0500        and      byte ptr [ebp + eax + 0x50c4c00], 0 
  0x010612F8  0000                    add      byte ptr [eax], al             
  0x010612FA  0000                    add      byte ptr [eax], al             
  0x010612FC  0000                    add      byte ptr [eax], al             
  0x010612FE  0000                    add      byte ptr [eax], al             
  0x01061300  0000                    add      byte ptr [eax], al             
  0x01061302  0000                    add      byte ptr [eax], al             
  0x01061304  0100                    add      dword ptr [eax], eax           
  0x01061306  0000                    add      byte ptr [eax], al             
  0x01061308  0000                    add      byte ptr [eax], al             
  0x0106130A  0000                    add      byte ptr [eax], al             
  0x0106130C  0000                    add      byte ptr [eax], al             
  0x0106130E  0000                    add      byte ptr [eax], al             
  0x01061310  0000                    add      byte ptr [eax], al             
  0x01061312  0000                    add      byte ptr [eax], al             
  0x01061314  0000                    add      byte ptr [eax], al             
  0x01061316  0000                    add      byte ptr [eax], al             
  0x01061318  0000                    add      byte ptr [eax], al             
  0x0106131A  0000                    add      byte ptr [eax], al             
  0x0106131C  0000                    add      byte ptr [eax], al             
  0x0106131E  0000                    add      byte ptr [eax], al             
  0x01061320  0000                    add      byte ptr [eax], al             
  0x01061322  0000                    add      byte ptr [eax], al             
  0x01061324  0000                    add      byte ptr [eax], al             
  0x01061326  0000                    add      byte ptr [eax], al             
  0x01061328  0000                    add      byte ptr [eax], al             
  0x0106132A  0000                    add      byte ptr [eax], al             
  0x0106132C  0000                    add      byte ptr [eax], al             
  0x0106132E  0000                    add      byte ptr [eax], al             
  0x01061330  0000                    add      byte ptr [eax], al             
  0x01061332  0000                    add      byte ptr [eax], al             
  0x01061334  0000                    add      byte ptr [eax], al             
  0x01061336  0000                    add      byte ptr [eax], al             
  0x01061338  0000                    add      byte ptr [eax], al             
  0x0106133A  0000                    add      byte ptr [eax], al             
  0x0106133C  0000                    add      byte ptr [eax], al             
  0x0106133E  0000                    add      byte ptr [eax], al             
  0x01061340  0000                    add      byte ptr [eax], al             
  0x01061342  0000                    add      byte ptr [eax], al             
  0x01061344  0000                    add      byte ptr [eax], al             
  0x01061346  0000                    add      byte ptr [eax], al             
  0x01061348  0000                    add      byte ptr [eax], al             
  0x0106134A  0000                    add      byte ptr [eax], al             
  0x0106134C  0000                    add      byte ptr [eax], al             
  0x0106134E  0000                    add      byte ptr [eax], al             
  0x01061350  0000                    add      byte ptr [eax], al             
  0x01061352  0000                    add      byte ptr [eax], al             
  0x01061354  0000                    add      byte ptr [eax], al             
  0x01061356  0000                    add      byte ptr [eax], al             
  0x01061358  0000                    add      byte ptr [eax], al             
  0x0106135A  0000                    add      byte ptr [eax], al             
  0x0106135C  0000                    add      byte ptr [eax], al             
  0x0106135E  0000                    add      byte ptr [eax], al             
  0x01061360  0000                    add      byte ptr [eax], al             
  0x01061362  0000                    add      byte ptr [eax], al             
  0x01061364  0000                    add      byte ptr [eax], al             
  0x01061366  0000                    add      byte ptr [eax], al             
  0x01061368  0000                    add      byte ptr [eax], al             
  0x0106136A  0000                    add      byte ptr [eax], al             
  0x0106136C  8eda                    mov      ds, edx                        
  0x0106136E  07                      pop      es                             
  0x0106136F  0000                    add      byte ptr [eax], al             
  0x01061371  0423                    add      al, 0x23                       
  0x01061373  004598                  add      byte ptr [ebp - 0x68], al      
  0x01061376  2100                    and      dword ptr [eax], eax           
  0x01061379  080500900c05            or       byte ptr [0x50c9000], al       
  0x0106137F  0098da07001f            add      byte ptr [eax + 0x1f0007da], bl 
  0x01061385  0905008d0c05            or       dword ptr [0x50c8d00], eax     
  0x0106138B  0084f007001601          add      byte ptr [eax + esi*8 + 0x1160007], al 
  0x01061392  0000                    add      byte ptr [eax], al             
  0x01061394  48                      dec      eax                            
  0x01061395  c40b                    les      ecx, ptr [ebx]                 
  0x01061397  00847007001601          add      byte ptr [eax + esi*2 + 0x1160007], al 
  0x0106139E  0000                    add      byte ptr [eax], al             
  0x010613A0  870c0500002f23          xchg     dword ptr [eax + 0x232f0000], ecx 
  0x010613A7  00931d0c0000            add      byte ptr [ebx + 0xc1d], dl     
  0x010613AD  2422                    and      al, 0x22                       
  0x010613AF  004800                  add      byte ptr [eax], cl             
  0x010613B2  2000                    and      byte ptr [eax], al             
  0x010613B6  07                      pop      es                             
  0x010613B7  0016                    add      byte ptr [esi], dl             
  0x010613B9  0100                    add      dword ptr [eax], eax           
  0x010613BB  0010                    add      byte ptr [eax], dl             
  0x010613BD  0020                    add      byte ptr [eax], ah             
  0x010613BF  0000                    add      byte ptr [eax], al             
  0x010613C1  91                      xchg     ecx, eax                       
  0x010613C2  2100                    and      dword ptr [eax], eax           
  0x010613C4  93                      xchg     ebx, eax                       
  0x010613C5  0805005d0c05            or       byte ptr [0x50c5d00], al       
  0x010613CB  0000                    add      byte ptr [eax], al             
  0x010613CD  2e2300                  and      eax, dword ptr cs:[eax]        
  0x010613D0  854001                  test     dword ptr [eax + 1], eax       
  0x010613D3  005a24                  add      byte ptr [edx + 0x24], bl      
  0x010613D6  050000013a              add      eax, 0x3a010000                
  0x010613DB  0000                    add      byte ptr [eax], al             
  0x010613DD  003c00                  add      byte ptr [eax + eax], bh       
  0x010613E0  c00805                  ror      byte ptr [eax], 5              
  0x010613E3  00560c                  add      byte ptr [esi + 0xc], dl       
  0x010613E6  050000003a              add      eax, 0x3a000000                
  0x010613EB  0000                    add      byte ptr [eax], al             
  0x010613ED  003c00                  add      byte ptr [eax + eax], bh       
  0x010613F0  9c                      pushfd                                  
  0x010613F1  080500520c05            or       byte ptr [0x50c5200], al       
  0x010613F7  0000                    add      byte ptr [eax], al             
  0x010613F9  f4                      hlt                                     
  0x010613FA  61                      popal                                   
  0x010613FB  00ab01000003            add      byte ptr [ebx + 0x3000001], ch 
  0x01061401  0c05                    or       al, 5                          
  0x01061403  0000                    add      byte ptr [eax], al             
  0x01061405  f4                      hlt                                     
  0x01061406  61                      popal                                   
  0x01061407  00af01000010            add      byte ptr [edi + 0x10000001], ch 
  0x0106140D  d806                    fadd     dword ptr [esi]                
  0x0106140F  000400                  add      byte ptr [eax + eax], al       
  0x01061412  0000                    add      byte ptr [eax], al             
  0x01061414  00d8                    add      al, bl                         
  0x01061416  44                      inc      esp                            
  0x01061417  00845907000000          add      byte ptr [ecx + ebx*2 + 7], al 
  0x0106141E  0000                    add      byte ptr [eax], al             
  0x01061420  47                      inc      edi                            
  0x01061421  0c05                    or       al, 5                          
  0x01061423  0000                    add      byte ptr [eax], al             
  0x01061425  003a                    add      byte ptr [edx], bh             
  0x01061427  0000                    add      byte ptr [eax], al             
  0x01061429  013c00                  add      dword ptr [eax + eax], edi     
  0x0106142C  0000                    add      byte ptr [eax], al             
  0x0106142E  3d008c0805              cmp      eax, 0x5088c00                 
  0x01061433  00420c                  add      byte ptr [edx + 0xc], al       
  0x01061436  050000003a              add      eax, 0x3a000000                
  0x0106143B  0000                    add      byte ptr [eax], al             
  0x0106143D  003c00                  add      byte ptr [eax + eax], bh       
  0x01061440  8808                    mov      byte ptr [eax], cl             
  0x01061442  05001e0c05              add      eax, 0x50c1e00                 
  0x01061447  002402                  add      byte ptr [edx + eax], ah       
  0x0106144A  0000                    add      byte ptr [eax], al             
  0x0106144C  2e0200                  add      al, byte ptr cs:[eax]          
  0x0106144F  004a02                  add      byte ptr [edx + 2], cl         
  0x01061452  0000                    add      byte ptr [eax], al             
  0x01061454  55                      push     ebp                            
  0x01061455  0200                    add      al, byte ptr [eax]             
  0x01061457  006002                  add      byte ptr [eax + 2], ah         
  0x0106145A  0000                    add      byte ptr [eax], al             
  0x0106145C  6b0200                  imul     eax, dword ptr [edx], 0        
  0x0106145F  008d40010008            add      byte ptr [ebp + 0x8000140], cl 
  0x01061465  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01061466  050000bc21              add      eax, 0x21bc0000                
  0x0106146B  0000                    add      byte ptr [eax], al             
  0x0106146D  f4                      hlt                                     
  0x0106146E  6400f1                  add      cl, dh                         
  0x01061471  0100                    add      dword ptr [eax], eax           
  0x01061473  0000                    add      byte ptr [eax], al             
  0x01061475  49                      dec      ecx                            
  0x01061476  2000                    and      byte ptr [eax], al             
  0x01061478  96                      xchg     esi, eax                       
  0x01061479  ec                      in       al, dx                         
  0x0106147A  07                      pop      es                             
  0x0106147B  0080e60b000f            add      byte ptr [eax + 0xf000be6], al 
  0x01061481  0c05                    or       al, 5                          
  0x01061483  0000                    add      byte ptr [eax], al             
  0x01061485  0f2300                  mov      dr0, eax                       
  0x0106148A  07                      pop      es                             
  0x0106148B  009f01000084            add      byte ptr [edi - 0x7bffffff], bl 
  0x01061492  07                      pop      es                             
  0x01061493  009e01000014            add      byte ptr [esi + 0x14000001], bl 
  0x01061499  0020                    add      byte ptr [eax], ah             
  0x0106149B  000a                    add      byte ptr [edx], cl             
  0x0106149D  94                      xchg     esp, eax                       
  0x0106149E  0500485220              add      eax, 0x20524800                
  0x010614A3  00845a0700985a          add      byte ptr [edx + ebx*2 + 0x5a980007], al 
  0x010614AA  07                      pop      es                             
  0x010614AB  008c7007009f01          add      byte ptr [eax + esi*2 + 0x19f0007], cl 
  0x010614B2  0000                    add      byte ptr [eax], al             
  0x010614B4  8d7007                  lea      esi, [eax + 7]                 
  0x010614B7  009e01000013            add      byte ptr [esi + 0x13000001], bl 
  0x010614BD  0020                    add      byte ptr [eax], ah             
  0x010614BF  000c00                  add      byte ptr [eax + eax], cl       
  0x010614C2  0000                    add      byte ptr [eax], al             
  0x010614C4  00f4                    add      ah, dh                         
  0x010614C6  56                      push     esi                            
  0x010614C7  000400                  add      byte ptr [eax + eax], al       
  0x010614CA  0000                    add      byte ptr [eax], al             
  0x010614CC  0c00                    or       al, 0                          
  0x010614CE  0000                    add      byte ptr [eax], al             
  0x010614D0  84f0                    test     al, dh                         
  0x010614D2  07                      pop      es                             
  0x010614D3  0022                    add      byte ptr [edx], ah             
  0x010614D5  0100                    add      dword ptr [eax], eax           
  0x010614D7  00847007009e01          add      byte ptr [eax + esi*2 + 0x19e0007], al 
  0x010614DE  0000                    add      byte ptr [eax], al             
  0x010614E0  84f0                    test     al, dh                         
  0x010614E2  07                      pop      es                             
  0x010614E3  0023                    add      byte ptr [ebx], ah             
  0x010614E5  0100                    add      dword ptr [eax], eax           
  0x010614E7  00847007009f01          add      byte ptr [eax + esi*2 + 0x19f0007], al 
  0x010614EE  0000                    add      byte ptr [eax], al             
  0x010614F0  13f4                    adc      esi, esp                       
  0x010614F2  60                      pushal                                  
  0x010614F3  0022                    add      byte ptr [edx], ah             
  0x010614F5  0100                    add      dword ptr [eax], eax           
  0x010614F7  00901e060002            add      byte ptr [eax + 0x200061e], dl 
  0x010614FD  0000                    add      byte ptr [eax], al             
  0x010614FF  008e58070080            add      byte ptr [esi - 0x7ffff8a8], cl 
  0x01061505  100d00ce0000            adc      byte ptr [0xce00], cl          
  0x0106150B  00cc                    add      ah, cl                         
  0x0106150D  0f05                    syscall                                 
  0x0106150F  0000                    add      byte ptr [eax], al             
  0x01061511  f4                      hlt                                     
  0x01061512  6400a201000000          add      byte ptr fs:[edx + 1], ah      
  0x01061519  0c22                    or       al, 0x22                       
  0x0106151B  008040010000            add      byte ptr [eax + 0x140], al     
  0x01061521  90                      nop                                     
  0x01061522  2100                    and      dword ptr [eax], eax           
  0x01061524  80f00b                  xor      al, 0xb                        
  0x01061527  007602                  add      byte ptr [esi + 2], dh         
  0x0106152A  0000                    add      byte ptr [eax], al             
  0x0106152C  80f00b                  xor      al, 0xb                        
  0x0106152F  00e1                    add      cl, ah                         
  0x01061531  0200                    add      al, byte ptr [eax]             
  0x01061533  000c00                  add      byte ptr [eax + eax], cl       
  0x01061536  0000                    add      byte ptr [eax], al             
  0x01061538  00f4                    add      ah, dh                         
  0x0106153A  6400a201000000          add      byte ptr fs:[edx + 1], ah      
  0x01061541  0c22                    or       al, 0x22                       
  0x01061543  008040010000            add      byte ptr [eax + 0x140], al     
  0x01061549  90                      nop                                     
  0x0106154A  2100                    and      dword ptr [eax], eax           
  0x0106154C  80f00b                  xor      al, 0xb                        
  0x0106154F  008802000080            add      byte ptr [eax - 0x7ffffffe], cl 
  0x01061555  f00b00                  lock or  eax, dword ptr [eax]           
  0x01061558  e102                    loope    0x106155c                      
  0x0106155A  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01061558 (cond_jump)
  0x0106155C  0c00                    or       al, 0                          
  0x0106155E  0000                    add      byte ptr [eax], al             
  0x01061560  00f4                    add      ah, dh                         
  0x01061562  6400a201000000          add      byte ptr fs:[edx + 1], ah      
  0x01061569  0c22                    or       al, 0x22                       
  0x0106156B  008040010000            add      byte ptr [eax + 0x140], al     
  0x01061571  90                      nop                                     
  0x01061572  2100                    and      dword ptr [eax], eax           
  0x01061574  004e23                  add      byte ptr [esi + 0x23], cl      
  0x01061577  008540010042            add      byte ptr [ebp + 0x42000140], al 
  0x0106157D  100d00060000            adc      byte ptr [0x600], cl           
  0x01061583  0080f00b009a            add      byte ptr [eax - 0x65fff410], al 
  0x01061589  0200                    add      al, byte ptr [eax]             
  0x0106158B  00c0                    add      al, al                         
  0x0106158D  100d00040000            adc      byte ptr [0x400], cl           
  0x01061593  0080f00b00b1            add      byte ptr [eax - 0x4efff410], al 
  0x01061599  0200                    add      al, byte ptr [eax]             
  0x0106159B  0080f00b00e1            add      byte ptr [eax - 0x1efff410], al 
  0x010615A1  0200                    add      al, byte ptr [eax]             
  0x010615A3  000c00                  add      byte ptr [eax + eax], cl       
  0x010615A6  0000                    add      byte ptr [eax], al             
  0x010615A8  00f4                    add      ah, dh                         
  0x010615AA  6400a201000000          add      byte ptr fs:[edx + 1], ah      
  0x010615B1  0c22                    or       al, 0x22                       
  0x010615B3  00c0                    add      al, al                         
  0x010615B5  40                      inc      eax                            
  0x010615B6  0100                    add      dword ptr [eax], eax           
  0x010615B8  0018                    add      byte ptr [eax], bl             
  0x010615BA  0000                    add      byte ptr [eax], al             
  0x010615BC  0090210080f0            add      byte ptr [eax - 0xf7fffdf], dl 
  0x010615C2  0b00                    or       eax, dword ptr [eax]           
  0x010615C4  7602                    jbe      0x10615c8                      
  0x010615C6  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x010615C4 (cond_jump)
  0x010615C8  80f00b                  xor      al, 0xb                        
  0x010615CB  00e1                    add      cl, ah                         
  0x010615CD  0200                    add      al, byte ptr [eax]             
  0x010615CF  000c00                  add      byte ptr [eax + eax], cl       
  0x010615D2  0000                    add      byte ptr [eax], al             
  0x010615D4  00f4                    add      ah, dh                         
  0x010615D6  6400a201000000          add      byte ptr fs:[edx + 1], ah      
  0x010615DD  0c22                    or       al, 0x22                       
  0x010615DF  00c0                    add      al, al                         
  0x010615E1  40                      inc      eax                            
  0x010615E2  0100                    add      dword ptr [eax], eax           
  0x010615E4  0018                    add      byte ptr [eax], bl             
  0x010615E6  0000                    add      byte ptr [eax], al             
  0x010615E8  0090210080f0            add      byte ptr [eax - 0xf7fffdf], dl 
  0x010615EE  0b00                    or       eax, dword ptr [eax]           
  0x010615F0  8802                    mov      byte ptr [edx], al             
  0x010615F2  0000                    add      byte ptr [eax], al             
  0x010615F4  80f00b                  xor      al, 0xb                        
  0x010615F7  00e1                    add      cl, ah                         
  0x010615F9  0200                    add      al, byte ptr [eax]             
  0x010615FB  000c00                  add      byte ptr [eax + eax], cl       
  0x010615FE  0000                    add      byte ptr [eax], al             
  0x01061600  00f4                    add      ah, dh                         
  0x01061602  6400a201000000          add      byte ptr fs:[edx + 1], ah      
  0x01061609  0c22                    or       al, 0x22                       
  0x0106160B  00c0                    add      al, al                         
  0x0106160D  40                      inc      eax                            
  0x0106160E  0100                    add      dword ptr [eax], eax           
  0x01061610  0028                    add      byte ptr [eax], ch             
  0x01061612  0000                    add      byte ptr [eax], al             
  0x01061614  0090210080f0            add      byte ptr [eax - 0xf7fffdf], dl 
  0x0106161A  0b00                    or       eax, dword ptr [eax]           
  0x0106161C  7602                    jbe      0x1061620                      
  0x0106161E  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x0106161C (cond_jump)
  0x01061620  80f00b                  xor      al, 0xb                        
  0x01061623  00e1                    add      cl, ah                         
  0x01061625  0200                    add      al, byte ptr [eax]             
  0x01061627  000c00                  add      byte ptr [eax + eax], cl       
  0x0106162A  0000                    add      byte ptr [eax], al             
  0x0106162C  00f4                    add      ah, dh                         
  0x0106162E  6400a201000000          add      byte ptr fs:[edx + 1], ah      
  0x01061635  0c22                    or       al, 0x22                       
  0x01061637  00c0                    add      al, al                         
  0x01061639  40                      inc      eax                            
  0x0106163A  0100                    add      dword ptr [eax], eax           
  0x0106163C  0028                    add      byte ptr [eax], ch             
  0x0106163E  0000                    add      byte ptr [eax], al             
  0x01061640  0090210080f0            add      byte ptr [eax - 0xf7fffdf], dl 
  0x01061646  0b00                    or       eax, dword ptr [eax]           
  0x01061648  8802                    mov      byte ptr [edx], al             
  0x0106164A  0000                    add      byte ptr [eax], al             
  0x0106164C  80f00b                  xor      al, 0xb                        
  0x0106164F  00e1                    add      cl, ah                         
  0x01061651  0200                    add      al, byte ptr [eax]             
  0x01061653  000c00                  add      byte ptr [eax + eax], cl       
  0x01061656  0000                    add      byte ptr [eax], al             
  0x01061658  80f00b                  xor      al, 0xb                        
  0x0106165B  00d0                    add      al, dl                         
  0x0106165D  0200                    add      al, byte ptr [eax]             
  0x0106165F  0000                    add      byte ptr [eax], al             
  0x01061661  95                      xchg     ebp, eax                       
  0x01061662  2200                    and      al, byte ptr [eax]             
  0x01061664  008c2200c64001          add      byte ptr [edx + 0x140c600], cl 
  0x0106166B  00ff                    add      bh, bh                         
  0x0106166D  3f                      aas                                     
  0x0106166E  0000                    add      byte ptr [eax], al             
  0x01061670  c24001                  ret      0x140                          
  0x01061673  0000                    add      byte ptr [eax], al             
  0x01061675  40                      inc      eax                            
  0x01061676  0000                    add      byte ptr [eax], al             
  0x01061678  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x0106167B  0000                    add      byte ptr [eax], al             
  0x0106167D  f4                      hlt                                     
  0x0106167E  54                      push     esp                            
  0x0106167F  00e0                    add      al, ah                         
  0x01061681  5b                      pop      ebx                            
  0x01061682  0000                    add      byte ptr [eax], al             
  0x01061684  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x01061687  00985d070090            add      byte ptr [eax - 0x6ffff8a3], bl 
  0x0106168D  5d                      pop      ebp                            
  0x0106168E  07                      pop      es                             
  0x0106168F  0000                    add      byte ptr [eax], al             
  0x01061691  2e2200                  and      al, byte ptr cs:[eax]          
  0x01061694  841e                    test     byte ptr [esi], bl             
  0x01061696  0c00                    or       al, 0                          
  0x01061698  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x0106169B  000c00                  add      byte ptr [eax + eax], cl       
  0x0106169E  0000                    add      byte ptr [eax], al             
  0x010616A0  80f00b                  xor      al, 0xb                        
  0x010616A3  00d0                    add      al, dl                         
  0x010616A5  0200                    add      al, byte ptr [eax]             
  0x010616A7  0000                    add      byte ptr [eax], al             
  0x010616A9  95                      xchg     ebp, eax                       
  0x010616AA  2200                    and      al, byte ptr [eax]             
  0x010616AC  008c2200c64001          add      byte ptr [edx + 0x140c600], cl 
  0x010616B3  00ff                    add      bh, bh                         
  0x010616B5  3f                      aas                                     
  0x010616B6  0000                    add      byte ptr [eax], al             
  0x010616B8  c24001                  ret      0x140                          
  0x010616BB  0000                    add      byte ptr [eax], al             
  0x010616BD  40                      inc      eax                            
  0x010616BE  0000                    add      byte ptr [eax], al             
  0x010616C0  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x010616C3  0000                    add      byte ptr [eax], al             
  0x010616C5  f4                      hlt                                     
  0x010616C6  54                      push     esp                            
  0x010616C7  00e2                    add      dl, ah                         
  0x010616C9  5b                      pop      ebx                            
  0x010616CA  0000                    add      byte ptr [eax], al             
  0x010616CC  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x010616CF  00985d070090            add      byte ptr [eax - 0x6ffff8a3], bl 
  0x010616D5  5d                      pop      ebp                            
  0x010616D6  07                      pop      es                             
  0x010616D7  0000                    add      byte ptr [eax], al             
  0x010616D9  2e2200                  and      al, byte ptr cs:[eax]          
  0x010616DC  841e                    test     byte ptr [esi], bl             
  0x010616DE  0c00                    or       al, 0                          
  0x010616E0  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x010616E3  000c00                  add      byte ptr [eax + eax], cl       
  0x010616E6  0000                    add      byte ptr [eax], al             
  0x010616E8  80f00b                  xor      al, 0xb                        
  0x010616EB  00d0                    add      al, dl                         
  0x010616ED  0200                    add      al, byte ptr [eax]             
  0x010616EF  0000                    add      byte ptr [eax], al             
  0x010616F1  95                      xchg     ebp, eax                       
  0x010616F2  2200                    and      al, byte ptr [eax]             
  0x010616F4  008c2200c64001          add      byte ptr [edx + 0x140c600], cl 
  0x010616FB  00ff                    add      bh, bh                         
  0x010616FD  3f                      aas                                     
  0x010616FE  0000                    add      byte ptr [eax], al             
  0x01061700  c24001                  ret      0x140                          
  0x01061703  0000                    add      byte ptr [eax], al             
  0x01061705  40                      inc      eax                            
  0x01061706  0000                    add      byte ptr [eax], al             
  0x01061708  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x0106170B  0000                    add      byte ptr [eax], al             
  0x0106170D  f4                      hlt                                     
  0x0106170E  54                      push     esp                            
  0x0106170F  0002                    add      byte ptr [edx], al             
  0x01061711  46                      inc      esi                            
  0x01061712  0000                    add      byte ptr [eax], al             
  0x01061714  002f                    add      byte ptr [edi], ch             
  0x01061716  2200                    and      al, byte ptr [eax]             
  0x01061718  8b1e                    mov      ebx, dword ptr [esi]           
  0x0106171A  0c00                    or       al, 0                          
  0x0106171C  00e5                    add      ch, ah                         
  0x0106171E  2100                    and      dword ptr [eax], eax           
  0x01061720  6200                    bound    eax, qword ptr [eax]           
  0x01061722  2000                    and      byte ptr [eax], al             
  0x01061724  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x01061727  00985d070000            add      byte ptr [eax + 0x75d], bl     
  0x0106172D  8e23                    mov      fs, word ptr [ebx]             
  0x0106172F  009c1e0c000004          add      byte ptr [esi + ebx + 0x400000c], bl 
  0x01061736  2200                    and      al, byte ptr [eax]             
  0x01061738  40                      inc      eax                            
  0x01061739  0020                    add      byte ptr [eax], ah             
  0x0106173B  008c5d07000c00          add      byte ptr [ebp + ebx*2 + 0xc0007], cl 
  0x01061742  0000                    add      byte ptr [eax], al             
  0x01061744  80f00b                  xor      al, 0xb                        
  0x01061747  00d0                    add      al, dl                         
  0x01061749  0200                    add      al, byte ptr [eax]             
  0x0106174B  0000                    add      byte ptr [eax], al             
  0x0106174D  95                      xchg     ebp, eax                       
  0x0106174E  2200                    and      al, byte ptr [eax]             
  0x01061750  008c2200c64001          add      byte ptr [edx + 0x140c600], cl 
  0x01061757  00ff                    add      bh, bh                         
  0x01061759  3f                      aas                                     
  0x0106175A  0000                    add      byte ptr [eax], al             
  0x0106175C  c24001                  ret      0x140                          
  0x0106175F  0000                    add      byte ptr [eax], al             
  0x01061761  40                      inc      eax                            
  0x01061762  0000                    add      byte ptr [eax], al             
  0x01061764  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x01061767  0000                    add      byte ptr [eax], al             
  0x01061769  f4                      hlt                                     
  0x0106176A  54                      push     esp                            
  0x0106176B  0003                    add      byte ptr [ebx], al             
  0x0106176D  06                      push     es                             
  0x0106176E  0000                    add      byte ptr [eax], al             
  0x01061770  002f                    add      byte ptr [edi], ch             
  0x01061772  2200                    and      al, byte ptr [eax]             
  0x01061774  8b1e                    mov      ebx, dword ptr [esi]           
  0x01061776  0c00                    or       al, 0                          
  0x01061778  00e5                    add      ch, ah                         
  0x0106177A  2100                    and      dword ptr [eax], eax           
  0x0106177C  6200                    bound    eax, qword ptr [eax]           
  0x0106177E  2000                    and      byte ptr [eax], al             
  0x01061780  000f                    add      byte ptr [edi], cl             
  0x01061782  2300                    and      eax, dword ptr [eax]           
  0x01061784  9d                      popfd                                   
  0x01061785  1e                      push     ds                             
  0x01061786  0c00                    or       al, 0                          
  0x01061788  00e5                    add      ch, ah                         
  0x0106178A  2100                    and      dword ptr [eax], eax           
  0x0106178C  6200                    bound    eax, qword ptr [eax]           
  0x0106178E  2000                    and      byte ptr [eax], al             
  0x01061790  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x01061793  0000                    add      byte ptr [eax], al             
  0x01061795  0f2300                  mov      dr0, eax                       
  0x01061798  891e                    mov      dword ptr [esi], ebx           
  0x0106179A  0c00                    or       al, 0                          
  0x0106179C  004523                  add      byte ptr [ebp + 0x23], al      
  0x0106179F  006800                  add      byte ptr [eax], ch             
  0x010617A2  2000                    and      byte ptr [eax], al             
  0x010617A4  8d5d07                  lea      ebx, [ebp + 7]                 
  0x010617A7  0000                    add      byte ptr [eax], al             
  0x010617A9  8e23                    mov      fs, word ptr [ebx]             
  0x010617AB  009c1e0c000004          add      byte ptr [esi + ebx + 0x400000c], bl 
  0x010617B2  2200                    and      al, byte ptr [eax]             
  0x010617B4  40                      inc      eax                            
  0x010617B5  0020                    add      byte ptr [eax], ah             
  0x010617B7  008c5d07000c00          add      byte ptr [ebp + ebx*2 + 0xc0007], cl 
  0x010617BE  0000                    add      byte ptr [eax], al             
  0x010617C0  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010617C1  96                      xchg     esi, eax                       
  0x010617C2  0a00                    or       al, byte ptr [eax]             
  0x010617C4  d002                    rol      byte ptr [edx], 1              
  0x010617C6  0000                    add      byte ptr [eax], al             
  0x010617C8  85f4                    test     esp, esi                       
  0x010617CA  0800                    or       byte ptr [eax], al             
  0x010617CC  800000                  add      byte ptr [eax], 0              
  0x010617CF  000c00                  add      byte ptr [eax + eax], cl       
  0x010617D2  0000                    add      byte ptr [eax], al             
  0x010617D4  96                      xchg     esi, eax                       
  0x010617D5  f4                      hlt                                     
  0x010617D6  0800                    or       byte ptr [eax], al             
  0x010617D8  0100                    add      dword ptr [eax], eax           
  0x010617DA  0000                    add      byte ptr [eax], al             
  0x010617DC  84960a00d702            test     byte ptr [esi + 0x2d7000a], dl 
  0x010617E2  0000                    add      byte ptr [eax], al             
  0x010617E4  0c00                    or       al, 0                          
  0x010617E6  0000                    add      byte ptr [eax], al             
  0x010617E8  aa                      stosb    byte ptr es:[edi], al          
  0x010617E9  850a                    test     dword ptr [edx], ecx           
  0x010617EB  00fe                    add      dh, bh                         
  0x010617ED  0200                    add      al, byte ptr [eax]             
  0x010617EF  0087850a00da            add      byte ptr [edi - 0x25fff57b], al 
  0x010617F5  0200                    add      al, byte ptr [eax]             
  0x010617F7  0085f4080080            add      byte ptr [ebp - 0x7ffff70c], al 
  0x010617FD  0000                    add      byte ptr [eax], al             
  0x010617FF  000c00                  add      byte ptr [eax + eax], cl       
  0x01061802  0000                    add      byte ptr [eax], al             
  0x01061804  008e2200c040            add      byte ptr [esi + 0x40c00022], cl 
  0x0106180A  0100                    add      dword ptr [eax], eax           
  0x0106180C  0028                    add      byte ptr [eax], ch             
  0x0106180E  0000                    add      byte ptr [eax], al             
  0x01061810  14ce                    adc      al, 0xce                       
  0x01061812  0800                    or       byte ptr [eax], al             
  0x01061814  80f00b                  xor      al, 0xb                        
  0x01061817  00d5                    add      ch, dl                         
  0x01061819  0200                    add      al, byte ptr [eax]             
  0x0106181B  001b                    add      byte ptr [ebx], bl             
  0x0106181D  0020                    add      byte ptr [eax], ah             
  0x0106181F  0000                    add      byte ptr [eax], al             
  0x01061821  af                      scasd    eax, dword ptr es:[edi]        
  0x01061822  2300                    and      eax, dword ptr [eax]           
  0x01061824  8d4001                  lea      eax, [eax + 1]                 
  0x01061827  004a10                  add      byte ptr [edx + 0x10], cl      
  0x0106182A  0d00040000              or       eax, 0x400                     
  0x0106182F  0080f00b00da            add      byte ptr [eax - 0x25fff410], al 
  0x01061835  0200                    add      al, byte ptr [eax]             
  0x01061837  000c00                  add      byte ptr [eax + eax], cl       
  0x0106183A  0000                    add      byte ptr [eax], al             
  0x0106183C  85f4                    test     esp, esi                       
  0x0106183E  0800                    or       byte ptr [eax], al             
  0x01061840  ff0f                    dec      dword ptr [edi]                
  0x01061842  0000                    add      byte ptr [eax], al             
  0x01061844  84f4                    test     ah, dh                         
  0x01061846  0800                    or       byte ptr [eax], al             
  0x01061848  0100                    add      dword ptr [eax], eax           
  0x0106184A  0000                    add      byte ptr [eax], al             
  0x0106184C  8af4                    mov      dh, ah                         
  0x0106184E  0800                    or       byte ptr [eax], al             
  0x01061850  0000                    add      byte ptr [eax], al             
  0x01061852  0000                    add      byte ptr [eax], al             
  0x01061854  00f4                    add      ah, dh                         
  0x01061856  44                      inc      esp                            
  0x01061857  0000                    add      byte ptr [eax], al             
  0x01061859  40                      inc      eax                            
  0x0106185A  0000                    add      byte ptr [eax], al             
  0x0106185C  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106185F  00d5                    add      ch, dl                         
  0x01061862  ff00                    inc      dword ptr [eax]                
  0x01061864  007044                  add      byte ptr [eax + 0x44], dh      
  0x01061867  00d4                    add      ah, dl                         
  0x0106186A  ff00                    inc      dword ptr [eax]                
  0x0106186C  97                      xchg     edi, eax                       
  0x0106186D  f4                      hlt                                     
  0x0106186E  0800                    or       byte ptr [eax], al             
  0x01061870  0000                    add      byte ptr [eax], al             
  0x01061872  0000                    add      byte ptr [eax], al             
  0x01061874  0c00                    or       al, 0                          
  0x01061876  0000                    add      byte ptr [eax], al             
  0x01061878  000c0500000000          add      byte ptr [eax], cl             
  0x0106187F  00401b                  add      byte ptr [eax + 0x1b], al      
  0x01061882  d000                    rol      byte ptr [eax], 1              
  0x01061884  f20200                  add      al, byte ptr [eax]             
  0x01061887  007201                  add      byte ptr [edx + 1], dh         
  0x0106188A  0100                    add      dword ptr [eax], eax           
  0x0106188C  11f5                    adc      ebp, esi                       
  0x0106188E  f700400c0500            test     dword ptr [eax], 0x50c40       
  0x01061894  37                      aaa                                     
  0x01061895  0c04                    or       al, 4                          
  0x01061897  00a78a040084            add      byte ptr [edi - 0x7bfffb76], ah 
  0x0106189D  180500b1b705            sbb      byte ptr [0x5b7b100], al       
  0x010618A3  004a6a                  add      byte ptr [edx + 0x6a], cl      
  0x010618A6  06                      push     es                             
  0x010618A7  00ae32070085            add      byte ptr [esi - 0x7afff8ce], ch 
  0x010618AD  1308                    adc      ecx, dword ptr [eax]           
  0x010618AF  00cc                    add      ah, cl                         
  0x010618B1  0f09                    wbinvd                                  
  0x010618B3  00db                    add      bl, bl                         
  0x010618B5  2a0a                    sub      cl, byte ptr [edx]             
  0x010618B7  007368                  add      byte ptr [ebx + 0x68], dh      
  0x010618BA  0b00                    or       eax, dword ptr [eax]           
  0x010618BC  cdcc                    int      0xcc                           
  0x010618BE  0c00                    or       al, 0                          
  0x010618C0  a15c0e003f              mov      eax, dword ptr [0x3f000e5c]    
  0x010618C5  1d10009a14              sbb      eax, 0x149a0010                
  0x010618CA  1200                    adc      al, byte ptr [eax]             
  0x010618CC  61                      popal                                   
  0x010618CD  49                      dec      ecx                            
  0x010618CE  1400                    adc      al, 0                          
  0x010618D0  11c3                    adc      ebx, eax                       
  0x010618D2  16                      push     ss                             
  0x010618D3  0013                    add      byte ptr [ebx], dl             
  0x010618D5  8a19                    mov      bl, byte ptr [ecx]             
  0x010618D7  00d7                    add      bh, dl                         
  0x010618D9  a7                      cmpsd    dword ptr [esi], dword ptr es:[edi] 
  0x010618DA  1c00                    sbb      al, 0                          
  0x010618DC  f3262000                and      byte ptr es:[eax], al          
  0x010618E0  47                      inc      edi                            
  0x010618E1  132400                  adc      esp, dword ptr [eax + eax]     
  0x010618E4  27                      daa                                     
  0x010618E5  7a28                    jp       0x106190f                      
  0x010618E7  00866a2d002d            add      byte ptr [esi + 0x2d002d6a], al 
  0x010618ED  f5                      cmc                                     
  0x010618EE  3200                    xor      al, byte ptr [eax]             
  0x010618F0  ee                      out      dx, al                         
  0x010618F1  2c39                    sub      al, 0x39                       
  0x010618F3  00e7                    add      bh, ah                         
  0x010618F5  2640                    inc      eax                            
  0x010618F7  00cd                    add      ch, cl                         
  0x010618F9  fa                      cli                                     
  0x010618FA  47                      inc      edi                            
  0x010618FB  0036                    add      byte ptr [esi], dh             
  0x010618FD  c3                      ret                                     
  0x010618FE  50                      push     eax                            
  0x010618FF  00f8                    add      al, bh                         
  0x01061901  9d                      popfd                                   
  0x01061902  5a                      pop      edx                            
  0x01061903  008cac65008314          add      byte ptr [esp + ebp*4 + 0x14830065], cl 
  0x0106190A  7200                    jb       0x106190c                      
  0x0106190E  7f00                    jg       0x1061910                      
                                        ; XREF: 0x0106190E (cond_jump)
  0x01061910  007060                  add      byte ptr [eax + 0x60], dh      
  0x01061913  002e                    add      byte ptr [esi], ch             
  0x01061915  06                      push     es                             
  0x01061916  0000                    add      byte ptr [eax], al             
  0x01061918  0b00                    or       eax, dword ptr [eax]           
  0x0106191A  2000                    and      byte ptr [eax], al             
  0x0106191C  06                      push     es                             
  0x0106191D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106191E  050000f444              add      eax, 0x44f40000                
  0x01061923  0002                    add      byte ptr [edx], al             
  0x01061925  800000                  add      byte ptr [eax], 0              
  0x01061928  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106192B  000406                  add      byte ptr [esi + eax], al       
  0x0106192E  0000                    add      byte ptr [eax], al             
  0x01061930  050c050000              add      eax, 0x50c                     
  0x01061935  f4                      hlt                                     
  0x01061936  44                      inc      esp                            
  0x01061937  0002                    add      byte ptr [edx], al             
  0x01061939  0000                    add      byte ptr [eax], al             
  0x0106193B  0000                    add      byte ptr [eax], al             
  0x0106193D  7044                    jo       0x1061983                      
  0x0106193F  000406                  add      byte ptr [esi + eax], al       
  0x01061942  0000                    add      byte ptr [eax], al             
  0x01061944  00f4                    add      ah, dh                         
  0x01061946  44                      inc      esp                            
  0x01061947  000a                    add      byte ptr [edx], cl             
  0x01061949  0000                    add      byte ptr [eax], al             
  0x0106194B  0000                    add      byte ptr [eax], al             
  0x0106194D  7044                    jo       0x1061993                      
  0x0106194F  0000                    add      byte ptr [eax], al             
  0x01061951  06                      push     es                             
  0x01061952  0000                    add      byte ptr [eax], al             
  0x01061954  00f4                    add      ah, dh                         
  0x01061956  44                      inc      esp                            
  0x01061957  000a                    add      byte ptr [edx], cl             
  0x01061959  06                      push     es                             
  0x0106195A  0000                    add      byte ptr [eax], al             
  0x0106195C  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106195F  0001                    add      byte ptr [ecx], al             
  0x01061961  06                      push     es                             
  0x01061962  0000                    add      byte ptr [eax], al             
  0x01061964  00f4                    add      ah, dh                         
  0x01061966  44                      inc      esp                            
  0x01061967  0010                    add      byte ptr [eax], dl             
  0x01061969  06                      push     es                             
  0x0106196A  0000                    add      byte ptr [eax], al             
  0x0106196C  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106196F  0002                    add      byte ptr [edx], al             
  0x01061971  06                      push     es                             
  0x01061972  0000                    add      byte ptr [eax], al             
  0x01061974  00f4                    add      ah, dh                         
  0x01061976  44                      inc      esp                            
  0x01061977  0016                    add      byte ptr [esi], dl             
  0x01061979  06                      push     es                             
  0x0106197A  0000                    add      byte ptr [eax], al             
  0x0106197C  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106197F  0003                    add      byte ptr [ebx], al             
  0x01061981  06                      push     es                             
  0x01061982  0000                    add      byte ptr [eax], al             
  0x01061984  00f4                    add      ah, dh                         
  0x01061986  44                      inc      esp                            
  0x01061987  001c06                  add      byte ptr [esi + eax], bl       
  0x0106198A  0000                    add      byte ptr [eax], al             
  0x0106198C  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106198F  000506000000            add      byte ptr [6], al               
  0x01061995  f4                      hlt                                     
  0x01061996  44                      inc      esp                            
  0x01061997  0022                    add      byte ptr [edx], ah             
  0x01061999  06                      push     es                             
  0x0106199A  0000                    add      byte ptr [eax], al             
  0x0106199C  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106199F  0006                    add      byte ptr [esi], al             
  0x010619A1  06                      push     es                             
  0x010619A2  0000                    add      byte ptr [eax], al             
  0x010619A4  00f4                    add      ah, dh                         
  0x010619A6  44                      inc      esp                            
  0x010619A7  0028                    add      byte ptr [eax], ch             
  0x010619A9  06                      push     es                             
  0x010619AA  0000                    add      byte ptr [eax], al             
  0x010619AC  007044                  add      byte ptr [eax + 0x44], dh      
  0x010619AF  0007                    add      byte ptr [edi], al             
  0x010619B1  06                      push     es                             
  0x010619B2  0000                    add      byte ptr [eax], al             
  0x010619B4  00f4                    add      ah, dh                         
  0x010619B6  44                      inc      esp                            
  0x010619B7  0000                    add      byte ptr [eax], al             
  0x010619B9  0000                    add      byte ptr [eax], al             
  0x010619BB  0000                    add      byte ptr [eax], al             
  0x010619BD  7044                    jo       0x1061a03                      
  0x010619BF  0008                    add      byte ptr [eax], cl             
  0x010619C1  06                      push     es                             
  0x010619C2  0000                    add      byte ptr [eax], al             
  0x010619C4  00f4                    add      ah, dh                         
  0x010619C6  44                      inc      esp                            
  0x010619C7  0000                    add      byte ptr [eax], al             
  0x010619C9  0100                    add      dword ptr [eax], eax           
  0x010619CB  0000                    add      byte ptr [eax], al             
  0x010619CD  7044                    jo       0x1061a13                      
  0x010619CF  0009                    add      byte ptr [ecx], cl             
  0x010619D1  06                      push     es                             
  0x010619D2  0000                    add      byte ptr [eax], al             
  0x010619D4  00f4                    add      ah, dh                         
  0x010619D6  60                      pushal                                  
  0x010619D7  000a                    add      byte ptr [edx], cl             
  0x010619D9  06                      push     es                             
  0x010619DA  0000                    add      byte ptr [eax], al             
  0x010619DC  00f4                    add      ah, dh                         
  0x010619DE  44                      inc      esp                            
  0x010619DF  0000                    add      byte ptr [eax], al             
  0x010619E1  0000                    add      byte ptr [eax], al             
  0x010619E3  0000                    add      byte ptr [eax], al             
  0x010619E5  58                      pop      eax                            
  0x010619E6  44                      inc      esp                            
  0x010619E7  0000                    add      byte ptr [eax], al             
  0x010619E9  f4                      hlt                                     
  0x010619EA  44                      inc      esp                            
  0x010619EB  0000                    add      byte ptr [eax], al             
  0x010619ED  0100                    add      dword ptr [eax], eax           
  0x010619EF  0000                    add      byte ptr [eax], al             
  0x010619F1  58                      pop      eax                            
  0x010619F2  44                      inc      esp                            
  0x010619F3  0000                    add      byte ptr [eax], al             
  0x010619F5  f4                      hlt                                     
  0x010619F6  44                      inc      esp                            
  0x010619F7  0000                    add      byte ptr [eax], al             
  0x010619F9  0200                    add      al, byte ptr [eax]             
  0x010619FB  0000                    add      byte ptr [eax], al             
  0x010619FD  58                      pop      eax                            
  0x010619FE  44                      inc      esp                            
  0x010619FF  0000                    add      byte ptr [eax], al             
  0x01061A01  f4                      hlt                                     
  0x01061A02  44                      inc      esp                            
                                        ; XREF: 0x010619BD (cond_jump)
  0x01061A03  0000                    add      byte ptr [eax], al             
  0x01061A05  0300                    add      eax, dword ptr [eax]           
  0x01061A07  0000                    add      byte ptr [eax], al             
  0x01061A09  58                      pop      eax                            
  0x01061A0A  44                      inc      esp                            
  0x01061A0B  0000                    add      byte ptr [eax], al             
  0x01061A0D  f4                      hlt                                     
  0x01061A0E  44                      inc      esp                            
  0x01061A0F  0000                    add      byte ptr [eax], al             
  0x01061A11  0400                    add      al, 0                          
                                        ; XREF: 0x010619CD (cond_jump)
  0x01061A13  0000                    add      byte ptr [eax], al             
  0x01061A15  58                      pop      eax                            
  0x01061A16  44                      inc      esp                            
  0x01061A17  0000                    add      byte ptr [eax], al             
  0x01061A19  f4                      hlt                                     
  0x01061A1A  44                      inc      esp                            
  0x01061A1B  00ff                    add      bh, bh                         
  0x01061A1E  ff00                    inc      dword ptr [eax]                
  0x01061A20  006044                  add      byte ptr [eax + 0x44], ah      
  0x01061A23  0000                    add      byte ptr [eax], al             
  0x01061A25  f4                      hlt                                     
  0x01061A26  60                      pushal                                  
  0x01061A27  0010                    add      byte ptr [eax], dl             
  0x01061A29  06                      push     es                             
  0x01061A2A  0000                    add      byte ptr [eax], al             
  0x01061A2C  00f4                    add      ah, dh                         
  0x01061A2E  44                      inc      esp                            
  0x01061A2F  0001                    add      byte ptr [ecx], al             
  0x01061A31  0000                    add      byte ptr [eax], al             
  0x01061A33  0000                    add      byte ptr [eax], al             
  0x01061A35  58                      pop      eax                            
  0x01061A36  44                      inc      esp                            
  0x01061A37  0000                    add      byte ptr [eax], al             
  0x01061A39  58                      pop      eax                            
  0x01061A3A  44                      inc      esp                            
  0x01061A3B  0000                    add      byte ptr [eax], al             
  0x01061A3D  58                      pop      eax                            
  0x01061A3E  44                      inc      esp                            
  0x01061A3F  0000                    add      byte ptr [eax], al             
  0x01061A41  58                      pop      eax                            
  0x01061A42  44                      inc      esp                            
  0x01061A43  0000                    add      byte ptr [eax], al             
  0x01061A45  58                      pop      eax                            
  0x01061A46  44                      inc      esp                            
  0x01061A47  0000                    add      byte ptr [eax], al             
  0x01061A49  002400                  add      byte ptr [eax + eax], ah       
  0x01061A4C  006044                  add      byte ptr [eax + 0x44], ah      
  0x01061A4F  0000                    add      byte ptr [eax], al             
  0x01061A51  f4                      hlt                                     
  0x01061A52  60                      pushal                                  
  0x01061A53  0016                    add      byte ptr [esi], dl             
  0x01061A55  06                      push     es                             
  0x01061A56  0000                    add      byte ptr [eax], al             
  0x01061A58  00f4                    add      ah, dh                         
  0x01061A5A  44                      inc      esp                            
  0x01061A5B  00ff                    add      bh, bh                         
  0x01061A5E  ff00                    inc      dword ptr [eax]                
  0x01061A60  005844                  add      byte ptr [eax + 0x44], bl      
  0x01061A63  0000                    add      byte ptr [eax], al             
  0x01061A65  58                      pop      eax                            
  0x01061A66  44                      inc      esp                            
  0x01061A67  0000                    add      byte ptr [eax], al             
  0x01061A69  58                      pop      eax                            
  0x01061A6A  44                      inc      esp                            
  0x01061A6B  0000                    add      byte ptr [eax], al             
  0x01061A6D  58                      pop      eax                            
  0x01061A6E  44                      inc      esp                            
  0x01061A6F  0000                    add      byte ptr [eax], al             
  0x01061A71  58                      pop      eax                            
  0x01061A72  44                      inc      esp                            
  0x01061A73  0000                    add      byte ptr [eax], al             
  0x01061A75  60                      pushal                                  
  0x01061A76  44                      inc      esp                            
  0x01061A77  0000                    add      byte ptr [eax], al             
  0x01061A79  f4                      hlt                                     
  0x01061A7A  60                      pushal                                  
  0x01061A7B  001c06                  add      byte ptr [esi + eax], bl       
  0x01061A7E  0000                    add      byte ptr [eax], al             
  0x01061A80  00f4                    add      ah, dh                         
  0x01061A82  44                      inc      esp                            
  0x01061A83  0000                    add      byte ptr [eax], al             
  0x01061A85  0400                    add      al, 0                          
  0x01061A87  0000                    add      byte ptr [eax], al             
  0x01061A89  58                      pop      eax                            
  0x01061A8A  44                      inc      esp                            
  0x01061A8B  0000                    add      byte ptr [eax], al             
  0x01061A8D  f4                      hlt                                     
  0x01061A8E  44                      inc      esp                            
  0x01061A8F  00ff                    add      bh, bh                         
  0x01061A92  ff00                    inc      dword ptr [eax]                
  0x01061A94  005844                  add      byte ptr [eax + 0x44], bl      
  0x01061A97  0000                    add      byte ptr [eax], al             
  0x01061A99  f4                      hlt                                     
  0x01061A9A  44                      inc      esp                            
  0x01061A9B  0000                    add      byte ptr [eax], al             
  0x01061A9D  0500000058              add      eax, 0x58000000                
  0x01061AA2  44                      inc      esp                            
  0x01061AA3  0000                    add      byte ptr [eax], al             
  0x01061AA5  f4                      hlt                                     
  0x01061AA6  44                      inc      esp                            
  0x01061AA7  00ff                    add      bh, bh                         
  0x01061AAA  ff00                    inc      dword ptr [eax]                
  0x01061AAC  005844                  add      byte ptr [eax + 0x44], bl      
  0x01061AAF  0000                    add      byte ptr [eax], al             
  0x01061AB1  f4                      hlt                                     
  0x01061AB2  44                      inc      esp                            
  0x01061AB3  00ff                    add      bh, bh                         
  0x01061AB6  ff00                    inc      dword ptr [eax]                
  0x01061AB8  005844                  add      byte ptr [eax + 0x44], bl      
  0x01061ABB  0000                    add      byte ptr [eax], al             
  0x01061ABD  f4                      hlt                                     
  0x01061ABE  44                      inc      esp                            
  0x01061ABF  00ff                    add      bh, bh                         
  0x01061AC2  ff00                    inc      dword ptr [eax]                
  0x01061AC4  005844                  add      byte ptr [eax + 0x44], bl      
  0x01061AC7  0000                    add      byte ptr [eax], al             
  0x01061AC9  f4                      hlt                                     
  0x01061ACA  60                      pushal                                  
  0x01061ACB  0022                    add      byte ptr [edx], ah             
  0x01061ACD  06                      push     es                             
  0x01061ACE  0000                    add      byte ptr [eax], al             
  0x01061AD0  00f4                    add      ah, dh                         
  0x01061AD2  44                      inc      esp                            
  0x01061AD3  0001                    add      byte ptr [ecx], al             
  0x01061AD5  0000                    add      byte ptr [eax], al             
  0x01061AD7  0000                    add      byte ptr [eax], al             
  0x01061AD9  58                      pop      eax                            
  0x01061ADA  44                      inc      esp                            
  0x01061ADB  0000                    add      byte ptr [eax], al             
  0x01061ADD  002400                  add      byte ptr [eax + eax], ah       
  0x01061AE0  005844                  add      byte ptr [eax + 0x44], bl      
  0x01061AE3  0000                    add      byte ptr [eax], al             
  0x01061AE5  f4                      hlt                                     
  0x01061AE6  44                      inc      esp                            
  0x01061AE7  0001                    add      byte ptr [ecx], al             
  0x01061AE9  0000                    add      byte ptr [eax], al             
  0x01061AEB  0000                    add      byte ptr [eax], al             
  0x01061AED  58                      pop      eax                            
  0x01061AEE  44                      inc      esp                            
  0x01061AEF  0000                    add      byte ptr [eax], al             
  0x01061AF1  002400                  add      byte ptr [eax + eax], ah       
  0x01061AF4  005844                  add      byte ptr [eax + 0x44], bl      
  0x01061AF7  0000                    add      byte ptr [eax], al             
  0x01061AF9  002400                  add      byte ptr [eax + eax], ah       
  0x01061AFC  005844                  add      byte ptr [eax + 0x44], bl      
  0x01061AFF  0000                    add      byte ptr [eax], al             
  0x01061B01  002400                  add      byte ptr [eax + eax], ah       
  0x01061B04  005844                  add      byte ptr [eax + 0x44], bl      
  0x01061B07  0000                    add      byte ptr [eax], al             
  0x01061B09  f4                      hlt                                     
  0x01061B0A  60                      pushal                                  
  0x01061B0B  0028                    add      byte ptr [eax], ch             
  0x01061B0D  06                      push     es                             
  0x01061B0E  0000                    add      byte ptr [eax], al             
  0x01061B10  00f4                    add      ah, dh                         
  0x01061B12  44                      inc      esp                            
  0x01061B13  00ff                    add      bh, bh                         
  0x01061B16  ff00                    inc      dword ptr [eax]                
  0x01061B18  005844                  add      byte ptr [eax + 0x44], bl      
  0x01061B1B  0000                    add      byte ptr [eax], al             
  0x01061B1D  58                      pop      eax                            
  0x01061B1E  44                      inc      esp                            
  0x01061B1F  0000                    add      byte ptr [eax], al             
  0x01061B21  58                      pop      eax                            
  0x01061B22  44                      inc      esp                            
  0x01061B23  0000                    add      byte ptr [eax], al             
  0x01061B25  58                      pop      eax                            
  0x01061B26  44                      inc      esp                            
  0x01061B27  0000                    add      byte ptr [eax], al             
  0x01061B29  58                      pop      eax                            
  0x01061B2A  44                      inc      esp                            
  0x01061B2B  0000                    add      byte ptr [eax], al             
  0x01061B2D  58                      pop      eax                            
  0x01061B2E  44                      inc      esp                            
  0x01061B2F  0000                    add      byte ptr [eax], al             
  0x01061B31  f4                      hlt                                     
  0x01061B32  56                      push     esi                            
  0x01061B33  0007                    add      byte ptr [edi], al             
  0x01061B35  0000                    add      byte ptr [eax], al             
  0x01061B37  0000                    add      byte ptr [eax], al             
  0x01061B39  f4                      hlt                                     
  0x01061B3A  60                      pushal                                  
  0x01061B3B  0000                    add      byte ptr [eax], al             
  0x01061B3D  0000                    add      byte ptr [eax], al             
  0x01061B3F  0000                    add      byte ptr [eax], al             
  0x01061B41  f4                      hlt                                     
  0x01061B42  7000                    jo       0x1061b44                      
                                        ; XREF: 0x01061B42 (cond_jump)
  0x01061B44  0001                    add      byte ptr [ecx], al             
  0x01061B46  0000                    add      byte ptr [eax], al             
  0x01061B48  0000                    add      byte ptr [eax], al             
  0x01061B4A  3900                    cmp      dword ptr [eax], eax           
  0x01061B4C  80010d                  add      byte ptr [ecx], 0xd            
  0x01061B4F  0000                    add      byte ptr [eax], al             
  0x01061B51  f4                      hlt                                     
  0x01061B52  56                      push     esi                            
  0x01061B53  0007                    add      byte ptr [edi], al             
  0x01061B55  0000                    add      byte ptr [eax], al             
  0x01061B57  0000                    add      byte ptr [eax], al             
  0x01061B59  f4                      hlt                                     
  0x01061B5A  60                      pushal                                  
  0x01061B5B  0000                    add      byte ptr [eax], al             
  0x01061B5D  0100                    add      dword ptr [eax], eax           
  0x01061B5F  0000                    add      byte ptr [eax], al             
  0x01061B61  f4                      hlt                                     
  0x01061B62  7000                    jo       0x1061b64                      
                                        ; XREF: 0x01061B62 (cond_jump)
  0x01061B64  0001                    add      byte ptr [ecx], al             
  0x01061B66  0000                    add      byte ptr [eax], al             
  0x01061B68  0001                    add      byte ptr [ecx], al             
  0x01061B6A  3900                    cmp      dword ptr [eax], eax           
  0x01061B6C  80010d                  add      byte ptr [ecx], 0xd            
  0x01061B6F  0000                    add      byte ptr [eax], al             
  0x01061B71  f4                      hlt                                     
  0x01061B72  56                      push     esi                            
  0x01061B73  0007                    add      byte ptr [edi], al             
  0x01061B75  0000                    add      byte ptr [eax], al             
  0x01061B77  0000                    add      byte ptr [eax], al             
  0x01061B79  f4                      hlt                                     
  0x01061B7A  60                      pushal                                  
  0x01061B7B  0000                    add      byte ptr [eax], al             
  0x01061B7D  0200                    add      al, byte ptr [eax]             
  0x01061B7F  0000                    add      byte ptr [eax], al             
  0x01061B81  f4                      hlt                                     
  0x01061B82  7000                    jo       0x1061b84                      
                                        ; XREF: 0x01061B82 (cond_jump)
  0x01061B84  0001                    add      byte ptr [ecx], al             
  0x01061B86  0000                    add      byte ptr [eax], al             
  0x01061B88  0002                    add      byte ptr [edx], al             
  0x01061B8A  3900                    cmp      dword ptr [eax], eax           
  0x01061B8C  80010d                  add      byte ptr [ecx], 0xd            
  0x01061B8F  0000                    add      byte ptr [eax], al             
  0x01061B91  f4                      hlt                                     
  0x01061B92  56                      push     esi                            
  0x01061B93  0007                    add      byte ptr [edi], al             
  0x01061B95  0000                    add      byte ptr [eax], al             
  0x01061B97  0000                    add      byte ptr [eax], al             
  0x01061B99  f4                      hlt                                     
  0x01061B9A  60                      pushal                                  
  0x01061B9B  0000                    add      byte ptr [eax], al             
  0x01061B9D  0300                    add      eax, dword ptr [eax]           
  0x01061B9F  0000                    add      byte ptr [eax], al             
  0x01061BA1  f4                      hlt                                     
  0x01061BA2  7000                    jo       0x1061ba4                      
                                        ; XREF: 0x01061BA2 (cond_jump)
  0x01061BA4  0001                    add      byte ptr [ecx], al             
  0x01061BA6  0000                    add      byte ptr [eax], al             
  0x01061BA8  0003                    add      byte ptr [ebx], al             
  0x01061BAA  3900                    cmp      dword ptr [eax], eax           
  0x01061BAC  80010d                  add      byte ptr [ecx], 0xd            
  0x01061BAF  0000                    add      byte ptr [eax], al             
  0x01061BB1  f4                      hlt                                     
  0x01061BB2  56                      push     esi                            
  0x01061BB3  0007                    add      byte ptr [edi], al             
  0x01061BB5  0000                    add      byte ptr [eax], al             
  0x01061BB7  0000                    add      byte ptr [eax], al             
  0x01061BB9  f4                      hlt                                     
  0x01061BBA  60                      pushal                                  
  0x01061BBB  0000                    add      byte ptr [eax], al             
  0x01061BBD  0400                    add      al, 0                          
  0x01061BBF  0000                    add      byte ptr [eax], al             
  0x01061BC1  f4                      hlt                                     
  0x01061BC2  7000                    jo       0x1061bc4                      
                                        ; XREF: 0x01061BC2 (cond_jump)
  0x01061BC4  0001                    add      byte ptr [ecx], al             
  0x01061BC6  0000                    add      byte ptr [eax], al             
  0x01061BC8  000439                  add      byte ptr [ecx + edi], al       
  0x01061BCB  0080010d0013            add      byte ptr [eax + 0x13000d01], al 
  0x01061BD2  6200                    bound    eax, qword ptr [eax]           
  0x01061BD4  2e06                    push     es                             
  0x01061BD6  0000                    add      byte ptr [eax], al             
  0x01061BD8  dc1a                    fcomp    qword ptr [edx]                
  0x01061BDA  0200                    add      al, byte ptr [eax]             
  0x01061BDC  00f4                    add      ah, dh                         
  0x01061BDE  44                      inc      esp                            
  0x01061BDF  0001                    add      byte ptr [ecx], al             
  0x01061BE1  0000                    add      byte ptr [eax], al             
  0x01061BE3  004500                  add      byte ptr [ebp], al             
  0x01061BE6  2000                    and      byte ptr [eax], al             
  0x01061BE8  41                      inc      ecx                            
  0x01061BE9  2920                    sub      dword ptr [eax], esp           
  0x01061BEB  0000                    add      byte ptr [eax], al             
  0x01061BED  f4                      hlt                                     
  0x01061BEE  44                      inc      esp                            
  0x01061BEF  001f                    add      byte ptr [edi], bl             
  0x01061BF1  0000                    add      byte ptr [eax], al             
  0x01061BF3  004500                  add      byte ptr [ebp], al             
  0x01061BF6  2000                    and      byte ptr [eax], al             
  0x01061BF8  41                      inc      ecx                            
  0x01061BF9  27                      daa                                     
  0x01061BFA  2000                    and      byte ptr [eax], al             
  0x01061BFC  0098210000f4            add      byte ptr [eax - 0xbffffdf], bl 
  0x01061C02  60                      pushal                                  
  0x01061C03  000503000085            add      byte ptr [0x85000003], al      
  0x01061C09  e807009708              call     0x99d1c15                      
  0x01061C0E  050013f460              add      eax, 0x60f41300                
  0x01061C13  0000                    add      byte ptr [eax], al             
  0x01061C15  06                      push     es                             
  0x01061C16  0000                    add      byte ptr [eax], al             
  0x01061C18  00f4                    add      ah, dh                         
  0x01061C1A  57                      push     edi                            
  0x01061C1B  0016                    add      byte ptr [esi], dl             
  0x01061C1D  0000                    add      byte ptr [eax], al             
  0x01061C1F  0080100d005b            add      byte ptr [eax + 0x5b000d10], al 
  0x01061C25  0000                    add      byte ptr [eax], al             
  0x01061C27  0013                    add      byte ptr [ebx], dl             
  0x01061C29  f4                      hlt                                     
  0x01061C2A  6200                    bound    eax, qword ptr [eax]           
  0x01061C2C  000400                  add      byte ptr [eax + eax], al       
  0x01061C2F  001b                    add      byte ptr [ebx], bl             
  0x01061C31  0020                    add      byte ptr [eax], ah             
  0x01061C33  009100060005            add      byte ptr [ecx + 0x5000600], dl 
  0x01061C39  0000                    add      byte ptr [eax], al             
  0x01061C3B  0000                    add      byte ptr [eax], al             
  0x01061C3D  da44008a                fiadd    dword ptr [eax + eax - 0x76]   
  0x01061C41  0020                    add      byte ptr [eax], ah             
  0x01061C43  004700                  add      byte ptr [edi], al             
  0x01061C46  2000                    and      byte ptr [eax], al             
  0x01061C48  40                      inc      eax                            
  0x01061C49  90                      nop                                     
  0x01061C4A  0200                    add      al, byte ptr [eax]             
  0x01061C4C  260020                  add      byte ptr es:[eax], ah          
  0x01061C4F  00911c0c0000            add      byte ptr [ecx + 0xc1c], dl     
  0x01061C55  7056                    jo       0x1061cad                      
  0x01061C57  002f                    add      byte ptr [edi], ch             
  0x01061C59  06                      push     es                             
  0x01061C5A  0000                    add      byte ptr [eax], al             
  0x01061C5C  00a721000026            add      byte ptr [edi + 0x26000021], ah 
  0x01061C62  2100                    and      dword ptr [eax], eax           
  0x01061C64  13402f                  adc      eax, dword ptr [eax + 0x2f]    
  0x01061C67  009017060009            add      byte ptr [eax + 0x9000617], dl 
  0x01061C6D  0000                    add      byte ptr [eax], al             
  0x01061C6F  0010                    add      byte ptr [eax], dl             
  0x01061C71  c521                    lds      esp, ptr [ecx]                 
  0x01061C73  0000                    add      byte ptr [eax], al             
  0x01061C75  0000                    add      byte ptr [eax], al             
  0x01061C77  0000                    add      byte ptr [eax], al             
  0x01061C79  c421                    les      esp, ptr [ecx]                 
  0x01061C7B  00840020003000          add      byte ptr [eax + eax + 0x300020], al 
  0x01061C82  2000                    and      byte ptr [eax], al             
  0x01061C84  00ae20001021            add      byte ptr [esi + 0x21100020], ch 
  0x01061C8A  2000                    and      byte ptr [eax], al             
  0x01061C8C  2a00                    sub      al, byte ptr [eax]             
  0x01061C8E  2000                    and      byte ptr [eax], al             
  0x01061C90  007056                  add      byte ptr [eax + 0x56], dh      
  0x01061C93  0031                    add      byte ptr [ecx], dh             
  0x01061C95  06                      push     es                             
  0x01061C96  0000                    add      byte ptr [eax], al             
  0x01061C98  13f4                    adc      esi, esp                       
  0x01061C9A  6200                    bound    eax, qword ptr [eax]           
  0x01061C9C  000500001b00            add      byte ptr [0x1b0000], al        
  0x01061CA2  2000                    and      byte ptr [eax], al             
  0x01061CA4  91                      xchg     ecx, eax                       
  0x01061CA5  0006                    add      byte ptr [esi], al             
  0x01061CA7  000500000000            add      byte ptr [0], al               
                                        ; XREF: 0x01061C55 (cond_jump)
  0x01061CAD  da44008a                fiadd    dword ptr [eax + eax - 0x76]   
  0x01061CB1  0020                    add      byte ptr [eax], ah             
  0x01061CB3  004700                  add      byte ptr [edi], al             
  0x01061CB6  2000                    and      byte ptr [eax], al             
  0x01061CB8  40                      inc      eax                            
  0x01061CB9  90                      nop                                     
  0x01061CBA  0200                    add      al, byte ptr [eax]             
  0x01061CBC  260020                  add      byte ptr es:[eax], ah          
  0x01061CBF  00911c0c0000            add      byte ptr [ecx + 0xc1c], dl     
  0x01061CC5  7056                    jo       0x1061d1d                      
  0x01061CC7  0030                    add      byte ptr [eax], dh             
  0x01061CC9  06                      push     es                             
  0x01061CCA  0000                    add      byte ptr [eax], al             
  0x01061CCC  00a721000026            add      byte ptr [edi + 0x26000021], ah 
  0x01061CD2  2100                    and      dword ptr [eax], eax           
  0x01061CD4  13402f                  adc      eax, dword ptr [eax + 0x2f]    
  0x01061CD7  009017060009            add      byte ptr [eax + 0x9000617], dl 
  0x01061CDD  0000                    add      byte ptr [eax], al             
  0x01061CDF  0010                    add      byte ptr [eax], dl             
  0x01061CE1  c521                    lds      esp, ptr [ecx]                 
  0x01061CE3  0000                    add      byte ptr [eax], al             
  0x01061CE5  0000                    add      byte ptr [eax], al             
  0x01061CE7  0000                    add      byte ptr [eax], al             
  0x01061CE9  c421                    les      esp, ptr [ecx]                 
  0x01061CEB  00840020003000          add      byte ptr [eax + eax + 0x300020], al 
  0x01061CF2  2000                    and      byte ptr [eax], al             
  0x01061CF4  00ae20001021            add      byte ptr [esi + 0x21100020], ch 
  0x01061CFA  2000                    and      byte ptr [eax], al             
  0x01061CFC  2a00                    sub      al, byte ptr [eax]             
  0x01061CFE  2000                    and      byte ptr [eax], al             
  0x01061D00  007056                  add      byte ptr [eax + 0x56], dh      
  0x01061D03  0032                    add      byte ptr [edx], dh             
  0x01061D05  06                      push     es                             
  0x01061D06  0000                    add      byte ptr [eax], al             
  0x01061D08  00f4                    add      ah, dh                         
  0x01061D0A  56                      push     esi                            
  0x01061D0B  0008                    add      byte ptr [eax], cl             
  0x01061D0D  0000                    add      byte ptr [eax], al             
  0x01061D0F  0000                    add      byte ptr [eax], al             
  0x01061D11  f4                      hlt                                     
  0x01061D12  60                      pushal                                  
  0x01061D13  0000                    add      byte ptr [eax], al             
  0x01061D15  0400                    add      al, 0                          
  0x01061D17  0000                    add      byte ptr [eax], al             
  0x01061D19  f4                      hlt                                     
  0x01061D1A  7000                    jo       0x1061d1c                      
                                        ; XREF: 0x01061D1A (cond_jump)
  0x01061D1C  0001                    add      byte ptr [ecx], al             
  0x01061D1E  0000                    add      byte ptr [eax], al             
  0x01061D20  0000                    add      byte ptr [eax], al             
  0x01061D22  3900                    cmp      dword ptr [eax], eax           
  0x01061D24  80010d                  add      byte ptr [ecx], 0xd            
  0x01061D27  0000                    add      byte ptr [eax], al             
  0x01061D29  f4                      hlt                                     
  0x01061D2A  56                      push     esi                            
  0x01061D2B  0008                    add      byte ptr [eax], cl             
  0x01061D2D  0000                    add      byte ptr [eax], al             
  0x01061D2F  0000                    add      byte ptr [eax], al             
  0x01061D31  f4                      hlt                                     
  0x01061D32  60                      pushal                                  
  0x01061D33  0000                    add      byte ptr [eax], al             
  0x01061D35  05000000f4              add      eax, 0xf4000000                
  0x01061D3A  7000                    jo       0x1061d3c                      
                                        ; XREF: 0x01061D3A (cond_jump)
  0x01061D3C  0001                    add      byte ptr [ecx], al             
  0x01061D3E  0000                    add      byte ptr [eax], al             
  0x01061D40  0001                    add      byte ptr [ecx], al             
  0x01061D42  3900                    cmp      dword ptr [eax], eax           
  0x01061D44  80010d                  add      byte ptr [ecx], 0xd            
  0x01061D47  0000                    add      byte ptr [eax], al             
  0x01061D49  f4                      hlt                                     
  0x01061D4A  56                      push     esi                            
  0x01061D4B  000f                    add      byte ptr [edi], cl             
  0x01061D4D  0000                    add      byte ptr [eax], al             
  0x01061D4F  0000                    add      byte ptr [eax], al             
  0x01061D51  f4                      hlt                                     
  0x01061D52  60                      pushal                                  
  0x01061D53  002f                    add      byte ptr [edi], ch             
  0x01061D55  06                      push     es                             
  0x01061D56  0000                    add      byte ptr [eax], al             
  0x01061D58  000438                  add      byte ptr [eax + edi], al       
  0x01061D5B  0000                    add      byte ptr [eax], al             
  0x01061D5D  0039                    add      byte ptr [ecx], bh             
  0x01061D5F  0080010d000c            add      byte ptr [eax + 0xc000d01], al 
  0x01061D65  0000                    add      byte ptr [eax], al             
  0x01061D67  0000                    add      byte ptr [eax], al             
  0x01061D69  f4                      hlt                                     
  0x01061D6A  60                      pushal                                  
  0x01061D6B  0000                    add      byte ptr [eax], al             
  0x01061D6D  0000                    add      byte ptr [eax], al             
  0x01061D6F  009280060005            add      byte ptr [edx + 0x5000680], dl 
  0x01061D75  0000                    add      byte ptr [eax], al             
  0x01061D77  0000                    add      byte ptr [eax], al             
  0x01061D79  d84400a1                fadd     dword ptr [eax + eax - 0x5f]   
  0x01061D7D  d04600                  rol      byte ptr [esi], 1              
  0x01061D80  e958560000              jmp      0x10673dd                      
  0x01061D85  58                      pop      eax                            
  0x01061D86  57                      push     edi                            
  0x01061D87  000c00                  add      byte ptr [eax + eax], cl       
  0x01061D8A  0000                    add      byte ptr [eax], al             
  0x01061D8C  20f4                    and      ah, dh                         
  0x01061D8E  0500ffffff              add      eax, 0xffffff00                
  0x01061D93  00a0610400a0            add      byte ptr [eax - 0x5ffffb9f], ah 
  0x01061D99  620400                  bound    eax, qword ptr [eax + eax]     
  0x01061D9C  a0640400a0              mov      al, byte ptr [0xa0000464]      
  0x01061DA1  650400                  add      al, 0                          
  0x01061DA4  a0660400b8              mov      al, byte ptr [0xb8000466]      
  0x01061DA9  f30000                  add      byte ptr [eax], al             
  0x01061DAC  00f4                    add      ah, dh                         
  0x01061DAE  44                      inc      esp                            
  0x01061DAF  0016                    add      byte ptr [esi], dl             
  0x01061DB1  0000                    add      byte ptr [eax], al             
  0x01061DB3  004d00                  add      byte ptr [ebp], cl             
  0x01061DB6  2000                    and      byte ptr [eax], al             
  0x01061DB8  4a                      dec      edx                            
  0x01061DB9  100d00080000            adc      byte ptr [0x800], cl           
  0x01061DBF  0000                    add      byte ptr [eax], al             
  0x01061DC1  0030                    add      byte ptr [eax], dh             
  0x01061DC3  0000                    add      byte ptr [eax], al             
  0x01061DC5  f4                      hlt                                     
  0x01061DC6  56                      push     esi                            
  0x01061DC7  0000                    add      byte ptr [eax], al             
  0x01061DC9  0000                    add      byte ptr [eax], al             
  0x01061DCB  0000                    add      byte ptr [eax], al             
  0x01061DCD  f4                      hlt                                     
  0x01061DCE  57                      push     edi                            
  0x01061DCF  00ff                    add      bh, bh                         
  0x01061DD2  ff00                    inc      dword ptr [eax]                
  0x01061DD4  0c00                    or       al, 0                          
  0x01061DD6  0000                    add      byte ptr [eax], al             
  0x01061DD8  80100d                  adc      byte ptr [eax], 0xd            
  0x01061DDB  00b800000000            add      byte ptr [eax], bh             
  0x01061DE2  56                      push     esi                            
  0x01061DE3  0036                    add      byte ptr [esi], dh             
  0x01061DE5  06                      push     es                             
  0x01061DE6  0000                    add      byte ptr [eax], al             
  0x01061DE8  0300                    add      eax, dword ptr [eax]           
  0x01061DEA  2000                    and      byte ptr [eax], al             
  0x01061DEC  06                      push     es                             
  0x01061DED  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01061DEE  050080100d              add      eax, 0xd108000                 
  0x01061DF3  005001                  add      byte ptr [eax + 1], dl         
  0x01061DF6  0000                    add      byte ptr [eax], al             
  0x01061DF8  80100d                  adc      byte ptr [eax], 0xd            
  0x01061DFB  002f                    add      byte ptr [edi], ch             
  0x01061DFD  0100                    add      dword ptr [eax], eax           
  0x01061DFF  0003                    add      byte ptr [ebx], al             
  0x01061E01  0c05                    or       al, 5                          
  0x01061E03  0080100d0053            add      byte ptr [eax + 0x53000d10], al 
  0x01061E09  0100                    add      dword ptr [eax], eax           
  0x01061E0B  0080100d0030            add      byte ptr [eax + 0x30000d10], al 
  0x01061E11  0100                    add      dword ptr [eax], eax           
  0x01061E13  0000                    add      byte ptr [eax], al             
  0x01061E16  56                      push     esi                            
  0x01061E17  0037                    add      byte ptr [edi], dh             
  0x01061E19  06                      push     es                             
  0x01061E1A  0000                    add      byte ptr [eax], al             
  0x01061E1C  854001                  test     dword ptr [eax + 1], eax       
  0x01061E1F  0017                    add      byte ptr [edi], dl             
  0x01061E21  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01061E22  050000f066              add      eax, 0x66f00000                
  0x01061E27  0033                    add      byte ptr [ebx], dh             
  0x01061E29  06                      push     es                             
  0x01061E2A  0000                    add      byte ptr [eax], al             
  0x01061E2C  0003                    add      byte ptr [ebx], al             
  0x01061E2E  3e0000                  add      byte ptr ds:[eax], al          
  0x01061E31  ee                      out      dx, al                         
  0x01061E32  60                      pushal                                  
  0x01061E33  0000                    add      byte ptr [eax], al             
  0x01061E35  043e                    add      al, 0x3e                       
  0x01061E37  0000                    add      byte ptr [eax], al             
  0x01061E39  ee                      out      dx, al                         
  0x01061E3A  61                      popal                                   
  0x01061E3B  0000                    add      byte ptr [eax], al             
  0x01061E3D  f066003406              lock add byte ptr [esi + eax], dh       
  0x01061E42  0000                    add      byte ptr [eax], al             
  0x01061E44  0003                    add      byte ptr [ebx], al             
  0x01061E46  3e0000                  add      byte ptr ds:[eax], al          
  0x01061E49  ee                      out      dx, al                         
  0x01061E4A  7000                    jo       0x1061e4c                      
                                        ; XREF: 0x01061E4A (cond_jump)
  0x01061E4C  00043e                  add      byte ptr [esi + edi], al       
  0x01061E4F  0000                    add      byte ptr [eax], al             
  0x01061E51  ee                      out      dx, al                         
  0x01061E52  7100                    jno      0x1061e54                      
                                        ; XREF: 0x01061E52 (cond_jump)
  0x01061E54  00f4                    add      ah, dh                         
  0x01061E56  46                      inc      esi                            
  0x01061E57  007a82                  add      byte ptr [edx - 0x7e], bh      
  0x01061E5A  5a                      pop      edx                            
  0x01061E5B  0000                    add      byte ptr [eax], al             
  0x01061E5E  6200                    bound    eax, qword ptr [eax]           
  0x01061E60  3c06                    cmp      al, 6                          
  0x01061E62  0000                    add      byte ptr [eax], al             
  0x01061E64  10d2                    adc      dl, dl                         
  0x01061E66  06                      push     es                             
  0x01061E67  000500000000            add      byte ptr [0], al               
  0x01061E6D  e044                    loopne   0x1061eb3                      
  0x01061E6F  00d0                    add      al, dl                         
  0x01061E71  c9                      leave                                   
  0x01061E72  44                      inc      esp                            
  0x01061E73  00d3                    add      bl, dl                         
  0x01061E75  0020                    add      byte ptr [eax], ah             
  0x01061E77  0000                    add      byte ptr [eax], al             
  0x01061E79  48                      dec      eax                            
  0x01061E7A  56                      push     esi                            
  0x01061E7B  0000                    add      byte ptr [eax], al             
  0x01061E7D  f0660033                lock add byte ptr [ebx], dh             
  0x01061E81  06                      push     es                             
  0x01061E82  0000                    add      byte ptr [eax], al             
  0x01061E84  0000                    add      byte ptr [eax], al             
  0x01061E86  3e0000                  add      byte ptr ds:[eax], al          
  0x01061E89  ee                      out      dx, al                         
  0x01061E8A  60                      pushal                                  
  0x01061E8B  0000                    add      byte ptr [eax], al             
  0x01061E8D  023e                    add      bh, byte ptr [esi]             
  0x01061E8F  0000                    add      byte ptr [eax], al             
  0x01061E91  ee                      out      dx, al                         
  0x01061E92  61                      popal                                   
  0x01061E93  0000                    add      byte ptr [eax], al             
  0x01061E95  013e                    add      dword ptr [esi], edi           
  0x01061E97  0000                    add      byte ptr [eax], al             
  0x01061E99  ee                      out      dx, al                         
  0x01061E9A  6200                    bound    eax, qword ptr [eax]           
  0x01061E9C  00f0                    add      al, dh                         
  0x01061E9E  660038                  add      byte ptr [eax], bh             
  0x01061EA1  06                      push     es                             
  0x01061EA2  0000                    add      byte ptr [eax], al             
  0x01061EA4  0000                    add      byte ptr [eax], al             
  0x01061EA6  3e0000                  add      byte ptr ds:[eax], al          
  0x01061EA9  ee                      out      dx, al                         
  0x01061EAA  640000                  add      byte ptr fs:[eax], al          
  0x01061EAD  023e                    add      bh, byte ptr [esi]             
  0x01061EAF  0000                    add      byte ptr [eax], al             
  0x01061EB1  ee                      out      dx, al                         
  0x01061EB2  650000                  add      byte ptr gs:[eax], al          
  0x01061EB5  f066003406              lock add byte ptr [esi + eax], dh       
  0x01061EBA  0000                    add      byte ptr [eax], al             
  0x01061EBC  0000                    add      byte ptr [eax], al             
  0x01061EBE  3e0000                  add      byte ptr ds:[eax], al          
  0x01061EC1  ee                      out      dx, al                         
  0x01061EC2  7000                    jo       0x1061ec4                      
                                        ; XREF: 0x01061EC2 (cond_jump)
  0x01061EC4  0002                    add      byte ptr [edx], al             
  0x01061EC6  3e0000                  add      byte ptr ds:[eax], al          
  0x01061EC9  ee                      out      dx, al                         
  0x01061ECA  7100                    jno      0x1061ecc                      
                                        ; XREF: 0x01061ECA (cond_jump)
  0x01061ECC  0001                    add      byte ptr [ecx], al             
  0x01061ECE  3e0000                  add      byte ptr ds:[eax], al          
  0x01061ED1  ee                      out      dx, al                         
  0x01061ED2  7200                    jb       0x1061ed4                      
                                        ; XREF: 0x01061ED2 (cond_jump)
  0x01061ED4  00f0                    add      al, dh                         
  0x01061ED6  660039                  add      byte ptr [ecx], bh             
  0x01061ED9  06                      push     es                             
  0x01061EDA  0000                    add      byte ptr [eax], al             
  0x01061EDC  0000                    add      byte ptr [eax], al             
  0x01061EDE  3e0000                  add      byte ptr ds:[eax], al          
  0x01061EE1  ee                      out      dx, al                         
  0x01061EE2  7400                    je       0x1061ee4                      
                                        ; XREF: 0x01061EE2 (cond_jump)
  0x01061EE4  00f4                    add      ah, dh                         
  0x01061EE6  7600                    jbe      0x1061ee8                      
                                        ; XREF: 0x01061EE6 (cond_jump)
  0x01061EE8  0200                    add      al, byte ptr [eax]             
  0x01061EEA  0000                    add      byte ptr [eax], al             
  0x01061EEC  00ee                    add      dh, ch                         
  0x01061EEE  7500                    jne      0x1061ef0                      
                                        ; XREF: 0x01061EEE (cond_jump)
  0x01061EF0  00f4                    add      ah, dh                         
  0x01061EF2  45                      inc      ebp                            
  0x01061EF3  007a82                  add      byte ptr [edx - 0x7e], bh      
  0x01061EF6  5a                      pop      edx                            
  0x01061EF7  0000                    add      byte ptr [eax], al             
  0x01061EF9  f066003c06              lock add byte ptr [esi + eax], bh       
  0x01061EFE  0000                    add      byte ptr [eax], al             
  0x01061F00  00d6                    add      dh, dl                         
  0x01061F02  06                      push     es                             
  0x01061F03  00a604000000            add      byte ptr [esi + 4], ah         
  0x01061F09  ca4400                  retf     0x44                           
  0x01061F0C  00c8                    add      al, cl                         
  0x01061F0E  56                      push     esi                            
  0x01061F0F  00a3c95700ab            add      byte ptr [ebx - 0x54ffa837], ah 
  0x01061F15  4c                      dec      esp                            
  0x01061F16  56                      push     esi                            
  0x01061F17  0000                    add      byte ptr [eax], al             
  0x01061F19  4d                      dec      ebp                            
  0x01061F1A  57                      push     edi                            
  0x01061F1B  0000                    add      byte ptr [eax], al             
  0x01061F1D  f4                      hlt                                     
  0x01061F1E  61                      popal                                   
  0x01061F1F  003d06000000            add      byte ptr [6], bh               
  0x01061F25  f065008b06000000        lock add byte ptr gs:[ebx + 6], cl      
  0x01061F2D  f4                      hlt                                     
  0x01061F2E  6200                    bound    eax, qword ptr [eax]           
  0x01061F30  7106                    jno      0x1061f38                      
  0x01061F32  0000                    add      byte ptr [eax], al             
  0x01061F34  00f0                    add      al, dh                         
  0x01061F36  660038                  add      byte ptr [eax], bh             
  0x01061F39  06                      push     es                             
  0x01061F3A  0000                    add      byte ptr [eax], al             
  0x01061F3C  0000                    add      byte ptr [eax], al             
  0x01061F3E  3e0000                  add      byte ptr ds:[eax], al          
  0x01061F41  ee                      out      dx, al                         
  0x01061F42  60                      pushal                                  
  0x01061F43  0000                    add      byte ptr [eax], al             
  0x01061F45  1422                    adc      al, 0x22                       
  0x01061F47  0000                    add      byte ptr [eax], al             
  0x01061F49  f0660039                lock add byte ptr [ecx], bh             
  0x01061F4D  06                      push     es                             
  0x01061F4E  0000                    add      byte ptr [eax], al             
  0x01061F50  00ee                    add      dh, ch                         
  0x01061F52  7000                    jo       0x1061f54                      
                                        ; XREF: 0x01061F52 (cond_jump)
  0x01061F54  001c23                  add      byte ptr [ebx], bl             
  0x01061F57  0000                    add      byte ptr [eax], al             
  0x01061F5A  50                      push     eax                            
  0x01061F5B  003c06                  add      byte ptr [esi + eax], bh       
  0x01061F5E  0000                    add      byte ptr [eax], al             
  0x01061F60  0a00                    or       al, byte ptr [eax]             
  0x01061F62  0000                    add      byte ptr [eax], al             
  0x01061F64  001e                    add      byte ptr [esi], bl             
  0x01061F66  2100                    and      dword ptr [eax], eax           
  0x01061F68  00f4                    add      ah, dh                         
  0x01061F6A  7200                    jb       0x1061f6c                      
                                        ; XREF: 0x01061F6A (cond_jump)
  0x01061F6C  0400                    add      al, 0                          
  0x01061F6E  0000                    add      byte ptr [eax], al             
  0x01061F70  80f00b                  xor      al, 0xb                        
  0x01061F73  00ca                    add      dl, cl                         
  0x01061F75  05000000f4              add      eax, 0xf4000000                
  0x01061F7A  61                      popal                                   
  0x01061F7B  004d06                  add      byte ptr [ebp + 6], cl         
  0x01061F7E  0000                    add      byte ptr [eax], al             
  0x01061F80  00f0                    add      al, dh                         
  0x01061F82  65008b06000000          add      byte ptr gs:[ebx + 6], cl      
  0x01061F89  f4                      hlt                                     
  0x01061F8A  6200                    bound    eax, qword ptr [eax]           
  0x01061F8C  7906                    jns      0x1061f94                      
  0x01061F8E  0000                    add      byte ptr [eax], al             
  0x01061F90  00f0                    add      al, dh                         
  0x01061F92  660038                  add      byte ptr [eax], bh             
  0x01061F95  06                      push     es                             
  0x01061F96  0000                    add      byte ptr [eax], al             
  0x01061F98  0002                    add      byte ptr [edx], al             
  0x01061F9A  3e0000                  add      byte ptr ds:[eax], al          
  0x01061F9D  ee                      out      dx, al                         
  0x01061F9E  60                      pushal                                  
  0x01061F9F  0000                    add      byte ptr [eax], al             
  0x01061FA1  1422                    adc      al, 0x22                       
  0x01061FA3  0000                    add      byte ptr [eax], al             
  0x01061FA5  f0660039                lock add byte ptr [ecx], bh             
  0x01061FA9  06                      push     es                             
  0x01061FAA  0000                    add      byte ptr [eax], al             
  0x01061FAC  00ee                    add      dh, ch                         
  0x01061FAE  7000                    jo       0x1061fb0                      
                                        ; XREF: 0x01061FAE (cond_jump)
  0x01061FB0  001c23                  add      byte ptr [ebx], bl             
  0x01061FB3  0000                    add      byte ptr [eax], al             
  0x01061FB6  50                      push     eax                            
  0x01061FB7  003c06                  add      byte ptr [esi + eax], bh       
  0x01061FBA  0000                    add      byte ptr [eax], al             
  0x01061FBC  0a00                    or       al, byte ptr [eax]             
  0x01061FBE  0000                    add      byte ptr [eax], al             
  0x01061FC0  001e                    add      byte ptr [esi], bl             
  0x01061FC2  2100                    and      dword ptr [eax], eax           
  0x01061FC4  00f4                    add      ah, dh                         
  0x01061FC6  7200                    jb       0x1061fc8                      
                                        ; XREF: 0x01061FC6 (cond_jump)
  0x01061FC8  0400                    add      al, 0                          
  0x01061FCA  0000                    add      byte ptr [eax], al             
  0x01061FCC  80f00b                  xor      al, 0xb                        
  0x01061FCF  00ca                    add      dl, cl                         
  0x01061FD1  05000000f4              add      eax, 0xf4000000                
  0x01061FD6  61                      popal                                   
  0x01061FD7  005d06                  add      byte ptr [ebp + 6], bl         
  0x01061FDA  0000                    add      byte ptr [eax], al             
  0x01061FDC  00f0                    add      al, dh                         
  0x01061FDE  65008c06000000f4        add      byte ptr gs:[esi + eax - 0xc000000], cl 
  0x01061FE6  6200                    bound    eax, qword ptr [eax]           
  0x01061FE8  8106000000f0            add      dword ptr [esi], 0xf0000000    
  0x01061FEE  660033                  add      byte ptr [ebx], dh             
  0x01061FF1  06                      push     es                             
  0x01061FF2  0000                    add      byte ptr [eax], al             
  0x01061FF4  0003                    add      byte ptr [ebx], al             
  0x01061FF6  3e0000                  add      byte ptr ds:[eax], al          
  0x01061FF9  ee                      out      dx, al                         
  0x01061FFA  60                      pushal                                  
  0x01061FFB  0000                    add      byte ptr [eax], al             
  0x01061FFD  1422                    adc      al, 0x22                       
  0x01061FFF  0000                    add      byte ptr [eax], al             
  0x01062001  f066003406              lock add byte ptr [esi + eax], dh       
  0x01062006  0000                    add      byte ptr [eax], al             
  0x01062008  00ee                    add      dh, ch                         
  0x0106200A  7000                    jo       0x106200c                      
                                        ; XREF: 0x0106200A (cond_jump)
  0x0106200C  001c23                  add      byte ptr [ebx], bl             
  0x0106200F  0000                    add      byte ptr [eax], al             
  0x01062012  50                      push     eax                            
  0x01062013  003c06                  add      byte ptr [esi + eax], bh       
  0x01062016  0000                    add      byte ptr [eax], al             
  0x01062018  0a00                    or       al, byte ptr [eax]             
  0x0106201A  0000                    add      byte ptr [eax], al             
  0x0106201C  001e                    add      byte ptr [esi], bl             
  0x0106201E  2100                    and      dword ptr [eax], eax           
  0x01062020  00f4                    add      ah, dh                         
  0x01062022  7200                    jb       0x1062024                      
                                        ; XREF: 0x01062022 (cond_jump)
  0x01062024  0500000080              add      eax, 0x80000000                
  0x01062029  f00b00                  lock or  eax, dword ptr [eax]           
  0x0106202C  ca0500                  retf     5                              
  0x0106202F  0000                    add      byte ptr [eax], al             
  0x01062031  f0660038                lock add byte ptr [eax], bh             
  0x01062035  06                      push     es                             
  0x01062036  0000                    add      byte ptr [eax], al             
  0x01062038  0000                    add      byte ptr [eax], al             
  0x0106203A  3e0000                  add      byte ptr ds:[eax], al          
  0x0106203D  ee                      out      dx, al                         
  0x0106203E  60                      pushal                                  
  0x0106203F  0000                    add      byte ptr [eax], al             
  0x01062041  023e                    add      bh, byte ptr [esi]             
  0x01062043  0000                    add      byte ptr [eax], al             
  0x01062045  ee                      out      dx, al                         
  0x01062046  61                      popal                                   
  0x01062047  0000                    add      byte ptr [eax], al             
  0x01062049  f0660033                lock add byte ptr [ebx], dh             
  0x0106204D  06                      push     es                             
  0x0106204E  0000                    add      byte ptr [eax], al             
  0x01062050  0003                    add      byte ptr [ebx], al             
  0x01062052  3e0000                  add      byte ptr ds:[eax], al          
  0x01062055  ee                      out      dx, al                         
  0x01062056  6200                    bound    eax, qword ptr [eax]           
  0x01062058  00f0                    add      al, dh                         
  0x0106205A  660039                  add      byte ptr [ecx], bh             
  0x0106205D  06                      push     es                             
  0x0106205E  0000                    add      byte ptr [eax], al             
  0x01062060  0000                    add      byte ptr [eax], al             
  0x01062062  3e0000                  add      byte ptr ds:[eax], al          
  0x01062065  ee                      out      dx, al                         
  0x01062066  7000                    jo       0x1062068                      
                                        ; XREF: 0x01062066 (cond_jump)
  0x01062068  0002                    add      byte ptr [edx], al             
  0x0106206A  3e0000                  add      byte ptr ds:[eax], al          
  0x0106206D  ee                      out      dx, al                         
  0x0106206E  7100                    jno      0x1062070                      
                                        ; XREF: 0x0106206E (cond_jump)
  0x01062070  00f0                    add      al, dh                         
  0x01062072  66003406                add      byte ptr [esi + eax], dh       
  0x01062076  0000                    add      byte ptr [eax], al             
  0x01062078  0003                    add      byte ptr [ebx], al             
  0x0106207A  3e0000                  add      byte ptr ds:[eax], al          
  0x0106207D  ee                      out      dx, al                         
  0x0106207E  7200                    jb       0x1062080                      
                                        ; XREF: 0x0106207E (cond_jump)
  0x01062080  00f4                    add      ah, dh                         
  0x01062082  45                      inc      ebp                            
  0x01062083  007a82                  add      byte ptr [edx - 0x7e], bh      
  0x01062086  5a                      pop      edx                            
  0x01062087  0000                    add      byte ptr [eax], al             
  0x01062089  f064003c06              lock add byte ptr fs:[esi + eax], bh    
  0x0106208E  0000                    add      byte ptr [eax], al             
  0x01062090  00d4                    add      ah, dl                         
  0x01062092  06                      push     es                             
  0x01062093  000a                    add      byte ptr [edx], cl             
  0x01062095  05000000ca              add      eax, 0xca000000                
  0x0106209A  44                      inc      esp                            
  0x0106209B  0000                    add      byte ptr [eax], al             
  0x0106209D  e056                    loopne   0x10620f5                      
  0x0106209F  00a3e15700af            add      byte ptr [ebx - 0x50ffa81f], ah 
  0x010620A5  48                      dec      eax                            
  0x010620A6  56                      push     esi                            
  0x010620A7  0000                    add      byte ptr [eax], al             
  0x010620A9  49                      dec      ecx                            
  0x010620AA  57                      push     edi                            
  0x010620AB  0080100d00b4            add      byte ptr [eax - 0x4bfff2f0], al 
  0x010620B1  0000                    add      byte ptr [eax], al             
  0x010620B3  000c00                  add      byte ptr [eax + eax], cl       
  0x010620B6  0000                    add      byte ptr [eax], al             
  0x010620B8  005820                  add      byte ptr [eax + 0x20], bl      
  0x010620BB  0000                    add      byte ptr [eax], al             
  0x010620BD  d8440000                fadd     dword ptr [eax + eax]          
  0x010620C1  7044                    jo       0x1062107                      
  0x010620C3  0033                    add      byte ptr [ebx], dh             
  0x010620C5  06                      push     es                             
  0x010620C6  0000                    add      byte ptr [eax], al             
  0x010620C8  00d8                    add      al, bl                         
  0x010620CA  44                      inc      esp                            
  0x010620CB  0000                    add      byte ptr [eax], al             
  0x010620CD  7044                    jo       0x1062113                      
  0x010620CF  003406                  add      byte ptr [esi + eax], dh       
  0x010620D2  0000                    add      byte ptr [eax], al             
  0x010620D4  00d8                    add      al, bl                         
  0x010620D6  44                      inc      esp                            
  0x010620D7  0000                    add      byte ptr [eax], al             
  0x010620D9  7044                    jo       0x106211f                      
  0x010620DB  003506000000            add      byte ptr [6], dh               
  0x010620E1  d85700                  fcom     dword ptr [edi]                
  0x010620E4  90                      nop                                     
  0x010620E5  180c00                  sbb      byte ptr [eax + eax], cl       
  0x010620E8  27                      daa                                     
  0x010620E9  1000                    adc      byte ptr [eax], al             
  0x010620EB  0000                    add      byte ptr [eax], al             
  0x010620ED  7050                    jo       0x106213f                      
  0x010620EF  0036                    add      byte ptr [esi], dh             
  0x010620F1  06                      push     es                             
  0x010620F2  0000                    add      byte ptr [eax], al             
  0x010620F4  90                      nop                                     
                                        ; XREF: 0x0106209D (cond_jump)
  0x010620F5  180c00                  sbb      byte ptr [eax + eax], cl       
  0x010620F8  1910                    sbb      dword ptr [eax], edx           
  0x010620FA  0000                    add      byte ptr [eax], al             
  0x010620FC  007050                  add      byte ptr [eax + 0x50], dh      
  0x010620FF  0037                    add      byte ptr [edi], dh             
  0x01062101  06                      push     es                             
  0x01062102  0000                    add      byte ptr [eax], al             
  0x01062104  00d8                    add      al, bl                         
  0x01062106  44                      inc      esp                            
                                        ; XREF: 0x010620C1 (cond_jump)
  0x01062107  0000                    add      byte ptr [eax], al             
  0x01062109  7044                    jo       0x106214f                      
  0x0106210B  0038                    add      byte ptr [eax], bh             
  0x0106210D  06                      push     es                             
  0x0106210E  0000                    add      byte ptr [eax], al             
  0x01062110  00d8                    add      al, bl                         
  0x01062112  44                      inc      esp                            
                                        ; XREF: 0x010620CD (cond_jump)
  0x01062113  0000                    add      byte ptr [eax], al             
  0x01062115  7044                    jo       0x106215b                      
  0x01062117  0039                    add      byte ptr [ecx], bh             
  0x01062119  06                      push     es                             
  0x0106211A  0000                    add      byte ptr [eax], al             
  0x0106211C  00d8                    add      al, bl                         
  0x0106211E  44                      inc      esp                            
                                        ; XREF: 0x010620D9 (cond_jump)
  0x0106211F  0000                    add      byte ptr [eax], al             
  0x01062121  7044                    jo       0x1062167                      
  0x01062123  003a                    add      byte ptr [edx], bh             
  0x01062125  06                      push     es                             
  0x01062126  0000                    add      byte ptr [eax], al             
  0x01062128  00d8                    add      al, bl                         
  0x0106212A  57                      push     edi                            
  0x0106212B  0090180c0024            add      byte ptr [eax + 0x24000c18], dl 
  0x01062131  2000                    and      byte ptr [eax], al             
  0x01062133  0000                    add      byte ptr [eax], al             
  0x01062135  7050                    jo       0x1062187                      
  0x01062137  003b                    add      byte ptr [ebx], bh             
  0x01062139  06                      push     es                             
  0x0106213A  0000                    add      byte ptr [eax], al             
  0x0106213C  00d8                    add      al, bl                         
  0x0106213E  44                      inc      esp                            
                                        ; XREF: 0x010620ED (cond_jump)
  0x0106213F  0000                    add      byte ptr [eax], al             
  0x01062141  7044                    jo       0x1062187                      
  0x01062143  003c06                  add      byte ptr [esi + eax], bh       
  0x01062146  0000                    add      byte ptr [eax], al             
  0x01062148  0c00                    or       al, 0                          
  0x0106214A  0000                    add      byte ptr [eax], al             
  0x0106214C  8d95c0000000            lea      edx, [ebp + 0xc0]              
  0x01062152  0000                    add      byte ptr [eax], al             
  0x01062154  e5d4                    in       eax, 0xd4                      
  0x01062156  7e00                    jle      0x1062158                      
                                        ; XREF: 0x01062156 (cond_jump)
  0x01062158  0000                    add      byte ptr [eax], al             
  0x0106215A  c00000                  rol      byte ptr [eax], 0              
  0x0106215D  0000                    add      byte ptr [eax], al             
  0x0106215F  004ae2                  add      byte ptr [edx - 0x1e], cl      
  0x01062162  4f                      dec      edi                            
  0x01062163  00cc                    add      ah, cl                         
  0x01062165  673f                    aas                                     
                                        ; XREF: 0x01062121 (cond_jump)
  0x01062167  00cc                    add      ah, cl                         
  0x01062169  673f                    aas                                     
  0x0106216B  004ae2                  add      byte ptr [edx - 0x1e], cl      
  0x0106216E  4f                      dec      edi                            
  0x0106216F  00ff                    add      bh, bh                         
  0x01062172  7f00                    jg       0x1062174                      
                                        ; XREF: 0x01062172 (cond_jump)
  0x01062174  e85b850038              call     0x3906a6d4                     
  0x01062179  667500                  jne      0x106217c                      
                                        ; XREF: 0x01062179 (cond_jump)
  0x0106217C  386675                  cmp      byte ptr [esi + 0x75], ah      
  0x0106217F  00e8                    add      al, ch                         
  0x01062181  5b                      pop      ebx                            
  0x01062182  8500                    test     dword ptr [eax], eax           
  0x01062186  7f00                    jg       0x1062188                      
                                        ; XREF: 0x01062186 (cond_jump)
  0x01062188  92                      xchg     edx, eax                       
  0x01062189  1f                      pop      ds                             
  0x0106218A  ea004b40e2004b          ljmp     0x4b00:0xe2404b00              
  0x01062191  40                      inc      eax                            
  0x01062192  e200                    loop     0x1062194                      
                                        ; XREF: 0x01062192 (cond_jump)
  0x01062194  92                      xchg     edx, eax                       
  0x01062195  1f                      pop      ds                             
  0x01062196  ea00ffff7f001b          ljmp     0x1b00:0x7fffff00              
  0x0106219D  2b810085ac7d            sub      eax, dword ptr [ecx + 0x7dac8500] 
  0x010621A3  0094d57e006c2a          add      byte ptr [ebp + edx*8 + 0x2a6c007e], dl 
  0x010621AA  810094d57e00            add      dword ptr [eax], 0x7ed594      
  0x010621B0  4a                      dec      edx                            
  0x010621B1  e24f                    loop     0x1062202                      
  0x010621B3  00cc                    add      ah, cl                         
  0x010621B5  673f                    aas                                     
  0x010621B7  0026                    add      byte ptr [esi], ah             
  0x010621B9  94                      xchg     esp, eax                       
  0x010621BA  57                      push     edi                            
  0x010621BB  007fff                  add      byte ptr [edi - 1], bh         
  0x010621BE  55                      push     ebp                            
  0x010621BF  0026                    add      byte ptr [esi], ah             
  0x010621C1  94                      xchg     esp, eax                       
  0x010621C2  57                      push     edi                            
  0x010621C3  004ae2                  add      byte ptr [edx - 0x1e], cl      
  0x010621C6  4f                      dec      edi                            
  0x010621C7  00cc                    add      ah, cl                         
  0x010621C9  673f                    aas                                     
  0x010621CB  0026                    add      byte ptr [esi], ah             
  0x010621CD  94                      xchg     esp, eax                       
  0x010621CE  57                      push     edi                            
  0x010621CF  007fff                  add      byte ptr [edi - 1], bh         
  0x010621D2  55                      push     ebp                            
  0x010621D3  0026                    add      byte ptr [esi], ah             
  0x010621D5  94                      xchg     esp, eax                       
  0x010621D6  57                      push     edi                            
  0x010621D7  0022                    add      byte ptr [edx], ah             
  0x010621D9  3e82006d                add      byte ptr ds:[eax], 0x6d        
  0x010621DD  877b00                  xchg     dword ptr [ebx], edi           
  0x010621E0  6d                      insd     dword ptr es:[edi], dx         
  0x010621E1  877b00                  xchg     dword ptr [ebx], edi           
  0x010621E4  223e                    and      bh, byte ptr [esi]             
  0x010621E6  8200ff                  add      byte ptr [eax], 0xff           
  0x010621EA  7f00                    jg       0x10621ec                      
                                        ; XREF: 0x010621EA (cond_jump)
  0x010621EC  5e                      pop      esi                            
  0x010621ED  3bb2004ff727            cmp      esi, dword ptr [edx + 0x27f74f00] 
  0x010621F3  004ff7                  add      byte ptr [edi - 9], cl         
  0x010621F6  27                      daa                                     
  0x010621F7  005e3b                  add      byte ptr [esi + 0x3b], bl      
  0x010621FA  b200                    mov      dl, 0                          
  0x010621FE  7f00                    jg       0x1062200                      
                                        ; XREF: 0x010621FE (cond_jump)
  0x01062200  7489                    je       0x106218b                      
                                        ; XREF: 0x010621B1 (cond_jump)
  0x01062202  c00000                  rol      byte ptr [eax], 0              
  0x01062205  0000                    add      byte ptr [eax], al             
  0x01062207  0019                    add      byte ptr [ecx], bl             
  0x01062209  ed                      in       eax, dx                        
  0x0106220A  7e00                    jle      0x106220c                      
                                        ; XREF: 0x0106220A (cond_jump)
  0x0106220C  0000                    add      byte ptr [eax], al             
  0x0106220E  c00000                  rol      byte ptr [eax], 0              
  0x01062211  0000                    add      byte ptr [eax], al             
  0x01062213  00f8                    add      al, bh                         
  0x01062215  2a4600                  sub      al, byte ptr [esi]             
  0x01062218  208637002086            and      byte ptr [esi - 0x79dfffc9], al 
  0x0106221E  37                      aaa                                     
  0x0106221F  00f8                    add      al, bh                         
  0x01062221  2a4600                  sub      al, byte ptr [esi]             
  0x01062226  7f00                    jg       0x1062228                      
                                        ; XREF: 0x01062226 (cond_jump)
  0x01062228  9e                      sahf                                    
  0x01062229  ef                      out      dx, eax                        
  0x0106222A  8400                    test     byte ptr [eax], al             
  0x0106222C  353a760035              xor      eax, 0x3500763a                
  0x01062231  3a7600                  cmp      dh, byte ptr [esi]             
  0x01062234  9e                      sahf                                    
  0x01062235  ef                      out      dx, eax                        
  0x01062236  8400                    test     byte ptr [eax], al             
  0x0106223A  7f00                    jg       0x106223c                      
                                        ; XREF: 0x0106223A (cond_jump)
  0x0106223C  fe48e6                  dec      byte ptr [eax - 0x1a]          
  0x0106223F  008ab7e4008a            add      byte ptr [edx - 0x75ff1b49], cl 
  0x01062245  b7e4                    mov      bh, 0xe4                       
  0x01062247  00fe                    add      dh, bh                         
  0x01062249  48                      dec      eax                            
  0x0106224A  e600                    out      0, al                          
  0x0106224E  7f00                    jg       0x1062250                      
                                        ; XREF: 0x0106224E (cond_jump)
  0x01062250  e712                    out      0x12, eax                      
  0x01062252  81007fdc7d00            add      dword ptr [eax], 0x7ddc7f      
  0x01062258  ac                      lodsb    al, byte ptr [esi]             
  0x01062259  ed                      in       eax, dx                        
  0x0106225A  7e00                    jle      0x106225c                      
                                        ; XREF: 0x0106225A (cond_jump)
  0x0106225C  54                      push     esp                            
  0x0106225D  128100aced7e            adc      al, byte ptr [ecx + 0x7eedac00] 
  0x01062263  00f8                    add      al, bh                         
  0x01062265  2a4600                  sub      al, byte ptr [esi]             
  0x01062268  20863700f31d            and      byte ptr [esi + 0x1df30037], al 
  0x0106226E  51                      push     ecx                            
  0x0106226F  0090f54e00f3            add      byte ptr [eax - 0xcffb10b], dl 
  0x01062275  1d5100f82a              sbb      eax, 0x2af80051                
  0x0106227A  46                      inc      esi                            
  0x0106227B  0020                    add      byte ptr [eax], ah             
  0x0106227D  8637                    xchg     byte ptr [edi], dh             
  0x0106227F  00f3                    add      bl, dh                         
  0x01062281  1d510090f5              sbb      eax, 0xf5900051                
  0x01062286  4e                      dec      esi                            
  0x01062287  00f3                    add      bl, dh                         
  0x01062289  1d51001a10              sbb      eax, 0x101a0051                
  0x0106228E  8200ed                  add      byte ptr [eax], 0xed           
  0x01062291  e27b                    loop     0x106230e                      
  0x01062293  00ed                    add      ch, ch                         
  0x01062295  e27b                    loop     0x1062312                      
  0x01062297  001a                    add      byte ptr [edx], bl             
  0x01062299  108200ffff7f            adc      byte ptr [edx + 0x7fffff00], al 
  0x0106229F  00fc                    add      ah, bh                         
  0x010622A1  2eaf                    scasd    eax, dword ptr es:[edi]        
  0x010622A3  0000                    add      byte ptr [eax], al             
  0x010622A5  782c                    js       0x10622d3                      
  0x010622A7  0000                    add      byte ptr [eax], al             
  0x010622A9  782c                    js       0x10622d7                      
  0x010622AB  00fc                    add      ah, bh                         
  0x010622AD  2eaf                    scasd    eax, dword ptr es:[edi]        
  0x010622AF  00ff                    add      bh, bh                         
  0x010622B2  7f00                    jg       0x10622b4                      
                                        ; XREF: 0x010622B2 (cond_jump)
  0x010622B4  13f4                    adc      esi, esp                       
  0x010622B6  61                      popal                                   
  0x010622B7  003d06000090            add      byte ptr [0x90000006], bh      
  0x010622BD  4e                      dec      esi                            
  0x010622BE  06                      push     es                             
  0x010622BF  0002                    add      byte ptr [edx], al             
  0x010622C1  0000                    add      byte ptr [eax], al             
  0x010622C3  0000                    add      byte ptr [eax], al             
  0x010622C5  59                      pop      ecx                            
  0x010622C6  56                      push     esi                            
  0x010622C7  000c00                  add      byte ptr [eax + eax], cl       
  0x010622CA  0000                    add      byte ptr [eax], al             
  0x010622CC  00f4                    add      ah, dh                         
  0x010622CE  60                      pushal                                  
  0x010622CF  0033                    add      byte ptr [ebx], dh             
  0x010622D1  05000000f4              add      eax, 0xf4000000                
  0x010622D6  61                      popal                                   
                                        ; XREF: 0x010622A9 (cond_jump)
  0x010622D7  0000                    add      byte ptr [eax], al             
  0x010622D9  0000                    add      byte ptr [eax], al             
  0x010622DB  00905a060003            add      byte ptr [eax + 0x300065a], dl 
  0x010622E1  0000                    add      byte ptr [eax], al             
  0x010622E3  0084d807000059          add      byte ptr [eax + ebx*8 + 0x59000007], al 
  0x010622EA  4c                      dec      esp                            
  0x010622EB  0000                    add      byte ptr [eax], al             
  0x010622EE  56                      push     esi                            
  0x010622EF  003b                    add      byte ptr [ebx], bh             
  0x010622F1  06                      push     es                             
  0x010622F2  0000                    add      byte ptr [eax], al             
  0x010622F4  0000                    add      byte ptr [eax], al             
  0x010622F6  2400                    and      al, 0                          
  0x010622F8  00f4                    add      ah, dh                         
  0x010622FA  60                      pushal                                  
  0x010622FB  002d00000045            add      byte ptr [0x45000000], ch      
  0x01062301  f4                      hlt                                     
  0x01062302  61                      popal                                   
  0x01062303  004100                  add      byte ptr [ecx], al             
  0x01062306  0000                    add      byte ptr [eax], al             
  0x01062308  05a4050000              add      eax, 0x5a4                     
  0x0106230D  f4                      hlt                                     
                                        ; XREF: 0x01062291 (cond_jump)
  0x0106230E  60                      pushal                                  
  0x0106230F  0000                    add      byte ptr [eax], al             
  0x01062311  0000                    add      byte ptr [eax], al             
  0x01062313  0000                    add      byte ptr [eax], al             
  0x01062315  f4                      hlt                                     
  0x01062316  61                      popal                                   
  0x01062317  001400                  add      byte ptr [eax + eax], dl       
  0x0106231A  0000                    add      byte ptr [eax], al             
  0x0106231C  007060                  add      byte ptr [eax + 0x60], dh      
  0x0106231F  008b06000000            add      byte ptr [ebx + 6], cl         
  0x01062325  7061                    jo       0x1062388                      
  0x01062327  008c0600000c00          add      byte ptr [esi + eax + 0xc0000], cl 
  0x0106232E  0000                    add      byte ptr [eax], al             
  0x01062330  00f4                    add      ah, dh                         
  0x01062332  56                      push     esi                            
  0x01062333  0011                    add      byte ptr [ecx], dl             
  0x01062335  0000                    add      byte ptr [eax], al             
  0x01062337  0000                    add      byte ptr [eax], al             
  0x01062339  f4                      hlt                                     
  0x0106233A  57                      push     edi                            
  0x0106233B  0000                    add      byte ptr [eax], al             
  0x0106233D  0000                    add      byte ptr [eax], al             
  0x0106233F  0000                    add      byte ptr [eax], al             
  0x01062341  4e                      dec      esi                            
  0x01062342  3800                    cmp      byte ptr [eax], al             
  0x01062344  80f00b                  xor      al, 0xb                        
  0x01062347  00800100000c            add      byte ptr [eax + 0xc000001], al 
  0x0106234D  0000                    add      byte ptr [eax], al             
  0x0106234F  0000                    add      byte ptr [eax], al             
  0x01062351  f4                      hlt                                     
  0x01062352  56                      push     esi                            
  0x01062353  0011                    add      byte ptr [ecx], dl             
  0x01062355  0000                    add      byte ptr [eax], al             
  0x01062357  0000                    add      byte ptr [eax], al             
  0x01062359  f4                      hlt                                     
  0x0106235A  57                      push     edi                            
  0x0106235B  0001                    add      byte ptr [ecx], al             
  0x0106235D  0000                    add      byte ptr [eax], al             
  0x0106235F  0000                    add      byte ptr [eax], al             
  0x01062361  f4                      hlt                                     
  0x01062362  60                      pushal                                  
  0x01062363  003d06000000            add      byte ptr [6], bh               
  0x01062369  4e                      dec      esi                            
  0x0106236A  3800                    cmp      byte ptr [eax], al             
  0x0106236C  0000                    add      byte ptr [eax], al             
  0x0106236E  3900                    cmp      dword ptr [eax], eax           
  0x01062370  80f00b                  xor      al, 0xb                        
  0x01062373  00800100000c            add      byte ptr [eax + 0xc000001], al 
  0x01062379  0000                    add      byte ptr [eax], al             
  0x0106237B  0000                    add      byte ptr [eax], al             
  0x0106237D  f4                      hlt                                     
  0x0106237E  56                      push     esi                            
  0x0106237F  0011                    add      byte ptr [ecx], dl             
  0x01062381  0000                    add      byte ptr [eax], al             
  0x01062383  0000                    add      byte ptr [eax], al             
  0x01062385  f4                      hlt                                     
  0x01062386  57                      push     edi                            
  0x01062387  0002                    add      byte ptr [edx], al             
  0x01062389  0000                    add      byte ptr [eax], al             
  0x0106238B  0000                    add      byte ptr [eax], al             
  0x0106238D  f4                      hlt                                     
  0x0106238E  60                      pushal                                  
  0x0106238F  003d06000000            add      byte ptr [6], bh               
  0x01062395  4e                      dec      esi                            
  0x01062396  3800                    cmp      byte ptr [eax], al             
  0x01062398  0000                    add      byte ptr [eax], al             
  0x0106239A  3900                    cmp      dword ptr [eax], eax           
  0x0106239C  80f00b                  xor      al, 0xb                        
  0x0106239F  00800100000c            add      byte ptr [eax + 0xc000001], al 
  0x010623A5  0000                    add      byte ptr [eax], al             
  0x010623A7  0000                    add      byte ptr [eax], al             
  0x010623A9  f4                      hlt                                     
  0x010623AA  7100                    jno      0x10623ac                      
  0x010623AE  ff00                    inc      dword ptr [eax]                
  0x010623B0  00f4                    add      ah, dh                         
  0x010623B2  7500                    jne      0x10623b4                      
                                        ; XREF: 0x010623B2 (cond_jump)
  0x010623B4  fc                      cld                                     
  0x010623B6  ff00                    inc      dword ptr [eax]                
  0x010623B8  0096220010da            add      byte ptr [esi - 0x25efffde], dl 
  0x010623BE  06                      push     es                             
  0x010623BF  0021                    add      byte ptr [ecx], ah             
  0x010623C1  0000                    add      byte ptr [eax], al             
  0x010623C3  0000                    add      byte ptr [eax], al             
  0x010623C5  da5700                  ficom    dword ptr [edi]                
  0x010623C8  00d2                    add      dl, dl                         
  0x010623CA  51                      push     ecx                            
  0x010623CB  0000                    add      byte ptr [eax], al             
  0x010623CD  b9f00010de              mov      ecx, 0xde1000f0                
  0x010623D2  06                      push     es                             
  0x010623D3  000b                    add      byte ptr [ebx], cl             
  0x010623D5  0000                    add      byte ptr [eax], al             
  0x010623D7  00d4                    add      ah, dl                         
  0x010623D9  e145                    loope    0x1062420                      
  0x010623DB  00d6                    add      dh, dl                         
  0x010623DD  39f0                    cmp      eax, esi                       
  0x010623DF  00e6                    add      dh, ah                         
  0x010623E1  a8f0                    test     al, 0xf0                       
  0x010623E3  00d2                    add      dl, dl                         
  0x010623E5  a1f400e259              mov      eax, dword ptr [0x59e200f4]    
  0x010623EA  44                      inc      esp                            
  0x010623EB  00e2                    add      dl, ah                         
  0x010623ED  a1d000d249              mov      eax, dword ptr [0x49d200d0]    
  0x010623F2  45                      inc      ebp                            
  0x010623F3  0010                    add      byte ptr [eax], dl             
  0x010623F5  0020                    add      byte ptr [eax], ah             
  0x010623F7  0009                    add      byte ptr [ecx], cl             
  0x010623F9  dd10                    fst      qword ptr [eax]                
  0x010623FB  004c4c44                add      byte ptr [esp + ecx*2 + 0x44], cl 
  0x010623FF  00d4                    add      ah, dl                         
  0x01062401  e145                    loope    0x1062448                      
  0x01062403  00d6                    add      dh, dl                         
  0x01062405  39f0                    cmp      eax, esi                       
  0x01062407  00e6                    add      dh, ah                         
  0x01062409  a8f0                    test     al, 0xf0                       
  0x0106240B  00d2                    add      dl, dl                         
  0x0106240D  a1f400e259              mov      eax, dword ptr [0x59e200f4]    
  0x01062412  44                      inc      esp                            
  0x01062413  00e2                    add      dl, ah                         
  0x01062415  a1f000d259              mov      eax, dword ptr [0x59d200f0]    
  0x0106241A  45                      inc      ebp                            
  0x0106241B  0010                    add      byte ptr [eax], dl             
  0x0106241D  0020                    add      byte ptr [eax], ah             
  0x0106241F  0009                    add      byte ptr [ecx], cl             
  0x01062421  c421                    les      esp, ptr [ecx]                 
  0x01062423  004c4c44                add      byte ptr [esp + ecx*2 + 0x44], cl 
  0x01062427  0084f10300005a          add      byte ptr [ecx + esi*8 + 0x5a000003], al 
  0x0106242E  55                      push     ebp                            
  0x0106242F  0000                    add      byte ptr [eax], al             
  0x01062431  5a                      pop      edx                            
  0x01062432  51                      push     ecx                            
  0x01062433  0000                    add      byte ptr [eax], al             
  0x01062435  d422                    aam      0x22                           
  0x01062437  0000                    add      byte ptr [eax], al             
  0x01062439  90                      nop                                     
  0x0106243A  2200                    and      al, byte ptr [eax]             
  0x0106243C  00982300a460            add      byte ptr [eax + 0x60a40023], bl 
  0x01062442  0400                    add      al, 0                          
  0x01062444  0c00                    or       al, 0                          
  0x01062446  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01062401 (cond_jump)
  0x01062448  40                      inc      eax                            
  0x01062449  1bd0                    sbb      edx, eax                       
  0x0106244B  006208                  add      byte ptr [edx + 8], ah         
  0x0106244E  0000                    add      byte ptr [eax], al             
  0x01062450  7201                    jb       0x1062453                      
  0x01062452  0200                    add      al, byte ptr [eax]             
  0x01062454  56                      push     esi                            
  0x01062455  6b680000                imul     ebp, dword ptr [eax], 0        
  0x01062459  7044                    jo       0x106249f                      
  0x0106245B  006509                  add      byte ptr [ebp + 9], ah         
  0x0106245E  0000                    add      byte ptr [eax], al             
  0x01062460  007060                  add      byte ptr [eax + 0x60], dh      
  0x01062463  006809                  add      byte ptr [eax + 9], ch         
  0x01062466  0000                    add      byte ptr [eax], al             
  0x01062468  0b00                    or       eax, dword ptr [eax]           
  0x0106246A  2000                    and      byte ptr [eax], al             
  0x0106246C  07                      pop      es                             
  0x0106246D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106246E  0500df0805              add      eax, 0x508df00                 
  0x01062473  0080100d00ce            add      byte ptr [eax - 0x31fff2f0], al 
  0x01062479  07                      pop      es                             
  0x0106247A  0000                    add      byte ptr [eax], al             
  0x0106247C  80100d                  adc      byte ptr [eax], 0xd            
  0x0106247F  000b                    add      byte ptr [ebx], cl             
  0x01062481  0800                    or       byte ptr [eax], al             
  0x01062483  00050c050080            add      byte ptr [0x8000050c], al      
  0x01062489  100d00d40700            adc      byte ptr [0x7d400], cl         
  0x0106248F  0080100d00f8            add      byte ptr [eax - 0x7fff2f0], al 
  0x01062495  07                      pop      es                             
  0x01062496  0000                    add      byte ptr [eax], al             
  0x01062499  08050000f062            or       byte ptr [0x62f00000], al      
                                        ; XREF: 0x01062459 (cond_jump)
  0x0106249F  006809                  add      byte ptr [eax + 9], ch         
  0x010624A2  0000                    add      byte ptr [eax], al             
  0x010624A4  00f4                    add      ah, dh                         
  0x010624A6  60                      pushal                                  
  0x010624A7  00c2                    add      dl, al                         
  0x010624A9  0f0000                  sldt     word ptr [eax]                 
  0x010624AC  d8720a                  fdiv     dword ptr [edx + 0xa]          
  0x010624AF  000500000000            add      byte ptr [0], al               
  0x010624B5  002400                  add      byte ptr [eax + eax], ah       
  0x010624B8  007044                  add      byte ptr [eax + 0x44], dh      
  0x010624BB  006609                  add      byte ptr [esi + 9], ah         
  0x010624BE  0000                    add      byte ptr [eax], al             
  0x010624C0  00e8                    add      al, ch                         
  0x010624C2  5e                      pop      esi                            
  0x010624C3  009f1a02000b            add      byte ptr [edi + 0xb00021a], bl 
  0x010624C9  0020                    add      byte ptr [eax], ah             
  0x010624CB  0002                    add      byte ptr [edx], al             
  0x010624CD  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010624CE  0500804101              add      eax, 0x1418000                 
  0x010624D3  0000                    add      byte ptr [eax], al             
  0x010624D5  7054                    jo       0x106252b                      
  0x010624D7  006709                  add      byte ptr [edi + 9], ah         
  0x010624DA  0000                    add      byte ptr [eax], al             
  0x010624DC  00f0                    add      al, dh                         
  0x010624DE  44                      inc      esp                            
  0x010624DF  006609                  add      byte ptr [esi + 9], ah         
  0x010624E2  0000                    add      byte ptr [eax], al             
  0x010624E4  52                      push     edx                            
  0x010624E5  090500110805            or       dword ptr [0x5081100], eax     
  0x010624EB  0000                    add      byte ptr [eax], al             
  0x010624EE  44                      inc      esp                            
  0x010624EF  006609                  add      byte ptr [esi + 9], ah         
  0x010624F2  0000                    add      byte ptr [eax], al             
  0x010624F4  80100d                  adc      byte ptr [eax], 0xd            
  0x010624F7  0002                    add      byte ptr [edx], al             
  0x010624F9  0800                    or       byte ptr [eax], al             
  0x010624FB  0000                    add      byte ptr [eax], al             
  0x010624FE  56                      push     esi                            
  0x010624FF  006609                  add      byte ptr [esi + 9], ah         
  0x01062502  0000                    add      byte ptr [eax], al             
  0x01062504  80410100                add      byte ptr [ecx + 1], 0          
  0x01062508  00f0                    add      al, dh                         
  0x0106250A  44                      inc      esp                            
  0x0106250B  006709                  add      byte ptr [edi + 9], ah         
  0x0106250E  0000                    add      byte ptr [eax], al             
  0x01062510  007054                  add      byte ptr [eax + 0x54], dh      
  0x01062513  006609                  add      byte ptr [esi + 9], ah         
  0x01062516  0000                    add      byte ptr [eax], al             
  0x01062518  45                      inc      ebp                            
  0x01062519  0020                    add      byte ptr [eax], ah             
  0x0106251B  00d0                    add      al, dl                         
  0x0106251D  97                      xchg     edi, eax                       
  0x0106251E  050080100d              add      eax, 0xd108000                 
  0x01062523  00bc0700000c00          add      byte ptr [edi + eax + 0xc0000], bh 
  0x0106252A  0000                    add      byte ptr [eax], al             
  0x0106252C  00f0                    add      al, dh                         
  0x0106252E  56                      push     esi                            
  0x0106252F  006609                  add      byte ptr [esi + 9], ah         
  0x01062532  0000                    add      byte ptr [eax], al             
  0x01062534  00f0                    add      al, dh                         
  0x01062536  44                      inc      esp                            
  0x01062537  006509                  add      byte ptr [ebp + 9], ah         
  0x0106253A  0000                    add      byte ptr [eax], al             
  0x0106253C  40                      inc      eax                            
  0x0106253D  190c00                  sbb      dword ptr [eax + eax], ecx     
  0x01062540  208000000070            and      byte ptr [eax + 0x70000000], al 
  0x01062546  54                      push     esp                            
  0x01062547  004309                  add      byte ptr [ebx + 9], al         
  0x0106254A  0000                    add      byte ptr [eax], al             
  0x0106254C  00f0                    add      al, dh                         
  0x0106254E  56                      push     esi                            
  0x0106254F  006609                  add      byte ptr [esi + 9], ah         
  0x01062552  0000                    add      byte ptr [eax], al             
  0x01062554  0300                    add      eax, dword ptr [eax]           
  0x01062556  2000                    and      byte ptr [eax], al             
  0x01062558  5a                      pop      edx                            
  0x01062559  2405                    and      al, 5                          
  0x0106255B  0000                    add      byte ptr [eax], al             
  0x0106255E  6200                    bound    eax, qword ptr [eax]           
  0x01062560  6809000000              push     9                              
  0x01062565  f4                      hlt                                     
  0x01062566  60                      pushal                                  
  0x01062567  005309                  add      byte ptr [ebx + 9], dl         
  0x0106256A  0000                    add      byte ptr [eax], al             
  0x0106256C  00f4                    add      ah, dh                         
  0x0106256E  44                      inc      esp                            
  0x0106256F  008000000090            add      byte ptr [eax - 0x70000000], al 
  0x01062575  06                      push     es                             
  0x01062576  06                      push     es                             
  0x01062577  0002                    add      byte ptr [edx], al             
  0x01062579  0000                    add      byte ptr [eax], al             
  0x0106257B  0000                    add      byte ptr [eax], al             
  0x0106257D  58                      pop      eax                            
  0x0106257E  44                      inc      esp                            
  0x0106257F  00de                    add      dh, bl                         
  0x01062581  1202                    adc      al, byte ptr [edx]             
  0x01062583  00941a02004019          add      byte ptr [edx + ebx + 0x19400002], dl 
  0x0106258A  0c00                    or       al, 0                          
  0x0106258C  1b10                    sbb      edx, dword ptr [eax]           
  0x0106258E  0000                    add      byte ptr [eax], al             
  0x01062590  007054                  add      byte ptr [eax + 0x54], dh      
  0x01062593  0036                    add      byte ptr [esi], dh             
  0x01062595  0900                    or       dword ptr [eax], eax           
  0x01062597  0013                    add      byte ptr [ebx], dl             
  0x01062599  f4                      hlt                                     
  0x0106259A  44                      inc      esp                            
  0x0106259B  0012                    add      byte ptr [edx], dl             
  0x0106259D  0000                    add      byte ptr [eax], al             
  0x0106259F  004019                  add      byte ptr [eax + 0x19], al      
  0x010625A2  0c00                    or       al, 0                          
  0x010625A4  215000                  and      dword ptr [eax], edx           
  0x010625A7  0000                    add      byte ptr [eax], al             
  0x010625A9  7054                    jo       0x10625ff                      
  0x010625AB  003a                    add      byte ptr [edx], bh             
  0x010625AD  0900                    or       dword ptr [eax], eax           
  0x010625AF  009e220200d4            add      byte ptr [esi - 0x2bfffdde], bl 
  0x010625B5  2a02                    sub      al, byte ptr [edx]             
  0x010625B7  004019                  add      byte ptr [eax + 0x19], al      
  0x010625BA  0c00                    or       al, 0                          
  0x010625BC  2110                    and      dword ptr [eax], edx           
  0x010625BE  0000                    add      byte ptr [eax], al             
  0x010625C0  94                      xchg     esp, eax                       
  0x010625C1  2a02                    sub      al, byte ptr [edx]             
  0x010625C3  004019                  add      byte ptr [eax + 0x19], al      
  0x010625C6  0c00                    or       al, 0                          
  0x010625C8  2210                    and      dl, byte ptr [eax]             
  0x010625CA  0000                    add      byte ptr [eax], al             
  0x010625CC  d422                    aam      0x22                           
  0x010625CE  0200                    add      al, byte ptr [eax]             
  0x010625D0  40                      inc      eax                            
  0x010625D1  190c00                  sbb      dword ptr [eax + eax], ecx     
  0x010625D4  2310                    and      edx, dword ptr [eax]           
  0x010625D6  0000                    add      byte ptr [eax], al             
  0x010625D8  007054                  add      byte ptr [eax + 0x54], dh      
  0x010625DB  003b                    add      byte ptr [ebx], bh             
  0x010625DD  0900                    or       dword ptr [eax], eax           
  0x010625DF  0013                    add      byte ptr [ebx], dl             
  0x010625E1  0020                    add      byte ptr [eax], ah             
  0x010625E3  00944a02004019          add      byte ptr [edx + ecx*2 + 0x19400002], dl 
  0x010625EA  0c00                    or       al, 0                          
  0x010625EC  1a20                    sbb      ah, byte ptr [eax]             
  0x010625EE  0000                    add      byte ptr [eax], al             
  0x010625F0  007054                  add      byte ptr [eax + 0x54], dh      
  0x010625F3  004709                  add      byte ptr [edi + 9], al         
  0x010625F6  0000                    add      byte ptr [eax], al             
  0x010625F8  d41a                    aam      0x1a                           
  0x010625FA  0200                    add      al, byte ptr [eax]             
  0x010625FC  007044                  add      byte ptr [eax + 0x44], dh      
                                        ; XREF: 0x010625A9 (cond_jump)
  0x010625FF  004809                  add      byte ptr [eax + 9], cl         
  0x01062602  0000                    add      byte ptr [eax], al             
  0x01062604  1300                    adc      eax, dword ptr [eax]           
  0x01062606  2000                    and      byte ptr [eax], al             
  0x01062608  94                      xchg     esp, eax                       
  0x01062609  3a02                    cmp      al, byte ptr [edx]             
  0x0106260B  004019                  add      byte ptr [eax + 0x19], al      
  0x0106260E  0c00                    or       al, 0                          
  0x01062610  1810                    sbb      byte ptr [eax], dl             
  0x01062612  0000                    add      byte ptr [eax], al             
  0x01062614  94                      xchg     esp, eax                       
  0x01062615  3202                    xor      al, byte ptr [edx]             
  0x01062617  004019                  add      byte ptr [eax + 0x19], al      
  0x0106261A  0c00                    or       al, 0                          
  0x0106261C  1910                    sbb      dword ptr [eax], edx           
  0x0106261E  0000                    add      byte ptr [eax], al             
  0x01062620  007054                  add      byte ptr [eax + 0x54], dh      
  0x01062623  00440900                add      byte ptr [ecx + ecx], al       
  0x01062627  00d4                    add      ah, dl                         
  0x01062629  3a02                    cmp      al, byte ptr [edx]             
  0x0106262B  0000                    add      byte ptr [eax], al             
  0x0106262D  7044                    jo       0x1062673                      
  0x0106262F  004609                  add      byte ptr [esi + 9], al         
  0x01062632  0000                    add      byte ptr [eax], al             
  0x01062634  d432                    aam      0x32                           
  0x01062636  0200                    add      al, byte ptr [eax]             
  0x01062638  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106263B  004509                  add      byte ptr [ebp + 9], al         
  0x0106263E  0000                    add      byte ptr [eax], al             
  0x01062640  13f4                    adc      esi, esp                       
  0x01062642  60                      pushal                                  
  0x01062643  0032                    add      byte ptr [edx], dh             
  0x01062645  0900                    or       dword ptr [eax], eax           
  0x01062647  0000                    add      byte ptr [eax], al             
  0x01062649  f4                      hlt                                     
  0x0106264A  57                      push     edi                            
  0x0106264B  0010                    add      byte ptr [eax], dl             
  0x0106264D  0000                    add      byte ptr [eax], al             
  0x0106264F  0080100d00a9            add      byte ptr [eax - 0x56fff2f0], al 
  0x01062655  0200                    add      al, byte ptr [eax]             
  0x01062657  0000                    add      byte ptr [eax], al             
  0x01062659  f4                      hlt                                     
  0x0106265A  44                      inc      esp                            
  0x0106265B  0000                    add      byte ptr [eax], al             
  0x0106265D  0000                    add      byte ptr [eax], al             
  0x0106265F  004500                  add      byte ptr [ebp], al             
  0x01062662  2000                    and      byte ptr [eax], al             
  0x01062664  00740500                add      byte ptr [ebp + eax], dh       
  0x01062668  0c00                    or       al, 0                          
  0x0106266A  0000                    add      byte ptr [eax], al             
  0x0106266C  1b00                    sbb      eax, dword ptr [eax]           
  0x0106266E  3000                    xor      byte ptr [eax], al             
  0x01062670  80100d                  adc      byte ptr [eax], 0xd            
                                        ; XREF: 0x0106262D (cond_jump)
  0x01062673  00a10200000c            add      byte ptr [ecx + 0xc000002], ah 
  0x01062679  0000                    add      byte ptr [eax], al             
  0x0106267B  0000                    add      byte ptr [eax], al             
  0x0106267D  f4                      hlt                                     
  0x0106267E  44                      inc      esp                            
  0x0106267F  001500000000            add      byte ptr [0], dl               
  0x01062685  7044                    jo       0x10626cb                      
  0x01062687  0032                    add      byte ptr [edx], dh             
  0x01062689  0900                    or       dword ptr [eax], eax           
  0x0106268B  0000                    add      byte ptr [eax], al             
  0x0106268D  f4                      hlt                                     
  0x0106268E  44                      inc      esp                            
  0x0106268F  005309                  add      byte ptr [ebx + 9], dl         
  0x01062692  0000                    add      byte ptr [eax], al             
  0x01062694  007044                  add      byte ptr [eax + 0x44], dh      
  0x01062697  0033                    add      byte ptr [ebx], dh             
  0x01062699  0900                    or       dword ptr [eax], eax           
  0x0106269B  0000                    add      byte ptr [eax], al             
  0x0106269D  f4                      hlt                                     
  0x0106269E  44                      inc      esp                            
  0x0106269F  005f09                  add      byte ptr [edi + 9], bl         
  0x010626A2  0000                    add      byte ptr [eax], al             
  0x010626A4  007044                  add      byte ptr [eax + 0x44], dh      
  0x010626A7  003409                  add      byte ptr [ecx + ecx], dh       
  0x010626AA  0000                    add      byte ptr [eax], al             
  0x010626AC  00f4                    add      ah, dh                         
  0x010626AE  44                      inc      esp                            
  0x010626AF  005909                  add      byte ptr [ecx + 9], bl         
  0x010626B2  0000                    add      byte ptr [eax], al             
  0x010626B4  007044                  add      byte ptr [eax + 0x44], dh      
  0x010626B7  003509000000            add      byte ptr [9], dh               
  0x010626BD  f4                      hlt                                     
  0x010626BE  44                      inc      esp                            
  0x010626BF  00ff                    add      bh, bh                         
  0x010626C1  ff00                    inc      dword ptr [eax]                
  0x010626C3  0000                    add      byte ptr [eax], al             
  0x010626C5  7044                    jo       0x106270b                      
  0x010626C7  0039                    add      byte ptr [ecx], bh             
  0x010626C9  0900                    or       dword ptr [eax], eax           
                                        ; XREF: 0x01062685 (cond_jump)
  0x010626CB  0000                    add      byte ptr [eax], al             
  0x010626CD  f4                      hlt                                     
  0x010626CE  44                      inc      esp                            
  0x010626CF  004709                  add      byte ptr [edi + 9], al         
  0x010626D2  0000                    add      byte ptr [eax], al             
  0x010626D4  007044                  add      byte ptr [eax + 0x44], dh      
  0x010626D7  003c09                  add      byte ptr [ecx + ecx], bh       
  0x010626DA  0000                    add      byte ptr [eax], al             
  0x010626DC  0000                    add      byte ptr [eax], al             
  0x010626DE  2400                    and      al, 0                          
  0x010626E0  007044                  add      byte ptr [eax + 0x44], dh      
  0x010626E3  0037                    add      byte ptr [edi], dh             
  0x010626E5  0900                    or       dword ptr [eax], eax           
  0x010626E7  0000                    add      byte ptr [eax], al             
  0x010626E9  7044                    jo       0x106272f                      
  0x010626EB  0038                    add      byte ptr [eax], bh             
  0x010626ED  0900                    or       dword ptr [eax], eax           
  0x010626EF  0000                    add      byte ptr [eax], al             
  0x010626F1  7044                    jo       0x1062737                      
  0x010626F3  003d09000000            add      byte ptr [9], bh               
  0x010626F9  7044                    jo       0x106273f                      
  0x010626FB  003e                    add      byte ptr [esi], bh             
  0x010626FD  0900                    or       dword ptr [eax], eax           
  0x010626FF  0000                    add      byte ptr [eax], al             
  0x01062701  7044                    jo       0x1062747                      
  0x01062703  003f                    add      byte ptr [edi], bh             
  0x01062705  0900                    or       dword ptr [eax], eax           
  0x01062707  0000                    add      byte ptr [eax], al             
  0x01062709  7044                    jo       0x106274f                      
                                        ; XREF: 0x010626C5 (cond_jump)
  0x0106270B  004009                  add      byte ptr [eax + 9], al         
  0x0106270E  0000                    add      byte ptr [eax], al             
  0x01062710  007044                  add      byte ptr [eax + 0x44], dh      
  0x01062713  004109                  add      byte ptr [ecx + 9], al         
  0x01062716  0000                    add      byte ptr [eax], al             
  0x01062718  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106271B  004209                  add      byte ptr [edx + 9], al         
  0x0106271E  0000                    add      byte ptr [eax], al             
  0x01062720  00f4                    add      ah, dh                         
  0x01062722  60                      pushal                                  
  0x01062723  004d09                  add      byte ptr [ebp + 9], cl         
  0x01062726  0000                    add      byte ptr [eax], al             
  0x01062728  00f4                    add      ah, dh                         
  0x0106272A  44                      inc      esp                            
  0x0106272B  0000                    add      byte ptr [eax], al             
  0x0106272D  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x010626E9 (cond_jump)
  0x0106272F  0000                    add      byte ptr [eax], al             
  0x01062731  58                      pop      eax                            
  0x01062732  44                      inc      esp                            
  0x01062733  0000                    add      byte ptr [eax], al             
  0x01062735  f4                      hlt                                     
  0x01062736  44                      inc      esp                            
                                        ; XREF: 0x010626F1 (cond_jump)
  0x01062737  0002                    add      byte ptr [edx], al             
  0x01062739  0000                    add      byte ptr [eax], al             
  0x0106273B  0000                    add      byte ptr [eax], al             
  0x0106273D  58                      pop      eax                            
  0x0106273E  44                      inc      esp                            
                                        ; XREF: 0x010626F9 (cond_jump)
  0x0106273F  0000                    add      byte ptr [eax], al             
  0x01062741  f4                      hlt                                     
  0x01062742  44                      inc      esp                            
  0x01062743  0003                    add      byte ptr [ebx], al             
  0x01062745  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01062701 (cond_jump)
  0x01062747  0000                    add      byte ptr [eax], al             
  0x01062749  58                      pop      eax                            
  0x0106274A  44                      inc      esp                            
  0x0106274B  0000                    add      byte ptr [eax], al             
  0x0106274D  f4                      hlt                                     
  0x0106274E  44                      inc      esp                            
                                        ; XREF: 0x01062709 (cond_jump)
  0x0106274F  000400                  add      byte ptr [eax + eax], al       
  0x01062752  0000                    add      byte ptr [eax], al             
  0x01062754  005844                  add      byte ptr [eax + 0x44], bl      
  0x01062757  0000                    add      byte ptr [eax], al             
  0x01062759  f4                      hlt                                     
  0x0106275A  44                      inc      esp                            
  0x0106275B  0001                    add      byte ptr [ecx], al             
  0x0106275D  0000                    add      byte ptr [eax], al             
  0x0106275F  0000                    add      byte ptr [eax], al             
  0x01062761  58                      pop      eax                            
  0x01062762  44                      inc      esp                            
  0x01062763  0000                    add      byte ptr [eax], al             
  0x01062765  f4                      hlt                                     
  0x01062766  44                      inc      esp                            
  0x01062767  000500000000            add      byte ptr [0], al               
  0x0106276D  58                      pop      eax                            
  0x0106276E  44                      inc      esp                            
  0x0106276F  0000                    add      byte ptr [eax], al             
  0x01062771  f4                      hlt                                     
  0x01062772  60                      pushal                                  
  0x01062773  005f09                  add      byte ptr [edi + 9], bl         
  0x01062776  0000                    add      byte ptr [eax], al             
  0x01062778  00f4                    add      ah, dh                         
  0x0106277A  44                      inc      esp                            
  0x0106277B  0001                    add      byte ptr [ecx], al             
  0x0106277D  0000                    add      byte ptr [eax], al             
  0x0106277F  009006060002            add      byte ptr [eax + 0x2000606], dl 
  0x01062785  0000                    add      byte ptr [eax], al             
  0x01062787  0000                    add      byte ptr [eax], al             
  0x01062789  58                      pop      eax                            
  0x0106278A  44                      inc      esp                            
  0x0106278B  0000                    add      byte ptr [eax], al             
  0x0106278D  f4                      hlt                                     
  0x0106278E  60                      pushal                                  
  0x0106278F  005909                  add      byte ptr [ecx + 9], bl         
  0x01062792  0000                    add      byte ptr [eax], al             
  0x01062794  00f4                    add      ah, dh                         
  0x01062796  44                      inc      esp                            
  0x01062797  00ff                    add      bh, bh                         
  0x01062799  ff00                    inc      dword ptr [eax]                
  0x0106279B  009006060002            add      byte ptr [eax + 0x2000606], dl 
  0x010627A1  0000                    add      byte ptr [eax], al             
  0x010627A3  0000                    add      byte ptr [eax], al             
  0x010627A5  58                      pop      eax                            
  0x010627A6  44                      inc      esp                            
  0x010627A7  000c00                  add      byte ptr [eax + eax], cl       
  0x010627AA  0000                    add      byte ptr [eax], al             
  0x010627AC  00f0                    add      al, dh                         
  0x010627AE  6200                    bound    eax, qword ptr [eax]           
  0x010627B0  6809000000              push     9                              
  0x010627B5  f4                      hlt                                     
  0x010627B6  45                      inc      ebp                            
  0x010627B7  0003                    add      byte ptr [ebx], al             
  0x010627B9  0000                    add      byte ptr [eax], al             
  0x010627BB  00d6                    add      dh, dl                         
  0x010627BD  1202                    adc      al, byte ptr [edx]             
  0x010627BF  00e0                    add      al, ah                         
  0x010627C1  0020                    add      byte ptr [eax], ah             
  0x010627C3  0000                    add      byte ptr [eax], al             
  0x010627C5  f4                      hlt                                     
  0x010627C6  6200                    bound    eax, qword ptr [eax]           
  0x010627C8  92                      xchg     edx, eax                       
  0x010627C9  0f0000                  sldt     word ptr [eax]                 
  0x010627CC  000e                    add      byte ptr [esi], cl             
  0x010627CE  2100                    and      dword ptr [eax], eax           
  0x010627D0  40                      inc      eax                            
  0x010627D1  0020                    add      byte ptr [eax], ah             
  0x010627D3  0000                    add      byte ptr [eax], al             
  0x010627D5  f4                      hlt                                     
  0x010627D6  60                      pushal                                  
  0x010627D7  008000000000            add      byte ptr [eax], al             
  0x010627DD  9a210000f47000          lcall    0x70, 0xf4000021               
  0x010627E4  0001                    add      byte ptr [ecx], al             
  0x010627E6  0000                    add      byte ptr [eax], al             
  0x010627E8  00f4                    add      ah, dh                         
  0x010627EA  56                      push     esi                            
  0x010627EB  0007                    add      byte ptr [edi], al             
  0x010627ED  0000                    add      byte ptr [eax], al             
  0x010627EF  0000                    add      byte ptr [eax], al             
  0x010627F1  ea790080010d00          ljmp     0xd:0x1800079                  
  0x010627F8  0300                    add      eax, dword ptr [eax]           
  0x010627FA  2000                    and      byte ptr [eax], al             
  0x010627FC  002405000c0000          add      byte ptr [eax + 0xc00], ah     
  0x01062803  0000                    add      byte ptr [eax], al             
  0x01062805  0823                    or       byte ptr [ebx], ah             
  0x01062807  000a                    add      byte ptr [edx], cl             
  0x01062809  0000                    add      byte ptr [eax], al             
  0x0106280B  00a0c80400a0            add      byte ptr [eax - 0x5ffffb38], ah 
  0x01062811  61                      popal                                   
  0x01062812  0400                    add      al, 0                          
  0x01062814  a0640400a0              mov      al, byte ptr [0xa0000464]      
  0x01062819  650400                  add      al, 0                          
  0x0106281C  f8                      clc                                     
  0x0106281D  0400                    add      al, 0                          
  0x0106281F  0000                    add      byte ptr [eax], al             
  0x01062821  0e                      push     cs                             
  0x01062822  2300                    and      eax, dword ptr [eax]           
  0x01062824  2200                    and      al, byte ptr [eax]             
  0x01062826  2000                    and      byte ptr [eax], al             
  0x01062828  009821000014            add      byte ptr [eax + 0x14000021], bl 
  0x0106282E  2200                    and      al, byte ptr [eax]             
  0x01062830  114804                  adc      dword ptr [eax + 4], ecx       
  0x01062833  0000                    add      byte ptr [eax], al             
  0x01062835  35220000e0              xor      eax, 0xe0000022                
  0x0106283A  5f                      pop      edi                            
  0x0106283B  0000                    add      byte ptr [eax], al             
  0x0106283D  e14f                    loope    0x106288e                      
  0x0106283F  0078e0                  add      byte ptr [eax - 0x20], bh      
  0x01062842  5e                      pop      esi                            
  0x01062843  0010                    add      byte ptr [eax], dl             
  0x01062845  d806                    fadd     dword ptr [esi]                
  0x01062847  0009                    add      byte ptr [ecx], cl             
  0x01062849  0000                    add      byte ptr [eax], al             
  0x0106284B  0019                    add      byte ptr [ecx], bl             
  0x0106284D  d94500                  fld      dword ptr [ebp]                
  0x01062850  16                      push     ss                             
  0x01062851  0020                    add      byte ptr [eax], ah             
  0x01062853  0000                    add      byte ptr [eax], al             
  0x01062855  808f0068b88a00          or       byte ptr [edi - 0x75479800], 0 
  0x0106285C  19e1                    sbb      ecx, esp                       
  0x0106285E  4f                      dec      edi                            
  0x0106285F  0016                    add      byte ptr [esi], dl             
  0x01062861  0020                    add      byte ptr [eax], ah             
  0x01062863  0000                    add      byte ptr [eax], al             
  0x01062865  1ccf                    sbb      al, 0xcf                       
  0x01062867  00781d                  add      byte ptr [eax + 0x1d], bh      
  0x0106286A  ca0000                  retf     0                              
  0x0106286D  0e                      push     cs                             
  0x0106286E  2300                    and      eax, dword ptr [eax]           
  0x01062870  2230                    and      dh, byte ptr [eax]             
  0x01062872  2200                    and      al, byte ptr [eax]             
  0x01062874  009821000014            add      byte ptr [eax + 0x14000021], bl 
  0x0106287A  2200                    and      al, byte ptr [eax]             
  0x0106287C  114804                  adc      dword ptr [eax + 4], ecx       
  0x0106287F  0000                    add      byte ptr [eax], al             
  0x01062881  35220000e0              xor      eax, 0xe0000022                
  0x01062886  5f                      pop      edi                            
  0x01062887  0000                    add      byte ptr [eax], al             
  0x01062889  e14f                    loope    0x10628da                      
  0x0106288B  0078e0                  add      byte ptr [eax - 0x20], bh      
                                        ; XREF: 0x0106283D (cond_jump)
  0x0106288E  5e                      pop      esi                            
  0x0106288F  0010                    add      byte ptr [eax], dl             
  0x01062891  d806                    fadd     dword ptr [esi]                
  0x01062893  0009                    add      byte ptr [ecx], cl             
  0x01062895  0000                    add      byte ptr [eax], al             
  0x01062897  0019                    add      byte ptr [ecx], bl             
  0x01062899  d94500                  fld      dword ptr [ebp]                
  0x0106289C  16                      push     ss                             
  0x0106289D  0020                    add      byte ptr [eax], ah             
  0x0106289F  0000                    add      byte ptr [eax], al             
  0x010628A1  808f0068b88a00          or       byte ptr [edi - 0x75479800], 0 
  0x010628A8  19e1                    sbb      ecx, esp                       
  0x010628AA  4f                      dec      edi                            
  0x010628AB  0016                    add      byte ptr [esi], dl             
  0x010628AD  0020                    add      byte ptr [eax], ah             
  0x010628AF  0000                    add      byte ptr [eax], al             
  0x010628B1  1ccf                    sbb      al, 0xcf                       
  0x010628B3  00781d                  add      byte ptr [eax + 0x1d], bh      
  0x010628B6  ca0000                  retf     0                              
  0x010628B9  3022                    xor      byte ptr [edx], ah             
  0x010628BB  0000                    add      byte ptr [eax], al             
  0x010628BD  1422                    adc      al, 0x22                       
  0x010628BF  0011                    add      byte ptr [ecx], dl             
  0x010628C1  48                      dec      eax                            
  0x010628C2  0400                    add      al, 0                          
  0x010628C4  0035220000e0            add      byte ptr [0xe0000022], dh      
  0x010628CA  5f                      pop      edi                            
  0x010628CB  0000                    add      byte ptr [eax], al             
  0x010628CD  e145                    loope    0x1062914                      
  0x010628CF  006ce05e                add      byte ptr [eax + 0x5e], ch      
  0x010628D3  0010                    add      byte ptr [eax], dl             
  0x010628D5  d806                    fadd     dword ptr [esi]                
  0x010628D7  0009                    add      byte ptr [ecx], cl             
  0x010628D9  0000                    add      byte ptr [eax], al             
  0x010628DB  0019                    add      byte ptr [ecx], bl             
  0x010628DE  4f                      dec      edi                            
  0x010628DF  0016                    add      byte ptr [esi], dl             
  0x010628E1  0020                    add      byte ptr [eax], ah             
  0x010628E3  0000                    add      byte ptr [eax], al             
  0x010628E5  808f0078b88a00          or       byte ptr [edi - 0x75478800], 0 
  0x010628EC  19e1                    sbb      ecx, esp                       
  0x010628EE  45                      inc      ebp                            
  0x010628EF  0016                    add      byte ptr [esi], dl             
  0x010628F1  0020                    add      byte ptr [eax], ah             
  0x010628F3  0000                    add      byte ptr [eax], al             
  0x010628F5  1ccf                    sbb      al, 0xcf                       
  0x010628F7  006c1dca                add      byte ptr [ebp + ebx - 0x36], ch 
  0x010628FB  0000                    add      byte ptr [eax], al             
  0x010628FD  0e                      push     cs                             
  0x010628FE  2300                    and      eax, dword ptr [eax]           
  0x01062900  2202                    and      al, byte ptr [edx]             
  0x01062902  3a00                    cmp      al, byte ptr [eax]             
  0x01062904  0030                    add      byte ptr [eax], dh             
  0x01062906  2200                    and      al, byte ptr [eax]             
  0x01062908  009921000011            add      byte ptr [ecx + 0x11000021], bl 
  0x0106290E  2200                    and      al, byte ptr [eax]             
  0x01062910  0032                    add      byte ptr [edx], dh             
  0x01062912  2300                    and      eax, dword ptr [eax]           
                                        ; XREF: 0x010628CD (cond_jump)
  0x01062914  001422                  add      byte ptr [edx], dl             
  0x01062917  0000                    add      byte ptr [eax], al             
  0x01062919  f4                      hlt                                     
  0x0106291A  6600520f                add      byte ptr [edx + 0xf], dl       
  0x0106291E  0000                    add      byte ptr [eax], al             
  0x01062920  004920                  add      byte ptr [ecx + 0x20], cl      
  0x01062923  0000                    add      byte ptr [eax], al             
  0x01062925  352200185a              xor      eax, 0x5a180022                
  0x0106292A  0400                    add      al, 0                          
  0x0106292C  001c23                  add      byte ptr [ebx], bl             
  0x0106292F  0000                    add      byte ptr [eax], al             
  0x01062931  1d23000052              sbb      eax, 0x52000023                
  0x01062936  2000                    and      byte ptr [eax], al             
  0x01062938  00e0                    add      al, ah                         
  0x0106293A  5f                      pop      edi                            
  0x0106293B  0000                    add      byte ptr [eax], al             
  0x0106293D  c1f400                  sal      esp, 0                         
  0x01062940  00de                    add      dh, bl                         
  0x01062942  4c                      dec      esp                            
  0x01062943  00aed94f00bf            add      byte ptr [esi - 0x40ffb027], ch 
  0x01062949  e05e                    loopne   0x10629a9                      
  0x0106294B  0010                    add      byte ptr [eax], dl             
  0x0106294D  da06                    fiadd    dword ptr [esi]                
  0x0106294F  0020                    add      byte ptr [eax], ah             
  0x01062951  0000                    add      byte ptr [eax], al             
  0x01062953  0010                    add      byte ptr [eax], dl             
  0x01062955  d206                    rol      byte ptr [esi], cl             
  0x01062957  0007                    add      byte ptr [edi], al             
  0x01062959  0000                    add      byte ptr [eax], al             
  0x0106295B  0016                    add      byte ptr [esi], dl             
  0x0106295D  808f00eee14500          or       byte ptr [edi + 0x45e1ee00], 0 
  0x01062964  cb                      retf                                    
  0x01062965  b88a00161c              mov      eax, 0x1c16008a                
  0x0106296A  cf                      iretd                                   
  0x0106296B  00aed94f00bf            add      byte ptr [esi - 0x40ffb027], ch 
  0x01062971  1dca000049              sbb      eax, 0x490000ca                
  0x01062976  2000                    and      byte ptr [eax], al             
  0x01062978  16                      push     ss                             
  0x01062979  808f00eea88a00          or       byte ptr [edi - 0x75571200], 0 
  0x01062980  cb                      retf                                    
  0x01062981  e145                    loope    0x10629c8                      
  0x01062983  0016                    add      byte ptr [esi], dl             
  0x01062985  0ccf                    or       al, 0xcf                       
  0x01062987  00ea                    add      dl, ch                         
  0x0106298A  4f                      dec      edi                            
  0x0106298B  00cf                    add      bh, cl                         
  0x0106298D  0dca0010d2              or       eax, 0xd21000ca                
  0x01062992  06                      push     es                             
  0x01062993  0007                    add      byte ptr [edi], al             
  0x01062995  0000                    add      byte ptr [eax], al             
  0x01062997  0016                    add      byte ptr [esi], dl             
  0x01062999  808f00aee14500          or       byte ptr [edi + 0x45e1ae00], 0 
  0x010629A0  bfb88a0016              mov      edi, 0x16008ab8                
  0x010629A5  1ccf                    sbb      al, 0xcf                       
  0x010629A7  00ea                    add      dl, ch                         
  0x010629AA  4f                      dec      edi                            
  0x010629AB  00cf                    add      bh, cl                         
  0x010629AD  1dca000049              sbb      eax, 0x490000ca                
  0x010629B2  2000                    and      byte ptr [eax], al             
  0x010629B4  16                      push     ss                             
  0x010629B5  808f00aea88a00          or       byte ptr [edi - 0x75575200], 0 
  0x010629BC  bfc1f40000              mov      edi, 0xf4c1                    
  0x010629C1  de4c0016                fimul    word ptr [eax + eax + 0x16]    
  0x010629C5  0ccf                    or       al, 0xcf                       
  0x010629C7  00aed94f00bf            add      byte ptr [esi - 0x40ffb027], ch 
  0x010629CD  0dca00002f              or       eax, 0x2f0000ca                
  0x010629D2  2300                    and      eax, dword ptr [eax]           
  0x010629D4  2a4e23                  sub      cl, byte ptr [esi + 0x23]      
  0x010629D7  0032                    add      byte ptr [edx], dh             
  0x010629D9  0020                    add      byte ptr [eax], ah             
  0x010629DB  0000                    add      byte ptr [eax], al             
  0x010629DD  b92100009a              mov      ecx, 0x9a000021                
  0x010629E2  2100                    and      dword ptr [eax], eax           
  0x010629E4  80cd0c                  or       ch, 0xc                        
  0x010629E7  00ca                    add      dl, cl                         
  0x010629EA  ff00                    inc      dword ptr [eax]                
  0x010629EC  0002                    add      byte ptr [edx], al             
  0x010629EE  3800                    cmp      byte ptr [eax], al             
  0x010629F0  001422                  add      byte ptr [edx], dl             
  0x010629F3  0000                    add      byte ptr [eax], al             
  0x010629F5  1c23                    sbb      al, 0x23                       
  0x010629F7  0000                    add      byte ptr [eax], al             
  0x010629F9  52                      push     edx                            
  0x010629FA  2300                    and      eax, dword ptr [eax]           
  0x010629FC  00f4                    add      ah, dh                         
  0x010629FE  6600520f                add      byte ptr [edx + 0xf], dl       
  0x01062A02  0000                    add      byte ptr [eax], al             
  0x01062A04  115804                  adc      dword ptr [eax + 4], ebx       
  0x01062A07  0000                    add      byte ptr [eax], al             
  0x01062A09  1923                    sbb      dword ptr [ebx], esp           
  0x01062A0B  0000                    add      byte ptr [eax], al             
  0x01062A0D  352200001d              xor      eax, 0x1d000022                
  0x01062A12  2300                    and      eax, dword ptr [eax]           
  0x01062A14  005220                  add      byte ptr [edx + 0x20], dl      
  0x01062A17  0000                    add      byte ptr [eax], al             
  0x01062A19  e05f                    loopne   0x1062a7a                      
  0x01062A1B  0000                    add      byte ptr [eax], al             
  0x01062A1D  c1f400                  sal      esp, 0                         
  0x01062A20  00de                    add      dh, bl                         
  0x01062A22  4c                      dec      esp                            
  0x01062A23  00aec94f00bf            add      byte ptr [esi - 0x40ffb037], ch 
  0x01062A29  e05e                    loopne   0x1062a89                      
  0x01062A2B  0016                    add      byte ptr [esi], dl             
  0x01062A2D  0020                    add      byte ptr [eax], ah             
  0x01062A2F  0000                    add      byte ptr [eax], al             
  0x01062A31  808f00eea88a00          or       byte ptr [edi - 0x75571200], 0 
  0x01062A38  cb                      retf                                    
  0x01062A39  e145                    loope    0x1062a80                      
  0x01062A3B  0016                    add      byte ptr [esi], dl             
  0x01062A3D  0ccf                    or       al, 0xcf                       
  0x01062A3F  0010                    add      byte ptr [eax], dl             
  0x01062A41  d206                    rol      byte ptr [esi], cl             
  0x01062A43  0010                    add      byte ptr [eax], dl             
  0x01062A45  0000                    add      byte ptr [eax], al             
  0x01062A47  00ea                    add      dl, ch                         
  0x01062A49  c9                      leave                                   
  0x01062A4A  4f                      dec      edi                            
  0x01062A4B  00cf                    add      bh, cl                         
  0x01062A4D  0dca001600              or       eax, 0x1600ca                  
  0x01062A52  2000                    and      byte ptr [eax], al             
  0x01062A54  00808f00aea8            add      byte ptr [eax - 0x5751ff71], al 
  0x01062A5A  8a00                    mov      al, byte ptr [eax]             
  0x01062A5C  bfc1f40000              mov      edi, 0xf4c1                    
  0x01062A61  de4c0016                fimul    word ptr [eax + eax + 0x16]    
  0x01062A65  0ccf                    or       al, 0xcf                       
  0x01062A67  00aec94f00bf            add      byte ptr [esi - 0x40ffb037], ch 
  0x01062A6D  0dca001600              or       eax, 0x1600ca                  
  0x01062A72  2000                    and      byte ptr [eax], al             
  0x01062A74  00808f00eea8            add      byte ptr [eax - 0x5711ff71], al 
                                        ; XREF: 0x01062A19 (cond_jump)
  0x01062A7A  8a00                    mov      al, byte ptr [eax]             
  0x01062A7C  cb                      retf                                    
  0x01062A7D  e145                    loope    0x1062ac4                      
  0x01062A7F  0016                    add      byte ptr [esi], dl             
  0x01062A81  0ccf                    or       al, 0xcf                       
  0x01062A83  00ea                    add      dl, ch                         
  0x01062A85  c9                      leave                                   
  0x01062A86  4f                      dec      edi                            
  0x01062A87  00cf                    add      bh, cl                         
                                        ; XREF: 0x01062A29 (cond_jump)
  0x01062A89  0dca001600              or       eax, 0x1600ca                  
  0x01062A8E  2000                    and      byte ptr [eax], al             
  0x01062A90  00808f00aea8            add      byte ptr [eax - 0x5751ff71], al 
  0x01062A96  8a00                    mov      al, byte ptr [eax]             
  0x01062A98  bf00200020              mov      edi, 0x20002000                
  0x01062A9D  f4                      hlt                                     
  0x01062A9E  0500ffff00              add      eax, 0xffff00                  
  0x01062AA3  0016                    add      byte ptr [esi], dl             
  0x01062AA5  4c                      dec      esp                            
  0x01062AA6  57                      push     edi                            
  0x01062AA7  00a061040000            add      byte ptr [eax + 0x461], ah     
  0x01062AAD  4d                      dec      ebp                            
  0x01062AAE  56                      push     esi                            
  0x01062AAF  00a0640400a0            add      byte ptr [eax - 0x5ffffb9c], ah 
  0x01062AB5  650400                  add      al, 0                          
  0x01062AB8  b8f300000c              mov      eax, 0xc0000f3                 
  0x01062ABD  0000                    add      byte ptr [eax], al             
  0x01062ABF  0000                    add      byte ptr [eax], al             
  0x01062AC1  f4                      hlt                                     
  0x01062AC2  7100                    jno      0x1062ac4                      
  0x01062AC6  ff00                    inc      dword ptr [eax]                
  0x01062AC8  00f4                    add      ah, dh                         
  0x01062ACA  7500                    jne      0x1062acc                      
                                        ; XREF: 0x01062ACA (cond_jump)
  0x01062ACC  fc                      cld                                     
  0x01062ACE  ff00                    inc      dword ptr [eax]                
  0x01062AD0  0096220010da            add      byte ptr [esi - 0x25efffde], dl 
  0x01062AD6  06                      push     es                             
  0x01062AD7  001a                    add      byte ptr [edx], bl             
  0x01062AD9  0000                    add      byte ptr [eax], al             
  0x01062ADB  0000                    add      byte ptr [eax], al             
  0x01062ADD  b9f00010de              mov      ecx, 0xde1000f0                
  0x01062AE2  06                      push     es                             
  0x01062AE3  000a                    add      byte ptr [edx], cl             
  0x01062AE5  0000                    add      byte ptr [eax], al             
  0x01062AE7  00d4                    add      ah, dl                         
  0x01062AE9  e145                    loope    0x1062b30                      
  0x01062AEB  00d6                    add      dh, dl                         
  0x01062AED  39f0                    cmp      eax, esi                       
  0x01062AEF  00e6                    add      dh, ah                         
  0x01062AF1  a8f0                    test     al, 0xf0                       
  0x01062AF3  00d2                    add      dl, dl                         
  0x01062AF5  a1f400e259              mov      eax, dword ptr [0x59e200f4]    
  0x01062AFA  44                      inc      esp                            
  0x01062AFB  00e2                    add      dl, ah                         
  0x01062AFD  a1d000d349              mov      eax, dword ptr [0x49d300d0]    
  0x01062B02  45                      inc      ebp                            
  0x01062B03  0000                    add      byte ptr [eax], al             
  0x01062B05  dd10                    fst      qword ptr [eax]                
  0x01062B07  0000                    add      byte ptr [eax], al             
  0x01062B09  4c                      dec      esp                            
  0x01062B0A  44                      inc      esp                            
  0x01062B0B  00d4                    add      ah, dl                         
  0x01062B0D  e145                    loope    0x1062b54                      
  0x01062B0F  00d6                    add      dh, dl                         
  0x01062B11  39f0                    cmp      eax, esi                       
  0x01062B13  00e6                    add      dh, ah                         
  0x01062B15  a8f0                    test     al, 0xf0                       
  0x01062B17  00d2                    add      dl, dl                         
  0x01062B19  a1f400e259              mov      eax, dword ptr [0x59e200f4]    
  0x01062B1E  44                      inc      esp                            
  0x01062B1F  00e2                    add      dl, ah                         
  0x01062B21  a1f000d359              mov      eax, dword ptr [0x59d300f0]    
  0x01062B26  45                      inc      ebp                            
  0x01062B27  0000                    add      byte ptr [eax], al             
  0x01062B29  4c                      dec      esp                            
  0x01062B2A  56                      push     esi                            
  0x01062B2B  008ef1030000            add      byte ptr [esi + 0x3f1], cl     
  0x01062B31  d422                    aam      0x22                           
  0x01062B33  0000                    add      byte ptr [eax], al             
  0x01062B35  90                      nop                                     
  0x01062B36  2200                    and      al, byte ptr [eax]             
  0x01062B38  00982300a460            add      byte ptr [eax + 0x60a40023], bl 
  0x01062B3E  0400                    add      al, 0                          
  0x01062B40  0c00                    or       al, 0                          
  0x01062B42  0000                    add      byte ptr [eax], al             
  0x01062B44  00f4                    add      ah, dh                         
  0x01062B46  7100                    jno      0x1062b48                      
  0x01062B4A  ff00                    inc      dword ptr [eax]                
  0x01062B4C  00f4                    add      ah, dh                         
  0x01062B4E  7500                    jne      0x1062b50                      
                                        ; XREF: 0x01062B4E (cond_jump)
  0x01062B50  fc                      cld                                     
  0x01062B52  ff00                    inc      dword ptr [eax]                
                                        ; XREF: 0x01062B0D (cond_jump)
  0x01062B54  0096220010da            add      byte ptr [esi - 0x25efffde], dl 
  0x01062B5A  06                      push     es                             
  0x01062B5B  0021                    add      byte ptr [ecx], ah             
  0x01062B5D  0000                    add      byte ptr [eax], al             
  0x01062B5F  0000                    add      byte ptr [eax], al             
  0x01062B61  da5700                  ficom    dword ptr [edi]                
  0x01062B64  00d2                    add      dl, dl                         
  0x01062B66  51                      push     ecx                            
  0x01062B67  0000                    add      byte ptr [eax], al             
  0x01062B69  b9f00010de              mov      ecx, 0xde1000f0                
  0x01062B6E  06                      push     es                             
  0x01062B6F  000b                    add      byte ptr [ebx], cl             
  0x01062B71  0000                    add      byte ptr [eax], al             
  0x01062B73  00d4                    add      ah, dl                         
  0x01062B75  e145                    loope    0x1062bbc                      
  0x01062B77  00d6                    add      dh, dl                         
  0x01062B79  39f0                    cmp      eax, esi                       
  0x01062B7B  00e6                    add      dh, ah                         
  0x01062B7D  a8f0                    test     al, 0xf0                       
  0x01062B7F  00d2                    add      dl, dl                         
  0x01062B81  a1f400e259              mov      eax, dword ptr [0x59e200f4]    
  0x01062B86  44                      inc      esp                            
  0x01062B87  00e2                    add      dl, ah                         
  0x01062B89  a1d000d249              mov      eax, dword ptr [0x49d200d0]    
  0x01062B8E  45                      inc      ebp                            
  0x01062B8F  0010                    add      byte ptr [eax], dl             
  0x01062B91  0020                    add      byte ptr [eax], ah             
  0x01062B93  0009                    add      byte ptr [ecx], cl             
  0x01062B95  dd10                    fst      qword ptr [eax]                
  0x01062B97  004c4c44                add      byte ptr [esp + ecx*2 + 0x44], cl 
  0x01062B9B  00d4                    add      ah, dl                         
  0x01062B9D  e145                    loope    0x1062be4                      
  0x01062B9F  00d6                    add      dh, dl                         
  0x01062BA1  39f0                    cmp      eax, esi                       
  0x01062BA3  00e6                    add      dh, ah                         
  0x01062BA5  a8f0                    test     al, 0xf0                       
  0x01062BA7  00d2                    add      dl, dl                         
  0x01062BA9  a1f400e259              mov      eax, dword ptr [0x59e200f4]    
  0x01062BAE  44                      inc      esp                            
  0x01062BAF  00e2                    add      dl, ah                         
  0x01062BB1  a1f000d259              mov      eax, dword ptr [0x59d200f0]    
  0x01062BB6  45                      inc      ebp                            
  0x01062BB7  0010                    add      byte ptr [eax], dl             
  0x01062BB9  0020                    add      byte ptr [eax], ah             
  0x01062BBB  0009                    add      byte ptr [ecx], cl             
  0x01062BBD  c421                    les      esp, ptr [ecx]                 
  0x01062BBF  004c4c44                add      byte ptr [esp + ecx*2 + 0x44], cl 
  0x01062BC3  0084f10300005a          add      byte ptr [ecx + esi*8 + 0x5a000003], al 
  0x01062BCA  55                      push     ebp                            
  0x01062BCB  0000                    add      byte ptr [eax], al             
  0x01062BCD  5a                      pop      edx                            
  0x01062BCE  51                      push     ecx                            
  0x01062BCF  0000                    add      byte ptr [eax], al             
  0x01062BD1  d422                    aam      0x22                           
  0x01062BD3  0000                    add      byte ptr [eax], al             
  0x01062BD5  90                      nop                                     
  0x01062BD6  2200                    and      al, byte ptr [eax]             
  0x01062BD8  00982300a460            add      byte ptr [eax + 0x60a40023], bl 
  0x01062BDE  0400                    add      al, 0                          
  0x01062BE0  0c00                    or       al, 0                          
  0x01062BE2  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01062B9D (cond_jump)
  0x01062BE4  00c8                    add      al, cl                         
  0x01062BE6  44                      inc      esp                            
  0x01062BE7  00a000200014            add      byte ptr [eax + 0x14002000], ah 
  0x01062BED  c8440011                enter    0x44, 0x11                     
  0x01062BF1  0020                    add      byte ptr [eax], ah             
  0x01062BF3  0010                    add      byte ptr [eax], dl             
  0x01062BF5  de06                    fiadd    word ptr [esi]                 
  0x01062BF7  0005000000a0            add      byte ptr [0xa0000000], al      
  0x01062BFD  0c18                    or       al, 0x18                       
  0x01062BFF  00bac8440014            add      byte ptr [edx + 0x140044c8], bh 
  0x01062C05  0020                    add      byte ptr [eax], ah             
  0x01062C07  0011                    add      byte ptr [ecx], dl             
  0x01062C09  0020                    add      byte ptr [eax], ah             
  0x01062C0B  0000                    add      byte ptr [eax], al             
  0x01062C0D  2418                    and      al, 0x18                       
  0x01062C0F  00ba0020000c            add      byte ptr [edx + 0xc002000], bh 
  0x01062C15  0000                    add      byte ptr [eax], al             
  0x01062C17  0013                    add      byte ptr [ebx], dl             
  0x01062C19  c84600e1                enter    0x46, -0x1f                    
  0x01062C1D  0020                    add      byte ptr [eax], ah             
  0x01062C1F  0010                    add      byte ptr [eax], dl             
  0x01062C21  de06                    fiadd    word ptr [esi]                 
  0x01062C23  0003                    add      byte ptr [ebx], al             
  0x01062C25  0000                    add      byte ptr [eax], al             
  0x01062C27  0000                    add      byte ptr [eax], al             
  0x01062C29  c84600e1                enter    0x46, -0x1f                    
  0x01062C2D  4c                      dec      esp                            
  0x01062C2E  56                      push     esi                            
  0x01062C2F  0000                    add      byte ptr [eax], al             
  0x01062C31  6456                    push     esi                            
  0x01062C33  000c00                  add      byte ptr [eax + eax], cl       
  0x01062C36  0000                    add      byte ptr [eax], al             
  0x01062C38  004039                  add      byte ptr [eax + 0x39], al      
  0x01062C3B  0000                    add      byte ptr [eax], al             
  0x01062C3D  3d23000049              cmp      eax, 0x49000023                
  0x01062C42  2000                    and      byte ptr [eax], al             
  0x01062C44  004d20                  add      byte ptr [ebp + 0x20], cl      
  0x01062C47  0012                    add      byte ptr [edx], dl             
  0x01062C49  51                      push     ecx                            
  0x01062C4A  0400                    add      al, 0                          
  0x01062C4C  16                      push     ss                             
  0x01062C4D  55                      push     ebp                            
  0x01062C4E  0400                    add      al, 0                          
  0x01062C50  10d9                    adc      cl, bl                         
  0x01062C52  06                      push     es                             
  0x01062C53  000400                  add      byte ptr [eax + eax], al       
  0x01062C56  0000                    add      byte ptr [eax], al             
  0x01062C58  00d9                    add      cl, bl                         
  0x01062C5A  46                      inc      esi                            
  0x01062C5B  0000                    add      byte ptr [eax], al             
  0x01062C5D  b2b0                    mov      dl, 0xb0                       
  0x01062C5F  0000                    add      byte ptr [eax], al             
  0x01062C61  56                      push     esi                            
  0x01062C62  44                      inc      esp                            
  0x01062C63  0000                    add      byte ptr [eax], al             
  0x01062C66  3800                    cmp      byte ptr [eax], al             
  0x01062C68  001c23                  add      byte ptr [ebx], bl             
  0x01062C6B  0000                    add      byte ptr [eax], al             
  0x01062C6D  41                      inc      ecx                            
  0x01062C6E  2000                    and      byte ptr [eax], al             
  0x01062C70  004520                  add      byte ptr [ebp + 0x20], al      
  0x01062C73  0012                    add      byte ptr [edx], dl             
  0x01062C75  48                      dec      eax                            
  0x01062C76  0400                    add      al, 0                          
  0x01062C78  16                      push     ss                             
  0x01062C79  4c                      dec      esp                            
  0x01062C7A  0400                    add      al, 0                          
  0x01062C7C  0002                    add      byte ptr [edx], al             
  0x01062C7E  3800                    cmp      byte ptr [eax], al             
  0x01062C80  00f4                    add      ah, dh                         
  0x01062C82  7200                    jb       0x1062c84                      
  0x01062C86  ff00                    inc      dword ptr [eax]                
  0x01062C88  0002                    add      byte ptr [edx], al             
  0x01062C8A  3c00                    cmp      al, 0                          
  0x01062C8C  00f4                    add      ah, dh                         
  0x01062C8E  7600                    jbe      0x1062c90                      
  0x01062C92  ff00                    inc      dword ptr [eax]                
  0x01062C94  0088d000d4ca            add      byte ptr [eax - 0x352bff30], cl 
  0x01062C9A  d500                    aad      0                              
  0x01062C9C  f30020                  add      byte ptr [eax], ah             
  0x01062C9F  00c8                    add      al, cl                         
  0x01062CA1  59                      pop      ecx                            
  0x01062CA2  56                      push     esi                            
  0x01062CA3  00eb                    add      bl, ch                         
  0x01062CA5  88d0                    mov      al, dl                         
  0x01062CA7  00903f060005            add      byte ptr [eax + 0x500063f], dl 
  0x01062CAD  0000                    add      byte ptr [eax], al             
  0x01062CAF  00d4                    add      ah, dl                         
  0x01062CB1  cad500                  retf     0xd5                           
  0x01062CB4  f35d                    pop      ebp                            
  0x01062CB6  57                      push     edi                            
  0x01062CB7  00c8                    add      al, cl                         
  0x01062CB9  59                      pop      ecx                            
  0x01062CBA  56                      push     esi                            
  0x01062CBB  00eb                    add      bl, ch                         
  0x01062CBD  88d0                    mov      al, dl                         
  0x01062CBF  0000                    add      byte ptr [eax], al             
  0x01062CC1  5d                      pop      ebp                            
  0x01062CC2  57                      push     edi                            
  0x01062CC3  0000                    add      byte ptr [eax], al             
  0x01062CC5  40                      inc      eax                            
  0x01062CC6  2000                    and      byte ptr [eax], al             
  0x01062CC8  00442000                add      byte ptr [eax], al             
  0x01062CCC  007f38                  add      byte ptr [edi + 0x38], bh      
  0x01062CCF  0000                    add      byte ptr [eax], al             
  0x01062CD1  1a23                    sbb      ah, byte ptr [ebx]             
  0x01062CD3  0000                    add      byte ptr [eax], al             
  0x01062CD5  1c23                    sbb      al, 0x23                       
  0x01062CD7  0000                    add      byte ptr [eax], al             
  0x01062CD9  1e                      push     ds                             
  0x01062CDA  2300                    and      eax, dword ptr [eax]           
  0x01062CDC  004120                  add      byte ptr [ecx + 0x20], al      
  0x01062CDF  0000                    add      byte ptr [eax], al             
  0x01062CE1  45                      inc      ebp                            
  0x01062CE2  2000                    and      byte ptr [eax], al             
  0x01062CE4  004020                  add      byte ptr [eax + 0x20], al      
  0x01062CE7  0000                    add      byte ptr [eax], al             
  0x01062CE9  4a                      dec      edx                            
  0x01062CEA  2000                    and      byte ptr [eax], al             
  0x01062CEC  00442000                add      byte ptr [eax], al             
  0x01062CF0  004e20                  add      byte ptr [esi + 0x20], cl      
  0x01062CF3  0000                    add      byte ptr [eax], al             
  0x01062CF5  0238                    add      bh, byte ptr [eax]             
  0x01062CF7  0000                    add      byte ptr [eax], al             
  0x01062CF9  f4                      hlt                                     
  0x01062CFA  7200                    jb       0x1062cfc                      
  0x01062CFE  ff00                    inc      dword ptr [eax]                
  0x01062D00  0002                    add      byte ptr [edx], al             
  0x01062D02  3c00                    cmp      al, 0                          
  0x01062D04  00f4                    add      ah, dh                         
  0x01062D06  7600                    jbe      0x1062d08                      
  0x01062D0A  ff00                    inc      dword ptr [eax]                
  0x01062D0C  0088d000d4ca            add      byte ptr [eax - 0x352bff30], cl 
  0x01062D12  d500                    aad      0                              
  0x01062D14  f30020                  add      byte ptr [eax], ah             
  0x01062D17  00c8                    add      al, cl                         
  0x01062D19  7956                    jns      0x1062d71                      
  0x01062D1B  00eb                    add      bl, ch                         
  0x01062D1D  88d0                    mov      al, dl                         
  0x01062D1F  00903f060005            add      byte ptr [eax + 0x500063f], dl 
  0x01062D25  0000                    add      byte ptr [eax], al             
  0x01062D27  00d4                    add      ah, dl                         
  0x01062D29  cad500                  retf     0xd5                           
  0x01062D2C  f37d5f                  jge      0x1062d8e                      
  0x01062D2F  00c8                    add      al, cl                         
  0x01062D31  7956                    jns      0x1062d89                      
  0x01062D33  00eb                    add      bl, ch                         
  0x01062D35  88d0                    mov      al, dl                         
  0x01062D37  0000                    add      byte ptr [eax], al             
  0x01062D39  7d5f                    jge      0x1062d9a                      
  0x01062D3B  000c00                  add      byte ptr [eax + eax], cl       
  0x01062D3E  0000                    add      byte ptr [eax], al             
  0x01062D40  00c0                    add      al, al                         
  0x01062D42  f1                      int1                                    
  0x01062D43  0000                    add      byte ptr [eax], al             
  0x01062D45  da4d00                  fimul    dword ptr [ebp]                
  0x01062D48  c8d84e00                enter    0x4ed8, 0                      
  0x01062D4C  eb00                    jmp      0x1062d4e                      
                                        ; XREF: 0x01062D4C (jump)
  0x01062D4E  2000                    and      byte ptr [eax], al             
  0x01062D50  b064                    mov      al, 0x64                       
  0x01062D52  5f                      pop      edi                            
  0x01062D53  0010                    add      byte ptr [eax], dl             
  0x01062D55  da06                    fiadd    dword ptr [esi]                
  0x01062D57  0006                    add      byte ptr [esi], al             
  0x01062D59  0000                    add      byte ptr [eax], al             
  0x01062D5B  00a7c0f10000            add      byte ptr [edi + 0xf1c0], ah    
  0x01062D61  da4d00                  fimul    dword ptr [ebp]                
  0x01062D64  c8d84e00                enter    0x4ed8, 0                      
  0x01062D68  eb5c                    jmp      0x1062dc6                      
  0x01062D6A  56                      push     esi                            
  0x01062D6B  00b0645f00a7            add      byte ptr [eax - 0x58ffa09c], dh 
                                        ; XREF: 0x01062D19 (cond_jump)
  0x01062D71  0020                    add      byte ptr [eax], ah             
  0x01062D73  0000                    add      byte ptr [eax], al             
  0x01062D75  5c                      pop      esp                            
  0x01062D76  56                      push     esi                            
  0x01062D77  000c00                  add      byte ptr [eax + eax], cl       
  0x01062D7A  0000                    add      byte ptr [eax], al             
  0x01062D7C  00c0                    add      al, al                         
  0x01062D7E  f1                      int1                                    
  0x01062D7F  0000                    add      byte ptr [eax], al             
  0x01062D81  da4d00                  fimul    dword ptr [ebp]                
  0x01062D84  c8e14e00                enter    0x4ee1, 0                      
  0x01062D88  eb00                    jmp      0x1062d8a                      
                                        ; XREF: 0x01062D88 (jump)
  0x01062D8A  2000                    and      byte ptr [eax], al             
  0x01062D8C  b0d8                    mov      al, 0xd8                       
                                        ; XREF: 0x01062D2C (cond_jump)
  0x01062D8E  4e                      dec      esi                            
  0x01062D8F  00a7d94400c8            add      byte ptr [edi - 0x37ffbb27], ah 
  0x01062D95  645f                    pop      edi                            
  0x01062D97  00eb                    add      bl, ch                         
  0x01062D99  5c                      pop      esp                            
                                        ; XREF: 0x01062D39 (cond_jump)
  0x01062D9A  56                      push     esi                            
  0x01062D9B  00b0655f0010            add      byte ptr [eax + 0x10005f65], dh 
  0x01062DA1  da06                    fiadd    dword ptr [esi]                
  0x01062DA3  000a                    add      byte ptr [edx], cl             
  0x01062DA5  0000                    add      byte ptr [eax], al             
  0x01062DA7  00a7c0f10000            add      byte ptr [edi + 0xf1c0], ah    
  0x01062DAD  da4d00                  fimul    dword ptr [ebp]                
  0x01062DB0  c8e14e00                enter    0x4ee1, 0                      
  0x01062DB4  eb5d                    jmp      0x1062e13                      
  0x01062DB6  56                      push     esi                            
  0x01062DB7  00b0d84e00a7            add      byte ptr [eax - 0x58ffb128], dh 
  0x01062DBD  d94400c8                fld      dword ptr [eax + eax - 0x38]   
  0x01062DC1  645f                    pop      edi                            
  0x01062DC3  00eb                    add      bl, ch                         
  0x01062DC5  5c                      pop      esp                            
                                        ; XREF: 0x01062D68 (jump)
  0x01062DC6  56                      push     esi                            
  0x01062DC7  00b0655f00a7            add      byte ptr [eax - 0x58ffa09b], dh 
  0x01062DCD  0020                    add      byte ptr [eax], ah             
  0x01062DCF  0000                    add      byte ptr [eax], al             
  0x01062DD1  5d                      pop      ebp                            
  0x01062DD2  56                      push     esi                            
  0x01062DD3  000c00                  add      byte ptr [eax + eax], cl       
  0x01062DD6  0000                    add      byte ptr [eax], al             
  0x01062DD8  00c0                    add      al, al                         
  0x01062DDA  f1                      int1                                    
  0x01062DDB  0000                    add      byte ptr [eax], al             
  0x01062DDD  da4d00                  fimul    dword ptr [ebp]                
  0x01062DE0  a8c8                    test     al, 0xc8                       
  0x01062DE2  4e                      dec      esi                            
  0x01062DE3  00bb002000e0            add      byte ptr [ebx - 0x1fffe000], bh 
  0x01062DE9  4d                      dec      ebp                            
  0x01062DEA  57                      push     edi                            
  0x01062DEB  0010                    add      byte ptr [eax], dl             
  0x01062DED  da06                    fiadd    dword ptr [esi]                
  0x01062DEF  0006                    add      byte ptr [esi], al             
  0x01062DF1  0000                    add      byte ptr [eax], al             
  0x01062DF3  00c7                    add      bh, al                         
  0x01062DF5  c0f100                  sal      cl, 0                          
  0x01062DF8  00da                    add      dl, bl                         
  0x01062DFA  4d                      dec      ebp                            
  0x01062DFB  00a8c84e00bb            add      byte ptr [eax - 0x44ffb138], ch 
  0x01062E01  4c                      dec      esp                            
  0x01062E02  56                      push     esi                            
  0x01062E03  00e0                    add      al, ah                         
  0x01062E05  4d                      dec      ebp                            
  0x01062E06  57                      push     edi                            
  0x01062E07  00c7                    add      bh, al                         
  0x01062E09  0020                    add      byte ptr [eax], ah             
  0x01062E0B  0000                    add      byte ptr [eax], al             
  0x01062E0D  4c                      dec      esp                            
  0x01062E0E  56                      push     esi                            
  0x01062E0F  000c00                  add      byte ptr [eax + eax], cl       
  0x01062E12  0000                    add      byte ptr [eax], al             
  0x01062E14  00c1                    add      cl, al                         
  0x01062E16  f1                      int1                                    
  0x01062E17  0000                    add      byte ptr [eax], al             
  0x01062E19  da4d00                  fimul    dword ptr [ebp]                
  0x01062E1C  a8e1                    test     al, 0xe1                       
  0x01062E1E  4e                      dec      esi                            
  0x01062E1F  00bbe04e00e0            add      byte ptr [ebx - 0x1fffb120], bh 
  0x01062E25  c84400c7                enter    0x44, -0x39                    
  0x01062E29  55                      push     ebp                            
  0x01062E2A  57                      push     edi                            
  0x01062E2B  00b8e14e00ab            add      byte ptr [eax - 0x54ffb11f], bh 
  0x01062E31  5c                      pop      esp                            
  0x01062E32  56                      push     esi                            
  0x01062E33  00e0                    add      al, ah                         
  0x01062E35  c9                      leave                                   
  0x01062E36  44                      inc      esp                            
  0x01062E37  00c7                    add      bh, al                         
  0x01062E39  4d                      dec      ebp                            
  0x01062E3A  57                      push     edi                            
  0x01062E3B  0010                    add      byte ptr [eax], dl             
  0x01062E3D  da06                    fiadd    dword ptr [esi]                
  0x01062E3F  000b                    add      byte ptr [ebx], cl             
  0x01062E41  0000                    add      byte ptr [eax], al             
  0x01062E43  0000                    add      byte ptr [eax], al             
  0x01062E45  c1f100                  sal      ecx, 0                         
  0x01062E48  00da                    add      dl, bl                         
  0x01062E4A  4d                      dec      ebp                            
  0x01062E4B  00a8e14e00bb            add      byte ptr [eax - 0x44ffb11f], ch 
  0x01062E51  0cc8                    or       al, 0xc8                       
  0x01062E53  00e0                    add      al, ah                         
  0x01062E55  c84400c7                enter    0x44, -0x39                    
  0x01062E59  55                      push     ebp                            
  0x01062E5A  57                      push     edi                            
  0x01062E5B  00b8e14e00ab            add      byte ptr [eax - 0x54ffb11f], bh 
  0x01062E61  5c                      pop      esp                            
  0x01062E62  56                      push     esi                            
  0x01062E63  00e0                    add      al, ah                         
  0x01062E65  c9                      leave                                   
  0x01062E66  44                      inc      esp                            
  0x01062E67  00c7                    add      bh, al                         
  0x01062E69  4d                      dec      ebp                            
  0x01062E6A  57                      push     edi                            
  0x01062E6B  0000                    add      byte ptr [eax], al             
  0x01062E6D  4c                      dec      esp                            
  0x01062E6E  56                      push     esi                            
  0x01062E6F  000c00                  add      byte ptr [eax + eax], cl       
  0x01062E72  0000                    add      byte ptr [eax], al             
  0x01062E74  00d8                    add      al, bl                         
  0x01062E76  56                      push     esi                            
  0x01062E77  0010                    add      byte ptr [eax], dl             
  0x01062E79  d906                    fld      dword ptr [esi]                
  0x01062E7B  0007                    add      byte ptr [edi], al             
  0x01062E7D  0000                    add      byte ptr [eax], al             
  0x01062E7F  0001                    add      byte ptr [ecx], al             
  0x01062E81  1e                      push     ds                             
  0x01062E82  0c00                    or       al, 0                          
  0x01062E84  3e0020                  add      byte ptr ds:[eax], ah          
  0x01062E87  0003                    add      byte ptr [ebx], al             
  0x01062E89  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01062E8A  2300                    and      eax, dword ptr [eax]           
  0x01062E8C  48                      dec      eax                            
  0x01062E8D  a0020000d8              mov      al, byte ptr [0xd8000002]      
  0x01062E92  56                      push     esi                            
  0x01062E93  0000                    add      byte ptr [eax], al             
  0x01062E95  59                      pop      ecx                            
  0x01062E96  57                      push     edi                            
  0x01062E97  0000                    add      byte ptr [eax], al             
  0x01062E99  50                      push     eax                            
  0x01062E9A  2000                    and      byte ptr [eax], al             
  0x01062E9C  0c00                    or       al, 0                          
  0x01062E9E  0000                    add      byte ptr [eax], al             
  0x01062EA0  00f4                    add      ah, dh                         
  0x01062EA2  46                      inc      esi                            
  0x01062EA3  0001                    add      byte ptr [ecx], al             
  0x01062EA5  0000                    add      byte ptr [eax], al             
  0x01062EA7  0000                    add      byte ptr [eax], al             
  0x01062EA9  ae                      scasb    al, byte ptr es:[edi]          
  0x01062EAA  2300                    and      eax, dword ptr [eax]           
  0x01062EAC  55                      push     ebp                            
  0x01062EAD  3522000da4              xor      eax, 0xa40d0022                
  0x01062EB2  050000b422              add      eax, 0x22b40000                
  0x01062EB7  0010                    add      byte ptr [eax], dl             
  0x01062EB9  dc06                    fadd     qword ptr [esi]                
  0x01062EBB  0009                    add      byte ptr [ecx], cl             
  0x01062EBD  0000                    add      byte ptr [eax], al             
  0x01062EBF  0000                    add      byte ptr [eax], al             
  0x01062EC1  f4                      hlt                                     
  0x01062EC2  56                      push     esi                            
  0x01062EC3  00ff                    add      bh, bh                         
  0x01062EC6  7f00                    jg       0x1062ec8                      
                                        ; XREF: 0x01062EC6 (cond_jump)
  0x01062EC8  10dd                    adc      ch, bl                         
  0x01062ECA  06                      push     es                             
  0x01062ECB  000400                  add      byte ptr [eax + eax], al       
  0x01062ECE  0000                    add      byte ptr [eax], al             
  0x01062ED0  00dc                    add      ah, bl                         
  0x01062ED2  44                      inc      esp                            
  0x01062ED3  004500                  add      byte ptr [ebp], al             
  0x01062ED6  2000                    and      byte ptr [eax], al             
  0x01062ED8  40                      inc      eax                            
  0x01062ED9  7002                    jo       0x1062edd                      
  0x01062EDB  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01062ED9 (cond_jump)
  0x01062EDD  4d                      dec      ebp                            
  0x01062EDE  54                      push     esp                            
  0x01062EDF  0000                    add      byte ptr [eax], al             
  0x01062EE1  352200004f              xor      eax, 0x4f000022                
  0x01062EE6  2300                    and      eax, dword ptr [eax]           
  0x01062EE8  0be2                    or       esp, edx                       
  0x01062EEA  56                      push     esi                            
  0x01062EEB  0006                    add      byte ptr [esi], al             
  0x01062EED  2405                    and      al, 5                          
  0x01062EEF  0000                    add      byte ptr [eax], al             
  0x01062EF1  f4                      hlt                                     
  0x01062EF2  44                      inc      esp                            
  0x01062EF3  000f                    add      byte ptr [edi], cl             
  0x01062EF5  0000                    add      byte ptr [eax], al             
  0x01062EF7  004500                  add      byte ptr [ebp], al             
  0x01062EFA  2000                    and      byte ptr [eax], al             
  0x01062EFC  40                      inc      eax                            
  0x01062EFD  7002                    jo       0x1062f01                      
  0x01062EFF  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01062EFD (cond_jump)
  0x01062F01  62540000                bound    edx, qword ptr [eax + eax]     
  0x01062F05  8521                    test     dword ptr [ecx], esp           
  0x01062F07  0010                    add      byte ptr [eax], dl             
  0x01062F09  dc06                    fadd     qword ptr [esi]                
  0x01062F0B  000400                  add      byte ptr [eax + eax], al       
  0x01062F0E  0000                    add      byte ptr [eax], al             
  0x01062F10  00e5                    add      ch, ah                         
  0x01062F12  56                      push     esi                            
  0x01062F13  00648521                add      byte ptr [ebp + eax*4 + 0x21], ah 
  0x01062F17  0000                    add      byte ptr [eax], al             
  0x01062F19  4d                      dec      ebp                            
  0x01062F1A  54                      push     esp                            
  0x01062F1B  0000                    add      byte ptr [eax], al             
  0x01062F1D  3522005987              xor      eax, 0x87590022                
  0x01062F22  2300                    and      eax, dword ptr [eax]           
  0x01062F24  00f4                    add      ah, dh                         
  0x01062F26  45                      inc      ebp                            
  0x01062F27  0002                    add      byte ptr [edx], al             
  0x01062F29  0000                    add      byte ptr [eax], al             
  0x01062F2B  0000                    add      byte ptr [eax], al             
  0x01062F2D  e556                    in       eax, 0x56                      
  0x01062F2F  0065f4                  add      byte ptr [ebp - 0xc], ah       
  0x01062F32  45                      inc      ebp                            
  0x01062F33  00fe                    add      dh, bh                         
  0x01062F36  ff00                    inc      dword ptr [eax]                
  0x01062F38  17                      pop      ss                             
  0x01062F39  7405                    je       0x1062f40                      
  0x01062F3B  0065f4                  add      byte ptr [ebp - 0xc], ah       
  0x01062F3E  45                      inc      ebp                            
  0x01062F3F  0002                    add      byte ptr [edx], al             
  0x01062F41  0000                    add      byte ptr [eax], al             
  0x01062F43  0011                    add      byte ptr [ecx], dl             
  0x01062F45  94                      xchg     esp, eax                       
  0x01062F46  0500584d20              add      eax, 0x204d5800                
  0x01062F4B  007d00                  add      byte ptr [ebp], bh             
  0x01062F4E  2000                    and      byte ptr [eax], al             
  0x01062F50  4d                      dec      ebp                            
  0x01062F51  7405                    je       0x1062f58                      
  0x01062F53  00d6                    add      dh, dl                         
  0x01062F55  97                      xchg     edi, eax                       
  0x01062F56  050000e556              add      eax, 0x56e50000                
  0x01062F5B  0065f4                  add      byte ptr [ebp - 0xc], ah       
  0x01062F5E  45                      inc      ebp                            
  0x01062F5F  00fe                    add      dh, bh                         
  0x01062F62  ff00                    inc      dword ptr [eax]                
  0x01062F64  13740500                adc      esi, dword ptr [ebp + eax]     
  0x01062F68  65f4                    hlt                                     
  0x01062F6A  45                      inc      ebp                            
  0x01062F6B  0002                    add      byte ptr [edx], al             
  0x01062F6D  0000                    add      byte ptr [eax], al             
  0x01062F6F  0006                    add      byte ptr [esi], al             
  0x01062F71  94                      xchg     esp, eax                       
  0x01062F72  0500584d20              add      eax, 0x204d5800                
  0x01062F77  007d00                  add      byte ptr [ebp], bh             
  0x01062F7A  2000                    and      byte ptr [eax], al             
  0x01062F7C  42                      inc      edx                            
  0x01062F7D  7405                    je       0x1062f84                      
  0x01062F7F  00cb                    add      bl, cl                         
  0x01062F81  97                      xchg     edi, eax                       
  0x01062F82  0500d5a705              add      eax, 0x5a7d500                 
  0x01062F87  005c4520                add      byte ptr [ebp + eax*2 + 0x20], bl 
  0x01062F8B  000da4050000            add      byte ptr [0x5a4], cl           
  0x01062F91  e556                    in       eax, 0x56                      
  0x01062F93  00540020                add      byte ptr [eax + eax + 0x20], dl 
  0x01062F97  0000                    add      byte ptr [eax], al             
  0x01062F99  4d                      dec      ebp                            
  0x01062F9A  54                      push     esp                            
  0x01062F9B  0000                    add      byte ptr [eax], al             
  0x01062F9D  e556                    in       eax, 0x56                      
  0x01062F9F  0050f4                  add      byte ptr [eax - 0xc], dl       
  0x01062FA2  45                      inc      ebp                            
  0x01062FA3  0002                    add      byte ptr [edx], al             
  0x01062FA5  0000                    add      byte ptr [eax], al             
  0x01062FA7  0000                    add      byte ptr [eax], al             
  0x01062FA9  45                      inc      ebp                            
  0x01062FAA  54                      push     esp                            
  0x01062FAB  00c0                    add      al, al                         
  0x01062FAD  0f05                    syscall                                 
  0x01062FAF  0054f445                add      byte ptr [esp + esi*8 + 0x45], dl 
  0x01062FB3  0002                    add      byte ptr [edx], al             
  0x01062FB5  0000                    add      byte ptr [eax], al             
  0x01062FB7  0000                    add      byte ptr [eax], al             
  0x01062FB9  6554                    push     esp                            
  0x01062FBB  00c7                    add      bh, al                         
  0x01062FBD  0f05                    syscall                                 
  0x01062FBF  0000                    add      byte ptr [eax], al             
  0x01062FC1  4e                      dec      esi                            
  0x01062FC2  2300                    and      eax, dword ptr [eax]           
  0x01062FC4  034d20                  add      ecx, dword ptr [ebp + 0x20]    
  0x01062FC7  0007                    add      byte ptr [edi], al             
  0x01062FC9  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01062FCA  050000e256              add      eax, 0x56e20000                
  0x01062FCF  00540020                add      byte ptr [eax + eax + 0x20], dl 
  0x01062FD3  0000                    add      byte ptr [eax], al             
  0x01062FD5  62540000                bound    edx, qword ptr [eax + eax]     
  0x01062FD9  e556                    in       eax, 0x56                      
  0x01062FDB  005000                  add      byte ptr [eax], dl             
  0x01062FDE  2000                    and      byte ptr [eax], al             
  0x01062FE0  006554                  add      byte ptr [ebp + 0x54], ah      
  0x01062FE3  0000                    add      byte ptr [eax], al             
  0x01062FE5  e256                    loop     0x106303d                      
  0x01062FE7  00540020                add      byte ptr [eax + eax + 0x20], dl 
  0x01062FEB  0000                    add      byte ptr [eax], al             
  0x01062FED  62540000                bound    edx, qword ptr [eax + eax]     
  0x01062FF1  e556                    in       eax, 0x56                      
  0x01062FF3  0050f4                  add      byte ptr [eax - 0xc], dl       
  0x01062FF6  45                      inc      ebp                            
  0x01062FF7  0002                    add      byte ptr [edx], al             
  0x01062FF9  0000                    add      byte ptr [eax], al             
  0x01062FFB  005865                  add      byte ptr [eax + 0x65], bl      
  0x01062FFE  54                      push     esp                            
  0x01062FFF  008b0f050000            add      byte ptr [ebx + 0x50f], cl     
  0x01063005  35220000e2              xor      eax, 0xe2000022                
  0x0106300A  45                      inc      ebp                            
  0x0106300B  0010                    add      byte ptr [eax], dl             
  0x0106300D  dc06                    fadd     qword ptr [esi]                
  0x0106300F  000500000000            add      byte ptr [0], al               
  0x01063015  e556                    in       eax, 0x56                      
  0x01063017  006000                  add      byte ptr [eax], ah             
  0x0106301A  2000                    and      byte ptr [eax], al             
  0x0106301C  00852100004d            add      byte ptr [ebp + 0x4d000021], al 
  0x01063022  54                      push     esp                            
  0x01063023  0000                    add      byte ptr [eax], al             
  0x01063025  ae                      scasb    al, byte ptr es:[edi]          
  0x01063026  2300                    and      eax, dword ptr [eax]           
  0x01063028  55                      push     ebp                            
  0x01063029  35220009a4              xor      eax, 0xa4090022                
  0x0106302E  050000b422              add      eax, 0x22b40000                
  0x01063033  0010                    add      byte ptr [eax], dl             
  0x01063035  dc06                    fadd     qword ptr [esi]                
  0x01063037  0006                    add      byte ptr [esi], al             
  0x01063039  0000                    add      byte ptr [eax], al             
  0x0106303B  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01062FE5 (cond_jump)
  0x0106303D  cd44                    int      0x44                           
  0x0106303F  0010                    add      byte ptr [eax], dl             
  0x01063041  dd06                    fld      qword ptr [esi]                
  0x01063043  0002                    add      byte ptr [edx], al             
  0x01063045  0000                    add      byte ptr [eax], al             
  0x01063047  0000                    add      byte ptr [eax], al             
  0x01063049  5c                      pop      esp                            
  0x0106304A  44                      inc      esp                            
  0x0106304B  0000                    add      byte ptr [eax], al             
  0x0106304D  0000                    add      byte ptr [eax], al             
  0x0106304F  000c00                  add      byte ptr [eax + eax], cl       
  0x01063052  0000                    add      byte ptr [eax], al             
  0x01063054  00f0                    add      al, dh                         
  0x01063056  44                      inc      esp                            
  0x01063057  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106305A  0000                    add      byte ptr [eax], al             
  0x0106305C  00f0                    add      al, dh                         
  0x0106305E  56                      push     esi                            
  0x0106305F  00970b000045            add      byte ptr [edi + 0x4500000b], dl 
  0x01063065  0020                    add      byte ptr [eax], ah             
  0x01063067  0013                    add      byte ptr [ebx], dl             
  0x01063069  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106306A  0500009620              add      eax, 0x20960000                
  0x0106306F  0000                    add      byte ptr [eax], al             
  0x01063071  f4                      hlt                                     
  0x01063072  60                      pushal                                  
  0x01063073  008001000000            add      byte ptr [eax + 1], al         
  0x01063079  f4                      hlt                                     
  0x0106307A  61                      popal                                   
  0x0106307B  004102                  add      byte ptr [ecx + 2], al         
  0x0106307E  0000                    add      byte ptr [eax], al             
  0x01063080  00f4                    add      ah, dh                         
  0x01063082  56                      push     esi                            
  0x01063083  00a50b000000            add      byte ptr [ebp + 0xb], ah       
  0x01063089  c422                    les      esp, ptr [edx]                 
  0x0106308B  004000                  add      byte ptr [eax], al             
  0x0106308E  2000                    and      byte ptr [eax], al             
  0x01063090  0092210000e2            add      byte ptr [edx - 0x1dffffdf], dl 
  0x01063096  7100                    jno      0x1063098                      
                                        ; XREF: 0x01063096 (cond_jump)
  0x01063098  10d9                    adc      cl, bl                         
  0x0106309A  06                      push     es                             
  0x0106309B  000500000000            add      byte ptr [0], al               
  0x010630A1  d9440000                fld      dword ptr [eax + eax]          
  0x010630A5  e056                    loopne   0x10630fd                      
  0x010630A7  00481e                  add      byte ptr [eax + 0x1e], cl      
  0x010630AA  0c00                    or       al, 0                          
  0x010630AC  005854                  add      byte ptr [eax + 0x54], bl      
  0x010630AF  0010                    add      byte ptr [eax], dl             
  0x010630B1  0c05                    or       al, 5                          
  0x010630B3  0000                    add      byte ptr [eax], al             
  0x010630B6  56                      push     esi                            
  0x010630B7  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x010630BA  0000                    add      byte ptr [eax], al             
  0x010630BC  0300                    add      eax, dword ptr [eax]           
  0x010630BE  2000                    and      byte ptr [eax], al             
  0x010630C0  0ca4                    or       al, 0xa4                       
  0x010630C2  050000f460              add      eax, 0x60f40000                
  0x010630C7  003502000000            add      byte ptr [2], dh               
  0x010630CD  f4                      hlt                                     
  0x010630CE  61                      popal                                   
  0x010630CF  00f6                    add      dh, dh                         
  0x010630D1  0200                    add      al, byte ptr [eax]             
  0x010630D3  0000                    add      byte ptr [eax], al             
  0x010630D5  07                      pop      es                             
  0x010630D6  3900                    cmp      dword ptr [eax], eax           
  0x010630D8  10d9                    adc      cl, bl                         
  0x010630DA  06                      push     es                             
  0x010630DB  000500000000            add      byte ptr [0], al               
  0x010630E1  d9440000                fld      dword ptr [eax + eax]          
  0x010630E5  e056                    loopne   0x106313d                      
  0x010630E7  00481e                  add      byte ptr [eax + 0x1e], cl      
  0x010630EA  0c00                    or       al, 0                          
  0x010630EC  005854                  add      byte ptr [eax + 0x54], bl      
  0x010630EF  000c00                  add      byte ptr [eax + eax], cl       
  0x010630F2  0000                    add      byte ptr [eax], al             
  0x010630F4  20f4                    and      ah, dh                         
  0x010630F6  0500ffffff              add      eax, 0xffffff00                
  0x010630FB  00a0610400a0            add      byte ptr [eax - 0x5ffffb9f], ah 
  0x01063101  620400                  bound    eax, qword ptr [eax + eax]     
  0x01063104  a0640400a0              mov      al, byte ptr [0xa0000464]      
  0x01063109  650400                  add      al, 0                          
  0x0106310C  a0660400b8              mov      al, byte ptr [0xb8000466]      
  0x01063111  f30000                  add      byte ptr [eax], al             
  0x01063114  00f4                    add      ah, dh                         
  0x01063116  44                      inc      esp                            
  0x01063117  0000                    add      byte ptr [eax], al             
  0x01063119  0000                    add      byte ptr [eax], al             
  0x0106311B  004d00                  add      byte ptr [ebp], cl             
  0x0106311E  2000                    and      byte ptr [eax], al             
  0x01063120  0ca4                    or       al, 0xa4                       
  0x01063122  050000f444              add      eax, 0x44f40000                
  0x01063127  0010                    add      byte ptr [eax], dl             
  0x01063129  0000                    add      byte ptr [eax], al             
  0x0106312B  004d00                  add      byte ptr [ebp], cl             
  0x0106312E  2000                    and      byte ptr [eax], al             
  0x01063130  4a                      dec      edx                            
  0x01063131  100d00110000            adc      byte ptr [0x1100], cl          
  0x01063137  0000                    add      byte ptr [eax], al             
  0x01063139  0030                    add      byte ptr [eax], dh             
  0x0106313B  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x010630E5 (cond_jump)
  0x0106313D  f4                      hlt                                     
  0x0106313E  56                      push     esi                            
  0x0106313F  0000                    add      byte ptr [eax], al             
  0x01063141  0000                    add      byte ptr [eax], al             
  0x01063143  0000                    add      byte ptr [eax], al             
  0x01063145  f4                      hlt                                     
  0x01063146  57                      push     edi                            
  0x01063147  00ff                    add      bh, bh                         
  0x0106314A  ff00                    inc      dword ptr [eax]                
  0x0106314C  0c00                    or       al, 0                          
  0x0106314E  0000                    add      byte ptr [eax], al             
  0x01063150  1300                    adc      eax, dword ptr [eax]           
  0x01063152  2000                    and      byte ptr [eax], al             
  0x01063154  007056                  add      byte ptr [eax + 0x56], dh      
  0x01063157  0012                    add      byte ptr [edx], dl             
  0x01063159  0900                    or       dword ptr [eax], eax           
  0x0106315B  0000                    add      byte ptr [eax], al             
  0x0106315D  0030                    add      byte ptr [eax], dh             
  0x0106315F  0000                    add      byte ptr [eax], al             
  0x01063161  f4                      hlt                                     
  0x01063162  56                      push     esi                            
  0x01063163  0000                    add      byte ptr [eax], al             
  0x01063165  0000                    add      byte ptr [eax], al             
  0x01063167  0000                    add      byte ptr [eax], al             
  0x01063169  f4                      hlt                                     
  0x0106316A  57                      push     edi                            
  0x0106316B  0008                    add      byte ptr [eax], cl             
  0x0106316D  06                      push     es                             
  0x0106316E  0000                    add      byte ptr [eax], al             
  0x01063170  0c00                    or       al, 0                          
  0x01063172  0000                    add      byte ptr [eax], al             
  0x01063174  5c                      pop      esp                            
  0x01063175  08050080100d            or       byte ptr [0xd108000], al       
  0x0106317B  009600000000            add      byte ptr [esi], dl             
  0x01063182  56                      push     esi                            
  0x01063183  00960b000003            add      byte ptr [esi + 0x300000b], dl 
  0x01063189  0020                    add      byte ptr [eax], ah             
  0x0106318B  005374                  add      byte ptr [ebx + 0x74], dl      
  0x0106318E  050080100d              add      eax, 0xd108000                 
  0x01063193  00c4                    add      ah, al                         
  0x01063195  0000                    add      byte ptr [eax], al             
  0x01063197  0000                    add      byte ptr [eax], al             
  0x0106319A  56                      push     esi                            
  0x0106319B  00960b000003            add      byte ptr [esi + 0x300000b], dl 
  0x010631A1  0020                    add      byte ptr [eax], ah             
  0x010631A3  004d74                  add      byte ptr [ebp + 0x74], cl      
  0x010631A6  050080100d              add      eax, 0xd108000                 
  0x010631AB  006e01                  add      byte ptr [esi + 1], ch         
  0x010631AE  0000                    add      byte ptr [eax], al             
  0x010631B0  80100d                  adc      byte ptr [eax], 0xd            
  0x010631B3  00b101000080            add      byte ptr [ecx - 0x7fffffff], dh 
  0x010631B9  100d00f40100            adc      byte ptr [0x1f400], cl         
  0x010631BF  0000                    add      byte ptr [eax], al             
  0x010631C1  002400                  add      byte ptr [eax + eax], ah       
  0x010631C4  007044                  add      byte ptr [eax + 0x44], dh      
  0x010631C7  0031                    add      byte ptr [ecx], dh             
  0x010631C9  0900                    or       dword ptr [eax], eax           
  0x010631CB  0000                    add      byte ptr [eax], al             
  0x010631CE  56                      push     esi                            
  0x010631CF  00410b                  add      byte ptr [ecx + 0xb], al       
  0x010631D2  0000                    add      byte ptr [eax], al             
  0x010631D4  00f0                    add      al, dh                         
  0x010631D6  44                      inc      esp                            
  0x010631D7  00970b000045            add      byte ptr [edi + 0x4500000b], dl 
  0x010631DD  0020                    add      byte ptr [eax], ah             
  0x010631DF  0009                    add      byte ptr [ecx], cl             
  0x010631E1  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010631E2  050080100d              add      eax, 0xd108000                 
  0x010631E7  004601                  add      byte ptr [esi + 1], al         
  0x010631EA  0000                    add      byte ptr [eax], al             
  0x010631EC  80100d                  adc      byte ptr [eax], 0xd            
  0x010631EF  002f                    add      byte ptr [edi], ch             
  0x010631F1  0200                    add      al, byte ptr [eax]             
  0x010631F3  0000                    add      byte ptr [eax], al             
  0x010631F5  7055                    jo       0x106324c                      
  0x010631F7  0031                    add      byte ptr [ecx], dh             
  0x010631F9  0900                    or       dword ptr [eax], eax           
  0x010631FB  0080100d0017            add      byte ptr [eax + 0x17000d10], al 
  0x01063201  0300                    add      eax, dword ptr [eax]           
  0x01063203  0080100d002f            add      byte ptr [eax + 0x2f000d10], al 
  0x01063209  0300                    add      eax, dword ptr [eax]           
  0x0106320B  0080100d003e            add      byte ptr [eax + 0x3e000d10], al 
  0x01063211  0300                    add      eax, dword ptr [eax]           
  0x01063213  0080100d0099            add      byte ptr [eax - 0x66fff2f0], al 
  0x01063219  0300                    add      eax, dword ptr [eax]           
  0x0106321B  0080100d0055            add      byte ptr [eax + 0x55000d10], al 
  0x01063221  0300                    add      eax, dword ptr [eax]           
  0x01063223  0000                    add      byte ptr [eax], al             
  0x01063226  56                      push     esi                            
  0x01063227  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106322A  0000                    add      byte ptr [eax], al             
  0x0106322C  0300                    add      eax, dword ptr [eax]           
  0x0106322E  2000                    and      byte ptr [eax], al             
  0x01063230  0a10                    or       dl, byte ptr [eax]             
  0x01063232  0d00400400              or       eax, 0x44000                   
  0x01063237  0080100d00a2            add      byte ptr [eax - 0x5dfff2f0], al 
  0x0106323D  0300                    add      eax, dword ptr [eax]           
  0x0106323F  0080100d00cf            add      byte ptr [eax - 0x30fff2f0], al 
  0x01063245  0300                    add      eax, dword ptr [eax]           
  0x01063247  0080100d00ea            add      byte ptr [eax - 0x15fff2f0], al 
  0x0106324D  0300                    add      eax, dword ptr [eax]           
  0x0106324F  0080100d0081            add      byte ptr [eax - 0x7efff2f0], al 
  0x01063256  ff00                    inc      dword ptr [eax]                
  0x01063258  1300                    adc      eax, dword ptr [eax]           
  0x0106325A  2000                    and      byte ptr [eax], al             
  0x0106325C  1b10                    sbb      edx, dword ptr [eax]           
  0x0106325E  2100                    and      dword ptr [eax], eax           
  0x01063260  0c00                    or       al, 0                          
  0x01063262  0000                    add      byte ptr [eax], al             
  0x01063264  005820                  add      byte ptr [eax + 0x20], bl      
  0x01063267  0000                    add      byte ptr [eax], al             
  0x01063269  d8440000                fadd     dword ptr [eax + eax]          
  0x0106326D  7044                    jo       0x10632b3                      
  0x0106326F  00420b                  add      byte ptr [edx + 0xb], al       
  0x01063272  0000                    add      byte ptr [eax], al             
  0x01063274  00d8                    add      al, bl                         
  0x01063276  44                      inc      esp                            
  0x01063277  0000                    add      byte ptr [eax], al             
  0x01063279  7044                    jo       0x10632bf                      
  0x0106327B  00430b                  add      byte ptr [ebx + 0xb], al       
  0x0106327E  0000                    add      byte ptr [eax], al             
  0x01063280  00d8                    add      al, bl                         
  0x01063282  44                      inc      esp                            
  0x01063283  0000                    add      byte ptr [eax], al             
  0x01063285  7044                    jo       0x10632cb                      
  0x01063287  00440b00                add      byte ptr [ebx + ecx], al       
  0x0106328B  0000                    add      byte ptr [eax], al             
  0x0106328D  d85700                  fcom     dword ptr [edi]                
  0x01063290  90                      nop                                     
  0x01063291  180c00                  sbb      byte ptr [eax + eax], cl       
  0x01063294  2420                    and      al, 0x20                       
  0x01063296  0000                    add      byte ptr [eax], al             
  0x01063298  007050                  add      byte ptr [eax + 0x50], dh      
  0x0106329B  007b0b                  add      byte ptr [ebx + 0xb], bh       
  0x0106329E  0000                    add      byte ptr [eax], al             
  0x010632A0  90                      nop                                     
  0x010632A1  180c00                  sbb      byte ptr [eax + eax], cl       
  0x010632A4  1b10                    sbb      edx, dword ptr [eax]           
  0x010632A6  0000                    add      byte ptr [eax], al             
  0x010632A8  007050                  add      byte ptr [eax + 0x50], dh      
  0x010632AB  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x010632AE  0000                    add      byte ptr [eax], al             
  0x010632B0  90                      nop                                     
  0x010632B1  180c00                  sbb      byte ptr [eax + eax], cl       
  0x010632B4  1830                    sbb      byte ptr [eax], dh             
  0x010632B6  0000                    add      byte ptr [eax], al             
  0x010632B8  007050                  add      byte ptr [eax + 0x50], dh      
  0x010632BB  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x010632BE  0000                    add      byte ptr [eax], al             
  0x010632C0  00d8                    add      al, bl                         
  0x010632C2  44                      inc      esp                            
  0x010632C3  0000                    add      byte ptr [eax], al             
  0x010632C5  7044                    jo       0x106330b                      
  0x010632C7  00450b                  add      byte ptr [ebp + 0xb], al       
  0x010632CA  0000                    add      byte ptr [eax], al             
  0x010632CC  00d8                    add      al, bl                         
  0x010632CE  44                      inc      esp                            
  0x010632CF  0000                    add      byte ptr [eax], al             
  0x010632D1  7044                    jo       0x1063317                      
  0x010632D3  00460b                  add      byte ptr [esi + 0xb], al       
  0x010632D6  0000                    add      byte ptr [eax], al             
  0x010632D8  00d8                    add      al, bl                         
  0x010632DA  44                      inc      esp                            
  0x010632DB  0000                    add      byte ptr [eax], al             
  0x010632DD  7044                    jo       0x1063323                      
  0x010632DF  00470b                  add      byte ptr [edi + 0xb], al       
  0x010632E2  0000                    add      byte ptr [eax], al             
  0x010632E4  00d8                    add      al, bl                         
  0x010632E6  57                      push     edi                            
  0x010632E7  0090180c0020            add      byte ptr [eax + 0x20000c18], dl 
  0x010632ED  60                      pushal                                  
  0x010632EE  0000                    add      byte ptr [eax], al             
  0x010632F0  007050                  add      byte ptr [eax + 0x50], dh      
  0x010632F3  007c0b00                add      byte ptr [ebx + ecx], bh       
  0x010632F7  0000                    add      byte ptr [eax], al             
  0x010632F9  d85700                  fcom     dword ptr [edi]                
  0x010632FC  90                      nop                                     
  0x010632FD  180c00                  sbb      byte ptr [eax + eax], cl       
  0x01063300  2310                    and      edx, dword ptr [eax]           
  0x01063302  0000                    add      byte ptr [eax], al             
  0x01063304  007050                  add      byte ptr [eax + 0x50], dh      
  0x01063307  003d02000090            add      byte ptr [0x90000002], bh      
  0x0106330D  180c00                  sbb      byte ptr [eax + eax], cl       
  0x01063310  2210                    and      dl, byte ptr [eax]             
  0x01063312  0000                    add      byte ptr [eax], al             
  0x01063314  007050                  add      byte ptr [eax + 0x50], dh      
                                        ; XREF: 0x010632D1 (cond_jump)
  0x01063317  003e                    add      byte ptr [esi], bh             
  0x01063319  0200                    add      al, byte ptr [eax]             
  0x0106331B  0090180c0021            add      byte ptr [eax + 0x21000c18], dl 
  0x01063321  1000                    adc      byte ptr [eax], al             
                                        ; XREF: 0x010632DD (cond_jump)
  0x01063323  0000                    add      byte ptr [eax], al             
  0x01063325  7050                    jo       0x1063377                      
  0x01063327  003f                    add      byte ptr [edi], bh             
  0x01063329  0200                    add      al, byte ptr [eax]             
  0x0106332B  0090180c0018            add      byte ptr [eax + 0x18000c18], dl 
  0x01063331  40                      inc      eax                            
  0x01063332  0000                    add      byte ptr [eax], al             
  0x01063334  007050                  add      byte ptr [eax + 0x50], dh      
  0x01063337  004002                  add      byte ptr [eax + 2], al         
  0x0106333A  0000                    add      byte ptr [eax], al             
  0x0106333C  00d8                    add      al, bl                         
  0x0106333E  61                      popal                                   
  0x0106333F  0000                    add      byte ptr [eax], al             
  0x01063341  06                      push     es                             
  0x01063342  3800                    cmp      byte ptr [eax], al             
  0x01063344  004820                  add      byte ptr [eax + 0x20], cl      
  0x01063347  0000                    add      byte ptr [eax], al             
  0x01063349  d95700                  fst      dword ptr [edi]                
  0x0106334C  90                      nop                                     
  0x0106334D  180c00                  sbb      byte ptr [eax + eax], cl       
  0x01063350  1a20                    sbb      ah, byte ptr [eax]             
  0x01063352  0000                    add      byte ptr [eax], al             
  0x01063354  007050                  add      byte ptr [eax + 0x50], dh      
  0x01063357  004e0b                  add      byte ptr [esi + 0xb], cl       
  0x0106335A  0000                    add      byte ptr [eax], al             
  0x0106335C  00d9                    add      cl, bl                         
  0x0106335E  57                      push     edi                            
  0x0106335F  008e5f010000            add      byte ptr [esi + 0x15f], cl     
  0x01063365  7057                    jo       0x10633be                      
  0x01063367  00490b                  add      byte ptr [ecx + 0xb], cl       
  0x0106336A  0000                    add      byte ptr [eax], al             
  0x0106336C  00d8                    add      al, bl                         
  0x0106336E  57                      push     edi                            
  0x0106336F  0090180c0018            add      byte ptr [eax + 0x18000c18], dl 
  0x01063375  800000                  add      byte ptr [eax], 0              
  0x01063378  007050                  add      byte ptr [eax + 0x50], dh      
  0x0106337B  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106337E  0000                    add      byte ptr [eax], al             
  0x01063380  90                      nop                                     
  0x01063381  180c00                  sbb      byte ptr [eax + eax], cl       
  0x01063384  208000000070            and      byte ptr [eax + 0x70000000], al 
  0x0106338A  50                      push     eax                            
  0x0106338B  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106338E  0000                    add      byte ptr [eax], al             
  0x01063390  00d8                    add      al, bl                         
  0x01063392  57                      push     edi                            
  0x01063393  0090180c0018            add      byte ptr [eax + 0x18000c18], dl 
  0x01063399  1000                    adc      byte ptr [eax], al             
  0x0106339B  0000                    add      byte ptr [eax], al             
  0x0106339D  7050                    jo       0x10633ef                      
  0x0106339F  004c0b00                add      byte ptr [ebx + ecx], cl       
  0x010633A3  0090180c0019            add      byte ptr [eax + 0x19000c18], dl 
  0x010633A9  1000                    adc      byte ptr [eax], al             
  0x010633AB  0000                    add      byte ptr [eax], al             
  0x010633AD  7050                    jo       0x10633ff                      
  0x010633AF  004a0b                  add      byte ptr [edx + 0xb], cl       
  0x010633B2  0000                    add      byte ptr [eax], al             
  0x010633B4  00d8                    add      al, bl                         
  0x010633B6  57                      push     edi                            
  0x010633B7  0000                    add      byte ptr [eax], al             
  0x010633B9  7057                    jo       0x1063412                      
  0x010633BB  004b0b                  add      byte ptr [ebx + 0xb], cl       
                                        ; XREF: 0x01063365 (cond_jump)
  0x010633BE  0000                    add      byte ptr [eax], al             
  0x010633C0  00e0                    add      al, ah                         
  0x010633C2  57                      push     edi                            
  0x010633C3  0000                    add      byte ptr [eax], al             
  0x010633C5  7057                    jo       0x106341e                      
  0x010633C7  004d0b                  add      byte ptr [ebp + 0xb], cl       
  0x010633CA  0000                    add      byte ptr [eax], al             
  0x010633CC  0c00                    or       al, 0                          
  0x010633CE  0000                    add      byte ptr [eax], al             
  0x010633D0  00f4                    add      ah, dh                         
  0x010633D2  44                      inc      esp                            
  0x010633D3  0000                    add      byte ptr [eax], al             
  0x010633D5  0000                    add      byte ptr [eax], al             
  0x010633D7  0000                    add      byte ptr [eax], al             
  0x010633D9  7044                    jo       0x106341f                      
  0x010633DB  00960b000000            add      byte ptr [esi + 0xb], dl       
  0x010633E2  56                      push     esi                            
  0x010633E3  004002                  add      byte ptr [eax + 2], al         
  0x010633E6  0000                    add      byte ptr [eax], al             
  0x010633E8  00f4                    add      ah, dh                         
  0x010633EA  44                      inc      esp                            
  0x010633EB  0009                    add      byte ptr [ecx], cl             
  0x010633ED  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x0106339D (cond_jump)
  0x010633EF  004500                  add      byte ptr [ebp], al             
  0x010633F2  2000                    and      byte ptr [eax], al             
  0x010633F4  41                      inc      ecx                            
  0x010633F5  27                      daa                                     
  0x010633F6  2000                    and      byte ptr [eax], al             
  0x010633F8  007054                  add      byte ptr [eax + 0x54], dh      
  0x010633FB  004002                  add      byte ptr [eax + 2], al         
  0x010633FE  0000                    add      byte ptr [eax], al             
  0x01063400  00f0                    add      al, dh                         
  0x01063402  56                      push     esi                            
  0x01063403  00490b                  add      byte ptr [ecx + 0xb], cl       
  0x01063406  0000                    add      byte ptr [eax], al             
  0x01063408  00f4                    add      ah, dh                         
  0x0106340A  44                      inc      esp                            
  0x0106340B  001f                    add      byte ptr [edi], bl             
  0x0106340D  0000                    add      byte ptr [eax], al             
  0x0106340F  0045f4                  add      byte ptr [ebp - 0xc], al       
                                        ; XREF: 0x010633B9 (cond_jump)
  0x01063412  45                      inc      ebp                            
  0x01063413  0000                    add      byte ptr [eax], al             
  0x01063415  0000                    add      byte ptr [eax], al             
  0x01063417  004127                  add      byte ptr [ecx + 0x27], al      
  0x0106341A  2000                    and      byte ptr [eax], al             
  0x0106341C  650020                  add      byte ptr gs:[eax], ah          
                                        ; XREF: 0x010633D9 (cond_jump)
  0x0106341F  006129                  add      byte ptr [ecx + 0x29], ah      
  0x01063422  2000                    and      byte ptr [eax], al             
  0x01063424  007054                  add      byte ptr [eax + 0x54], dh      
  0x01063427  00490b                  add      byte ptr [ecx + 0xb], cl       
  0x0106342A  0000                    add      byte ptr [eax], al             
  0x0106342C  00f0                    add      al, dh                         
  0x0106342E  56                      push     esi                            
  0x0106342F  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x01063432  0000                    add      byte ptr [eax], al             
  0x01063434  00f4                    add      ah, dh                         
  0x01063436  44                      inc      esp                            
  0x01063437  0007                    add      byte ptr [edi], al             
  0x01063439  0000                    add      byte ptr [eax], al             
  0x0106343B  0045f4                  add      byte ptr [ebp - 0xc], al       
  0x0106343E  45                      inc      ebp                            
  0x0106343F  0006                    add      byte ptr [esi], al             
  0x01063441  0000                    add      byte ptr [eax], al             
  0x01063443  0014a4                  add      byte ptr [esp], dl             
  0x01063446  050065f444              add      eax, 0x44f46500                
  0x0106344B  0003                    add      byte ptr [ebx], al             
  0x0106344D  0000                    add      byte ptr [eax], al             
  0x0106344F  0011                    add      byte ptr [ecx], dl             
  0x01063451  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01063452  050045f445              add      eax, 0x45f44500                
  0x01063457  0002                    add      byte ptr [edx], al             
  0x01063459  0000                    add      byte ptr [eax], al             
  0x0106345B  000e                    add      byte ptr [esi], cl             
  0x0106345D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106345E  050065f444              add      eax, 0x44f46500                
  0x01063463  000400                  add      byte ptr [eax + eax], al       
  0x01063466  0000                    add      byte ptr [eax], al             
  0x01063468  0ba4050045f445          or       esp, dword ptr [ebp + eax + 0x45f44500] 
  0x0106346F  000500000008            add      byte ptr [0x8000000], al       
  0x01063475  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01063476  050065f444              add      eax, 0x44f46500                
  0x0106347B  0001                    add      byte ptr [ecx], al             
  0x0106347D  0000                    add      byte ptr [eax], al             
  0x0106347F  0005a4050000            add      byte ptr [0x5a4], al           
  0x01063485  f4                      hlt                                     
  0x01063486  44                      inc      esp                            
  0x01063487  0002                    add      byte ptr [edx], al             
  0x01063489  0000                    add      byte ptr [eax], al             
  0x0106348B  0000                    add      byte ptr [eax], al             
  0x0106348D  7044                    jo       0x10634d3                      
  0x0106348F  00960b000000            add      byte ptr [esi + 0xb], dl       
  0x01063495  7054                    jo       0x10634eb                      
  0x01063497  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x0106349A  0000                    add      byte ptr [eax], al             
  0x0106349C  0c00                    or       al, 0                          
  0x0106349E  0000                    add      byte ptr [eax], al             
  0x010634A0  00f0                    add      al, dh                         
  0x010634A2  56                      push     esi                            
  0x010634A3  0012                    add      byte ptr [edx], dl             
  0x010634A5  0900                    or       dword ptr [eax], eax           
  0x010634A7  0000                    add      byte ptr [eax], al             
  0x010634A9  f4                      hlt                                     
  0x010634AA  44                      inc      esp                            
  0x010634AB  006507                  add      byte ptr [ebp + 7], ah         
  0x010634AE  0200                    add      al, byte ptr [eax]             
  0x010634B0  45                      inc      ebp                            
  0x010634B1  0020                    add      byte ptr [eax], ah             
  0x010634B3  0006                    add      byte ptr [esi], al             
  0x010634B5  2405                    and      al, 5                          
  0x010634B7  0000                    add      byte ptr [eax], al             
  0x010634BA  56                      push     esi                            
  0x010634BB  00400b                  add      byte ptr [eax + 0xb], al       
  0x010634BE  0000                    add      byte ptr [eax], al             
  0x010634C0  0300                    add      eax, dword ptr [eax]           
  0x010634C2  2000                    and      byte ptr [eax], al             
  0x010634C4  5e                      pop      esi                            
  0x010634C5  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010634C6  05000c0000              add      eax, 0xc00                     
  0x010634CB  0013                    add      byte ptr [ebx], dl             
  0x010634CD  f4                      hlt                                     
  0x010634CE  60                      pushal                                  
  0x010634CF  00fd                    add      ch, bh                         
  0x010634D1  0400                    add      al, 0                          
                                        ; XREF: 0x0106348D (cond_jump)
  0x010634D3  009006060003            add      byte ptr [eax + 0x3000606], dl 
  0x010634D9  0000                    add      byte ptr [eax], al             
  0x010634DB  0000                    add      byte ptr [eax], al             
  0x010634DD  58                      pop      eax                            
  0x010634DE  54                      push     esp                            
  0x010634DF  0000                    add      byte ptr [eax], al             
  0x010634E1  58                      pop      eax                            
  0x010634E2  54                      push     esp                            
  0x010634E3  0013                    add      byte ptr [ebx], dl             
  0x010634E5  f4                      hlt                                     
  0x010634E6  60                      pushal                                  
  0x010634E7  00a805000090            add      byte ptr [eax - 0x6ffffffb], ch 
  0x010634ED  0506000200              add      eax, 0x20006                   
  0x010634F2  0000                    add      byte ptr [eax], al             
  0x010634F4  005854                  add      byte ptr [eax + 0x54], bl      
  0x010634F7  0013                    add      byte ptr [ebx], dl             
  0x010634F9  f4                      hlt                                     
  0x010634FA  60                      pushal                                  
  0x010634FB  007b05                  add      byte ptr [ebx + 5], bh         
  0x010634FE  0000                    add      byte ptr [eax], al             
  0x01063500  90                      nop                                     
  0x01063501  2806                    sub      byte ptr [esi], al             
  0x01063503  0002                    add      byte ptr [edx], al             
  0x01063505  0000                    add      byte ptr [eax], al             
  0x01063507  0000                    add      byte ptr [eax], al             
  0x01063509  58                      pop      eax                            
  0x0106350A  54                      push     esp                            
  0x0106350B  0013                    add      byte ptr [ebx], dl             
  0x0106350D  f4                      hlt                                     
  0x0106350E  60                      pushal                                  
  0x0106350F  00ae05000090            add      byte ptr [esi - 0x6ffffffb], ch 
  0x01063515  5a                      pop      edx                            
  0x01063516  06                      push     es                             
  0x01063517  0002                    add      byte ptr [edx], al             
  0x01063519  0000                    add      byte ptr [eax], al             
  0x0106351B  0000                    add      byte ptr [eax], al             
  0x0106351D  58                      pop      eax                            
  0x0106351E  54                      push     esp                            
  0x0106351F  0013                    add      byte ptr [ebx], dl             
  0x01063521  f4                      hlt                                     
  0x01063522  60                      pushal                                  
  0x01063523  0008                    add      byte ptr [eax], cl             
  0x01063525  06                      push     es                             
  0x01063526  0000                    add      byte ptr [eax], al             
  0x01063528  90                      nop                                     
  0x01063529  0506000200              add      eax, 0x20006                   
  0x0106352E  0000                    add      byte ptr [eax], al             
  0x01063530  005854                  add      byte ptr [eax + 0x54], bl      
  0x01063533  0013                    add      byte ptr [ebx], dl             
  0x01063535  f4                      hlt                                     
  0x01063536  60                      pushal                                  
  0x01063537  000d06000090            add      byte ptr [0x90000006], cl      
  0x0106353D  0506000200              add      eax, 0x20006                   
  0x01063542  0000                    add      byte ptr [eax], al             
  0x01063544  005854                  add      byte ptr [eax + 0x54], bl      
  0x01063547  0013                    add      byte ptr [ebx], dl             
  0x01063549  f4                      hlt                                     
  0x0106354A  60                      pushal                                  
  0x0106354B  0009                    add      byte ptr [ecx], cl             
  0x0106354D  0500009010              add      eax, 0x10900000                
  0x01063552  06                      push     es                             
  0x01063553  0002                    add      byte ptr [edx], al             
  0x01063555  0000                    add      byte ptr [eax], al             
  0x01063557  0000                    add      byte ptr [eax], al             
  0x01063559  58                      pop      eax                            
  0x0106355A  54                      push     esp                            
  0x0106355B  0013                    add      byte ptr [ebx], dl             
  0x0106355D  f4                      hlt                                     
  0x0106355E  60                      pushal                                  
  0x0106355F  0019                    add      byte ptr [ecx], bl             
  0x01063561  0500009008              add      eax, 0x8900000                 
  0x01063566  06                      push     es                             
  0x01063567  0002                    add      byte ptr [edx], al             
  0x01063569  0000                    add      byte ptr [eax], al             
  0x0106356B  0000                    add      byte ptr [eax], al             
  0x0106356D  58                      pop      eax                            
  0x0106356E  54                      push     esp                            
  0x0106356F  0013                    add      byte ptr [ebx], dl             
  0x01063571  f4                      hlt                                     
  0x01063572  60                      pushal                                  
  0x01063573  0021                    add      byte ptr [ecx], ah             
  0x01063575  050000903c              add      eax, 0x3c900000                
  0x0106357A  06                      push     es                             
  0x0106357B  0002                    add      byte ptr [edx], al             
  0x0106357D  0000                    add      byte ptr [eax], al             
  0x0106357F  0000                    add      byte ptr [eax], al             
  0x01063581  58                      pop      eax                            
  0x01063582  54                      push     esp                            
  0x01063583  0013                    add      byte ptr [ebx], dl             
  0x01063585  f4                      hlt                                     
  0x01063586  60                      pushal                                  
  0x01063587  005d05                  add      byte ptr [ebp + 5], bl         
  0x0106358A  0000                    add      byte ptr [eax], al             
  0x0106358C  90                      nop                                     
  0x0106358D  1e                      push     ds                             
  0x0106358E  06                      push     es                             
  0x0106358F  0002                    add      byte ptr [edx], al             
  0x01063591  0000                    add      byte ptr [eax], al             
  0x01063593  0000                    add      byte ptr [eax], al             
  0x01063595  58                      pop      eax                            
  0x01063596  54                      push     esp                            
  0x01063597  0013                    add      byte ptr [ebx], dl             
  0x01063599  f4                      hlt                                     
  0x0106359A  60                      pushal                                  
  0x0106359B  0012                    add      byte ptr [edx], dl             
  0x0106359D  06                      push     es                             
  0x0106359E  0000                    add      byte ptr [eax], al             
  0x010635A0  93                      xchg     ebx, eax                       
  0x010635A1  0006                    add      byte ptr [esi], al             
  0x010635A3  0002                    add      byte ptr [edx], al             
  0x010635A5  0000                    add      byte ptr [eax], al             
  0x010635A7  0000                    add      byte ptr [eax], al             
  0x010635A9  58                      pop      eax                            
  0x010635AA  54                      push     esp                            
  0x010635AB  0000                    add      byte ptr [eax], al             
  0x010635AD  f4                      hlt                                     
  0x010635AE  44                      inc      esp                            
  0x010635AF  006507                  add      byte ptr [ebp + 7], ah         
  0x010635B2  0200                    add      al, byte ptr [eax]             
  0x010635B4  007044                  add      byte ptr [eax + 0x44], dh      
  0x010635B7  0012                    add      byte ptr [edx], dl             
  0x010635B9  0900                    or       dword ptr [eax], eax           
  0x010635BB  0000                    add      byte ptr [eax], al             
  0x010635BD  f4                      hlt                                     
  0x010635BE  44                      inc      esp                            
  0x010635BF  0000                    add      byte ptr [eax], al             
  0x010635C1  0000                    add      byte ptr [eax], al             
  0x010635C3  0000                    add      byte ptr [eax], al             
  0x010635C5  7044                    jo       0x106360b                      
  0x010635C7  00960b000000            add      byte ptr [esi + 0xb], dl       
  0x010635CD  f4                      hlt                                     
  0x010635CE  61                      popal                                   
  0x010635CF  00c2                    add      dl, al                         
  0x010635D1  0f0000                  sldt     word ptr [eax]                 
  0x010635D4  00f0                    add      al, dh                         
  0x010635D6  7100                    jno      0x10635d8                      
                                        ; XREF: 0x010635D6 (cond_jump)
  0x010635D8  7d0b                    jge      0x10635e5                      
  0x010635DA  0000                    add      byte ptr [eax], al             
  0x010635DC  00f0                    add      al, dh                         
  0x010635DE  44                      inc      esp                            
  0x010635DF  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x010635E2  0000                    add      byte ptr [eax], al             
  0x010635E4  00e9                    add      cl, ch                         
  0x010635E6  5e                      pop      esi                            
  0x010635E7  004070                  add      byte ptr [eax + 0x70], al      
  0x010635EA  54                      push     esp                            
  0x010635EB  00970b000000            add      byte ptr [edi + 0xb], dl       
  0x010635F1  7054                    jo       0x1063647                      
  0x010635F3  00980b00001b            add      byte ptr [eax + 0x1b00000b], bl 
  0x010635FA  44                      inc      esp                            
  0x010635FB  00970b000013            add      byte ptr [edi + 0x1300000b], dl 
  0x01063601  052d004d02              add      eax, 0x24d002d                 
  0x01063606  2c00                    sub      al, 0                          
  0x01063608  5a                      pop      edx                            
  0x01063609  94                      xchg     esp, eax                       
  0x0106360A  05001bf044              add      eax, 0x44f01b00                
  0x0106360F  00980b000013            add      byte ptr [eax + 0x1300000b], bl 
  0x01063615  06                      push     es                             
  0x01063616  2d004d022c              sub      eax, 0x2c024d00                
  0x0106361B  005594                  add      byte ptr [ebp - 0x6c], dl      
  0x0106361E  050000f056              add      eax, 0x56f00000                
  0x01063623  007c0b00                add      byte ptr [ebx + ecx], bh       
  0x01063627  0023                    add      byte ptr [ebx], ah             
  0x01063629  0020                    add      byte ptr [eax], ah             
  0x0106362B  0000                    add      byte ptr [eax], al             
  0x0106362D  7054                    jo       0x1063683                      
  0x0106362F  00990b00001b            add      byte ptr [ecx + 0x1b00000b], bl 
  0x01063636  44                      inc      esp                            
  0x01063637  007b0b                  add      byte ptr [ebx + 0xb], bh       
  0x0106363A  0000                    add      byte ptr [eax], al             
  0x0106363C  1303                    adc      eax, dword ptr [ebx]           
  0x0106363E  2d004d042c              sub      eax, 0x2c044d00                
  0x01063643  004b94                  add      byte ptr [ebx - 0x6c], cl      
  0x01063646  05001bf044              add      eax, 0x44f01b00                
  0x0106364B  00990b000013            add      byte ptr [ecx + 0x1300000b], bl 
  0x01063651  132d004d032c            adc      ebp, dword ptr [0x2c034d00]    
  0x01063657  004694                  add      byte ptr [esi - 0x6c], al      
  0x0106365A  050000f056              add      eax, 0x56f00000                
  0x0106365F  007c0b00                add      byte ptr [ebx + ecx], bh       
  0x01063663  00c4                    add      ah, al                         
  0x01063665  40                      inc      eax                            
  0x01063666  0100                    add      dword ptr [eax], eax           
  0x01063668  2400                    and      al, 0                          
  0x0106366A  0000                    add      byte ptr [eax], al             
  0x0106366C  00da                    add      dl, bl                         
  0x0106366E  2100                    and      dword ptr [eax], eax           
  0x01063670  00f0                    add      al, dh                         
  0x01063672  44                      inc      esp                            
  0x01063673  007b0b                  add      byte ptr [ebx + 0xb], bh       
  0x01063676  0000                    add      byte ptr [eax], al             
  0x01063678  00f4                    add      ah, dh                         
  0x0106367A  46                      inc      esi                            
  0x0106367B  0006                    add      byte ptr [esi], al             
  0x0106367D  0000                    add      byte ptr [eax], al             
  0x0106367F  00d0                    add      al, dl                         
  0x01063681  44                      inc      esp                            
  0x01063682  2300                    and      eax, dword ptr [eax]           
  0x01063684  2e1d0c0040f4            sbb      eax, 0xf440000c                
  0x0106368A  44                      inc      esp                            
  0x0106368B  004c0f00                add      byte ptr [edi + ecx], cl       
  0x0106368F  004000                  add      byte ptr [eax], al             
  0x01063692  2000                    and      byte ptr [eax], al             
  0x01063694  0091210000e1            add      byte ptr [ecx - 0x1effffdf], dl 
  0x0106369A  5e                      pop      esi                            
  0x0106369B  0022                    add      byte ptr [edx], ah             
  0x0106369D  cf                      iretd                                   
  0x0106369E  2100                    and      dword ptr [eax], eax           
  0x010636A0  22842100220020          and      al, byte ptr [ecx + 0x20002200] 
  0x010636A7  004070                  add      byte ptr [eax + 0x70], al      
  0x010636AA  57                      push     edi                            
  0x010636AB  009a0b000000            add      byte ptr [edx + 0xb], bl       
  0x010636B1  8521                    test     dword ptr [ecx], esp           
  0x010636B3  006ce421                add      byte ptr [esp + 0x21], ch      
  0x010636B7  0000                    add      byte ptr [eax], al             
  0x010636B9  f4                      hlt                                     
  0x010636BA  46                      inc      esi                            
  0x010636BB  0008                    add      byte ptr [eax], cl             
  0x010636BD  0000                    add      byte ptr [eax], al             
  0x010636BF  00d0                    add      al, dl                         
  0x010636C1  a7                      cmpsd    dword ptr [esi], dword ptr es:[edi] 
  0x010636C2  2100                    and      dword ptr [eax], eax           
  0x010636C4  e87050009d              call     0x9e068739                     
  0x010636C9  0b00                    or       eax, dword ptr [eax]           
  0x010636CB  0000                    add      byte ptr [eax], al             
  0x010636CD  7045                    jo       0x1063714                      
  0x010636CF  009b0b0000b0            add      byte ptr [ebx - 0x4ffffff5], bl 
  0x010636D5  7051                    jo       0x1063728                      
  0x010636D7  009e0b000000            add      byte ptr [esi + 0xb], bl       
  0x010636DD  7047                    jo       0x1063726                      
  0x010636DF  009c0b00000070          add      byte ptr [ebx + ecx + 0x70000000], bl 
  0x010636E6  50                      push     eax                            
  0x010636E7  009f0b000003            add      byte ptr [edi + 0x300000b], bl 
  0x010636ED  0c05                    or       al, 5                          
  0x010636EF  0000                    add      byte ptr [eax], al             
  0x010636F1  7054                    jo       0x1063747                      
  0x010636F3  00960b00000c            add      byte ptr [esi + 0xc00000b], dl 
  0x010636F9  0000                    add      byte ptr [eax], al             
  0x010636FB  0000                    add      byte ptr [eax], al             
  0x010636FD  f4                      hlt                                     
  0x010636FE  56                      push     esi                            
  0x010636FF  001409                  add      byte ptr [ecx + ecx], dl       
  0x01063702  0000                    add      byte ptr [eax], al             
  0x01063704  00f0                    add      al, dh                         
  0x01063706  44                      inc      esp                            
  0x01063707  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106370A  0000                    add      byte ptr [eax], al             
  0x0106370C  40                      inc      eax                            
  0x0106370D  0020                    add      byte ptr [eax], ah             
  0x0106370F  0000                    add      byte ptr [eax], al             
  0x01063711  91                      xchg     ecx, eax                       
  0x01063712  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x010636CD (cond_jump)
  0x01063714  00e1                    add      cl, ah                         
  0x01063716  56                      push     esi                            
  0x01063717  0001                    add      byte ptr [ecx], al             
  0x01063719  1e                      push     ds                             
  0x0106371A  0c00                    or       al, 0                          
  0x0106371C  3ef4                    hlt                                     
  0x0106371E  44                      inc      esp                            
  0x0106371F  0001                    add      byte ptr [ecx], al             
  0x01063721  0000                    add      byte ptr [eax], al             
  0x01063723  004c0020                add      byte ptr [eax + eax + 0x20], cl 
  0x01063727  001b                    add      byte ptr [ebx], bl             
  0x01063729  2920                    sub      dword ptr [eax], esp           
  0x0106372B  0003                    add      byte ptr [ebx], al             
  0x0106372D  f4                      hlt                                     
  0x0106372E  45                      inc      ebp                            
  0x0106372F  0003                    add      byte ptr [ebx], al             
  0x01063731  0000                    add      byte ptr [eax], al             
  0x01063733  0068a0                  add      byte ptr [eax - 0x60], ch      
  0x01063736  0200                    add      al, byte ptr [eax]             
  0x01063738  6d                      insd     dword ptr es:[edi], dx         
  0x01063739  0020                    add      byte ptr [eax], ah             
  0x0106373B  006870                  add      byte ptr [eax + 0x70], ch      
  0x0106373E  0200                    add      al, byte ptr [eax]             
  0x01063740  00f4                    add      ah, dh                         
  0x01063742  56                      push     esi                            
  0x01063743  00610b                  add      byte ptr [ecx + 0xb], ah       
  0x01063746  0000                    add      byte ptr [eax], al             
  0x01063748  00f0                    add      al, dh                         
  0x0106374A  44                      inc      esp                            
  0x0106374B  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106374E  0000                    add      byte ptr [eax], al             
  0x01063750  40                      inc      eax                            
  0x01063751  0020                    add      byte ptr [eax], ah             
  0x01063753  0000                    add      byte ptr [eax], al             
  0x01063755  90                      nop                                     
  0x01063756  2100                    and      dword ptr [eax], eax           
  0x01063758  006055                  add      byte ptr [eax + 0x55], ah      
  0x0106375B  000c00                  add      byte ptr [eax + eax], cl       
  0x0106375E  0000                    add      byte ptr [eax], al             
  0x01063760  00f0                    add      al, dh                         
  0x01063762  44                      inc      esp                            
  0x01063763  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x01063766  0000                    add      byte ptr [eax], al             
  0x01063768  00f4                    add      ah, dh                         
  0x0106376A  46                      inc      esi                            
  0x0106376B  0006                    add      byte ptr [esi], al             
  0x0106376D  0000                    add      byte ptr [eax], al             
  0x0106376F  00d0                    add      al, dl                         
  0x01063772  44                      inc      esp                            
  0x01063773  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063776  0000                    add      byte ptr [eax], al             
  0x01063778  2e1d0c0040f4            sbb      eax, 0xf440000c                
  0x0106377E  44                      inc      esp                            
  0x0106377F  00920f000040            add      byte ptr [edx + 0x4000000f], dl 
  0x01063785  0020                    add      byte ptr [eax], ah             
  0x01063787  0000                    add      byte ptr [eax], al             
  0x01063789  94                      xchg     esp, eax                       
  0x0106378A  2100                    and      dword ptr [eax], eax           
  0x0106378C  00f0                    add      al, dh                         
  0x0106378E  56                      push     esi                            
  0x0106378F  00440b00                add      byte ptr [ebx + ecx], al       
  0x01063793  0000                    add      byte ptr [eax], al             
  0x01063795  e44c                    in       al, 0x4c                       
  0x01063797  004000                  add      byte ptr [eax], al             
  0x0106379A  2000                    and      byte ptr [eax], al             
  0x0106379C  0091210020e1            add      byte ptr [ecx - 0x1edfffdf], dl 
  0x010637A2  050000f056              add      eax, 0x56f00000                
  0x010637A7  00420b                  add      byte ptr [edx + 0xb], al       
  0x010637AA  0000                    add      byte ptr [eax], al             
  0x010637AC  00e4                    add      ah, ah                         
  0x010637AE  4c                      dec      esp                            
  0x010637AF  004000                  add      byte ptr [eax], al             
  0x010637B2  2000                    and      byte ptr [eax], al             
  0x010637B4  0091210000f0            add      byte ptr [ecx - 0xfffffdf], dl 
  0x010637BA  56                      push     esi                            
  0x010637BB  00430b                  add      byte ptr [ebx + 0xb], al       
  0x010637BE  0000                    add      byte ptr [eax], al             
  0x010637C0  00e4                    add      ah, ah                         
  0x010637C2  4c                      dec      esp                            
  0x010637C3  004000                  add      byte ptr [eax], al             
  0x010637C6  2000                    and      byte ptr [eax], al             
  0x010637C8  0092210000f4            add      byte ptr [edx - 0xbffffdf], dl 
  0x010637CE  44                      inc      esp                            
  0x010637CF  0000                    add      byte ptr [eax], al             
  0x010637D1  0100                    add      dword ptr [eax], eax           
  0x010637D3  0000                    add      byte ptr [eax], al             
  0x010637D5  e246                    loop     0x106381d                      
  0x010637D7  00d0                    add      al, dl                         
  0x010637D9  0020                    add      byte ptr [eax], ah             
  0x010637DB  0022                    add      byte ptr [edx], ah             
  0x010637DD  002400                  add      byte ptr [eax + eax], ah       
  0x010637E0  0006                    add      byte ptr [esi], al             
  0x010637E2  2100                    and      dword ptr [eax], eax           
  0x010637E4  d000                    rol      byte ptr [eax], 1              
  0x010637E6  2400                    and      al, 0                          
  0x010637E8  00e2                    add      dl, ah                         
  0x010637EA  46                      inc      esi                            
  0x010637EB  00d2                    add      dl, dl                         
  0x010637ED  002400                  add      byte ptr [eax + eax], ah       
  0x010637F0  2e1d0c0040e1            sbb      eax, 0xe140000c                
  0x010637F6  44                      inc      esp                            
  0x010637F7  004000                  add      byte ptr [eax], al             
  0x010637FA  2000                    and      byte ptr [eax], al             
  0x010637FC  0090210000e2            add      byte ptr [eax - 0x1dffffdf], dl 
  0x01063802  7000                    jo       0x1063804                      
                                        ; XREF: 0x01063802 (cond_jump)
  0x01063804  00f4                    add      ah, dh                         
  0x01063806  6400fd                  add      ch, bh                         
  0x01063809  0200                    add      al, byte ptr [eax]             
  0x0106380B  0000                    add      byte ptr [eax], al             
  0x0106380D  013c00                  add      dword ptr [eax + eax], edi     
  0x01063810  00ff                    add      bh, bh                         
  0x01063812  3e0000                  add      byte ptr ds:[eax], al          
  0x01063815  f4                      hlt                                     
  0x01063816  45                      inc      ebp                            
  0x01063817  00cf                    add      bh, cl                         
  0x01063819  f73f                    idiv     dword ptr [edi]                
  0x0106381B  0000                    add      byte ptr [eax], al             
  0x0106381E  56                      push     esi                            
  0x0106381F  003f                    add      byte ptr [edi], bh             
  0x01063821  0200                    add      al, byte ptr [eax]             
  0x01063823  0003                    add      byte ptr [ebx], al             
  0x01063825  0020                    add      byte ptr [eax], ah             
  0x01063827  000f                    add      byte ptr [edi], cl             
  0x01063829  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106382A  050000f056              add      eax, 0x56f00000                
  0x0106382F  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063832  0000                    add      byte ptr [eax], al             
  0x01063834  32f4                    xor      dh, ah                         
  0x01063836  44                      inc      esp                            
  0x01063837  00fd                    add      ch, bh                         
  0x01063839  0400                    add      al, 0                          
  0x0106383B  004000                  add      byte ptr [eax], al             
  0x0106383E  2000                    and      byte ptr [eax], al             
  0x01063840  0091210000f4            add      byte ptr [ecx - 0xbffffdf], dl 
  0x01063846  47                      inc      edi                            
  0x01063847  004703                  add      byte ptr [edi + 3], al         
  0x0106384A  0000                    add      byte ptr [eax], al             
  0x0106384C  00d9                    add      cl, bl                         
  0x0106384E  57                      push     edi                            
  0x0106384F  0000                    add      byte ptr [eax], al             
  0x01063851  d15100                  rcl      dword ptr [ecx]                
  0x01063854  e704                    out      4, eax                         
  0x01063856  0d00005955              or       eax, 0x55590000                
  0x0106385B  0000                    add      byte ptr [eax], al             
  0x0106385D  61                      popal                                   
  0x0106385E  51                      push     ecx                            
  0x0106385F  0002                    add      byte ptr [edx], al             
  0x01063861  0c05                    or       al, 5                          
  0x01063863  00f4                    add      ah, dh                         
  0x01063865  040d                    add      al, 0xd                        
  0x01063867  0020                    add      byte ptr [eax], ah             
  0x01063869  f4                      hlt                                     
  0x0106386A  0500ffff00              add      eax, 0xffff00                  
  0x0106386F  000c00                  add      byte ptr [eax + eax], cl       
  0x01063872  0000                    add      byte ptr [eax], al             
  0x01063874  00f0                    add      al, dh                         
  0x01063876  56                      push     esi                            
  0x01063877  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106387A  0000                    add      byte ptr [eax], al             
  0x0106387C  00f0                    add      al, dh                         
  0x0106387E  44                      inc      esp                            
  0x0106387F  00970b000045            add      byte ptr [edi + 0x4500000b], dl 
  0x01063885  0020                    add      byte ptr [eax], ah             
  0x01063887  004da4                  add      byte ptr [ebp - 0x5c], cl      
  0x0106388A  050000f056              add      eax, 0x56f00000                
  0x0106388F  003d02000003            add      byte ptr [0x3000002], bh       
  0x01063895  0020                    add      byte ptr [eax], ah             
  0x01063897  005ba4                  add      byte ptr [ebx - 0x5c], bl      
  0x0106389A  050000f460              add      eax, 0x60f40000                
  0x0106389F  00fd                    add      ch, bh                         
  0x010638A1  0200                    add      al, byte ptr [eax]             
  0x010638A3  0000                    add      byte ptr [eax], al             
  0x010638A5  1422                    adc      al, 0x22                       
  0x010638A7  0000                    add      byte ptr [eax], al             
  0x010638A9  0138                    add      dword ptr [eax], edi           
  0x010638AB  0000                    add      byte ptr [eax], al             
  0x010638AD  1c23                    sbb      al, 0x23                       
  0x010638AF  0000                    add      byte ptr [eax], al             
  0x010638B2  44                      inc      esp                            
  0x010638B3  00410b                  add      byte ptr [ecx + 0xb], al       
  0x010638B6  0000                    add      byte ptr [eax], al             
  0x010638B8  00f4                    add      ah, dh                         
  0x010638BA  46                      inc      esi                            
  0x010638BB  000c00                  add      byte ptr [eax + eax], cl       
  0x010638BE  0000                    add      byte ptr [eax], al             
  0x010638C0  d0f4                    sal      ah, 1                          
  0x010638C2  44                      inc      esp                            
  0x010638C3  0021                    add      byte ptr [ecx], ah             
  0x010638C5  0500002e1d              add      eax, 0x1d2e0000                
  0x010638CA  0c00                    or       al, 0                          
  0x010638CC  40                      inc      eax                            
  0x010638CD  0020                    add      byte ptr [eax], ah             
  0x010638CF  0000                    add      byte ptr [eax], al             
  0x010638D1  91                      xchg     ecx, eax                       
  0x010638D2  2100                    and      dword ptr [eax], eax           
  0x010638D4  00f0                    add      al, dh                         
  0x010638D6  44                      inc      esp                            
  0x010638D7  00410b                  add      byte ptr [ecx + 0xb], al       
  0x010638DA  0000                    add      byte ptr [eax], al             
  0x010638DC  00f4                    add      ah, dh                         
  0x010638DE  46                      inc      esi                            
  0x010638DF  0006                    add      byte ptr [esi], al             
  0x010638E1  0000                    add      byte ptr [eax], al             
  0x010638E3  00d0                    add      al, dl                         
  0x010638E5  f4                      hlt                                     
  0x010638E6  44                      inc      esp                            
  0x010638E7  005d05                  add      byte ptr [ebp + 5], bl         
  0x010638EA  0000                    add      byte ptr [eax], al             
  0x010638EC  2e1d0c004000            sbb      eax, 0x40000c                  
  0x010638F2  2000                    and      byte ptr [eax], al             
  0x010638F4  0092210000f0            add      byte ptr [edx - 0xfffffdf], dl 
  0x010638FA  56                      push     esi                            
  0x010638FB  004002                  add      byte ptr [eax + 2], al         
  0x010638FE  0000                    add      byte ptr [eax], al             
  0x01063900  c44001                  les      eax, ptr [eax + 1]             
  0x01063903  0007                    add      byte ptr [edi], al             
  0x01063905  0000                    add      byte ptr [eax], al             
  0x01063907  0000                    add      byte ptr [eax], al             
  0x01063909  da21                    fisub    dword ptr [ecx]                
  0x0106390B  0000                    add      byte ptr [eax], al             
  0x0106390D  44                      inc      esp                            
  0x0106390E  2300                    and      eax, dword ptr [eax]           
  0x01063910  00f4                    add      ah, dh                         
  0x01063912  46                      inc      esi                            
  0x01063913  000f                    add      byte ptr [edi], cl             
  0x01063915  0000                    add      byte ptr [eax], al             
  0x01063917  00d0                    add      al, dl                         
  0x01063919  f4                      hlt                                     
  0x0106391A  44                      inc      esp                            
  0x0106391B  001408                  add      byte ptr [eax + ecx], dl       
  0x0106391E  0000                    add      byte ptr [eax], al             
  0x01063920  2e1d0c004000            sbb      eax, 0x40000c                  
  0x01063926  2000                    and      byte ptr [eax], al             
  0x01063928  009521000003            add      byte ptr [ebp + 0x3000021], dl 
  0x0106392E  3a00                    cmp      al, byte ptr [eax]             
  0x01063930  00ff                    add      bh, bh                         
  0x01063932  3e009e040d0013          add      byte ptr ds:[esi + 0x13000d04], bl 
  0x01063939  0c05                    or       al, 5                          
  0x0106393B  0000                    add      byte ptr [eax], al             
  0x0106393E  56                      push     esi                            
  0x0106393F  003e                    add      byte ptr [esi], bh             
  0x01063941  0200                    add      al, byte ptr [eax]             
  0x01063943  0003                    add      byte ptr [ebx], al             
  0x01063945  0020                    add      byte ptr [eax], ah             
  0x01063947  000f                    add      byte ptr [edi], cl             
  0x01063949  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106394A  050000f460              add      eax, 0x60f40000                
  0x0106394F  00fd                    add      ch, bh                         
  0x01063951  0200                    add      al, byte ptr [eax]             
  0x01063953  0000                    add      byte ptr [eax], al             
  0x01063955  1422                    adc      al, 0x22                       
  0x01063957  0000                    add      byte ptr [eax], al             
  0x01063959  0138                    add      dword ptr [eax], edi           
  0x0106395B  0000                    add      byte ptr [eax], al             
  0x0106395D  1c23                    sbb      al, 0x23                       
  0x0106395F  0000                    add      byte ptr [eax], al             
  0x01063961  f4                      hlt                                     
  0x01063962  61                      popal                                   
  0x01063963  0009                    add      byte ptr [ecx], cl             
  0x01063965  05000000f4              add      eax, 0xf4000000                
  0x0106396A  6200                    bound    eax, qword ptr [eax]           
  0x0106396C  1905000000f4            sbb      dword ptr [0xf4000000], eax    
  0x01063972  650000                  add      byte ptr gs:[eax], al          
  0x01063975  0800                    or       byte ptr [eax], al             
  0x01063977  0000                    add      byte ptr [eax], al             
  0x01063979  043a                    add      al, 0x3a                       
  0x0106397B  0000                    add      byte ptr [eax], al             
  0x0106397E  3e00bf040d000c          add      byte ptr ds:[edi + 0xc000d04], bh 
  0x01063985  0000                    add      byte ptr [eax], al             
  0x01063987  0000                    add      byte ptr [eax], al             
  0x0106398A  44                      inc      esp                            
  0x0106398B  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x0106398E  0000                    add      byte ptr [eax], al             
  0x01063990  00f4                    add      ah, dh                         
  0x01063992  46                      inc      esi                            
  0x01063993  0006                    add      byte ptr [esi], al             
  0x01063995  0000                    add      byte ptr [eax], al             
  0x01063997  00d0                    add      al, dl                         
  0x0106399A  44                      inc      esp                            
  0x0106399B  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106399E  0000                    add      byte ptr [eax], al             
  0x010639A0  2e1d0c0040f4            sbb      eax, 0xf440000c                
  0x010639A6  44                      inc      esp                            
  0x010639A7  00920f000040            add      byte ptr [edx + 0x4000000f], dl 
  0x010639AD  0020                    add      byte ptr [eax], ah             
  0x010639AF  0000                    add      byte ptr [eax], al             
  0x010639B1  91                      xchg     ecx, eax                       
  0x010639B2  2100                    and      dword ptr [eax], eax           
  0x010639B4  00e1                    add      cl, ah                         
  0x010639B6  4c                      dec      esp                            
  0x010639B7  0000                    add      byte ptr [eax], al             
  0x010639B9  7044                    jo       0x10639ff                      
  0x010639BB  0013                    add      byte ptr [ebx], dl             
  0x010639BD  0900                    or       dword ptr [eax], eax           
  0x010639BF  0000                    add      byte ptr [eax], al             
  0x010639C1  f4                      hlt                                     
  0x010639C2  61                      popal                                   
  0x010639C3  00fd                    add      ch, bh                         
  0x010639C5  0200                    add      al, byte ptr [eax]             
  0x010639C7  0013                    add      byte ptr [ebx], dl             
  0x010639C9  0020                    add      byte ptr [eax], ah             
  0x010639CB  001b                    add      byte ptr [ebx], bl             
  0x010639CD  d9440091                fld      dword ptr [eax + eax - 0x6f]   
  0x010639D1  0006                    add      byte ptr [esi], al             
  0x010639D3  000400                  add      byte ptr [eax + eax], al       
  0x010639D6  0000                    add      byte ptr [eax], al             
  0x010639D8  47                      inc      edi                            
  0x010639D9  0020                    add      byte ptr [eax], ah             
  0x010639DB  004090                  add      byte ptr [eax - 0x70], al      
  0x010639DE  0200                    add      al, byte ptr [eax]             
  0x010639E0  8ad9                    mov      bl, cl                         
  0x010639E2  44                      inc      esp                            
  0x010639E3  0000                    add      byte ptr [eax], al             
  0x010639E5  f4                      hlt                                     
  0x010639E6  60                      pushal                                  
  0x010639E7  00a805000000            add      byte ptr [eax + 5], ch         
  0x010639EE  7000                    jo       0x10639f0                      
                                        ; XREF: 0x010639EE (cond_jump)
  0x010639F0  41                      inc      ecx                            
  0x010639F1  0b00                    or       eax, dword ptr [eax]           
  0x010639F3  0032                    add      byte ptr [edx], dh             
  0x010639F5  0020                    add      byte ptr [eax], ah             
  0x010639F7  0026                    add      byte ptr [esi], ah             
  0x010639F9  e844004768              call     0x694d3a42                     
  0x010639FE  56                      push     esi                            
                                        ; XREF: 0x010639B9 (cond_jump)
  0x010639FF  004090                  add      byte ptr [eax - 0x70], al      
  0x01063A02  0200                    add      al, byte ptr [eax]             
  0x01063A04  00c7                    add      bh, al                         
  0x01063A06  2100                    and      dword ptr [eax], eax           
  0x01063A08  00f4                    add      ah, dh                         
  0x01063A0A  56                      push     esi                            
  0x01063A0B  001409                  add      byte ptr [ecx + ecx], dl       
  0x01063A0E  0000                    add      byte ptr [eax], al             
  0x01063A10  00f0                    add      al, dh                         
  0x01063A12  44                      inc      esp                            
  0x01063A13  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063A16  0000                    add      byte ptr [eax], al             
  0x01063A18  40                      inc      eax                            
  0x01063A19  0020                    add      byte ptr [eax], ah             
  0x01063A1B  0000                    add      byte ptr [eax], al             
  0x01063A1D  90                      nop                                     
  0x01063A1E  2100                    and      dword ptr [eax], eax           
  0x01063A20  006047                  add      byte ptr [eax + 0x47], ah      
  0x01063A23  00911c0c0000            add      byte ptr [ecx + 0xc1c], dl     
  0x01063A2A  44                      inc      esp                            
  0x01063A2B  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063A2E  0000                    add      byte ptr [eax], al             
  0x01063A30  00f4                    add      ah, dh                         
  0x01063A32  46                      inc      esi                            
  0x01063A33  0002                    add      byte ptr [edx], al             
  0x01063A35  0000                    add      byte ptr [eax], al             
  0x01063A37  00d0                    add      al, dl                         
  0x01063A39  f4                      hlt                                     
  0x01063A3A  44                      inc      esp                            
  0x01063A3B  0020                    add      byte ptr [eax], ah             
  0x01063A3D  0900                    or       dword ptr [eax], eax           
  0x01063A3F  002e                    add      byte ptr [esi], ch             
  0x01063A41  1d0c004000              sbb      eax, 0x40000c                  
  0x01063A46  2000                    and      byte ptr [eax], al             
  0x01063A48  009021000058            add      byte ptr [eax + 0x58000021], dl 
  0x01063A4E  55                      push     ebp                            
  0x01063A4F  0000                    add      byte ptr [eax], al             
  0x01063A51  60                      pushal                                  
  0x01063A52  51                      push     ecx                            
  0x01063A53  0000                    add      byte ptr [eax], al             
  0x01063A55  f4                      hlt                                     
  0x01063A56  56                      push     esi                            
  0x01063A57  001a                    add      byte ptr [edx], bl             
  0x01063A59  0900                    or       dword ptr [eax], eax           
  0x01063A5B  0000                    add      byte ptr [eax], al             
  0x01063A5E  44                      inc      esp                            
  0x01063A5F  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063A62  0000                    add      byte ptr [eax], al             
  0x01063A64  40                      inc      eax                            
  0x01063A65  0020                    add      byte ptr [eax], ah             
  0x01063A67  0000                    add      byte ptr [eax], al             
  0x01063A69  90                      nop                                     
  0x01063A6A  2100                    and      dword ptr [eax], eax           
  0x01063A6C  00a721000026            add      byte ptr [edi + 0x26000021], ah 
  0x01063A72  2100                    and      dword ptr [eax], eax           
  0x01063A74  13402f                  adc      eax, dword ptr [eax + 0x2f]    
  0x01063A77  009017060008            add      byte ptr [eax + 0x8000617], dl 
  0x01063A7D  0000                    add      byte ptr [eax], al             
  0x01063A7F  0010                    add      byte ptr [eax], dl             
  0x01063A81  c521                    lds      esp, ptr [ecx]                 
  0x01063A83  0000                    add      byte ptr [eax], al             
  0x01063A85  c421                    les      esp, ptr [ecx]                 
  0x01063A87  00840020003000          add      byte ptr [eax + eax + 0x300020], al 
  0x01063A8E  2000                    and      byte ptr [eax], al             
  0x01063A90  00ae20001021            add      byte ptr [esi + 0x21100020], ch 
  0x01063A96  2000                    and      byte ptr [eax], al             
  0x01063A98  2a00                    sub      al, byte ptr [eax]             
  0x01063A9A  2000                    and      byte ptr [eax], al             
  0x01063A9C  3200                    xor      al, byte ptr [eax]             
  0x01063A9E  2000                    and      byte ptr [eax], al             
  0x01063AA0  006056                  add      byte ptr [eax + 0x56], ah      
  0x01063AA3  000c00                  add      byte ptr [eax + eax], cl       
  0x01063AA6  0000                    add      byte ptr [eax], al             
  0x01063AA8  00f4                    add      ah, dh                         
  0x01063AAA  60                      pushal                                  
  0x01063AAB  00fd                    add      ch, bh                         
  0x01063AAD  0200                    add      al, byte ptr [eax]             
  0x01063AAF  0000                    add      byte ptr [eax], al             
  0x01063AB1  f4                      hlt                                     
  0x01063AB2  6400fd                  add      ch, bh                         
  0x01063AB5  0300                    add      eax, dword ptr [eax]           
  0x01063AB7  0000                    add      byte ptr [eax], al             
  0x01063AB9  0138                    add      dword ptr [eax], edi           
  0x01063ABB  0000                    add      byte ptr [eax], al             
  0x01063ABD  1c23                    sbb      al, 0x23                       
  0x01063ABF  0000                    add      byte ptr [eax], al             
  0x01063AC2  44                      inc      esp                            
  0x01063AC3  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063AC6  0000                    add      byte ptr [eax], al             
  0x01063AC8  00f4                    add      ah, dh                         
  0x01063ACA  46                      inc      esi                            
  0x01063ACB  0008                    add      byte ptr [eax], cl             
  0x01063ACD  0000                    add      byte ptr [eax], al             
  0x01063ACF  00d0                    add      al, dl                         
  0x01063AD1  f4                      hlt                                     
  0x01063AD2  44                      inc      esp                            
  0x01063AD3  007b05                  add      byte ptr [ebx + 5], bh         
  0x01063AD6  0000                    add      byte ptr [eax], al             
  0x01063AD8  2e1d0c004000            sbb      eax, 0x40000c                  
  0x01063ADE  2000                    and      byte ptr [eax], al             
  0x01063AE0  0091210000f4            add      byte ptr [ecx - 0xbffffdf], dl 
  0x01063AE6  6500a208000000          add      byte ptr gs:[edx + 8], ah      
  0x01063AED  023a                    add      bh, byte ptr [edx]             
  0x01063AEF  0000                    add      byte ptr [eax], al             
  0x01063AF2  3e009e040d0000          add      byte ptr ds:[esi + 0xd04], bl  
  0x01063AFA  44                      inc      esp                            
  0x01063AFB  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063AFE  0000                    add      byte ptr [eax], al             
  0x01063B00  00f4                    add      ah, dh                         
  0x01063B02  46                      inc      esi                            
  0x01063B03  0012                    add      byte ptr [edx], dl             
  0x01063B05  0000                    add      byte ptr [eax], al             
  0x01063B07  00d0                    add      al, dl                         
  0x01063B09  f4                      hlt                                     
  0x01063B0A  44                      inc      esp                            
  0x01063B0B  00ae0500002e            add      byte ptr [esi + 0x2e000005], ch 
  0x01063B11  1d0c004000              sbb      eax, 0x40000c                  
  0x01063B16  2000                    and      byte ptr [eax], al             
  0x01063B18  00902100000e            add      byte ptr [eax + 0xe000021], dl 
  0x01063B1E  3800                    cmp      byte ptr [eax], al             
  0x01063B20  00f4                    add      ah, dh                         
  0x01063B22  61                      popal                                   
  0x01063B23  00fd                    add      ch, bh                         
  0x01063B25  0300                    add      eax, dword ptr [eax]           
  0x01063B27  0000                    add      byte ptr [eax], al             
  0x01063B29  48                      dec      eax                            
  0x01063B2A  2000                    and      byte ptr [eax], al             
  0x01063B2C  90                      nop                                     
  0x01063B2D  0406                    add      al, 6                          
  0x01063B2F  0009                    add      byte ptr [ecx], cl             
  0x01063B31  0000                    add      byte ptr [eax], al             
  0x01063B33  0013                    add      byte ptr [ebx], dl             
  0x01063B35  0020                    add      byte ptr [eax], ah             
  0x01063B37  009040060004            add      byte ptr [eax + 0x4000640], dl 
  0x01063B3D  0000                    add      byte ptr [eax], al             
  0x01063B3F  0000                    add      byte ptr [eax], al             
  0x01063B41  d9440047                fld      dword ptr [eax + eax + 0x47]   
  0x01063B45  0020                    add      byte ptr [eax], ah             
  0x01063B47  004090                  add      byte ptr [eax - 0x70], al      
  0x01063B4A  0200                    add      al, byte ptr [eax]             
  0x01063B4C  260020                  add      byte ptr es:[eax], ah          
  0x01063B4F  0000                    add      byte ptr [eax], al             
  0x01063B51  58                      pop      eax                            
  0x01063B52  56                      push     esi                            
  0x01063B53  0000                    add      byte ptr [eax], al             
  0x01063B56  44                      inc      esp                            
  0x01063B57  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063B5A  0000                    add      byte ptr [eax], al             
  0x01063B5C  00f4                    add      ah, dh                         
  0x01063B5E  46                      inc      esi                            
  0x01063B5F  0012                    add      byte ptr [edx], dl             
  0x01063B61  0000                    add      byte ptr [eax], al             
  0x01063B63  00d0                    add      al, dl                         
  0x01063B65  f4                      hlt                                     
  0x01063B66  44                      inc      esp                            
  0x01063B67  00ae0500002e            add      byte ptr [esi + 0x2e000005], ch 
  0x01063B6D  1d0c004000              sbb      eax, 0x40000c                  
  0x01063B72  2000                    and      byte ptr [eax], al             
  0x01063B74  009021000008            add      byte ptr [eax + 0x8000021], dl 
  0x01063B7A  3800                    cmp      byte ptr [eax], al             
  0x01063B7C  00f4                    add      ah, dh                         
  0x01063B7E  57                      push     edi                            
  0x01063B7F  0002                    add      byte ptr [edx], al             
  0x01063B81  0000                    add      byte ptr [eax], al             
  0x01063B83  0000                    add      byte ptr [eax], al             
  0x01063B85  48                      dec      eax                            
  0x01063B86  2000                    and      byte ptr [eax], al             
  0x01063B88  0006                    add      byte ptr [esi], al             
  0x01063B8A  3800                    cmp      byte ptr [eax], al             
  0x01063B8C  90                      nop                                     
  0x01063B8D  0206                    add      al, byte ptr [esi]             
  0x01063B8F  000b                    add      byte ptr [ebx], cl             
  0x01063B91  0000                    add      byte ptr [eax], al             
  0x01063B93  0000                    add      byte ptr [eax], al             
  0x01063B95  1122                    adc      dword ptr [edx], esp           
  0x01063B97  0012                    add      byte ptr [edx], dl             
  0x01063B99  48                      dec      eax                            
  0x01063B9A  0400                    add      al, 0                          
  0x01063B9C  10cd                    adc      ch, cl                         
  0x01063B9E  06                      push     es                             
  0x01063B9F  0006                    add      byte ptr [esi], al             
  0x01063BA1  0000                    add      byte ptr [eax], al             
  0x01063BA3  0000                    add      byte ptr [eax], al             
  0x01063BA5  da440000                fiadd    dword ptr [eax + eax]          
  0x01063BA9  da5600                  ficom    dword ptr [esi]                
  0x01063BAC  45                      inc      ebp                            
  0x01063BAD  0020                    add      byte ptr [eax], ah             
  0x01063BAF  004090                  add      byte ptr [eax - 0x70], al      
  0x01063BB2  0200                    add      al, byte ptr [eax]             
  0x01063BB4  005956                  add      byte ptr [ecx + 0x56], bl      
  0x01063BB7  002a                    add      byte ptr [edx], ch             
  0x01063BB9  40                      inc      eax                            
  0x01063BBA  2000                    and      byte ptr [eax], al             
  0x01063BBC  00f0                    add      al, dh                         
  0x01063BBE  44                      inc      esp                            
  0x01063BBF  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063BC2  0000                    add      byte ptr [eax], al             
  0x01063BC4  00f4                    add      ah, dh                         
  0x01063BC6  46                      inc      esi                            
  0x01063BC7  0012                    add      byte ptr [edx], dl             
  0x01063BC9  0000                    add      byte ptr [eax], al             
  0x01063BCB  00d0                    add      al, dl                         
  0x01063BCD  f4                      hlt                                     
  0x01063BCE  44                      inc      esp                            
  0x01063BCF  00ae0500002e            add      byte ptr [esi + 0x2e000005], ch 
  0x01063BD5  1d0c004000              sbb      eax, 0x40000c                  
  0x01063BDA  2000                    and      byte ptr [eax], al             
  0x01063BDC  009021000006            add      byte ptr [eax + 0x6000021], dl 
  0x01063BE2  3800                    cmp      byte ptr [eax], al             
  0x01063BE4  00f4                    add      ah, dh                         
  0x01063BE6  6200                    bound    eax, qword ptr [eax]           
  0x01063BE8  af                      scasd    eax, dword ptr es:[edi]        
  0x01063BE9  0800                    or       byte ptr [eax], al             
  0x01063BEB  0000                    add      byte ptr [eax], al             
  0x01063BED  0239                    add      bh, byte ptr [ecx]             
  0x01063BEF  001b                    add      byte ptr [ebx], bl             
  0x01063BF1  f4                      hlt                                     
  0x01063BF2  45                      inc      ebp                            
  0x01063BF3  0001                    add      byte ptr [ecx], al             
  0x01063BF5  0000                    add      byte ptr [eax], al             
  0x01063BF7  0000                    add      byte ptr [eax], al             
  0x01063BF9  a6                      cmpsb    byte ptr [esi], byte ptr es:[edi] 
  0x01063BFA  2000                    and      byte ptr [eax], al             
  0x01063BFC  90                      nop                                     
  0x01063BFD  0306                    add      eax, dword ptr [esi]           
  0x01063BFF  000d00000000            add      byte ptr [0], cl               
  0x01063C05  1122                    adc      dword ptr [edx], esp           
  0x01063C07  0000                    add      byte ptr [eax], al             
  0x01063C09  da4f00                  fimul    dword ptr [edi]                
  0x01063C0C  004920                  add      byte ptr [ecx + 0x20], cl      
  0x01063C0F  0000                    add      byte ptr [eax], al             
  0x01063C11  d1440010                rol      dword ptr [eax + eax + 0x10], 1 
  0x01063C15  c60600                  mov      byte ptr [esi], 0              
  0x01063C18  0400                    add      al, 0                          
  0x01063C1A  0000                    add      byte ptr [eax], al             
  0x01063C1C  c0c944                  ror      cl, 0x44                       
  0x01063C1F  0045d1                  add      byte ptr [ebp - 0x2f], al      
  0x01063C22  44                      inc      esp                            
  0x01063C23  006870                  add      byte ptr [eax + 0x70], ch      
  0x01063C26  0200                    add      al, byte ptr [eax]             
  0x01063C28  00ce                    add      dh, cl                         
  0x01063C2A  2000                    and      byte ptr [eax], al             
  0x01063C2C  324820                  xor      cl, byte ptr [eax + 0x20]      
  0x01063C2F  0000                    add      byte ptr [eax], al             
  0x01063C31  8621                    xchg     byte ptr [ecx], ah             
  0x01063C33  0000                    add      byte ptr [eax], al             
  0x01063C36  44                      inc      esp                            
  0x01063C37  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063C3A  0000                    add      byte ptr [eax], al             
  0x01063C3C  00f4                    add      ah, dh                         
  0x01063C3E  46                      inc      esi                            
  0x01063C3F  0012                    add      byte ptr [edx], dl             
  0x01063C41  0000                    add      byte ptr [eax], al             
  0x01063C43  00d0                    add      al, dl                         
  0x01063C45  f4                      hlt                                     
  0x01063C46  44                      inc      esp                            
  0x01063C47  00ae0500002e            add      byte ptr [esi + 0x2e000005], ch 
  0x01063C4D  1d0c004000              sbb      eax, 0x40000c                  
  0x01063C52  2000                    and      byte ptr [eax], al             
  0x01063C54  009021000002            add      byte ptr [eax + 0x2000021], dl 
  0x01063C5A  3800                    cmp      byte ptr [eax], al             
  0x01063C5C  00f4                    add      ah, dh                         
  0x01063C5E  44                      inc      esp                            
  0x01063C5F  0000                    add      byte ptr [eax], al             
  0x01063C61  3200                    xor      al, byte ptr [eax]             
  0x01063C63  0000                    add      byte ptr [eax], al             
  0x01063C65  e856004500              call     0x14b3cc0                      
  0x01063C6A  2000                    and      byte ptr [eax], al             
  0x01063C6C  1b29                    sbb      ebp, dword ptr [ecx]           
  0x01063C6E  2000                    and      byte ptr [eax], al             
  0x01063C70  00f0                    add      al, dh                         
  0x01063C72  44                      inc      esp                            
  0x01063C73  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063C76  0000                    add      byte ptr [eax], al             
  0x01063C78  00f4                    add      ah, dh                         
  0x01063C7A  46                      inc      esi                            
  0x01063C7B  0002                    add      byte ptr [edx], al             
  0x01063C7D  0000                    add      byte ptr [eax], al             
  0x01063C7F  00d0                    add      al, dl                         
  0x01063C81  f4                      hlt                                     
  0x01063C82  44                      inc      esp                            
  0x01063C83  0020                    add      byte ptr [eax], ah             
  0x01063C85  0900                    or       dword ptr [eax], eax           
  0x01063C87  002e                    add      byte ptr [esi], ch             
  0x01063C89  1d0c004000              sbb      eax, 0x40000c                  
  0x01063C8E  2000                    and      byte ptr [eax], al             
  0x01063C90  0091210000f4            add      byte ptr [ecx - 0xbffffdf], dl 
  0x01063C96  56                      push     esi                            
  0x01063C97  0008                    add      byte ptr [eax], cl             
  0x01063C99  06                      push     es                             
  0x01063C9A  0000                    add      byte ptr [eax], al             
  0x01063C9C  00f0                    add      al, dh                         
  0x01063C9E  44                      inc      esp                            
  0x01063C9F  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063CA2  0000                    add      byte ptr [eax], al             
  0x01063CA4  40                      inc      eax                            
  0x01063CA5  0020                    add      byte ptr [eax], ah             
  0x01063CA7  0000                    add      byte ptr [eax], al             
  0x01063CA9  90                      nop                                     
  0x01063CAA  2100                    and      dword ptr [eax], eax           
  0x01063CAC  00e1                    add      cl, ah                         
  0x01063CAE  44                      inc      esp                            
  0x01063CAF  0000                    add      byte ptr [eax], al             
  0x01063CB1  f4                      hlt                                     
  0x01063CB2  46                      inc      esi                            
  0x01063CB3  00ff                    add      bh, bh                         
  0x01063CB6  7f00                    jg       0x1063cb8                      
                                        ; XREF: 0x01063CB6 (cond_jump)
  0x01063CB8  d0e0                    shl      al, 1                          
  0x01063CBA  44                      inc      esp                            
  0x01063CBB  004500                  add      byte ptr [ebp], al             
  0x01063CBE  2000                    and      byte ptr [eax], al             
  0x01063CC0  1b29                    sbb      ebp, dword ptr [ecx]           
  0x01063CC2  2000                    and      byte ptr [eax], al             
  0x01063CC4  00f4                    add      ah, dh                         
  0x01063CC6  56                      push     esi                            
  0x01063CC7  002c09                  add      byte ptr [ecx + ecx], ch       
  0x01063CCA  0000                    add      byte ptr [eax], al             
  0x01063CCC  00f0                    add      al, dh                         
  0x01063CCE  44                      inc      esp                            
  0x01063CCF  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063CD2  0000                    add      byte ptr [eax], al             
  0x01063CD4  40                      inc      eax                            
  0x01063CD5  0020                    add      byte ptr [eax], ah             
  0x01063CD7  0000                    add      byte ptr [eax], al             
  0x01063CD9  90                      nop                                     
  0x01063CDA  2100                    and      dword ptr [eax], eax           
  0x01063CDC  006055                  add      byte ptr [eax + 0x55], ah      
  0x01063CDF  0000                    add      byte ptr [eax], al             
  0x01063CE2  44                      inc      esp                            
  0x01063CE3  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063CE6  0000                    add      byte ptr [eax], al             
  0x01063CE8  00f4                    add      ah, dh                         
  0x01063CEA  46                      inc      esi                            
  0x01063CEB  0012                    add      byte ptr [edx], dl             
  0x01063CED  0000                    add      byte ptr [eax], al             
  0x01063CEF  00d0                    add      al, dl                         
  0x01063CF1  f4                      hlt                                     
  0x01063CF2  44                      inc      esp                            
  0x01063CF3  00ae0500002e            add      byte ptr [esi + 0x2e000005], ch 
  0x01063CF9  1d0c004000              sbb      eax, 0x40000c                  
  0x01063CFE  2000                    and      byte ptr [eax], al             
  0x01063D00  009021000006            add      byte ptr [eax + 0x6000021], dl 
  0x01063D06  3800                    cmp      byte ptr [eax], al             
  0x01063D08  00f4                    add      ah, dh                         
  0x01063D0A  6200                    bound    eax, qword ptr [eax]           
  0x01063D0C  ac                      lodsb    al, byte ptr [esi]             
  0x01063D0D  0800                    or       byte ptr [eax], al             
  0x01063D0F  0000                    add      byte ptr [eax], al             
  0x01063D11  0239                    add      bh, byte ptr [ecx]             
  0x01063D13  001b                    add      byte ptr [ebx], bl             
  0x01063D15  a6                      cmpsb    byte ptr [esi], byte ptr es:[edi] 
  0x01063D16  2000                    and      byte ptr [eax], al             
  0x01063D18  90                      nop                                     
  0x01063D19  0306                    add      eax, dword ptr [esi]           
  0x01063D1B  000d00000000            add      byte ptr [0], cl               
  0x01063D21  1122                    adc      dword ptr [edx], esp           
  0x01063D23  0000                    add      byte ptr [eax], al             
  0x01063D25  da4f00                  fimul    dword ptr [edi]                
  0x01063D28  004920                  add      byte ptr [ecx + 0x20], cl      
  0x01063D2B  0000                    add      byte ptr [eax], al             
  0x01063D2D  d1440010                rol      dword ptr [eax + eax + 0x10], 1 
  0x01063D31  c60600                  mov      byte ptr [esi], 0              
  0x01063D34  0400                    add      al, 0                          
  0x01063D36  0000                    add      byte ptr [eax], al             
  0x01063D38  c0c944                  ror      cl, 0x44                       
  0x01063D3B  0045d1                  add      byte ptr [ebp - 0x2f], al      
  0x01063D3E  44                      inc      esp                            
  0x01063D3F  006870                  add      byte ptr [eax + 0x70], ch      
  0x01063D42  0200                    add      al, byte ptr [eax]             
  0x01063D44  00ce                    add      dh, cl                         
  0x01063D46  2000                    and      byte ptr [eax], al             
  0x01063D48  324820                  xor      cl, byte ptr [eax + 0x20]      
  0x01063D4B  0000                    add      byte ptr [eax], al             
  0x01063D4D  8621                    xchg     byte ptr [ecx], ah             
  0x01063D4F  0000                    add      byte ptr [eax], al             
  0x01063D52  44                      inc      esp                            
  0x01063D53  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063D56  0000                    add      byte ptr [eax], al             
  0x01063D58  00f4                    add      ah, dh                         
  0x01063D5A  46                      inc      esi                            
  0x01063D5B  0012                    add      byte ptr [edx], dl             
  0x01063D5D  0000                    add      byte ptr [eax], al             
  0x01063D5F  00d0                    add      al, dl                         
  0x01063D61  f4                      hlt                                     
  0x01063D62  44                      inc      esp                            
  0x01063D63  00ae0500002e            add      byte ptr [esi + 0x2e000005], ch 
  0x01063D69  1d0c004000              sbb      eax, 0x40000c                  
  0x01063D6E  2000                    and      byte ptr [eax], al             
  0x01063D70  009021000002            add      byte ptr [eax + 0x2000021], dl 
  0x01063D76  3800                    cmp      byte ptr [eax], al             
  0x01063D78  00f4                    add      ah, dh                         
  0x01063D7A  44                      inc      esp                            
  0x01063D7B  0000                    add      byte ptr [eax], al             
  0x01063D7D  3200                    xor      al, byte ptr [eax]             
  0x01063D7F  0000                    add      byte ptr [eax], al             
  0x01063D81  e856004500              call     0x14b3ddc                      
  0x01063D86  2000                    and      byte ptr [eax], al             
  0x01063D88  1b29                    sbb      ebp, dword ptr [ecx]           
  0x01063D8A  2000                    and      byte ptr [eax], al             
  0x01063D8C  00f0                    add      al, dh                         
  0x01063D8E  44                      inc      esp                            
  0x01063D8F  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063D92  0000                    add      byte ptr [eax], al             
  0x01063D94  00f4                    add      ah, dh                         
  0x01063D96  46                      inc      esi                            
  0x01063D97  0002                    add      byte ptr [edx], al             
  0x01063D99  0000                    add      byte ptr [eax], al             
  0x01063D9B  00d0                    add      al, dl                         
  0x01063D9D  f4                      hlt                                     
  0x01063D9E  44                      inc      esp                            
  0x01063D9F  0020                    add      byte ptr [eax], ah             
  0x01063DA1  0900                    or       dword ptr [eax], eax           
  0x01063DA3  002e                    add      byte ptr [esi], ch             
  0x01063DA5  1d0c004000              sbb      eax, 0x40000c                  
  0x01063DAA  2000                    and      byte ptr [eax], al             
  0x01063DAC  0091210000f4            add      byte ptr [ecx - 0xbffffdf], dl 
  0x01063DB2  56                      push     esi                            
  0x01063DB3  0008                    add      byte ptr [eax], cl             
  0x01063DB5  06                      push     es                             
  0x01063DB6  0000                    add      byte ptr [eax], al             
  0x01063DB8  00f0                    add      al, dh                         
  0x01063DBA  44                      inc      esp                            
  0x01063DBB  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063DBE  0000                    add      byte ptr [eax], al             
  0x01063DC0  40                      inc      eax                            
  0x01063DC1  0020                    add      byte ptr [eax], ah             
  0x01063DC3  0000                    add      byte ptr [eax], al             
  0x01063DC5  90                      nop                                     
  0x01063DC6  2100                    and      dword ptr [eax], eax           
  0x01063DC8  00e1                    add      cl, ah                         
  0x01063DCA  44                      inc      esp                            
  0x01063DCB  0000                    add      byte ptr [eax], al             
  0x01063DCD  f4                      hlt                                     
  0x01063DCE  46                      inc      esi                            
  0x01063DCF  0000                    add      byte ptr [eax], al             
  0x01063DD1  004000                  add      byte ptr [eax], al             
  0x01063DD4  d0e0                    shl      al, 1                          
  0x01063DD6  46                      inc      esi                            
  0x01063DD7  005560                  add      byte ptr [ebp + 0x60], dl      
  0x01063DDA  44                      inc      esp                            
  0x01063DDB  001b                    add      byte ptr [ebx], bl             
  0x01063DDD  2920                    sub      dword ptr [eax], esp           
  0x01063DDF  0000                    add      byte ptr [eax], al             
  0x01063DE1  f4                      hlt                                     
  0x01063DE2  56                      push     esi                            
  0x01063DE3  007f0b                  add      byte ptr [edi + 0xb], bh       
  0x01063DE6  0000                    add      byte ptr [eax], al             
  0x01063DE8  00f0                    add      al, dh                         
  0x01063DEA  44                      inc      esp                            
  0x01063DEB  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063DEE  0000                    add      byte ptr [eax], al             
  0x01063DF0  40                      inc      eax                            
  0x01063DF1  0020                    add      byte ptr [eax], ah             
  0x01063DF3  0000                    add      byte ptr [eax], al             
  0x01063DF5  90                      nop                                     
  0x01063DF6  2100                    and      dword ptr [eax], eax           
  0x01063DF8  006055                  add      byte ptr [eax + 0x55], ah      
  0x01063DFB  0000                    add      byte ptr [eax], al             
  0x01063DFE  44                      inc      esp                            
  0x01063DFF  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063E02  0000                    add      byte ptr [eax], al             
  0x01063E04  00f4                    add      ah, dh                         
  0x01063E06  46                      inc      esi                            
  0x01063E07  0012                    add      byte ptr [edx], dl             
  0x01063E09  0000                    add      byte ptr [eax], al             
  0x01063E0B  00d0                    add      al, dl                         
  0x01063E0D  f4                      hlt                                     
  0x01063E0E  44                      inc      esp                            
  0x01063E0F  00ae0500002e            add      byte ptr [esi + 0x2e000005], ch 
  0x01063E15  1d0c004000              sbb      eax, 0x40000c                  
  0x01063E1A  2000                    and      byte ptr [eax], al             
  0x01063E1C  009021000006            add      byte ptr [eax + 0x6000021], dl 
  0x01063E22  3800                    cmp      byte ptr [eax], al             
  0x01063E24  00ae20009003            add      byte ptr [esi + 0x3900020], ch 
  0x01063E2A  06                      push     es                             
  0x01063E2B  000a                    add      byte ptr [edx], cl             
  0x01063E2D  0000                    add      byte ptr [eax], al             
  0x01063E2F  0000                    add      byte ptr [eax], al             
  0x01063E31  1122                    adc      dword ptr [edx], esp           
  0x01063E33  0000                    add      byte ptr [eax], al             
  0x01063E35  99                      cdq                                     
  0x01063E36  2100                    and      dword ptr [eax], eax           
  0x01063E38  0012                    add      byte ptr [edx], dl             
  0x01063E3A  2200                    and      al, byte ptr [eax]             
  0x01063E3C  004920                  add      byte ptr [ecx + 0x20], cl      
  0x01063E3F  0000                    add      byte ptr [eax], al             
  0x01063E41  d9440000                fld      dword ptr [eax + eax]          
  0x01063E45  5a                      pop      edx                            
  0x01063E46  44                      inc      esp                            
  0x01063E47  0000                    add      byte ptr [eax], al             
  0x01063E49  d9440000                fld      dword ptr [eax + eax]          
  0x01063E4D  5a                      pop      edx                            
  0x01063E4E  44                      inc      esp                            
  0x01063E4F  0032                    add      byte ptr [edx], dh             
  0x01063E51  48                      dec      eax                            
  0x01063E52  2000                    and      byte ptr [eax], al             
  0x01063E54  0c00                    or       al, 0                          
  0x01063E56  0000                    add      byte ptr [eax], al             
  0x01063E58  00f4                    add      ah, dh                         
  0x01063E5A  56                      push     esi                            
  0x01063E5B  007f0b                  add      byte ptr [edi + 0xb], bh       
  0x01063E5E  0000                    add      byte ptr [eax], al             
  0x01063E60  00f0                    add      al, dh                         
  0x01063E62  44                      inc      esp                            
  0x01063E63  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063E66  0000                    add      byte ptr [eax], al             
  0x01063E68  40                      inc      eax                            
  0x01063E69  0020                    add      byte ptr [eax], ah             
  0x01063E6B  0000                    add      byte ptr [eax], al             
  0x01063E6D  90                      nop                                     
  0x01063E6E  2100                    and      dword ptr [eax], eax           
  0x01063E70  00f4                    add      ah, dh                         
  0x01063E72  56                      push     esi                            
  0x01063E73  000d06000000            add      byte ptr [6], cl               
  0x01063E7A  44                      inc      esp                            
  0x01063E7B  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063E7E  0000                    add      byte ptr [eax], al             
  0x01063E80  40                      inc      eax                            
  0x01063E81  0020                    add      byte ptr [eax], ah             
  0x01063E83  0000                    add      byte ptr [eax], al             
  0x01063E85  91                      xchg     ecx, eax                       
  0x01063E86  2100                    and      dword ptr [eax], eax           
  0x01063E88  00f4                    add      ah, dh                         
  0x01063E8A  56                      push     esi                            
  0x01063E8B  00840b000000f0          add      byte ptr [ebx + ecx - 0x10000000], al 
  0x01063E92  44                      inc      esp                            
  0x01063E93  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063E96  0000                    add      byte ptr [eax], al             
  0x01063E98  40                      inc      eax                            
  0x01063E99  0020                    add      byte ptr [eax], ah             
  0x01063E9B  0000                    add      byte ptr [eax], al             
  0x01063E9D  92                      xchg     edx, eax                       
  0x01063E9E  2100                    and      dword ptr [eax], eax           
  0x01063EA0  1be0                    sbb      esp, eax                       
  0x01063EA2  44                      inc      esp                            
  0x01063EA3  0000                    add      byte ptr [eax], al             
  0x01063EA5  e156                    loope    0x1063efd                      
  0x01063EA7  0042f4                  add      byte ptr [edx - 0xc], al       
  0x01063EAA  45                      inc      ebp                            
  0x01063EAB  0001                    add      byte ptr [ecx], al             
  0x01063EAD  0000                    add      byte ptr [eax], al             
  0x01063EAF  0068a0                  add      byte ptr [eax - 0x60], ch      
  0x01063EB2  0200                    add      al, byte ptr [eax]             
  0x01063EB4  006257                  add      byte ptr [edx + 0x57], ah      
  0x01063EB7  0000                    add      byte ptr [eax], al             
  0x01063EB9  61                      popal                                   
  0x01063EBA  44                      inc      esp                            
  0x01063EBB  000c00                  add      byte ptr [eax + eax], cl       
  0x01063EBE  0000                    add      byte ptr [eax], al             
  0x01063EC0  00f4                    add      ah, dh                         
  0x01063EC2  60                      pushal                                  
  0x01063EC3  00fd                    add      ch, bh                         
  0x01063EC5  0200                    add      al, byte ptr [eax]             
  0x01063EC7  0000                    add      byte ptr [eax], al             
  0x01063ECA  44                      inc      esp                            
  0x01063ECB  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01063ECE  0000                    add      byte ptr [eax], al             
  0x01063ED0  00f4                    add      ah, dh                         
  0x01063ED2  46                      inc      esi                            
  0x01063ED3  0080000000d0            add      byte ptr [eax - 0x30000000], al 
  0x01063ED9  f4                      hlt                                     
  0x01063EDA  44                      inc      esp                            
  0x01063EDB  0012                    add      byte ptr [edx], dl             
  0x01063EDD  06                      push     es                             
  0x01063EDE  0000                    add      byte ptr [eax], al             
  0x01063EE0  2e1d0c004000            sbb      eax, 0x40000c                  
  0x01063EE6  2000                    and      byte ptr [eax], al             
  0x01063EE8  0091210000f4            add      byte ptr [ecx - 0xbffffdf], dl 
  0x01063EEE  6400b208000000          add      byte ptr fs:[edx + 8], dh      
  0x01063EF5  f4                      hlt                                     
  0x01063EF6  650000                  add      byte ptr gs:[eax], al          
  0x01063EF9  0000                    add      byte ptr [eax], al             
  0x01063EFB  00fc                    add      ah, bh                         
                                        ; XREF: 0x01063EA5 (cond_jump)
  0x01063EFD  040d                    add      al, 0xd                        
  0x01063EFF  000c00                  add      byte ptr [eax + eax], cl       
  0x01063F02  0000                    add      byte ptr [eax], al             
  0x01063F04  00f0                    add      al, dh                         
  0x01063F06  56                      push     esi                            
  0x01063F07  0031                    add      byte ptr [ecx], dh             
  0x01063F09  0900                    or       dword ptr [eax], eax           
  0x01063F0B  0003                    add      byte ptr [ebx], al             
  0x01063F0D  0020                    add      byte ptr [eax], ah             
  0x01063F0F  000e                    add      byte ptr [esi], cl             
  0x01063F11  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01063F12  050000f460              add      eax, 0x60f40000                
  0x01063F17  0000                    add      byte ptr [eax], al             
  0x01063F19  0000                    add      byte ptr [eax], al             
  0x01063F1B  0000                    add      byte ptr [eax], al             
  0x01063F1D  f4                      hlt                                     
  0x01063F1E  61                      popal                                   
  0x01063F1F  004000                  add      byte ptr [eax], al             
  0x01063F22  0000                    add      byte ptr [eax], al             
  0x01063F24  001422                  add      byte ptr [edx], dl             
  0x01063F27  0000                    add      byte ptr [eax], al             
  0x01063F29  35220000f4              xor      eax, 0xf4000022                
  0x01063F2E  6200                    bound    eax, qword ptr [eax]           
  0x01063F30  b20a                    mov      dl, 0xa                        
  0x01063F32  0000                    add      byte ptr [eax], al             
  0x01063F34  00f4                    add      ah, dh                         
  0x01063F36  6600f2                  add      dl, dh                         
  0x01063F39  0a00                    or       al, byte ptr [eax]             
  0x01063F3B  0000                    add      byte ptr [eax], al             
  0x01063F3D  3f                      aas                                     
  0x01063F3E  3a00                    cmp      al, byte ptr [eax]             
  0x01063F40  4d                      dec      ebp                            
  0x01063F41  050d000a0c              add      eax, 0xc0a000d                 
  0x01063F46  050000f460              add      eax, 0x60f40000                
  0x01063F4B  0000                    add      byte ptr [eax], al             
  0x01063F4D  0000                    add      byte ptr [eax], al             
  0x01063F4F  0000                    add      byte ptr [eax], al             
  0x01063F51  1422                    adc      al, 0x22                       
  0x01063F53  0000                    add      byte ptr [eax], al             
  0x01063F55  f4                      hlt                                     
  0x01063F56  6200                    bound    eax, qword ptr [eax]           
  0x01063F58  b209                    mov      dl, 9                          
  0x01063F5A  0000                    add      byte ptr [eax], al             
  0x01063F5C  00f4                    add      ah, dh                         
  0x01063F5E  660032                  add      byte ptr [edx], dh             
  0x01063F61  0a00                    or       al, byte ptr [eax]             
  0x01063F63  0000                    add      byte ptr [eax], al             
  0x01063F65  7f3a                    jg       0x1063fa1                      
  0x01063F67  003e                    add      byte ptr [esi], bh             
  0x01063F69  050d000c00              add      eax, 0xc000d                   
  0x01063F6E  0000                    add      byte ptr [eax], al             
  0x01063F70  a0000500a0              mov      al, byte ptr [0xa0000500]      
  0x01063F75  61                      popal                                   
  0x01063F76  0400                    add      al, 0                          
  0x01063F78  00f0                    add      al, dh                         
  0x01063F7A  56                      push     esi                            
  0x01063F7B  0031                    add      byte ptr [ecx], dh             
  0x01063F7D  0900                    or       dword ptr [eax], eax           
  0x01063F7F  0003                    add      byte ptr [ebx], al             
  0x01063F81  0020                    add      byte ptr [eax], ah             
  0x01063F83  0015a4050000            add      byte ptr [0x5a4], dl           
  0x01063F89  f4                      hlt                                     
  0x01063F8A  60                      pushal                                  
  0x01063F8B  0000                    add      byte ptr [eax], al             
  0x01063F8D  0000                    add      byte ptr [eax], al             
  0x01063F8F  0000                    add      byte ptr [eax], al             
  0x01063F91  f4                      hlt                                     
  0x01063F92  61                      popal                                   
  0x01063F93  004000                  add      byte ptr [eax], al             
  0x01063F96  0000                    add      byte ptr [eax], al             
  0x01063F98  00f4                    add      ah, dh                         
  0x01063F9A  6400fd                  add      ch, bh                         
  0x01063F9D  0300                    add      eax, dword ptr [eax]           
  0x01063F9F  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01063F65 (cond_jump)
  0x01063FA1  f4                      hlt                                     
  0x01063FA2  6500fc                  add      ah, bh                         
  0x01063FA5  0400                    add      al, 0                          
  0x01063FA7  0000                    add      byte ptr [eax], al             
  0x01063FA9  f4                      hlt                                     
  0x01063FAA  6200                    bound    eax, qword ptr [eax]           
  0x01063FAC  b20a                    mov      dl, 0xa                        
  0x01063FAE  0000                    add      byte ptr [eax], al             
  0x01063FB0  00f4                    add      ah, dh                         
  0x01063FB2  6600f2                  add      dl, dh                         
  0x01063FB5  0a00                    or       al, byte ptr [eax]             
  0x01063FB7  0000                    add      byte ptr [eax], al             
  0x01063FB9  2038                    and      byte ptr [eax], bh             
  0x01063FBB  0000                    add      byte ptr [eax], al             
  0x01063FBD  1923                    sbb      dword ptr [ebx], esp           
  0x01063FBF  0000                    add      byte ptr [eax], al             
  0x01063FC1  3f                      aas                                     
  0x01063FC2  3a00                    cmp      al, byte ptr [eax]             
  0x01063FC4  0003                    add      byte ptr [ebx], al             
  0x01063FC6  3c00                    cmp      al, 0                          
  0x01063FC8  00f4                    add      ah, dh                         
  0x01063FCA  7500                    jne      0x1063fcc                      
                                        ; XREF: 0x01063FCA (cond_jump)
  0x01063FCC  fd                      std                                     
  0x01063FCE  ff00                    inc      dword ptr [eax]                
  0x01063FD0  7305                    jae      0x1063fd7                      
  0x01063FD2  0d00110c05              or       eax, 0x50c1100                 
                                        ; XREF: 0x01063FD0 (cond_jump)
  0x01063FD7  0000                    add      byte ptr [eax], al             
  0x01063FD9  f4                      hlt                                     
  0x01063FDA  60                      pushal                                  
  0x01063FDB  0000                    add      byte ptr [eax], al             
  0x01063FDD  0000                    add      byte ptr [eax], al             
  0x01063FDF  0000                    add      byte ptr [eax], al             
  0x01063FE1  f4                      hlt                                     
  0x01063FE2  6400fd                  add      ch, bh                         
  0x01063FE5  0300                    add      eax, dword ptr [eax]           
  0x01063FE7  0000                    add      byte ptr [eax], al             
  0x01063FE9  f4                      hlt                                     
  0x01063FEA  6500fc                  add      ah, bh                         
  0x01063FED  0400                    add      al, 0                          
  0x01063FEF  0000                    add      byte ptr [eax], al             
  0x01063FF1  f4                      hlt                                     
  0x01063FF2  6200                    bound    eax, qword ptr [eax]           
  0x01063FF4  b209                    mov      dl, 9                          
  0x01063FF6  0000                    add      byte ptr [eax], al             
  0x01063FF8  00f4                    add      ah, dh                         
  0x01063FFA  660032                  add      byte ptr [edx], dh             
  0x01063FFD  0a00                    or       al, byte ptr [eax]             
  0x01063FFF  0000                    add      byte ptr [eax], al             
  0x01064001  40                      inc      eax                            
  0x01064002  3800                    cmp      byte ptr [eax], al             
  0x01064004  007f3a                  add      byte ptr [edi + 0x3a], bh      
  0x01064007  0000                    add      byte ptr [eax], al             
  0x01064009  023c00                  add      bh, byte ptr [eax + eax]       
  0x0106400C  00f4                    add      ah, dh                         
  0x0106400E  7500                    jne      0x1064010                      
  0x01064012  ff00                    inc      dword ptr [eax]                
  0x01064014  64050d0020f4            add      eax, 0xf420000d                
  0x0106401A  0500ffff00              add      eax, 0xffff00                  
  0x0106401F  00a061040000            add      byte ptr [eax + 0x461], ah     
  0x01064026  56                      push     esi                            
  0x01064027  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106402A  0000                    add      byte ptr [eax], al             
  0x0106402C  00f0                    add      al, dh                         
  0x0106402E  44                      inc      esp                            
  0x0106402F  00970b000045            add      byte ptr [edi + 0x4500000b], dl 
  0x01064035  f4                      hlt                                     
  0x01064036  60                      pushal                                  
  0x01064037  00fd                    add      ch, bh                         
  0x01064039  0300                    add      eax, dword ptr [eax]           
  0x0106403B  0008                    add      byte ptr [eax], cl             
  0x0106403D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106403E  050000f461              add      eax, 0x61f40000                
  0x01064043  008001000090            add      byte ptr [eax - 0x6fffffff], al 
  0x01064049  b506                    mov      ch, 6                          
  0x0106404B  0003                    add      byte ptr [ebx], al             
  0x0106404D  0000                    add      byte ptr [eax], al             
  0x0106404F  0000                    add      byte ptr [eax], al             
  0x01064051  d8440000                fadd     dword ptr [eax + eax]          
  0x01064055  59                      pop      ecx                            
  0x01064056  44                      inc      esp                            
  0x01064057  0007                    add      byte ptr [edi], al             
  0x01064059  0c05                    or       al, 5                          
  0x0106405B  0000                    add      byte ptr [eax], al             
  0x0106405D  f4                      hlt                                     
  0x0106405E  61                      popal                                   
  0x0106405F  003502000090            add      byte ptr [0x90000002], dh      
  0x01064065  07                      pop      es                             
  0x01064066  06                      push     es                             
  0x01064067  0003                    add      byte ptr [ebx], al             
  0x01064069  0000                    add      byte ptr [eax], al             
  0x0106406B  0000                    add      byte ptr [eax], al             
  0x0106406D  d8440000                fadd     dword ptr [eax + eax]          
  0x01064071  59                      pop      ecx                            
  0x01064072  44                      inc      esp                            
  0x01064073  000c00                  add      byte ptr [eax + eax], cl       
  0x01064076  0000                    add      byte ptr [eax], al             
  0x01064078  00f0                    add      al, dh                         
  0x0106407A  56                      push     esi                            
  0x0106407B  0031                    add      byte ptr [ecx], dh             
  0x0106407D  0900                    or       dword ptr [eax], eax           
  0x0106407F  0003                    add      byte ptr [ebx], al             
  0x01064081  0020                    add      byte ptr [eax], ah             
  0x01064083  000a                    add      byte ptr [edx], cl             
  0x01064085  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01064086  050000f460              add      eax, 0x60f40000                
  0x0106408B  0000                    add      byte ptr [eax], al             
  0x0106408D  0000                    add      byte ptr [eax], al             
  0x0106408F  0000                    add      byte ptr [eax], al             
  0x01064091  40                      inc      eax                            
  0x01064092  3800                    cmp      byte ptr [eax], al             
  0x01064094  ef                      out      dx, eax                        
  0x01064095  030d0000f460            add      ecx, dword ptr [0x60f40000]    
  0x0106409B  004000                  add      byte ptr [eax], al             
  0x0106409E  0000                    add      byte ptr [eax], al             
  0x010640A0  004038                  add      byte ptr [eax + 0x38], al      
  0x010640A3  00ef                    add      bh, ch                         
  0x010640A5  030d00050c05            add      ecx, dword ptr [0x50c0500]     
  0x010640AB  0000                    add      byte ptr [eax], al             
  0x010640AD  f4                      hlt                                     
  0x010640AE  60                      pushal                                  
  0x010640AF  0000                    add      byte ptr [eax], al             
  0x010640B1  0000                    add      byte ptr [eax], al             
  0x010640B3  0000                    add      byte ptr [eax], al             
  0x010640B5  803800                  cmp      byte ptr [eax], 0              
  0x010640B8  ef                      out      dx, eax                        
  0x010640B9  030d000c0000            add      ecx, dword ptr [0xc00]         
  0x010640BF  0000                    add      byte ptr [eax], al             
  0x010640C2  56                      push     esi                            
  0x010640C3  00970b000000            add      byte ptr [edi + 0xb], dl       
  0x010640CA  44                      inc      esp                            
  0x010640CB  00410b                  add      byte ptr [ecx + 0xb], al       
  0x010640CE  0000                    add      byte ptr [eax], al             
  0x010640D0  45                      inc      ebp                            
  0x010640D1  f4                      hlt                                     
  0x010640D2  45                      inc      ebp                            
  0x010640D3  0001                    add      byte ptr [ecx], al             
  0x010640D5  0000                    add      byte ptr [eax], al             
  0x010640D7  0003                    add      byte ptr [ebx], al             
  0x010640D9  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010640DA  05000d0805              add      eax, 0x5080d00                 
  0x010640DF  0003                    add      byte ptr [ebx], al             
  0x010640E1  0c05                    or       al, 5                          
  0x010640E3  0000                    add      byte ptr [eax], al             
  0x010640E5  7045                    jo       0x106412c                      
  0x010640E7  008f0b000000            add      byte ptr [edi + 0xb], cl       
  0x010640ED  f4                      hlt                                     
  0x010640EE  60                      pushal                                  
  0x010640EF  007f0b                  add      byte ptr [edi + 0xb], bh       
  0x010640F2  0000                    add      byte ptr [eax], al             
  0x010640F4  00f4                    add      ah, dh                         
  0x010640F6  61                      popal                                   
  0x010640F7  00a305000090            add      byte ptr [ebx - 0x6ffffffb], ah 
  0x010640FD  0506000300              add      eax, 0x30006                   
  0x01064102  0000                    add      byte ptr [eax], al             
  0x01064104  00d8                    add      al, bl                         
  0x01064106  44                      inc      esp                            
  0x01064107  0000                    add      byte ptr [eax], al             
  0x01064109  59                      pop      ecx                            
  0x0106410A  44                      inc      esp                            
  0x0106410B  000c00                  add      byte ptr [eax + eax], cl       
  0x0106410E  0000                    add      byte ptr [eax], al             
  0x01064110  0003                    add      byte ptr [ebx], al             
  0x01064112  2900                    sub      dword ptr [eax], eax           
  0x01064114  00f0                    add      al, dh                         
  0x01064116  7000                    jo       0x1064118                      
                                        ; XREF: 0x01064116 (cond_jump)
  0x01064118  41                      inc      ecx                            
  0x01064119  0b00                    or       eax, dword ptr [eax]           
  0x0106411B  0000                    add      byte ptr [eax], al             
  0x0106411D  f4                      hlt                                     
  0x0106411E  60                      pushal                                  
  0x0106411F  007f0b                  add      byte ptr [edi + 0xb], bh       
  0x01064122  0000                    add      byte ptr [eax], al             
  0x01064124  00e8                    add      al, ch                         
  0x01064126  56                      push     esi                            
  0x01064127  008541010010            add      byte ptr [ebp + 0x10000141], al 
  0x0106412D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106412E  050000f460              add      eax, 0x60f40000                
  0x01064133  002c09                  add      byte ptr [ecx + ecx], ch       
  0x01064136  0000                    add      byte ptr [eax], al             
  0x01064138  00e8                    add      al, ch                         
  0x0106413A  56                      push     esi                            
  0x0106413B  00854101000b            add      byte ptr [ebp + 0xb000141], al 
  0x01064141  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01064142  050000f056              add      eax, 0x56f00000                
  0x01064147  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106414A  0000                    add      byte ptr [eax], al             
  0x0106414C  854001                  test     dword ptr [eax + 1], eax       
  0x0106414F  0006                    add      byte ptr [esi], al             
  0x01064151  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01064152  050000f460              add      eax, 0x60f40000                
  0x01064157  00a305000000            add      byte ptr [ebx + 5], ah         
  0x0106415D  e856008541              call     0x428b41b8                     
  0x01064162  0100                    add      dword ptr [eax], eax           
  0x01064164  02a40500000229          add      ah, byte ptr [ebp + eax + 0x29020000] 
  0x0106416B  0000                    add      byte ptr [eax], al             
  0x0106416D  f4                      hlt                                     
  0x0106416E  60                      pushal                                  
  0x0106416F  008a0b000000            add      byte ptr [edx + 0xb], cl       
  0x01064175  6851000c00              push     0xc0051                        
  0x0106417A  0000                    add      byte ptr [eax], al             
  0x0106417C  0018                    add      byte ptr [eax], bl             
  0x0106417E  3d0000f044              cmp      eax, 0x44f00000                
  0x01064183  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01064186  0000                    add      byte ptr [eax], al             
  0x01064188  00f0                    add      al, dh                         
  0x0106418A  56                      push     esi                            
  0x0106418B  00970b000045            add      byte ptr [edi + 0x4500000b], dl 
  0x01064191  f4                      hlt                                     
  0x01064192  60                      pushal                                  
  0x01064193  00800100000c            add      byte ptr [eax + 0xc000001], al 
  0x01064199  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106419A  0500009620              add      eax, 0x20960000                
  0x0106419F  0000                    add      byte ptr [eax], al             
  0x010641A1  f4                      hlt                                     
  0x010641A2  61                      popal                                   
  0x010641A3  004102                  add      byte ptr [ecx + 2], al         
  0x010641A6  0000                    add      byte ptr [eax], al             
  0x010641A8  00f4                    add      ah, dh                         
  0x010641AA  56                      push     esi                            
  0x010641AB  00a50b000000            add      byte ptr [ebp + 0xb], ah       
  0x010641B1  c422                    les      esp, ptr [edx]                 
  0x010641B3  004000                  add      byte ptr [eax], al             
  0x010641B6  2000                    and      byte ptr [eax], al             
  0x010641B8  0092210000e2            add      byte ptr [edx - 0x1dffffdf], dl 
  0x010641BE  7100                    jno      0x10641c0                      
                                        ; XREF: 0x010641BE (cond_jump)
  0x010641C0  8b050d000a0c            mov      eax, dword ptr [0xc0a000d]     
  0x010641C6  050000f056              add      eax, 0x56f00000                
  0x010641CB  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x010641CE  0000                    add      byte ptr [eax], al             
  0x010641D0  03f4                    add      esi, esp                       
  0x010641D2  60                      pushal                                  
  0x010641D3  003502000005            add      byte ptr [0x5000002], dh       
  0x010641D9  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010641DA  050000f461              add      eax, 0x61f40000                
  0x010641DF  00f6                    add      dh, dh                         
  0x010641E1  0200                    add      al, byte ptr [eax]             
  0x010641E3  0000                    add      byte ptr [eax], al             
  0x010641E5  07                      pop      es                             
  0x010641E6  3900                    cmp      dword ptr [eax], eax           
  0x010641E8  8b050d000c00            mov      eax, dword ptr [0xc000d]       
  0x010641EE  0000                    add      byte ptr [eax], al             
  0x010641F0  00f0                    add      al, dh                         
  0x010641F2  44                      inc      esp                            
  0x010641F3  00410b                  add      byte ptr [ecx + 0xb], al       
  0x010641F6  0000                    add      byte ptr [eax], al             
  0x010641F8  00f0                    add      al, dh                         
  0x010641FA  56                      push     esi                            
  0x010641FB  00970b000045            add      byte ptr [edi + 0x4500000b], dl 
  0x01064201  f4                      hlt                                     
  0x01064202  61                      popal                                   
  0x01064203  004102                  add      byte ptr [ecx + 2], al         
  0x01064206  0000                    add      byte ptr [eax], al             
  0x01064208  59                      pop      ecx                            
  0x01064209  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106420A  050000f456              add      eax, 0x56f40000                
  0x0106420F  008a0b000000            add      byte ptr [edx + 0xb], cl       
  0x01064216  44                      inc      esp                            
  0x01064217  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106421A  0000                    add      byte ptr [eax], al             
  0x0106421C  40                      inc      eax                            
  0x0106421D  0020                    add      byte ptr [eax], ah             
  0x0106421F  0000                    add      byte ptr [eax], al             
  0x01064221  90                      nop                                     
  0x01064222  2100                    and      dword ptr [eax], eax           
  0x01064224  00f4                    add      ah, dh                         
  0x01064226  56                      push     esi                            
  0x01064227  00a50b000000            add      byte ptr [ebp + 0xb], ah       
  0x0106422E  44                      inc      esp                            
  0x0106422F  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01064232  0000                    add      byte ptr [eax], al             
  0x01064234  40                      inc      eax                            
  0x01064235  0020                    add      byte ptr [eax], ah             
  0x01064237  0000                    add      byte ptr [eax], al             
  0x01064239  92                      xchg     edx, eax                       
  0x0106423A  2100                    and      dword ptr [eax], eax           
  0x0106423C  00e0                    add      al, ah                         
  0x0106423E  56                      push     esi                            
  0x0106423F  0000                    add      byte ptr [eax], al             
  0x01064241  e271                    loop     0x10642b4                      
  0x01064243  0000                    add      byte ptr [eax], al             
  0x01064245  94                      xchg     esp, eax                       
  0x01064246  2100                    and      dword ptr [eax], eax           
  0x01064248  0036                    add      byte ptr [esi], dh             
  0x0106424A  2200                    and      al, byte ptr [eax]             
  0x0106424C  00f4                    add      ah, dh                         
  0x0106424E  56                      push     esi                            
  0x0106424F  005c0b00                add      byte ptr [ebx + ecx], bl       
  0x01064253  0000                    add      byte ptr [eax], al             
  0x01064256  44                      inc      esp                            
  0x01064257  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106425A  0000                    add      byte ptr [eax], al             
  0x0106425C  40                      inc      eax                            
  0x0106425D  0020                    add      byte ptr [eax], ah             
  0x0106425F  0000                    add      byte ptr [eax], al             
  0x01064261  90                      nop                                     
  0x01064262  2100                    and      dword ptr [eax], eax           
  0x01064264  00f4                    add      ah, dh                         
  0x01064266  56                      push     esi                            
  0x01064267  00910b000000            add      byte ptr [ecx + 0xb], dl       
  0x0106426E  44                      inc      esp                            
  0x0106426F  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01064272  0000                    add      byte ptr [eax], al             
  0x01064274  40                      inc      eax                            
  0x01064275  0020                    add      byte ptr [eax], ah             
  0x01064277  0000                    add      byte ptr [eax], al             
  0x01064279  92                      xchg     edx, eax                       
  0x0106427A  2100                    and      dword ptr [eax], eax           
  0x0106427C  002e                    add      byte ptr [esi], ch             
  0x0106427E  2300                    and      eax, dword ptr [eax]           
  0x01064280  844101                  test     byte ptr [ecx + 1], al         
  0x01064283  00c4                    add      ah, al                         
  0x01064285  740b                    je       0x1064292                      
  0x01064287  0016                    add      byte ptr [esi], dl             
  0x01064289  0f0000                  sldt     word ptr [eax]                 
  0x0106428C  00852100adf4            add      byte ptr [ebp - 0xb52ffdf], al 
                                        ; XREF: 0x01064285 (cond_jump)
  0x01064292  47                      inc      edi                            
  0x01064293  0001                    add      byte ptr [ecx], al             
  0x01064295  0000                    add      byte ptr [eax], al             
  0x01064297  00c4                    add      ah, al                         
  0x01064299  740b                    je       0x10642a6                      
  0x0106429B  0012                    add      byte ptr [edx], dl             
  0x0106429D  0f0000                  sldt     word ptr [eax]                 
  0x010642A0  00e6                    add      dh, ah                         
  0x010642A2  2100                    and      dword ptr [eax], eax           
  0x010642A4  d09d20002e1d            rcr      byte ptr [ebp + 0x1d2e0020], 1 
  0x010642AA  0c00                    or       al, 0                          
  0x010642AC  65f4                    hlt                                     
  0x010642AE  46                      inc      esi                            
  0x010642AF  00abaa2a0078            add      byte ptr [ebx + 0x78002aaa], ch 
  0x010642B5  2920                    sub      dword ptr [eax], esp           
  0x010642B7  0000                    add      byte ptr [eax], al             
  0x010642B9  60                      pushal                                  
  0x010642BA  55                      push     ebp                            
  0x010642BB  0000                    add      byte ptr [eax], al             
  0x010642BD  a5                      movsd    dword ptr es:[edi], dword ptr [esi] 
  0x010642BE  2100                    and      dword ptr [eax], eax           
  0x010642C0  e9bc210082              jmp      0x83066481                     
  0x010642C5  1d0c001000              sbb      eax, 0x10000c                  
  0x010642CA  2000                    and      byte ptr [eax], al             
  0x010642CC  650020                  add      byte ptr gs:[eax], ah          
  0x010642CF  007829                  add      byte ptr [eax + 0x29], bh      
  0x010642D2  2000                    and      byte ptr [eax], al             
  0x010642D4  006255                  add      byte ptr [edx + 0x55], ah      
  0x010642D7  0000                    add      byte ptr [eax], al             
  0x010642D9  3222                    xor      ah, byte ptr [edx]             
  0x010642DB  0000                    add      byte ptr [eax], al             
  0x010642DD  59                      pop      ecx                            
  0x010642DE  2000                    and      byte ptr [eax], al             
  0x010642E0  0000                    add      byte ptr [eax], al             
  0x010642E2  3a00                    cmp      al, byte ptr [eax]             
  0x010642E4  96                      xchg     esi, eax                       
  0x010642E5  050d00110c              add      eax, 0xc11000d                 
  0x010642EA  050000f056              add      eax, 0x56f00000                
  0x010642EF  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x010642F2  0000                    add      byte ptr [eax], al             
  0x010642F4  03f4                    add      esi, esp                       
  0x010642F6  60                      pushal                                  
  0x010642F7  008f0b00000c            add      byte ptr [edi + 0xc00000b], cl 
  0x010642FD  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010642FE  050000f461              add      eax, 0x61f40000                
  0x01064303  00f6                    add      dh, dh                         
  0x01064305  0200                    add      al, byte ptr [eax]             
  0x01064307  0000                    add      byte ptr [eax], al             
  0x01064309  07                      pop      es                             
  0x0106430A  3900                    cmp      dword ptr [eax], eax           
  0x0106430C  0036                    add      byte ptr [esi], dh             
  0x0106430E  2200                    and      al, byte ptr [eax]             
  0x01064310  0032                    add      byte ptr [edx], dh             
  0x01064312  2200                    and      al, byte ptr [eax]             
  0x01064314  005920                  add      byte ptr [ecx + 0x20], bl      
  0x01064317  0000                    add      byte ptr [eax], al             
  0x01064319  003a                    add      byte ptr [edx], bh             
  0x0106431B  0000                    add      byte ptr [eax], al             
  0x0106431D  06                      push     es                             
  0x0106431E  3c00                    cmp      al, 0                          
  0x01064320  00f0                    add      al, dh                         
  0x01064322  7d00                    jge      0x1064324                      
                                        ; XREF: 0x01064322 (cond_jump)
  0x01064324  130f                    adc      ecx, dword ptr [edi]           
  0x01064326  0000                    add      byte ptr [eax], al             
  0x01064328  96                      xchg     esi, eax                       
  0x01064329  050d000c00              add      eax, 0xc000d                   
  0x0106432E  0000                    add      byte ptr [eax], al             
  0x01064330  00f0                    add      al, dh                         
  0x01064332  56                      push     esi                            
  0x01064333  004002                  add      byte ptr [eax + 2], al         
  0x01064336  0000                    add      byte ptr [eax], al             
  0x01064338  041d                    add      al, 0x1d                       
  0x0106433A  0c00                    or       al, 0                          
  0x0106433C  00c7                    add      bh, al                         
  0x0106433E  2100                    and      dword ptr [eax], eax           
  0x01064340  00f4                    add      ah, dh                         
  0x01064342  46                      inc      esi                            
  0x01064343  0003                    add      byte ptr [ebx], al             
  0x01064345  0000                    add      byte ptr [eax], al             
  0x01064347  00b00020002e            add      byte ptr [eax + 0x2e002000], dh 
  0x0106434D  1d0c00c040              sbb      eax, 0x40c0000c                
  0x01064352  0100                    add      dword ptr [eax], eax           
  0x01064354  49                      dec      ecx                            
  0x01064355  0000                    add      byte ptr [eax], al             
  0x01064357  0000                    add      byte ptr [eax], al             
  0x0106435A  2100                    and      dword ptr [eax], eax           
  0x0106435C  00f4                    add      ah, dh                         
  0x0106435E  61                      popal                                   
  0x0106435F  00a00b000000            add      byte ptr [eax + 0xb], ah       
  0x01064365  f4                      hlt                                     
  0x01064366  6200                    bound    eax, qword ptr [eax]           
  0x01064368  a5                      movsd    dword ptr es:[edi], dword ptr [esi] 
  0x01064369  0b00                    or       eax, dword ptr [eax]           
  0x0106436B  0000                    add      byte ptr [eax], al             
  0x0106436E  45                      inc      ebp                            
  0x0106436F  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x01064375  c506                    lds      eax, ptr [esi]                 
  0x01064377  0003                    add      byte ptr [ebx], al             
  0x01064379  0000                    add      byte ptr [eax], al             
  0x0106437B  0000                    add      byte ptr [eax], al             
  0x0106437D  59                      pop      ecx                            
  0x0106437E  47                      inc      edi                            
  0x0106437F  0000                    add      byte ptr [eax], al             
  0x01064381  5a                      pop      edx                            
  0x01064382  46                      inc      esi                            
  0x01064383  0000                    add      byte ptr [eax], al             
  0x01064385  f4                      hlt                                     
  0x01064386  57                      push     edi                            
  0x01064387  0001                    add      byte ptr [ecx], al             
  0x01064389  0000                    add      byte ptr [eax], al             
  0x0106438B  0000                    add      byte ptr [eax], al             
  0x0106438E  56                      push     esi                            
  0x0106438F  00400b                  add      byte ptr [eax + 0xb], al       
  0x01064392  0000                    add      byte ptr [eax], al             
  0x01064394  0300                    add      eax, dword ptr [eax]           
  0x01064396  2000                    and      byte ptr [eax], al             
  0x01064398  02a405001b0020          add      ah, byte ptr [ebp + eax + 0x20001b00] 
  0x0106439F  0000                    add      byte ptr [eax], al             
  0x010643A1  7057                    jo       0x10643fa                      
  0x010643A3  00900b00000c            add      byte ptr [eax + 0xc00000b], dl 
  0x010643A9  0000                    add      byte ptr [eax], al             
  0x010643AB  0000                    add      byte ptr [eax], al             
  0x010643AD  f4                      hlt                                     
  0x010643AE  56                      push     esi                            
  0x010643AF  0012                    add      byte ptr [edx], dl             
  0x010643B1  0000                    add      byte ptr [eax], al             
  0x010643B3  0000                    add      byte ptr [eax], al             
  0x010643B5  f4                      hlt                                     
  0x010643B6  57                      push     edi                            
  0x010643B7  0000                    add      byte ptr [eax], al             
  0x010643B9  0000                    add      byte ptr [eax], al             
  0x010643BB  0000                    add      byte ptr [eax], al             
  0x010643BD  f4                      hlt                                     
  0x010643BE  7000                    jo       0x10643c0                      
                                        ; XREF: 0x010643BE (cond_jump)
  0x010643C0  16                      push     ss                             
  0x010643C1  0400                    add      al, 0                          
  0x010643C3  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x010643C9  0100                    add      dword ptr [eax], eax           
  0x010643CB  0003                    add      byte ptr [ebx], al             
  0x010643CD  0020                    add      byte ptr [eax], ah             
  0x010643CF  0000                    add      byte ptr [eax], al             
  0x010643D1  2405                    and      al, 5                          
  0x010643D3  000c00                  add      byte ptr [eax + eax], cl       
  0x010643D6  0000                    add      byte ptr [eax], al             
  0x010643D8  00f4                    add      ah, dh                         
  0x010643DA  56                      push     esi                            
  0x010643DB  0012                    add      byte ptr [edx], dl             
  0x010643DD  0000                    add      byte ptr [eax], al             
  0x010643DF  0000                    add      byte ptr [eax], al             
  0x010643E1  f4                      hlt                                     
  0x010643E2  57                      push     edi                            
  0x010643E3  0001                    add      byte ptr [ecx], al             
  0x010643E5  0000                    add      byte ptr [eax], al             
  0x010643E7  0000                    add      byte ptr [eax], al             
  0x010643E9  f4                      hlt                                     
  0x010643EA  60                      pushal                                  
  0x010643EB  00fd                    add      ch, bh                         
  0x010643ED  0400                    add      al, 0                          
  0x010643EF  0000                    add      byte ptr [eax], al             
  0x010643F1  f4                      hlt                                     
  0x010643F2  7000                    jo       0x10643f4                      
                                        ; XREF: 0x010643F2 (cond_jump)
  0x010643F4  16                      push     ss                             
  0x010643F5  0400                    add      al, 0                          
  0x010643F7  0000                    add      byte ptr [eax], al             
  0x010643F9  0039                    add      byte ptr [ecx], bh             
  0x010643FB  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x01064401  0100                    add      dword ptr [eax], eax           
  0x01064403  0003                    add      byte ptr [ebx], al             
  0x01064405  0020                    add      byte ptr [eax], ah             
  0x01064407  0000                    add      byte ptr [eax], al             
  0x01064409  2405                    and      al, 5                          
  0x0106440B  000c00                  add      byte ptr [eax + eax], cl       
  0x0106440E  0000                    add      byte ptr [eax], al             
  0x01064410  00f4                    add      ah, dh                         
  0x01064412  56                      push     esi                            
  0x01064413  0012                    add      byte ptr [edx], dl             
  0x01064415  0000                    add      byte ptr [eax], al             
  0x01064417  0000                    add      byte ptr [eax], al             
  0x01064419  f4                      hlt                                     
  0x0106441A  57                      push     edi                            
  0x0106441B  0002                    add      byte ptr [edx], al             
  0x0106441D  0000                    add      byte ptr [eax], al             
  0x0106441F  0000                    add      byte ptr [eax], al             
  0x01064421  f4                      hlt                                     
  0x01064422  60                      pushal                                  
  0x01064423  00fd                    add      ch, bh                         
  0x01064425  0400                    add      al, 0                          
  0x01064427  0000                    add      byte ptr [eax], al             
  0x01064429  f4                      hlt                                     
  0x0106442A  7000                    jo       0x106442c                      
                                        ; XREF: 0x0106442A (cond_jump)
  0x0106442C  16                      push     ss                             
  0x0106442D  0400                    add      al, 0                          
  0x0106442F  0000                    add      byte ptr [eax], al             
  0x01064431  0039                    add      byte ptr [ecx], bh             
  0x01064433  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x01064439  0100                    add      dword ptr [eax], eax           
  0x0106443B  0003                    add      byte ptr [ebx], al             
  0x0106443D  0020                    add      byte ptr [eax], ah             
  0x0106443F  0000                    add      byte ptr [eax], al             
  0x01064441  2405                    and      al, 5                          
  0x01064443  0000                    add      byte ptr [eax], al             
  0x01064445  f4                      hlt                                     
  0x01064446  56                      push     esi                            
  0x01064447  000e                    add      byte ptr [esi], cl             
  0x01064449  0000                    add      byte ptr [eax], al             
  0x0106444B  0000                    add      byte ptr [eax], al             
  0x0106444D  f4                      hlt                                     
  0x0106444E  60                      pushal                                  
  0x0106444F  001409                  add      byte ptr [ecx + ecx], dl       
  0x01064452  0000                    add      byte ptr [eax], al             
  0x01064454  000c38                  add      byte ptr [eax + edi], cl       
  0x01064457  0000                    add      byte ptr [eax], al             
  0x01064459  0039                    add      byte ptr [ecx], bh             
  0x0106445B  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x01064461  0100                    add      dword ptr [eax], eax           
  0x01064463  0003                    add      byte ptr [ebx], al             
  0x01064465  0020                    add      byte ptr [eax], ah             
  0x01064467  0000                    add      byte ptr [eax], al             
  0x01064469  2405                    and      al, 5                          
  0x0106446B  000c00                  add      byte ptr [eax + eax], cl       
  0x0106446E  0000                    add      byte ptr [eax], al             
  0x01064470  00f4                    add      ah, dh                         
  0x01064472  56                      push     esi                            
  0x01064473  0019                    add      byte ptr [ecx], bl             
  0x01064475  0000                    add      byte ptr [eax], al             
  0x01064477  0000                    add      byte ptr [eax], al             
  0x01064479  f4                      hlt                                     
  0x0106447A  57                      push     edi                            
  0x0106447B  0001                    add      byte ptr [ecx], al             
  0x0106447D  0000                    add      byte ptr [eax], al             
  0x0106447F  0000                    add      byte ptr [eax], al             
  0x01064481  0039                    add      byte ptr [ecx], bh             
  0x01064483  0000                    add      byte ptr [eax], al             
  0x01064485  f4                      hlt                                     
  0x01064486  7000                    jo       0x1064488                      
                                        ; XREF: 0x01064486 (cond_jump)
  0x01064488  800000                  add      byte ptr [eax], 0              
  0x0106448B  0000                    add      byte ptr [eax], al             
  0x0106448D  f4                      hlt                                     
  0x0106448E  60                      pushal                                  
  0x0106448F  00400b                  add      byte ptr [eax + 0xb], al       
  0x01064492  0000                    add      byte ptr [eax], al             
  0x01064494  80f00b                  xor      al, 0xb                        
  0x01064497  008001000003            add      byte ptr [eax + 0x3000001], al 
  0x0106449D  0020                    add      byte ptr [eax], ah             
  0x0106449F  0000                    add      byte ptr [eax], al             
  0x010644A1  2405                    and      al, 5                          
  0x010644A3  000c00                  add      byte ptr [eax + eax], cl       
  0x010644A6  0000                    add      byte ptr [eax], al             
  0x010644A8  00f4                    add      ah, dh                         
  0x010644AA  56                      push     esi                            
  0x010644AB  001500000000            add      byte ptr [0], dl               
  0x010644B1  f4                      hlt                                     
  0x010644B2  57                      push     edi                            
  0x010644B3  0000                    add      byte ptr [eax], al             
  0x010644B5  0000                    add      byte ptr [eax], al             
  0x010644B7  0000                    add      byte ptr [eax], al             
  0x010644B9  f4                      hlt                                     
  0x010644BA  7000                    jo       0x10644bc                      
                                        ; XREF: 0x010644BA (cond_jump)
  0x010644BC  90                      nop                                     
  0x010644BD  0300                    add      eax, dword ptr [eax]           
  0x010644BF  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x010644C5  0100                    add      dword ptr [eax], eax           
  0x010644C7  0003                    add      byte ptr [ebx], al             
  0x010644C9  0020                    add      byte ptr [eax], ah             
  0x010644CB  0000                    add      byte ptr [eax], al             
  0x010644CD  2405                    and      al, 5                          
  0x010644CF  0000                    add      byte ptr [eax], al             
  0x010644D1  f4                      hlt                                     
  0x010644D2  56                      push     esi                            
  0x010644D3  0016                    add      byte ptr [esi], dl             
  0x010644D5  0000                    add      byte ptr [eax], al             
  0x010644D7  0000                    add      byte ptr [eax], al             
  0x010644D9  f4                      hlt                                     
  0x010644DA  57                      push     edi                            
  0x010644DB  0000                    add      byte ptr [eax], al             
  0x010644DD  0000                    add      byte ptr [eax], al             
  0x010644DF  0000                    add      byte ptr [eax], al             
  0x010644E1  f4                      hlt                                     
  0x010644E2  7000                    jo       0x10644e4                      
                                        ; XREF: 0x010644E2 (cond_jump)
  0x010644E4  90                      nop                                     
  0x010644E5  0300                    add      eax, dword ptr [eax]           
  0x010644E7  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x010644ED  0100                    add      dword ptr [eax], eax           
  0x010644EF  0003                    add      byte ptr [ebx], al             
  0x010644F1  0020                    add      byte ptr [eax], ah             
  0x010644F3  0000                    add      byte ptr [eax], al             
  0x010644F5  2405                    and      al, 5                          
  0x010644F7  000c00                  add      byte ptr [eax + eax], cl       
  0x010644FA  0000                    add      byte ptr [eax], al             
  0x010644FC  007044                  add      byte ptr [eax + 0x44], dh      
  0x010644FF  006909                  add      byte ptr [ecx + 9], ch         
  0x01064502  0000                    add      byte ptr [eax], al             
  0x01064504  00f0                    add      al, dh                         
  0x01064506  56                      push     esi                            
  0x01064507  00970b000045            add      byte ptr [edi + 0x4500000b], dl 
  0x0106450D  0020                    add      byte ptr [eax], ah             
  0x0106450F  0007                    add      byte ptr [edi], al             
  0x01064511  2405                    and      al, 5                          
  0x01064513  0000                    add      byte ptr [eax], al             
  0x01064515  f4                      hlt                                     
  0x01064516  7100                    jno      0x1064518                      
                                        ; XREF: 0x01064516 (cond_jump)
  0x01064518  8903                    mov      dword ptr [ebx], eax           
  0x0106451A  0000                    add      byte ptr [eax], al             
  0x0106451C  0007                    add      byte ptr [edi], al             
  0x0106451E  3800                    cmp      byte ptr [eax], al             
  0x01064520  00f4                    add      ah, dh                         
  0x01064522  60                      pushal                                  
  0x01064523  003502000007            add      byte ptr [0x7000002], dh       
  0x01064529  0c05                    or       al, 5                          
  0x0106452B  0000                    add      byte ptr [eax], al             
  0x0106452D  f4                      hlt                                     
  0x0106452E  46                      inc      esi                            
  0x0106452F  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x01064535  d820                    fsub     dword ptr [eax]                
  0x01064537  0022                    add      byte ptr [edx], ah             
  0x01064539  f4                      hlt                                     
  0x0106453A  60                      pushal                                  
  0x0106453B  008001000000            add      byte ptr [eax + 1], al         
  0x01064541  1921                    sbb      dword ptr [ecx], esp           
  0x01064543  0000                    add      byte ptr [eax], al             
  0x01064545  f4                      hlt                                     
  0x01064546  56                      push     esi                            
  0x01064547  001500000000            add      byte ptr [0], dl               
  0x0106454D  f4                      hlt                                     
  0x0106454E  57                      push     edi                            
  0x0106454F  0002                    add      byte ptr [edx], al             
  0x01064551  0000                    add      byte ptr [eax], al             
  0x01064553  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x01064559  0100                    add      dword ptr [eax], eax           
  0x0106455B  0003                    add      byte ptr [ebx], al             
  0x0106455D  0020                    add      byte ptr [eax], ah             
  0x0106455F  0000                    add      byte ptr [eax], al             
  0x01064561  2405                    and      al, 5                          
  0x01064563  0000                    add      byte ptr [eax], al             
  0x01064566  44                      inc      esp                            
  0x01064567  006909                  add      byte ptr [ecx + 9], ch         
  0x0106456A  0000                    add      byte ptr [eax], al             
  0x0106456C  00f0                    add      al, dh                         
  0x0106456E  56                      push     esi                            
  0x0106456F  00970b000045            add      byte ptr [edi + 0x4500000b], dl 
  0x01064575  0020                    add      byte ptr [eax], ah             
  0x01064577  0007                    add      byte ptr [edi], al             
  0x01064579  2405                    and      al, 5                          
  0x0106457B  0000                    add      byte ptr [eax], al             
  0x0106457D  f4                      hlt                                     
  0x0106457E  7100                    jno      0x1064580                      
                                        ; XREF: 0x0106457E (cond_jump)
  0x01064580  8903                    mov      dword ptr [ebx], eax           
  0x01064582  0000                    add      byte ptr [eax], al             
  0x01064584  0007                    add      byte ptr [edi], al             
  0x01064586  3800                    cmp      byte ptr [eax], al             
  0x01064588  00f4                    add      ah, dh                         
  0x0106458A  60                      pushal                                  
  0x0106458B  00f6                    add      dh, dh                         
  0x0106458D  0200                    add      al, byte ptr [eax]             
  0x0106458F  0007                    add      byte ptr [edi], al             
  0x01064591  0c05                    or       al, 5                          
  0x01064593  0000                    add      byte ptr [eax], al             
  0x01064595  f4                      hlt                                     
  0x01064596  46                      inc      esi                            
  0x01064597  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x0106459D  d820                    fsub     dword ptr [eax]                
  0x0106459F  0022                    add      byte ptr [edx], ah             
  0x010645A1  f4                      hlt                                     
  0x010645A2  60                      pushal                                  
  0x010645A3  004102                  add      byte ptr [ecx + 2], al         
  0x010645A6  0000                    add      byte ptr [eax], al             
  0x010645A8  0019                    add      byte ptr [ecx], bl             
  0x010645AA  2100                    and      dword ptr [eax], eax           
  0x010645AC  00f4                    add      ah, dh                         
  0x010645AE  56                      push     esi                            
  0x010645AF  0016                    add      byte ptr [esi], dl             
  0x010645B1  0000                    add      byte ptr [eax], al             
  0x010645B3  0000                    add      byte ptr [eax], al             
  0x010645B5  f4                      hlt                                     
  0x010645B6  57                      push     edi                            
  0x010645B7  0002                    add      byte ptr [edx], al             
  0x010645B9  0000                    add      byte ptr [eax], al             
  0x010645BB  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x010645C1  0100                    add      dword ptr [eax], eax           
  0x010645C3  0003                    add      byte ptr [ebx], al             
  0x010645C5  0020                    add      byte ptr [eax], ah             
  0x010645C7  0000                    add      byte ptr [eax], al             
  0x010645C9  2405                    and      al, 5                          
  0x010645CB  000c00                  add      byte ptr [eax + eax], cl       
  0x010645CE  0000                    add      byte ptr [eax], al             
  0x010645D0  40                      inc      eax                            
  0x010645D1  1bd0                    sbb      edx, eax                       
  0x010645D3  005206                  add      byte ptr [edx + 6], dl         
  0x010645D6  0000                    add      byte ptr [eax], al             
  0x010645D8  7201                    jb       0x10645db                      
  0x010645DA  0300                    add      eax, dword ptr [eax]           
  0x010645DC  50                      push     eax                            
  0x010645DD  0b8c000b002000          or       ecx, dword ptr [eax + eax + 0x20000b] 
  0x010645E4  0210                    add      dl, byte ptr [eax]             
  0x010645E6  0d004b0600              or       eax, 0x64b00                   
  0x010645EB  0080100d003b            add      byte ptr [eax + 0x3b000d10], al 
  0x010645F1  06                      push     es                             
  0x010645F2  0000                    add      byte ptr [eax], al             
  0x010645F4  00f4                    add      ah, dh                         
  0x010645F6  57                      push     edi                            
  0x010645F7  0010                    add      byte ptr [eax], dl             
  0x010645F9  0000                    add      byte ptr [eax], al             
  0x010645FB  0000                    add      byte ptr [eax], al             
  0x010645FD  0030                    add      byte ptr [eax], dh             
  0x010645FF  0080100d0033            add      byte ptr [eax + 0x33000d10], al 
  0x01064605  0200                    add      al, byte ptr [eax]             
  0x01064607  0000                    add      byte ptr [eax], al             
  0x01064609  f4                      hlt                                     
  0x0106460A  44                      inc      esp                            
  0x0106460B  0000                    add      byte ptr [eax], al             
  0x0106460D  0000                    add      byte ptr [eax], al             
  0x0106460F  004500                  add      byte ptr [ebp], al             
  0x01064612  2000                    and      byte ptr [eax], al             
  0x01064614  00740500                add      byte ptr [ebp + eax], dh       
  0x01064618  80100d                  adc      byte ptr [eax], 0xd            
  0x0106461B  003f                    add      byte ptr [edi], bh             
  0x0106461D  06                      push     es                             
  0x0106461E  0000                    add      byte ptr [eax], al             
  0x01064620  0c00                    or       al, 0                          
  0x01064622  0000                    add      byte ptr [eax], al             
  0x01064624  61                      popal                                   
  0x01064625  f4                      hlt                                     
  0x01064626  46                      inc      esi                            
  0x01064627  0010                    add      byte ptr [eax], dl             
  0x01064629  0000                    add      byte ptr [eax], al             
  0x0106462B  0000                    add      byte ptr [eax], al             
  0x0106462D  07                      pop      es                             
  0x0106462E  2300                    and      eax, dword ptr [eax]           
  0x01064630  10d9                    adc      cl, bl                         
  0x01064632  06                      push     es                             
  0x01064633  000a                    add      byte ptr [edx], cl             
  0x01064635  0000                    add      byte ptr [eax], al             
  0x01064637  007cd950                add      byte ptr [ecx + ebx*8 + 0x50], bh 
  0x0106463B  0007                    add      byte ptr [edi], al             
  0x0106463D  7405                    je       0x1064644                      
  0x0106463F  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x01064642  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x0106463D (cond_jump)
  0x01064644  46                      inc      esi                            
  0x01064645  1e                      push     ds                             
  0x01064646  0c00                    or       al, 0                          
  0x01064648  90                      nop                                     
  0x01064649  1e                      push     ds                             
  0x0106464A  0c00                    or       al, 0                          
  0x0106464C  49                      dec      ecx                            
  0x0106464D  e421                    in       al, 0x21                       
  0x0106464F  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x01064652  54                      push     esp                            
  0x01064653  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x01064656  0c00                    or       al, 0                          
  0x01064658  4e                      dec      esi                            
  0x01064659  1e                      push     ds                             
  0x0106465A  0c00                    or       al, 0                          
  0x0106465C  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x01064662  0000                    add      byte ptr [eax], al             
  0x01064664  61                      popal                                   
  0x01064665  f4                      hlt                                     
                                        ; XREF: 0x010646B8 (cond_jump)
  0x01064666  46                      inc      esi                            
  0x01064667  0010                    add      byte ptr [eax], dl             
  0x01064669  0000                    add      byte ptr [eax], al             
  0x0106466B  0000                    add      byte ptr [eax], al             
  0x0106466D  07                      pop      es                             
  0x0106466E  2300                    and      eax, dword ptr [eax]           
  0x01064670  7cd9                    jl       0x106464b                      
  0x01064672  50                      push     eax                            
  0x01064673  0007                    add      byte ptr [edi], al             
  0x01064675  7405                    je       0x106467c                      
  0x01064677  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x0106467A  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x01064675 (cond_jump)
  0x0106467C  46                      inc      esi                            
  0x0106467D  1e                      push     ds                             
  0x0106467E  0c00                    or       al, 0                          
  0x01064680  90                      nop                                     
  0x01064681  1e                      push     ds                             
  0x01064682  0c00                    or       al, 0                          
  0x01064684  49                      dec      ecx                            
  0x01064685  e421                    in       al, 0x21                       
  0x01064687  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106468A  54                      push     esp                            
  0x0106468B  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106468E  0c00                    or       al, 0                          
  0x01064690  4e                      dec      esi                            
  0x01064691  1e                      push     ds                             
  0x01064692  0c00                    or       al, 0                          
  0x01064694  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x0106469A  0000                    add      byte ptr [eax], al             
  0x0106469C  00f4                    add      ah, dh                         
  0x0106469E  46                      inc      esi                            
  0x0106469F  0010                    add      byte ptr [eax], dl             
  0x010646A1  0000                    add      byte ptr [eax], al             
  0x010646A3  0000                    add      byte ptr [eax], al             
  0x010646A5  07                      pop      es                             
  0x010646A6  2300                    and      eax, dword ptr [eax]           
  0x010646A8  10d9                    adc      cl, bl                         
  0x010646AA  06                      push     es                             
  0x010646AB  000d00000000            add      byte ptr [0], cl               
  0x010646B1  d95600                  fst      dword ptr [esi]                
  0x010646B4  6e                      outsb    dx, byte ptr [esi]             
  0x010646B5  1e                      push     ds                             
  0x010646B6  0c00                    or       al, 0                          
  0x010646B8  7cac                    jl       0x1064666                      
  0x010646BA  2000                    and      byte ptr [eax], al             
  0x010646BC  07                      pop      es                             
  0x010646BD  7405                    je       0x10646c4                      
  0x010646BF  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x010646C2  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x010646BD (cond_jump)
  0x010646C4  46                      inc      esi                            
  0x010646C5  1e                      push     ds                             
  0x010646C6  0c00                    or       al, 0                          
  0x010646C8  90                      nop                                     
  0x010646C9  1e                      push     ds                             
  0x010646CA  0c00                    or       al, 0                          
  0x010646CC  49                      dec      ecx                            
  0x010646CD  e421                    in       al, 0x21                       
  0x010646CF  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x010646D2  54                      push     esp                            
  0x010646D3  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x010646D6  0c00                    or       al, 0                          
  0x010646D8  4e                      dec      esi                            
  0x010646D9  1e                      push     ds                             
  0x010646DA  0c00                    or       al, 0                          
  0x010646DC  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x010646E2  0000                    add      byte ptr [eax], al             
  0x010646E4  00f4                    add      ah, dh                         
  0x010646E6  46                      inc      esi                            
  0x010646E7  0010                    add      byte ptr [eax], dl             
  0x010646E9  0000                    add      byte ptr [eax], al             
  0x010646EB  0000                    add      byte ptr [eax], al             
  0x010646ED  07                      pop      es                             
                                        ; XREF: 0x01064740 (cond_jump)
  0x010646EE  2300                    and      eax, dword ptr [eax]           
  0x010646F0  10d9                    adc      cl, bl                         
  0x010646F2  06                      push     es                             
  0x010646F3  000d00000000            add      byte ptr [0], cl               
  0x010646F9  d95e00                  fstp     dword ptr [esi]                
  0x010646FC  6e                      outsb    dx, byte ptr [esi]             
  0x010646FD  1e                      push     ds                             
  0x010646FE  0c00                    or       al, 0                          
  0x01064700  7cac                    jl       0x10646ae                      
  0x01064702  2000                    and      byte ptr [eax], al             
  0x01064704  07                      pop      es                             
  0x01064705  7405                    je       0x106470c                      
  0x01064707  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x0106470A  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x01064705 (cond_jump)
  0x0106470C  46                      inc      esi                            
  0x0106470D  1e                      push     ds                             
  0x0106470E  0c00                    or       al, 0                          
  0x01064710  90                      nop                                     
  0x01064711  1e                      push     ds                             
  0x01064712  0c00                    or       al, 0                          
  0x01064714  49                      dec      ecx                            
  0x01064715  e421                    in       al, 0x21                       
  0x01064717  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106471A  54                      push     esp                            
  0x0106471B  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106471E  0c00                    or       al, 0                          
  0x01064720  4e                      dec      esi                            
  0x01064721  1e                      push     ds                             
  0x01064722  0c00                    or       al, 0                          
  0x01064724  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x0106472A  0000                    add      byte ptr [eax], al             
  0x0106472C  00f4                    add      ah, dh                         
                                        ; XREF: 0x01064780 (cond_jump)
  0x0106472E  46                      inc      esi                            
  0x0106472F  0010                    add      byte ptr [eax], dl             
  0x01064731  0000                    add      byte ptr [eax], al             
  0x01064733  0000                    add      byte ptr [eax], al             
  0x01064735  07                      pop      es                             
  0x01064736  2300                    and      eax, dword ptr [eax]           
  0x01064738  00d9                    add      cl, bl                         
  0x0106473A  56                      push     esi                            
  0x0106473B  006e1e                  add      byte ptr [esi + 0x1e], ch      
  0x0106473E  0c00                    or       al, 0                          
  0x01064740  7cac                    jl       0x10646ee                      
  0x01064742  2000                    and      byte ptr [eax], al             
  0x01064744  07                      pop      es                             
  0x01064745  7405                    je       0x106474c                      
  0x01064747  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x0106474A  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x01064745 (cond_jump)
  0x0106474C  46                      inc      esi                            
  0x0106474D  1e                      push     ds                             
  0x0106474E  0c00                    or       al, 0                          
  0x01064750  90                      nop                                     
  0x01064751  1e                      push     ds                             
  0x01064752  0c00                    or       al, 0                          
  0x01064754  49                      dec      ecx                            
  0x01064755  e421                    in       al, 0x21                       
  0x01064757  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106475A  54                      push     esp                            
  0x0106475B  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106475E  0c00                    or       al, 0                          
  0x01064760  4e                      dec      esi                            
  0x01064761  1e                      push     ds                             
  0x01064762  0c00                    or       al, 0                          
  0x01064764  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x0106476A  0000                    add      byte ptr [eax], al             
  0x0106476C  00f4                    add      ah, dh                         
  0x0106476E  46                      inc      esi                            
  0x0106476F  0010                    add      byte ptr [eax], dl             
  0x01064771  0000                    add      byte ptr [eax], al             
  0x01064773  0000                    add      byte ptr [eax], al             
  0x01064775  07                      pop      es                             
  0x01064776  2300                    and      eax, dword ptr [eax]           
  0x01064778  00d9                    add      cl, bl                         
  0x0106477A  5e                      pop      esi                            
  0x0106477B  006e1e                  add      byte ptr [esi + 0x1e], ch      
  0x0106477E  0c00                    or       al, 0                          
  0x01064780  7cac                    jl       0x106472e                      
  0x01064782  2000                    and      byte ptr [eax], al             
  0x01064784  07                      pop      es                             
  0x01064785  7405                    je       0x106478c                      
  0x01064787  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x0106478A  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x01064785 (cond_jump)
  0x0106478C  46                      inc      esi                            
  0x0106478D  1e                      push     ds                             
  0x0106478E  0c00                    or       al, 0                          
  0x01064790  90                      nop                                     
  0x01064791  1e                      push     ds                             
  0x01064792  0c00                    or       al, 0                          
  0x01064794  49                      dec      ecx                            
  0x01064795  e421                    in       al, 0x21                       
  0x01064797  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106479A  54                      push     esp                            
  0x0106479B  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106479E  0c00                    or       al, 0                          
  0x010647A0  4e                      dec      esi                            
  0x010647A1  1e                      push     ds                             
  0x010647A2  0c00                    or       al, 0                          
  0x010647A4  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x010647AA  0000                    add      byte ptr [eax], al             
  0x010647AC  00f4                    add      ah, dh                         
  0x010647AE  61                      popal                                   
  0x010647AF  0012                    add      byte ptr [edx], dl             
  0x010647B1  0d000000f4              or       eax, 0xf4000000                
  0x010647B6  46                      inc      esi                            
  0x010647B7  00ff                    add      bh, bh                         
  0x010647B9  0000                    add      byte ptr [eax], al             
  0x010647BB  0010                    add      byte ptr [eax], dl             
  0x010647BD  d806                    fadd     dword ptr [esi]                
  0x010647BF  000e                    add      byte ptr [esi], cl             
  0x010647C1  0000                    add      byte ptr [eax], al             
  0x010647C3  00901c0c0056            add      byte ptr [eax + 0x56000c1c], dl 
  0x010647C9  0020                    add      byte ptr [eax], ah             
  0x010647CB  0000                    add      byte ptr [eax], al             
  0x010647CD  d85100                  fcom     dword ptr [ecx]                
  0x010647D0  00992100911d            add      byte ptr [ecx + 0x1d910021], bl 
  0x010647D6  0c00                    or       al, 0                          
  0x010647D8  00e9                    add      cl, ch                         
  0x010647DA  4c                      dec      esp                            
  0x010647DB  004b00                  add      byte ptr [ebx], cl             
  0x010647DE  2000                    and      byte ptr [eax], al             
  0x010647E0  90                      nop                                     
  0x010647E1  1c0c                    sbb      al, 0xc                        
  0x010647E3  005600                  add      byte ptr [esi], dl             
  0x010647E6  2000                    and      byte ptr [eax], al             
  0x010647E8  00992100911d            add      byte ptr [ecx + 0x1d910021], bl 
  0x010647EE  0c00                    or       al, 0                          
  0x010647F0  00e9                    add      cl, ch                         
  0x010647F2  4c                      dec      esp                            
  0x010647F3  004b00                  add      byte ptr [ebx], cl             
  0x010647F6  2000                    and      byte ptr [eax], al             
  0x010647F8  91                      xchg     ecx, eax                       
  0x010647F9  1e                      push     ds                             
  0x010647FA  0c00                    or       al, 0                          
  0x010647FC  00ae2100111c            add      byte ptr [esi + 0x1c110021], ch 
  0x01064802  0c00                    or       al, 0                          
  0x01064804  0c00                    or       al, 0                          
  0x01064806  0000                    add      byte ptr [eax], al             
  0x01064808  1bf4                    sbb      esi, esp                       
  0x0106480A  61                      popal                                   
  0x0106480B  0012                    add      byte ptr [edx], dl             
  0x0106480D  0e                      push     cs                             
  0x0106480E  0000                    add      byte ptr [eax], al             
  0x01064810  00f4                    add      ah, dh                         
  0x01064812  46                      inc      esi                            
  0x01064813  00ff                    add      bh, bh                         
  0x01064815  0000                    add      byte ptr [eax], al             
  0x01064817  0000                    add      byte ptr [eax], al             
  0x01064819  48                      dec      eax                            
  0x0106481A  2000                    and      byte ptr [eax], al             
  0x0106481C  10d8                    adc      al, bl                         
  0x0106481E  06                      push     es                             
  0x0106481F  000d0000005e            add      byte ptr [0x5e000000], cl      
  0x01064825  ae                      scasb    al, byte ptr es:[edi]          
  0x01064826  2100                    and      dword ptr [eax], eax           
  0x01064828  00f8                    add      al, bh                         
  0x0106482A  44                      inc      esp                            
  0x0106482B  0000                    add      byte ptr [eax], al             
  0x0106482D  b92100d01e              mov      ecx, 0x1ed00021                
  0x01064832  0c00                    or       al, 0                          
  0x01064834  42                      inc      edx                            
  0x01064835  0020                    add      byte ptr [eax], ah             
  0x01064837  0000                    add      byte ptr [eax], al             
  0x01064839  e94c004300              jmp      0x149488a                      
  0x0106483E  2000                    and      byte ptr [eax], al             
  0x01064840  56                      push     esi                            
  0x01064842  2100                    and      dword ptr [eax], eax           
  0x01064844  00992100d11e            add      byte ptr [ecx + 0x1ed10021], bl 
  0x0106484A  0c00                    or       al, 0                          
  0x0106484C  00e9                    add      cl, ch                         
  0x0106484E  4c                      dec      esp                            
  0x0106484F  004b00                  add      byte ptr [ebx], cl             
  0x01064852  2000                    and      byte ptr [eax], al             
  0x01064854  91                      xchg     ecx, eax                       
  0x01064855  1e                      push     ds                             
  0x01064856  0c00                    or       al, 0                          
  0x01064858  00ae2100111c            add      byte ptr [esi + 0x1c110021], ch 
  0x0106485E  0c00                    or       al, 0                          
  0x01064860  0c00                    or       al, 0                          
  0x01064862  0000                    add      byte ptr [eax], al             
  0x01064864  180400                  sbb      byte ptr [eax + eax], al       
  0x01064867  0018                    add      byte ptr [eax], bl             
  0x01064869  0400                    add      al, 0                          
  0x0106486B  0018                    add      byte ptr [eax], bl             
  0x0106486D  0400                    add      al, 0                          
  0x0106486F  002a                    add      byte ptr [edx], ch             
  0x01064871  0400                    add      al, 0                          
  0x01064873  002a                    add      byte ptr [edx], ch             
  0x01064875  0400                    add      al, 0                          
  0x01064877  002a                    add      byte ptr [edx], ch             
  0x01064879  0400                    add      al, 0                          
  0x0106487B  002504000042            add      byte ptr [0x42000004], ah      
  0x01064881  0400                    add      al, 0                          
  0x01064883  004204                  add      byte ptr [edx + 4], al         
  0x01064886  0000                    add      byte ptr [eax], al             
  0x01064888  42                      inc      edx                            
  0x01064889  0400                    add      al, 0                          
  0x0106488B  004204                  add      byte ptr [edx + 4], al         
  0x0106488E  0000                    add      byte ptr [eax], al             
  0x01064890  42                      inc      edx                            
  0x01064891  0400                    add      al, 0                          
  0x01064893  004204                  add      byte ptr [edx + 4], al         
  0x01064896  0000                    add      byte ptr [eax], al             
  0x01064898  42                      inc      edx                            
  0x01064899  0400                    add      al, 0                          
  0x0106489B  004204                  add      byte ptr [edx + 4], al         
  0x0106489E  0000                    add      byte ptr [eax], al             
  0x010648A0  42                      inc      edx                            
  0x010648A1  0400                    add      al, 0                          
  0x010648A3  004204                  add      byte ptr [edx + 4], al         
  0x010648A6  0000                    add      byte ptr [eax], al             
  0x010648A8  42                      inc      edx                            
  0x010648A9  0400                    add      al, 0                          
  0x010648AB  004204                  add      byte ptr [edx + 4], al         
  0x010648AE  0000                    add      byte ptr [eax], al             
  0x010648B0  42                      inc      edx                            
  0x010648B1  0400                    add      al, 0                          
  0x010648B3  004e04                  add      byte ptr [esi + 4], cl         
  0x010648B6  0000                    add      byte ptr [eax], al             
  0x010648B8  4e                      dec      esi                            
  0x010648B9  0400                    add      al, 0                          
  0x010648BB  004e04                  add      byte ptr [esi + 4], cl         
  0x010648BE  0000                    add      byte ptr [eax], al             
  0x010648C0  5f                      pop      edi                            
  0x010648C1  0400                    add      al, 0                          
  0x010648C3  005f04                  add      byte ptr [edi + 4], bl         
  0x010648C6  0000                    add      byte ptr [eax], al             
  0x010648C8  5f                      pop      edi                            
  0x010648C9  0400                    add      al, 0                          
  0x010648CB  005f04                  add      byte ptr [edi + 4], bl         
  0x010648CE  0000                    add      byte ptr [eax], al             
  0x010648D0  5f                      pop      edi                            
  0x010648D1  0400                    add      al, 0                          
  0x010648D3  005f04                  add      byte ptr [edi + 4], bl         
  0x010648D6  0000                    add      byte ptr [eax], al             
  0x010648D8  5f                      pop      edi                            
  0x010648D9  0400                    add      al, 0                          
  0x010648DB  005f04                  add      byte ptr [edi + 4], bl         
  0x010648DE  0000                    add      byte ptr [eax], al             
  0x010648E0  5f                      pop      edi                            
  0x010648E1  0400                    add      al, 0                          
  0x010648E3  005f04                  add      byte ptr [edi + 4], bl         
  0x010648E6  0000                    add      byte ptr [eax], al             
  0x010648E8  5f                      pop      edi                            
  0x010648E9  0400                    add      al, 0                          
  0x010648EB  005f04                  add      byte ptr [edi + 4], bl         
  0x010648EE  0000                    add      byte ptr [eax], al             
  0x010648F0  5f                      pop      edi                            
  0x010648F1  0400                    add      al, 0                          
  0x010648F3  005f04                  add      byte ptr [edi + 4], bl         
  0x010648F6  0000                    add      byte ptr [eax], al             
  0x010648F8  5f                      pop      edi                            
  0x010648F9  0400                    add      al, 0                          
  0x010648FB  005f04                  add      byte ptr [edi + 4], bl         
  0x010648FE  0000                    add      byte ptr [eax], al             
  0x01064900  5f                      pop      edi                            
  0x01064901  0400                    add      al, 0                          
  0x01064903  005f04                  add      byte ptr [edi + 4], bl         
  0x01064906  0000                    add      byte ptr [eax], al             
  0x01064908  5f                      pop      edi                            
  0x01064909  0400                    add      al, 0                          
  0x0106490B  005f04                  add      byte ptr [edi + 4], bl         
  0x0106490E  0000                    add      byte ptr [eax], al             
  0x01064910  5f                      pop      edi                            
  0x01064911  0400                    add      al, 0                          
  0x01064913  005f04                  add      byte ptr [edi + 4], bl         
  0x01064916  0000                    add      byte ptr [eax], al             
  0x01064918  5f                      pop      edi                            
  0x01064919  0400                    add      al, 0                          
  0x0106491B  005f04                  add      byte ptr [edi + 4], bl         
  0x0106491E  0000                    add      byte ptr [eax], al             
  0x01064920  5f                      pop      edi                            
  0x01064921  0400                    add      al, 0                          
  0x01064923  005f04                  add      byte ptr [edi + 4], bl         
  0x01064926  0000                    add      byte ptr [eax], al             
  0x01064928  5f                      pop      edi                            
  0x01064929  0400                    add      al, 0                          
  0x0106492B  0000                    add      byte ptr [eax], al             
  0x0106492D  b122                    mov      cl, 0x22                       
  0x0106492F  0000                    add      byte ptr [eax], al             
  0x01064931  1923                    sbb      dword ptr [ebx], esp           
  0x01064933  0000                    add      byte ptr [eax], al             
  0x01064935  48                      dec      eax                            
  0x01064936  2000                    and      byte ptr [eax], al             
  0x01064938  004920                  add      byte ptr [ecx + 0x20], cl      
  0x0106493B  001b                    add      byte ptr [ebx], bl             
  0x0106493D  f4                      hlt                                     
  0x0106493E  45                      inc      ebp                            
  0x0106493F  004000                  add      byte ptr [eax], al             
  0x01064942  0000                    add      byte ptr [eax], al             
  0x01064944  00f4                    add      ah, dh                         
  0x01064946  51                      push     ecx                            
  0x01064947  0000                    add      byte ptr [eax], al             
  0x01064949  0c00                    or       al, 0                          
  0x0106494B  0001                    add      byte ptr [ecx], al             
  0x0106494D  d8440010                fadd     dword ptr [eax + eax + 0x10]   
  0x01064951  dc06                    fadd     qword ptr [esi]                
  0x01064953  0003                    add      byte ptr [ebx], al             
  0x01064955  0000                    add      byte ptr [eax], al             
  0x01064957  00a6d8440001            add      byte ptr [esi + 0x10044d8], ah 
  0x0106495D  59                      pop      ecx                            
  0x0106495E  50                      push     eax                            
  0x0106495F  0000                    add      byte ptr [eax], al             
  0x01064961  002400                  add      byte ptr [eax + eax], ah       
  0x01064964  007044                  add      byte ptr [eax + 0x44], dh      
  0x01064967  009204000000            add      byte ptr [edx + 4], dl         
  0x0106496D  002400                  add      byte ptr [eax + eax], ah       
  0x01064970  007044                  add      byte ptr [eax + 0x44], dh      
  0x01064973  009104000000            add      byte ptr [ecx + 4], dl         
  0x01064979  1023                    adc      byte ptr [ebx], ah             
  0x0106497B  0000                    add      byte ptr [eax], al             
  0x0106497D  b8220000f4              mov      eax, 0xf4000022                
  0x01064982  7400                    je       0x1064984                      
                                        ; XREF: 0x01064982 (cond_jump)
  0x01064984  a5                      movsd    dword ptr es:[edi], dword ptr [esi] 
  0x01064985  0300                    add      eax, dword ptr [eax]           
  0x01064987  0000                    add      byte ptr [eax], al             
  0x01064989  f4                      hlt                                     
  0x0106498A  650032                  add      byte ptr gs:[edx], dh          
  0x0106498D  0b00                    or       eax, dword ptr [eax]           
  0x0106498F  0000                    add      byte ptr [eax], al             
  0x01064992  44                      inc      esp                            
  0x01064993  007b0b                  add      byte ptr [ebx + 0xb], bh       
  0x01064996  0000                    add      byte ptr [eax], al             
  0x01064998  00f4                    add      ah, dh                         
  0x0106499A  46                      inc      esi                            
  0x0106499B  0032                    add      byte ptr [edx], dh             
  0x0106499D  0000                    add      byte ptr [eax], al             
  0x0106499F  00d0                    add      al, dl                         
  0x010649A1  44                      inc      esp                            
  0x010649A2  2200                    and      al, byte ptr [eax]             
  0x010649A4  2e1d0c0040f4            sbb      eax, 0xf440000c                
  0x010649AA  44                      inc      esp                            
  0x010649AB  001c0c                  add      byte ptr [esp + ecx], bl       
  0x010649AE  0000                    add      byte ptr [eax], al             
  0x010649B0  40                      inc      eax                            
  0x010649B1  0020                    add      byte ptr [eax], ah             
  0x010649B3  0000                    add      byte ptr [eax], al             
  0x010649B5  96                      xchg     esi, eax                       
  0x010649B6  2100                    and      dword ptr [eax], eax           
  0x010649B8  0001                    add      byte ptr [ecx], al             
  0x010649BA  3900                    cmp      dword ptr [eax], eax           
  0x010649BC  ce                      into                                    
  0x010649BD  720b                    jb       0x10649ca                      
  0x010649BF  001a                    add      byte ptr [edx], bl             
  0x010649C1  0f0000                  sldt     word ptr [eax]                 
  0x010649C4  00c4                    add      ah, al                         
  0x010649C6  2300                    and      eax, dword ptr [eax]           
  0x010649C8  45                      inc      ebp                            
  0x010649C9  07                      pop      es                             
                                        ; XREF: 0x010649BD (cond_jump)
  0x010649CA  2200                    and      al, byte ptr [eax]             
  0x010649CC  40                      inc      eax                            
  0x010649CD  7002                    jo       0x10649d1                      
  0x010649CF  00742423                add      byte ptr [esp + 0x23], dh      
  0x010649D3  0044e857                add      byte ptr [eax + ebp*8 + 0x57], al 
  0x010649D7  0000                    add      byte ptr [eax], al             
  0x010649D9  58                      pop      eax                            
  0x010649DA  2000                    and      byte ptr [eax], al             
  0x010649DC  00e8                    add      al, ch                         
  0x010649DE  45                      inc      ebp                            
  0x010649DF  000da4050000            add      byte ptr [0x5a4], cl           
  0x010649E5  f4                      hlt                                     
  0x010649E6  47                      inc      edi                            
  0x010649E7  00d1                    add      cl, dl                         
  0x010649E9  0000                    add      byte ptr [eax], al             
  0x010649EB  0010                    add      byte ptr [eax], dl             
  0x010649ED  cc                      int3                                    
  0x010649EE  06                      push     es                             
  0x010649EF  0009                    add      byte ptr [ecx], cl             
  0x010649F1  0000                    add      byte ptr [eax], al             
  0x010649F3  006cee21                add      byte ptr [esi + ebp*8 + 0x21], ch 
  0x010649F7  006090                  add      byte ptr [eax - 0x70], ah      
  0x010649FA  0200                    add      al, byte ptr [eax]             
  0x010649FC  2e58                    pop      eax                            
  0x010649FE  2000                    and      byte ptr [eax], al             
  0x01064A00  2be8                    sub      ebp, eax                       
  0x01064A02  45                      inc      ebp                            
  0x01064A03  007dbd                  add      byte ptr [ebp - 0x43], bh      
  0x01064A06  2100                    and      dword ptr [eax], eax           
  0x01064A08  00ed                    add      ch, ch                         
  0x01064A0A  4c                      dec      esp                            
  0x01064A0B  00402f                  add      byte ptr [eax + 0x2f], al      
  0x01064A0E  2000                    and      byte ptr [eax], al             
  0x01064A10  00cf                    add      bh, cl                         
  0x01064A12  2100                    and      dword ptr [eax], eax           
  0x01064A14  00542200                add      byte ptr [edx], dl             
  0x01064A18  61                      popal                                   
  0x01064A19  f4                      hlt                                     
  0x01064A1A  44                      inc      esp                            
  0x01064A1B  0000                    add      byte ptr [eax], al             
  0x01064A1D  0100                    add      dword ptr [eax], eax           
  0x01064A1F  0094ec070044f0          add      byte ptr [esp + ebp*8 - 0xfbbfff9], dl 
  0x01064A26  47                      inc      edi                            
  0x01064A27  009104000080            add      byte ptr [ecx - 0x7ffffffc], dl 
  0x01064A2D  e40a                    in       al, 0xa                        
  0x01064A2F  000d70570093            add      byte ptr [0x93005770], cl      
  0x01064A35  0400                    add      al, 0                          
  0x01064A37  0008                    add      byte ptr [eax], cl             
  0x01064A39  f4                      hlt                                     
  0x01064A3A  05006dee20              add      eax, 0x20ee6d00                
  0x01064A3F  0058f4                  add      byte ptr [eax - 0xc], bl       
  0x01064A42  0500c44001              add      eax, 0x140c400                 
  0x01064A47  004000                  add      byte ptr [eax], al             
  0x01064A4A  0000                    add      byte ptr [eax], al             
  0x01064A4C  1329                    adc      ebp, dword ptr [ecx]           
  0x01064A4E  2000                    and      byte ptr [eax], al             
  0x01064A50  00872100530c            add      byte ptr [edi + 0xc530021], al 
  0x01064A56  050000f447              add      eax, 0x47f40000                
  0x01064A5B  008001000050            add      byte ptr [eax + 0x50000001], al 
  0x01064A61  0c05                    or       al, 5                          
  0x01064A63  0000                    add      byte ptr [eax], al             
  0x01064A65  8621                    xchg     byte ptr [ecx], ah             
  0x01064A67  0000                    add      byte ptr [eax], al             
  0x01064A69  ce                      into                                    
  0x01064A6A  2300                    and      eax, dword ptr [eax]           
  0x01064A6C  854701                  test     dword ptr [edi + 1], eax       
  0x01064A6F  000da4050000            add      byte ptr [0x5a4], cl           
  0x01064A75  ce                      into                                    
  0x01064A76  2000                    and      byte ptr [eax], al             
  0x01064A78  0d00200008              or       eax, 0x8002000                 
  0x01064A7D  f4                      hlt                                     
  0x01064A7E  05006dee20              add      eax, 0x20ee6d00                
  0x01064A83  0008                    add      byte ptr [eax], cl             
  0x01064A85  f4                      hlt                                     
  0x01064A86  0500c44001              add      eax, 0x140c400                 
  0x01064A8B  004000                  add      byte ptr [eax], al             
  0x01064A8E  0000                    add      byte ptr [eax], al             
  0x01064A90  1329                    adc      ebp, dword ptr [ecx]           
  0x01064A92  2000                    and      byte ptr [eax], al             
  0x01064A94  00872100030c            add      byte ptr [edi + 0xc030021], al 
  0x01064A9A  050000f447              add      eax, 0x47f40000                
  0x01064A9F  008001000000            add      byte ptr [eax + 1], al         
  0x01064AA6  44                      inc      esp                            
  0x01064AA7  00930400004d            add      byte ptr [ebx + 0x4d000004], dl 
  0x01064AAE  56                      push     esi                            
  0x01064AAF  009204000000            add      byte ptr [edx + 4], dl         
  0x01064AB5  7055                    jo       0x1064b0c                      
  0x01064AB7  009304000004            add      byte ptr [ebx + 0x4000004], dl 
  0x01064ABD  94                      xchg     esp, eax                       
  0x01064ABE  0500002e23              add      eax, 0x232e0000                
  0x01064AC3  0000                    add      byte ptr [eax], al             
  0x01064AC5  7071                    jo       0x1064b38                      
  0x01064AC7  009204000003            add      byte ptr [edx + 0x3000004], dl 
  0x01064ACD  0020                    add      byte ptr [eax], ah             
  0x01064ACF  0014a4                  add      byte ptr [esp], dl             
  0x01064AD2  05001e0c05              add      eax, 0x50c1e00                 
  0x01064AD7  000d00200008            add      byte ptr [0x8002000], cl       
  0x01064ADD  f4                      hlt                                     
  0x01064ADE  05006dee20              add      eax, 0x20ee6d00                
  0x01064AE3  001a                    add      byte ptr [edx], bl             
  0x01064AE5  f4                      hlt                                     
  0x01064AE6  0500c44001              add      eax, 0x140c400                 
  0x01064AEB  004000                  add      byte ptr [eax], al             
  0x01064AEE  0000                    add      byte ptr [eax], al             
  0x01064AF0  1329                    adc      ebp, dword ptr [ecx]           
  0x01064AF2  2000                    and      byte ptr [eax], al             
  0x01064AF4  00872100150c            add      byte ptr [edi + 0xc150021], al 
  0x01064AFA  050000f447              add      eax, 0x47f40000                
  0x01064AFF  004001                  add      byte ptr [eax + 1], al         
  0x01064B02  0000                    add      byte ptr [eax], al             
  0x01064B04  120c0500710020          adc      cl, byte ptr [eax + 0x20007100] 
  0x01064B0B  00c4                    add      ah, al                         
  0x01064B0D  40                      inc      eax                            
  0x01064B0E  0100                    add      dword ptr [eax], eax           
  0x01064B10  800000                  add      byte ptr [eax], 0              
  0x01064B13  0013                    add      byte ptr [ebx], dl             
  0x01064B15  2920                    sub      dword ptr [eax], esp           
  0x01064B17  0000                    add      byte ptr [eax], al             
  0x01064B19  8721                    xchg     dword ptr [ecx], esp           
  0x01064B1B  000c0c                  add      byte ptr [esp + ecx], cl       
  0x01064B1E  050001f044              add      eax, 0x44f00100                
  0x01064B23  008f04000044            add      byte ptr [edi + 0x44000004], cl 
  0x01064B2A  44                      inc      esp                            
  0x01064B2B  008e04000001            add      byte ptr [esi + 0x1000004], cl 
  0x01064B31  7054                    jo       0x1064b87                      
  0x01064B33  008b04000044            add      byte ptr [ebx + 0x44000004], cl 
  0x01064B39  7047                    jo       0x1064b82                      
  0x01064B3B  009104000074            add      byte ptr [ecx + 0x74000004], dl 
  0x01064B41  7054                    jo       0x1064b97                      
  0x01064B43  008a0400001b            add      byte ptr [edx + 0x1b000004], cl 
  0x01064B49  0c05                    or       al, 5                          
  0x01064B4B  0000                    add      byte ptr [eax], al             
  0x01064B4E  56                      push     esi                            
  0x01064B4F  008b04000000            add      byte ptr [ebx + 4], cl         
  0x01064B56  44                      inc      esp                            
  0x01064B57  008d04000044            add      byte ptr [ebp + 0x44000004], cl 
  0x01064B5E  44                      inc      esp                            
  0x01064B5F  008f04000001            add      byte ptr [edi + 0x1000004], cl 
  0x01064B65  8621                    xchg     byte ptr [ecx], ah             
  0x01064B67  0044f045                add      byte ptr [eax + esi*8 + 0x45], al 
  0x01064B6B  008a04000055            add      byte ptr [edx + 0x55000004], cl 
  0x01064B72  44                      inc      esp                            
  0x01064B73  008c0400005090          add      byte ptr [esp + eax - 0x6fb00000], cl 
  0x01064B7A  0200                    add      al, byte ptr [eax]             
  0x01064B7C  61                      popal                                   
  0x01064B7D  7054                    jo       0x1064bd3                      
  0x01064B7F  008b04000044            add      byte ptr [ebx + 0x44000004], cl 
  0x01064B86  44                      inc      esp                            
                                        ; XREF: 0x01064B31 (cond_jump)
  0x01064B87  008e04000001            add      byte ptr [esi + 0x1000004], cl 
  0x01064B8D  8621                    xchg     byte ptr [ecx], ah             
  0x01064B8F  00447047                add      byte ptr [eax + esi*2 + 0x47], al 
  0x01064B93  009104000055            add      byte ptr [ecx + 0x55000004], dl 
  0x01064B9A  44                      inc      esp                            
  0x01064B9B  008b04000050            add      byte ptr [ebx + 0x50000004], cl 
  0x01064BA1  90                      nop                                     
  0x01064BA2  0200                    add      al, byte ptr [eax]             
  0x01064BA4  7470                    je       0x1064c16                      
  0x01064BA6  54                      push     esp                            
  0x01064BA7  008a04000045            add      byte ptr [edx + 0x45000004], cl 
  0x01064BAD  0020                    add      byte ptr [eax], ah             
  0x01064BAF  004090                  add      byte ptr [eax - 0x70], al      
  0x01064BB2  0200                    add      al, byte ptr [eax]             
  0x01064BB4  00f0                    add      al, dh                         
  0x01064BB6  44                      inc      esp                            
  0x01064BB7  00900400004c            add      byte ptr [eax + 0x4c000004], dl 
  0x01064BBD  de4e00                  fimul    word ptr [esi]                 
  0x01064BC0  851c0c                  test     dword ptr [esp + ecx], ebx     
  0x01064BC3  001429                  add      byte ptr [ecx + ebp], dl       
  0x01064BC6  2000                    and      byte ptr [eax], al             
  0x01064BC8  55                      push     ebp                            
  0x01064BC9  0020                    add      byte ptr [eax], ah             
  0x01064BCB  005090                  add      byte ptr [eax - 0x70], dl      
  0x01064BCE  0200                    add      al, byte ptr [eax]             
  0x01064BD0  006a54                  add      byte ptr [edx + 0x54], ch      
                                        ; XREF: 0x01064B7D (cond_jump)
  0x01064BD3  0000                    add      byte ptr [eax], al             
  0x01064BD5  0e                      push     cs                             
  0x01064BD6  2200                    and      al, byte ptr [eax]             
  0x01064BD8  00c4                    add      ah, al                         
  0x01064BDA  2300                    and      eax, dword ptr [eax]           
  0x01064BDC  45                      inc      ebp                            
  0x01064BDD  5a                      pop      edx                            
  0x01064BDE  2000                    and      byte ptr [eax], al             
  0x01064BE0  d7                      xlatb                                   
  0x01064BE1  96                      xchg     esi, eax                       
  0x01064BE2  05000c0000              add      eax, 0xc00                     
  0x01064BE7  0000                    add      byte ptr [eax], al             
  0x01064BEA  56                      push     esi                            
  0x01064BEB  00b704000003            add      byte ptr [edi + 0x3000004], dh 
  0x01064BF2  44                      inc      esp                            
  0x01064BF3  00a204000007            add      byte ptr [edx + 0x7000004], ah 
  0x01064BF9  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01064BFA  050000ee20              add      eax, 0x20ee0000                
  0x01064BFF  00640024                add      byte ptr [eax + eax + 0x24], ah 
  0x01064C03  0010                    add      byte ptr [eax], dl             
  0x01064C05  cc                      int3                                    
  0x01064C06  06                      push     es                             
  0x01064C07  0002                    add      byte ptr [edx], al             
  0x01064C09  0000                    add      byte ptr [eax], al             
  0x01064C0B  0000                    add      byte ptr [eax], al             
  0x01064C0D  59                      pop      ecx                            
  0x01064C0E  44                      inc      esp                            
  0x01064C0F  004d0c                  add      byte ptr [ebp + 0xc], cl       
  0x01064C12  050000f464              add      eax, 0x64f40000                
  0x01064C17  00ba0c000000            add      byte ptr [edx + 0xc], bh       
  0x01064C1D  f4                      hlt                                     
  0x01064C1E  6600a504000000          add      byte ptr [ebp + 4], ah         
  0x01064C25  da5700                  ficom    dword ptr [edi]                
  0x01064C28  4c                      dec      esp                            
  0x01064C2A  46                      inc      esi                            
  0x01064C2B  00bf0400005c            add      byte ptr [edi + 0x5c000004], bh 
  0x01064C31  0020                    add      byte ptr [eax], ah             
  0x01064C33  001b                    add      byte ptr [ebx], bl             
  0x01064C35  2920                    sub      dword ptr [eax], esp           
  0x01064C37  00ce                    add      dh, cl                         
  0x01064C39  40                      inc      eax                            
  0x01064C3A  0100                    add      dword ptr [eax], eax           
  0x01064C3C  e01f                    loopne   0x1064c5d                      
  0x01064C3E  0000                    add      byte ptr [eax], al             
  0x01064C40  58                      pop      eax                            
  0x01064C41  dd5e00                  fstp     qword ptr [esi]                
  0x01064C44  7500                    jne      0x1064c46                      
                                        ; XREF: 0x01064C44 (cond_jump)
  0x01064C46  2000                    and      byte ptr [eax], al             
  0x01064C48  7070                    jo       0x1064cba                      
  0x01064C4A  0200                    add      al, byte ptr [eax]             
  0x01064C4C  64c521                  lds      esp, ptr fs:[ecx]              
  0x01064C4F  0084410100009e          add      byte ptr [ecx + eax*2 - 0x61ffffff], al 
  0x01064C56  2100                    and      dword ptr [eax], eax           
  0x01064C58  00d8                    add      al, bl                         
  0x01064C5A  56                      push     esi                            
  0x01064C5B  0014f4                  add      byte ptr [esp + esi*8], dl     
  0x01064C5E  46                      inc      esi                            
  0x01064C5F  003f                    add      byte ptr [edi], bh             
  0x01064C61  0000                    add      byte ptr [eax], al             
  0x01064C63  0013                    add      byte ptr [ebx], dl             
  0x01064C65  2920                    sub      dword ptr [eax], esp           
  0x01064C67  00ca                    add      dl, cl                         
  0x01064C69  1e                      push     ds                             
  0x01064C6A  0c00                    or       al, 0                          
  0x01064C6C  55                      push     ebp                            
  0x01064C6D  0020                    add      byte ptr [eax], ah             
  0x01064C6F  005070                  add      byte ptr [eax + 0x70], dl      
  0x01064C72  0200                    add      al, byte ptr [eax]             
  0x01064C74  009c210010de06          add      byte ptr [ecx + 0x6de1000], bl 
  0x01064C7B  000b                    add      byte ptr [ebx], cl             
  0x01064C7D  0000                    add      byte ptr [eax], al             
  0x01064C7F  0000                    add      byte ptr [eax], al             
  0x01064C81  d85600                  fcom     dword ptr [esi]                
  0x01064C84  14ec                    adc      al, 0xec                       
  0x01064C86  7e00                    jle      0x1064c88                      
                                        ; XREF: 0x01064C86 (cond_jump)
  0x01064C88  1329                    adc      ebp, dword ptr [ecx]           
  0x01064C8A  2000                    and      byte ptr [eax], al             
  0x01064C8C  ca1e0c                  retf     0xc1e                          
  0x01064C8F  005559                  add      byte ptr [ebp + 0x59], dl      
  0x01064C92  7600                    jbe      0x1064c94                      
                                        ; XREF: 0x01064C92 (cond_jump)
  0x01064C94  50                      push     eax                            
  0x01064C95  7002                    jo       0x1064c99                      
  0x01064C97  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01064C95 (cond_jump)
  0x01064C99  9c                      pushfd                                  
  0x01064C9A  2100                    and      dword ptr [eax], eax           
  0x01064C9C  00ee                    add      dh, ch                         
  0x01064C9E  56                      push     esi                            
  0x01064C9F  008041010000            add      byte ptr [eax + 0x141], al     
  0x01064CA5  6e                      outsb    dx, byte ptr [esi]             
  0x01064CA6  54                      push     esp                            
  0x01064CA7  0000                    add      byte ptr [eax], al             
  0x01064CA9  ec                      in       al, dx                         
  0x01064CAA  7e00                    jle      0x1064cac                      
                                        ; XREF: 0x01064CAA (cond_jump)
  0x01064CAC  005976                  add      byte ptr [ecx + 0x76], bl      
  0x01064CAF  0000                    add      byte ptr [eax], al             
  0x01064CB1  ee                      out      dx, al                         
  0x01064CB2  56                      push     esi                            
  0x01064CB3  008041010071            add      byte ptr [eax + 0x71000141], al 
  0x01064CB9  6e                      outsb    dx, byte ptr [esi]             
                                        ; XREF: 0x01064C48 (cond_jump)
  0x01064CBA  54                      push     esp                            
  0x01064CBB  006500                  add      byte ptr [ebp], ah             
  0x01064CBE  2000                    and      byte ptr [eax], al             
  0x01064CC0  99                      cdq                                     
  0x01064CC1  7705                    ja       0x1064cc8                      
  0x01064CC3  000c00                  add      byte ptr [eax + eax], cl       
  0x01064CC6  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01064CC1 (cond_jump)
  0x01064CC8  00f4                    add      ah, dh                         
  0x01064CCA  60                      pushal                                  
  0x01064CCB  00680b                  add      byte ptr [eax + 0xb], ch       
  0x01064CCE  0000                    add      byte ptr [eax], al             
  0x01064CD0  00f0                    add      al, dh                         
  0x01064CD2  7000                    jo       0x1064cd4                      
                                        ; XREF: 0x01064CD2 (cond_jump)
  0x01064CD4  40                      inc      eax                            
  0x01064CD5  0b00                    or       eax, dword ptr [eax]           
  0x01064CD7  0000                    add      byte ptr [eax], al             
  0x01064CD9  e8570000f0              call     0xf1064d35                     
  0x01064CDE  44                      inc      esp                            
  0x01064CDF  007a0b                  add      byte ptr [edx + 0xb], bh       
  0x01064CE2  0000                    add      byte ptr [eax], al             
  0x01064CE4  4c                      dec      esp                            
  0x01064CE5  0020                    add      byte ptr [eax], ah             
  0x01064CE7  000b                    add      byte ptr [ebx], cl             
  0x01064CE9  0020                    add      byte ptr [eax], ah             
  0x01064CEB  000c14                  add      byte ptr [esp + edx], cl       
  0x01064CEE  0500130020              add      eax, 0x20001300                
  0x01064CF3  0000                    add      byte ptr [eax], al             
  0x01064CF5  7056                    jo       0x1064d4d                      
  0x01064CF7  00660b                  add      byte ptr [esi + 0xb], ah       
  0x01064CFA  0000                    add      byte ptr [eax], al             
  0x01064CFC  007056                  add      byte ptr [eax + 0x56], dh      
  0x01064CFF  00670b                  add      byte ptr [edi + 0xb], ah       
  0x01064D02  0000                    add      byte ptr [eax], al             
  0x01064D04  007056                  add      byte ptr [eax + 0x56], dh      
  0x01064D07  00a40400000070          add      byte ptr [esp + eax + 0x70000000], ah 
  0x01064D0E  56                      push     esi                            
  0x01064D0F  006e0b                  add      byte ptr [esi + 0xb], ch       
  0x01064D12  0000                    add      byte ptr [eax], al             
  0x01064D14  c0100d                  rcl      byte ptr [eax], 0xd            
  0x01064D17  0027                    add      byte ptr [edi], ah             
  0x01064D19  0000                    add      byte ptr [eax], al             
  0x01064D1B  0013                    add      byte ptr [ebx], dl             
  0x01064D1D  0020                    add      byte ptr [eax], ah             
  0x01064D1F  0000                    add      byte ptr [eax], al             
  0x01064D21  d821                    fsub     dword ptr [ecx]                
  0x01064D23  0000                    add      byte ptr [eax], al             
  0x01064D26  44                      inc      esp                            
  0x01064D27  00700b                  add      byte ptr [eax + 0xb], dh       
  0x01064D2A  0000                    add      byte ptr [eax], al             
  0x01064D2C  45                      inc      ebp                            
  0x01064D2D  0020                    add      byte ptr [eax], ah             
  0x01064D2F  000494                  add      byte ptr [esp + edx*4], al     
  0x01064D32  050000f456              add      eax, 0x56f40000                
  0x01064D37  0009                    add      byte ptr [ecx], cl             
  0x01064D39  0000                    add      byte ptr [eax], al             
  0x01064D3B  0000                    add      byte ptr [eax], al             
  0x01064D3D  d821                    fsub     dword ptr [ecx]                
  0x01064D3F  000500200009            add      byte ptr [0x9002000], al       
  0x01064D45  f4                      hlt                                     
  0x01064D46  0500130020              add      eax, 0x20001300                
  0x01064D4B  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01064CF5 (cond_jump)
  0x01064D4D  7056                    jo       0x1064da5                      
  0x01064D4F  00660b                  add      byte ptr [esi + 0xb], ah       
  0x01064D52  0000                    add      byte ptr [eax], al             
  0x01064D54  007056                  add      byte ptr [eax + 0x56], dh      
  0x01064D57  00670b                  add      byte ptr [edi + 0xb], ah       
  0x01064D5A  0000                    add      byte ptr [eax], al             
  0x01064D5C  007056                  add      byte ptr [eax + 0x56], dh      
  0x01064D5F  00a4040000130c          add      byte ptr [esp + eax + 0xc130000], ah 
  0x01064D66  050000f456              add      eax, 0x56f40000                
  0x01064D6B  0001                    add      byte ptr [ecx], al             
  0x01064D6D  0000                    add      byte ptr [eax], al             
  0x01064D6F  0000                    add      byte ptr [eax], al             
  0x01064D71  7056                    jo       0x1064dc9                      
  0x01064D73  00660b                  add      byte ptr [esi + 0xb], ah       
  0x01064D76  0000                    add      byte ptr [eax], al             
  0x01064D78  00ee                    add      dh, ch                         
  0x01064D7A  2100                    and      dword ptr [eax], eax           
  0x01064D7C  000423                  add      byte ptr [ebx], al             
  0x01064D7F  00440020                add      byte ptr [eax + eax + 0x20], al 
  0x01064D83  0006                    add      byte ptr [esi], al             
  0x01064D85  1c0c                    sbb      al, 0xc                        
  0x01064D87  0000                    add      byte ptr [eax], al             
  0x01064D89  0028                    add      byte ptr [eax], ch             
  0x01064D8B  0000                    add      byte ptr [eax], al             
  0x01064D8D  7056                    jo       0x1064de5                      
  0x01064D8F  00670b                  add      byte ptr [edi + 0xb], ah       
  0x01064D92  0000                    add      byte ptr [eax], al             
  0x01064D94  06                      push     es                             
  0x01064D95  1d0c000004              sbb      eax, 0x400000c                 
  0x01064D9A  2300                    and      eax, dword ptr [eax]           
  0x01064D9C  40                      inc      eax                            
  0x01064D9D  0020                    add      byte ptr [eax], ah             
  0x01064D9F  0000                    add      byte ptr [eax], al             
  0x01064DA1  7056                    jo       0x1064df9                      
  0x01064DA3  00a404000000c4          add      byte ptr [esp + eax - 0x3c000000], ah 
  0x01064DAA  2100                    and      dword ptr [eax], eax           
  0x01064DAC  4c                      dec      esp                            
  0x01064DAD  0020                    add      byte ptr [eax], ah             
  0x01064DAF  0000                    add      byte ptr [eax], al             
  0x01064DB2  56                      push     esi                            
  0x01064DB3  00400b                  add      byte ptr [eax + 0xb], al       
  0x01064DB6  0000                    add      byte ptr [eax], al             
  0x01064DB8  00f4                    add      ah, dh                         
  0x01064DBA  44                      inc      esp                            
  0x01064DBB  000500000045            add      byte ptr [0x45000000], al      
  0x01064DC1  0020                    add      byte ptr [eax], ah             
  0x01064DC3  0013                    add      byte ptr [ebx], dl             
  0x01064DC5  2405                    and      al, 5                          
  0x01064DC7  0000                    add      byte ptr [eax], al             
  0x01064DCA  56                      push     esi                            
  0x01064DCB  009f0b000000            add      byte ptr [edi + 0xb], bl       
  0x01064DD2  44                      inc      esp                            
  0x01064DD3  007a0b                  add      byte ptr [edx + 0xb], bh       
  0x01064DD6  0000                    add      byte ptr [eax], al             
  0x01064DD8  44                      inc      esp                            
  0x01064DD9  0020                    add      byte ptr [eax], ah             
  0x01064DDB  0000                    add      byte ptr [eax], al             
  0x01064DDE  44                      inc      esp                            
  0x01064DDF  00530b                  add      byte ptr [ebx + 0xb], dl       
  0x01064DE2  0000                    add      byte ptr [eax], al             
  0x01064DE4  44                      inc      esp                            
                                        ; XREF: 0x01064D8D (cond_jump)
  0x01064DE5  0020                    add      byte ptr [eax], ah             
  0x01064DE7  0000                    add      byte ptr [eax], al             
  0x01064DE9  d921                    fldenv   [ecx]                          
  0x01064DEB  0000                    add      byte ptr [eax], al             
  0x01064DED  7057                    jo       0x1064e46                      
  0x01064DEF  006e0b                  add      byte ptr [esi + 0xb], ch       
  0x01064DF2  0000                    add      byte ptr [eax], al             
  0x01064DF4  0300                    add      eax, dword ptr [eax]           
  0x01064DF6  2000                    and      byte ptr [eax], al             
  0x01064DF8  0494                    add      al, 0x94                       
  0x01064DFA  0500050020              add      eax, 0x20000500                
  0x01064DFF  0002                    add      byte ptr [edx], al             
  0x01064E01  f4                      hlt                                     
  0x01064E02  0500030c05              add      eax, 0x50c0300                 
  0x01064E07  0000                    add      byte ptr [eax], al             
  0x01064E09  2423                    and      al, 0x23                       
  0x01064E0B  0000                    add      byte ptr [eax], al             
  0x01064E0E  2000                    and      byte ptr [eax], al             
  0x01064E10  00f0                    add      al, dh                         
  0x01064E12  56                      push     esi                            
  0x01064E13  00700b                  add      byte ptr [eax + 0xb], dh       
  0x01064E16  0000                    add      byte ptr [eax], al             
  0x01064E18  0300                    add      eax, dword ptr [eax]           
  0x01064E1A  2000                    and      byte ptr [eax], al             
  0x01064E1C  0af4                    or       dh, ah                         
  0x01064E1E  050000f444              add      eax, 0x44f40000                
  0x01064E23  0001                    add      byte ptr [ecx], al             
  0x01064E25  0000                    add      byte ptr [eax], al             
  0x01064E27  0000                    add      byte ptr [eax], al             
  0x01064E29  7044                    jo       0x1064e6f                      
  0x01064E2B  00660b                  add      byte ptr [esi + 0xb], ah       
  0x01064E2E  0000                    add      byte ptr [eax], al             
  0x01064E30  00f0                    add      al, dh                         
  0x01064E32  44                      inc      esp                            
  0x01064E33  00670b                  add      byte ptr [edi + 0xb], ah       
  0x01064E36  0000                    add      byte ptr [eax], al             
  0x01064E38  40                      inc      eax                            
  0x01064E39  0020                    add      byte ptr [eax], ah             
  0x01064E3B  0000                    add      byte ptr [eax], al             
  0x01064E3D  7056                    jo       0x1064e95                      
  0x01064E3F  00670b                  add      byte ptr [edi + 0xb], ah       
  0x01064E42  0000                    add      byte ptr [eax], al             
  0x01064E44  0c00                    or       al, 0                          
                                        ; XREF: 0x01064DED (cond_jump)
  0x01064E46  0000                    add      byte ptr [eax], al             
  0x01064E48  0011                    add      byte ptr [ecx], dl             
  0x01064E4A  2200                    and      al, byte ptr [eax]             
  0x01064E4C  00b2220069f4            add      byte ptr [edx - 0xb96ffde], dh 
  0x01064E52  46                      inc      esi                            
  0x01064E53  0002                    add      byte ptr [edx], al             
  0x01064E55  0000                    add      byte ptr [eax], al             
  0x01064E57  0010                    add      byte ptr [eax], dl             
  0x01064E59  d806                    fadd     dword ptr [esi]                
  0x01064E5B  000500000000            add      byte ptr [0], al               
  0x01064E61  c9                      leave                                   
  0x01064E62  56                      push     esi                            
  0x01064E63  00148f                  add      byte ptr [edi + ecx*4], dl     
  0x01064E66  2100                    and      dword ptr [eax], eax           
  0x01064E68  50                      push     eax                            
  0x01064E69  0020                    add      byte ptr [eax], ah             
  0x01064E6B  0000                    add      byte ptr [eax], al             
  0x01064E6D  5a                      pop      edx                            
  0x01064E6E  54                      push     esp                            
                                        ; XREF: 0x01064E29 (cond_jump)
  0x01064E6F  0000                    add      byte ptr [eax], al             
  0x01064E71  4e                      dec      esi                            
  0x01064E72  2300                    and      eax, dword ptr [eax]           
  0x01064E74  32442300                xor      al, byte ptr [ebx]             
  0x01064E78  40                      inc      eax                            
  0x01064E79  0423                    add      al, 0x23                       
  0x01064E7B  00440024                add      byte ptr [eax + eax + 0x24], al 
  0x01064E7F  0004a4                  add      byte ptr [esp], al             
  0x01064E82  050010cc06              add      eax, 0x6cc1000                 
  0x01064E87  0002                    add      byte ptr [edx], al             
  0x01064E89  0000                    add      byte ptr [eax], al             
  0x01064E8B  0000                    add      byte ptr [eax], al             
  0x01064E8D  5a                      pop      edx                            
  0x01064E8E  44                      inc      esp                            
  0x01064E8F  0000                    add      byte ptr [eax], al             
  0x01064E91  b022                    mov      al, 0x22                       
  0x01064E93  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01064E3D (cond_jump)
  0x01064E95  91                      xchg     ecx, eax                       
  0x01064E96  2200                    and      al, byte ptr [eax]             
  0x01064E98  00f4                    add      ah, dh                         
  0x01064E9A  65000d0d000000          add      byte ptr gs:[0xd], cl          
  0x01064EA1  f4                      hlt                                     
  0x01064EA2  7500                    jne      0x1064ea4                      
  0x01064EA6  ff00                    inc      dword ptr [eax]                
  0x01064EA8  10da                    adc      dl, bl                         
  0x01064EAA  06                      push     es                             
  0x01064EAB  0007                    add      byte ptr [edi], al             
  0x01064EAD  0000                    add      byte ptr [eax], al             
  0x01064EAF  0000                    add      byte ptr [eax], al             
  0x01064EB1  b8f000d0b8              mov      eax, 0xb8d000f0                
  0x01064EB7  00d2                    add      dl, dl                         
  0x01064EB9  b8d000d200              mov      eax, 0xd200d0                  
  0x01064EBE  2000                    and      byte ptr [eax], al             
  0x01064EC0  2200                    and      al, byte ptr [eax]             
  0x01064EC2  2000                    and      byte ptr [eax], al             
  0x01064EC4  005958                  add      byte ptr [ecx + 0x58], bl      
  0x01064EC7  000c00                  add      byte ptr [eax + eax], cl       
  0x01064ECA  0000                    add      byte ptr [eax], al             
  0x01064ECC  20f4                    and      ah, dh                         
  0x01064ECE  0500ffffff              add      eax, 0xffffff00                
  0x01064ED3  00a0610400a0            add      byte ptr [eax - 0x5ffffb9f], ah 
  0x01064ED9  620400                  bound    eax, qword ptr [eax + eax]     
  0x01064EDC  a0640400a0              mov      al, byte ptr [0xa0000464]      
  0x01064EE1  650400                  add      al, 0                          
  0x01064EE4  a0660400b8              mov      al, byte ptr [0xb8000466]      
  0x01064EE9  f30000                  add      byte ptr [eax], al             
  0x01064EEC  00f4                    add      ah, dh                         
  0x01064EEE  44                      inc      esp                            
  0x01064EEF  0000                    add      byte ptr [eax], al             
  0x01064EF1  0000                    add      byte ptr [eax], al             
  0x01064EF3  004d00                  add      byte ptr [ebp], cl             
  0x01064EF6  2000                    and      byte ptr [eax], al             
  0x01064EF8  0ca4                    or       al, 0xa4                       
  0x01064EFA  050000f444              add      eax, 0x44f40000                
  0x01064EFF  0010                    add      byte ptr [eax], dl             
  0x01064F01  0000                    add      byte ptr [eax], al             
  0x01064F03  004d00                  add      byte ptr [ebp], cl             
  0x01064F06  2000                    and      byte ptr [eax], al             
  0x01064F08  4a                      dec      edx                            
  0x01064F09  100d000f0000            adc      byte ptr [0xf00], cl           
  0x01064F0F  0000                    add      byte ptr [eax], al             
  0x01064F11  0030                    add      byte ptr [eax], dh             
  0x01064F13  0000                    add      byte ptr [eax], al             
  0x01064F15  f4                      hlt                                     
  0x01064F16  56                      push     esi                            
  0x01064F17  0000                    add      byte ptr [eax], al             
  0x01064F19  0000                    add      byte ptr [eax], al             
  0x01064F1B  0000                    add      byte ptr [eax], al             
  0x01064F1D  f4                      hlt                                     
  0x01064F1E  57                      push     edi                            
  0x01064F1F  00ff                    add      bh, bh                         
  0x01064F22  ff00                    inc      dword ptr [eax]                
  0x01064F24  0c00                    or       al, 0                          
  0x01064F26  0000                    add      byte ptr [eax], al             
  0x01064F28  1300                    adc      eax, dword ptr [eax]           
  0x01064F2A  2000                    and      byte ptr [eax], al             
  0x01064F2C  0000                    add      byte ptr [eax], al             
  0x01064F2E  3000                    xor      byte ptr [eax], al             
  0x01064F30  00f4                    add      ah, dh                         
  0x01064F32  56                      push     esi                            
  0x01064F33  0000                    add      byte ptr [eax], al             
  0x01064F35  0000                    add      byte ptr [eax], al             
  0x01064F37  0000                    add      byte ptr [eax], al             
  0x01064F39  f4                      hlt                                     
  0x01064F3A  57                      push     edi                            
  0x01064F3B  0008                    add      byte ptr [eax], cl             
  0x01064F3D  06                      push     es                             
  0x01064F3E  0000                    add      byte ptr [eax], al             
  0x01064F40  0c00                    or       al, 0                          
  0x01064F42  0000                    add      byte ptr [eax], al             
  0x01064F44  00f0                    add      al, dh                         
  0x01064F46  56                      push     esi                            
  0x01064F47  00960b000003            add      byte ptr [esi + 0x300000b], dl 
  0x01064F4D  0020                    add      byte ptr [eax], ah             
  0x01064F4F  001e                    add      byte ptr [esi], bl             
  0x01064F51  7405                    je       0x1064f58                      
  0x01064F53  0000                    add      byte ptr [eax], al             
  0x01064F56  56                      push     esi                            
  0x01064F57  00400b                  add      byte ptr [eax + 0xb], al       
  0x01064F5A  0000                    add      byte ptr [eax], al             
  0x01064F5C  0300                    add      eax, dword ptr [eax]           
  0x01064F5E  2e0002                  add      byte ptr cs:[edx], al          
  0x01064F61  2405                    and      al, 5                          
  0x01064F63  008041010000            add      byte ptr [eax + 0x141], al     
  0x01064F69  7056                    jo       0x1064fc1                      
  0x01064F6B  00890b000080            add      byte ptr [ecx - 0x7ffffff5], cl 
  0x01064F71  100d008b0300            adc      byte ptr [0x38b00], cl         
  0x01064F77  0000                    add      byte ptr [eax], al             
  0x01064F79  f4                      hlt                                     
  0x01064F7A  44                      inc      esp                            
  0x01064F7B  00b007000000            add      byte ptr [eax + 7], dh         
  0x01064F81  7044                    jo       0x1064fc7                      
  0x01064F83  00720b                  add      byte ptr [edx + 0xb], dh       
  0x01064F86  0000                    add      byte ptr [eax], al             
  0x01064F88  80100d                  adc      byte ptr [eax], 0xd            
  0x01064F8B  001400                  add      byte ptr [eax + eax], dl       
  0x01064F8E  0000                    add      byte ptr [eax], al             
  0x01064F90  00f0                    add      al, dh                         
  0x01064F92  56                      push     esi                            
  0x01064F93  00400b                  add      byte ptr [eax + 0xb], al       
  0x01064F96  0000                    add      byte ptr [eax], al             
  0x01064F98  0300                    add      eax, dword ptr [eax]           
  0x01064F9A  2e0003                  add      byte ptr cs:[ebx], al          
  0x01064F9D  2405                    and      al, 5                          
  0x01064F9F  0080100d0053            add      byte ptr [eax + 0x53000d10], al 
  0x01064FA5  0300                    add      eax, dword ptr [eax]           
  0x01064FA7  0080100d009d            add      byte ptr [eax - 0x62fff2f0], al 
  0x01064FAD  0000                    add      byte ptr [eax], al             
  0x01064FAF  0000                    add      byte ptr [eax], al             
  0x01064FB2  56                      push     esi                            
  0x01064FB3  00960b000003            add      byte ptr [esi + 0x300000b], dl 
  0x01064FB9  0020                    add      byte ptr [eax], ah             
  0x01064FBB  0003                    add      byte ptr [ebx], al             
  0x01064FBD  2405                    and      al, 5                          
  0x01064FBF  0080100d009c            add      byte ptr [eax - 0x63fff2f0], al 
  0x01064FC5  0100                    add      dword ptr [eax], eax           
                                        ; XREF: 0x01064F81 (cond_jump)
  0x01064FC7  0013                    add      byte ptr [ebx], dl             
  0x01064FC9  0020                    add      byte ptr [eax], ah             
  0x01064FCB  001b                    add      byte ptr [ebx], bl             
  0x01064FCD  1021                    adc      byte ptr [ecx], ah             
  0x01064FCF  000c00                  add      byte ptr [eax + eax], cl       
  0x01064FD2  0000                    add      byte ptr [eax], al             
  0x01064FD4  0c00                    or       al, 0                          
  0x01064FD6  0000                    add      byte ptr [eax], al             
  0x01064FD8  00f4                    add      ah, dh                         
  0x01064FDA  44                      inc      esp                            
  0x01064FDB  0001                    add      byte ptr [ecx], al             
  0x01064FDD  0000                    add      byte ptr [eax], al             
  0x01064FDF  0000                    add      byte ptr [eax], al             
  0x01064FE1  7044                    jo       0x1065027                      
  0x01064FE3  006f0b                  add      byte ptr [edi + 0xb], ch       
  0x01064FE6  0000                    add      byte ptr [eax], al             
  0x01064FE8  1bf0                    sbb      esi, eax                       
  0x01064FEA  56                      push     esi                            
  0x01064FEB  00400b                  add      byte ptr [eax + 0xb], al       
  0x01064FEE  0000                    add      byte ptr [eax], al             
  0x01064FF0  0300                    add      eax, dword ptr [eax]           
  0x01064FF2  2000                    and      byte ptr [eax], al             
  0x01064FF4  02240500090000          add      ah, byte ptr [eax + 0x900]     
  0x01064FFB  0000                    add      byte ptr [eax], al             
  0x01064FFD  7051                    jo       0x1065050                      
  0x01064FFF  00c0                    add      al, al                         
  0x01065001  0400                    add      al, 0                          
  0x01065003  0000                    add      byte ptr [eax], al             
  0x01065005  0230                    add      dh, byte ptr [eax]             
  0x01065007  0000                    add      byte ptr [eax], al             
  0x01065009  0131                    add      dword ptr [ecx], esi           
  0x0106500B  0000                    add      byte ptr [eax], al             
  0x0106500D  0132                    add      dword ptr [edx], esi           
  0x0106500F  0000                    add      byte ptr [eax], al             
  0x01065011  023500c4700b            add      dh, byte ptr [0xb70c400]       
  0x01065017  0008                    add      byte ptr [eax], cl             
  0x01065019  0c00                    or       al, 0                          
  0x0106501B  0000                    add      byte ptr [eax], al             
  0x0106501D  7044                    jo       0x1065063                      
  0x0106501F  008d040000c4            add      byte ptr [ebp - 0x3bfffffc], cl 
  0x01065025  710b                    jno      0x1065032                      
                                        ; XREF: 0x01064FE1 (cond_jump)
  0x01065027  00040c                  add      byte ptr [esp + ecx], al       
  0x0106502A  0000                    add      byte ptr [eax], al             
  0x0106502C  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106502F  008c040000c472          add      byte ptr [esp + eax + 0x72c40000], cl 
  0x01065036  0b00                    or       eax, dword ptr [eax]           
  0x01065038  140c                    adc      al, 0xc                        
  0x0106503A  0000                    add      byte ptr [eax], al             
  0x0106503C  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106503F  008f040000c4            add      byte ptr [edi - 0x3bfffffc], cl 
  0x01065045  750b                    jne      0x1065052                      
  0x01065047  0018                    add      byte ptr [eax], bl             
  0x01065049  0c00                    or       al, 0                          
  0x0106504B  0000                    add      byte ptr [eax], al             
  0x0106504D  7044                    jo       0x1065093                      
  0x0106504F  009004000000            add      byte ptr [eax + 4], dl         
  0x01065055  0036                    add      byte ptr [esi], dh             
  0x01065057  0000                    add      byte ptr [eax], al             
  0x0106505A  44                      inc      esp                            
  0x0106505B  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x01065061  c406                    les      eax, ptr [esi]                 
                                        ; XREF: 0x0106501D (cond_jump)
  0x01065063  004e00                  add      byte ptr [esi], cl             
  0x01065066  0000                    add      byte ptr [eax], al             
  0x01065068  0001                    add      byte ptr [ecx], al             
  0x0106506A  2800                    sub      byte ptr [eax], al             
  0x0106506C  007050                  add      byte ptr [eax + 0x50], dh      
  0x0106506F  00c0                    add      al, al                         
  0x01065071  0400                    add      al, 0                          
  0x01065073  0000                    add      byte ptr [eax], al             
  0x01065075  0430                    add      al, 0x30                       
  0x01065077  00c4                    add      ah, al                         
  0x01065079  700b                    jo       0x1065086                      
  0x0106507B  000c0c                  add      byte ptr [esp + ecx], cl       
  0x0106507E  0000                    add      byte ptr [eax], al             
  0x01065080  007044                  add      byte ptr [eax + 0x44], dh      
  0x01065083  008e04000000            add      byte ptr [esi + 4], cl         
  0x01065089  f4                      hlt                                     
  0x0106508A  44                      inc      esp                            
  0x0106508B  0000                    add      byte ptr [eax], al             
  0x0106508D  80ff00                  cmp      bh, 0                          
  0x01065090  007044                  add      byte ptr [eax + 0x44], dh      
                                        ; XREF: 0x0106504D (cond_jump)
  0x01065093  008a04000000            add      byte ptr [edx + 4], cl         
  0x01065099  f4                      hlt                                     
  0x0106509A  44                      inc      esp                            
  0x0106509B  0000                    add      byte ptr [eax], al             
  0x0106509D  80ff00                  cmp      bh, 0                          
  0x010650A0  007044                  add      byte ptr [eax + 0x44], dh      
  0x010650A3  008b04000000            add      byte ptr [ebx + 4], cl         
  0x010650A9  c422                    les      esp, ptr [edx]                 
  0x010650AB  0000                    add      byte ptr [eax], al             
  0x010650AD  f4                      hlt                                     
  0x010650AE  46                      inc      esi                            
  0x010650AF  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x010650B5  f4                      hlt                                     
  0x010650B6  44                      inc      esp                            
  0x010650B7  00fa                    add      dl, bh                         
  0x010650B9  0000                    add      byte ptr [eax], al             
  0x010650BB  002e                    add      byte ptr [esi], ch             
  0x010650BD  1d0c004000              sbb      eax, 0x40000c                  
  0x010650C2  2000                    and      byte ptr [eax], al             
  0x010650C4  0090210000c4            add      byte ptr [eax - 0x3bffffdf], dl 
  0x010650CA  2200                    and      al, byte ptr [eax]             
  0x010650CC  00f4                    add      ah, dh                         
  0x010650CE  46                      inc      esi                            
  0x010650CF  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x010650D5  f4                      hlt                                     
  0x010650D6  44                      inc      esp                            
  0x010650D7  00fa                    add      dl, bh                         
  0x010650D9  0000                    add      byte ptr [eax], al             
  0x010650DB  002e                    add      byte ptr [esi], ch             
  0x010650DD  1d0c004000              sbb      eax, 0x40000c                  
  0x010650E2  2000                    and      byte ptr [eax], al             
  0x010650E4  0095210000c4            add      byte ptr [ebp - 0x3bffffdf], dl 
  0x010650EA  2200                    and      al, byte ptr [eax]             
  0x010650EC  00f4                    add      ah, dh                         
  0x010650EE  46                      inc      esi                            
  0x010650EF  0032                    add      byte ptr [edx], dh             
  0x010650F1  0000                    add      byte ptr [eax], al             
  0x010650F3  00d0                    add      al, dl                         
  0x010650F5  f4                      hlt                                     
  0x010650F6  44                      inc      esp                            
  0x010650F7  0000                    add      byte ptr [eax], al             
  0x010650F9  0000                    add      byte ptr [eax], al             
  0x010650FB  002e                    add      byte ptr [esi], ch             
  0x010650FD  1d0c004000              sbb      eax, 0x40000c                  
  0x01065102  2000                    and      byte ptr [eax], al             
  0x01065104  009a21000000            add      byte ptr [edx + 0x21], bl      
  0x0106510A  3800                    cmp      byte ptr [eax], al             
  0x0106510C  00f4                    add      ah, dh                         
  0x0106510E  56                      push     esi                            
  0x0106510F  00a50b000000            add      byte ptr [ebp + 0xb], ah       
  0x01065115  c422                    les      esp, ptr [edx]                 
  0x01065117  004000                  add      byte ptr [eax], al             
  0x0106511A  2000                    and      byte ptr [eax], al             
  0x0106511C  0091210000e1            add      byte ptr [ecx - 0x1effffdf], dl 
  0x01065122  7400                    je       0x1065124                      
                                        ; XREF: 0x01065122 (cond_jump)
  0x01065124  00e1                    add      cl, ah                         
  0x01065126  7600                    jbe      0x1065128                      
                                        ; XREF: 0x01065126 (cond_jump)
  0x01065128  0000                    add      byte ptr [eax], al             
  0x0106512A  3200                    xor      al, byte ptr [eax]             
  0x0106512C  007066                  add      byte ptr [eax + 0x66], dh      
  0x0106512F  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01065132  0000                    add      byte ptr [eax], al             
  0x01065134  d7                      xlatb                                   
  0x01065135  030d0000f066            add      ecx, dword ptr [0x66f00000]    
  0x0106513B  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106513E  0000                    add      byte ptr [eax], al             
  0x01065140  00f4                    add      ah, dh                         
  0x01065142  56                      push     esi                            
  0x01065143  00c1                    add      cl, al                         
  0x01065145  0400                    add      al, 0                          
  0x01065147  0000                    add      byte ptr [eax], al             
  0x01065149  c422                    les      esp, ptr [edx]                 
  0x0106514B  004000                  add      byte ptr [eax], al             
  0x0106514E  2000                    and      byte ptr [eax], al             
  0x01065150  009021000060            add      byte ptr [eax + 0x60000021], dl 
  0x01065156  6200                    bound    eax, qword ptr [eax]           
  0x01065158  00f4                    add      ah, dh                         
  0x0106515A  56                      push     esi                            
  0x0106515B  009404000000c4          add      byte ptr [esp + eax - 0x3c000000], dl 
  0x01065162  2200                    and      al, byte ptr [eax]             
  0x01065164  40                      inc      eax                            
  0x01065165  0020                    add      byte ptr [eax], ah             
  0x01065167  0000                    add      byte ptr [eax], al             
  0x01065169  90                      nop                                     
  0x0106516A  2100                    and      dword ptr [eax], eax           
  0x0106516C  00f0                    add      al, dh                         
  0x0106516E  44                      inc      esp                            
  0x0106516F  008a04000000            add      byte ptr [edx + 4], cl         
  0x01065175  60                      pushal                                  
  0x01065176  44                      inc      esp                            
  0x01065177  0000                    add      byte ptr [eax], al             
  0x01065179  f4                      hlt                                     
  0x0106517A  56                      push     esi                            
  0x0106517B  009904000000            add      byte ptr [ecx + 4], bl         
  0x01065181  c422                    les      esp, ptr [edx]                 
  0x01065183  004000                  add      byte ptr [eax], al             
  0x01065186  2000                    and      byte ptr [eax], al             
  0x01065188  0090210000f0            add      byte ptr [eax - 0xfffffdf], dl 
  0x0106518E  44                      inc      esp                            
  0x0106518F  008b04000000            add      byte ptr [ebx + 4], cl         
  0x01065195  60                      pushal                                  
  0x01065196  44                      inc      esp                            
  0x01065197  0000                    add      byte ptr [eax], al             
  0x01065199  5e                      pop      esi                            
  0x0106519A  2000                    and      byte ptr [eax], al             
  0x0106519C  00f0                    add      al, dh                         
  0x0106519E  56                      push     esi                            
  0x0106519F  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x010651A2  0000                    add      byte ptr [eax], al             
  0x010651A4  0300                    add      eax, dword ptr [eax]           
  0x010651A6  2000                    and      byte ptr [eax], al             
  0x010651A8  1ca4                    sbb      al, 0xa4                       
  0x010651AA  0500000128              add      eax, 0x28010000                
  0x010651AF  0000                    add      byte ptr [eax], al             
  0x010651B1  7050                    jo       0x1065203                      
  0x010651B3  00c0                    add      al, al                         
  0x010651B5  0400                    add      al, 0                          
  0x010651B7  0000                    add      byte ptr [eax], al             
  0x010651B9  0430                    add      al, 0x30                       
  0x010651BB  00c4                    add      ah, al                         
  0x010651BD  700b                    jo       0x10651ca                      
  0x010651BF  000c0c                  add      byte ptr [esp + ecx], cl       
  0x010651C2  0000                    add      byte ptr [eax], al             
  0x010651C4  007044                  add      byte ptr [eax + 0x44], dh      
  0x010651C7  008e04000000            add      byte ptr [esi + 4], cl         
  0x010651CD  f4                      hlt                                     
  0x010651CE  44                      inc      esp                            
  0x010651CF  0000                    add      byte ptr [eax], al             
  0x010651D1  80ff00                  cmp      bh, 0                          
  0x010651D4  007044                  add      byte ptr [eax + 0x44], dh      
  0x010651D7  008a04000000            add      byte ptr [edx + 4], cl         
  0x010651DD  f4                      hlt                                     
  0x010651DE  44                      inc      esp                            
  0x010651DF  0000                    add      byte ptr [eax], al             
  0x010651E1  80ff00                  cmp      bh, 0                          
  0x010651E4  007044                  add      byte ptr [eax + 0x44], dh      
  0x010651E7  008b04000000            add      byte ptr [ebx + 4], cl         
  0x010651ED  f4                      hlt                                     
  0x010651EE  60                      pushal                                  
  0x010651EF  008304000000            add      byte ptr [ebx + 4], al         
  0x010651F5  f4                      hlt                                     
  0x010651F6  65008304000000          add      byte ptr gs:[ebx + 4], al      
  0x010651FD  f4                      hlt                                     
  0x010651FE  7200                    jb       0x1065200                      
                                        ; XREF: 0x010651FE (cond_jump)
  0x01065200  b804000000              mov      eax, 4                         
  0x01065205  0038                    add      byte ptr [eax], bh             
  0x01065207  0000                    add      byte ptr [eax], al             
  0x01065209  07                      pop      es                             
  0x0106520A  3c00                    cmp      al, 0                          
  0x0106520C  0007                    add      byte ptr [edi], al             
  0x0106520E  3e0000                  add      byte ptr ds:[eax], al          
  0x01065211  0032                    add      byte ptr [edx], dh             
  0x01065213  00d7                    add      bh, dl                         
  0x01065215  030d000c0000            add      ecx, dword ptr [0xc00]         
  0x0106521B  0000                    add      byte ptr [eax], al             
  0x0106521E  56                      push     esi                            
  0x0106521F  00400b                  add      byte ptr [eax + 0xb], al       
  0x01065222  0000                    add      byte ptr [eax], al             
  0x01065224  0300                    add      eax, dword ptr [eax]           
  0x01065226  2000                    and      byte ptr [eax], al             
  0x01065228  0424                    add      al, 0x24                       
  0x0106522A  0500000024              add      eax, 0x24000000                
  0x0106522F  0000                    add      byte ptr [eax], al             
  0x01065231  7044                    jo       0x1065277                      
  0x01065233  006e0b                  add      byte ptr [esi + 0xb], ch       
  0x01065236  0000                    add      byte ptr [eax], al             
  0x01065238  0000                    add      byte ptr [eax], al             
  0x0106523A  3400                    xor      al, 0                          
  0x0106523C  1b00                    sbb      eax, dword ptr [eax]           
  0x0106523E  2000                    and      byte ptr [eax], al             
  0x01065240  00f0                    add      al, dh                         
  0x01065242  44                      inc      esp                            
  0x01065243  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x01065249  c406                    les      eax, ptr [esi]                 
  0x0106524B  0003                    add      byte ptr [ebx], al             
  0x0106524D  0000                    add      byte ptr [eax], al             
  0x0106524F  008841010088            add      byte ptr [eax - 0x77fffebf], cl 
  0x01065255  41                      inc      ecx                            
  0x01065256  0100                    add      dword ptr [eax], eax           
  0x01065258  884101                  mov      byte ptr [ecx + 1], al         
  0x0106525B  0000                    add      byte ptr [eax], al             
  0x0106525E  56                      push     esi                            
  0x0106525F  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x01065262  0000                    add      byte ptr [eax], al             
  0x01065264  0300                    add      eax, dword ptr [eax]           
  0x01065266  2000                    and      byte ptr [eax], al             
  0x01065268  02240500884101          add      ah, byte ptr [eax + 0x1418800] 
  0x0106526F  0000                    add      byte ptr [eax], al             
  0x01065272  56                      push     esi                            
  0x01065273  004a0b                  add      byte ptr [edx + 0xb], cl       
  0x01065276  0000                    add      byte ptr [eax], al             
  0x01065278  03f4                    add      esi, esp                       
  0x0106527A  44                      inc      esp                            
  0x0106527B  0008                    add      byte ptr [eax], cl             
  0x0106527D  0000                    add      byte ptr [eax], al             
  0x0106527F  0002                    add      byte ptr [edx], al             
  0x01065281  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01065282  0500480020              add      eax, 0x20004800                
  0x01065287  008841010000            add      byte ptr [eax + 0x141], cl     
  0x0106528E  56                      push     esi                            
  0x0106528F  00890b000003            add      byte ptr [ecx + 0x300000b], cl 
  0x01065295  0020                    add      byte ptr [eax], ah             
  0x01065297  0002                    add      byte ptr [edx], al             
  0x01065299  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106529A  0500884101              add      eax, 0x1418800                 
  0x0106529F  0000                    add      byte ptr [eax], al             
  0x010652A2  56                      push     esi                            
  0x010652A3  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x010652A6  0000                    add      byte ptr [eax], al             
  0x010652A8  854201                  test     dword ptr [edx + 1], eax       
  0x010652AB  0007                    add      byte ptr [edi], al             
  0x010652AD  2405                    and      al, 5                          
  0x010652AF  008841010000            add      byte ptr [eax + 0x141], cl     
  0x010652B6  56                      push     esi                            
  0x010652B7  00400b                  add      byte ptr [eax + 0xb], al       
  0x010652BA  0000                    add      byte ptr [eax], al             
  0x010652BC  03f4                    add      esi, esp                       
  0x010652BE  44                      inc      esp                            
  0x010652BF  000400                  add      byte ptr [eax + eax], al       
  0x010652C2  0000                    add      byte ptr [eax], al             
  0x010652C4  48                      dec      eax                            
  0x010652C5  2a20                    sub      ah, byte ptr [eax]             
  0x010652C7  0000                    add      byte ptr [eax], al             
  0x010652CA  44                      inc      esp                            
  0x010652CB  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x010652D1  c406                    les      eax, ptr [esi]                 
  0x010652D3  0002                    add      byte ptr [edx], al             
  0x010652D5  0000                    add      byte ptr [eax], al             
  0x010652D7  008842010000            add      byte ptr [eax + 0x142], cl     
  0x010652DE  56                      push     esi                            
  0x010652DF  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x010652E2  0000                    add      byte ptr [eax], al             
  0x010652E4  0300                    add      eax, dword ptr [eax]           
  0x010652E6  2000                    and      byte ptr [eax], al             
  0x010652E8  02a40500884101          add      ah, byte ptr [ebp + eax + 0x1418800] 
  0x010652EF  0000                    add      byte ptr [eax], al             
  0x010652F1  f4                      hlt                                     
  0x010652F2  56                      push     esi                            
  0x010652F3  008a0b000000            add      byte ptr [edx + 0xb], cl       
  0x010652F9  002400                  add      byte ptr [eax + eax], ah       
  0x010652FC  40                      inc      eax                            
  0x010652FD  0020                    add      byte ptr [eax], ah             
  0x010652FF  0000                    add      byte ptr [eax], al             
  0x01065301  90                      nop                                     
  0x01065302  2100                    and      dword ptr [eax], eax           
  0x01065304  00f0                    add      al, dh                         
  0x01065306  44                      inc      esp                            
  0x01065307  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x0106530D  c406                    les      eax, ptr [esi]                 
  0x0106530F  0006                    add      byte ptr [esi], al             
  0x01065311  0000                    add      byte ptr [eax], al             
  0x01065313  0000                    add      byte ptr [eax], al             
  0x01065315  d85600                  fcom     dword ptr [esi]                
  0x01065318  0300                    add      eax, dword ptr [eax]           
  0x0106531A  2000                    and      byte ptr [eax], al             
  0x0106531C  02a40500884601          add      ah, byte ptr [ebp + eax + 0x1468800] 
  0x01065323  0000                    add      byte ptr [eax], al             
  0x01065325  0000                    add      byte ptr [eax], al             
  0x01065327  0000                    add      byte ptr [eax], al             
  0x01065329  f4                      hlt                                     
  0x0106532A  60                      pushal                                  
  0x0106532B  008a0b000000            add      byte ptr [edx + 0xb], cl       
  0x01065331  f4                      hlt                                     
  0x01065332  61                      popal                                   
  0x01065333  00910b000000            add      byte ptr [ecx + 0xb], dl       
  0x01065339  f4                      hlt                                     
  0x0106533A  46                      inc      esi                            
  0x0106533B  0007                    add      byte ptr [edi], al             
  0x0106533D  0000                    add      byte ptr [eax], al             
  0x0106533F  0000                    add      byte ptr [eax], al             
  0x01065342  44                      inc      esp                            
  0x01065343  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x01065349  c406                    les      eax, ptr [esi]                 
  0x0106534B  000a                    add      byte ptr [edx], cl             
  0x0106534D  0000                    add      byte ptr [eax], al             
  0x0106534F  0000                    add      byte ptr [eax], al             
  0x01065351  d85600                  fcom     dword ptr [esi]                
  0x01065354  03d9                    add      ebx, ecx                       
  0x01065356  44                      inc      esp                            
  0x01065357  0006                    add      byte ptr [esi], al             
  0x01065359  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106535A  0500884401              add      eax, 0x1448800                 
  0x0106535F  00d0                    add      al, dl                         
  0x01065361  0020                    add      byte ptr [eax], ah             
  0x01065363  002e                    add      byte ptr [esi], ch             
  0x01065365  1d0c001800              sbb      eax, 0x18000c                  
  0x0106536A  2000                    and      byte ptr [eax], al             
  0x0106536C  884201                  mov      byte ptr [edx + 1], al         
  0x0106536F  0000                    add      byte ptr [eax], al             
  0x01065371  0000                    add      byte ptr [eax], al             
  0x01065373  0000                    add      byte ptr [eax], al             
  0x01065376  56                      push     esi                            
  0x01065377  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x0106537A  0000                    add      byte ptr [eax], al             
  0x0106537C  0300                    add      eax, dword ptr [eax]           
  0x0106537E  2000                    and      byte ptr [eax], al             
  0x01065380  08a4050000f056          or       byte ptr [ebp + eax + 0x56f00000], ah 
  0x01065387  008f0b000003            add      byte ptr [edi + 0x300000b], cl 
  0x0106538D  f4                      hlt                                     
  0x0106538E  44                      inc      esp                            
  0x0106538F  000e                    add      byte ptr [esi], cl             
  0x01065391  0000                    add      byte ptr [eax], al             
  0x01065393  0003                    add      byte ptr [ebx], al             
  0x01065395  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01065396  0500884401              add      eax, 0x1448800                 
  0x0106539B  004800                  add      byte ptr [eax], cl             
  0x0106539E  2000                    and      byte ptr [eax], al             
  0x010653A0  884101                  mov      byte ptr [ecx + 1], al         
  0x010653A3  0000                    add      byte ptr [eax], al             
  0x010653A6  56                      push     esi                            
  0x010653A7  00900b000003            add      byte ptr [eax + 0x300000b], dl 
  0x010653AD  0020                    add      byte ptr [eax], ah             
  0x010653AF  0006                    add      byte ptr [esi], al             
  0x010653B1  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010653B2  0500884201              add      eax, 0x1428800                 
  0x010653B7  008842010088            add      byte ptr [eax - 0x77fffebe], cl 
  0x010653BD  42                      inc      edx                            
  0x010653BE  0100                    add      dword ptr [eax], eax           
  0x010653C0  884201                  mov      byte ptr [edx + 1], al         
  0x010653C3  008843010088            add      byte ptr [eax - 0x77fffebd], cl 
  0x010653C9  41                      inc      ecx                            
  0x010653CA  0100                    add      dword ptr [eax], eax           
  0x010653CC  00f0                    add      al, dh                         
  0x010653CE  56                      push     esi                            
  0x010653CF  006f0b                  add      byte ptr [edi + 0xb], ch       
  0x010653D2  0000                    add      byte ptr [eax], al             
  0x010653D4  0300                    add      eax, dword ptr [eax]           
  0x010653D6  2000                    and      byte ptr [eax], al             
  0x010653D8  0e                      push     cs                             
  0x010653D9  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010653DA  0500884601              add      eax, 0x1468800                 
  0x010653DF  0000                    add      byte ptr [eax], al             
  0x010653E2  44                      inc      esp                            
  0x010653E3  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x010653E9  c406                    les      eax, ptr [esi]                 
  0x010653EB  0003                    add      byte ptr [ebx], al             
  0x010653ED  0000                    add      byte ptr [eax], al             
  0x010653EF  008844010088            add      byte ptr [eax - 0x77fffebc], cl 
  0x010653F5  43                      inc      ebx                            
  0x010653F6  0100                    add      dword ptr [eax], eax           
  0x010653F8  00f0                    add      al, dh                         
  0x010653FA  56                      push     esi                            
  0x010653FB  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x010653FE  0000                    add      byte ptr [eax], al             
  0x01065400  0300                    add      eax, dword ptr [eax]           
  0x01065402  2000                    and      byte ptr [eax], al             
  0x01065404  03a40500884401          add      esp, dword ptr [ebp + eax + 0x1448800] 
  0x0106540B  008843010088            add      byte ptr [eax - 0x77fffebd], cl 
  0x01065411  41                      inc      ecx                            
  0x01065412  0100                    add      dword ptr [eax], eax           
  0x01065414  884101                  mov      byte ptr [ecx + 1], al         
  0x01065417  001b                    add      byte ptr [ebx], bl             
  0x01065419  e721                    out      0x21, eax                      
  0x0106541B  0000                    add      byte ptr [eax], al             
  0x0106541E  56                      push     esi                            
  0x0106541F  00400b                  add      byte ptr [eax + 0xb], al       
  0x01065422  0000                    add      byte ptr [eax], al             
  0x01065424  c54001                  lds      eax, ptr [eax + 1]             
  0x01065427  0003                    add      byte ptr [ebx], al             
  0x01065429  0000                    add      byte ptr [eax], al             
  0x0106542B  004210                  add      byte ptr [edx + 0x10], al      
  0x0106542E  0d000d0000              or       eax, 0xd00                     
  0x01065433  0079e7                  add      byte ptr [ecx - 0x19], bh      
  0x01065436  2100                    and      dword ptr [eax], eax           
  0x01065438  884901                  mov      byte ptr [ecx + 1], cl         
  0x0106543B  0079e7                  add      byte ptr [ecx - 0x19], bh      
  0x0106543E  2100                    and      dword ptr [eax], eax           
  0x01065440  884101                  mov      byte ptr [ecx + 1], al         
  0x01065443  008841010000            add      byte ptr [eax + 0x141], cl     
  0x0106544A  56                      push     esi                            
  0x0106544B  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106544E  0000                    add      byte ptr [eax], al             
  0x01065450  c54001                  lds      eax, ptr [eax + 1]             
  0x01065453  0003                    add      byte ptr [ebx], al             
  0x01065455  0000                    add      byte ptr [eax], al             
  0x01065457  0002                    add      byte ptr [edx], al             
  0x01065459  2405                    and      al, 5                          
  0x0106545B  00886f010088            add      byte ptr [eax - 0x77fffe91], cl 
  0x01065461  47                      inc      edi                            
  0x01065462  0100                    add      dword ptr [eax], eax           
  0x01065465  1e                      push     ds                             
  0x01065466  0c00                    or       al, 0                          
  0x01065468  007055                  add      byte ptr [eax + 0x55], dh      
  0x0106546B  00700b                  add      byte ptr [eax + 0xb], dh       
  0x0106546E  0000                    add      byte ptr [eax], al             
  0x01065470  871e                    xchg     dword ptr [esi], ebx           
  0x01065472  0c00                    or       al, 0                          
  0x01065474  79e4                    jns      0x106545a                      
  0x01065476  2100                    and      dword ptr [eax], eax           
  0x01065478  48                      dec      eax                            
  0x01065479  0020                    add      byte ptr [eax], ah             
  0x0106547B  0000                    add      byte ptr [eax], al             
  0x0106547D  7055                    jo       0x10654d4                      
  0x0106547F  00710b                  add      byte ptr [ecx + 0xb], dh       
  0x01065482  0000                    add      byte ptr [eax], al             
  0x01065484  00f0                    add      al, dh                         
  0x01065486  56                      push     esi                            
  0x01065487  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106548A  0000                    add      byte ptr [eax], al             
  0x0106548C  0300                    add      eax, dword ptr [eax]           
  0x0106548E  2000                    and      byte ptr [eax], al             
  0x01065490  07                      pop      es                             
  0x01065491  2405                    and      al, 5                          
  0x01065493  001b                    add      byte ptr [ebx], bl             
  0x01065495  0020                    add      byte ptr [eax], ah             
  0x01065497  008841010088            add      byte ptr [eax - 0x77fffebf], cl 
  0x0106549D  41                      inc      ecx                            
  0x0106549E  0100                    add      dword ptr [eax], eax           
  0x010654A0  885001                  mov      byte ptr [eax + 1], dl         
  0x010654A3  0000                    add      byte ptr [eax], al             
  0x010654A5  7055                    jo       0x10654fc                      
  0x010654A7  00530b                  add      byte ptr [ebx + 0xb], dl       
  0x010654AA  0000                    add      byte ptr [eax], al             
  0x010654AC  00f0                    add      al, dh                         
  0x010654AE  56                      push     esi                            
  0x010654AF  00400b                  add      byte ptr [eax + 0xb], al       
  0x010654B2  0000                    add      byte ptr [eax], al             
  0x010654B4  0300                    add      eax, dword ptr [eax]           
  0x010654B6  2000                    and      byte ptr [eax], al             
  0x010654B8  8c24050000f057          mov      word ptr [eax + 0x57f00000], fs 
  0x010654BF  00510b                  add      byte ptr [ecx + 0xb], dl       
  0x010654C2  0000                    add      byte ptr [eax], al             
  0x010654C4  00f0                    add      al, dh                         
  0x010654C6  44                      inc      esp                            
  0x010654C7  00530b                  add      byte ptr [ebx + 0xb], dl       
  0x010654CA  0000                    add      byte ptr [eax], al             
  0x010654CC  48                      dec      eax                            
  0x010654CD  0020                    add      byte ptr [eax], ah             
  0x010654CF  0000                    add      byte ptr [eax], al             
  0x010654D2  44                      inc      esp                            
  0x010654D3  009a0b000000            add      byte ptr [edx + 0xb], bl       
  0x010654D9  f4                      hlt                                     
  0x010654DA  46                      inc      esi                            
  0x010654DB  0008                    add      byte ptr [eax], cl             
  0x010654DD  0000                    add      byte ptr [eax], al             
  0x010654DF  00d0                    add      al, dl                         
  0x010654E1  0020                    add      byte ptr [eax], ah             
  0x010654E3  0000                    add      byte ptr [eax], al             
  0x010654E5  0e                      push     cs                             
  0x010654E6  2100                    and      dword ptr [eax], eax           
  0x010654E8  1400                    adc      al, 0                          
  0x010654EA  2000                    and      byte ptr [eax], al             
  0x010654EC  007054                  add      byte ptr [eax + 0x54], dh      
  0x010654EF  00520b                  add      byte ptr [edx + 0xb], dl       
  0x010654F2  0000                    add      byte ptr [eax], al             
  0x010654F4  00f0                    add      al, dh                         
  0x010654F6  56                      push     esi                            
  0x010654F7  00530b                  add      byte ptr [ebx + 0xb], dl       
  0x010654FA  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x010654A5 (cond_jump)
  0x010654FC  00f0                    add      al, dh                         
  0x010654FE  44                      inc      esp                            
  0x010654FF  009f0b000045            add      byte ptr [edi + 0x4500000b], bl 
  0x01065505  0020                    add      byte ptr [eax], ah             
  0x01065507  00857405001b            add      byte ptr [ebp + 0x1b000574], al 
  0x0106550D  f4                      hlt                                     
  0x0106550E  44                      inc      esp                            
  0x0106550F  005555                  add      byte ptr [ebp + 0x55], dl      
  0x01065512  150000f056              adc      eax, 0x56f00000                
  0x01065517  00520b                  add      byte ptr [edx + 0xb], dl       
  0x0106551A  0000                    add      byte ptr [eax], al             
  0x0106551C  c44001                  les      eax, ptr [eax + 1]             
  0x0106551F  002f                    add      byte ptr [edi], ch             
  0x01065521  0000                    add      byte ptr [eax], al             
  0x01065523  0000                    add      byte ptr [eax], al             
  0x01065525  8521                    test     dword ptr [ecx], esp           
  0x01065527  00a800200000            add      byte ptr [eax + 0x2000], ch    
  0x0106552D  af                      scasd    eax, dword ptr es:[edi]        
  0x0106552E  2100                    and      dword ptr [eax], eax           
  0x01065530  00f0                    add      al, dh                         
  0x01065532  44                      inc      esp                            
  0x01065533  00710b                  add      byte ptr [ecx + 0xb], dh       
  0x01065536  0000                    add      byte ptr [eax], al             
  0x01065538  4d                      dec      ebp                            
  0x01065539  0020                    add      byte ptr [eax], ah             
  0x0106553B  0058f4                  add      byte ptr [eax - 0xc], bl       
  0x0106553E  050000a521              add      eax, 0x21a50000                
  0x01065543  0000                    add      byte ptr [eax], al             
  0x01065545  f4                      hlt                                     
  0x01065546  44                      inc      esp                            
  0x01065547  0006                    add      byte ptr [esi], al             
  0x01065549  0000                    add      byte ptr [eax], al             
  0x0106554B  00a00020002e            add      byte ptr [eax + 0x2e002000], ah 
  0x01065551  1d0c0036f0              sbb      eax, 0xf036000c                
  0x01065556  44                      inc      esp                            
  0x01065557  00520b                  add      byte ptr [edx + 0xb], dl       
  0x0106555A  0000                    add      byte ptr [eax], al             
  0x0106555C  40                      inc      eax                            
  0x0106555D  0020                    add      byte ptr [eax], ah             
  0x0106555F  00c4                    add      ah, al                         
  0x01065561  40                      inc      eax                            
  0x01065562  0100                    add      dword ptr [eax], eax           
  0x01065564  2f                      das                                     
  0x01065565  0000                    add      byte ptr [eax], al             
  0x01065567  0000                    add      byte ptr [eax], al             
  0x0106556A  2100                    and      dword ptr [eax], eax           
  0x0106556C  c8400100                enter    0x140, 0                       
  0x01065570  0100                    add      dword ptr [eax], eax           
  0x01065572  0000                    add      byte ptr [eax], al             
  0x01065574  00f4                    add      ah, dh                         
  0x01065576  56                      push     esi                            
  0x01065577  00680b                  add      byte ptr [eax + 0xb], ch       
  0x0106557A  0000                    add      byte ptr [eax], al             
  0x0106557C  0000                    add      byte ptr [eax], al             
  0x0106557E  2400                    and      al, 0                          
  0x01065580  40                      inc      eax                            
  0x01065581  0020                    add      byte ptr [eax], ah             
  0x01065583  0000                    add      byte ptr [eax], al             
  0x01065585  90                      nop                                     
  0x01065586  2100                    and      dword ptr [eax], eax           
  0x01065588  00f8                    add      al, bh                         
  0x0106558A  2000                    and      byte ptr [eax], al             
  0x0106558C  10d8                    adc      al, bl                         
  0x0106558E  06                      push     es                             
  0x0106558F  0002                    add      byte ptr [edx], al             
  0x01065591  0000                    add      byte ptr [eax], al             
  0x01065593  0000                    add      byte ptr [eax], al             
  0x01065595  58                      pop      eax                            
  0x01065596  57                      push     edi                            
  0x01065597  00cc                    add      ah, cl                         
  0x01065599  40                      inc      eax                            
  0x0106559A  0100                    add      dword ptr [eax], eax           
  0x0106559C  0100                    add      dword ptr [eax], eax           
  0x0106559E  0000                    add      byte ptr [eax], al             
  0x010655A0  00f4                    add      ah, dh                         
  0x010655A2  56                      push     esi                            
  0x010655A3  0006                    add      byte ptr [esi], al             
  0x010655A5  0000                    add      byte ptr [eax], al             
  0x010655A7  00740020                add      byte ptr [eax + eax + 0x20], dh 
  0x010655AB  0003                    add      byte ptr [ebx], al             
  0x010655AD  0020                    add      byte ptr [eax], ah             
  0x010655AF  0005f4050000            add      byte ptr [0x5f4], al           
  0x010655B5  d821                    fsub     dword ptr [ecx]                
  0x010655B7  0010                    add      byte ptr [eax], dl             
  0x010655B9  d806                    fadd     dword ptr [esi]                
  0x010655BB  0002                    add      byte ptr [edx], al             
  0x010655BD  0000                    add      byte ptr [eax], al             
  0x010655BF  0000                    add      byte ptr [eax], al             
  0x010655C1  58                      pop      eax                            
  0x010655C2  57                      push     edi                            
  0x010655C3  0000                    add      byte ptr [eax], al             
  0x010655C5  f4                      hlt                                     
  0x010655C6  56                      push     esi                            
  0x010655C7  00680b                  add      byte ptr [eax + 0xb], ch       
  0x010655CA  0000                    add      byte ptr [eax], al             
  0x010655CC  00f4                    add      ah, dh                         
  0x010655CE  44                      inc      esp                            
  0x010655CF  0003                    add      byte ptr [ebx], al             
  0x010655D1  0000                    add      byte ptr [eax], al             
  0x010655D3  004000                  add      byte ptr [eax], al             
  0x010655D6  2000                    and      byte ptr [eax], al             
  0x010655D8  0090210000e0            add      byte ptr [eax - 0x1fffffdf], dl 
  0x010655DE  56                      push     esi                            
  0x010655DF  00806f010000            add      byte ptr [eax + 0x16f], al     
  0x010655E5  60                      pushal                                  
  0x010655E6  56                      push     esi                            
  0x010655E7  0000                    add      byte ptr [eax], al             
  0x010655E9  f4                      hlt                                     
  0x010655EA  56                      push     esi                            
  0x010655EB  00680b                  add      byte ptr [eax + 0xb], ch       
  0x010655EE  0000                    add      byte ptr [eax], al             
  0x010655F0  0000                    add      byte ptr [eax], al             
  0x010655F2  2400                    and      al, 0                          
  0x010655F4  40                      inc      eax                            
  0x010655F5  0020                    add      byte ptr [eax], ah             
  0x010655F7  0000                    add      byte ptr [eax], al             
  0x010655F9  90                      nop                                     
  0x010655FA  2100                    and      dword ptr [eax], eax           
  0x010655FC  00f0                    add      al, dh                         
  0x010655FE  7000                    jo       0x1065600                      
                                        ; XREF: 0x010655FE (cond_jump)
  0x01065600  40                      inc      eax                            
  0x01065601  0b00                    or       eax, dword ptr [eax]           
  0x01065603  0000                    add      byte ptr [eax], al             
  0x01065605  e8560000f0              call     0xf1065660                     
  0x0106560A  44                      inc      esp                            
  0x0106560B  00710b                  add      byte ptr [ecx + 0xb], dh       
  0x0106560E  0000                    add      byte ptr [eax], al             
  0x01065610  44                      inc      esp                            
  0x01065611  0020                    add      byte ptr [eax], ah             
  0x01065613  0000                    add      byte ptr [eax], al             
  0x01065615  6856000c00              push     0xc0056                        
  0x0106561A  0000                    add      byte ptr [eax], al             
  0x0106561C  00f4                    add      ah, dh                         
  0x0106561E  44                      inc      esp                            
  0x0106561F  0001                    add      byte ptr [ecx], al             
  0x01065621  0000                    add      byte ptr [eax], al             
  0x01065623  0000                    add      byte ptr [eax], al             
  0x01065625  7044                    jo       0x106566b                      
  0x01065627  00960b00000c            add      byte ptr [esi + 0xc00000b], dl 
  0x0106562D  0000                    add      byte ptr [eax], al             
  0x0106562F  0080100d0023            add      byte ptr [eax + 0x23000d10], al 
  0x01065635  0000                    add      byte ptr [eax], al             
  0x01065637  0003                    add      byte ptr [ebx], al             
  0x01065639  0020                    add      byte ptr [eax], ah             
  0x0106563B  001b                    add      byte ptr [ebx], bl             
  0x0106563D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106563E  050080100d              add      eax, 0xd108000                 
  0x01065643  00a2fdff0000            add      byte ptr [edx + 0xfffd], ah    
  0x01065649  f4                      hlt                                     
  0x0106564A  56                      push     esi                            
  0x0106564B  000500000000            add      byte ptr [0], al               
  0x01065652  44                      inc      esp                            
  0x01065653  00400b                  add      byte ptr [eax + 0xb], al       
  0x01065656  0000                    add      byte ptr [eax], al             
  0x01065658  45                      inc      ebp                            
  0x01065659  0020                    add      byte ptr [eax], ah             
  0x0106565B  0017                    add      byte ptr [edi], dl             
  0x0106565D  f4                      hlt                                     
  0x0106565E  050000f456              add      eax, 0x56f40000                
  0x01065663  00680b                  add      byte ptr [eax + 0xb], ch       
  0x01065666  0000                    add      byte ptr [eax], al             
  0x01065668  00f0                    add      al, dh                         
  0x0106566A  44                      inc      esp                            
                                        ; XREF: 0x01065625 (cond_jump)
  0x0106566B  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106566E  0000                    add      byte ptr [eax], al             
  0x01065670  40                      inc      eax                            
  0x01065671  0020                    add      byte ptr [eax], ah             
  0x01065673  00c0                    add      al, al                         
  0x01065675  40                      inc      eax                            
  0x01065676  0100                    add      dword ptr [eax], eax           
  0x01065678  0100                    add      dword ptr [eax], eax           
  0x0106567A  0000                    add      byte ptr [eax], al             
  0x0106567C  00d0                    add      al, dl                         
  0x0106567E  2100                    and      dword ptr [eax], eax           
  0x01065680  00d0                    add      al, dl                         
  0x01065682  56                      push     esi                            
  0x01065683  0000                    add      byte ptr [eax], al             
  0x01065685  d8440040                fadd     dword ptr [eax + eax + 0x40]   
  0x01065689  0020                    add      byte ptr [eax], ah             
  0x0106568B  0000                    add      byte ptr [eax], al             
  0x0106568E  44                      inc      esp                            
  0x0106568F  007a0b                  add      byte ptr [edx + 0xb], bh       
  0x01065692  0000                    add      byte ptr [eax], al             
  0x01065694  44                      inc      esp                            
  0x01065696  45                      inc      ebp                            
  0x01065697  00a40400006400          add      byte ptr [esp + eax + 0x640000], ah 
  0x0106569E  2000                    and      byte ptr [eax], al             
  0x010656A0  006056                  add      byte ptr [eax + 0x56], ah      
  0x010656A3  00050c050080            add      byte ptr [0x8000050c], al      
  0x010656A9  100d00580100            adc      byte ptr [0x15800], cl         
  0x010656AF  0080100d0086            add      byte ptr [eax - 0x79fff2f0], al 
  0x010656B5  fd                      std                                     
  0x010656B6  ff00                    inc      dword ptr [eax]                
  0x010656B8  0c00                    or       al, 0                          
  0x010656BA  0000                    add      byte ptr [eax], al             
  0x010656BC  00f4                    add      ah, dh                         
  0x010656BE  45                      inc      ebp                            
  0x010656BF  0090ffff0000            add      byte ptr [eax + 0xffff], dl    
  0x010656C5  7045                    jo       0x106570c                      
  0x010656C7  009f04000080            add      byte ptr [edi - 0x7ffffffc], bl 
  0x010656CD  100d007c0000            adc      byte ptr [0x7c00], cl          
  0x010656D3  0000                    add      byte ptr [eax], al             
  0x010656D5  f4                      hlt                                     
  0x010656D6  44                      inc      esp                            
  0x010656D7  0008                    add      byte ptr [eax], cl             
  0x010656D9  0000                    add      byte ptr [eax], al             
  0x010656DB  0000                    add      byte ptr [eax], al             
  0x010656DD  7044                    jo       0x1065723                      
  0x010656DF  009e04000000            add      byte ptr [esi + 4], bl         
  0x010656E5  002400                  add      byte ptr [eax + eax], ah       
  0x010656E8  007044                  add      byte ptr [eax + 0x44], dh      
  0x010656EB  00b504000000            add      byte ptr [ebp + 4], dh         
  0x010656F2  50                      push     eax                            
  0x010656F3  009e0400000a            add      byte ptr [esi + 0xa000004], bl 
  0x010656F9  0000                    add      byte ptr [eax], al             
  0x010656FB  0000                    add      byte ptr [eax], al             
  0x010656FD  7050                    jo       0x106574f                      
  0x010656FF  009e04000080            add      byte ptr [esi - 0x7ffffffc], bl 
  0x01065705  100d00870000            adc      byte ptr [0x8700], cl          
  0x0106570B  000b                    add      byte ptr [ebx], cl             
  0x0106570D  0020                    add      byte ptr [eax], ah             
  0x0106570F  0009                    add      byte ptr [ecx], cl             
  0x01065711  94                      xchg     esp, eax                       
  0x01065712  050000f444              add      eax, 0x44f40000                
  0x01065717  0001                    add      byte ptr [ecx], al             
  0x01065719  0000                    add      byte ptr [eax], al             
  0x0106571B  0000                    add      byte ptr [eax], al             
  0x0106571D  7044                    jo       0x1065763                      
  0x0106571F  00b504000000            add      byte ptr [ebp + 4], dh         
  0x01065726  44                      inc      esp                            
  0x01065727  009f04000000            add      byte ptr [edi + 4], bl         
  0x0106572D  7044                    jo       0x1065773                      
  0x0106572F  00b604000000            add      byte ptr [esi + 4], dh         
  0x01065736  56                      push     esi                            
  0x01065737  00b504000003            add      byte ptr [ebp + 0x3000004], dh 
  0x0106573D  0020                    add      byte ptr [eax], ah             
  0x0106573F  000f                    add      byte ptr [edi], cl             
  0x01065741  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01065742  050000f456              add      eax, 0x56f40000                
  0x01065747  0010                    add      byte ptr [eax], dl             
  0x01065749  0000                    add      byte ptr [eax], al             
  0x0106574B  0000                    add      byte ptr [eax], al             
  0x0106574D  c421                    les      esp, ptr [ecx]                 
                                        ; XREF: 0x010656FD (cond_jump)
  0x0106574F  0000                    add      byte ptr [eax], al             
  0x01065751  7056                    jo       0x10657a9                      
  0x01065753  00a004000000            add      byte ptr [eax + 4], ah         
  0x0106575A  56                      push     esi                            
  0x0106575B  009f04000000            add      byte ptr [edi + 4], bl         
  0x01065761  7056                    jo       0x10657b9                      
                                        ; XREF: 0x0106571D (cond_jump)
  0x01065763  00a104000040            add      byte ptr [ecx + 0x40000004], ah 
  0x01065769  0020                    add      byte ptr [eax], ah             
  0x0106576B  0022                    add      byte ptr [edx], ah             
  0x0106576D  0020                    add      byte ptr [eax], ah             
  0x0106576F  0000                    add      byte ptr [eax], al             
  0x01065771  7056                    jo       0x10657c9                      
                                        ; XREF: 0x0106572D (cond_jump)
  0x01065773  009f0400000e            add      byte ptr [edi + 0xe000004], bl 
  0x01065779  0c05                    or       al, 5                          
  0x0106577B  0000                    add      byte ptr [eax], al             
  0x0106577D  f4                      hlt                                     
  0x0106577E  56                      push     esi                            
  0x0106577F  0010                    add      byte ptr [eax], dl             
  0x01065782  ff00                    inc      dword ptr [eax]                
  0x01065784  00c4                    add      ah, al                         
  0x01065786  2100                    and      dword ptr [eax], eax           
  0x01065788  007056                  add      byte ptr [eax + 0x56], dh      
  0x0106578B  00a104000000            add      byte ptr [ecx + 4], ah         
  0x01065792  56                      push     esi                            
  0x01065793  009f04000000            add      byte ptr [edi + 4], bl         
  0x01065799  7056                    jo       0x10657f1                      
  0x0106579B  00a004000040            add      byte ptr [eax + 0x40000004], ah 
  0x010657A1  0020                    add      byte ptr [eax], ah             
  0x010657A3  0022                    add      byte ptr [edx], ah             
  0x010657A5  0020                    add      byte ptr [eax], ah             
  0x010657A7  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01065751 (cond_jump)
  0x010657A9  7056                    jo       0x1065801                      
  0x010657AB  009f04000080            add      byte ptr [edi - 0x7ffffffc], bl 
  0x010657B1  100d00430000            adc      byte ptr [0x4300], cl          
  0x010657B7  0080100d005a            add      byte ptr [eax + 0x5a000d10], al 
  0x010657BD  0000                    add      byte ptr [eax], al             
  0x010657BF  000b                    add      byte ptr [ebx], cl             
  0x010657C1  0020                    add      byte ptr [eax], ah             
  0x010657C3  000e                    add      byte ptr [esi], cl             
  0x010657C5  94                      xchg     esp, eax                       
  0x010657C6  050000f044              add      eax, 0x44f00000                
  0x010657CB  009f04000000            add      byte ptr [edi + 4], bl         
  0x010657D1  7044                    jo       0x1065817                      
  0x010657D3  00a104000000            add      byte ptr [ecx + 4], ah         
  0x010657D9  f4                      hlt                                     
  0x010657DA  44                      inc      esp                            
  0x010657DB  0001                    add      byte ptr [ecx], al             
  0x010657DD  0000                    add      byte ptr [eax], al             
  0x010657DF  0000                    add      byte ptr [eax], al             
  0x010657E1  7044                    jo       0x1065827                      
  0x010657E3  00b504000000            add      byte ptr [ebp + 4], dh         
  0x010657EA  44                      inc      esp                            
  0x010657EB  009f04000000            add      byte ptr [edi + 4], bl         
                                        ; XREF: 0x01065799 (cond_jump)
  0x010657F1  7044                    jo       0x1065837                      
  0x010657F3  00b604000005            add      byte ptr [esi + 0x5000004], dh 
  0x010657F9  0c05                    or       al, 5                          
  0x010657FB  0000                    add      byte ptr [eax], al             
  0x010657FE  44                      inc      esp                            
  0x010657FF  009f04000000            add      byte ptr [edi + 4], bl         
  0x01065805  7044                    jo       0x106584b                      
  0x01065807  00a004000000            add      byte ptr [eax + 4], ah         
  0x0106580E  56                      push     esi                            
  0x0106580F  00a004000000            add      byte ptr [eax + 4], ah         
  0x01065816  44                      inc      esp                            
                                        ; XREF: 0x010657D1 (cond_jump)
  0x01065817  00a104000044            add      byte ptr [ecx + 0x44000004], ah 
  0x0106581E  2100                    and      dword ptr [eax], eax           
  0x01065820  c54001                  lds      eax, ptr [eax + 1]             
  0x01065823  0001                    add      byte ptr [ecx], al             
  0x01065825  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x010657E1 (cond_jump)
  0x01065827  0008                    add      byte ptr [eax], cl             
  0x01065829  2405                    and      al, 5                          
  0x0106582B  0080100d0028            add      byte ptr [eax + 0x28000d10], al 
  0x01065831  0100                    add      dword ptr [eax], eax           
  0x01065833  0000                    add      byte ptr [eax], al             
  0x01065835  f4                      hlt                                     
  0x01065836  44                      inc      esp                            
                                        ; XREF: 0x010657F1 (cond_jump)
  0x01065837  0001                    add      byte ptr [ecx], al             
  0x01065839  0000                    add      byte ptr [eax], al             
  0x0106583B  0000                    add      byte ptr [eax], al             
  0x0106583D  7044                    jo       0x1065883                      
  0x0106583F  00b50400001b            add      byte ptr [ebp + 0x1b000004], dh 
  0x01065845  0c05                    or       al, 5                          
  0x01065847  005100                  add      byte ptr [ecx], dl             
  0x0106584A  2000                    and      byte ptr [eax], al             
  0x0106584C  40                      inc      eax                            
  0x0106584D  0020                    add      byte ptr [eax], ah             
  0x0106584F  0022                    add      byte ptr [edx], ah             
  0x01065851  0020                    add      byte ptr [eax], ah             
  0x01065853  004500                  add      byte ptr [ebp], al             
  0x01065856  2000                    and      byte ptr [eax], al             
  0x01065858  0474                    add      al, 0x74                       
  0x0106585A  0500008e20              add      eax, 0x208e0000                
  0x0106585F  008041010005            add      byte ptr [eax + 0x5000141], al 
  0x01065865  0c05                    or       al, 5                          
  0x01065867  005500                  add      byte ptr [ebp], dl             
  0x0106586A  2000                    and      byte ptr [eax], al             
  0x0106586C  0394050000ce20          add      edx, dword ptr [ebp + eax + 0x20ce0000] 
  0x01065873  00844101000070          add      byte ptr [ecx + eax*2 + 0x70000001], al 
  0x0106587A  54                      push     esp                            
  0x0106587B  009f04000000            add      byte ptr [edi + 4], bl         
  0x01065882  56                      push     esi                            
                                        ; XREF: 0x0106583D (cond_jump)
  0x01065883  009e04000084            add      byte ptr [esi - 0x7bfffffc], bl 
  0x01065889  41                      inc      ecx                            
  0x0106588A  0100                    add      dword ptr [eax], eax           
  0x0106588C  007054                  add      byte ptr [eax + 0x54], dh      
  0x0106588F  009e04000087            add      byte ptr [esi - 0x78fffffc], bl 
  0x01065895  7705                    ja       0x106589c                      
  0x01065897  0000                    add      byte ptr [eax], al             
  0x0106589A  56                      push     esi                            
  0x0106589B  00b504000085            add      byte ptr [ebp - 0x7afffffc], dh 
  0x010658A1  41                      inc      ecx                            
  0x010658A2  0100                    add      dword ptr [eax], eax           
  0x010658A4  0324050080100d          add      esp, dword ptr [eax + 0xd108000] 
  0x010658AB  0009                    add      byte ptr [ecx], cl             
  0x010658AD  0100                    add      dword ptr [eax], eax           
  0x010658AF  0000                    add      byte ptr [eax], al             
  0x010658B2  56                      push     esi                            
  0x010658B3  00b50400000c            add      byte ptr [ebp + 0xc000004], dh 
  0x010658B9  0000                    add      byte ptr [eax], al             
  0x010658BB  0000                    add      byte ptr [eax], al             
  0x010658BE  56                      push     esi                            
  0x010658BF  009f040000c0            add      byte ptr [edi - 0x3ffffffc], bl 
  0x010658C5  40                      inc      eax                            
  0x010658C6  0100                    add      dword ptr [eax], eax           
  0x010658C8  f00000                  lock add byte ptr [eax], al             
  0x010658CB  0008                    add      byte ptr [eax], cl             
  0x010658CD  1c0c                    sbb      al, 0xc                        
  0x010658CF  0000                    add      byte ptr [eax], al             
  0x010658D1  8421                    test     byte ptr [ecx], ah             
  0x010658D3  0000                    add      byte ptr [eax], al             
  0x010658D5  002c00                  add      byte ptr [eax + eax], ch       
  0x010658D8  081d0c000086            or       byte ptr [0x8600000c], bl      
  0x010658DE  2100                    and      dword ptr [eax], eax           
  0x010658E0  00f4                    add      ah, dh                         
  0x010658E2  60                      pushal                                  
  0x010658E3  00730b                  add      byte ptr [ebx + 0xb], dh       
  0x010658E6  0000                    add      byte ptr [eax], al             
  0x010658E8  00f4                    add      ah, dh                         
  0x010658EA  6200                    bound    eax, qword ptr [eax]           
  0x010658EC  790b                    jns      0x10658f9                      
  0x010658EE  0000                    add      byte ptr [eax], al             
  0x010658F0  00f4                    add      ah, dh                         
  0x010658F2  6400740b00              add      byte ptr fs:[ebx + ecx], dh    
  0x010658F7  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x010658EC (cond_jump)
  0x010658F9  053c0000f0              add      eax, 0xf000003c                
  0x010658FE  7000                    jo       0x1065900                      
                                        ; XREF: 0x010658FE (cond_jump)
  0x01065900  97                      xchg     edi, eax                       
  0x01065901  0b00                    or       eax, dword ptr [eax]           
  0x01065903  0000                    add      byte ptr [eax], al             
  0x01065905  95                      xchg     ebp, eax                       
  0x01065906  2200                    and      al, byte ptr [eax]             
  0x01065908  005844                  add      byte ptr [eax + 0x44], bl      
  0x0106590B  0000                    add      byte ptr [eax], al             
  0x0106590D  5a                      pop      edx                            
  0x0106590E  46                      inc      esi                            
  0x0106590F  0010                    add      byte ptr [eax], dl             
  0x01065911  d806                    fadd     dword ptr [esi]                
  0x01065913  0002                    add      byte ptr [edx], al             
  0x01065915  0000                    add      byte ptr [eax], al             
  0x01065917  0000                    add      byte ptr [eax], al             
  0x01065919  5d                      pop      ebp                            
  0x0106591A  46                      inc      esi                            
  0x0106591B  000c00                  add      byte ptr [eax + eax], cl       
  0x0106591E  0000                    add      byte ptr [eax], al             
  0x01065920  00f0                    add      al, dh                         
  0x01065922  7000                    jo       0x1065924                      
                                        ; XREF: 0x01065922 (cond_jump)
  0x01065924  40                      inc      eax                            
  0x01065925  0b00                    or       eax, dword ptr [eax]           
  0x01065927  0000                    add      byte ptr [eax], al             
  0x01065929  f4                      hlt                                     
  0x0106592A  60                      pushal                                  
  0x0106592B  00680b                  add      byte ptr [eax + 0xb], ch       
  0x0106592E  0000                    add      byte ptr [eax], al             
  0x01065930  00e8                    add      al, ch                         
  0x01065932  57                      push     edi                            
  0x01065933  0000                    add      byte ptr [eax], al             
  0x01065935  fa                      cli                                     
  0x01065936  2100                    and      dword ptr [eax], eax           
  0x01065938  00f0                    add      al, dh                         
  0x0106593A  56                      push     esi                            
  0x0106593B  00c0                    add      al, al                         
  0x0106593D  0400                    add      al, 0                          
  0x0106593F  0003                    add      byte ptr [ebx], al             
  0x01065941  0020                    add      byte ptr [eax], ah             
  0x01065943  0045a5                  add      byte ptr [ebp - 0x5b], al      
  0x01065946  050000f456              add      eax, 0x56f40000                
  0x0106594B  0001                    add      byte ptr [ecx], al             
  0x0106594D  0000                    add      byte ptr [eax], al             
  0x0106594F  0000                    add      byte ptr [eax], al             
  0x01065951  7056                    jo       0x10659a9                      
  0x01065953  00b704000000            add      byte ptr [edi + 4], dh         
  0x01065959  f4                      hlt                                     
  0x0106595A  56                      push     esi                            
  0x0106595B  0000                    add      byte ptr [eax], al             
  0x0106595D  0000                    add      byte ptr [eax], al             
  0x0106595F  0000                    add      byte ptr [eax], al             
  0x01065962  44                      inc      esp                            
  0x01065963  00730b                  add      byte ptr [ebx + 0xb], dh       
  0x01065966  0000                    add      byte ptr [eax], al             
  0x01065968  45                      inc      ebp                            
  0x01065969  0020                    add      byte ptr [eax], ah             
  0x0106596B  0004a4                  add      byte ptr [esp], al             
  0x0106596E  0500000024              add      eax, 0x24000000                
  0x01065973  0000                    add      byte ptr [eax], al             
  0x01065975  7044                    jo       0x10659bb                      
  0x01065977  00b704000000            add      byte ptr [edi + 4], dh         
  0x0106597D  f4                      hlt                                     
  0x0106597E  46                      inc      esi                            
  0x0106597F  0000                    add      byte ptr [eax], al             
  0x01065981  0000                    add      byte ptr [eax], al             
  0x01065983  0000                    add      byte ptr [eax], al             
  0x01065985  f4                      hlt                                     
  0x01065986  60                      pushal                                  
  0x01065987  00740b00                add      byte ptr [ebx + ecx], dh       
  0x0106598B  0000                    add      byte ptr [eax], al             
  0x0106598E  44                      inc      esp                            
  0x0106598F  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x01065995  c406                    les      eax, ptr [esi]                 
  0x01065997  0008                    add      byte ptr [eax], cl             
  0x01065999  0000                    add      byte ptr [eax], al             
  0x0106599B  0000                    add      byte ptr [eax], al             
  0x0106599D  d85600                  fcom     dword ptr [esi]                
  0x010659A0  55                      push     ebp                            
  0x010659A1  0020                    add      byte ptr [eax], ah             
  0x010659A3  0004a4                  add      byte ptr [esp], al             
  0x010659A6  0500130020              add      eax, 0x20001300                
  0x010659AB  0000                    add      byte ptr [eax], al             
  0x010659AD  7056                    jo       0x1065a05                      
  0x010659AF  00b704000000            add      byte ptr [edi + 4], dh         
  0x010659B5  0000                    add      byte ptr [eax], al             
  0x010659B7  0000                    add      byte ptr [eax], al             
  0x010659BA  56                      push     esi                            
                                        ; XREF: 0x01065975 (cond_jump)
  0x010659BB  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x010659BE  0000                    add      byte ptr [eax], al             
  0x010659C0  0300                    add      eax, dword ptr [eax]           
  0x010659C2  2000                    and      byte ptr [eax], al             
  0x010659C4  08a4050000f056          or       byte ptr [ebp + eax + 0x56f00000], ah 
  0x010659CB  00790b                  add      byte ptr [ecx + 0xb], bh       
  0x010659CE  0000                    add      byte ptr [eax], al             
  0x010659D0  55                      push     ebp                            
  0x010659D1  0020                    add      byte ptr [eax], ah             
  0x010659D3  0004a4                  add      byte ptr [esp], al             
  0x010659D6  0500130020              add      eax, 0x20001300                
  0x010659DB  0000                    add      byte ptr [eax], al             
  0x010659DD  7056                    jo       0x1065a35                      
  0x010659DF  00b704000000            add      byte ptr [edi + 4], dh         
  0x010659E5  07                      pop      es                             
  0x010659E6  3000                    xor      byte ptr [eax], al             
  0x010659E8  c4700b                  les      esi, ptr [eax + 0xb]           
  0x010659EB  00b20c000000            add      byte ptr [edx + 0xc], dh       
  0x010659F1  7044                    jo       0x1065a37                      
  0x010659F3  00bf04000013            add      byte ptr [edi + 0x13000004], bh 
  0x010659F9  f4                      hlt                                     
  0x010659FA  60                      pushal                                  
  0x010659FB  00a504000090            add      byte ptr [ebp - 0x6ffffffc], ah 
  0x01065A01  1006                    adc      byte ptr [esi], al             
  0x01065A03  0002                    add      byte ptr [edx], al             
                                        ; XREF: 0x010659AD (cond_jump)
  0x01065A05  0000                    add      byte ptr [eax], al             
  0x01065A07  0000                    add      byte ptr [eax], al             
  0x01065A09  58                      pop      eax                            
  0x01065A0A  56                      push     esi                            
  0x01065A0B  0000                    add      byte ptr [eax], al             
  0x01065A0D  0036                    add      byte ptr [esi], dh             
  0x01065A0F  0000                    add      byte ptr [eax], al             
  0x01065A12  44                      inc      esp                            
  0x01065A13  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x01065A19  c406                    les      eax, ptr [esi]                 
  0x01065A1B  0036                    add      byte ptr [esi], dh             
  0x01065A1D  0000                    add      byte ptr [eax], al             
  0x01065A1F  0000                    add      byte ptr [eax], al             
  0x01065A21  f4                      hlt                                     
  0x01065A22  56                      push     esi                            
  0x01065A23  00740b00                add      byte ptr [ebx + ecx], dh       
  0x01065A27  0000                    add      byte ptr [eax], al             
  0x01065A29  c422                    les      esp, ptr [edx]                 
  0x01065A2B  004000                  add      byte ptr [eax], al             
  0x01065A2E  2000                    and      byte ptr [eax], al             
  0x01065A30  0090210000f0            add      byte ptr [eax - 0xfffffdf], dl 
  0x01065A36  56                      push     esi                            
                                        ; XREF: 0x010659F1 (cond_jump)
  0x01065A37  00730b                  add      byte ptr [ebx + 0xb], dh       
  0x01065A3A  0000                    add      byte ptr [eax], al             
  0x01065A3C  00e0                    add      al, ah                         
  0x01065A3E  44                      inc      esp                            
  0x01065A3F  00844f0100081d          add      byte ptr [edi + ecx*2 + 0x1d080001], al 
  0x01065A46  0c00                    or       al, 0                          
  0x01065A48  40                      inc      eax                            
  0x01065A49  0020                    add      byte ptr [eax], ah             
  0x01065A4B  00041d0c000070          add      byte ptr [ebx + 0x7000000c], al 
  0x01065A52  54                      push     esp                            
  0x01065A53  00a204000000            add      byte ptr [edx + 4], ah         
  0x01065A59  f4                      hlt                                     
  0x01065A5A  56                      push     esi                            
  0x01065A5B  00a50b000000            add      byte ptr [ebp + 0xb], ah       
  0x01065A61  c422                    les      esp, ptr [edx]                 
  0x01065A63  004000                  add      byte ptr [eax], al             
  0x01065A66  2000                    and      byte ptr [eax], al             
  0x01065A68  009021000000            add      byte ptr [eax + 0x21], dl      
  0x01065A6E  250000e047              and      eax, 0x47e00000                
  0x01065A73  0000                    add      byte ptr [eax], al             
  0x01065A75  c422                    les      esp, ptr [edx]                 
  0x01065A77  0000                    add      byte ptr [eax], al             
  0x01065A79  f4                      hlt                                     
  0x01065A7A  46                      inc      esi                            
  0x01065A7B  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x01065A81  f4                      hlt                                     
  0x01065A82  44                      inc      esp                            
  0x01065A83  00fa                    add      dl, bh                         
  0x01065A85  0000                    add      byte ptr [eax], al             
  0x01065A87  002e                    add      byte ptr [esi], ch             
  0x01065A89  1d0c004000              sbb      eax, 0x40000c                  
  0x01065A8E  2000                    and      byte ptr [eax], al             
  0x01065A90  0090210000c4            add      byte ptr [eax - 0x3bffffdf], dl 
  0x01065A96  2200                    and      al, byte ptr [eax]             
  0x01065A98  00f4                    add      ah, dh                         
  0x01065A9A  46                      inc      esi                            
  0x01065A9B  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x01065AA2  44                      inc      esp                            
  0x01065AA3  00720b                  add      byte ptr [edx + 0xb], dh       
  0x01065AA6  0000                    add      byte ptr [eax], al             
  0x01065AA8  2e1d0c004000            sbb      eax, 0x40000c                  
  0x01065AAE  2000                    and      byte ptr [eax], al             
  0x01065AB0  0091210000c4            add      byte ptr [ecx - 0x3bffffdf], dl 
  0x01065AB6  2200                    and      al, byte ptr [eax]             
  0x01065AB8  00f4                    add      ah, dh                         
  0x01065ABA  46                      inc      esi                            
  0x01065ABB  0032                    add      byte ptr [edx], dh             
  0x01065ABD  0000                    add      byte ptr [eax], al             
  0x01065ABF  00d0                    add      al, dl                         
  0x01065AC1  f4                      hlt                                     
  0x01065AC2  44                      inc      esp                            
  0x01065AC3  0000                    add      byte ptr [eax], al             
  0x01065AC5  0000                    add      byte ptr [eax], al             
  0x01065AC7  002e                    add      byte ptr [esi], ch             
  0x01065AC9  1d0c004000              sbb      eax, 0x40000c                  
  0x01065ACE  2000                    and      byte ptr [eax], al             
  0x01065AD0  0092210000f4            add      byte ptr [edx - 0xbffffdf], dl 
  0x01065AD6  65001a                  add      byte ptr gs:[edx], bl          
  0x01065AD9  0f0000                  sldt     word ptr [eax]                 
  0x01065ADC  007066                  add      byte ptr [eax + 0x66], dh      
  0x01065ADF  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01065AE2  0000                    add      byte ptr [eax], al             
  0x01065AE4  86040d0000f066          xchg     byte ptr [ecx + 0x66f00000], al 
  0x01065AEB  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01065AEE  0000                    add      byte ptr [eax], al             
  0x01065AF0  005e20                  add      byte ptr [esi + 0x20], bl      
  0x01065AF3  0000                    add      byte ptr [eax], al             
  0x01065AF6  56                      push     esi                            
  0x01065AF7  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x01065AFA  0000                    add      byte ptr [eax], al             
  0x01065AFC  0300                    add      eax, dword ptr [eax]           
  0x01065AFE  2000                    and      byte ptr [eax], al             
  0x01065B00  17                      pop      ss                             
  0x01065B01  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01065B02  050000f056              add      eax, 0x56f00000                
  0x01065B07  00730b                  add      byte ptr [ebx + 0xb], dh       
  0x01065B0A  0000                    add      byte ptr [eax], al             
  0x01065B0C  00f0                    add      al, dh                         
  0x01065B0E  44                      inc      esp                            
  0x01065B0F  00790b                  add      byte ptr [ecx + 0xb], bh       
  0x01065B12  0000                    add      byte ptr [eax], al             
  0x01065B14  844f01                  test     byte ptr [edi + 1], cl         
  0x01065B17  0008                    add      byte ptr [eax], cl             
  0x01065B19  1d0c004000              sbb      eax, 0x40000c                  
  0x01065B1E  2000                    and      byte ptr [eax], al             
  0x01065B20  041d                    add      al, 0x1d                       
  0x01065B22  0c00                    or       al, 0                          
  0x01065B24  007054                  add      byte ptr [eax + 0x54], dh      
  0x01065B27  00a204000000            add      byte ptr [edx + 4], ah         
  0x01065B2D  00250000f447            add      byte ptr [0x47f40000], ah      
  0x01065B33  0007                    add      byte ptr [edi], al             
  0x01065B35  0000                    add      byte ptr [eax], al             
  0x01065B37  0000                    add      byte ptr [eax], al             
  0x01065B39  f4                      hlt                                     
  0x01065B3A  60                      pushal                                  
  0x01065B3B  008304000000            add      byte ptr [ebx + 4], al         
  0x01065B41  f4                      hlt                                     
  0x01065B42  61                      popal                                   
  0x01065B43  0039                    add      byte ptr [ecx], bh             
  0x01065B45  0b00                    or       eax, dword ptr [eax]           
  0x01065B47  0000                    add      byte ptr [eax], al             
  0x01065B49  f4                      hlt                                     
  0x01065B4A  6200                    bound    eax, qword ptr [eax]           
  0x01065B4C  b804000000              mov      eax, 4                         
  0x01065B51  f4                      hlt                                     
  0x01065B52  65001a                  add      byte ptr gs:[edx], bl          
  0x01065B55  0f0000                  sldt     word ptr [eax]                 
  0x01065B58  86040d0000f460          xchg     byte ptr [ecx + 0x60f40000], al 
  0x01065B5F  00a60400001b            add      byte ptr [esi + 0x1b000004], ah 
  0x01065B65  f4                      hlt                                     
  0x01065B66  6600fb                  add      bl, bh                         
  0x01065B69  0c00                    or       al, 0                          
  0x01065B6B  0000                    add      byte ptr [eax], al             
  0x01065B6D  d8440013                fadd     dword ptr [eax + eax + 0x13]   
  0x01065B71  f4                      hlt                                     
  0x01065B72  47                      inc      edi                            
  0x01065B73  005555                  add      byte ptr [ebp + 0x55], dl      
  0x01065B76  d500                    aad      0                              
  0x01065B78  00e8                    add      al, ch                         
  0x01065B7A  2000                    and      byte ptr [eax], al             
  0x01065B7D  de4e00                  fimul    word ptr [esi]                 
  0x01065B80  13842100dad844          adc      eax, dword ptr [ecx + 0x44d8da00] 
  0x01065B87  0000                    add      byte ptr [eax], al             
  0x01065B89  e82000c6de              call     0xdfcc5bae                     
  0x01065B8E  4e                      dec      esi                            
  0x01065B8F  0000                    add      byte ptr [eax], al             
  0x01065B91  8421                    test     byte ptr [ecx], ah             
  0x01065B93  00da                    add      dl, bl                         
  0x01065B95  d8f0                    fdiv     st(0)                          
  0x01065B97  00da                    add      dl, bl                         
  0x01065B99  d8440013                fadd     dword ptr [eax + eax + 0x13]   
  0x01065B9D  f4                      hlt                                     
  0x01065B9E  47                      inc      edi                            
  0x01065B9F  0000                    add      byte ptr [eax], al             
  0x01065BA1  00c0                    add      al, al                         
  0x01065BA3  0000                    add      byte ptr [eax], al             
  0x01065BA5  e82000c6de              call     0xdfcc5bca                     
  0x01065BAA  4e                      dec      esi                            
  0x01065BAB  0000                    add      byte ptr [eax], al             
  0x01065BAD  8421                    test     byte ptr [ecx], ah             
  0x01065BAF  00da                    add      dl, bl                         
  0x01065BB1  0020                    add      byte ptr [eax], ah             
  0x01065BB3  0000                    add      byte ptr [eax], al             
  0x01065BB5  d8f0                    fdiv     st(0)                          
  0x01065BB7  00900a060002            add      byte ptr [eax + 0x200060a], dl 
  0x01065BBD  0000                    add      byte ptr [eax], al             
  0x01065BBF  00da                    add      dl, bl                         
  0x01065BC1  d8f0                    fdiv     st(0)                          
  0x01065BC3  00da                    add      dl, bl                         
  0x01065BC5  0020                    add      byte ptr [eax], ah             
  0x01065BC7  00ae1d0c0000            add      byte ptr [esi + 0xc1d], ch     
  0x01065BCD  7056                    jo       0x1065c25                      
  0x01065BCF  007a0b                  add      byte ptr [edx + 0xb], bh       
  0x01065BD2  0000                    add      byte ptr [eax], al             
  0x01065BD4  020c0500000c05          add      cl, byte ptr [eax + 0x50c0000] 
  0x01065BDB  001b                    add      byte ptr [ebx], bl             
  0x01065BDE  44                      inc      esp                            
  0x01065BDF  007a0b                  add      byte ptr [edx + 0xb], bh       
  0x01065BE2  0000                    add      byte ptr [eax], al             
  0x01065BE4  004f23                  add      byte ptr [edi + 0x23], cl      
  0x01065BE7  004c0020                add      byte ptr [eax + eax + 0x20], cl 
  0x01065BEB  0000                    add      byte ptr [eax], al             
  0x01065BED  fa                      cli                                     
  0x01065BEE  2100                    and      dword ptr [eax], eax           
  0x01065BF0  0b00                    or       eax, dword ptr [eax]           
  0x01065BF2  2000                    and      byte ptr [eax], al             
  0x01065BF4  02140500030c05          add      dl, byte ptr [eax + 0x50c0300] 
  0x01065BFB  0080100d0033            add      byte ptr [eax + 0x33000d10], al 
  0x01065C01  fc                      cld                                     
  0x01065C02  ff00                    inc      dword ptr [eax]                
  0x01065C04  0c00                    or       al, 0                          
  0x01065C06  0000                    add      byte ptr [eax], al             
  0x01065C08  1bf4                    sbb      esi, esp                       
  0x01065C0A  60                      pushal                                  
  0x01065C0B  007a0b                  add      byte ptr [edx + 0xb], bh       
  0x01065C0E  0000                    add      byte ptr [eax], al             
  0x01065C10  006057                  add      byte ptr [eax + 0x57], ah      
  0x01065C13  0000                    add      byte ptr [eax], al             
  0x01065C15  f4                      hlt                                     
  0x01065C16  60                      pushal                                  
  0x01065C17  00730b                  add      byte ptr [ebx + 0xb], dh       
  0x01065C1A  0000                    add      byte ptr [eax], al             
  0x01065C1C  00f4                    add      ah, dh                         
  0x01065C1E  6200                    bound    eax, qword ptr [eax]           
  0x01065C20  790b                    jns      0x1065c2d                      
  0x01065C22  0000                    add      byte ptr [eax], al             
  0x01065C24  00f4                    add      ah, dh                         
  0x01065C26  6400740b00              add      byte ptr fs:[ebx + ecx], dh    
  0x01065C2B  0000                    add      byte ptr [eax], al             
  0x01065C2E  7000                    jo       0x1065c30                      
                                        ; XREF: 0x01065C2E (cond_jump)
  0x01065C30  97                      xchg     edi, eax                       
  0x01065C31  0b00                    or       eax, dword ptr [eax]           
  0x01065C33  0000                    add      byte ptr [eax], al             
  0x01065C35  95                      xchg     ebp, eax                       
  0x01065C36  2200                    and      al, byte ptr [eax]             
  0x01065C38  006057                  add      byte ptr [eax + 0x57], ah      
  0x01065C3B  0000                    add      byte ptr [eax], al             
  0x01065C3D  625700                  bound    edx, qword ptr [edi]           
  0x01065C40  10d8                    adc      al, bl                         
  0x01065C42  06                      push     es                             
  0x01065C43  0002                    add      byte ptr [edx], al             
  0x01065C45  0000                    add      byte ptr [eax], al             
  0x01065C47  0000                    add      byte ptr [eax], al             
  0x01065C49  5d                      pop      ebp                            
  0x01065C4A  57                      push     edi                            
  0x01065C4B  0000                    add      byte ptr [eax], al             
  0x01065C4D  0036                    add      byte ptr [esi], dh             
  0x01065C4F  0000                    add      byte ptr [eax], al             
  0x01065C52  44                      inc      esp                            
  0x01065C53  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x01065C59  c406                    les      eax, ptr [esi]                 
  0x01065C5B  0012                    add      byte ptr [edx], dl             
  0x01065C5D  0000                    add      byte ptr [eax], al             
  0x01065C5F  0000                    add      byte ptr [eax], al             
  0x01065C61  c422                    les      esp, ptr [edx]                 
  0x01065C63  0000                    add      byte ptr [eax], al             
  0x01065C65  f4                      hlt                                     
  0x01065C66  46                      inc      esi                            
  0x01065C67  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x01065C6E  44                      inc      esp                            
  0x01065C6F  00720b                  add      byte ptr [edx + 0xb], dh       
  0x01065C72  0000                    add      byte ptr [eax], al             
  0x01065C74  2e1d0c004000            sbb      eax, 0x40000c                  
  0x01065C7A  2000                    and      byte ptr [eax], al             
  0x01065C7C  0090210000f4            add      byte ptr [eax - 0xbffffdf], dl 
  0x01065C82  56                      push     esi                            
  0x01065C83  00a50b000000            add      byte ptr [ebp + 0xb], ah       
  0x01065C89  c422                    les      esp, ptr [edx]                 
  0x01065C8B  004000                  add      byte ptr [eax], al             
  0x01065C8E  2000                    and      byte ptr [eax], al             
  0x01065C90  009221001062            add      byte ptr [edx + 0x62100021], dl 
  0x01065C96  06                      push     es                             
  0x01065C97  0002                    add      byte ptr [edx], al             
  0x01065C99  0000                    add      byte ptr [eax], al             
  0x01065C9B  0000                    add      byte ptr [eax], al             
  0x01065C9D  58                      pop      eax                            
  0x01065C9E  57                      push     edi                            
  0x01065C9F  0000                    add      byte ptr [eax], al             
  0x01065CA1  5e                      pop      esi                            
  0x01065CA2  2000                    and      byte ptr [eax], al             
  0x01065CA4  00f0                    add      al, dh                         
  0x01065CA6  56                      push     esi                            
  0x01065CA7  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x01065CAA  0000                    add      byte ptr [eax], al             
  0x01065CAC  0300                    add      eax, dword ptr [eax]           
  0x01065CAE  2000                    and      byte ptr [eax], al             
  0x01065CB0  06                      push     es                             
  0x01065CB1  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01065CB2  050000f460              add      eax, 0x60f40000                
  0x01065CB7  0039                    add      byte ptr [ecx], bh             
  0x01065CB9  0b00                    or       eax, dword ptr [eax]           
  0x01065CBB  009007060002            add      byte ptr [eax + 0x2000607], dl 
  0x01065CC1  0000                    add      byte ptr [eax], al             
  0x01065CC3  0000                    add      byte ptr [eax], al             
  0x01065CC5  58                      pop      eax                            
  0x01065CC6  57                      push     edi                            
  0x01065CC7  000c00                  add      byte ptr [eax + eax], cl       
  0x01065CCA  0000                    add      byte ptr [eax], al             
  0x01065CCC  00f0                    add      al, dh                         
  0x01065CCE  44                      inc      esp                            
  0x01065CCF  00b604000000            add      byte ptr [esi + 4], dh         
  0x01065CD5  7044                    jo       0x1065d1b                      
  0x01065CD7  009f04000080            add      byte ptr [edi - 0x7ffffffc], bl 
  0x01065CDD  100d00f8feff            adc      byte ptr [0xfffef800], cl      
  0x01065CE3  000f                    add      byte ptr [edi], cl             
  0x01065CE5  0a05000c0000            or       al, byte ptr [0xc00]           
  0x01065CEB  001b                    add      byte ptr [ebx], bl             
  0x01065CED  0020                    add      byte ptr [eax], ah             
  0x01065CEF  008850010088            add      byte ptr [eax - 0x77fffeb0], cl 
  0x01065CF5  50                      push     eax                            
  0x01065CF6  0100                    add      dword ptr [eax], eax           
  0x01065CF8  884201                  mov      byte ptr [edx + 1], al         
  0x01065CFB  008846010088            add      byte ptr [eax - 0x77fffeba], cl 
  0x01065D01  45                      inc      ebp                            
  0x01065D02  0100                    add      dword ptr [eax], eax           
  0x01065D04  884301                  mov      byte ptr [ebx + 1], al         
  0x01065D07  008843010000            add      byte ptr [eax + 0x143], cl     
  0x01065D0E  56                      push     esi                            
  0x01065D0F  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x01065D12  0000                    add      byte ptr [eax], al             
  0x01065D14  854101                  test     dword ptr [ecx + 1], eax       
  0x01065D17  0004a4                  add      byte ptr [esp], al             
  0x01065D1A  0500864101              add      eax, 0x1418600                 
  0x01065D1F  0002                    add      byte ptr [edx], al             
  0x01065D21  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01065D22  0500884201              add      eax, 0x1428800                 
  0x01065D27  0000                    add      byte ptr [eax], al             
  0x01065D2A  56                      push     esi                            
  0x01065D2B  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x01065D2E  0000                    add      byte ptr [eax], al             
  0x01065D30  86440100                xchg     byte ptr [ecx + eax], al       
  0x01065D34  02a40500884201          add      ah, byte ptr [ebp + eax + 0x1428800] 
  0x01065D3B  0000                    add      byte ptr [eax], al             
  0x01065D3E  56                      push     esi                            
  0x01065D3F  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x01065D42  0000                    add      byte ptr [eax], al             
  0x01065D44  854201                  test     dword ptr [edx + 1], eax       
  0x01065D47  0002                    add      byte ptr [edx], al             
  0x01065D49  2405                    and      al, 5                          
  0x01065D4B  008842010088            add      byte ptr [eax - 0x77fffebe], cl 
  0x01065D51  41                      inc      ecx                            
  0x01065D52  0100                    add      dword ptr [eax], eax           
  0x01065D54  884501                  mov      byte ptr [ebp + 1], al         
  0x01065D57  008841010000            add      byte ptr [eax + 0x141], cl     
  0x01065D5E  56                      push     esi                            
  0x01065D5F  004c0b00                add      byte ptr [ebx + ecx], cl       
  0x01065D63  0003                    add      byte ptr [ebx], al             
  0x01065D65  f4                      hlt                                     
  0x01065D66  44                      inc      esp                            
  0x01065D67  0008                    add      byte ptr [eax], cl             
  0x01065D69  0000                    add      byte ptr [eax], al             
  0x01065D6B  0002                    add      byte ptr [edx], al             
  0x01065D6D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01065D6E  0500480020              add      eax, 0x20004800                
  0x01065D73  008841010088            add      byte ptr [eax - 0x77fffebf], cl 
  0x01065D79  41                      inc      ecx                            
  0x01065D7A  0100                    add      dword ptr [eax], eax           
  0x01065D7C  884101                  mov      byte ptr [ecx + 1], al         
  0x01065D7F  008841010088            add      byte ptr [eax - 0x77fffebf], cl 
  0x01065D85  41                      inc      ecx                            
  0x01065D86  0100                    add      dword ptr [eax], eax           
  0x01065D88  884101                  mov      byte ptr [ecx + 1], al         
  0x01065D8B  008841010000            add      byte ptr [eax + 0x141], cl     
  0x01065D91  7057                    jo       0x1065dea                      
  0x01065D93  00510b                  add      byte ptr [ecx + 0xb], dl       
  0x01065D96  0000                    add      byte ptr [eax], al             
  0x01065D98  0c00                    or       al, 0                          
  0x01065D9A  0000                    add      byte ptr [eax], al             
  0x01065D9C  0000                    add      byte ptr [eax], al             
  0x01065D9E  360000                  add      byte ptr ss:[eax], al          
  0x01065DA2  44                      inc      esp                            
  0x01065DA3  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x01065DA9  c406                    les      eax, ptr [esi]                 
  0x01065DAB  003400                  add      byte ptr [eax + eax], dh       
  0x01065DAE  0000                    add      byte ptr [eax], al             
  0x01065DB0  00f4                    add      ah, dh                         
  0x01065DB2  56                      push     esi                            
  0x01065DB3  008a0b000000            add      byte ptr [edx + 0xb], cl       
  0x01065DB9  c422                    les      esp, ptr [edx]                 
  0x01065DBB  004000                  add      byte ptr [eax], al             
  0x01065DBE  2000                    and      byte ptr [eax], al             
  0x01065DC0  0090210000e0            add      byte ptr [eax - 0x1fffffdf], dl 
  0x01065DC6  56                      push     esi                            
  0x01065DC7  0003                    add      byte ptr [ebx], al             
  0x01065DC9  92                      xchg     edx, eax                       
  0x01065DCA  2100                    and      dword ptr [eax], eax           
  0x01065DCC  4b                      dec      ebx                            
  0x01065DCD  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01065DCE  050000c422              add      eax, 0x22c40000                
  0x01065DD3  0000                    add      byte ptr [eax], al             
  0x01065DD5  f4                      hlt                                     
  0x01065DD6  46                      inc      esi                            
  0x01065DD7  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x01065DDD  f4                      hlt                                     
  0x01065DDE  44                      inc      esp                            
  0x01065DDF  00fa                    add      dl, bh                         
  0x01065DE1  0000                    add      byte ptr [eax], al             
  0x01065DE3  002e                    add      byte ptr [esi], ch             
  0x01065DE5  1d0c004000              sbb      eax, 0x40000c                  
                                        ; XREF: 0x01065D91 (cond_jump)
  0x01065DEA  2000                    and      byte ptr [eax], al             
  0x01065DEC  0090210000f4            add      byte ptr [eax - 0xbffffdf], dl 
  0x01065DF2  56                      push     esi                            
  0x01065DF3  005c0b00                add      byte ptr [ebx + ecx], bl       
  0x01065DF7  0000                    add      byte ptr [eax], al             
  0x01065DF9  c422                    les      esp, ptr [edx]                 
  0x01065DFB  004000                  add      byte ptr [eax], al             
  0x01065DFE  2000                    and      byte ptr [eax], al             
  0x01065E00  0091210000e1            add      byte ptr [ecx - 0x1effffdf], dl 
  0x01065E06  7000                    jo       0x1065e08                      
                                        ; XREF: 0x01065E06 (cond_jump)
  0x01065E08  d9720b                  fnstenv  [edx + 0xb]                    
  0x01065E0B  0012                    add      byte ptr [edx], dl             
  0x01065E0D  0f0000                  sldt     word ptr [eax]                 
  0x01065E10  00f4                    add      ah, dh                         
  0x01065E12  56                      push     esi                            
  0x01065E13  00910b000000            add      byte ptr [ecx + 0xb], dl       
  0x01065E19  c422                    les      esp, ptr [edx]                 
  0x01065E1B  004000                  add      byte ptr [eax], al             
  0x01065E1E  2000                    and      byte ptr [eax], al             
  0x01065E20  0091210000e1            add      byte ptr [ecx - 0x1effffdf], dl 
  0x01065E26  7200                    jb       0x1065e28                      
                                        ; XREF: 0x01065E26 (cond_jump)
  0x01065E28  00d8                    add      al, bl                         
  0x01065E2A  45                      inc      ebp                            
  0x01065E2B  0000                    add      byte ptr [eax], al             
  0x01065E2D  c422                    les      esp, ptr [edx]                 
  0x01065E2F  0000                    add      byte ptr [eax], al             
  0x01065E31  f4                      hlt                                     
  0x01065E32  46                      inc      esi                            
  0x01065E33  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x01065E39  f4                      hlt                                     
  0x01065E3A  44                      inc      esp                            
  0x01065E3B  00b00700002e            add      byte ptr [eax + 0x2e000007], dh 
  0x01065E41  1d0c004000              sbb      eax, 0x40000c                  
  0x01065E46  2000                    and      byte ptr [eax], al             
  0x01065E48  00952100005d            add      byte ptr [ebp + 0x5d000021], dl 
  0x01065E4E  45                      inc      ebp                            
  0x01065E4F  0000                    add      byte ptr [eax], al             
  0x01065E51  c422                    les      esp, ptr [edx]                 
  0x01065E53  0000                    add      byte ptr [eax], al             
  0x01065E55  f4                      hlt                                     
  0x01065E56  46                      inc      esi                            
  0x01065E57  001f                    add      byte ptr [edi], bl             
  0x01065E59  0000                    add      byte ptr [eax], al             
  0x01065E5B  00d0                    add      al, dl                         
  0x01065E5D  f4                      hlt                                     
  0x01065E5E  44                      inc      esp                            
  0x01065E5F  0000                    add      byte ptr [eax], al             
  0x01065E61  0000                    add      byte ptr [eax], al             
  0x01065E63  002e                    add      byte ptr [esi], ch             
  0x01065E65  1d0c004000              sbb      eax, 0x40000c                  
  0x01065E6A  2000                    and      byte ptr [eax], al             
  0x01065E6C  00942100005c4d          add      byte ptr [ecx + 0x4d5c0000], dl 
  0x01065E73  001e                    add      byte ptr [esi], bl             
  0x01065E75  050d00005e              add      eax, 0x5e00000d                
  0x01065E7A  2000                    and      byte ptr [eax], al             
  0x01065E7C  00f0                    add      al, dh                         
  0x01065E7E  56                      push     esi                            
  0x01065E7F  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x01065E82  0000                    add      byte ptr [eax], al             
  0x01065E84  0300                    add      eax, dword ptr [eax]           
  0x01065E86  2000                    and      byte ptr [eax], al             
  0x01065E88  13a4050000f056          adc      esp, dword ptr [ebp + eax + 0x56f00000] 
  0x01065E8F  008f0b000003            add      byte ptr [edi + 0x300000b], cl 
  0x01065E95  0020                    add      byte ptr [eax], ah             
  0x01065E97  000f                    add      byte ptr [edi], cl             
  0x01065E99  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01065E9A  050000f460              add      eax, 0x60f40000                
  0x01065E9F  008304000000            add      byte ptr [ebx + 4], al         
  0x01065EA5  06                      push     es                             
  0x01065EA6  3800                    cmp      byte ptr [eax], al             
  0x01065EA8  00f0                    add      al, dh                         
  0x01065EAA  7900                    jns      0x1065eac                      
                                        ; XREF: 0x01065EAA (cond_jump)
  0x01065EAC  130f                    adc      ecx, dword ptr [edi]           
  0x01065EAE  0000                    add      byte ptr [eax], al             
  0x01065EB0  0002                    add      byte ptr [edx], al             
  0x01065EB2  3a00                    cmp      al, byte ptr [eax]             
  0x01065EB4  00d8                    add      al, bl                         
  0x01065EB6  45                      inc      ebp                            
  0x01065EB7  0000                    add      byte ptr [eax], al             
  0x01065EB9  f4                      hlt                                     
  0x01065EBA  650039                  add      byte ptr gs:[ecx], bh          
  0x01065EBD  0b00                    or       eax, dword ptr [eax]           
  0x01065EBF  0000                    add      byte ptr [eax], al             
  0x01065EC1  5d                      pop      ebp                            
  0x01065EC2  45                      inc      ebp                            
  0x01065EC3  0000                    add      byte ptr [eax], al             
  0x01065EC5  f4                      hlt                                     
  0x01065EC6  64009b00000000          add      byte ptr fs:[ebx], bl          
  0x01065ECD  5c                      pop      esp                            
  0x01065ECE  4d                      dec      ebp                            
  0x01065ECF  001e                    add      byte ptr [esi], bl             
  0x01065ED1  050d000c00              add      eax, 0xc000d                   
  0x01065ED6  0000                    add      byte ptr [eax], al             
  0x01065ED8  00f4                    add      ah, dh                         
  0x01065EDA  56                      push     esi                            
  0x01065EDB  0016                    add      byte ptr [esi], dl             
  0x01065EDD  0000                    add      byte ptr [eax], al             
  0x01065EDF  0000                    add      byte ptr [eax], al             
  0x01065EE1  f4                      hlt                                     
  0x01065EE2  57                      push     edi                            
  0x01065EE3  0001                    add      byte ptr [ecx], al             
  0x01065EE5  0000                    add      byte ptr [eax], al             
  0x01065EE7  0000                    add      byte ptr [eax], al             
  0x01065EE9  f4                      hlt                                     
  0x01065EEA  7000                    jo       0x1065eec                      
                                        ; XREF: 0x01065EEA (cond_jump)
  0x01065EEC  90                      nop                                     
  0x01065EED  0300                    add      eax, dword ptr [eax]           
  0x01065EEF  0000                    add      byte ptr [eax], al             
  0x01065EF1  0039                    add      byte ptr [ecx], bh             
  0x01065EF3  0000                    add      byte ptr [eax], al             
  0x01065EF5  f4                      hlt                                     
  0x01065EF6  60                      pushal                                  
  0x01065EF7  00fa                    add      dl, bh                         
  0x01065EF9  0000                    add      byte ptr [eax], al             
  0x01065EFB  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x01065F01  0100                    add      dword ptr [eax], eax           
  0x01065F03  0003                    add      byte ptr [ebx], al             
  0x01065F05  0020                    add      byte ptr [eax], ah             
  0x01065F07  0000                    add      byte ptr [eax], al             
  0x01065F09  2405                    and      al, 5                          
  0x01065F0B  000c00                  add      byte ptr [eax + eax], cl       
  0x01065F0E  0000                    add      byte ptr [eax], al             
  0x01065F10  0c00                    or       al, 0                          
  0x01065F12  0000                    add      byte ptr [eax], al             
  0x01065F14  0c00                    or       al, 0                          
  0x01065F16  0000                    add      byte ptr [eax], al             
  0x01065F18  40                      inc      eax                            
  0x01065F19  1bd0                    sbb      edx, eax                       
  0x01065F1B  00d3                    add      bl, dl                         
  0x01065F1D  06                      push     es                             
  0x01065F1E  0000                    add      byte ptr [eax], al             
  0x01065F20  7201                    jb       0x1065f23                      
  0x01065F22  0400                    add      al, 0                          
  0x01065F24  c2c60f                  ret      0xfc6                          
  0x01065F27  0000                    add      byte ptr [eax], al             
  0x01065F29  7044                    jo       0x1065f6f                      
  0x01065F2B  00fb                    add      bl, bh                         
  0x01065F2D  0000                    add      byte ptr [eax], al             
  0x01065F2F  000b                    add      byte ptr [ebx], cl             
  0x01065F31  0020                    add      byte ptr [eax], ah             
  0x01065F33  0003                    add      byte ptr [ebx], al             
  0x01065F35  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01065F36  050080100d              add      eax, 0xd108000                 
  0x01065F3B  00c0                    add      al, al                         
  0x01065F3D  06                      push     es                             
  0x01065F3E  0000                    add      byte ptr [eax], al             
  0x01065F40  80100d                  adc      byte ptr [eax], 0xd            
  0x01065F43  006c0600                add      byte ptr [esi + eax], ch       
  0x01065F47  0000                    add      byte ptr [eax], al             
  0x01065F4A  57                      push     edi                            
  0x01065F4B  00fb                    add      bl, bh                         
  0x01065F4D  0000                    add      byte ptr [eax], al             
  0x01065F4F  000b                    add      byte ptr [ebx], cl             
  0x01065F51  f4                      hlt                                     
  0x01065F52  60                      pushal                                  
  0x01065F53  001f                    add      byte ptr [edi], bl             
  0x01065F55  0000                    add      byte ptr [eax], al             
  0x01065F57  0012                    add      byte ptr [edx], dl             
  0x01065F59  2405                    and      al, 5                          
  0x01065F5B  0000                    add      byte ptr [eax], al             
  0x01065F5D  002400                  add      byte ptr [eax + eax], ah       
  0x01065F60  007044                  add      byte ptr [eax + 0x44], dh      
  0x01065F63  004f0b                  add      byte ptr [edi + 0xb], cl       
  0x01065F66  0000                    add      byte ptr [eax], al             
  0x01065F68  007044                  add      byte ptr [eax + 0x44], dh      
  0x01065F6B  00500b                  add      byte ptr [eax + 0xb], dl       
  0x01065F6E  0000                    add      byte ptr [eax], al             
  0x01065F70  00f4                    add      ah, dh                         
  0x01065F72  44                      inc      esp                            
  0x01065F73  0000                    add      byte ptr [eax], al             
  0x01065F75  72f8                    jb       0x1065f6f                      
  0x01065F77  0000                    add      byte ptr [eax], al             
  0x01065F79  58                      pop      eax                            
  0x01065F7A  44                      inc      esp                            
  0x01065F7B  0000                    add      byte ptr [eax], al             
  0x01065F7D  f4                      hlt                                     
  0x01065F7E  44                      inc      esp                            
  0x01065F7F  0000                    add      byte ptr [eax], al             
  0x01065F81  1f                      pop      ds                             
  0x01065F82  4e                      dec      esi                            
  0x01065F83  0000                    add      byte ptr [eax], al             
  0x01065F85  58                      pop      eax                            
  0x01065F86  44                      inc      esp                            
  0x01065F87  0000                    add      byte ptr [eax], al             
  0x01065F89  f4                      hlt                                     
  0x01065F8A  44                      inc      esp                            
  0x01065F8B  0000                    add      byte ptr [eax], al             
  0x01065F8D  0100                    add      dword ptr [eax], eax           
  0x01065F8F  0000                    add      byte ptr [eax], al             
  0x01065F91  58                      pop      eax                            
  0x01065F92  44                      inc      esp                            
  0x01065F93  0000                    add      byte ptr [eax], al             
  0x01065F95  f4                      hlt                                     
  0x01065F96  44                      inc      esp                            
  0x01065F97  0000                    add      byte ptr [eax], al             
  0x01065F99  005000                  add      byte ptr [eax], dl             
  0x01065F9C  005844                  add      byte ptr [eax + 0x44], bl      
  0x01065F9F  0000                    add      byte ptr [eax], al             
  0x01065FA2  56                      push     esi                            
  0x01065FA3  004f0b                  add      byte ptr [edi + 0xb], cl       
  0x01065FA6  0000                    add      byte ptr [eax], al             
  0x01065FA8  03f0                    add      esi, eax                       
  0x01065FAA  44                      inc      esp                            
  0x01065FAB  00500b                  add      byte ptr [eax + 0xb], dl       
  0x01065FAE  0000                    add      byte ptr [eax], al             
  0x01065FB0  02a40500005844          add      ah, byte ptr [ebp + eax + 0x44580000] 
  0x01065FB7  0000                    add      byte ptr [eax], al             
  0x01065FB9  f4                      hlt                                     
  0x01065FBA  57                      push     edi                            
  0x01065FBB  0010                    add      byte ptr [eax], dl             
  0x01065FBD  0000                    add      byte ptr [eax], al             
  0x01065FBF  0080100d00a6            add      byte ptr [eax - 0x59fff2f0], al 
  0x01065FC5  0100                    add      dword ptr [eax], eax           
  0x01065FC7  0000                    add      byte ptr [eax], al             
  0x01065FC9  f4                      hlt                                     
  0x01065FCA  44                      inc      esp                            
  0x01065FCB  0000                    add      byte ptr [eax], al             
  0x01065FCD  0000                    add      byte ptr [eax], al             
  0x01065FCF  004500                  add      byte ptr [ebp], al             
  0x01065FD2  2000                    and      byte ptr [eax], al             
  0x01065FD4  00740500                add      byte ptr [ebp + eax], dh       
  0x01065FD8  005820                  add      byte ptr [eax + 0x20], bl      
  0x01065FDB  0000                    add      byte ptr [eax], al             
  0x01065FDD  d85600                  fcom     dword ptr [esi]                
  0x01065FE0  00f0                    add      al, dh                         
  0x01065FE2  57                      push     edi                            
  0x01065FE3  00fb                    add      bl, bh                         
  0x01065FE5  0000                    add      byte ptr [eax], al             
  0x01065FE7  000b                    add      byte ptr [ebx], cl             
  0x01065FE9  f4                      hlt                                     
  0x01065FEA  44                      inc      esp                            
  0x01065FEB  000400                  add      byte ptr [eax + eax], al       
  0x01065FEE  0000                    add      byte ptr [eax], al             
  0x01065FF0  40                      inc      eax                            
  0x01065FF1  2a20                    sub      ah, byte ptr [eax]             
  0x01065FF3  0000                    add      byte ptr [eax], al             
  0x01065FF6  57                      push     edi                            
  0x01065FF7  004f0b                  add      byte ptr [edi + 0xb], cl       
  0x01065FFA  0000                    add      byte ptr [eax], al             
  0x01065FFC  0bf4                    or       esi, esp                       
  0x01065FFE  44                      inc      esp                            
  0x01065FFF  0001                    add      byte ptr [ecx], al             
  0x01066001  0000                    add      byte ptr [eax], al             
  0x01066003  004022                  add      byte ptr [eax + 0x22], al      
  0x01066006  2000                    and      byte ptr [eax], al             
  0x01066008  0000                    add      byte ptr [eax], al             
  0x0106600A  2400                    and      al, 0                          
  0x0106600C  0000                    add      byte ptr [eax], al             
  0x0106600E  250000f460              and      eax, 0x60f40000                
  0x01066013  001f                    add      byte ptr [edi], bl             
  0x01066015  0000                    add      byte ptr [eax], al             
  0x01066017  0080cc0c0007            add      byte ptr [eax + 0x7000ccc], al 
  0x0106601D  0000                    add      byte ptr [eax], al             
  0x0106601F  0040cc                  add      byte ptr [eax - 0x34], al      
  0x01066022  0a00                    or       al, byte ptr [eax]             
  0x01066024  0098210000f4            add      byte ptr [eax - 0xbffffdf], bl 
  0x0106602A  44                      inc      esp                            
  0x0106602B  0001                    add      byte ptr [ecx], al             
  0x0106602D  0000                    add      byte ptr [eax], al             
  0x0106602F  0000                    add      byte ptr [eax], al             
  0x01066031  e845000070              call     0x7106607b                     
  0x01066036  44                      inc      esp                            
  0x01066037  004f0b                  add      byte ptr [edi + 0xb], cl       
  0x0106603A  0000                    add      byte ptr [eax], al             
  0x0106603C  007045                  add      byte ptr [eax + 0x45], dh      
  0x0106603F  00500b                  add      byte ptr [eax + 0xb], dl       
  0x01066042  0000                    add      byte ptr [eax], al             
  0x01066044  0084210000f056          add      byte ptr [ecx + 0x56f00000], al 
  0x0106604B  00fb                    add      bl, bh                         
  0x0106604D  0000                    add      byte ptr [eax], al             
  0x0106604F  0080100d0036            add      byte ptr [eax + 0x36000d10], al 
  0x01066055  06                      push     es                             
  0x01066056  0000                    add      byte ptr [eax], al             
  0x01066058  0c00                    or       al, 0                          
  0x0106605A  0000                    add      byte ptr [eax], al             
  0x0106605C  61                      popal                                   
  0x0106605D  f4                      hlt                                     
  0x0106605E  46                      inc      esi                            
  0x0106605F  0010                    add      byte ptr [eax], dl             
  0x01066061  0000                    add      byte ptr [eax], al             
  0x01066063  0000                    add      byte ptr [eax], al             
  0x01066065  07                      pop      es                             
  0x01066066  2300                    and      eax, dword ptr [eax]           
  0x01066068  10d9                    adc      cl, bl                         
  0x0106606A  06                      push     es                             
  0x0106606B  000a                    add      byte ptr [edx], cl             
  0x0106606D  0000                    add      byte ptr [eax], al             
  0x0106606F  007cd950                add      byte ptr [ecx + ebx*8 + 0x50], bh 
  0x01066073  0007                    add      byte ptr [edi], al             
  0x01066075  7405                    je       0x106607c                      
  0x01066077  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x0106607A  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x01066075 (cond_jump)
  0x0106607C  46                      inc      esi                            
  0x0106607D  1e                      push     ds                             
  0x0106607E  0c00                    or       al, 0                          
  0x01066080  90                      nop                                     
  0x01066081  1e                      push     ds                             
  0x01066082  0c00                    or       al, 0                          
  0x01066084  49                      dec      ecx                            
  0x01066085  e421                    in       al, 0x21                       
  0x01066087  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106608A  54                      push     esp                            
  0x0106608B  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106608E  0c00                    or       al, 0                          
  0x01066090  4e                      dec      esi                            
  0x01066091  1e                      push     ds                             
  0x01066092  0c00                    or       al, 0                          
  0x01066094  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x0106609A  0000                    add      byte ptr [eax], al             
  0x0106609C  61                      popal                                   
  0x0106609D  f4                      hlt                                     
                                        ; XREF: 0x010660F0 (cond_jump)
  0x0106609E  46                      inc      esi                            
  0x0106609F  0010                    add      byte ptr [eax], dl             
  0x010660A1  0000                    add      byte ptr [eax], al             
  0x010660A3  0000                    add      byte ptr [eax], al             
  0x010660A5  07                      pop      es                             
  0x010660A6  2300                    and      eax, dword ptr [eax]           
  0x010660A8  7cd9                    jl       0x1066083                      
  0x010660AA  50                      push     eax                            
  0x010660AB  0007                    add      byte ptr [edi], al             
  0x010660AD  7405                    je       0x10660b4                      
  0x010660AF  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x010660B2  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x010660AD (cond_jump)
  0x010660B4  46                      inc      esi                            
  0x010660B5  1e                      push     ds                             
  0x010660B6  0c00                    or       al, 0                          
  0x010660B8  90                      nop                                     
  0x010660B9  1e                      push     ds                             
  0x010660BA  0c00                    or       al, 0                          
  0x010660BC  49                      dec      ecx                            
  0x010660BD  e421                    in       al, 0x21                       
  0x010660BF  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x010660C2  54                      push     esp                            
  0x010660C3  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x010660C6  0c00                    or       al, 0                          
  0x010660C8  4e                      dec      esi                            
  0x010660C9  1e                      push     ds                             
  0x010660CA  0c00                    or       al, 0                          
  0x010660CC  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x010660D2  0000                    add      byte ptr [eax], al             
  0x010660D4  00f4                    add      ah, dh                         
  0x010660D6  46                      inc      esi                            
  0x010660D7  0010                    add      byte ptr [eax], dl             
  0x010660D9  0000                    add      byte ptr [eax], al             
  0x010660DB  0000                    add      byte ptr [eax], al             
  0x010660DD  07                      pop      es                             
  0x010660DE  2300                    and      eax, dword ptr [eax]           
  0x010660E0  10d9                    adc      cl, bl                         
  0x010660E2  06                      push     es                             
  0x010660E3  000d00000000            add      byte ptr [0], cl               
  0x010660E9  d95600                  fst      dword ptr [esi]                
  0x010660EC  6e                      outsb    dx, byte ptr [esi]             
  0x010660ED  1e                      push     ds                             
  0x010660EE  0c00                    or       al, 0                          
  0x010660F0  7cac                    jl       0x106609e                      
  0x010660F2  2000                    and      byte ptr [eax], al             
  0x010660F4  07                      pop      es                             
  0x010660F5  7405                    je       0x10660fc                      
  0x010660F7  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x010660FA  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x010660F5 (cond_jump)
  0x010660FC  46                      inc      esi                            
  0x010660FD  1e                      push     ds                             
  0x010660FE  0c00                    or       al, 0                          
  0x01066100  90                      nop                                     
  0x01066101  1e                      push     ds                             
  0x01066102  0c00                    or       al, 0                          
  0x01066104  49                      dec      ecx                            
  0x01066105  e421                    in       al, 0x21                       
  0x01066107  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106610A  54                      push     esp                            
  0x0106610B  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106610E  0c00                    or       al, 0                          
  0x01066110  4e                      dec      esi                            
  0x01066111  1e                      push     ds                             
  0x01066112  0c00                    or       al, 0                          
  0x01066114  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x0106611A  0000                    add      byte ptr [eax], al             
  0x0106611C  00f4                    add      ah, dh                         
  0x0106611E  46                      inc      esi                            
  0x0106611F  0010                    add      byte ptr [eax], dl             
  0x01066121  0000                    add      byte ptr [eax], al             
  0x01066123  0000                    add      byte ptr [eax], al             
  0x01066125  07                      pop      es                             
                                        ; XREF: 0x01066178 (cond_jump)
  0x01066126  2300                    and      eax, dword ptr [eax]           
  0x01066128  10d9                    adc      cl, bl                         
  0x0106612A  06                      push     es                             
  0x0106612B  000d00000000            add      byte ptr [0], cl               
  0x01066131  d95e00                  fstp     dword ptr [esi]                
  0x01066134  6e                      outsb    dx, byte ptr [esi]             
  0x01066135  1e                      push     ds                             
  0x01066136  0c00                    or       al, 0                          
  0x01066138  7cac                    jl       0x10660e6                      
  0x0106613A  2000                    and      byte ptr [eax], al             
  0x0106613C  07                      pop      es                             
  0x0106613D  7405                    je       0x1066144                      
  0x0106613F  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x01066142  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x0106613D (cond_jump)
  0x01066144  46                      inc      esi                            
  0x01066145  1e                      push     ds                             
  0x01066146  0c00                    or       al, 0                          
  0x01066148  90                      nop                                     
  0x01066149  1e                      push     ds                             
  0x0106614A  0c00                    or       al, 0                          
  0x0106614C  49                      dec      ecx                            
  0x0106614D  e421                    in       al, 0x21                       
  0x0106614F  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x01066152  54                      push     esp                            
  0x01066153  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x01066156  0c00                    or       al, 0                          
  0x01066158  4e                      dec      esi                            
  0x01066159  1e                      push     ds                             
  0x0106615A  0c00                    or       al, 0                          
  0x0106615C  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x01066162  0000                    add      byte ptr [eax], al             
  0x01066164  00f4                    add      ah, dh                         
                                        ; XREF: 0x010661B8 (cond_jump)
  0x01066166  46                      inc      esi                            
  0x01066167  0010                    add      byte ptr [eax], dl             
  0x01066169  0000                    add      byte ptr [eax], al             
  0x0106616B  0000                    add      byte ptr [eax], al             
  0x0106616D  07                      pop      es                             
  0x0106616E  2300                    and      eax, dword ptr [eax]           
  0x01066170  00d9                    add      cl, bl                         
  0x01066172  56                      push     esi                            
  0x01066173  006e1e                  add      byte ptr [esi + 0x1e], ch      
  0x01066176  0c00                    or       al, 0                          
  0x01066178  7cac                    jl       0x1066126                      
  0x0106617A  2000                    and      byte ptr [eax], al             
  0x0106617C  07                      pop      es                             
  0x0106617D  7405                    je       0x1066184                      
  0x0106617F  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x01066182  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x0106617D (cond_jump)
  0x01066184  46                      inc      esi                            
  0x01066185  1e                      push     ds                             
  0x01066186  0c00                    or       al, 0                          
  0x01066188  90                      nop                                     
  0x01066189  1e                      push     ds                             
  0x0106618A  0c00                    or       al, 0                          
  0x0106618C  49                      dec      ecx                            
  0x0106618D  e421                    in       al, 0x21                       
  0x0106618F  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x01066192  54                      push     esp                            
  0x01066193  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x01066196  0c00                    or       al, 0                          
  0x01066198  4e                      dec      esi                            
  0x01066199  1e                      push     ds                             
  0x0106619A  0c00                    or       al, 0                          
  0x0106619C  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x010661A2  0000                    add      byte ptr [eax], al             
  0x010661A4  00f4                    add      ah, dh                         
  0x010661A6  46                      inc      esi                            
  0x010661A7  0010                    add      byte ptr [eax], dl             
  0x010661A9  0000                    add      byte ptr [eax], al             
  0x010661AB  0000                    add      byte ptr [eax], al             
  0x010661AD  07                      pop      es                             
  0x010661AE  2300                    and      eax, dword ptr [eax]           
  0x010661B0  00d9                    add      cl, bl                         
  0x010661B2  5e                      pop      esi                            
  0x010661B3  006e1e                  add      byte ptr [esi + 0x1e], ch      
  0x010661B6  0c00                    or       al, 0                          
  0x010661B8  7cac                    jl       0x1066166                      
  0x010661BA  2000                    and      byte ptr [eax], al             
  0x010661BC  07                      pop      es                             
  0x010661BD  7405                    je       0x10661c4                      
  0x010661BF  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x010661C2  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x010661BD (cond_jump)
  0x010661C4  46                      inc      esi                            
  0x010661C5  1e                      push     ds                             
  0x010661C6  0c00                    or       al, 0                          
  0x010661C8  90                      nop                                     
  0x010661C9  1e                      push     ds                             
  0x010661CA  0c00                    or       al, 0                          
  0x010661CC  49                      dec      ecx                            
  0x010661CD  e421                    in       al, 0x21                       
  0x010661CF  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x010661D2  54                      push     esp                            
  0x010661D3  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x010661D6  0c00                    or       al, 0                          
  0x010661D8  4e                      dec      esi                            
  0x010661D9  1e                      push     ds                             
  0x010661DA  0c00                    or       al, 0                          
  0x010661DC  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x010661E2  0000                    add      byte ptr [eax], al             
  0x010661E4  00f4                    add      ah, dh                         
  0x010661E6  61                      popal                                   
  0x010661E7  0012                    add      byte ptr [edx], dl             
  0x010661E9  0d000000f4              or       eax, 0xf4000000                
  0x010661EE  46                      inc      esi                            
  0x010661EF  00ff                    add      bh, bh                         
  0x010661F1  0000                    add      byte ptr [eax], al             
  0x010661F3  0010                    add      byte ptr [eax], dl             
  0x010661F5  d806                    fadd     dword ptr [esi]                
  0x010661F7  000e                    add      byte ptr [esi], cl             
  0x010661F9  0000                    add      byte ptr [eax], al             
  0x010661FB  00901c0c0056            add      byte ptr [eax + 0x56000c1c], dl 
  0x01066201  0020                    add      byte ptr [eax], ah             
  0x01066203  0000                    add      byte ptr [eax], al             
  0x01066205  d85100                  fcom     dword ptr [ecx]                
  0x01066208  00992100911d            add      byte ptr [ecx + 0x1d910021], bl 
  0x0106620E  0c00                    or       al, 0                          
  0x01066210  00e9                    add      cl, ch                         
  0x01066212  4c                      dec      esp                            
  0x01066213  004b00                  add      byte ptr [ebx], cl             
  0x01066216  2000                    and      byte ptr [eax], al             
  0x01066218  90                      nop                                     
  0x01066219  1c0c                    sbb      al, 0xc                        
  0x0106621B  005600                  add      byte ptr [esi], dl             
  0x0106621E  2000                    and      byte ptr [eax], al             
  0x01066220  00992100911d            add      byte ptr [ecx + 0x1d910021], bl 
  0x01066226  0c00                    or       al, 0                          
  0x01066228  00e9                    add      cl, ch                         
  0x0106622A  4c                      dec      esp                            
  0x0106622B  004b00                  add      byte ptr [ebx], cl             
  0x0106622E  2000                    and      byte ptr [eax], al             
  0x01066230  91                      xchg     ecx, eax                       
  0x01066231  1e                      push     ds                             
  0x01066232  0c00                    or       al, 0                          
  0x01066234  00ae2100111c            add      byte ptr [esi + 0x1c110021], ch 
  0x0106623A  0c00                    or       al, 0                          
  0x0106623C  0c00                    or       al, 0                          
  0x0106623E  0000                    add      byte ptr [eax], al             
  0x01066240  1bf4                    sbb      esi, esp                       
  0x01066242  61                      popal                                   
  0x01066243  0012                    add      byte ptr [edx], dl             
  0x01066245  0e                      push     cs                             
  0x01066246  0000                    add      byte ptr [eax], al             
  0x01066248  00f4                    add      ah, dh                         
  0x0106624A  46                      inc      esi                            
  0x0106624B  00ff                    add      bh, bh                         
  0x0106624D  0000                    add      byte ptr [eax], al             
  0x0106624F  0000                    add      byte ptr [eax], al             
  0x01066251  48                      dec      eax                            
  0x01066252  2000                    and      byte ptr [eax], al             
  0x01066254  10d8                    adc      al, bl                         
  0x01066256  06                      push     es                             
  0x01066257  000d0000005e            add      byte ptr [0x5e000000], cl      
  0x0106625D  ae                      scasb    al, byte ptr es:[edi]          
  0x0106625E  2100                    and      dword ptr [eax], eax           
  0x01066260  00f8                    add      al, bh                         
  0x01066262  44                      inc      esp                            
  0x01066263  0000                    add      byte ptr [eax], al             
  0x01066265  b92100d01e              mov      ecx, 0x1ed00021                
  0x0106626A  0c00                    or       al, 0                          
  0x0106626C  42                      inc      edx                            
  0x0106626D  0020                    add      byte ptr [eax], ah             
  0x0106626F  0000                    add      byte ptr [eax], al             
  0x01066271  e94c004300              jmp      0x14962c2                      
  0x01066276  2000                    and      byte ptr [eax], al             
  0x01066278  56                      push     esi                            
  0x0106627A  2100                    and      dword ptr [eax], eax           
  0x0106627C  00992100d11e            add      byte ptr [ecx + 0x1ed10021], bl 
  0x01066282  0c00                    or       al, 0                          
  0x01066284  00e9                    add      cl, ch                         
  0x01066286  4c                      dec      esp                            
  0x01066287  004b00                  add      byte ptr [ebx], cl             
  0x0106628A  2000                    and      byte ptr [eax], al             
  0x0106628C  91                      xchg     ecx, eax                       
  0x0106628D  1e                      push     ds                             
  0x0106628E  0c00                    or       al, 0                          
  0x01066290  00ae2100111c            add      byte ptr [esi + 0x1c110021], ch 
  0x01066296  0c00                    or       al, 0                          
  0x01066298  0c00                    or       al, 0                          
  0x0106629A  0000                    add      byte ptr [eax], al             
  0x0106629C  7904                    jns      0x10662a2                      
  0x0106629E  0000                    add      byte ptr [eax], al             
  0x010662A0  fa                      cli                                     
  0x010662A1  0300                    add      eax, dword ptr [eax]           
  0x010662A3  0017                    add      byte ptr [edi], dl             
  0x010662A5  0400                    add      al, 0                          
  0x010662A7  003404                  add      byte ptr [esp + eax], dh       
  0x010662AA  0000                    add      byte ptr [eax], al             
  0x010662AC  3b0400                  cmp      eax, dword ptr [eax + eax]     
  0x010662AF  00540400                add      byte ptr [esp + eax], dl       
  0x010662B3  005b04                  add      byte ptr [ebx + 4], bl         
  0x010662B6  0000                    add      byte ptr [eax], al             
  0x010662B8  5e                      pop      esi                            
  0x010662B9  0400                    add      al, 0                          
  0x010662BB  006104                  add      byte ptr [ecx + 4], ah         
  0x010662BE  0000                    add      byte ptr [eax], al             
  0x010662C0  640400                  add      al, 0                          
  0x010662C3  006704                  add      byte ptr [edi + 4], ah         
  0x010662C6  0000                    add      byte ptr [eax], al             
  0x010662C8  6a04                    push     4                              
  0x010662CA  0000                    add      byte ptr [eax], al             
  0x010662CC  6d                      insd     dword ptr es:[edi], dx         
  0x010662CD  0400                    add      al, 0                          
  0x010662CF  007004                  add      byte ptr [eax + 4], dh         
  0x010662D2  0000                    add      byte ptr [eax], al             
  0x010662D4  7304                    jae      0x10662da                      
  0x010662D6  0000                    add      byte ptr [eax], al             
  0x010662D8  7604                    jbe      0x10662de                      
                                        ; XREF: 0x010662D4 (cond_jump)
  0x010662DA  0000                    add      byte ptr [eax], al             
  0x010662DC  00f4                    add      ah, dh                         
                                        ; XREF: 0x010662D8 (cond_jump)
  0x010662DE  7400                    je       0x10662e0                      
                                        ; XREF: 0x010662DE (cond_jump)
  0x010662E0  e103                    loope    0x10662e5                      
  0x010662E2  0000                    add      byte ptr [eax], al             
  0x010662E4  10d8                    adc      al, bl                         
  0x010662E6  06                      push     es                             
  0x010662E7  008600000000            add      byte ptr [esi], al             
  0x010662ED  dd640000                frstor   dword ptr [eax + eax]          
  0x010662F1  e056                    loopne   0x1066349                      
  0x010662F3  0096ec070000            add      byte ptr [esi + 0x7ec], dl     
  0x010662F9  8521                    test     dword ptr [ecx], esp           
  0x010662FB  0080e60a0000            add      byte ptr [eax + 0xae6], al     
  0x01066301  f4                      hlt                                     
  0x01066302  44                      inc      esp                            
  0x01066303  0003                    add      byte ptr [ebx], al             
  0x01066305  0000                    add      byte ptr [eax], al             
  0x01066307  00a0f4620005            add      byte ptr [eax + 0x50062f4], ah 
  0x0106630D  0000                    add      byte ptr [eax], al             
  0x0106630F  0040f0                  add      byte ptr [eax - 0x10], al      
  0x01066312  7200                    jb       0x1066314                      
                                        ; XREF: 0x01066312 (cond_jump)
  0x01066314  0200                    add      al, byte ptr [eax]             
  0x01066316  0000                    add      byte ptr [eax], al             
  0x01066318  224f23                  and      cl, byte ptr [edi + 0x23]      
  0x0106631B  000b                    add      byte ptr [ebx], cl             
  0x0106631D  0139                    add      dword ptr [ecx], edi           
  0x0106631F  0000                    add      byte ptr [eax], al             
  0x01066321  6a54                    push     0x54                           
  0x01066323  000424                  add      byte ptr [esp], al             
  0x01066326  0500007060              add      eax, 0x60700000                
  0x0106632B  000d0000000e            add      byte ptr [0xe000000], cl       
  0x01066331  0c05                    or       al, 5                          
  0x01066333  0000                    add      byte ptr [eax], al             
  0x01066335  f4                      hlt                                     
  0x01066336  66000a                  add      byte ptr [edx], cl             
  0x01066339  0d00000024              or       eax, 0x24000000                
  0x0106633E  2300                    and      eax, dword ptr [eax]           
  0x01066340  4d                      dec      ebp                            
  0x01066341  0239                    add      bh, byte ptr [ecx]             
  0x01066343  0009                    add      byte ptr [ecx], cl             
  0x01066345  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01066346  050000daf0              add      eax, 0xf0da0000                
  0x0106634B  00d0                    add      al, dl                         
  0x0106634F  00d2                    add      dl, dl                         
  0x01066353  00d2                    add      dl, dl                         
  0x01066355  f066000d00000024        lock add byte ptr [0x24000000], cl      
  0x0106635D  1d0c000000              sbb      eax, 0xc                       
  0x01066362  3900                    cmp      dword ptr [eax], eax           
  0x01066364  006650                  add      byte ptr [esi + 0x50], ah      
  0x01066367  0013                    add      byte ptr [ebx], dl             
  0x01066369  7071                    jo       0x10663dc                      
  0x0106636B  0002                    add      byte ptr [edx], al             
  0x0106636D  0000                    add      byte ptr [eax], al             
  0x0106636F  00c3                    add      bl, al                         
  0x01066371  0c05                    or       al, 5                          
  0x01066373  0000                    add      byte ptr [eax], al             
  0x01066375  f4                      hlt                                     
  0x01066376  44                      inc      esp                            
  0x01066377  0005000000a0            add      byte ptr [0xa0000000], al      
  0x0106637D  f4                      hlt                                     
  0x0106637E  6200                    bound    eax, qword ptr [eax]           
  0x01066380  0800                    or       byte ptr [eax], al             
  0x01066382  0000                    add      byte ptr [eax], al             
  0x01066384  40                      inc      eax                            
  0x01066386  7200                    jb       0x1066388                      
                                        ; XREF: 0x01066386 (cond_jump)
  0x01066388  0300                    add      eax, dword ptr [eax]           
  0x0106638A  0000                    add      byte ptr [eax], al             
  0x0106638C  224f23                  and      cl, byte ptr [edi + 0x23]      
  0x0106638F  000b                    add      byte ptr [ebx], cl             
  0x01066391  0139                    add      dword ptr [ecx], edi           
  0x01066393  0000                    add      byte ptr [eax], al             
  0x01066395  6a54                    push     0x54                           
  0x01066397  000424                  add      byte ptr [esp], al             
  0x0106639A  0500007060              add      eax, 0x60700000                
  0x0106639F  000e                    add      byte ptr [esi], cl             
  0x010663A1  0000                    add      byte ptr [eax], al             
  0x010663A3  000e                    add      byte ptr [esi], cl             
  0x010663A5  0c05                    or       al, 5                          
  0x010663A7  0000                    add      byte ptr [eax], al             
  0x010663A9  f4                      hlt                                     
  0x010663AA  66000d0d000000          add      byte ptr [0xd], cl             
  0x010663B1  2423                    and      al, 0x23                       
  0x010663B3  004d02                  add      byte ptr [ebp + 2], cl         
  0x010663B6  3900                    cmp      dword ptr [eax], eax           
  0x010663B8  09a4050000daf0          or       dword ptr [ebp + eax - 0xf260000], esp 
  0x010663BF  00d0                    add      al, dl                         
  0x010663C3  00d2                    add      dl, dl                         
  0x010663C7  00d2                    add      dl, dl                         
  0x010663C9  f066000e                lock add byte ptr [esi], cl             
  0x010663CD  0000                    add      byte ptr [eax], al             
  0x010663CF  0020                    add      byte ptr [eax], ah             
  0x010663D1  1d0c000000              sbb      eax, 0xc                       
  0x010663D6  3900                    cmp      dword ptr [eax], eax           
  0x010663D8  006650                  add      byte ptr [esi + 0x50], ah      
  0x010663DB  0013                    add      byte ptr [ebx], dl             
  0x010663DD  7071                    jo       0x1066450                      
  0x010663DF  0003                    add      byte ptr [ebx], al             
  0x010663E1  0000                    add      byte ptr [eax], al             
  0x010663E3  00860c050000            add      byte ptr [esi + 0x50c], al     
  0x010663E9  f4                      hlt                                     
  0x010663EA  44                      inc      esp                            
  0x010663EB  0007                    add      byte ptr [edi], al             
  0x010663ED  0000                    add      byte ptr [eax], al             
  0x010663EF  00a000200040            add      byte ptr [eax + 0x40002000], ah 
  0x010663F5  0020                    add      byte ptr [eax], ah             
  0x010663F7  0038                    add      byte ptr [eax], bh             
  0x010663F9  1d0c00101c              sbb      eax, 0x1c10000c                
  0x010663FE  0c00                    or       al, 0                          
  0x01066400  5f                      pop      edi                            
  0x01066401  0c05                    or       al, 5                          
  0x01066403  0000                    add      byte ptr [eax], al             
  0x01066405  f4                      hlt                                     
  0x01066406  44                      inc      esp                            
  0x01066407  000b                    add      byte ptr [ebx], cl             
  0x01066409  0000                    add      byte ptr [eax], al             
  0x0106640B  00a0f462000b            add      byte ptr [eax + 0xb0062f4], ah 
  0x01066411  0000                    add      byte ptr [eax], al             
  0x01066413  0040f0                  add      byte ptr [eax - 0x10], al      
  0x01066416  7200                    jb       0x1066418                      
                                        ; XREF: 0x01066416 (cond_jump)
  0x01066418  0400                    add      al, 0                          
  0x0106641A  0000                    add      byte ptr [eax], al             
  0x0106641C  224f23                  and      cl, byte ptr [edi + 0x23]      
  0x0106641F  000b                    add      byte ptr [ebx], cl             
  0x01066421  0139                    add      dword ptr [ecx], edi           
  0x01066423  0000                    add      byte ptr [eax], al             
  0x01066425  f4                      hlt                                     
  0x01066426  660010                  add      byte ptr [eax], dl             
  0x01066429  0d0000006a              or       eax, 0x6a000000                
  0x0106642E  54                      push     esp                            
  0x0106642F  000424                  add      byte ptr [esp], al             
  0x01066432  0500007060              add      eax, 0x60700000                
  0x01066437  000f                    add      byte ptr [edi], cl             
  0x01066439  0000                    add      byte ptr [eax], al             
  0x0106643B  0008                    add      byte ptr [eax], cl             
  0x0106643D  0c05                    or       al, 5                          
  0x0106643F  0000                    add      byte ptr [eax], al             
  0x01066443  00d0                    add      al, dl                         
  0x01066447  00d2                    add      dl, dl                         
  0x01066449  f066000f                lock add byte ptr [edi], cl             
  0x0106644D  0000                    add      byte ptr [eax], al             
  0x0106644F  0020                    add      byte ptr [eax], ah             
  0x01066451  1d0c000000              sbb      eax, 0xc                       
  0x01066456  3900                    cmp      dword ptr [eax], eax           
  0x01066458  006650                  add      byte ptr [esi + 0x50], ah      
  0x0106645B  0013                    add      byte ptr [ebx], dl             
  0x0106645D  7071                    jo       0x10664d0                      
  0x0106645F  000400                  add      byte ptr [eax + eax], al       
  0x01066462  0000                    add      byte ptr [eax], al             
  0x01066464  46                      inc      esi                            
  0x01066465  0c05                    or       al, 5                          
  0x01066467  0000                    add      byte ptr [eax], al             
  0x01066469  f4                      hlt                                     
  0x0106646A  44                      inc      esp                            
  0x0106646B  000f                    add      byte ptr [edi], cl             
  0x0106646D  0000                    add      byte ptr [eax], al             
  0x0106646F  00a000200040            add      byte ptr [eax + 0x40002000], ah 
  0x01066475  0020                    add      byte ptr [eax], ah             
  0x01066477  0036                    add      byte ptr [esi], dh             
  0x01066479  1d0c00101c              sbb      eax, 0x1c10000c                
  0x0106647E  0c00                    or       al, 0                          
  0x01066480  1f                      pop      ds                             
  0x01066481  0c05                    or       al, 5                          
  0x01066483  0000                    add      byte ptr [eax], al             
  0x01066485  f4                      hlt                                     
  0x01066486  56                      push     esi                            
  0x01066487  0000                    add      byte ptr [eax], al             
  0x01066489  000400                  add      byte ptr [eax + eax], al       
  0x0106648C  1b0c050000f456          sbb      ecx, dword ptr [eax + 0x56f40000] 
  0x01066493  0000                    add      byte ptr [eax], al             
  0x01066495  0002                    add      byte ptr [edx], al             
  0x01066497  0018                    add      byte ptr [eax], bl             
  0x01066499  0c05                    or       al, 5                          
  0x0106649B  0000                    add      byte ptr [eax], al             
  0x0106649D  f4                      hlt                                     
  0x0106649E  56                      push     esi                            
  0x0106649F  0000                    add      byte ptr [eax], al             
  0x010664A1  0001                    add      byte ptr [ecx], al             
  0x010664A3  00150c050000            add      byte ptr [0x50c], dl           
  0x010664A9  f4                      hlt                                     
  0x010664AA  56                      push     esi                            
  0x010664AB  0000                    add      byte ptr [eax], al             
  0x010664AD  800000                  add      byte ptr [eax], 0              
  0x010664B0  120c050000f456          adc      cl, byte ptr [eax + 0x56f40000] 
  0x010664B7  0000                    add      byte ptr [eax], al             
  0x010664B9  40                      inc      eax                            
  0x010664BA  0000                    add      byte ptr [eax], al             
  0x010664BD  0c05                    or       al, 5                          
  0x010664BF  0000                    add      byte ptr [eax], al             
  0x010664C1  f4                      hlt                                     
  0x010664C2  56                      push     esi                            
  0x010664C3  0000                    add      byte ptr [eax], al             
  0x010664C5  2000                    and      byte ptr [eax], al             
  0x010664C7  000c0c                  add      byte ptr [esp + ecx], cl       
  0x010664CA  050000f456              add      eax, 0x56f40000                
  0x010664CF  0000                    add      byte ptr [eax], al             
  0x010664D1  1000                    adc      byte ptr [eax], al             
  0x010664D3  0009                    add      byte ptr [ecx], cl             
  0x010664D5  0c05                    or       al, 5                          
  0x010664D7  0000                    add      byte ptr [eax], al             
  0x010664D9  f4                      hlt                                     
  0x010664DA  56                      push     esi                            
  0x010664DB  0000                    add      byte ptr [eax], al             
  0x010664DD  0800                    or       byte ptr [eax], al             
  0x010664DF  0006                    add      byte ptr [esi], al             
  0x010664E1  0c05                    or       al, 5                          
  0x010664E3  0000                    add      byte ptr [eax], al             
  0x010664E5  f4                      hlt                                     
  0x010664E6  56                      push     esi                            
  0x010664E7  0000                    add      byte ptr [eax], al             
  0x010664E9  0400                    add      al, 0                          
  0x010664EB  0003                    add      byte ptr [ebx], al             
  0x010664ED  0c05                    or       al, 5                          
  0x010664EF  0000                    add      byte ptr [eax], al             
  0x010664F1  f4                      hlt                                     
  0x010664F2  56                      push     esi                            
  0x010664F3  0000                    add      byte ptr [eax], al             
  0x010664F5  0100                    add      dword ptr [eax], eax           
  0x010664F7  006000                  add      byte ptr [eax], ah             
  0x010664FA  2000                    and      byte ptr [eax], al             
  0x010664FC  005856                  add      byte ptr [eax + 0x56], bl      
  0x010664FF  000c00                  add      byte ptr [eax + eax], cl       
  0x01066502  0000                    add      byte ptr [eax], al             
  0x01066504  c6040000                mov      byte ptr [eax + eax], 0        
  0x01066508  b204                    mov      dl, 4                          
  0x0106650A  0000                    add      byte ptr [eax], al             
  0x0106650C  a804                    test     al, 4                          
  0x0106650E  0000                    add      byte ptr [eax], al             
  0x01066510  bb0400009e              mov      ebx, 0x9e000004                
  0x01066515  0400                    add      al, 0                          
  0x01066517  00bb040000bb            add      byte ptr [ebx - 0x44fffffc], bh 
  0x0106651D  0400                    add      al, 0                          
  0x0106651F  00bb040000bb            add      byte ptr [ebx - 0x44fffffc], bh 
  0x01066525  0400                    add      al, 0                          
  0x01066527  00bb040000bb            add      byte ptr [ebx - 0x44fffffc], bh 
  0x0106652D  0400                    add      al, 0                          
  0x0106652F  00bb040000bb            add      byte ptr [ebx - 0x44fffffc], bh 
  0x01066535  0400                    add      al, 0                          
  0x01066537  00bb040000bb            add      byte ptr [ebx - 0x44fffffc], bh 
  0x0106653D  0400                    add      al, 0                          
  0x0106653F  00bb04000000            add      byte ptr [ebx + 4], bh         
  0x01066546  6200                    bound    eax, qword ptr [eax]           
  0x01066548  55                      push     ebp                            
  0x01066549  0b00                    or       eax, dword ptr [eax]           
  0x0106654B  0022                    add      byte ptr [edx], ah             
  0x0106654E  0500470b00              add      eax, 0xb4700                   
  0x01066553  0000                    add      byte ptr [eax], al             
  0x01066556  56                      push     esi                            
  0x01066557  00560b                  add      byte ptr [esi + 0xb], dl       
  0x0106655A  0000                    add      byte ptr [eax], al             
  0x0106655C  00f0                    add      al, dh                         
  0x0106655E  45                      inc      ebp                            
  0x0106655F  00570b                  add      byte ptr [edi + 0xb], dl       
  0x01066562  0000                    add      byte ptr [eax], al             
  0x01066564  00f4                    add      ah, dh                         
  0x01066566  46                      inc      esi                            
  0x01066567  0010                    add      byte ptr [eax], dl             
  0x01066569  0000                    add      byte ptr [eax], al             
  0x0106656B  0000                    add      byte ptr [eax], al             
  0x0106656D  f4                      hlt                                     
  0x0106656E  7400                    je       0x1066570                      
                                        ; XREF: 0x0106656E (cond_jump)
  0x01066570  7b04                    jnp      0x1066576                      
  0x01066572  0000                    add      byte ptr [eax], al             
  0x01066574  10d8                    adc      al, bl                         
                                        ; XREF: 0x01066570 (cond_jump)
  0x01066576  06                      push     es                             
  0x01066577  002f                    add      byte ptr [edi], ch             
  0x01066579  0000                    add      byte ptr [eax], al             
  0x0106657B  0000                    add      byte ptr [eax], al             
  0x0106657D  dd640096                frstor   dword ptr [eax + eax - 0x6a]   
  0x01066581  ec                      in       al, dx                         
  0x01066582  07                      pop      es                             
  0x01066583  00c7                    add      bh, al                         
  0x01066585  740b                    je       0x1066592                      
  0x01066587  00fa                    add      dl, bh                         
  0x01066589  0c00                    or       al, 0                          
  0x0106658B  0080e60a0000            add      byte ptr [eax + 0xae6], al     
                                        ; XREF: 0x01066585 (cond_jump)
  0x01066592  57                      push     edi                            
  0x01066593  000400                  add      byte ptr [eax + eax], al       
  0x01066596  0000                    add      byte ptr [eax], al             
  0x01066598  8c4101                  mov      word ptr [ecx + 1], es         
  0x0106659B  0000                    add      byte ptr [eax], al             
  0x0106659D  7055                    jo       0x10665f4                      
  0x0106659F  000400                  add      byte ptr [eax + eax], al       
  0x010665A2  0000                    add      byte ptr [eax], al             
  0x010665A4  43                      inc      ebx                            
  0x010665A5  2405                    and      al, 5                          
  0x010665A7  0000                    add      byte ptr [eax], al             
  0x010665A9  0239                    add      bh, byte ptr [ecx]             
  0x010665AB  0000                    add      byte ptr [eax], al             
  0x010665AD  7071                    jo       0x1066620                      
  0x010665AF  000400                  add      byte ptr [eax + eax], al       
  0x010665B2  0000                    add      byte ptr [eax], al             
  0x010665B4  140c                    adc      al, 0xc                        
  0x010665B6  050000f057              add      eax, 0x57f00000                
  0x010665BB  0003                    add      byte ptr [ebx], al             
  0x010665BD  0000                    add      byte ptr [eax], al             
  0x010665BF  008c4101000070          add      byte ptr [ecx + eax*2 + 0x70000001], cl 
  0x010665C6  55                      push     ebp                            
  0x010665C7  0003                    add      byte ptr [ebx], al             
  0x010665C9  0000                    add      byte ptr [eax], al             
  0x010665CB  0019                    add      byte ptr [ecx], bl             
  0x010665CD  2405                    and      al, 5                          
  0x010665CF  0000                    add      byte ptr [eax], al             
  0x010665D1  0339                    add      edi, dword ptr [ecx]           
  0x010665D3  0000                    add      byte ptr [eax], al             
  0x010665D5  7071                    jo       0x1066648                      
  0x010665D7  0003                    add      byte ptr [ebx], al             
  0x010665D9  0000                    add      byte ptr [eax], al             
  0x010665DB  000a                    add      byte ptr [edx], cl             
  0x010665DD  0c05                    or       al, 5                          
  0x010665DF  0000                    add      byte ptr [eax], al             
  0x010665E2  57                      push     edi                            
  0x010665E3  0002                    add      byte ptr [edx], al             
  0x010665E5  0000                    add      byte ptr [eax], al             
  0x010665E7  008c4101000070          add      byte ptr [ecx + eax*2 + 0x70000001], cl 
  0x010665EE  55                      push     ebp                            
  0x010665EF  0002                    add      byte ptr [edx], al             
  0x010665F1  0000                    add      byte ptr [eax], al             
  0x010665F3  000f                    add      byte ptr [edi], cl             
  0x010665F5  2405                    and      al, 5                          
  0x010665F7  0000                    add      byte ptr [eax], al             
  0x010665F9  0339                    add      edi, dword ptr [ecx]           
  0x010665FB  0000                    add      byte ptr [eax], al             
  0x010665FD  7071                    jo       0x1066670                      
  0x010665FF  0002                    add      byte ptr [edx], al             
  0x01066601  0000                    add      byte ptr [eax], al             
  0x01066603  006900                  add      byte ptr [ecx], ch             
  0x01066606  2000                    and      byte ptr [eax], al             
  0x01066608  7ce0                    jl       0x10665ea                      
  0x0106660A  50                      push     eax                            
  0x0106660B  0007                    add      byte ptr [edi], al             
  0x0106660D  7405                    je       0x1066614                      
  0x0106660F  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x01066612  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x0106660D (cond_jump)
  0x01066614  46                      inc      esi                            
  0x01066615  1e                      push     ds                             
  0x01066616  0c00                    or       al, 0                          
  0x01066618  90                      nop                                     
  0x01066619  1e                      push     ds                             
  0x0106661A  0c00                    or       al, 0                          
  0x0106661C  49                      dec      ecx                            
  0x0106661D  e421                    in       al, 0x21                       
  0x0106661F  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x01066622  54                      push     esp                            
  0x01066623  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x01066626  0c00                    or       al, 0                          
  0x01066628  4e                      dec      esi                            
  0x01066629  1e                      push     ds                             
  0x0106662A  0c00                    or       al, 0                          
  0x0106662C  00a521000058            add      byte ptr [ebp + 0x58000021], ah 
  0x01066632  2000                    and      byte ptr [eax], al             
  0x01066634  007054                  add      byte ptr [eax + 0x54], dh      
  0x01066637  00560b                  add      byte ptr [esi + 0xb], dl       
  0x0106663A  0000                    add      byte ptr [eax], al             
  0x0106663C  007045                  add      byte ptr [eax + 0x45], dh      
  0x0106663F  00570b                  add      byte ptr [edi + 0xb], dl       
  0x01066642  0000                    add      byte ptr [eax], al             
  0x01066644  007062                  add      byte ptr [eax + 0x62], dh      
  0x01066647  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x0106664A  0000                    add      byte ptr [eax], al             
  0x0106664C  22f4                    and      dh, ah                         
  0x0106664E  0500ffff00              add      eax, 0xffff00                  
  0x01066653  000c00                  add      byte ptr [eax + eax], cl       
  0x01066656  0000                    add      byte ptr [eax], al             
  0x01066658  20f4                    and      ah, dh                         
  0x0106665A  0500ffffff              add      eax, 0xffffff00                
  0x0106665F  00a0610400a0            add      byte ptr [eax - 0x5ffffb9f], ah 
  0x01066665  620400                  bound    eax, qword ptr [eax + eax]     
  0x01066668  a0640400a0              mov      al, byte ptr [0xa0000464]      
  0x0106666D  650400                  add      al, 0                          
                                        ; XREF: 0x010665FD (cond_jump)
  0x01066670  a0660400b8              mov      al, byte ptr [0xb8000466]      
  0x01066675  f30000                  add      byte ptr [eax], al             
  0x01066678  00f4                    add      ah, dh                         
  0x0106667A  44                      inc      esp                            
  0x0106667B  0000                    add      byte ptr [eax], al             
  0x0106667D  0000                    add      byte ptr [eax], al             
  0x0106667F  004d00                  add      byte ptr [ebp], cl             
  0x01066682  2000                    and      byte ptr [eax], al             
  0x01066684  0ca4                    or       al, 0xa4                       
  0x01066686  050000f444              add      eax, 0x44f40000                
  0x0106668B  0010                    add      byte ptr [eax], dl             
  0x0106668D  0000                    add      byte ptr [eax], al             
  0x0106668F  004d00                  add      byte ptr [ebp], cl             
  0x01066692  2000                    and      byte ptr [eax], al             
  0x01066694  4a                      dec      edx                            
  0x01066695  100d000f0000            adc      byte ptr [0xf00], cl           
  0x0106669B  0000                    add      byte ptr [eax], al             
  0x0106669D  0030                    add      byte ptr [eax], dh             
  0x0106669F  0000                    add      byte ptr [eax], al             
  0x010666A1  f4                      hlt                                     
  0x010666A2  56                      push     esi                            
  0x010666A3  0000                    add      byte ptr [eax], al             
  0x010666A5  0000                    add      byte ptr [eax], al             
  0x010666A7  0000                    add      byte ptr [eax], al             
  0x010666A9  f4                      hlt                                     
  0x010666AA  57                      push     edi                            
  0x010666AB  00ff                    add      bh, bh                         
  0x010666AE  ff00                    inc      dword ptr [eax]                
  0x010666B0  0c00                    or       al, 0                          
  0x010666B2  0000                    add      byte ptr [eax], al             
  0x010666B4  1300                    adc      eax, dword ptr [eax]           
  0x010666B6  2000                    and      byte ptr [eax], al             
  0x010666B8  0000                    add      byte ptr [eax], al             
  0x010666BA  3000                    xor      byte ptr [eax], al             
  0x010666BC  00f4                    add      ah, dh                         
  0x010666BE  56                      push     esi                            
  0x010666BF  0000                    add      byte ptr [eax], al             
  0x010666C1  0000                    add      byte ptr [eax], al             
  0x010666C3  0000                    add      byte ptr [eax], al             
  0x010666C5  f4                      hlt                                     
  0x010666C6  57                      push     edi                            
  0x010666C7  0008                    add      byte ptr [eax], cl             
  0x010666C9  06                      push     es                             
  0x010666CA  0000                    add      byte ptr [eax], al             
  0x010666CC  0c00                    or       al, 0                          
  0x010666CE  0000                    add      byte ptr [eax], al             
  0x010666D0  00f0                    add      al, dh                         
  0x010666D2  56                      push     esi                            
  0x010666D3  00960b000003            add      byte ptr [esi + 0x300000b], dl 
  0x010666D9  0020                    add      byte ptr [eax], ah             
  0x010666DB  005874                  add      byte ptr [eax + 0x74], bl      
  0x010666DE  0500007060              add      eax, 0x60700000                
  0x010666E3  00450b                  add      byte ptr [ebp + 0xb], al       
  0x010666E6  0000                    add      byte ptr [eax], al             
  0x010666E8  007060                  add      byte ptr [eax + 0x60], dh      
  0x010666EB  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x010666EE  0000                    add      byte ptr [eax], al             
  0x010666F0  00f4                    add      ah, dh                         
  0x010666F2  45                      inc      ebp                            
  0x010666F3  00b007000000            add      byte ptr [eax + 7], dh         
  0x010666F9  7045                    jo       0x1066740                      
  0x010666FB  00720b                  add      byte ptr [edx + 0xb], dh       
  0x010666FE  0000                    add      byte ptr [eax], al             
  0x01066700  00f0                    add      al, dh                         
  0x01066702  56                      push     esi                            
  0x01066703  00400b                  add      byte ptr [eax + 0xb], al       
  0x01066706  0000                    add      byte ptr [eax], al             
  0x01066708  0300                    add      eax, dword ptr [eax]           
  0x0106670A  2400                    and      al, 0                          
  0x0106670C  09240500007044          or       dword ptr [eax + 0x44700000], esp 
  0x01066713  00560b                  add      byte ptr [esi + 0xb], dl       
  0x01066716  0000                    add      byte ptr [eax], al             
  0x01066718  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106671B  00570b                  add      byte ptr [edi + 0xb], dl       
  0x0106671E  0000                    add      byte ptr [eax], al             
  0x01066720  007044                  add      byte ptr [eax + 0x44], dh      
  0x01066723  009d0b000080            add      byte ptr [ebp - 0x7ffffff5], bl 
  0x01066729  100d008c0000            adc      byte ptr [0x8c00], cl          
  0x0106672F  0080100d0029            add      byte ptr [eax + 0x29000d10], al 
  0x01066735  0100                    add      dword ptr [eax], eax           
  0x01066737  0080100d009e            add      byte ptr [eax - 0x61fff2f0], al 
  0x0106673D  0100                    add      dword ptr [eax], eax           
  0x0106673F  0080100d0066            add      byte ptr [eax + 0x66000d10], al 
  0x01066745  0300                    add      eax, dword ptr [eax]           
  0x01066747  0000                    add      byte ptr [eax], al             
  0x0106674A  56                      push     esi                            
  0x0106674B  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106674E  0000                    add      byte ptr [eax], al             
  0x01066750  854501                  test     dword ptr [ebp + 1], eax       
  0x01066753  0003                    add      byte ptr [ebx], al             
  0x01066755  2405                    and      al, 5                          
  0x01066757  0080100d0093            add      byte ptr [eax - 0x6cfff2f0], al 
  0x0106675D  0300                    add      eax, dword ptr [eax]           
  0x0106675F  0000                    add      byte ptr [eax], al             
  0x01066762  56                      push     esi                            
  0x01066763  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x01066766  0000                    add      byte ptr [eax], al             
  0x01066768  00f0                    add      al, dh                         
  0x0106676A  44                      inc      esp                            
  0x0106676B  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106676E  0000                    add      byte ptr [eax], al             
  0x01066770  44                      inc      esp                            
  0x01066771  0020                    add      byte ptr [eax], ah             
  0x01066773  0000                    add      byte ptr [eax], al             
  0x01066775  7054                    jo       0x10667cb                      
  0x01066777  00580b                  add      byte ptr [eax + 0xb], bl       
  0x0106677A  0000                    add      byte ptr [eax], al             
  0x0106677C  80100d                  adc      byte ptr [eax], 0xd            
  0x0106677F  00d0                    add      al, dl                         
  0x01066781  0300                    add      eax, dword ptr [eax]           
  0x01066783  0000                    add      byte ptr [eax], al             
  0x01066786  56                      push     esi                            
  0x01066787  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106678A  0000                    add      byte ptr [eax], al             
  0x0106678C  854501                  test     dword ptr [ebp + 1], eax       
  0x0106678F  000b                    add      byte ptr [ebx], cl             
  0x01066791  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01066792  050000f044              add      eax, 0x44f00000                
  0x01066797  00580b                  add      byte ptr [eax + 0xb], bl       
  0x0106679A  0000                    add      byte ptr [eax], al             
  0x0106679C  00f4                    add      ah, dh                         
  0x0106679E  45                      inc      ebp                            
  0x0106679F  0010                    add      byte ptr [eax], dl             
  0x010667A1  0000                    add      byte ptr [eax], al             
  0x010667A3  00a0f044009d            add      byte ptr [eax - 0x62ffbb10], ah 
  0x010667A9  0b00                    or       eax, dword ptr [eax]           
  0x010667AB  002e                    add      byte ptr [esi], ch             
  0x010667AD  1d0c004000              sbb      eax, 0x40000c                  
  0x010667B2  2000                    and      byte ptr [eax], al             
  0x010667B4  007056                  add      byte ptr [eax + 0x56], dh      
  0x010667B7  009d0b000080            add      byte ptr [ebp - 0x7ffffff5], bl 
  0x010667BD  100d00080000            adc      byte ptr [0x800], cl           
  0x010667C3  000c00                  add      byte ptr [eax + eax], cl       
  0x010667C6  0000                    add      byte ptr [eax], al             
  0x010667C8  00f4                    add      ah, dh                         
  0x010667CA  44                      inc      esp                            
                                        ; XREF: 0x01066775 (cond_jump)
  0x010667CB  0000                    add      byte ptr [eax], al             
  0x010667CD  0100                    add      dword ptr [eax], eax           
  0x010667CF  0000                    add      byte ptr [eax], al             
  0x010667D1  7044                    jo       0x1066817                      
  0x010667D3  0010                    add      byte ptr [eax], dl             
  0x010667D5  0000                    add      byte ptr [eax], al             
  0x010667D7  000c00                  add      byte ptr [eax + eax], cl       
  0x010667DA  0000                    add      byte ptr [eax], al             
  0x010667DC  00f0                    add      al, dh                         
  0x010667DE  56                      push     esi                            
  0x010667DF  00960b000003            add      byte ptr [esi + 0x300000b], dl 
  0x010667E5  0020                    add      byte ptr [eax], ah             
  0x010667E7  0007                    add      byte ptr [edi], al             
  0x010667E9  f4                      hlt                                     
  0x010667EA  050013f044              add      eax, 0x44f01300                
  0x010667EF  00450b                  add      byte ptr [ebp + 0xb], al       
  0x010667F2  0000                    add      byte ptr [eax], al             
  0x010667F4  007044                  add      byte ptr [eax + 0x44], dh      
  0x010667F7  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x010667FA  0000                    add      byte ptr [eax], al             
  0x010667FC  007054                  add      byte ptr [eax + 0x54], dh      
  0x010667FF  009a0b000000            add      byte ptr [edx + 0xb], bl       
  0x01066805  f4                      hlt                                     
  0x01066806  60                      pushal                                  
  0x01066807  0011                    add      byte ptr [ecx], dl             
  0x01066809  0000                    add      byte ptr [eax], al             
  0x0106680B  0000                    add      byte ptr [eax], al             
  0x0106680D  f4                      hlt                                     
  0x0106680E  44                      inc      esp                            
  0x0106680F  000d00000000            add      byte ptr [0], cl               
  0x01066815  58                      pop      eax                            
  0x01066816  44                      inc      esp                            
                                        ; XREF: 0x010667D1 (cond_jump)
  0x01066817  0000                    add      byte ptr [eax], al             
  0x0106681A  56                      push     esi                            
  0x0106681B  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x0106681E  0000                    add      byte ptr [eax], al             
  0x01066820  00f0                    add      al, dh                         
  0x01066822  44                      inc      esp                            
  0x01066823  00450b                  add      byte ptr [ebp + 0xb], al       
  0x01066826  0000                    add      byte ptr [eax], al             
  0x01066828  44                      inc      esp                            
  0x01066829  0020                    add      byte ptr [eax], ah             
  0x0106682B  0000                    add      byte ptr [eax], al             
  0x0106682D  58                      pop      eax                            
  0x0106682E  54                      push     esp                            
  0x0106682F  0000                    add      byte ptr [eax], al             
  0x01066832  44                      inc      esp                            
  0x01066833  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x01066836  0000                    add      byte ptr [eax], al             
  0x01066838  005844                  add      byte ptr [eax + 0x44], bl      
  0x0106683B  0000                    add      byte ptr [eax], al             
  0x0106683D  002400                  add      byte ptr [eax + eax], ah       
  0x01066840  005844                  add      byte ptr [eax + 0x44], bl      
  0x01066843  0000                    add      byte ptr [eax], al             
  0x01066845  58                      pop      eax                            
  0x01066846  44                      inc      esp                            
  0x01066847  0000                    add      byte ptr [eax], al             
  0x01066849  58                      pop      eax                            
  0x0106684A  44                      inc      esp                            
  0x0106684B  0000                    add      byte ptr [eax], al             
  0x0106684D  58                      pop      eax                            
  0x0106684E  44                      inc      esp                            
  0x0106684F  0013                    add      byte ptr [ebx], dl             
  0x01066851  f4                      hlt                                     
  0x01066852  44                      inc      esp                            
  0x01066853  0009                    add      byte ptr [ecx], cl             
  0x01066855  0000                    add      byte ptr [eax], al             
  0x01066857  0000                    add      byte ptr [eax], al             
  0x01066859  7044                    jo       0x106689f                      
  0x0106685B  001e                    add      byte ptr [esi], bl             
  0x0106685D  0000                    add      byte ptr [eax], al             
  0x0106685F  0000                    add      byte ptr [eax], al             
  0x01066862  44                      inc      esp                            
  0x01066863  001e                    add      byte ptr [esi], bl             
  0x01066865  0000                    add      byte ptr [eax], al             
  0x01066867  004019                  add      byte ptr [eax + 0x19], al      
  0x0106686A  0c00                    or       al, 0                          
  0x0106686C  184000                  sbb      byte ptr [eax], al             
  0x0106686F  0000                    add      byte ptr [eax], al             
  0x01066871  58                      pop      eax                            
  0x01066872  54                      push     esp                            
  0x01066873  0000                    add      byte ptr [eax], al             
  0x01066875  002400                  add      byte ptr [eax + eax], ah       
  0x01066878  005844                  add      byte ptr [eax + 0x44], bl      
  0x0106687B  001b                    add      byte ptr [ebx], bl             
  0x0106687D  0020                    add      byte ptr [eax], ah             
  0x0106687F  0013                    add      byte ptr [ebx], dl             
  0x01066881  0020                    add      byte ptr [eax], ah             
  0x01066883  00df                    add      bh, bl                         
  0x01066885  1e                      push     ds                             
  0x01066886  0c00                    or       al, 0                          
  0x01066888  00a4210040190c          add      byte ptr [ecx + 0xc194000], ah 
  0x0106688F  0020                    add      byte ptr [eax], ah             
  0x01066891  800000                  add      byte ptr [eax], 0              
  0x01066894  1b00                    sbb      eax, dword ptr [eax]           
  0x01066896  2000                    and      byte ptr [eax], al             
  0x01066898  df1e                    fistp    word ptr [esi]                 
  0x0106689A  0c00                    or       al, 0                          
  0x0106689C  00a4210040190c          add      byte ptr [ecx + 0xc194000], ah 
  0x010668A3  0018                    add      byte ptr [eax], bl             
  0x010668A5  800000                  add      byte ptr [eax], 0              
  0x010668A8  005854                  add      byte ptr [eax + 0x54], bl      
  0x010668AB  0013                    add      byte ptr [ebx], dl             
  0x010668AE  57                      push     edi                            
  0x010668AF  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x010668B2  0000                    add      byte ptr [eax], al             
  0x010668B4  0bf4                    or       esi, esp                       
  0x010668B6  45                      inc      ebp                            
  0x010668B7  008000000007            add      byte ptr [eax + 0x7000000], al 
  0x010668BD  2405                    and      al, 5                          
  0x010668BF  001b                    add      byte ptr [ebx], bl             
  0x010668C1  0020                    add      byte ptr [eax], ah             
  0x010668C3  00a11c0c0068            add      byte ptr [ecx + 0x68000c1c], ah 
  0x010668C9  0020                    add      byte ptr [eax], ah             
  0x010668CB  0000                    add      byte ptr [eax], al             
  0x010668CD  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010668CE  2100                    and      dword ptr [eax], eax           
  0x010668D0  40                      inc      eax                            
  0x010668D1  190c00                  sbb      dword ptr [eax + eax], ecx     
  0x010668D4  208000001b00            and      byte ptr [eax + 0x1b0000], al  
  0x010668DA  2000                    and      byte ptr [eax], al             
  0x010668DC  a11c0c0068              mov      eax, dword ptr [0x68000c1c]    
  0x010668E1  0020                    add      byte ptr [eax], ah             
  0x010668E3  0000                    add      byte ptr [eax], al             
  0x010668E5  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010668E6  2100                    and      dword ptr [eax], eax           
  0x010668E8  40                      inc      eax                            
  0x010668E9  190c00                  sbb      dword ptr [eax + eax], ecx     
  0x010668EC  188000000058            sbb      byte ptr [eax + 0x58000000], al 
  0x010668F2  54                      push     esp                            
  0x010668F3  0013                    add      byte ptr [ebx], dl             
  0x010668F6  57                      push     edi                            
  0x010668F7  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x010668FA  0000                    add      byte ptr [eax], al             
  0x010668FC  0b00                    or       eax, dword ptr [eax]           
  0x010668FE  2000                    and      byte ptr [eax], al             
  0x01066900  07                      pop      es                             
  0x01066901  2405                    and      al, 5                          
  0x01066903  001b                    add      byte ptr [ebx], bl             
  0x01066905  0020                    add      byte ptr [eax], ah             
  0x01066907  00a11c0c0068            add      byte ptr [ecx + 0x68000c1c], ah 
  0x0106690D  0020                    add      byte ptr [eax], ah             
  0x0106690F  0000                    add      byte ptr [eax], al             
  0x01066911  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01066912  2100                    and      dword ptr [eax], eax           
  0x01066914  40                      inc      eax                            
  0x01066915  190c00                  sbb      dword ptr [eax + eax], ecx     
  0x01066918  20800000a11c            and      byte ptr [eax + 0x1ca10000], al 
  0x0106691E  0c00                    or       al, 0                          
  0x01066920  6800200000              push     0x2000                         
  0x01066925  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01066926  2100                    and      dword ptr [eax], eax           
  0x01066928  40                      inc      eax                            
  0x01066929  190c00                  sbb      dword ptr [eax + eax], ecx     
  0x0106692C  188000000058            sbb      byte ptr [eax + 0x58000000], al 
  0x01066932  54                      push     esp                            
  0x01066933  0013                    add      byte ptr [ebx], dl             
  0x01066935  0020                    add      byte ptr [eax], ah             
  0x01066937  0000                    add      byte ptr [eax], al             
  0x01066939  58                      pop      eax                            
  0x0106693A  54                      push     esp                            
  0x0106693B  0000                    add      byte ptr [eax], al             
  0x0106693D  f4                      hlt                                     
  0x0106693E  60                      pushal                                  
  0x0106693F  0011                    add      byte ptr [ecx], dl             
  0x01066941  0000                    add      byte ptr [eax], al             
  0x01066943  0000                    add      byte ptr [eax], al             
  0x01066946  56                      push     esi                            
  0x01066947  00960b000000            add      byte ptr [esi + 0xb], dl       
  0x0106694D  f4                      hlt                                     
  0x0106694E  57                      push     edi                            
  0x0106694F  0008                    add      byte ptr [eax], cl             
  0x01066951  06                      push     es                             
  0x01066952  0000                    add      byte ptr [eax], al             
  0x01066954  0c00                    or       al, 0                          
  0x01066956  0000                    add      byte ptr [eax], al             
  0x01066958  00f0                    add      al, dh                         
  0x0106695A  6200                    bound    eax, qword ptr [eax]           
  0x0106695C  45                      inc      ebp                            
  0x0106695D  0b00                    or       eax, dword ptr [eax]           
  0x0106695F  0022                    add      byte ptr [edx], ah             
  0x01066962  0500470b00              add      eax, 0xb4700                   
  0x01066967  0000                    add      byte ptr [eax], al             
  0x01066969  f4                      hlt                                     
  0x0106696A  57                      push     edi                            
  0x0106696B  0010                    add      byte ptr [eax], dl             
  0x0106696D  0000                    add      byte ptr [eax], al             
  0x0106696F  0000                    add      byte ptr [eax], al             
  0x01066971  00250000f444            add      byte ptr [0x44f40000], ah      
  0x01066977  00770b                  add      byte ptr [edi + 0xb], dh       
  0x0106697A  0000                    add      byte ptr [eax], al             
  0x0106697C  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106697F  0000                    add      byte ptr [eax], al             
  0x01066981  0000                    add      byte ptr [eax], al             
  0x01066983  0000                    add      byte ptr [eax], al             
  0x01066985  f4                      hlt                                     
  0x01066986  44                      inc      esp                            
  0x01066987  0000                    add      byte ptr [eax], al             
  0x01066989  0000                    add      byte ptr [eax], al             
  0x0106698B  0000                    add      byte ptr [eax], al             
  0x0106698D  7044                    jo       0x10669d3                      
  0x0106698F  00540b00                add      byte ptr [ebx + ecx], dl       
  0x01066993  0000                    add      byte ptr [eax], al             
  0x01066995  f4                      hlt                                     
  0x01066996  61                      popal                                   
  0x01066997  0000                    add      byte ptr [eax], al             
  0x01066999  0000                    add      byte ptr [eax], al             
  0x0106699B  0000                    add      byte ptr [eax], al             
  0x0106699D  1038                    adc      byte ptr [eax], bh             
  0x0106699F  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x010669A5  f4                      hlt                                     
  0x010669A6  61                      popal                                   
  0x010669A7  00540b00                add      byte ptr [ebx + ecx], dl       
  0x010669AB  0000                    add      byte ptr [eax], al             
  0x010669AD  1038                    adc      byte ptr [eax], bh             
  0x010669AF  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x010669B5  f4                      hlt                                     
  0x010669B6  61                      popal                                   
  0x010669B7  007b0b                  add      byte ptr [ebx + 0xb], bh       
  0x010669BA  0000                    add      byte ptr [eax], al             
  0x010669BC  0002                    add      byte ptr [edx], al             
  0x010669BE  3800                    cmp      byte ptr [eax], al             
  0x010669C0  93                      xchg     ebx, eax                       
  0x010669C1  030d0000f461            add      ecx, dword ptr [0x61f40000]    
  0x010669C7  007c0b00                add      byte ptr [ebx + ecx], bh       
  0x010669CB  0000                    add      byte ptr [eax], al             
  0x010669CD  06                      push     es                             
  0x010669CE  3800                    cmp      byte ptr [eax], al             
  0x010669D0  93                      xchg     ebx, eax                       
  0x010669D1  030d00000428            add      ecx, dword ptr [0x28040000]    
  0x010669D7  0000                    add      byte ptr [eax], al             
  0x010669D9  7050                    jo       0x1066a2b                      
  0x010669DB  001e                    add      byte ptr [esi], bl             
  0x010669DD  0000                    add      byte ptr [eax], al             
  0x010669DF  0000                    add      byte ptr [eax], al             
  0x010669E1  f4                      hlt                                     
  0x010669E2  61                      popal                                   
  0x010669E3  001e                    add      byte ptr [esi], bl             
  0x010669E5  0000                    add      byte ptr [eax], al             
  0x010669E7  0000                    add      byte ptr [eax], al             
  0x010669E9  0538009303              add      eax, 0x3930038                 
  0x010669EE  0d00000028              or       eax, 0x28000000                
  0x010669F3  0000                    add      byte ptr [eax], al             
  0x010669F5  7050                    jo       0x1066a47                      
  0x010669F7  001e                    add      byte ptr [esi], bl             
  0x010669F9  0000                    add      byte ptr [eax], al             
  0x010669FB  0000                    add      byte ptr [eax], al             
  0x010669FD  f4                      hlt                                     
  0x010669FE  61                      popal                                   
  0x010669FF  001e                    add      byte ptr [esi], bl             
  0x01066A01  0000                    add      byte ptr [eax], al             
  0x01066A03  0000                    add      byte ptr [eax], al             
  0x01066A05  0338                    add      edi, dword ptr [eax]           
  0x01066A07  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x01066A0D  f4                      hlt                                     
  0x01066A0E  61                      popal                                   
  0x01066A0F  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x01066A12  0000                    add      byte ptr [eax], al             
  0x01066A14  0003                    add      byte ptr [ebx], al             
  0x01066A16  3800                    cmp      byte ptr [eax], al             
  0x01066A18  93                      xchg     ebx, eax                       
  0x01066A19  030d0000f056            add      ecx, dword ptr [0x56f00000]    
  0x01066A1F  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x01066A22  0000                    add      byte ptr [eax], al             
  0x01066A24  854101                  test     dword ptr [ecx + 1], eax       
  0x01066A27  000a                    add      byte ptr [edx], cl             
  0x01066A29  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01066A2A  0500864101              add      eax, 0x1418600                 
  0x01066A2F  0008                    add      byte ptr [eax], cl             
  0x01066A31  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01066A32  0500000028              add      eax, 0x28000000                
  0x01066A37  0000                    add      byte ptr [eax], al             
  0x01066A39  7050                    jo       0x1066a8b                      
  0x01066A3B  001e                    add      byte ptr [esi], bl             
  0x01066A3D  0000                    add      byte ptr [eax], al             
  0x01066A3F  0000                    add      byte ptr [eax], al             
  0x01066A41  f4                      hlt                                     
  0x01066A42  61                      popal                                   
  0x01066A43  001e                    add      byte ptr [esi], bl             
  0x01066A45  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x010669F5 (cond_jump)
  0x01066A47  0000                    add      byte ptr [eax], al             
  0x01066A49  0238                    add      bh, byte ptr [eax]             
  0x01066A4B  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x01066A52  56                      push     esi                            
  0x01066A53  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x01066A56  0000                    add      byte ptr [eax], al             
  0x01066A58  86440100                xchg     byte ptr [ecx + eax], al       
  0x01066A5C  08a40500000028          or       byte ptr [ebp + eax + 0x28000000], ah 
  0x01066A63  0000                    add      byte ptr [eax], al             
  0x01066A65  7050                    jo       0x1066ab7                      
  0x01066A67  001e                    add      byte ptr [esi], bl             
  0x01066A69  0000                    add      byte ptr [eax], al             
  0x01066A6B  0000                    add      byte ptr [eax], al             
  0x01066A6D  f4                      hlt                                     
  0x01066A6E  61                      popal                                   
  0x01066A6F  001e                    add      byte ptr [esi], bl             
  0x01066A71  0000                    add      byte ptr [eax], al             
  0x01066A73  0000                    add      byte ptr [eax], al             
  0x01066A75  0238                    add      bh, byte ptr [eax]             
  0x01066A77  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x01066A7E  56                      push     esi                            
  0x01066A7F  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x01066A82  0000                    add      byte ptr [eax], al             
  0x01066A84  854201                  test     dword ptr [edx + 1], eax       
  0x01066A87  000524050000            add      byte ptr [0x524], al           
  0x01066A8D  f4                      hlt                                     
  0x01066A8E  61                      popal                                   
  0x01066A8F  004e0b                  add      byte ptr [esi + 0xb], cl       
  0x01066A92  0000                    add      byte ptr [eax], al             
  0x01066A94  0002                    add      byte ptr [edx], al             
  0x01066A96  3800                    cmp      byte ptr [eax], al             
  0x01066A98  93                      xchg     ebx, eax                       
  0x01066A99  030d0000f461            add      ecx, dword ptr [0x61f40000]    
  0x01066A9F  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x01066AA2  0000                    add      byte ptr [eax], al             
  0x01066AA4  0001                    add      byte ptr [ecx], al             
  0x01066AA6  3800                    cmp      byte ptr [eax], al             
  0x01066AA8  93                      xchg     ebx, eax                       
  0x01066AA9  030d0000f461            add      ecx, dword ptr [0x61f40000]    
  0x01066AAF  00490b                  add      byte ptr [ecx + 0xb], cl       
  0x01066AB2  0000                    add      byte ptr [eax], al             
  0x01066AB4  000538009303            add      byte ptr [0x3930038], al       
  0x01066ABA  0d0000f461              or       eax, 0x61f40000                
  0x01066ABF  004c0b00                add      byte ptr [ebx + ecx], cl       
  0x01066AC3  0000                    add      byte ptr [eax], al             
  0x01066AC5  0138                    add      dword ptr [eax], edi           
  0x01066AC7  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x01066ACE  56                      push     esi                            
  0x01066ACF  004c0b00                add      byte ptr [ebx + ecx], cl       
  0x01066AD3  0003                    add      byte ptr [ebx], al             
  0x01066AD5  0020                    add      byte ptr [eax], ah             
  0x01066AD7  0005a4050000            add      byte ptr [0x5a4], al           
  0x01066ADD  f4                      hlt                                     
  0x01066ADE  61                      popal                                   
  0x01066ADF  004d0b                  add      byte ptr [ebp + 0xb], cl       
  0x01066AE2  0000                    add      byte ptr [eax], al             
  0x01066AE4  0008                    add      byte ptr [eax], cl             
  0x01066AE6  3800                    cmp      byte ptr [eax], al             
  0x01066AE8  93                      xchg     ebx, eax                       
  0x01066AE9  030d00000028            add      ecx, dword ptr [0x28000000]    
  0x01066AEF  0000                    add      byte ptr [eax], al             
  0x01066AF1  7050                    jo       0x1066b43                      
  0x01066AF3  001e                    add      byte ptr [esi], bl             
  0x01066AF5  0000                    add      byte ptr [eax], al             
  0x01066AF7  0000                    add      byte ptr [eax], al             
  0x01066AF9  f4                      hlt                                     
  0x01066AFA  61                      popal                                   
  0x01066AFB  001e                    add      byte ptr [esi], bl             
  0x01066AFD  0000                    add      byte ptr [eax], al             
  0x01066AFF  0000                    add      byte ptr [eax], al             
  0x01066B01  0138                    add      dword ptr [eax], edi           
  0x01066B03  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x01066B09  0028                    add      byte ptr [eax], ch             
  0x01066B0B  0000                    add      byte ptr [eax], al             
  0x01066B0D  7050                    jo       0x1066b5f                      
  0x01066B0F  001e                    add      byte ptr [esi], bl             
  0x01066B11  0000                    add      byte ptr [eax], al             
  0x01066B13  0000                    add      byte ptr [eax], al             
  0x01066B15  f4                      hlt                                     
  0x01066B16  61                      popal                                   
  0x01066B17  001e                    add      byte ptr [esi], bl             
  0x01066B19  0000                    add      byte ptr [eax], al             
  0x01066B1B  0000                    add      byte ptr [eax], al             
  0x01066B1D  0138                    add      dword ptr [eax], edi           
  0x01066B1F  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x01066B25  0028                    add      byte ptr [eax], ch             
  0x01066B27  0000                    add      byte ptr [eax], al             
  0x01066B29  7050                    jo       0x1066b7b                      
  0x01066B2B  001e                    add      byte ptr [esi], bl             
  0x01066B2D  0000                    add      byte ptr [eax], al             
  0x01066B2F  0000                    add      byte ptr [eax], al             
  0x01066B31  f4                      hlt                                     
  0x01066B32  61                      popal                                   
  0x01066B33  001e                    add      byte ptr [esi], bl             
  0x01066B35  0000                    add      byte ptr [eax], al             
  0x01066B37  0000                    add      byte ptr [eax], al             
  0x01066B39  0138                    add      dword ptr [eax], edi           
  0x01066B3B  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x01066B41  0128                    add      dword ptr [eax], ebp           
                                        ; XREF: 0x01066AF1 (cond_jump)
  0x01066B43  0000                    add      byte ptr [eax], al             
  0x01066B45  7050                    jo       0x1066b97                      
  0x01066B47  001e                    add      byte ptr [esi], bl             
  0x01066B49  0000                    add      byte ptr [eax], al             
  0x01066B4B  0000                    add      byte ptr [eax], al             
  0x01066B4D  f4                      hlt                                     
  0x01066B4E  61                      popal                                   
  0x01066B4F  001e                    add      byte ptr [esi], bl             
  0x01066B51  0000                    add      byte ptr [eax], al             
  0x01066B53  0000                    add      byte ptr [eax], al             
  0x01066B55  0138                    add      dword ptr [eax], edi           
  0x01066B57  0093030d0013            add      byte ptr [ebx + 0x13000d03], dl 
  0x01066B5D  0020                    add      byte ptr [eax], ah             
                                        ; XREF: 0x01066B0D (cond_jump)
  0x01066B5F  0000                    add      byte ptr [eax], al             
  0x01066B61  7056                    jo       0x1066bb9                      
  0x01066B63  001e                    add      byte ptr [esi], bl             
  0x01066B65  0000                    add      byte ptr [eax], al             
  0x01066B67  0000                    add      byte ptr [eax], al             
  0x01066B69  f4                      hlt                                     
  0x01066B6A  61                      popal                                   
  0x01066B6B  001e                    add      byte ptr [esi], bl             
  0x01066B6D  0000                    add      byte ptr [eax], al             
  0x01066B6F  0000                    add      byte ptr [eax], al             
  0x01066B71  0138                    add      dword ptr [eax], edi           
  0x01066B73  0093030d0013            add      byte ptr [ebx + 0x13000d03], dl 
  0x01066B79  0020                    add      byte ptr [eax], ah             
                                        ; XREF: 0x01066B29 (cond_jump)
  0x01066B7B  0000                    add      byte ptr [eax], al             
  0x01066B7D  7056                    jo       0x1066bd5                      
  0x01066B7F  001e                    add      byte ptr [esi], bl             
  0x01066B81  0000                    add      byte ptr [eax], al             
  0x01066B83  0000                    add      byte ptr [eax], al             
  0x01066B85  f4                      hlt                                     
  0x01066B86  61                      popal                                   
  0x01066B87  001e                    add      byte ptr [esi], bl             
  0x01066B89  0000                    add      byte ptr [eax], al             
  0x01066B8B  0000                    add      byte ptr [eax], al             
  0x01066B8D  0138                    add      dword ptr [eax], edi           
  0x01066B8F  0093030d0013            add      byte ptr [ebx + 0x13000d03], dl 
  0x01066B95  0020                    add      byte ptr [eax], ah             
                                        ; XREF: 0x01066B45 (cond_jump)
  0x01066B97  0000                    add      byte ptr [eax], al             
  0x01066B99  7050                    jo       0x1066beb                      
  0x01066B9B  001e                    add      byte ptr [esi], bl             
  0x01066B9D  0000                    add      byte ptr [eax], al             
  0x01066B9F  0000                    add      byte ptr [eax], al             
  0x01066BA1  f4                      hlt                                     
  0x01066BA2  61                      popal                                   
  0x01066BA3  001e                    add      byte ptr [esi], bl             
  0x01066BA5  0000                    add      byte ptr [eax], al             
  0x01066BA7  0000                    add      byte ptr [eax], al             
  0x01066BA9  0138                    add      dword ptr [eax], edi           
  0x01066BAB  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x01066BB1  7045                    jo       0x1066bf8                      
  0x01066BB3  00560b                  add      byte ptr [esi + 0xb], dl       
  0x01066BB6  0000                    add      byte ptr [eax], al             
  0x01066BB8  007057                  add      byte ptr [eax + 0x57], dh      
  0x01066BBB  00570b                  add      byte ptr [edi + 0xb], dl       
  0x01066BBE  0000                    add      byte ptr [eax], al             
  0x01066BC0  007062                  add      byte ptr [eax + 0x62], dh      
  0x01066BC3  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x01066BC6  0000                    add      byte ptr [eax], al             
  0x01066BC8  22f4                    and      dh, ah                         
  0x01066BCA  0500ffff00              add      eax, 0xffff00                  
  0x01066BCF  000c00                  add      byte ptr [eax + eax], cl       
  0x01066BD2  0000                    add      byte ptr [eax], al             
  0x01066BD4  1300                    adc      eax, dword ptr [eax]           
  0x01066BD6  2000                    and      byte ptr [eax], al             
  0x01066BD8  007056                  add      byte ptr [eax + 0x56], dh      
  0x01066BDB  0002                    add      byte ptr [edx], al             
  0x01066BDD  0000                    add      byte ptr [eax], al             
  0x01066BDF  0000                    add      byte ptr [eax], al             
  0x01066BE1  7056                    jo       0x1066c39                      
  0x01066BE3  0003                    add      byte ptr [ebx], al             
  0x01066BE5  0000                    add      byte ptr [eax], al             
  0x01066BE7  0000                    add      byte ptr [eax], al             
  0x01066BE9  7056                    jo       0x1066c41                      
                                        ; XREF: 0x01066B99 (cond_jump)
  0x01066BEB  000400                  add      byte ptr [eax + eax], al       
  0x01066BEE  0000                    add      byte ptr [eax], al             
  0x01066BF0  0000                    add      byte ptr [eax], al             
  0x01066BF2  360000                  add      byte ptr ss:[eax], al          
  0x01066BF6  44                      inc      esp                            
  0x01066BF7  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x01066BFD  c406                    les      eax, ptr [esi]                 
  0x01066BFF  001d00000000            add      byte ptr [0], bl               
  0x01066C05  f4                      hlt                                     
  0x01066C06  56                      push     esi                            
  0x01066C07  00a50b000000            add      byte ptr [ebp + 0xb], ah       
  0x01066C0D  c422                    les      esp, ptr [edx]                 
  0x01066C0F  004000                  add      byte ptr [eax], al             
  0x01066C12  2000                    and      byte ptr [eax], al             
  0x01066C14  0090210000e0            add      byte ptr [eax - 0x1fffffdf], dl 
  0x01066C1A  7000                    jo       0x1066c1c                      
                                        ; XREF: 0x01066C1A (cond_jump)
  0x01066C1C  00c4                    add      ah, al                         
  0x01066C1E  2200                    and      al, byte ptr [eax]             
  0x01066C20  00f4                    add      ah, dh                         
  0x01066C22  46                      inc      esi                            
  0x01066C23  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x01066C29  f4                      hlt                                     
  0x01066C2A  44                      inc      esp                            
  0x01066C2B  0000                    add      byte ptr [eax], al             
  0x01066C2D  0100                    add      dword ptr [eax], eax           
  0x01066C2F  002e                    add      byte ptr [esi], ch             
  0x01066C31  1d0c004000              sbb      eax, 0x40000c                  
  0x01066C36  2000                    and      byte ptr [eax], al             
  0x01066C38  0090210000c4            add      byte ptr [eax - 0x3bffffdf], dl 
  0x01066C3E  2200                    and      al, byte ptr [eax]             
  0x01066C40  00f4                    add      ah, dh                         
  0x01066C42  46                      inc      esi                            
  0x01066C43  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x01066C4A  44                      inc      esp                            
  0x01066C4B  00720b                  add      byte ptr [edx + 0xb], dh       
  0x01066C4E  0000                    add      byte ptr [eax], al             
  0x01066C50  2e1d0c004000            sbb      eax, 0x40000c                  
  0x01066C56  2000                    and      byte ptr [eax], al             
  0x01066C58  009521000070            add      byte ptr [ebp + 0x70000021], dl 
  0x01066C5E  6600410b                add      byte ptr [ecx + 0xb], al       
  0x01066C62  0000                    add      byte ptr [eax], al             
  0x01066C64  f1                      int1                                    
  0x01066C65  030d0000f066            add      ecx, dword ptr [0x66f00000]    
  0x01066C6B  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01066C6E  0000                    add      byte ptr [eax], al             
  0x01066C70  005e20                  add      byte ptr [esi + 0x20], bl      
  0x01066C73  0000                    add      byte ptr [eax], al             
  0x01066C76  56                      push     esi                            
  0x01066C77  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x01066C7A  0000                    add      byte ptr [eax], al             
  0x01066C7C  0300                    add      eax, dword ptr [eax]           
  0x01066C7E  2000                    and      byte ptr [eax], al             
  0x01066C80  07                      pop      es                             
  0x01066C81  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01066C82  0500000738              add      eax, 0x38070000                
  0x01066C87  0000                    add      byte ptr [eax], al             
  0x01066C89  f4                      hlt                                     
  0x01066C8A  60                      pushal                                  
  0x01066C8B  008904000000            add      byte ptr [ecx + 4], cl         
  0x01066C91  f4                      hlt                                     
  0x01066C92  650039                  add      byte ptr gs:[ecx], bh          
  0x01066C95  0b00                    or       eax, dword ptr [eax]           
  0x01066C97  00f1                    add      cl, dh                         
  0x01066C99  030d0000f057            add      ecx, dword ptr [0x57f00000]    
  0x01066C9F  0002                    add      byte ptr [edx], al             
  0x01066CA1  0000                    add      byte ptr [eax], al             
  0x01066CA3  000b                    add      byte ptr [ebx], cl             
  0x01066CA5  0020                    add      byte ptr [eax], ah             
  0x01066CA7  0014a4                  add      byte ptr [esp], dl             
  0x01066CAA  050000f462              add      eax, 0x62f40000                
  0x01066CAF  000500000000            add      byte ptr [0], al               
  0x01066CB5  f4                      hlt                                     
  0x01066CB6  66000a                  add      byte ptr [edx], cl             
  0x01066CB9  0d0000004e              or       eax, 0x4e000000                
  0x01066CBE  2200                    and      al, byte ptr [eax]             
  0x01066CC0  10f4                    adc      ah, dh                         
  0x01066CC2  44                      inc      esp                            
  0x01066CC3  0001                    add      byte ptr [ecx], al             
  0x01066CC5  0000                    add      byte ptr [eax], al             
  0x01066CC7  008c4301003ed0          add      byte ptr [ebx + eax*2 - 0x2fc1ffff], cl 
  0x01066CCE  2100                    and      dword ptr [eax], eax           
  0x01066CD0  10cd                    adc      ch, cl                         
  0x01066CD2  06                      push     es                             
  0x01066CD3  0002                    add      byte ptr [edx], al             
  0x01066CD5  0000                    add      byte ptr [eax], al             
  0x01066CD7  0000                    add      byte ptr [eax], al             
  0x01066CD9  58                      pop      eax                            
  0x01066CDA  44                      inc      esp                            
  0x01066CDB  0000                    add      byte ptr [eax], al             
  0x01066CDF  00d0                    add      al, dl                         
  0x01066CE3  00d2                    add      dl, dl                         
  0x01066CE7  00d2                    add      dl, dl                         
  0x01066CE9  f066000d00000024        lock add byte ptr [0x24000000], cl      
  0x01066CF1  1d0c000066              sbb      eax, 0x6600000c                
  0x01066CF6  50                      push     eax                            
  0x01066CF7  0000                    add      byte ptr [eax], al             
  0x01066CFA  57                      push     edi                            
  0x01066CFB  0003                    add      byte ptr [ebx], al             
  0x01066CFD  0000                    add      byte ptr [eax], al             
  0x01066CFF  000b                    add      byte ptr [ebx], cl             
  0x01066D01  0020                    add      byte ptr [eax], ah             
  0x01066D03  0014a4                  add      byte ptr [esp], dl             
  0x01066D06  050000f462              add      eax, 0x62f40000                
  0x01066D0B  0008                    add      byte ptr [eax], cl             
  0x01066D0D  0000                    add      byte ptr [eax], al             
  0x01066D0F  0000                    add      byte ptr [eax], al             
  0x01066D11  f4                      hlt                                     
  0x01066D12  66000d0d000000          add      byte ptr [0xd], cl             
  0x01066D19  4e                      dec      esi                            
  0x01066D1A  2200                    and      al, byte ptr [eax]             
  0x01066D1C  10f4                    adc      ah, dh                         
  0x01066D1E  44                      inc      esp                            
  0x01066D1F  0002                    add      byte ptr [edx], al             
  0x01066D21  0000                    add      byte ptr [eax], al             
  0x01066D23  008c4301003ed0          add      byte ptr [ebx + eax*2 - 0x2fc1ffff], cl 
  0x01066D2A  2100                    and      dword ptr [eax], eax           
  0x01066D2C  10cd                    adc      ch, cl                         
  0x01066D2E  06                      push     es                             
  0x01066D2F  0002                    add      byte ptr [edx], al             
  0x01066D31  0000                    add      byte ptr [eax], al             
  0x01066D33  0000                    add      byte ptr [eax], al             
  0x01066D35  58                      pop      eax                            
  0x01066D36  44                      inc      esp                            
  0x01066D37  0000                    add      byte ptr [eax], al             
  0x01066D3B  00d0                    add      al, dl                         
  0x01066D3F  00d2                    add      dl, dl                         
  0x01066D43  00d2                    add      dl, dl                         
  0x01066D45  f066000e                lock add byte ptr [esi], cl             
  0x01066D49  0000                    add      byte ptr [eax], al             
  0x01066D4B  0020                    add      byte ptr [eax], ah             
  0x01066D4D  1d0c000066              sbb      eax, 0x6600000c                
  0x01066D52  50                      push     eax                            
  0x01066D53  0000                    add      byte ptr [eax], al             
  0x01066D56  57                      push     edi                            
  0x01066D57  000400                  add      byte ptr [eax + eax], al       
  0x01066D5A  0000                    add      byte ptr [eax], al             
  0x01066D5C  0b00                    or       eax, dword ptr [eax]           
  0x01066D5E  2000                    and      byte ptr [eax], al             
  0x01066D60  13a4050000f462          adc      esp, dword ptr [ebp + eax + 0x62f40000] 
  0x01066D67  000b                    add      byte ptr [ebx], cl             
  0x01066D69  0000                    add      byte ptr [eax], al             
  0x01066D6B  0000                    add      byte ptr [eax], al             
  0x01066D6D  f4                      hlt                                     
  0x01066D6E  660010                  add      byte ptr [eax], dl             
  0x01066D71  0d0000004e              or       eax, 0x4e000000                
  0x01066D76  2200                    and      al, byte ptr [eax]             
  0x01066D78  10f4                    adc      ah, dh                         
  0x01066D7A  44                      inc      esp                            
  0x01066D7B  00050000008c            add      byte ptr [0x8c000000], al      
  0x01066D81  42                      inc      edx                            
  0x01066D82  0100                    add      dword ptr [eax], eax           
  0x01066D84  3ed021                  shl      byte ptr ds:[ecx], 1           
  0x01066D87  0010                    add      byte ptr [eax], dl             
  0x01066D89  cd06                    int      6                              
  0x01066D8B  0002                    add      byte ptr [edx], al             
  0x01066D8D  0000                    add      byte ptr [eax], al             
  0x01066D8F  0000                    add      byte ptr [eax], al             
  0x01066D91  58                      pop      eax                            
  0x01066D92  44                      inc      esp                            
  0x01066D93  0000                    add      byte ptr [eax], al             
  0x01066D97  00d0                    add      al, dl                         
  0x01066D9B  00d2                    add      dl, dl                         
  0x01066D9D  f066000f                lock add byte ptr [edi], cl             
  0x01066DA1  0000                    add      byte ptr [eax], al             
  0x01066DA3  0020                    add      byte ptr [eax], ah             
  0x01066DA5  1d0c000066              sbb      eax, 0x6600000c                
  0x01066DAA  50                      push     eax                            
  0x01066DAB  000c00                  add      byte ptr [eax + eax], cl       
  0x01066DAE  0000                    add      byte ptr [eax], al             
  0x01066DB0  00f0                    add      al, dh                         
  0x01066DB2  6200                    bound    eax, qword ptr [eax]           
  0x01066DB4  55                      push     ebp                            
  0x01066DB5  0b00                    or       eax, dword ptr [eax]           
  0x01066DB7  0022                    add      byte ptr [edx], ah             
  0x01066DBA  0500470b00              add      eax, 0xb4700                   
  0x01066DBF  0000                    add      byte ptr [eax], al             
  0x01066DC2  57                      push     edi                            
  0x01066DC3  00570b                  add      byte ptr [edi + 0xb], dl       
  0x01066DC6  0000                    add      byte ptr [eax], al             
  0x01066DC8  00f0                    add      al, dh                         
  0x01066DCA  45                      inc      ebp                            
  0x01066DCB  00560b                  add      byte ptr [esi + 0xb], dl       
  0x01066DCE  0000                    add      byte ptr [eax], al             
  0x01066DD0  00f4                    add      ah, dh                         
  0x01066DD2  61                      popal                                   
  0x01066DD3  007f0b                  add      byte ptr [edi + 0xb], bh       
  0x01066DD6  0000                    add      byte ptr [eax], al             
  0x01066DD8  00f0                    add      al, dh                         
  0x01066DDA  7100                    jno      0x1066ddc                      
                                        ; XREF: 0x01066DDA (cond_jump)
  0x01066DDC  97                      xchg     edi, eax                       
  0x01066DDD  0b00                    or       eax, dword ptr [eax]           
  0x01066DDF  0000                    add      byte ptr [eax], al             
  0x01066DE1  0138                    add      dword ptr [eax], edi           
  0x01066DE3  006f03                  add      byte ptr [edi + 3], ch         
  0x01066DE6  0d0000f461              or       eax, 0x61f40000                
  0x01066DEB  00840b000000f0          add      byte ptr [ebx + ecx - 0x10000000], al 
  0x01066DF2  7100                    jno      0x1066df4                      
                                        ; XREF: 0x01066DF2 (cond_jump)
  0x01066DF4  97                      xchg     edi, eax                       
  0x01066DF5  0b00                    or       eax, dword ptr [eax]           
  0x01066DF7  0000                    add      byte ptr [eax], al             
  0x01066DF9  0138                    add      dword ptr [eax], edi           
  0x01066DFB  006f03                  add      byte ptr [edi + 3], ch         
  0x01066DFE  0d0000f461              or       eax, 0x61f40000                
  0x01066E03  004a0b                  add      byte ptr [edx + 0xb], cl       
  0x01066E06  0000                    add      byte ptr [eax], al             
  0x01066E08  0001                    add      byte ptr [ecx], al             
  0x01066E0A  3800                    cmp      byte ptr [eax], al             
  0x01066E0C  93                      xchg     ebx, eax                       
  0x01066E0D  030d0000f056            add      ecx, dword ptr [0x56f00000]    
  0x01066E13  004a0b                  add      byte ptr [edx + 0xb], cl       
  0x01066E16  0000                    add      byte ptr [eax], al             
  0x01066E18  0300                    add      eax, dword ptr [eax]           
  0x01066E1A  2000                    and      byte ptr [eax], al             
  0x01066E1C  05a4050000              add      eax, 0x5a4                     
  0x01066E21  f4                      hlt                                     
  0x01066E22  61                      popal                                   
  0x01066E23  004b0b                  add      byte ptr [ebx + 0xb], cl       
  0x01066E26  0000                    add      byte ptr [eax], al             
  0x01066E28  0008                    add      byte ptr [eax], cl             
  0x01066E2A  3800                    cmp      byte ptr [eax], al             
  0x01066E2C  93                      xchg     ebx, eax                       
  0x01066E2D  030d00130020            add      ecx, dword ptr [0x20001300]    
  0x01066E33  0000                    add      byte ptr [eax], al             
  0x01066E35  7056                    jo       0x1066e8d                      
  0x01066E37  001e                    add      byte ptr [esi], bl             
  0x01066E39  0000                    add      byte ptr [eax], al             
  0x01066E3B  0000                    add      byte ptr [eax], al             
  0x01066E3D  f4                      hlt                                     
  0x01066E3E  61                      popal                                   
  0x01066E3F  00890b000000            add      byte ptr [ecx + 0xb], cl       
  0x01066E45  0138                    add      dword ptr [eax], edi           
  0x01066E47  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x01066E4D  f9                      stc                                     
  0x01066E4E  56                      push     esi                            
  0x01066E4F  0003                    add      byte ptr [ebx], al             
  0x01066E51  0020                    add      byte ptr [eax], ah             
  0x01066E53  0005a4050000            add      byte ptr [0x5a4], al           
  0x01066E59  f4                      hlt                                     
  0x01066E5A  61                      popal                                   
  0x01066E5B  001e                    add      byte ptr [esi], bl             
  0x01066E5D  0000                    add      byte ptr [eax], al             
  0x01066E5F  0000                    add      byte ptr [eax], al             
  0x01066E61  0138                    add      dword ptr [eax], edi           
  0x01066E63  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x01066E6A  56                      push     esi                            
  0x01066E6B  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x01066E6E  0000                    add      byte ptr [eax], al             
  0x01066E70  c54001                  lds      eax, ptr [eax + 1]             
  0x01066E73  0002                    add      byte ptr [edx], al             
  0x01066E75  0000                    add      byte ptr [eax], al             
  0x01066E77  0012                    add      byte ptr [edx], dl             
  0x01066E79  2405                    and      al, 5                          
  0x01066E7B  0000                    add      byte ptr [eax], al             
  0x01066E7D  f4                      hlt                                     
  0x01066E7E  44                      inc      esp                            
  0x01066E7F  0010                    add      byte ptr [eax], dl             
  0x01066E81  0000                    add      byte ptr [eax], al             
  0x01066E83  0000                    add      byte ptr [eax], al             
  0x01066E85  7044                    jo       0x1066ecb                      
  0x01066E87  001e                    add      byte ptr [esi], bl             
  0x01066E89  0000                    add      byte ptr [eax], al             
  0x01066E8B  0000                    add      byte ptr [eax], al             
  0x01066E8E  56                      push     esi                            
  0x01066E8F  00400b                  add      byte ptr [eax + 0xb], al       
  0x01066E92  0000                    add      byte ptr [eax], al             
  0x01066E94  0300                    add      eax, dword ptr [eax]           
  0x01066E96  2000                    and      byte ptr [eax], al             
  0x01066E98  06                      push     es                             
  0x01066E99  2405                    and      al, 5                          
  0x01066E9B  0000                    add      byte ptr [eax], al             
  0x01066E9D  f4                      hlt                                     
  0x01066E9E  61                      popal                                   
  0x01066E9F  001e                    add      byte ptr [esi], bl             
  0x01066EA1  0000                    add      byte ptr [eax], al             
  0x01066EA3  0000                    add      byte ptr [eax], al             
  0x01066EA5  0538009303              add      eax, 0x3930038                 
  0x01066EAA  0d00050c05              or       eax, 0x50c0500                 
  0x01066EAF  0000                    add      byte ptr [eax], al             
  0x01066EB1  f4                      hlt                                     
  0x01066EB2  61                      popal                                   
  0x01066EB3  001e                    add      byte ptr [esi], bl             
  0x01066EB5  0000                    add      byte ptr [eax], al             
  0x01066EB7  0000                    add      byte ptr [eax], al             
  0x01066EB9  0138                    add      dword ptr [eax], edi           
  0x01066EBB  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x01066EC1  f4                      hlt                                     
  0x01066EC2  61                      popal                                   
  0x01066EC3  008a0b000000            add      byte ptr [edx + 0xb], cl       
  0x01066ECA  7100                    jno      0x1066ecc                      
                                        ; XREF: 0x01066ECA (cond_jump)
  0x01066ECC  97                      xchg     edi, eax                       
  0x01066ECD  0b00                    or       eax, dword ptr [eax]           
  0x01066ECF  0000                    add      byte ptr [eax], al             
  0x01066ED1  0238                    add      bh, byte ptr [eax]             
  0x01066ED3  006f03                  add      byte ptr [edi + 3], ch         
  0x01066ED6  0d0000f056              or       eax, 0x56f00000                
  0x01066EDB  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x01066EDE  0000                    add      byte ptr [eax], al             
  0x01066EE0  0300                    add      eax, dword ptr [eax]           
  0x01066EE2  2000                    and      byte ptr [eax], al             
  0x01066EE4  05a4050000              add      eax, 0x5a4                     
  0x01066EE9  f4                      hlt                                     
  0x01066EEA  61                      popal                                   
  0x01066EEB  008f0b000000            add      byte ptr [edi + 0xb], cl       
  0x01066EF1  0138                    add      dword ptr [eax], edi           
  0x01066EF3  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x01066EF9  0036                    add      byte ptr [esi], dh             
  0x01066EFB  0000                    add      byte ptr [eax], al             
  0x01066EFE  44                      inc      esp                            
  0x01066EFF  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x01066F05  c406                    les      eax, ptr [esi]                 
  0x01066F07  0011                    add      byte ptr [ecx], dl             
  0x01066F09  0000                    add      byte ptr [eax], al             
  0x01066F0B  0000                    add      byte ptr [eax], al             
  0x01066F0D  f4                      hlt                                     
  0x01066F0E  56                      push     esi                            
  0x01066F0F  008a0b000000            add      byte ptr [edx + 0xb], cl       
  0x01066F15  c422                    les      esp, ptr [edx]                 
  0x01066F17  004000                  add      byte ptr [eax], al             
  0x01066F1A  2000                    and      byte ptr [eax], al             
  0x01066F1C  0091210000e1            add      byte ptr [ecx - 0x1effffdf], dl 
  0x01066F22  56                      push     esi                            
  0x01066F23  0003                    add      byte ptr [ebx], al             
  0x01066F25  0020                    add      byte ptr [eax], ah             
  0x01066F27  0008                    add      byte ptr [eax], cl             
  0x01066F29  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01066F2A  050000f456              add      eax, 0x56f40000                
  0x01066F2F  00a00b000000            add      byte ptr [eax + 0xb], ah       
  0x01066F35  c422                    les      esp, ptr [edx]                 
  0x01066F37  004000                  add      byte ptr [eax], al             
  0x01066F3A  2000                    and      byte ptr [eax], al             
  0x01066F3C  009121000006            add      byte ptr [ecx + 0x6000021], dl 
  0x01066F42  3800                    cmp      byte ptr [eax], al             
  0x01066F44  93                      xchg     ebx, eax                       
  0x01066F45  030d00005e20            add      ecx, dword ptr [0x205e0000]    
  0x01066F4B  0000                    add      byte ptr [eax], al             
  0x01066F4D  0036                    add      byte ptr [esi], dh             
  0x01066F4F  0000                    add      byte ptr [eax], al             
  0x01066F52  44                      inc      esp                            
  0x01066F53  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x01066F59  c406                    les      eax, ptr [esi]                 
  0x01066F5B  0023                    add      byte ptr [ebx], ah             
  0x01066F5D  0000                    add      byte ptr [eax], al             
  0x01066F5F  0000                    add      byte ptr [eax], al             
  0x01066F61  f4                      hlt                                     
  0x01066F62  56                      push     esi                            
  0x01066F63  008a0b000000            add      byte ptr [edx + 0xb], cl       
  0x01066F69  c422                    les      esp, ptr [edx]                 
  0x01066F6B  004000                  add      byte ptr [eax], al             
  0x01066F6E  2000                    and      byte ptr [eax], al             
  0x01066F70  0091210000e1            add      byte ptr [ecx - 0x1effffdf], dl 
  0x01066F76  56                      push     esi                            
  0x01066F77  0003                    add      byte ptr [ebx], al             
  0x01066F79  0020                    add      byte ptr [eax], ah             
  0x01066F7B  001a                    add      byte ptr [edx], bl             
  0x01066F7D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01066F7E  050000c422              add      eax, 0x22c40000                
  0x01066F83  0000                    add      byte ptr [eax], al             
  0x01066F85  f4                      hlt                                     
  0x01066F86  46                      inc      esi                            
  0x01066F87  001f                    add      byte ptr [edi], bl             
  0x01066F89  0000                    add      byte ptr [eax], al             
  0x01066F8B  00d0                    add      al, dl                         
  0x01066F8D  f4                      hlt                                     
  0x01066F8E  44                      inc      esp                            
  0x01066F8F  0000                    add      byte ptr [eax], al             
  0x01066F91  0000                    add      byte ptr [eax], al             
  0x01066F93  002e                    add      byte ptr [esi], ch             
  0x01066F95  1d0c004000              sbb      eax, 0x40000c                  
  0x01066F9A  2000                    and      byte ptr [eax], al             
  0x01066F9C  009121000004            add      byte ptr [ecx + 0x4000021], dl 
  0x01066FA2  3800                    cmp      byte ptr [eax], al             
  0x01066FA4  a3030d0000              mov      dword ptr [0xd03], eax         
  0x01066FA9  f4                      hlt                                     
  0x01066FAA  56                      push     esi                            
  0x01066FAB  00910b000000            add      byte ptr [ecx + 0xb], dl       
  0x01066FB1  c422                    les      esp, ptr [edx]                 
  0x01066FB3  004000                  add      byte ptr [eax], al             
  0x01066FB6  2000                    and      byte ptr [eax], al             
  0x01066FB8  0090210000e0            add      byte ptr [eax - 0x1fffffdf], dl 
  0x01066FBE  7100                    jno      0x1066fc0                      
                                        ; XREF: 0x01066FBE (cond_jump)
  0x01066FC0  0007                    add      byte ptr [edi], al             
  0x01066FC2  3800                    cmp      byte ptr [eax], al             
  0x01066FC4  81030d0000f4            add      dword ptr [ebx], 0xf400000d    
  0x01066FCA  56                      push     esi                            
  0x01066FCB  00610b                  add      byte ptr [ecx + 0xb], ah       
  0x01066FCE  0000                    add      byte ptr [eax], al             
  0x01066FD0  00c4                    add      ah, al                         
  0x01066FD2  2200                    and      al, byte ptr [eax]             
  0x01066FD4  40                      inc      eax                            
  0x01066FD5  0020                    add      byte ptr [eax], ah             
  0x01066FD7  0000                    add      byte ptr [eax], al             
  0x01066FD9  91                      xchg     ecx, eax                       
  0x01066FDA  2100                    and      dword ptr [eax], eax           
  0x01066FDC  0002                    add      byte ptr [edx], al             
  0x01066FDE  3800                    cmp      byte ptr [eax], al             
  0x01066FE0  93                      xchg     ebx, eax                       
  0x01066FE1  030d00005e20            add      ecx, dword ptr [0x205e0000]    
  0x01066FE7  0000                    add      byte ptr [eax], al             
  0x01066FEA  56                      push     esi                            
  0x01066FEB  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x01066FEE  0000                    add      byte ptr [eax], al             
  0x01066FF0  0300                    add      eax, dword ptr [eax]           
  0x01066FF2  2000                    and      byte ptr [eax], al             
  0x01066FF4  0ca4                    or       al, 0xa4                       
  0x01066FF6  050000f056              add      eax, 0x56f00000                
  0x01066FFB  008f0b000003            add      byte ptr [edi + 0x300000b], cl 
  0x01067001  0020                    add      byte ptr [eax], ah             
  0x01067003  0008                    add      byte ptr [eax], cl             
  0x01067005  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01067006  050000f461              add      eax, 0x61f40000                
  0x0106700B  009b00000000            add      byte ptr [ebx], bl             
  0x01067011  0438                    add      al, 0x38                       
  0x01067013  00a3030d0000            add      byte ptr [ebx + 0xd03], ah     
  0x01067019  0239                    add      bh, byte ptr [ecx]             
  0x0106701B  0000                    add      byte ptr [eax], al             
  0x0106701D  07                      pop      es                             
  0x0106701E  3800                    cmp      byte ptr [eax], al             
  0x01067020  81030d0000f4            add      dword ptr [ebx], 0xf400000d    
  0x01067026  61                      popal                                   
  0x01067027  00900b000000            add      byte ptr [eax + 0xb], dl       
  0x0106702D  0138                    add      dword ptr [eax], edi           
  0x0106702F  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x01067035  f9                      stc                                     
  0x01067036  56                      push     esi                            
  0x01067037  0003                    add      byte ptr [ebx], al             
  0x01067039  0020                    add      byte ptr [eax], ah             
  0x0106703B  0049a4                  add      byte ptr [ecx - 0x5c], cl      
  0x0106703E  050000f456              add      eax, 0x56f40000                
  0x01067043  0002                    add      byte ptr [edx], al             
  0x01067045  0000                    add      byte ptr [eax], al             
  0x01067047  0000                    add      byte ptr [eax], al             
  0x01067049  7056                    jo       0x10670a1                      
  0x0106704B  001e                    add      byte ptr [esi], bl             
  0x0106704D  0000                    add      byte ptr [eax], al             
  0x0106704F  0000                    add      byte ptr [eax], al             
  0x01067051  f4                      hlt                                     
  0x01067052  61                      popal                                   
  0x01067053  001e                    add      byte ptr [esi], bl             
  0x01067055  0000                    add      byte ptr [eax], al             
  0x01067057  0000                    add      byte ptr [eax], al             
  0x01067059  0238                    add      bh, byte ptr [eax]             
  0x0106705B  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x01067061  f4                      hlt                                     
  0x01067062  56                      push     esi                            
  0x01067063  0001                    add      byte ptr [ecx], al             
  0x01067065  0000                    add      byte ptr [eax], al             
  0x01067067  0000                    add      byte ptr [eax], al             
  0x01067069  7056                    jo       0x10670c1                      
  0x0106706B  001e                    add      byte ptr [esi], bl             
  0x0106706D  0000                    add      byte ptr [eax], al             
  0x0106706F  0000                    add      byte ptr [eax], al             
  0x01067071  f4                      hlt                                     
  0x01067072  61                      popal                                   
  0x01067073  001e                    add      byte ptr [esi], bl             
  0x01067075  0000                    add      byte ptr [eax], al             
  0x01067077  0000                    add      byte ptr [eax], al             
  0x01067079  0238                    add      bh, byte ptr [eax]             
  0x0106707B  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x01067081  f4                      hlt                                     
  0x01067082  56                      push     esi                            
  0x01067083  0001                    add      byte ptr [ecx], al             
  0x01067085  0000                    add      byte ptr [eax], al             
  0x01067087  0000                    add      byte ptr [eax], al             
  0x01067089  7056                    jo       0x10670e1                      
  0x0106708B  001e                    add      byte ptr [esi], bl             
  0x0106708D  0000                    add      byte ptr [eax], al             
  0x0106708F  0000                    add      byte ptr [eax], al             
  0x01067091  f4                      hlt                                     
  0x01067092  61                      popal                                   
  0x01067093  001e                    add      byte ptr [esi], bl             
  0x01067095  0000                    add      byte ptr [eax], al             
  0x01067097  0000                    add      byte ptr [eax], al             
  0x01067099  0238                    add      bh, byte ptr [eax]             
  0x0106709B  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
                                        ; XREF: 0x01067049 (cond_jump)
  0x010670A1  f4                      hlt                                     
  0x010670A2  56                      push     esi                            
  0x010670A3  0002                    add      byte ptr [edx], al             
  0x010670A5  0000                    add      byte ptr [eax], al             
  0x010670A7  0000                    add      byte ptr [eax], al             
  0x010670A9  7056                    jo       0x1067101                      
  0x010670AB  001e                    add      byte ptr [esi], bl             
  0x010670AD  0000                    add      byte ptr [eax], al             
  0x010670AF  0000                    add      byte ptr [eax], al             
  0x010670B1  f4                      hlt                                     
  0x010670B2  61                      popal                                   
  0x010670B3  001e                    add      byte ptr [esi], bl             
  0x010670B5  0000                    add      byte ptr [eax], al             
  0x010670B7  0000                    add      byte ptr [eax], al             
  0x010670B9  0238                    add      bh, byte ptr [eax]             
  0x010670BB  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
                                        ; XREF: 0x01067069 (cond_jump)
  0x010670C1  f4                      hlt                                     
  0x010670C2  56                      push     esi                            
  0x010670C3  0007                    add      byte ptr [edi], al             
  0x010670C5  0000                    add      byte ptr [eax], al             
  0x010670C7  0000                    add      byte ptr [eax], al             
  0x010670C9  7056                    jo       0x1067121                      
  0x010670CB  001e                    add      byte ptr [esi], bl             
  0x010670CD  0000                    add      byte ptr [eax], al             
  0x010670CF  0000                    add      byte ptr [eax], al             
  0x010670D1  f4                      hlt                                     
  0x010670D2  61                      popal                                   
  0x010670D3  001e                    add      byte ptr [esi], bl             
  0x010670D5  0000                    add      byte ptr [eax], al             
  0x010670D7  0000                    add      byte ptr [eax], al             
  0x010670D9  0338                    add      edi, dword ptr [eax]           
  0x010670DB  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
                                        ; XREF: 0x01067089 (cond_jump)
  0x010670E1  f4                      hlt                                     
  0x010670E2  61                      popal                                   
  0x010670E3  006f0b                  add      byte ptr [edi + 0xb], ch       
  0x010670E6  0000                    add      byte ptr [eax], al             
  0x010670E8  0001                    add      byte ptr [ecx], al             
  0x010670EA  3800                    cmp      byte ptr [eax], al             
  0x010670EC  93                      xchg     ebx, eax                       
  0x010670ED  030d0000f956            add      ecx, dword ptr [0x56f90000]    
  0x010670F3  0003                    add      byte ptr [ebx], al             
  0x010670F5  0020                    add      byte ptr [eax], ah             
  0x010670F7  004aa4                  add      byte ptr [edx - 0x5c], cl      
  0x010670FA  050000f461              add      eax, 0x61f40000                
  0x010670FF  00730b                  add      byte ptr [ebx + 0xb], dh       
  0x01067102  0000                    add      byte ptr [eax], al             
  0x01067104  0006                    add      byte ptr [esi], al             
  0x01067106  3800                    cmp      byte ptr [eax], al             
  0x01067108  93                      xchg     ebx, eax                       
  0x01067109  030d00000036            add      ecx, dword ptr [0x36000000]    
  0x0106710F  0000                    add      byte ptr [eax], al             
  0x01067112  44                      inc      esp                            
  0x01067113  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x01067119  c406                    les      eax, ptr [esi]                 
  0x0106711B  0011                    add      byte ptr [ecx], dl             
  0x0106711D  0000                    add      byte ptr [eax], al             
  0x0106711F  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x010670C9 (cond_jump)
  0x01067121  f4                      hlt                                     
  0x01067122  56                      push     esi                            
  0x01067123  00740b00                add      byte ptr [ebx + ecx], dh       
  0x01067127  0000                    add      byte ptr [eax], al             
  0x01067129  c422                    les      esp, ptr [edx]                 
  0x0106712B  004000                  add      byte ptr [eax], al             
  0x0106712E  2000                    and      byte ptr [eax], al             
  0x01067130  009121000004            add      byte ptr [ecx + 0x4000021], dl 
  0x01067136  3800                    cmp      byte ptr [eax], al             
  0x01067138  93                      xchg     ebx, eax                       
  0x01067139  030d0000f456            add      ecx, dword ptr [0x56f40000]    
  0x0106713F  000400                  add      byte ptr [eax + eax], al       
  0x01067142  0000                    add      byte ptr [eax], al             
  0x01067144  007056                  add      byte ptr [eax + 0x56], dh      
  0x01067147  001e                    add      byte ptr [esi], bl             
  0x01067149  0000                    add      byte ptr [eax], al             
  0x0106714B  0000                    add      byte ptr [eax], al             
  0x0106714D  f4                      hlt                                     
  0x0106714E  61                      popal                                   
  0x0106714F  001e                    add      byte ptr [esi], bl             
  0x01067151  0000                    add      byte ptr [eax], al             
  0x01067153  0000                    add      byte ptr [eax], al             
  0x01067155  0338                    add      edi, dword ptr [eax]           
  0x01067157  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106715D  5e                      pop      esi                            
  0x0106715E  2000                    and      byte ptr [eax], al             
  0x01067160  00f0                    add      al, dh                         
  0x01067162  56                      push     esi                            
  0x01067163  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x01067166  0000                    add      byte ptr [eax], al             
  0x01067168  0300                    add      eax, dword ptr [eax]           
  0x0106716A  2000                    and      byte ptr [eax], al             
  0x0106716C  0da4050000              or       eax, 0x5a4                     
  0x01067171  f4                      hlt                                     
  0x01067172  61                      popal                                   
  0x01067173  00790b                  add      byte ptr [ecx + 0xb], bh       
  0x01067176  0000                    add      byte ptr [eax], al             
  0x01067178  000438                  add      byte ptr [eax + edi], al       
  0x0106717B  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x01067181  f4                      hlt                                     
  0x01067182  56                      push     esi                            
  0x01067183  000400                  add      byte ptr [eax + eax], al       
  0x01067186  0000                    add      byte ptr [eax], al             
  0x01067188  007056                  add      byte ptr [eax + 0x56], dh      
  0x0106718B  001e                    add      byte ptr [esi], bl             
  0x0106718D  0000                    add      byte ptr [eax], al             
  0x0106718F  0000                    add      byte ptr [eax], al             
  0x01067191  f4                      hlt                                     
  0x01067192  61                      popal                                   
  0x01067193  001e                    add      byte ptr [esi], bl             
  0x01067195  0000                    add      byte ptr [eax], al             
  0x01067197  0000                    add      byte ptr [eax], al             
  0x01067199  0338                    add      edi, dword ptr [eax]           
  0x0106719B  0093030d0013            add      byte ptr [ebx + 0x13000d03], dl 
  0x010671A1  f4                      hlt                                     
  0x010671A2  61                      popal                                   
  0x010671A3  001e                    add      byte ptr [esi], bl             
  0x010671A5  0000                    add      byte ptr [eax], al             
  0x010671A7  0000                    add      byte ptr [eax], al             
  0x010671A9  61                      popal                                   
  0x010671AA  56                      push     esi                            
  0x010671AB  0000                    add      byte ptr [eax], al             
  0x010671AD  0138                    add      dword ptr [eax], edi           
  0x010671AF  0093030d0001            add      byte ptr [ebx + 0x1000d03], dl 
  0x010671B5  0c05                    or       al, 5                          
  0x010671B7  0000                    add      byte ptr [eax], al             
  0x010671BA  56                      push     esi                            
  0x010671BB  00400b                  add      byte ptr [eax + 0xb], al       
  0x010671BE  0000                    add      byte ptr [eax], al             
  0x010671C0  854301                  test     dword ptr [ebx + 1], eax       
  0x010671C3  005524                  add      byte ptr [ebp + 0x24], dl      
  0x010671C6  0500004e22              add      eax, 0x224e0000                
  0x010671CB  0000                    add      byte ptr [eax], al             
  0x010671CE  44                      inc      esp                            
  0x010671CF  00450b                  add      byte ptr [ebp + 0xb], al       
  0x010671D2  0000                    add      byte ptr [eax], al             
  0x010671D4  44                      inc      esp                            
  0x010671D5  f4                      hlt                                     
  0x010671D6  46                      inc      esi                            
  0x010671D7  0010                    add      byte ptr [eax], dl             
  0x010671D9  0000                    add      byte ptr [eax], al             
  0x010671DB  0000                    add      byte ptr [eax], al             
  0x010671DE  2100                    and      dword ptr [eax], eax           
  0x010671E0  00ee                    add      dh, ch                         
  0x010671E2  2100                    and      dword ptr [eax], eax           
  0x010671E4  36f4                    hlt                                     
  0x010671E6  44                      inc      esp                            
  0x010671E7  0010                    add      byte ptr [eax], dl             
  0x010671E9  0000                    add      byte ptr [eax], al             
  0x010671EB  004000                  add      byte ptr [eax], al             
  0x010671EE  2000                    and      byte ptr [eax], al             
  0x010671F0  00c4                    add      ah, al                         
  0x010671F2  2100                    and      dword ptr [eax], eax           
  0x010671F4  b0f0                    mov      al, 0xf0                       
                                        ; XREF: 0x01067204 (cond_jump)
  0x010671F6  47                      inc      edi                            
  0x010671F7  009d0b00002e            add      byte ptr [ebp + 0x2e00000b], bl 
  0x010671FD  1d0c004000              sbb      eax, 0x40000c                  
  0x01067202  2000                    and      byte ptr [eax], al             
  0x01067204  70f0                    jo       0x10671f6                      
  0x01067206  44                      inc      esp                            
  0x01067207  00670b                  add      byte ptr [edi + 0xb], ah       
  0x0106720A  0000                    add      byte ptr [eax], al             
  0x0106720C  41                      inc      ecx                            
  0x0106720E  2100                    and      dword ptr [eax], eax           
  0x01067210  06                      push     es                             
  0x01067211  1d0c0000b0              sbb      eax, 0xb000000c                
  0x01067216  1800                    sbb      byte ptr [eax], al             
  0x01067218  9e                      sahf                                    
  0x01067219  0b00                    or       eax, dword ptr [eax]           
  0x0106721B  0054f044                add      byte ptr [eax + esi*8 + 0x44], dl 
  0x0106721F  007a0b                  add      byte ptr [edx + 0xb], bh       
  0x01067222  0000                    add      byte ptr [eax], al             
  0x01067224  44                      inc      esp                            
  0x01067225  0020                    add      byte ptr [eax], ah             
  0x01067227  00740020                add      byte ptr [eax + eax + 0x20], dh 
  0x0106722B  0003                    add      byte ptr [ebx], al             
  0x0106722D  0020                    add      byte ptr [eax], ah             
  0x0106722F  001a                    add      byte ptr [edx], bl             
  0x01067231  f4                      hlt                                     
  0x01067232  0500804701              add      eax, 0x1478000                 
  0x01067237  0000                    add      byte ptr [eax], al             
  0x0106723A  44                      inc      esp                            
  0x0106723B  00670b                  add      byte ptr [edi + 0xb], ah       
  0x0106723E  0000                    add      byte ptr [eax], al             
  0x01067240  06                      push     es                             
  0x01067241  1c0c                    sbb      al, 0xc                        
  0x01067243  0041c4                  add      byte ptr [ecx - 0x3c], al      
  0x01067246  2100                    and      dword ptr [eax], eax           
  0x01067248  40                      inc      eax                            
  0x01067249  0020                    add      byte ptr [eax], ah             
  0x0106724B  0000                    add      byte ptr [eax], al             
  0x0106724D  7056                    jo       0x10672a5                      
  0x0106724F  00670b                  add      byte ptr [edi + 0xb], ah       
  0x01067252  0000                    add      byte ptr [eax], al             
  0x01067254  c54001                  lds      eax, ptr [eax + 1]             
  0x01067257  00ff                    add      bh, bh                         
  0x01067259  0100                    add      dword ptr [eax], eax           
  0x0106725B  0002                    add      byte ptr [edx], al             
  0x0106725D  f4                      hlt                                     
  0x0106725E  05000c0000              add      eax, 0xc00                     
  0x01067263  0000                    add      byte ptr [eax], al             
  0x01067266  56                      push     esi                            
  0x01067267  00710b                  add      byte ptr [ecx + 0xb], dh       
  0x0106726A  0000                    add      byte ptr [eax], al             
  0x0106726C  41                      inc      ecx                            
  0x0106726D  c421                    les      esp, ptr [ecx]                 
  0x0106726F  0006                    add      byte ptr [esi], al             
  0x01067271  1d0c0041c4              sbb      eax, 0xc441000c                
  0x01067276  2100                    and      dword ptr [eax], eax           
  0x01067278  40                      inc      eax                            
  0x01067279  0020                    add      byte ptr [eax], ah             
  0x0106727B  0000                    add      byte ptr [eax], al             
  0x0106727D  7056                    jo       0x10672d5                      
  0x0106727F  00710b                  add      byte ptr [ecx + 0xb], dh       
  0x01067282  0000                    add      byte ptr [eax], al             
  0x01067284  00f4                    add      ah, dh                         
  0x01067286  60                      pushal                                  
  0x01067287  006c0b00                add      byte ptr [ebx + ecx], ch       
  0x0106728B  0000                    add      byte ptr [eax], al             
  0x0106728D  e056                    loopne   0x10672e5                      
  0x0106728F  00440020                add      byte ptr [eax + eax + 0x20], al 
  0x01067293  0000                    add      byte ptr [eax], al             
  0x01067295  60                      pushal                                  
  0x01067296  56                      push     esi                            
  0x01067297  0000                    add      byte ptr [eax], al             
  0x01067299  f4                      hlt                                     
  0x0106729A  61                      popal                                   
  0x0106729B  00660b                  add      byte ptr [esi + 0xb], ah       
  0x0106729E  0000                    add      byte ptr [eax], al             
  0x010672A0  0001                    add      byte ptr [ecx], al             
  0x010672A2  3800                    cmp      byte ptr [eax], al             
  0x010672A4  93                      xchg     ebx, eax                       
                                        ; XREF: 0x0106724D (cond_jump)
  0x010672A5  030d0000f956            add      ecx, dword ptr [0x56f90000]    
  0x010672AB  0003                    add      byte ptr [ebx], al             
  0x010672AD  0020                    add      byte ptr [eax], ah             
  0x010672AF  0001                    add      byte ptr [ecx], al             
  0x010672B1  a5                      movsd    dword ptr es:[edi], dword ptr [esi] 
  0x010672B2  050000f461              add      eax, 0x61f40000                
  0x010672B7  00670b                  add      byte ptr [edi + 0xb], ah       
  0x010672BA  0000                    add      byte ptr [eax], al             
  0x010672BC  0009                    add      byte ptr [ecx], cl             
  0x010672BE  3800                    cmp      byte ptr [eax], al             
  0x010672C0  93                      xchg     ebx, eax                       
  0x010672C1  030d0000f056            add      ecx, dword ptr [0x56f00000]    
  0x010672C7  00700b                  add      byte ptr [eax + 0xb], dh       
  0x010672CA  0000                    add      byte ptr [eax], al             
  0x010672CC  0300                    add      eax, dword ptr [eax]           
  0x010672CE  2000                    and      byte ptr [eax], al             
  0x010672D0  9f                      lahf                                    
  0x010672D1  f4                      hlt                                     
  0x010672D2  050000f444              add      eax, 0x44f40000                
  0x010672D7  0001                    add      byte ptr [ecx], al             
  0x010672D9  0000                    add      byte ptr [eax], al             
  0x010672DB  0000                    add      byte ptr [eax], al             
  0x010672DD  7044                    jo       0x1067323                      
  0x010672DF  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x010672E2  0000                    add      byte ptr [eax], al             
  0x010672E4  13f4                    adc      esi, esp                       
  0x010672E6  61                      popal                                   
  0x010672E7  001e                    add      byte ptr [esi], bl             
  0x010672E9  0000                    add      byte ptr [eax], al             
  0x010672EB  0000                    add      byte ptr [eax], al             
  0x010672ED  61                      popal                                   
  0x010672EE  56                      push     esi                            
  0x010672EF  0000                    add      byte ptr [eax], al             
  0x010672F1  0138                    add      dword ptr [eax], edi           
  0x010672F3  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x010672F9  002400                  add      byte ptr [eax + eax], ah       
  0x010672FC  007044                  add      byte ptr [eax + 0x44], dh      
  0x010672FF  001e                    add      byte ptr [esi], bl             
  0x01067301  0000                    add      byte ptr [eax], al             
  0x01067303  0000                    add      byte ptr [eax], al             
  0x01067305  f4                      hlt                                     
  0x01067306  61                      popal                                   
  0x01067307  001e                    add      byte ptr [esi], bl             
  0x01067309  0000                    add      byte ptr [eax], al             
  0x0106730B  0000                    add      byte ptr [eax], al             
  0x0106730D  0138                    add      dword ptr [eax], edi           
  0x0106730F  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x01067316  56                      push     esi                            
  0x01067317  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x0106731A  0000                    add      byte ptr [eax], al             
  0x0106731C  80410100                add      byte ptr [ecx + 1], 0          
  0x01067320  007056                  add      byte ptr [eax + 0x56], dh      
                                        ; XREF: 0x010672DD (cond_jump)
  0x01067323  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x01067326  0000                    add      byte ptr [eax], al             
  0x01067328  00f0                    add      al, dh                         
  0x0106732A  56                      push     esi                            
  0x0106732B  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106732E  0000                    add      byte ptr [eax], al             
  0x01067330  854301                  test     dword ptr [ebx + 1], eax       
  0x01067333  004124                  add      byte ptr [ecx + 0x24], al      
  0x01067336  0500000024              add      eax, 0x24000000                
  0x0106733B  0000                    add      byte ptr [eax], al             
  0x0106733D  7044                    jo       0x1067383                      
  0x0106733F  001e                    add      byte ptr [esi], bl             
  0x01067341  0000                    add      byte ptr [eax], al             
  0x01067343  0000                    add      byte ptr [eax], al             
  0x01067345  ee                      out      dx, al                         
  0x01067346  2100                    and      dword ptr [eax], eax           
  0x01067348  855001                  test     dword ptr [eax + 1], edx       
  0x0106734B  000b                    add      byte ptr [ebx], cl             
  0x0106734D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106734E  050000f044              add      eax, 0x44f00000                
  0x01067353  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x01067356  0000                    add      byte ptr [eax], al             
  0x01067358  40                      inc      eax                            
  0x01067359  0020                    add      byte ptr [eax], ah             
  0x0106735B  0000                    add      byte ptr [eax], al             
  0x0106735D  e421                    in       al, 0x21                       
  0x0106735F  0000                    add      byte ptr [eax], al             
  0x01067361  7056                    jo       0x10673b9                      
  0x01067363  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x01067366  0000                    add      byte ptr [eax], al             
  0x01067368  00f4                    add      ah, dh                         
  0x0106736A  61                      popal                                   
  0x0106736B  001e                    add      byte ptr [esi], bl             
  0x0106736D  0000                    add      byte ptr [eax], al             
  0x0106736F  0000                    add      byte ptr [eax], al             
  0x01067371  98                      cwde                                    
  0x01067372  2000                    and      byte ptr [eax], al             
  0x01067374  93                      xchg     ebx, eax                       
  0x01067375  030d00004e22            add      ecx, dword ptr [0x224e0000]    
  0x0106737B  0000                    add      byte ptr [eax], al             
  0x0106737D  7056                    jo       0x10673d5                      
  0x0106737F  00590b                  add      byte ptr [ecx + 0xb], bl       
  0x01067382  0000                    add      byte ptr [eax], al             
  0x01067384  00f4                    add      ah, dh                         
  0x01067386  61                      popal                                   
  0x01067387  001e                    add      byte ptr [esi], bl             
  0x01067389  0000                    add      byte ptr [eax], al             
  0x0106738B  0000                    add      byte ptr [eax], al             
  0x0106738D  1038                    adc      byte ptr [eax], bh             
  0x0106738F  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x01067395  f4                      hlt                                     
  0x01067396  61                      popal                                   
  0x01067397  001e                    add      byte ptr [esi], bl             
  0x01067399  0000                    add      byte ptr [eax], al             
  0x0106739B  0000                    add      byte ptr [eax], al             
  0x0106739D  1038                    adc      byte ptr [eax], bh             
  0x0106739F  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x010673A6  56                      push     esi                            
  0x010673A7  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x010673AA  0000                    add      byte ptr [eax], al             
  0x010673AC  80600100                and      byte ptr [eax + 1], 0          
  0x010673B0  007056                  add      byte ptr [eax + 0x56], dh      
  0x010673B3  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x010673B6  0000                    add      byte ptr [eax], al             
  0x010673B8  0000                    add      byte ptr [eax], al             
  0x010673BA  2400                    and      al, 0                          
  0x010673BC  007044                  add      byte ptr [eax + 0x44], dh      
  0x010673BF  001e                    add      byte ptr [esi], bl             
  0x010673C1  0000                    add      byte ptr [eax], al             
  0x010673C3  0000                    add      byte ptr [eax], al             
  0x010673C6  56                      push     esi                            
  0x010673C7  00700b                  add      byte ptr [eax + 0xb], dh       
  0x010673CA  0000                    add      byte ptr [eax], al             
  0x010673CC  06                      push     es                             
  0x010673CD  1d0c0000f0              sbb      eax, 0xf000000c                
  0x010673D2  44                      inc      esp                            
  0x010673D3  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x010673D6  0000                    add      byte ptr [eax], al             
  0x010673D8  44                      inc      esp                            
  0x010673D9  0020                    add      byte ptr [eax], ah             
  0x010673DB  0006                    add      byte ptr [esi], al             
                                        ; XREF: 0x01061D80 (jump)
  0x010673DD  1c0c                    sbb      al, 0xc                        
  0x010673DF  0010                    add      byte ptr [eax], dl             
  0x010673E1  cc                      int3                                    
  0x010673E2  06                      push     es                             
  0x010673E3  000a                    add      byte ptr [edx], cl             
  0x010673E5  0000                    add      byte ptr [eax], al             
  0x010673E7  0000                    add      byte ptr [eax], al             
  0x010673E9  f4                      hlt                                     
  0x010673EA  61                      popal                                   
  0x010673EB  001e                    add      byte ptr [esi], bl             
  0x010673ED  0000                    add      byte ptr [eax], al             
  0x010673EF  0000                    add      byte ptr [eax], al             
  0x010673F1  0838                    or       byte ptr [eax], bh             
  0x010673F3  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x010673FA  56                      push     esi                            
  0x010673FB  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x010673FE  0000                    add      byte ptr [eax], al             
  0x01067400  80480100                or       byte ptr [eax + 1], 0          
  0x01067404  007056                  add      byte ptr [eax + 0x56], dh      
  0x01067407  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x0106740A  0000                    add      byte ptr [eax], al             
  0x0106740C  00f0                    add      al, dh                         
  0x0106740E  56                      push     esi                            
  0x0106740F  00700b                  add      byte ptr [eax + 0xb], dh       
  0x01067412  0000                    add      byte ptr [eax], al             
  0x01067414  06                      push     es                             
  0x01067415  1d0c0000f0              sbb      eax, 0xf000000c                
  0x0106741A  44                      inc      esp                            
  0x0106741B  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x0106741E  0000                    add      byte ptr [eax], al             
  0x01067420  44                      inc      esp                            
  0x01067421  0020                    add      byte ptr [eax], ah             
  0x01067423  0000                    add      byte ptr [eax], al             
  0x01067425  f4                      hlt                                     
  0x01067426  61                      popal                                   
  0x01067427  001e                    add      byte ptr [esi], bl             
  0x01067429  0000                    add      byte ptr [eax], al             
  0x0106742B  0000                    add      byte ptr [eax], al             
  0x0106742D  98                      cwde                                    
  0x0106742E  2100                    and      dword ptr [eax], eax           
  0x01067430  93                      xchg     ebx, eax                       
  0x01067431  030d0000f056            add      ecx, dword ptr [0x56f00000]    
  0x01067437  00670b                  add      byte ptr [edi + 0xb], ah       
  0x0106743A  0000                    add      byte ptr [eax], al             
  0x0106743C  00f0                    add      al, dh                         
  0x0106743E  44                      inc      esp                            
  0x0106743F  00700b                  add      byte ptr [eax + 0xb], dh       
  0x01067442  0000                    add      byte ptr [eax], al             
  0x01067444  44                      inc      esp                            
  0x01067445  0020                    add      byte ptr [eax], ah             
  0x01067447  000f                    add      byte ptr [edi], cl             
  0x01067449  0c05                    or       al, 5                          
  0x0106744B  0000                    add      byte ptr [eax], al             
  0x0106744E  56                      push     esi                            
  0x0106744F  00670b                  add      byte ptr [edi + 0xb], ah       
  0x01067452  0000                    add      byte ptr [eax], al             
  0x01067454  0300                    add      eax, dword ptr [eax]           
  0x01067456  2e000b                  add      byte ptr cs:[ebx], cl          
  0x01067459  f4                      hlt                                     
  0x0106745A  0500000024              add      eax, 0x24000000                
  0x0106745F  0000                    add      byte ptr [eax], al             
  0x01067461  7044                    jo       0x10674a7                      
  0x01067463  001e                    add      byte ptr [esi], bl             
  0x01067465  0000                    add      byte ptr [eax], al             
  0x01067467  0000                    add      byte ptr [eax], al             
  0x01067469  f4                      hlt                                     
  0x0106746A  61                      popal                                   
  0x0106746B  001e                    add      byte ptr [esi], bl             
  0x0106746D  0000                    add      byte ptr [eax], al             
  0x0106746F  0000                    add      byte ptr [eax], al             
  0x01067471  0838                    or       byte ptr [eax], bh             
  0x01067473  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106747A  56                      push     esi                            
  0x0106747B  00670b                  add      byte ptr [edi + 0xb], ah       
  0x0106747E  0000                    add      byte ptr [eax], al             
  0x01067480  844101                  test     byte ptr [ecx + 1], al         
  0x01067483  0003                    add      byte ptr [ebx], al             
  0x01067485  0020                    add      byte ptr [eax], ah             
  0x01067487  000b                    add      byte ptr [ebx], cl             
  0x01067489  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106748A  050010cc06              add      eax, 0x6cc1000                 
  0x0106748F  0009                    add      byte ptr [ecx], cl             
  0x01067491  0000                    add      byte ptr [eax], al             
  0x01067493  0013                    add      byte ptr [ebx], dl             
  0x01067495  0020                    add      byte ptr [eax], ah             
  0x01067497  0000                    add      byte ptr [eax], al             
  0x01067499  7056                    jo       0x10674f1                      
  0x0106749B  0010                    add      byte ptr [eax], dl             
  0x0106749D  0000                    add      byte ptr [eax], al             
  0x0106749F  0000                    add      byte ptr [eax], al             
  0x010674A1  f4                      hlt                                     
  0x010674A2  61                      popal                                   
  0x010674A3  0010                    add      byte ptr [eax], dl             
  0x010674A5  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01067461 (cond_jump)
  0x010674A7  0000                    add      byte ptr [eax], al             
  0x010674A9  0838                    or       byte ptr [eax], bh             
  0x010674AB  006103                  add      byte ptr [ecx + 3], ah         
  0x010674AE  0d00000000              or       eax, 0                         
  0x010674B3  0000                    add      byte ptr [eax], al             
  0x010674B5  7045                    jo       0x10674fc                      
  0x010674B7  00560b                  add      byte ptr [esi + 0xb], dl       
  0x010674BA  0000                    add      byte ptr [eax], al             
  0x010674BC  007057                  add      byte ptr [eax + 0x57], dh      
  0x010674BF  00570b                  add      byte ptr [edi + 0xb], dl       
  0x010674C2  0000                    add      byte ptr [eax], al             
  0x010674C4  007062                  add      byte ptr [eax + 0x62], dh      
  0x010674C7  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x010674CA  0000                    add      byte ptr [eax], al             
  0x010674CC  22f4                    and      dh, ah                         
  0x010674CE  0500ffff00              add      eax, 0xffff00                  
  0x010674D3  000c00                  add      byte ptr [eax + eax], cl       
  0x010674D6  0000                    add      byte ptr [eax], al             
  0x010674D8  0001                    add      byte ptr [ecx], al             
  0x010674DA  3900                    cmp      dword ptr [eax], eax           
  0x010674DC  007071                  add      byte ptr [eax + 0x71], dh      
  0x010674DF  0002                    add      byte ptr [edx], al             
  0x010674E1  0000                    add      byte ptr [eax], al             
  0x010674E3  0000                    add      byte ptr [eax], al             
  0x010674E5  7071                    jo       0x1067558                      
  0x010674E7  0003                    add      byte ptr [ebx], al             
  0x010674E9  0000                    add      byte ptr [eax], al             
  0x010674EB  0000                    add      byte ptr [eax], al             
  0x010674ED  7071                    jo       0x1067560                      
  0x010674EF  000400                  add      byte ptr [eax + eax], al       
  0x010674F2  0000                    add      byte ptr [eax], al             
  0x010674F4  0000                    add      byte ptr [eax], al             
  0x010674F6  360000                  add      byte ptr ss:[eax], al          
  0x010674FA  44                      inc      esp                            
  0x010674FB  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x01067501  c406                    les      eax, ptr [esi]                 
  0x01067503  001d00000000            add      byte ptr [0], bl               
  0x01067509  f4                      hlt                                     
  0x0106750A  56                      push     esi                            
  0x0106750B  00a50b000000            add      byte ptr [ebp + 0xb], ah       
  0x01067511  c422                    les      esp, ptr [edx]                 
  0x01067513  004000                  add      byte ptr [eax], al             
  0x01067516  2000                    and      byte ptr [eax], al             
  0x01067518  0090210000e0            add      byte ptr [eax - 0x1fffffdf], dl 
  0x0106751E  7000                    jo       0x1067520                      
                                        ; XREF: 0x0106751E (cond_jump)
  0x01067520  00c4                    add      ah, al                         
  0x01067522  2200                    and      al, byte ptr [eax]             
  0x01067524  00f4                    add      ah, dh                         
  0x01067526  46                      inc      esi                            
  0x01067527  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x0106752D  f4                      hlt                                     
  0x0106752E  44                      inc      esp                            
  0x0106752F  0000                    add      byte ptr [eax], al             
  0x01067531  0100                    add      dword ptr [eax], eax           
  0x01067533  002e                    add      byte ptr [esi], ch             
  0x01067535  1d0c004000              sbb      eax, 0x40000c                  
  0x0106753A  2000                    and      byte ptr [eax], al             
  0x0106753C  0090210000c4            add      byte ptr [eax - 0x3bffffdf], dl 
  0x01067542  2200                    and      al, byte ptr [eax]             
  0x01067544  00f4                    add      ah, dh                         
  0x01067546  46                      inc      esi                            
  0x01067547  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x0106754E  44                      inc      esp                            
  0x0106754F  00720b                  add      byte ptr [edx + 0xb], dh       
  0x01067552  0000                    add      byte ptr [eax], al             
  0x01067554  2e1d0c004000            sbb      eax, 0x40000c                  
  0x0106755A  2000                    and      byte ptr [eax], al             
  0x0106755C  009521000070            add      byte ptr [ebp + 0x70000021], dl 
  0x01067562  6600410b                add      byte ptr [ecx + 0xb], al       
  0x01067566  0000                    add      byte ptr [eax], al             
  0x01067568  8b040d0000f066          mov      eax, dword ptr [ecx + 0x66f00000] 
  0x0106756F  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01067572  0000                    add      byte ptr [eax], al             
  0x01067574  005e20                  add      byte ptr [esi + 0x20], bl      
  0x01067577  0000                    add      byte ptr [eax], al             
  0x0106757A  56                      push     esi                            
  0x0106757B  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x0106757E  0000                    add      byte ptr [eax], al             
  0x01067580  0300                    add      eax, dword ptr [eax]           
  0x01067582  2000                    and      byte ptr [eax], al             
  0x01067584  07                      pop      es                             
  0x01067585  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01067586  0500000738              add      eax, 0x38070000                
  0x0106758B  0000                    add      byte ptr [eax], al             
  0x0106758D  f4                      hlt                                     
  0x0106758E  60                      pushal                                  
  0x0106758F  008904000000            add      byte ptr [ecx + 4], cl         
  0x01067595  f4                      hlt                                     
  0x01067596  650039                  add      byte ptr gs:[ecx], bh          
  0x01067599  0b00                    or       eax, dword ptr [eax]           
  0x0106759B  008b040d000c            add      byte ptr [ebx + 0xc000d04], cl 
  0x010675A1  0000                    add      byte ptr [eax], al             
  0x010675A3  0000                    add      byte ptr [eax], al             
  0x010675A6  6200                    bound    eax, qword ptr [eax]           
  0x010675A8  55                      push     ebp                            
  0x010675A9  0b00                    or       eax, dword ptr [eax]           
  0x010675AB  0022                    add      byte ptr [edx], ah             
  0x010675AE  0500470b00              add      eax, 0xb4700                   
  0x010675B3  0000                    add      byte ptr [eax], al             
  0x010675B6  57                      push     edi                            
  0x010675B7  00570b                  add      byte ptr [edi + 0xb], dl       
  0x010675BA  0000                    add      byte ptr [eax], al             
  0x010675BC  00f0                    add      al, dh                         
  0x010675BE  45                      inc      ebp                            
  0x010675BF  00560b                  add      byte ptr [esi + 0xb], dl       
  0x010675C2  0000                    add      byte ptr [eax], al             
  0x010675C4  0000                    add      byte ptr [eax], al             
  0x010675C6  2400                    and      al, 0                          
  0x010675C8  007044                  add      byte ptr [eax + 0x44], dh      
  0x010675CB  001e                    add      byte ptr [esi], bl             
  0x010675CD  0000                    add      byte ptr [eax], al             
  0x010675CF  0000                    add      byte ptr [eax], al             
  0x010675D2  56                      push     esi                            
  0x010675D3  006e0b                  add      byte ptr [esi + 0xb], ch       
  0x010675D6  0000                    add      byte ptr [eax], al             
  0x010675D8  855001                  test     dword ptr [eax + 1], edx       
  0x010675DB  0009                    add      byte ptr [ecx], cl             
  0x010675DD  94                      xchg     esp, eax                       
  0x010675DE  0500845001              add      eax, 0x1508400                 
  0x010675E3  0000                    add      byte ptr [eax], al             
  0x010675E5  7054                    jo       0x106763b                      
  0x010675E7  006e0b                  add      byte ptr [esi + 0xb], ch       
  0x010675EA  0000                    add      byte ptr [eax], al             
  0x010675EC  00f4                    add      ah, dh                         
  0x010675EE  61                      popal                                   
  0x010675EF  001e                    add      byte ptr [esi], bl             
  0x010675F1  0000                    add      byte ptr [eax], al             
  0x010675F3  0000                    add      byte ptr [eax], al             
  0x010675F5  1038                    adc      byte ptr [eax], bh             
  0x010675F7  0093030d00d5            add      byte ptr [ebx - 0x2afff2fd], dl 
  0x010675FD  0f05                    syscall                                 
  0x010675FF  0003                    add      byte ptr [ebx], al             
  0x01067601  0020                    add      byte ptr [eax], ah             
  0x01067603  0005a4050000            add      byte ptr [0x5a4], al           
  0x01067609  f4                      hlt                                     
  0x0106760A  61                      popal                                   
  0x0106760B  001e                    add      byte ptr [esi], bl             
  0x0106760D  0000                    add      byte ptr [eax], al             
  0x0106760F  0000                    add      byte ptr [eax], al             
  0x01067611  98                      cwde                                    
  0x01067612  2100                    and      dword ptr [eax], eax           
  0x01067614  93                      xchg     ebx, eax                       
  0x01067615  030d00130020            add      ecx, dword ptr [0x20001300]    
  0x0106761B  0000                    add      byte ptr [eax], al             
  0x0106761D  7056                    jo       0x1067675                      
  0x0106761F  0001                    add      byte ptr [ecx], al             
  0x01067621  0000                    add      byte ptr [eax], al             
  0x01067623  0000                    add      byte ptr [eax], al             
  0x01067625  7056                    jo       0x106767d                      
  0x01067627  001e                    add      byte ptr [esi], bl             
  0x01067629  0000                    add      byte ptr [eax], al             
  0x0106762B  0000                    add      byte ptr [eax], al             
  0x0106762D  f4                      hlt                                     
  0x0106762E  61                      popal                                   
  0x0106762F  001e                    add      byte ptr [esi], bl             
  0x01067631  0000                    add      byte ptr [eax], al             
  0x01067633  0000                    add      byte ptr [eax], al             
  0x01067635  0138                    add      dword ptr [eax], edi           
  0x01067637  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106763D  f4                      hlt                                     
  0x0106763E  61                      popal                                   
  0x0106763F  0001                    add      byte ptr [ecx], al             
  0x01067641  0000                    add      byte ptr [eax], al             
  0x01067643  0000                    add      byte ptr [eax], al             
  0x01067645  0138                    add      dword ptr [eax], edi           
  0x01067647  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106764D  f4                      hlt                                     
  0x0106764E  61                      popal                                   
  0x0106764F  001e                    add      byte ptr [esi], bl             
  0x01067651  0000                    add      byte ptr [eax], al             
  0x01067653  0000                    add      byte ptr [eax], al             
  0x01067655  1038                    adc      byte ptr [eax], bh             
  0x01067657  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106765D  7045                    jo       0x10676a4                      
  0x0106765F  00560b                  add      byte ptr [esi + 0xb], dl       
  0x01067662  0000                    add      byte ptr [eax], al             
  0x01067664  007057                  add      byte ptr [eax + 0x57], dh      
  0x01067667  00570b                  add      byte ptr [edi + 0xb], dl       
  0x0106766A  0000                    add      byte ptr [eax], al             
  0x0106766C  007062                  add      byte ptr [eax + 0x62], dh      
  0x0106766F  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x01067672  0000                    add      byte ptr [eax], al             
  0x01067674  22f4                    and      dh, ah                         
  0x01067676  0500ffff00              add      eax, 0xffff00                  
  0x0106767B  0000                    add      byte ptr [eax], al             
  0x0106767E  56                      push     esi                            
  0x0106767F  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x01067682  0000                    add      byte ptr [eax], al             
  0x01067684  00f0                    add      al, dh                         
  0x01067686  44                      inc      esp                            
  0x01067687  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106768A  0000                    add      byte ptr [eax], al             
  0x0106768C  44                      inc      esp                            
  0x0106768D  0020                    add      byte ptr [eax], ah             
  0x0106768F  0000                    add      byte ptr [eax], al             
  0x01067691  c421                    les      esp, ptr [ecx]                 
  0x01067693  0000                    add      byte ptr [eax], al             
  0x01067695  f4                      hlt                                     
  0x01067696  45                      inc      ebp                            
  0x01067697  0010                    add      byte ptr [eax], dl             
  0x01067699  0000                    add      byte ptr [eax], al             
  0x0106769B  00a00020002e            add      byte ptr [eax + 0x2e002000], ah 
  0x010676A1  1d0c0000f0              sbb      eax, 0xf000000c                
  0x010676A6  44                      inc      esp                            
  0x010676A7  009d0b000040            add      byte ptr [ebp + 0x4000000b], bl 
  0x010676AD  0020                    add      byte ptr [eax], ah             
  0x010676AF  0000                    add      byte ptr [eax], al             
  0x010676B1  7056                    jo       0x1067709                      
  0x010676B3  009d0b00000c            add      byte ptr [ebp + 0xc00000b], bl 
  0x010676B9  0000                    add      byte ptr [eax], al             
  0x010676BB  0000                    add      byte ptr [eax], al             
  0x010676BE  56                      push     esi                            
  0x010676BF  00400b                  add      byte ptr [eax + 0xb], al       
  0x010676C2  0000                    add      byte ptr [eax], al             
  0x010676C4  854001                  test     dword ptr [eax + 1], eax       
  0x010676C7  0010                    add      byte ptr [eax], dl             
  0x010676C9  2405                    and      al, 5                          
  0x010676CB  0000                    add      byte ptr [eax], al             
  0x010676CE  60                      pushal                                  
  0x010676CF  00450b                  add      byte ptr [ebp + 0xb], al       
  0x010676D2  0000                    add      byte ptr [eax], al             
  0x010676D4  005820                  add      byte ptr [eax + 0x20], bl      
  0x010676D7  0020                    add      byte ptr [eax], ah             
  0x010676DA  0500470b00              add      eax, 0xb4700                   
  0x010676DF  0000                    add      byte ptr [eax], al             
  0x010676E2  56                      push     esi                            
  0x010676E3  00580b                  add      byte ptr [eax + 0xb], bl       
  0x010676E6  0000                    add      byte ptr [eax], al             
  0x010676E8  844101                  test     byte ptr [ecx + 1], al         
  0x010676EB  001b                    add      byte ptr [ebx], bl             
  0x010676ED  d821                    fsub     dword ptr [ecx]                
  0x010676EF  00b3030d0000            add      byte ptr [ebx + 0xd03], dh     
  0x010676F5  7055                    jo       0x106774c                      
  0x010676F7  005a0b                  add      byte ptr [edx + 0xb], bl       
  0x010676FA  0000                    add      byte ptr [eax], al             
  0x010676FC  20f4                    and      ah, dh                         
  0x010676FE  0500ffff00              add      eax, 0xffff00                  
  0x01067703  00da                    add      dl, bl                         
  0x01067705  0c05                    or       al, 5                          
  0x01067707  008541010003            add      byte ptr [ebp + 0x3000141], al 
  0x0106770D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106770E  0500854201              add      eax, 0x1428500                 
  0x01067713  000f                    add      byte ptr [edi], cl             
  0x01067715  2405                    and      al, 5                          
  0x01067717  0000                    add      byte ptr [eax], al             
  0x0106771A  60                      pushal                                  
  0x0106771B  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106771E  0000                    add      byte ptr [eax], al             
  0x01067720  20f0                    and      al, dh                         
  0x01067722  0500470b00              add      eax, 0xb4700                   
  0x01067727  001b                    add      byte ptr [ebx], bl             
  0x0106772A  7000                    jo       0x106772c                      
                                        ; XREF: 0x0106772A (cond_jump)
  0x0106772C  58                      pop      eax                            
  0x0106772D  0b00                    or       eax, dword ptr [eax]           
  0x0106772F  0000                    add      byte ptr [eax], al             
  0x01067732  55                      push     ebp                            
  0x01067733  005a0b                  add      byte ptr [edx + 0xb], bl       
  0x01067736  0000                    add      byte ptr [eax], al             
  0x01067738  b303                    mov      bl, 3                          
  0x0106773A  0d00007055              or       eax, 0x55700000                
  0x0106773F  005a0b                  add      byte ptr [edx + 0xb], bl       
  0x01067742  0000                    add      byte ptr [eax], al             
  0x01067744  20f4                    and      ah, dh                         
  0x01067746  0500ffff00              add      eax, 0xffff00                  
  0x0106774B  00c8                    add      al, cl                         
  0x0106774D  0c05                    or       al, 5                          
  0x0106774F  008543010082            add      byte ptr [ebp - 0x7dfffebd], al 
  0x01067755  2405                    and      al, 5                          
  0x01067757  0000                    add      byte ptr [eax], al             
  0x0106775A  56                      push     esi                            
  0x0106775B  00590b                  add      byte ptr [ecx + 0xb], bl       
  0x0106775E  0000                    add      byte ptr [eax], al             
  0x01067760  00f0                    add      al, dh                         
  0x01067762  44                      inc      esp                            
  0x01067763  00450b                  add      byte ptr [ebp + 0xb], al       
  0x01067766  0000                    add      byte ptr [eax], al             
  0x01067768  44                      inc      esp                            
  0x01067769  0020                    add      byte ptr [eax], ah             
  0x0106776B  008041010000            add      byte ptr [eax + 0x141], al     
  0x01067771  d821                    fsub     dword ptr [ecx]                
  0x01067773  0000                    add      byte ptr [eax], al             
  0x01067775  90                      nop                                     
  0x01067776  2000                    and      byte ptr [eax], al             
  0x01067778  20f0                    and      al, dh                         
  0x0106777A  0500470b00              add      eax, 0xb4700                   
  0x0106777F  0000                    add      byte ptr [eax], al             
  0x01067782  55                      push     ebp                            
  0x01067783  005a0b                  add      byte ptr [edx + 0xb], bl       
  0x01067786  0000                    add      byte ptr [eax], al             
  0x01067788  b303                    mov      bl, 3                          
  0x0106778A  0d00911e0c              or       eax, 0xc1e9100                 
  0x0106778F  0000                    add      byte ptr [eax], al             
  0x01067792  61                      popal                                   
  0x01067793  00590b                  add      byte ptr [ecx + 0xb], bl       
  0x01067796  0000                    add      byte ptr [eax], al             
  0x01067798  006155                  add      byte ptr [ecx + 0x55], ah      
  0x0106779B  00911c0c0000            add      byte ptr [ecx + 0xc1c], dl     
  0x010677A2  44                      inc      esp                            
  0x010677A3  009d0b000000            add      byte ptr [ebp + 0xb], bl       
  0x010677A9  082500a00020            or       byte ptr [0x2000a000], ah      
  0x010677AF  0000                    add      byte ptr [eax], al             
  0x010677B2  44                      inc      esp                            
  0x010677B3  009b0b000041            add      byte ptr [ebx + 0x4100000b], bl 
  0x010677B9  c421                    les      esp, ptr [ecx]                 
  0x010677BB  00440020                add      byte ptr [eax + eax + 0x20], al 
  0x010677BF  0000                    add      byte ptr [eax], al             
  0x010677C1  0423                    add      al, 0x23                       
  0x010677C3  00440020                add      byte ptr [eax + eax + 0x20], al 
  0x010677C7  0000                    add      byte ptr [eax], al             
  0x010677C9  9a200000d82100          lcall    0x21, 0xd8000020               
  0x010677D0  00f0                    add      al, dh                         
  0x010677D2  56                      push     esi                            
  0x010677D3  00590b                  add      byte ptr [ecx + 0xb], bl       
  0x010677D6  0000                    add      byte ptr [eax], al             
  0x010677D8  80410100                add      byte ptr [ecx + 1], 0          
  0x010677DC  00d0                    add      al, dl                         
  0x010677DE  2100                    and      dword ptr [eax], eax           
  0x010677E0  ca030d                  retf     0xd03                          
  0x010677E3  0000                    add      byte ptr [eax], al             
  0x010677E6  56                      push     esi                            
  0x010677E7  00590b                  add      byte ptr [ecx + 0xb], bl       
  0x010677EA  0000                    add      byte ptr [eax], al             
  0x010677EC  80410100                add      byte ptr [ecx + 1], 0          
  0x010677F0  00d0                    add      al, dl                         
  0x010677F2  2100                    and      dword ptr [eax], eax           
  0x010677F4  91                      xchg     ecx, eax                       
  0x010677F5  1e                      push     ds                             
  0x010677F6  0c00                    or       al, 0                          
  0x010677F8  006055                  add      byte ptr [eax + 0x55], ah      
  0x010677FB  00911c0c0000            add      byte ptr [ecx + 0xc1c], dl     
  0x01067802  56                      push     esi                            
  0x01067803  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x01067806  0000                    add      byte ptr [eax], al             
  0x01067808  00f0                    add      al, dh                         
  0x0106780A  44                      inc      esp                            
  0x0106780B  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106780E  0000                    add      byte ptr [eax], al             
  0x01067810  44                      inc      esp                            
  0x01067811  0020                    add      byte ptr [eax], ah             
  0x01067813  0000                    add      byte ptr [eax], al             
  0x01067815  44                      inc      esp                            
  0x01067816  2300                    and      eax, dword ptr [eax]           
  0x01067818  44                      inc      esp                            
  0x01067819  0020                    add      byte ptr [eax], ah             
  0x0106781B  0000                    add      byte ptr [eax], al             
  0x0106781D  0423                    add      al, 0x23                       
  0x0106781F  00440020                add      byte ptr [eax + eax + 0x20], al 
  0x01067823  0000                    add      byte ptr [eax], al             
  0x01067825  d821                    fsub     dword ptr [ecx]                
  0x01067827  0000                    add      byte ptr [eax], al             
  0x0106782A  56                      push     esi                            
  0x0106782B  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106782E  0000                    add      byte ptr [eax], al             
  0x01067830  40                      inc      eax                            
  0x01067831  0020                    add      byte ptr [eax], ah             
  0x01067833  0000                    add      byte ptr [eax], al             
  0x01067835  44                      inc      esp                            
  0x01067836  2300                    and      eax, dword ptr [eax]           
  0x01067838  40                      inc      eax                            
  0x01067839  0020                    add      byte ptr [eax], ah             
  0x0106783B  0000                    add      byte ptr [eax], al             
  0x0106783D  d021                    shl      byte ptr [ecx], 1              
  0x0106783F  001b                    add      byte ptr [ebx], bl             
  0x01067841  0020                    add      byte ptr [eax], ah             
  0x01067843  00b3030d0000            add      byte ptr [ebx + 0xd03], dh     
  0x01067849  7055                    jo       0x10678a0                      
  0x0106784B  005a0b                  add      byte ptr [edx + 0xb], bl       
  0x0106784E  0000                    add      byte ptr [eax], al             
  0x01067850  20f4                    and      ah, dh                         
  0x01067852  0500ffff00              add      eax, 0xffff00                  
  0x01067857  00450c                  add      byte ptr [ebp + 0xc], al       
  0x0106785A  0500854401              add      eax, 0x1448500                 
  0x0106785F  000f                    add      byte ptr [edi], cl             
  0x01067861  2405                    and      al, 5                          
  0x01067863  0020                    add      byte ptr [eax], ah             
  0x01067866  0500470b00              add      eax, 0xb4700                   
  0x0106786B  0000                    add      byte ptr [eax], al             
  0x0106786E  60                      pushal                                  
  0x0106786F  00450b                  add      byte ptr [ebp + 0xb], al       
  0x01067872  0000                    add      byte ptr [eax], al             
  0x01067874  00f0                    add      al, dh                         
  0x01067876  7000                    jo       0x1067878                      
                                        ; XREF: 0x01067876 (cond_jump)
  0x01067878  58                      pop      eax                            
  0x01067879  0b00                    or       eax, dword ptr [eax]           
  0x0106787B  0000                    add      byte ptr [eax], al             
  0x0106787E  57                      push     edi                            
  0x0106787F  005a0b                  add      byte ptr [edx + 0xb], bl       
  0x01067882  0000                    add      byte ptr [eax], al             
  0x01067884  b303                    mov      bl, 3                          
  0x01067886  0d00007055              or       eax, 0x55700000                
  0x0106788B  005a0b                  add      byte ptr [edx + 0xb], bl       
  0x0106788E  0000                    add      byte ptr [eax], al             
  0x01067890  20f4                    and      ah, dh                         
  0x01067892  0500ffff00              add      eax, 0xffff00                  
  0x01067897  00150c050085            add      byte ptr [0x8500050c], dl      
  0x0106789D  45                      inc      ebp                            
  0x0106789E  0100                    add      dword ptr [eax], eax           
                                        ; XREF: 0x01067849 (cond_jump)
  0x010678A0  1324050020f005          adc      esp, dword ptr [eax + 0x5f02000] 
  0x010678A7  00470b                  add      byte ptr [edi + 0xb], al       
  0x010678AA  0000                    add      byte ptr [eax], al             
  0x010678AC  00f0                    add      al, dh                         
  0x010678AE  60                      pushal                                  
  0x010678AF  00450b                  add      byte ptr [ebp + 0xb], al       
  0x010678B2  0000                    add      byte ptr [eax], al             
  0x010678B4  00f0                    add      al, dh                         
  0x010678B6  7000                    jo       0x10678b8                      
                                        ; XREF: 0x010678B6 (cond_jump)
  0x010678B8  58                      pop      eax                            
  0x010678B9  0b00                    or       eax, dword ptr [eax]           
  0x010678BB  0000                    add      byte ptr [eax], al             
  0x010678BE  57                      push     edi                            
  0x010678BF  005a0b                  add      byte ptr [edx + 0xb], bl       
  0x010678C2  0000                    add      byte ptr [eax], al             
  0x010678C4  b303                    mov      bl, 3                          
  0x010678C6  0d0000f056              or       eax, 0x56f00000                
  0x010678CB  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x010678CE  0000                    add      byte ptr [eax], al             
  0x010678D0  844101                  test     byte ptr [ecx + 1], al         
  0x010678D3  0000                    add      byte ptr [eax], al             
  0x010678D5  d021                    shl      byte ptr [ecx], 1              
  0x010678D7  00911e0c0000            add      byte ptr [ecx + 0xc1e], dl     
  0x010678DD  60                      pushal                                  
  0x010678DE  55                      push     ebp                            
  0x010678DF  00911c0c0020            add      byte ptr [ecx + 0x20000c1c], dl 
  0x010678E5  f4                      hlt                                     
  0x010678E6  0500ffff00              add      eax, 0xffff00                  
  0x010678EB  000c00                  add      byte ptr [eax + eax], cl       
  0x010678EE  0000                    add      byte ptr [eax], al             
  0x010678F0  00f4                    add      ah, dh                         
  0x010678F2  56                      push     esi                            
  0x010678F3  001500000000            add      byte ptr [0], dl               
  0x010678F9  f4                      hlt                                     
  0x010678FA  57                      push     edi                            
  0x010678FB  0001                    add      byte ptr [ecx], al             
  0x010678FD  0000                    add      byte ptr [eax], al             
  0x010678FF  0000                    add      byte ptr [eax], al             
  0x01067901  f4                      hlt                                     
  0x01067902  7000                    jo       0x1067904                      
                                        ; XREF: 0x01067902 (cond_jump)
  0x01067904  90                      nop                                     
  0x01067905  0300                    add      eax, dword ptr [eax]           
  0x01067907  0000                    add      byte ptr [eax], al             
  0x01067909  0039                    add      byte ptr [ecx], bh             
  0x0106790B  0000                    add      byte ptr [eax], al             
  0x0106790D  f4                      hlt                                     
  0x0106790E  60                      pushal                                  
  0x0106790F  0000                    add      byte ptr [eax], al             
  0x01067911  0100                    add      dword ptr [eax], eax           
  0x01067913  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x01067919  0100                    add      dword ptr [eax], eax           
  0x0106791B  0003                    add      byte ptr [ebx], al             
  0x0106791D  0020                    add      byte ptr [eax], ah             
  0x0106791F  0000                    add      byte ptr [eax], al             
  0x01067921  2405                    and      al, 5                          
  0x01067923  000c00                  add      byte ptr [eax + eax], cl       
  0x01067926  0000                    add      byte ptr [eax], al             
  0x01067928  007054                  add      byte ptr [eax + 0x54], dh      
  0x0106792B  00fd                    add      ch, bh                         
  0x0106792D  0000                    add      byte ptr [eax], al             
  0x0106792F  0000                    add      byte ptr [eax], al             
  0x01067931  7044                    jo       0x1067977                      
  0x01067933  00fe                    add      dh, bh                         
  0x01067935  0000                    add      byte ptr [eax], al             
  0x01067937  0000                    add      byte ptr [eax], al             
  0x01067939  7060                    jo       0x106799b                      
  0x0106793B  00ff                    add      bh, bh                         
  0x0106793D  0000                    add      byte ptr [eax], al             
  0x0106793F  0003                    add      byte ptr [ebx], al             
  0x01067941  0020                    add      byte ptr [eax], ah             
  0x01067943  0010                    add      byte ptr [eax], dl             
  0x01067945  2405                    and      al, 5                          
  0x01067947  0000                    add      byte ptr [eax], al             
  0x01067949  f4                      hlt                                     
  0x0106794A  56                      push     esi                            
  0x0106794B  000c00                  add      byte ptr [eax + eax], cl       
  0x0106794E  0000                    add      byte ptr [eax], al             
  0x01067950  00f4                    add      ah, dh                         
  0x01067952  7000                    jo       0x1067954                      
                                        ; XREF: 0x01067952 (cond_jump)
  0x01067954  da0500000000            fiadd    dword ptr [0]                  
  0x0106795A  3900                    cmp      dword ptr [eax], eax           
  0x0106795C  80f00b                  xor      al, 0xb                        
  0x0106795F  008001000003            add      byte ptr [eax + 0x3000001], al 
  0x01067965  0020                    add      byte ptr [eax], ah             
  0x01067967  0000                    add      byte ptr [eax], al             
  0x01067969  2405                    and      al, 5                          
  0x0106796B  0000                    add      byte ptr [eax], al             
  0x0106796E  56                      push     esi                            
  0x0106796F  00fd                    add      ch, bh                         
  0x01067971  0000                    add      byte ptr [eax], al             
  0x01067973  0000                    add      byte ptr [eax], al             
  0x01067976  60                      pushal                                  
                                        ; XREF: 0x01067931 (cond_jump)
  0x01067977  00ff                    add      bh, bh                         
  0x01067979  0000                    add      byte ptr [eax], al             
  0x0106797B  0000                    add      byte ptr [eax], al             
  0x0106797E  44                      inc      esp                            
  0x0106797F  00fe                    add      dh, bh                         
  0x01067981  0000                    add      byte ptr [eax], al             
  0x01067983  0003                    add      byte ptr [ebx], al             
  0x01067985  f4                      hlt                                     
  0x01067986  45                      inc      ebp                            
  0x01067987  00da                    add      dl, bl                         
  0x01067989  0500000324              add      eax, 0x24030000                
  0x0106798E  0500007045              add      eax, 0x45700000                
  0x01067993  00480b                  add      byte ptr [eax + 0xb], cl       
  0x01067996  0000                    add      byte ptr [eax], al             
  0x01067998  0098200000f0            add      byte ptr [eax - 0xfffffe0], bl 
  0x0106799E  56                      push     esi                            
  0x0106799F  00480b                  add      byte ptr [eax + 0xb], cl       
  0x010679A2  0000                    add      byte ptr [eax], al             
  0x010679A4  40                      inc      eax                            
  0x010679A5  99                      cdq                                     
  0x010679A6  2100                    and      dword ptr [eax], eax           
  0x010679A8  007054                  add      byte ptr [eax + 0x54], dh      
  0x010679AB  00480b                  add      byte ptr [eax + 0xb], cl       
  0x010679AE  0000                    add      byte ptr [eax], al             
  0x010679B0  00f4                    add      ah, dh                         
  0x010679B2  56                      push     esi                            
  0x010679B3  0009                    add      byte ptr [ecx], cl             
  0x010679B5  0000                    add      byte ptr [eax], al             
  0x010679B7  0000                    add      byte ptr [eax], al             
  0x010679B9  f4                      hlt                                     
  0x010679BA  57                      push     edi                            
  0x010679BB  0002                    add      byte ptr [edx], al             
  0x010679BD  0000                    add      byte ptr [eax], al             
  0x010679BF  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x010679C5  0100                    add      dword ptr [eax], eax           
  0x010679C7  0003                    add      byte ptr [ebx], al             
  0x010679C9  0020                    add      byte ptr [eax], ah             
  0x010679CB  0000                    add      byte ptr [eax], al             
  0x010679CD  2405                    and      al, 5                          
  0x010679CF  0000                    add      byte ptr [eax], al             
  0x010679D2  56                      push     esi                            
  0x010679D3  00fd                    add      ch, bh                         
  0x010679D5  0000                    add      byte ptr [eax], al             
  0x010679D7  008545010009            add      byte ptr [ebp + 0x9000145], al 
  0x010679DD  2405                    and      al, 5                          
  0x010679DF  0000                    add      byte ptr [eax], al             
  0x010679E1  f4                      hlt                                     
  0x010679E2  56                      push     esi                            
  0x010679E3  000c00                  add      byte ptr [eax + eax], cl       
  0x010679E6  0000                    add      byte ptr [eax], al             
  0x010679E8  00f4                    add      ah, dh                         
  0x010679EA  7000                    jo       0x10679ec                      
                                        ; XREF: 0x010679EA (cond_jump)
  0x010679EC  2201                    and      al, byte ptr [ecx]             
  0x010679EE  0000                    add      byte ptr [eax], al             
  0x010679F0  00f4                    add      ah, dh                         
  0x010679F2  7100                    jno      0x10679f4                      
                                        ; XREF: 0x010679F2 (cond_jump)
  0x010679F4  de0a                    fimul    word ptr [edx]                 
  0x010679F6  0000                    add      byte ptr [eax], al             
  0x010679F8  80f00b                  xor      al, 0xb                        
  0x010679FB  008001000000            add      byte ptr [eax + 1], al         
  0x01067A01  f4                      hlt                                     
  0x01067A02  56                      push     esi                            
  0x01067A03  0019                    add      byte ptr [ecx], bl             
  0x01067A05  0000                    add      byte ptr [eax], al             
  0x01067A07  0000                    add      byte ptr [eax], al             
  0x01067A09  f4                      hlt                                     
  0x01067A0A  57                      push     edi                            
  0x01067A0B  0002                    add      byte ptr [edx], al             
  0x01067A0D  0000                    add      byte ptr [eax], al             
  0x01067A0F  0000                    add      byte ptr [eax], al             
  0x01067A11  0039                    add      byte ptr [ecx], bh             
  0x01067A13  0000                    add      byte ptr [eax], al             
  0x01067A15  f4                      hlt                                     
  0x01067A16  7000                    jo       0x1067a18                      
                                        ; XREF: 0x01067A16 (cond_jump)
  0x01067A18  800000                  add      byte ptr [eax], 0              
  0x01067A1B  0000                    add      byte ptr [eax], al             
  0x01067A1D  f4                      hlt                                     
  0x01067A1E  60                      pushal                                  
  0x01067A1F  00400b                  add      byte ptr [eax + 0xb], al       
  0x01067A22  0000                    add      byte ptr [eax], al             
  0x01067A24  80f00b                  xor      al, 0xb                        
  0x01067A27  008001000003            add      byte ptr [eax + 0x3000001], al 
  0x01067A2D  0020                    add      byte ptr [eax], ah             
  0x01067A2F  0000                    add      byte ptr [eax], al             
  0x01067A31  2405                    and      al, 5                          
  0x01067A33  000c00                  add      byte ptr [eax + eax], cl       
  0x01067A36  0000                    add      byte ptr [eax], al             
  0x01067A38  00f4                    add      ah, dh                         
  0x01067A3A  56                      push     esi                            
  0x01067A3B  0019                    add      byte ptr [ecx], bl             
  0x01067A3D  0000                    add      byte ptr [eax], al             
  0x01067A3F  0000                    add      byte ptr [eax], al             
  0x01067A41  f4                      hlt                                     
  0x01067A42  57                      push     edi                            
  0x01067A43  0000                    add      byte ptr [eax], al             
  0x01067A45  0000                    add      byte ptr [eax], al             
  0x01067A47  0000                    add      byte ptr [eax], al             
  0x01067A49  f4                      hlt                                     
  0x01067A4A  7000                    jo       0x1067a4c                      
                                        ; XREF: 0x01067A4A (cond_jump)
  0x01067A4C  800000                  add      byte ptr [eax], 0              
  0x01067A4F  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x01067A55  0100                    add      dword ptr [eax], eax           
  0x01067A57  0003                    add      byte ptr [ebx], al             
  0x01067A59  0020                    add      byte ptr [eax], ah             
  0x01067A5B  0000                    add      byte ptr [eax], al             
  0x01067A5D  2405                    and      al, 5                          
  0x01067A5F  000c00                  add      byte ptr [eax + eax], cl       
  0x01067A62  0000                    add      byte ptr [eax], al             
  0x01067A64  0000                    add      byte ptr [eax], al             
  0x01067A66  0000                    add      byte ptr [eax], al             
  0x01067A68  40                      inc      eax                            
  0x01067A69  1bd0                    sbb      edx, eax                       
  0x01067A6B  00bc0000007201          add      byte ptr [eax + eax + 0x1720000], bh 
  0x01067A72  0500265e7d              add      eax, 0x7d5e2600                
  0x01067A77  0000                    add      byte ptr [eax], al             
  0x01067A79  7060                    jo       0x1067adb                      
  0x01067A7B  0000                    add      byte ptr [eax], al             
  0x01067A7D  07                      pop      es                             
  0x01067A7E  0000                    add      byte ptr [eax], al             
  0x01067A80  00f4                    add      ah, dh                         
  0x01067A82  56                      push     esi                            
  0x01067A83  0007                    add      byte ptr [edi], al             
  0x01067A85  0000                    add      byte ptr [eax], al             
  0x01067A87  0000                    add      byte ptr [eax], al             
  0x01067A89  f4                      hlt                                     
  0x01067A8A  60                      pushal                                  
  0x01067A8B  0000                    add      byte ptr [eax], al             
  0x01067A8D  0000                    add      byte ptr [eax], al             
  0x01067A8F  0000                    add      byte ptr [eax], al             
  0x01067A91  f4                      hlt                                     
  0x01067A92  7000                    jo       0x1067a94                      
                                        ; XREF: 0x01067A92 (cond_jump)
  0x01067A94  0001                    add      byte ptr [ecx], al             
  0x01067A96  0000                    add      byte ptr [eax], al             
  0x01067A98  0000                    add      byte ptr [eax], al             
  0x01067A9A  3900                    cmp      dword ptr [eax], eax           
  0x01067A9C  80010d                  add      byte ptr [ecx], 0xd            
  0x01067A9F  0000                    add      byte ptr [eax], al             
  0x01067AA1  f4                      hlt                                     
  0x01067AA2  56                      push     esi                            
  0x01067AA3  0007                    add      byte ptr [edi], al             
  0x01067AA5  0000                    add      byte ptr [eax], al             
  0x01067AA7  0000                    add      byte ptr [eax], al             
  0x01067AA9  f4                      hlt                                     
  0x01067AAA  60                      pushal                                  
  0x01067AAB  0000                    add      byte ptr [eax], al             
  0x01067AAD  0100                    add      dword ptr [eax], eax           
  0x01067AAF  0000                    add      byte ptr [eax], al             
  0x01067AB1  f4                      hlt                                     
  0x01067AB2  7000                    jo       0x1067ab4                      
                                        ; XREF: 0x01067AB2 (cond_jump)
  0x01067AB4  0001                    add      byte ptr [ecx], al             
  0x01067AB6  0000                    add      byte ptr [eax], al             
  0x01067AB8  0001                    add      byte ptr [ecx], al             
  0x01067ABA  3900                    cmp      dword ptr [eax], eax           
  0x01067ABC  80010d                  add      byte ptr [ecx], 0xd            
  0x01067ABF  0000                    add      byte ptr [eax], al             
  0x01067AC1  f4                      hlt                                     
  0x01067AC2  56                      push     esi                            
  0x01067AC3  0007                    add      byte ptr [edi], al             
  0x01067AC5  0000                    add      byte ptr [eax], al             
  0x01067AC7  0000                    add      byte ptr [eax], al             
  0x01067AC9  f4                      hlt                                     
  0x01067ACA  60                      pushal                                  
  0x01067ACB  0000                    add      byte ptr [eax], al             
  0x01067ACD  0200                    add      al, byte ptr [eax]             
  0x01067ACF  0000                    add      byte ptr [eax], al             
  0x01067AD1  f4                      hlt                                     
  0x01067AD2  7000                    jo       0x1067ad4                      
                                        ; XREF: 0x01067AD2 (cond_jump)
  0x01067AD4  0001                    add      byte ptr [ecx], al             
  0x01067AD6  0000                    add      byte ptr [eax], al             
  0x01067AD8  0002                    add      byte ptr [edx], al             
  0x01067ADA  3900                    cmp      dword ptr [eax], eax           
  0x01067ADC  80010d                  add      byte ptr [ecx], 0xd            
  0x01067ADF  0000                    add      byte ptr [eax], al             
  0x01067AE1  f4                      hlt                                     
  0x01067AE2  56                      push     esi                            
  0x01067AE3  0007                    add      byte ptr [edi], al             
  0x01067AE5  0000                    add      byte ptr [eax], al             
  0x01067AE7  0000                    add      byte ptr [eax], al             
  0x01067AE9  f4                      hlt                                     
  0x01067AEA  60                      pushal                                  
  0x01067AEB  0000                    add      byte ptr [eax], al             
  0x01067AED  0300                    add      eax, dword ptr [eax]           
  0x01067AEF  0000                    add      byte ptr [eax], al             
  0x01067AF1  f4                      hlt                                     
  0x01067AF2  7000                    jo       0x1067af4                      
                                        ; XREF: 0x01067AF2 (cond_jump)
  0x01067AF4  0001                    add      byte ptr [ecx], al             
  0x01067AF6  0000                    add      byte ptr [eax], al             
  0x01067AF8  0003                    add      byte ptr [ebx], al             
  0x01067AFA  3900                    cmp      dword ptr [eax], eax           
  0x01067AFC  80010d                  add      byte ptr [ecx], 0xd            
  0x01067AFF  0000                    add      byte ptr [eax], al             
  0x01067B01  f4                      hlt                                     
  0x01067B02  56                      push     esi                            
  0x01067B03  0007                    add      byte ptr [edi], al             
  0x01067B05  0000                    add      byte ptr [eax], al             
  0x01067B07  0000                    add      byte ptr [eax], al             
  0x01067B09  f4                      hlt                                     
  0x01067B0A  60                      pushal                                  
  0x01067B0B  0000                    add      byte ptr [eax], al             
  0x01067B0D  0400                    add      al, 0                          
  0x01067B0F  0000                    add      byte ptr [eax], al             
  0x01067B11  f4                      hlt                                     
  0x01067B12  7000                    jo       0x1067b14                      
                                        ; XREF: 0x01067B12 (cond_jump)
  0x01067B14  0001                    add      byte ptr [ecx], al             
  0x01067B16  0000                    add      byte ptr [eax], al             
  0x01067B18  000439                  add      byte ptr [ecx + edi], al       
  0x01067B1B  0080010d0000            add      byte ptr [eax + 0xd01], al     
  0x01067B21  f4                      hlt                                     
  0x01067B22  44                      inc      esp                            
  0x01067B23  0000                    add      byte ptr [eax], al             
  0x01067B25  004000                  add      byte ptr [eax], al             
  0x01067B28  00704c                  add      byte ptr [eax + 0x4c], dh      
  0x01067B2B  0000                    add      byte ptr [eax], al             
  0x01067B2D  0000                    add      byte ptr [eax], al             
  0x01067B2F  0000                    add      byte ptr [eax], al             
  0x01067B31  f4                      hlt                                     
  0x01067B32  44                      inc      esp                            
  0x01067B33  007982                  add      byte ptr [ecx - 0x7e], bh      
  0x01067B36  5a                      pop      edx                            
  0x01067B37  0000                    add      byte ptr [eax], al             
  0x01067B39  704c                    jo       0x1067b87                      
  0x01067B3B  0001                    add      byte ptr [ecx], al             
  0x01067B3D  0000                    add      byte ptr [eax], al             
  0x01067B3F  0000                    add      byte ptr [eax], al             
  0x01067B41  f4                      hlt                                     
  0x01067B42  44                      inc      esp                            
  0x01067B43  0000                    add      byte ptr [eax], al             
  0x01067B45  004000                  add      byte ptr [eax], al             
  0x01067B48  00704c                  add      byte ptr [eax + 0x4c], dh      
  0x01067B4B  0002                    add      byte ptr [edx], al             
  0x01067B4D  0000                    add      byte ptr [eax], al             
  0x01067B4F  0000                    add      byte ptr [eax], al             
  0x01067B51  f4                      hlt                                     
  0x01067B52  44                      inc      esp                            
  0x01067B53  003c41                  add      byte ptr [ecx + eax*2], bh     
  0x01067B56  2d0000704c              sub      eax, 0x4c700000                
  0x01067B5B  0003                    add      byte ptr [ebx], al             
  0x01067B5D  0000                    add      byte ptr [eax], al             
  0x01067B5F  0000                    add      byte ptr [eax], al             
  0x01067B61  f4                      hlt                                     
  0x01067B62  44                      inc      esp                            
  0x01067B63  003c41                  add      byte ptr [ecx + eax*2], bh     
  0x01067B66  2d0000704c              sub      eax, 0x4c700000                
  0x01067B6B  000400                  add      byte ptr [eax + eax], al       
  0x01067B6E  0000                    add      byte ptr [eax], al             
  0x01067B70  00f0                    add      al, dh                         
  0x01067B72  6200                    bound    eax, qword ptr [eax]           
  0x01067B74  0007                    add      byte ptr [edi], al             
  0x01067B76  0000                    add      byte ptr [eax], al             
  0x01067B78  0000                    add      byte ptr [eax], al             
  0x01067B7A  0000                    add      byte ptr [eax], al             
  0x01067B7C  0000                    add      byte ptr [eax], al             
  0x01067B7E  0000                    add      byte ptr [eax], al             
  0x01067B80  d542                    aad      0x42                           
  0x01067B82  0200                    add      al, byte ptr [eax]             
  0x01067B84  9e                      sahf                                    
  0x01067B85  42                      inc      edx                            
  0x01067B86  0200                    add      al, byte ptr [eax]             
  0x01067B88  0300                    add      eax, dword ptr [eax]           
  0x01067B8A  2000                    and      byte ptr [eax], al             
  0x01067B8C  0ba4050000f460          or       esp, dword ptr [ebp + eax + 0x60f40000] 
  0x01067B93  0000                    add      byte ptr [eax], al             
  0x01067B95  0000                    add      byte ptr [eax], al             
  0x01067B97  0000                    add      byte ptr [eax], al             
  0x01067B99  0138                    add      dword ptr [eax], edi           
  0x01067B9B  0000                    add      byte ptr [eax], al             
  0x01067B9E  4e                      dec      esi                            
  0x01067B9F  0000                    add      byte ptr [eax], al             
  0x01067BA1  0000                    add      byte ptr [eax], al             
  0x01067BA3  009005060004            add      byte ptr [eax + 0x4000605], dl 
  0x01067BA9  0000                    add      byte ptr [eax], al             
  0x01067BAB  00e1                    add      cl, ah                         
  0x01067BAD  0020                    add      byte ptr [eax], ah             
  0x01067BAF  0000                    add      byte ptr [eax], al             
  0x01067BB1  e84e000058              call     0x59067c04                     
  0x01067BB6  5e                      pop      esi                            
  0x01067BB7  0000                    add      byte ptr [eax], al             
  0x01067BB9  f4                      hlt                                     
  0x01067BBA  6200                    bound    eax, qword ptr [eax]           
  0x01067BBC  0005000000f4            add      byte ptr [0xf4000000], al      
  0x01067BC2  660000                  add      byte ptr [eax], al             
  0x01067BC5  06                      push     es                             
  0x01067BC6  0000                    add      byte ptr [eax], al             
  0x01067BC8  00f4                    add      ah, dh                         
  0x01067BCA  7000                    jo       0x1067bcc                      
                                        ; XREF: 0x01067BCA (cond_jump)
  0x01067BCC  0001                    add      byte ptr [ecx], al             
  0x01067BCE  0000                    add      byte ptr [eax], al             
  0x01067BD0  00f4                    add      ah, dh                         
  0x01067BD2  60                      pushal                                  
  0x01067BD3  0000                    add      byte ptr [eax], al             
  0x01067BD5  0000                    add      byte ptr [eax], al             
  0x01067BD7  0000                    add      byte ptr [eax], al             
  0x01067BD9  f4                      hlt                                     
  0x01067BDA  640000                  add      byte ptr fs:[eax], al          
  0x01067BDD  0000                    add      byte ptr [eax], al             
  0x01067BDF  0000                    add      byte ptr [eax], al             
  0x01067BE1  1522009100              adc      eax, 0x910022                  
  0x01067BE6  06                      push     es                             
  0x01067BE7  000c00                  add      byte ptr [eax + eax], cl       
  0x01067BEA  0000                    add      byte ptr [eax], al             
  0x01067BEC  0088f000d088            add      byte ptr [eax - 0x772fff10], cl 
  0x01067BF3  00d2                    add      dl, dl                         
  0x01067BF5  88f0                    mov      al, dh                         
  0x01067BF7  00d2                    add      dl, dl                         
  0x01067BF9  88f0                    mov      al, dh                         
  0x01067BFB  00d2                    add      dl, dl                         
  0x01067BFD  80c000                  add      al, 0                          
  0x01067C00  d3dd                    rcr      ebp, cl                        
  0x01067C02  4e                      dec      esi                            
  0x01067C03  0000                    add      byte ptr [eax], al             
  0x01067C05  b022                    mov      al, 0x22                       
  0x01067C07  0000                    add      byte ptr [eax], al             
  0x01067C09  f4                      hlt                                     
  0x01067C0A  640000                  add      byte ptr fs:[eax], al          
  0x01067C0D  0000                    add      byte ptr [eax], al             
  0x01067C0F  0000                    add      byte ptr [eax], al             
  0x01067C11  5a                      pop      edx                            
  0x01067C12  56                      push     esi                            
  0x01067C13  0000                    add      byte ptr [eax], al             
  0x01067C15  5e                      pop      esi                            
  0x01067C16  56                      push     esi                            
  0x01067C17  0013                    add      byte ptr [ebx], dl             
  0x01067C19  f4                      hlt                                     
  0x01067C1A  6200                    bound    eax, qword ptr [eax]           
  0x01067C1C  000500001b00            add      byte ptr [0x1b0000], al        
  0x01067C22  2000                    and      byte ptr [eax], al             
  0x01067C24  91                      xchg     ecx, eax                       
  0x01067C25  0006                    add      byte ptr [esi], al             
  0x01067C27  000500000000            add      byte ptr [0], al               
  0x01067C2D  da44008a                fiadd    dword ptr [eax + eax - 0x76]   
  0x01067C31  0020                    add      byte ptr [eax], ah             
  0x01067C33  004700                  add      byte ptr [edi], al             
  0x01067C36  2000                    and      byte ptr [eax], al             
  0x01067C38  40                      inc      eax                            
  0x01067C39  90                      nop                                     
  0x01067C3A  0200                    add      al, byte ptr [eax]             
  0x01067C3C  260020                  add      byte ptr es:[eax], ah          
  0x01067C3F  00911c0c0000            add      byte ptr [ecx + 0xc1c], dl     
  0x01067C45  7056                    jo       0x1067c9d                      
  0x01067C47  0001                    add      byte ptr [ecx], al             
  0x01067C49  07                      pop      es                             
  0x01067C4A  0000                    add      byte ptr [eax], al             
  0x01067C4C  00a721000026            add      byte ptr [edi + 0x26000021], ah 
  0x01067C52  2100                    and      dword ptr [eax], eax           
  0x01067C54  13402f                  adc      eax, dword ptr [eax + 0x2f]    
  0x01067C57  009017060009            add      byte ptr [eax + 0x9000617], dl 
  0x01067C5D  0000                    add      byte ptr [eax], al             
  0x01067C5F  0010                    add      byte ptr [eax], dl             
  0x01067C61  c521                    lds      esp, ptr [ecx]                 
  0x01067C63  0000                    add      byte ptr [eax], al             
  0x01067C65  0000                    add      byte ptr [eax], al             
  0x01067C67  0000                    add      byte ptr [eax], al             
  0x01067C69  c421                    les      esp, ptr [ecx]                 
  0x01067C6B  00840020003000          add      byte ptr [eax + eax + 0x300020], al 
  0x01067C72  2000                    and      byte ptr [eax], al             
  0x01067C74  00ae20001021            add      byte ptr [esi + 0x21100020], ch 
  0x01067C7A  2000                    and      byte ptr [eax], al             
  0x01067C7C  2a00                    sub      al, byte ptr [eax]             
  0x01067C7E  2000                    and      byte ptr [eax], al             
  0x01067C80  007056                  add      byte ptr [eax + 0x56], dh      
  0x01067C83  0003                    add      byte ptr [ebx], al             
  0x01067C85  07                      pop      es                             
  0x01067C86  0000                    add      byte ptr [eax], al             
  0x01067C88  13f4                    adc      esi, esp                       
  0x01067C8A  6200                    bound    eax, qword ptr [eax]           
  0x01067C8C  0006                    add      byte ptr [esi], al             
  0x01067C8E  0000                    add      byte ptr [eax], al             
  0x01067C90  1b00                    sbb      eax, dword ptr [eax]           
  0x01067C92  2000                    and      byte ptr [eax], al             
  0x01067C94  91                      xchg     ecx, eax                       
  0x01067C95  0006                    add      byte ptr [esi], al             
  0x01067C97  000500000000            add      byte ptr [0], al               
                                        ; XREF: 0x01067C45 (cond_jump)
  0x01067C9D  da44008a                fiadd    dword ptr [eax + eax - 0x76]   
  0x01067CA1  0020                    add      byte ptr [eax], ah             
  0x01067CA3  004700                  add      byte ptr [edi], al             
  0x01067CA6  2000                    and      byte ptr [eax], al             
  0x01067CA8  40                      inc      eax                            
  0x01067CA9  90                      nop                                     
  0x01067CAA  0200                    add      al, byte ptr [eax]             
  0x01067CAC  260020                  add      byte ptr es:[eax], ah          
  0x01067CAF  00911c0c0000            add      byte ptr [ecx + 0xc1c], dl     
  0x01067CB5  7056                    jo       0x1067d0d                      
  0x01067CB7  0002                    add      byte ptr [edx], al             
  0x01067CB9  07                      pop      es                             
  0x01067CBA  0000                    add      byte ptr [eax], al             
  0x01067CBC  00a721000026            add      byte ptr [edi + 0x26000021], ah 
  0x01067CC2  2100                    and      dword ptr [eax], eax           
  0x01067CC4  13402f                  adc      eax, dword ptr [eax + 0x2f]    
  0x01067CC7  009017060009            add      byte ptr [eax + 0x9000617], dl 
  0x01067CCD  0000                    add      byte ptr [eax], al             
  0x01067CCF  0010                    add      byte ptr [eax], dl             
  0x01067CD1  c521                    lds      esp, ptr [ecx]                 
  0x01067CD3  0000                    add      byte ptr [eax], al             
  0x01067CD5  0000                    add      byte ptr [eax], al             
  0x01067CD7  0000                    add      byte ptr [eax], al             
  0x01067CD9  c421                    les      esp, ptr [ecx]                 
  0x01067CDB  00840020003000          add      byte ptr [eax + eax + 0x300020], al 
  0x01067CE2  2000                    and      byte ptr [eax], al             
  0x01067CE4  00ae20001021            add      byte ptr [esi + 0x21100020], ch 
  0x01067CEA  2000                    and      byte ptr [eax], al             
  0x01067CEC  2a00                    sub      al, byte ptr [eax]             
  0x01067CEE  2000                    and      byte ptr [eax], al             
  0x01067CF0  007056                  add      byte ptr [eax + 0x56], dh      
  0x01067CF3  000407                  add      byte ptr [edi + eax], al       
  0x01067CF6  0000                    add      byte ptr [eax], al             
  0x01067CF8  00f4                    add      ah, dh                         
  0x01067CFA  56                      push     esi                            
  0x01067CFB  0008                    add      byte ptr [eax], cl             
  0x01067CFD  0000                    add      byte ptr [eax], al             
  0x01067CFF  0000                    add      byte ptr [eax], al             
  0x01067D01  f4                      hlt                                     
  0x01067D02  60                      pushal                                  
  0x01067D03  0000                    add      byte ptr [eax], al             
  0x01067D05  05000000f4              add      eax, 0xf4000000                
  0x01067D0A  7000                    jo       0x1067d0c                      
                                        ; XREF: 0x01067D0A (cond_jump)
  0x01067D0C  0001                    add      byte ptr [ecx], al             
  0x01067D0E  0000                    add      byte ptr [eax], al             
  0x01067D10  0000                    add      byte ptr [eax], al             
  0x01067D12  3900                    cmp      dword ptr [eax], eax           
  0x01067D14  80010d                  add      byte ptr [ecx], 0xd            
  0x01067D17  0000                    add      byte ptr [eax], al             
  0x01067D19  f4                      hlt                                     
  0x01067D1A  56                      push     esi                            
  0x01067D1B  0008                    add      byte ptr [eax], cl             
  0x01067D1D  0000                    add      byte ptr [eax], al             
  0x01067D1F  0000                    add      byte ptr [eax], al             
  0x01067D21  f4                      hlt                                     
  0x01067D22  60                      pushal                                  
  0x01067D23  0000                    add      byte ptr [eax], al             
  0x01067D25  06                      push     es                             
  0x01067D26  0000                    add      byte ptr [eax], al             
  0x01067D28  00f4                    add      ah, dh                         
  0x01067D2A  7000                    jo       0x1067d2c                      
                                        ; XREF: 0x01067D2A (cond_jump)
  0x01067D2C  0001                    add      byte ptr [ecx], al             
  0x01067D2E  0000                    add      byte ptr [eax], al             
  0x01067D30  0001                    add      byte ptr [ecx], al             
  0x01067D32  3900                    cmp      dword ptr [eax], eax           
  0x01067D34  80010d                  add      byte ptr [ecx], 0xd            
  0x01067D37  0000                    add      byte ptr [eax], al             
  0x01067D39  f4                      hlt                                     
  0x01067D3A  56                      push     esi                            
  0x01067D3B  000f                    add      byte ptr [edi], cl             
  0x01067D3D  0000                    add      byte ptr [eax], al             
  0x01067D3F  0000                    add      byte ptr [eax], al             
  0x01067D41  f4                      hlt                                     
  0x01067D42  60                      pushal                                  
  0x01067D43  0001                    add      byte ptr [ecx], al             
  0x01067D45  07                      pop      es                             
  0x01067D46  0000                    add      byte ptr [eax], al             
  0x01067D48  000438                  add      byte ptr [eax + edi], al       
  0x01067D4B  0000                    add      byte ptr [eax], al             
  0x01067D4D  0039                    add      byte ptr [ecx], bh             
  0x01067D4F  0080010d000c            add      byte ptr [eax + 0xc000d01], al 
  0x01067D55  0000                    add      byte ptr [eax], al             
  0x01067D57  00401b                  add      byte ptr [eax + 0x1b], al      
  0x01067D5A  d000                    rol      byte ptr [eax], 1              
  0x01067D5C  c9                      leave                                   
  0x01067D5D  0000                    add      byte ptr [eax], al             
  0x01067D5F  007201                  add      byte ptr [edx + 1], dh         
  0x01067D62  06                      push     es                             
  0x01067D63  00b0c4870000            add      byte ptr [eax + 0x87c4], dh    
  0x01067D69  7060                    jo       0x1067dcb                      
  0x01067D6B  0000                    add      byte ptr [eax], al             
  0x01067D6D  07                      pop      es                             
  0x01067D6E  0000                    add      byte ptr [eax], al             
  0x01067D70  00f4                    add      ah, dh                         
  0x01067D72  56                      push     esi                            
  0x01067D73  0007                    add      byte ptr [edi], al             
  0x01067D75  0000                    add      byte ptr [eax], al             
  0x01067D77  0000                    add      byte ptr [eax], al             
  0x01067D79  f4                      hlt                                     
  0x01067D7A  60                      pushal                                  
  0x01067D7B  0000                    add      byte ptr [eax], al             
  0x01067D7D  0000                    add      byte ptr [eax], al             
  0x01067D7F  0000                    add      byte ptr [eax], al             
  0x01067D81  f4                      hlt                                     
  0x01067D82  7000                    jo       0x1067d84                      
                                        ; XREF: 0x01067D82 (cond_jump)
  0x01067D84  0001                    add      byte ptr [ecx], al             
  0x01067D86  0000                    add      byte ptr [eax], al             
  0x01067D88  0000                    add      byte ptr [eax], al             
  0x01067D8A  3900                    cmp      dword ptr [eax], eax           
  0x01067D8C  80010d                  add      byte ptr [ecx], 0xd            
  0x01067D8F  0000                    add      byte ptr [eax], al             
  0x01067D91  f4                      hlt                                     
  0x01067D92  56                      push     esi                            
  0x01067D93  0007                    add      byte ptr [edi], al             
  0x01067D95  0000                    add      byte ptr [eax], al             
  0x01067D97  0000                    add      byte ptr [eax], al             
  0x01067D99  f4                      hlt                                     
  0x01067D9A  60                      pushal                                  
  0x01067D9B  0000                    add      byte ptr [eax], al             
  0x01067D9D  0100                    add      dword ptr [eax], eax           
  0x01067D9F  0000                    add      byte ptr [eax], al             
  0x01067DA1  f4                      hlt                                     
  0x01067DA2  7000                    jo       0x1067da4                      
                                        ; XREF: 0x01067DA2 (cond_jump)
  0x01067DA4  0001                    add      byte ptr [ecx], al             
  0x01067DA6  0000                    add      byte ptr [eax], al             
  0x01067DA8  0001                    add      byte ptr [ecx], al             
  0x01067DAA  3900                    cmp      dword ptr [eax], eax           
  0x01067DAC  80010d                  add      byte ptr [ecx], 0xd            
  0x01067DAF  0000                    add      byte ptr [eax], al             
  0x01067DB1  f4                      hlt                                     
  0x01067DB2  56                      push     esi                            
  0x01067DB3  0007                    add      byte ptr [edi], al             
  0x01067DB5  0000                    add      byte ptr [eax], al             
  0x01067DB7  0000                    add      byte ptr [eax], al             
  0x01067DB9  f4                      hlt                                     
  0x01067DBA  60                      pushal                                  
  0x01067DBB  0000                    add      byte ptr [eax], al             
  0x01067DBD  0200                    add      al, byte ptr [eax]             
  0x01067DBF  0000                    add      byte ptr [eax], al             
  0x01067DC1  f4                      hlt                                     
  0x01067DC2  7000                    jo       0x1067dc4                      
                                        ; XREF: 0x01067DC2 (cond_jump)
  0x01067DC4  0001                    add      byte ptr [ecx], al             
  0x01067DC6  0000                    add      byte ptr [eax], al             
  0x01067DC8  0002                    add      byte ptr [edx], al             
  0x01067DCA  3900                    cmp      dword ptr [eax], eax           
  0x01067DCC  80010d                  add      byte ptr [ecx], 0xd            
  0x01067DCF  0000                    add      byte ptr [eax], al             
  0x01067DD1  f4                      hlt                                     
  0x01067DD2  56                      push     esi                            
  0x01067DD3  0007                    add      byte ptr [edi], al             
  0x01067DD5  0000                    add      byte ptr [eax], al             
  0x01067DD7  0000                    add      byte ptr [eax], al             
  0x01067DD9  f4                      hlt                                     
  0x01067DDA  60                      pushal                                  
  0x01067DDB  0000                    add      byte ptr [eax], al             
  0x01067DDD  0300                    add      eax, dword ptr [eax]           
  0x01067DDF  0000                    add      byte ptr [eax], al             
  0x01067DE1  f4                      hlt                                     
  0x01067DE2  7000                    jo       0x1067de4                      
                                        ; XREF: 0x01067DE2 (cond_jump)
  0x01067DE4  0001                    add      byte ptr [ecx], al             
  0x01067DE6  0000                    add      byte ptr [eax], al             
  0x01067DE8  0003                    add      byte ptr [ebx], al             
  0x01067DEA  3900                    cmp      dword ptr [eax], eax           
  0x01067DEC  80010d                  add      byte ptr [ecx], 0xd            
  0x01067DEF  0000                    add      byte ptr [eax], al             
  0x01067DF1  f4                      hlt                                     
  0x01067DF2  56                      push     esi                            
  0x01067DF3  0007                    add      byte ptr [edi], al             
  0x01067DF5  0000                    add      byte ptr [eax], al             
  0x01067DF7  0000                    add      byte ptr [eax], al             
  0x01067DF9  f4                      hlt                                     
  0x01067DFA  60                      pushal                                  
  0x01067DFB  0000                    add      byte ptr [eax], al             
  0x01067DFD  0400                    add      al, 0                          
  0x01067DFF  0000                    add      byte ptr [eax], al             
  0x01067E01  f4                      hlt                                     
  0x01067E02  7000                    jo       0x1067e04                      
                                        ; XREF: 0x01067E02 (cond_jump)
  0x01067E04  0001                    add      byte ptr [ecx], al             
  0x01067E06  0000                    add      byte ptr [eax], al             
  0x01067E08  000439                  add      byte ptr [ecx + edi], al       
  0x01067E0B  0080010d0000            add      byte ptr [eax + 0xd01], al     
  0x01067E11  f4                      hlt                                     
  0x01067E12  44                      inc      esp                            
  0x01067E13  00ff                    add      bh, bh                         
  0x01067E16  7f00                    jg       0x1067e18                      
                                        ; XREF: 0x01067E16 (cond_jump)
  0x01067E18  00704c                  add      byte ptr [eax + 0x4c], dh      
  0x01067E1B  0000                    add      byte ptr [eax], al             
  0x01067E1D  0000                    add      byte ptr [eax], al             
  0x01067E1F  0000                    add      byte ptr [eax], al             
  0x01067E21  704c                    jo       0x1067e6f                      
  0x01067E23  000500000000            add      byte ptr [0], al               
  0x01067E29  f4                      hlt                                     
  0x01067E2A  44                      inc      esp                            
  0x01067E2B  007982                  add      byte ptr [ecx - 0x7e], bh      
  0x01067E2E  5a                      pop      edx                            
  0x01067E2F  0000                    add      byte ptr [eax], al             
  0x01067E31  704c                    jo       0x1067e7f                      
  0x01067E33  0002                    add      byte ptr [edx], al             
  0x01067E35  0000                    add      byte ptr [eax], al             
  0x01067E37  0000                    add      byte ptr [eax], al             
  0x01067E39  704c                    jo       0x1067e87                      
  0x01067E3B  0003                    add      byte ptr [ebx], al             
  0x01067E3D  0000                    add      byte ptr [eax], al             
  0x01067E3F  0000                    add      byte ptr [eax], al             
  0x01067E41  f4                      hlt                                     
  0x01067E42  44                      inc      esp                            
  0x01067E43  007982                  add      byte ptr [ecx - 0x7e], bh      
  0x01067E46  5a                      pop      edx                            
  0x01067E47  0000                    add      byte ptr [eax], al             
  0x01067E49  704c                    jo       0x1067e97                      
  0x01067E4B  0006                    add      byte ptr [esi], al             
  0x01067E4D  0000                    add      byte ptr [eax], al             
  0x01067E4F  0000                    add      byte ptr [eax], al             
  0x01067E51  704c                    jo       0x1067e9f                      
  0x01067E53  0009                    add      byte ptr [ecx], cl             
  0x01067E55  0000                    add      byte ptr [eax], al             
  0x01067E57  0000                    add      byte ptr [eax], al             
  0x01067E59  f4                      hlt                                     
  0x01067E5A  44                      inc      esp                            
  0x01067E5B  0000                    add      byte ptr [eax], al             
  0x01067E5D  0000                    add      byte ptr [eax], al             
  0x01067E5F  0000                    add      byte ptr [eax], al             
  0x01067E61  704c                    jo       0x1067eaf                      
  0x01067E63  000400                  add      byte ptr [eax + eax], al       
  0x01067E66  0000                    add      byte ptr [eax], al             
  0x01067E68  00704c                  add      byte ptr [eax + 0x4c], dh      
  0x01067E6B  0008                    add      byte ptr [eax], cl             
  0x01067E6D  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01067E21 (cond_jump)
  0x01067E6F  0000                    add      byte ptr [eax], al             
  0x01067E71  704c                    jo       0x1067ebf                      
  0x01067E73  0001                    add      byte ptr [ecx], al             
  0x01067E75  0000                    add      byte ptr [eax], al             
  0x01067E77  0000                    add      byte ptr [eax], al             
  0x01067E79  704c                    jo       0x1067ec7                      
  0x01067E7B  0007                    add      byte ptr [edi], al             
  0x01067E7D  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01067E31 (cond_jump)
  0x01067E7F  0000                    add      byte ptr [eax], al             
  0x01067E82  6200                    bound    eax, qword ptr [eax]           
  0x01067E84  0007                    add      byte ptr [edi], al             
  0x01067E86  0000                    add      byte ptr [eax], al             
  0x01067E88  0000                    add      byte ptr [eax], al             
  0x01067E8A  0000                    add      byte ptr [eax], al             
  0x01067E8C  0000                    add      byte ptr [eax], al             
  0x01067E8E  0000                    add      byte ptr [eax], al             
  0x01067E90  d542                    aad      0x42                           
  0x01067E92  0200                    add      al, byte ptr [eax]             
  0x01067E94  9e                      sahf                                    
  0x01067E95  42                      inc      edx                            
  0x01067E96  0200                    add      al, byte ptr [eax]             
  0x01067E98  0300                    add      eax, dword ptr [eax]           
  0x01067E9A  2000                    and      byte ptr [eax], al             
  0x01067E9C  0ba4050000f460          or       esp, dword ptr [ebp + eax + 0x60f40000] 
  0x01067EA3  0000                    add      byte ptr [eax], al             
  0x01067EA5  0000                    add      byte ptr [eax], al             
  0x01067EA7  0000                    add      byte ptr [eax], al             
  0x01067EA9  0138                    add      dword ptr [eax], edi           
  0x01067EAB  0000                    add      byte ptr [eax], al             
  0x01067EAE  4e                      dec      esi                            
                                        ; XREF: 0x01067E61 (cond_jump)
  0x01067EAF  0000                    add      byte ptr [eax], al             
  0x01067EB1  0000                    add      byte ptr [eax], al             
  0x01067EB3  00900a060004            add      byte ptr [eax + 0x400060a], dl 
  0x01067EB9  0000                    add      byte ptr [eax], al             
  0x01067EBB  00e1                    add      cl, ah                         
  0x01067EBD  0020                    add      byte ptr [eax], ah             
                                        ; XREF: 0x01067E71 (cond_jump)
  0x01067EBF  0000                    add      byte ptr [eax], al             
  0x01067EC1  e84e000058              call     0x59067f14                     
  0x01067EC6  5e                      pop      esi                            
                                        ; XREF: 0x01067E79 (cond_jump)
  0x01067EC7  0000                    add      byte ptr [eax], al             
  0x01067EC9  f4                      hlt                                     
  0x01067ECA  6200                    bound    eax, qword ptr [eax]           
  0x01067ECC  0005000000f4            add      byte ptr [0xf4000000], al      
  0x01067ED2  660000                  add      byte ptr [eax], al             
  0x01067ED5  06                      push     es                             
  0x01067ED6  0000                    add      byte ptr [eax], al             
  0x01067ED8  00f4                    add      ah, dh                         
  0x01067EDA  7000                    jo       0x1067edc                      
                                        ; XREF: 0x01067EDA (cond_jump)
  0x01067EDC  0001                    add      byte ptr [ecx], al             
  0x01067EDE  0000                    add      byte ptr [eax], al             
  0x01067EE0  00f4                    add      ah, dh                         
  0x01067EE2  60                      pushal                                  
  0x01067EE3  0000                    add      byte ptr [eax], al             
  0x01067EE5  0000                    add      byte ptr [eax], al             
  0x01067EE7  0000                    add      byte ptr [eax], al             
  0x01067EE9  f4                      hlt                                     
  0x01067EEA  640000                  add      byte ptr fs:[eax], al          
  0x01067EED  0000                    add      byte ptr [eax], al             
  0x01067EEF  0000                    add      byte ptr [eax], al             
  0x01067EF1  1522009100              adc      eax, 0x910022                  
  0x01067EF6  06                      push     es                             
  0x01067EF7  0011                    add      byte ptr [ecx], dl             
  0x01067EF9  0000                    add      byte ptr [eax], al             
  0x01067EFB  0000                    add      byte ptr [eax], al             
  0x01067EFD  88f0                    mov      al, dh                         
  0x01067EFF  00d0                    add      al, dl                         
  0x01067F01  dc4e00                  fmul     qword ptr [esi]                
  0x01067F04  d888f000d2dc            fmul     dword ptr [eax - 0x232dff10]   
  0x01067F0A  4e                      dec      esi                            
  0x01067F0B  00da                    add      dl, bl                         
  0x01067F0D  88f0                    mov      al, dh                         
  0x01067F0F  00d2                    add      dl, dl                         
  0x01067F11  dc4e00                  fmul     qword ptr [esi]                
  0x01067F14  da88f000d2dc            fimul    dword ptr [eax - 0x232dff10]   
  0x01067F1A  4e                      dec      esi                            
  0x01067F1B  00da                    add      dl, bl                         
  0x01067F1D  88f0                    mov      al, dh                         
  0x01067F1F  00d3                    add      bl, dl                         
  0x01067F21  dc4e00                  fmul     qword ptr [esi]                
  0x01067F24  dbdd                    fcmovnu  st(0), st(5)                   
  0x01067F26  4e                      dec      esi                            
  0x01067F27  0000                    add      byte ptr [eax], al             
  0x01067F29  b022                    mov      al, 0x22                       
  0x01067F2B  0000                    add      byte ptr [eax], al             
  0x01067F2D  f4                      hlt                                     
  0x01067F2E  640000                  add      byte ptr fs:[eax], al          
  0x01067F31  0000                    add      byte ptr [eax], al             
  0x01067F33  0000                    add      byte ptr [eax], al             
  0x01067F35  5a                      pop      edx                            
  0x01067F36  56                      push     esi                            
  0x01067F37  0000                    add      byte ptr [eax], al             
  0x01067F39  5e                      pop      esi                            
  0x01067F3A  57                      push     edi                            
  0x01067F3B  0013                    add      byte ptr [ebx], dl             
  0x01067F3D  f4                      hlt                                     
  0x01067F3E  6200                    bound    eax, qword ptr [eax]           
  0x01067F40  000500001b00            add      byte ptr [0x1b0000], al        
  0x01067F46  2000                    and      byte ptr [eax], al             
  0x01067F48  91                      xchg     ecx, eax                       
  0x01067F49  0006                    add      byte ptr [esi], al             
  0x01067F4B  000500000000            add      byte ptr [0], al               
  0x01067F51  da44008a                fiadd    dword ptr [eax + eax - 0x76]   
  0x01067F55  0020                    add      byte ptr [eax], ah             
  0x01067F57  004700                  add      byte ptr [edi], al             
  0x01067F5A  2000                    and      byte ptr [eax], al             
  0x01067F5C  40                      inc      eax                            
  0x01067F5D  90                      nop                                     
  0x01067F5E  0200                    add      al, byte ptr [eax]             
  0x01067F60  260020                  add      byte ptr es:[eax], ah          
  0x01067F63  00911c0c0000            add      byte ptr [ecx + 0xc1c], dl     
  0x01067F69  7056                    jo       0x1067fc1                      
  0x01067F6B  0001                    add      byte ptr [ecx], al             
  0x01067F6D  07                      pop      es                             
  0x01067F6E  0000                    add      byte ptr [eax], al             
  0x01067F70  00a721000026            add      byte ptr [edi + 0x26000021], ah 
  0x01067F76  2100                    and      dword ptr [eax], eax           
  0x01067F78  13402f                  adc      eax, dword ptr [eax + 0x2f]    
  0x01067F7B  009017060009            add      byte ptr [eax + 0x9000617], dl 
  0x01067F81  0000                    add      byte ptr [eax], al             
  0x01067F83  0010                    add      byte ptr [eax], dl             
  0x01067F85  c521                    lds      esp, ptr [ecx]                 
  0x01067F87  0000                    add      byte ptr [eax], al             
  0x01067F89  0000                    add      byte ptr [eax], al             
  0x01067F8B  0000                    add      byte ptr [eax], al             
  0x01067F8D  c421                    les      esp, ptr [ecx]                 
  0x01067F8F  00840020003000          add      byte ptr [eax + eax + 0x300020], al 
  0x01067F96  2000                    and      byte ptr [eax], al             
  0x01067F98  00ae20001021            add      byte ptr [esi + 0x21100020], ch 
  0x01067F9E  2000                    and      byte ptr [eax], al             
  0x01067FA0  2a00                    sub      al, byte ptr [eax]             
  0x01067FA2  2000                    and      byte ptr [eax], al             
  0x01067FA4  007056                  add      byte ptr [eax + 0x56], dh      
  0x01067FA7  0003                    add      byte ptr [ebx], al             
  0x01067FA9  07                      pop      es                             
  0x01067FAA  0000                    add      byte ptr [eax], al             
  0x01067FAC  13f4                    adc      esi, esp                       
  0x01067FAE  6200                    bound    eax, qword ptr [eax]           
  0x01067FB0  0006                    add      byte ptr [esi], al             
  0x01067FB2  0000                    add      byte ptr [eax], al             
  0x01067FB4  1b00                    sbb      eax, dword ptr [eax]           
  0x01067FB6  2000                    and      byte ptr [eax], al             
  0x01067FB8  91                      xchg     ecx, eax                       
  0x01067FB9  0006                    add      byte ptr [esi], al             
  0x01067FBB  000500000000            add      byte ptr [0], al               
                                        ; XREF: 0x01067F69 (cond_jump)
  0x01067FC1  da44008a                fiadd    dword ptr [eax + eax - 0x76]   
  0x01067FC5  0020                    add      byte ptr [eax], ah             
  0x01067FC7  004700                  add      byte ptr [edi], al             
  0x01067FCA  2000                    and      byte ptr [eax], al             
  0x01067FCC  40                      inc      eax                            
  0x01067FCD  90                      nop                                     
  0x01067FCE  0200                    add      al, byte ptr [eax]             
  0x01067FD0  260020                  add      byte ptr es:[eax], ah          
  0x01067FD3  00911c0c0000            add      byte ptr [ecx + 0xc1c], dl     
  0x01067FD9  7056                    jo       0x1068031                      
  0x01067FDB  0002                    add      byte ptr [edx], al             
  0x01067FDD  07                      pop      es                             
  0x01067FDE  0000                    add      byte ptr [eax], al             
  0x01067FE0  00a721000026            add      byte ptr [edi + 0x26000021], ah 
  0x01067FE6  2100                    and      dword ptr [eax], eax           
  0x01067FE8  13402f                  adc      eax, dword ptr [eax + 0x2f]    
  0x01067FEB  009017060009            add      byte ptr [eax + 0x9000617], dl 
  0x01067FF1  0000                    add      byte ptr [eax], al             
  0x01067FF3  0010                    add      byte ptr [eax], dl             
  0x01067FF5  c521                    lds      esp, ptr [ecx]                 
  0x01067FF7  0000                    add      byte ptr [eax], al             
  0x01067FF9  0000                    add      byte ptr [eax], al             
  0x01067FFB  0000                    add      byte ptr [eax], al             
  0x01067FFD  c421                    les      esp, ptr [ecx]                 
  0x01067FFF  00840020003000          add      byte ptr [eax + eax + 0x300020], al 
  0x01068006  2000                    and      byte ptr [eax], al             
  0x01068008  00ae20001021            add      byte ptr [esi + 0x21100020], ch 
  0x0106800E  2000                    and      byte ptr [eax], al             
  0x01068010  2a00                    sub      al, byte ptr [eax]             
  0x01068012  2000                    and      byte ptr [eax], al             
  0x01068014  007056                  add      byte ptr [eax + 0x56], dh      
  0x01068017  000407                  add      byte ptr [edi + eax], al       
  0x0106801A  0000                    add      byte ptr [eax], al             
  0x0106801C  00f4                    add      ah, dh                         
  0x0106801E  56                      push     esi                            
  0x0106801F  0008                    add      byte ptr [eax], cl             
  0x01068021  0000                    add      byte ptr [eax], al             
  0x01068023  0000                    add      byte ptr [eax], al             
  0x01068025  f4                      hlt                                     
  0x01068026  60                      pushal                                  
  0x01068027  0000                    add      byte ptr [eax], al             
  0x01068029  05000000f4              add      eax, 0xf4000000                
  0x0106802E  7000                    jo       0x1068030                      
                                        ; XREF: 0x0106802E (cond_jump)
  0x01068030  0001                    add      byte ptr [ecx], al             
  0x01068032  0000                    add      byte ptr [eax], al             
  0x01068034  0000                    add      byte ptr [eax], al             
  0x01068036  3900                    cmp      dword ptr [eax], eax           
  0x01068038  80010d                  add      byte ptr [ecx], 0xd            
  0x0106803B  0000                    add      byte ptr [eax], al             
  0x0106803D  f4                      hlt                                     
  0x0106803E  56                      push     esi                            
  0x0106803F  0008                    add      byte ptr [eax], cl             
  0x01068041  0000                    add      byte ptr [eax], al             
  0x01068043  0000                    add      byte ptr [eax], al             
  0x01068045  f4                      hlt                                     
  0x01068046  60                      pushal                                  
  0x01068047  0000                    add      byte ptr [eax], al             
  0x01068049  06                      push     es                             
  0x0106804A  0000                    add      byte ptr [eax], al             
  0x0106804C  00f4                    add      ah, dh                         
  0x0106804E  7000                    jo       0x1068050                      
                                        ; XREF: 0x0106804E (cond_jump)
  0x01068050  0001                    add      byte ptr [ecx], al             
  0x01068052  0000                    add      byte ptr [eax], al             
  0x01068054  0001                    add      byte ptr [ecx], al             
  0x01068056  3900                    cmp      dword ptr [eax], eax           
  0x01068058  80010d                  add      byte ptr [ecx], 0xd            
  0x0106805B  0000                    add      byte ptr [eax], al             
  0x0106805D  f4                      hlt                                     
  0x0106805E  56                      push     esi                            
  0x0106805F  000f                    add      byte ptr [edi], cl             
  0x01068061  0000                    add      byte ptr [eax], al             
  0x01068063  0000                    add      byte ptr [eax], al             
  0x01068065  f4                      hlt                                     
  0x01068066  60                      pushal                                  
  0x01068067  0001                    add      byte ptr [ecx], al             
  0x01068069  07                      pop      es                             
  0x0106806A  0000                    add      byte ptr [eax], al             
  0x0106806C  000438                  add      byte ptr [eax + edi], al       
  0x0106806F  0000                    add      byte ptr [eax], al             
  0x01068071  0039                    add      byte ptr [ecx], bh             
  0x01068073  0080010d000c            add      byte ptr [eax + 0xc000d01], al 
  0x01068079  0000                    add      byte ptr [eax], al             
  0x0106807B  0000                    add      byte ptr [eax], al             
  0x0106807D  0000                    add      byte ptr [eax], al             
  0x0106807F  0018                    add      byte ptr [eax], bl             
  0x01068081  0000                    add      byte ptr [eax], al             
  0x01068083  0001                    add      byte ptr [ecx], al             
  0x01068085  0000                    add      byte ptr [eax], al             
  0x01068087  0001                    add      byte ptr [ecx], al             
  0x01068089  0000                    add      byte ptr [eax], al             
  0x0106808B  0000                    add      byte ptr [eax], al             
  0x0106808D  0000                    add      byte ptr [eax], al             
  0x0106808F  0000                    add      byte ptr [eax], al             
  0x01068091  0000                    add      byte ptr [eax], al             
  0x01068093  0007                    add      byte ptr [edi], al             
  0x01068095  0000                    add      byte ptr [eax], al             
  0x01068097  0001                    add      byte ptr [ecx], al             
  0x01068099  0000                    add      byte ptr [eax], al             
  0x0106809B  001f                    add      byte ptr [edi], bl             
  0x0106809D  0000                    add      byte ptr [eax], al             
  0x0106809F  0009                    add      byte ptr [ecx], cl             
  0x010680A1  0000                    add      byte ptr [eax], al             
  0x010680A3  0000                    add      byte ptr [eax], al             
  0x010680A5  0000                    add      byte ptr [eax], al             
  0x010680A7  0001                    add      byte ptr [ecx], al             
  0x010680A9  0000                    add      byte ptr [eax], al             
  0x010680AB  0001                    add      byte ptr [ecx], al             
  0x010680AD  0000                    add      byte ptr [eax], al             
  0x010680AF  0000                    add      byte ptr [eax], al             
  0x010680B1  0000                    add      byte ptr [eax], al             
  0x010680B3  0000                    add      byte ptr [eax], al             
  0x010680B5  0000                    add      byte ptr [eax], al             
  0x010680B7  0001                    add      byte ptr [ecx], al             
  0x010680B9  0000                    add      byte ptr [eax], al             
  0x010680BB  00ef                    add      bh, ch                         
  0x010680BD  0000                    add      byte ptr [eax], al             
  0x010680BF  0000                    add      byte ptr [eax], al             
  0x010680C1  0000                    add      byte ptr [eax], al             
  0x010680C3  008cac65000200          add      byte ptr [esp + ebp*4 + 0x20065], cl 
  0x010680CA  0000                    add      byte ptr [eax], al             
