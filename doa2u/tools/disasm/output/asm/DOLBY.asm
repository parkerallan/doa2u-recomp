; ============================================================
; Section: DOLBY
; VA: 0x010673A0 - 0x0106E520
; Size: 29056 bytes (28.4 KB)
; Functions: 0
; Instructions: 12339
; ============================================================

  0x010673A0  080c0500000000          or       byte ptr [eax], cl             
  0x010673A7  0001                    add      byte ptr [ecx], al             
  0x010673A9  0000                    add      byte ptr [eax], al             
  0x010673AB  0001                    add      byte ptr [ecx], al             
  0x010673AD  0000                    add      byte ptr [eax], al             
  0x010673AF  0000                    add      byte ptr [eax], al             
  0x010673B1  0000                    add      byte ptr [eax], al             
  0x010673B3  0000                    add      byte ptr [eax], al             
  0x010673B5  0000                    add      byte ptr [eax], al             
  0x010673B7  00cc                    add      ah, cl                         
  0x010673B9  cc                      int3                                    
  0x010673BA  cc                      int3                                    
  0x010673BB  0000                    add      byte ptr [eax], al             
  0x010673BD  0000                    add      byte ptr [eax], al             
  0x010673BF  0000                    add      byte ptr [eax], al             
  0x010673C1  002400                  add      byte ptr [eax + eax], ah       
  0x010673C4  847007                  test     byte ptr [eax + 7], dh         
  0x010673C7  000400                  add      byte ptr [eax + eax], al       
  0x010673CA  0000                    add      byte ptr [eax], al             
  0x010673CC  847007                  test     byte ptr [eax + 7], dh         
  0x010673CF  000500000032            add      byte ptr [0x32000000], al      
  0x010673D5  f4                      hlt                                     
  0x010673D6  07                      pop      es                             
  0x010673D7  00ff                    add      bh, bh                         
  0x010673DA  ff00                    inc      dword ptr [eax]                
  0x010673DC  30f4                    xor      ah, dh                         
  0x010673DE  07                      pop      es                             
  0x010673DF  0001                    add      byte ptr [ecx], al             
  0x010673E1  0000                    add      byte ptr [eax], al             
  0x010673E3  0031                    add      byte ptr [ecx], dh             
  0x010673E5  f4                      hlt                                     
  0x010673E6  07                      pop      es                             
  0x010673E7  0001                    add      byte ptr [ecx], al             
  0x010673E9  0000                    add      byte ptr [eax], al             
  0x010673EB  00bb0005002a            add      byte ptr [ebx + 0x2a000500], bh 
  0x010673F1  f4                      hlt                                     
  0x010673F2  0500e00b00              add      eax, 0xbe000                   
  0x010673F7  00b820050074            add      byte ptr [eax + 0x74000520], bh 
  0x010673FD  fa                      cli                                     
  0x010673FE  0a00                    or       al, byte ptr [eax]             
  0x01067400  1300                    adc      eax, dword ptr [eax]           
  0x01067402  2000                    and      byte ptr [eax], al             
  0x01067404  887007                  mov      byte ptr [eax + 7], dh         
  0x01067407  0001                    add      byte ptr [ecx], al             
  0x01067409  0000                    add      byte ptr [eax], al             
  0x0106740B  0008                    add      byte ptr [eax], cl             
  0x0106740D  0000                    add      byte ptr [eax], al             
  0x0106740F  008870070002            add      byte ptr [eax + 0x2000770], cl 
  0x01067415  0000                    add      byte ptr [eax], al             
  0x01067417  008870070003            add      byte ptr [eax + 0x3000770], cl 
  0x0106741D  0000                    add      byte ptr [eax], al             
  0x0106741F  0000                    add      byte ptr [eax], al             
  0x01067421  f4                      hlt                                     
  0x01067422  56                      push     esi                            
  0x01067423  0000                    add      byte ptr [eax], al             
  0x01067425  0000                    add      byte ptr [eax], al             
  0x01067427  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x0106742D  0100                    add      dword ptr [eax], eax           
  0x0106742F  0003                    add      byte ptr [ebx], al             
  0x01067431  0020                    add      byte ptr [eax], ah             
  0x01067433  004210                  add      byte ptr [edx + 0x10], al      
  0x01067436  0d00a20000              or       eax, 0xa200                    
  0x0106743B  0085f4080002            add      byte ptr [ebp + 0x20008f4], al 
  0x01067441  0000                    add      byte ptr [eax], al             
  0x01067443  008ef0070007            add      byte ptr [esi + 0x70007f0], cl 
  0x01067449  0000                    add      byte ptr [eax], al             
  0x0106744B  00804101008e            add      byte ptr [eax - 0x71fffebf], al 
  0x01067451  7007                    jo       0x106745a                      
  0x01067453  0007                    add      byte ptr [edi], al             
  0x01067455  0000                    add      byte ptr [eax], al             
  0x01067457  0084f408000100          add      byte ptr [esp + esi*8 + 0x10008], al 
  0x0106745E  0000                    add      byte ptr [eax], al             
  0x01067460  1300                    adc      eax, dword ptr [eax]           
  0x01067462  2000                    and      byte ptr [eax], al             
  0x01067464  80410100                add      byte ptr [ecx + 1], 0          
  0x01067468  81850a003100000000f0    add      dword ptr [ebp + 0x31000a], 0xf0000000 
  0x01067472  44                      inc      esp                            
  0x01067473  00b3ffff0084            add      byte ptr [ebx - 0x7bff0001], dh 
  0x01067479  7007                    jo       0x1067482                      
  0x0106747B  000500000085            add      byte ptr [0x85000000], al      
  0x01067481  f4                      hlt                                     
                                        ; XREF: 0x01067479 (cond_jump)
  0x01067482  0800                    or       byte ptr [eax], al             
  0x01067484  0200                    add      al, byte ptr [eax]             
  0x01067486  0000                    add      byte ptr [eax], al             
  0x0106748A  07                      pop      es                             
  0x0106748B  0001                    add      byte ptr [ecx], al             
  0x0106748D  0000                    add      byte ptr [eax], al             
  0x0106748F  0003                    add      byte ptr [ebx], al             
  0x01067491  f4                      hlt                                     
  0x01067492  60                      pushal                                  
  0x01067493  00c0                    add      al, al                         
  0x01067495  0b00                    or       eax, dword ptr [eax]           
  0x01067497  0009                    add      byte ptr [ecx], cl             
  0x01067499  2405                    and      al, 5                          
  0x0106749B  0000                    add      byte ptr [eax], al             
  0x0106749D  f4                      hlt                                     
  0x0106749E  56                      push     esi                            
  0x0106749F  000a                    add      byte ptr [edx], cl             
  0x010674A1  0000                    add      byte ptr [eax], al             
  0x010674A3  0000                    add      byte ptr [eax], al             
  0x010674A5  2038                    and      byte ptr [eax], bh             
  0x010674A7  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x010674AD  0100                    add      dword ptr [eax], eax           
  0x010674AF  0003                    add      byte ptr [ebx], al             
  0x010674B1  0020                    add      byte ptr [eax], ah             
  0x010674B3  004210                  add      byte ptr [edx + 0x10], al      
  0x010674B6  0d00820000              or       eax, 0x8200                    
  0x010674BB  0000                    add      byte ptr [eax], al             
  0x010674BE  56                      push     esi                            
  0x010674BF  00c1                    add      cl, al                         
  0x010674C1  0b00                    or       eax, dword ptr [eax]           
  0x010674C3  0003                    add      byte ptr [ebx], al             
  0x010674C5  f4                      hlt                                     
  0x010674C6  60                      pushal                                  
  0x010674C7  0000                    add      byte ptr [eax], al             
  0x010674C9  0300                    add      eax, dword ptr [eax]           
  0x010674CB  0012                    add      byte ptr [edx], dl             
  0x010674CD  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010674CE  050000f456              add      eax, 0x56f40000                
  0x010674D3  0001                    add      byte ptr [ecx], al             
  0x010674D5  0000                    add      byte ptr [eax], al             
  0x010674D7  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x010674DD  0100                    add      dword ptr [eax], eax           
  0x010674DF  0003                    add      byte ptr [ebx], al             
  0x010674E1  0020                    add      byte ptr [eax], ah             
  0x010674E3  004210                  add      byte ptr [edx + 0x10], al      
  0x010674E6  0d00760000              or       eax, 0x7600                    
  0x010674EB  008ff0070002            add      byte ptr [edi + 0x20007f0], cl 
  0x010674F1  0000                    add      byte ptr [eax], al             
  0x010674F3  0000                    add      byte ptr [eax], al             
  0x010674F5  f4                      hlt                                     
  0x010674F6  60                      pushal                                  
  0x010674F7  00c0                    add      al, al                         
  0x010674F9  0b00                    or       eax, dword ptr [eax]           
  0x010674FB  0080f00b0004            add      byte ptr [eax + 0x4000bf0], al 
  0x01067501  0300                    add      eax, dword ptr [eax]           
  0x01067503  0000                    add      byte ptr [eax], al             
  0x01067505  002400                  add      byte ptr [eax + eax], ah       
  0x01067508  847007                  test     byte ptr [eax + 7], dh         
  0x0106750B  0002                    add      byte ptr [edx], al             
  0x0106750D  0000                    add      byte ptr [eax], al             
  0x0106750F  001c0c                  add      byte ptr [esp + ecx], bl       
  0x01067512  050000f057              add      eax, 0x57f00000                
  0x01067517  00c3                    add      bl, al                         
  0x01067519  0b00                    or       eax, dword ptr [eax]           
  0x0106751B  000b                    add      byte ptr [ebx], cl             
  0x0106751D  f4                      hlt                                     
  0x0106751E  60                      pushal                                  
  0x0106751F  0000                    add      byte ptr [eax], al             
  0x01067521  0300                    add      eax, dword ptr [eax]           
  0x01067523  0017                    add      byte ptr [edi], dl             
  0x01067525  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01067526  050013f444              add      eax, 0x44f41300                
  0x0106752B  0005000000cd            add      byte ptr [0xcd000000], al      
  0x01067531  40                      inc      eax                            
  0x01067532  0100                    add      dword ptr [eax], eax           
  0x01067534  0100                    add      dword ptr [eax], eax           
  0x01067536  0000                    add      byte ptr [eax], al             
  0x01067538  41                      inc      ecx                            
  0x01067539  2a20                    sub      ah, byte ptr [eax]             
  0x0106753B  0000                    add      byte ptr [eax], al             
  0x0106753D  f4                      hlt                                     
  0x0106753E  44                      inc      esp                            
  0x0106753F  0006                    add      byte ptr [esi], al             
  0x01067541  0000                    add      byte ptr [eax], al             
  0x01067543  00cd                    add      ch, cl                         
  0x01067545  40                      inc      eax                            
  0x01067546  0100                    add      dword ptr [eax], eax           
  0x01067548  0200                    add      al, byte ptr [eax]             
  0x0106754A  0000                    add      byte ptr [eax], al             
  0x0106754C  41                      inc      ecx                            
  0x0106754D  2a20                    sub      ah, byte ptr [eax]             
  0x0106754F  0003                    add      byte ptr [ebx], al             
  0x01067551  0020                    add      byte ptr [eax], ah             
  0x01067553  000b                    add      byte ptr [ebx], cl             
  0x01067555  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01067556  050080f00b              add      eax, 0xbf08000                 
  0x0106755B  008001000003            add      byte ptr [eax + 0x3000001], al 
  0x01067561  0020                    add      byte ptr [eax], ah             
  0x01067563  004210                  add      byte ptr [edx + 0x10], al      
  0x01067566  0d00560000              or       eax, 0x5600                    
  0x0106756B  0000                    add      byte ptr [eax], al             
  0x0106756D  f4                      hlt                                     
  0x0106756E  60                      pushal                                  
  0x0106756F  00c0                    add      al, al                         
  0x01067571  0b00                    or       eax, dword ptr [eax]           
  0x01067573  0080f00b0004            add      byte ptr [eax + 0x4000bf0], al 
  0x01067579  0300                    add      eax, dword ptr [eax]           
  0x0106757B  0001                    add      byte ptr [ecx], al             
  0x0106757D  0c05                    or       al, 5                          
  0x0106757F  0000                    add      byte ptr [eax], al             
  0x01067582  56                      push     esi                            
  0x01067583  00c2                    add      dl, al                         
  0x01067585  0b00                    or       eax, dword ptr [eax]           
  0x01067587  0003                    add      byte ptr [ebx], al             
  0x01067589  f4                      hlt                                     
  0x0106758A  60                      pushal                                  
  0x0106758B  0000                    add      byte ptr [eax], al             
  0x0106758D  0300                    add      eax, dword ptr [eax]           
  0x0106758F  004fa4                  add      byte ptr [edi - 0x5c], cl      
  0x01067592  050000f456              add      eax, 0x56f40000                
  0x01067597  0002                    add      byte ptr [edx], al             
  0x01067599  0000                    add      byte ptr [eax], al             
  0x0106759B  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x010675A1  0100                    add      dword ptr [eax], eax           
  0x010675A3  0003                    add      byte ptr [ebx], al             
  0x010675A5  0020                    add      byte ptr [eax], ah             
  0x010675A7  004210                  add      byte ptr [edx + 0x10], al      
  0x010675AA  0d00450000              or       eax, 0x4500                    
  0x010675AF  0000                    add      byte ptr [eax], al             
  0x010675B1  f4                      hlt                                     
  0x010675B2  60                      pushal                                  
  0x010675B3  00c0                    add      al, al                         
  0x010675B5  0b00                    or       eax, dword ptr [eax]           
  0x010675B7  008ff0070003            add      byte ptr [edi + 0x30007f0], cl 
  0x010675BD  0000                    add      byte ptr [eax], al             
  0x010675BF  0084f007000100          add      byte ptr [eax + esi*8 + 0x10007], al 
  0x010675C6  0000                    add      byte ptr [eax], al             
  0x010675C8  80f00b                  xor      al, 0xb                        
  0x010675CB  000403                  add      byte ptr [ebx + eax], al       
  0x010675CE  0000                    add      byte ptr [eax], al             
  0x010675D0  00f4                    add      ah, dh                         
  0x010675D2  60                      pushal                                  
  0x010675D3  0000                    add      byte ptr [eax], al             
  0x010675D5  0300                    add      eax, dword ptr [eax]           
  0x010675D7  0000                    add      byte ptr [eax], al             
  0x010675D9  f4                      hlt                                     
  0x010675DA  56                      push     esi                            
  0x010675DB  0003                    add      byte ptr [ebx], al             
  0x010675DD  0000                    add      byte ptr [eax], al             
  0x010675DF  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x010675E5  0100                    add      dword ptr [eax], eax           
  0x010675E7  0003                    add      byte ptr [ebx], al             
  0x010675E9  0020                    add      byte ptr [eax], ah             
  0x010675EB  004210                  add      byte ptr [edx + 0x10], al      
  0x010675EE  0d00340000              or       eax, 0x3400                    
  0x010675F3  008ff0070003            add      byte ptr [edi + 0x30007f0], cl 
  0x010675F9  0000                    add      byte ptr [eax], al             
  0x010675FB  0080f00b0004            add      byte ptr [eax + 0x4000bf0], al 
  0x01067601  0300                    add      eax, dword ptr [eax]           
  0x01067603  0000                    add      byte ptr [eax], al             
  0x01067605  f4                      hlt                                     
  0x01067606  60                      pushal                                  
  0x01067607  0000                    add      byte ptr [eax], al             
  0x01067609  0300                    add      eax, dword ptr [eax]           
  0x0106760B  0000                    add      byte ptr [eax], al             
  0x0106760D  f4                      hlt                                     
  0x0106760E  56                      push     esi                            
  0x0106760F  000400                  add      byte ptr [eax + eax], al       
  0x01067612  0000                    add      byte ptr [eax], al             
  0x01067614  80f00b                  xor      al, 0xb                        
  0x01067617  008001000003            add      byte ptr [eax + 0x3000001], al 
  0x0106761D  0020                    add      byte ptr [eax], ah             
  0x0106761F  004210                  add      byte ptr [edx + 0x10], al      
  0x01067622  0d00270000              or       eax, 0x2700                    
  0x01067627  008ff0070003            add      byte ptr [edi + 0x30007f0], cl 
  0x0106762D  0000                    add      byte ptr [eax], al             
  0x0106762F  0084f007000100          add      byte ptr [eax + esi*8 + 0x10007], al 
  0x01067636  0000                    add      byte ptr [eax], al             
  0x01067638  80f00b                  xor      al, 0xb                        
  0x0106763B  000403                  add      byte ptr [ebx + eax], al       
  0x0106763E  0000                    add      byte ptr [eax], al             
  0x01067640  0000                    add      byte ptr [eax], al             
  0x01067642  2400                    and      al, 0                          
  0x01067644  847007                  test     byte ptr [eax + 7], dh         
  0x01067647  0003                    add      byte ptr [ebx], al             
  0x01067649  0000                    add      byte ptr [eax], al             
  0x0106764B  008ef0070001            add      byte ptr [esi + 0x10007f0], cl 
  0x01067651  0000                    add      byte ptr [eax], al             
  0x01067653  008041010085            add      byte ptr [eax - 0x7afffebf], al 
  0x01067659  46                      inc      esi                            
  0x0106765A  0100                    add      dword ptr [eax], eax           
  0x0106765C  1321                    adc      esp, dword ptr [ecx]           
  0x0106765E  2000                    and      byte ptr [eax], al             
  0x01067661  7007                    jo       0x106766a                      
  0x01067663  0001                    add      byte ptr [ecx], al             
  0x01067665  0000                    add      byte ptr [eax], al             
  0x01067667  0000                    add      byte ptr [eax], al             
  0x01067669  f4                      hlt                                     
                                        ; XREF: 0x01067661 (cond_jump)
  0x0106766A  56                      push     esi                            
  0x0106766B  000b                    add      byte ptr [ebx], cl             
  0x0106766D  0000                    add      byte ptr [eax], al             
  0x0106766F  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x01067675  0100                    add      dword ptr [eax], eax           
  0x01067677  0000                    add      byte ptr [eax], al             
  0x0106767A  56                      push     esi                            
  0x0106767B  00b3ffff0084            add      byte ptr [ebx - 0x7bff0001], dh 
  0x01067682  07                      pop      es                             
  0x01067683  000500000044            add      byte ptr [0x44000000], al      
  0x01067689  0020                    add      byte ptr [eax], ah             
  0x0106768B  008c7007000400          add      byte ptr [eax + esi*2 + 0x40007], cl 
  0x01067692  0000                    add      byte ptr [eax], al             
  0x01067694  00f4                    add      ah, dh                         
  0x01067696  44                      inc      esp                            
  0x01067697  00a0cd0a00f8            add      byte ptr [eax - 0x7fff533], ah 
  0x0106769D  1f                      pop      ds                             
  0x0106769E  0c00                    or       al, 0                          
  0x010676A0  c9                      leave                                   
  0x010676A1  96                      xchg     esi, eax                       
  0x010676A2  050000f444              add      eax, 0x44f40000                
  0x010676A7  00bbbbbb0084            add      byte ptr [ebx - 0x7bff4445], bh 
  0x010676AD  7007                    jo       0x10676b6                      
  0x010676AF  0006                    add      byte ptr [esi], al             
  0x010676B1  0000                    add      byte ptr [eax], al             
  0x010676B3  0000                    add      byte ptr [eax], al             
  0x010676B5  0c05                    or       al, 5                          
  0x010676B7  00c3                    add      bl, al                         
  0x010676B9  0e                      push     cs                             
  0x010676BA  0500c20e05              add      eax, 0x50ec200                 
  0x010676BF  0000                    add      byte ptr [eax], al             
  0x010676C1  f4                      hlt                                     
  0x010676C2  6200                    bound    eax, qword ptr [eax]           
  0x010676C4  0001                    add      byte ptr [ecx], al             
  0x010676C6  0000                    add      byte ptr [eax], al             
  0x010676C8  009a21000001            add      byte ptr [edx + 0x1000021], bl 
  0x010676CE  3d00854001              cmp      eax, 0x1408500                 
  0x010676D3  000f                    add      byte ptr [edi], cl             
  0x010676D5  a5                      movsd    dword ptr es:[edi], dword ptr [esi] 
  0x010676D6  0500004a20              add      eax, 0x204a0000                
  0x010676DB  0000                    add      byte ptr [eax], al             
  0x010676DD  4a                      dec      edx                            
  0x010676DE  2000                    and      byte ptr [eax], al             
  0x010676E0  91                      xchg     ecx, eax                       
  0x010676E1  da07                    fiadd    dword ptr [edi]                
  0x010676E3  0085510100ce            add      byte ptr [ebp - 0x31fffeaf], al 
  0x010676E9  1405                    adc      al, 5                          
  0x010676EB  008546010054            add      byte ptr [ebp + 0x54000146], al 
  0x010676F1  f4                      hlt                                     
  0x010676F2  0500854901              add      eax, 0x1498500                 
  0x010676F7  008ca40500854a          add      byte ptr [esp + 0x4a850005], cl 
  0x010676FE  0100                    add      dword ptr [eax], eax           
  0x01067700  4b                      dec      ebx                            
  0x01067701  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01067702  0500854b01              add      eax, 0x14b8500                 
  0x01067707  0051a4                  add      byte ptr [ecx - 0x5c], dl      
  0x0106770A  0500854c01              add      eax, 0x14c8500                 
  0x0106770F  0095a4050085            add      byte ptr [ebp - 0x7afffa5c], dl 
  0x01067715  4d                      dec      ebp                            
  0x01067716  0100                    add      dword ptr [eax], eax           
  0x01067718  98                      cwde                                    
  0x01067719  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106771A  0500854801              add      eax, 0x1488500                 
  0x0106771F  005ba4                  add      byte ptr [ebx - 0x5c], bl      
  0x01067722  0500854e01              add      eax, 0x14e8500                 
  0x01067727  0087a4050085            add      byte ptr [edi - 0x7afffa5c], al 
  0x0106772D  4f                      dec      edi                            
  0x0106772E  0100                    add      dword ptr [eax], eax           
  0x01067730  82a405004c0c0500        and      byte ptr [ebp + eax + 0x50c4c00], 0 
  0x01067738  0000                    add      byte ptr [eax], al             
  0x0106773A  0000                    add      byte ptr [eax], al             
  0x0106773C  0000                    add      byte ptr [eax], al             
  0x0106773E  0000                    add      byte ptr [eax], al             
  0x01067740  0000                    add      byte ptr [eax], al             
  0x01067742  0000                    add      byte ptr [eax], al             
  0x01067744  0100                    add      dword ptr [eax], eax           
  0x01067746  0000                    add      byte ptr [eax], al             
  0x01067748  0000                    add      byte ptr [eax], al             
  0x0106774A  0000                    add      byte ptr [eax], al             
  0x0106774C  0000                    add      byte ptr [eax], al             
  0x0106774E  0000                    add      byte ptr [eax], al             
  0x01067750  0000                    add      byte ptr [eax], al             
  0x01067752  0000                    add      byte ptr [eax], al             
  0x01067754  0000                    add      byte ptr [eax], al             
  0x01067756  0000                    add      byte ptr [eax], al             
  0x01067758  0000                    add      byte ptr [eax], al             
  0x0106775A  0000                    add      byte ptr [eax], al             
  0x0106775C  0000                    add      byte ptr [eax], al             
  0x0106775E  0000                    add      byte ptr [eax], al             
  0x01067760  0000                    add      byte ptr [eax], al             
  0x01067762  0000                    add      byte ptr [eax], al             
  0x01067764  0000                    add      byte ptr [eax], al             
  0x01067766  0000                    add      byte ptr [eax], al             
  0x01067768  0000                    add      byte ptr [eax], al             
  0x0106776A  0000                    add      byte ptr [eax], al             
  0x0106776C  0000                    add      byte ptr [eax], al             
  0x0106776E  0000                    add      byte ptr [eax], al             
  0x01067770  0000                    add      byte ptr [eax], al             
  0x01067772  0000                    add      byte ptr [eax], al             
  0x01067774  0000                    add      byte ptr [eax], al             
  0x01067776  0000                    add      byte ptr [eax], al             
  0x01067778  0000                    add      byte ptr [eax], al             
  0x0106777A  0000                    add      byte ptr [eax], al             
  0x0106777C  0000                    add      byte ptr [eax], al             
  0x0106777E  0000                    add      byte ptr [eax], al             
  0x01067780  0000                    add      byte ptr [eax], al             
  0x01067782  0000                    add      byte ptr [eax], al             
  0x01067784  0000                    add      byte ptr [eax], al             
  0x01067786  0000                    add      byte ptr [eax], al             
  0x01067788  0000                    add      byte ptr [eax], al             
  0x0106778A  0000                    add      byte ptr [eax], al             
  0x0106778C  0000                    add      byte ptr [eax], al             
  0x0106778E  0000                    add      byte ptr [eax], al             
  0x01067790  0000                    add      byte ptr [eax], al             
  0x01067792  0000                    add      byte ptr [eax], al             
  0x01067794  0000                    add      byte ptr [eax], al             
  0x01067796  0000                    add      byte ptr [eax], al             
  0x01067798  0000                    add      byte ptr [eax], al             
  0x0106779A  0000                    add      byte ptr [eax], al             
  0x0106779C  0000                    add      byte ptr [eax], al             
  0x0106779E  0000                    add      byte ptr [eax], al             
  0x010677A0  0000                    add      byte ptr [eax], al             
  0x010677A2  0000                    add      byte ptr [eax], al             
  0x010677A4  0000                    add      byte ptr [eax], al             
  0x010677A6  0000                    add      byte ptr [eax], al             
  0x010677A8  0000                    add      byte ptr [eax], al             
  0x010677AA  0000                    add      byte ptr [eax], al             
  0x010677AC  8eda                    mov      ds, edx                        
  0x010677AE  07                      pop      es                             
  0x010677AF  0000                    add      byte ptr [eax], al             
  0x010677B1  0423                    add      al, 0x23                       
  0x010677B3  004598                  add      byte ptr [ebp - 0x68], al      
  0x010677B6  2100                    and      dword ptr [eax], eax           
  0x010677B9  080500900c05            or       byte ptr [0x50c9000], al       
  0x010677BF  0098da07001f            add      byte ptr [eax + 0x1f0007da], bl 
  0x010677C5  0905008d0c05            or       dword ptr [0x50c8d00], eax     
  0x010677CB  0084f007001601          add      byte ptr [eax + esi*8 + 0x1160007], al 
  0x010677D2  0000                    add      byte ptr [eax], al             
  0x010677D4  48                      dec      eax                            
  0x010677D5  c40b                    les      ecx, ptr [ebx]                 
  0x010677D7  00847007001601          add      byte ptr [eax + esi*2 + 0x1160007], al 
  0x010677DE  0000                    add      byte ptr [eax], al             
  0x010677E0  870c0500002f23          xchg     dword ptr [eax + 0x232f0000], ecx 
  0x010677E7  00931d0c0000            add      byte ptr [ebx + 0xc1d], dl     
  0x010677ED  2422                    and      al, 0x22                       
  0x010677EF  004800                  add      byte ptr [eax], cl             
  0x010677F2  2000                    and      byte ptr [eax], al             
  0x010677F6  07                      pop      es                             
  0x010677F7  0016                    add      byte ptr [esi], dl             
  0x010677F9  0100                    add      dword ptr [eax], eax           
  0x010677FB  0010                    add      byte ptr [eax], dl             
  0x010677FD  0020                    add      byte ptr [eax], ah             
  0x010677FF  0000                    add      byte ptr [eax], al             
  0x01067801  91                      xchg     ecx, eax                       
  0x01067802  2100                    and      dword ptr [eax], eax           
  0x01067804  93                      xchg     ebx, eax                       
  0x01067805  0805005d0c05            or       byte ptr [0x50c5d00], al       
  0x0106780B  0000                    add      byte ptr [eax], al             
  0x0106780D  2e2300                  and      eax, dword ptr cs:[eax]        
  0x01067810  854001                  test     dword ptr [eax + 1], eax       
  0x01067813  005a24                  add      byte ptr [edx + 0x24], bl      
  0x01067816  050000013a              add      eax, 0x3a010000                
  0x0106781B  0000                    add      byte ptr [eax], al             
  0x0106781D  003c00                  add      byte ptr [eax + eax], bh       
  0x01067820  c00805                  ror      byte ptr [eax], 5              
  0x01067823  00560c                  add      byte ptr [esi + 0xc], dl       
  0x01067826  050000003a              add      eax, 0x3a000000                
  0x0106782B  0000                    add      byte ptr [eax], al             
  0x0106782D  003c00                  add      byte ptr [eax + eax], bh       
  0x01067830  9c                      pushfd                                  
  0x01067831  080500520c05            or       byte ptr [0x50c5200], al       
  0x01067837  0000                    add      byte ptr [eax], al             
  0x01067839  f4                      hlt                                     
  0x0106783A  61                      popal                                   
  0x0106783B  00ab01000003            add      byte ptr [ebx + 0x3000001], ch 
  0x01067841  0c05                    or       al, 5                          
  0x01067843  0000                    add      byte ptr [eax], al             
  0x01067845  f4                      hlt                                     
  0x01067846  61                      popal                                   
  0x01067847  00af01000010            add      byte ptr [edi + 0x10000001], ch 
  0x0106784D  d806                    fadd     dword ptr [esi]                
  0x0106784F  000400                  add      byte ptr [eax + eax], al       
  0x01067852  0000                    add      byte ptr [eax], al             
  0x01067854  00d8                    add      al, bl                         
  0x01067856  44                      inc      esp                            
  0x01067857  00845907000000          add      byte ptr [ecx + ebx*2 + 7], al 
  0x0106785E  0000                    add      byte ptr [eax], al             
  0x01067860  47                      inc      edi                            
  0x01067861  0c05                    or       al, 5                          
  0x01067863  0000                    add      byte ptr [eax], al             
  0x01067865  003a                    add      byte ptr [edx], bh             
  0x01067867  0000                    add      byte ptr [eax], al             
  0x01067869  013c00                  add      dword ptr [eax + eax], edi     
  0x0106786C  0000                    add      byte ptr [eax], al             
  0x0106786E  3d008c0805              cmp      eax, 0x5088c00                 
  0x01067873  00420c                  add      byte ptr [edx + 0xc], al       
  0x01067876  050000003a              add      eax, 0x3a000000                
  0x0106787B  0000                    add      byte ptr [eax], al             
  0x0106787D  003c00                  add      byte ptr [eax + eax], bh       
  0x01067880  8808                    mov      byte ptr [eax], cl             
  0x01067882  05001e0c05              add      eax, 0x50c1e00                 
  0x01067887  002402                  add      byte ptr [edx + eax], ah       
  0x0106788A  0000                    add      byte ptr [eax], al             
  0x0106788C  2e0200                  add      al, byte ptr cs:[eax]          
  0x0106788F  004a02                  add      byte ptr [edx + 2], cl         
  0x01067892  0000                    add      byte ptr [eax], al             
  0x01067894  55                      push     ebp                            
  0x01067895  0200                    add      al, byte ptr [eax]             
  0x01067897  006002                  add      byte ptr [eax + 2], ah         
  0x0106789A  0000                    add      byte ptr [eax], al             
  0x0106789C  6b0200                  imul     eax, dword ptr [edx], 0        
  0x0106789F  008d40010008            add      byte ptr [ebp + 0x8000140], cl 
  0x010678A5  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010678A6  050000bc21              add      eax, 0x21bc0000                
  0x010678AB  0000                    add      byte ptr [eax], al             
  0x010678AD  f4                      hlt                                     
  0x010678AE  6400f1                  add      cl, dh                         
  0x010678B1  0100                    add      dword ptr [eax], eax           
  0x010678B3  0000                    add      byte ptr [eax], al             
  0x010678B5  49                      dec      ecx                            
  0x010678B6  2000                    and      byte ptr [eax], al             
  0x010678B8  96                      xchg     esi, eax                       
  0x010678B9  ec                      in       al, dx                         
  0x010678BA  07                      pop      es                             
  0x010678BB  0080e60b000f            add      byte ptr [eax + 0xf000be6], al 
  0x010678C1  0c05                    or       al, 5                          
  0x010678C3  0000                    add      byte ptr [eax], al             
  0x010678C5  0f2300                  mov      dr0, eax                       
  0x010678CA  07                      pop      es                             
  0x010678CB  009f01000084            add      byte ptr [edi - 0x7bffffff], bl 
  0x010678D2  07                      pop      es                             
  0x010678D3  009e01000014            add      byte ptr [esi + 0x14000001], bl 
  0x010678D9  0020                    add      byte ptr [eax], ah             
  0x010678DB  000a                    add      byte ptr [edx], cl             
  0x010678DD  94                      xchg     esp, eax                       
  0x010678DE  0500485220              add      eax, 0x20524800                
  0x010678E3  00845a0700985a          add      byte ptr [edx + ebx*2 + 0x5a980007], al 
  0x010678EA  07                      pop      es                             
  0x010678EB  008c7007009f01          add      byte ptr [eax + esi*2 + 0x19f0007], cl 
  0x010678F2  0000                    add      byte ptr [eax], al             
  0x010678F4  8d7007                  lea      esi, [eax + 7]                 
  0x010678F7  009e01000013            add      byte ptr [esi + 0x13000001], bl 
  0x010678FD  0020                    add      byte ptr [eax], ah             
  0x010678FF  000c00                  add      byte ptr [eax + eax], cl       
  0x01067902  0000                    add      byte ptr [eax], al             
  0x01067904  00f4                    add      ah, dh                         
  0x01067906  56                      push     esi                            
  0x01067907  000400                  add      byte ptr [eax + eax], al       
  0x0106790A  0000                    add      byte ptr [eax], al             
  0x0106790C  0c00                    or       al, 0                          
  0x0106790E  0000                    add      byte ptr [eax], al             
  0x01067910  84f0                    test     al, dh                         
  0x01067912  07                      pop      es                             
  0x01067913  0022                    add      byte ptr [edx], ah             
  0x01067915  0100                    add      dword ptr [eax], eax           
  0x01067917  00847007009e01          add      byte ptr [eax + esi*2 + 0x19e0007], al 
  0x0106791E  0000                    add      byte ptr [eax], al             
  0x01067920  84f0                    test     al, dh                         
  0x01067922  07                      pop      es                             
  0x01067923  0023                    add      byte ptr [ebx], ah             
  0x01067925  0100                    add      dword ptr [eax], eax           
  0x01067927  00847007009f01          add      byte ptr [eax + esi*2 + 0x19f0007], al 
  0x0106792E  0000                    add      byte ptr [eax], al             
  0x01067930  13f4                    adc      esi, esp                       
  0x01067932  60                      pushal                                  
  0x01067933  0022                    add      byte ptr [edx], ah             
  0x01067935  0100                    add      dword ptr [eax], eax           
  0x01067937  00901e060002            add      byte ptr [eax + 0x200061e], dl 
  0x0106793D  0000                    add      byte ptr [eax], al             
  0x0106793F  008e58070080            add      byte ptr [esi - 0x7ffff8a8], cl 
  0x01067945  100d00ce0000            adc      byte ptr [0xce00], cl          
  0x0106794B  00cc                    add      ah, cl                         
  0x0106794D  0f05                    syscall                                 
  0x0106794F  0000                    add      byte ptr [eax], al             
  0x01067951  f4                      hlt                                     
  0x01067952  6400a201000000          add      byte ptr fs:[edx + 1], ah      
  0x01067959  0c22                    or       al, 0x22                       
  0x0106795B  008040010000            add      byte ptr [eax + 0x140], al     
  0x01067961  90                      nop                                     
  0x01067962  2100                    and      dword ptr [eax], eax           
  0x01067964  80f00b                  xor      al, 0xb                        
  0x01067967  007602                  add      byte ptr [esi + 2], dh         
  0x0106796A  0000                    add      byte ptr [eax], al             
  0x0106796C  80f00b                  xor      al, 0xb                        
  0x0106796F  00e1                    add      cl, ah                         
  0x01067971  0200                    add      al, byte ptr [eax]             
  0x01067973  000c00                  add      byte ptr [eax + eax], cl       
  0x01067976  0000                    add      byte ptr [eax], al             
  0x01067978  00f4                    add      ah, dh                         
  0x0106797A  6400a201000000          add      byte ptr fs:[edx + 1], ah      
  0x01067981  0c22                    or       al, 0x22                       
  0x01067983  008040010000            add      byte ptr [eax + 0x140], al     
  0x01067989  90                      nop                                     
  0x0106798A  2100                    and      dword ptr [eax], eax           
  0x0106798C  80f00b                  xor      al, 0xb                        
  0x0106798F  008802000080            add      byte ptr [eax - 0x7ffffffe], cl 
  0x01067995  f00b00                  lock or  eax, dword ptr [eax]           
  0x01067998  e102                    loope    0x106799c                      
  0x0106799A  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01067998 (cond_jump)
  0x0106799C  0c00                    or       al, 0                          
  0x0106799E  0000                    add      byte ptr [eax], al             
  0x010679A0  00f4                    add      ah, dh                         
  0x010679A2  6400a201000000          add      byte ptr fs:[edx + 1], ah      
  0x010679A9  0c22                    or       al, 0x22                       
  0x010679AB  008040010000            add      byte ptr [eax + 0x140], al     
  0x010679B1  90                      nop                                     
  0x010679B2  2100                    and      dword ptr [eax], eax           
  0x010679B4  004e23                  add      byte ptr [esi + 0x23], cl      
  0x010679B7  008540010042            add      byte ptr [ebp + 0x42000140], al 
  0x010679BD  100d00060000            adc      byte ptr [0x600], cl           
  0x010679C3  0080f00b009a            add      byte ptr [eax - 0x65fff410], al 
  0x010679C9  0200                    add      al, byte ptr [eax]             
  0x010679CB  00c0                    add      al, al                         
  0x010679CD  100d00040000            adc      byte ptr [0x400], cl           
  0x010679D3  0080f00b00b1            add      byte ptr [eax - 0x4efff410], al 
  0x010679D9  0200                    add      al, byte ptr [eax]             
  0x010679DB  0080f00b00e1            add      byte ptr [eax - 0x1efff410], al 
  0x010679E1  0200                    add      al, byte ptr [eax]             
  0x010679E3  000c00                  add      byte ptr [eax + eax], cl       
  0x010679E6  0000                    add      byte ptr [eax], al             
  0x010679E8  00f4                    add      ah, dh                         
  0x010679EA  6400a201000000          add      byte ptr fs:[edx + 1], ah      
  0x010679F1  0c22                    or       al, 0x22                       
  0x010679F3  00c0                    add      al, al                         
  0x010679F5  40                      inc      eax                            
  0x010679F6  0100                    add      dword ptr [eax], eax           
  0x010679F8  0018                    add      byte ptr [eax], bl             
  0x010679FA  0000                    add      byte ptr [eax], al             
  0x010679FC  0090210080f0            add      byte ptr [eax - 0xf7fffdf], dl 
  0x01067A02  0b00                    or       eax, dword ptr [eax]           
  0x01067A04  7602                    jbe      0x1067a08                      
  0x01067A06  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01067A04 (cond_jump)
  0x01067A08  80f00b                  xor      al, 0xb                        
  0x01067A0B  00e1                    add      cl, ah                         
  0x01067A0D  0200                    add      al, byte ptr [eax]             
  0x01067A0F  000c00                  add      byte ptr [eax + eax], cl       
  0x01067A12  0000                    add      byte ptr [eax], al             
  0x01067A14  00f4                    add      ah, dh                         
  0x01067A16  6400a201000000          add      byte ptr fs:[edx + 1], ah      
  0x01067A1D  0c22                    or       al, 0x22                       
  0x01067A1F  00c0                    add      al, al                         
  0x01067A21  40                      inc      eax                            
  0x01067A22  0100                    add      dword ptr [eax], eax           
  0x01067A24  0018                    add      byte ptr [eax], bl             
  0x01067A26  0000                    add      byte ptr [eax], al             
  0x01067A28  0090210080f0            add      byte ptr [eax - 0xf7fffdf], dl 
  0x01067A2E  0b00                    or       eax, dword ptr [eax]           
  0x01067A30  8802                    mov      byte ptr [edx], al             
  0x01067A32  0000                    add      byte ptr [eax], al             
  0x01067A34  80f00b                  xor      al, 0xb                        
  0x01067A37  00e1                    add      cl, ah                         
  0x01067A39  0200                    add      al, byte ptr [eax]             
  0x01067A3B  000c00                  add      byte ptr [eax + eax], cl       
  0x01067A3E  0000                    add      byte ptr [eax], al             
  0x01067A40  00f4                    add      ah, dh                         
  0x01067A42  6400a201000000          add      byte ptr fs:[edx + 1], ah      
  0x01067A49  0c22                    or       al, 0x22                       
  0x01067A4B  00c0                    add      al, al                         
  0x01067A4D  40                      inc      eax                            
  0x01067A4E  0100                    add      dword ptr [eax], eax           
  0x01067A50  0028                    add      byte ptr [eax], ch             
  0x01067A52  0000                    add      byte ptr [eax], al             
  0x01067A54  0090210080f0            add      byte ptr [eax - 0xf7fffdf], dl 
  0x01067A5A  0b00                    or       eax, dword ptr [eax]           
  0x01067A5C  7602                    jbe      0x1067a60                      
  0x01067A5E  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01067A5C (cond_jump)
  0x01067A60  80f00b                  xor      al, 0xb                        
  0x01067A63  00e1                    add      cl, ah                         
  0x01067A65  0200                    add      al, byte ptr [eax]             
  0x01067A67  000c00                  add      byte ptr [eax + eax], cl       
  0x01067A6A  0000                    add      byte ptr [eax], al             
  0x01067A6C  00f4                    add      ah, dh                         
  0x01067A6E  6400a201000000          add      byte ptr fs:[edx + 1], ah      
  0x01067A75  0c22                    or       al, 0x22                       
  0x01067A77  00c0                    add      al, al                         
  0x01067A79  40                      inc      eax                            
  0x01067A7A  0100                    add      dword ptr [eax], eax           
  0x01067A7C  0028                    add      byte ptr [eax], ch             
  0x01067A7E  0000                    add      byte ptr [eax], al             
  0x01067A80  0090210080f0            add      byte ptr [eax - 0xf7fffdf], dl 
  0x01067A86  0b00                    or       eax, dword ptr [eax]           
  0x01067A88  8802                    mov      byte ptr [edx], al             
  0x01067A8A  0000                    add      byte ptr [eax], al             
  0x01067A8C  80f00b                  xor      al, 0xb                        
  0x01067A8F  00e1                    add      cl, ah                         
  0x01067A91  0200                    add      al, byte ptr [eax]             
  0x01067A93  000c00                  add      byte ptr [eax + eax], cl       
  0x01067A96  0000                    add      byte ptr [eax], al             
  0x01067A98  80f00b                  xor      al, 0xb                        
  0x01067A9B  00d0                    add      al, dl                         
  0x01067A9D  0200                    add      al, byte ptr [eax]             
  0x01067A9F  0000                    add      byte ptr [eax], al             
  0x01067AA1  95                      xchg     ebp, eax                       
  0x01067AA2  2200                    and      al, byte ptr [eax]             
  0x01067AA4  008c2200c64001          add      byte ptr [edx + 0x140c600], cl 
  0x01067AAB  00ff                    add      bh, bh                         
  0x01067AAD  3f                      aas                                     
  0x01067AAE  0000                    add      byte ptr [eax], al             
  0x01067AB0  c24001                  ret      0x140                          
  0x01067AB3  0000                    add      byte ptr [eax], al             
  0x01067AB5  40                      inc      eax                            
  0x01067AB6  0000                    add      byte ptr [eax], al             
  0x01067AB8  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x01067ABB  0000                    add      byte ptr [eax], al             
  0x01067ABD  f4                      hlt                                     
  0x01067ABE  54                      push     esp                            
  0x01067ABF  00e0                    add      al, ah                         
  0x01067AC1  5b                      pop      ebx                            
  0x01067AC2  0000                    add      byte ptr [eax], al             
  0x01067AC4  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x01067AC7  00985d070090            add      byte ptr [eax - 0x6ffff8a3], bl 
  0x01067ACD  5d                      pop      ebp                            
  0x01067ACE  07                      pop      es                             
  0x01067ACF  0000                    add      byte ptr [eax], al             
  0x01067AD1  2e2200                  and      al, byte ptr cs:[eax]          
  0x01067AD4  841e                    test     byte ptr [esi], bl             
  0x01067AD6  0c00                    or       al, 0                          
  0x01067AD8  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x01067ADB  000c00                  add      byte ptr [eax + eax], cl       
  0x01067ADE  0000                    add      byte ptr [eax], al             
  0x01067AE0  80f00b                  xor      al, 0xb                        
  0x01067AE3  00d0                    add      al, dl                         
  0x01067AE5  0200                    add      al, byte ptr [eax]             
  0x01067AE7  0000                    add      byte ptr [eax], al             
  0x01067AE9  95                      xchg     ebp, eax                       
  0x01067AEA  2200                    and      al, byte ptr [eax]             
  0x01067AEC  008c2200c64001          add      byte ptr [edx + 0x140c600], cl 
  0x01067AF3  00ff                    add      bh, bh                         
  0x01067AF5  3f                      aas                                     
  0x01067AF6  0000                    add      byte ptr [eax], al             
  0x01067AF8  c24001                  ret      0x140                          
  0x01067AFB  0000                    add      byte ptr [eax], al             
  0x01067AFD  40                      inc      eax                            
  0x01067AFE  0000                    add      byte ptr [eax], al             
  0x01067B00  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x01067B03  0000                    add      byte ptr [eax], al             
  0x01067B05  f4                      hlt                                     
  0x01067B06  54                      push     esp                            
  0x01067B07  00e2                    add      dl, ah                         
  0x01067B09  5b                      pop      ebx                            
  0x01067B0A  0000                    add      byte ptr [eax], al             
  0x01067B0C  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x01067B0F  00985d070090            add      byte ptr [eax - 0x6ffff8a3], bl 
  0x01067B15  5d                      pop      ebp                            
  0x01067B16  07                      pop      es                             
  0x01067B17  0000                    add      byte ptr [eax], al             
  0x01067B19  2e2200                  and      al, byte ptr cs:[eax]          
  0x01067B1C  841e                    test     byte ptr [esi], bl             
  0x01067B1E  0c00                    or       al, 0                          
  0x01067B20  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x01067B23  000c00                  add      byte ptr [eax + eax], cl       
  0x01067B26  0000                    add      byte ptr [eax], al             
  0x01067B28  80f00b                  xor      al, 0xb                        
  0x01067B2B  00d0                    add      al, dl                         
  0x01067B2D  0200                    add      al, byte ptr [eax]             
  0x01067B2F  0000                    add      byte ptr [eax], al             
  0x01067B31  95                      xchg     ebp, eax                       
  0x01067B32  2200                    and      al, byte ptr [eax]             
  0x01067B34  008c2200c64001          add      byte ptr [edx + 0x140c600], cl 
  0x01067B3B  00ff                    add      bh, bh                         
  0x01067B3D  3f                      aas                                     
  0x01067B3E  0000                    add      byte ptr [eax], al             
  0x01067B40  c24001                  ret      0x140                          
  0x01067B43  0000                    add      byte ptr [eax], al             
  0x01067B45  40                      inc      eax                            
  0x01067B46  0000                    add      byte ptr [eax], al             
  0x01067B48  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x01067B4B  0000                    add      byte ptr [eax], al             
  0x01067B4D  f4                      hlt                                     
  0x01067B4E  54                      push     esp                            
  0x01067B4F  0002                    add      byte ptr [edx], al             
  0x01067B51  46                      inc      esi                            
  0x01067B52  0000                    add      byte ptr [eax], al             
  0x01067B54  002f                    add      byte ptr [edi], ch             
  0x01067B56  2200                    and      al, byte ptr [eax]             
  0x01067B58  8b1e                    mov      ebx, dword ptr [esi]           
  0x01067B5A  0c00                    or       al, 0                          
  0x01067B5C  00e5                    add      ch, ah                         
  0x01067B5E  2100                    and      dword ptr [eax], eax           
  0x01067B60  6200                    bound    eax, qword ptr [eax]           
  0x01067B62  2000                    and      byte ptr [eax], al             
  0x01067B64  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x01067B67  00985d070000            add      byte ptr [eax + 0x75d], bl     
  0x01067B6D  8e23                    mov      fs, word ptr [ebx]             
  0x01067B6F  009c1e0c000004          add      byte ptr [esi + ebx + 0x400000c], bl 
  0x01067B76  2200                    and      al, byte ptr [eax]             
  0x01067B78  40                      inc      eax                            
  0x01067B79  0020                    add      byte ptr [eax], ah             
  0x01067B7B  008c5d07000c00          add      byte ptr [ebp + ebx*2 + 0xc0007], cl 
  0x01067B82  0000                    add      byte ptr [eax], al             
  0x01067B84  80f00b                  xor      al, 0xb                        
  0x01067B87  00d0                    add      al, dl                         
  0x01067B89  0200                    add      al, byte ptr [eax]             
  0x01067B8B  0000                    add      byte ptr [eax], al             
  0x01067B8D  95                      xchg     ebp, eax                       
  0x01067B8E  2200                    and      al, byte ptr [eax]             
  0x01067B90  008c2200c64001          add      byte ptr [edx + 0x140c600], cl 
  0x01067B97  00ff                    add      bh, bh                         
  0x01067B99  3f                      aas                                     
  0x01067B9A  0000                    add      byte ptr [eax], al             
  0x01067B9C  c24001                  ret      0x140                          
  0x01067B9F  0000                    add      byte ptr [eax], al             
  0x01067BA1  40                      inc      eax                            
  0x01067BA2  0000                    add      byte ptr [eax], al             
  0x01067BA4  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x01067BA7  0000                    add      byte ptr [eax], al             
  0x01067BA9  f4                      hlt                                     
  0x01067BAA  54                      push     esp                            
  0x01067BAB  0003                    add      byte ptr [ebx], al             
  0x01067BAD  06                      push     es                             
  0x01067BAE  0000                    add      byte ptr [eax], al             
  0x01067BB0  002f                    add      byte ptr [edi], ch             
  0x01067BB2  2200                    and      al, byte ptr [eax]             
  0x01067BB4  8b1e                    mov      ebx, dword ptr [esi]           
  0x01067BB6  0c00                    or       al, 0                          
  0x01067BB8  00e5                    add      ch, ah                         
  0x01067BBA  2100                    and      dword ptr [eax], eax           
  0x01067BBC  6200                    bound    eax, qword ptr [eax]           
  0x01067BBE  2000                    and      byte ptr [eax], al             
  0x01067BC0  000f                    add      byte ptr [edi], cl             
  0x01067BC2  2300                    and      eax, dword ptr [eax]           
  0x01067BC4  9d                      popfd                                   
  0x01067BC5  1e                      push     ds                             
  0x01067BC6  0c00                    or       al, 0                          
  0x01067BC8  00e5                    add      ch, ah                         
  0x01067BCA  2100                    and      dword ptr [eax], eax           
  0x01067BCC  6200                    bound    eax, qword ptr [eax]           
  0x01067BCE  2000                    and      byte ptr [eax], al             
  0x01067BD0  8c5d07                  mov      word ptr [ebp + 7], ds         
  0x01067BD3  0000                    add      byte ptr [eax], al             
  0x01067BD5  0f2300                  mov      dr0, eax                       
  0x01067BD8  891e                    mov      dword ptr [esi], ebx           
  0x01067BDA  0c00                    or       al, 0                          
  0x01067BDC  004523                  add      byte ptr [ebp + 0x23], al      
  0x01067BDF  006800                  add      byte ptr [eax], ch             
  0x01067BE2  2000                    and      byte ptr [eax], al             
  0x01067BE4  8d5d07                  lea      ebx, [ebp + 7]                 
  0x01067BE7  0000                    add      byte ptr [eax], al             
  0x01067BE9  8e23                    mov      fs, word ptr [ebx]             
  0x01067BEB  009c1e0c000004          add      byte ptr [esi + ebx + 0x400000c], bl 
  0x01067BF2  2200                    and      al, byte ptr [eax]             
  0x01067BF4  40                      inc      eax                            
  0x01067BF5  0020                    add      byte ptr [eax], ah             
  0x01067BF7  008c5d07000c00          add      byte ptr [ebp + ebx*2 + 0xc0007], cl 
  0x01067BFE  0000                    add      byte ptr [eax], al             
  0x01067C00  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01067C01  96                      xchg     esi, eax                       
  0x01067C02  0a00                    or       al, byte ptr [eax]             
  0x01067C04  d002                    rol      byte ptr [edx], 1              
  0x01067C06  0000                    add      byte ptr [eax], al             
  0x01067C08  85f4                    test     esp, esi                       
  0x01067C0A  0800                    or       byte ptr [eax], al             
  0x01067C0C  800000                  add      byte ptr [eax], 0              
  0x01067C0F  000c00                  add      byte ptr [eax + eax], cl       
  0x01067C12  0000                    add      byte ptr [eax], al             
  0x01067C14  96                      xchg     esi, eax                       
  0x01067C15  f4                      hlt                                     
  0x01067C16  0800                    or       byte ptr [eax], al             
  0x01067C18  0100                    add      dword ptr [eax], eax           
  0x01067C1A  0000                    add      byte ptr [eax], al             
  0x01067C1C  84960a00d702            test     byte ptr [esi + 0x2d7000a], dl 
  0x01067C22  0000                    add      byte ptr [eax], al             
  0x01067C24  0c00                    or       al, 0                          
  0x01067C26  0000                    add      byte ptr [eax], al             
  0x01067C28  aa                      stosb    byte ptr es:[edi], al          
  0x01067C29  850a                    test     dword ptr [edx], ecx           
  0x01067C2B  00fe                    add      dh, bh                         
  0x01067C2D  0200                    add      al, byte ptr [eax]             
  0x01067C2F  0087850a00da            add      byte ptr [edi - 0x25fff57b], al 
  0x01067C35  0200                    add      al, byte ptr [eax]             
  0x01067C37  0085f4080080            add      byte ptr [ebp - 0x7ffff70c], al 
  0x01067C3D  0000                    add      byte ptr [eax], al             
  0x01067C3F  000c00                  add      byte ptr [eax + eax], cl       
  0x01067C42  0000                    add      byte ptr [eax], al             
  0x01067C44  008e2200c040            add      byte ptr [esi + 0x40c00022], cl 
  0x01067C4A  0100                    add      dword ptr [eax], eax           
  0x01067C4C  0028                    add      byte ptr [eax], ch             
  0x01067C4E  0000                    add      byte ptr [eax], al             
  0x01067C50  14ce                    adc      al, 0xce                       
  0x01067C52  0800                    or       byte ptr [eax], al             
  0x01067C54  80f00b                  xor      al, 0xb                        
  0x01067C57  00d5                    add      ch, dl                         
  0x01067C59  0200                    add      al, byte ptr [eax]             
  0x01067C5B  001b                    add      byte ptr [ebx], bl             
  0x01067C5D  0020                    add      byte ptr [eax], ah             
  0x01067C5F  0000                    add      byte ptr [eax], al             
  0x01067C61  af                      scasd    eax, dword ptr es:[edi]        
  0x01067C62  2300                    and      eax, dword ptr [eax]           
  0x01067C64  8d4001                  lea      eax, [eax + 1]                 
  0x01067C67  004a10                  add      byte ptr [edx + 0x10], cl      
  0x01067C6A  0d00040000              or       eax, 0x400                     
  0x01067C6F  0080f00b00da            add      byte ptr [eax - 0x25fff410], al 
  0x01067C75  0200                    add      al, byte ptr [eax]             
  0x01067C77  000c00                  add      byte ptr [eax + eax], cl       
  0x01067C7A  0000                    add      byte ptr [eax], al             
  0x01067C7C  85f4                    test     esp, esi                       
  0x01067C7E  0800                    or       byte ptr [eax], al             
  0x01067C80  ff0f                    dec      dword ptr [edi]                
  0x01067C82  0000                    add      byte ptr [eax], al             
  0x01067C84  84f4                    test     ah, dh                         
  0x01067C86  0800                    or       byte ptr [eax], al             
  0x01067C88  0100                    add      dword ptr [eax], eax           
  0x01067C8A  0000                    add      byte ptr [eax], al             
  0x01067C8C  8af4                    mov      dh, ah                         
  0x01067C8E  0800                    or       byte ptr [eax], al             
  0x01067C90  0000                    add      byte ptr [eax], al             
  0x01067C92  0000                    add      byte ptr [eax], al             
  0x01067C94  00f4                    add      ah, dh                         
  0x01067C96  44                      inc      esp                            
  0x01067C97  0000                    add      byte ptr [eax], al             
  0x01067C99  40                      inc      eax                            
  0x01067C9A  0000                    add      byte ptr [eax], al             
  0x01067C9C  007044                  add      byte ptr [eax + 0x44], dh      
  0x01067C9F  00d5                    add      ch, dl                         
  0x01067CA2  ff00                    inc      dword ptr [eax]                
  0x01067CA4  007044                  add      byte ptr [eax + 0x44], dh      
  0x01067CA7  00d4                    add      ah, dl                         
  0x01067CAA  ff00                    inc      dword ptr [eax]                
  0x01067CAC  97                      xchg     edi, eax                       
  0x01067CAD  f4                      hlt                                     
  0x01067CAE  0800                    or       byte ptr [eax], al             
  0x01067CB0  0000                    add      byte ptr [eax], al             
  0x01067CB2  0000                    add      byte ptr [eax], al             
  0x01067CB4  0c00                    or       al, 0                          
  0x01067CB6  0000                    add      byte ptr [eax], al             
  0x01067CB8  000c0500000000          add      byte ptr [eax], cl             
  0x01067CBF  00401b                  add      byte ptr [eax + 0x1b], al      
  0x01067CC2  d000                    rol      byte ptr [eax], 1              
  0x01067CC4  f20200                  add      al, byte ptr [eax]             
  0x01067CC7  007201                  add      byte ptr [edx + 1], dh         
  0x01067CCA  0100                    add      dword ptr [eax], eax           
  0x01067CCC  11f5                    adc      ebp, esi                       
  0x01067CCE  f700400c0500            test     dword ptr [eax], 0x50c40       
  0x01067CD4  37                      aaa                                     
  0x01067CD5  0c04                    or       al, 4                          
  0x01067CD7  00a78a040084            add      byte ptr [edi - 0x7bfffb76], ah 
  0x01067CDD  180500b1b705            sbb      byte ptr [0x5b7b100], al       
  0x01067CE3  004a6a                  add      byte ptr [edx + 0x6a], cl      
  0x01067CE6  06                      push     es                             
  0x01067CE7  00ae32070085            add      byte ptr [esi - 0x7afff8ce], ch 
  0x01067CED  1308                    adc      ecx, dword ptr [eax]           
  0x01067CEF  00cc                    add      ah, cl                         
  0x01067CF1  0f09                    wbinvd                                  
  0x01067CF3  00db                    add      bl, bl                         
  0x01067CF5  2a0a                    sub      cl, byte ptr [edx]             
  0x01067CF7  007368                  add      byte ptr [ebx + 0x68], dh      
  0x01067CFA  0b00                    or       eax, dword ptr [eax]           
  0x01067CFC  cdcc                    int      0xcc                           
  0x01067CFE  0c00                    or       al, 0                          
  0x01067D00  a15c0e003f              mov      eax, dword ptr [0x3f000e5c]    
  0x01067D05  1d10009a14              sbb      eax, 0x149a0010                
  0x01067D0A  1200                    adc      al, byte ptr [eax]             
  0x01067D0C  61                      popal                                   
  0x01067D0D  49                      dec      ecx                            
  0x01067D0E  1400                    adc      al, 0                          
  0x01067D10  11c3                    adc      ebx, eax                       
  0x01067D12  16                      push     ss                             
  0x01067D13  0013                    add      byte ptr [ebx], dl             
  0x01067D15  8a19                    mov      bl, byte ptr [ecx]             
  0x01067D17  00d7                    add      bh, dl                         
  0x01067D19  a7                      cmpsd    dword ptr [esi], dword ptr es:[edi] 
  0x01067D1A  1c00                    sbb      al, 0                          
  0x01067D1C  f3262000                and      byte ptr es:[eax], al          
  0x01067D20  47                      inc      edi                            
  0x01067D21  132400                  adc      esp, dword ptr [eax + eax]     
  0x01067D24  27                      daa                                     
  0x01067D25  7a28                    jp       0x1067d4f                      
  0x01067D27  00866a2d002d            add      byte ptr [esi + 0x2d002d6a], al 
  0x01067D2D  f5                      cmc                                     
  0x01067D2E  3200                    xor      al, byte ptr [eax]             
  0x01067D30  ee                      out      dx, al                         
  0x01067D31  2c39                    sub      al, 0x39                       
  0x01067D33  00e7                    add      bh, ah                         
  0x01067D35  2640                    inc      eax                            
  0x01067D37  00cd                    add      ch, cl                         
  0x01067D39  fa                      cli                                     
  0x01067D3A  47                      inc      edi                            
  0x01067D3B  0036                    add      byte ptr [esi], dh             
  0x01067D3D  c3                      ret                                     
  0x01067D3E  50                      push     eax                            
  0x01067D3F  00f8                    add      al, bh                         
  0x01067D41  9d                      popfd                                   
  0x01067D42  5a                      pop      edx                            
  0x01067D43  008cac65008314          add      byte ptr [esp + ebp*4 + 0x14830065], cl 
  0x01067D4A  7200                    jb       0x1067d4c                      
  0x01067D4E  7f00                    jg       0x1067d50                      
                                        ; XREF: 0x01067D4E (cond_jump)
  0x01067D50  007060                  add      byte ptr [eax + 0x60], dh      
  0x01067D53  002e                    add      byte ptr [esi], ch             
  0x01067D55  06                      push     es                             
  0x01067D56  0000                    add      byte ptr [eax], al             
  0x01067D58  0b00                    or       eax, dword ptr [eax]           
  0x01067D5A  2000                    and      byte ptr [eax], al             
  0x01067D5C  06                      push     es                             
  0x01067D5D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01067D5E  050000f444              add      eax, 0x44f40000                
  0x01067D63  0002                    add      byte ptr [edx], al             
  0x01067D65  800000                  add      byte ptr [eax], 0              
  0x01067D68  007044                  add      byte ptr [eax + 0x44], dh      
  0x01067D6B  000406                  add      byte ptr [esi + eax], al       
  0x01067D6E  0000                    add      byte ptr [eax], al             
  0x01067D70  050c050000              add      eax, 0x50c                     
  0x01067D75  f4                      hlt                                     
  0x01067D76  44                      inc      esp                            
  0x01067D77  0002                    add      byte ptr [edx], al             
  0x01067D79  0000                    add      byte ptr [eax], al             
  0x01067D7B  0000                    add      byte ptr [eax], al             
  0x01067D7D  7044                    jo       0x1067dc3                      
  0x01067D7F  000406                  add      byte ptr [esi + eax], al       
  0x01067D82  0000                    add      byte ptr [eax], al             
  0x01067D84  00f4                    add      ah, dh                         
  0x01067D86  44                      inc      esp                            
  0x01067D87  000a                    add      byte ptr [edx], cl             
  0x01067D89  0000                    add      byte ptr [eax], al             
  0x01067D8B  0000                    add      byte ptr [eax], al             
  0x01067D8D  7044                    jo       0x1067dd3                      
  0x01067D8F  0000                    add      byte ptr [eax], al             
  0x01067D91  06                      push     es                             
  0x01067D92  0000                    add      byte ptr [eax], al             
  0x01067D94  00f4                    add      ah, dh                         
  0x01067D96  44                      inc      esp                            
  0x01067D97  000a                    add      byte ptr [edx], cl             
  0x01067D99  06                      push     es                             
  0x01067D9A  0000                    add      byte ptr [eax], al             
  0x01067D9C  007044                  add      byte ptr [eax + 0x44], dh      
  0x01067D9F  0001                    add      byte ptr [ecx], al             
  0x01067DA1  06                      push     es                             
  0x01067DA2  0000                    add      byte ptr [eax], al             
  0x01067DA4  00f4                    add      ah, dh                         
  0x01067DA6  44                      inc      esp                            
  0x01067DA7  0010                    add      byte ptr [eax], dl             
  0x01067DA9  06                      push     es                             
  0x01067DAA  0000                    add      byte ptr [eax], al             
  0x01067DAC  007044                  add      byte ptr [eax + 0x44], dh      
  0x01067DAF  0002                    add      byte ptr [edx], al             
  0x01067DB1  06                      push     es                             
  0x01067DB2  0000                    add      byte ptr [eax], al             
  0x01067DB4  00f4                    add      ah, dh                         
  0x01067DB6  44                      inc      esp                            
  0x01067DB7  0016                    add      byte ptr [esi], dl             
  0x01067DB9  06                      push     es                             
  0x01067DBA  0000                    add      byte ptr [eax], al             
  0x01067DBC  007044                  add      byte ptr [eax + 0x44], dh      
  0x01067DBF  0003                    add      byte ptr [ebx], al             
  0x01067DC1  06                      push     es                             
  0x01067DC2  0000                    add      byte ptr [eax], al             
  0x01067DC4  00f4                    add      ah, dh                         
  0x01067DC6  44                      inc      esp                            
  0x01067DC7  001c06                  add      byte ptr [esi + eax], bl       
  0x01067DCA  0000                    add      byte ptr [eax], al             
  0x01067DCC  007044                  add      byte ptr [eax + 0x44], dh      
  0x01067DCF  000506000000            add      byte ptr [6], al               
  0x01067DD5  f4                      hlt                                     
  0x01067DD6  44                      inc      esp                            
  0x01067DD7  0022                    add      byte ptr [edx], ah             
  0x01067DD9  06                      push     es                             
  0x01067DDA  0000                    add      byte ptr [eax], al             
  0x01067DDC  007044                  add      byte ptr [eax + 0x44], dh      
  0x01067DDF  0006                    add      byte ptr [esi], al             
  0x01067DE1  06                      push     es                             
  0x01067DE2  0000                    add      byte ptr [eax], al             
  0x01067DE4  00f4                    add      ah, dh                         
  0x01067DE6  44                      inc      esp                            
  0x01067DE7  0028                    add      byte ptr [eax], ch             
  0x01067DE9  06                      push     es                             
  0x01067DEA  0000                    add      byte ptr [eax], al             
  0x01067DEC  007044                  add      byte ptr [eax + 0x44], dh      
  0x01067DEF  0007                    add      byte ptr [edi], al             
  0x01067DF1  06                      push     es                             
  0x01067DF2  0000                    add      byte ptr [eax], al             
  0x01067DF4  00f4                    add      ah, dh                         
  0x01067DF6  44                      inc      esp                            
  0x01067DF7  0000                    add      byte ptr [eax], al             
  0x01067DF9  0000                    add      byte ptr [eax], al             
  0x01067DFB  0000                    add      byte ptr [eax], al             
  0x01067DFD  7044                    jo       0x1067e43                      
  0x01067DFF  0008                    add      byte ptr [eax], cl             
  0x01067E01  06                      push     es                             
  0x01067E02  0000                    add      byte ptr [eax], al             
  0x01067E04  00f4                    add      ah, dh                         
  0x01067E06  44                      inc      esp                            
  0x01067E07  0000                    add      byte ptr [eax], al             
  0x01067E09  0100                    add      dword ptr [eax], eax           
  0x01067E0B  0000                    add      byte ptr [eax], al             
  0x01067E0D  7044                    jo       0x1067e53                      
  0x01067E0F  0009                    add      byte ptr [ecx], cl             
  0x01067E11  06                      push     es                             
  0x01067E12  0000                    add      byte ptr [eax], al             
  0x01067E14  00f4                    add      ah, dh                         
  0x01067E16  60                      pushal                                  
  0x01067E17  000a                    add      byte ptr [edx], cl             
  0x01067E19  06                      push     es                             
  0x01067E1A  0000                    add      byte ptr [eax], al             
  0x01067E1C  00f4                    add      ah, dh                         
  0x01067E1E  44                      inc      esp                            
  0x01067E1F  0000                    add      byte ptr [eax], al             
  0x01067E21  0000                    add      byte ptr [eax], al             
  0x01067E23  0000                    add      byte ptr [eax], al             
  0x01067E25  58                      pop      eax                            
  0x01067E26  44                      inc      esp                            
  0x01067E27  0000                    add      byte ptr [eax], al             
  0x01067E29  f4                      hlt                                     
  0x01067E2A  44                      inc      esp                            
  0x01067E2B  0000                    add      byte ptr [eax], al             
  0x01067E2D  0100                    add      dword ptr [eax], eax           
  0x01067E2F  0000                    add      byte ptr [eax], al             
  0x01067E31  58                      pop      eax                            
  0x01067E32  44                      inc      esp                            
  0x01067E33  0000                    add      byte ptr [eax], al             
  0x01067E35  f4                      hlt                                     
  0x01067E36  44                      inc      esp                            
  0x01067E37  0000                    add      byte ptr [eax], al             
  0x01067E39  0200                    add      al, byte ptr [eax]             
  0x01067E3B  0000                    add      byte ptr [eax], al             
  0x01067E3D  58                      pop      eax                            
  0x01067E3E  44                      inc      esp                            
  0x01067E3F  0000                    add      byte ptr [eax], al             
  0x01067E41  f4                      hlt                                     
  0x01067E42  44                      inc      esp                            
                                        ; XREF: 0x01067DFD (cond_jump)
  0x01067E43  0000                    add      byte ptr [eax], al             
  0x01067E45  0300                    add      eax, dword ptr [eax]           
  0x01067E47  0000                    add      byte ptr [eax], al             
  0x01067E49  58                      pop      eax                            
  0x01067E4A  44                      inc      esp                            
  0x01067E4B  0000                    add      byte ptr [eax], al             
  0x01067E4D  f4                      hlt                                     
  0x01067E4E  44                      inc      esp                            
  0x01067E4F  0000                    add      byte ptr [eax], al             
  0x01067E51  0400                    add      al, 0                          
                                        ; XREF: 0x01067E0D (cond_jump)
  0x01067E53  0000                    add      byte ptr [eax], al             
  0x01067E55  58                      pop      eax                            
  0x01067E56  44                      inc      esp                            
  0x01067E57  0000                    add      byte ptr [eax], al             
  0x01067E59  f4                      hlt                                     
  0x01067E5A  44                      inc      esp                            
  0x01067E5B  00ff                    add      bh, bh                         
  0x01067E5E  ff00                    inc      dword ptr [eax]                
  0x01067E60  006044                  add      byte ptr [eax + 0x44], ah      
  0x01067E63  0000                    add      byte ptr [eax], al             
  0x01067E65  f4                      hlt                                     
  0x01067E66  60                      pushal                                  
  0x01067E67  0010                    add      byte ptr [eax], dl             
  0x01067E69  06                      push     es                             
  0x01067E6A  0000                    add      byte ptr [eax], al             
  0x01067E6C  00f4                    add      ah, dh                         
  0x01067E6E  44                      inc      esp                            
  0x01067E6F  0001                    add      byte ptr [ecx], al             
  0x01067E71  0000                    add      byte ptr [eax], al             
  0x01067E73  0000                    add      byte ptr [eax], al             
  0x01067E75  58                      pop      eax                            
  0x01067E76  44                      inc      esp                            
  0x01067E77  0000                    add      byte ptr [eax], al             
  0x01067E79  58                      pop      eax                            
  0x01067E7A  44                      inc      esp                            
  0x01067E7B  0000                    add      byte ptr [eax], al             
  0x01067E7D  58                      pop      eax                            
  0x01067E7E  44                      inc      esp                            
  0x01067E7F  0000                    add      byte ptr [eax], al             
  0x01067E81  58                      pop      eax                            
  0x01067E82  44                      inc      esp                            
  0x01067E83  0000                    add      byte ptr [eax], al             
  0x01067E85  58                      pop      eax                            
  0x01067E86  44                      inc      esp                            
  0x01067E87  0000                    add      byte ptr [eax], al             
  0x01067E89  002400                  add      byte ptr [eax + eax], ah       
  0x01067E8C  006044                  add      byte ptr [eax + 0x44], ah      
  0x01067E8F  0000                    add      byte ptr [eax], al             
  0x01067E91  f4                      hlt                                     
  0x01067E92  60                      pushal                                  
  0x01067E93  0016                    add      byte ptr [esi], dl             
  0x01067E95  06                      push     es                             
  0x01067E96  0000                    add      byte ptr [eax], al             
  0x01067E98  00f4                    add      ah, dh                         
  0x01067E9A  44                      inc      esp                            
  0x01067E9B  00ff                    add      bh, bh                         
  0x01067E9E  ff00                    inc      dword ptr [eax]                
  0x01067EA0  005844                  add      byte ptr [eax + 0x44], bl      
  0x01067EA3  0000                    add      byte ptr [eax], al             
  0x01067EA5  58                      pop      eax                            
  0x01067EA6  44                      inc      esp                            
  0x01067EA7  0000                    add      byte ptr [eax], al             
  0x01067EA9  58                      pop      eax                            
  0x01067EAA  44                      inc      esp                            
  0x01067EAB  0000                    add      byte ptr [eax], al             
  0x01067EAD  58                      pop      eax                            
  0x01067EAE  44                      inc      esp                            
  0x01067EAF  0000                    add      byte ptr [eax], al             
  0x01067EB1  58                      pop      eax                            
  0x01067EB2  44                      inc      esp                            
  0x01067EB3  0000                    add      byte ptr [eax], al             
  0x01067EB5  60                      pushal                                  
  0x01067EB6  44                      inc      esp                            
  0x01067EB7  0000                    add      byte ptr [eax], al             
  0x01067EB9  f4                      hlt                                     
  0x01067EBA  60                      pushal                                  
  0x01067EBB  001c06                  add      byte ptr [esi + eax], bl       
  0x01067EBE  0000                    add      byte ptr [eax], al             
  0x01067EC0  00f4                    add      ah, dh                         
  0x01067EC2  44                      inc      esp                            
  0x01067EC3  0000                    add      byte ptr [eax], al             
  0x01067EC5  0400                    add      al, 0                          
  0x01067EC7  0000                    add      byte ptr [eax], al             
  0x01067EC9  58                      pop      eax                            
  0x01067ECA  44                      inc      esp                            
  0x01067ECB  0000                    add      byte ptr [eax], al             
  0x01067ECD  f4                      hlt                                     
  0x01067ECE  44                      inc      esp                            
  0x01067ECF  00ff                    add      bh, bh                         
  0x01067ED2  ff00                    inc      dword ptr [eax]                
  0x01067ED4  005844                  add      byte ptr [eax + 0x44], bl      
  0x01067ED7  0000                    add      byte ptr [eax], al             
  0x01067ED9  f4                      hlt                                     
  0x01067EDA  44                      inc      esp                            
  0x01067EDB  0000                    add      byte ptr [eax], al             
  0x01067EDD  0500000058              add      eax, 0x58000000                
  0x01067EE2  44                      inc      esp                            
  0x01067EE3  0000                    add      byte ptr [eax], al             
  0x01067EE5  f4                      hlt                                     
  0x01067EE6  44                      inc      esp                            
  0x01067EE7  00ff                    add      bh, bh                         
  0x01067EEA  ff00                    inc      dword ptr [eax]                
  0x01067EEC  005844                  add      byte ptr [eax + 0x44], bl      
  0x01067EEF  0000                    add      byte ptr [eax], al             
  0x01067EF1  f4                      hlt                                     
  0x01067EF2  44                      inc      esp                            
  0x01067EF3  00ff                    add      bh, bh                         
  0x01067EF6  ff00                    inc      dword ptr [eax]                
  0x01067EF8  005844                  add      byte ptr [eax + 0x44], bl      
  0x01067EFB  0000                    add      byte ptr [eax], al             
  0x01067EFD  f4                      hlt                                     
  0x01067EFE  44                      inc      esp                            
  0x01067EFF  00ff                    add      bh, bh                         
  0x01067F02  ff00                    inc      dword ptr [eax]                
  0x01067F04  005844                  add      byte ptr [eax + 0x44], bl      
  0x01067F07  0000                    add      byte ptr [eax], al             
  0x01067F09  f4                      hlt                                     
  0x01067F0A  60                      pushal                                  
  0x01067F0B  0022                    add      byte ptr [edx], ah             
  0x01067F0D  06                      push     es                             
  0x01067F0E  0000                    add      byte ptr [eax], al             
  0x01067F10  00f4                    add      ah, dh                         
  0x01067F12  44                      inc      esp                            
  0x01067F13  0001                    add      byte ptr [ecx], al             
  0x01067F15  0000                    add      byte ptr [eax], al             
  0x01067F17  0000                    add      byte ptr [eax], al             
  0x01067F19  58                      pop      eax                            
  0x01067F1A  44                      inc      esp                            
  0x01067F1B  0000                    add      byte ptr [eax], al             
  0x01067F1D  002400                  add      byte ptr [eax + eax], ah       
  0x01067F20  005844                  add      byte ptr [eax + 0x44], bl      
  0x01067F23  0000                    add      byte ptr [eax], al             
  0x01067F25  f4                      hlt                                     
  0x01067F26  44                      inc      esp                            
  0x01067F27  0001                    add      byte ptr [ecx], al             
  0x01067F29  0000                    add      byte ptr [eax], al             
  0x01067F2B  0000                    add      byte ptr [eax], al             
  0x01067F2D  58                      pop      eax                            
  0x01067F2E  44                      inc      esp                            
  0x01067F2F  0000                    add      byte ptr [eax], al             
  0x01067F31  002400                  add      byte ptr [eax + eax], ah       
  0x01067F34  005844                  add      byte ptr [eax + 0x44], bl      
  0x01067F37  0000                    add      byte ptr [eax], al             
  0x01067F39  002400                  add      byte ptr [eax + eax], ah       
  0x01067F3C  005844                  add      byte ptr [eax + 0x44], bl      
  0x01067F3F  0000                    add      byte ptr [eax], al             
  0x01067F41  002400                  add      byte ptr [eax + eax], ah       
  0x01067F44  005844                  add      byte ptr [eax + 0x44], bl      
  0x01067F47  0000                    add      byte ptr [eax], al             
  0x01067F49  f4                      hlt                                     
  0x01067F4A  60                      pushal                                  
  0x01067F4B  0028                    add      byte ptr [eax], ch             
  0x01067F4D  06                      push     es                             
  0x01067F4E  0000                    add      byte ptr [eax], al             
  0x01067F50  00f4                    add      ah, dh                         
  0x01067F52  44                      inc      esp                            
  0x01067F53  00ff                    add      bh, bh                         
  0x01067F56  ff00                    inc      dword ptr [eax]                
  0x01067F58  005844                  add      byte ptr [eax + 0x44], bl      
  0x01067F5B  0000                    add      byte ptr [eax], al             
  0x01067F5D  58                      pop      eax                            
  0x01067F5E  44                      inc      esp                            
  0x01067F5F  0000                    add      byte ptr [eax], al             
  0x01067F61  58                      pop      eax                            
  0x01067F62  44                      inc      esp                            
  0x01067F63  0000                    add      byte ptr [eax], al             
  0x01067F65  58                      pop      eax                            
  0x01067F66  44                      inc      esp                            
  0x01067F67  0000                    add      byte ptr [eax], al             
  0x01067F69  58                      pop      eax                            
  0x01067F6A  44                      inc      esp                            
  0x01067F6B  0000                    add      byte ptr [eax], al             
  0x01067F6D  58                      pop      eax                            
  0x01067F6E  44                      inc      esp                            
  0x01067F6F  0000                    add      byte ptr [eax], al             
  0x01067F71  f4                      hlt                                     
  0x01067F72  56                      push     esi                            
  0x01067F73  0007                    add      byte ptr [edi], al             
  0x01067F75  0000                    add      byte ptr [eax], al             
  0x01067F77  0000                    add      byte ptr [eax], al             
  0x01067F79  f4                      hlt                                     
  0x01067F7A  60                      pushal                                  
  0x01067F7B  0000                    add      byte ptr [eax], al             
  0x01067F7D  0000                    add      byte ptr [eax], al             
  0x01067F7F  0000                    add      byte ptr [eax], al             
  0x01067F81  f4                      hlt                                     
  0x01067F82  7000                    jo       0x1067f84                      
                                        ; XREF: 0x01067F82 (cond_jump)
  0x01067F84  0001                    add      byte ptr [ecx], al             
  0x01067F86  0000                    add      byte ptr [eax], al             
  0x01067F88  0000                    add      byte ptr [eax], al             
  0x01067F8A  3900                    cmp      dword ptr [eax], eax           
  0x01067F8C  80010d                  add      byte ptr [ecx], 0xd            
  0x01067F8F  0000                    add      byte ptr [eax], al             
  0x01067F91  f4                      hlt                                     
  0x01067F92  56                      push     esi                            
  0x01067F93  0007                    add      byte ptr [edi], al             
  0x01067F95  0000                    add      byte ptr [eax], al             
  0x01067F97  0000                    add      byte ptr [eax], al             
  0x01067F99  f4                      hlt                                     
  0x01067F9A  60                      pushal                                  
  0x01067F9B  0000                    add      byte ptr [eax], al             
  0x01067F9D  0100                    add      dword ptr [eax], eax           
  0x01067F9F  0000                    add      byte ptr [eax], al             
  0x01067FA1  f4                      hlt                                     
  0x01067FA2  7000                    jo       0x1067fa4                      
                                        ; XREF: 0x01067FA2 (cond_jump)
  0x01067FA4  0001                    add      byte ptr [ecx], al             
  0x01067FA6  0000                    add      byte ptr [eax], al             
  0x01067FA8  0001                    add      byte ptr [ecx], al             
  0x01067FAA  3900                    cmp      dword ptr [eax], eax           
  0x01067FAC  80010d                  add      byte ptr [ecx], 0xd            
  0x01067FAF  0000                    add      byte ptr [eax], al             
  0x01067FB1  f4                      hlt                                     
  0x01067FB2  56                      push     esi                            
  0x01067FB3  0007                    add      byte ptr [edi], al             
  0x01067FB5  0000                    add      byte ptr [eax], al             
  0x01067FB7  0000                    add      byte ptr [eax], al             
  0x01067FB9  f4                      hlt                                     
  0x01067FBA  60                      pushal                                  
  0x01067FBB  0000                    add      byte ptr [eax], al             
  0x01067FBD  0200                    add      al, byte ptr [eax]             
  0x01067FBF  0000                    add      byte ptr [eax], al             
  0x01067FC1  f4                      hlt                                     
  0x01067FC2  7000                    jo       0x1067fc4                      
                                        ; XREF: 0x01067FC2 (cond_jump)
  0x01067FC4  0001                    add      byte ptr [ecx], al             
  0x01067FC6  0000                    add      byte ptr [eax], al             
  0x01067FC8  0002                    add      byte ptr [edx], al             
  0x01067FCA  3900                    cmp      dword ptr [eax], eax           
  0x01067FCC  80010d                  add      byte ptr [ecx], 0xd            
  0x01067FCF  0000                    add      byte ptr [eax], al             
  0x01067FD1  f4                      hlt                                     
  0x01067FD2  56                      push     esi                            
  0x01067FD3  0007                    add      byte ptr [edi], al             
  0x01067FD5  0000                    add      byte ptr [eax], al             
  0x01067FD7  0000                    add      byte ptr [eax], al             
  0x01067FD9  f4                      hlt                                     
  0x01067FDA  60                      pushal                                  
  0x01067FDB  0000                    add      byte ptr [eax], al             
  0x01067FDD  0300                    add      eax, dword ptr [eax]           
  0x01067FDF  0000                    add      byte ptr [eax], al             
  0x01067FE1  f4                      hlt                                     
  0x01067FE2  7000                    jo       0x1067fe4                      
                                        ; XREF: 0x01067FE2 (cond_jump)
  0x01067FE4  0001                    add      byte ptr [ecx], al             
  0x01067FE6  0000                    add      byte ptr [eax], al             
  0x01067FE8  0003                    add      byte ptr [ebx], al             
  0x01067FEA  3900                    cmp      dword ptr [eax], eax           
  0x01067FEC  80010d                  add      byte ptr [ecx], 0xd            
  0x01067FEF  0000                    add      byte ptr [eax], al             
  0x01067FF1  f4                      hlt                                     
  0x01067FF2  56                      push     esi                            
  0x01067FF3  0007                    add      byte ptr [edi], al             
  0x01067FF5  0000                    add      byte ptr [eax], al             
  0x01067FF7  0000                    add      byte ptr [eax], al             
  0x01067FF9  f4                      hlt                                     
  0x01067FFA  60                      pushal                                  
  0x01067FFB  0000                    add      byte ptr [eax], al             
  0x01067FFD  0400                    add      al, 0                          
  0x01067FFF  0000                    add      byte ptr [eax], al             
  0x01068001  f4                      hlt                                     
  0x01068002  7000                    jo       0x1068004                      
                                        ; XREF: 0x01068002 (cond_jump)
  0x01068004  0001                    add      byte ptr [ecx], al             
  0x01068006  0000                    add      byte ptr [eax], al             
  0x01068008  000439                  add      byte ptr [ecx + edi], al       
  0x0106800B  0080010d0013            add      byte ptr [eax + 0x13000d01], al 
  0x01068012  6200                    bound    eax, qword ptr [eax]           
  0x01068014  2e06                    push     es                             
  0x01068016  0000                    add      byte ptr [eax], al             
  0x01068018  dc1a                    fcomp    qword ptr [edx]                
  0x0106801A  0200                    add      al, byte ptr [eax]             
  0x0106801C  00f4                    add      ah, dh                         
  0x0106801E  44                      inc      esp                            
  0x0106801F  0001                    add      byte ptr [ecx], al             
  0x01068021  0000                    add      byte ptr [eax], al             
  0x01068023  004500                  add      byte ptr [ebp], al             
  0x01068026  2000                    and      byte ptr [eax], al             
  0x01068028  41                      inc      ecx                            
  0x01068029  2920                    sub      dword ptr [eax], esp           
  0x0106802B  0000                    add      byte ptr [eax], al             
  0x0106802D  f4                      hlt                                     
  0x0106802E  44                      inc      esp                            
  0x0106802F  001f                    add      byte ptr [edi], bl             
  0x01068031  0000                    add      byte ptr [eax], al             
  0x01068033  004500                  add      byte ptr [ebp], al             
  0x01068036  2000                    and      byte ptr [eax], al             
  0x01068038  41                      inc      ecx                            
  0x01068039  27                      daa                                     
  0x0106803A  2000                    and      byte ptr [eax], al             
  0x0106803C  0098210000f4            add      byte ptr [eax - 0xbffffdf], bl 
  0x01068042  60                      pushal                                  
  0x01068043  000503000085            add      byte ptr [0x85000003], al      
  0x01068049  e807009708              call     0x99d8055                      
  0x0106804E  050013f460              add      eax, 0x60f41300                
  0x01068053  0000                    add      byte ptr [eax], al             
  0x01068055  06                      push     es                             
  0x01068056  0000                    add      byte ptr [eax], al             
  0x01068058  00f4                    add      ah, dh                         
  0x0106805A  57                      push     edi                            
  0x0106805B  0016                    add      byte ptr [esi], dl             
  0x0106805D  0000                    add      byte ptr [eax], al             
  0x0106805F  0080100d005b            add      byte ptr [eax + 0x5b000d10], al 
  0x01068065  0000                    add      byte ptr [eax], al             
  0x01068067  0013                    add      byte ptr [ebx], dl             
  0x01068069  f4                      hlt                                     
  0x0106806A  6200                    bound    eax, qword ptr [eax]           
  0x0106806C  000400                  add      byte ptr [eax + eax], al       
  0x0106806F  001b                    add      byte ptr [ebx], bl             
  0x01068071  0020                    add      byte ptr [eax], ah             
  0x01068073  009100060005            add      byte ptr [ecx + 0x5000600], dl 
  0x01068079  0000                    add      byte ptr [eax], al             
  0x0106807B  0000                    add      byte ptr [eax], al             
  0x0106807D  da44008a                fiadd    dword ptr [eax + eax - 0x76]   
  0x01068081  0020                    add      byte ptr [eax], ah             
  0x01068083  004700                  add      byte ptr [edi], al             
  0x01068086  2000                    and      byte ptr [eax], al             
  0x01068088  40                      inc      eax                            
  0x01068089  90                      nop                                     
  0x0106808A  0200                    add      al, byte ptr [eax]             
  0x0106808C  260020                  add      byte ptr es:[eax], ah          
  0x0106808F  00911c0c0000            add      byte ptr [ecx + 0xc1c], dl     
  0x01068095  7056                    jo       0x10680ed                      
  0x01068097  002f                    add      byte ptr [edi], ch             
  0x01068099  06                      push     es                             
  0x0106809A  0000                    add      byte ptr [eax], al             
  0x0106809C  00a721000026            add      byte ptr [edi + 0x26000021], ah 
  0x010680A2  2100                    and      dword ptr [eax], eax           
  0x010680A4  13402f                  adc      eax, dword ptr [eax + 0x2f]    
  0x010680A7  009017060009            add      byte ptr [eax + 0x9000617], dl 
  0x010680AD  0000                    add      byte ptr [eax], al             
  0x010680AF  0010                    add      byte ptr [eax], dl             
  0x010680B1  c521                    lds      esp, ptr [ecx]                 
  0x010680B3  0000                    add      byte ptr [eax], al             
  0x010680B5  0000                    add      byte ptr [eax], al             
  0x010680B7  0000                    add      byte ptr [eax], al             
  0x010680B9  c421                    les      esp, ptr [ecx]                 
  0x010680BB  00840020003000          add      byte ptr [eax + eax + 0x300020], al 
  0x010680C2  2000                    and      byte ptr [eax], al             
  0x010680C4  00ae20001021            add      byte ptr [esi + 0x21100020], ch 
  0x010680CA  2000                    and      byte ptr [eax], al             
  0x010680CC  2a00                    sub      al, byte ptr [eax]             
  0x010680CE  2000                    and      byte ptr [eax], al             
  0x010680D0  007056                  add      byte ptr [eax + 0x56], dh      
  0x010680D3  0031                    add      byte ptr [ecx], dh             
  0x010680D5  06                      push     es                             
  0x010680D6  0000                    add      byte ptr [eax], al             
  0x010680D8  13f4                    adc      esi, esp                       
  0x010680DA  6200                    bound    eax, qword ptr [eax]           
  0x010680DC  000500001b00            add      byte ptr [0x1b0000], al        
  0x010680E2  2000                    and      byte ptr [eax], al             
  0x010680E4  91                      xchg     ecx, eax                       
  0x010680E5  0006                    add      byte ptr [esi], al             
  0x010680E7  000500000000            add      byte ptr [0], al               
                                        ; XREF: 0x01068095 (cond_jump)
  0x010680ED  da44008a                fiadd    dword ptr [eax + eax - 0x76]   
  0x010680F1  0020                    add      byte ptr [eax], ah             
  0x010680F3  004700                  add      byte ptr [edi], al             
  0x010680F6  2000                    and      byte ptr [eax], al             
  0x010680F8  40                      inc      eax                            
  0x010680F9  90                      nop                                     
  0x010680FA  0200                    add      al, byte ptr [eax]             
  0x010680FC  260020                  add      byte ptr es:[eax], ah          
  0x010680FF  00911c0c0000            add      byte ptr [ecx + 0xc1c], dl     
  0x01068105  7056                    jo       0x106815d                      
  0x01068107  0030                    add      byte ptr [eax], dh             
  0x01068109  06                      push     es                             
  0x0106810A  0000                    add      byte ptr [eax], al             
  0x0106810C  00a721000026            add      byte ptr [edi + 0x26000021], ah 
  0x01068112  2100                    and      dword ptr [eax], eax           
  0x01068114  13402f                  adc      eax, dword ptr [eax + 0x2f]    
  0x01068117  009017060009            add      byte ptr [eax + 0x9000617], dl 
  0x0106811D  0000                    add      byte ptr [eax], al             
  0x0106811F  0010                    add      byte ptr [eax], dl             
  0x01068121  c521                    lds      esp, ptr [ecx]                 
  0x01068123  0000                    add      byte ptr [eax], al             
  0x01068125  0000                    add      byte ptr [eax], al             
  0x01068127  0000                    add      byte ptr [eax], al             
  0x01068129  c421                    les      esp, ptr [ecx]                 
  0x0106812B  00840020003000          add      byte ptr [eax + eax + 0x300020], al 
  0x01068132  2000                    and      byte ptr [eax], al             
  0x01068134  00ae20001021            add      byte ptr [esi + 0x21100020], ch 
  0x0106813A  2000                    and      byte ptr [eax], al             
  0x0106813C  2a00                    sub      al, byte ptr [eax]             
  0x0106813E  2000                    and      byte ptr [eax], al             
  0x01068140  007056                  add      byte ptr [eax + 0x56], dh      
  0x01068143  0032                    add      byte ptr [edx], dh             
  0x01068145  06                      push     es                             
  0x01068146  0000                    add      byte ptr [eax], al             
  0x01068148  00f4                    add      ah, dh                         
  0x0106814A  56                      push     esi                            
  0x0106814B  0008                    add      byte ptr [eax], cl             
  0x0106814D  0000                    add      byte ptr [eax], al             
  0x0106814F  0000                    add      byte ptr [eax], al             
  0x01068151  f4                      hlt                                     
  0x01068152  60                      pushal                                  
  0x01068153  0000                    add      byte ptr [eax], al             
  0x01068155  0400                    add      al, 0                          
  0x01068157  0000                    add      byte ptr [eax], al             
  0x01068159  f4                      hlt                                     
  0x0106815A  7000                    jo       0x106815c                      
                                        ; XREF: 0x0106815A (cond_jump)
  0x0106815C  0001                    add      byte ptr [ecx], al             
  0x0106815E  0000                    add      byte ptr [eax], al             
  0x01068160  0000                    add      byte ptr [eax], al             
  0x01068162  3900                    cmp      dword ptr [eax], eax           
  0x01068164  80010d                  add      byte ptr [ecx], 0xd            
  0x01068167  0000                    add      byte ptr [eax], al             
  0x01068169  f4                      hlt                                     
  0x0106816A  56                      push     esi                            
  0x0106816B  0008                    add      byte ptr [eax], cl             
  0x0106816D  0000                    add      byte ptr [eax], al             
  0x0106816F  0000                    add      byte ptr [eax], al             
  0x01068171  f4                      hlt                                     
  0x01068172  60                      pushal                                  
  0x01068173  0000                    add      byte ptr [eax], al             
  0x01068175  05000000f4              add      eax, 0xf4000000                
  0x0106817A  7000                    jo       0x106817c                      
                                        ; XREF: 0x0106817A (cond_jump)
  0x0106817C  0001                    add      byte ptr [ecx], al             
  0x0106817E  0000                    add      byte ptr [eax], al             
  0x01068180  0001                    add      byte ptr [ecx], al             
  0x01068182  3900                    cmp      dword ptr [eax], eax           
  0x01068184  80010d                  add      byte ptr [ecx], 0xd            
  0x01068187  0000                    add      byte ptr [eax], al             
  0x01068189  f4                      hlt                                     
  0x0106818A  56                      push     esi                            
  0x0106818B  000f                    add      byte ptr [edi], cl             
  0x0106818D  0000                    add      byte ptr [eax], al             
  0x0106818F  0000                    add      byte ptr [eax], al             
  0x01068191  f4                      hlt                                     
  0x01068192  60                      pushal                                  
  0x01068193  002f                    add      byte ptr [edi], ch             
  0x01068195  06                      push     es                             
  0x01068196  0000                    add      byte ptr [eax], al             
  0x01068198  000438                  add      byte ptr [eax + edi], al       
  0x0106819B  0000                    add      byte ptr [eax], al             
  0x0106819D  0039                    add      byte ptr [ecx], bh             
  0x0106819F  0080010d000c            add      byte ptr [eax + 0xc000d01], al 
  0x010681A5  0000                    add      byte ptr [eax], al             
  0x010681A7  0000                    add      byte ptr [eax], al             
  0x010681A9  f4                      hlt                                     
  0x010681AA  60                      pushal                                  
  0x010681AB  0000                    add      byte ptr [eax], al             
  0x010681AD  0000                    add      byte ptr [eax], al             
  0x010681AF  009280060005            add      byte ptr [edx + 0x5000680], dl 
  0x010681B5  0000                    add      byte ptr [eax], al             
  0x010681B7  0000                    add      byte ptr [eax], al             
  0x010681B9  d84400a1                fadd     dword ptr [eax + eax - 0x5f]   
  0x010681BD  d04600                  rol      byte ptr [esi], 1              
  0x010681C0  e958560000              jmp      0x106d81d                      
  0x010681C5  58                      pop      eax                            
  0x010681C6  57                      push     edi                            
  0x010681C7  000c00                  add      byte ptr [eax + eax], cl       
  0x010681CA  0000                    add      byte ptr [eax], al             
  0x010681CC  20f4                    and      ah, dh                         
  0x010681CE  0500ffffff              add      eax, 0xffffff00                
  0x010681D3  00a0610400a0            add      byte ptr [eax - 0x5ffffb9f], ah 
  0x010681D9  620400                  bound    eax, qword ptr [eax + eax]     
  0x010681DC  a0640400a0              mov      al, byte ptr [0xa0000464]      
  0x010681E1  650400                  add      al, 0                          
  0x010681E4  a0660400b8              mov      al, byte ptr [0xb8000466]      
  0x010681E9  f30000                  add      byte ptr [eax], al             
  0x010681EC  00f4                    add      ah, dh                         
  0x010681EE  44                      inc      esp                            
  0x010681EF  0016                    add      byte ptr [esi], dl             
  0x010681F1  0000                    add      byte ptr [eax], al             
  0x010681F3  004d00                  add      byte ptr [ebp], cl             
  0x010681F6  2000                    and      byte ptr [eax], al             
  0x010681F8  4a                      dec      edx                            
  0x010681F9  100d00080000            adc      byte ptr [0x800], cl           
  0x010681FF  0000                    add      byte ptr [eax], al             
  0x01068201  0030                    add      byte ptr [eax], dh             
  0x01068203  0000                    add      byte ptr [eax], al             
  0x01068205  f4                      hlt                                     
  0x01068206  56                      push     esi                            
  0x01068207  0000                    add      byte ptr [eax], al             
  0x01068209  0000                    add      byte ptr [eax], al             
  0x0106820B  0000                    add      byte ptr [eax], al             
  0x0106820D  f4                      hlt                                     
  0x0106820E  57                      push     edi                            
  0x0106820F  00ff                    add      bh, bh                         
  0x01068212  ff00                    inc      dword ptr [eax]                
  0x01068214  0c00                    or       al, 0                          
  0x01068216  0000                    add      byte ptr [eax], al             
  0x01068218  80100d                  adc      byte ptr [eax], 0xd            
  0x0106821B  00b800000000            add      byte ptr [eax], bh             
  0x01068222  56                      push     esi                            
  0x01068223  0036                    add      byte ptr [esi], dh             
  0x01068225  06                      push     es                             
  0x01068226  0000                    add      byte ptr [eax], al             
  0x01068228  0300                    add      eax, dword ptr [eax]           
  0x0106822A  2000                    and      byte ptr [eax], al             
  0x0106822C  06                      push     es                             
  0x0106822D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106822E  050080100d              add      eax, 0xd108000                 
  0x01068233  005001                  add      byte ptr [eax + 1], dl         
  0x01068236  0000                    add      byte ptr [eax], al             
  0x01068238  80100d                  adc      byte ptr [eax], 0xd            
  0x0106823B  002f                    add      byte ptr [edi], ch             
  0x0106823D  0100                    add      dword ptr [eax], eax           
  0x0106823F  0003                    add      byte ptr [ebx], al             
  0x01068241  0c05                    or       al, 5                          
  0x01068243  0080100d0053            add      byte ptr [eax + 0x53000d10], al 
  0x01068249  0100                    add      dword ptr [eax], eax           
  0x0106824B  0080100d0030            add      byte ptr [eax + 0x30000d10], al 
  0x01068251  0100                    add      dword ptr [eax], eax           
  0x01068253  0000                    add      byte ptr [eax], al             
  0x01068256  56                      push     esi                            
  0x01068257  0037                    add      byte ptr [edi], dh             
  0x01068259  06                      push     es                             
  0x0106825A  0000                    add      byte ptr [eax], al             
  0x0106825C  854001                  test     dword ptr [eax + 1], eax       
  0x0106825F  0017                    add      byte ptr [edi], dl             
  0x01068261  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01068262  050000f066              add      eax, 0x66f00000                
  0x01068267  0033                    add      byte ptr [ebx], dh             
  0x01068269  06                      push     es                             
  0x0106826A  0000                    add      byte ptr [eax], al             
  0x0106826C  0003                    add      byte ptr [ebx], al             
  0x0106826E  3e0000                  add      byte ptr ds:[eax], al          
  0x01068271  ee                      out      dx, al                         
  0x01068272  60                      pushal                                  
  0x01068273  0000                    add      byte ptr [eax], al             
  0x01068275  043e                    add      al, 0x3e                       
  0x01068277  0000                    add      byte ptr [eax], al             
  0x01068279  ee                      out      dx, al                         
  0x0106827A  61                      popal                                   
  0x0106827B  0000                    add      byte ptr [eax], al             
  0x0106827D  f066003406              lock add byte ptr [esi + eax], dh       
  0x01068282  0000                    add      byte ptr [eax], al             
  0x01068284  0003                    add      byte ptr [ebx], al             
  0x01068286  3e0000                  add      byte ptr ds:[eax], al          
  0x01068289  ee                      out      dx, al                         
  0x0106828A  7000                    jo       0x106828c                      
                                        ; XREF: 0x0106828A (cond_jump)
  0x0106828C  00043e                  add      byte ptr [esi + edi], al       
  0x0106828F  0000                    add      byte ptr [eax], al             
  0x01068291  ee                      out      dx, al                         
  0x01068292  7100                    jno      0x1068294                      
                                        ; XREF: 0x01068292 (cond_jump)
  0x01068294  00f4                    add      ah, dh                         
  0x01068296  46                      inc      esi                            
  0x01068297  007a82                  add      byte ptr [edx - 0x7e], bh      
  0x0106829A  5a                      pop      edx                            
  0x0106829B  0000                    add      byte ptr [eax], al             
  0x0106829E  6200                    bound    eax, qword ptr [eax]           
  0x010682A0  3c06                    cmp      al, 6                          
  0x010682A2  0000                    add      byte ptr [eax], al             
  0x010682A4  10d2                    adc      dl, dl                         
  0x010682A6  06                      push     es                             
  0x010682A7  000500000000            add      byte ptr [0], al               
  0x010682AD  e044                    loopne   0x10682f3                      
  0x010682AF  00d0                    add      al, dl                         
  0x010682B1  c9                      leave                                   
  0x010682B2  44                      inc      esp                            
  0x010682B3  00d3                    add      bl, dl                         
  0x010682B5  0020                    add      byte ptr [eax], ah             
  0x010682B7  0000                    add      byte ptr [eax], al             
  0x010682B9  48                      dec      eax                            
  0x010682BA  56                      push     esi                            
  0x010682BB  0000                    add      byte ptr [eax], al             
  0x010682BD  f0660033                lock add byte ptr [ebx], dh             
  0x010682C1  06                      push     es                             
  0x010682C2  0000                    add      byte ptr [eax], al             
  0x010682C4  0000                    add      byte ptr [eax], al             
  0x010682C6  3e0000                  add      byte ptr ds:[eax], al          
  0x010682C9  ee                      out      dx, al                         
  0x010682CA  60                      pushal                                  
  0x010682CB  0000                    add      byte ptr [eax], al             
  0x010682CD  023e                    add      bh, byte ptr [esi]             
  0x010682CF  0000                    add      byte ptr [eax], al             
  0x010682D1  ee                      out      dx, al                         
  0x010682D2  61                      popal                                   
  0x010682D3  0000                    add      byte ptr [eax], al             
  0x010682D5  013e                    add      dword ptr [esi], edi           
  0x010682D7  0000                    add      byte ptr [eax], al             
  0x010682D9  ee                      out      dx, al                         
  0x010682DA  6200                    bound    eax, qword ptr [eax]           
  0x010682DC  00f0                    add      al, dh                         
  0x010682DE  660038                  add      byte ptr [eax], bh             
  0x010682E1  06                      push     es                             
  0x010682E2  0000                    add      byte ptr [eax], al             
  0x010682E4  0000                    add      byte ptr [eax], al             
  0x010682E6  3e0000                  add      byte ptr ds:[eax], al          
  0x010682E9  ee                      out      dx, al                         
  0x010682EA  640000                  add      byte ptr fs:[eax], al          
  0x010682ED  023e                    add      bh, byte ptr [esi]             
  0x010682EF  0000                    add      byte ptr [eax], al             
  0x010682F1  ee                      out      dx, al                         
  0x010682F2  650000                  add      byte ptr gs:[eax], al          
  0x010682F5  f066003406              lock add byte ptr [esi + eax], dh       
  0x010682FA  0000                    add      byte ptr [eax], al             
  0x010682FC  0000                    add      byte ptr [eax], al             
  0x010682FE  3e0000                  add      byte ptr ds:[eax], al          
  0x01068301  ee                      out      dx, al                         
  0x01068302  7000                    jo       0x1068304                      
                                        ; XREF: 0x01068302 (cond_jump)
  0x01068304  0002                    add      byte ptr [edx], al             
  0x01068306  3e0000                  add      byte ptr ds:[eax], al          
  0x01068309  ee                      out      dx, al                         
  0x0106830A  7100                    jno      0x106830c                      
                                        ; XREF: 0x0106830A (cond_jump)
  0x0106830C  0001                    add      byte ptr [ecx], al             
  0x0106830E  3e0000                  add      byte ptr ds:[eax], al          
  0x01068311  ee                      out      dx, al                         
  0x01068312  7200                    jb       0x1068314                      
                                        ; XREF: 0x01068312 (cond_jump)
  0x01068314  00f0                    add      al, dh                         
  0x01068316  660039                  add      byte ptr [ecx], bh             
  0x01068319  06                      push     es                             
  0x0106831A  0000                    add      byte ptr [eax], al             
  0x0106831C  0000                    add      byte ptr [eax], al             
  0x0106831E  3e0000                  add      byte ptr ds:[eax], al          
  0x01068321  ee                      out      dx, al                         
  0x01068322  7400                    je       0x1068324                      
                                        ; XREF: 0x01068322 (cond_jump)
  0x01068324  00f4                    add      ah, dh                         
  0x01068326  7600                    jbe      0x1068328                      
                                        ; XREF: 0x01068326 (cond_jump)
  0x01068328  0200                    add      al, byte ptr [eax]             
  0x0106832A  0000                    add      byte ptr [eax], al             
  0x0106832C  00ee                    add      dh, ch                         
  0x0106832E  7500                    jne      0x1068330                      
                                        ; XREF: 0x0106832E (cond_jump)
  0x01068330  00f4                    add      ah, dh                         
  0x01068332  45                      inc      ebp                            
  0x01068333  007a82                  add      byte ptr [edx - 0x7e], bh      
  0x01068336  5a                      pop      edx                            
  0x01068337  0000                    add      byte ptr [eax], al             
  0x01068339  f066003c06              lock add byte ptr [esi + eax], bh       
  0x0106833E  0000                    add      byte ptr [eax], al             
  0x01068340  00d6                    add      dh, dl                         
  0x01068342  06                      push     es                             
  0x01068343  00a604000000            add      byte ptr [esi + 4], ah         
  0x01068349  ca4400                  retf     0x44                           
  0x0106834C  00c8                    add      al, cl                         
  0x0106834E  56                      push     esi                            
  0x0106834F  00a3c95700ab            add      byte ptr [ebx - 0x54ffa837], ah 
  0x01068355  4c                      dec      esp                            
  0x01068356  56                      push     esi                            
  0x01068357  0000                    add      byte ptr [eax], al             
  0x01068359  4d                      dec      ebp                            
  0x0106835A  57                      push     edi                            
  0x0106835B  0000                    add      byte ptr [eax], al             
  0x0106835D  f4                      hlt                                     
  0x0106835E  61                      popal                                   
  0x0106835F  003d06000000            add      byte ptr [6], bh               
  0x01068365  f065008b06000000        lock add byte ptr gs:[ebx + 6], cl      
  0x0106836D  f4                      hlt                                     
  0x0106836E  6200                    bound    eax, qword ptr [eax]           
  0x01068370  7106                    jno      0x1068378                      
  0x01068372  0000                    add      byte ptr [eax], al             
  0x01068374  00f0                    add      al, dh                         
  0x01068376  660038                  add      byte ptr [eax], bh             
  0x01068379  06                      push     es                             
  0x0106837A  0000                    add      byte ptr [eax], al             
  0x0106837C  0000                    add      byte ptr [eax], al             
  0x0106837E  3e0000                  add      byte ptr ds:[eax], al          
  0x01068381  ee                      out      dx, al                         
  0x01068382  60                      pushal                                  
  0x01068383  0000                    add      byte ptr [eax], al             
  0x01068385  1422                    adc      al, 0x22                       
  0x01068387  0000                    add      byte ptr [eax], al             
  0x01068389  f0660039                lock add byte ptr [ecx], bh             
  0x0106838D  06                      push     es                             
  0x0106838E  0000                    add      byte ptr [eax], al             
  0x01068390  00ee                    add      dh, ch                         
  0x01068392  7000                    jo       0x1068394                      
                                        ; XREF: 0x01068392 (cond_jump)
  0x01068394  001c23                  add      byte ptr [ebx], bl             
  0x01068397  0000                    add      byte ptr [eax], al             
  0x0106839A  50                      push     eax                            
  0x0106839B  003c06                  add      byte ptr [esi + eax], bh       
  0x0106839E  0000                    add      byte ptr [eax], al             
  0x010683A0  0a00                    or       al, byte ptr [eax]             
  0x010683A2  0000                    add      byte ptr [eax], al             
  0x010683A4  001e                    add      byte ptr [esi], bl             
  0x010683A6  2100                    and      dword ptr [eax], eax           
  0x010683A8  00f4                    add      ah, dh                         
  0x010683AA  7200                    jb       0x10683ac                      
                                        ; XREF: 0x010683AA (cond_jump)
  0x010683AC  0400                    add      al, 0                          
  0x010683AE  0000                    add      byte ptr [eax], al             
  0x010683B0  80f00b                  xor      al, 0xb                        
  0x010683B3  00ca                    add      dl, cl                         
  0x010683B5  05000000f4              add      eax, 0xf4000000                
  0x010683BA  61                      popal                                   
  0x010683BB  004d06                  add      byte ptr [ebp + 6], cl         
  0x010683BE  0000                    add      byte ptr [eax], al             
  0x010683C0  00f0                    add      al, dh                         
  0x010683C2  65008b06000000          add      byte ptr gs:[ebx + 6], cl      
  0x010683C9  f4                      hlt                                     
  0x010683CA  6200                    bound    eax, qword ptr [eax]           
  0x010683CC  7906                    jns      0x10683d4                      
  0x010683CE  0000                    add      byte ptr [eax], al             
  0x010683D0  00f0                    add      al, dh                         
  0x010683D2  660038                  add      byte ptr [eax], bh             
  0x010683D5  06                      push     es                             
  0x010683D6  0000                    add      byte ptr [eax], al             
  0x010683D8  0002                    add      byte ptr [edx], al             
  0x010683DA  3e0000                  add      byte ptr ds:[eax], al          
  0x010683DD  ee                      out      dx, al                         
  0x010683DE  60                      pushal                                  
  0x010683DF  0000                    add      byte ptr [eax], al             
  0x010683E1  1422                    adc      al, 0x22                       
  0x010683E3  0000                    add      byte ptr [eax], al             
  0x010683E5  f0660039                lock add byte ptr [ecx], bh             
  0x010683E9  06                      push     es                             
  0x010683EA  0000                    add      byte ptr [eax], al             
  0x010683EC  00ee                    add      dh, ch                         
  0x010683EE  7000                    jo       0x10683f0                      
                                        ; XREF: 0x010683EE (cond_jump)
  0x010683F0  001c23                  add      byte ptr [ebx], bl             
  0x010683F3  0000                    add      byte ptr [eax], al             
  0x010683F6  50                      push     eax                            
  0x010683F7  003c06                  add      byte ptr [esi + eax], bh       
  0x010683FA  0000                    add      byte ptr [eax], al             
  0x010683FC  0a00                    or       al, byte ptr [eax]             
  0x010683FE  0000                    add      byte ptr [eax], al             
  0x01068400  001e                    add      byte ptr [esi], bl             
  0x01068402  2100                    and      dword ptr [eax], eax           
  0x01068404  00f4                    add      ah, dh                         
  0x01068406  7200                    jb       0x1068408                      
                                        ; XREF: 0x01068406 (cond_jump)
  0x01068408  0400                    add      al, 0                          
  0x0106840A  0000                    add      byte ptr [eax], al             
  0x0106840C  80f00b                  xor      al, 0xb                        
  0x0106840F  00ca                    add      dl, cl                         
  0x01068411  05000000f4              add      eax, 0xf4000000                
  0x01068416  61                      popal                                   
  0x01068417  005d06                  add      byte ptr [ebp + 6], bl         
  0x0106841A  0000                    add      byte ptr [eax], al             
  0x0106841C  00f0                    add      al, dh                         
  0x0106841E  65008c06000000f4        add      byte ptr gs:[esi + eax - 0xc000000], cl 
  0x01068426  6200                    bound    eax, qword ptr [eax]           
  0x01068428  8106000000f0            add      dword ptr [esi], 0xf0000000    
  0x0106842E  660033                  add      byte ptr [ebx], dh             
  0x01068431  06                      push     es                             
  0x01068432  0000                    add      byte ptr [eax], al             
  0x01068434  0003                    add      byte ptr [ebx], al             
  0x01068436  3e0000                  add      byte ptr ds:[eax], al          
  0x01068439  ee                      out      dx, al                         
  0x0106843A  60                      pushal                                  
  0x0106843B  0000                    add      byte ptr [eax], al             
  0x0106843D  1422                    adc      al, 0x22                       
  0x0106843F  0000                    add      byte ptr [eax], al             
  0x01068441  f066003406              lock add byte ptr [esi + eax], dh       
  0x01068446  0000                    add      byte ptr [eax], al             
  0x01068448  00ee                    add      dh, ch                         
  0x0106844A  7000                    jo       0x106844c                      
                                        ; XREF: 0x0106844A (cond_jump)
  0x0106844C  001c23                  add      byte ptr [ebx], bl             
  0x0106844F  0000                    add      byte ptr [eax], al             
  0x01068452  50                      push     eax                            
  0x01068453  003c06                  add      byte ptr [esi + eax], bh       
  0x01068456  0000                    add      byte ptr [eax], al             
  0x01068458  0a00                    or       al, byte ptr [eax]             
  0x0106845A  0000                    add      byte ptr [eax], al             
  0x0106845C  001e                    add      byte ptr [esi], bl             
  0x0106845E  2100                    and      dword ptr [eax], eax           
  0x01068460  00f4                    add      ah, dh                         
  0x01068462  7200                    jb       0x1068464                      
                                        ; XREF: 0x01068462 (cond_jump)
  0x01068464  0500000080              add      eax, 0x80000000                
  0x01068469  f00b00                  lock or  eax, dword ptr [eax]           
  0x0106846C  ca0500                  retf     5                              
  0x0106846F  0000                    add      byte ptr [eax], al             
  0x01068471  f0660038                lock add byte ptr [eax], bh             
  0x01068475  06                      push     es                             
  0x01068476  0000                    add      byte ptr [eax], al             
  0x01068478  0000                    add      byte ptr [eax], al             
  0x0106847A  3e0000                  add      byte ptr ds:[eax], al          
  0x0106847D  ee                      out      dx, al                         
  0x0106847E  60                      pushal                                  
  0x0106847F  0000                    add      byte ptr [eax], al             
  0x01068481  023e                    add      bh, byte ptr [esi]             
  0x01068483  0000                    add      byte ptr [eax], al             
  0x01068485  ee                      out      dx, al                         
  0x01068486  61                      popal                                   
  0x01068487  0000                    add      byte ptr [eax], al             
  0x01068489  f0660033                lock add byte ptr [ebx], dh             
  0x0106848D  06                      push     es                             
  0x0106848E  0000                    add      byte ptr [eax], al             
  0x01068490  0003                    add      byte ptr [ebx], al             
  0x01068492  3e0000                  add      byte ptr ds:[eax], al          
  0x01068495  ee                      out      dx, al                         
  0x01068496  6200                    bound    eax, qword ptr [eax]           
  0x01068498  00f0                    add      al, dh                         
  0x0106849A  660039                  add      byte ptr [ecx], bh             
  0x0106849D  06                      push     es                             
  0x0106849E  0000                    add      byte ptr [eax], al             
  0x010684A0  0000                    add      byte ptr [eax], al             
  0x010684A2  3e0000                  add      byte ptr ds:[eax], al          
  0x010684A5  ee                      out      dx, al                         
  0x010684A6  7000                    jo       0x10684a8                      
                                        ; XREF: 0x010684A6 (cond_jump)
  0x010684A8  0002                    add      byte ptr [edx], al             
  0x010684AA  3e0000                  add      byte ptr ds:[eax], al          
  0x010684AD  ee                      out      dx, al                         
  0x010684AE  7100                    jno      0x10684b0                      
                                        ; XREF: 0x010684AE (cond_jump)
  0x010684B0  00f0                    add      al, dh                         
  0x010684B2  66003406                add      byte ptr [esi + eax], dh       
  0x010684B6  0000                    add      byte ptr [eax], al             
  0x010684B8  0003                    add      byte ptr [ebx], al             
  0x010684BA  3e0000                  add      byte ptr ds:[eax], al          
  0x010684BD  ee                      out      dx, al                         
  0x010684BE  7200                    jb       0x10684c0                      
                                        ; XREF: 0x010684BE (cond_jump)
  0x010684C0  00f4                    add      ah, dh                         
  0x010684C2  45                      inc      ebp                            
  0x010684C3  007a82                  add      byte ptr [edx - 0x7e], bh      
  0x010684C6  5a                      pop      edx                            
  0x010684C7  0000                    add      byte ptr [eax], al             
  0x010684C9  f064003c06              lock add byte ptr fs:[esi + eax], bh    
  0x010684CE  0000                    add      byte ptr [eax], al             
  0x010684D0  00d4                    add      ah, dl                         
  0x010684D2  06                      push     es                             
  0x010684D3  000a                    add      byte ptr [edx], cl             
  0x010684D5  05000000ca              add      eax, 0xca000000                
  0x010684DA  44                      inc      esp                            
  0x010684DB  0000                    add      byte ptr [eax], al             
  0x010684DD  e056                    loopne   0x1068535                      
  0x010684DF  00a3e15700af            add      byte ptr [ebx - 0x50ffa81f], ah 
  0x010684E5  48                      dec      eax                            
  0x010684E6  56                      push     esi                            
  0x010684E7  0000                    add      byte ptr [eax], al             
  0x010684E9  49                      dec      ecx                            
  0x010684EA  57                      push     edi                            
  0x010684EB  0080100d00b4            add      byte ptr [eax - 0x4bfff2f0], al 
  0x010684F1  0000                    add      byte ptr [eax], al             
  0x010684F3  000c00                  add      byte ptr [eax + eax], cl       
  0x010684F6  0000                    add      byte ptr [eax], al             
  0x010684F8  005820                  add      byte ptr [eax + 0x20], bl      
  0x010684FB  0000                    add      byte ptr [eax], al             
  0x010684FD  d8440000                fadd     dword ptr [eax + eax]          
  0x01068501  7044                    jo       0x1068547                      
  0x01068503  0033                    add      byte ptr [ebx], dh             
  0x01068505  06                      push     es                             
  0x01068506  0000                    add      byte ptr [eax], al             
  0x01068508  00d8                    add      al, bl                         
  0x0106850A  44                      inc      esp                            
  0x0106850B  0000                    add      byte ptr [eax], al             
  0x0106850D  7044                    jo       0x1068553                      
  0x0106850F  003406                  add      byte ptr [esi + eax], dh       
  0x01068512  0000                    add      byte ptr [eax], al             
  0x01068514  00d8                    add      al, bl                         
  0x01068516  44                      inc      esp                            
  0x01068517  0000                    add      byte ptr [eax], al             
  0x01068519  7044                    jo       0x106855f                      
  0x0106851B  003506000000            add      byte ptr [6], dh               
  0x01068521  d85700                  fcom     dword ptr [edi]                
  0x01068524  90                      nop                                     
  0x01068525  180c00                  sbb      byte ptr [eax + eax], cl       
  0x01068528  27                      daa                                     
  0x01068529  1000                    adc      byte ptr [eax], al             
  0x0106852B  0000                    add      byte ptr [eax], al             
  0x0106852D  7050                    jo       0x106857f                      
  0x0106852F  0036                    add      byte ptr [esi], dh             
  0x01068531  06                      push     es                             
  0x01068532  0000                    add      byte ptr [eax], al             
  0x01068534  90                      nop                                     
                                        ; XREF: 0x010684DD (cond_jump)
  0x01068535  180c00                  sbb      byte ptr [eax + eax], cl       
  0x01068538  1910                    sbb      dword ptr [eax], edx           
  0x0106853A  0000                    add      byte ptr [eax], al             
  0x0106853C  007050                  add      byte ptr [eax + 0x50], dh      
  0x0106853F  0037                    add      byte ptr [edi], dh             
  0x01068541  06                      push     es                             
  0x01068542  0000                    add      byte ptr [eax], al             
  0x01068544  00d8                    add      al, bl                         
  0x01068546  44                      inc      esp                            
                                        ; XREF: 0x01068501 (cond_jump)
  0x01068547  0000                    add      byte ptr [eax], al             
  0x01068549  7044                    jo       0x106858f                      
  0x0106854B  0038                    add      byte ptr [eax], bh             
  0x0106854D  06                      push     es                             
  0x0106854E  0000                    add      byte ptr [eax], al             
  0x01068550  00d8                    add      al, bl                         
  0x01068552  44                      inc      esp                            
                                        ; XREF: 0x0106850D (cond_jump)
  0x01068553  0000                    add      byte ptr [eax], al             
  0x01068555  7044                    jo       0x106859b                      
  0x01068557  0039                    add      byte ptr [ecx], bh             
  0x01068559  06                      push     es                             
  0x0106855A  0000                    add      byte ptr [eax], al             
  0x0106855C  00d8                    add      al, bl                         
  0x0106855E  44                      inc      esp                            
                                        ; XREF: 0x01068519 (cond_jump)
  0x0106855F  0000                    add      byte ptr [eax], al             
  0x01068561  7044                    jo       0x10685a7                      
  0x01068563  003a                    add      byte ptr [edx], bh             
  0x01068565  06                      push     es                             
  0x01068566  0000                    add      byte ptr [eax], al             
  0x01068568  00d8                    add      al, bl                         
  0x0106856A  57                      push     edi                            
  0x0106856B  0090180c0024            add      byte ptr [eax + 0x24000c18], dl 
  0x01068571  2000                    and      byte ptr [eax], al             
  0x01068573  0000                    add      byte ptr [eax], al             
  0x01068575  7050                    jo       0x10685c7                      
  0x01068577  003b                    add      byte ptr [ebx], bh             
  0x01068579  06                      push     es                             
  0x0106857A  0000                    add      byte ptr [eax], al             
  0x0106857C  00d8                    add      al, bl                         
  0x0106857E  44                      inc      esp                            
                                        ; XREF: 0x0106852D (cond_jump)
  0x0106857F  0000                    add      byte ptr [eax], al             
  0x01068581  7044                    jo       0x10685c7                      
  0x01068583  003c06                  add      byte ptr [esi + eax], bh       
  0x01068586  0000                    add      byte ptr [eax], al             
  0x01068588  0c00                    or       al, 0                          
  0x0106858A  0000                    add      byte ptr [eax], al             
  0x0106858C  8d95c0000000            lea      edx, [ebp + 0xc0]              
  0x01068592  0000                    add      byte ptr [eax], al             
  0x01068594  e5d4                    in       eax, 0xd4                      
  0x01068596  7e00                    jle      0x1068598                      
                                        ; XREF: 0x01068596 (cond_jump)
  0x01068598  0000                    add      byte ptr [eax], al             
  0x0106859A  c00000                  rol      byte ptr [eax], 0              
  0x0106859D  0000                    add      byte ptr [eax], al             
  0x0106859F  004ae2                  add      byte ptr [edx - 0x1e], cl      
  0x010685A2  4f                      dec      edi                            
  0x010685A3  00cc                    add      ah, cl                         
  0x010685A5  673f                    aas                                     
                                        ; XREF: 0x01068561 (cond_jump)
  0x010685A7  00cc                    add      ah, cl                         
  0x010685A9  673f                    aas                                     
  0x010685AB  004ae2                  add      byte ptr [edx - 0x1e], cl      
  0x010685AE  4f                      dec      edi                            
  0x010685AF  00ff                    add      bh, bh                         
  0x010685B2  7f00                    jg       0x10685b4                      
                                        ; XREF: 0x010685B2 (cond_jump)
  0x010685B4  e85b850038              call     0x39070b14                     
  0x010685B9  667500                  jne      0x10685bc                      
                                        ; XREF: 0x010685B9 (cond_jump)
  0x010685BC  386675                  cmp      byte ptr [esi + 0x75], ah      
  0x010685BF  00e8                    add      al, ch                         
  0x010685C1  5b                      pop      ebx                            
  0x010685C2  8500                    test     dword ptr [eax], eax           
  0x010685C6  7f00                    jg       0x10685c8                      
                                        ; XREF: 0x010685C6 (cond_jump)
  0x010685C8  92                      xchg     edx, eax                       
  0x010685C9  1f                      pop      ds                             
  0x010685CA  ea004b40e2004b          ljmp     0x4b00:0xe2404b00              
  0x010685D1  40                      inc      eax                            
  0x010685D2  e200                    loop     0x10685d4                      
                                        ; XREF: 0x010685D2 (cond_jump)
  0x010685D4  92                      xchg     edx, eax                       
  0x010685D5  1f                      pop      ds                             
  0x010685D6  ea00ffff7f001b          ljmp     0x1b00:0x7fffff00              
  0x010685DD  2b810085ac7d            sub      eax, dword ptr [ecx + 0x7dac8500] 
  0x010685E3  0094d57e006c2a          add      byte ptr [ebp + edx*8 + 0x2a6c007e], dl 
  0x010685EA  810094d57e00            add      dword ptr [eax], 0x7ed594      
  0x010685F0  4a                      dec      edx                            
  0x010685F1  e24f                    loop     0x1068642                      
  0x010685F3  00cc                    add      ah, cl                         
  0x010685F5  673f                    aas                                     
  0x010685F7  0026                    add      byte ptr [esi], ah             
  0x010685F9  94                      xchg     esp, eax                       
  0x010685FA  57                      push     edi                            
  0x010685FB  007fff                  add      byte ptr [edi - 1], bh         
  0x010685FE  55                      push     ebp                            
  0x010685FF  0026                    add      byte ptr [esi], ah             
  0x01068601  94                      xchg     esp, eax                       
  0x01068602  57                      push     edi                            
  0x01068603  004ae2                  add      byte ptr [edx - 0x1e], cl      
  0x01068606  4f                      dec      edi                            
  0x01068607  00cc                    add      ah, cl                         
  0x01068609  673f                    aas                                     
  0x0106860B  0026                    add      byte ptr [esi], ah             
  0x0106860D  94                      xchg     esp, eax                       
  0x0106860E  57                      push     edi                            
  0x0106860F  007fff                  add      byte ptr [edi - 1], bh         
  0x01068612  55                      push     ebp                            
  0x01068613  0026                    add      byte ptr [esi], ah             
  0x01068615  94                      xchg     esp, eax                       
  0x01068616  57                      push     edi                            
  0x01068617  0022                    add      byte ptr [edx], ah             
  0x01068619  3e82006d                add      byte ptr ds:[eax], 0x6d        
  0x0106861D  877b00                  xchg     dword ptr [ebx], edi           
  0x01068620  6d                      insd     dword ptr es:[edi], dx         
  0x01068621  877b00                  xchg     dword ptr [ebx], edi           
  0x01068624  223e                    and      bh, byte ptr [esi]             
  0x01068626  8200ff                  add      byte ptr [eax], 0xff           
  0x0106862A  7f00                    jg       0x106862c                      
                                        ; XREF: 0x0106862A (cond_jump)
  0x0106862C  5e                      pop      esi                            
  0x0106862D  3bb2004ff727            cmp      esi, dword ptr [edx + 0x27f74f00] 
  0x01068633  004ff7                  add      byte ptr [edi - 9], cl         
  0x01068636  27                      daa                                     
  0x01068637  005e3b                  add      byte ptr [esi + 0x3b], bl      
  0x0106863A  b200                    mov      dl, 0                          
  0x0106863E  7f00                    jg       0x1068640                      
                                        ; XREF: 0x0106863E (cond_jump)
  0x01068640  7489                    je       0x10685cb                      
                                        ; XREF: 0x010685F1 (cond_jump)
  0x01068642  c00000                  rol      byte ptr [eax], 0              
  0x01068645  0000                    add      byte ptr [eax], al             
  0x01068647  0019                    add      byte ptr [ecx], bl             
  0x01068649  ed                      in       eax, dx                        
  0x0106864A  7e00                    jle      0x106864c                      
                                        ; XREF: 0x0106864A (cond_jump)
  0x0106864C  0000                    add      byte ptr [eax], al             
  0x0106864E  c00000                  rol      byte ptr [eax], 0              
  0x01068651  0000                    add      byte ptr [eax], al             
  0x01068653  00f8                    add      al, bh                         
  0x01068655  2a4600                  sub      al, byte ptr [esi]             
  0x01068658  208637002086            and      byte ptr [esi - 0x79dfffc9], al 
  0x0106865E  37                      aaa                                     
  0x0106865F  00f8                    add      al, bh                         
  0x01068661  2a4600                  sub      al, byte ptr [esi]             
  0x01068666  7f00                    jg       0x1068668                      
                                        ; XREF: 0x01068666 (cond_jump)
  0x01068668  9e                      sahf                                    
  0x01068669  ef                      out      dx, eax                        
  0x0106866A  8400                    test     byte ptr [eax], al             
  0x0106866C  353a760035              xor      eax, 0x3500763a                
  0x01068671  3a7600                  cmp      dh, byte ptr [esi]             
  0x01068674  9e                      sahf                                    
  0x01068675  ef                      out      dx, eax                        
  0x01068676  8400                    test     byte ptr [eax], al             
  0x0106867A  7f00                    jg       0x106867c                      
                                        ; XREF: 0x0106867A (cond_jump)
  0x0106867C  fe48e6                  dec      byte ptr [eax - 0x1a]          
  0x0106867F  008ab7e4008a            add      byte ptr [edx - 0x75ff1b49], cl 
  0x01068685  b7e4                    mov      bh, 0xe4                       
  0x01068687  00fe                    add      dh, bh                         
  0x01068689  48                      dec      eax                            
  0x0106868A  e600                    out      0, al                          
  0x0106868E  7f00                    jg       0x1068690                      
                                        ; XREF: 0x0106868E (cond_jump)
  0x01068690  e712                    out      0x12, eax                      
  0x01068692  81007fdc7d00            add      dword ptr [eax], 0x7ddc7f      
  0x01068698  ac                      lodsb    al, byte ptr [esi]             
  0x01068699  ed                      in       eax, dx                        
  0x0106869A  7e00                    jle      0x106869c                      
                                        ; XREF: 0x0106869A (cond_jump)
  0x0106869C  54                      push     esp                            
  0x0106869D  128100aced7e            adc      al, byte ptr [ecx + 0x7eedac00] 
  0x010686A3  00f8                    add      al, bh                         
  0x010686A5  2a4600                  sub      al, byte ptr [esi]             
  0x010686A8  20863700f31d            and      byte ptr [esi + 0x1df30037], al 
  0x010686AE  51                      push     ecx                            
  0x010686AF  0090f54e00f3            add      byte ptr [eax - 0xcffb10b], dl 
  0x010686B5  1d5100f82a              sbb      eax, 0x2af80051                
  0x010686BA  46                      inc      esi                            
  0x010686BB  0020                    add      byte ptr [eax], ah             
  0x010686BD  8637                    xchg     byte ptr [edi], dh             
  0x010686BF  00f3                    add      bl, dh                         
  0x010686C1  1d510090f5              sbb      eax, 0xf5900051                
  0x010686C6  4e                      dec      esi                            
  0x010686C7  00f3                    add      bl, dh                         
  0x010686C9  1d51001a10              sbb      eax, 0x101a0051                
  0x010686CE  8200ed                  add      byte ptr [eax], 0xed           
  0x010686D1  e27b                    loop     0x106874e                      
  0x010686D3  00ed                    add      ch, ch                         
  0x010686D5  e27b                    loop     0x1068752                      
  0x010686D7  001a                    add      byte ptr [edx], bl             
  0x010686D9  108200ffff7f            adc      byte ptr [edx + 0x7fffff00], al 
  0x010686DF  00fc                    add      ah, bh                         
  0x010686E1  2eaf                    scasd    eax, dword ptr es:[edi]        
  0x010686E3  0000                    add      byte ptr [eax], al             
  0x010686E5  782c                    js       0x1068713                      
  0x010686E7  0000                    add      byte ptr [eax], al             
  0x010686E9  782c                    js       0x1068717                      
  0x010686EB  00fc                    add      ah, bh                         
  0x010686ED  2eaf                    scasd    eax, dword ptr es:[edi]        
  0x010686EF  00ff                    add      bh, bh                         
  0x010686F2  7f00                    jg       0x10686f4                      
                                        ; XREF: 0x010686F2 (cond_jump)
  0x010686F4  13f4                    adc      esi, esp                       
  0x010686F6  61                      popal                                   
  0x010686F7  003d06000090            add      byte ptr [0x90000006], bh      
  0x010686FD  4e                      dec      esi                            
  0x010686FE  06                      push     es                             
  0x010686FF  0002                    add      byte ptr [edx], al             
  0x01068701  0000                    add      byte ptr [eax], al             
  0x01068703  0000                    add      byte ptr [eax], al             
  0x01068705  59                      pop      ecx                            
  0x01068706  56                      push     esi                            
  0x01068707  000c00                  add      byte ptr [eax + eax], cl       
  0x0106870A  0000                    add      byte ptr [eax], al             
  0x0106870C  00f4                    add      ah, dh                         
  0x0106870E  60                      pushal                                  
  0x0106870F  0033                    add      byte ptr [ebx], dh             
  0x01068711  05000000f4              add      eax, 0xf4000000                
  0x01068716  61                      popal                                   
                                        ; XREF: 0x010686E9 (cond_jump)
  0x01068717  0000                    add      byte ptr [eax], al             
  0x01068719  0000                    add      byte ptr [eax], al             
  0x0106871B  00905a060003            add      byte ptr [eax + 0x300065a], dl 
  0x01068721  0000                    add      byte ptr [eax], al             
  0x01068723  0084d807000059          add      byte ptr [eax + ebx*8 + 0x59000007], al 
  0x0106872A  4c                      dec      esp                            
  0x0106872B  0000                    add      byte ptr [eax], al             
  0x0106872E  56                      push     esi                            
  0x0106872F  003b                    add      byte ptr [ebx], bh             
  0x01068731  06                      push     es                             
  0x01068732  0000                    add      byte ptr [eax], al             
  0x01068734  0000                    add      byte ptr [eax], al             
  0x01068736  2400                    and      al, 0                          
  0x01068738  00f4                    add      ah, dh                         
  0x0106873A  60                      pushal                                  
  0x0106873B  002d00000045            add      byte ptr [0x45000000], ch      
  0x01068741  f4                      hlt                                     
  0x01068742  61                      popal                                   
  0x01068743  004100                  add      byte ptr [ecx], al             
  0x01068746  0000                    add      byte ptr [eax], al             
  0x01068748  05a4050000              add      eax, 0x5a4                     
  0x0106874D  f4                      hlt                                     
                                        ; XREF: 0x010686D1 (cond_jump)
  0x0106874E  60                      pushal                                  
  0x0106874F  0000                    add      byte ptr [eax], al             
  0x01068751  0000                    add      byte ptr [eax], al             
  0x01068753  0000                    add      byte ptr [eax], al             
  0x01068755  f4                      hlt                                     
  0x01068756  61                      popal                                   
  0x01068757  001400                  add      byte ptr [eax + eax], dl       
  0x0106875A  0000                    add      byte ptr [eax], al             
  0x0106875C  007060                  add      byte ptr [eax + 0x60], dh      
  0x0106875F  008b06000000            add      byte ptr [ebx + 6], cl         
  0x01068765  7061                    jo       0x10687c8                      
  0x01068767  008c0600000c00          add      byte ptr [esi + eax + 0xc0000], cl 
  0x0106876E  0000                    add      byte ptr [eax], al             
  0x01068770  00f4                    add      ah, dh                         
  0x01068772  56                      push     esi                            
  0x01068773  0011                    add      byte ptr [ecx], dl             
  0x01068775  0000                    add      byte ptr [eax], al             
  0x01068777  0000                    add      byte ptr [eax], al             
  0x01068779  f4                      hlt                                     
  0x0106877A  57                      push     edi                            
  0x0106877B  0000                    add      byte ptr [eax], al             
  0x0106877D  0000                    add      byte ptr [eax], al             
  0x0106877F  0000                    add      byte ptr [eax], al             
  0x01068781  4e                      dec      esi                            
  0x01068782  3800                    cmp      byte ptr [eax], al             
  0x01068784  80f00b                  xor      al, 0xb                        
  0x01068787  00800100000c            add      byte ptr [eax + 0xc000001], al 
  0x0106878D  0000                    add      byte ptr [eax], al             
  0x0106878F  0000                    add      byte ptr [eax], al             
  0x01068791  f4                      hlt                                     
  0x01068792  56                      push     esi                            
  0x01068793  0011                    add      byte ptr [ecx], dl             
  0x01068795  0000                    add      byte ptr [eax], al             
  0x01068797  0000                    add      byte ptr [eax], al             
  0x01068799  f4                      hlt                                     
  0x0106879A  57                      push     edi                            
  0x0106879B  0001                    add      byte ptr [ecx], al             
  0x0106879D  0000                    add      byte ptr [eax], al             
  0x0106879F  0000                    add      byte ptr [eax], al             
  0x010687A1  f4                      hlt                                     
  0x010687A2  60                      pushal                                  
  0x010687A3  003d06000000            add      byte ptr [6], bh               
  0x010687A9  4e                      dec      esi                            
  0x010687AA  3800                    cmp      byte ptr [eax], al             
  0x010687AC  0000                    add      byte ptr [eax], al             
  0x010687AE  3900                    cmp      dword ptr [eax], eax           
  0x010687B0  80f00b                  xor      al, 0xb                        
  0x010687B3  00800100000c            add      byte ptr [eax + 0xc000001], al 
  0x010687B9  0000                    add      byte ptr [eax], al             
  0x010687BB  0000                    add      byte ptr [eax], al             
  0x010687BD  f4                      hlt                                     
  0x010687BE  56                      push     esi                            
  0x010687BF  0011                    add      byte ptr [ecx], dl             
  0x010687C1  0000                    add      byte ptr [eax], al             
  0x010687C3  0000                    add      byte ptr [eax], al             
  0x010687C5  f4                      hlt                                     
  0x010687C6  57                      push     edi                            
  0x010687C7  0002                    add      byte ptr [edx], al             
  0x010687C9  0000                    add      byte ptr [eax], al             
  0x010687CB  0000                    add      byte ptr [eax], al             
  0x010687CD  f4                      hlt                                     
  0x010687CE  60                      pushal                                  
  0x010687CF  003d06000000            add      byte ptr [6], bh               
  0x010687D5  4e                      dec      esi                            
  0x010687D6  3800                    cmp      byte ptr [eax], al             
  0x010687D8  0000                    add      byte ptr [eax], al             
  0x010687DA  3900                    cmp      dword ptr [eax], eax           
  0x010687DC  80f00b                  xor      al, 0xb                        
  0x010687DF  00800100000c            add      byte ptr [eax + 0xc000001], al 
  0x010687E5  0000                    add      byte ptr [eax], al             
  0x010687E7  0000                    add      byte ptr [eax], al             
  0x010687E9  f4                      hlt                                     
  0x010687EA  7100                    jno      0x10687ec                      
  0x010687EE  ff00                    inc      dword ptr [eax]                
  0x010687F0  00f4                    add      ah, dh                         
  0x010687F2  7500                    jne      0x10687f4                      
                                        ; XREF: 0x010687F2 (cond_jump)
  0x010687F4  fc                      cld                                     
  0x010687F6  ff00                    inc      dword ptr [eax]                
  0x010687F8  0096220010da            add      byte ptr [esi - 0x25efffde], dl 
  0x010687FE  06                      push     es                             
  0x010687FF  0021                    add      byte ptr [ecx], ah             
  0x01068801  0000                    add      byte ptr [eax], al             
  0x01068803  0000                    add      byte ptr [eax], al             
  0x01068805  da5700                  ficom    dword ptr [edi]                
  0x01068808  00d2                    add      dl, dl                         
  0x0106880A  51                      push     ecx                            
  0x0106880B  0000                    add      byte ptr [eax], al             
  0x0106880D  b9f00010de              mov      ecx, 0xde1000f0                
  0x01068812  06                      push     es                             
  0x01068813  000b                    add      byte ptr [ebx], cl             
  0x01068815  0000                    add      byte ptr [eax], al             
  0x01068817  00d4                    add      ah, dl                         
  0x01068819  e145                    loope    0x1068860                      
  0x0106881B  00d6                    add      dh, dl                         
  0x0106881D  39f0                    cmp      eax, esi                       
  0x0106881F  00e6                    add      dh, ah                         
  0x01068821  a8f0                    test     al, 0xf0                       
  0x01068823  00d2                    add      dl, dl                         
  0x01068825  a1f400e259              mov      eax, dword ptr [0x59e200f4]    
  0x0106882A  44                      inc      esp                            
  0x0106882B  00e2                    add      dl, ah                         
  0x0106882D  a1d000d249              mov      eax, dword ptr [0x49d200d0]    
  0x01068832  45                      inc      ebp                            
  0x01068833  0010                    add      byte ptr [eax], dl             
  0x01068835  0020                    add      byte ptr [eax], ah             
  0x01068837  0009                    add      byte ptr [ecx], cl             
  0x01068839  dd10                    fst      qword ptr [eax]                
  0x0106883B  004c4c44                add      byte ptr [esp + ecx*2 + 0x44], cl 
  0x0106883F  00d4                    add      ah, dl                         
  0x01068841  e145                    loope    0x1068888                      
  0x01068843  00d6                    add      dh, dl                         
  0x01068845  39f0                    cmp      eax, esi                       
  0x01068847  00e6                    add      dh, ah                         
  0x01068849  a8f0                    test     al, 0xf0                       
  0x0106884B  00d2                    add      dl, dl                         
  0x0106884D  a1f400e259              mov      eax, dword ptr [0x59e200f4]    
  0x01068852  44                      inc      esp                            
  0x01068853  00e2                    add      dl, ah                         
  0x01068855  a1f000d259              mov      eax, dword ptr [0x59d200f0]    
  0x0106885A  45                      inc      ebp                            
  0x0106885B  0010                    add      byte ptr [eax], dl             
  0x0106885D  0020                    add      byte ptr [eax], ah             
  0x0106885F  0009                    add      byte ptr [ecx], cl             
  0x01068861  c421                    les      esp, ptr [ecx]                 
  0x01068863  004c4c44                add      byte ptr [esp + ecx*2 + 0x44], cl 
  0x01068867  0084f10300005a          add      byte ptr [ecx + esi*8 + 0x5a000003], al 
  0x0106886E  55                      push     ebp                            
  0x0106886F  0000                    add      byte ptr [eax], al             
  0x01068871  5a                      pop      edx                            
  0x01068872  51                      push     ecx                            
  0x01068873  0000                    add      byte ptr [eax], al             
  0x01068875  d422                    aam      0x22                           
  0x01068877  0000                    add      byte ptr [eax], al             
  0x01068879  90                      nop                                     
  0x0106887A  2200                    and      al, byte ptr [eax]             
  0x0106887C  00982300a460            add      byte ptr [eax + 0x60a40023], bl 
  0x01068882  0400                    add      al, 0                          
  0x01068884  0c00                    or       al, 0                          
  0x01068886  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01068841 (cond_jump)
  0x01068888  40                      inc      eax                            
  0x01068889  1bd0                    sbb      edx, eax                       
  0x0106888B  006208                  add      byte ptr [edx + 8], ah         
  0x0106888E  0000                    add      byte ptr [eax], al             
  0x01068890  7201                    jb       0x1068893                      
  0x01068892  0200                    add      al, byte ptr [eax]             
  0x01068894  56                      push     esi                            
  0x01068895  6b680000                imul     ebp, dword ptr [eax], 0        
  0x01068899  7044                    jo       0x10688df                      
  0x0106889B  006509                  add      byte ptr [ebp + 9], ah         
  0x0106889E  0000                    add      byte ptr [eax], al             
  0x010688A0  007060                  add      byte ptr [eax + 0x60], dh      
  0x010688A3  006809                  add      byte ptr [eax + 9], ch         
  0x010688A6  0000                    add      byte ptr [eax], al             
  0x010688A8  0b00                    or       eax, dword ptr [eax]           
  0x010688AA  2000                    and      byte ptr [eax], al             
  0x010688AC  07                      pop      es                             
  0x010688AD  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010688AE  0500df0805              add      eax, 0x508df00                 
  0x010688B3  0080100d00ce            add      byte ptr [eax - 0x31fff2f0], al 
  0x010688B9  07                      pop      es                             
  0x010688BA  0000                    add      byte ptr [eax], al             
  0x010688BC  80100d                  adc      byte ptr [eax], 0xd            
  0x010688BF  000b                    add      byte ptr [ebx], cl             
  0x010688C1  0800                    or       byte ptr [eax], al             
  0x010688C3  00050c050080            add      byte ptr [0x8000050c], al      
  0x010688C9  100d00d40700            adc      byte ptr [0x7d400], cl         
  0x010688CF  0080100d00f8            add      byte ptr [eax - 0x7fff2f0], al 
  0x010688D5  07                      pop      es                             
  0x010688D6  0000                    add      byte ptr [eax], al             
  0x010688D9  08050000f062            or       byte ptr [0x62f00000], al      
                                        ; XREF: 0x01068899 (cond_jump)
  0x010688DF  006809                  add      byte ptr [eax + 9], ch         
  0x010688E2  0000                    add      byte ptr [eax], al             
  0x010688E4  00f4                    add      ah, dh                         
  0x010688E6  60                      pushal                                  
  0x010688E7  00c2                    add      dl, al                         
  0x010688E9  0f0000                  sldt     word ptr [eax]                 
  0x010688EC  d8720a                  fdiv     dword ptr [edx + 0xa]          
  0x010688EF  000500000000            add      byte ptr [0], al               
  0x010688F5  002400                  add      byte ptr [eax + eax], ah       
  0x010688F8  007044                  add      byte ptr [eax + 0x44], dh      
  0x010688FB  006609                  add      byte ptr [esi + 9], ah         
  0x010688FE  0000                    add      byte ptr [eax], al             
  0x01068900  00e8                    add      al, ch                         
  0x01068902  5e                      pop      esi                            
  0x01068903  009f1a02000b            add      byte ptr [edi + 0xb00021a], bl 
  0x01068909  0020                    add      byte ptr [eax], ah             
  0x0106890B  0002                    add      byte ptr [edx], al             
  0x0106890D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106890E  0500804101              add      eax, 0x1418000                 
  0x01068913  0000                    add      byte ptr [eax], al             
  0x01068915  7054                    jo       0x106896b                      
  0x01068917  006709                  add      byte ptr [edi + 9], ah         
  0x0106891A  0000                    add      byte ptr [eax], al             
  0x0106891C  00f0                    add      al, dh                         
  0x0106891E  44                      inc      esp                            
  0x0106891F  006609                  add      byte ptr [esi + 9], ah         
  0x01068922  0000                    add      byte ptr [eax], al             
  0x01068924  52                      push     edx                            
  0x01068925  090500110805            or       dword ptr [0x5081100], eax     
  0x0106892B  0000                    add      byte ptr [eax], al             
  0x0106892E  44                      inc      esp                            
  0x0106892F  006609                  add      byte ptr [esi + 9], ah         
  0x01068932  0000                    add      byte ptr [eax], al             
  0x01068934  80100d                  adc      byte ptr [eax], 0xd            
  0x01068937  0002                    add      byte ptr [edx], al             
  0x01068939  0800                    or       byte ptr [eax], al             
  0x0106893B  0000                    add      byte ptr [eax], al             
  0x0106893E  56                      push     esi                            
  0x0106893F  006609                  add      byte ptr [esi + 9], ah         
  0x01068942  0000                    add      byte ptr [eax], al             
  0x01068944  80410100                add      byte ptr [ecx + 1], 0          
  0x01068948  00f0                    add      al, dh                         
  0x0106894A  44                      inc      esp                            
  0x0106894B  006709                  add      byte ptr [edi + 9], ah         
  0x0106894E  0000                    add      byte ptr [eax], al             
  0x01068950  007054                  add      byte ptr [eax + 0x54], dh      
  0x01068953  006609                  add      byte ptr [esi + 9], ah         
  0x01068956  0000                    add      byte ptr [eax], al             
  0x01068958  45                      inc      ebp                            
  0x01068959  0020                    add      byte ptr [eax], ah             
  0x0106895B  00d0                    add      al, dl                         
  0x0106895D  97                      xchg     edi, eax                       
  0x0106895E  050080100d              add      eax, 0xd108000                 
  0x01068963  00bc0700000c00          add      byte ptr [edi + eax + 0xc0000], bh 
  0x0106896A  0000                    add      byte ptr [eax], al             
  0x0106896C  00f0                    add      al, dh                         
  0x0106896E  56                      push     esi                            
  0x0106896F  006609                  add      byte ptr [esi + 9], ah         
  0x01068972  0000                    add      byte ptr [eax], al             
  0x01068974  00f0                    add      al, dh                         
  0x01068976  44                      inc      esp                            
  0x01068977  006509                  add      byte ptr [ebp + 9], ah         
  0x0106897A  0000                    add      byte ptr [eax], al             
  0x0106897C  40                      inc      eax                            
  0x0106897D  190c00                  sbb      dword ptr [eax + eax], ecx     
  0x01068980  208000000070            and      byte ptr [eax + 0x70000000], al 
  0x01068986  54                      push     esp                            
  0x01068987  004309                  add      byte ptr [ebx + 9], al         
  0x0106898A  0000                    add      byte ptr [eax], al             
  0x0106898C  00f0                    add      al, dh                         
  0x0106898E  56                      push     esi                            
  0x0106898F  006609                  add      byte ptr [esi + 9], ah         
  0x01068992  0000                    add      byte ptr [eax], al             
  0x01068994  0300                    add      eax, dword ptr [eax]           
  0x01068996  2000                    and      byte ptr [eax], al             
  0x01068998  5a                      pop      edx                            
  0x01068999  2405                    and      al, 5                          
  0x0106899B  0000                    add      byte ptr [eax], al             
  0x0106899E  6200                    bound    eax, qword ptr [eax]           
  0x010689A0  6809000000              push     9                              
  0x010689A5  f4                      hlt                                     
  0x010689A6  60                      pushal                                  
  0x010689A7  005309                  add      byte ptr [ebx + 9], dl         
  0x010689AA  0000                    add      byte ptr [eax], al             
  0x010689AC  00f4                    add      ah, dh                         
  0x010689AE  44                      inc      esp                            
  0x010689AF  008000000090            add      byte ptr [eax - 0x70000000], al 
  0x010689B5  06                      push     es                             
  0x010689B6  06                      push     es                             
  0x010689B7  0002                    add      byte ptr [edx], al             
  0x010689B9  0000                    add      byte ptr [eax], al             
  0x010689BB  0000                    add      byte ptr [eax], al             
  0x010689BD  58                      pop      eax                            
  0x010689BE  44                      inc      esp                            
  0x010689BF  00de                    add      dh, bl                         
  0x010689C1  1202                    adc      al, byte ptr [edx]             
  0x010689C3  00941a02004019          add      byte ptr [edx + ebx + 0x19400002], dl 
  0x010689CA  0c00                    or       al, 0                          
  0x010689CC  1b10                    sbb      edx, dword ptr [eax]           
  0x010689CE  0000                    add      byte ptr [eax], al             
  0x010689D0  007054                  add      byte ptr [eax + 0x54], dh      
  0x010689D3  0036                    add      byte ptr [esi], dh             
  0x010689D5  0900                    or       dword ptr [eax], eax           
  0x010689D7  0013                    add      byte ptr [ebx], dl             
  0x010689D9  f4                      hlt                                     
  0x010689DA  44                      inc      esp                            
  0x010689DB  0012                    add      byte ptr [edx], dl             
  0x010689DD  0000                    add      byte ptr [eax], al             
  0x010689DF  004019                  add      byte ptr [eax + 0x19], al      
  0x010689E2  0c00                    or       al, 0                          
  0x010689E4  215000                  and      dword ptr [eax], edx           
  0x010689E7  0000                    add      byte ptr [eax], al             
  0x010689E9  7054                    jo       0x1068a3f                      
  0x010689EB  003a                    add      byte ptr [edx], bh             
  0x010689ED  0900                    or       dword ptr [eax], eax           
  0x010689EF  009e220200d4            add      byte ptr [esi - 0x2bfffdde], bl 
  0x010689F5  2a02                    sub      al, byte ptr [edx]             
  0x010689F7  004019                  add      byte ptr [eax + 0x19], al      
  0x010689FA  0c00                    or       al, 0                          
  0x010689FC  2110                    and      dword ptr [eax], edx           
  0x010689FE  0000                    add      byte ptr [eax], al             
  0x01068A00  94                      xchg     esp, eax                       
  0x01068A01  2a02                    sub      al, byte ptr [edx]             
  0x01068A03  004019                  add      byte ptr [eax + 0x19], al      
  0x01068A06  0c00                    or       al, 0                          
  0x01068A08  2210                    and      dl, byte ptr [eax]             
  0x01068A0A  0000                    add      byte ptr [eax], al             
  0x01068A0C  d422                    aam      0x22                           
  0x01068A0E  0200                    add      al, byte ptr [eax]             
  0x01068A10  40                      inc      eax                            
  0x01068A11  190c00                  sbb      dword ptr [eax + eax], ecx     
  0x01068A14  2310                    and      edx, dword ptr [eax]           
  0x01068A16  0000                    add      byte ptr [eax], al             
  0x01068A18  007054                  add      byte ptr [eax + 0x54], dh      
  0x01068A1B  003b                    add      byte ptr [ebx], bh             
  0x01068A1D  0900                    or       dword ptr [eax], eax           
  0x01068A1F  0013                    add      byte ptr [ebx], dl             
  0x01068A21  0020                    add      byte ptr [eax], ah             
  0x01068A23  00944a02004019          add      byte ptr [edx + ecx*2 + 0x19400002], dl 
  0x01068A2A  0c00                    or       al, 0                          
  0x01068A2C  1a20                    sbb      ah, byte ptr [eax]             
  0x01068A2E  0000                    add      byte ptr [eax], al             
  0x01068A30  007054                  add      byte ptr [eax + 0x54], dh      
  0x01068A33  004709                  add      byte ptr [edi + 9], al         
  0x01068A36  0000                    add      byte ptr [eax], al             
  0x01068A38  d41a                    aam      0x1a                           
  0x01068A3A  0200                    add      al, byte ptr [eax]             
  0x01068A3C  007044                  add      byte ptr [eax + 0x44], dh      
                                        ; XREF: 0x010689E9 (cond_jump)
  0x01068A3F  004809                  add      byte ptr [eax + 9], cl         
  0x01068A42  0000                    add      byte ptr [eax], al             
  0x01068A44  1300                    adc      eax, dword ptr [eax]           
  0x01068A46  2000                    and      byte ptr [eax], al             
  0x01068A48  94                      xchg     esp, eax                       
  0x01068A49  3a02                    cmp      al, byte ptr [edx]             
  0x01068A4B  004019                  add      byte ptr [eax + 0x19], al      
  0x01068A4E  0c00                    or       al, 0                          
  0x01068A50  1810                    sbb      byte ptr [eax], dl             
  0x01068A52  0000                    add      byte ptr [eax], al             
  0x01068A54  94                      xchg     esp, eax                       
  0x01068A55  3202                    xor      al, byte ptr [edx]             
  0x01068A57  004019                  add      byte ptr [eax + 0x19], al      
  0x01068A5A  0c00                    or       al, 0                          
  0x01068A5C  1910                    sbb      dword ptr [eax], edx           
  0x01068A5E  0000                    add      byte ptr [eax], al             
  0x01068A60  007054                  add      byte ptr [eax + 0x54], dh      
  0x01068A63  00440900                add      byte ptr [ecx + ecx], al       
  0x01068A67  00d4                    add      ah, dl                         
  0x01068A69  3a02                    cmp      al, byte ptr [edx]             
  0x01068A6B  0000                    add      byte ptr [eax], al             
  0x01068A6D  7044                    jo       0x1068ab3                      
  0x01068A6F  004609                  add      byte ptr [esi + 9], al         
  0x01068A72  0000                    add      byte ptr [eax], al             
  0x01068A74  d432                    aam      0x32                           
  0x01068A76  0200                    add      al, byte ptr [eax]             
  0x01068A78  007044                  add      byte ptr [eax + 0x44], dh      
  0x01068A7B  004509                  add      byte ptr [ebp + 9], al         
  0x01068A7E  0000                    add      byte ptr [eax], al             
  0x01068A80  13f4                    adc      esi, esp                       
  0x01068A82  60                      pushal                                  
  0x01068A83  0032                    add      byte ptr [edx], dh             
  0x01068A85  0900                    or       dword ptr [eax], eax           
  0x01068A87  0000                    add      byte ptr [eax], al             
  0x01068A89  f4                      hlt                                     
  0x01068A8A  57                      push     edi                            
  0x01068A8B  0010                    add      byte ptr [eax], dl             
  0x01068A8D  0000                    add      byte ptr [eax], al             
  0x01068A8F  0080100d00a9            add      byte ptr [eax - 0x56fff2f0], al 
  0x01068A95  0200                    add      al, byte ptr [eax]             
  0x01068A97  0000                    add      byte ptr [eax], al             
  0x01068A99  f4                      hlt                                     
  0x01068A9A  44                      inc      esp                            
  0x01068A9B  0000                    add      byte ptr [eax], al             
  0x01068A9D  0000                    add      byte ptr [eax], al             
  0x01068A9F  004500                  add      byte ptr [ebp], al             
  0x01068AA2  2000                    and      byte ptr [eax], al             
  0x01068AA4  00740500                add      byte ptr [ebp + eax], dh       
  0x01068AA8  0c00                    or       al, 0                          
  0x01068AAA  0000                    add      byte ptr [eax], al             
  0x01068AAC  1b00                    sbb      eax, dword ptr [eax]           
  0x01068AAE  3000                    xor      byte ptr [eax], al             
  0x01068AB0  80100d                  adc      byte ptr [eax], 0xd            
                                        ; XREF: 0x01068A6D (cond_jump)
  0x01068AB3  00a10200000c            add      byte ptr [ecx + 0xc000002], ah 
  0x01068AB9  0000                    add      byte ptr [eax], al             
  0x01068ABB  0000                    add      byte ptr [eax], al             
  0x01068ABD  f4                      hlt                                     
  0x01068ABE  44                      inc      esp                            
  0x01068ABF  001500000000            add      byte ptr [0], dl               
  0x01068AC5  7044                    jo       0x1068b0b                      
  0x01068AC7  0032                    add      byte ptr [edx], dh             
  0x01068AC9  0900                    or       dword ptr [eax], eax           
  0x01068ACB  0000                    add      byte ptr [eax], al             
  0x01068ACD  f4                      hlt                                     
  0x01068ACE  44                      inc      esp                            
  0x01068ACF  005309                  add      byte ptr [ebx + 9], dl         
  0x01068AD2  0000                    add      byte ptr [eax], al             
  0x01068AD4  007044                  add      byte ptr [eax + 0x44], dh      
  0x01068AD7  0033                    add      byte ptr [ebx], dh             
  0x01068AD9  0900                    or       dword ptr [eax], eax           
  0x01068ADB  0000                    add      byte ptr [eax], al             
  0x01068ADD  f4                      hlt                                     
  0x01068ADE  44                      inc      esp                            
  0x01068ADF  005f09                  add      byte ptr [edi + 9], bl         
  0x01068AE2  0000                    add      byte ptr [eax], al             
  0x01068AE4  007044                  add      byte ptr [eax + 0x44], dh      
  0x01068AE7  003409                  add      byte ptr [ecx + ecx], dh       
  0x01068AEA  0000                    add      byte ptr [eax], al             
  0x01068AEC  00f4                    add      ah, dh                         
  0x01068AEE  44                      inc      esp                            
  0x01068AEF  005909                  add      byte ptr [ecx + 9], bl         
  0x01068AF2  0000                    add      byte ptr [eax], al             
  0x01068AF4  007044                  add      byte ptr [eax + 0x44], dh      
  0x01068AF7  003509000000            add      byte ptr [9], dh               
  0x01068AFD  f4                      hlt                                     
  0x01068AFE  44                      inc      esp                            
  0x01068AFF  00ff                    add      bh, bh                         
  0x01068B01  ff00                    inc      dword ptr [eax]                
  0x01068B03  0000                    add      byte ptr [eax], al             
  0x01068B05  7044                    jo       0x1068b4b                      
  0x01068B07  0039                    add      byte ptr [ecx], bh             
  0x01068B09  0900                    or       dword ptr [eax], eax           
                                        ; XREF: 0x01068AC5 (cond_jump)
  0x01068B0B  0000                    add      byte ptr [eax], al             
  0x01068B0D  f4                      hlt                                     
  0x01068B0E  44                      inc      esp                            
  0x01068B0F  004709                  add      byte ptr [edi + 9], al         
  0x01068B12  0000                    add      byte ptr [eax], al             
  0x01068B14  007044                  add      byte ptr [eax + 0x44], dh      
  0x01068B17  003c09                  add      byte ptr [ecx + ecx], bh       
  0x01068B1A  0000                    add      byte ptr [eax], al             
  0x01068B1C  0000                    add      byte ptr [eax], al             
  0x01068B1E  2400                    and      al, 0                          
  0x01068B20  007044                  add      byte ptr [eax + 0x44], dh      
  0x01068B23  0037                    add      byte ptr [edi], dh             
  0x01068B25  0900                    or       dword ptr [eax], eax           
  0x01068B27  0000                    add      byte ptr [eax], al             
  0x01068B29  7044                    jo       0x1068b6f                      
  0x01068B2B  0038                    add      byte ptr [eax], bh             
  0x01068B2D  0900                    or       dword ptr [eax], eax           
  0x01068B2F  0000                    add      byte ptr [eax], al             
  0x01068B31  7044                    jo       0x1068b77                      
  0x01068B33  003d09000000            add      byte ptr [9], bh               
  0x01068B39  7044                    jo       0x1068b7f                      
  0x01068B3B  003e                    add      byte ptr [esi], bh             
  0x01068B3D  0900                    or       dword ptr [eax], eax           
  0x01068B3F  0000                    add      byte ptr [eax], al             
  0x01068B41  7044                    jo       0x1068b87                      
  0x01068B43  003f                    add      byte ptr [edi], bh             
  0x01068B45  0900                    or       dword ptr [eax], eax           
  0x01068B47  0000                    add      byte ptr [eax], al             
  0x01068B49  7044                    jo       0x1068b8f                      
                                        ; XREF: 0x01068B05 (cond_jump)
  0x01068B4B  004009                  add      byte ptr [eax + 9], al         
  0x01068B4E  0000                    add      byte ptr [eax], al             
  0x01068B50  007044                  add      byte ptr [eax + 0x44], dh      
  0x01068B53  004109                  add      byte ptr [ecx + 9], al         
  0x01068B56  0000                    add      byte ptr [eax], al             
  0x01068B58  007044                  add      byte ptr [eax + 0x44], dh      
  0x01068B5B  004209                  add      byte ptr [edx + 9], al         
  0x01068B5E  0000                    add      byte ptr [eax], al             
  0x01068B60  00f4                    add      ah, dh                         
  0x01068B62  60                      pushal                                  
  0x01068B63  004d09                  add      byte ptr [ebp + 9], cl         
  0x01068B66  0000                    add      byte ptr [eax], al             
  0x01068B68  00f4                    add      ah, dh                         
  0x01068B6A  44                      inc      esp                            
  0x01068B6B  0000                    add      byte ptr [eax], al             
  0x01068B6D  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01068B29 (cond_jump)
  0x01068B6F  0000                    add      byte ptr [eax], al             
  0x01068B71  58                      pop      eax                            
  0x01068B72  44                      inc      esp                            
  0x01068B73  0000                    add      byte ptr [eax], al             
  0x01068B75  f4                      hlt                                     
  0x01068B76  44                      inc      esp                            
                                        ; XREF: 0x01068B31 (cond_jump)
  0x01068B77  0002                    add      byte ptr [edx], al             
  0x01068B79  0000                    add      byte ptr [eax], al             
  0x01068B7B  0000                    add      byte ptr [eax], al             
  0x01068B7D  58                      pop      eax                            
  0x01068B7E  44                      inc      esp                            
                                        ; XREF: 0x01068B39 (cond_jump)
  0x01068B7F  0000                    add      byte ptr [eax], al             
  0x01068B81  f4                      hlt                                     
  0x01068B82  44                      inc      esp                            
  0x01068B83  0003                    add      byte ptr [ebx], al             
  0x01068B85  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01068B41 (cond_jump)
  0x01068B87  0000                    add      byte ptr [eax], al             
  0x01068B89  58                      pop      eax                            
  0x01068B8A  44                      inc      esp                            
  0x01068B8B  0000                    add      byte ptr [eax], al             
  0x01068B8D  f4                      hlt                                     
  0x01068B8E  44                      inc      esp                            
                                        ; XREF: 0x01068B49 (cond_jump)
  0x01068B8F  000400                  add      byte ptr [eax + eax], al       
  0x01068B92  0000                    add      byte ptr [eax], al             
  0x01068B94  005844                  add      byte ptr [eax + 0x44], bl      
  0x01068B97  0000                    add      byte ptr [eax], al             
  0x01068B99  f4                      hlt                                     
  0x01068B9A  44                      inc      esp                            
  0x01068B9B  0001                    add      byte ptr [ecx], al             
  0x01068B9D  0000                    add      byte ptr [eax], al             
  0x01068B9F  0000                    add      byte ptr [eax], al             
  0x01068BA1  58                      pop      eax                            
  0x01068BA2  44                      inc      esp                            
  0x01068BA3  0000                    add      byte ptr [eax], al             
  0x01068BA5  f4                      hlt                                     
  0x01068BA6  44                      inc      esp                            
  0x01068BA7  000500000000            add      byte ptr [0], al               
  0x01068BAD  58                      pop      eax                            
  0x01068BAE  44                      inc      esp                            
  0x01068BAF  0000                    add      byte ptr [eax], al             
  0x01068BB1  f4                      hlt                                     
  0x01068BB2  60                      pushal                                  
  0x01068BB3  005f09                  add      byte ptr [edi + 9], bl         
  0x01068BB6  0000                    add      byte ptr [eax], al             
  0x01068BB8  00f4                    add      ah, dh                         
  0x01068BBA  44                      inc      esp                            
  0x01068BBB  0001                    add      byte ptr [ecx], al             
  0x01068BBD  0000                    add      byte ptr [eax], al             
  0x01068BBF  009006060002            add      byte ptr [eax + 0x2000606], dl 
  0x01068BC5  0000                    add      byte ptr [eax], al             
  0x01068BC7  0000                    add      byte ptr [eax], al             
  0x01068BC9  58                      pop      eax                            
  0x01068BCA  44                      inc      esp                            
  0x01068BCB  0000                    add      byte ptr [eax], al             
  0x01068BCD  f4                      hlt                                     
  0x01068BCE  60                      pushal                                  
  0x01068BCF  005909                  add      byte ptr [ecx + 9], bl         
  0x01068BD2  0000                    add      byte ptr [eax], al             
  0x01068BD4  00f4                    add      ah, dh                         
  0x01068BD6  44                      inc      esp                            
  0x01068BD7  00ff                    add      bh, bh                         
  0x01068BD9  ff00                    inc      dword ptr [eax]                
  0x01068BDB  009006060002            add      byte ptr [eax + 0x2000606], dl 
  0x01068BE1  0000                    add      byte ptr [eax], al             
  0x01068BE3  0000                    add      byte ptr [eax], al             
  0x01068BE5  58                      pop      eax                            
  0x01068BE6  44                      inc      esp                            
  0x01068BE7  000c00                  add      byte ptr [eax + eax], cl       
  0x01068BEA  0000                    add      byte ptr [eax], al             
  0x01068BEC  00f0                    add      al, dh                         
  0x01068BEE  6200                    bound    eax, qword ptr [eax]           
  0x01068BF0  6809000000              push     9                              
  0x01068BF5  f4                      hlt                                     
  0x01068BF6  45                      inc      ebp                            
  0x01068BF7  0003                    add      byte ptr [ebx], al             
  0x01068BF9  0000                    add      byte ptr [eax], al             
  0x01068BFB  00d6                    add      dh, dl                         
  0x01068BFD  1202                    adc      al, byte ptr [edx]             
  0x01068BFF  00e0                    add      al, ah                         
  0x01068C01  0020                    add      byte ptr [eax], ah             
  0x01068C03  0000                    add      byte ptr [eax], al             
  0x01068C05  f4                      hlt                                     
  0x01068C06  6200                    bound    eax, qword ptr [eax]           
  0x01068C08  92                      xchg     edx, eax                       
  0x01068C09  0f0000                  sldt     word ptr [eax]                 
  0x01068C0C  000e                    add      byte ptr [esi], cl             
  0x01068C0E  2100                    and      dword ptr [eax], eax           
  0x01068C10  40                      inc      eax                            
  0x01068C11  0020                    add      byte ptr [eax], ah             
  0x01068C13  0000                    add      byte ptr [eax], al             
  0x01068C15  f4                      hlt                                     
  0x01068C16  60                      pushal                                  
  0x01068C17  008000000000            add      byte ptr [eax], al             
  0x01068C1D  9a210000f47000          lcall    0x70, 0xf4000021               
  0x01068C24  0001                    add      byte ptr [ecx], al             
  0x01068C26  0000                    add      byte ptr [eax], al             
  0x01068C28  00f4                    add      ah, dh                         
  0x01068C2A  56                      push     esi                            
  0x01068C2B  0007                    add      byte ptr [edi], al             
  0x01068C2D  0000                    add      byte ptr [eax], al             
  0x01068C2F  0000                    add      byte ptr [eax], al             
  0x01068C31  ea790080010d00          ljmp     0xd:0x1800079                  
  0x01068C38  0300                    add      eax, dword ptr [eax]           
  0x01068C3A  2000                    and      byte ptr [eax], al             
  0x01068C3C  002405000c0000          add      byte ptr [eax + 0xc00], ah     
  0x01068C43  0000                    add      byte ptr [eax], al             
  0x01068C45  0823                    or       byte ptr [ebx], ah             
  0x01068C47  000a                    add      byte ptr [edx], cl             
  0x01068C49  0000                    add      byte ptr [eax], al             
  0x01068C4B  00a0c80400a0            add      byte ptr [eax - 0x5ffffb38], ah 
  0x01068C51  61                      popal                                   
  0x01068C52  0400                    add      al, 0                          
  0x01068C54  a0640400a0              mov      al, byte ptr [0xa0000464]      
  0x01068C59  650400                  add      al, 0                          
  0x01068C5C  f8                      clc                                     
  0x01068C5D  0400                    add      al, 0                          
  0x01068C5F  0000                    add      byte ptr [eax], al             
  0x01068C61  0e                      push     cs                             
  0x01068C62  2300                    and      eax, dword ptr [eax]           
  0x01068C64  2200                    and      al, byte ptr [eax]             
  0x01068C66  2000                    and      byte ptr [eax], al             
  0x01068C68  009821000014            add      byte ptr [eax + 0x14000021], bl 
  0x01068C6E  2200                    and      al, byte ptr [eax]             
  0x01068C70  114804                  adc      dword ptr [eax + 4], ecx       
  0x01068C73  0000                    add      byte ptr [eax], al             
  0x01068C75  35220000e0              xor      eax, 0xe0000022                
  0x01068C7A  5f                      pop      edi                            
  0x01068C7B  0000                    add      byte ptr [eax], al             
  0x01068C7D  e14f                    loope    0x1068cce                      
  0x01068C7F  0078e0                  add      byte ptr [eax - 0x20], bh      
  0x01068C82  5e                      pop      esi                            
  0x01068C83  0010                    add      byte ptr [eax], dl             
  0x01068C85  d806                    fadd     dword ptr [esi]                
  0x01068C87  0009                    add      byte ptr [ecx], cl             
  0x01068C89  0000                    add      byte ptr [eax], al             
  0x01068C8B  0019                    add      byte ptr [ecx], bl             
  0x01068C8D  d94500                  fld      dword ptr [ebp]                
  0x01068C90  16                      push     ss                             
  0x01068C91  0020                    add      byte ptr [eax], ah             
  0x01068C93  0000                    add      byte ptr [eax], al             
  0x01068C95  808f0068b88a00          or       byte ptr [edi - 0x75479800], 0 
  0x01068C9C  19e1                    sbb      ecx, esp                       
  0x01068C9E  4f                      dec      edi                            
  0x01068C9F  0016                    add      byte ptr [esi], dl             
  0x01068CA1  0020                    add      byte ptr [eax], ah             
  0x01068CA3  0000                    add      byte ptr [eax], al             
  0x01068CA5  1ccf                    sbb      al, 0xcf                       
  0x01068CA7  00781d                  add      byte ptr [eax + 0x1d], bh      
  0x01068CAA  ca0000                  retf     0                              
  0x01068CAD  0e                      push     cs                             
  0x01068CAE  2300                    and      eax, dword ptr [eax]           
  0x01068CB0  2230                    and      dh, byte ptr [eax]             
  0x01068CB2  2200                    and      al, byte ptr [eax]             
  0x01068CB4  009821000014            add      byte ptr [eax + 0x14000021], bl 
  0x01068CBA  2200                    and      al, byte ptr [eax]             
  0x01068CBC  114804                  adc      dword ptr [eax + 4], ecx       
  0x01068CBF  0000                    add      byte ptr [eax], al             
  0x01068CC1  35220000e0              xor      eax, 0xe0000022                
  0x01068CC6  5f                      pop      edi                            
  0x01068CC7  0000                    add      byte ptr [eax], al             
  0x01068CC9  e14f                    loope    0x1068d1a                      
  0x01068CCB  0078e0                  add      byte ptr [eax - 0x20], bh      
                                        ; XREF: 0x01068C7D (cond_jump)
  0x01068CCE  5e                      pop      esi                            
  0x01068CCF  0010                    add      byte ptr [eax], dl             
  0x01068CD1  d806                    fadd     dword ptr [esi]                
  0x01068CD3  0009                    add      byte ptr [ecx], cl             
  0x01068CD5  0000                    add      byte ptr [eax], al             
  0x01068CD7  0019                    add      byte ptr [ecx], bl             
  0x01068CD9  d94500                  fld      dword ptr [ebp]                
  0x01068CDC  16                      push     ss                             
  0x01068CDD  0020                    add      byte ptr [eax], ah             
  0x01068CDF  0000                    add      byte ptr [eax], al             
  0x01068CE1  808f0068b88a00          or       byte ptr [edi - 0x75479800], 0 
  0x01068CE8  19e1                    sbb      ecx, esp                       
  0x01068CEA  4f                      dec      edi                            
  0x01068CEB  0016                    add      byte ptr [esi], dl             
  0x01068CED  0020                    add      byte ptr [eax], ah             
  0x01068CEF  0000                    add      byte ptr [eax], al             
  0x01068CF1  1ccf                    sbb      al, 0xcf                       
  0x01068CF3  00781d                  add      byte ptr [eax + 0x1d], bh      
  0x01068CF6  ca0000                  retf     0                              
  0x01068CF9  3022                    xor      byte ptr [edx], ah             
  0x01068CFB  0000                    add      byte ptr [eax], al             
  0x01068CFD  1422                    adc      al, 0x22                       
  0x01068CFF  0011                    add      byte ptr [ecx], dl             
  0x01068D01  48                      dec      eax                            
  0x01068D02  0400                    add      al, 0                          
  0x01068D04  0035220000e0            add      byte ptr [0xe0000022], dh      
  0x01068D0A  5f                      pop      edi                            
  0x01068D0B  0000                    add      byte ptr [eax], al             
  0x01068D0D  e145                    loope    0x1068d54                      
  0x01068D0F  006ce05e                add      byte ptr [eax + 0x5e], ch      
  0x01068D13  0010                    add      byte ptr [eax], dl             
  0x01068D15  d806                    fadd     dword ptr [esi]                
  0x01068D17  0009                    add      byte ptr [ecx], cl             
  0x01068D19  0000                    add      byte ptr [eax], al             
  0x01068D1B  0019                    add      byte ptr [ecx], bl             
  0x01068D1E  4f                      dec      edi                            
  0x01068D1F  0016                    add      byte ptr [esi], dl             
  0x01068D21  0020                    add      byte ptr [eax], ah             
  0x01068D23  0000                    add      byte ptr [eax], al             
  0x01068D25  808f0078b88a00          or       byte ptr [edi - 0x75478800], 0 
  0x01068D2C  19e1                    sbb      ecx, esp                       
  0x01068D2E  45                      inc      ebp                            
  0x01068D2F  0016                    add      byte ptr [esi], dl             
  0x01068D31  0020                    add      byte ptr [eax], ah             
  0x01068D33  0000                    add      byte ptr [eax], al             
  0x01068D35  1ccf                    sbb      al, 0xcf                       
  0x01068D37  006c1dca                add      byte ptr [ebp + ebx - 0x36], ch 
  0x01068D3B  0000                    add      byte ptr [eax], al             
  0x01068D3D  0e                      push     cs                             
  0x01068D3E  2300                    and      eax, dword ptr [eax]           
  0x01068D40  2202                    and      al, byte ptr [edx]             
  0x01068D42  3a00                    cmp      al, byte ptr [eax]             
  0x01068D44  0030                    add      byte ptr [eax], dh             
  0x01068D46  2200                    and      al, byte ptr [eax]             
  0x01068D48  009921000011            add      byte ptr [ecx + 0x11000021], bl 
  0x01068D4E  2200                    and      al, byte ptr [eax]             
  0x01068D50  0032                    add      byte ptr [edx], dh             
  0x01068D52  2300                    and      eax, dword ptr [eax]           
                                        ; XREF: 0x01068D0D (cond_jump)
  0x01068D54  001422                  add      byte ptr [edx], dl             
  0x01068D57  0000                    add      byte ptr [eax], al             
  0x01068D59  f4                      hlt                                     
  0x01068D5A  6600520f                add      byte ptr [edx + 0xf], dl       
  0x01068D5E  0000                    add      byte ptr [eax], al             
  0x01068D60  004920                  add      byte ptr [ecx + 0x20], cl      
  0x01068D63  0000                    add      byte ptr [eax], al             
  0x01068D65  352200185a              xor      eax, 0x5a180022                
  0x01068D6A  0400                    add      al, 0                          
  0x01068D6C  001c23                  add      byte ptr [ebx], bl             
  0x01068D6F  0000                    add      byte ptr [eax], al             
  0x01068D71  1d23000052              sbb      eax, 0x52000023                
  0x01068D76  2000                    and      byte ptr [eax], al             
  0x01068D78  00e0                    add      al, ah                         
  0x01068D7A  5f                      pop      edi                            
  0x01068D7B  0000                    add      byte ptr [eax], al             
  0x01068D7D  c1f400                  sal      esp, 0                         
  0x01068D80  00de                    add      dh, bl                         
  0x01068D82  4c                      dec      esp                            
  0x01068D83  00aed94f00bf            add      byte ptr [esi - 0x40ffb027], ch 
  0x01068D89  e05e                    loopne   0x1068de9                      
  0x01068D8B  0010                    add      byte ptr [eax], dl             
  0x01068D8D  da06                    fiadd    dword ptr [esi]                
  0x01068D8F  0020                    add      byte ptr [eax], ah             
  0x01068D91  0000                    add      byte ptr [eax], al             
  0x01068D93  0010                    add      byte ptr [eax], dl             
  0x01068D95  d206                    rol      byte ptr [esi], cl             
  0x01068D97  0007                    add      byte ptr [edi], al             
  0x01068D99  0000                    add      byte ptr [eax], al             
  0x01068D9B  0016                    add      byte ptr [esi], dl             
  0x01068D9D  808f00eee14500          or       byte ptr [edi + 0x45e1ee00], 0 
  0x01068DA4  cb                      retf                                    
  0x01068DA5  b88a00161c              mov      eax, 0x1c16008a                
  0x01068DAA  cf                      iretd                                   
  0x01068DAB  00aed94f00bf            add      byte ptr [esi - 0x40ffb027], ch 
  0x01068DB1  1dca000049              sbb      eax, 0x490000ca                
  0x01068DB6  2000                    and      byte ptr [eax], al             
  0x01068DB8  16                      push     ss                             
  0x01068DB9  808f00eea88a00          or       byte ptr [edi - 0x75571200], 0 
  0x01068DC0  cb                      retf                                    
  0x01068DC1  e145                    loope    0x1068e08                      
  0x01068DC3  0016                    add      byte ptr [esi], dl             
  0x01068DC5  0ccf                    or       al, 0xcf                       
  0x01068DC7  00ea                    add      dl, ch                         
  0x01068DCA  4f                      dec      edi                            
  0x01068DCB  00cf                    add      bh, cl                         
  0x01068DCD  0dca0010d2              or       eax, 0xd21000ca                
  0x01068DD2  06                      push     es                             
  0x01068DD3  0007                    add      byte ptr [edi], al             
  0x01068DD5  0000                    add      byte ptr [eax], al             
  0x01068DD7  0016                    add      byte ptr [esi], dl             
  0x01068DD9  808f00aee14500          or       byte ptr [edi + 0x45e1ae00], 0 
  0x01068DE0  bfb88a0016              mov      edi, 0x16008ab8                
  0x01068DE5  1ccf                    sbb      al, 0xcf                       
  0x01068DE7  00ea                    add      dl, ch                         
  0x01068DEA  4f                      dec      edi                            
  0x01068DEB  00cf                    add      bh, cl                         
  0x01068DED  1dca000049              sbb      eax, 0x490000ca                
  0x01068DF2  2000                    and      byte ptr [eax], al             
  0x01068DF4  16                      push     ss                             
  0x01068DF5  808f00aea88a00          or       byte ptr [edi - 0x75575200], 0 
  0x01068DFC  bfc1f40000              mov      edi, 0xf4c1                    
  0x01068E01  de4c0016                fimul    word ptr [eax + eax + 0x16]    
  0x01068E05  0ccf                    or       al, 0xcf                       
  0x01068E07  00aed94f00bf            add      byte ptr [esi - 0x40ffb027], ch 
  0x01068E0D  0dca00002f              or       eax, 0x2f0000ca                
  0x01068E12  2300                    and      eax, dword ptr [eax]           
  0x01068E14  2a4e23                  sub      cl, byte ptr [esi + 0x23]      
  0x01068E17  0032                    add      byte ptr [edx], dh             
  0x01068E19  0020                    add      byte ptr [eax], ah             
  0x01068E1B  0000                    add      byte ptr [eax], al             
  0x01068E1D  b92100009a              mov      ecx, 0x9a000021                
  0x01068E22  2100                    and      dword ptr [eax], eax           
  0x01068E24  80cd0c                  or       ch, 0xc                        
  0x01068E27  00ca                    add      dl, cl                         
  0x01068E2A  ff00                    inc      dword ptr [eax]                
  0x01068E2C  0002                    add      byte ptr [edx], al             
  0x01068E2E  3800                    cmp      byte ptr [eax], al             
  0x01068E30  001422                  add      byte ptr [edx], dl             
  0x01068E33  0000                    add      byte ptr [eax], al             
  0x01068E35  1c23                    sbb      al, 0x23                       
  0x01068E37  0000                    add      byte ptr [eax], al             
  0x01068E39  52                      push     edx                            
  0x01068E3A  2300                    and      eax, dword ptr [eax]           
  0x01068E3C  00f4                    add      ah, dh                         
  0x01068E3E  6600520f                add      byte ptr [edx + 0xf], dl       
  0x01068E42  0000                    add      byte ptr [eax], al             
  0x01068E44  115804                  adc      dword ptr [eax + 4], ebx       
  0x01068E47  0000                    add      byte ptr [eax], al             
  0x01068E49  1923                    sbb      dword ptr [ebx], esp           
  0x01068E4B  0000                    add      byte ptr [eax], al             
  0x01068E4D  352200001d              xor      eax, 0x1d000022                
  0x01068E52  2300                    and      eax, dword ptr [eax]           
  0x01068E54  005220                  add      byte ptr [edx + 0x20], dl      
  0x01068E57  0000                    add      byte ptr [eax], al             
  0x01068E59  e05f                    loopne   0x1068eba                      
  0x01068E5B  0000                    add      byte ptr [eax], al             
  0x01068E5D  c1f400                  sal      esp, 0                         
  0x01068E60  00de                    add      dh, bl                         
  0x01068E62  4c                      dec      esp                            
  0x01068E63  00aec94f00bf            add      byte ptr [esi - 0x40ffb037], ch 
  0x01068E69  e05e                    loopne   0x1068ec9                      
  0x01068E6B  0016                    add      byte ptr [esi], dl             
  0x01068E6D  0020                    add      byte ptr [eax], ah             
  0x01068E6F  0000                    add      byte ptr [eax], al             
  0x01068E71  808f00eea88a00          or       byte ptr [edi - 0x75571200], 0 
  0x01068E78  cb                      retf                                    
  0x01068E79  e145                    loope    0x1068ec0                      
  0x01068E7B  0016                    add      byte ptr [esi], dl             
  0x01068E7D  0ccf                    or       al, 0xcf                       
  0x01068E7F  0010                    add      byte ptr [eax], dl             
  0x01068E81  d206                    rol      byte ptr [esi], cl             
  0x01068E83  0010                    add      byte ptr [eax], dl             
  0x01068E85  0000                    add      byte ptr [eax], al             
  0x01068E87  00ea                    add      dl, ch                         
  0x01068E89  c9                      leave                                   
  0x01068E8A  4f                      dec      edi                            
  0x01068E8B  00cf                    add      bh, cl                         
  0x01068E8D  0dca001600              or       eax, 0x1600ca                  
  0x01068E92  2000                    and      byte ptr [eax], al             
  0x01068E94  00808f00aea8            add      byte ptr [eax - 0x5751ff71], al 
  0x01068E9A  8a00                    mov      al, byte ptr [eax]             
  0x01068E9C  bfc1f40000              mov      edi, 0xf4c1                    
  0x01068EA1  de4c0016                fimul    word ptr [eax + eax + 0x16]    
  0x01068EA5  0ccf                    or       al, 0xcf                       
  0x01068EA7  00aec94f00bf            add      byte ptr [esi - 0x40ffb037], ch 
  0x01068EAD  0dca001600              or       eax, 0x1600ca                  
  0x01068EB2  2000                    and      byte ptr [eax], al             
  0x01068EB4  00808f00eea8            add      byte ptr [eax - 0x5711ff71], al 
                                        ; XREF: 0x01068E59 (cond_jump)
  0x01068EBA  8a00                    mov      al, byte ptr [eax]             
  0x01068EBC  cb                      retf                                    
  0x01068EBD  e145                    loope    0x1068f04                      
  0x01068EBF  0016                    add      byte ptr [esi], dl             
  0x01068EC1  0ccf                    or       al, 0xcf                       
  0x01068EC3  00ea                    add      dl, ch                         
  0x01068EC5  c9                      leave                                   
  0x01068EC6  4f                      dec      edi                            
  0x01068EC7  00cf                    add      bh, cl                         
                                        ; XREF: 0x01068E69 (cond_jump)
  0x01068EC9  0dca001600              or       eax, 0x1600ca                  
  0x01068ECE  2000                    and      byte ptr [eax], al             
  0x01068ED0  00808f00aea8            add      byte ptr [eax - 0x5751ff71], al 
  0x01068ED6  8a00                    mov      al, byte ptr [eax]             
  0x01068ED8  bf00200020              mov      edi, 0x20002000                
  0x01068EDD  f4                      hlt                                     
  0x01068EDE  0500ffff00              add      eax, 0xffff00                  
  0x01068EE3  0016                    add      byte ptr [esi], dl             
  0x01068EE5  4c                      dec      esp                            
  0x01068EE6  57                      push     edi                            
  0x01068EE7  00a061040000            add      byte ptr [eax + 0x461], ah     
  0x01068EED  4d                      dec      ebp                            
  0x01068EEE  56                      push     esi                            
  0x01068EEF  00a0640400a0            add      byte ptr [eax - 0x5ffffb9c], ah 
  0x01068EF5  650400                  add      al, 0                          
  0x01068EF8  b8f300000c              mov      eax, 0xc0000f3                 
  0x01068EFD  0000                    add      byte ptr [eax], al             
  0x01068EFF  0000                    add      byte ptr [eax], al             
  0x01068F01  f4                      hlt                                     
  0x01068F02  7100                    jno      0x1068f04                      
  0x01068F06  ff00                    inc      dword ptr [eax]                
  0x01068F08  00f4                    add      ah, dh                         
  0x01068F0A  7500                    jne      0x1068f0c                      
                                        ; XREF: 0x01068F0A (cond_jump)
  0x01068F0C  fc                      cld                                     
  0x01068F0E  ff00                    inc      dword ptr [eax]                
  0x01068F10  0096220010da            add      byte ptr [esi - 0x25efffde], dl 
  0x01068F16  06                      push     es                             
  0x01068F17  001a                    add      byte ptr [edx], bl             
  0x01068F19  0000                    add      byte ptr [eax], al             
  0x01068F1B  0000                    add      byte ptr [eax], al             
  0x01068F1D  b9f00010de              mov      ecx, 0xde1000f0                
  0x01068F22  06                      push     es                             
  0x01068F23  000a                    add      byte ptr [edx], cl             
  0x01068F25  0000                    add      byte ptr [eax], al             
  0x01068F27  00d4                    add      ah, dl                         
  0x01068F29  e145                    loope    0x1068f70                      
  0x01068F2B  00d6                    add      dh, dl                         
  0x01068F2D  39f0                    cmp      eax, esi                       
  0x01068F2F  00e6                    add      dh, ah                         
  0x01068F31  a8f0                    test     al, 0xf0                       
  0x01068F33  00d2                    add      dl, dl                         
  0x01068F35  a1f400e259              mov      eax, dword ptr [0x59e200f4]    
  0x01068F3A  44                      inc      esp                            
  0x01068F3B  00e2                    add      dl, ah                         
  0x01068F3D  a1d000d349              mov      eax, dword ptr [0x49d300d0]    
  0x01068F42  45                      inc      ebp                            
  0x01068F43  0000                    add      byte ptr [eax], al             
  0x01068F45  dd10                    fst      qword ptr [eax]                
  0x01068F47  0000                    add      byte ptr [eax], al             
  0x01068F49  4c                      dec      esp                            
  0x01068F4A  44                      inc      esp                            
  0x01068F4B  00d4                    add      ah, dl                         
  0x01068F4D  e145                    loope    0x1068f94                      
  0x01068F4F  00d6                    add      dh, dl                         
  0x01068F51  39f0                    cmp      eax, esi                       
  0x01068F53  00e6                    add      dh, ah                         
  0x01068F55  a8f0                    test     al, 0xf0                       
  0x01068F57  00d2                    add      dl, dl                         
  0x01068F59  a1f400e259              mov      eax, dword ptr [0x59e200f4]    
  0x01068F5E  44                      inc      esp                            
  0x01068F5F  00e2                    add      dl, ah                         
  0x01068F61  a1f000d359              mov      eax, dword ptr [0x59d300f0]    
  0x01068F66  45                      inc      ebp                            
  0x01068F67  0000                    add      byte ptr [eax], al             
  0x01068F69  4c                      dec      esp                            
  0x01068F6A  56                      push     esi                            
  0x01068F6B  008ef1030000            add      byte ptr [esi + 0x3f1], cl     
  0x01068F71  d422                    aam      0x22                           
  0x01068F73  0000                    add      byte ptr [eax], al             
  0x01068F75  90                      nop                                     
  0x01068F76  2200                    and      al, byte ptr [eax]             
  0x01068F78  00982300a460            add      byte ptr [eax + 0x60a40023], bl 
  0x01068F7E  0400                    add      al, 0                          
  0x01068F80  0c00                    or       al, 0                          
  0x01068F82  0000                    add      byte ptr [eax], al             
  0x01068F84  00f4                    add      ah, dh                         
  0x01068F86  7100                    jno      0x1068f88                      
  0x01068F8A  ff00                    inc      dword ptr [eax]                
  0x01068F8C  00f4                    add      ah, dh                         
  0x01068F8E  7500                    jne      0x1068f90                      
                                        ; XREF: 0x01068F8E (cond_jump)
  0x01068F90  fc                      cld                                     
  0x01068F92  ff00                    inc      dword ptr [eax]                
                                        ; XREF: 0x01068F4D (cond_jump)
  0x01068F94  0096220010da            add      byte ptr [esi - 0x25efffde], dl 
  0x01068F9A  06                      push     es                             
  0x01068F9B  0021                    add      byte ptr [ecx], ah             
  0x01068F9D  0000                    add      byte ptr [eax], al             
  0x01068F9F  0000                    add      byte ptr [eax], al             
  0x01068FA1  da5700                  ficom    dword ptr [edi]                
  0x01068FA4  00d2                    add      dl, dl                         
  0x01068FA6  51                      push     ecx                            
  0x01068FA7  0000                    add      byte ptr [eax], al             
  0x01068FA9  b9f00010de              mov      ecx, 0xde1000f0                
  0x01068FAE  06                      push     es                             
  0x01068FAF  000b                    add      byte ptr [ebx], cl             
  0x01068FB1  0000                    add      byte ptr [eax], al             
  0x01068FB3  00d4                    add      ah, dl                         
  0x01068FB5  e145                    loope    0x1068ffc                      
  0x01068FB7  00d6                    add      dh, dl                         
  0x01068FB9  39f0                    cmp      eax, esi                       
  0x01068FBB  00e6                    add      dh, ah                         
  0x01068FBD  a8f0                    test     al, 0xf0                       
  0x01068FBF  00d2                    add      dl, dl                         
  0x01068FC1  a1f400e259              mov      eax, dword ptr [0x59e200f4]    
  0x01068FC6  44                      inc      esp                            
  0x01068FC7  00e2                    add      dl, ah                         
  0x01068FC9  a1d000d249              mov      eax, dword ptr [0x49d200d0]    
  0x01068FCE  45                      inc      ebp                            
  0x01068FCF  0010                    add      byte ptr [eax], dl             
  0x01068FD1  0020                    add      byte ptr [eax], ah             
  0x01068FD3  0009                    add      byte ptr [ecx], cl             
  0x01068FD5  dd10                    fst      qword ptr [eax]                
  0x01068FD7  004c4c44                add      byte ptr [esp + ecx*2 + 0x44], cl 
  0x01068FDB  00d4                    add      ah, dl                         
  0x01068FDD  e145                    loope    0x1069024                      
  0x01068FDF  00d6                    add      dh, dl                         
  0x01068FE1  39f0                    cmp      eax, esi                       
  0x01068FE3  00e6                    add      dh, ah                         
  0x01068FE5  a8f0                    test     al, 0xf0                       
  0x01068FE7  00d2                    add      dl, dl                         
  0x01068FE9  a1f400e259              mov      eax, dword ptr [0x59e200f4]    
  0x01068FEE  44                      inc      esp                            
  0x01068FEF  00e2                    add      dl, ah                         
  0x01068FF1  a1f000d259              mov      eax, dword ptr [0x59d200f0]    
  0x01068FF6  45                      inc      ebp                            
  0x01068FF7  0010                    add      byte ptr [eax], dl             
  0x01068FF9  0020                    add      byte ptr [eax], ah             
  0x01068FFB  0009                    add      byte ptr [ecx], cl             
  0x01068FFD  c421                    les      esp, ptr [ecx]                 
  0x01068FFF  004c4c44                add      byte ptr [esp + ecx*2 + 0x44], cl 
  0x01069003  0084f10300005a          add      byte ptr [ecx + esi*8 + 0x5a000003], al 
  0x0106900A  55                      push     ebp                            
  0x0106900B  0000                    add      byte ptr [eax], al             
  0x0106900D  5a                      pop      edx                            
  0x0106900E  51                      push     ecx                            
  0x0106900F  0000                    add      byte ptr [eax], al             
  0x01069011  d422                    aam      0x22                           
  0x01069013  0000                    add      byte ptr [eax], al             
  0x01069015  90                      nop                                     
  0x01069016  2200                    and      al, byte ptr [eax]             
  0x01069018  00982300a460            add      byte ptr [eax + 0x60a40023], bl 
  0x0106901E  0400                    add      al, 0                          
  0x01069020  0c00                    or       al, 0                          
  0x01069022  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01068FDD (cond_jump)
  0x01069024  00c8                    add      al, cl                         
  0x01069026  44                      inc      esp                            
  0x01069027  00a000200014            add      byte ptr [eax + 0x14002000], ah 
  0x0106902D  c8440011                enter    0x44, 0x11                     
  0x01069031  0020                    add      byte ptr [eax], ah             
  0x01069033  0010                    add      byte ptr [eax], dl             
  0x01069035  de06                    fiadd    word ptr [esi]                 
  0x01069037  0005000000a0            add      byte ptr [0xa0000000], al      
  0x0106903D  0c18                    or       al, 0x18                       
  0x0106903F  00bac8440014            add      byte ptr [edx + 0x140044c8], bh 
  0x01069045  0020                    add      byte ptr [eax], ah             
  0x01069047  0011                    add      byte ptr [ecx], dl             
  0x01069049  0020                    add      byte ptr [eax], ah             
  0x0106904B  0000                    add      byte ptr [eax], al             
  0x0106904D  2418                    and      al, 0x18                       
  0x0106904F  00ba0020000c            add      byte ptr [edx + 0xc002000], bh 
  0x01069055  0000                    add      byte ptr [eax], al             
  0x01069057  0013                    add      byte ptr [ebx], dl             
  0x01069059  c84600e1                enter    0x46, -0x1f                    
  0x0106905D  0020                    add      byte ptr [eax], ah             
  0x0106905F  0010                    add      byte ptr [eax], dl             
  0x01069061  de06                    fiadd    word ptr [esi]                 
  0x01069063  0003                    add      byte ptr [ebx], al             
  0x01069065  0000                    add      byte ptr [eax], al             
  0x01069067  0000                    add      byte ptr [eax], al             
  0x01069069  c84600e1                enter    0x46, -0x1f                    
  0x0106906D  4c                      dec      esp                            
  0x0106906E  56                      push     esi                            
  0x0106906F  0000                    add      byte ptr [eax], al             
  0x01069071  6456                    push     esi                            
  0x01069073  000c00                  add      byte ptr [eax + eax], cl       
  0x01069076  0000                    add      byte ptr [eax], al             
  0x01069078  004039                  add      byte ptr [eax + 0x39], al      
  0x0106907B  0000                    add      byte ptr [eax], al             
  0x0106907D  3d23000049              cmp      eax, 0x49000023                
  0x01069082  2000                    and      byte ptr [eax], al             
  0x01069084  004d20                  add      byte ptr [ebp + 0x20], cl      
  0x01069087  0012                    add      byte ptr [edx], dl             
  0x01069089  51                      push     ecx                            
  0x0106908A  0400                    add      al, 0                          
  0x0106908C  16                      push     ss                             
  0x0106908D  55                      push     ebp                            
  0x0106908E  0400                    add      al, 0                          
  0x01069090  10d9                    adc      cl, bl                         
  0x01069092  06                      push     es                             
  0x01069093  000400                  add      byte ptr [eax + eax], al       
  0x01069096  0000                    add      byte ptr [eax], al             
  0x01069098  00d9                    add      cl, bl                         
  0x0106909A  46                      inc      esi                            
  0x0106909B  0000                    add      byte ptr [eax], al             
  0x0106909D  b2b0                    mov      dl, 0xb0                       
  0x0106909F  0000                    add      byte ptr [eax], al             
  0x010690A1  56                      push     esi                            
  0x010690A2  44                      inc      esp                            
  0x010690A3  0000                    add      byte ptr [eax], al             
  0x010690A6  3800                    cmp      byte ptr [eax], al             
  0x010690A8  001c23                  add      byte ptr [ebx], bl             
  0x010690AB  0000                    add      byte ptr [eax], al             
  0x010690AD  41                      inc      ecx                            
  0x010690AE  2000                    and      byte ptr [eax], al             
  0x010690B0  004520                  add      byte ptr [ebp + 0x20], al      
  0x010690B3  0012                    add      byte ptr [edx], dl             
  0x010690B5  48                      dec      eax                            
  0x010690B6  0400                    add      al, 0                          
  0x010690B8  16                      push     ss                             
  0x010690B9  4c                      dec      esp                            
  0x010690BA  0400                    add      al, 0                          
  0x010690BC  0002                    add      byte ptr [edx], al             
  0x010690BE  3800                    cmp      byte ptr [eax], al             
  0x010690C0  00f4                    add      ah, dh                         
  0x010690C2  7200                    jb       0x10690c4                      
  0x010690C6  ff00                    inc      dword ptr [eax]                
  0x010690C8  0002                    add      byte ptr [edx], al             
  0x010690CA  3c00                    cmp      al, 0                          
  0x010690CC  00f4                    add      ah, dh                         
  0x010690CE  7600                    jbe      0x10690d0                      
  0x010690D2  ff00                    inc      dword ptr [eax]                
  0x010690D4  0088d000d4ca            add      byte ptr [eax - 0x352bff30], cl 
  0x010690DA  d500                    aad      0                              
  0x010690DC  f30020                  add      byte ptr [eax], ah             
  0x010690DF  00c8                    add      al, cl                         
  0x010690E1  59                      pop      ecx                            
  0x010690E2  56                      push     esi                            
  0x010690E3  00eb                    add      bl, ch                         
  0x010690E5  88d0                    mov      al, dl                         
  0x010690E7  00903f060005            add      byte ptr [eax + 0x500063f], dl 
  0x010690ED  0000                    add      byte ptr [eax], al             
  0x010690EF  00d4                    add      ah, dl                         
  0x010690F1  cad500                  retf     0xd5                           
  0x010690F4  f35d                    pop      ebp                            
  0x010690F6  57                      push     edi                            
  0x010690F7  00c8                    add      al, cl                         
  0x010690F9  59                      pop      ecx                            
  0x010690FA  56                      push     esi                            
  0x010690FB  00eb                    add      bl, ch                         
  0x010690FD  88d0                    mov      al, dl                         
  0x010690FF  0000                    add      byte ptr [eax], al             
  0x01069101  5d                      pop      ebp                            
  0x01069102  57                      push     edi                            
  0x01069103  0000                    add      byte ptr [eax], al             
  0x01069105  40                      inc      eax                            
  0x01069106  2000                    and      byte ptr [eax], al             
  0x01069108  00442000                add      byte ptr [eax], al             
  0x0106910C  007f38                  add      byte ptr [edi + 0x38], bh      
  0x0106910F  0000                    add      byte ptr [eax], al             
  0x01069111  1a23                    sbb      ah, byte ptr [ebx]             
  0x01069113  0000                    add      byte ptr [eax], al             
  0x01069115  1c23                    sbb      al, 0x23                       
  0x01069117  0000                    add      byte ptr [eax], al             
  0x01069119  1e                      push     ds                             
  0x0106911A  2300                    and      eax, dword ptr [eax]           
  0x0106911C  004120                  add      byte ptr [ecx + 0x20], al      
  0x0106911F  0000                    add      byte ptr [eax], al             
  0x01069121  45                      inc      ebp                            
  0x01069122  2000                    and      byte ptr [eax], al             
  0x01069124  004020                  add      byte ptr [eax + 0x20], al      
  0x01069127  0000                    add      byte ptr [eax], al             
  0x01069129  4a                      dec      edx                            
  0x0106912A  2000                    and      byte ptr [eax], al             
  0x0106912C  00442000                add      byte ptr [eax], al             
  0x01069130  004e20                  add      byte ptr [esi + 0x20], cl      
  0x01069133  0000                    add      byte ptr [eax], al             
  0x01069135  0238                    add      bh, byte ptr [eax]             
  0x01069137  0000                    add      byte ptr [eax], al             
  0x01069139  f4                      hlt                                     
  0x0106913A  7200                    jb       0x106913c                      
  0x0106913E  ff00                    inc      dword ptr [eax]                
  0x01069140  0002                    add      byte ptr [edx], al             
  0x01069142  3c00                    cmp      al, 0                          
  0x01069144  00f4                    add      ah, dh                         
  0x01069146  7600                    jbe      0x1069148                      
  0x0106914A  ff00                    inc      dword ptr [eax]                
  0x0106914C  0088d000d4ca            add      byte ptr [eax - 0x352bff30], cl 
  0x01069152  d500                    aad      0                              
  0x01069154  f30020                  add      byte ptr [eax], ah             
  0x01069157  00c8                    add      al, cl                         
  0x01069159  7956                    jns      0x10691b1                      
  0x0106915B  00eb                    add      bl, ch                         
  0x0106915D  88d0                    mov      al, dl                         
  0x0106915F  00903f060005            add      byte ptr [eax + 0x500063f], dl 
  0x01069165  0000                    add      byte ptr [eax], al             
  0x01069167  00d4                    add      ah, dl                         
  0x01069169  cad500                  retf     0xd5                           
  0x0106916C  f37d5f                  jge      0x10691ce                      
  0x0106916F  00c8                    add      al, cl                         
  0x01069171  7956                    jns      0x10691c9                      
  0x01069173  00eb                    add      bl, ch                         
  0x01069175  88d0                    mov      al, dl                         
  0x01069177  0000                    add      byte ptr [eax], al             
  0x01069179  7d5f                    jge      0x10691da                      
  0x0106917B  000c00                  add      byte ptr [eax + eax], cl       
  0x0106917E  0000                    add      byte ptr [eax], al             
  0x01069180  00c0                    add      al, al                         
  0x01069182  f1                      int1                                    
  0x01069183  0000                    add      byte ptr [eax], al             
  0x01069185  da4d00                  fimul    dword ptr [ebp]                
  0x01069188  c8d84e00                enter    0x4ed8, 0                      
  0x0106918C  eb00                    jmp      0x106918e                      
                                        ; XREF: 0x0106918C (jump)
  0x0106918E  2000                    and      byte ptr [eax], al             
  0x01069190  b064                    mov      al, 0x64                       
  0x01069192  5f                      pop      edi                            
  0x01069193  0010                    add      byte ptr [eax], dl             
  0x01069195  da06                    fiadd    dword ptr [esi]                
  0x01069197  0006                    add      byte ptr [esi], al             
  0x01069199  0000                    add      byte ptr [eax], al             
  0x0106919B  00a7c0f10000            add      byte ptr [edi + 0xf1c0], ah    
  0x010691A1  da4d00                  fimul    dword ptr [ebp]                
  0x010691A4  c8d84e00                enter    0x4ed8, 0                      
  0x010691A8  eb5c                    jmp      0x1069206                      
  0x010691AA  56                      push     esi                            
  0x010691AB  00b0645f00a7            add      byte ptr [eax - 0x58ffa09c], dh 
                                        ; XREF: 0x01069159 (cond_jump)
  0x010691B1  0020                    add      byte ptr [eax], ah             
  0x010691B3  0000                    add      byte ptr [eax], al             
  0x010691B5  5c                      pop      esp                            
  0x010691B6  56                      push     esi                            
  0x010691B7  000c00                  add      byte ptr [eax + eax], cl       
  0x010691BA  0000                    add      byte ptr [eax], al             
  0x010691BC  00c0                    add      al, al                         
  0x010691BE  f1                      int1                                    
  0x010691BF  0000                    add      byte ptr [eax], al             
  0x010691C1  da4d00                  fimul    dword ptr [ebp]                
  0x010691C4  c8e14e00                enter    0x4ee1, 0                      
  0x010691C8  eb00                    jmp      0x10691ca                      
                                        ; XREF: 0x010691C8 (jump)
  0x010691CA  2000                    and      byte ptr [eax], al             
  0x010691CC  b0d8                    mov      al, 0xd8                       
                                        ; XREF: 0x0106916C (cond_jump)
  0x010691CE  4e                      dec      esi                            
  0x010691CF  00a7d94400c8            add      byte ptr [edi - 0x37ffbb27], ah 
  0x010691D5  645f                    pop      edi                            
  0x010691D7  00eb                    add      bl, ch                         
  0x010691D9  5c                      pop      esp                            
                                        ; XREF: 0x01069179 (cond_jump)
  0x010691DA  56                      push     esi                            
  0x010691DB  00b0655f0010            add      byte ptr [eax + 0x10005f65], dh 
  0x010691E1  da06                    fiadd    dword ptr [esi]                
  0x010691E3  000a                    add      byte ptr [edx], cl             
  0x010691E5  0000                    add      byte ptr [eax], al             
  0x010691E7  00a7c0f10000            add      byte ptr [edi + 0xf1c0], ah    
  0x010691ED  da4d00                  fimul    dword ptr [ebp]                
  0x010691F0  c8e14e00                enter    0x4ee1, 0                      
  0x010691F4  eb5d                    jmp      0x1069253                      
  0x010691F6  56                      push     esi                            
  0x010691F7  00b0d84e00a7            add      byte ptr [eax - 0x58ffb128], dh 
  0x010691FD  d94400c8                fld      dword ptr [eax + eax - 0x38]   
  0x01069201  645f                    pop      edi                            
  0x01069203  00eb                    add      bl, ch                         
  0x01069205  5c                      pop      esp                            
                                        ; XREF: 0x010691A8 (jump)
  0x01069206  56                      push     esi                            
  0x01069207  00b0655f00a7            add      byte ptr [eax - 0x58ffa09b], dh 
  0x0106920D  0020                    add      byte ptr [eax], ah             
  0x0106920F  0000                    add      byte ptr [eax], al             
  0x01069211  5d                      pop      ebp                            
  0x01069212  56                      push     esi                            
  0x01069213  000c00                  add      byte ptr [eax + eax], cl       
  0x01069216  0000                    add      byte ptr [eax], al             
  0x01069218  00c0                    add      al, al                         
  0x0106921A  f1                      int1                                    
  0x0106921B  0000                    add      byte ptr [eax], al             
  0x0106921D  da4d00                  fimul    dword ptr [ebp]                
  0x01069220  a8c8                    test     al, 0xc8                       
  0x01069222  4e                      dec      esi                            
  0x01069223  00bb002000e0            add      byte ptr [ebx - 0x1fffe000], bh 
  0x01069229  4d                      dec      ebp                            
  0x0106922A  57                      push     edi                            
  0x0106922B  0010                    add      byte ptr [eax], dl             
  0x0106922D  da06                    fiadd    dword ptr [esi]                
  0x0106922F  0006                    add      byte ptr [esi], al             
  0x01069231  0000                    add      byte ptr [eax], al             
  0x01069233  00c7                    add      bh, al                         
  0x01069235  c0f100                  sal      cl, 0                          
  0x01069238  00da                    add      dl, bl                         
  0x0106923A  4d                      dec      ebp                            
  0x0106923B  00a8c84e00bb            add      byte ptr [eax - 0x44ffb138], ch 
  0x01069241  4c                      dec      esp                            
  0x01069242  56                      push     esi                            
  0x01069243  00e0                    add      al, ah                         
  0x01069245  4d                      dec      ebp                            
  0x01069246  57                      push     edi                            
  0x01069247  00c7                    add      bh, al                         
  0x01069249  0020                    add      byte ptr [eax], ah             
  0x0106924B  0000                    add      byte ptr [eax], al             
  0x0106924D  4c                      dec      esp                            
  0x0106924E  56                      push     esi                            
  0x0106924F  000c00                  add      byte ptr [eax + eax], cl       
  0x01069252  0000                    add      byte ptr [eax], al             
  0x01069254  00c1                    add      cl, al                         
  0x01069256  f1                      int1                                    
  0x01069257  0000                    add      byte ptr [eax], al             
  0x01069259  da4d00                  fimul    dword ptr [ebp]                
  0x0106925C  a8e1                    test     al, 0xe1                       
  0x0106925E  4e                      dec      esi                            
  0x0106925F  00bbe04e00e0            add      byte ptr [ebx - 0x1fffb120], bh 
  0x01069265  c84400c7                enter    0x44, -0x39                    
  0x01069269  55                      push     ebp                            
  0x0106926A  57                      push     edi                            
  0x0106926B  00b8e14e00ab            add      byte ptr [eax - 0x54ffb11f], bh 
  0x01069271  5c                      pop      esp                            
  0x01069272  56                      push     esi                            
  0x01069273  00e0                    add      al, ah                         
  0x01069275  c9                      leave                                   
  0x01069276  44                      inc      esp                            
  0x01069277  00c7                    add      bh, al                         
  0x01069279  4d                      dec      ebp                            
  0x0106927A  57                      push     edi                            
  0x0106927B  0010                    add      byte ptr [eax], dl             
  0x0106927D  da06                    fiadd    dword ptr [esi]                
  0x0106927F  000b                    add      byte ptr [ebx], cl             
  0x01069281  0000                    add      byte ptr [eax], al             
  0x01069283  0000                    add      byte ptr [eax], al             
  0x01069285  c1f100                  sal      ecx, 0                         
  0x01069288  00da                    add      dl, bl                         
  0x0106928A  4d                      dec      ebp                            
  0x0106928B  00a8e14e00bb            add      byte ptr [eax - 0x44ffb11f], ch 
  0x01069291  0cc8                    or       al, 0xc8                       
  0x01069293  00e0                    add      al, ah                         
  0x01069295  c84400c7                enter    0x44, -0x39                    
  0x01069299  55                      push     ebp                            
  0x0106929A  57                      push     edi                            
  0x0106929B  00b8e14e00ab            add      byte ptr [eax - 0x54ffb11f], bh 
  0x010692A1  5c                      pop      esp                            
  0x010692A2  56                      push     esi                            
  0x010692A3  00e0                    add      al, ah                         
  0x010692A5  c9                      leave                                   
  0x010692A6  44                      inc      esp                            
  0x010692A7  00c7                    add      bh, al                         
  0x010692A9  4d                      dec      ebp                            
  0x010692AA  57                      push     edi                            
  0x010692AB  0000                    add      byte ptr [eax], al             
  0x010692AD  4c                      dec      esp                            
  0x010692AE  56                      push     esi                            
  0x010692AF  000c00                  add      byte ptr [eax + eax], cl       
  0x010692B2  0000                    add      byte ptr [eax], al             
  0x010692B4  00d8                    add      al, bl                         
  0x010692B6  56                      push     esi                            
  0x010692B7  0010                    add      byte ptr [eax], dl             
  0x010692B9  d906                    fld      dword ptr [esi]                
  0x010692BB  0007                    add      byte ptr [edi], al             
  0x010692BD  0000                    add      byte ptr [eax], al             
  0x010692BF  0001                    add      byte ptr [ecx], al             
  0x010692C1  1e                      push     ds                             
  0x010692C2  0c00                    or       al, 0                          
  0x010692C4  3e0020                  add      byte ptr ds:[eax], ah          
  0x010692C7  0003                    add      byte ptr [ebx], al             
  0x010692C9  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010692CA  2300                    and      eax, dword ptr [eax]           
  0x010692CC  48                      dec      eax                            
  0x010692CD  a0020000d8              mov      al, byte ptr [0xd8000002]      
  0x010692D2  56                      push     esi                            
  0x010692D3  0000                    add      byte ptr [eax], al             
  0x010692D5  59                      pop      ecx                            
  0x010692D6  57                      push     edi                            
  0x010692D7  0000                    add      byte ptr [eax], al             
  0x010692D9  50                      push     eax                            
  0x010692DA  2000                    and      byte ptr [eax], al             
  0x010692DC  0c00                    or       al, 0                          
  0x010692DE  0000                    add      byte ptr [eax], al             
  0x010692E0  00f4                    add      ah, dh                         
  0x010692E2  46                      inc      esi                            
  0x010692E3  0001                    add      byte ptr [ecx], al             
  0x010692E5  0000                    add      byte ptr [eax], al             
  0x010692E7  0000                    add      byte ptr [eax], al             
  0x010692E9  ae                      scasb    al, byte ptr es:[edi]          
  0x010692EA  2300                    and      eax, dword ptr [eax]           
  0x010692EC  55                      push     ebp                            
  0x010692ED  3522000da4              xor      eax, 0xa40d0022                
  0x010692F2  050000b422              add      eax, 0x22b40000                
  0x010692F7  0010                    add      byte ptr [eax], dl             
  0x010692F9  dc06                    fadd     qword ptr [esi]                
  0x010692FB  0009                    add      byte ptr [ecx], cl             
  0x010692FD  0000                    add      byte ptr [eax], al             
  0x010692FF  0000                    add      byte ptr [eax], al             
  0x01069301  f4                      hlt                                     
  0x01069302  56                      push     esi                            
  0x01069303  00ff                    add      bh, bh                         
  0x01069306  7f00                    jg       0x1069308                      
                                        ; XREF: 0x01069306 (cond_jump)
  0x01069308  10dd                    adc      ch, bl                         
  0x0106930A  06                      push     es                             
  0x0106930B  000400                  add      byte ptr [eax + eax], al       
  0x0106930E  0000                    add      byte ptr [eax], al             
  0x01069310  00dc                    add      ah, bl                         
  0x01069312  44                      inc      esp                            
  0x01069313  004500                  add      byte ptr [ebp], al             
  0x01069316  2000                    and      byte ptr [eax], al             
  0x01069318  40                      inc      eax                            
  0x01069319  7002                    jo       0x106931d                      
  0x0106931B  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01069319 (cond_jump)
  0x0106931D  4d                      dec      ebp                            
  0x0106931E  54                      push     esp                            
  0x0106931F  0000                    add      byte ptr [eax], al             
  0x01069321  352200004f              xor      eax, 0x4f000022                
  0x01069326  2300                    and      eax, dword ptr [eax]           
  0x01069328  0be2                    or       esp, edx                       
  0x0106932A  56                      push     esi                            
  0x0106932B  0006                    add      byte ptr [esi], al             
  0x0106932D  2405                    and      al, 5                          
  0x0106932F  0000                    add      byte ptr [eax], al             
  0x01069331  f4                      hlt                                     
  0x01069332  44                      inc      esp                            
  0x01069333  000f                    add      byte ptr [edi], cl             
  0x01069335  0000                    add      byte ptr [eax], al             
  0x01069337  004500                  add      byte ptr [ebp], al             
  0x0106933A  2000                    and      byte ptr [eax], al             
  0x0106933C  40                      inc      eax                            
  0x0106933D  7002                    jo       0x1069341                      
  0x0106933F  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x0106933D (cond_jump)
  0x01069341  62540000                bound    edx, qword ptr [eax + eax]     
  0x01069345  8521                    test     dword ptr [ecx], esp           
  0x01069347  0010                    add      byte ptr [eax], dl             
  0x01069349  dc06                    fadd     qword ptr [esi]                
  0x0106934B  000400                  add      byte ptr [eax + eax], al       
  0x0106934E  0000                    add      byte ptr [eax], al             
  0x01069350  00e5                    add      ch, ah                         
  0x01069352  56                      push     esi                            
  0x01069353  00648521                add      byte ptr [ebp + eax*4 + 0x21], ah 
  0x01069357  0000                    add      byte ptr [eax], al             
  0x01069359  4d                      dec      ebp                            
  0x0106935A  54                      push     esp                            
  0x0106935B  0000                    add      byte ptr [eax], al             
  0x0106935D  3522005987              xor      eax, 0x87590022                
  0x01069362  2300                    and      eax, dword ptr [eax]           
  0x01069364  00f4                    add      ah, dh                         
  0x01069366  45                      inc      ebp                            
  0x01069367  0002                    add      byte ptr [edx], al             
  0x01069369  0000                    add      byte ptr [eax], al             
  0x0106936B  0000                    add      byte ptr [eax], al             
  0x0106936D  e556                    in       eax, 0x56                      
  0x0106936F  0065f4                  add      byte ptr [ebp - 0xc], ah       
  0x01069372  45                      inc      ebp                            
  0x01069373  00fe                    add      dh, bh                         
  0x01069376  ff00                    inc      dword ptr [eax]                
  0x01069378  17                      pop      ss                             
  0x01069379  7405                    je       0x1069380                      
  0x0106937B  0065f4                  add      byte ptr [ebp - 0xc], ah       
  0x0106937E  45                      inc      ebp                            
  0x0106937F  0002                    add      byte ptr [edx], al             
  0x01069381  0000                    add      byte ptr [eax], al             
  0x01069383  0011                    add      byte ptr [ecx], dl             
  0x01069385  94                      xchg     esp, eax                       
  0x01069386  0500584d20              add      eax, 0x204d5800                
  0x0106938B  007d00                  add      byte ptr [ebp], bh             
  0x0106938E  2000                    and      byte ptr [eax], al             
  0x01069390  4d                      dec      ebp                            
  0x01069391  7405                    je       0x1069398                      
  0x01069393  00d6                    add      dh, dl                         
  0x01069395  97                      xchg     edi, eax                       
  0x01069396  050000e556              add      eax, 0x56e50000                
  0x0106939B  0065f4                  add      byte ptr [ebp - 0xc], ah       
  0x0106939E  45                      inc      ebp                            
  0x0106939F  00fe                    add      dh, bh                         
  0x010693A2  ff00                    inc      dword ptr [eax]                
  0x010693A4  13740500                adc      esi, dword ptr [ebp + eax]     
  0x010693A8  65f4                    hlt                                     
  0x010693AA  45                      inc      ebp                            
  0x010693AB  0002                    add      byte ptr [edx], al             
  0x010693AD  0000                    add      byte ptr [eax], al             
  0x010693AF  0006                    add      byte ptr [esi], al             
  0x010693B1  94                      xchg     esp, eax                       
  0x010693B2  0500584d20              add      eax, 0x204d5800                
  0x010693B7  007d00                  add      byte ptr [ebp], bh             
  0x010693BA  2000                    and      byte ptr [eax], al             
  0x010693BC  42                      inc      edx                            
  0x010693BD  7405                    je       0x10693c4                      
  0x010693BF  00cb                    add      bl, cl                         
  0x010693C1  97                      xchg     edi, eax                       
  0x010693C2  0500d5a705              add      eax, 0x5a7d500                 
  0x010693C7  005c4520                add      byte ptr [ebp + eax*2 + 0x20], bl 
  0x010693CB  000da4050000            add      byte ptr [0x5a4], cl           
  0x010693D1  e556                    in       eax, 0x56                      
  0x010693D3  00540020                add      byte ptr [eax + eax + 0x20], dl 
  0x010693D7  0000                    add      byte ptr [eax], al             
  0x010693D9  4d                      dec      ebp                            
  0x010693DA  54                      push     esp                            
  0x010693DB  0000                    add      byte ptr [eax], al             
  0x010693DD  e556                    in       eax, 0x56                      
  0x010693DF  0050f4                  add      byte ptr [eax - 0xc], dl       
  0x010693E2  45                      inc      ebp                            
  0x010693E3  0002                    add      byte ptr [edx], al             
  0x010693E5  0000                    add      byte ptr [eax], al             
  0x010693E7  0000                    add      byte ptr [eax], al             
  0x010693E9  45                      inc      ebp                            
  0x010693EA  54                      push     esp                            
  0x010693EB  00c0                    add      al, al                         
  0x010693ED  0f05                    syscall                                 
  0x010693EF  0054f445                add      byte ptr [esp + esi*8 + 0x45], dl 
  0x010693F3  0002                    add      byte ptr [edx], al             
  0x010693F5  0000                    add      byte ptr [eax], al             
  0x010693F7  0000                    add      byte ptr [eax], al             
  0x010693F9  6554                    push     esp                            
  0x010693FB  00c7                    add      bh, al                         
  0x010693FD  0f05                    syscall                                 
  0x010693FF  0000                    add      byte ptr [eax], al             
  0x01069401  4e                      dec      esi                            
  0x01069402  2300                    and      eax, dword ptr [eax]           
  0x01069404  034d20                  add      ecx, dword ptr [ebp + 0x20]    
  0x01069407  0007                    add      byte ptr [edi], al             
  0x01069409  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106940A  050000e256              add      eax, 0x56e20000                
  0x0106940F  00540020                add      byte ptr [eax + eax + 0x20], dl 
  0x01069413  0000                    add      byte ptr [eax], al             
  0x01069415  62540000                bound    edx, qword ptr [eax + eax]     
  0x01069419  e556                    in       eax, 0x56                      
  0x0106941B  005000                  add      byte ptr [eax], dl             
  0x0106941E  2000                    and      byte ptr [eax], al             
  0x01069420  006554                  add      byte ptr [ebp + 0x54], ah      
  0x01069423  0000                    add      byte ptr [eax], al             
  0x01069425  e256                    loop     0x106947d                      
  0x01069427  00540020                add      byte ptr [eax + eax + 0x20], dl 
  0x0106942B  0000                    add      byte ptr [eax], al             
  0x0106942D  62540000                bound    edx, qword ptr [eax + eax]     
  0x01069431  e556                    in       eax, 0x56                      
  0x01069433  0050f4                  add      byte ptr [eax - 0xc], dl       
  0x01069436  45                      inc      ebp                            
  0x01069437  0002                    add      byte ptr [edx], al             
  0x01069439  0000                    add      byte ptr [eax], al             
  0x0106943B  005865                  add      byte ptr [eax + 0x65], bl      
  0x0106943E  54                      push     esp                            
  0x0106943F  008b0f050000            add      byte ptr [ebx + 0x50f], cl     
  0x01069445  35220000e2              xor      eax, 0xe2000022                
  0x0106944A  45                      inc      ebp                            
  0x0106944B  0010                    add      byte ptr [eax], dl             
  0x0106944D  dc06                    fadd     qword ptr [esi]                
  0x0106944F  000500000000            add      byte ptr [0], al               
  0x01069455  e556                    in       eax, 0x56                      
  0x01069457  006000                  add      byte ptr [eax], ah             
  0x0106945A  2000                    and      byte ptr [eax], al             
  0x0106945C  00852100004d            add      byte ptr [ebp + 0x4d000021], al 
  0x01069462  54                      push     esp                            
  0x01069463  0000                    add      byte ptr [eax], al             
  0x01069465  ae                      scasb    al, byte ptr es:[edi]          
  0x01069466  2300                    and      eax, dword ptr [eax]           
  0x01069468  55                      push     ebp                            
  0x01069469  35220009a4              xor      eax, 0xa4090022                
  0x0106946E  050000b422              add      eax, 0x22b40000                
  0x01069473  0010                    add      byte ptr [eax], dl             
  0x01069475  dc06                    fadd     qword ptr [esi]                
  0x01069477  0006                    add      byte ptr [esi], al             
  0x01069479  0000                    add      byte ptr [eax], al             
  0x0106947B  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01069425 (cond_jump)
  0x0106947D  cd44                    int      0x44                           
  0x0106947F  0010                    add      byte ptr [eax], dl             
  0x01069481  dd06                    fld      qword ptr [esi]                
  0x01069483  0002                    add      byte ptr [edx], al             
  0x01069485  0000                    add      byte ptr [eax], al             
  0x01069487  0000                    add      byte ptr [eax], al             
  0x01069489  5c                      pop      esp                            
  0x0106948A  44                      inc      esp                            
  0x0106948B  0000                    add      byte ptr [eax], al             
  0x0106948D  0000                    add      byte ptr [eax], al             
  0x0106948F  000c00                  add      byte ptr [eax + eax], cl       
  0x01069492  0000                    add      byte ptr [eax], al             
  0x01069494  00f0                    add      al, dh                         
  0x01069496  44                      inc      esp                            
  0x01069497  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106949A  0000                    add      byte ptr [eax], al             
  0x0106949C  00f0                    add      al, dh                         
  0x0106949E  56                      push     esi                            
  0x0106949F  00970b000045            add      byte ptr [edi + 0x4500000b], dl 
  0x010694A5  0020                    add      byte ptr [eax], ah             
  0x010694A7  0013                    add      byte ptr [ebx], dl             
  0x010694A9  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010694AA  0500009620              add      eax, 0x20960000                
  0x010694AF  0000                    add      byte ptr [eax], al             
  0x010694B1  f4                      hlt                                     
  0x010694B2  60                      pushal                                  
  0x010694B3  008001000000            add      byte ptr [eax + 1], al         
  0x010694B9  f4                      hlt                                     
  0x010694BA  61                      popal                                   
  0x010694BB  004102                  add      byte ptr [ecx + 2], al         
  0x010694BE  0000                    add      byte ptr [eax], al             
  0x010694C0  00f4                    add      ah, dh                         
  0x010694C2  56                      push     esi                            
  0x010694C3  00a50b000000            add      byte ptr [ebp + 0xb], ah       
  0x010694C9  c422                    les      esp, ptr [edx]                 
  0x010694CB  004000                  add      byte ptr [eax], al             
  0x010694CE  2000                    and      byte ptr [eax], al             
  0x010694D0  0092210000e2            add      byte ptr [edx - 0x1dffffdf], dl 
  0x010694D6  7100                    jno      0x10694d8                      
                                        ; XREF: 0x010694D6 (cond_jump)
  0x010694D8  10d9                    adc      cl, bl                         
  0x010694DA  06                      push     es                             
  0x010694DB  000500000000            add      byte ptr [0], al               
  0x010694E1  d9440000                fld      dword ptr [eax + eax]          
  0x010694E5  e056                    loopne   0x106953d                      
  0x010694E7  00481e                  add      byte ptr [eax + 0x1e], cl      
  0x010694EA  0c00                    or       al, 0                          
  0x010694EC  005854                  add      byte ptr [eax + 0x54], bl      
  0x010694EF  0010                    add      byte ptr [eax], dl             
  0x010694F1  0c05                    or       al, 5                          
  0x010694F3  0000                    add      byte ptr [eax], al             
  0x010694F6  56                      push     esi                            
  0x010694F7  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x010694FA  0000                    add      byte ptr [eax], al             
  0x010694FC  0300                    add      eax, dword ptr [eax]           
  0x010694FE  2000                    and      byte ptr [eax], al             
  0x01069500  0ca4                    or       al, 0xa4                       
  0x01069502  050000f460              add      eax, 0x60f40000                
  0x01069507  003502000000            add      byte ptr [2], dh               
  0x0106950D  f4                      hlt                                     
  0x0106950E  61                      popal                                   
  0x0106950F  00f6                    add      dh, dh                         
  0x01069511  0200                    add      al, byte ptr [eax]             
  0x01069513  0000                    add      byte ptr [eax], al             
  0x01069515  07                      pop      es                             
  0x01069516  3900                    cmp      dword ptr [eax], eax           
  0x01069518  10d9                    adc      cl, bl                         
  0x0106951A  06                      push     es                             
  0x0106951B  000500000000            add      byte ptr [0], al               
  0x01069521  d9440000                fld      dword ptr [eax + eax]          
  0x01069525  e056                    loopne   0x106957d                      
  0x01069527  00481e                  add      byte ptr [eax + 0x1e], cl      
  0x0106952A  0c00                    or       al, 0                          
  0x0106952C  005854                  add      byte ptr [eax + 0x54], bl      
  0x0106952F  000c00                  add      byte ptr [eax + eax], cl       
  0x01069532  0000                    add      byte ptr [eax], al             
  0x01069534  20f4                    and      ah, dh                         
  0x01069536  0500ffffff              add      eax, 0xffffff00                
  0x0106953B  00a0610400a0            add      byte ptr [eax - 0x5ffffb9f], ah 
  0x01069541  620400                  bound    eax, qword ptr [eax + eax]     
  0x01069544  a0640400a0              mov      al, byte ptr [0xa0000464]      
  0x01069549  650400                  add      al, 0                          
  0x0106954C  a0660400b8              mov      al, byte ptr [0xb8000466]      
  0x01069551  f30000                  add      byte ptr [eax], al             
  0x01069554  00f4                    add      ah, dh                         
  0x01069556  44                      inc      esp                            
  0x01069557  0000                    add      byte ptr [eax], al             
  0x01069559  0000                    add      byte ptr [eax], al             
  0x0106955B  004d00                  add      byte ptr [ebp], cl             
  0x0106955E  2000                    and      byte ptr [eax], al             
  0x01069560  0ca4                    or       al, 0xa4                       
  0x01069562  050000f444              add      eax, 0x44f40000                
  0x01069567  0010                    add      byte ptr [eax], dl             
  0x01069569  0000                    add      byte ptr [eax], al             
  0x0106956B  004d00                  add      byte ptr [ebp], cl             
  0x0106956E  2000                    and      byte ptr [eax], al             
  0x01069570  4a                      dec      edx                            
  0x01069571  100d00110000            adc      byte ptr [0x1100], cl          
  0x01069577  0000                    add      byte ptr [eax], al             
  0x01069579  0030                    add      byte ptr [eax], dh             
  0x0106957B  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x01069525 (cond_jump)
  0x0106957D  f4                      hlt                                     
  0x0106957E  56                      push     esi                            
  0x0106957F  0000                    add      byte ptr [eax], al             
  0x01069581  0000                    add      byte ptr [eax], al             
  0x01069583  0000                    add      byte ptr [eax], al             
  0x01069585  f4                      hlt                                     
  0x01069586  57                      push     edi                            
  0x01069587  00ff                    add      bh, bh                         
  0x0106958A  ff00                    inc      dword ptr [eax]                
  0x0106958C  0c00                    or       al, 0                          
  0x0106958E  0000                    add      byte ptr [eax], al             
  0x01069590  1300                    adc      eax, dword ptr [eax]           
  0x01069592  2000                    and      byte ptr [eax], al             
  0x01069594  007056                  add      byte ptr [eax + 0x56], dh      
  0x01069597  0012                    add      byte ptr [edx], dl             
  0x01069599  0900                    or       dword ptr [eax], eax           
  0x0106959B  0000                    add      byte ptr [eax], al             
  0x0106959D  0030                    add      byte ptr [eax], dh             
  0x0106959F  0000                    add      byte ptr [eax], al             
  0x010695A1  f4                      hlt                                     
  0x010695A2  56                      push     esi                            
  0x010695A3  0000                    add      byte ptr [eax], al             
  0x010695A5  0000                    add      byte ptr [eax], al             
  0x010695A7  0000                    add      byte ptr [eax], al             
  0x010695A9  f4                      hlt                                     
  0x010695AA  57                      push     edi                            
  0x010695AB  0008                    add      byte ptr [eax], cl             
  0x010695AD  06                      push     es                             
  0x010695AE  0000                    add      byte ptr [eax], al             
  0x010695B0  0c00                    or       al, 0                          
  0x010695B2  0000                    add      byte ptr [eax], al             
  0x010695B4  5c                      pop      esp                            
  0x010695B5  08050080100d            or       byte ptr [0xd108000], al       
  0x010695BB  009600000000            add      byte ptr [esi], dl             
  0x010695C2  56                      push     esi                            
  0x010695C3  00960b000003            add      byte ptr [esi + 0x300000b], dl 
  0x010695C9  0020                    add      byte ptr [eax], ah             
  0x010695CB  005374                  add      byte ptr [ebx + 0x74], dl      
  0x010695CE  050080100d              add      eax, 0xd108000                 
  0x010695D3  00c4                    add      ah, al                         
  0x010695D5  0000                    add      byte ptr [eax], al             
  0x010695D7  0000                    add      byte ptr [eax], al             
  0x010695DA  56                      push     esi                            
  0x010695DB  00960b000003            add      byte ptr [esi + 0x300000b], dl 
  0x010695E1  0020                    add      byte ptr [eax], ah             
  0x010695E3  004d74                  add      byte ptr [ebp + 0x74], cl      
  0x010695E6  050080100d              add      eax, 0xd108000                 
  0x010695EB  006e01                  add      byte ptr [esi + 1], ch         
  0x010695EE  0000                    add      byte ptr [eax], al             
  0x010695F0  80100d                  adc      byte ptr [eax], 0xd            
  0x010695F3  00b101000080            add      byte ptr [ecx - 0x7fffffff], dh 
  0x010695F9  100d00f40100            adc      byte ptr [0x1f400], cl         
  0x010695FF  0000                    add      byte ptr [eax], al             
  0x01069601  002400                  add      byte ptr [eax + eax], ah       
  0x01069604  007044                  add      byte ptr [eax + 0x44], dh      
  0x01069607  0031                    add      byte ptr [ecx], dh             
  0x01069609  0900                    or       dword ptr [eax], eax           
  0x0106960B  0000                    add      byte ptr [eax], al             
  0x0106960E  56                      push     esi                            
  0x0106960F  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01069612  0000                    add      byte ptr [eax], al             
  0x01069614  00f0                    add      al, dh                         
  0x01069616  44                      inc      esp                            
  0x01069617  00970b000045            add      byte ptr [edi + 0x4500000b], dl 
  0x0106961D  0020                    add      byte ptr [eax], ah             
  0x0106961F  0009                    add      byte ptr [ecx], cl             
  0x01069621  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01069622  050080100d              add      eax, 0xd108000                 
  0x01069627  004601                  add      byte ptr [esi + 1], al         
  0x0106962A  0000                    add      byte ptr [eax], al             
  0x0106962C  80100d                  adc      byte ptr [eax], 0xd            
  0x0106962F  002f                    add      byte ptr [edi], ch             
  0x01069631  0200                    add      al, byte ptr [eax]             
  0x01069633  0000                    add      byte ptr [eax], al             
  0x01069635  7055                    jo       0x106968c                      
  0x01069637  0031                    add      byte ptr [ecx], dh             
  0x01069639  0900                    or       dword ptr [eax], eax           
  0x0106963B  0080100d0017            add      byte ptr [eax + 0x17000d10], al 
  0x01069641  0300                    add      eax, dword ptr [eax]           
  0x01069643  0080100d002f            add      byte ptr [eax + 0x2f000d10], al 
  0x01069649  0300                    add      eax, dword ptr [eax]           
  0x0106964B  0080100d003e            add      byte ptr [eax + 0x3e000d10], al 
  0x01069651  0300                    add      eax, dword ptr [eax]           
  0x01069653  0080100d0099            add      byte ptr [eax - 0x66fff2f0], al 
  0x01069659  0300                    add      eax, dword ptr [eax]           
  0x0106965B  0080100d0055            add      byte ptr [eax + 0x55000d10], al 
  0x01069661  0300                    add      eax, dword ptr [eax]           
  0x01069663  0000                    add      byte ptr [eax], al             
  0x01069666  56                      push     esi                            
  0x01069667  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106966A  0000                    add      byte ptr [eax], al             
  0x0106966C  0300                    add      eax, dword ptr [eax]           
  0x0106966E  2000                    and      byte ptr [eax], al             
  0x01069670  0a10                    or       dl, byte ptr [eax]             
  0x01069672  0d00400400              or       eax, 0x44000                   
  0x01069677  0080100d00a2            add      byte ptr [eax - 0x5dfff2f0], al 
  0x0106967D  0300                    add      eax, dword ptr [eax]           
  0x0106967F  0080100d00cf            add      byte ptr [eax - 0x30fff2f0], al 
  0x01069685  0300                    add      eax, dword ptr [eax]           
  0x01069687  0080100d00ea            add      byte ptr [eax - 0x15fff2f0], al 
  0x0106968D  0300                    add      eax, dword ptr [eax]           
  0x0106968F  0080100d0081            add      byte ptr [eax - 0x7efff2f0], al 
  0x01069696  ff00                    inc      dword ptr [eax]                
  0x01069698  1300                    adc      eax, dword ptr [eax]           
  0x0106969A  2000                    and      byte ptr [eax], al             
  0x0106969C  1b10                    sbb      edx, dword ptr [eax]           
  0x0106969E  2100                    and      dword ptr [eax], eax           
  0x010696A0  0c00                    or       al, 0                          
  0x010696A2  0000                    add      byte ptr [eax], al             
  0x010696A4  005820                  add      byte ptr [eax + 0x20], bl      
  0x010696A7  0000                    add      byte ptr [eax], al             
  0x010696A9  d8440000                fadd     dword ptr [eax + eax]          
  0x010696AD  7044                    jo       0x10696f3                      
  0x010696AF  00420b                  add      byte ptr [edx + 0xb], al       
  0x010696B2  0000                    add      byte ptr [eax], al             
  0x010696B4  00d8                    add      al, bl                         
  0x010696B6  44                      inc      esp                            
  0x010696B7  0000                    add      byte ptr [eax], al             
  0x010696B9  7044                    jo       0x10696ff                      
  0x010696BB  00430b                  add      byte ptr [ebx + 0xb], al       
  0x010696BE  0000                    add      byte ptr [eax], al             
  0x010696C0  00d8                    add      al, bl                         
  0x010696C2  44                      inc      esp                            
  0x010696C3  0000                    add      byte ptr [eax], al             
  0x010696C5  7044                    jo       0x106970b                      
  0x010696C7  00440b00                add      byte ptr [ebx + ecx], al       
  0x010696CB  0000                    add      byte ptr [eax], al             
  0x010696CD  d85700                  fcom     dword ptr [edi]                
  0x010696D0  90                      nop                                     
  0x010696D1  180c00                  sbb      byte ptr [eax + eax], cl       
  0x010696D4  2420                    and      al, 0x20                       
  0x010696D6  0000                    add      byte ptr [eax], al             
  0x010696D8  007050                  add      byte ptr [eax + 0x50], dh      
  0x010696DB  007b0b                  add      byte ptr [ebx + 0xb], bh       
  0x010696DE  0000                    add      byte ptr [eax], al             
  0x010696E0  90                      nop                                     
  0x010696E1  180c00                  sbb      byte ptr [eax + eax], cl       
  0x010696E4  1b10                    sbb      edx, dword ptr [eax]           
  0x010696E6  0000                    add      byte ptr [eax], al             
  0x010696E8  007050                  add      byte ptr [eax + 0x50], dh      
  0x010696EB  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x010696EE  0000                    add      byte ptr [eax], al             
  0x010696F0  90                      nop                                     
  0x010696F1  180c00                  sbb      byte ptr [eax + eax], cl       
  0x010696F4  1830                    sbb      byte ptr [eax], dh             
  0x010696F6  0000                    add      byte ptr [eax], al             
  0x010696F8  007050                  add      byte ptr [eax + 0x50], dh      
  0x010696FB  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x010696FE  0000                    add      byte ptr [eax], al             
  0x01069700  00d8                    add      al, bl                         
  0x01069702  44                      inc      esp                            
  0x01069703  0000                    add      byte ptr [eax], al             
  0x01069705  7044                    jo       0x106974b                      
  0x01069707  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106970A  0000                    add      byte ptr [eax], al             
  0x0106970C  00d8                    add      al, bl                         
  0x0106970E  44                      inc      esp                            
  0x0106970F  0000                    add      byte ptr [eax], al             
  0x01069711  7044                    jo       0x1069757                      
  0x01069713  00460b                  add      byte ptr [esi + 0xb], al       
  0x01069716  0000                    add      byte ptr [eax], al             
  0x01069718  00d8                    add      al, bl                         
  0x0106971A  44                      inc      esp                            
  0x0106971B  0000                    add      byte ptr [eax], al             
  0x0106971D  7044                    jo       0x1069763                      
  0x0106971F  00470b                  add      byte ptr [edi + 0xb], al       
  0x01069722  0000                    add      byte ptr [eax], al             
  0x01069724  00d8                    add      al, bl                         
  0x01069726  57                      push     edi                            
  0x01069727  0090180c0020            add      byte ptr [eax + 0x20000c18], dl 
  0x0106972D  60                      pushal                                  
  0x0106972E  0000                    add      byte ptr [eax], al             
  0x01069730  007050                  add      byte ptr [eax + 0x50], dh      
  0x01069733  007c0b00                add      byte ptr [ebx + ecx], bh       
  0x01069737  0000                    add      byte ptr [eax], al             
  0x01069739  d85700                  fcom     dword ptr [edi]                
  0x0106973C  90                      nop                                     
  0x0106973D  180c00                  sbb      byte ptr [eax + eax], cl       
  0x01069740  2310                    and      edx, dword ptr [eax]           
  0x01069742  0000                    add      byte ptr [eax], al             
  0x01069744  007050                  add      byte ptr [eax + 0x50], dh      
  0x01069747  003d02000090            add      byte ptr [0x90000002], bh      
  0x0106974D  180c00                  sbb      byte ptr [eax + eax], cl       
  0x01069750  2210                    and      dl, byte ptr [eax]             
  0x01069752  0000                    add      byte ptr [eax], al             
  0x01069754  007050                  add      byte ptr [eax + 0x50], dh      
                                        ; XREF: 0x01069711 (cond_jump)
  0x01069757  003e                    add      byte ptr [esi], bh             
  0x01069759  0200                    add      al, byte ptr [eax]             
  0x0106975B  0090180c0021            add      byte ptr [eax + 0x21000c18], dl 
  0x01069761  1000                    adc      byte ptr [eax], al             
                                        ; XREF: 0x0106971D (cond_jump)
  0x01069763  0000                    add      byte ptr [eax], al             
  0x01069765  7050                    jo       0x10697b7                      
  0x01069767  003f                    add      byte ptr [edi], bh             
  0x01069769  0200                    add      al, byte ptr [eax]             
  0x0106976B  0090180c0018            add      byte ptr [eax + 0x18000c18], dl 
  0x01069771  40                      inc      eax                            
  0x01069772  0000                    add      byte ptr [eax], al             
  0x01069774  007050                  add      byte ptr [eax + 0x50], dh      
  0x01069777  004002                  add      byte ptr [eax + 2], al         
  0x0106977A  0000                    add      byte ptr [eax], al             
  0x0106977C  00d8                    add      al, bl                         
  0x0106977E  61                      popal                                   
  0x0106977F  0000                    add      byte ptr [eax], al             
  0x01069781  06                      push     es                             
  0x01069782  3800                    cmp      byte ptr [eax], al             
  0x01069784  004820                  add      byte ptr [eax + 0x20], cl      
  0x01069787  0000                    add      byte ptr [eax], al             
  0x01069789  d95700                  fst      dword ptr [edi]                
  0x0106978C  90                      nop                                     
  0x0106978D  180c00                  sbb      byte ptr [eax + eax], cl       
  0x01069790  1a20                    sbb      ah, byte ptr [eax]             
  0x01069792  0000                    add      byte ptr [eax], al             
  0x01069794  007050                  add      byte ptr [eax + 0x50], dh      
  0x01069797  004e0b                  add      byte ptr [esi + 0xb], cl       
  0x0106979A  0000                    add      byte ptr [eax], al             
  0x0106979C  00d9                    add      cl, bl                         
  0x0106979E  57                      push     edi                            
  0x0106979F  008e5f010000            add      byte ptr [esi + 0x15f], cl     
  0x010697A5  7057                    jo       0x10697fe                      
  0x010697A7  00490b                  add      byte ptr [ecx + 0xb], cl       
  0x010697AA  0000                    add      byte ptr [eax], al             
  0x010697AC  00d8                    add      al, bl                         
  0x010697AE  57                      push     edi                            
  0x010697AF  0090180c0018            add      byte ptr [eax + 0x18000c18], dl 
  0x010697B5  800000                  add      byte ptr [eax], 0              
  0x010697B8  007050                  add      byte ptr [eax + 0x50], dh      
  0x010697BB  00410b                  add      byte ptr [ecx + 0xb], al       
  0x010697BE  0000                    add      byte ptr [eax], al             
  0x010697C0  90                      nop                                     
  0x010697C1  180c00                  sbb      byte ptr [eax + eax], cl       
  0x010697C4  208000000070            and      byte ptr [eax + 0x70000000], al 
  0x010697CA  50                      push     eax                            
  0x010697CB  00400b                  add      byte ptr [eax + 0xb], al       
  0x010697CE  0000                    add      byte ptr [eax], al             
  0x010697D0  00d8                    add      al, bl                         
  0x010697D2  57                      push     edi                            
  0x010697D3  0090180c0018            add      byte ptr [eax + 0x18000c18], dl 
  0x010697D9  1000                    adc      byte ptr [eax], al             
  0x010697DB  0000                    add      byte ptr [eax], al             
  0x010697DD  7050                    jo       0x106982f                      
  0x010697DF  004c0b00                add      byte ptr [ebx + ecx], cl       
  0x010697E3  0090180c0019            add      byte ptr [eax + 0x19000c18], dl 
  0x010697E9  1000                    adc      byte ptr [eax], al             
  0x010697EB  0000                    add      byte ptr [eax], al             
  0x010697ED  7050                    jo       0x106983f                      
  0x010697EF  004a0b                  add      byte ptr [edx + 0xb], cl       
  0x010697F2  0000                    add      byte ptr [eax], al             
  0x010697F4  00d8                    add      al, bl                         
  0x010697F6  57                      push     edi                            
  0x010697F7  0000                    add      byte ptr [eax], al             
  0x010697F9  7057                    jo       0x1069852                      
  0x010697FB  004b0b                  add      byte ptr [ebx + 0xb], cl       
                                        ; XREF: 0x010697A5 (cond_jump)
  0x010697FE  0000                    add      byte ptr [eax], al             
  0x01069800  00e0                    add      al, ah                         
  0x01069802  57                      push     edi                            
  0x01069803  0000                    add      byte ptr [eax], al             
  0x01069805  7057                    jo       0x106985e                      
  0x01069807  004d0b                  add      byte ptr [ebp + 0xb], cl       
  0x0106980A  0000                    add      byte ptr [eax], al             
  0x0106980C  0c00                    or       al, 0                          
  0x0106980E  0000                    add      byte ptr [eax], al             
  0x01069810  00f4                    add      ah, dh                         
  0x01069812  44                      inc      esp                            
  0x01069813  0000                    add      byte ptr [eax], al             
  0x01069815  0000                    add      byte ptr [eax], al             
  0x01069817  0000                    add      byte ptr [eax], al             
  0x01069819  7044                    jo       0x106985f                      
  0x0106981B  00960b000000            add      byte ptr [esi + 0xb], dl       
  0x01069822  56                      push     esi                            
  0x01069823  004002                  add      byte ptr [eax + 2], al         
  0x01069826  0000                    add      byte ptr [eax], al             
  0x01069828  00f4                    add      ah, dh                         
  0x0106982A  44                      inc      esp                            
  0x0106982B  0009                    add      byte ptr [ecx], cl             
  0x0106982D  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x010697DD (cond_jump)
  0x0106982F  004500                  add      byte ptr [ebp], al             
  0x01069832  2000                    and      byte ptr [eax], al             
  0x01069834  41                      inc      ecx                            
  0x01069835  27                      daa                                     
  0x01069836  2000                    and      byte ptr [eax], al             
  0x01069838  007054                  add      byte ptr [eax + 0x54], dh      
  0x0106983B  004002                  add      byte ptr [eax + 2], al         
  0x0106983E  0000                    add      byte ptr [eax], al             
  0x01069840  00f0                    add      al, dh                         
  0x01069842  56                      push     esi                            
  0x01069843  00490b                  add      byte ptr [ecx + 0xb], cl       
  0x01069846  0000                    add      byte ptr [eax], al             
  0x01069848  00f4                    add      ah, dh                         
  0x0106984A  44                      inc      esp                            
  0x0106984B  001f                    add      byte ptr [edi], bl             
  0x0106984D  0000                    add      byte ptr [eax], al             
  0x0106984F  0045f4                  add      byte ptr [ebp - 0xc], al       
                                        ; XREF: 0x010697F9 (cond_jump)
  0x01069852  45                      inc      ebp                            
  0x01069853  0000                    add      byte ptr [eax], al             
  0x01069855  0000                    add      byte ptr [eax], al             
  0x01069857  004127                  add      byte ptr [ecx + 0x27], al      
  0x0106985A  2000                    and      byte ptr [eax], al             
  0x0106985C  650020                  add      byte ptr gs:[eax], ah          
                                        ; XREF: 0x01069819 (cond_jump)
  0x0106985F  006129                  add      byte ptr [ecx + 0x29], ah      
  0x01069862  2000                    and      byte ptr [eax], al             
  0x01069864  007054                  add      byte ptr [eax + 0x54], dh      
  0x01069867  00490b                  add      byte ptr [ecx + 0xb], cl       
  0x0106986A  0000                    add      byte ptr [eax], al             
  0x0106986C  00f0                    add      al, dh                         
  0x0106986E  56                      push     esi                            
  0x0106986F  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x01069872  0000                    add      byte ptr [eax], al             
  0x01069874  00f4                    add      ah, dh                         
  0x01069876  44                      inc      esp                            
  0x01069877  0007                    add      byte ptr [edi], al             
  0x01069879  0000                    add      byte ptr [eax], al             
  0x0106987B  0045f4                  add      byte ptr [ebp - 0xc], al       
  0x0106987E  45                      inc      ebp                            
  0x0106987F  0006                    add      byte ptr [esi], al             
  0x01069881  0000                    add      byte ptr [eax], al             
  0x01069883  0014a4                  add      byte ptr [esp], dl             
  0x01069886  050065f444              add      eax, 0x44f46500                
  0x0106988B  0003                    add      byte ptr [ebx], al             
  0x0106988D  0000                    add      byte ptr [eax], al             
  0x0106988F  0011                    add      byte ptr [ecx], dl             
  0x01069891  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01069892  050045f445              add      eax, 0x45f44500                
  0x01069897  0002                    add      byte ptr [edx], al             
  0x01069899  0000                    add      byte ptr [eax], al             
  0x0106989B  000e                    add      byte ptr [esi], cl             
  0x0106989D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106989E  050065f444              add      eax, 0x44f46500                
  0x010698A3  000400                  add      byte ptr [eax + eax], al       
  0x010698A6  0000                    add      byte ptr [eax], al             
  0x010698A8  0ba4050045f445          or       esp, dword ptr [ebp + eax + 0x45f44500] 
  0x010698AF  000500000008            add      byte ptr [0x8000000], al       
  0x010698B5  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x010698B6  050065f444              add      eax, 0x44f46500                
  0x010698BB  0001                    add      byte ptr [ecx], al             
  0x010698BD  0000                    add      byte ptr [eax], al             
  0x010698BF  0005a4050000            add      byte ptr [0x5a4], al           
  0x010698C5  f4                      hlt                                     
  0x010698C6  44                      inc      esp                            
  0x010698C7  0002                    add      byte ptr [edx], al             
  0x010698C9  0000                    add      byte ptr [eax], al             
  0x010698CB  0000                    add      byte ptr [eax], al             
  0x010698CD  7044                    jo       0x1069913                      
  0x010698CF  00960b000000            add      byte ptr [esi + 0xb], dl       
  0x010698D5  7054                    jo       0x106992b                      
  0x010698D7  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x010698DA  0000                    add      byte ptr [eax], al             
  0x010698DC  0c00                    or       al, 0                          
  0x010698DE  0000                    add      byte ptr [eax], al             
  0x010698E0  00f0                    add      al, dh                         
  0x010698E2  56                      push     esi                            
  0x010698E3  0012                    add      byte ptr [edx], dl             
  0x010698E5  0900                    or       dword ptr [eax], eax           
  0x010698E7  0000                    add      byte ptr [eax], al             
  0x010698E9  f4                      hlt                                     
  0x010698EA  44                      inc      esp                            
  0x010698EB  006507                  add      byte ptr [ebp + 7], ah         
  0x010698EE  0200                    add      al, byte ptr [eax]             
  0x010698F0  45                      inc      ebp                            
  0x010698F1  0020                    add      byte ptr [eax], ah             
  0x010698F3  0006                    add      byte ptr [esi], al             
  0x010698F5  2405                    and      al, 5                          
  0x010698F7  0000                    add      byte ptr [eax], al             
  0x010698FA  56                      push     esi                            
  0x010698FB  00400b                  add      byte ptr [eax + 0xb], al       
  0x010698FE  0000                    add      byte ptr [eax], al             
  0x01069900  0300                    add      eax, dword ptr [eax]           
  0x01069902  2000                    and      byte ptr [eax], al             
  0x01069904  5e                      pop      esi                            
  0x01069905  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01069906  05000c0000              add      eax, 0xc00                     
  0x0106990B  0013                    add      byte ptr [ebx], dl             
  0x0106990D  f4                      hlt                                     
  0x0106990E  60                      pushal                                  
  0x0106990F  00fd                    add      ch, bh                         
  0x01069911  0400                    add      al, 0                          
                                        ; XREF: 0x010698CD (cond_jump)
  0x01069913  009006060003            add      byte ptr [eax + 0x3000606], dl 
  0x01069919  0000                    add      byte ptr [eax], al             
  0x0106991B  0000                    add      byte ptr [eax], al             
  0x0106991D  58                      pop      eax                            
  0x0106991E  54                      push     esp                            
  0x0106991F  0000                    add      byte ptr [eax], al             
  0x01069921  58                      pop      eax                            
  0x01069922  54                      push     esp                            
  0x01069923  0013                    add      byte ptr [ebx], dl             
  0x01069925  f4                      hlt                                     
  0x01069926  60                      pushal                                  
  0x01069927  00a805000090            add      byte ptr [eax - 0x6ffffffb], ch 
  0x0106992D  0506000200              add      eax, 0x20006                   
  0x01069932  0000                    add      byte ptr [eax], al             
  0x01069934  005854                  add      byte ptr [eax + 0x54], bl      
  0x01069937  0013                    add      byte ptr [ebx], dl             
  0x01069939  f4                      hlt                                     
  0x0106993A  60                      pushal                                  
  0x0106993B  007b05                  add      byte ptr [ebx + 5], bh         
  0x0106993E  0000                    add      byte ptr [eax], al             
  0x01069940  90                      nop                                     
  0x01069941  2806                    sub      byte ptr [esi], al             
  0x01069943  0002                    add      byte ptr [edx], al             
  0x01069945  0000                    add      byte ptr [eax], al             
  0x01069947  0000                    add      byte ptr [eax], al             
  0x01069949  58                      pop      eax                            
  0x0106994A  54                      push     esp                            
  0x0106994B  0013                    add      byte ptr [ebx], dl             
  0x0106994D  f4                      hlt                                     
  0x0106994E  60                      pushal                                  
  0x0106994F  00ae05000090            add      byte ptr [esi - 0x6ffffffb], ch 
  0x01069955  5a                      pop      edx                            
  0x01069956  06                      push     es                             
  0x01069957  0002                    add      byte ptr [edx], al             
  0x01069959  0000                    add      byte ptr [eax], al             
  0x0106995B  0000                    add      byte ptr [eax], al             
  0x0106995D  58                      pop      eax                            
  0x0106995E  54                      push     esp                            
  0x0106995F  0013                    add      byte ptr [ebx], dl             
  0x01069961  f4                      hlt                                     
  0x01069962  60                      pushal                                  
  0x01069963  0008                    add      byte ptr [eax], cl             
  0x01069965  06                      push     es                             
  0x01069966  0000                    add      byte ptr [eax], al             
  0x01069968  90                      nop                                     
  0x01069969  0506000200              add      eax, 0x20006                   
  0x0106996E  0000                    add      byte ptr [eax], al             
  0x01069970  005854                  add      byte ptr [eax + 0x54], bl      
  0x01069973  0013                    add      byte ptr [ebx], dl             
  0x01069975  f4                      hlt                                     
  0x01069976  60                      pushal                                  
  0x01069977  000d06000090            add      byte ptr [0x90000006], cl      
  0x0106997D  0506000200              add      eax, 0x20006                   
  0x01069982  0000                    add      byte ptr [eax], al             
  0x01069984  005854                  add      byte ptr [eax + 0x54], bl      
  0x01069987  0013                    add      byte ptr [ebx], dl             
  0x01069989  f4                      hlt                                     
  0x0106998A  60                      pushal                                  
  0x0106998B  0009                    add      byte ptr [ecx], cl             
  0x0106998D  0500009010              add      eax, 0x10900000                
  0x01069992  06                      push     es                             
  0x01069993  0002                    add      byte ptr [edx], al             
  0x01069995  0000                    add      byte ptr [eax], al             
  0x01069997  0000                    add      byte ptr [eax], al             
  0x01069999  58                      pop      eax                            
  0x0106999A  54                      push     esp                            
  0x0106999B  0013                    add      byte ptr [ebx], dl             
  0x0106999D  f4                      hlt                                     
  0x0106999E  60                      pushal                                  
  0x0106999F  0019                    add      byte ptr [ecx], bl             
  0x010699A1  0500009008              add      eax, 0x8900000                 
  0x010699A6  06                      push     es                             
  0x010699A7  0002                    add      byte ptr [edx], al             
  0x010699A9  0000                    add      byte ptr [eax], al             
  0x010699AB  0000                    add      byte ptr [eax], al             
  0x010699AD  58                      pop      eax                            
  0x010699AE  54                      push     esp                            
  0x010699AF  0013                    add      byte ptr [ebx], dl             
  0x010699B1  f4                      hlt                                     
  0x010699B2  60                      pushal                                  
  0x010699B3  0021                    add      byte ptr [ecx], ah             
  0x010699B5  050000903c              add      eax, 0x3c900000                
  0x010699BA  06                      push     es                             
  0x010699BB  0002                    add      byte ptr [edx], al             
  0x010699BD  0000                    add      byte ptr [eax], al             
  0x010699BF  0000                    add      byte ptr [eax], al             
  0x010699C1  58                      pop      eax                            
  0x010699C2  54                      push     esp                            
  0x010699C3  0013                    add      byte ptr [ebx], dl             
  0x010699C5  f4                      hlt                                     
  0x010699C6  60                      pushal                                  
  0x010699C7  005d05                  add      byte ptr [ebp + 5], bl         
  0x010699CA  0000                    add      byte ptr [eax], al             
  0x010699CC  90                      nop                                     
  0x010699CD  1e                      push     ds                             
  0x010699CE  06                      push     es                             
  0x010699CF  0002                    add      byte ptr [edx], al             
  0x010699D1  0000                    add      byte ptr [eax], al             
  0x010699D3  0000                    add      byte ptr [eax], al             
  0x010699D5  58                      pop      eax                            
  0x010699D6  54                      push     esp                            
  0x010699D7  0013                    add      byte ptr [ebx], dl             
  0x010699D9  f4                      hlt                                     
  0x010699DA  60                      pushal                                  
  0x010699DB  0012                    add      byte ptr [edx], dl             
  0x010699DD  06                      push     es                             
  0x010699DE  0000                    add      byte ptr [eax], al             
  0x010699E0  93                      xchg     ebx, eax                       
  0x010699E1  0006                    add      byte ptr [esi], al             
  0x010699E3  0002                    add      byte ptr [edx], al             
  0x010699E5  0000                    add      byte ptr [eax], al             
  0x010699E7  0000                    add      byte ptr [eax], al             
  0x010699E9  58                      pop      eax                            
  0x010699EA  54                      push     esp                            
  0x010699EB  0000                    add      byte ptr [eax], al             
  0x010699ED  f4                      hlt                                     
  0x010699EE  44                      inc      esp                            
  0x010699EF  006507                  add      byte ptr [ebp + 7], ah         
  0x010699F2  0200                    add      al, byte ptr [eax]             
  0x010699F4  007044                  add      byte ptr [eax + 0x44], dh      
  0x010699F7  0012                    add      byte ptr [edx], dl             
  0x010699F9  0900                    or       dword ptr [eax], eax           
  0x010699FB  0000                    add      byte ptr [eax], al             
  0x010699FD  f4                      hlt                                     
  0x010699FE  44                      inc      esp                            
  0x010699FF  0000                    add      byte ptr [eax], al             
  0x01069A01  0000                    add      byte ptr [eax], al             
  0x01069A03  0000                    add      byte ptr [eax], al             
  0x01069A05  7044                    jo       0x1069a4b                      
  0x01069A07  00960b000000            add      byte ptr [esi + 0xb], dl       
  0x01069A0D  f4                      hlt                                     
  0x01069A0E  61                      popal                                   
  0x01069A0F  00c2                    add      dl, al                         
  0x01069A11  0f0000                  sldt     word ptr [eax]                 
  0x01069A14  00f0                    add      al, dh                         
  0x01069A16  7100                    jno      0x1069a18                      
                                        ; XREF: 0x01069A16 (cond_jump)
  0x01069A18  7d0b                    jge      0x1069a25                      
  0x01069A1A  0000                    add      byte ptr [eax], al             
  0x01069A1C  00f0                    add      al, dh                         
  0x01069A1E  44                      inc      esp                            
  0x01069A1F  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x01069A22  0000                    add      byte ptr [eax], al             
  0x01069A24  00e9                    add      cl, ch                         
  0x01069A26  5e                      pop      esi                            
  0x01069A27  004070                  add      byte ptr [eax + 0x70], al      
  0x01069A2A  54                      push     esp                            
  0x01069A2B  00970b000000            add      byte ptr [edi + 0xb], dl       
  0x01069A31  7054                    jo       0x1069a87                      
  0x01069A33  00980b00001b            add      byte ptr [eax + 0x1b00000b], bl 
  0x01069A3A  44                      inc      esp                            
  0x01069A3B  00970b000013            add      byte ptr [edi + 0x1300000b], dl 
  0x01069A41  052d004d02              add      eax, 0x24d002d                 
  0x01069A46  2c00                    sub      al, 0                          
  0x01069A48  5a                      pop      edx                            
  0x01069A49  94                      xchg     esp, eax                       
  0x01069A4A  05001bf044              add      eax, 0x44f01b00                
  0x01069A4F  00980b000013            add      byte ptr [eax + 0x1300000b], bl 
  0x01069A55  06                      push     es                             
  0x01069A56  2d004d022c              sub      eax, 0x2c024d00                
  0x01069A5B  005594                  add      byte ptr [ebp - 0x6c], dl      
  0x01069A5E  050000f056              add      eax, 0x56f00000                
  0x01069A63  007c0b00                add      byte ptr [ebx + ecx], bh       
  0x01069A67  0023                    add      byte ptr [ebx], ah             
  0x01069A69  0020                    add      byte ptr [eax], ah             
  0x01069A6B  0000                    add      byte ptr [eax], al             
  0x01069A6D  7054                    jo       0x1069ac3                      
  0x01069A6F  00990b00001b            add      byte ptr [ecx + 0x1b00000b], bl 
  0x01069A76  44                      inc      esp                            
  0x01069A77  007b0b                  add      byte ptr [ebx + 0xb], bh       
  0x01069A7A  0000                    add      byte ptr [eax], al             
  0x01069A7C  1303                    adc      eax, dword ptr [ebx]           
  0x01069A7E  2d004d042c              sub      eax, 0x2c044d00                
  0x01069A83  004b94                  add      byte ptr [ebx - 0x6c], cl      
  0x01069A86  05001bf044              add      eax, 0x44f01b00                
  0x01069A8B  00990b000013            add      byte ptr [ecx + 0x1300000b], bl 
  0x01069A91  132d004d032c            adc      ebp, dword ptr [0x2c034d00]    
  0x01069A97  004694                  add      byte ptr [esi - 0x6c], al      
  0x01069A9A  050000f056              add      eax, 0x56f00000                
  0x01069A9F  007c0b00                add      byte ptr [ebx + ecx], bh       
  0x01069AA3  00c4                    add      ah, al                         
  0x01069AA5  40                      inc      eax                            
  0x01069AA6  0100                    add      dword ptr [eax], eax           
  0x01069AA8  2400                    and      al, 0                          
  0x01069AAA  0000                    add      byte ptr [eax], al             
  0x01069AAC  00da                    add      dl, bl                         
  0x01069AAE  2100                    and      dword ptr [eax], eax           
  0x01069AB0  00f0                    add      al, dh                         
  0x01069AB2  44                      inc      esp                            
  0x01069AB3  007b0b                  add      byte ptr [ebx + 0xb], bh       
  0x01069AB6  0000                    add      byte ptr [eax], al             
  0x01069AB8  00f4                    add      ah, dh                         
  0x01069ABA  46                      inc      esi                            
  0x01069ABB  0006                    add      byte ptr [esi], al             
  0x01069ABD  0000                    add      byte ptr [eax], al             
  0x01069ABF  00d0                    add      al, dl                         
  0x01069AC1  44                      inc      esp                            
  0x01069AC2  2300                    and      eax, dword ptr [eax]           
  0x01069AC4  2e1d0c0040f4            sbb      eax, 0xf440000c                
  0x01069ACA  44                      inc      esp                            
  0x01069ACB  004c0f00                add      byte ptr [edi + ecx], cl       
  0x01069ACF  004000                  add      byte ptr [eax], al             
  0x01069AD2  2000                    and      byte ptr [eax], al             
  0x01069AD4  0091210000e1            add      byte ptr [ecx - 0x1effffdf], dl 
  0x01069ADA  5e                      pop      esi                            
  0x01069ADB  0022                    add      byte ptr [edx], ah             
  0x01069ADD  cf                      iretd                                   
  0x01069ADE  2100                    and      dword ptr [eax], eax           
  0x01069AE0  22842100220020          and      al, byte ptr [ecx + 0x20002200] 
  0x01069AE7  004070                  add      byte ptr [eax + 0x70], al      
  0x01069AEA  57                      push     edi                            
  0x01069AEB  009a0b000000            add      byte ptr [edx + 0xb], bl       
  0x01069AF1  8521                    test     dword ptr [ecx], esp           
  0x01069AF3  006ce421                add      byte ptr [esp + 0x21], ch      
  0x01069AF7  0000                    add      byte ptr [eax], al             
  0x01069AF9  f4                      hlt                                     
  0x01069AFA  46                      inc      esi                            
  0x01069AFB  0008                    add      byte ptr [eax], cl             
  0x01069AFD  0000                    add      byte ptr [eax], al             
  0x01069AFF  00d0                    add      al, dl                         
  0x01069B01  a7                      cmpsd    dword ptr [esi], dword ptr es:[edi] 
  0x01069B02  2100                    and      dword ptr [eax], eax           
  0x01069B04  e87050009d              call     0x9e06eb79                     
  0x01069B09  0b00                    or       eax, dword ptr [eax]           
  0x01069B0B  0000                    add      byte ptr [eax], al             
  0x01069B0D  7045                    jo       0x1069b54                      
  0x01069B0F  009b0b0000b0            add      byte ptr [ebx - 0x4ffffff5], bl 
  0x01069B15  7051                    jo       0x1069b68                      
  0x01069B17  009e0b000000            add      byte ptr [esi + 0xb], bl       
  0x01069B1D  7047                    jo       0x1069b66                      
  0x01069B1F  009c0b00000070          add      byte ptr [ebx + ecx + 0x70000000], bl 
  0x01069B26  50                      push     eax                            
  0x01069B27  009f0b000003            add      byte ptr [edi + 0x300000b], bl 
  0x01069B2D  0c05                    or       al, 5                          
  0x01069B2F  0000                    add      byte ptr [eax], al             
  0x01069B31  7054                    jo       0x1069b87                      
  0x01069B33  00960b00000c            add      byte ptr [esi + 0xc00000b], dl 
  0x01069B39  0000                    add      byte ptr [eax], al             
  0x01069B3B  0000                    add      byte ptr [eax], al             
  0x01069B3D  f4                      hlt                                     
  0x01069B3E  56                      push     esi                            
  0x01069B3F  001409                  add      byte ptr [ecx + ecx], dl       
  0x01069B42  0000                    add      byte ptr [eax], al             
  0x01069B44  00f0                    add      al, dh                         
  0x01069B46  44                      inc      esp                            
  0x01069B47  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01069B4A  0000                    add      byte ptr [eax], al             
  0x01069B4C  40                      inc      eax                            
  0x01069B4D  0020                    add      byte ptr [eax], ah             
  0x01069B4F  0000                    add      byte ptr [eax], al             
  0x01069B51  91                      xchg     ecx, eax                       
  0x01069B52  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x01069B0D (cond_jump)
  0x01069B54  00e1                    add      cl, ah                         
  0x01069B56  56                      push     esi                            
  0x01069B57  0001                    add      byte ptr [ecx], al             
  0x01069B59  1e                      push     ds                             
  0x01069B5A  0c00                    or       al, 0                          
  0x01069B5C  3ef4                    hlt                                     
  0x01069B5E  44                      inc      esp                            
  0x01069B5F  0001                    add      byte ptr [ecx], al             
  0x01069B61  0000                    add      byte ptr [eax], al             
  0x01069B63  004c0020                add      byte ptr [eax + eax + 0x20], cl 
  0x01069B67  001b                    add      byte ptr [ebx], bl             
  0x01069B69  2920                    sub      dword ptr [eax], esp           
  0x01069B6B  0003                    add      byte ptr [ebx], al             
  0x01069B6D  f4                      hlt                                     
  0x01069B6E  45                      inc      ebp                            
  0x01069B6F  0003                    add      byte ptr [ebx], al             
  0x01069B71  0000                    add      byte ptr [eax], al             
  0x01069B73  0068a0                  add      byte ptr [eax - 0x60], ch      
  0x01069B76  0200                    add      al, byte ptr [eax]             
  0x01069B78  6d                      insd     dword ptr es:[edi], dx         
  0x01069B79  0020                    add      byte ptr [eax], ah             
  0x01069B7B  006870                  add      byte ptr [eax + 0x70], ch      
  0x01069B7E  0200                    add      al, byte ptr [eax]             
  0x01069B80  00f4                    add      ah, dh                         
  0x01069B82  56                      push     esi                            
  0x01069B83  00610b                  add      byte ptr [ecx + 0xb], ah       
  0x01069B86  0000                    add      byte ptr [eax], al             
  0x01069B88  00f0                    add      al, dh                         
  0x01069B8A  44                      inc      esp                            
  0x01069B8B  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01069B8E  0000                    add      byte ptr [eax], al             
  0x01069B90  40                      inc      eax                            
  0x01069B91  0020                    add      byte ptr [eax], ah             
  0x01069B93  0000                    add      byte ptr [eax], al             
  0x01069B95  90                      nop                                     
  0x01069B96  2100                    and      dword ptr [eax], eax           
  0x01069B98  006055                  add      byte ptr [eax + 0x55], ah      
  0x01069B9B  000c00                  add      byte ptr [eax + eax], cl       
  0x01069B9E  0000                    add      byte ptr [eax], al             
  0x01069BA0  00f0                    add      al, dh                         
  0x01069BA2  44                      inc      esp                            
  0x01069BA3  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x01069BA6  0000                    add      byte ptr [eax], al             
  0x01069BA8  00f4                    add      ah, dh                         
  0x01069BAA  46                      inc      esi                            
  0x01069BAB  0006                    add      byte ptr [esi], al             
  0x01069BAD  0000                    add      byte ptr [eax], al             
  0x01069BAF  00d0                    add      al, dl                         
  0x01069BB2  44                      inc      esp                            
  0x01069BB3  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01069BB6  0000                    add      byte ptr [eax], al             
  0x01069BB8  2e1d0c0040f4            sbb      eax, 0xf440000c                
  0x01069BBE  44                      inc      esp                            
  0x01069BBF  00920f000040            add      byte ptr [edx + 0x4000000f], dl 
  0x01069BC5  0020                    add      byte ptr [eax], ah             
  0x01069BC7  0000                    add      byte ptr [eax], al             
  0x01069BC9  94                      xchg     esp, eax                       
  0x01069BCA  2100                    and      dword ptr [eax], eax           
  0x01069BCC  00f0                    add      al, dh                         
  0x01069BCE  56                      push     esi                            
  0x01069BCF  00440b00                add      byte ptr [ebx + ecx], al       
  0x01069BD3  0000                    add      byte ptr [eax], al             
  0x01069BD5  e44c                    in       al, 0x4c                       
  0x01069BD7  004000                  add      byte ptr [eax], al             
  0x01069BDA  2000                    and      byte ptr [eax], al             
  0x01069BDC  0091210020e1            add      byte ptr [ecx - 0x1edfffdf], dl 
  0x01069BE2  050000f056              add      eax, 0x56f00000                
  0x01069BE7  00420b                  add      byte ptr [edx + 0xb], al       
  0x01069BEA  0000                    add      byte ptr [eax], al             
  0x01069BEC  00e4                    add      ah, ah                         
  0x01069BEE  4c                      dec      esp                            
  0x01069BEF  004000                  add      byte ptr [eax], al             
  0x01069BF2  2000                    and      byte ptr [eax], al             
  0x01069BF4  0091210000f0            add      byte ptr [ecx - 0xfffffdf], dl 
  0x01069BFA  56                      push     esi                            
  0x01069BFB  00430b                  add      byte ptr [ebx + 0xb], al       
  0x01069BFE  0000                    add      byte ptr [eax], al             
  0x01069C00  00e4                    add      ah, ah                         
  0x01069C02  4c                      dec      esp                            
  0x01069C03  004000                  add      byte ptr [eax], al             
  0x01069C06  2000                    and      byte ptr [eax], al             
  0x01069C08  0092210000f4            add      byte ptr [edx - 0xbffffdf], dl 
  0x01069C0E  44                      inc      esp                            
  0x01069C0F  0000                    add      byte ptr [eax], al             
  0x01069C11  0100                    add      dword ptr [eax], eax           
  0x01069C13  0000                    add      byte ptr [eax], al             
  0x01069C15  e246                    loop     0x1069c5d                      
  0x01069C17  00d0                    add      al, dl                         
  0x01069C19  0020                    add      byte ptr [eax], ah             
  0x01069C1B  0022                    add      byte ptr [edx], ah             
  0x01069C1D  002400                  add      byte ptr [eax + eax], ah       
  0x01069C20  0006                    add      byte ptr [esi], al             
  0x01069C22  2100                    and      dword ptr [eax], eax           
  0x01069C24  d000                    rol      byte ptr [eax], 1              
  0x01069C26  2400                    and      al, 0                          
  0x01069C28  00e2                    add      dl, ah                         
  0x01069C2A  46                      inc      esi                            
  0x01069C2B  00d2                    add      dl, dl                         
  0x01069C2D  002400                  add      byte ptr [eax + eax], ah       
  0x01069C30  2e1d0c0040e1            sbb      eax, 0xe140000c                
  0x01069C36  44                      inc      esp                            
  0x01069C37  004000                  add      byte ptr [eax], al             
  0x01069C3A  2000                    and      byte ptr [eax], al             
  0x01069C3C  0090210000e2            add      byte ptr [eax - 0x1dffffdf], dl 
  0x01069C42  7000                    jo       0x1069c44                      
                                        ; XREF: 0x01069C42 (cond_jump)
  0x01069C44  00f4                    add      ah, dh                         
  0x01069C46  6400fd                  add      ch, bh                         
  0x01069C49  0200                    add      al, byte ptr [eax]             
  0x01069C4B  0000                    add      byte ptr [eax], al             
  0x01069C4D  013c00                  add      dword ptr [eax + eax], edi     
  0x01069C50  00ff                    add      bh, bh                         
  0x01069C52  3e0000                  add      byte ptr ds:[eax], al          
  0x01069C55  f4                      hlt                                     
  0x01069C56  45                      inc      ebp                            
  0x01069C57  00cf                    add      bh, cl                         
  0x01069C59  f73f                    idiv     dword ptr [edi]                
  0x01069C5B  0000                    add      byte ptr [eax], al             
  0x01069C5E  56                      push     esi                            
  0x01069C5F  003f                    add      byte ptr [edi], bh             
  0x01069C61  0200                    add      al, byte ptr [eax]             
  0x01069C63  0003                    add      byte ptr [ebx], al             
  0x01069C65  0020                    add      byte ptr [eax], ah             
  0x01069C67  000f                    add      byte ptr [edi], cl             
  0x01069C69  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01069C6A  050000f056              add      eax, 0x56f00000                
  0x01069C6F  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01069C72  0000                    add      byte ptr [eax], al             
  0x01069C74  32f4                    xor      dh, ah                         
  0x01069C76  44                      inc      esp                            
  0x01069C77  00fd                    add      ch, bh                         
  0x01069C79  0400                    add      al, 0                          
  0x01069C7B  004000                  add      byte ptr [eax], al             
  0x01069C7E  2000                    and      byte ptr [eax], al             
  0x01069C80  0091210000f4            add      byte ptr [ecx - 0xbffffdf], dl 
  0x01069C86  47                      inc      edi                            
  0x01069C87  004703                  add      byte ptr [edi + 3], al         
  0x01069C8A  0000                    add      byte ptr [eax], al             
  0x01069C8C  00d9                    add      cl, bl                         
  0x01069C8E  57                      push     edi                            
  0x01069C8F  0000                    add      byte ptr [eax], al             
  0x01069C91  d15100                  rcl      dword ptr [ecx]                
  0x01069C94  e704                    out      4, eax                         
  0x01069C96  0d00005955              or       eax, 0x55590000                
  0x01069C9B  0000                    add      byte ptr [eax], al             
  0x01069C9D  61                      popal                                   
  0x01069C9E  51                      push     ecx                            
  0x01069C9F  0002                    add      byte ptr [edx], al             
  0x01069CA1  0c05                    or       al, 5                          
  0x01069CA3  00f4                    add      ah, dh                         
  0x01069CA5  040d                    add      al, 0xd                        
  0x01069CA7  0020                    add      byte ptr [eax], ah             
  0x01069CA9  f4                      hlt                                     
  0x01069CAA  0500ffff00              add      eax, 0xffff00                  
  0x01069CAF  000c00                  add      byte ptr [eax + eax], cl       
  0x01069CB2  0000                    add      byte ptr [eax], al             
  0x01069CB4  00f0                    add      al, dh                         
  0x01069CB6  56                      push     esi                            
  0x01069CB7  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01069CBA  0000                    add      byte ptr [eax], al             
  0x01069CBC  00f0                    add      al, dh                         
  0x01069CBE  44                      inc      esp                            
  0x01069CBF  00970b000045            add      byte ptr [edi + 0x4500000b], dl 
  0x01069CC5  0020                    add      byte ptr [eax], ah             
  0x01069CC7  004da4                  add      byte ptr [ebp - 0x5c], cl      
  0x01069CCA  050000f056              add      eax, 0x56f00000                
  0x01069CCF  003d02000003            add      byte ptr [0x3000002], bh       
  0x01069CD5  0020                    add      byte ptr [eax], ah             
  0x01069CD7  005ba4                  add      byte ptr [ebx - 0x5c], bl      
  0x01069CDA  050000f460              add      eax, 0x60f40000                
  0x01069CDF  00fd                    add      ch, bh                         
  0x01069CE1  0200                    add      al, byte ptr [eax]             
  0x01069CE3  0000                    add      byte ptr [eax], al             
  0x01069CE5  1422                    adc      al, 0x22                       
  0x01069CE7  0000                    add      byte ptr [eax], al             
  0x01069CE9  0138                    add      dword ptr [eax], edi           
  0x01069CEB  0000                    add      byte ptr [eax], al             
  0x01069CED  1c23                    sbb      al, 0x23                       
  0x01069CEF  0000                    add      byte ptr [eax], al             
  0x01069CF2  44                      inc      esp                            
  0x01069CF3  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01069CF6  0000                    add      byte ptr [eax], al             
  0x01069CF8  00f4                    add      ah, dh                         
  0x01069CFA  46                      inc      esi                            
  0x01069CFB  000c00                  add      byte ptr [eax + eax], cl       
  0x01069CFE  0000                    add      byte ptr [eax], al             
  0x01069D00  d0f4                    sal      ah, 1                          
  0x01069D02  44                      inc      esp                            
  0x01069D03  0021                    add      byte ptr [ecx], ah             
  0x01069D05  0500002e1d              add      eax, 0x1d2e0000                
  0x01069D0A  0c00                    or       al, 0                          
  0x01069D0C  40                      inc      eax                            
  0x01069D0D  0020                    add      byte ptr [eax], ah             
  0x01069D0F  0000                    add      byte ptr [eax], al             
  0x01069D11  91                      xchg     ecx, eax                       
  0x01069D12  2100                    and      dword ptr [eax], eax           
  0x01069D14  00f0                    add      al, dh                         
  0x01069D16  44                      inc      esp                            
  0x01069D17  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01069D1A  0000                    add      byte ptr [eax], al             
  0x01069D1C  00f4                    add      ah, dh                         
  0x01069D1E  46                      inc      esi                            
  0x01069D1F  0006                    add      byte ptr [esi], al             
  0x01069D21  0000                    add      byte ptr [eax], al             
  0x01069D23  00d0                    add      al, dl                         
  0x01069D25  f4                      hlt                                     
  0x01069D26  44                      inc      esp                            
  0x01069D27  005d05                  add      byte ptr [ebp + 5], bl         
  0x01069D2A  0000                    add      byte ptr [eax], al             
  0x01069D2C  2e1d0c004000            sbb      eax, 0x40000c                  
  0x01069D32  2000                    and      byte ptr [eax], al             
  0x01069D34  0092210000f0            add      byte ptr [edx - 0xfffffdf], dl 
  0x01069D3A  56                      push     esi                            
  0x01069D3B  004002                  add      byte ptr [eax + 2], al         
  0x01069D3E  0000                    add      byte ptr [eax], al             
  0x01069D40  c44001                  les      eax, ptr [eax + 1]             
  0x01069D43  0007                    add      byte ptr [edi], al             
  0x01069D45  0000                    add      byte ptr [eax], al             
  0x01069D47  0000                    add      byte ptr [eax], al             
  0x01069D49  da21                    fisub    dword ptr [ecx]                
  0x01069D4B  0000                    add      byte ptr [eax], al             
  0x01069D4D  44                      inc      esp                            
  0x01069D4E  2300                    and      eax, dword ptr [eax]           
  0x01069D50  00f4                    add      ah, dh                         
  0x01069D52  46                      inc      esi                            
  0x01069D53  000f                    add      byte ptr [edi], cl             
  0x01069D55  0000                    add      byte ptr [eax], al             
  0x01069D57  00d0                    add      al, dl                         
  0x01069D59  f4                      hlt                                     
  0x01069D5A  44                      inc      esp                            
  0x01069D5B  001408                  add      byte ptr [eax + ecx], dl       
  0x01069D5E  0000                    add      byte ptr [eax], al             
  0x01069D60  2e1d0c004000            sbb      eax, 0x40000c                  
  0x01069D66  2000                    and      byte ptr [eax], al             
  0x01069D68  009521000003            add      byte ptr [ebp + 0x3000021], dl 
  0x01069D6E  3a00                    cmp      al, byte ptr [eax]             
  0x01069D70  00ff                    add      bh, bh                         
  0x01069D72  3e009e040d0013          add      byte ptr ds:[esi + 0x13000d04], bl 
  0x01069D79  0c05                    or       al, 5                          
  0x01069D7B  0000                    add      byte ptr [eax], al             
  0x01069D7E  56                      push     esi                            
  0x01069D7F  003e                    add      byte ptr [esi], bh             
  0x01069D81  0200                    add      al, byte ptr [eax]             
  0x01069D83  0003                    add      byte ptr [ebx], al             
  0x01069D85  0020                    add      byte ptr [eax], ah             
  0x01069D87  000f                    add      byte ptr [edi], cl             
  0x01069D89  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x01069D8A  050000f460              add      eax, 0x60f40000                
  0x01069D8F  00fd                    add      ch, bh                         
  0x01069D91  0200                    add      al, byte ptr [eax]             
  0x01069D93  0000                    add      byte ptr [eax], al             
  0x01069D95  1422                    adc      al, 0x22                       
  0x01069D97  0000                    add      byte ptr [eax], al             
  0x01069D99  0138                    add      dword ptr [eax], edi           
  0x01069D9B  0000                    add      byte ptr [eax], al             
  0x01069D9D  1c23                    sbb      al, 0x23                       
  0x01069D9F  0000                    add      byte ptr [eax], al             
  0x01069DA1  f4                      hlt                                     
  0x01069DA2  61                      popal                                   
  0x01069DA3  0009                    add      byte ptr [ecx], cl             
  0x01069DA5  05000000f4              add      eax, 0xf4000000                
  0x01069DAA  6200                    bound    eax, qword ptr [eax]           
  0x01069DAC  1905000000f4            sbb      dword ptr [0xf4000000], eax    
  0x01069DB2  650000                  add      byte ptr gs:[eax], al          
  0x01069DB5  0800                    or       byte ptr [eax], al             
  0x01069DB7  0000                    add      byte ptr [eax], al             
  0x01069DB9  043a                    add      al, 0x3a                       
  0x01069DBB  0000                    add      byte ptr [eax], al             
  0x01069DBE  3e00bf040d000c          add      byte ptr ds:[edi + 0xc000d04], bh 
  0x01069DC5  0000                    add      byte ptr [eax], al             
  0x01069DC7  0000                    add      byte ptr [eax], al             
  0x01069DCA  44                      inc      esp                            
  0x01069DCB  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x01069DCE  0000                    add      byte ptr [eax], al             
  0x01069DD0  00f4                    add      ah, dh                         
  0x01069DD2  46                      inc      esi                            
  0x01069DD3  0006                    add      byte ptr [esi], al             
  0x01069DD5  0000                    add      byte ptr [eax], al             
  0x01069DD7  00d0                    add      al, dl                         
  0x01069DDA  44                      inc      esp                            
  0x01069DDB  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01069DDE  0000                    add      byte ptr [eax], al             
  0x01069DE0  2e1d0c0040f4            sbb      eax, 0xf440000c                
  0x01069DE6  44                      inc      esp                            
  0x01069DE7  00920f000040            add      byte ptr [edx + 0x4000000f], dl 
  0x01069DED  0020                    add      byte ptr [eax], ah             
  0x01069DEF  0000                    add      byte ptr [eax], al             
  0x01069DF1  91                      xchg     ecx, eax                       
  0x01069DF2  2100                    and      dword ptr [eax], eax           
  0x01069DF4  00e1                    add      cl, ah                         
  0x01069DF6  4c                      dec      esp                            
  0x01069DF7  0000                    add      byte ptr [eax], al             
  0x01069DF9  7044                    jo       0x1069e3f                      
  0x01069DFB  0013                    add      byte ptr [ebx], dl             
  0x01069DFD  0900                    or       dword ptr [eax], eax           
  0x01069DFF  0000                    add      byte ptr [eax], al             
  0x01069E01  f4                      hlt                                     
  0x01069E02  61                      popal                                   
  0x01069E03  00fd                    add      ch, bh                         
  0x01069E05  0200                    add      al, byte ptr [eax]             
  0x01069E07  0013                    add      byte ptr [ebx], dl             
  0x01069E09  0020                    add      byte ptr [eax], ah             
  0x01069E0B  001b                    add      byte ptr [ebx], bl             
  0x01069E0D  d9440091                fld      dword ptr [eax + eax - 0x6f]   
  0x01069E11  0006                    add      byte ptr [esi], al             
  0x01069E13  000400                  add      byte ptr [eax + eax], al       
  0x01069E16  0000                    add      byte ptr [eax], al             
  0x01069E18  47                      inc      edi                            
  0x01069E19  0020                    add      byte ptr [eax], ah             
  0x01069E1B  004090                  add      byte ptr [eax - 0x70], al      
  0x01069E1E  0200                    add      al, byte ptr [eax]             
  0x01069E20  8ad9                    mov      bl, cl                         
  0x01069E22  44                      inc      esp                            
  0x01069E23  0000                    add      byte ptr [eax], al             
  0x01069E25  f4                      hlt                                     
  0x01069E26  60                      pushal                                  
  0x01069E27  00a805000000            add      byte ptr [eax + 5], ch         
  0x01069E2E  7000                    jo       0x1069e30                      
                                        ; XREF: 0x01069E2E (cond_jump)
  0x01069E30  41                      inc      ecx                            
  0x01069E31  0b00                    or       eax, dword ptr [eax]           
  0x01069E33  0032                    add      byte ptr [edx], dh             
  0x01069E35  0020                    add      byte ptr [eax], ah             
  0x01069E37  0026                    add      byte ptr [esi], ah             
  0x01069E39  e844004768              call     0x694d9e82                     
  0x01069E3E  56                      push     esi                            
                                        ; XREF: 0x01069DF9 (cond_jump)
  0x01069E3F  004090                  add      byte ptr [eax - 0x70], al      
  0x01069E42  0200                    add      al, byte ptr [eax]             
  0x01069E44  00c7                    add      bh, al                         
  0x01069E46  2100                    and      dword ptr [eax], eax           
  0x01069E48  00f4                    add      ah, dh                         
  0x01069E4A  56                      push     esi                            
  0x01069E4B  001409                  add      byte ptr [ecx + ecx], dl       
  0x01069E4E  0000                    add      byte ptr [eax], al             
  0x01069E50  00f0                    add      al, dh                         
  0x01069E52  44                      inc      esp                            
  0x01069E53  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01069E56  0000                    add      byte ptr [eax], al             
  0x01069E58  40                      inc      eax                            
  0x01069E59  0020                    add      byte ptr [eax], ah             
  0x01069E5B  0000                    add      byte ptr [eax], al             
  0x01069E5D  90                      nop                                     
  0x01069E5E  2100                    and      dword ptr [eax], eax           
  0x01069E60  006047                  add      byte ptr [eax + 0x47], ah      
  0x01069E63  00911c0c0000            add      byte ptr [ecx + 0xc1c], dl     
  0x01069E6A  44                      inc      esp                            
  0x01069E6B  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01069E6E  0000                    add      byte ptr [eax], al             
  0x01069E70  00f4                    add      ah, dh                         
  0x01069E72  46                      inc      esi                            
  0x01069E73  0002                    add      byte ptr [edx], al             
  0x01069E75  0000                    add      byte ptr [eax], al             
  0x01069E77  00d0                    add      al, dl                         
  0x01069E79  f4                      hlt                                     
  0x01069E7A  44                      inc      esp                            
  0x01069E7B  0020                    add      byte ptr [eax], ah             
  0x01069E7D  0900                    or       dword ptr [eax], eax           
  0x01069E7F  002e                    add      byte ptr [esi], ch             
  0x01069E81  1d0c004000              sbb      eax, 0x40000c                  
  0x01069E86  2000                    and      byte ptr [eax], al             
  0x01069E88  009021000058            add      byte ptr [eax + 0x58000021], dl 
  0x01069E8E  55                      push     ebp                            
  0x01069E8F  0000                    add      byte ptr [eax], al             
  0x01069E91  60                      pushal                                  
  0x01069E92  51                      push     ecx                            
  0x01069E93  0000                    add      byte ptr [eax], al             
  0x01069E95  f4                      hlt                                     
  0x01069E96  56                      push     esi                            
  0x01069E97  001a                    add      byte ptr [edx], bl             
  0x01069E99  0900                    or       dword ptr [eax], eax           
  0x01069E9B  0000                    add      byte ptr [eax], al             
  0x01069E9E  44                      inc      esp                            
  0x01069E9F  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01069EA2  0000                    add      byte ptr [eax], al             
  0x01069EA4  40                      inc      eax                            
  0x01069EA5  0020                    add      byte ptr [eax], ah             
  0x01069EA7  0000                    add      byte ptr [eax], al             
  0x01069EA9  90                      nop                                     
  0x01069EAA  2100                    and      dword ptr [eax], eax           
  0x01069EAC  00a721000026            add      byte ptr [edi + 0x26000021], ah 
  0x01069EB2  2100                    and      dword ptr [eax], eax           
  0x01069EB4  13402f                  adc      eax, dword ptr [eax + 0x2f]    
  0x01069EB7  009017060008            add      byte ptr [eax + 0x8000617], dl 
  0x01069EBD  0000                    add      byte ptr [eax], al             
  0x01069EBF  0010                    add      byte ptr [eax], dl             
  0x01069EC1  c521                    lds      esp, ptr [ecx]                 
  0x01069EC3  0000                    add      byte ptr [eax], al             
  0x01069EC5  c421                    les      esp, ptr [ecx]                 
  0x01069EC7  00840020003000          add      byte ptr [eax + eax + 0x300020], al 
  0x01069ECE  2000                    and      byte ptr [eax], al             
  0x01069ED0  00ae20001021            add      byte ptr [esi + 0x21100020], ch 
  0x01069ED6  2000                    and      byte ptr [eax], al             
  0x01069ED8  2a00                    sub      al, byte ptr [eax]             
  0x01069EDA  2000                    and      byte ptr [eax], al             
  0x01069EDC  3200                    xor      al, byte ptr [eax]             
  0x01069EDE  2000                    and      byte ptr [eax], al             
  0x01069EE0  006056                  add      byte ptr [eax + 0x56], ah      
  0x01069EE3  000c00                  add      byte ptr [eax + eax], cl       
  0x01069EE6  0000                    add      byte ptr [eax], al             
  0x01069EE8  00f4                    add      ah, dh                         
  0x01069EEA  60                      pushal                                  
  0x01069EEB  00fd                    add      ch, bh                         
  0x01069EED  0200                    add      al, byte ptr [eax]             
  0x01069EEF  0000                    add      byte ptr [eax], al             
  0x01069EF1  f4                      hlt                                     
  0x01069EF2  6400fd                  add      ch, bh                         
  0x01069EF5  0300                    add      eax, dword ptr [eax]           
  0x01069EF7  0000                    add      byte ptr [eax], al             
  0x01069EF9  0138                    add      dword ptr [eax], edi           
  0x01069EFB  0000                    add      byte ptr [eax], al             
  0x01069EFD  1c23                    sbb      al, 0x23                       
  0x01069EFF  0000                    add      byte ptr [eax], al             
  0x01069F02  44                      inc      esp                            
  0x01069F03  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01069F06  0000                    add      byte ptr [eax], al             
  0x01069F08  00f4                    add      ah, dh                         
  0x01069F0A  46                      inc      esi                            
  0x01069F0B  0008                    add      byte ptr [eax], cl             
  0x01069F0D  0000                    add      byte ptr [eax], al             
  0x01069F0F  00d0                    add      al, dl                         
  0x01069F11  f4                      hlt                                     
  0x01069F12  44                      inc      esp                            
  0x01069F13  007b05                  add      byte ptr [ebx + 5], bh         
  0x01069F16  0000                    add      byte ptr [eax], al             
  0x01069F18  2e1d0c004000            sbb      eax, 0x40000c                  
  0x01069F1E  2000                    and      byte ptr [eax], al             
  0x01069F20  0091210000f4            add      byte ptr [ecx - 0xbffffdf], dl 
  0x01069F26  6500a208000000          add      byte ptr gs:[edx + 8], ah      
  0x01069F2D  023a                    add      bh, byte ptr [edx]             
  0x01069F2F  0000                    add      byte ptr [eax], al             
  0x01069F32  3e009e040d0000          add      byte ptr ds:[esi + 0xd04], bl  
  0x01069F3A  44                      inc      esp                            
  0x01069F3B  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01069F3E  0000                    add      byte ptr [eax], al             
  0x01069F40  00f4                    add      ah, dh                         
  0x01069F42  46                      inc      esi                            
  0x01069F43  0012                    add      byte ptr [edx], dl             
  0x01069F45  0000                    add      byte ptr [eax], al             
  0x01069F47  00d0                    add      al, dl                         
  0x01069F49  f4                      hlt                                     
  0x01069F4A  44                      inc      esp                            
  0x01069F4B  00ae0500002e            add      byte ptr [esi + 0x2e000005], ch 
  0x01069F51  1d0c004000              sbb      eax, 0x40000c                  
  0x01069F56  2000                    and      byte ptr [eax], al             
  0x01069F58  00902100000e            add      byte ptr [eax + 0xe000021], dl 
  0x01069F5E  3800                    cmp      byte ptr [eax], al             
  0x01069F60  00f4                    add      ah, dh                         
  0x01069F62  61                      popal                                   
  0x01069F63  00fd                    add      ch, bh                         
  0x01069F65  0300                    add      eax, dword ptr [eax]           
  0x01069F67  0000                    add      byte ptr [eax], al             
  0x01069F69  48                      dec      eax                            
  0x01069F6A  2000                    and      byte ptr [eax], al             
  0x01069F6C  90                      nop                                     
  0x01069F6D  0406                    add      al, 6                          
  0x01069F6F  0009                    add      byte ptr [ecx], cl             
  0x01069F71  0000                    add      byte ptr [eax], al             
  0x01069F73  0013                    add      byte ptr [ebx], dl             
  0x01069F75  0020                    add      byte ptr [eax], ah             
  0x01069F77  009040060004            add      byte ptr [eax + 0x4000640], dl 
  0x01069F7D  0000                    add      byte ptr [eax], al             
  0x01069F7F  0000                    add      byte ptr [eax], al             
  0x01069F81  d9440047                fld      dword ptr [eax + eax + 0x47]   
  0x01069F85  0020                    add      byte ptr [eax], ah             
  0x01069F87  004090                  add      byte ptr [eax - 0x70], al      
  0x01069F8A  0200                    add      al, byte ptr [eax]             
  0x01069F8C  260020                  add      byte ptr es:[eax], ah          
  0x01069F8F  0000                    add      byte ptr [eax], al             
  0x01069F91  58                      pop      eax                            
  0x01069F92  56                      push     esi                            
  0x01069F93  0000                    add      byte ptr [eax], al             
  0x01069F96  44                      inc      esp                            
  0x01069F97  00410b                  add      byte ptr [ecx + 0xb], al       
  0x01069F9A  0000                    add      byte ptr [eax], al             
  0x01069F9C  00f4                    add      ah, dh                         
  0x01069F9E  46                      inc      esi                            
  0x01069F9F  0012                    add      byte ptr [edx], dl             
  0x01069FA1  0000                    add      byte ptr [eax], al             
  0x01069FA3  00d0                    add      al, dl                         
  0x01069FA5  f4                      hlt                                     
  0x01069FA6  44                      inc      esp                            
  0x01069FA7  00ae0500002e            add      byte ptr [esi + 0x2e000005], ch 
  0x01069FAD  1d0c004000              sbb      eax, 0x40000c                  
  0x01069FB2  2000                    and      byte ptr [eax], al             
  0x01069FB4  009021000008            add      byte ptr [eax + 0x8000021], dl 
  0x01069FBA  3800                    cmp      byte ptr [eax], al             
  0x01069FBC  00f4                    add      ah, dh                         
  0x01069FBE  57                      push     edi                            
  0x01069FBF  0002                    add      byte ptr [edx], al             
  0x01069FC1  0000                    add      byte ptr [eax], al             
  0x01069FC3  0000                    add      byte ptr [eax], al             
  0x01069FC5  48                      dec      eax                            
  0x01069FC6  2000                    and      byte ptr [eax], al             
  0x01069FC8  0006                    add      byte ptr [esi], al             
  0x01069FCA  3800                    cmp      byte ptr [eax], al             
  0x01069FCC  90                      nop                                     
  0x01069FCD  0206                    add      al, byte ptr [esi]             
  0x01069FCF  000b                    add      byte ptr [ebx], cl             
  0x01069FD1  0000                    add      byte ptr [eax], al             
  0x01069FD3  0000                    add      byte ptr [eax], al             
  0x01069FD5  1122                    adc      dword ptr [edx], esp           
  0x01069FD7  0012                    add      byte ptr [edx], dl             
  0x01069FD9  48                      dec      eax                            
  0x01069FDA  0400                    add      al, 0                          
  0x01069FDC  10cd                    adc      ch, cl                         
  0x01069FDE  06                      push     es                             
  0x01069FDF  0006                    add      byte ptr [esi], al             
  0x01069FE1  0000                    add      byte ptr [eax], al             
  0x01069FE3  0000                    add      byte ptr [eax], al             
  0x01069FE5  da440000                fiadd    dword ptr [eax + eax]          
  0x01069FE9  da5600                  ficom    dword ptr [esi]                
  0x01069FEC  45                      inc      ebp                            
  0x01069FED  0020                    add      byte ptr [eax], ah             
  0x01069FEF  004090                  add      byte ptr [eax - 0x70], al      
  0x01069FF2  0200                    add      al, byte ptr [eax]             
  0x01069FF4  005956                  add      byte ptr [ecx + 0x56], bl      
  0x01069FF7  002a                    add      byte ptr [edx], ch             
  0x01069FF9  40                      inc      eax                            
  0x01069FFA  2000                    and      byte ptr [eax], al             
  0x01069FFC  00f0                    add      al, dh                         
  0x01069FFE  44                      inc      esp                            
  0x01069FFF  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A002  0000                    add      byte ptr [eax], al             
  0x0106A004  00f4                    add      ah, dh                         
  0x0106A006  46                      inc      esi                            
  0x0106A007  0012                    add      byte ptr [edx], dl             
  0x0106A009  0000                    add      byte ptr [eax], al             
  0x0106A00B  00d0                    add      al, dl                         
  0x0106A00D  f4                      hlt                                     
  0x0106A00E  44                      inc      esp                            
  0x0106A00F  00ae0500002e            add      byte ptr [esi + 0x2e000005], ch 
  0x0106A015  1d0c004000              sbb      eax, 0x40000c                  
  0x0106A01A  2000                    and      byte ptr [eax], al             
  0x0106A01C  009021000006            add      byte ptr [eax + 0x6000021], dl 
  0x0106A022  3800                    cmp      byte ptr [eax], al             
  0x0106A024  00f4                    add      ah, dh                         
  0x0106A026  6200                    bound    eax, qword ptr [eax]           
  0x0106A028  af                      scasd    eax, dword ptr es:[edi]        
  0x0106A029  0800                    or       byte ptr [eax], al             
  0x0106A02B  0000                    add      byte ptr [eax], al             
  0x0106A02D  0239                    add      bh, byte ptr [ecx]             
  0x0106A02F  001b                    add      byte ptr [ebx], bl             
  0x0106A031  f4                      hlt                                     
  0x0106A032  45                      inc      ebp                            
  0x0106A033  0001                    add      byte ptr [ecx], al             
  0x0106A035  0000                    add      byte ptr [eax], al             
  0x0106A037  0000                    add      byte ptr [eax], al             
  0x0106A039  a6                      cmpsb    byte ptr [esi], byte ptr es:[edi] 
  0x0106A03A  2000                    and      byte ptr [eax], al             
  0x0106A03C  90                      nop                                     
  0x0106A03D  0306                    add      eax, dword ptr [esi]           
  0x0106A03F  000d00000000            add      byte ptr [0], cl               
  0x0106A045  1122                    adc      dword ptr [edx], esp           
  0x0106A047  0000                    add      byte ptr [eax], al             
  0x0106A049  da4f00                  fimul    dword ptr [edi]                
  0x0106A04C  004920                  add      byte ptr [ecx + 0x20], cl      
  0x0106A04F  0000                    add      byte ptr [eax], al             
  0x0106A051  d1440010                rol      dword ptr [eax + eax + 0x10], 1 
  0x0106A055  c60600                  mov      byte ptr [esi], 0              
  0x0106A058  0400                    add      al, 0                          
  0x0106A05A  0000                    add      byte ptr [eax], al             
  0x0106A05C  c0c944                  ror      cl, 0x44                       
  0x0106A05F  0045d1                  add      byte ptr [ebp - 0x2f], al      
  0x0106A062  44                      inc      esp                            
  0x0106A063  006870                  add      byte ptr [eax + 0x70], ch      
  0x0106A066  0200                    add      al, byte ptr [eax]             
  0x0106A068  00ce                    add      dh, cl                         
  0x0106A06A  2000                    and      byte ptr [eax], al             
  0x0106A06C  324820                  xor      cl, byte ptr [eax + 0x20]      
  0x0106A06F  0000                    add      byte ptr [eax], al             
  0x0106A071  8621                    xchg     byte ptr [ecx], ah             
  0x0106A073  0000                    add      byte ptr [eax], al             
  0x0106A076  44                      inc      esp                            
  0x0106A077  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A07A  0000                    add      byte ptr [eax], al             
  0x0106A07C  00f4                    add      ah, dh                         
  0x0106A07E  46                      inc      esi                            
  0x0106A07F  0012                    add      byte ptr [edx], dl             
  0x0106A081  0000                    add      byte ptr [eax], al             
  0x0106A083  00d0                    add      al, dl                         
  0x0106A085  f4                      hlt                                     
  0x0106A086  44                      inc      esp                            
  0x0106A087  00ae0500002e            add      byte ptr [esi + 0x2e000005], ch 
  0x0106A08D  1d0c004000              sbb      eax, 0x40000c                  
  0x0106A092  2000                    and      byte ptr [eax], al             
  0x0106A094  009021000002            add      byte ptr [eax + 0x2000021], dl 
  0x0106A09A  3800                    cmp      byte ptr [eax], al             
  0x0106A09C  00f4                    add      ah, dh                         
  0x0106A09E  44                      inc      esp                            
  0x0106A09F  0000                    add      byte ptr [eax], al             
  0x0106A0A1  3200                    xor      al, byte ptr [eax]             
  0x0106A0A3  0000                    add      byte ptr [eax], al             
  0x0106A0A5  e856004500              call     0x14ba100                      
  0x0106A0AA  2000                    and      byte ptr [eax], al             
  0x0106A0AC  1b29                    sbb      ebp, dword ptr [ecx]           
  0x0106A0AE  2000                    and      byte ptr [eax], al             
  0x0106A0B0  00f0                    add      al, dh                         
  0x0106A0B2  44                      inc      esp                            
  0x0106A0B3  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A0B6  0000                    add      byte ptr [eax], al             
  0x0106A0B8  00f4                    add      ah, dh                         
  0x0106A0BA  46                      inc      esi                            
  0x0106A0BB  0002                    add      byte ptr [edx], al             
  0x0106A0BD  0000                    add      byte ptr [eax], al             
  0x0106A0BF  00d0                    add      al, dl                         
  0x0106A0C1  f4                      hlt                                     
  0x0106A0C2  44                      inc      esp                            
  0x0106A0C3  0020                    add      byte ptr [eax], ah             
  0x0106A0C5  0900                    or       dword ptr [eax], eax           
  0x0106A0C7  002e                    add      byte ptr [esi], ch             
  0x0106A0C9  1d0c004000              sbb      eax, 0x40000c                  
  0x0106A0CE  2000                    and      byte ptr [eax], al             
  0x0106A0D0  0091210000f4            add      byte ptr [ecx - 0xbffffdf], dl 
  0x0106A0D6  56                      push     esi                            
  0x0106A0D7  0008                    add      byte ptr [eax], cl             
  0x0106A0D9  06                      push     es                             
  0x0106A0DA  0000                    add      byte ptr [eax], al             
  0x0106A0DC  00f0                    add      al, dh                         
  0x0106A0DE  44                      inc      esp                            
  0x0106A0DF  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A0E2  0000                    add      byte ptr [eax], al             
  0x0106A0E4  40                      inc      eax                            
  0x0106A0E5  0020                    add      byte ptr [eax], ah             
  0x0106A0E7  0000                    add      byte ptr [eax], al             
  0x0106A0E9  90                      nop                                     
  0x0106A0EA  2100                    and      dword ptr [eax], eax           
  0x0106A0EC  00e1                    add      cl, ah                         
  0x0106A0EE  44                      inc      esp                            
  0x0106A0EF  0000                    add      byte ptr [eax], al             
  0x0106A0F1  f4                      hlt                                     
  0x0106A0F2  46                      inc      esi                            
  0x0106A0F3  00ff                    add      bh, bh                         
  0x0106A0F6  7f00                    jg       0x106a0f8                      
                                        ; XREF: 0x0106A0F6 (cond_jump)
  0x0106A0F8  d0e0                    shl      al, 1                          
  0x0106A0FA  44                      inc      esp                            
  0x0106A0FB  004500                  add      byte ptr [ebp], al             
  0x0106A0FE  2000                    and      byte ptr [eax], al             
  0x0106A100  1b29                    sbb      ebp, dword ptr [ecx]           
  0x0106A102  2000                    and      byte ptr [eax], al             
  0x0106A104  00f4                    add      ah, dh                         
  0x0106A106  56                      push     esi                            
  0x0106A107  002c09                  add      byte ptr [ecx + ecx], ch       
  0x0106A10A  0000                    add      byte ptr [eax], al             
  0x0106A10C  00f0                    add      al, dh                         
  0x0106A10E  44                      inc      esp                            
  0x0106A10F  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A112  0000                    add      byte ptr [eax], al             
  0x0106A114  40                      inc      eax                            
  0x0106A115  0020                    add      byte ptr [eax], ah             
  0x0106A117  0000                    add      byte ptr [eax], al             
  0x0106A119  90                      nop                                     
  0x0106A11A  2100                    and      dword ptr [eax], eax           
  0x0106A11C  006055                  add      byte ptr [eax + 0x55], ah      
  0x0106A11F  0000                    add      byte ptr [eax], al             
  0x0106A122  44                      inc      esp                            
  0x0106A123  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A126  0000                    add      byte ptr [eax], al             
  0x0106A128  00f4                    add      ah, dh                         
  0x0106A12A  46                      inc      esi                            
  0x0106A12B  0012                    add      byte ptr [edx], dl             
  0x0106A12D  0000                    add      byte ptr [eax], al             
  0x0106A12F  00d0                    add      al, dl                         
  0x0106A131  f4                      hlt                                     
  0x0106A132  44                      inc      esp                            
  0x0106A133  00ae0500002e            add      byte ptr [esi + 0x2e000005], ch 
  0x0106A139  1d0c004000              sbb      eax, 0x40000c                  
  0x0106A13E  2000                    and      byte ptr [eax], al             
  0x0106A140  009021000006            add      byte ptr [eax + 0x6000021], dl 
  0x0106A146  3800                    cmp      byte ptr [eax], al             
  0x0106A148  00f4                    add      ah, dh                         
  0x0106A14A  6200                    bound    eax, qword ptr [eax]           
  0x0106A14C  ac                      lodsb    al, byte ptr [esi]             
  0x0106A14D  0800                    or       byte ptr [eax], al             
  0x0106A14F  0000                    add      byte ptr [eax], al             
  0x0106A151  0239                    add      bh, byte ptr [ecx]             
  0x0106A153  001b                    add      byte ptr [ebx], bl             
  0x0106A155  a6                      cmpsb    byte ptr [esi], byte ptr es:[edi] 
  0x0106A156  2000                    and      byte ptr [eax], al             
  0x0106A158  90                      nop                                     
  0x0106A159  0306                    add      eax, dword ptr [esi]           
  0x0106A15B  000d00000000            add      byte ptr [0], cl               
  0x0106A161  1122                    adc      dword ptr [edx], esp           
  0x0106A163  0000                    add      byte ptr [eax], al             
  0x0106A165  da4f00                  fimul    dword ptr [edi]                
  0x0106A168  004920                  add      byte ptr [ecx + 0x20], cl      
  0x0106A16B  0000                    add      byte ptr [eax], al             
  0x0106A16D  d1440010                rol      dword ptr [eax + eax + 0x10], 1 
  0x0106A171  c60600                  mov      byte ptr [esi], 0              
  0x0106A174  0400                    add      al, 0                          
  0x0106A176  0000                    add      byte ptr [eax], al             
  0x0106A178  c0c944                  ror      cl, 0x44                       
  0x0106A17B  0045d1                  add      byte ptr [ebp - 0x2f], al      
  0x0106A17E  44                      inc      esp                            
  0x0106A17F  006870                  add      byte ptr [eax + 0x70], ch      
  0x0106A182  0200                    add      al, byte ptr [eax]             
  0x0106A184  00ce                    add      dh, cl                         
  0x0106A186  2000                    and      byte ptr [eax], al             
  0x0106A188  324820                  xor      cl, byte ptr [eax + 0x20]      
  0x0106A18B  0000                    add      byte ptr [eax], al             
  0x0106A18D  8621                    xchg     byte ptr [ecx], ah             
  0x0106A18F  0000                    add      byte ptr [eax], al             
  0x0106A192  44                      inc      esp                            
  0x0106A193  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A196  0000                    add      byte ptr [eax], al             
  0x0106A198  00f4                    add      ah, dh                         
  0x0106A19A  46                      inc      esi                            
  0x0106A19B  0012                    add      byte ptr [edx], dl             
  0x0106A19D  0000                    add      byte ptr [eax], al             
  0x0106A19F  00d0                    add      al, dl                         
  0x0106A1A1  f4                      hlt                                     
  0x0106A1A2  44                      inc      esp                            
  0x0106A1A3  00ae0500002e            add      byte ptr [esi + 0x2e000005], ch 
  0x0106A1A9  1d0c004000              sbb      eax, 0x40000c                  
  0x0106A1AE  2000                    and      byte ptr [eax], al             
  0x0106A1B0  009021000002            add      byte ptr [eax + 0x2000021], dl 
  0x0106A1B6  3800                    cmp      byte ptr [eax], al             
  0x0106A1B8  00f4                    add      ah, dh                         
  0x0106A1BA  44                      inc      esp                            
  0x0106A1BB  0000                    add      byte ptr [eax], al             
  0x0106A1BD  3200                    xor      al, byte ptr [eax]             
  0x0106A1BF  0000                    add      byte ptr [eax], al             
  0x0106A1C1  e856004500              call     0x14ba21c                      
  0x0106A1C6  2000                    and      byte ptr [eax], al             
  0x0106A1C8  1b29                    sbb      ebp, dword ptr [ecx]           
  0x0106A1CA  2000                    and      byte ptr [eax], al             
  0x0106A1CC  00f0                    add      al, dh                         
  0x0106A1CE  44                      inc      esp                            
  0x0106A1CF  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A1D2  0000                    add      byte ptr [eax], al             
  0x0106A1D4  00f4                    add      ah, dh                         
  0x0106A1D6  46                      inc      esi                            
  0x0106A1D7  0002                    add      byte ptr [edx], al             
  0x0106A1D9  0000                    add      byte ptr [eax], al             
  0x0106A1DB  00d0                    add      al, dl                         
  0x0106A1DD  f4                      hlt                                     
  0x0106A1DE  44                      inc      esp                            
  0x0106A1DF  0020                    add      byte ptr [eax], ah             
  0x0106A1E1  0900                    or       dword ptr [eax], eax           
  0x0106A1E3  002e                    add      byte ptr [esi], ch             
  0x0106A1E5  1d0c004000              sbb      eax, 0x40000c                  
  0x0106A1EA  2000                    and      byte ptr [eax], al             
  0x0106A1EC  0091210000f4            add      byte ptr [ecx - 0xbffffdf], dl 
  0x0106A1F2  56                      push     esi                            
  0x0106A1F3  0008                    add      byte ptr [eax], cl             
  0x0106A1F5  06                      push     es                             
  0x0106A1F6  0000                    add      byte ptr [eax], al             
  0x0106A1F8  00f0                    add      al, dh                         
  0x0106A1FA  44                      inc      esp                            
  0x0106A1FB  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A1FE  0000                    add      byte ptr [eax], al             
  0x0106A200  40                      inc      eax                            
  0x0106A201  0020                    add      byte ptr [eax], ah             
  0x0106A203  0000                    add      byte ptr [eax], al             
  0x0106A205  90                      nop                                     
  0x0106A206  2100                    and      dword ptr [eax], eax           
  0x0106A208  00e1                    add      cl, ah                         
  0x0106A20A  44                      inc      esp                            
  0x0106A20B  0000                    add      byte ptr [eax], al             
  0x0106A20D  f4                      hlt                                     
  0x0106A20E  46                      inc      esi                            
  0x0106A20F  0000                    add      byte ptr [eax], al             
  0x0106A211  004000                  add      byte ptr [eax], al             
  0x0106A214  d0e0                    shl      al, 1                          
  0x0106A216  46                      inc      esi                            
  0x0106A217  005560                  add      byte ptr [ebp + 0x60], dl      
  0x0106A21A  44                      inc      esp                            
  0x0106A21B  001b                    add      byte ptr [ebx], bl             
  0x0106A21D  2920                    sub      dword ptr [eax], esp           
  0x0106A21F  0000                    add      byte ptr [eax], al             
  0x0106A221  f4                      hlt                                     
  0x0106A222  56                      push     esi                            
  0x0106A223  007f0b                  add      byte ptr [edi + 0xb], bh       
  0x0106A226  0000                    add      byte ptr [eax], al             
  0x0106A228  00f0                    add      al, dh                         
  0x0106A22A  44                      inc      esp                            
  0x0106A22B  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A22E  0000                    add      byte ptr [eax], al             
  0x0106A230  40                      inc      eax                            
  0x0106A231  0020                    add      byte ptr [eax], ah             
  0x0106A233  0000                    add      byte ptr [eax], al             
  0x0106A235  90                      nop                                     
  0x0106A236  2100                    and      dword ptr [eax], eax           
  0x0106A238  006055                  add      byte ptr [eax + 0x55], ah      
  0x0106A23B  0000                    add      byte ptr [eax], al             
  0x0106A23E  44                      inc      esp                            
  0x0106A23F  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A242  0000                    add      byte ptr [eax], al             
  0x0106A244  00f4                    add      ah, dh                         
  0x0106A246  46                      inc      esi                            
  0x0106A247  0012                    add      byte ptr [edx], dl             
  0x0106A249  0000                    add      byte ptr [eax], al             
  0x0106A24B  00d0                    add      al, dl                         
  0x0106A24D  f4                      hlt                                     
  0x0106A24E  44                      inc      esp                            
  0x0106A24F  00ae0500002e            add      byte ptr [esi + 0x2e000005], ch 
  0x0106A255  1d0c004000              sbb      eax, 0x40000c                  
  0x0106A25A  2000                    and      byte ptr [eax], al             
  0x0106A25C  009021000006            add      byte ptr [eax + 0x6000021], dl 
  0x0106A262  3800                    cmp      byte ptr [eax], al             
  0x0106A264  00ae20009003            add      byte ptr [esi + 0x3900020], ch 
  0x0106A26A  06                      push     es                             
  0x0106A26B  000a                    add      byte ptr [edx], cl             
  0x0106A26D  0000                    add      byte ptr [eax], al             
  0x0106A26F  0000                    add      byte ptr [eax], al             
  0x0106A271  1122                    adc      dword ptr [edx], esp           
  0x0106A273  0000                    add      byte ptr [eax], al             
  0x0106A275  99                      cdq                                     
  0x0106A276  2100                    and      dword ptr [eax], eax           
  0x0106A278  0012                    add      byte ptr [edx], dl             
  0x0106A27A  2200                    and      al, byte ptr [eax]             
  0x0106A27C  004920                  add      byte ptr [ecx + 0x20], cl      
  0x0106A27F  0000                    add      byte ptr [eax], al             
  0x0106A281  d9440000                fld      dword ptr [eax + eax]          
  0x0106A285  5a                      pop      edx                            
  0x0106A286  44                      inc      esp                            
  0x0106A287  0000                    add      byte ptr [eax], al             
  0x0106A289  d9440000                fld      dword ptr [eax + eax]          
  0x0106A28D  5a                      pop      edx                            
  0x0106A28E  44                      inc      esp                            
  0x0106A28F  0032                    add      byte ptr [edx], dh             
  0x0106A291  48                      dec      eax                            
  0x0106A292  2000                    and      byte ptr [eax], al             
  0x0106A294  0c00                    or       al, 0                          
  0x0106A296  0000                    add      byte ptr [eax], al             
  0x0106A298  00f4                    add      ah, dh                         
  0x0106A29A  56                      push     esi                            
  0x0106A29B  007f0b                  add      byte ptr [edi + 0xb], bh       
  0x0106A29E  0000                    add      byte ptr [eax], al             
  0x0106A2A0  00f0                    add      al, dh                         
  0x0106A2A2  44                      inc      esp                            
  0x0106A2A3  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A2A6  0000                    add      byte ptr [eax], al             
  0x0106A2A8  40                      inc      eax                            
  0x0106A2A9  0020                    add      byte ptr [eax], ah             
  0x0106A2AB  0000                    add      byte ptr [eax], al             
  0x0106A2AD  90                      nop                                     
  0x0106A2AE  2100                    and      dword ptr [eax], eax           
  0x0106A2B0  00f4                    add      ah, dh                         
  0x0106A2B2  56                      push     esi                            
  0x0106A2B3  000d06000000            add      byte ptr [6], cl               
  0x0106A2BA  44                      inc      esp                            
  0x0106A2BB  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A2BE  0000                    add      byte ptr [eax], al             
  0x0106A2C0  40                      inc      eax                            
  0x0106A2C1  0020                    add      byte ptr [eax], ah             
  0x0106A2C3  0000                    add      byte ptr [eax], al             
  0x0106A2C5  91                      xchg     ecx, eax                       
  0x0106A2C6  2100                    and      dword ptr [eax], eax           
  0x0106A2C8  00f4                    add      ah, dh                         
  0x0106A2CA  56                      push     esi                            
  0x0106A2CB  00840b000000f0          add      byte ptr [ebx + ecx - 0x10000000], al 
  0x0106A2D2  44                      inc      esp                            
  0x0106A2D3  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A2D6  0000                    add      byte ptr [eax], al             
  0x0106A2D8  40                      inc      eax                            
  0x0106A2D9  0020                    add      byte ptr [eax], ah             
  0x0106A2DB  0000                    add      byte ptr [eax], al             
  0x0106A2DD  92                      xchg     edx, eax                       
  0x0106A2DE  2100                    and      dword ptr [eax], eax           
  0x0106A2E0  1be0                    sbb      esp, eax                       
  0x0106A2E2  44                      inc      esp                            
  0x0106A2E3  0000                    add      byte ptr [eax], al             
  0x0106A2E5  e156                    loope    0x106a33d                      
  0x0106A2E7  0042f4                  add      byte ptr [edx - 0xc], al       
  0x0106A2EA  45                      inc      ebp                            
  0x0106A2EB  0001                    add      byte ptr [ecx], al             
  0x0106A2ED  0000                    add      byte ptr [eax], al             
  0x0106A2EF  0068a0                  add      byte ptr [eax - 0x60], ch      
  0x0106A2F2  0200                    add      al, byte ptr [eax]             
  0x0106A2F4  006257                  add      byte ptr [edx + 0x57], ah      
  0x0106A2F7  0000                    add      byte ptr [eax], al             
  0x0106A2F9  61                      popal                                   
  0x0106A2FA  44                      inc      esp                            
  0x0106A2FB  000c00                  add      byte ptr [eax + eax], cl       
  0x0106A2FE  0000                    add      byte ptr [eax], al             
  0x0106A300  00f4                    add      ah, dh                         
  0x0106A302  60                      pushal                                  
  0x0106A303  00fd                    add      ch, bh                         
  0x0106A305  0200                    add      al, byte ptr [eax]             
  0x0106A307  0000                    add      byte ptr [eax], al             
  0x0106A30A  44                      inc      esp                            
  0x0106A30B  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A30E  0000                    add      byte ptr [eax], al             
  0x0106A310  00f4                    add      ah, dh                         
  0x0106A312  46                      inc      esi                            
  0x0106A313  0080000000d0            add      byte ptr [eax - 0x30000000], al 
  0x0106A319  f4                      hlt                                     
  0x0106A31A  44                      inc      esp                            
  0x0106A31B  0012                    add      byte ptr [edx], dl             
  0x0106A31D  06                      push     es                             
  0x0106A31E  0000                    add      byte ptr [eax], al             
  0x0106A320  2e1d0c004000            sbb      eax, 0x40000c                  
  0x0106A326  2000                    and      byte ptr [eax], al             
  0x0106A328  0091210000f4            add      byte ptr [ecx - 0xbffffdf], dl 
  0x0106A32E  6400b208000000          add      byte ptr fs:[edx + 8], dh      
  0x0106A335  f4                      hlt                                     
  0x0106A336  650000                  add      byte ptr gs:[eax], al          
  0x0106A339  0000                    add      byte ptr [eax], al             
  0x0106A33B  00fc                    add      ah, bh                         
                                        ; XREF: 0x0106A2E5 (cond_jump)
  0x0106A33D  040d                    add      al, 0xd                        
  0x0106A33F  000c00                  add      byte ptr [eax + eax], cl       
  0x0106A342  0000                    add      byte ptr [eax], al             
  0x0106A344  00f0                    add      al, dh                         
  0x0106A346  56                      push     esi                            
  0x0106A347  0031                    add      byte ptr [ecx], dh             
  0x0106A349  0900                    or       dword ptr [eax], eax           
  0x0106A34B  0003                    add      byte ptr [ebx], al             
  0x0106A34D  0020                    add      byte ptr [eax], ah             
  0x0106A34F  000e                    add      byte ptr [esi], cl             
  0x0106A351  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106A352  050000f460              add      eax, 0x60f40000                
  0x0106A357  0000                    add      byte ptr [eax], al             
  0x0106A359  0000                    add      byte ptr [eax], al             
  0x0106A35B  0000                    add      byte ptr [eax], al             
  0x0106A35D  f4                      hlt                                     
  0x0106A35E  61                      popal                                   
  0x0106A35F  004000                  add      byte ptr [eax], al             
  0x0106A362  0000                    add      byte ptr [eax], al             
  0x0106A364  001422                  add      byte ptr [edx], dl             
  0x0106A367  0000                    add      byte ptr [eax], al             
  0x0106A369  35220000f4              xor      eax, 0xf4000022                
  0x0106A36E  6200                    bound    eax, qword ptr [eax]           
  0x0106A370  b20a                    mov      dl, 0xa                        
  0x0106A372  0000                    add      byte ptr [eax], al             
  0x0106A374  00f4                    add      ah, dh                         
  0x0106A376  6600f2                  add      dl, dh                         
  0x0106A379  0a00                    or       al, byte ptr [eax]             
  0x0106A37B  0000                    add      byte ptr [eax], al             
  0x0106A37D  3f                      aas                                     
  0x0106A37E  3a00                    cmp      al, byte ptr [eax]             
  0x0106A380  4d                      dec      ebp                            
  0x0106A381  050d000a0c              add      eax, 0xc0a000d                 
  0x0106A386  050000f460              add      eax, 0x60f40000                
  0x0106A38B  0000                    add      byte ptr [eax], al             
  0x0106A38D  0000                    add      byte ptr [eax], al             
  0x0106A38F  0000                    add      byte ptr [eax], al             
  0x0106A391  1422                    adc      al, 0x22                       
  0x0106A393  0000                    add      byte ptr [eax], al             
  0x0106A395  f4                      hlt                                     
  0x0106A396  6200                    bound    eax, qword ptr [eax]           
  0x0106A398  b209                    mov      dl, 9                          
  0x0106A39A  0000                    add      byte ptr [eax], al             
  0x0106A39C  00f4                    add      ah, dh                         
  0x0106A39E  660032                  add      byte ptr [edx], dh             
  0x0106A3A1  0a00                    or       al, byte ptr [eax]             
  0x0106A3A3  0000                    add      byte ptr [eax], al             
  0x0106A3A5  7f3a                    jg       0x106a3e1                      
  0x0106A3A7  003e                    add      byte ptr [esi], bh             
  0x0106A3A9  050d000c00              add      eax, 0xc000d                   
  0x0106A3AE  0000                    add      byte ptr [eax], al             
  0x0106A3B0  a0000500a0              mov      al, byte ptr [0xa0000500]      
  0x0106A3B5  61                      popal                                   
  0x0106A3B6  0400                    add      al, 0                          
  0x0106A3B8  00f0                    add      al, dh                         
  0x0106A3BA  56                      push     esi                            
  0x0106A3BB  0031                    add      byte ptr [ecx], dh             
  0x0106A3BD  0900                    or       dword ptr [eax], eax           
  0x0106A3BF  0003                    add      byte ptr [ebx], al             
  0x0106A3C1  0020                    add      byte ptr [eax], ah             
  0x0106A3C3  0015a4050000            add      byte ptr [0x5a4], dl           
  0x0106A3C9  f4                      hlt                                     
  0x0106A3CA  60                      pushal                                  
  0x0106A3CB  0000                    add      byte ptr [eax], al             
  0x0106A3CD  0000                    add      byte ptr [eax], al             
  0x0106A3CF  0000                    add      byte ptr [eax], al             
  0x0106A3D1  f4                      hlt                                     
  0x0106A3D2  61                      popal                                   
  0x0106A3D3  004000                  add      byte ptr [eax], al             
  0x0106A3D6  0000                    add      byte ptr [eax], al             
  0x0106A3D8  00f4                    add      ah, dh                         
  0x0106A3DA  6400fd                  add      ch, bh                         
  0x0106A3DD  0300                    add      eax, dword ptr [eax]           
  0x0106A3DF  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x0106A3A5 (cond_jump)
  0x0106A3E1  f4                      hlt                                     
  0x0106A3E2  6500fc                  add      ah, bh                         
  0x0106A3E5  0400                    add      al, 0                          
  0x0106A3E7  0000                    add      byte ptr [eax], al             
  0x0106A3E9  f4                      hlt                                     
  0x0106A3EA  6200                    bound    eax, qword ptr [eax]           
  0x0106A3EC  b20a                    mov      dl, 0xa                        
  0x0106A3EE  0000                    add      byte ptr [eax], al             
  0x0106A3F0  00f4                    add      ah, dh                         
  0x0106A3F2  6600f2                  add      dl, dh                         
  0x0106A3F5  0a00                    or       al, byte ptr [eax]             
  0x0106A3F7  0000                    add      byte ptr [eax], al             
  0x0106A3F9  2038                    and      byte ptr [eax], bh             
  0x0106A3FB  0000                    add      byte ptr [eax], al             
  0x0106A3FD  1923                    sbb      dword ptr [ebx], esp           
  0x0106A3FF  0000                    add      byte ptr [eax], al             
  0x0106A401  3f                      aas                                     
  0x0106A402  3a00                    cmp      al, byte ptr [eax]             
  0x0106A404  0003                    add      byte ptr [ebx], al             
  0x0106A406  3c00                    cmp      al, 0                          
  0x0106A408  00f4                    add      ah, dh                         
  0x0106A40A  7500                    jne      0x106a40c                      
                                        ; XREF: 0x0106A40A (cond_jump)
  0x0106A40C  fd                      std                                     
  0x0106A40E  ff00                    inc      dword ptr [eax]                
  0x0106A410  7305                    jae      0x106a417                      
  0x0106A412  0d00110c05              or       eax, 0x50c1100                 
                                        ; XREF: 0x0106A410 (cond_jump)
  0x0106A417  0000                    add      byte ptr [eax], al             
  0x0106A419  f4                      hlt                                     
  0x0106A41A  60                      pushal                                  
  0x0106A41B  0000                    add      byte ptr [eax], al             
  0x0106A41D  0000                    add      byte ptr [eax], al             
  0x0106A41F  0000                    add      byte ptr [eax], al             
  0x0106A421  f4                      hlt                                     
  0x0106A422  6400fd                  add      ch, bh                         
  0x0106A425  0300                    add      eax, dword ptr [eax]           
  0x0106A427  0000                    add      byte ptr [eax], al             
  0x0106A429  f4                      hlt                                     
  0x0106A42A  6500fc                  add      ah, bh                         
  0x0106A42D  0400                    add      al, 0                          
  0x0106A42F  0000                    add      byte ptr [eax], al             
  0x0106A431  f4                      hlt                                     
  0x0106A432  6200                    bound    eax, qword ptr [eax]           
  0x0106A434  b209                    mov      dl, 9                          
  0x0106A436  0000                    add      byte ptr [eax], al             
  0x0106A438  00f4                    add      ah, dh                         
  0x0106A43A  660032                  add      byte ptr [edx], dh             
  0x0106A43D  0a00                    or       al, byte ptr [eax]             
  0x0106A43F  0000                    add      byte ptr [eax], al             
  0x0106A441  40                      inc      eax                            
  0x0106A442  3800                    cmp      byte ptr [eax], al             
  0x0106A444  007f3a                  add      byte ptr [edi + 0x3a], bh      
  0x0106A447  0000                    add      byte ptr [eax], al             
  0x0106A449  023c00                  add      bh, byte ptr [eax + eax]       
  0x0106A44C  00f4                    add      ah, dh                         
  0x0106A44E  7500                    jne      0x106a450                      
  0x0106A452  ff00                    inc      dword ptr [eax]                
  0x0106A454  64050d0020f4            add      eax, 0xf420000d                
  0x0106A45A  0500ffff00              add      eax, 0xffff00                  
  0x0106A45F  00a061040000            add      byte ptr [eax + 0x461], ah     
  0x0106A466  56                      push     esi                            
  0x0106A467  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A46A  0000                    add      byte ptr [eax], al             
  0x0106A46C  00f0                    add      al, dh                         
  0x0106A46E  44                      inc      esp                            
  0x0106A46F  00970b000045            add      byte ptr [edi + 0x4500000b], dl 
  0x0106A475  f4                      hlt                                     
  0x0106A476  60                      pushal                                  
  0x0106A477  00fd                    add      ch, bh                         
  0x0106A479  0300                    add      eax, dword ptr [eax]           
  0x0106A47B  0008                    add      byte ptr [eax], cl             
  0x0106A47D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106A47E  050000f461              add      eax, 0x61f40000                
  0x0106A483  008001000090            add      byte ptr [eax - 0x6fffffff], al 
  0x0106A489  b506                    mov      ch, 6                          
  0x0106A48B  0003                    add      byte ptr [ebx], al             
  0x0106A48D  0000                    add      byte ptr [eax], al             
  0x0106A48F  0000                    add      byte ptr [eax], al             
  0x0106A491  d8440000                fadd     dword ptr [eax + eax]          
  0x0106A495  59                      pop      ecx                            
  0x0106A496  44                      inc      esp                            
  0x0106A497  0007                    add      byte ptr [edi], al             
  0x0106A499  0c05                    or       al, 5                          
  0x0106A49B  0000                    add      byte ptr [eax], al             
  0x0106A49D  f4                      hlt                                     
  0x0106A49E  61                      popal                                   
  0x0106A49F  003502000090            add      byte ptr [0x90000002], dh      
  0x0106A4A5  07                      pop      es                             
  0x0106A4A6  06                      push     es                             
  0x0106A4A7  0003                    add      byte ptr [ebx], al             
  0x0106A4A9  0000                    add      byte ptr [eax], al             
  0x0106A4AB  0000                    add      byte ptr [eax], al             
  0x0106A4AD  d8440000                fadd     dword ptr [eax + eax]          
  0x0106A4B1  59                      pop      ecx                            
  0x0106A4B2  44                      inc      esp                            
  0x0106A4B3  000c00                  add      byte ptr [eax + eax], cl       
  0x0106A4B6  0000                    add      byte ptr [eax], al             
  0x0106A4B8  00f0                    add      al, dh                         
  0x0106A4BA  56                      push     esi                            
  0x0106A4BB  0031                    add      byte ptr [ecx], dh             
  0x0106A4BD  0900                    or       dword ptr [eax], eax           
  0x0106A4BF  0003                    add      byte ptr [ebx], al             
  0x0106A4C1  0020                    add      byte ptr [eax], ah             
  0x0106A4C3  000a                    add      byte ptr [edx], cl             
  0x0106A4C5  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106A4C6  050000f460              add      eax, 0x60f40000                
  0x0106A4CB  0000                    add      byte ptr [eax], al             
  0x0106A4CD  0000                    add      byte ptr [eax], al             
  0x0106A4CF  0000                    add      byte ptr [eax], al             
  0x0106A4D1  40                      inc      eax                            
  0x0106A4D2  3800                    cmp      byte ptr [eax], al             
  0x0106A4D4  ef                      out      dx, eax                        
  0x0106A4D5  030d0000f460            add      ecx, dword ptr [0x60f40000]    
  0x0106A4DB  004000                  add      byte ptr [eax], al             
  0x0106A4DE  0000                    add      byte ptr [eax], al             
  0x0106A4E0  004038                  add      byte ptr [eax + 0x38], al      
  0x0106A4E3  00ef                    add      bh, ch                         
  0x0106A4E5  030d00050c05            add      ecx, dword ptr [0x50c0500]     
  0x0106A4EB  0000                    add      byte ptr [eax], al             
  0x0106A4ED  f4                      hlt                                     
  0x0106A4EE  60                      pushal                                  
  0x0106A4EF  0000                    add      byte ptr [eax], al             
  0x0106A4F1  0000                    add      byte ptr [eax], al             
  0x0106A4F3  0000                    add      byte ptr [eax], al             
  0x0106A4F5  803800                  cmp      byte ptr [eax], 0              
  0x0106A4F8  ef                      out      dx, eax                        
  0x0106A4F9  030d000c0000            add      ecx, dword ptr [0xc00]         
  0x0106A4FF  0000                    add      byte ptr [eax], al             
  0x0106A502  56                      push     esi                            
  0x0106A503  00970b000000            add      byte ptr [edi + 0xb], dl       
  0x0106A50A  44                      inc      esp                            
  0x0106A50B  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A50E  0000                    add      byte ptr [eax], al             
  0x0106A510  45                      inc      ebp                            
  0x0106A511  f4                      hlt                                     
  0x0106A512  45                      inc      ebp                            
  0x0106A513  0001                    add      byte ptr [ecx], al             
  0x0106A515  0000                    add      byte ptr [eax], al             
  0x0106A517  0003                    add      byte ptr [ebx], al             
  0x0106A519  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106A51A  05000d0805              add      eax, 0x5080d00                 
  0x0106A51F  0003                    add      byte ptr [ebx], al             
  0x0106A521  0c05                    or       al, 5                          
  0x0106A523  0000                    add      byte ptr [eax], al             
  0x0106A525  7045                    jo       0x106a56c                      
  0x0106A527  008f0b000000            add      byte ptr [edi + 0xb], cl       
  0x0106A52D  f4                      hlt                                     
  0x0106A52E  60                      pushal                                  
  0x0106A52F  007f0b                  add      byte ptr [edi + 0xb], bh       
  0x0106A532  0000                    add      byte ptr [eax], al             
  0x0106A534  00f4                    add      ah, dh                         
  0x0106A536  61                      popal                                   
  0x0106A537  00a305000090            add      byte ptr [ebx - 0x6ffffffb], ah 
  0x0106A53D  0506000300              add      eax, 0x30006                   
  0x0106A542  0000                    add      byte ptr [eax], al             
  0x0106A544  00d8                    add      al, bl                         
  0x0106A546  44                      inc      esp                            
  0x0106A547  0000                    add      byte ptr [eax], al             
  0x0106A549  59                      pop      ecx                            
  0x0106A54A  44                      inc      esp                            
  0x0106A54B  000c00                  add      byte ptr [eax + eax], cl       
  0x0106A54E  0000                    add      byte ptr [eax], al             
  0x0106A550  0003                    add      byte ptr [ebx], al             
  0x0106A552  2900                    sub      dword ptr [eax], eax           
  0x0106A554  00f0                    add      al, dh                         
  0x0106A556  7000                    jo       0x106a558                      
                                        ; XREF: 0x0106A556 (cond_jump)
  0x0106A558  41                      inc      ecx                            
  0x0106A559  0b00                    or       eax, dword ptr [eax]           
  0x0106A55B  0000                    add      byte ptr [eax], al             
  0x0106A55D  f4                      hlt                                     
  0x0106A55E  60                      pushal                                  
  0x0106A55F  007f0b                  add      byte ptr [edi + 0xb], bh       
  0x0106A562  0000                    add      byte ptr [eax], al             
  0x0106A564  00e8                    add      al, ch                         
  0x0106A566  56                      push     esi                            
  0x0106A567  008541010010            add      byte ptr [ebp + 0x10000141], al 
  0x0106A56D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106A56E  050000f460              add      eax, 0x60f40000                
  0x0106A573  002c09                  add      byte ptr [ecx + ecx], ch       
  0x0106A576  0000                    add      byte ptr [eax], al             
  0x0106A578  00e8                    add      al, ch                         
  0x0106A57A  56                      push     esi                            
  0x0106A57B  00854101000b            add      byte ptr [ebp + 0xb000141], al 
  0x0106A581  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106A582  050000f056              add      eax, 0x56f00000                
  0x0106A587  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106A58A  0000                    add      byte ptr [eax], al             
  0x0106A58C  854001                  test     dword ptr [eax + 1], eax       
  0x0106A58F  0006                    add      byte ptr [esi], al             
  0x0106A591  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106A592  050000f460              add      eax, 0x60f40000                
  0x0106A597  00a305000000            add      byte ptr [ebx + 5], ah         
  0x0106A59D  e856008541              call     0x428ba5f8                     
  0x0106A5A2  0100                    add      dword ptr [eax], eax           
  0x0106A5A4  02a40500000229          add      ah, byte ptr [ebp + eax + 0x29020000] 
  0x0106A5AB  0000                    add      byte ptr [eax], al             
  0x0106A5AD  f4                      hlt                                     
  0x0106A5AE  60                      pushal                                  
  0x0106A5AF  008a0b000000            add      byte ptr [edx + 0xb], cl       
  0x0106A5B5  6851000c00              push     0xc0051                        
  0x0106A5BA  0000                    add      byte ptr [eax], al             
  0x0106A5BC  0018                    add      byte ptr [eax], bl             
  0x0106A5BE  3d0000f044              cmp      eax, 0x44f00000                
  0x0106A5C3  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A5C6  0000                    add      byte ptr [eax], al             
  0x0106A5C8  00f0                    add      al, dh                         
  0x0106A5CA  56                      push     esi                            
  0x0106A5CB  00970b000045            add      byte ptr [edi + 0x4500000b], dl 
  0x0106A5D1  f4                      hlt                                     
  0x0106A5D2  60                      pushal                                  
  0x0106A5D3  00800100000c            add      byte ptr [eax + 0xc000001], al 
  0x0106A5D9  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106A5DA  0500009620              add      eax, 0x20960000                
  0x0106A5DF  0000                    add      byte ptr [eax], al             
  0x0106A5E1  f4                      hlt                                     
  0x0106A5E2  61                      popal                                   
  0x0106A5E3  004102                  add      byte ptr [ecx + 2], al         
  0x0106A5E6  0000                    add      byte ptr [eax], al             
  0x0106A5E8  00f4                    add      ah, dh                         
  0x0106A5EA  56                      push     esi                            
  0x0106A5EB  00a50b000000            add      byte ptr [ebp + 0xb], ah       
  0x0106A5F1  c422                    les      esp, ptr [edx]                 
  0x0106A5F3  004000                  add      byte ptr [eax], al             
  0x0106A5F6  2000                    and      byte ptr [eax], al             
  0x0106A5F8  0092210000e2            add      byte ptr [edx - 0x1dffffdf], dl 
  0x0106A5FE  7100                    jno      0x106a600                      
                                        ; XREF: 0x0106A5FE (cond_jump)
  0x0106A600  8b050d000a0c            mov      eax, dword ptr [0xc0a000d]     
  0x0106A606  050000f056              add      eax, 0x56f00000                
  0x0106A60B  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x0106A60E  0000                    add      byte ptr [eax], al             
  0x0106A610  03f4                    add      esi, esp                       
  0x0106A612  60                      pushal                                  
  0x0106A613  003502000005            add      byte ptr [0x5000002], dh       
  0x0106A619  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106A61A  050000f461              add      eax, 0x61f40000                
  0x0106A61F  00f6                    add      dh, dh                         
  0x0106A621  0200                    add      al, byte ptr [eax]             
  0x0106A623  0000                    add      byte ptr [eax], al             
  0x0106A625  07                      pop      es                             
  0x0106A626  3900                    cmp      dword ptr [eax], eax           
  0x0106A628  8b050d000c00            mov      eax, dword ptr [0xc000d]       
  0x0106A62E  0000                    add      byte ptr [eax], al             
  0x0106A630  00f0                    add      al, dh                         
  0x0106A632  44                      inc      esp                            
  0x0106A633  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A636  0000                    add      byte ptr [eax], al             
  0x0106A638  00f0                    add      al, dh                         
  0x0106A63A  56                      push     esi                            
  0x0106A63B  00970b000045            add      byte ptr [edi + 0x4500000b], dl 
  0x0106A641  f4                      hlt                                     
  0x0106A642  61                      popal                                   
  0x0106A643  004102                  add      byte ptr [ecx + 2], al         
  0x0106A646  0000                    add      byte ptr [eax], al             
  0x0106A648  59                      pop      ecx                            
  0x0106A649  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106A64A  050000f456              add      eax, 0x56f40000                
  0x0106A64F  008a0b000000            add      byte ptr [edx + 0xb], cl       
  0x0106A656  44                      inc      esp                            
  0x0106A657  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A65A  0000                    add      byte ptr [eax], al             
  0x0106A65C  40                      inc      eax                            
  0x0106A65D  0020                    add      byte ptr [eax], ah             
  0x0106A65F  0000                    add      byte ptr [eax], al             
  0x0106A661  90                      nop                                     
  0x0106A662  2100                    and      dword ptr [eax], eax           
  0x0106A664  00f4                    add      ah, dh                         
  0x0106A666  56                      push     esi                            
  0x0106A667  00a50b000000            add      byte ptr [ebp + 0xb], ah       
  0x0106A66E  44                      inc      esp                            
  0x0106A66F  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A672  0000                    add      byte ptr [eax], al             
  0x0106A674  40                      inc      eax                            
  0x0106A675  0020                    add      byte ptr [eax], ah             
  0x0106A677  0000                    add      byte ptr [eax], al             
  0x0106A679  92                      xchg     edx, eax                       
  0x0106A67A  2100                    and      dword ptr [eax], eax           
  0x0106A67C  00e0                    add      al, ah                         
  0x0106A67E  56                      push     esi                            
  0x0106A67F  0000                    add      byte ptr [eax], al             
  0x0106A681  e271                    loop     0x106a6f4                      
  0x0106A683  0000                    add      byte ptr [eax], al             
  0x0106A685  94                      xchg     esp, eax                       
  0x0106A686  2100                    and      dword ptr [eax], eax           
  0x0106A688  0036                    add      byte ptr [esi], dh             
  0x0106A68A  2200                    and      al, byte ptr [eax]             
  0x0106A68C  00f4                    add      ah, dh                         
  0x0106A68E  56                      push     esi                            
  0x0106A68F  005c0b00                add      byte ptr [ebx + ecx], bl       
  0x0106A693  0000                    add      byte ptr [eax], al             
  0x0106A696  44                      inc      esp                            
  0x0106A697  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A69A  0000                    add      byte ptr [eax], al             
  0x0106A69C  40                      inc      eax                            
  0x0106A69D  0020                    add      byte ptr [eax], ah             
  0x0106A69F  0000                    add      byte ptr [eax], al             
  0x0106A6A1  90                      nop                                     
  0x0106A6A2  2100                    and      dword ptr [eax], eax           
  0x0106A6A4  00f4                    add      ah, dh                         
  0x0106A6A6  56                      push     esi                            
  0x0106A6A7  00910b000000            add      byte ptr [ecx + 0xb], dl       
  0x0106A6AE  44                      inc      esp                            
  0x0106A6AF  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106A6B2  0000                    add      byte ptr [eax], al             
  0x0106A6B4  40                      inc      eax                            
  0x0106A6B5  0020                    add      byte ptr [eax], ah             
  0x0106A6B7  0000                    add      byte ptr [eax], al             
  0x0106A6B9  92                      xchg     edx, eax                       
  0x0106A6BA  2100                    and      dword ptr [eax], eax           
  0x0106A6BC  002e                    add      byte ptr [esi], ch             
  0x0106A6BE  2300                    and      eax, dword ptr [eax]           
  0x0106A6C0  844101                  test     byte ptr [ecx + 1], al         
  0x0106A6C3  00c4                    add      ah, al                         
  0x0106A6C5  740b                    je       0x106a6d2                      
  0x0106A6C7  0016                    add      byte ptr [esi], dl             
  0x0106A6C9  0f0000                  sldt     word ptr [eax]                 
  0x0106A6CC  00852100adf4            add      byte ptr [ebp - 0xb52ffdf], al 
                                        ; XREF: 0x0106A6C5 (cond_jump)
  0x0106A6D2  47                      inc      edi                            
  0x0106A6D3  0001                    add      byte ptr [ecx], al             
  0x0106A6D5  0000                    add      byte ptr [eax], al             
  0x0106A6D7  00c4                    add      ah, al                         
  0x0106A6D9  740b                    je       0x106a6e6                      
  0x0106A6DB  0012                    add      byte ptr [edx], dl             
  0x0106A6DD  0f0000                  sldt     word ptr [eax]                 
  0x0106A6E0  00e6                    add      dh, ah                         
  0x0106A6E2  2100                    and      dword ptr [eax], eax           
  0x0106A6E4  d09d20002e1d            rcr      byte ptr [ebp + 0x1d2e0020], 1 
  0x0106A6EA  0c00                    or       al, 0                          
  0x0106A6EC  65f4                    hlt                                     
  0x0106A6EE  46                      inc      esi                            
  0x0106A6EF  00abaa2a0078            add      byte ptr [ebx + 0x78002aaa], ch 
  0x0106A6F5  2920                    sub      dword ptr [eax], esp           
  0x0106A6F7  0000                    add      byte ptr [eax], al             
  0x0106A6F9  60                      pushal                                  
  0x0106A6FA  55                      push     ebp                            
  0x0106A6FB  0000                    add      byte ptr [eax], al             
  0x0106A6FD  a5                      movsd    dword ptr es:[edi], dword ptr [esi] 
  0x0106A6FE  2100                    and      dword ptr [eax], eax           
  0x0106A700  e9bc210082              jmp      0x8306c8c1                     
  0x0106A705  1d0c001000              sbb      eax, 0x10000c                  
  0x0106A70A  2000                    and      byte ptr [eax], al             
  0x0106A70C  650020                  add      byte ptr gs:[eax], ah          
  0x0106A70F  007829                  add      byte ptr [eax + 0x29], bh      
  0x0106A712  2000                    and      byte ptr [eax], al             
  0x0106A714  006255                  add      byte ptr [edx + 0x55], ah      
  0x0106A717  0000                    add      byte ptr [eax], al             
  0x0106A719  3222                    xor      ah, byte ptr [edx]             
  0x0106A71B  0000                    add      byte ptr [eax], al             
  0x0106A71D  59                      pop      ecx                            
  0x0106A71E  2000                    and      byte ptr [eax], al             
  0x0106A720  0000                    add      byte ptr [eax], al             
  0x0106A722  3a00                    cmp      al, byte ptr [eax]             
  0x0106A724  96                      xchg     esi, eax                       
  0x0106A725  050d00110c              add      eax, 0xc11000d                 
  0x0106A72A  050000f056              add      eax, 0x56f00000                
  0x0106A72F  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x0106A732  0000                    add      byte ptr [eax], al             
  0x0106A734  03f4                    add      esi, esp                       
  0x0106A736  60                      pushal                                  
  0x0106A737  008f0b00000c            add      byte ptr [edi + 0xc00000b], cl 
  0x0106A73D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106A73E  050000f461              add      eax, 0x61f40000                
  0x0106A743  00f6                    add      dh, dh                         
  0x0106A745  0200                    add      al, byte ptr [eax]             
  0x0106A747  0000                    add      byte ptr [eax], al             
  0x0106A749  07                      pop      es                             
  0x0106A74A  3900                    cmp      dword ptr [eax], eax           
  0x0106A74C  0036                    add      byte ptr [esi], dh             
  0x0106A74E  2200                    and      al, byte ptr [eax]             
  0x0106A750  0032                    add      byte ptr [edx], dh             
  0x0106A752  2200                    and      al, byte ptr [eax]             
  0x0106A754  005920                  add      byte ptr [ecx + 0x20], bl      
  0x0106A757  0000                    add      byte ptr [eax], al             
  0x0106A759  003a                    add      byte ptr [edx], bh             
  0x0106A75B  0000                    add      byte ptr [eax], al             
  0x0106A75D  06                      push     es                             
  0x0106A75E  3c00                    cmp      al, 0                          
  0x0106A760  00f0                    add      al, dh                         
  0x0106A762  7d00                    jge      0x106a764                      
                                        ; XREF: 0x0106A762 (cond_jump)
  0x0106A764  130f                    adc      ecx, dword ptr [edi]           
  0x0106A766  0000                    add      byte ptr [eax], al             
  0x0106A768  96                      xchg     esi, eax                       
  0x0106A769  050d000c00              add      eax, 0xc000d                   
  0x0106A76E  0000                    add      byte ptr [eax], al             
  0x0106A770  00f0                    add      al, dh                         
  0x0106A772  56                      push     esi                            
  0x0106A773  004002                  add      byte ptr [eax + 2], al         
  0x0106A776  0000                    add      byte ptr [eax], al             
  0x0106A778  041d                    add      al, 0x1d                       
  0x0106A77A  0c00                    or       al, 0                          
  0x0106A77C  00c7                    add      bh, al                         
  0x0106A77E  2100                    and      dword ptr [eax], eax           
  0x0106A780  00f4                    add      ah, dh                         
  0x0106A782  46                      inc      esi                            
  0x0106A783  0003                    add      byte ptr [ebx], al             
  0x0106A785  0000                    add      byte ptr [eax], al             
  0x0106A787  00b00020002e            add      byte ptr [eax + 0x2e002000], dh 
  0x0106A78D  1d0c00c040              sbb      eax, 0x40c0000c                
  0x0106A792  0100                    add      dword ptr [eax], eax           
  0x0106A794  49                      dec      ecx                            
  0x0106A795  0000                    add      byte ptr [eax], al             
  0x0106A797  0000                    add      byte ptr [eax], al             
  0x0106A79A  2100                    and      dword ptr [eax], eax           
  0x0106A79C  00f4                    add      ah, dh                         
  0x0106A79E  61                      popal                                   
  0x0106A79F  00a00b000000            add      byte ptr [eax + 0xb], ah       
  0x0106A7A5  f4                      hlt                                     
  0x0106A7A6  6200                    bound    eax, qword ptr [eax]           
  0x0106A7A8  a5                      movsd    dword ptr es:[edi], dword ptr [esi] 
  0x0106A7A9  0b00                    or       eax, dword ptr [eax]           
  0x0106A7AB  0000                    add      byte ptr [eax], al             
  0x0106A7AE  45                      inc      ebp                            
  0x0106A7AF  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x0106A7B5  c506                    lds      eax, ptr [esi]                 
  0x0106A7B7  0003                    add      byte ptr [ebx], al             
  0x0106A7B9  0000                    add      byte ptr [eax], al             
  0x0106A7BB  0000                    add      byte ptr [eax], al             
  0x0106A7BD  59                      pop      ecx                            
  0x0106A7BE  47                      inc      edi                            
  0x0106A7BF  0000                    add      byte ptr [eax], al             
  0x0106A7C1  5a                      pop      edx                            
  0x0106A7C2  46                      inc      esi                            
  0x0106A7C3  0000                    add      byte ptr [eax], al             
  0x0106A7C5  f4                      hlt                                     
  0x0106A7C6  57                      push     edi                            
  0x0106A7C7  0001                    add      byte ptr [ecx], al             
  0x0106A7C9  0000                    add      byte ptr [eax], al             
  0x0106A7CB  0000                    add      byte ptr [eax], al             
  0x0106A7CE  56                      push     esi                            
  0x0106A7CF  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106A7D2  0000                    add      byte ptr [eax], al             
  0x0106A7D4  0300                    add      eax, dword ptr [eax]           
  0x0106A7D6  2000                    and      byte ptr [eax], al             
  0x0106A7D8  02a405001b0020          add      ah, byte ptr [ebp + eax + 0x20001b00] 
  0x0106A7DF  0000                    add      byte ptr [eax], al             
  0x0106A7E1  7057                    jo       0x106a83a                      
  0x0106A7E3  00900b00000c            add      byte ptr [eax + 0xc00000b], dl 
  0x0106A7E9  0000                    add      byte ptr [eax], al             
  0x0106A7EB  0000                    add      byte ptr [eax], al             
  0x0106A7ED  f4                      hlt                                     
  0x0106A7EE  56                      push     esi                            
  0x0106A7EF  0012                    add      byte ptr [edx], dl             
  0x0106A7F1  0000                    add      byte ptr [eax], al             
  0x0106A7F3  0000                    add      byte ptr [eax], al             
  0x0106A7F5  f4                      hlt                                     
  0x0106A7F6  57                      push     edi                            
  0x0106A7F7  0000                    add      byte ptr [eax], al             
  0x0106A7F9  0000                    add      byte ptr [eax], al             
  0x0106A7FB  0000                    add      byte ptr [eax], al             
  0x0106A7FD  f4                      hlt                                     
  0x0106A7FE  7000                    jo       0x106a800                      
                                        ; XREF: 0x0106A7FE (cond_jump)
  0x0106A800  16                      push     ss                             
  0x0106A801  0400                    add      al, 0                          
  0x0106A803  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x0106A809  0100                    add      dword ptr [eax], eax           
  0x0106A80B  0003                    add      byte ptr [ebx], al             
  0x0106A80D  0020                    add      byte ptr [eax], ah             
  0x0106A80F  0000                    add      byte ptr [eax], al             
  0x0106A811  2405                    and      al, 5                          
  0x0106A813  000c00                  add      byte ptr [eax + eax], cl       
  0x0106A816  0000                    add      byte ptr [eax], al             
  0x0106A818  00f4                    add      ah, dh                         
  0x0106A81A  56                      push     esi                            
  0x0106A81B  0012                    add      byte ptr [edx], dl             
  0x0106A81D  0000                    add      byte ptr [eax], al             
  0x0106A81F  0000                    add      byte ptr [eax], al             
  0x0106A821  f4                      hlt                                     
  0x0106A822  57                      push     edi                            
  0x0106A823  0001                    add      byte ptr [ecx], al             
  0x0106A825  0000                    add      byte ptr [eax], al             
  0x0106A827  0000                    add      byte ptr [eax], al             
  0x0106A829  f4                      hlt                                     
  0x0106A82A  60                      pushal                                  
  0x0106A82B  00fd                    add      ch, bh                         
  0x0106A82D  0400                    add      al, 0                          
  0x0106A82F  0000                    add      byte ptr [eax], al             
  0x0106A831  f4                      hlt                                     
  0x0106A832  7000                    jo       0x106a834                      
                                        ; XREF: 0x0106A832 (cond_jump)
  0x0106A834  16                      push     ss                             
  0x0106A835  0400                    add      al, 0                          
  0x0106A837  0000                    add      byte ptr [eax], al             
  0x0106A839  0039                    add      byte ptr [ecx], bh             
  0x0106A83B  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x0106A841  0100                    add      dword ptr [eax], eax           
  0x0106A843  0003                    add      byte ptr [ebx], al             
  0x0106A845  0020                    add      byte ptr [eax], ah             
  0x0106A847  0000                    add      byte ptr [eax], al             
  0x0106A849  2405                    and      al, 5                          
  0x0106A84B  000c00                  add      byte ptr [eax + eax], cl       
  0x0106A84E  0000                    add      byte ptr [eax], al             
  0x0106A850  00f4                    add      ah, dh                         
  0x0106A852  56                      push     esi                            
  0x0106A853  0012                    add      byte ptr [edx], dl             
  0x0106A855  0000                    add      byte ptr [eax], al             
  0x0106A857  0000                    add      byte ptr [eax], al             
  0x0106A859  f4                      hlt                                     
  0x0106A85A  57                      push     edi                            
  0x0106A85B  0002                    add      byte ptr [edx], al             
  0x0106A85D  0000                    add      byte ptr [eax], al             
  0x0106A85F  0000                    add      byte ptr [eax], al             
  0x0106A861  f4                      hlt                                     
  0x0106A862  60                      pushal                                  
  0x0106A863  00fd                    add      ch, bh                         
  0x0106A865  0400                    add      al, 0                          
  0x0106A867  0000                    add      byte ptr [eax], al             
  0x0106A869  f4                      hlt                                     
  0x0106A86A  7000                    jo       0x106a86c                      
                                        ; XREF: 0x0106A86A (cond_jump)
  0x0106A86C  16                      push     ss                             
  0x0106A86D  0400                    add      al, 0                          
  0x0106A86F  0000                    add      byte ptr [eax], al             
  0x0106A871  0039                    add      byte ptr [ecx], bh             
  0x0106A873  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x0106A879  0100                    add      dword ptr [eax], eax           
  0x0106A87B  0003                    add      byte ptr [ebx], al             
  0x0106A87D  0020                    add      byte ptr [eax], ah             
  0x0106A87F  0000                    add      byte ptr [eax], al             
  0x0106A881  2405                    and      al, 5                          
  0x0106A883  0000                    add      byte ptr [eax], al             
  0x0106A885  f4                      hlt                                     
  0x0106A886  56                      push     esi                            
  0x0106A887  000e                    add      byte ptr [esi], cl             
  0x0106A889  0000                    add      byte ptr [eax], al             
  0x0106A88B  0000                    add      byte ptr [eax], al             
  0x0106A88D  f4                      hlt                                     
  0x0106A88E  60                      pushal                                  
  0x0106A88F  001409                  add      byte ptr [ecx + ecx], dl       
  0x0106A892  0000                    add      byte ptr [eax], al             
  0x0106A894  000c38                  add      byte ptr [eax + edi], cl       
  0x0106A897  0000                    add      byte ptr [eax], al             
  0x0106A899  0039                    add      byte ptr [ecx], bh             
  0x0106A89B  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x0106A8A1  0100                    add      dword ptr [eax], eax           
  0x0106A8A3  0003                    add      byte ptr [ebx], al             
  0x0106A8A5  0020                    add      byte ptr [eax], ah             
  0x0106A8A7  0000                    add      byte ptr [eax], al             
  0x0106A8A9  2405                    and      al, 5                          
  0x0106A8AB  000c00                  add      byte ptr [eax + eax], cl       
  0x0106A8AE  0000                    add      byte ptr [eax], al             
  0x0106A8B0  00f4                    add      ah, dh                         
  0x0106A8B2  56                      push     esi                            
  0x0106A8B3  0019                    add      byte ptr [ecx], bl             
  0x0106A8B5  0000                    add      byte ptr [eax], al             
  0x0106A8B7  0000                    add      byte ptr [eax], al             
  0x0106A8B9  f4                      hlt                                     
  0x0106A8BA  57                      push     edi                            
  0x0106A8BB  0001                    add      byte ptr [ecx], al             
  0x0106A8BD  0000                    add      byte ptr [eax], al             
  0x0106A8BF  0000                    add      byte ptr [eax], al             
  0x0106A8C1  0039                    add      byte ptr [ecx], bh             
  0x0106A8C3  0000                    add      byte ptr [eax], al             
  0x0106A8C5  f4                      hlt                                     
  0x0106A8C6  7000                    jo       0x106a8c8                      
                                        ; XREF: 0x0106A8C6 (cond_jump)
  0x0106A8C8  800000                  add      byte ptr [eax], 0              
  0x0106A8CB  0000                    add      byte ptr [eax], al             
  0x0106A8CD  f4                      hlt                                     
  0x0106A8CE  60                      pushal                                  
  0x0106A8CF  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106A8D2  0000                    add      byte ptr [eax], al             
  0x0106A8D4  80f00b                  xor      al, 0xb                        
  0x0106A8D7  008001000003            add      byte ptr [eax + 0x3000001], al 
  0x0106A8DD  0020                    add      byte ptr [eax], ah             
  0x0106A8DF  0000                    add      byte ptr [eax], al             
  0x0106A8E1  2405                    and      al, 5                          
  0x0106A8E3  000c00                  add      byte ptr [eax + eax], cl       
  0x0106A8E6  0000                    add      byte ptr [eax], al             
  0x0106A8E8  00f4                    add      ah, dh                         
  0x0106A8EA  56                      push     esi                            
  0x0106A8EB  001500000000            add      byte ptr [0], dl               
  0x0106A8F1  f4                      hlt                                     
  0x0106A8F2  57                      push     edi                            
  0x0106A8F3  0000                    add      byte ptr [eax], al             
  0x0106A8F5  0000                    add      byte ptr [eax], al             
  0x0106A8F7  0000                    add      byte ptr [eax], al             
  0x0106A8F9  f4                      hlt                                     
  0x0106A8FA  7000                    jo       0x106a8fc                      
                                        ; XREF: 0x0106A8FA (cond_jump)
  0x0106A8FC  90                      nop                                     
  0x0106A8FD  0300                    add      eax, dword ptr [eax]           
  0x0106A8FF  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x0106A905  0100                    add      dword ptr [eax], eax           
  0x0106A907  0003                    add      byte ptr [ebx], al             
  0x0106A909  0020                    add      byte ptr [eax], ah             
  0x0106A90B  0000                    add      byte ptr [eax], al             
  0x0106A90D  2405                    and      al, 5                          
  0x0106A90F  0000                    add      byte ptr [eax], al             
  0x0106A911  f4                      hlt                                     
  0x0106A912  56                      push     esi                            
  0x0106A913  0016                    add      byte ptr [esi], dl             
  0x0106A915  0000                    add      byte ptr [eax], al             
  0x0106A917  0000                    add      byte ptr [eax], al             
  0x0106A919  f4                      hlt                                     
  0x0106A91A  57                      push     edi                            
  0x0106A91B  0000                    add      byte ptr [eax], al             
  0x0106A91D  0000                    add      byte ptr [eax], al             
  0x0106A91F  0000                    add      byte ptr [eax], al             
  0x0106A921  f4                      hlt                                     
  0x0106A922  7000                    jo       0x106a924                      
                                        ; XREF: 0x0106A922 (cond_jump)
  0x0106A924  90                      nop                                     
  0x0106A925  0300                    add      eax, dword ptr [eax]           
  0x0106A927  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x0106A92D  0100                    add      dword ptr [eax], eax           
  0x0106A92F  0003                    add      byte ptr [ebx], al             
  0x0106A931  0020                    add      byte ptr [eax], ah             
  0x0106A933  0000                    add      byte ptr [eax], al             
  0x0106A935  2405                    and      al, 5                          
  0x0106A937  000c00                  add      byte ptr [eax + eax], cl       
  0x0106A93A  0000                    add      byte ptr [eax], al             
  0x0106A93C  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106A93F  006909                  add      byte ptr [ecx + 9], ch         
  0x0106A942  0000                    add      byte ptr [eax], al             
  0x0106A944  00f0                    add      al, dh                         
  0x0106A946  56                      push     esi                            
  0x0106A947  00970b000045            add      byte ptr [edi + 0x4500000b], dl 
  0x0106A94D  0020                    add      byte ptr [eax], ah             
  0x0106A94F  0007                    add      byte ptr [edi], al             
  0x0106A951  2405                    and      al, 5                          
  0x0106A953  0000                    add      byte ptr [eax], al             
  0x0106A955  f4                      hlt                                     
  0x0106A956  7100                    jno      0x106a958                      
                                        ; XREF: 0x0106A956 (cond_jump)
  0x0106A958  8903                    mov      dword ptr [ebx], eax           
  0x0106A95A  0000                    add      byte ptr [eax], al             
  0x0106A95C  0007                    add      byte ptr [edi], al             
  0x0106A95E  3800                    cmp      byte ptr [eax], al             
  0x0106A960  00f4                    add      ah, dh                         
  0x0106A962  60                      pushal                                  
  0x0106A963  003502000007            add      byte ptr [0x7000002], dh       
  0x0106A969  0c05                    or       al, 5                          
  0x0106A96B  0000                    add      byte ptr [eax], al             
  0x0106A96D  f4                      hlt                                     
  0x0106A96E  46                      inc      esi                            
  0x0106A96F  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x0106A975  d820                    fsub     dword ptr [eax]                
  0x0106A977  0022                    add      byte ptr [edx], ah             
  0x0106A979  f4                      hlt                                     
  0x0106A97A  60                      pushal                                  
  0x0106A97B  008001000000            add      byte ptr [eax + 1], al         
  0x0106A981  1921                    sbb      dword ptr [ecx], esp           
  0x0106A983  0000                    add      byte ptr [eax], al             
  0x0106A985  f4                      hlt                                     
  0x0106A986  56                      push     esi                            
  0x0106A987  001500000000            add      byte ptr [0], dl               
  0x0106A98D  f4                      hlt                                     
  0x0106A98E  57                      push     edi                            
  0x0106A98F  0002                    add      byte ptr [edx], al             
  0x0106A991  0000                    add      byte ptr [eax], al             
  0x0106A993  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x0106A999  0100                    add      dword ptr [eax], eax           
  0x0106A99B  0003                    add      byte ptr [ebx], al             
  0x0106A99D  0020                    add      byte ptr [eax], ah             
  0x0106A99F  0000                    add      byte ptr [eax], al             
  0x0106A9A1  2405                    and      al, 5                          
  0x0106A9A3  0000                    add      byte ptr [eax], al             
  0x0106A9A6  44                      inc      esp                            
  0x0106A9A7  006909                  add      byte ptr [ecx + 9], ch         
  0x0106A9AA  0000                    add      byte ptr [eax], al             
  0x0106A9AC  00f0                    add      al, dh                         
  0x0106A9AE  56                      push     esi                            
  0x0106A9AF  00970b000045            add      byte ptr [edi + 0x4500000b], dl 
  0x0106A9B5  0020                    add      byte ptr [eax], ah             
  0x0106A9B7  0007                    add      byte ptr [edi], al             
  0x0106A9B9  2405                    and      al, 5                          
  0x0106A9BB  0000                    add      byte ptr [eax], al             
  0x0106A9BD  f4                      hlt                                     
  0x0106A9BE  7100                    jno      0x106a9c0                      
                                        ; XREF: 0x0106A9BE (cond_jump)
  0x0106A9C0  8903                    mov      dword ptr [ebx], eax           
  0x0106A9C2  0000                    add      byte ptr [eax], al             
  0x0106A9C4  0007                    add      byte ptr [edi], al             
  0x0106A9C6  3800                    cmp      byte ptr [eax], al             
  0x0106A9C8  00f4                    add      ah, dh                         
  0x0106A9CA  60                      pushal                                  
  0x0106A9CB  00f6                    add      dh, dh                         
  0x0106A9CD  0200                    add      al, byte ptr [eax]             
  0x0106A9CF  0007                    add      byte ptr [edi], al             
  0x0106A9D1  0c05                    or       al, 5                          
  0x0106A9D3  0000                    add      byte ptr [eax], al             
  0x0106A9D5  f4                      hlt                                     
  0x0106A9D6  46                      inc      esi                            
  0x0106A9D7  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x0106A9DD  d820                    fsub     dword ptr [eax]                
  0x0106A9DF  0022                    add      byte ptr [edx], ah             
  0x0106A9E1  f4                      hlt                                     
  0x0106A9E2  60                      pushal                                  
  0x0106A9E3  004102                  add      byte ptr [ecx + 2], al         
  0x0106A9E6  0000                    add      byte ptr [eax], al             
  0x0106A9E8  0019                    add      byte ptr [ecx], bl             
  0x0106A9EA  2100                    and      dword ptr [eax], eax           
  0x0106A9EC  00f4                    add      ah, dh                         
  0x0106A9EE  56                      push     esi                            
  0x0106A9EF  0016                    add      byte ptr [esi], dl             
  0x0106A9F1  0000                    add      byte ptr [eax], al             
  0x0106A9F3  0000                    add      byte ptr [eax], al             
  0x0106A9F5  f4                      hlt                                     
  0x0106A9F6  57                      push     edi                            
  0x0106A9F7  0002                    add      byte ptr [edx], al             
  0x0106A9F9  0000                    add      byte ptr [eax], al             
  0x0106A9FB  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x0106AA01  0100                    add      dword ptr [eax], eax           
  0x0106AA03  0003                    add      byte ptr [ebx], al             
  0x0106AA05  0020                    add      byte ptr [eax], ah             
  0x0106AA07  0000                    add      byte ptr [eax], al             
  0x0106AA09  2405                    and      al, 5                          
  0x0106AA0B  000c00                  add      byte ptr [eax + eax], cl       
  0x0106AA0E  0000                    add      byte ptr [eax], al             
  0x0106AA10  40                      inc      eax                            
  0x0106AA11  1bd0                    sbb      edx, eax                       
  0x0106AA13  005206                  add      byte ptr [edx + 6], dl         
  0x0106AA16  0000                    add      byte ptr [eax], al             
  0x0106AA18  7201                    jb       0x106aa1b                      
  0x0106AA1A  0300                    add      eax, dword ptr [eax]           
  0x0106AA1C  50                      push     eax                            
  0x0106AA1D  0b8c000b002000          or       ecx, dword ptr [eax + eax + 0x20000b] 
  0x0106AA24  0210                    add      dl, byte ptr [eax]             
  0x0106AA26  0d004b0600              or       eax, 0x64b00                   
  0x0106AA2B  0080100d003b            add      byte ptr [eax + 0x3b000d10], al 
  0x0106AA31  06                      push     es                             
  0x0106AA32  0000                    add      byte ptr [eax], al             
  0x0106AA34  00f4                    add      ah, dh                         
  0x0106AA36  57                      push     edi                            
  0x0106AA37  0010                    add      byte ptr [eax], dl             
  0x0106AA39  0000                    add      byte ptr [eax], al             
  0x0106AA3B  0000                    add      byte ptr [eax], al             
  0x0106AA3D  0030                    add      byte ptr [eax], dh             
  0x0106AA3F  0080100d0033            add      byte ptr [eax + 0x33000d10], al 
  0x0106AA45  0200                    add      al, byte ptr [eax]             
  0x0106AA47  0000                    add      byte ptr [eax], al             
  0x0106AA49  f4                      hlt                                     
  0x0106AA4A  44                      inc      esp                            
  0x0106AA4B  0000                    add      byte ptr [eax], al             
  0x0106AA4D  0000                    add      byte ptr [eax], al             
  0x0106AA4F  004500                  add      byte ptr [ebp], al             
  0x0106AA52  2000                    and      byte ptr [eax], al             
  0x0106AA54  00740500                add      byte ptr [ebp + eax], dh       
  0x0106AA58  80100d                  adc      byte ptr [eax], 0xd            
  0x0106AA5B  003f                    add      byte ptr [edi], bh             
  0x0106AA5D  06                      push     es                             
  0x0106AA5E  0000                    add      byte ptr [eax], al             
  0x0106AA60  0c00                    or       al, 0                          
  0x0106AA62  0000                    add      byte ptr [eax], al             
  0x0106AA64  61                      popal                                   
  0x0106AA65  f4                      hlt                                     
  0x0106AA66  46                      inc      esi                            
  0x0106AA67  0010                    add      byte ptr [eax], dl             
  0x0106AA69  0000                    add      byte ptr [eax], al             
  0x0106AA6B  0000                    add      byte ptr [eax], al             
  0x0106AA6D  07                      pop      es                             
  0x0106AA6E  2300                    and      eax, dword ptr [eax]           
  0x0106AA70  10d9                    adc      cl, bl                         
  0x0106AA72  06                      push     es                             
  0x0106AA73  000a                    add      byte ptr [edx], cl             
  0x0106AA75  0000                    add      byte ptr [eax], al             
  0x0106AA77  007cd950                add      byte ptr [ecx + ebx*8 + 0x50], bh 
  0x0106AA7B  0007                    add      byte ptr [edi], al             
  0x0106AA7D  7405                    je       0x106aa84                      
  0x0106AA7F  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x0106AA82  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x0106AA7D (cond_jump)
  0x0106AA84  46                      inc      esi                            
  0x0106AA85  1e                      push     ds                             
  0x0106AA86  0c00                    or       al, 0                          
  0x0106AA88  90                      nop                                     
  0x0106AA89  1e                      push     ds                             
  0x0106AA8A  0c00                    or       al, 0                          
  0x0106AA8C  49                      dec      ecx                            
  0x0106AA8D  e421                    in       al, 0x21                       
  0x0106AA8F  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106AA92  54                      push     esp                            
  0x0106AA93  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106AA96  0c00                    or       al, 0                          
  0x0106AA98  4e                      dec      esi                            
  0x0106AA99  1e                      push     ds                             
  0x0106AA9A  0c00                    or       al, 0                          
  0x0106AA9C  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x0106AAA2  0000                    add      byte ptr [eax], al             
  0x0106AAA4  61                      popal                                   
  0x0106AAA5  f4                      hlt                                     
                                        ; XREF: 0x0106AAF8 (cond_jump)
  0x0106AAA6  46                      inc      esi                            
  0x0106AAA7  0010                    add      byte ptr [eax], dl             
  0x0106AAA9  0000                    add      byte ptr [eax], al             
  0x0106AAAB  0000                    add      byte ptr [eax], al             
  0x0106AAAD  07                      pop      es                             
  0x0106AAAE  2300                    and      eax, dword ptr [eax]           
  0x0106AAB0  7cd9                    jl       0x106aa8b                      
  0x0106AAB2  50                      push     eax                            
  0x0106AAB3  0007                    add      byte ptr [edi], al             
  0x0106AAB5  7405                    je       0x106aabc                      
  0x0106AAB7  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x0106AABA  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x0106AAB5 (cond_jump)
  0x0106AABC  46                      inc      esi                            
  0x0106AABD  1e                      push     ds                             
  0x0106AABE  0c00                    or       al, 0                          
  0x0106AAC0  90                      nop                                     
  0x0106AAC1  1e                      push     ds                             
  0x0106AAC2  0c00                    or       al, 0                          
  0x0106AAC4  49                      dec      ecx                            
  0x0106AAC5  e421                    in       al, 0x21                       
  0x0106AAC7  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106AACA  54                      push     esp                            
  0x0106AACB  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106AACE  0c00                    or       al, 0                          
  0x0106AAD0  4e                      dec      esi                            
  0x0106AAD1  1e                      push     ds                             
  0x0106AAD2  0c00                    or       al, 0                          
  0x0106AAD4  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x0106AADA  0000                    add      byte ptr [eax], al             
  0x0106AADC  00f4                    add      ah, dh                         
  0x0106AADE  46                      inc      esi                            
  0x0106AADF  0010                    add      byte ptr [eax], dl             
  0x0106AAE1  0000                    add      byte ptr [eax], al             
  0x0106AAE3  0000                    add      byte ptr [eax], al             
  0x0106AAE5  07                      pop      es                             
  0x0106AAE6  2300                    and      eax, dword ptr [eax]           
  0x0106AAE8  10d9                    adc      cl, bl                         
  0x0106AAEA  06                      push     es                             
  0x0106AAEB  000d00000000            add      byte ptr [0], cl               
  0x0106AAF1  d95600                  fst      dword ptr [esi]                
  0x0106AAF4  6e                      outsb    dx, byte ptr [esi]             
  0x0106AAF5  1e                      push     ds                             
  0x0106AAF6  0c00                    or       al, 0                          
  0x0106AAF8  7cac                    jl       0x106aaa6                      
  0x0106AAFA  2000                    and      byte ptr [eax], al             
  0x0106AAFC  07                      pop      es                             
  0x0106AAFD  7405                    je       0x106ab04                      
  0x0106AAFF  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x0106AB02  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x0106AAFD (cond_jump)
  0x0106AB04  46                      inc      esi                            
  0x0106AB05  1e                      push     ds                             
  0x0106AB06  0c00                    or       al, 0                          
  0x0106AB08  90                      nop                                     
  0x0106AB09  1e                      push     ds                             
  0x0106AB0A  0c00                    or       al, 0                          
  0x0106AB0C  49                      dec      ecx                            
  0x0106AB0D  e421                    in       al, 0x21                       
  0x0106AB0F  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106AB12  54                      push     esp                            
  0x0106AB13  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106AB16  0c00                    or       al, 0                          
  0x0106AB18  4e                      dec      esi                            
  0x0106AB19  1e                      push     ds                             
  0x0106AB1A  0c00                    or       al, 0                          
  0x0106AB1C  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x0106AB22  0000                    add      byte ptr [eax], al             
  0x0106AB24  00f4                    add      ah, dh                         
  0x0106AB26  46                      inc      esi                            
  0x0106AB27  0010                    add      byte ptr [eax], dl             
  0x0106AB29  0000                    add      byte ptr [eax], al             
  0x0106AB2B  0000                    add      byte ptr [eax], al             
  0x0106AB2D  07                      pop      es                             
                                        ; XREF: 0x0106AB80 (cond_jump)
  0x0106AB2E  2300                    and      eax, dword ptr [eax]           
  0x0106AB30  10d9                    adc      cl, bl                         
  0x0106AB32  06                      push     es                             
  0x0106AB33  000d00000000            add      byte ptr [0], cl               
  0x0106AB39  d95e00                  fstp     dword ptr [esi]                
  0x0106AB3C  6e                      outsb    dx, byte ptr [esi]             
  0x0106AB3D  1e                      push     ds                             
  0x0106AB3E  0c00                    or       al, 0                          
  0x0106AB40  7cac                    jl       0x106aaee                      
  0x0106AB42  2000                    and      byte ptr [eax], al             
  0x0106AB44  07                      pop      es                             
  0x0106AB45  7405                    je       0x106ab4c                      
  0x0106AB47  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x0106AB4A  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x0106AB45 (cond_jump)
  0x0106AB4C  46                      inc      esi                            
  0x0106AB4D  1e                      push     ds                             
  0x0106AB4E  0c00                    or       al, 0                          
  0x0106AB50  90                      nop                                     
  0x0106AB51  1e                      push     ds                             
  0x0106AB52  0c00                    or       al, 0                          
  0x0106AB54  49                      dec      ecx                            
  0x0106AB55  e421                    in       al, 0x21                       
  0x0106AB57  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106AB5A  54                      push     esp                            
  0x0106AB5B  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106AB5E  0c00                    or       al, 0                          
  0x0106AB60  4e                      dec      esi                            
  0x0106AB61  1e                      push     ds                             
  0x0106AB62  0c00                    or       al, 0                          
  0x0106AB64  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x0106AB6A  0000                    add      byte ptr [eax], al             
  0x0106AB6C  00f4                    add      ah, dh                         
                                        ; XREF: 0x0106ABC0 (cond_jump)
  0x0106AB6E  46                      inc      esi                            
  0x0106AB6F  0010                    add      byte ptr [eax], dl             
  0x0106AB71  0000                    add      byte ptr [eax], al             
  0x0106AB73  0000                    add      byte ptr [eax], al             
  0x0106AB75  07                      pop      es                             
  0x0106AB76  2300                    and      eax, dword ptr [eax]           
  0x0106AB78  00d9                    add      cl, bl                         
  0x0106AB7A  56                      push     esi                            
  0x0106AB7B  006e1e                  add      byte ptr [esi + 0x1e], ch      
  0x0106AB7E  0c00                    or       al, 0                          
  0x0106AB80  7cac                    jl       0x106ab2e                      
  0x0106AB82  2000                    and      byte ptr [eax], al             
  0x0106AB84  07                      pop      es                             
  0x0106AB85  7405                    je       0x106ab8c                      
  0x0106AB87  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x0106AB8A  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x0106AB85 (cond_jump)
  0x0106AB8C  46                      inc      esi                            
  0x0106AB8D  1e                      push     ds                             
  0x0106AB8E  0c00                    or       al, 0                          
  0x0106AB90  90                      nop                                     
  0x0106AB91  1e                      push     ds                             
  0x0106AB92  0c00                    or       al, 0                          
  0x0106AB94  49                      dec      ecx                            
  0x0106AB95  e421                    in       al, 0x21                       
  0x0106AB97  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106AB9A  54                      push     esp                            
  0x0106AB9B  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106AB9E  0c00                    or       al, 0                          
  0x0106ABA0  4e                      dec      esi                            
  0x0106ABA1  1e                      push     ds                             
  0x0106ABA2  0c00                    or       al, 0                          
  0x0106ABA4  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x0106ABAA  0000                    add      byte ptr [eax], al             
  0x0106ABAC  00f4                    add      ah, dh                         
  0x0106ABAE  46                      inc      esi                            
  0x0106ABAF  0010                    add      byte ptr [eax], dl             
  0x0106ABB1  0000                    add      byte ptr [eax], al             
  0x0106ABB3  0000                    add      byte ptr [eax], al             
  0x0106ABB5  07                      pop      es                             
  0x0106ABB6  2300                    and      eax, dword ptr [eax]           
  0x0106ABB8  00d9                    add      cl, bl                         
  0x0106ABBA  5e                      pop      esi                            
  0x0106ABBB  006e1e                  add      byte ptr [esi + 0x1e], ch      
  0x0106ABBE  0c00                    or       al, 0                          
  0x0106ABC0  7cac                    jl       0x106ab6e                      
  0x0106ABC2  2000                    and      byte ptr [eax], al             
  0x0106ABC4  07                      pop      es                             
  0x0106ABC5  7405                    je       0x106abcc                      
  0x0106ABC7  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x0106ABCA  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x0106ABC5 (cond_jump)
  0x0106ABCC  46                      inc      esi                            
  0x0106ABCD  1e                      push     ds                             
  0x0106ABCE  0c00                    or       al, 0                          
  0x0106ABD0  90                      nop                                     
  0x0106ABD1  1e                      push     ds                             
  0x0106ABD2  0c00                    or       al, 0                          
  0x0106ABD4  49                      dec      ecx                            
  0x0106ABD5  e421                    in       al, 0x21                       
  0x0106ABD7  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106ABDA  54                      push     esp                            
  0x0106ABDB  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106ABDE  0c00                    or       al, 0                          
  0x0106ABE0  4e                      dec      esi                            
  0x0106ABE1  1e                      push     ds                             
  0x0106ABE2  0c00                    or       al, 0                          
  0x0106ABE4  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x0106ABEA  0000                    add      byte ptr [eax], al             
  0x0106ABEC  00f4                    add      ah, dh                         
  0x0106ABEE  61                      popal                                   
  0x0106ABEF  0012                    add      byte ptr [edx], dl             
  0x0106ABF1  0d000000f4              or       eax, 0xf4000000                
  0x0106ABF6  46                      inc      esi                            
  0x0106ABF7  00ff                    add      bh, bh                         
  0x0106ABF9  0000                    add      byte ptr [eax], al             
  0x0106ABFB  0010                    add      byte ptr [eax], dl             
  0x0106ABFD  d806                    fadd     dword ptr [esi]                
  0x0106ABFF  000e                    add      byte ptr [esi], cl             
  0x0106AC01  0000                    add      byte ptr [eax], al             
  0x0106AC03  00901c0c0056            add      byte ptr [eax + 0x56000c1c], dl 
  0x0106AC09  0020                    add      byte ptr [eax], ah             
  0x0106AC0B  0000                    add      byte ptr [eax], al             
  0x0106AC0D  d85100                  fcom     dword ptr [ecx]                
  0x0106AC10  00992100911d            add      byte ptr [ecx + 0x1d910021], bl 
  0x0106AC16  0c00                    or       al, 0                          
  0x0106AC18  00e9                    add      cl, ch                         
  0x0106AC1A  4c                      dec      esp                            
  0x0106AC1B  004b00                  add      byte ptr [ebx], cl             
  0x0106AC1E  2000                    and      byte ptr [eax], al             
  0x0106AC20  90                      nop                                     
  0x0106AC21  1c0c                    sbb      al, 0xc                        
  0x0106AC23  005600                  add      byte ptr [esi], dl             
  0x0106AC26  2000                    and      byte ptr [eax], al             
  0x0106AC28  00992100911d            add      byte ptr [ecx + 0x1d910021], bl 
  0x0106AC2E  0c00                    or       al, 0                          
  0x0106AC30  00e9                    add      cl, ch                         
  0x0106AC32  4c                      dec      esp                            
  0x0106AC33  004b00                  add      byte ptr [ebx], cl             
  0x0106AC36  2000                    and      byte ptr [eax], al             
  0x0106AC38  91                      xchg     ecx, eax                       
  0x0106AC39  1e                      push     ds                             
  0x0106AC3A  0c00                    or       al, 0                          
  0x0106AC3C  00ae2100111c            add      byte ptr [esi + 0x1c110021], ch 
  0x0106AC42  0c00                    or       al, 0                          
  0x0106AC44  0c00                    or       al, 0                          
  0x0106AC46  0000                    add      byte ptr [eax], al             
  0x0106AC48  1bf4                    sbb      esi, esp                       
  0x0106AC4A  61                      popal                                   
  0x0106AC4B  0012                    add      byte ptr [edx], dl             
  0x0106AC4D  0e                      push     cs                             
  0x0106AC4E  0000                    add      byte ptr [eax], al             
  0x0106AC50  00f4                    add      ah, dh                         
  0x0106AC52  46                      inc      esi                            
  0x0106AC53  00ff                    add      bh, bh                         
  0x0106AC55  0000                    add      byte ptr [eax], al             
  0x0106AC57  0000                    add      byte ptr [eax], al             
  0x0106AC59  48                      dec      eax                            
  0x0106AC5A  2000                    and      byte ptr [eax], al             
  0x0106AC5C  10d8                    adc      al, bl                         
  0x0106AC5E  06                      push     es                             
  0x0106AC5F  000d0000005e            add      byte ptr [0x5e000000], cl      
  0x0106AC65  ae                      scasb    al, byte ptr es:[edi]          
  0x0106AC66  2100                    and      dword ptr [eax], eax           
  0x0106AC68  00f8                    add      al, bh                         
  0x0106AC6A  44                      inc      esp                            
  0x0106AC6B  0000                    add      byte ptr [eax], al             
  0x0106AC6D  b92100d01e              mov      ecx, 0x1ed00021                
  0x0106AC72  0c00                    or       al, 0                          
  0x0106AC74  42                      inc      edx                            
  0x0106AC75  0020                    add      byte ptr [eax], ah             
  0x0106AC77  0000                    add      byte ptr [eax], al             
  0x0106AC79  e94c004300              jmp      0x149acca                      
  0x0106AC7E  2000                    and      byte ptr [eax], al             
  0x0106AC80  56                      push     esi                            
  0x0106AC82  2100                    and      dword ptr [eax], eax           
  0x0106AC84  00992100d11e            add      byte ptr [ecx + 0x1ed10021], bl 
  0x0106AC8A  0c00                    or       al, 0                          
  0x0106AC8C  00e9                    add      cl, ch                         
  0x0106AC8E  4c                      dec      esp                            
  0x0106AC8F  004b00                  add      byte ptr [ebx], cl             
  0x0106AC92  2000                    and      byte ptr [eax], al             
  0x0106AC94  91                      xchg     ecx, eax                       
  0x0106AC95  1e                      push     ds                             
  0x0106AC96  0c00                    or       al, 0                          
  0x0106AC98  00ae2100111c            add      byte ptr [esi + 0x1c110021], ch 
  0x0106AC9E  0c00                    or       al, 0                          
  0x0106ACA0  0c00                    or       al, 0                          
  0x0106ACA2  0000                    add      byte ptr [eax], al             
  0x0106ACA4  180400                  sbb      byte ptr [eax + eax], al       
  0x0106ACA7  0018                    add      byte ptr [eax], bl             
  0x0106ACA9  0400                    add      al, 0                          
  0x0106ACAB  0018                    add      byte ptr [eax], bl             
  0x0106ACAD  0400                    add      al, 0                          
  0x0106ACAF  002a                    add      byte ptr [edx], ch             
  0x0106ACB1  0400                    add      al, 0                          
  0x0106ACB3  002a                    add      byte ptr [edx], ch             
  0x0106ACB5  0400                    add      al, 0                          
  0x0106ACB7  002a                    add      byte ptr [edx], ch             
  0x0106ACB9  0400                    add      al, 0                          
  0x0106ACBB  002504000042            add      byte ptr [0x42000004], ah      
  0x0106ACC1  0400                    add      al, 0                          
  0x0106ACC3  004204                  add      byte ptr [edx + 4], al         
  0x0106ACC6  0000                    add      byte ptr [eax], al             
  0x0106ACC8  42                      inc      edx                            
  0x0106ACC9  0400                    add      al, 0                          
  0x0106ACCB  004204                  add      byte ptr [edx + 4], al         
  0x0106ACCE  0000                    add      byte ptr [eax], al             
  0x0106ACD0  42                      inc      edx                            
  0x0106ACD1  0400                    add      al, 0                          
  0x0106ACD3  004204                  add      byte ptr [edx + 4], al         
  0x0106ACD6  0000                    add      byte ptr [eax], al             
  0x0106ACD8  42                      inc      edx                            
  0x0106ACD9  0400                    add      al, 0                          
  0x0106ACDB  004204                  add      byte ptr [edx + 4], al         
  0x0106ACDE  0000                    add      byte ptr [eax], al             
  0x0106ACE0  42                      inc      edx                            
  0x0106ACE1  0400                    add      al, 0                          
  0x0106ACE3  004204                  add      byte ptr [edx + 4], al         
  0x0106ACE6  0000                    add      byte ptr [eax], al             
  0x0106ACE8  42                      inc      edx                            
  0x0106ACE9  0400                    add      al, 0                          
  0x0106ACEB  004204                  add      byte ptr [edx + 4], al         
  0x0106ACEE  0000                    add      byte ptr [eax], al             
  0x0106ACF0  42                      inc      edx                            
  0x0106ACF1  0400                    add      al, 0                          
  0x0106ACF3  004e04                  add      byte ptr [esi + 4], cl         
  0x0106ACF6  0000                    add      byte ptr [eax], al             
  0x0106ACF8  4e                      dec      esi                            
  0x0106ACF9  0400                    add      al, 0                          
  0x0106ACFB  004e04                  add      byte ptr [esi + 4], cl         
  0x0106ACFE  0000                    add      byte ptr [eax], al             
  0x0106AD00  5f                      pop      edi                            
  0x0106AD01  0400                    add      al, 0                          
  0x0106AD03  005f04                  add      byte ptr [edi + 4], bl         
  0x0106AD06  0000                    add      byte ptr [eax], al             
  0x0106AD08  5f                      pop      edi                            
  0x0106AD09  0400                    add      al, 0                          
  0x0106AD0B  005f04                  add      byte ptr [edi + 4], bl         
  0x0106AD0E  0000                    add      byte ptr [eax], al             
  0x0106AD10  5f                      pop      edi                            
  0x0106AD11  0400                    add      al, 0                          
  0x0106AD13  005f04                  add      byte ptr [edi + 4], bl         
  0x0106AD16  0000                    add      byte ptr [eax], al             
  0x0106AD18  5f                      pop      edi                            
  0x0106AD19  0400                    add      al, 0                          
  0x0106AD1B  005f04                  add      byte ptr [edi + 4], bl         
  0x0106AD1E  0000                    add      byte ptr [eax], al             
  0x0106AD20  5f                      pop      edi                            
  0x0106AD21  0400                    add      al, 0                          
  0x0106AD23  005f04                  add      byte ptr [edi + 4], bl         
  0x0106AD26  0000                    add      byte ptr [eax], al             
  0x0106AD28  5f                      pop      edi                            
  0x0106AD29  0400                    add      al, 0                          
  0x0106AD2B  005f04                  add      byte ptr [edi + 4], bl         
  0x0106AD2E  0000                    add      byte ptr [eax], al             
  0x0106AD30  5f                      pop      edi                            
  0x0106AD31  0400                    add      al, 0                          
  0x0106AD33  005f04                  add      byte ptr [edi + 4], bl         
  0x0106AD36  0000                    add      byte ptr [eax], al             
  0x0106AD38  5f                      pop      edi                            
  0x0106AD39  0400                    add      al, 0                          
  0x0106AD3B  005f04                  add      byte ptr [edi + 4], bl         
  0x0106AD3E  0000                    add      byte ptr [eax], al             
  0x0106AD40  5f                      pop      edi                            
  0x0106AD41  0400                    add      al, 0                          
  0x0106AD43  005f04                  add      byte ptr [edi + 4], bl         
  0x0106AD46  0000                    add      byte ptr [eax], al             
  0x0106AD48  5f                      pop      edi                            
  0x0106AD49  0400                    add      al, 0                          
  0x0106AD4B  005f04                  add      byte ptr [edi + 4], bl         
  0x0106AD4E  0000                    add      byte ptr [eax], al             
  0x0106AD50  5f                      pop      edi                            
  0x0106AD51  0400                    add      al, 0                          
  0x0106AD53  005f04                  add      byte ptr [edi + 4], bl         
  0x0106AD56  0000                    add      byte ptr [eax], al             
  0x0106AD58  5f                      pop      edi                            
  0x0106AD59  0400                    add      al, 0                          
  0x0106AD5B  005f04                  add      byte ptr [edi + 4], bl         
  0x0106AD5E  0000                    add      byte ptr [eax], al             
  0x0106AD60  5f                      pop      edi                            
  0x0106AD61  0400                    add      al, 0                          
  0x0106AD63  005f04                  add      byte ptr [edi + 4], bl         
  0x0106AD66  0000                    add      byte ptr [eax], al             
  0x0106AD68  5f                      pop      edi                            
  0x0106AD69  0400                    add      al, 0                          
  0x0106AD6B  0000                    add      byte ptr [eax], al             
  0x0106AD6D  b122                    mov      cl, 0x22                       
  0x0106AD6F  0000                    add      byte ptr [eax], al             
  0x0106AD71  1923                    sbb      dword ptr [ebx], esp           
  0x0106AD73  0000                    add      byte ptr [eax], al             
  0x0106AD75  48                      dec      eax                            
  0x0106AD76  2000                    and      byte ptr [eax], al             
  0x0106AD78  004920                  add      byte ptr [ecx + 0x20], cl      
  0x0106AD7B  001b                    add      byte ptr [ebx], bl             
  0x0106AD7D  f4                      hlt                                     
  0x0106AD7E  45                      inc      ebp                            
  0x0106AD7F  004000                  add      byte ptr [eax], al             
  0x0106AD82  0000                    add      byte ptr [eax], al             
  0x0106AD84  00f4                    add      ah, dh                         
  0x0106AD86  51                      push     ecx                            
  0x0106AD87  0000                    add      byte ptr [eax], al             
  0x0106AD89  0c00                    or       al, 0                          
  0x0106AD8B  0001                    add      byte ptr [ecx], al             
  0x0106AD8D  d8440010                fadd     dword ptr [eax + eax + 0x10]   
  0x0106AD91  dc06                    fadd     qword ptr [esi]                
  0x0106AD93  0003                    add      byte ptr [ebx], al             
  0x0106AD95  0000                    add      byte ptr [eax], al             
  0x0106AD97  00a6d8440001            add      byte ptr [esi + 0x10044d8], ah 
  0x0106AD9D  59                      pop      ecx                            
  0x0106AD9E  50                      push     eax                            
  0x0106AD9F  0000                    add      byte ptr [eax], al             
  0x0106ADA1  002400                  add      byte ptr [eax + eax], ah       
  0x0106ADA4  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106ADA7  009204000000            add      byte ptr [edx + 4], dl         
  0x0106ADAD  002400                  add      byte ptr [eax + eax], ah       
  0x0106ADB0  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106ADB3  009104000000            add      byte ptr [ecx + 4], dl         
  0x0106ADB9  1023                    adc      byte ptr [ebx], ah             
  0x0106ADBB  0000                    add      byte ptr [eax], al             
  0x0106ADBD  b8220000f4              mov      eax, 0xf4000022                
  0x0106ADC2  7400                    je       0x106adc4                      
                                        ; XREF: 0x0106ADC2 (cond_jump)
  0x0106ADC4  a5                      movsd    dword ptr es:[edi], dword ptr [esi] 
  0x0106ADC5  0300                    add      eax, dword ptr [eax]           
  0x0106ADC7  0000                    add      byte ptr [eax], al             
  0x0106ADC9  f4                      hlt                                     
  0x0106ADCA  650032                  add      byte ptr gs:[edx], dh          
  0x0106ADCD  0b00                    or       eax, dword ptr [eax]           
  0x0106ADCF  0000                    add      byte ptr [eax], al             
  0x0106ADD2  44                      inc      esp                            
  0x0106ADD3  007b0b                  add      byte ptr [ebx + 0xb], bh       
  0x0106ADD6  0000                    add      byte ptr [eax], al             
  0x0106ADD8  00f4                    add      ah, dh                         
  0x0106ADDA  46                      inc      esi                            
  0x0106ADDB  0032                    add      byte ptr [edx], dh             
  0x0106ADDD  0000                    add      byte ptr [eax], al             
  0x0106ADDF  00d0                    add      al, dl                         
  0x0106ADE1  44                      inc      esp                            
  0x0106ADE2  2200                    and      al, byte ptr [eax]             
  0x0106ADE4  2e1d0c0040f4            sbb      eax, 0xf440000c                
  0x0106ADEA  44                      inc      esp                            
  0x0106ADEB  001c0c                  add      byte ptr [esp + ecx], bl       
  0x0106ADEE  0000                    add      byte ptr [eax], al             
  0x0106ADF0  40                      inc      eax                            
  0x0106ADF1  0020                    add      byte ptr [eax], ah             
  0x0106ADF3  0000                    add      byte ptr [eax], al             
  0x0106ADF5  96                      xchg     esi, eax                       
  0x0106ADF6  2100                    and      dword ptr [eax], eax           
  0x0106ADF8  0001                    add      byte ptr [ecx], al             
  0x0106ADFA  3900                    cmp      dword ptr [eax], eax           
  0x0106ADFC  ce                      into                                    
  0x0106ADFD  720b                    jb       0x106ae0a                      
  0x0106ADFF  001a                    add      byte ptr [edx], bl             
  0x0106AE01  0f0000                  sldt     word ptr [eax]                 
  0x0106AE04  00c4                    add      ah, al                         
  0x0106AE06  2300                    and      eax, dword ptr [eax]           
  0x0106AE08  45                      inc      ebp                            
  0x0106AE09  07                      pop      es                             
                                        ; XREF: 0x0106ADFD (cond_jump)
  0x0106AE0A  2200                    and      al, byte ptr [eax]             
  0x0106AE0C  40                      inc      eax                            
  0x0106AE0D  7002                    jo       0x106ae11                      
  0x0106AE0F  00742423                add      byte ptr [esp + 0x23], dh      
  0x0106AE13  0044e857                add      byte ptr [eax + ebp*8 + 0x57], al 
  0x0106AE17  0000                    add      byte ptr [eax], al             
  0x0106AE19  58                      pop      eax                            
  0x0106AE1A  2000                    and      byte ptr [eax], al             
  0x0106AE1C  00e8                    add      al, ch                         
  0x0106AE1E  45                      inc      ebp                            
  0x0106AE1F  000da4050000            add      byte ptr [0x5a4], cl           
  0x0106AE25  f4                      hlt                                     
  0x0106AE26  47                      inc      edi                            
  0x0106AE27  00d1                    add      cl, dl                         
  0x0106AE29  0000                    add      byte ptr [eax], al             
  0x0106AE2B  0010                    add      byte ptr [eax], dl             
  0x0106AE2D  cc                      int3                                    
  0x0106AE2E  06                      push     es                             
  0x0106AE2F  0009                    add      byte ptr [ecx], cl             
  0x0106AE31  0000                    add      byte ptr [eax], al             
  0x0106AE33  006cee21                add      byte ptr [esi + ebp*8 + 0x21], ch 
  0x0106AE37  006090                  add      byte ptr [eax - 0x70], ah      
  0x0106AE3A  0200                    add      al, byte ptr [eax]             
  0x0106AE3C  2e58                    pop      eax                            
  0x0106AE3E  2000                    and      byte ptr [eax], al             
  0x0106AE40  2be8                    sub      ebp, eax                       
  0x0106AE42  45                      inc      ebp                            
  0x0106AE43  007dbd                  add      byte ptr [ebp - 0x43], bh      
  0x0106AE46  2100                    and      dword ptr [eax], eax           
  0x0106AE48  00ed                    add      ch, ch                         
  0x0106AE4A  4c                      dec      esp                            
  0x0106AE4B  00402f                  add      byte ptr [eax + 0x2f], al      
  0x0106AE4E  2000                    and      byte ptr [eax], al             
  0x0106AE50  00cf                    add      bh, cl                         
  0x0106AE52  2100                    and      dword ptr [eax], eax           
  0x0106AE54  00542200                add      byte ptr [edx], dl             
  0x0106AE58  61                      popal                                   
  0x0106AE59  f4                      hlt                                     
  0x0106AE5A  44                      inc      esp                            
  0x0106AE5B  0000                    add      byte ptr [eax], al             
  0x0106AE5D  0100                    add      dword ptr [eax], eax           
  0x0106AE5F  0094ec070044f0          add      byte ptr [esp + ebp*8 - 0xfbbfff9], dl 
  0x0106AE66  47                      inc      edi                            
  0x0106AE67  009104000080            add      byte ptr [ecx - 0x7ffffffc], dl 
  0x0106AE6D  e40a                    in       al, 0xa                        
  0x0106AE6F  000d70570093            add      byte ptr [0x93005770], cl      
  0x0106AE75  0400                    add      al, 0                          
  0x0106AE77  0008                    add      byte ptr [eax], cl             
  0x0106AE79  f4                      hlt                                     
  0x0106AE7A  05006dee20              add      eax, 0x20ee6d00                
  0x0106AE7F  0058f4                  add      byte ptr [eax - 0xc], bl       
  0x0106AE82  0500c44001              add      eax, 0x140c400                 
  0x0106AE87  004000                  add      byte ptr [eax], al             
  0x0106AE8A  0000                    add      byte ptr [eax], al             
  0x0106AE8C  1329                    adc      ebp, dword ptr [ecx]           
  0x0106AE8E  2000                    and      byte ptr [eax], al             
  0x0106AE90  00872100530c            add      byte ptr [edi + 0xc530021], al 
  0x0106AE96  050000f447              add      eax, 0x47f40000                
  0x0106AE9B  008001000050            add      byte ptr [eax + 0x50000001], al 
  0x0106AEA1  0c05                    or       al, 5                          
  0x0106AEA3  0000                    add      byte ptr [eax], al             
  0x0106AEA5  8621                    xchg     byte ptr [ecx], ah             
  0x0106AEA7  0000                    add      byte ptr [eax], al             
  0x0106AEA9  ce                      into                                    
  0x0106AEAA  2300                    and      eax, dword ptr [eax]           
  0x0106AEAC  854701                  test     dword ptr [edi + 1], eax       
  0x0106AEAF  000da4050000            add      byte ptr [0x5a4], cl           
  0x0106AEB5  ce                      into                                    
  0x0106AEB6  2000                    and      byte ptr [eax], al             
  0x0106AEB8  0d00200008              or       eax, 0x8002000                 
  0x0106AEBD  f4                      hlt                                     
  0x0106AEBE  05006dee20              add      eax, 0x20ee6d00                
  0x0106AEC3  0008                    add      byte ptr [eax], cl             
  0x0106AEC5  f4                      hlt                                     
  0x0106AEC6  0500c44001              add      eax, 0x140c400                 
  0x0106AECB  004000                  add      byte ptr [eax], al             
  0x0106AECE  0000                    add      byte ptr [eax], al             
  0x0106AED0  1329                    adc      ebp, dword ptr [ecx]           
  0x0106AED2  2000                    and      byte ptr [eax], al             
  0x0106AED4  00872100030c            add      byte ptr [edi + 0xc030021], al 
  0x0106AEDA  050000f447              add      eax, 0x47f40000                
  0x0106AEDF  008001000000            add      byte ptr [eax + 1], al         
  0x0106AEE6  44                      inc      esp                            
  0x0106AEE7  00930400004d            add      byte ptr [ebx + 0x4d000004], dl 
  0x0106AEEE  56                      push     esi                            
  0x0106AEEF  009204000000            add      byte ptr [edx + 4], dl         
  0x0106AEF5  7055                    jo       0x106af4c                      
  0x0106AEF7  009304000004            add      byte ptr [ebx + 0x4000004], dl 
  0x0106AEFD  94                      xchg     esp, eax                       
  0x0106AEFE  0500002e23              add      eax, 0x232e0000                
  0x0106AF03  0000                    add      byte ptr [eax], al             
  0x0106AF05  7071                    jo       0x106af78                      
  0x0106AF07  009204000003            add      byte ptr [edx + 0x3000004], dl 
  0x0106AF0D  0020                    add      byte ptr [eax], ah             
  0x0106AF0F  0014a4                  add      byte ptr [esp], dl             
  0x0106AF12  05001e0c05              add      eax, 0x50c1e00                 
  0x0106AF17  000d00200008            add      byte ptr [0x8002000], cl       
  0x0106AF1D  f4                      hlt                                     
  0x0106AF1E  05006dee20              add      eax, 0x20ee6d00                
  0x0106AF23  001a                    add      byte ptr [edx], bl             
  0x0106AF25  f4                      hlt                                     
  0x0106AF26  0500c44001              add      eax, 0x140c400                 
  0x0106AF2B  004000                  add      byte ptr [eax], al             
  0x0106AF2E  0000                    add      byte ptr [eax], al             
  0x0106AF30  1329                    adc      ebp, dword ptr [ecx]           
  0x0106AF32  2000                    and      byte ptr [eax], al             
  0x0106AF34  00872100150c            add      byte ptr [edi + 0xc150021], al 
  0x0106AF3A  050000f447              add      eax, 0x47f40000                
  0x0106AF3F  004001                  add      byte ptr [eax + 1], al         
  0x0106AF42  0000                    add      byte ptr [eax], al             
  0x0106AF44  120c0500710020          adc      cl, byte ptr [eax + 0x20007100] 
  0x0106AF4B  00c4                    add      ah, al                         
  0x0106AF4D  40                      inc      eax                            
  0x0106AF4E  0100                    add      dword ptr [eax], eax           
  0x0106AF50  800000                  add      byte ptr [eax], 0              
  0x0106AF53  0013                    add      byte ptr [ebx], dl             
  0x0106AF55  2920                    sub      dword ptr [eax], esp           
  0x0106AF57  0000                    add      byte ptr [eax], al             
  0x0106AF59  8721                    xchg     dword ptr [ecx], esp           
  0x0106AF5B  000c0c                  add      byte ptr [esp + ecx], cl       
  0x0106AF5E  050001f044              add      eax, 0x44f00100                
  0x0106AF63  008f04000044            add      byte ptr [edi + 0x44000004], cl 
  0x0106AF6A  44                      inc      esp                            
  0x0106AF6B  008e04000001            add      byte ptr [esi + 0x1000004], cl 
  0x0106AF71  7054                    jo       0x106afc7                      
  0x0106AF73  008b04000044            add      byte ptr [ebx + 0x44000004], cl 
  0x0106AF79  7047                    jo       0x106afc2                      
  0x0106AF7B  009104000074            add      byte ptr [ecx + 0x74000004], dl 
  0x0106AF81  7054                    jo       0x106afd7                      
  0x0106AF83  008a0400001b            add      byte ptr [edx + 0x1b000004], cl 
  0x0106AF89  0c05                    or       al, 5                          
  0x0106AF8B  0000                    add      byte ptr [eax], al             
  0x0106AF8E  56                      push     esi                            
  0x0106AF8F  008b04000000            add      byte ptr [ebx + 4], cl         
  0x0106AF96  44                      inc      esp                            
  0x0106AF97  008d04000044            add      byte ptr [ebp + 0x44000004], cl 
  0x0106AF9E  44                      inc      esp                            
  0x0106AF9F  008f04000001            add      byte ptr [edi + 0x1000004], cl 
  0x0106AFA5  8621                    xchg     byte ptr [ecx], ah             
  0x0106AFA7  0044f045                add      byte ptr [eax + esi*8 + 0x45], al 
  0x0106AFAB  008a04000055            add      byte ptr [edx + 0x55000004], cl 
  0x0106AFB2  44                      inc      esp                            
  0x0106AFB3  008c0400005090          add      byte ptr [esp + eax - 0x6fb00000], cl 
  0x0106AFBA  0200                    add      al, byte ptr [eax]             
  0x0106AFBC  61                      popal                                   
  0x0106AFBD  7054                    jo       0x106b013                      
  0x0106AFBF  008b04000044            add      byte ptr [ebx + 0x44000004], cl 
  0x0106AFC6  44                      inc      esp                            
                                        ; XREF: 0x0106AF71 (cond_jump)
  0x0106AFC7  008e04000001            add      byte ptr [esi + 0x1000004], cl 
  0x0106AFCD  8621                    xchg     byte ptr [ecx], ah             
  0x0106AFCF  00447047                add      byte ptr [eax + esi*2 + 0x47], al 
  0x0106AFD3  009104000055            add      byte ptr [ecx + 0x55000004], dl 
  0x0106AFDA  44                      inc      esp                            
  0x0106AFDB  008b04000050            add      byte ptr [ebx + 0x50000004], cl 
  0x0106AFE1  90                      nop                                     
  0x0106AFE2  0200                    add      al, byte ptr [eax]             
  0x0106AFE4  7470                    je       0x106b056                      
  0x0106AFE6  54                      push     esp                            
  0x0106AFE7  008a04000045            add      byte ptr [edx + 0x45000004], cl 
  0x0106AFED  0020                    add      byte ptr [eax], ah             
  0x0106AFEF  004090                  add      byte ptr [eax - 0x70], al      
  0x0106AFF2  0200                    add      al, byte ptr [eax]             
  0x0106AFF4  00f0                    add      al, dh                         
  0x0106AFF6  44                      inc      esp                            
  0x0106AFF7  00900400004c            add      byte ptr [eax + 0x4c000004], dl 
  0x0106AFFD  de4e00                  fimul    word ptr [esi]                 
  0x0106B000  851c0c                  test     dword ptr [esp + ecx], ebx     
  0x0106B003  001429                  add      byte ptr [ecx + ebp], dl       
  0x0106B006  2000                    and      byte ptr [eax], al             
  0x0106B008  55                      push     ebp                            
  0x0106B009  0020                    add      byte ptr [eax], ah             
  0x0106B00B  005090                  add      byte ptr [eax - 0x70], dl      
  0x0106B00E  0200                    add      al, byte ptr [eax]             
  0x0106B010  006a54                  add      byte ptr [edx + 0x54], ch      
                                        ; XREF: 0x0106AFBD (cond_jump)
  0x0106B013  0000                    add      byte ptr [eax], al             
  0x0106B015  0e                      push     cs                             
  0x0106B016  2200                    and      al, byte ptr [eax]             
  0x0106B018  00c4                    add      ah, al                         
  0x0106B01A  2300                    and      eax, dword ptr [eax]           
  0x0106B01C  45                      inc      ebp                            
  0x0106B01D  5a                      pop      edx                            
  0x0106B01E  2000                    and      byte ptr [eax], al             
  0x0106B020  d7                      xlatb                                   
  0x0106B021  96                      xchg     esi, eax                       
  0x0106B022  05000c0000              add      eax, 0xc00                     
  0x0106B027  0000                    add      byte ptr [eax], al             
  0x0106B02A  56                      push     esi                            
  0x0106B02B  00b704000003            add      byte ptr [edi + 0x3000004], dh 
  0x0106B032  44                      inc      esp                            
  0x0106B033  00a204000007            add      byte ptr [edx + 0x7000004], ah 
  0x0106B039  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106B03A  050000ee20              add      eax, 0x20ee0000                
  0x0106B03F  00640024                add      byte ptr [eax + eax + 0x24], ah 
  0x0106B043  0010                    add      byte ptr [eax], dl             
  0x0106B045  cc                      int3                                    
  0x0106B046  06                      push     es                             
  0x0106B047  0002                    add      byte ptr [edx], al             
  0x0106B049  0000                    add      byte ptr [eax], al             
  0x0106B04B  0000                    add      byte ptr [eax], al             
  0x0106B04D  59                      pop      ecx                            
  0x0106B04E  44                      inc      esp                            
  0x0106B04F  004d0c                  add      byte ptr [ebp + 0xc], cl       
  0x0106B052  050000f464              add      eax, 0x64f40000                
  0x0106B057  00ba0c000000            add      byte ptr [edx + 0xc], bh       
  0x0106B05D  f4                      hlt                                     
  0x0106B05E  6600a504000000          add      byte ptr [ebp + 4], ah         
  0x0106B065  da5700                  ficom    dword ptr [edi]                
  0x0106B068  4c                      dec      esp                            
  0x0106B06A  46                      inc      esi                            
  0x0106B06B  00bf0400005c            add      byte ptr [edi + 0x5c000004], bh 
  0x0106B071  0020                    add      byte ptr [eax], ah             
  0x0106B073  001b                    add      byte ptr [ebx], bl             
  0x0106B075  2920                    sub      dword ptr [eax], esp           
  0x0106B077  00ce                    add      dh, cl                         
  0x0106B079  40                      inc      eax                            
  0x0106B07A  0100                    add      dword ptr [eax], eax           
  0x0106B07C  e01f                    loopne   0x106b09d                      
  0x0106B07E  0000                    add      byte ptr [eax], al             
  0x0106B080  58                      pop      eax                            
  0x0106B081  dd5e00                  fstp     qword ptr [esi]                
  0x0106B084  7500                    jne      0x106b086                      
                                        ; XREF: 0x0106B084 (cond_jump)
  0x0106B086  2000                    and      byte ptr [eax], al             
  0x0106B088  7070                    jo       0x106b0fa                      
  0x0106B08A  0200                    add      al, byte ptr [eax]             
  0x0106B08C  64c521                  lds      esp, ptr fs:[ecx]              
  0x0106B08F  0084410100009e          add      byte ptr [ecx + eax*2 - 0x61ffffff], al 
  0x0106B096  2100                    and      dword ptr [eax], eax           
  0x0106B098  00d8                    add      al, bl                         
  0x0106B09A  56                      push     esi                            
  0x0106B09B  0014f4                  add      byte ptr [esp + esi*8], dl     
  0x0106B09E  46                      inc      esi                            
  0x0106B09F  003f                    add      byte ptr [edi], bh             
  0x0106B0A1  0000                    add      byte ptr [eax], al             
  0x0106B0A3  0013                    add      byte ptr [ebx], dl             
  0x0106B0A5  2920                    sub      dword ptr [eax], esp           
  0x0106B0A7  00ca                    add      dl, cl                         
  0x0106B0A9  1e                      push     ds                             
  0x0106B0AA  0c00                    or       al, 0                          
  0x0106B0AC  55                      push     ebp                            
  0x0106B0AD  0020                    add      byte ptr [eax], ah             
  0x0106B0AF  005070                  add      byte ptr [eax + 0x70], dl      
  0x0106B0B2  0200                    add      al, byte ptr [eax]             
  0x0106B0B4  009c210010de06          add      byte ptr [ecx + 0x6de1000], bl 
  0x0106B0BB  000b                    add      byte ptr [ebx], cl             
  0x0106B0BD  0000                    add      byte ptr [eax], al             
  0x0106B0BF  0000                    add      byte ptr [eax], al             
  0x0106B0C1  d85600                  fcom     dword ptr [esi]                
  0x0106B0C4  14ec                    adc      al, 0xec                       
  0x0106B0C6  7e00                    jle      0x106b0c8                      
                                        ; XREF: 0x0106B0C6 (cond_jump)
  0x0106B0C8  1329                    adc      ebp, dword ptr [ecx]           
  0x0106B0CA  2000                    and      byte ptr [eax], al             
  0x0106B0CC  ca1e0c                  retf     0xc1e                          
  0x0106B0CF  005559                  add      byte ptr [ebp + 0x59], dl      
  0x0106B0D2  7600                    jbe      0x106b0d4                      
                                        ; XREF: 0x0106B0D2 (cond_jump)
  0x0106B0D4  50                      push     eax                            
  0x0106B0D5  7002                    jo       0x106b0d9                      
  0x0106B0D7  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x0106B0D5 (cond_jump)
  0x0106B0D9  9c                      pushfd                                  
  0x0106B0DA  2100                    and      dword ptr [eax], eax           
  0x0106B0DC  00ee                    add      dh, ch                         
  0x0106B0DE  56                      push     esi                            
  0x0106B0DF  008041010000            add      byte ptr [eax + 0x141], al     
  0x0106B0E5  6e                      outsb    dx, byte ptr [esi]             
  0x0106B0E6  54                      push     esp                            
  0x0106B0E7  0000                    add      byte ptr [eax], al             
  0x0106B0E9  ec                      in       al, dx                         
  0x0106B0EA  7e00                    jle      0x106b0ec                      
                                        ; XREF: 0x0106B0EA (cond_jump)
  0x0106B0EC  005976                  add      byte ptr [ecx + 0x76], bl      
  0x0106B0EF  0000                    add      byte ptr [eax], al             
  0x0106B0F1  ee                      out      dx, al                         
  0x0106B0F2  56                      push     esi                            
  0x0106B0F3  008041010071            add      byte ptr [eax + 0x71000141], al 
  0x0106B0F9  6e                      outsb    dx, byte ptr [esi]             
                                        ; XREF: 0x0106B088 (cond_jump)
  0x0106B0FA  54                      push     esp                            
  0x0106B0FB  006500                  add      byte ptr [ebp], ah             
  0x0106B0FE  2000                    and      byte ptr [eax], al             
  0x0106B100  99                      cdq                                     
  0x0106B101  7705                    ja       0x106b108                      
  0x0106B103  000c00                  add      byte ptr [eax + eax], cl       
  0x0106B106  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x0106B101 (cond_jump)
  0x0106B108  00f4                    add      ah, dh                         
  0x0106B10A  60                      pushal                                  
  0x0106B10B  00680b                  add      byte ptr [eax + 0xb], ch       
  0x0106B10E  0000                    add      byte ptr [eax], al             
  0x0106B110  00f0                    add      al, dh                         
  0x0106B112  7000                    jo       0x106b114                      
                                        ; XREF: 0x0106B112 (cond_jump)
  0x0106B114  40                      inc      eax                            
  0x0106B115  0b00                    or       eax, dword ptr [eax]           
  0x0106B117  0000                    add      byte ptr [eax], al             
  0x0106B119  e8570000f0              call     0xf106b175                     
  0x0106B11E  44                      inc      esp                            
  0x0106B11F  007a0b                  add      byte ptr [edx + 0xb], bh       
  0x0106B122  0000                    add      byte ptr [eax], al             
  0x0106B124  4c                      dec      esp                            
  0x0106B125  0020                    add      byte ptr [eax], ah             
  0x0106B127  000b                    add      byte ptr [ebx], cl             
  0x0106B129  0020                    add      byte ptr [eax], ah             
  0x0106B12B  000c14                  add      byte ptr [esp + edx], cl       
  0x0106B12E  0500130020              add      eax, 0x20001300                
  0x0106B133  0000                    add      byte ptr [eax], al             
  0x0106B135  7056                    jo       0x106b18d                      
  0x0106B137  00660b                  add      byte ptr [esi + 0xb], ah       
  0x0106B13A  0000                    add      byte ptr [eax], al             
  0x0106B13C  007056                  add      byte ptr [eax + 0x56], dh      
  0x0106B13F  00670b                  add      byte ptr [edi + 0xb], ah       
  0x0106B142  0000                    add      byte ptr [eax], al             
  0x0106B144  007056                  add      byte ptr [eax + 0x56], dh      
  0x0106B147  00a40400000070          add      byte ptr [esp + eax + 0x70000000], ah 
  0x0106B14E  56                      push     esi                            
  0x0106B14F  006e0b                  add      byte ptr [esi + 0xb], ch       
  0x0106B152  0000                    add      byte ptr [eax], al             
  0x0106B154  c0100d                  rcl      byte ptr [eax], 0xd            
  0x0106B157  0027                    add      byte ptr [edi], ah             
  0x0106B159  0000                    add      byte ptr [eax], al             
  0x0106B15B  0013                    add      byte ptr [ebx], dl             
  0x0106B15D  0020                    add      byte ptr [eax], ah             
  0x0106B15F  0000                    add      byte ptr [eax], al             
  0x0106B161  d821                    fsub     dword ptr [ecx]                
  0x0106B163  0000                    add      byte ptr [eax], al             
  0x0106B166  44                      inc      esp                            
  0x0106B167  00700b                  add      byte ptr [eax + 0xb], dh       
  0x0106B16A  0000                    add      byte ptr [eax], al             
  0x0106B16C  45                      inc      ebp                            
  0x0106B16D  0020                    add      byte ptr [eax], ah             
  0x0106B16F  000494                  add      byte ptr [esp + edx*4], al     
  0x0106B172  050000f456              add      eax, 0x56f40000                
  0x0106B177  0009                    add      byte ptr [ecx], cl             
  0x0106B179  0000                    add      byte ptr [eax], al             
  0x0106B17B  0000                    add      byte ptr [eax], al             
  0x0106B17D  d821                    fsub     dword ptr [ecx]                
  0x0106B17F  000500200009            add      byte ptr [0x9002000], al       
  0x0106B185  f4                      hlt                                     
  0x0106B186  0500130020              add      eax, 0x20001300                
  0x0106B18B  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x0106B135 (cond_jump)
  0x0106B18D  7056                    jo       0x106b1e5                      
  0x0106B18F  00660b                  add      byte ptr [esi + 0xb], ah       
  0x0106B192  0000                    add      byte ptr [eax], al             
  0x0106B194  007056                  add      byte ptr [eax + 0x56], dh      
  0x0106B197  00670b                  add      byte ptr [edi + 0xb], ah       
  0x0106B19A  0000                    add      byte ptr [eax], al             
  0x0106B19C  007056                  add      byte ptr [eax + 0x56], dh      
  0x0106B19F  00a4040000130c          add      byte ptr [esp + eax + 0xc130000], ah 
  0x0106B1A6  050000f456              add      eax, 0x56f40000                
  0x0106B1AB  0001                    add      byte ptr [ecx], al             
  0x0106B1AD  0000                    add      byte ptr [eax], al             
  0x0106B1AF  0000                    add      byte ptr [eax], al             
  0x0106B1B1  7056                    jo       0x106b209                      
  0x0106B1B3  00660b                  add      byte ptr [esi + 0xb], ah       
  0x0106B1B6  0000                    add      byte ptr [eax], al             
  0x0106B1B8  00ee                    add      dh, ch                         
  0x0106B1BA  2100                    and      dword ptr [eax], eax           
  0x0106B1BC  000423                  add      byte ptr [ebx], al             
  0x0106B1BF  00440020                add      byte ptr [eax + eax + 0x20], al 
  0x0106B1C3  0006                    add      byte ptr [esi], al             
  0x0106B1C5  1c0c                    sbb      al, 0xc                        
  0x0106B1C7  0000                    add      byte ptr [eax], al             
  0x0106B1C9  0028                    add      byte ptr [eax], ch             
  0x0106B1CB  0000                    add      byte ptr [eax], al             
  0x0106B1CD  7056                    jo       0x106b225                      
  0x0106B1CF  00670b                  add      byte ptr [edi + 0xb], ah       
  0x0106B1D2  0000                    add      byte ptr [eax], al             
  0x0106B1D4  06                      push     es                             
  0x0106B1D5  1d0c000004              sbb      eax, 0x400000c                 
  0x0106B1DA  2300                    and      eax, dword ptr [eax]           
  0x0106B1DC  40                      inc      eax                            
  0x0106B1DD  0020                    add      byte ptr [eax], ah             
  0x0106B1DF  0000                    add      byte ptr [eax], al             
  0x0106B1E1  7056                    jo       0x106b239                      
  0x0106B1E3  00a404000000c4          add      byte ptr [esp + eax - 0x3c000000], ah 
  0x0106B1EA  2100                    and      dword ptr [eax], eax           
  0x0106B1EC  4c                      dec      esp                            
  0x0106B1ED  0020                    add      byte ptr [eax], ah             
  0x0106B1EF  0000                    add      byte ptr [eax], al             
  0x0106B1F2  56                      push     esi                            
  0x0106B1F3  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106B1F6  0000                    add      byte ptr [eax], al             
  0x0106B1F8  00f4                    add      ah, dh                         
  0x0106B1FA  44                      inc      esp                            
  0x0106B1FB  000500000045            add      byte ptr [0x45000000], al      
  0x0106B201  0020                    add      byte ptr [eax], ah             
  0x0106B203  0013                    add      byte ptr [ebx], dl             
  0x0106B205  2405                    and      al, 5                          
  0x0106B207  0000                    add      byte ptr [eax], al             
  0x0106B20A  56                      push     esi                            
  0x0106B20B  009f0b000000            add      byte ptr [edi + 0xb], bl       
  0x0106B212  44                      inc      esp                            
  0x0106B213  007a0b                  add      byte ptr [edx + 0xb], bh       
  0x0106B216  0000                    add      byte ptr [eax], al             
  0x0106B218  44                      inc      esp                            
  0x0106B219  0020                    add      byte ptr [eax], ah             
  0x0106B21B  0000                    add      byte ptr [eax], al             
  0x0106B21E  44                      inc      esp                            
  0x0106B21F  00530b                  add      byte ptr [ebx + 0xb], dl       
  0x0106B222  0000                    add      byte ptr [eax], al             
  0x0106B224  44                      inc      esp                            
                                        ; XREF: 0x0106B1CD (cond_jump)
  0x0106B225  0020                    add      byte ptr [eax], ah             
  0x0106B227  0000                    add      byte ptr [eax], al             
  0x0106B229  d921                    fldenv   [ecx]                          
  0x0106B22B  0000                    add      byte ptr [eax], al             
  0x0106B22D  7057                    jo       0x106b286                      
  0x0106B22F  006e0b                  add      byte ptr [esi + 0xb], ch       
  0x0106B232  0000                    add      byte ptr [eax], al             
  0x0106B234  0300                    add      eax, dword ptr [eax]           
  0x0106B236  2000                    and      byte ptr [eax], al             
  0x0106B238  0494                    add      al, 0x94                       
  0x0106B23A  0500050020              add      eax, 0x20000500                
  0x0106B23F  0002                    add      byte ptr [edx], al             
  0x0106B241  f4                      hlt                                     
  0x0106B242  0500030c05              add      eax, 0x50c0300                 
  0x0106B247  0000                    add      byte ptr [eax], al             
  0x0106B249  2423                    and      al, 0x23                       
  0x0106B24B  0000                    add      byte ptr [eax], al             
  0x0106B24E  2000                    and      byte ptr [eax], al             
  0x0106B250  00f0                    add      al, dh                         
  0x0106B252  56                      push     esi                            
  0x0106B253  00700b                  add      byte ptr [eax + 0xb], dh       
  0x0106B256  0000                    add      byte ptr [eax], al             
  0x0106B258  0300                    add      eax, dword ptr [eax]           
  0x0106B25A  2000                    and      byte ptr [eax], al             
  0x0106B25C  0af4                    or       dh, ah                         
  0x0106B25E  050000f444              add      eax, 0x44f40000                
  0x0106B263  0001                    add      byte ptr [ecx], al             
  0x0106B265  0000                    add      byte ptr [eax], al             
  0x0106B267  0000                    add      byte ptr [eax], al             
  0x0106B269  7044                    jo       0x106b2af                      
  0x0106B26B  00660b                  add      byte ptr [esi + 0xb], ah       
  0x0106B26E  0000                    add      byte ptr [eax], al             
  0x0106B270  00f0                    add      al, dh                         
  0x0106B272  44                      inc      esp                            
  0x0106B273  00670b                  add      byte ptr [edi + 0xb], ah       
  0x0106B276  0000                    add      byte ptr [eax], al             
  0x0106B278  40                      inc      eax                            
  0x0106B279  0020                    add      byte ptr [eax], ah             
  0x0106B27B  0000                    add      byte ptr [eax], al             
  0x0106B27D  7056                    jo       0x106b2d5                      
  0x0106B27F  00670b                  add      byte ptr [edi + 0xb], ah       
  0x0106B282  0000                    add      byte ptr [eax], al             
  0x0106B284  0c00                    or       al, 0                          
                                        ; XREF: 0x0106B22D (cond_jump)
  0x0106B286  0000                    add      byte ptr [eax], al             
  0x0106B288  0011                    add      byte ptr [ecx], dl             
  0x0106B28A  2200                    and      al, byte ptr [eax]             
  0x0106B28C  00b2220069f4            add      byte ptr [edx - 0xb96ffde], dh 
  0x0106B292  46                      inc      esi                            
  0x0106B293  0002                    add      byte ptr [edx], al             
  0x0106B295  0000                    add      byte ptr [eax], al             
  0x0106B297  0010                    add      byte ptr [eax], dl             
  0x0106B299  d806                    fadd     dword ptr [esi]                
  0x0106B29B  000500000000            add      byte ptr [0], al               
  0x0106B2A1  c9                      leave                                   
  0x0106B2A2  56                      push     esi                            
  0x0106B2A3  00148f                  add      byte ptr [edi + ecx*4], dl     
  0x0106B2A6  2100                    and      dword ptr [eax], eax           
  0x0106B2A8  50                      push     eax                            
  0x0106B2A9  0020                    add      byte ptr [eax], ah             
  0x0106B2AB  0000                    add      byte ptr [eax], al             
  0x0106B2AD  5a                      pop      edx                            
  0x0106B2AE  54                      push     esp                            
                                        ; XREF: 0x0106B269 (cond_jump)
  0x0106B2AF  0000                    add      byte ptr [eax], al             
  0x0106B2B1  4e                      dec      esi                            
  0x0106B2B2  2300                    and      eax, dword ptr [eax]           
  0x0106B2B4  32442300                xor      al, byte ptr [ebx]             
  0x0106B2B8  40                      inc      eax                            
  0x0106B2B9  0423                    add      al, 0x23                       
  0x0106B2BB  00440024                add      byte ptr [eax + eax + 0x24], al 
  0x0106B2BF  0004a4                  add      byte ptr [esp], al             
  0x0106B2C2  050010cc06              add      eax, 0x6cc1000                 
  0x0106B2C7  0002                    add      byte ptr [edx], al             
  0x0106B2C9  0000                    add      byte ptr [eax], al             
  0x0106B2CB  0000                    add      byte ptr [eax], al             
  0x0106B2CD  5a                      pop      edx                            
  0x0106B2CE  44                      inc      esp                            
  0x0106B2CF  0000                    add      byte ptr [eax], al             
  0x0106B2D1  b022                    mov      al, 0x22                       
  0x0106B2D3  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x0106B27D (cond_jump)
  0x0106B2D5  91                      xchg     ecx, eax                       
  0x0106B2D6  2200                    and      al, byte ptr [eax]             
  0x0106B2D8  00f4                    add      ah, dh                         
  0x0106B2DA  65000d0d000000          add      byte ptr gs:[0xd], cl          
  0x0106B2E1  f4                      hlt                                     
  0x0106B2E2  7500                    jne      0x106b2e4                      
  0x0106B2E6  ff00                    inc      dword ptr [eax]                
  0x0106B2E8  10da                    adc      dl, bl                         
  0x0106B2EA  06                      push     es                             
  0x0106B2EB  0007                    add      byte ptr [edi], al             
  0x0106B2ED  0000                    add      byte ptr [eax], al             
  0x0106B2EF  0000                    add      byte ptr [eax], al             
  0x0106B2F1  b8f000d0b8              mov      eax, 0xb8d000f0                
  0x0106B2F7  00d2                    add      dl, dl                         
  0x0106B2F9  b8d000d200              mov      eax, 0xd200d0                  
  0x0106B2FE  2000                    and      byte ptr [eax], al             
  0x0106B300  2200                    and      al, byte ptr [eax]             
  0x0106B302  2000                    and      byte ptr [eax], al             
  0x0106B304  005958                  add      byte ptr [ecx + 0x58], bl      
  0x0106B307  000c00                  add      byte ptr [eax + eax], cl       
  0x0106B30A  0000                    add      byte ptr [eax], al             
  0x0106B30C  20f4                    and      ah, dh                         
  0x0106B30E  0500ffffff              add      eax, 0xffffff00                
  0x0106B313  00a0610400a0            add      byte ptr [eax - 0x5ffffb9f], ah 
  0x0106B319  620400                  bound    eax, qword ptr [eax + eax]     
  0x0106B31C  a0640400a0              mov      al, byte ptr [0xa0000464]      
  0x0106B321  650400                  add      al, 0                          
  0x0106B324  a0660400b8              mov      al, byte ptr [0xb8000466]      
  0x0106B329  f30000                  add      byte ptr [eax], al             
  0x0106B32C  00f4                    add      ah, dh                         
  0x0106B32E  44                      inc      esp                            
  0x0106B32F  0000                    add      byte ptr [eax], al             
  0x0106B331  0000                    add      byte ptr [eax], al             
  0x0106B333  004d00                  add      byte ptr [ebp], cl             
  0x0106B336  2000                    and      byte ptr [eax], al             
  0x0106B338  0ca4                    or       al, 0xa4                       
  0x0106B33A  050000f444              add      eax, 0x44f40000                
  0x0106B33F  0010                    add      byte ptr [eax], dl             
  0x0106B341  0000                    add      byte ptr [eax], al             
  0x0106B343  004d00                  add      byte ptr [ebp], cl             
  0x0106B346  2000                    and      byte ptr [eax], al             
  0x0106B348  4a                      dec      edx                            
  0x0106B349  100d000f0000            adc      byte ptr [0xf00], cl           
  0x0106B34F  0000                    add      byte ptr [eax], al             
  0x0106B351  0030                    add      byte ptr [eax], dh             
  0x0106B353  0000                    add      byte ptr [eax], al             
  0x0106B355  f4                      hlt                                     
  0x0106B356  56                      push     esi                            
  0x0106B357  0000                    add      byte ptr [eax], al             
  0x0106B359  0000                    add      byte ptr [eax], al             
  0x0106B35B  0000                    add      byte ptr [eax], al             
  0x0106B35D  f4                      hlt                                     
  0x0106B35E  57                      push     edi                            
  0x0106B35F  00ff                    add      bh, bh                         
  0x0106B362  ff00                    inc      dword ptr [eax]                
  0x0106B364  0c00                    or       al, 0                          
  0x0106B366  0000                    add      byte ptr [eax], al             
  0x0106B368  1300                    adc      eax, dword ptr [eax]           
  0x0106B36A  2000                    and      byte ptr [eax], al             
  0x0106B36C  0000                    add      byte ptr [eax], al             
  0x0106B36E  3000                    xor      byte ptr [eax], al             
  0x0106B370  00f4                    add      ah, dh                         
  0x0106B372  56                      push     esi                            
  0x0106B373  0000                    add      byte ptr [eax], al             
  0x0106B375  0000                    add      byte ptr [eax], al             
  0x0106B377  0000                    add      byte ptr [eax], al             
  0x0106B379  f4                      hlt                                     
  0x0106B37A  57                      push     edi                            
  0x0106B37B  0008                    add      byte ptr [eax], cl             
  0x0106B37D  06                      push     es                             
  0x0106B37E  0000                    add      byte ptr [eax], al             
  0x0106B380  0c00                    or       al, 0                          
  0x0106B382  0000                    add      byte ptr [eax], al             
  0x0106B384  00f0                    add      al, dh                         
  0x0106B386  56                      push     esi                            
  0x0106B387  00960b000003            add      byte ptr [esi + 0x300000b], dl 
  0x0106B38D  0020                    add      byte ptr [eax], ah             
  0x0106B38F  001e                    add      byte ptr [esi], bl             
  0x0106B391  7405                    je       0x106b398                      
  0x0106B393  0000                    add      byte ptr [eax], al             
  0x0106B396  56                      push     esi                            
  0x0106B397  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106B39A  0000                    add      byte ptr [eax], al             
  0x0106B39C  0300                    add      eax, dword ptr [eax]           
  0x0106B39E  2e0002                  add      byte ptr cs:[edx], al          
  0x0106B3A1  2405                    and      al, 5                          
  0x0106B3A3  008041010000            add      byte ptr [eax + 0x141], al     
  0x0106B3A9  7056                    jo       0x106b401                      
  0x0106B3AB  00890b000080            add      byte ptr [ecx - 0x7ffffff5], cl 
  0x0106B3B1  100d008b0300            adc      byte ptr [0x38b00], cl         
  0x0106B3B7  0000                    add      byte ptr [eax], al             
  0x0106B3B9  f4                      hlt                                     
  0x0106B3BA  44                      inc      esp                            
  0x0106B3BB  00b007000000            add      byte ptr [eax + 7], dh         
  0x0106B3C1  7044                    jo       0x106b407                      
  0x0106B3C3  00720b                  add      byte ptr [edx + 0xb], dh       
  0x0106B3C6  0000                    add      byte ptr [eax], al             
  0x0106B3C8  80100d                  adc      byte ptr [eax], 0xd            
  0x0106B3CB  001400                  add      byte ptr [eax + eax], dl       
  0x0106B3CE  0000                    add      byte ptr [eax], al             
  0x0106B3D0  00f0                    add      al, dh                         
  0x0106B3D2  56                      push     esi                            
  0x0106B3D3  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106B3D6  0000                    add      byte ptr [eax], al             
  0x0106B3D8  0300                    add      eax, dword ptr [eax]           
  0x0106B3DA  2e0003                  add      byte ptr cs:[ebx], al          
  0x0106B3DD  2405                    and      al, 5                          
  0x0106B3DF  0080100d0053            add      byte ptr [eax + 0x53000d10], al 
  0x0106B3E5  0300                    add      eax, dword ptr [eax]           
  0x0106B3E7  0080100d009d            add      byte ptr [eax - 0x62fff2f0], al 
  0x0106B3ED  0000                    add      byte ptr [eax], al             
  0x0106B3EF  0000                    add      byte ptr [eax], al             
  0x0106B3F2  56                      push     esi                            
  0x0106B3F3  00960b000003            add      byte ptr [esi + 0x300000b], dl 
  0x0106B3F9  0020                    add      byte ptr [eax], ah             
  0x0106B3FB  0003                    add      byte ptr [ebx], al             
  0x0106B3FD  2405                    and      al, 5                          
  0x0106B3FF  0080100d009c            add      byte ptr [eax - 0x63fff2f0], al 
  0x0106B405  0100                    add      dword ptr [eax], eax           
                                        ; XREF: 0x0106B3C1 (cond_jump)
  0x0106B407  0013                    add      byte ptr [ebx], dl             
  0x0106B409  0020                    add      byte ptr [eax], ah             
  0x0106B40B  001b                    add      byte ptr [ebx], bl             
  0x0106B40D  1021                    adc      byte ptr [ecx], ah             
  0x0106B40F  000c00                  add      byte ptr [eax + eax], cl       
  0x0106B412  0000                    add      byte ptr [eax], al             
  0x0106B414  0c00                    or       al, 0                          
  0x0106B416  0000                    add      byte ptr [eax], al             
  0x0106B418  00f4                    add      ah, dh                         
  0x0106B41A  44                      inc      esp                            
  0x0106B41B  0001                    add      byte ptr [ecx], al             
  0x0106B41D  0000                    add      byte ptr [eax], al             
  0x0106B41F  0000                    add      byte ptr [eax], al             
  0x0106B421  7044                    jo       0x106b467                      
  0x0106B423  006f0b                  add      byte ptr [edi + 0xb], ch       
  0x0106B426  0000                    add      byte ptr [eax], al             
  0x0106B428  1bf0                    sbb      esi, eax                       
  0x0106B42A  56                      push     esi                            
  0x0106B42B  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106B42E  0000                    add      byte ptr [eax], al             
  0x0106B430  0300                    add      eax, dword ptr [eax]           
  0x0106B432  2000                    and      byte ptr [eax], al             
  0x0106B434  02240500090000          add      ah, byte ptr [eax + 0x900]     
  0x0106B43B  0000                    add      byte ptr [eax], al             
  0x0106B43D  7051                    jo       0x106b490                      
  0x0106B43F  00c0                    add      al, al                         
  0x0106B441  0400                    add      al, 0                          
  0x0106B443  0000                    add      byte ptr [eax], al             
  0x0106B445  0230                    add      dh, byte ptr [eax]             
  0x0106B447  0000                    add      byte ptr [eax], al             
  0x0106B449  0131                    add      dword ptr [ecx], esi           
  0x0106B44B  0000                    add      byte ptr [eax], al             
  0x0106B44D  0132                    add      dword ptr [edx], esi           
  0x0106B44F  0000                    add      byte ptr [eax], al             
  0x0106B451  023500c4700b            add      dh, byte ptr [0xb70c400]       
  0x0106B457  0008                    add      byte ptr [eax], cl             
  0x0106B459  0c00                    or       al, 0                          
  0x0106B45B  0000                    add      byte ptr [eax], al             
  0x0106B45D  7044                    jo       0x106b4a3                      
  0x0106B45F  008d040000c4            add      byte ptr [ebp - 0x3bfffffc], cl 
  0x0106B465  710b                    jno      0x106b472                      
                                        ; XREF: 0x0106B421 (cond_jump)
  0x0106B467  00040c                  add      byte ptr [esp + ecx], al       
  0x0106B46A  0000                    add      byte ptr [eax], al             
  0x0106B46C  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106B46F  008c040000c472          add      byte ptr [esp + eax + 0x72c40000], cl 
  0x0106B476  0b00                    or       eax, dword ptr [eax]           
  0x0106B478  140c                    adc      al, 0xc                        
  0x0106B47A  0000                    add      byte ptr [eax], al             
  0x0106B47C  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106B47F  008f040000c4            add      byte ptr [edi - 0x3bfffffc], cl 
  0x0106B485  750b                    jne      0x106b492                      
  0x0106B487  0018                    add      byte ptr [eax], bl             
  0x0106B489  0c00                    or       al, 0                          
  0x0106B48B  0000                    add      byte ptr [eax], al             
  0x0106B48D  7044                    jo       0x106b4d3                      
  0x0106B48F  009004000000            add      byte ptr [eax + 4], dl         
  0x0106B495  0036                    add      byte ptr [esi], dh             
  0x0106B497  0000                    add      byte ptr [eax], al             
  0x0106B49A  44                      inc      esp                            
  0x0106B49B  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x0106B4A1  c406                    les      eax, ptr [esi]                 
                                        ; XREF: 0x0106B45D (cond_jump)
  0x0106B4A3  004e00                  add      byte ptr [esi], cl             
  0x0106B4A6  0000                    add      byte ptr [eax], al             
  0x0106B4A8  0001                    add      byte ptr [ecx], al             
  0x0106B4AA  2800                    sub      byte ptr [eax], al             
  0x0106B4AC  007050                  add      byte ptr [eax + 0x50], dh      
  0x0106B4AF  00c0                    add      al, al                         
  0x0106B4B1  0400                    add      al, 0                          
  0x0106B4B3  0000                    add      byte ptr [eax], al             
  0x0106B4B5  0430                    add      al, 0x30                       
  0x0106B4B7  00c4                    add      ah, al                         
  0x0106B4B9  700b                    jo       0x106b4c6                      
  0x0106B4BB  000c0c                  add      byte ptr [esp + ecx], cl       
  0x0106B4BE  0000                    add      byte ptr [eax], al             
  0x0106B4C0  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106B4C3  008e04000000            add      byte ptr [esi + 4], cl         
  0x0106B4C9  f4                      hlt                                     
  0x0106B4CA  44                      inc      esp                            
  0x0106B4CB  0000                    add      byte ptr [eax], al             
  0x0106B4CD  80ff00                  cmp      bh, 0                          
  0x0106B4D0  007044                  add      byte ptr [eax + 0x44], dh      
                                        ; XREF: 0x0106B48D (cond_jump)
  0x0106B4D3  008a04000000            add      byte ptr [edx + 4], cl         
  0x0106B4D9  f4                      hlt                                     
  0x0106B4DA  44                      inc      esp                            
  0x0106B4DB  0000                    add      byte ptr [eax], al             
  0x0106B4DD  80ff00                  cmp      bh, 0                          
  0x0106B4E0  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106B4E3  008b04000000            add      byte ptr [ebx + 4], cl         
  0x0106B4E9  c422                    les      esp, ptr [edx]                 
  0x0106B4EB  0000                    add      byte ptr [eax], al             
  0x0106B4ED  f4                      hlt                                     
  0x0106B4EE  46                      inc      esi                            
  0x0106B4EF  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x0106B4F5  f4                      hlt                                     
  0x0106B4F6  44                      inc      esp                            
  0x0106B4F7  00fa                    add      dl, bh                         
  0x0106B4F9  0000                    add      byte ptr [eax], al             
  0x0106B4FB  002e                    add      byte ptr [esi], ch             
  0x0106B4FD  1d0c004000              sbb      eax, 0x40000c                  
  0x0106B502  2000                    and      byte ptr [eax], al             
  0x0106B504  0090210000c4            add      byte ptr [eax - 0x3bffffdf], dl 
  0x0106B50A  2200                    and      al, byte ptr [eax]             
  0x0106B50C  00f4                    add      ah, dh                         
  0x0106B50E  46                      inc      esi                            
  0x0106B50F  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x0106B515  f4                      hlt                                     
  0x0106B516  44                      inc      esp                            
  0x0106B517  00fa                    add      dl, bh                         
  0x0106B519  0000                    add      byte ptr [eax], al             
  0x0106B51B  002e                    add      byte ptr [esi], ch             
  0x0106B51D  1d0c004000              sbb      eax, 0x40000c                  
  0x0106B522  2000                    and      byte ptr [eax], al             
  0x0106B524  0095210000c4            add      byte ptr [ebp - 0x3bffffdf], dl 
  0x0106B52A  2200                    and      al, byte ptr [eax]             
  0x0106B52C  00f4                    add      ah, dh                         
  0x0106B52E  46                      inc      esi                            
  0x0106B52F  0032                    add      byte ptr [edx], dh             
  0x0106B531  0000                    add      byte ptr [eax], al             
  0x0106B533  00d0                    add      al, dl                         
  0x0106B535  f4                      hlt                                     
  0x0106B536  44                      inc      esp                            
  0x0106B537  0000                    add      byte ptr [eax], al             
  0x0106B539  0000                    add      byte ptr [eax], al             
  0x0106B53B  002e                    add      byte ptr [esi], ch             
  0x0106B53D  1d0c004000              sbb      eax, 0x40000c                  
  0x0106B542  2000                    and      byte ptr [eax], al             
  0x0106B544  009a21000000            add      byte ptr [edx + 0x21], bl      
  0x0106B54A  3800                    cmp      byte ptr [eax], al             
  0x0106B54C  00f4                    add      ah, dh                         
  0x0106B54E  56                      push     esi                            
  0x0106B54F  00a50b000000            add      byte ptr [ebp + 0xb], ah       
  0x0106B555  c422                    les      esp, ptr [edx]                 
  0x0106B557  004000                  add      byte ptr [eax], al             
  0x0106B55A  2000                    and      byte ptr [eax], al             
  0x0106B55C  0091210000e1            add      byte ptr [ecx - 0x1effffdf], dl 
  0x0106B562  7400                    je       0x106b564                      
                                        ; XREF: 0x0106B562 (cond_jump)
  0x0106B564  00e1                    add      cl, ah                         
  0x0106B566  7600                    jbe      0x106b568                      
                                        ; XREF: 0x0106B566 (cond_jump)
  0x0106B568  0000                    add      byte ptr [eax], al             
  0x0106B56A  3200                    xor      al, byte ptr [eax]             
  0x0106B56C  007066                  add      byte ptr [eax + 0x66], dh      
  0x0106B56F  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106B572  0000                    add      byte ptr [eax], al             
  0x0106B574  d7                      xlatb                                   
  0x0106B575  030d0000f066            add      ecx, dword ptr [0x66f00000]    
  0x0106B57B  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106B57E  0000                    add      byte ptr [eax], al             
  0x0106B580  00f4                    add      ah, dh                         
  0x0106B582  56                      push     esi                            
  0x0106B583  00c1                    add      cl, al                         
  0x0106B585  0400                    add      al, 0                          
  0x0106B587  0000                    add      byte ptr [eax], al             
  0x0106B589  c422                    les      esp, ptr [edx]                 
  0x0106B58B  004000                  add      byte ptr [eax], al             
  0x0106B58E  2000                    and      byte ptr [eax], al             
  0x0106B590  009021000060            add      byte ptr [eax + 0x60000021], dl 
  0x0106B596  6200                    bound    eax, qword ptr [eax]           
  0x0106B598  00f4                    add      ah, dh                         
  0x0106B59A  56                      push     esi                            
  0x0106B59B  009404000000c4          add      byte ptr [esp + eax - 0x3c000000], dl 
  0x0106B5A2  2200                    and      al, byte ptr [eax]             
  0x0106B5A4  40                      inc      eax                            
  0x0106B5A5  0020                    add      byte ptr [eax], ah             
  0x0106B5A7  0000                    add      byte ptr [eax], al             
  0x0106B5A9  90                      nop                                     
  0x0106B5AA  2100                    and      dword ptr [eax], eax           
  0x0106B5AC  00f0                    add      al, dh                         
  0x0106B5AE  44                      inc      esp                            
  0x0106B5AF  008a04000000            add      byte ptr [edx + 4], cl         
  0x0106B5B5  60                      pushal                                  
  0x0106B5B6  44                      inc      esp                            
  0x0106B5B7  0000                    add      byte ptr [eax], al             
  0x0106B5B9  f4                      hlt                                     
  0x0106B5BA  56                      push     esi                            
  0x0106B5BB  009904000000            add      byte ptr [ecx + 4], bl         
  0x0106B5C1  c422                    les      esp, ptr [edx]                 
  0x0106B5C3  004000                  add      byte ptr [eax], al             
  0x0106B5C6  2000                    and      byte ptr [eax], al             
  0x0106B5C8  0090210000f0            add      byte ptr [eax - 0xfffffdf], dl 
  0x0106B5CE  44                      inc      esp                            
  0x0106B5CF  008b04000000            add      byte ptr [ebx + 4], cl         
  0x0106B5D5  60                      pushal                                  
  0x0106B5D6  44                      inc      esp                            
  0x0106B5D7  0000                    add      byte ptr [eax], al             
  0x0106B5D9  5e                      pop      esi                            
  0x0106B5DA  2000                    and      byte ptr [eax], al             
  0x0106B5DC  00f0                    add      al, dh                         
  0x0106B5DE  56                      push     esi                            
  0x0106B5DF  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x0106B5E2  0000                    add      byte ptr [eax], al             
  0x0106B5E4  0300                    add      eax, dword ptr [eax]           
  0x0106B5E6  2000                    and      byte ptr [eax], al             
  0x0106B5E8  1ca4                    sbb      al, 0xa4                       
  0x0106B5EA  0500000128              add      eax, 0x28010000                
  0x0106B5EF  0000                    add      byte ptr [eax], al             
  0x0106B5F1  7050                    jo       0x106b643                      
  0x0106B5F3  00c0                    add      al, al                         
  0x0106B5F5  0400                    add      al, 0                          
  0x0106B5F7  0000                    add      byte ptr [eax], al             
  0x0106B5F9  0430                    add      al, 0x30                       
  0x0106B5FB  00c4                    add      ah, al                         
  0x0106B5FD  700b                    jo       0x106b60a                      
  0x0106B5FF  000c0c                  add      byte ptr [esp + ecx], cl       
  0x0106B602  0000                    add      byte ptr [eax], al             
  0x0106B604  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106B607  008e04000000            add      byte ptr [esi + 4], cl         
  0x0106B60D  f4                      hlt                                     
  0x0106B60E  44                      inc      esp                            
  0x0106B60F  0000                    add      byte ptr [eax], al             
  0x0106B611  80ff00                  cmp      bh, 0                          
  0x0106B614  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106B617  008a04000000            add      byte ptr [edx + 4], cl         
  0x0106B61D  f4                      hlt                                     
  0x0106B61E  44                      inc      esp                            
  0x0106B61F  0000                    add      byte ptr [eax], al             
  0x0106B621  80ff00                  cmp      bh, 0                          
  0x0106B624  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106B627  008b04000000            add      byte ptr [ebx + 4], cl         
  0x0106B62D  f4                      hlt                                     
  0x0106B62E  60                      pushal                                  
  0x0106B62F  008304000000            add      byte ptr [ebx + 4], al         
  0x0106B635  f4                      hlt                                     
  0x0106B636  65008304000000          add      byte ptr gs:[ebx + 4], al      
  0x0106B63D  f4                      hlt                                     
  0x0106B63E  7200                    jb       0x106b640                      
                                        ; XREF: 0x0106B63E (cond_jump)
  0x0106B640  b804000000              mov      eax, 4                         
  0x0106B645  0038                    add      byte ptr [eax], bh             
  0x0106B647  0000                    add      byte ptr [eax], al             
  0x0106B649  07                      pop      es                             
  0x0106B64A  3c00                    cmp      al, 0                          
  0x0106B64C  0007                    add      byte ptr [edi], al             
  0x0106B64E  3e0000                  add      byte ptr ds:[eax], al          
  0x0106B651  0032                    add      byte ptr [edx], dh             
  0x0106B653  00d7                    add      bh, dl                         
  0x0106B655  030d000c0000            add      ecx, dword ptr [0xc00]         
  0x0106B65B  0000                    add      byte ptr [eax], al             
  0x0106B65E  56                      push     esi                            
  0x0106B65F  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106B662  0000                    add      byte ptr [eax], al             
  0x0106B664  0300                    add      eax, dword ptr [eax]           
  0x0106B666  2000                    and      byte ptr [eax], al             
  0x0106B668  0424                    add      al, 0x24                       
  0x0106B66A  0500000024              add      eax, 0x24000000                
  0x0106B66F  0000                    add      byte ptr [eax], al             
  0x0106B671  7044                    jo       0x106b6b7                      
  0x0106B673  006e0b                  add      byte ptr [esi + 0xb], ch       
  0x0106B676  0000                    add      byte ptr [eax], al             
  0x0106B678  0000                    add      byte ptr [eax], al             
  0x0106B67A  3400                    xor      al, 0                          
  0x0106B67C  1b00                    sbb      eax, dword ptr [eax]           
  0x0106B67E  2000                    and      byte ptr [eax], al             
  0x0106B680  00f0                    add      al, dh                         
  0x0106B682  44                      inc      esp                            
  0x0106B683  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x0106B689  c406                    les      eax, ptr [esi]                 
  0x0106B68B  0003                    add      byte ptr [ebx], al             
  0x0106B68D  0000                    add      byte ptr [eax], al             
  0x0106B68F  008841010088            add      byte ptr [eax - 0x77fffebf], cl 
  0x0106B695  41                      inc      ecx                            
  0x0106B696  0100                    add      dword ptr [eax], eax           
  0x0106B698  884101                  mov      byte ptr [ecx + 1], al         
  0x0106B69B  0000                    add      byte ptr [eax], al             
  0x0106B69E  56                      push     esi                            
  0x0106B69F  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x0106B6A2  0000                    add      byte ptr [eax], al             
  0x0106B6A4  0300                    add      eax, dword ptr [eax]           
  0x0106B6A6  2000                    and      byte ptr [eax], al             
  0x0106B6A8  02240500884101          add      ah, byte ptr [eax + 0x1418800] 
  0x0106B6AF  0000                    add      byte ptr [eax], al             
  0x0106B6B2  56                      push     esi                            
  0x0106B6B3  004a0b                  add      byte ptr [edx + 0xb], cl       
  0x0106B6B6  0000                    add      byte ptr [eax], al             
  0x0106B6B8  03f4                    add      esi, esp                       
  0x0106B6BA  44                      inc      esp                            
  0x0106B6BB  0008                    add      byte ptr [eax], cl             
  0x0106B6BD  0000                    add      byte ptr [eax], al             
  0x0106B6BF  0002                    add      byte ptr [edx], al             
  0x0106B6C1  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106B6C2  0500480020              add      eax, 0x20004800                
  0x0106B6C7  008841010000            add      byte ptr [eax + 0x141], cl     
  0x0106B6CE  56                      push     esi                            
  0x0106B6CF  00890b000003            add      byte ptr [ecx + 0x300000b], cl 
  0x0106B6D5  0020                    add      byte ptr [eax], ah             
  0x0106B6D7  0002                    add      byte ptr [edx], al             
  0x0106B6D9  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106B6DA  0500884101              add      eax, 0x1418800                 
  0x0106B6DF  0000                    add      byte ptr [eax], al             
  0x0106B6E2  56                      push     esi                            
  0x0106B6E3  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x0106B6E6  0000                    add      byte ptr [eax], al             
  0x0106B6E8  854201                  test     dword ptr [edx + 1], eax       
  0x0106B6EB  0007                    add      byte ptr [edi], al             
  0x0106B6ED  2405                    and      al, 5                          
  0x0106B6EF  008841010000            add      byte ptr [eax + 0x141], cl     
  0x0106B6F6  56                      push     esi                            
  0x0106B6F7  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106B6FA  0000                    add      byte ptr [eax], al             
  0x0106B6FC  03f4                    add      esi, esp                       
  0x0106B6FE  44                      inc      esp                            
  0x0106B6FF  000400                  add      byte ptr [eax + eax], al       
  0x0106B702  0000                    add      byte ptr [eax], al             
  0x0106B704  48                      dec      eax                            
  0x0106B705  2a20                    sub      ah, byte ptr [eax]             
  0x0106B707  0000                    add      byte ptr [eax], al             
  0x0106B70A  44                      inc      esp                            
  0x0106B70B  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x0106B711  c406                    les      eax, ptr [esi]                 
  0x0106B713  0002                    add      byte ptr [edx], al             
  0x0106B715  0000                    add      byte ptr [eax], al             
  0x0106B717  008842010000            add      byte ptr [eax + 0x142], cl     
  0x0106B71E  56                      push     esi                            
  0x0106B71F  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x0106B722  0000                    add      byte ptr [eax], al             
  0x0106B724  0300                    add      eax, dword ptr [eax]           
  0x0106B726  2000                    and      byte ptr [eax], al             
  0x0106B728  02a40500884101          add      ah, byte ptr [ebp + eax + 0x1418800] 
  0x0106B72F  0000                    add      byte ptr [eax], al             
  0x0106B731  f4                      hlt                                     
  0x0106B732  56                      push     esi                            
  0x0106B733  008a0b000000            add      byte ptr [edx + 0xb], cl       
  0x0106B739  002400                  add      byte ptr [eax + eax], ah       
  0x0106B73C  40                      inc      eax                            
  0x0106B73D  0020                    add      byte ptr [eax], ah             
  0x0106B73F  0000                    add      byte ptr [eax], al             
  0x0106B741  90                      nop                                     
  0x0106B742  2100                    and      dword ptr [eax], eax           
  0x0106B744  00f0                    add      al, dh                         
  0x0106B746  44                      inc      esp                            
  0x0106B747  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x0106B74D  c406                    les      eax, ptr [esi]                 
  0x0106B74F  0006                    add      byte ptr [esi], al             
  0x0106B751  0000                    add      byte ptr [eax], al             
  0x0106B753  0000                    add      byte ptr [eax], al             
  0x0106B755  d85600                  fcom     dword ptr [esi]                
  0x0106B758  0300                    add      eax, dword ptr [eax]           
  0x0106B75A  2000                    and      byte ptr [eax], al             
  0x0106B75C  02a40500884601          add      ah, byte ptr [ebp + eax + 0x1468800] 
  0x0106B763  0000                    add      byte ptr [eax], al             
  0x0106B765  0000                    add      byte ptr [eax], al             
  0x0106B767  0000                    add      byte ptr [eax], al             
  0x0106B769  f4                      hlt                                     
  0x0106B76A  60                      pushal                                  
  0x0106B76B  008a0b000000            add      byte ptr [edx + 0xb], cl       
  0x0106B771  f4                      hlt                                     
  0x0106B772  61                      popal                                   
  0x0106B773  00910b000000            add      byte ptr [ecx + 0xb], dl       
  0x0106B779  f4                      hlt                                     
  0x0106B77A  46                      inc      esi                            
  0x0106B77B  0007                    add      byte ptr [edi], al             
  0x0106B77D  0000                    add      byte ptr [eax], al             
  0x0106B77F  0000                    add      byte ptr [eax], al             
  0x0106B782  44                      inc      esp                            
  0x0106B783  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x0106B789  c406                    les      eax, ptr [esi]                 
  0x0106B78B  000a                    add      byte ptr [edx], cl             
  0x0106B78D  0000                    add      byte ptr [eax], al             
  0x0106B78F  0000                    add      byte ptr [eax], al             
  0x0106B791  d85600                  fcom     dword ptr [esi]                
  0x0106B794  03d9                    add      ebx, ecx                       
  0x0106B796  44                      inc      esp                            
  0x0106B797  0006                    add      byte ptr [esi], al             
  0x0106B799  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106B79A  0500884401              add      eax, 0x1448800                 
  0x0106B79F  00d0                    add      al, dl                         
  0x0106B7A1  0020                    add      byte ptr [eax], ah             
  0x0106B7A3  002e                    add      byte ptr [esi], ch             
  0x0106B7A5  1d0c001800              sbb      eax, 0x18000c                  
  0x0106B7AA  2000                    and      byte ptr [eax], al             
  0x0106B7AC  884201                  mov      byte ptr [edx + 1], al         
  0x0106B7AF  0000                    add      byte ptr [eax], al             
  0x0106B7B1  0000                    add      byte ptr [eax], al             
  0x0106B7B3  0000                    add      byte ptr [eax], al             
  0x0106B7B6  56                      push     esi                            
  0x0106B7B7  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x0106B7BA  0000                    add      byte ptr [eax], al             
  0x0106B7BC  0300                    add      eax, dword ptr [eax]           
  0x0106B7BE  2000                    and      byte ptr [eax], al             
  0x0106B7C0  08a4050000f056          or       byte ptr [ebp + eax + 0x56f00000], ah 
  0x0106B7C7  008f0b000003            add      byte ptr [edi + 0x300000b], cl 
  0x0106B7CD  f4                      hlt                                     
  0x0106B7CE  44                      inc      esp                            
  0x0106B7CF  000e                    add      byte ptr [esi], cl             
  0x0106B7D1  0000                    add      byte ptr [eax], al             
  0x0106B7D3  0003                    add      byte ptr [ebx], al             
  0x0106B7D5  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106B7D6  0500884401              add      eax, 0x1448800                 
  0x0106B7DB  004800                  add      byte ptr [eax], cl             
  0x0106B7DE  2000                    and      byte ptr [eax], al             
  0x0106B7E0  884101                  mov      byte ptr [ecx + 1], al         
  0x0106B7E3  0000                    add      byte ptr [eax], al             
  0x0106B7E6  56                      push     esi                            
  0x0106B7E7  00900b000003            add      byte ptr [eax + 0x300000b], dl 
  0x0106B7ED  0020                    add      byte ptr [eax], ah             
  0x0106B7EF  0006                    add      byte ptr [esi], al             
  0x0106B7F1  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106B7F2  0500884201              add      eax, 0x1428800                 
  0x0106B7F7  008842010088            add      byte ptr [eax - 0x77fffebe], cl 
  0x0106B7FD  42                      inc      edx                            
  0x0106B7FE  0100                    add      dword ptr [eax], eax           
  0x0106B800  884201                  mov      byte ptr [edx + 1], al         
  0x0106B803  008843010088            add      byte ptr [eax - 0x77fffebd], cl 
  0x0106B809  41                      inc      ecx                            
  0x0106B80A  0100                    add      dword ptr [eax], eax           
  0x0106B80C  00f0                    add      al, dh                         
  0x0106B80E  56                      push     esi                            
  0x0106B80F  006f0b                  add      byte ptr [edi + 0xb], ch       
  0x0106B812  0000                    add      byte ptr [eax], al             
  0x0106B814  0300                    add      eax, dword ptr [eax]           
  0x0106B816  2000                    and      byte ptr [eax], al             
  0x0106B818  0e                      push     cs                             
  0x0106B819  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106B81A  0500884601              add      eax, 0x1468800                 
  0x0106B81F  0000                    add      byte ptr [eax], al             
  0x0106B822  44                      inc      esp                            
  0x0106B823  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x0106B829  c406                    les      eax, ptr [esi]                 
  0x0106B82B  0003                    add      byte ptr [ebx], al             
  0x0106B82D  0000                    add      byte ptr [eax], al             
  0x0106B82F  008844010088            add      byte ptr [eax - 0x77fffebc], cl 
  0x0106B835  43                      inc      ebx                            
  0x0106B836  0100                    add      dword ptr [eax], eax           
  0x0106B838  00f0                    add      al, dh                         
  0x0106B83A  56                      push     esi                            
  0x0106B83B  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x0106B83E  0000                    add      byte ptr [eax], al             
  0x0106B840  0300                    add      eax, dword ptr [eax]           
  0x0106B842  2000                    and      byte ptr [eax], al             
  0x0106B844  03a40500884401          add      esp, dword ptr [ebp + eax + 0x1448800] 
  0x0106B84B  008843010088            add      byte ptr [eax - 0x77fffebd], cl 
  0x0106B851  41                      inc      ecx                            
  0x0106B852  0100                    add      dword ptr [eax], eax           
  0x0106B854  884101                  mov      byte ptr [ecx + 1], al         
  0x0106B857  001b                    add      byte ptr [ebx], bl             
  0x0106B859  e721                    out      0x21, eax                      
  0x0106B85B  0000                    add      byte ptr [eax], al             
  0x0106B85E  56                      push     esi                            
  0x0106B85F  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106B862  0000                    add      byte ptr [eax], al             
  0x0106B864  c54001                  lds      eax, ptr [eax + 1]             
  0x0106B867  0003                    add      byte ptr [ebx], al             
  0x0106B869  0000                    add      byte ptr [eax], al             
  0x0106B86B  004210                  add      byte ptr [edx + 0x10], al      
  0x0106B86E  0d000d0000              or       eax, 0xd00                     
  0x0106B873  0079e7                  add      byte ptr [ecx - 0x19], bh      
  0x0106B876  2100                    and      dword ptr [eax], eax           
  0x0106B878  884901                  mov      byte ptr [ecx + 1], cl         
  0x0106B87B  0079e7                  add      byte ptr [ecx - 0x19], bh      
  0x0106B87E  2100                    and      dword ptr [eax], eax           
  0x0106B880  884101                  mov      byte ptr [ecx + 1], al         
  0x0106B883  008841010000            add      byte ptr [eax + 0x141], cl     
  0x0106B88A  56                      push     esi                            
  0x0106B88B  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106B88E  0000                    add      byte ptr [eax], al             
  0x0106B890  c54001                  lds      eax, ptr [eax + 1]             
  0x0106B893  0003                    add      byte ptr [ebx], al             
  0x0106B895  0000                    add      byte ptr [eax], al             
  0x0106B897  0002                    add      byte ptr [edx], al             
  0x0106B899  2405                    and      al, 5                          
  0x0106B89B  00886f010088            add      byte ptr [eax - 0x77fffe91], cl 
  0x0106B8A1  47                      inc      edi                            
  0x0106B8A2  0100                    add      dword ptr [eax], eax           
  0x0106B8A5  1e                      push     ds                             
  0x0106B8A6  0c00                    or       al, 0                          
  0x0106B8A8  007055                  add      byte ptr [eax + 0x55], dh      
  0x0106B8AB  00700b                  add      byte ptr [eax + 0xb], dh       
  0x0106B8AE  0000                    add      byte ptr [eax], al             
  0x0106B8B0  871e                    xchg     dword ptr [esi], ebx           
  0x0106B8B2  0c00                    or       al, 0                          
  0x0106B8B4  79e4                    jns      0x106b89a                      
  0x0106B8B6  2100                    and      dword ptr [eax], eax           
  0x0106B8B8  48                      dec      eax                            
  0x0106B8B9  0020                    add      byte ptr [eax], ah             
  0x0106B8BB  0000                    add      byte ptr [eax], al             
  0x0106B8BD  7055                    jo       0x106b914                      
  0x0106B8BF  00710b                  add      byte ptr [ecx + 0xb], dh       
  0x0106B8C2  0000                    add      byte ptr [eax], al             
  0x0106B8C4  00f0                    add      al, dh                         
  0x0106B8C6  56                      push     esi                            
  0x0106B8C7  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106B8CA  0000                    add      byte ptr [eax], al             
  0x0106B8CC  0300                    add      eax, dword ptr [eax]           
  0x0106B8CE  2000                    and      byte ptr [eax], al             
  0x0106B8D0  07                      pop      es                             
  0x0106B8D1  2405                    and      al, 5                          
  0x0106B8D3  001b                    add      byte ptr [ebx], bl             
  0x0106B8D5  0020                    add      byte ptr [eax], ah             
  0x0106B8D7  008841010088            add      byte ptr [eax - 0x77fffebf], cl 
  0x0106B8DD  41                      inc      ecx                            
  0x0106B8DE  0100                    add      dword ptr [eax], eax           
  0x0106B8E0  885001                  mov      byte ptr [eax + 1], dl         
  0x0106B8E3  0000                    add      byte ptr [eax], al             
  0x0106B8E5  7055                    jo       0x106b93c                      
  0x0106B8E7  00530b                  add      byte ptr [ebx + 0xb], dl       
  0x0106B8EA  0000                    add      byte ptr [eax], al             
  0x0106B8EC  00f0                    add      al, dh                         
  0x0106B8EE  56                      push     esi                            
  0x0106B8EF  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106B8F2  0000                    add      byte ptr [eax], al             
  0x0106B8F4  0300                    add      eax, dword ptr [eax]           
  0x0106B8F6  2000                    and      byte ptr [eax], al             
  0x0106B8F8  8c24050000f057          mov      word ptr [eax + 0x57f00000], fs 
  0x0106B8FF  00510b                  add      byte ptr [ecx + 0xb], dl       
  0x0106B902  0000                    add      byte ptr [eax], al             
  0x0106B904  00f0                    add      al, dh                         
  0x0106B906  44                      inc      esp                            
  0x0106B907  00530b                  add      byte ptr [ebx + 0xb], dl       
  0x0106B90A  0000                    add      byte ptr [eax], al             
  0x0106B90C  48                      dec      eax                            
  0x0106B90D  0020                    add      byte ptr [eax], ah             
  0x0106B90F  0000                    add      byte ptr [eax], al             
  0x0106B912  44                      inc      esp                            
  0x0106B913  009a0b000000            add      byte ptr [edx + 0xb], bl       
  0x0106B919  f4                      hlt                                     
  0x0106B91A  46                      inc      esi                            
  0x0106B91B  0008                    add      byte ptr [eax], cl             
  0x0106B91D  0000                    add      byte ptr [eax], al             
  0x0106B91F  00d0                    add      al, dl                         
  0x0106B921  0020                    add      byte ptr [eax], ah             
  0x0106B923  0000                    add      byte ptr [eax], al             
  0x0106B925  0e                      push     cs                             
  0x0106B926  2100                    and      dword ptr [eax], eax           
  0x0106B928  1400                    adc      al, 0                          
  0x0106B92A  2000                    and      byte ptr [eax], al             
  0x0106B92C  007054                  add      byte ptr [eax + 0x54], dh      
  0x0106B92F  00520b                  add      byte ptr [edx + 0xb], dl       
  0x0106B932  0000                    add      byte ptr [eax], al             
  0x0106B934  00f0                    add      al, dh                         
  0x0106B936  56                      push     esi                            
  0x0106B937  00530b                  add      byte ptr [ebx + 0xb], dl       
  0x0106B93A  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x0106B8E5 (cond_jump)
  0x0106B93C  00f0                    add      al, dh                         
  0x0106B93E  44                      inc      esp                            
  0x0106B93F  009f0b000045            add      byte ptr [edi + 0x4500000b], bl 
  0x0106B945  0020                    add      byte ptr [eax], ah             
  0x0106B947  00857405001b            add      byte ptr [ebp + 0x1b000574], al 
  0x0106B94D  f4                      hlt                                     
  0x0106B94E  44                      inc      esp                            
  0x0106B94F  005555                  add      byte ptr [ebp + 0x55], dl      
  0x0106B952  150000f056              adc      eax, 0x56f00000                
  0x0106B957  00520b                  add      byte ptr [edx + 0xb], dl       
  0x0106B95A  0000                    add      byte ptr [eax], al             
  0x0106B95C  c44001                  les      eax, ptr [eax + 1]             
  0x0106B95F  002f                    add      byte ptr [edi], ch             
  0x0106B961  0000                    add      byte ptr [eax], al             
  0x0106B963  0000                    add      byte ptr [eax], al             
  0x0106B965  8521                    test     dword ptr [ecx], esp           
  0x0106B967  00a800200000            add      byte ptr [eax + 0x2000], ch    
  0x0106B96D  af                      scasd    eax, dword ptr es:[edi]        
  0x0106B96E  2100                    and      dword ptr [eax], eax           
  0x0106B970  00f0                    add      al, dh                         
  0x0106B972  44                      inc      esp                            
  0x0106B973  00710b                  add      byte ptr [ecx + 0xb], dh       
  0x0106B976  0000                    add      byte ptr [eax], al             
  0x0106B978  4d                      dec      ebp                            
  0x0106B979  0020                    add      byte ptr [eax], ah             
  0x0106B97B  0058f4                  add      byte ptr [eax - 0xc], bl       
  0x0106B97E  050000a521              add      eax, 0x21a50000                
  0x0106B983  0000                    add      byte ptr [eax], al             
  0x0106B985  f4                      hlt                                     
  0x0106B986  44                      inc      esp                            
  0x0106B987  0006                    add      byte ptr [esi], al             
  0x0106B989  0000                    add      byte ptr [eax], al             
  0x0106B98B  00a00020002e            add      byte ptr [eax + 0x2e002000], ah 
  0x0106B991  1d0c0036f0              sbb      eax, 0xf036000c                
  0x0106B996  44                      inc      esp                            
  0x0106B997  00520b                  add      byte ptr [edx + 0xb], dl       
  0x0106B99A  0000                    add      byte ptr [eax], al             
  0x0106B99C  40                      inc      eax                            
  0x0106B99D  0020                    add      byte ptr [eax], ah             
  0x0106B99F  00c4                    add      ah, al                         
  0x0106B9A1  40                      inc      eax                            
  0x0106B9A2  0100                    add      dword ptr [eax], eax           
  0x0106B9A4  2f                      das                                     
  0x0106B9A5  0000                    add      byte ptr [eax], al             
  0x0106B9A7  0000                    add      byte ptr [eax], al             
  0x0106B9AA  2100                    and      dword ptr [eax], eax           
  0x0106B9AC  c8400100                enter    0x140, 0                       
  0x0106B9B0  0100                    add      dword ptr [eax], eax           
  0x0106B9B2  0000                    add      byte ptr [eax], al             
  0x0106B9B4  00f4                    add      ah, dh                         
  0x0106B9B6  56                      push     esi                            
  0x0106B9B7  00680b                  add      byte ptr [eax + 0xb], ch       
  0x0106B9BA  0000                    add      byte ptr [eax], al             
  0x0106B9BC  0000                    add      byte ptr [eax], al             
  0x0106B9BE  2400                    and      al, 0                          
  0x0106B9C0  40                      inc      eax                            
  0x0106B9C1  0020                    add      byte ptr [eax], ah             
  0x0106B9C3  0000                    add      byte ptr [eax], al             
  0x0106B9C5  90                      nop                                     
  0x0106B9C6  2100                    and      dword ptr [eax], eax           
  0x0106B9C8  00f8                    add      al, bh                         
  0x0106B9CA  2000                    and      byte ptr [eax], al             
  0x0106B9CC  10d8                    adc      al, bl                         
  0x0106B9CE  06                      push     es                             
  0x0106B9CF  0002                    add      byte ptr [edx], al             
  0x0106B9D1  0000                    add      byte ptr [eax], al             
  0x0106B9D3  0000                    add      byte ptr [eax], al             
  0x0106B9D5  58                      pop      eax                            
  0x0106B9D6  57                      push     edi                            
  0x0106B9D7  00cc                    add      ah, cl                         
  0x0106B9D9  40                      inc      eax                            
  0x0106B9DA  0100                    add      dword ptr [eax], eax           
  0x0106B9DC  0100                    add      dword ptr [eax], eax           
  0x0106B9DE  0000                    add      byte ptr [eax], al             
  0x0106B9E0  00f4                    add      ah, dh                         
  0x0106B9E2  56                      push     esi                            
  0x0106B9E3  0006                    add      byte ptr [esi], al             
  0x0106B9E5  0000                    add      byte ptr [eax], al             
  0x0106B9E7  00740020                add      byte ptr [eax + eax + 0x20], dh 
  0x0106B9EB  0003                    add      byte ptr [ebx], al             
  0x0106B9ED  0020                    add      byte ptr [eax], ah             
  0x0106B9EF  0005f4050000            add      byte ptr [0x5f4], al           
  0x0106B9F5  d821                    fsub     dword ptr [ecx]                
  0x0106B9F7  0010                    add      byte ptr [eax], dl             
  0x0106B9F9  d806                    fadd     dword ptr [esi]                
  0x0106B9FB  0002                    add      byte ptr [edx], al             
  0x0106B9FD  0000                    add      byte ptr [eax], al             
  0x0106B9FF  0000                    add      byte ptr [eax], al             
  0x0106BA01  58                      pop      eax                            
  0x0106BA02  57                      push     edi                            
  0x0106BA03  0000                    add      byte ptr [eax], al             
  0x0106BA05  f4                      hlt                                     
  0x0106BA06  56                      push     esi                            
  0x0106BA07  00680b                  add      byte ptr [eax + 0xb], ch       
  0x0106BA0A  0000                    add      byte ptr [eax], al             
  0x0106BA0C  00f4                    add      ah, dh                         
  0x0106BA0E  44                      inc      esp                            
  0x0106BA0F  0003                    add      byte ptr [ebx], al             
  0x0106BA11  0000                    add      byte ptr [eax], al             
  0x0106BA13  004000                  add      byte ptr [eax], al             
  0x0106BA16  2000                    and      byte ptr [eax], al             
  0x0106BA18  0090210000e0            add      byte ptr [eax - 0x1fffffdf], dl 
  0x0106BA1E  56                      push     esi                            
  0x0106BA1F  00806f010000            add      byte ptr [eax + 0x16f], al     
  0x0106BA25  60                      pushal                                  
  0x0106BA26  56                      push     esi                            
  0x0106BA27  0000                    add      byte ptr [eax], al             
  0x0106BA29  f4                      hlt                                     
  0x0106BA2A  56                      push     esi                            
  0x0106BA2B  00680b                  add      byte ptr [eax + 0xb], ch       
  0x0106BA2E  0000                    add      byte ptr [eax], al             
  0x0106BA30  0000                    add      byte ptr [eax], al             
  0x0106BA32  2400                    and      al, 0                          
  0x0106BA34  40                      inc      eax                            
  0x0106BA35  0020                    add      byte ptr [eax], ah             
  0x0106BA37  0000                    add      byte ptr [eax], al             
  0x0106BA39  90                      nop                                     
  0x0106BA3A  2100                    and      dword ptr [eax], eax           
  0x0106BA3C  00f0                    add      al, dh                         
  0x0106BA3E  7000                    jo       0x106ba40                      
                                        ; XREF: 0x0106BA3E (cond_jump)
  0x0106BA40  40                      inc      eax                            
  0x0106BA41  0b00                    or       eax, dword ptr [eax]           
  0x0106BA43  0000                    add      byte ptr [eax], al             
  0x0106BA45  e8560000f0              call     0xf106baa0                     
  0x0106BA4A  44                      inc      esp                            
  0x0106BA4B  00710b                  add      byte ptr [ecx + 0xb], dh       
  0x0106BA4E  0000                    add      byte ptr [eax], al             
  0x0106BA50  44                      inc      esp                            
  0x0106BA51  0020                    add      byte ptr [eax], ah             
  0x0106BA53  0000                    add      byte ptr [eax], al             
  0x0106BA55  6856000c00              push     0xc0056                        
  0x0106BA5A  0000                    add      byte ptr [eax], al             
  0x0106BA5C  00f4                    add      ah, dh                         
  0x0106BA5E  44                      inc      esp                            
  0x0106BA5F  0001                    add      byte ptr [ecx], al             
  0x0106BA61  0000                    add      byte ptr [eax], al             
  0x0106BA63  0000                    add      byte ptr [eax], al             
  0x0106BA65  7044                    jo       0x106baab                      
  0x0106BA67  00960b00000c            add      byte ptr [esi + 0xc00000b], dl 
  0x0106BA6D  0000                    add      byte ptr [eax], al             
  0x0106BA6F  0080100d0023            add      byte ptr [eax + 0x23000d10], al 
  0x0106BA75  0000                    add      byte ptr [eax], al             
  0x0106BA77  0003                    add      byte ptr [ebx], al             
  0x0106BA79  0020                    add      byte ptr [eax], ah             
  0x0106BA7B  001b                    add      byte ptr [ebx], bl             
  0x0106BA7D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106BA7E  050080100d              add      eax, 0xd108000                 
  0x0106BA83  00a2fdff0000            add      byte ptr [edx + 0xfffd], ah    
  0x0106BA89  f4                      hlt                                     
  0x0106BA8A  56                      push     esi                            
  0x0106BA8B  000500000000            add      byte ptr [0], al               
  0x0106BA92  44                      inc      esp                            
  0x0106BA93  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106BA96  0000                    add      byte ptr [eax], al             
  0x0106BA98  45                      inc      ebp                            
  0x0106BA99  0020                    add      byte ptr [eax], ah             
  0x0106BA9B  0017                    add      byte ptr [edi], dl             
  0x0106BA9D  f4                      hlt                                     
  0x0106BA9E  050000f456              add      eax, 0x56f40000                
  0x0106BAA3  00680b                  add      byte ptr [eax + 0xb], ch       
  0x0106BAA6  0000                    add      byte ptr [eax], al             
  0x0106BAA8  00f0                    add      al, dh                         
  0x0106BAAA  44                      inc      esp                            
                                        ; XREF: 0x0106BA65 (cond_jump)
  0x0106BAAB  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106BAAE  0000                    add      byte ptr [eax], al             
  0x0106BAB0  40                      inc      eax                            
  0x0106BAB1  0020                    add      byte ptr [eax], ah             
  0x0106BAB3  00c0                    add      al, al                         
  0x0106BAB5  40                      inc      eax                            
  0x0106BAB6  0100                    add      dword ptr [eax], eax           
  0x0106BAB8  0100                    add      dword ptr [eax], eax           
  0x0106BABA  0000                    add      byte ptr [eax], al             
  0x0106BABC  00d0                    add      al, dl                         
  0x0106BABE  2100                    and      dword ptr [eax], eax           
  0x0106BAC0  00d0                    add      al, dl                         
  0x0106BAC2  56                      push     esi                            
  0x0106BAC3  0000                    add      byte ptr [eax], al             
  0x0106BAC5  d8440040                fadd     dword ptr [eax + eax + 0x40]   
  0x0106BAC9  0020                    add      byte ptr [eax], ah             
  0x0106BACB  0000                    add      byte ptr [eax], al             
  0x0106BACE  44                      inc      esp                            
  0x0106BACF  007a0b                  add      byte ptr [edx + 0xb], bh       
  0x0106BAD2  0000                    add      byte ptr [eax], al             
  0x0106BAD4  44                      inc      esp                            
  0x0106BAD6  45                      inc      ebp                            
  0x0106BAD7  00a40400006400          add      byte ptr [esp + eax + 0x640000], ah 
  0x0106BADE  2000                    and      byte ptr [eax], al             
  0x0106BAE0  006056                  add      byte ptr [eax + 0x56], ah      
  0x0106BAE3  00050c050080            add      byte ptr [0x8000050c], al      
  0x0106BAE9  100d00580100            adc      byte ptr [0x15800], cl         
  0x0106BAEF  0080100d0086            add      byte ptr [eax - 0x79fff2f0], al 
  0x0106BAF5  fd                      std                                     
  0x0106BAF6  ff00                    inc      dword ptr [eax]                
  0x0106BAF8  0c00                    or       al, 0                          
  0x0106BAFA  0000                    add      byte ptr [eax], al             
  0x0106BAFC  00f4                    add      ah, dh                         
  0x0106BAFE  45                      inc      ebp                            
  0x0106BAFF  0090ffff0000            add      byte ptr [eax + 0xffff], dl    
  0x0106BB05  7045                    jo       0x106bb4c                      
  0x0106BB07  009f04000080            add      byte ptr [edi - 0x7ffffffc], bl 
  0x0106BB0D  100d007c0000            adc      byte ptr [0x7c00], cl          
  0x0106BB13  0000                    add      byte ptr [eax], al             
  0x0106BB15  f4                      hlt                                     
  0x0106BB16  44                      inc      esp                            
  0x0106BB17  0008                    add      byte ptr [eax], cl             
  0x0106BB19  0000                    add      byte ptr [eax], al             
  0x0106BB1B  0000                    add      byte ptr [eax], al             
  0x0106BB1D  7044                    jo       0x106bb63                      
  0x0106BB1F  009e04000000            add      byte ptr [esi + 4], bl         
  0x0106BB25  002400                  add      byte ptr [eax + eax], ah       
  0x0106BB28  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106BB2B  00b504000000            add      byte ptr [ebp + 4], dh         
  0x0106BB32  50                      push     eax                            
  0x0106BB33  009e0400000a            add      byte ptr [esi + 0xa000004], bl 
  0x0106BB39  0000                    add      byte ptr [eax], al             
  0x0106BB3B  0000                    add      byte ptr [eax], al             
  0x0106BB3D  7050                    jo       0x106bb8f                      
  0x0106BB3F  009e04000080            add      byte ptr [esi - 0x7ffffffc], bl 
  0x0106BB45  100d00870000            adc      byte ptr [0x8700], cl          
  0x0106BB4B  000b                    add      byte ptr [ebx], cl             
  0x0106BB4D  0020                    add      byte ptr [eax], ah             
  0x0106BB4F  0009                    add      byte ptr [ecx], cl             
  0x0106BB51  94                      xchg     esp, eax                       
  0x0106BB52  050000f444              add      eax, 0x44f40000                
  0x0106BB57  0001                    add      byte ptr [ecx], al             
  0x0106BB59  0000                    add      byte ptr [eax], al             
  0x0106BB5B  0000                    add      byte ptr [eax], al             
  0x0106BB5D  7044                    jo       0x106bba3                      
  0x0106BB5F  00b504000000            add      byte ptr [ebp + 4], dh         
  0x0106BB66  44                      inc      esp                            
  0x0106BB67  009f04000000            add      byte ptr [edi + 4], bl         
  0x0106BB6D  7044                    jo       0x106bbb3                      
  0x0106BB6F  00b604000000            add      byte ptr [esi + 4], dh         
  0x0106BB76  56                      push     esi                            
  0x0106BB77  00b504000003            add      byte ptr [ebp + 0x3000004], dh 
  0x0106BB7D  0020                    add      byte ptr [eax], ah             
  0x0106BB7F  000f                    add      byte ptr [edi], cl             
  0x0106BB81  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106BB82  050000f456              add      eax, 0x56f40000                
  0x0106BB87  0010                    add      byte ptr [eax], dl             
  0x0106BB89  0000                    add      byte ptr [eax], al             
  0x0106BB8B  0000                    add      byte ptr [eax], al             
  0x0106BB8D  c421                    les      esp, ptr [ecx]                 
                                        ; XREF: 0x0106BB3D (cond_jump)
  0x0106BB8F  0000                    add      byte ptr [eax], al             
  0x0106BB91  7056                    jo       0x106bbe9                      
  0x0106BB93  00a004000000            add      byte ptr [eax + 4], ah         
  0x0106BB9A  56                      push     esi                            
  0x0106BB9B  009f04000000            add      byte ptr [edi + 4], bl         
  0x0106BBA1  7056                    jo       0x106bbf9                      
                                        ; XREF: 0x0106BB5D (cond_jump)
  0x0106BBA3  00a104000040            add      byte ptr [ecx + 0x40000004], ah 
  0x0106BBA9  0020                    add      byte ptr [eax], ah             
  0x0106BBAB  0022                    add      byte ptr [edx], ah             
  0x0106BBAD  0020                    add      byte ptr [eax], ah             
  0x0106BBAF  0000                    add      byte ptr [eax], al             
  0x0106BBB1  7056                    jo       0x106bc09                      
                                        ; XREF: 0x0106BB6D (cond_jump)
  0x0106BBB3  009f0400000e            add      byte ptr [edi + 0xe000004], bl 
  0x0106BBB9  0c05                    or       al, 5                          
  0x0106BBBB  0000                    add      byte ptr [eax], al             
  0x0106BBBD  f4                      hlt                                     
  0x0106BBBE  56                      push     esi                            
  0x0106BBBF  0010                    add      byte ptr [eax], dl             
  0x0106BBC2  ff00                    inc      dword ptr [eax]                
  0x0106BBC4  00c4                    add      ah, al                         
  0x0106BBC6  2100                    and      dword ptr [eax], eax           
  0x0106BBC8  007056                  add      byte ptr [eax + 0x56], dh      
  0x0106BBCB  00a104000000            add      byte ptr [ecx + 4], ah         
  0x0106BBD2  56                      push     esi                            
  0x0106BBD3  009f04000000            add      byte ptr [edi + 4], bl         
  0x0106BBD9  7056                    jo       0x106bc31                      
  0x0106BBDB  00a004000040            add      byte ptr [eax + 0x40000004], ah 
  0x0106BBE1  0020                    add      byte ptr [eax], ah             
  0x0106BBE3  0022                    add      byte ptr [edx], ah             
  0x0106BBE5  0020                    add      byte ptr [eax], ah             
  0x0106BBE7  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x0106BB91 (cond_jump)
  0x0106BBE9  7056                    jo       0x106bc41                      
  0x0106BBEB  009f04000080            add      byte ptr [edi - 0x7ffffffc], bl 
  0x0106BBF1  100d00430000            adc      byte ptr [0x4300], cl          
  0x0106BBF7  0080100d005a            add      byte ptr [eax + 0x5a000d10], al 
  0x0106BBFD  0000                    add      byte ptr [eax], al             
  0x0106BBFF  000b                    add      byte ptr [ebx], cl             
  0x0106BC01  0020                    add      byte ptr [eax], ah             
  0x0106BC03  000e                    add      byte ptr [esi], cl             
  0x0106BC05  94                      xchg     esp, eax                       
  0x0106BC06  050000f044              add      eax, 0x44f00000                
  0x0106BC0B  009f04000000            add      byte ptr [edi + 4], bl         
  0x0106BC11  7044                    jo       0x106bc57                      
  0x0106BC13  00a104000000            add      byte ptr [ecx + 4], ah         
  0x0106BC19  f4                      hlt                                     
  0x0106BC1A  44                      inc      esp                            
  0x0106BC1B  0001                    add      byte ptr [ecx], al             
  0x0106BC1D  0000                    add      byte ptr [eax], al             
  0x0106BC1F  0000                    add      byte ptr [eax], al             
  0x0106BC21  7044                    jo       0x106bc67                      
  0x0106BC23  00b504000000            add      byte ptr [ebp + 4], dh         
  0x0106BC2A  44                      inc      esp                            
  0x0106BC2B  009f04000000            add      byte ptr [edi + 4], bl         
                                        ; XREF: 0x0106BBD9 (cond_jump)
  0x0106BC31  7044                    jo       0x106bc77                      
  0x0106BC33  00b604000005            add      byte ptr [esi + 0x5000004], dh 
  0x0106BC39  0c05                    or       al, 5                          
  0x0106BC3B  0000                    add      byte ptr [eax], al             
  0x0106BC3E  44                      inc      esp                            
  0x0106BC3F  009f04000000            add      byte ptr [edi + 4], bl         
  0x0106BC45  7044                    jo       0x106bc8b                      
  0x0106BC47  00a004000000            add      byte ptr [eax + 4], ah         
  0x0106BC4E  56                      push     esi                            
  0x0106BC4F  00a004000000            add      byte ptr [eax + 4], ah         
  0x0106BC56  44                      inc      esp                            
                                        ; XREF: 0x0106BC11 (cond_jump)
  0x0106BC57  00a104000044            add      byte ptr [ecx + 0x44000004], ah 
  0x0106BC5E  2100                    and      dword ptr [eax], eax           
  0x0106BC60  c54001                  lds      eax, ptr [eax + 1]             
  0x0106BC63  0001                    add      byte ptr [ecx], al             
  0x0106BC65  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x0106BC21 (cond_jump)
  0x0106BC67  0008                    add      byte ptr [eax], cl             
  0x0106BC69  2405                    and      al, 5                          
  0x0106BC6B  0080100d0028            add      byte ptr [eax + 0x28000d10], al 
  0x0106BC71  0100                    add      dword ptr [eax], eax           
  0x0106BC73  0000                    add      byte ptr [eax], al             
  0x0106BC75  f4                      hlt                                     
  0x0106BC76  44                      inc      esp                            
                                        ; XREF: 0x0106BC31 (cond_jump)
  0x0106BC77  0001                    add      byte ptr [ecx], al             
  0x0106BC79  0000                    add      byte ptr [eax], al             
  0x0106BC7B  0000                    add      byte ptr [eax], al             
  0x0106BC7D  7044                    jo       0x106bcc3                      
  0x0106BC7F  00b50400001b            add      byte ptr [ebp + 0x1b000004], dh 
  0x0106BC85  0c05                    or       al, 5                          
  0x0106BC87  005100                  add      byte ptr [ecx], dl             
  0x0106BC8A  2000                    and      byte ptr [eax], al             
  0x0106BC8C  40                      inc      eax                            
  0x0106BC8D  0020                    add      byte ptr [eax], ah             
  0x0106BC8F  0022                    add      byte ptr [edx], ah             
  0x0106BC91  0020                    add      byte ptr [eax], ah             
  0x0106BC93  004500                  add      byte ptr [ebp], al             
  0x0106BC96  2000                    and      byte ptr [eax], al             
  0x0106BC98  0474                    add      al, 0x74                       
  0x0106BC9A  0500008e20              add      eax, 0x208e0000                
  0x0106BC9F  008041010005            add      byte ptr [eax + 0x5000141], al 
  0x0106BCA5  0c05                    or       al, 5                          
  0x0106BCA7  005500                  add      byte ptr [ebp], dl             
  0x0106BCAA  2000                    and      byte ptr [eax], al             
  0x0106BCAC  0394050000ce20          add      edx, dword ptr [ebp + eax + 0x20ce0000] 
  0x0106BCB3  00844101000070          add      byte ptr [ecx + eax*2 + 0x70000001], al 
  0x0106BCBA  54                      push     esp                            
  0x0106BCBB  009f04000000            add      byte ptr [edi + 4], bl         
  0x0106BCC2  56                      push     esi                            
                                        ; XREF: 0x0106BC7D (cond_jump)
  0x0106BCC3  009e04000084            add      byte ptr [esi - 0x7bfffffc], bl 
  0x0106BCC9  41                      inc      ecx                            
  0x0106BCCA  0100                    add      dword ptr [eax], eax           
  0x0106BCCC  007054                  add      byte ptr [eax + 0x54], dh      
  0x0106BCCF  009e04000087            add      byte ptr [esi - 0x78fffffc], bl 
  0x0106BCD5  7705                    ja       0x106bcdc                      
  0x0106BCD7  0000                    add      byte ptr [eax], al             
  0x0106BCDA  56                      push     esi                            
  0x0106BCDB  00b504000085            add      byte ptr [ebp - 0x7afffffc], dh 
  0x0106BCE1  41                      inc      ecx                            
  0x0106BCE2  0100                    add      dword ptr [eax], eax           
  0x0106BCE4  0324050080100d          add      esp, dword ptr [eax + 0xd108000] 
  0x0106BCEB  0009                    add      byte ptr [ecx], cl             
  0x0106BCED  0100                    add      dword ptr [eax], eax           
  0x0106BCEF  0000                    add      byte ptr [eax], al             
  0x0106BCF2  56                      push     esi                            
  0x0106BCF3  00b50400000c            add      byte ptr [ebp + 0xc000004], dh 
  0x0106BCF9  0000                    add      byte ptr [eax], al             
  0x0106BCFB  0000                    add      byte ptr [eax], al             
  0x0106BCFE  56                      push     esi                            
  0x0106BCFF  009f040000c0            add      byte ptr [edi - 0x3ffffffc], bl 
  0x0106BD05  40                      inc      eax                            
  0x0106BD06  0100                    add      dword ptr [eax], eax           
  0x0106BD08  f00000                  lock add byte ptr [eax], al             
  0x0106BD0B  0008                    add      byte ptr [eax], cl             
  0x0106BD0D  1c0c                    sbb      al, 0xc                        
  0x0106BD0F  0000                    add      byte ptr [eax], al             
  0x0106BD11  8421                    test     byte ptr [ecx], ah             
  0x0106BD13  0000                    add      byte ptr [eax], al             
  0x0106BD15  002c00                  add      byte ptr [eax + eax], ch       
  0x0106BD18  081d0c000086            or       byte ptr [0x8600000c], bl      
  0x0106BD1E  2100                    and      dword ptr [eax], eax           
  0x0106BD20  00f4                    add      ah, dh                         
  0x0106BD22  60                      pushal                                  
  0x0106BD23  00730b                  add      byte ptr [ebx + 0xb], dh       
  0x0106BD26  0000                    add      byte ptr [eax], al             
  0x0106BD28  00f4                    add      ah, dh                         
  0x0106BD2A  6200                    bound    eax, qword ptr [eax]           
  0x0106BD2C  790b                    jns      0x106bd39                      
  0x0106BD2E  0000                    add      byte ptr [eax], al             
  0x0106BD30  00f4                    add      ah, dh                         
  0x0106BD32  6400740b00              add      byte ptr fs:[ebx + ecx], dh    
  0x0106BD37  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x0106BD2C (cond_jump)
  0x0106BD39  053c0000f0              add      eax, 0xf000003c                
  0x0106BD3E  7000                    jo       0x106bd40                      
                                        ; XREF: 0x0106BD3E (cond_jump)
  0x0106BD40  97                      xchg     edi, eax                       
  0x0106BD41  0b00                    or       eax, dword ptr [eax]           
  0x0106BD43  0000                    add      byte ptr [eax], al             
  0x0106BD45  95                      xchg     ebp, eax                       
  0x0106BD46  2200                    and      al, byte ptr [eax]             
  0x0106BD48  005844                  add      byte ptr [eax + 0x44], bl      
  0x0106BD4B  0000                    add      byte ptr [eax], al             
  0x0106BD4D  5a                      pop      edx                            
  0x0106BD4E  46                      inc      esi                            
  0x0106BD4F  0010                    add      byte ptr [eax], dl             
  0x0106BD51  d806                    fadd     dword ptr [esi]                
  0x0106BD53  0002                    add      byte ptr [edx], al             
  0x0106BD55  0000                    add      byte ptr [eax], al             
  0x0106BD57  0000                    add      byte ptr [eax], al             
  0x0106BD59  5d                      pop      ebp                            
  0x0106BD5A  46                      inc      esi                            
  0x0106BD5B  000c00                  add      byte ptr [eax + eax], cl       
  0x0106BD5E  0000                    add      byte ptr [eax], al             
  0x0106BD60  00f0                    add      al, dh                         
  0x0106BD62  7000                    jo       0x106bd64                      
                                        ; XREF: 0x0106BD62 (cond_jump)
  0x0106BD64  40                      inc      eax                            
  0x0106BD65  0b00                    or       eax, dword ptr [eax]           
  0x0106BD67  0000                    add      byte ptr [eax], al             
  0x0106BD69  f4                      hlt                                     
  0x0106BD6A  60                      pushal                                  
  0x0106BD6B  00680b                  add      byte ptr [eax + 0xb], ch       
  0x0106BD6E  0000                    add      byte ptr [eax], al             
  0x0106BD70  00e8                    add      al, ch                         
  0x0106BD72  57                      push     edi                            
  0x0106BD73  0000                    add      byte ptr [eax], al             
  0x0106BD75  fa                      cli                                     
  0x0106BD76  2100                    and      dword ptr [eax], eax           
  0x0106BD78  00f0                    add      al, dh                         
  0x0106BD7A  56                      push     esi                            
  0x0106BD7B  00c0                    add      al, al                         
  0x0106BD7D  0400                    add      al, 0                          
  0x0106BD7F  0003                    add      byte ptr [ebx], al             
  0x0106BD81  0020                    add      byte ptr [eax], ah             
  0x0106BD83  0045a5                  add      byte ptr [ebp - 0x5b], al      
  0x0106BD86  050000f456              add      eax, 0x56f40000                
  0x0106BD8B  0001                    add      byte ptr [ecx], al             
  0x0106BD8D  0000                    add      byte ptr [eax], al             
  0x0106BD8F  0000                    add      byte ptr [eax], al             
  0x0106BD91  7056                    jo       0x106bde9                      
  0x0106BD93  00b704000000            add      byte ptr [edi + 4], dh         
  0x0106BD99  f4                      hlt                                     
  0x0106BD9A  56                      push     esi                            
  0x0106BD9B  0000                    add      byte ptr [eax], al             
  0x0106BD9D  0000                    add      byte ptr [eax], al             
  0x0106BD9F  0000                    add      byte ptr [eax], al             
  0x0106BDA2  44                      inc      esp                            
  0x0106BDA3  00730b                  add      byte ptr [ebx + 0xb], dh       
  0x0106BDA6  0000                    add      byte ptr [eax], al             
  0x0106BDA8  45                      inc      ebp                            
  0x0106BDA9  0020                    add      byte ptr [eax], ah             
  0x0106BDAB  0004a4                  add      byte ptr [esp], al             
  0x0106BDAE  0500000024              add      eax, 0x24000000                
  0x0106BDB3  0000                    add      byte ptr [eax], al             
  0x0106BDB5  7044                    jo       0x106bdfb                      
  0x0106BDB7  00b704000000            add      byte ptr [edi + 4], dh         
  0x0106BDBD  f4                      hlt                                     
  0x0106BDBE  46                      inc      esi                            
  0x0106BDBF  0000                    add      byte ptr [eax], al             
  0x0106BDC1  0000                    add      byte ptr [eax], al             
  0x0106BDC3  0000                    add      byte ptr [eax], al             
  0x0106BDC5  f4                      hlt                                     
  0x0106BDC6  60                      pushal                                  
  0x0106BDC7  00740b00                add      byte ptr [ebx + ecx], dh       
  0x0106BDCB  0000                    add      byte ptr [eax], al             
  0x0106BDCE  44                      inc      esp                            
  0x0106BDCF  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x0106BDD5  c406                    les      eax, ptr [esi]                 
  0x0106BDD7  0008                    add      byte ptr [eax], cl             
  0x0106BDD9  0000                    add      byte ptr [eax], al             
  0x0106BDDB  0000                    add      byte ptr [eax], al             
  0x0106BDDD  d85600                  fcom     dword ptr [esi]                
  0x0106BDE0  55                      push     ebp                            
  0x0106BDE1  0020                    add      byte ptr [eax], ah             
  0x0106BDE3  0004a4                  add      byte ptr [esp], al             
  0x0106BDE6  0500130020              add      eax, 0x20001300                
  0x0106BDEB  0000                    add      byte ptr [eax], al             
  0x0106BDED  7056                    jo       0x106be45                      
  0x0106BDEF  00b704000000            add      byte ptr [edi + 4], dh         
  0x0106BDF5  0000                    add      byte ptr [eax], al             
  0x0106BDF7  0000                    add      byte ptr [eax], al             
  0x0106BDFA  56                      push     esi                            
                                        ; XREF: 0x0106BDB5 (cond_jump)
  0x0106BDFB  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x0106BDFE  0000                    add      byte ptr [eax], al             
  0x0106BE00  0300                    add      eax, dword ptr [eax]           
  0x0106BE02  2000                    and      byte ptr [eax], al             
  0x0106BE04  08a4050000f056          or       byte ptr [ebp + eax + 0x56f00000], ah 
  0x0106BE0B  00790b                  add      byte ptr [ecx + 0xb], bh       
  0x0106BE0E  0000                    add      byte ptr [eax], al             
  0x0106BE10  55                      push     ebp                            
  0x0106BE11  0020                    add      byte ptr [eax], ah             
  0x0106BE13  0004a4                  add      byte ptr [esp], al             
  0x0106BE16  0500130020              add      eax, 0x20001300                
  0x0106BE1B  0000                    add      byte ptr [eax], al             
  0x0106BE1D  7056                    jo       0x106be75                      
  0x0106BE1F  00b704000000            add      byte ptr [edi + 4], dh         
  0x0106BE25  07                      pop      es                             
  0x0106BE26  3000                    xor      byte ptr [eax], al             
  0x0106BE28  c4700b                  les      esi, ptr [eax + 0xb]           
  0x0106BE2B  00b20c000000            add      byte ptr [edx + 0xc], dh       
  0x0106BE31  7044                    jo       0x106be77                      
  0x0106BE33  00bf04000013            add      byte ptr [edi + 0x13000004], bh 
  0x0106BE39  f4                      hlt                                     
  0x0106BE3A  60                      pushal                                  
  0x0106BE3B  00a504000090            add      byte ptr [ebp - 0x6ffffffc], ah 
  0x0106BE41  1006                    adc      byte ptr [esi], al             
  0x0106BE43  0002                    add      byte ptr [edx], al             
                                        ; XREF: 0x0106BDED (cond_jump)
  0x0106BE45  0000                    add      byte ptr [eax], al             
  0x0106BE47  0000                    add      byte ptr [eax], al             
  0x0106BE49  58                      pop      eax                            
  0x0106BE4A  56                      push     esi                            
  0x0106BE4B  0000                    add      byte ptr [eax], al             
  0x0106BE4D  0036                    add      byte ptr [esi], dh             
  0x0106BE4F  0000                    add      byte ptr [eax], al             
  0x0106BE52  44                      inc      esp                            
  0x0106BE53  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x0106BE59  c406                    les      eax, ptr [esi]                 
  0x0106BE5B  0036                    add      byte ptr [esi], dh             
  0x0106BE5D  0000                    add      byte ptr [eax], al             
  0x0106BE5F  0000                    add      byte ptr [eax], al             
  0x0106BE61  f4                      hlt                                     
  0x0106BE62  56                      push     esi                            
  0x0106BE63  00740b00                add      byte ptr [ebx + ecx], dh       
  0x0106BE67  0000                    add      byte ptr [eax], al             
  0x0106BE69  c422                    les      esp, ptr [edx]                 
  0x0106BE6B  004000                  add      byte ptr [eax], al             
  0x0106BE6E  2000                    and      byte ptr [eax], al             
  0x0106BE70  0090210000f0            add      byte ptr [eax - 0xfffffdf], dl 
  0x0106BE76  56                      push     esi                            
                                        ; XREF: 0x0106BE31 (cond_jump)
  0x0106BE77  00730b                  add      byte ptr [ebx + 0xb], dh       
  0x0106BE7A  0000                    add      byte ptr [eax], al             
  0x0106BE7C  00e0                    add      al, ah                         
  0x0106BE7E  44                      inc      esp                            
  0x0106BE7F  00844f0100081d          add      byte ptr [edi + ecx*2 + 0x1d080001], al 
  0x0106BE86  0c00                    or       al, 0                          
  0x0106BE88  40                      inc      eax                            
  0x0106BE89  0020                    add      byte ptr [eax], ah             
  0x0106BE8B  00041d0c000070          add      byte ptr [ebx + 0x7000000c], al 
  0x0106BE92  54                      push     esp                            
  0x0106BE93  00a204000000            add      byte ptr [edx + 4], ah         
  0x0106BE99  f4                      hlt                                     
  0x0106BE9A  56                      push     esi                            
  0x0106BE9B  00a50b000000            add      byte ptr [ebp + 0xb], ah       
  0x0106BEA1  c422                    les      esp, ptr [edx]                 
  0x0106BEA3  004000                  add      byte ptr [eax], al             
  0x0106BEA6  2000                    and      byte ptr [eax], al             
  0x0106BEA8  009021000000            add      byte ptr [eax + 0x21], dl      
  0x0106BEAE  250000e047              and      eax, 0x47e00000                
  0x0106BEB3  0000                    add      byte ptr [eax], al             
  0x0106BEB5  c422                    les      esp, ptr [edx]                 
  0x0106BEB7  0000                    add      byte ptr [eax], al             
  0x0106BEB9  f4                      hlt                                     
  0x0106BEBA  46                      inc      esi                            
  0x0106BEBB  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x0106BEC1  f4                      hlt                                     
  0x0106BEC2  44                      inc      esp                            
  0x0106BEC3  00fa                    add      dl, bh                         
  0x0106BEC5  0000                    add      byte ptr [eax], al             
  0x0106BEC7  002e                    add      byte ptr [esi], ch             
  0x0106BEC9  1d0c004000              sbb      eax, 0x40000c                  
  0x0106BECE  2000                    and      byte ptr [eax], al             
  0x0106BED0  0090210000c4            add      byte ptr [eax - 0x3bffffdf], dl 
  0x0106BED6  2200                    and      al, byte ptr [eax]             
  0x0106BED8  00f4                    add      ah, dh                         
  0x0106BEDA  46                      inc      esi                            
  0x0106BEDB  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x0106BEE2  44                      inc      esp                            
  0x0106BEE3  00720b                  add      byte ptr [edx + 0xb], dh       
  0x0106BEE6  0000                    add      byte ptr [eax], al             
  0x0106BEE8  2e1d0c004000            sbb      eax, 0x40000c                  
  0x0106BEEE  2000                    and      byte ptr [eax], al             
  0x0106BEF0  0091210000c4            add      byte ptr [ecx - 0x3bffffdf], dl 
  0x0106BEF6  2200                    and      al, byte ptr [eax]             
  0x0106BEF8  00f4                    add      ah, dh                         
  0x0106BEFA  46                      inc      esi                            
  0x0106BEFB  0032                    add      byte ptr [edx], dh             
  0x0106BEFD  0000                    add      byte ptr [eax], al             
  0x0106BEFF  00d0                    add      al, dl                         
  0x0106BF01  f4                      hlt                                     
  0x0106BF02  44                      inc      esp                            
  0x0106BF03  0000                    add      byte ptr [eax], al             
  0x0106BF05  0000                    add      byte ptr [eax], al             
  0x0106BF07  002e                    add      byte ptr [esi], ch             
  0x0106BF09  1d0c004000              sbb      eax, 0x40000c                  
  0x0106BF0E  2000                    and      byte ptr [eax], al             
  0x0106BF10  0092210000f4            add      byte ptr [edx - 0xbffffdf], dl 
  0x0106BF16  65001a                  add      byte ptr gs:[edx], bl          
  0x0106BF19  0f0000                  sldt     word ptr [eax]                 
  0x0106BF1C  007066                  add      byte ptr [eax + 0x66], dh      
  0x0106BF1F  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106BF22  0000                    add      byte ptr [eax], al             
  0x0106BF24  86040d0000f066          xchg     byte ptr [ecx + 0x66f00000], al 
  0x0106BF2B  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106BF2E  0000                    add      byte ptr [eax], al             
  0x0106BF30  005e20                  add      byte ptr [esi + 0x20], bl      
  0x0106BF33  0000                    add      byte ptr [eax], al             
  0x0106BF36  56                      push     esi                            
  0x0106BF37  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x0106BF3A  0000                    add      byte ptr [eax], al             
  0x0106BF3C  0300                    add      eax, dword ptr [eax]           
  0x0106BF3E  2000                    and      byte ptr [eax], al             
  0x0106BF40  17                      pop      ss                             
  0x0106BF41  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106BF42  050000f056              add      eax, 0x56f00000                
  0x0106BF47  00730b                  add      byte ptr [ebx + 0xb], dh       
  0x0106BF4A  0000                    add      byte ptr [eax], al             
  0x0106BF4C  00f0                    add      al, dh                         
  0x0106BF4E  44                      inc      esp                            
  0x0106BF4F  00790b                  add      byte ptr [ecx + 0xb], bh       
  0x0106BF52  0000                    add      byte ptr [eax], al             
  0x0106BF54  844f01                  test     byte ptr [edi + 1], cl         
  0x0106BF57  0008                    add      byte ptr [eax], cl             
  0x0106BF59  1d0c004000              sbb      eax, 0x40000c                  
  0x0106BF5E  2000                    and      byte ptr [eax], al             
  0x0106BF60  041d                    add      al, 0x1d                       
  0x0106BF62  0c00                    or       al, 0                          
  0x0106BF64  007054                  add      byte ptr [eax + 0x54], dh      
  0x0106BF67  00a204000000            add      byte ptr [edx + 4], ah         
  0x0106BF6D  00250000f447            add      byte ptr [0x47f40000], ah      
  0x0106BF73  0007                    add      byte ptr [edi], al             
  0x0106BF75  0000                    add      byte ptr [eax], al             
  0x0106BF77  0000                    add      byte ptr [eax], al             
  0x0106BF79  f4                      hlt                                     
  0x0106BF7A  60                      pushal                                  
  0x0106BF7B  008304000000            add      byte ptr [ebx + 4], al         
  0x0106BF81  f4                      hlt                                     
  0x0106BF82  61                      popal                                   
  0x0106BF83  0039                    add      byte ptr [ecx], bh             
  0x0106BF85  0b00                    or       eax, dword ptr [eax]           
  0x0106BF87  0000                    add      byte ptr [eax], al             
  0x0106BF89  f4                      hlt                                     
  0x0106BF8A  6200                    bound    eax, qword ptr [eax]           
  0x0106BF8C  b804000000              mov      eax, 4                         
  0x0106BF91  f4                      hlt                                     
  0x0106BF92  65001a                  add      byte ptr gs:[edx], bl          
  0x0106BF95  0f0000                  sldt     word ptr [eax]                 
  0x0106BF98  86040d0000f460          xchg     byte ptr [ecx + 0x60f40000], al 
  0x0106BF9F  00a60400001b            add      byte ptr [esi + 0x1b000004], ah 
  0x0106BFA5  f4                      hlt                                     
  0x0106BFA6  6600fb                  add      bl, bh                         
  0x0106BFA9  0c00                    or       al, 0                          
  0x0106BFAB  0000                    add      byte ptr [eax], al             
  0x0106BFAD  d8440013                fadd     dword ptr [eax + eax + 0x13]   
  0x0106BFB1  f4                      hlt                                     
  0x0106BFB2  47                      inc      edi                            
  0x0106BFB3  005555                  add      byte ptr [ebp + 0x55], dl      
  0x0106BFB6  d500                    aad      0                              
  0x0106BFB8  00e8                    add      al, ch                         
  0x0106BFBA  2000                    and      byte ptr [eax], al             
  0x0106BFBD  de4e00                  fimul    word ptr [esi]                 
  0x0106BFC0  13842100dad844          adc      eax, dword ptr [ecx + 0x44d8da00] 
  0x0106BFC7  0000                    add      byte ptr [eax], al             
  0x0106BFC9  e82000c6de              call     0xdfccbfee                     
  0x0106BFCE  4e                      dec      esi                            
  0x0106BFCF  0000                    add      byte ptr [eax], al             
  0x0106BFD1  8421                    test     byte ptr [ecx], ah             
  0x0106BFD3  00da                    add      dl, bl                         
  0x0106BFD5  d8f0                    fdiv     st(0)                          
  0x0106BFD7  00da                    add      dl, bl                         
  0x0106BFD9  d8440013                fadd     dword ptr [eax + eax + 0x13]   
  0x0106BFDD  f4                      hlt                                     
  0x0106BFDE  47                      inc      edi                            
  0x0106BFDF  0000                    add      byte ptr [eax], al             
  0x0106BFE1  00c0                    add      al, al                         
  0x0106BFE3  0000                    add      byte ptr [eax], al             
  0x0106BFE5  e82000c6de              call     0xdfccc00a                     
  0x0106BFEA  4e                      dec      esi                            
  0x0106BFEB  0000                    add      byte ptr [eax], al             
  0x0106BFED  8421                    test     byte ptr [ecx], ah             
  0x0106BFEF  00da                    add      dl, bl                         
  0x0106BFF1  0020                    add      byte ptr [eax], ah             
  0x0106BFF3  0000                    add      byte ptr [eax], al             
  0x0106BFF5  d8f0                    fdiv     st(0)                          
  0x0106BFF7  00900a060002            add      byte ptr [eax + 0x200060a], dl 
  0x0106BFFD  0000                    add      byte ptr [eax], al             
  0x0106BFFF  00da                    add      dl, bl                         
  0x0106C001  d8f0                    fdiv     st(0)                          
  0x0106C003  00da                    add      dl, bl                         
  0x0106C005  0020                    add      byte ptr [eax], ah             
  0x0106C007  00ae1d0c0000            add      byte ptr [esi + 0xc1d], ch     
  0x0106C00D  7056                    jo       0x106c065                      
  0x0106C00F  007a0b                  add      byte ptr [edx + 0xb], bh       
  0x0106C012  0000                    add      byte ptr [eax], al             
  0x0106C014  020c0500000c05          add      cl, byte ptr [eax + 0x50c0000] 
  0x0106C01B  001b                    add      byte ptr [ebx], bl             
  0x0106C01E  44                      inc      esp                            
  0x0106C01F  007a0b                  add      byte ptr [edx + 0xb], bh       
  0x0106C022  0000                    add      byte ptr [eax], al             
  0x0106C024  004f23                  add      byte ptr [edi + 0x23], cl      
  0x0106C027  004c0020                add      byte ptr [eax + eax + 0x20], cl 
  0x0106C02B  0000                    add      byte ptr [eax], al             
  0x0106C02D  fa                      cli                                     
  0x0106C02E  2100                    and      dword ptr [eax], eax           
  0x0106C030  0b00                    or       eax, dword ptr [eax]           
  0x0106C032  2000                    and      byte ptr [eax], al             
  0x0106C034  02140500030c05          add      dl, byte ptr [eax + 0x50c0300] 
  0x0106C03B  0080100d0033            add      byte ptr [eax + 0x33000d10], al 
  0x0106C041  fc                      cld                                     
  0x0106C042  ff00                    inc      dword ptr [eax]                
  0x0106C044  0c00                    or       al, 0                          
  0x0106C046  0000                    add      byte ptr [eax], al             
  0x0106C048  1bf4                    sbb      esi, esp                       
  0x0106C04A  60                      pushal                                  
  0x0106C04B  007a0b                  add      byte ptr [edx + 0xb], bh       
  0x0106C04E  0000                    add      byte ptr [eax], al             
  0x0106C050  006057                  add      byte ptr [eax + 0x57], ah      
  0x0106C053  0000                    add      byte ptr [eax], al             
  0x0106C055  f4                      hlt                                     
  0x0106C056  60                      pushal                                  
  0x0106C057  00730b                  add      byte ptr [ebx + 0xb], dh       
  0x0106C05A  0000                    add      byte ptr [eax], al             
  0x0106C05C  00f4                    add      ah, dh                         
  0x0106C05E  6200                    bound    eax, qword ptr [eax]           
  0x0106C060  790b                    jns      0x106c06d                      
  0x0106C062  0000                    add      byte ptr [eax], al             
  0x0106C064  00f4                    add      ah, dh                         
  0x0106C066  6400740b00              add      byte ptr fs:[ebx + ecx], dh    
  0x0106C06B  0000                    add      byte ptr [eax], al             
  0x0106C06E  7000                    jo       0x106c070                      
                                        ; XREF: 0x0106C06E (cond_jump)
  0x0106C070  97                      xchg     edi, eax                       
  0x0106C071  0b00                    or       eax, dword ptr [eax]           
  0x0106C073  0000                    add      byte ptr [eax], al             
  0x0106C075  95                      xchg     ebp, eax                       
  0x0106C076  2200                    and      al, byte ptr [eax]             
  0x0106C078  006057                  add      byte ptr [eax + 0x57], ah      
  0x0106C07B  0000                    add      byte ptr [eax], al             
  0x0106C07D  625700                  bound    edx, qword ptr [edi]           
  0x0106C080  10d8                    adc      al, bl                         
  0x0106C082  06                      push     es                             
  0x0106C083  0002                    add      byte ptr [edx], al             
  0x0106C085  0000                    add      byte ptr [eax], al             
  0x0106C087  0000                    add      byte ptr [eax], al             
  0x0106C089  5d                      pop      ebp                            
  0x0106C08A  57                      push     edi                            
  0x0106C08B  0000                    add      byte ptr [eax], al             
  0x0106C08D  0036                    add      byte ptr [esi], dh             
  0x0106C08F  0000                    add      byte ptr [eax], al             
  0x0106C092  44                      inc      esp                            
  0x0106C093  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x0106C099  c406                    les      eax, ptr [esi]                 
  0x0106C09B  0012                    add      byte ptr [edx], dl             
  0x0106C09D  0000                    add      byte ptr [eax], al             
  0x0106C09F  0000                    add      byte ptr [eax], al             
  0x0106C0A1  c422                    les      esp, ptr [edx]                 
  0x0106C0A3  0000                    add      byte ptr [eax], al             
  0x0106C0A5  f4                      hlt                                     
  0x0106C0A6  46                      inc      esi                            
  0x0106C0A7  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x0106C0AE  44                      inc      esp                            
  0x0106C0AF  00720b                  add      byte ptr [edx + 0xb], dh       
  0x0106C0B2  0000                    add      byte ptr [eax], al             
  0x0106C0B4  2e1d0c004000            sbb      eax, 0x40000c                  
  0x0106C0BA  2000                    and      byte ptr [eax], al             
  0x0106C0BC  0090210000f4            add      byte ptr [eax - 0xbffffdf], dl 
  0x0106C0C2  56                      push     esi                            
  0x0106C0C3  00a50b000000            add      byte ptr [ebp + 0xb], ah       
  0x0106C0C9  c422                    les      esp, ptr [edx]                 
  0x0106C0CB  004000                  add      byte ptr [eax], al             
  0x0106C0CE  2000                    and      byte ptr [eax], al             
  0x0106C0D0  009221001062            add      byte ptr [edx + 0x62100021], dl 
  0x0106C0D6  06                      push     es                             
  0x0106C0D7  0002                    add      byte ptr [edx], al             
  0x0106C0D9  0000                    add      byte ptr [eax], al             
  0x0106C0DB  0000                    add      byte ptr [eax], al             
  0x0106C0DD  58                      pop      eax                            
  0x0106C0DE  57                      push     edi                            
  0x0106C0DF  0000                    add      byte ptr [eax], al             
  0x0106C0E1  5e                      pop      esi                            
  0x0106C0E2  2000                    and      byte ptr [eax], al             
  0x0106C0E4  00f0                    add      al, dh                         
  0x0106C0E6  56                      push     esi                            
  0x0106C0E7  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x0106C0EA  0000                    add      byte ptr [eax], al             
  0x0106C0EC  0300                    add      eax, dword ptr [eax]           
  0x0106C0EE  2000                    and      byte ptr [eax], al             
  0x0106C0F0  06                      push     es                             
  0x0106C0F1  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106C0F2  050000f460              add      eax, 0x60f40000                
  0x0106C0F7  0039                    add      byte ptr [ecx], bh             
  0x0106C0F9  0b00                    or       eax, dword ptr [eax]           
  0x0106C0FB  009007060002            add      byte ptr [eax + 0x2000607], dl 
  0x0106C101  0000                    add      byte ptr [eax], al             
  0x0106C103  0000                    add      byte ptr [eax], al             
  0x0106C105  58                      pop      eax                            
  0x0106C106  57                      push     edi                            
  0x0106C107  000c00                  add      byte ptr [eax + eax], cl       
  0x0106C10A  0000                    add      byte ptr [eax], al             
  0x0106C10C  00f0                    add      al, dh                         
  0x0106C10E  44                      inc      esp                            
  0x0106C10F  00b604000000            add      byte ptr [esi + 4], dh         
  0x0106C115  7044                    jo       0x106c15b                      
  0x0106C117  009f04000080            add      byte ptr [edi - 0x7ffffffc], bl 
  0x0106C11D  100d00f8feff            adc      byte ptr [0xfffef800], cl      
  0x0106C123  000f                    add      byte ptr [edi], cl             
  0x0106C125  0a05000c0000            or       al, byte ptr [0xc00]           
  0x0106C12B  001b                    add      byte ptr [ebx], bl             
  0x0106C12D  0020                    add      byte ptr [eax], ah             
  0x0106C12F  008850010088            add      byte ptr [eax - 0x77fffeb0], cl 
  0x0106C135  50                      push     eax                            
  0x0106C136  0100                    add      dword ptr [eax], eax           
  0x0106C138  884201                  mov      byte ptr [edx + 1], al         
  0x0106C13B  008846010088            add      byte ptr [eax - 0x77fffeba], cl 
  0x0106C141  45                      inc      ebp                            
  0x0106C142  0100                    add      dword ptr [eax], eax           
  0x0106C144  884301                  mov      byte ptr [ebx + 1], al         
  0x0106C147  008843010000            add      byte ptr [eax + 0x143], cl     
  0x0106C14E  56                      push     esi                            
  0x0106C14F  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x0106C152  0000                    add      byte ptr [eax], al             
  0x0106C154  854101                  test     dword ptr [ecx + 1], eax       
  0x0106C157  0004a4                  add      byte ptr [esp], al             
  0x0106C15A  0500864101              add      eax, 0x1418600                 
  0x0106C15F  0002                    add      byte ptr [edx], al             
  0x0106C161  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106C162  0500884201              add      eax, 0x1428800                 
  0x0106C167  0000                    add      byte ptr [eax], al             
  0x0106C16A  56                      push     esi                            
  0x0106C16B  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x0106C16E  0000                    add      byte ptr [eax], al             
  0x0106C170  86440100                xchg     byte ptr [ecx + eax], al       
  0x0106C174  02a40500884201          add      ah, byte ptr [ebp + eax + 0x1428800] 
  0x0106C17B  0000                    add      byte ptr [eax], al             
  0x0106C17E  56                      push     esi                            
  0x0106C17F  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x0106C182  0000                    add      byte ptr [eax], al             
  0x0106C184  854201                  test     dword ptr [edx + 1], eax       
  0x0106C187  0002                    add      byte ptr [edx], al             
  0x0106C189  2405                    and      al, 5                          
  0x0106C18B  008842010088            add      byte ptr [eax - 0x77fffebe], cl 
  0x0106C191  41                      inc      ecx                            
  0x0106C192  0100                    add      dword ptr [eax], eax           
  0x0106C194  884501                  mov      byte ptr [ebp + 1], al         
  0x0106C197  008841010000            add      byte ptr [eax + 0x141], cl     
  0x0106C19E  56                      push     esi                            
  0x0106C19F  004c0b00                add      byte ptr [ebx + ecx], cl       
  0x0106C1A3  0003                    add      byte ptr [ebx], al             
  0x0106C1A5  f4                      hlt                                     
  0x0106C1A6  44                      inc      esp                            
  0x0106C1A7  0008                    add      byte ptr [eax], cl             
  0x0106C1A9  0000                    add      byte ptr [eax], al             
  0x0106C1AB  0002                    add      byte ptr [edx], al             
  0x0106C1AD  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106C1AE  0500480020              add      eax, 0x20004800                
  0x0106C1B3  008841010088            add      byte ptr [eax - 0x77fffebf], cl 
  0x0106C1B9  41                      inc      ecx                            
  0x0106C1BA  0100                    add      dword ptr [eax], eax           
  0x0106C1BC  884101                  mov      byte ptr [ecx + 1], al         
  0x0106C1BF  008841010088            add      byte ptr [eax - 0x77fffebf], cl 
  0x0106C1C5  41                      inc      ecx                            
  0x0106C1C6  0100                    add      dword ptr [eax], eax           
  0x0106C1C8  884101                  mov      byte ptr [ecx + 1], al         
  0x0106C1CB  008841010000            add      byte ptr [eax + 0x141], cl     
  0x0106C1D1  7057                    jo       0x106c22a                      
  0x0106C1D3  00510b                  add      byte ptr [ecx + 0xb], dl       
  0x0106C1D6  0000                    add      byte ptr [eax], al             
  0x0106C1D8  0c00                    or       al, 0                          
  0x0106C1DA  0000                    add      byte ptr [eax], al             
  0x0106C1DC  0000                    add      byte ptr [eax], al             
  0x0106C1DE  360000                  add      byte ptr ss:[eax], al          
  0x0106C1E2  44                      inc      esp                            
  0x0106C1E3  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x0106C1E9  c406                    les      eax, ptr [esi]                 
  0x0106C1EB  003400                  add      byte ptr [eax + eax], dh       
  0x0106C1EE  0000                    add      byte ptr [eax], al             
  0x0106C1F0  00f4                    add      ah, dh                         
  0x0106C1F2  56                      push     esi                            
  0x0106C1F3  008a0b000000            add      byte ptr [edx + 0xb], cl       
  0x0106C1F9  c422                    les      esp, ptr [edx]                 
  0x0106C1FB  004000                  add      byte ptr [eax], al             
  0x0106C1FE  2000                    and      byte ptr [eax], al             
  0x0106C200  0090210000e0            add      byte ptr [eax - 0x1fffffdf], dl 
  0x0106C206  56                      push     esi                            
  0x0106C207  0003                    add      byte ptr [ebx], al             
  0x0106C209  92                      xchg     edx, eax                       
  0x0106C20A  2100                    and      dword ptr [eax], eax           
  0x0106C20C  4b                      dec      ebx                            
  0x0106C20D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106C20E  050000c422              add      eax, 0x22c40000                
  0x0106C213  0000                    add      byte ptr [eax], al             
  0x0106C215  f4                      hlt                                     
  0x0106C216  46                      inc      esi                            
  0x0106C217  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x0106C21D  f4                      hlt                                     
  0x0106C21E  44                      inc      esp                            
  0x0106C21F  00fa                    add      dl, bh                         
  0x0106C221  0000                    add      byte ptr [eax], al             
  0x0106C223  002e                    add      byte ptr [esi], ch             
  0x0106C225  1d0c004000              sbb      eax, 0x40000c                  
                                        ; XREF: 0x0106C1D1 (cond_jump)
  0x0106C22A  2000                    and      byte ptr [eax], al             
  0x0106C22C  0090210000f4            add      byte ptr [eax - 0xbffffdf], dl 
  0x0106C232  56                      push     esi                            
  0x0106C233  005c0b00                add      byte ptr [ebx + ecx], bl       
  0x0106C237  0000                    add      byte ptr [eax], al             
  0x0106C239  c422                    les      esp, ptr [edx]                 
  0x0106C23B  004000                  add      byte ptr [eax], al             
  0x0106C23E  2000                    and      byte ptr [eax], al             
  0x0106C240  0091210000e1            add      byte ptr [ecx - 0x1effffdf], dl 
  0x0106C246  7000                    jo       0x106c248                      
                                        ; XREF: 0x0106C246 (cond_jump)
  0x0106C248  d9720b                  fnstenv  [edx + 0xb]                    
  0x0106C24B  0012                    add      byte ptr [edx], dl             
  0x0106C24D  0f0000                  sldt     word ptr [eax]                 
  0x0106C250  00f4                    add      ah, dh                         
  0x0106C252  56                      push     esi                            
  0x0106C253  00910b000000            add      byte ptr [ecx + 0xb], dl       
  0x0106C259  c422                    les      esp, ptr [edx]                 
  0x0106C25B  004000                  add      byte ptr [eax], al             
  0x0106C25E  2000                    and      byte ptr [eax], al             
  0x0106C260  0091210000e1            add      byte ptr [ecx - 0x1effffdf], dl 
  0x0106C266  7200                    jb       0x106c268                      
                                        ; XREF: 0x0106C266 (cond_jump)
  0x0106C268  00d8                    add      al, bl                         
  0x0106C26A  45                      inc      ebp                            
  0x0106C26B  0000                    add      byte ptr [eax], al             
  0x0106C26D  c422                    les      esp, ptr [edx]                 
  0x0106C26F  0000                    add      byte ptr [eax], al             
  0x0106C271  f4                      hlt                                     
  0x0106C272  46                      inc      esi                            
  0x0106C273  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x0106C279  f4                      hlt                                     
  0x0106C27A  44                      inc      esp                            
  0x0106C27B  00b00700002e            add      byte ptr [eax + 0x2e000007], dh 
  0x0106C281  1d0c004000              sbb      eax, 0x40000c                  
  0x0106C286  2000                    and      byte ptr [eax], al             
  0x0106C288  00952100005d            add      byte ptr [ebp + 0x5d000021], dl 
  0x0106C28E  45                      inc      ebp                            
  0x0106C28F  0000                    add      byte ptr [eax], al             
  0x0106C291  c422                    les      esp, ptr [edx]                 
  0x0106C293  0000                    add      byte ptr [eax], al             
  0x0106C295  f4                      hlt                                     
  0x0106C296  46                      inc      esi                            
  0x0106C297  001f                    add      byte ptr [edi], bl             
  0x0106C299  0000                    add      byte ptr [eax], al             
  0x0106C29B  00d0                    add      al, dl                         
  0x0106C29D  f4                      hlt                                     
  0x0106C29E  44                      inc      esp                            
  0x0106C29F  0000                    add      byte ptr [eax], al             
  0x0106C2A1  0000                    add      byte ptr [eax], al             
  0x0106C2A3  002e                    add      byte ptr [esi], ch             
  0x0106C2A5  1d0c004000              sbb      eax, 0x40000c                  
  0x0106C2AA  2000                    and      byte ptr [eax], al             
  0x0106C2AC  00942100005c4d          add      byte ptr [ecx + 0x4d5c0000], dl 
  0x0106C2B3  001e                    add      byte ptr [esi], bl             
  0x0106C2B5  050d00005e              add      eax, 0x5e00000d                
  0x0106C2BA  2000                    and      byte ptr [eax], al             
  0x0106C2BC  00f0                    add      al, dh                         
  0x0106C2BE  56                      push     esi                            
  0x0106C2BF  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x0106C2C2  0000                    add      byte ptr [eax], al             
  0x0106C2C4  0300                    add      eax, dword ptr [eax]           
  0x0106C2C6  2000                    and      byte ptr [eax], al             
  0x0106C2C8  13a4050000f056          adc      esp, dword ptr [ebp + eax + 0x56f00000] 
  0x0106C2CF  008f0b000003            add      byte ptr [edi + 0x300000b], cl 
  0x0106C2D5  0020                    add      byte ptr [eax], ah             
  0x0106C2D7  000f                    add      byte ptr [edi], cl             
  0x0106C2D9  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106C2DA  050000f460              add      eax, 0x60f40000                
  0x0106C2DF  008304000000            add      byte ptr [ebx + 4], al         
  0x0106C2E5  06                      push     es                             
  0x0106C2E6  3800                    cmp      byte ptr [eax], al             
  0x0106C2E8  00f0                    add      al, dh                         
  0x0106C2EA  7900                    jns      0x106c2ec                      
                                        ; XREF: 0x0106C2EA (cond_jump)
  0x0106C2EC  130f                    adc      ecx, dword ptr [edi]           
  0x0106C2EE  0000                    add      byte ptr [eax], al             
  0x0106C2F0  0002                    add      byte ptr [edx], al             
  0x0106C2F2  3a00                    cmp      al, byte ptr [eax]             
  0x0106C2F4  00d8                    add      al, bl                         
  0x0106C2F6  45                      inc      ebp                            
  0x0106C2F7  0000                    add      byte ptr [eax], al             
  0x0106C2F9  f4                      hlt                                     
  0x0106C2FA  650039                  add      byte ptr gs:[ecx], bh          
  0x0106C2FD  0b00                    or       eax, dword ptr [eax]           
  0x0106C2FF  0000                    add      byte ptr [eax], al             
  0x0106C301  5d                      pop      ebp                            
  0x0106C302  45                      inc      ebp                            
  0x0106C303  0000                    add      byte ptr [eax], al             
  0x0106C305  f4                      hlt                                     
  0x0106C306  64009b00000000          add      byte ptr fs:[ebx], bl          
  0x0106C30D  5c                      pop      esp                            
  0x0106C30E  4d                      dec      ebp                            
  0x0106C30F  001e                    add      byte ptr [esi], bl             
  0x0106C311  050d000c00              add      eax, 0xc000d                   
  0x0106C316  0000                    add      byte ptr [eax], al             
  0x0106C318  00f4                    add      ah, dh                         
  0x0106C31A  56                      push     esi                            
  0x0106C31B  0016                    add      byte ptr [esi], dl             
  0x0106C31D  0000                    add      byte ptr [eax], al             
  0x0106C31F  0000                    add      byte ptr [eax], al             
  0x0106C321  f4                      hlt                                     
  0x0106C322  57                      push     edi                            
  0x0106C323  0001                    add      byte ptr [ecx], al             
  0x0106C325  0000                    add      byte ptr [eax], al             
  0x0106C327  0000                    add      byte ptr [eax], al             
  0x0106C329  f4                      hlt                                     
  0x0106C32A  7000                    jo       0x106c32c                      
                                        ; XREF: 0x0106C32A (cond_jump)
  0x0106C32C  90                      nop                                     
  0x0106C32D  0300                    add      eax, dword ptr [eax]           
  0x0106C32F  0000                    add      byte ptr [eax], al             
  0x0106C331  0039                    add      byte ptr [ecx], bh             
  0x0106C333  0000                    add      byte ptr [eax], al             
  0x0106C335  f4                      hlt                                     
  0x0106C336  60                      pushal                                  
  0x0106C337  00fa                    add      dl, bh                         
  0x0106C339  0000                    add      byte ptr [eax], al             
  0x0106C33B  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x0106C341  0100                    add      dword ptr [eax], eax           
  0x0106C343  0003                    add      byte ptr [ebx], al             
  0x0106C345  0020                    add      byte ptr [eax], ah             
  0x0106C347  0000                    add      byte ptr [eax], al             
  0x0106C349  2405                    and      al, 5                          
  0x0106C34B  000c00                  add      byte ptr [eax + eax], cl       
  0x0106C34E  0000                    add      byte ptr [eax], al             
  0x0106C350  0c00                    or       al, 0                          
  0x0106C352  0000                    add      byte ptr [eax], al             
  0x0106C354  0c00                    or       al, 0                          
  0x0106C356  0000                    add      byte ptr [eax], al             
  0x0106C358  40                      inc      eax                            
  0x0106C359  1bd0                    sbb      edx, eax                       
  0x0106C35B  00d3                    add      bl, dl                         
  0x0106C35D  06                      push     es                             
  0x0106C35E  0000                    add      byte ptr [eax], al             
  0x0106C360  7201                    jb       0x106c363                      
  0x0106C362  0400                    add      al, 0                          
  0x0106C364  c2c60f                  ret      0xfc6                          
  0x0106C367  0000                    add      byte ptr [eax], al             
  0x0106C369  7044                    jo       0x106c3af                      
  0x0106C36B  00fb                    add      bl, bh                         
  0x0106C36D  0000                    add      byte ptr [eax], al             
  0x0106C36F  000b                    add      byte ptr [ebx], cl             
  0x0106C371  0020                    add      byte ptr [eax], ah             
  0x0106C373  0003                    add      byte ptr [ebx], al             
  0x0106C375  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106C376  050080100d              add      eax, 0xd108000                 
  0x0106C37B  00c0                    add      al, al                         
  0x0106C37D  06                      push     es                             
  0x0106C37E  0000                    add      byte ptr [eax], al             
  0x0106C380  80100d                  adc      byte ptr [eax], 0xd            
  0x0106C383  006c0600                add      byte ptr [esi + eax], ch       
  0x0106C387  0000                    add      byte ptr [eax], al             
  0x0106C38A  57                      push     edi                            
  0x0106C38B  00fb                    add      bl, bh                         
  0x0106C38D  0000                    add      byte ptr [eax], al             
  0x0106C38F  000b                    add      byte ptr [ebx], cl             
  0x0106C391  f4                      hlt                                     
  0x0106C392  60                      pushal                                  
  0x0106C393  001f                    add      byte ptr [edi], bl             
  0x0106C395  0000                    add      byte ptr [eax], al             
  0x0106C397  0012                    add      byte ptr [edx], dl             
  0x0106C399  2405                    and      al, 5                          
  0x0106C39B  0000                    add      byte ptr [eax], al             
  0x0106C39D  002400                  add      byte ptr [eax + eax], ah       
  0x0106C3A0  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106C3A3  004f0b                  add      byte ptr [edi + 0xb], cl       
  0x0106C3A6  0000                    add      byte ptr [eax], al             
  0x0106C3A8  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106C3AB  00500b                  add      byte ptr [eax + 0xb], dl       
  0x0106C3AE  0000                    add      byte ptr [eax], al             
  0x0106C3B0  00f4                    add      ah, dh                         
  0x0106C3B2  44                      inc      esp                            
  0x0106C3B3  0000                    add      byte ptr [eax], al             
  0x0106C3B5  72f8                    jb       0x106c3af                      
  0x0106C3B7  0000                    add      byte ptr [eax], al             
  0x0106C3B9  58                      pop      eax                            
  0x0106C3BA  44                      inc      esp                            
  0x0106C3BB  0000                    add      byte ptr [eax], al             
  0x0106C3BD  f4                      hlt                                     
  0x0106C3BE  44                      inc      esp                            
  0x0106C3BF  0000                    add      byte ptr [eax], al             
  0x0106C3C1  1f                      pop      ds                             
  0x0106C3C2  4e                      dec      esi                            
  0x0106C3C3  0000                    add      byte ptr [eax], al             
  0x0106C3C5  58                      pop      eax                            
  0x0106C3C6  44                      inc      esp                            
  0x0106C3C7  0000                    add      byte ptr [eax], al             
  0x0106C3C9  f4                      hlt                                     
  0x0106C3CA  44                      inc      esp                            
  0x0106C3CB  0000                    add      byte ptr [eax], al             
  0x0106C3CD  0100                    add      dword ptr [eax], eax           
  0x0106C3CF  0000                    add      byte ptr [eax], al             
  0x0106C3D1  58                      pop      eax                            
  0x0106C3D2  44                      inc      esp                            
  0x0106C3D3  0000                    add      byte ptr [eax], al             
  0x0106C3D5  f4                      hlt                                     
  0x0106C3D6  44                      inc      esp                            
  0x0106C3D7  0000                    add      byte ptr [eax], al             
  0x0106C3D9  005000                  add      byte ptr [eax], dl             
  0x0106C3DC  005844                  add      byte ptr [eax + 0x44], bl      
  0x0106C3DF  0000                    add      byte ptr [eax], al             
  0x0106C3E2  56                      push     esi                            
  0x0106C3E3  004f0b                  add      byte ptr [edi + 0xb], cl       
  0x0106C3E6  0000                    add      byte ptr [eax], al             
  0x0106C3E8  03f0                    add      esi, eax                       
  0x0106C3EA  44                      inc      esp                            
  0x0106C3EB  00500b                  add      byte ptr [eax + 0xb], dl       
  0x0106C3EE  0000                    add      byte ptr [eax], al             
  0x0106C3F0  02a40500005844          add      ah, byte ptr [ebp + eax + 0x44580000] 
  0x0106C3F7  0000                    add      byte ptr [eax], al             
  0x0106C3F9  f4                      hlt                                     
  0x0106C3FA  57                      push     edi                            
  0x0106C3FB  0010                    add      byte ptr [eax], dl             
  0x0106C3FD  0000                    add      byte ptr [eax], al             
  0x0106C3FF  0080100d00a6            add      byte ptr [eax - 0x59fff2f0], al 
  0x0106C405  0100                    add      dword ptr [eax], eax           
  0x0106C407  0000                    add      byte ptr [eax], al             
  0x0106C409  f4                      hlt                                     
  0x0106C40A  44                      inc      esp                            
  0x0106C40B  0000                    add      byte ptr [eax], al             
  0x0106C40D  0000                    add      byte ptr [eax], al             
  0x0106C40F  004500                  add      byte ptr [ebp], al             
  0x0106C412  2000                    and      byte ptr [eax], al             
  0x0106C414  00740500                add      byte ptr [ebp + eax], dh       
  0x0106C418  005820                  add      byte ptr [eax + 0x20], bl      
  0x0106C41B  0000                    add      byte ptr [eax], al             
  0x0106C41D  d85600                  fcom     dword ptr [esi]                
  0x0106C420  00f0                    add      al, dh                         
  0x0106C422  57                      push     edi                            
  0x0106C423  00fb                    add      bl, bh                         
  0x0106C425  0000                    add      byte ptr [eax], al             
  0x0106C427  000b                    add      byte ptr [ebx], cl             
  0x0106C429  f4                      hlt                                     
  0x0106C42A  44                      inc      esp                            
  0x0106C42B  000400                  add      byte ptr [eax + eax], al       
  0x0106C42E  0000                    add      byte ptr [eax], al             
  0x0106C430  40                      inc      eax                            
  0x0106C431  2a20                    sub      ah, byte ptr [eax]             
  0x0106C433  0000                    add      byte ptr [eax], al             
  0x0106C436  57                      push     edi                            
  0x0106C437  004f0b                  add      byte ptr [edi + 0xb], cl       
  0x0106C43A  0000                    add      byte ptr [eax], al             
  0x0106C43C  0bf4                    or       esi, esp                       
  0x0106C43E  44                      inc      esp                            
  0x0106C43F  0001                    add      byte ptr [ecx], al             
  0x0106C441  0000                    add      byte ptr [eax], al             
  0x0106C443  004022                  add      byte ptr [eax + 0x22], al      
  0x0106C446  2000                    and      byte ptr [eax], al             
  0x0106C448  0000                    add      byte ptr [eax], al             
  0x0106C44A  2400                    and      al, 0                          
  0x0106C44C  0000                    add      byte ptr [eax], al             
  0x0106C44E  250000f460              and      eax, 0x60f40000                
  0x0106C453  001f                    add      byte ptr [edi], bl             
  0x0106C455  0000                    add      byte ptr [eax], al             
  0x0106C457  0080cc0c0007            add      byte ptr [eax + 0x7000ccc], al 
  0x0106C45D  0000                    add      byte ptr [eax], al             
  0x0106C45F  0040cc                  add      byte ptr [eax - 0x34], al      
  0x0106C462  0a00                    or       al, byte ptr [eax]             
  0x0106C464  0098210000f4            add      byte ptr [eax - 0xbffffdf], bl 
  0x0106C46A  44                      inc      esp                            
  0x0106C46B  0001                    add      byte ptr [ecx], al             
  0x0106C46D  0000                    add      byte ptr [eax], al             
  0x0106C46F  0000                    add      byte ptr [eax], al             
  0x0106C471  e845000070              call     0x7106c4bb                     
  0x0106C476  44                      inc      esp                            
  0x0106C477  004f0b                  add      byte ptr [edi + 0xb], cl       
  0x0106C47A  0000                    add      byte ptr [eax], al             
  0x0106C47C  007045                  add      byte ptr [eax + 0x45], dh      
  0x0106C47F  00500b                  add      byte ptr [eax + 0xb], dl       
  0x0106C482  0000                    add      byte ptr [eax], al             
  0x0106C484  0084210000f056          add      byte ptr [ecx + 0x56f00000], al 
  0x0106C48B  00fb                    add      bl, bh                         
  0x0106C48D  0000                    add      byte ptr [eax], al             
  0x0106C48F  0080100d0036            add      byte ptr [eax + 0x36000d10], al 
  0x0106C495  06                      push     es                             
  0x0106C496  0000                    add      byte ptr [eax], al             
  0x0106C498  0c00                    or       al, 0                          
  0x0106C49A  0000                    add      byte ptr [eax], al             
  0x0106C49C  61                      popal                                   
  0x0106C49D  f4                      hlt                                     
  0x0106C49E  46                      inc      esi                            
  0x0106C49F  0010                    add      byte ptr [eax], dl             
  0x0106C4A1  0000                    add      byte ptr [eax], al             
  0x0106C4A3  0000                    add      byte ptr [eax], al             
  0x0106C4A5  07                      pop      es                             
  0x0106C4A6  2300                    and      eax, dword ptr [eax]           
  0x0106C4A8  10d9                    adc      cl, bl                         
  0x0106C4AA  06                      push     es                             
  0x0106C4AB  000a                    add      byte ptr [edx], cl             
  0x0106C4AD  0000                    add      byte ptr [eax], al             
  0x0106C4AF  007cd950                add      byte ptr [ecx + ebx*8 + 0x50], bh 
  0x0106C4B3  0007                    add      byte ptr [edi], al             
  0x0106C4B5  7405                    je       0x106c4bc                      
  0x0106C4B7  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x0106C4BA  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x0106C4B5 (cond_jump)
  0x0106C4BC  46                      inc      esi                            
  0x0106C4BD  1e                      push     ds                             
  0x0106C4BE  0c00                    or       al, 0                          
  0x0106C4C0  90                      nop                                     
  0x0106C4C1  1e                      push     ds                             
  0x0106C4C2  0c00                    or       al, 0                          
  0x0106C4C4  49                      dec      ecx                            
  0x0106C4C5  e421                    in       al, 0x21                       
  0x0106C4C7  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106C4CA  54                      push     esp                            
  0x0106C4CB  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106C4CE  0c00                    or       al, 0                          
  0x0106C4D0  4e                      dec      esi                            
  0x0106C4D1  1e                      push     ds                             
  0x0106C4D2  0c00                    or       al, 0                          
  0x0106C4D4  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x0106C4DA  0000                    add      byte ptr [eax], al             
  0x0106C4DC  61                      popal                                   
  0x0106C4DD  f4                      hlt                                     
                                        ; XREF: 0x0106C530 (cond_jump)
  0x0106C4DE  46                      inc      esi                            
  0x0106C4DF  0010                    add      byte ptr [eax], dl             
  0x0106C4E1  0000                    add      byte ptr [eax], al             
  0x0106C4E3  0000                    add      byte ptr [eax], al             
  0x0106C4E5  07                      pop      es                             
  0x0106C4E6  2300                    and      eax, dword ptr [eax]           
  0x0106C4E8  7cd9                    jl       0x106c4c3                      
  0x0106C4EA  50                      push     eax                            
  0x0106C4EB  0007                    add      byte ptr [edi], al             
  0x0106C4ED  7405                    je       0x106c4f4                      
  0x0106C4EF  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x0106C4F2  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x0106C4ED (cond_jump)
  0x0106C4F4  46                      inc      esi                            
  0x0106C4F5  1e                      push     ds                             
  0x0106C4F6  0c00                    or       al, 0                          
  0x0106C4F8  90                      nop                                     
  0x0106C4F9  1e                      push     ds                             
  0x0106C4FA  0c00                    or       al, 0                          
  0x0106C4FC  49                      dec      ecx                            
  0x0106C4FD  e421                    in       al, 0x21                       
  0x0106C4FF  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106C502  54                      push     esp                            
  0x0106C503  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106C506  0c00                    or       al, 0                          
  0x0106C508  4e                      dec      esi                            
  0x0106C509  1e                      push     ds                             
  0x0106C50A  0c00                    or       al, 0                          
  0x0106C50C  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x0106C512  0000                    add      byte ptr [eax], al             
  0x0106C514  00f4                    add      ah, dh                         
  0x0106C516  46                      inc      esi                            
  0x0106C517  0010                    add      byte ptr [eax], dl             
  0x0106C519  0000                    add      byte ptr [eax], al             
  0x0106C51B  0000                    add      byte ptr [eax], al             
  0x0106C51D  07                      pop      es                             
  0x0106C51E  2300                    and      eax, dword ptr [eax]           
  0x0106C520  10d9                    adc      cl, bl                         
  0x0106C522  06                      push     es                             
  0x0106C523  000d00000000            add      byte ptr [0], cl               
  0x0106C529  d95600                  fst      dword ptr [esi]                
  0x0106C52C  6e                      outsb    dx, byte ptr [esi]             
  0x0106C52D  1e                      push     ds                             
  0x0106C52E  0c00                    or       al, 0                          
  0x0106C530  7cac                    jl       0x106c4de                      
  0x0106C532  2000                    and      byte ptr [eax], al             
  0x0106C534  07                      pop      es                             
  0x0106C535  7405                    je       0x106c53c                      
  0x0106C537  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x0106C53A  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x0106C535 (cond_jump)
  0x0106C53C  46                      inc      esi                            
  0x0106C53D  1e                      push     ds                             
  0x0106C53E  0c00                    or       al, 0                          
  0x0106C540  90                      nop                                     
  0x0106C541  1e                      push     ds                             
  0x0106C542  0c00                    or       al, 0                          
  0x0106C544  49                      dec      ecx                            
  0x0106C545  e421                    in       al, 0x21                       
  0x0106C547  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106C54A  54                      push     esp                            
  0x0106C54B  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106C54E  0c00                    or       al, 0                          
  0x0106C550  4e                      dec      esi                            
  0x0106C551  1e                      push     ds                             
  0x0106C552  0c00                    or       al, 0                          
  0x0106C554  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x0106C55A  0000                    add      byte ptr [eax], al             
  0x0106C55C  00f4                    add      ah, dh                         
  0x0106C55E  46                      inc      esi                            
  0x0106C55F  0010                    add      byte ptr [eax], dl             
  0x0106C561  0000                    add      byte ptr [eax], al             
  0x0106C563  0000                    add      byte ptr [eax], al             
  0x0106C565  07                      pop      es                             
                                        ; XREF: 0x0106C5B8 (cond_jump)
  0x0106C566  2300                    and      eax, dword ptr [eax]           
  0x0106C568  10d9                    adc      cl, bl                         
  0x0106C56A  06                      push     es                             
  0x0106C56B  000d00000000            add      byte ptr [0], cl               
  0x0106C571  d95e00                  fstp     dword ptr [esi]                
  0x0106C574  6e                      outsb    dx, byte ptr [esi]             
  0x0106C575  1e                      push     ds                             
  0x0106C576  0c00                    or       al, 0                          
  0x0106C578  7cac                    jl       0x106c526                      
  0x0106C57A  2000                    and      byte ptr [eax], al             
  0x0106C57C  07                      pop      es                             
  0x0106C57D  7405                    je       0x106c584                      
  0x0106C57F  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x0106C582  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x0106C57D (cond_jump)
  0x0106C584  46                      inc      esi                            
  0x0106C585  1e                      push     ds                             
  0x0106C586  0c00                    or       al, 0                          
  0x0106C588  90                      nop                                     
  0x0106C589  1e                      push     ds                             
  0x0106C58A  0c00                    or       al, 0                          
  0x0106C58C  49                      dec      ecx                            
  0x0106C58D  e421                    in       al, 0x21                       
  0x0106C58F  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106C592  54                      push     esp                            
  0x0106C593  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106C596  0c00                    or       al, 0                          
  0x0106C598  4e                      dec      esi                            
  0x0106C599  1e                      push     ds                             
  0x0106C59A  0c00                    or       al, 0                          
  0x0106C59C  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x0106C5A2  0000                    add      byte ptr [eax], al             
  0x0106C5A4  00f4                    add      ah, dh                         
                                        ; XREF: 0x0106C5F8 (cond_jump)
  0x0106C5A6  46                      inc      esi                            
  0x0106C5A7  0010                    add      byte ptr [eax], dl             
  0x0106C5A9  0000                    add      byte ptr [eax], al             
  0x0106C5AB  0000                    add      byte ptr [eax], al             
  0x0106C5AD  07                      pop      es                             
  0x0106C5AE  2300                    and      eax, dword ptr [eax]           
  0x0106C5B0  00d9                    add      cl, bl                         
  0x0106C5B2  56                      push     esi                            
  0x0106C5B3  006e1e                  add      byte ptr [esi + 0x1e], ch      
  0x0106C5B6  0c00                    or       al, 0                          
  0x0106C5B8  7cac                    jl       0x106c566                      
  0x0106C5BA  2000                    and      byte ptr [eax], al             
  0x0106C5BC  07                      pop      es                             
  0x0106C5BD  7405                    je       0x106c5c4                      
  0x0106C5BF  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x0106C5C2  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x0106C5BD (cond_jump)
  0x0106C5C4  46                      inc      esi                            
  0x0106C5C5  1e                      push     ds                             
  0x0106C5C6  0c00                    or       al, 0                          
  0x0106C5C8  90                      nop                                     
  0x0106C5C9  1e                      push     ds                             
  0x0106C5CA  0c00                    or       al, 0                          
  0x0106C5CC  49                      dec      ecx                            
  0x0106C5CD  e421                    in       al, 0x21                       
  0x0106C5CF  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106C5D2  54                      push     esp                            
  0x0106C5D3  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106C5D6  0c00                    or       al, 0                          
  0x0106C5D8  4e                      dec      esi                            
  0x0106C5D9  1e                      push     ds                             
  0x0106C5DA  0c00                    or       al, 0                          
  0x0106C5DC  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x0106C5E2  0000                    add      byte ptr [eax], al             
  0x0106C5E4  00f4                    add      ah, dh                         
  0x0106C5E6  46                      inc      esi                            
  0x0106C5E7  0010                    add      byte ptr [eax], dl             
  0x0106C5E9  0000                    add      byte ptr [eax], al             
  0x0106C5EB  0000                    add      byte ptr [eax], al             
  0x0106C5ED  07                      pop      es                             
  0x0106C5EE  2300                    and      eax, dword ptr [eax]           
  0x0106C5F0  00d9                    add      cl, bl                         
  0x0106C5F2  5e                      pop      esi                            
  0x0106C5F3  006e1e                  add      byte ptr [esi + 0x1e], ch      
  0x0106C5F6  0c00                    or       al, 0                          
  0x0106C5F8  7cac                    jl       0x106c5a6                      
  0x0106C5FA  2000                    and      byte ptr [eax], al             
  0x0106C5FC  07                      pop      es                             
  0x0106C5FD  7405                    je       0x106c604                      
  0x0106C5FF  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x0106C602  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x0106C5FD (cond_jump)
  0x0106C604  46                      inc      esi                            
  0x0106C605  1e                      push     ds                             
  0x0106C606  0c00                    or       al, 0                          
  0x0106C608  90                      nop                                     
  0x0106C609  1e                      push     ds                             
  0x0106C60A  0c00                    or       al, 0                          
  0x0106C60C  49                      dec      ecx                            
  0x0106C60D  e421                    in       al, 0x21                       
  0x0106C60F  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106C612  54                      push     esp                            
  0x0106C613  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106C616  0c00                    or       al, 0                          
  0x0106C618  4e                      dec      esi                            
  0x0106C619  1e                      push     ds                             
  0x0106C61A  0c00                    or       al, 0                          
  0x0106C61C  008521000c00            add      byte ptr [ebp + 0xc0021], al   
  0x0106C622  0000                    add      byte ptr [eax], al             
  0x0106C624  00f4                    add      ah, dh                         
  0x0106C626  61                      popal                                   
  0x0106C627  0012                    add      byte ptr [edx], dl             
  0x0106C629  0d000000f4              or       eax, 0xf4000000                
  0x0106C62E  46                      inc      esi                            
  0x0106C62F  00ff                    add      bh, bh                         
  0x0106C631  0000                    add      byte ptr [eax], al             
  0x0106C633  0010                    add      byte ptr [eax], dl             
  0x0106C635  d806                    fadd     dword ptr [esi]                
  0x0106C637  000e                    add      byte ptr [esi], cl             
  0x0106C639  0000                    add      byte ptr [eax], al             
  0x0106C63B  00901c0c0056            add      byte ptr [eax + 0x56000c1c], dl 
  0x0106C641  0020                    add      byte ptr [eax], ah             
  0x0106C643  0000                    add      byte ptr [eax], al             
  0x0106C645  d85100                  fcom     dword ptr [ecx]                
  0x0106C648  00992100911d            add      byte ptr [ecx + 0x1d910021], bl 
  0x0106C64E  0c00                    or       al, 0                          
  0x0106C650  00e9                    add      cl, ch                         
  0x0106C652  4c                      dec      esp                            
  0x0106C653  004b00                  add      byte ptr [ebx], cl             
  0x0106C656  2000                    and      byte ptr [eax], al             
  0x0106C658  90                      nop                                     
  0x0106C659  1c0c                    sbb      al, 0xc                        
  0x0106C65B  005600                  add      byte ptr [esi], dl             
  0x0106C65E  2000                    and      byte ptr [eax], al             
  0x0106C660  00992100911d            add      byte ptr [ecx + 0x1d910021], bl 
  0x0106C666  0c00                    or       al, 0                          
  0x0106C668  00e9                    add      cl, ch                         
  0x0106C66A  4c                      dec      esp                            
  0x0106C66B  004b00                  add      byte ptr [ebx], cl             
  0x0106C66E  2000                    and      byte ptr [eax], al             
  0x0106C670  91                      xchg     ecx, eax                       
  0x0106C671  1e                      push     ds                             
  0x0106C672  0c00                    or       al, 0                          
  0x0106C674  00ae2100111c            add      byte ptr [esi + 0x1c110021], ch 
  0x0106C67A  0c00                    or       al, 0                          
  0x0106C67C  0c00                    or       al, 0                          
  0x0106C67E  0000                    add      byte ptr [eax], al             
  0x0106C680  1bf4                    sbb      esi, esp                       
  0x0106C682  61                      popal                                   
  0x0106C683  0012                    add      byte ptr [edx], dl             
  0x0106C685  0e                      push     cs                             
  0x0106C686  0000                    add      byte ptr [eax], al             
  0x0106C688  00f4                    add      ah, dh                         
  0x0106C68A  46                      inc      esi                            
  0x0106C68B  00ff                    add      bh, bh                         
  0x0106C68D  0000                    add      byte ptr [eax], al             
  0x0106C68F  0000                    add      byte ptr [eax], al             
  0x0106C691  48                      dec      eax                            
  0x0106C692  2000                    and      byte ptr [eax], al             
  0x0106C694  10d8                    adc      al, bl                         
  0x0106C696  06                      push     es                             
  0x0106C697  000d0000005e            add      byte ptr [0x5e000000], cl      
  0x0106C69D  ae                      scasb    al, byte ptr es:[edi]          
  0x0106C69E  2100                    and      dword ptr [eax], eax           
  0x0106C6A0  00f8                    add      al, bh                         
  0x0106C6A2  44                      inc      esp                            
  0x0106C6A3  0000                    add      byte ptr [eax], al             
  0x0106C6A5  b92100d01e              mov      ecx, 0x1ed00021                
  0x0106C6AA  0c00                    or       al, 0                          
  0x0106C6AC  42                      inc      edx                            
  0x0106C6AD  0020                    add      byte ptr [eax], ah             
  0x0106C6AF  0000                    add      byte ptr [eax], al             
  0x0106C6B1  e94c004300              jmp      0x149c702                      
  0x0106C6B6  2000                    and      byte ptr [eax], al             
  0x0106C6B8  56                      push     esi                            
  0x0106C6BA  2100                    and      dword ptr [eax], eax           
  0x0106C6BC  00992100d11e            add      byte ptr [ecx + 0x1ed10021], bl 
  0x0106C6C2  0c00                    or       al, 0                          
  0x0106C6C4  00e9                    add      cl, ch                         
  0x0106C6C6  4c                      dec      esp                            
  0x0106C6C7  004b00                  add      byte ptr [ebx], cl             
  0x0106C6CA  2000                    and      byte ptr [eax], al             
  0x0106C6CC  91                      xchg     ecx, eax                       
  0x0106C6CD  1e                      push     ds                             
  0x0106C6CE  0c00                    or       al, 0                          
  0x0106C6D0  00ae2100111c            add      byte ptr [esi + 0x1c110021], ch 
  0x0106C6D6  0c00                    or       al, 0                          
  0x0106C6D8  0c00                    or       al, 0                          
  0x0106C6DA  0000                    add      byte ptr [eax], al             
  0x0106C6DC  7904                    jns      0x106c6e2                      
  0x0106C6DE  0000                    add      byte ptr [eax], al             
  0x0106C6E0  fa                      cli                                     
  0x0106C6E1  0300                    add      eax, dword ptr [eax]           
  0x0106C6E3  0017                    add      byte ptr [edi], dl             
  0x0106C6E5  0400                    add      al, 0                          
  0x0106C6E7  003404                  add      byte ptr [esp + eax], dh       
  0x0106C6EA  0000                    add      byte ptr [eax], al             
  0x0106C6EC  3b0400                  cmp      eax, dword ptr [eax + eax]     
  0x0106C6EF  00540400                add      byte ptr [esp + eax], dl       
  0x0106C6F3  005b04                  add      byte ptr [ebx + 4], bl         
  0x0106C6F6  0000                    add      byte ptr [eax], al             
  0x0106C6F8  5e                      pop      esi                            
  0x0106C6F9  0400                    add      al, 0                          
  0x0106C6FB  006104                  add      byte ptr [ecx + 4], ah         
  0x0106C6FE  0000                    add      byte ptr [eax], al             
  0x0106C700  640400                  add      al, 0                          
  0x0106C703  006704                  add      byte ptr [edi + 4], ah         
  0x0106C706  0000                    add      byte ptr [eax], al             
  0x0106C708  6a04                    push     4                              
  0x0106C70A  0000                    add      byte ptr [eax], al             
  0x0106C70C  6d                      insd     dword ptr es:[edi], dx         
  0x0106C70D  0400                    add      al, 0                          
  0x0106C70F  007004                  add      byte ptr [eax + 4], dh         
  0x0106C712  0000                    add      byte ptr [eax], al             
  0x0106C714  7304                    jae      0x106c71a                      
  0x0106C716  0000                    add      byte ptr [eax], al             
  0x0106C718  7604                    jbe      0x106c71e                      
                                        ; XREF: 0x0106C714 (cond_jump)
  0x0106C71A  0000                    add      byte ptr [eax], al             
  0x0106C71C  00f4                    add      ah, dh                         
                                        ; XREF: 0x0106C718 (cond_jump)
  0x0106C71E  7400                    je       0x106c720                      
                                        ; XREF: 0x0106C71E (cond_jump)
  0x0106C720  e103                    loope    0x106c725                      
  0x0106C722  0000                    add      byte ptr [eax], al             
  0x0106C724  10d8                    adc      al, bl                         
  0x0106C726  06                      push     es                             
  0x0106C727  008600000000            add      byte ptr [esi], al             
  0x0106C72D  dd640000                frstor   dword ptr [eax + eax]          
  0x0106C731  e056                    loopne   0x106c789                      
  0x0106C733  0096ec070000            add      byte ptr [esi + 0x7ec], dl     
  0x0106C739  8521                    test     dword ptr [ecx], esp           
  0x0106C73B  0080e60a0000            add      byte ptr [eax + 0xae6], al     
  0x0106C741  f4                      hlt                                     
  0x0106C742  44                      inc      esp                            
  0x0106C743  0003                    add      byte ptr [ebx], al             
  0x0106C745  0000                    add      byte ptr [eax], al             
  0x0106C747  00a0f4620005            add      byte ptr [eax + 0x50062f4], ah 
  0x0106C74D  0000                    add      byte ptr [eax], al             
  0x0106C74F  0040f0                  add      byte ptr [eax - 0x10], al      
  0x0106C752  7200                    jb       0x106c754                      
                                        ; XREF: 0x0106C752 (cond_jump)
  0x0106C754  0200                    add      al, byte ptr [eax]             
  0x0106C756  0000                    add      byte ptr [eax], al             
  0x0106C758  224f23                  and      cl, byte ptr [edi + 0x23]      
  0x0106C75B  000b                    add      byte ptr [ebx], cl             
  0x0106C75D  0139                    add      dword ptr [ecx], edi           
  0x0106C75F  0000                    add      byte ptr [eax], al             
  0x0106C761  6a54                    push     0x54                           
  0x0106C763  000424                  add      byte ptr [esp], al             
  0x0106C766  0500007060              add      eax, 0x60700000                
  0x0106C76B  000d0000000e            add      byte ptr [0xe000000], cl       
  0x0106C771  0c05                    or       al, 5                          
  0x0106C773  0000                    add      byte ptr [eax], al             
  0x0106C775  f4                      hlt                                     
  0x0106C776  66000a                  add      byte ptr [edx], cl             
  0x0106C779  0d00000024              or       eax, 0x24000000                
  0x0106C77E  2300                    and      eax, dword ptr [eax]           
  0x0106C780  4d                      dec      ebp                            
  0x0106C781  0239                    add      bh, byte ptr [ecx]             
  0x0106C783  0009                    add      byte ptr [ecx], cl             
  0x0106C785  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106C786  050000daf0              add      eax, 0xf0da0000                
  0x0106C78B  00d0                    add      al, dl                         
  0x0106C78F  00d2                    add      dl, dl                         
  0x0106C793  00d2                    add      dl, dl                         
  0x0106C795  f066000d00000024        lock add byte ptr [0x24000000], cl      
  0x0106C79D  1d0c000000              sbb      eax, 0xc                       
  0x0106C7A2  3900                    cmp      dword ptr [eax], eax           
  0x0106C7A4  006650                  add      byte ptr [esi + 0x50], ah      
  0x0106C7A7  0013                    add      byte ptr [ebx], dl             
  0x0106C7A9  7071                    jo       0x106c81c                      
  0x0106C7AB  0002                    add      byte ptr [edx], al             
  0x0106C7AD  0000                    add      byte ptr [eax], al             
  0x0106C7AF  00c3                    add      bl, al                         
  0x0106C7B1  0c05                    or       al, 5                          
  0x0106C7B3  0000                    add      byte ptr [eax], al             
  0x0106C7B5  f4                      hlt                                     
  0x0106C7B6  44                      inc      esp                            
  0x0106C7B7  0005000000a0            add      byte ptr [0xa0000000], al      
  0x0106C7BD  f4                      hlt                                     
  0x0106C7BE  6200                    bound    eax, qword ptr [eax]           
  0x0106C7C0  0800                    or       byte ptr [eax], al             
  0x0106C7C2  0000                    add      byte ptr [eax], al             
  0x0106C7C4  40                      inc      eax                            
  0x0106C7C6  7200                    jb       0x106c7c8                      
                                        ; XREF: 0x0106C7C6 (cond_jump)
  0x0106C7C8  0300                    add      eax, dword ptr [eax]           
  0x0106C7CA  0000                    add      byte ptr [eax], al             
  0x0106C7CC  224f23                  and      cl, byte ptr [edi + 0x23]      
  0x0106C7CF  000b                    add      byte ptr [ebx], cl             
  0x0106C7D1  0139                    add      dword ptr [ecx], edi           
  0x0106C7D3  0000                    add      byte ptr [eax], al             
  0x0106C7D5  6a54                    push     0x54                           
  0x0106C7D7  000424                  add      byte ptr [esp], al             
  0x0106C7DA  0500007060              add      eax, 0x60700000                
  0x0106C7DF  000e                    add      byte ptr [esi], cl             
  0x0106C7E1  0000                    add      byte ptr [eax], al             
  0x0106C7E3  000e                    add      byte ptr [esi], cl             
  0x0106C7E5  0c05                    or       al, 5                          
  0x0106C7E7  0000                    add      byte ptr [eax], al             
  0x0106C7E9  f4                      hlt                                     
  0x0106C7EA  66000d0d000000          add      byte ptr [0xd], cl             
  0x0106C7F1  2423                    and      al, 0x23                       
  0x0106C7F3  004d02                  add      byte ptr [ebp + 2], cl         
  0x0106C7F6  3900                    cmp      dword ptr [eax], eax           
  0x0106C7F8  09a4050000daf0          or       dword ptr [ebp + eax - 0xf260000], esp 
  0x0106C7FF  00d0                    add      al, dl                         
  0x0106C803  00d2                    add      dl, dl                         
  0x0106C807  00d2                    add      dl, dl                         
  0x0106C809  f066000e                lock add byte ptr [esi], cl             
  0x0106C80D  0000                    add      byte ptr [eax], al             
  0x0106C80F  0020                    add      byte ptr [eax], ah             
  0x0106C811  1d0c000000              sbb      eax, 0xc                       
  0x0106C816  3900                    cmp      dword ptr [eax], eax           
  0x0106C818  006650                  add      byte ptr [esi + 0x50], ah      
  0x0106C81B  0013                    add      byte ptr [ebx], dl             
  0x0106C81D  7071                    jo       0x106c890                      
  0x0106C81F  0003                    add      byte ptr [ebx], al             
  0x0106C821  0000                    add      byte ptr [eax], al             
  0x0106C823  00860c050000            add      byte ptr [esi + 0x50c], al     
  0x0106C829  f4                      hlt                                     
  0x0106C82A  44                      inc      esp                            
  0x0106C82B  0007                    add      byte ptr [edi], al             
  0x0106C82D  0000                    add      byte ptr [eax], al             
  0x0106C82F  00a000200040            add      byte ptr [eax + 0x40002000], ah 
  0x0106C835  0020                    add      byte ptr [eax], ah             
  0x0106C837  0038                    add      byte ptr [eax], bh             
  0x0106C839  1d0c00101c              sbb      eax, 0x1c10000c                
  0x0106C83E  0c00                    or       al, 0                          
  0x0106C840  5f                      pop      edi                            
  0x0106C841  0c05                    or       al, 5                          
  0x0106C843  0000                    add      byte ptr [eax], al             
  0x0106C845  f4                      hlt                                     
  0x0106C846  44                      inc      esp                            
  0x0106C847  000b                    add      byte ptr [ebx], cl             
  0x0106C849  0000                    add      byte ptr [eax], al             
  0x0106C84B  00a0f462000b            add      byte ptr [eax + 0xb0062f4], ah 
  0x0106C851  0000                    add      byte ptr [eax], al             
  0x0106C853  0040f0                  add      byte ptr [eax - 0x10], al      
  0x0106C856  7200                    jb       0x106c858                      
                                        ; XREF: 0x0106C856 (cond_jump)
  0x0106C858  0400                    add      al, 0                          
  0x0106C85A  0000                    add      byte ptr [eax], al             
  0x0106C85C  224f23                  and      cl, byte ptr [edi + 0x23]      
  0x0106C85F  000b                    add      byte ptr [ebx], cl             
  0x0106C861  0139                    add      dword ptr [ecx], edi           
  0x0106C863  0000                    add      byte ptr [eax], al             
  0x0106C865  f4                      hlt                                     
  0x0106C866  660010                  add      byte ptr [eax], dl             
  0x0106C869  0d0000006a              or       eax, 0x6a000000                
  0x0106C86E  54                      push     esp                            
  0x0106C86F  000424                  add      byte ptr [esp], al             
  0x0106C872  0500007060              add      eax, 0x60700000                
  0x0106C877  000f                    add      byte ptr [edi], cl             
  0x0106C879  0000                    add      byte ptr [eax], al             
  0x0106C87B  0008                    add      byte ptr [eax], cl             
  0x0106C87D  0c05                    or       al, 5                          
  0x0106C87F  0000                    add      byte ptr [eax], al             
  0x0106C883  00d0                    add      al, dl                         
  0x0106C887  00d2                    add      dl, dl                         
  0x0106C889  f066000f                lock add byte ptr [edi], cl             
  0x0106C88D  0000                    add      byte ptr [eax], al             
  0x0106C88F  0020                    add      byte ptr [eax], ah             
  0x0106C891  1d0c000000              sbb      eax, 0xc                       
  0x0106C896  3900                    cmp      dword ptr [eax], eax           
  0x0106C898  006650                  add      byte ptr [esi + 0x50], ah      
  0x0106C89B  0013                    add      byte ptr [ebx], dl             
  0x0106C89D  7071                    jo       0x106c910                      
  0x0106C89F  000400                  add      byte ptr [eax + eax], al       
  0x0106C8A2  0000                    add      byte ptr [eax], al             
  0x0106C8A4  46                      inc      esi                            
  0x0106C8A5  0c05                    or       al, 5                          
  0x0106C8A7  0000                    add      byte ptr [eax], al             
  0x0106C8A9  f4                      hlt                                     
  0x0106C8AA  44                      inc      esp                            
  0x0106C8AB  000f                    add      byte ptr [edi], cl             
  0x0106C8AD  0000                    add      byte ptr [eax], al             
  0x0106C8AF  00a000200040            add      byte ptr [eax + 0x40002000], ah 
  0x0106C8B5  0020                    add      byte ptr [eax], ah             
  0x0106C8B7  0036                    add      byte ptr [esi], dh             
  0x0106C8B9  1d0c00101c              sbb      eax, 0x1c10000c                
  0x0106C8BE  0c00                    or       al, 0                          
  0x0106C8C0  1f                      pop      ds                             
  0x0106C8C1  0c05                    or       al, 5                          
  0x0106C8C3  0000                    add      byte ptr [eax], al             
  0x0106C8C5  f4                      hlt                                     
  0x0106C8C6  56                      push     esi                            
  0x0106C8C7  0000                    add      byte ptr [eax], al             
  0x0106C8C9  000400                  add      byte ptr [eax + eax], al       
  0x0106C8CC  1b0c050000f456          sbb      ecx, dword ptr [eax + 0x56f40000] 
  0x0106C8D3  0000                    add      byte ptr [eax], al             
  0x0106C8D5  0002                    add      byte ptr [edx], al             
  0x0106C8D7  0018                    add      byte ptr [eax], bl             
  0x0106C8D9  0c05                    or       al, 5                          
  0x0106C8DB  0000                    add      byte ptr [eax], al             
  0x0106C8DD  f4                      hlt                                     
  0x0106C8DE  56                      push     esi                            
  0x0106C8DF  0000                    add      byte ptr [eax], al             
  0x0106C8E1  0001                    add      byte ptr [ecx], al             
  0x0106C8E3  00150c050000            add      byte ptr [0x50c], dl           
  0x0106C8E9  f4                      hlt                                     
  0x0106C8EA  56                      push     esi                            
  0x0106C8EB  0000                    add      byte ptr [eax], al             
  0x0106C8ED  800000                  add      byte ptr [eax], 0              
  0x0106C8F0  120c050000f456          adc      cl, byte ptr [eax + 0x56f40000] 
  0x0106C8F7  0000                    add      byte ptr [eax], al             
  0x0106C8F9  40                      inc      eax                            
  0x0106C8FA  0000                    add      byte ptr [eax], al             
  0x0106C8FD  0c05                    or       al, 5                          
  0x0106C8FF  0000                    add      byte ptr [eax], al             
  0x0106C901  f4                      hlt                                     
  0x0106C902  56                      push     esi                            
  0x0106C903  0000                    add      byte ptr [eax], al             
  0x0106C905  2000                    and      byte ptr [eax], al             
  0x0106C907  000c0c                  add      byte ptr [esp + ecx], cl       
  0x0106C90A  050000f456              add      eax, 0x56f40000                
  0x0106C90F  0000                    add      byte ptr [eax], al             
  0x0106C911  1000                    adc      byte ptr [eax], al             
  0x0106C913  0009                    add      byte ptr [ecx], cl             
  0x0106C915  0c05                    or       al, 5                          
  0x0106C917  0000                    add      byte ptr [eax], al             
  0x0106C919  f4                      hlt                                     
  0x0106C91A  56                      push     esi                            
  0x0106C91B  0000                    add      byte ptr [eax], al             
  0x0106C91D  0800                    or       byte ptr [eax], al             
  0x0106C91F  0006                    add      byte ptr [esi], al             
  0x0106C921  0c05                    or       al, 5                          
  0x0106C923  0000                    add      byte ptr [eax], al             
  0x0106C925  f4                      hlt                                     
  0x0106C926  56                      push     esi                            
  0x0106C927  0000                    add      byte ptr [eax], al             
  0x0106C929  0400                    add      al, 0                          
  0x0106C92B  0003                    add      byte ptr [ebx], al             
  0x0106C92D  0c05                    or       al, 5                          
  0x0106C92F  0000                    add      byte ptr [eax], al             
  0x0106C931  f4                      hlt                                     
  0x0106C932  56                      push     esi                            
  0x0106C933  0000                    add      byte ptr [eax], al             
  0x0106C935  0100                    add      dword ptr [eax], eax           
  0x0106C937  006000                  add      byte ptr [eax], ah             
  0x0106C93A  2000                    and      byte ptr [eax], al             
  0x0106C93C  005856                  add      byte ptr [eax + 0x56], bl      
  0x0106C93F  000c00                  add      byte ptr [eax + eax], cl       
  0x0106C942  0000                    add      byte ptr [eax], al             
  0x0106C944  c6040000                mov      byte ptr [eax + eax], 0        
  0x0106C948  b204                    mov      dl, 4                          
  0x0106C94A  0000                    add      byte ptr [eax], al             
  0x0106C94C  a804                    test     al, 4                          
  0x0106C94E  0000                    add      byte ptr [eax], al             
  0x0106C950  bb0400009e              mov      ebx, 0x9e000004                
  0x0106C955  0400                    add      al, 0                          
  0x0106C957  00bb040000bb            add      byte ptr [ebx - 0x44fffffc], bh 
  0x0106C95D  0400                    add      al, 0                          
  0x0106C95F  00bb040000bb            add      byte ptr [ebx - 0x44fffffc], bh 
  0x0106C965  0400                    add      al, 0                          
  0x0106C967  00bb040000bb            add      byte ptr [ebx - 0x44fffffc], bh 
  0x0106C96D  0400                    add      al, 0                          
  0x0106C96F  00bb040000bb            add      byte ptr [ebx - 0x44fffffc], bh 
  0x0106C975  0400                    add      al, 0                          
  0x0106C977  00bb040000bb            add      byte ptr [ebx - 0x44fffffc], bh 
  0x0106C97D  0400                    add      al, 0                          
  0x0106C97F  00bb04000000            add      byte ptr [ebx + 4], bh         
  0x0106C986  6200                    bound    eax, qword ptr [eax]           
  0x0106C988  55                      push     ebp                            
  0x0106C989  0b00                    or       eax, dword ptr [eax]           
  0x0106C98B  0022                    add      byte ptr [edx], ah             
  0x0106C98E  0500470b00              add      eax, 0xb4700                   
  0x0106C993  0000                    add      byte ptr [eax], al             
  0x0106C996  56                      push     esi                            
  0x0106C997  00560b                  add      byte ptr [esi + 0xb], dl       
  0x0106C99A  0000                    add      byte ptr [eax], al             
  0x0106C99C  00f0                    add      al, dh                         
  0x0106C99E  45                      inc      ebp                            
  0x0106C99F  00570b                  add      byte ptr [edi + 0xb], dl       
  0x0106C9A2  0000                    add      byte ptr [eax], al             
  0x0106C9A4  00f4                    add      ah, dh                         
  0x0106C9A6  46                      inc      esi                            
  0x0106C9A7  0010                    add      byte ptr [eax], dl             
  0x0106C9A9  0000                    add      byte ptr [eax], al             
  0x0106C9AB  0000                    add      byte ptr [eax], al             
  0x0106C9AD  f4                      hlt                                     
  0x0106C9AE  7400                    je       0x106c9b0                      
                                        ; XREF: 0x0106C9AE (cond_jump)
  0x0106C9B0  7b04                    jnp      0x106c9b6                      
  0x0106C9B2  0000                    add      byte ptr [eax], al             
  0x0106C9B4  10d8                    adc      al, bl                         
                                        ; XREF: 0x0106C9B0 (cond_jump)
  0x0106C9B6  06                      push     es                             
  0x0106C9B7  002f                    add      byte ptr [edi], ch             
  0x0106C9B9  0000                    add      byte ptr [eax], al             
  0x0106C9BB  0000                    add      byte ptr [eax], al             
  0x0106C9BD  dd640096                frstor   dword ptr [eax + eax - 0x6a]   
  0x0106C9C1  ec                      in       al, dx                         
  0x0106C9C2  07                      pop      es                             
  0x0106C9C3  00c7                    add      bh, al                         
  0x0106C9C5  740b                    je       0x106c9d2                      
  0x0106C9C7  00fa                    add      dl, bh                         
  0x0106C9C9  0c00                    or       al, 0                          
  0x0106C9CB  0080e60a0000            add      byte ptr [eax + 0xae6], al     
                                        ; XREF: 0x0106C9C5 (cond_jump)
  0x0106C9D2  57                      push     edi                            
  0x0106C9D3  000400                  add      byte ptr [eax + eax], al       
  0x0106C9D6  0000                    add      byte ptr [eax], al             
  0x0106C9D8  8c4101                  mov      word ptr [ecx + 1], es         
  0x0106C9DB  0000                    add      byte ptr [eax], al             
  0x0106C9DD  7055                    jo       0x106ca34                      
  0x0106C9DF  000400                  add      byte ptr [eax + eax], al       
  0x0106C9E2  0000                    add      byte ptr [eax], al             
  0x0106C9E4  43                      inc      ebx                            
  0x0106C9E5  2405                    and      al, 5                          
  0x0106C9E7  0000                    add      byte ptr [eax], al             
  0x0106C9E9  0239                    add      bh, byte ptr [ecx]             
  0x0106C9EB  0000                    add      byte ptr [eax], al             
  0x0106C9ED  7071                    jo       0x106ca60                      
  0x0106C9EF  000400                  add      byte ptr [eax + eax], al       
  0x0106C9F2  0000                    add      byte ptr [eax], al             
  0x0106C9F4  140c                    adc      al, 0xc                        
  0x0106C9F6  050000f057              add      eax, 0x57f00000                
  0x0106C9FB  0003                    add      byte ptr [ebx], al             
  0x0106C9FD  0000                    add      byte ptr [eax], al             
  0x0106C9FF  008c4101000070          add      byte ptr [ecx + eax*2 + 0x70000001], cl 
  0x0106CA06  55                      push     ebp                            
  0x0106CA07  0003                    add      byte ptr [ebx], al             
  0x0106CA09  0000                    add      byte ptr [eax], al             
  0x0106CA0B  0019                    add      byte ptr [ecx], bl             
  0x0106CA0D  2405                    and      al, 5                          
  0x0106CA0F  0000                    add      byte ptr [eax], al             
  0x0106CA11  0339                    add      edi, dword ptr [ecx]           
  0x0106CA13  0000                    add      byte ptr [eax], al             
  0x0106CA15  7071                    jo       0x106ca88                      
  0x0106CA17  0003                    add      byte ptr [ebx], al             
  0x0106CA19  0000                    add      byte ptr [eax], al             
  0x0106CA1B  000a                    add      byte ptr [edx], cl             
  0x0106CA1D  0c05                    or       al, 5                          
  0x0106CA1F  0000                    add      byte ptr [eax], al             
  0x0106CA22  57                      push     edi                            
  0x0106CA23  0002                    add      byte ptr [edx], al             
  0x0106CA25  0000                    add      byte ptr [eax], al             
  0x0106CA27  008c4101000070          add      byte ptr [ecx + eax*2 + 0x70000001], cl 
  0x0106CA2E  55                      push     ebp                            
  0x0106CA2F  0002                    add      byte ptr [edx], al             
  0x0106CA31  0000                    add      byte ptr [eax], al             
  0x0106CA33  000f                    add      byte ptr [edi], cl             
  0x0106CA35  2405                    and      al, 5                          
  0x0106CA37  0000                    add      byte ptr [eax], al             
  0x0106CA39  0339                    add      edi, dword ptr [ecx]           
  0x0106CA3B  0000                    add      byte ptr [eax], al             
  0x0106CA3D  7071                    jo       0x106cab0                      
  0x0106CA3F  0002                    add      byte ptr [edx], al             
  0x0106CA41  0000                    add      byte ptr [eax], al             
  0x0106CA43  006900                  add      byte ptr [ecx], ch             
  0x0106CA46  2000                    and      byte ptr [eax], al             
  0x0106CA48  7ce0                    jl       0x106ca2a                      
  0x0106CA4A  50                      push     eax                            
  0x0106CA4B  0007                    add      byte ptr [edi], al             
  0x0106CA4D  7405                    je       0x106ca54                      
  0x0106CA4F  0078e4                  add      byte ptr [eax - 0x1c], bh      
  0x0106CA52  2100                    and      dword ptr [eax], eax           
                                        ; XREF: 0x0106CA4D (cond_jump)
  0x0106CA54  46                      inc      esi                            
  0x0106CA55  1e                      push     ds                             
  0x0106CA56  0c00                    or       al, 0                          
  0x0106CA58  90                      nop                                     
  0x0106CA59  1e                      push     ds                             
  0x0106CA5A  0c00                    or       al, 0                          
  0x0106CA5C  49                      dec      ecx                            
  0x0106CA5D  e421                    in       al, 0x21                       
  0x0106CA5F  00585a                  add      byte ptr [eax + 0x5a], bl      
  0x0106CA62  54                      push     esp                            
  0x0106CA63  00681e                  add      byte ptr [eax + 0x1e], ch      
  0x0106CA66  0c00                    or       al, 0                          
  0x0106CA68  4e                      dec      esi                            
  0x0106CA69  1e                      push     ds                             
  0x0106CA6A  0c00                    or       al, 0                          
  0x0106CA6C  00a521000058            add      byte ptr [ebp + 0x58000021], ah 
  0x0106CA72  2000                    and      byte ptr [eax], al             
  0x0106CA74  007054                  add      byte ptr [eax + 0x54], dh      
  0x0106CA77  00560b                  add      byte ptr [esi + 0xb], dl       
  0x0106CA7A  0000                    add      byte ptr [eax], al             
  0x0106CA7C  007045                  add      byte ptr [eax + 0x45], dh      
  0x0106CA7F  00570b                  add      byte ptr [edi + 0xb], dl       
  0x0106CA82  0000                    add      byte ptr [eax], al             
  0x0106CA84  007062                  add      byte ptr [eax + 0x62], dh      
  0x0106CA87  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x0106CA8A  0000                    add      byte ptr [eax], al             
  0x0106CA8C  22f4                    and      dh, ah                         
  0x0106CA8E  0500ffff00              add      eax, 0xffff00                  
  0x0106CA93  000c00                  add      byte ptr [eax + eax], cl       
  0x0106CA96  0000                    add      byte ptr [eax], al             
  0x0106CA98  20f4                    and      ah, dh                         
  0x0106CA9A  0500ffffff              add      eax, 0xffffff00                
  0x0106CA9F  00a0610400a0            add      byte ptr [eax - 0x5ffffb9f], ah 
  0x0106CAA5  620400                  bound    eax, qword ptr [eax + eax]     
  0x0106CAA8  a0640400a0              mov      al, byte ptr [0xa0000464]      
  0x0106CAAD  650400                  add      al, 0                          
                                        ; XREF: 0x0106CA3D (cond_jump)
  0x0106CAB0  a0660400b8              mov      al, byte ptr [0xb8000466]      
  0x0106CAB5  f30000                  add      byte ptr [eax], al             
  0x0106CAB8  00f4                    add      ah, dh                         
  0x0106CABA  44                      inc      esp                            
  0x0106CABB  0000                    add      byte ptr [eax], al             
  0x0106CABD  0000                    add      byte ptr [eax], al             
  0x0106CABF  004d00                  add      byte ptr [ebp], cl             
  0x0106CAC2  2000                    and      byte ptr [eax], al             
  0x0106CAC4  0ca4                    or       al, 0xa4                       
  0x0106CAC6  050000f444              add      eax, 0x44f40000                
  0x0106CACB  0010                    add      byte ptr [eax], dl             
  0x0106CACD  0000                    add      byte ptr [eax], al             
  0x0106CACF  004d00                  add      byte ptr [ebp], cl             
  0x0106CAD2  2000                    and      byte ptr [eax], al             
  0x0106CAD4  4a                      dec      edx                            
  0x0106CAD5  100d000f0000            adc      byte ptr [0xf00], cl           
  0x0106CADB  0000                    add      byte ptr [eax], al             
  0x0106CADD  0030                    add      byte ptr [eax], dh             
  0x0106CADF  0000                    add      byte ptr [eax], al             
  0x0106CAE1  f4                      hlt                                     
  0x0106CAE2  56                      push     esi                            
  0x0106CAE3  0000                    add      byte ptr [eax], al             
  0x0106CAE5  0000                    add      byte ptr [eax], al             
  0x0106CAE7  0000                    add      byte ptr [eax], al             
  0x0106CAE9  f4                      hlt                                     
  0x0106CAEA  57                      push     edi                            
  0x0106CAEB  00ff                    add      bh, bh                         
  0x0106CAEE  ff00                    inc      dword ptr [eax]                
  0x0106CAF0  0c00                    or       al, 0                          
  0x0106CAF2  0000                    add      byte ptr [eax], al             
  0x0106CAF4  1300                    adc      eax, dword ptr [eax]           
  0x0106CAF6  2000                    and      byte ptr [eax], al             
  0x0106CAF8  0000                    add      byte ptr [eax], al             
  0x0106CAFA  3000                    xor      byte ptr [eax], al             
  0x0106CAFC  00f4                    add      ah, dh                         
  0x0106CAFE  56                      push     esi                            
  0x0106CAFF  0000                    add      byte ptr [eax], al             
  0x0106CB01  0000                    add      byte ptr [eax], al             
  0x0106CB03  0000                    add      byte ptr [eax], al             
  0x0106CB05  f4                      hlt                                     
  0x0106CB06  57                      push     edi                            
  0x0106CB07  0008                    add      byte ptr [eax], cl             
  0x0106CB09  06                      push     es                             
  0x0106CB0A  0000                    add      byte ptr [eax], al             
  0x0106CB0C  0c00                    or       al, 0                          
  0x0106CB0E  0000                    add      byte ptr [eax], al             
  0x0106CB10  00f0                    add      al, dh                         
  0x0106CB12  56                      push     esi                            
  0x0106CB13  00960b000003            add      byte ptr [esi + 0x300000b], dl 
  0x0106CB19  0020                    add      byte ptr [eax], ah             
  0x0106CB1B  005874                  add      byte ptr [eax + 0x74], bl      
  0x0106CB1E  0500007060              add      eax, 0x60700000                
  0x0106CB23  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106CB26  0000                    add      byte ptr [eax], al             
  0x0106CB28  007060                  add      byte ptr [eax + 0x60], dh      
  0x0106CB2B  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x0106CB2E  0000                    add      byte ptr [eax], al             
  0x0106CB30  00f4                    add      ah, dh                         
  0x0106CB32  45                      inc      ebp                            
  0x0106CB33  00b007000000            add      byte ptr [eax + 7], dh         
  0x0106CB39  7045                    jo       0x106cb80                      
  0x0106CB3B  00720b                  add      byte ptr [edx + 0xb], dh       
  0x0106CB3E  0000                    add      byte ptr [eax], al             
  0x0106CB40  00f0                    add      al, dh                         
  0x0106CB42  56                      push     esi                            
  0x0106CB43  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106CB46  0000                    add      byte ptr [eax], al             
  0x0106CB48  0300                    add      eax, dword ptr [eax]           
  0x0106CB4A  2400                    and      al, 0                          
  0x0106CB4C  09240500007044          or       dword ptr [eax + 0x44700000], esp 
  0x0106CB53  00560b                  add      byte ptr [esi + 0xb], dl       
  0x0106CB56  0000                    add      byte ptr [eax], al             
  0x0106CB58  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106CB5B  00570b                  add      byte ptr [edi + 0xb], dl       
  0x0106CB5E  0000                    add      byte ptr [eax], al             
  0x0106CB60  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106CB63  009d0b000080            add      byte ptr [ebp - 0x7ffffff5], bl 
  0x0106CB69  100d008c0000            adc      byte ptr [0x8c00], cl          
  0x0106CB6F  0080100d0029            add      byte ptr [eax + 0x29000d10], al 
  0x0106CB75  0100                    add      dword ptr [eax], eax           
  0x0106CB77  0080100d009e            add      byte ptr [eax - 0x61fff2f0], al 
  0x0106CB7D  0100                    add      dword ptr [eax], eax           
  0x0106CB7F  0080100d0066            add      byte ptr [eax + 0x66000d10], al 
  0x0106CB85  0300                    add      eax, dword ptr [eax]           
  0x0106CB87  0000                    add      byte ptr [eax], al             
  0x0106CB8A  56                      push     esi                            
  0x0106CB8B  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106CB8E  0000                    add      byte ptr [eax], al             
  0x0106CB90  854501                  test     dword ptr [ebp + 1], eax       
  0x0106CB93  0003                    add      byte ptr [ebx], al             
  0x0106CB95  2405                    and      al, 5                          
  0x0106CB97  0080100d0093            add      byte ptr [eax - 0x6cfff2f0], al 
  0x0106CB9D  0300                    add      eax, dword ptr [eax]           
  0x0106CB9F  0000                    add      byte ptr [eax], al             
  0x0106CBA2  56                      push     esi                            
  0x0106CBA3  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x0106CBA6  0000                    add      byte ptr [eax], al             
  0x0106CBA8  00f0                    add      al, dh                         
  0x0106CBAA  44                      inc      esp                            
  0x0106CBAB  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106CBAE  0000                    add      byte ptr [eax], al             
  0x0106CBB0  44                      inc      esp                            
  0x0106CBB1  0020                    add      byte ptr [eax], ah             
  0x0106CBB3  0000                    add      byte ptr [eax], al             
  0x0106CBB5  7054                    jo       0x106cc0b                      
  0x0106CBB7  00580b                  add      byte ptr [eax + 0xb], bl       
  0x0106CBBA  0000                    add      byte ptr [eax], al             
  0x0106CBBC  80100d                  adc      byte ptr [eax], 0xd            
  0x0106CBBF  00d0                    add      al, dl                         
  0x0106CBC1  0300                    add      eax, dword ptr [eax]           
  0x0106CBC3  0000                    add      byte ptr [eax], al             
  0x0106CBC6  56                      push     esi                            
  0x0106CBC7  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106CBCA  0000                    add      byte ptr [eax], al             
  0x0106CBCC  854501                  test     dword ptr [ebp + 1], eax       
  0x0106CBCF  000b                    add      byte ptr [ebx], cl             
  0x0106CBD1  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106CBD2  050000f044              add      eax, 0x44f00000                
  0x0106CBD7  00580b                  add      byte ptr [eax + 0xb], bl       
  0x0106CBDA  0000                    add      byte ptr [eax], al             
  0x0106CBDC  00f4                    add      ah, dh                         
  0x0106CBDE  45                      inc      ebp                            
  0x0106CBDF  0010                    add      byte ptr [eax], dl             
  0x0106CBE1  0000                    add      byte ptr [eax], al             
  0x0106CBE3  00a0f044009d            add      byte ptr [eax - 0x62ffbb10], ah 
  0x0106CBE9  0b00                    or       eax, dword ptr [eax]           
  0x0106CBEB  002e                    add      byte ptr [esi], ch             
  0x0106CBED  1d0c004000              sbb      eax, 0x40000c                  
  0x0106CBF2  2000                    and      byte ptr [eax], al             
  0x0106CBF4  007056                  add      byte ptr [eax + 0x56], dh      
  0x0106CBF7  009d0b000080            add      byte ptr [ebp - 0x7ffffff5], bl 
  0x0106CBFD  100d00080000            adc      byte ptr [0x800], cl           
  0x0106CC03  000c00                  add      byte ptr [eax + eax], cl       
  0x0106CC06  0000                    add      byte ptr [eax], al             
  0x0106CC08  00f4                    add      ah, dh                         
  0x0106CC0A  44                      inc      esp                            
                                        ; XREF: 0x0106CBB5 (cond_jump)
  0x0106CC0B  0000                    add      byte ptr [eax], al             
  0x0106CC0D  0100                    add      dword ptr [eax], eax           
  0x0106CC0F  0000                    add      byte ptr [eax], al             
  0x0106CC11  7044                    jo       0x106cc57                      
  0x0106CC13  0010                    add      byte ptr [eax], dl             
  0x0106CC15  0000                    add      byte ptr [eax], al             
  0x0106CC17  000c00                  add      byte ptr [eax + eax], cl       
  0x0106CC1A  0000                    add      byte ptr [eax], al             
  0x0106CC1C  00f0                    add      al, dh                         
  0x0106CC1E  56                      push     esi                            
  0x0106CC1F  00960b000003            add      byte ptr [esi + 0x300000b], dl 
  0x0106CC25  0020                    add      byte ptr [eax], ah             
  0x0106CC27  0007                    add      byte ptr [edi], al             
  0x0106CC29  f4                      hlt                                     
  0x0106CC2A  050013f044              add      eax, 0x44f01300                
  0x0106CC2F  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106CC32  0000                    add      byte ptr [eax], al             
  0x0106CC34  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106CC37  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x0106CC3A  0000                    add      byte ptr [eax], al             
  0x0106CC3C  007054                  add      byte ptr [eax + 0x54], dh      
  0x0106CC3F  009a0b000000            add      byte ptr [edx + 0xb], bl       
  0x0106CC45  f4                      hlt                                     
  0x0106CC46  60                      pushal                                  
  0x0106CC47  0011                    add      byte ptr [ecx], dl             
  0x0106CC49  0000                    add      byte ptr [eax], al             
  0x0106CC4B  0000                    add      byte ptr [eax], al             
  0x0106CC4D  f4                      hlt                                     
  0x0106CC4E  44                      inc      esp                            
  0x0106CC4F  000d00000000            add      byte ptr [0], cl               
  0x0106CC55  58                      pop      eax                            
  0x0106CC56  44                      inc      esp                            
                                        ; XREF: 0x0106CC11 (cond_jump)
  0x0106CC57  0000                    add      byte ptr [eax], al             
  0x0106CC5A  56                      push     esi                            
  0x0106CC5B  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x0106CC5E  0000                    add      byte ptr [eax], al             
  0x0106CC60  00f0                    add      al, dh                         
  0x0106CC62  44                      inc      esp                            
  0x0106CC63  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106CC66  0000                    add      byte ptr [eax], al             
  0x0106CC68  44                      inc      esp                            
  0x0106CC69  0020                    add      byte ptr [eax], ah             
  0x0106CC6B  0000                    add      byte ptr [eax], al             
  0x0106CC6D  58                      pop      eax                            
  0x0106CC6E  54                      push     esp                            
  0x0106CC6F  0000                    add      byte ptr [eax], al             
  0x0106CC72  44                      inc      esp                            
  0x0106CC73  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x0106CC76  0000                    add      byte ptr [eax], al             
  0x0106CC78  005844                  add      byte ptr [eax + 0x44], bl      
  0x0106CC7B  0000                    add      byte ptr [eax], al             
  0x0106CC7D  002400                  add      byte ptr [eax + eax], ah       
  0x0106CC80  005844                  add      byte ptr [eax + 0x44], bl      
  0x0106CC83  0000                    add      byte ptr [eax], al             
  0x0106CC85  58                      pop      eax                            
  0x0106CC86  44                      inc      esp                            
  0x0106CC87  0000                    add      byte ptr [eax], al             
  0x0106CC89  58                      pop      eax                            
  0x0106CC8A  44                      inc      esp                            
  0x0106CC8B  0000                    add      byte ptr [eax], al             
  0x0106CC8D  58                      pop      eax                            
  0x0106CC8E  44                      inc      esp                            
  0x0106CC8F  0013                    add      byte ptr [ebx], dl             
  0x0106CC91  f4                      hlt                                     
  0x0106CC92  44                      inc      esp                            
  0x0106CC93  0009                    add      byte ptr [ecx], cl             
  0x0106CC95  0000                    add      byte ptr [eax], al             
  0x0106CC97  0000                    add      byte ptr [eax], al             
  0x0106CC99  7044                    jo       0x106ccdf                      
  0x0106CC9B  001e                    add      byte ptr [esi], bl             
  0x0106CC9D  0000                    add      byte ptr [eax], al             
  0x0106CC9F  0000                    add      byte ptr [eax], al             
  0x0106CCA2  44                      inc      esp                            
  0x0106CCA3  001e                    add      byte ptr [esi], bl             
  0x0106CCA5  0000                    add      byte ptr [eax], al             
  0x0106CCA7  004019                  add      byte ptr [eax + 0x19], al      
  0x0106CCAA  0c00                    or       al, 0                          
  0x0106CCAC  184000                  sbb      byte ptr [eax], al             
  0x0106CCAF  0000                    add      byte ptr [eax], al             
  0x0106CCB1  58                      pop      eax                            
  0x0106CCB2  54                      push     esp                            
  0x0106CCB3  0000                    add      byte ptr [eax], al             
  0x0106CCB5  002400                  add      byte ptr [eax + eax], ah       
  0x0106CCB8  005844                  add      byte ptr [eax + 0x44], bl      
  0x0106CCBB  001b                    add      byte ptr [ebx], bl             
  0x0106CCBD  0020                    add      byte ptr [eax], ah             
  0x0106CCBF  0013                    add      byte ptr [ebx], dl             
  0x0106CCC1  0020                    add      byte ptr [eax], ah             
  0x0106CCC3  00df                    add      bh, bl                         
  0x0106CCC5  1e                      push     ds                             
  0x0106CCC6  0c00                    or       al, 0                          
  0x0106CCC8  00a4210040190c          add      byte ptr [ecx + 0xc194000], ah 
  0x0106CCCF  0020                    add      byte ptr [eax], ah             
  0x0106CCD1  800000                  add      byte ptr [eax], 0              
  0x0106CCD4  1b00                    sbb      eax, dword ptr [eax]           
  0x0106CCD6  2000                    and      byte ptr [eax], al             
  0x0106CCD8  df1e                    fistp    word ptr [esi]                 
  0x0106CCDA  0c00                    or       al, 0                          
  0x0106CCDC  00a4210040190c          add      byte ptr [ecx + 0xc194000], ah 
  0x0106CCE3  0018                    add      byte ptr [eax], bl             
  0x0106CCE5  800000                  add      byte ptr [eax], 0              
  0x0106CCE8  005854                  add      byte ptr [eax + 0x54], bl      
  0x0106CCEB  0013                    add      byte ptr [ebx], dl             
  0x0106CCEE  57                      push     edi                            
  0x0106CCEF  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x0106CCF2  0000                    add      byte ptr [eax], al             
  0x0106CCF4  0bf4                    or       esi, esp                       
  0x0106CCF6  45                      inc      ebp                            
  0x0106CCF7  008000000007            add      byte ptr [eax + 0x7000000], al 
  0x0106CCFD  2405                    and      al, 5                          
  0x0106CCFF  001b                    add      byte ptr [ebx], bl             
  0x0106CD01  0020                    add      byte ptr [eax], ah             
  0x0106CD03  00a11c0c0068            add      byte ptr [ecx + 0x68000c1c], ah 
  0x0106CD09  0020                    add      byte ptr [eax], ah             
  0x0106CD0B  0000                    add      byte ptr [eax], al             
  0x0106CD0D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106CD0E  2100                    and      dword ptr [eax], eax           
  0x0106CD10  40                      inc      eax                            
  0x0106CD11  190c00                  sbb      dword ptr [eax + eax], ecx     
  0x0106CD14  208000001b00            and      byte ptr [eax + 0x1b0000], al  
  0x0106CD1A  2000                    and      byte ptr [eax], al             
  0x0106CD1C  a11c0c0068              mov      eax, dword ptr [0x68000c1c]    
  0x0106CD21  0020                    add      byte ptr [eax], ah             
  0x0106CD23  0000                    add      byte ptr [eax], al             
  0x0106CD25  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106CD26  2100                    and      dword ptr [eax], eax           
  0x0106CD28  40                      inc      eax                            
  0x0106CD29  190c00                  sbb      dword ptr [eax + eax], ecx     
  0x0106CD2C  188000000058            sbb      byte ptr [eax + 0x58000000], al 
  0x0106CD32  54                      push     esp                            
  0x0106CD33  0013                    add      byte ptr [ebx], dl             
  0x0106CD36  57                      push     edi                            
  0x0106CD37  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x0106CD3A  0000                    add      byte ptr [eax], al             
  0x0106CD3C  0b00                    or       eax, dword ptr [eax]           
  0x0106CD3E  2000                    and      byte ptr [eax], al             
  0x0106CD40  07                      pop      es                             
  0x0106CD41  2405                    and      al, 5                          
  0x0106CD43  001b                    add      byte ptr [ebx], bl             
  0x0106CD45  0020                    add      byte ptr [eax], ah             
  0x0106CD47  00a11c0c0068            add      byte ptr [ecx + 0x68000c1c], ah 
  0x0106CD4D  0020                    add      byte ptr [eax], ah             
  0x0106CD4F  0000                    add      byte ptr [eax], al             
  0x0106CD51  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106CD52  2100                    and      dword ptr [eax], eax           
  0x0106CD54  40                      inc      eax                            
  0x0106CD55  190c00                  sbb      dword ptr [eax + eax], ecx     
  0x0106CD58  20800000a11c            and      byte ptr [eax + 0x1ca10000], al 
  0x0106CD5E  0c00                    or       al, 0                          
  0x0106CD60  6800200000              push     0x2000                         
  0x0106CD65  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106CD66  2100                    and      dword ptr [eax], eax           
  0x0106CD68  40                      inc      eax                            
  0x0106CD69  190c00                  sbb      dword ptr [eax + eax], ecx     
  0x0106CD6C  188000000058            sbb      byte ptr [eax + 0x58000000], al 
  0x0106CD72  54                      push     esp                            
  0x0106CD73  0013                    add      byte ptr [ebx], dl             
  0x0106CD75  0020                    add      byte ptr [eax], ah             
  0x0106CD77  0000                    add      byte ptr [eax], al             
  0x0106CD79  58                      pop      eax                            
  0x0106CD7A  54                      push     esp                            
  0x0106CD7B  0000                    add      byte ptr [eax], al             
  0x0106CD7D  f4                      hlt                                     
  0x0106CD7E  60                      pushal                                  
  0x0106CD7F  0011                    add      byte ptr [ecx], dl             
  0x0106CD81  0000                    add      byte ptr [eax], al             
  0x0106CD83  0000                    add      byte ptr [eax], al             
  0x0106CD86  56                      push     esi                            
  0x0106CD87  00960b000000            add      byte ptr [esi + 0xb], dl       
  0x0106CD8D  f4                      hlt                                     
  0x0106CD8E  57                      push     edi                            
  0x0106CD8F  0008                    add      byte ptr [eax], cl             
  0x0106CD91  06                      push     es                             
  0x0106CD92  0000                    add      byte ptr [eax], al             
  0x0106CD94  0c00                    or       al, 0                          
  0x0106CD96  0000                    add      byte ptr [eax], al             
  0x0106CD98  00f0                    add      al, dh                         
  0x0106CD9A  6200                    bound    eax, qword ptr [eax]           
  0x0106CD9C  45                      inc      ebp                            
  0x0106CD9D  0b00                    or       eax, dword ptr [eax]           
  0x0106CD9F  0022                    add      byte ptr [edx], ah             
  0x0106CDA2  0500470b00              add      eax, 0xb4700                   
  0x0106CDA7  0000                    add      byte ptr [eax], al             
  0x0106CDA9  f4                      hlt                                     
  0x0106CDAA  57                      push     edi                            
  0x0106CDAB  0010                    add      byte ptr [eax], dl             
  0x0106CDAD  0000                    add      byte ptr [eax], al             
  0x0106CDAF  0000                    add      byte ptr [eax], al             
  0x0106CDB1  00250000f444            add      byte ptr [0x44f40000], ah      
  0x0106CDB7  00770b                  add      byte ptr [edi + 0xb], dh       
  0x0106CDBA  0000                    add      byte ptr [eax], al             
  0x0106CDBC  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106CDBF  0000                    add      byte ptr [eax], al             
  0x0106CDC1  0000                    add      byte ptr [eax], al             
  0x0106CDC3  0000                    add      byte ptr [eax], al             
  0x0106CDC5  f4                      hlt                                     
  0x0106CDC6  44                      inc      esp                            
  0x0106CDC7  0000                    add      byte ptr [eax], al             
  0x0106CDC9  0000                    add      byte ptr [eax], al             
  0x0106CDCB  0000                    add      byte ptr [eax], al             
  0x0106CDCD  7044                    jo       0x106ce13                      
  0x0106CDCF  00540b00                add      byte ptr [ebx + ecx], dl       
  0x0106CDD3  0000                    add      byte ptr [eax], al             
  0x0106CDD5  f4                      hlt                                     
  0x0106CDD6  61                      popal                                   
  0x0106CDD7  0000                    add      byte ptr [eax], al             
  0x0106CDD9  0000                    add      byte ptr [eax], al             
  0x0106CDDB  0000                    add      byte ptr [eax], al             
  0x0106CDDD  1038                    adc      byte ptr [eax], bh             
  0x0106CDDF  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106CDE5  f4                      hlt                                     
  0x0106CDE6  61                      popal                                   
  0x0106CDE7  00540b00                add      byte ptr [ebx + ecx], dl       
  0x0106CDEB  0000                    add      byte ptr [eax], al             
  0x0106CDED  1038                    adc      byte ptr [eax], bh             
  0x0106CDEF  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106CDF5  f4                      hlt                                     
  0x0106CDF6  61                      popal                                   
  0x0106CDF7  007b0b                  add      byte ptr [ebx + 0xb], bh       
  0x0106CDFA  0000                    add      byte ptr [eax], al             
  0x0106CDFC  0002                    add      byte ptr [edx], al             
  0x0106CDFE  3800                    cmp      byte ptr [eax], al             
  0x0106CE00  93                      xchg     ebx, eax                       
  0x0106CE01  030d0000f461            add      ecx, dword ptr [0x61f40000]    
  0x0106CE07  007c0b00                add      byte ptr [ebx + ecx], bh       
  0x0106CE0B  0000                    add      byte ptr [eax], al             
  0x0106CE0D  06                      push     es                             
  0x0106CE0E  3800                    cmp      byte ptr [eax], al             
  0x0106CE10  93                      xchg     ebx, eax                       
  0x0106CE11  030d00000428            add      ecx, dword ptr [0x28040000]    
  0x0106CE17  0000                    add      byte ptr [eax], al             
  0x0106CE19  7050                    jo       0x106ce6b                      
  0x0106CE1B  001e                    add      byte ptr [esi], bl             
  0x0106CE1D  0000                    add      byte ptr [eax], al             
  0x0106CE1F  0000                    add      byte ptr [eax], al             
  0x0106CE21  f4                      hlt                                     
  0x0106CE22  61                      popal                                   
  0x0106CE23  001e                    add      byte ptr [esi], bl             
  0x0106CE25  0000                    add      byte ptr [eax], al             
  0x0106CE27  0000                    add      byte ptr [eax], al             
  0x0106CE29  0538009303              add      eax, 0x3930038                 
  0x0106CE2E  0d00000028              or       eax, 0x28000000                
  0x0106CE33  0000                    add      byte ptr [eax], al             
  0x0106CE35  7050                    jo       0x106ce87                      
  0x0106CE37  001e                    add      byte ptr [esi], bl             
  0x0106CE39  0000                    add      byte ptr [eax], al             
  0x0106CE3B  0000                    add      byte ptr [eax], al             
  0x0106CE3D  f4                      hlt                                     
  0x0106CE3E  61                      popal                                   
  0x0106CE3F  001e                    add      byte ptr [esi], bl             
  0x0106CE41  0000                    add      byte ptr [eax], al             
  0x0106CE43  0000                    add      byte ptr [eax], al             
  0x0106CE45  0338                    add      edi, dword ptr [eax]           
  0x0106CE47  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106CE4D  f4                      hlt                                     
  0x0106CE4E  61                      popal                                   
  0x0106CE4F  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x0106CE52  0000                    add      byte ptr [eax], al             
  0x0106CE54  0003                    add      byte ptr [ebx], al             
  0x0106CE56  3800                    cmp      byte ptr [eax], al             
  0x0106CE58  93                      xchg     ebx, eax                       
  0x0106CE59  030d0000f056            add      ecx, dword ptr [0x56f00000]    
  0x0106CE5F  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x0106CE62  0000                    add      byte ptr [eax], al             
  0x0106CE64  854101                  test     dword ptr [ecx + 1], eax       
  0x0106CE67  000a                    add      byte ptr [edx], cl             
  0x0106CE69  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106CE6A  0500864101              add      eax, 0x1418600                 
  0x0106CE6F  0008                    add      byte ptr [eax], cl             
  0x0106CE71  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106CE72  0500000028              add      eax, 0x28000000                
  0x0106CE77  0000                    add      byte ptr [eax], al             
  0x0106CE79  7050                    jo       0x106cecb                      
  0x0106CE7B  001e                    add      byte ptr [esi], bl             
  0x0106CE7D  0000                    add      byte ptr [eax], al             
  0x0106CE7F  0000                    add      byte ptr [eax], al             
  0x0106CE81  f4                      hlt                                     
  0x0106CE82  61                      popal                                   
  0x0106CE83  001e                    add      byte ptr [esi], bl             
  0x0106CE85  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x0106CE35 (cond_jump)
  0x0106CE87  0000                    add      byte ptr [eax], al             
  0x0106CE89  0238                    add      bh, byte ptr [eax]             
  0x0106CE8B  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106CE92  56                      push     esi                            
  0x0106CE93  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x0106CE96  0000                    add      byte ptr [eax], al             
  0x0106CE98  86440100                xchg     byte ptr [ecx + eax], al       
  0x0106CE9C  08a40500000028          or       byte ptr [ebp + eax + 0x28000000], ah 
  0x0106CEA3  0000                    add      byte ptr [eax], al             
  0x0106CEA5  7050                    jo       0x106cef7                      
  0x0106CEA7  001e                    add      byte ptr [esi], bl             
  0x0106CEA9  0000                    add      byte ptr [eax], al             
  0x0106CEAB  0000                    add      byte ptr [eax], al             
  0x0106CEAD  f4                      hlt                                     
  0x0106CEAE  61                      popal                                   
  0x0106CEAF  001e                    add      byte ptr [esi], bl             
  0x0106CEB1  0000                    add      byte ptr [eax], al             
  0x0106CEB3  0000                    add      byte ptr [eax], al             
  0x0106CEB5  0238                    add      bh, byte ptr [eax]             
  0x0106CEB7  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106CEBE  56                      push     esi                            
  0x0106CEBF  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x0106CEC2  0000                    add      byte ptr [eax], al             
  0x0106CEC4  854201                  test     dword ptr [edx + 1], eax       
  0x0106CEC7  000524050000            add      byte ptr [0x524], al           
  0x0106CECD  f4                      hlt                                     
  0x0106CECE  61                      popal                                   
  0x0106CECF  004e0b                  add      byte ptr [esi + 0xb], cl       
  0x0106CED2  0000                    add      byte ptr [eax], al             
  0x0106CED4  0002                    add      byte ptr [edx], al             
  0x0106CED6  3800                    cmp      byte ptr [eax], al             
  0x0106CED8  93                      xchg     ebx, eax                       
  0x0106CED9  030d0000f461            add      ecx, dword ptr [0x61f40000]    
  0x0106CEDF  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x0106CEE2  0000                    add      byte ptr [eax], al             
  0x0106CEE4  0001                    add      byte ptr [ecx], al             
  0x0106CEE6  3800                    cmp      byte ptr [eax], al             
  0x0106CEE8  93                      xchg     ebx, eax                       
  0x0106CEE9  030d0000f461            add      ecx, dword ptr [0x61f40000]    
  0x0106CEEF  00490b                  add      byte ptr [ecx + 0xb], cl       
  0x0106CEF2  0000                    add      byte ptr [eax], al             
  0x0106CEF4  000538009303            add      byte ptr [0x3930038], al       
  0x0106CEFA  0d0000f461              or       eax, 0x61f40000                
  0x0106CEFF  004c0b00                add      byte ptr [ebx + ecx], cl       
  0x0106CF03  0000                    add      byte ptr [eax], al             
  0x0106CF05  0138                    add      dword ptr [eax], edi           
  0x0106CF07  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106CF0E  56                      push     esi                            
  0x0106CF0F  004c0b00                add      byte ptr [ebx + ecx], cl       
  0x0106CF13  0003                    add      byte ptr [ebx], al             
  0x0106CF15  0020                    add      byte ptr [eax], ah             
  0x0106CF17  0005a4050000            add      byte ptr [0x5a4], al           
  0x0106CF1D  f4                      hlt                                     
  0x0106CF1E  61                      popal                                   
  0x0106CF1F  004d0b                  add      byte ptr [ebp + 0xb], cl       
  0x0106CF22  0000                    add      byte ptr [eax], al             
  0x0106CF24  0008                    add      byte ptr [eax], cl             
  0x0106CF26  3800                    cmp      byte ptr [eax], al             
  0x0106CF28  93                      xchg     ebx, eax                       
  0x0106CF29  030d00000028            add      ecx, dword ptr [0x28000000]    
  0x0106CF2F  0000                    add      byte ptr [eax], al             
  0x0106CF31  7050                    jo       0x106cf83                      
  0x0106CF33  001e                    add      byte ptr [esi], bl             
  0x0106CF35  0000                    add      byte ptr [eax], al             
  0x0106CF37  0000                    add      byte ptr [eax], al             
  0x0106CF39  f4                      hlt                                     
  0x0106CF3A  61                      popal                                   
  0x0106CF3B  001e                    add      byte ptr [esi], bl             
  0x0106CF3D  0000                    add      byte ptr [eax], al             
  0x0106CF3F  0000                    add      byte ptr [eax], al             
  0x0106CF41  0138                    add      dword ptr [eax], edi           
  0x0106CF43  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106CF49  0028                    add      byte ptr [eax], ch             
  0x0106CF4B  0000                    add      byte ptr [eax], al             
  0x0106CF4D  7050                    jo       0x106cf9f                      
  0x0106CF4F  001e                    add      byte ptr [esi], bl             
  0x0106CF51  0000                    add      byte ptr [eax], al             
  0x0106CF53  0000                    add      byte ptr [eax], al             
  0x0106CF55  f4                      hlt                                     
  0x0106CF56  61                      popal                                   
  0x0106CF57  001e                    add      byte ptr [esi], bl             
  0x0106CF59  0000                    add      byte ptr [eax], al             
  0x0106CF5B  0000                    add      byte ptr [eax], al             
  0x0106CF5D  0138                    add      dword ptr [eax], edi           
  0x0106CF5F  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106CF65  0028                    add      byte ptr [eax], ch             
  0x0106CF67  0000                    add      byte ptr [eax], al             
  0x0106CF69  7050                    jo       0x106cfbb                      
  0x0106CF6B  001e                    add      byte ptr [esi], bl             
  0x0106CF6D  0000                    add      byte ptr [eax], al             
  0x0106CF6F  0000                    add      byte ptr [eax], al             
  0x0106CF71  f4                      hlt                                     
  0x0106CF72  61                      popal                                   
  0x0106CF73  001e                    add      byte ptr [esi], bl             
  0x0106CF75  0000                    add      byte ptr [eax], al             
  0x0106CF77  0000                    add      byte ptr [eax], al             
  0x0106CF79  0138                    add      dword ptr [eax], edi           
  0x0106CF7B  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106CF81  0128                    add      dword ptr [eax], ebp           
                                        ; XREF: 0x0106CF31 (cond_jump)
  0x0106CF83  0000                    add      byte ptr [eax], al             
  0x0106CF85  7050                    jo       0x106cfd7                      
  0x0106CF87  001e                    add      byte ptr [esi], bl             
  0x0106CF89  0000                    add      byte ptr [eax], al             
  0x0106CF8B  0000                    add      byte ptr [eax], al             
  0x0106CF8D  f4                      hlt                                     
  0x0106CF8E  61                      popal                                   
  0x0106CF8F  001e                    add      byte ptr [esi], bl             
  0x0106CF91  0000                    add      byte ptr [eax], al             
  0x0106CF93  0000                    add      byte ptr [eax], al             
  0x0106CF95  0138                    add      dword ptr [eax], edi           
  0x0106CF97  0093030d0013            add      byte ptr [ebx + 0x13000d03], dl 
  0x0106CF9D  0020                    add      byte ptr [eax], ah             
                                        ; XREF: 0x0106CF4D (cond_jump)
  0x0106CF9F  0000                    add      byte ptr [eax], al             
  0x0106CFA1  7056                    jo       0x106cff9                      
  0x0106CFA3  001e                    add      byte ptr [esi], bl             
  0x0106CFA5  0000                    add      byte ptr [eax], al             
  0x0106CFA7  0000                    add      byte ptr [eax], al             
  0x0106CFA9  f4                      hlt                                     
  0x0106CFAA  61                      popal                                   
  0x0106CFAB  001e                    add      byte ptr [esi], bl             
  0x0106CFAD  0000                    add      byte ptr [eax], al             
  0x0106CFAF  0000                    add      byte ptr [eax], al             
  0x0106CFB1  0138                    add      dword ptr [eax], edi           
  0x0106CFB3  0093030d0013            add      byte ptr [ebx + 0x13000d03], dl 
  0x0106CFB9  0020                    add      byte ptr [eax], ah             
                                        ; XREF: 0x0106CF69 (cond_jump)
  0x0106CFBB  0000                    add      byte ptr [eax], al             
  0x0106CFBD  7056                    jo       0x106d015                      
  0x0106CFBF  001e                    add      byte ptr [esi], bl             
  0x0106CFC1  0000                    add      byte ptr [eax], al             
  0x0106CFC3  0000                    add      byte ptr [eax], al             
  0x0106CFC5  f4                      hlt                                     
  0x0106CFC6  61                      popal                                   
  0x0106CFC7  001e                    add      byte ptr [esi], bl             
  0x0106CFC9  0000                    add      byte ptr [eax], al             
  0x0106CFCB  0000                    add      byte ptr [eax], al             
  0x0106CFCD  0138                    add      dword ptr [eax], edi           
  0x0106CFCF  0093030d0013            add      byte ptr [ebx + 0x13000d03], dl 
  0x0106CFD5  0020                    add      byte ptr [eax], ah             
                                        ; XREF: 0x0106CF85 (cond_jump)
  0x0106CFD7  0000                    add      byte ptr [eax], al             
  0x0106CFD9  7050                    jo       0x106d02b                      
  0x0106CFDB  001e                    add      byte ptr [esi], bl             
  0x0106CFDD  0000                    add      byte ptr [eax], al             
  0x0106CFDF  0000                    add      byte ptr [eax], al             
  0x0106CFE1  f4                      hlt                                     
  0x0106CFE2  61                      popal                                   
  0x0106CFE3  001e                    add      byte ptr [esi], bl             
  0x0106CFE5  0000                    add      byte ptr [eax], al             
  0x0106CFE7  0000                    add      byte ptr [eax], al             
  0x0106CFE9  0138                    add      dword ptr [eax], edi           
  0x0106CFEB  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106CFF1  7045                    jo       0x106d038                      
  0x0106CFF3  00560b                  add      byte ptr [esi + 0xb], dl       
  0x0106CFF6  0000                    add      byte ptr [eax], al             
  0x0106CFF8  007057                  add      byte ptr [eax + 0x57], dh      
  0x0106CFFB  00570b                  add      byte ptr [edi + 0xb], dl       
  0x0106CFFE  0000                    add      byte ptr [eax], al             
  0x0106D000  007062                  add      byte ptr [eax + 0x62], dh      
  0x0106D003  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x0106D006  0000                    add      byte ptr [eax], al             
  0x0106D008  22f4                    and      dh, ah                         
  0x0106D00A  0500ffff00              add      eax, 0xffff00                  
  0x0106D00F  000c00                  add      byte ptr [eax + eax], cl       
  0x0106D012  0000                    add      byte ptr [eax], al             
  0x0106D014  1300                    adc      eax, dword ptr [eax]           
  0x0106D016  2000                    and      byte ptr [eax], al             
  0x0106D018  007056                  add      byte ptr [eax + 0x56], dh      
  0x0106D01B  0002                    add      byte ptr [edx], al             
  0x0106D01D  0000                    add      byte ptr [eax], al             
  0x0106D01F  0000                    add      byte ptr [eax], al             
  0x0106D021  7056                    jo       0x106d079                      
  0x0106D023  0003                    add      byte ptr [ebx], al             
  0x0106D025  0000                    add      byte ptr [eax], al             
  0x0106D027  0000                    add      byte ptr [eax], al             
  0x0106D029  7056                    jo       0x106d081                      
                                        ; XREF: 0x0106CFD9 (cond_jump)
  0x0106D02B  000400                  add      byte ptr [eax + eax], al       
  0x0106D02E  0000                    add      byte ptr [eax], al             
  0x0106D030  0000                    add      byte ptr [eax], al             
  0x0106D032  360000                  add      byte ptr ss:[eax], al          
  0x0106D036  44                      inc      esp                            
  0x0106D037  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x0106D03D  c406                    les      eax, ptr [esi]                 
  0x0106D03F  001d00000000            add      byte ptr [0], bl               
  0x0106D045  f4                      hlt                                     
  0x0106D046  56                      push     esi                            
  0x0106D047  00a50b000000            add      byte ptr [ebp + 0xb], ah       
  0x0106D04D  c422                    les      esp, ptr [edx]                 
  0x0106D04F  004000                  add      byte ptr [eax], al             
  0x0106D052  2000                    and      byte ptr [eax], al             
  0x0106D054  0090210000e0            add      byte ptr [eax - 0x1fffffdf], dl 
  0x0106D05A  7000                    jo       0x106d05c                      
                                        ; XREF: 0x0106D05A (cond_jump)
  0x0106D05C  00c4                    add      ah, al                         
  0x0106D05E  2200                    and      al, byte ptr [eax]             
  0x0106D060  00f4                    add      ah, dh                         
  0x0106D062  46                      inc      esi                            
  0x0106D063  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x0106D069  f4                      hlt                                     
  0x0106D06A  44                      inc      esp                            
  0x0106D06B  0000                    add      byte ptr [eax], al             
  0x0106D06D  0100                    add      dword ptr [eax], eax           
  0x0106D06F  002e                    add      byte ptr [esi], ch             
  0x0106D071  1d0c004000              sbb      eax, 0x40000c                  
  0x0106D076  2000                    and      byte ptr [eax], al             
  0x0106D078  0090210000c4            add      byte ptr [eax - 0x3bffffdf], dl 
  0x0106D07E  2200                    and      al, byte ptr [eax]             
  0x0106D080  00f4                    add      ah, dh                         
  0x0106D082  46                      inc      esi                            
  0x0106D083  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x0106D08A  44                      inc      esp                            
  0x0106D08B  00720b                  add      byte ptr [edx + 0xb], dh       
  0x0106D08E  0000                    add      byte ptr [eax], al             
  0x0106D090  2e1d0c004000            sbb      eax, 0x40000c                  
  0x0106D096  2000                    and      byte ptr [eax], al             
  0x0106D098  009521000070            add      byte ptr [ebp + 0x70000021], dl 
  0x0106D09E  6600410b                add      byte ptr [ecx + 0xb], al       
  0x0106D0A2  0000                    add      byte ptr [eax], al             
  0x0106D0A4  f1                      int1                                    
  0x0106D0A5  030d0000f066            add      ecx, dword ptr [0x66f00000]    
  0x0106D0AB  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106D0AE  0000                    add      byte ptr [eax], al             
  0x0106D0B0  005e20                  add      byte ptr [esi + 0x20], bl      
  0x0106D0B3  0000                    add      byte ptr [eax], al             
  0x0106D0B6  56                      push     esi                            
  0x0106D0B7  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x0106D0BA  0000                    add      byte ptr [eax], al             
  0x0106D0BC  0300                    add      eax, dword ptr [eax]           
  0x0106D0BE  2000                    and      byte ptr [eax], al             
  0x0106D0C0  07                      pop      es                             
  0x0106D0C1  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106D0C2  0500000738              add      eax, 0x38070000                
  0x0106D0C7  0000                    add      byte ptr [eax], al             
  0x0106D0C9  f4                      hlt                                     
  0x0106D0CA  60                      pushal                                  
  0x0106D0CB  008904000000            add      byte ptr [ecx + 4], cl         
  0x0106D0D1  f4                      hlt                                     
  0x0106D0D2  650039                  add      byte ptr gs:[ecx], bh          
  0x0106D0D5  0b00                    or       eax, dword ptr [eax]           
  0x0106D0D7  00f1                    add      cl, dh                         
  0x0106D0D9  030d0000f057            add      ecx, dword ptr [0x57f00000]    
  0x0106D0DF  0002                    add      byte ptr [edx], al             
  0x0106D0E1  0000                    add      byte ptr [eax], al             
  0x0106D0E3  000b                    add      byte ptr [ebx], cl             
  0x0106D0E5  0020                    add      byte ptr [eax], ah             
  0x0106D0E7  0014a4                  add      byte ptr [esp], dl             
  0x0106D0EA  050000f462              add      eax, 0x62f40000                
  0x0106D0EF  000500000000            add      byte ptr [0], al               
  0x0106D0F5  f4                      hlt                                     
  0x0106D0F6  66000a                  add      byte ptr [edx], cl             
  0x0106D0F9  0d0000004e              or       eax, 0x4e000000                
  0x0106D0FE  2200                    and      al, byte ptr [eax]             
  0x0106D100  10f4                    adc      ah, dh                         
  0x0106D102  44                      inc      esp                            
  0x0106D103  0001                    add      byte ptr [ecx], al             
  0x0106D105  0000                    add      byte ptr [eax], al             
  0x0106D107  008c4301003ed0          add      byte ptr [ebx + eax*2 - 0x2fc1ffff], cl 
  0x0106D10E  2100                    and      dword ptr [eax], eax           
  0x0106D110  10cd                    adc      ch, cl                         
  0x0106D112  06                      push     es                             
  0x0106D113  0002                    add      byte ptr [edx], al             
  0x0106D115  0000                    add      byte ptr [eax], al             
  0x0106D117  0000                    add      byte ptr [eax], al             
  0x0106D119  58                      pop      eax                            
  0x0106D11A  44                      inc      esp                            
  0x0106D11B  0000                    add      byte ptr [eax], al             
  0x0106D11F  00d0                    add      al, dl                         
  0x0106D123  00d2                    add      dl, dl                         
  0x0106D127  00d2                    add      dl, dl                         
  0x0106D129  f066000d00000024        lock add byte ptr [0x24000000], cl      
  0x0106D131  1d0c000066              sbb      eax, 0x6600000c                
  0x0106D136  50                      push     eax                            
  0x0106D137  0000                    add      byte ptr [eax], al             
  0x0106D13A  57                      push     edi                            
  0x0106D13B  0003                    add      byte ptr [ebx], al             
  0x0106D13D  0000                    add      byte ptr [eax], al             
  0x0106D13F  000b                    add      byte ptr [ebx], cl             
  0x0106D141  0020                    add      byte ptr [eax], ah             
  0x0106D143  0014a4                  add      byte ptr [esp], dl             
  0x0106D146  050000f462              add      eax, 0x62f40000                
  0x0106D14B  0008                    add      byte ptr [eax], cl             
  0x0106D14D  0000                    add      byte ptr [eax], al             
  0x0106D14F  0000                    add      byte ptr [eax], al             
  0x0106D151  f4                      hlt                                     
  0x0106D152  66000d0d000000          add      byte ptr [0xd], cl             
  0x0106D159  4e                      dec      esi                            
  0x0106D15A  2200                    and      al, byte ptr [eax]             
  0x0106D15C  10f4                    adc      ah, dh                         
  0x0106D15E  44                      inc      esp                            
  0x0106D15F  0002                    add      byte ptr [edx], al             
  0x0106D161  0000                    add      byte ptr [eax], al             
  0x0106D163  008c4301003ed0          add      byte ptr [ebx + eax*2 - 0x2fc1ffff], cl 
  0x0106D16A  2100                    and      dword ptr [eax], eax           
  0x0106D16C  10cd                    adc      ch, cl                         
  0x0106D16E  06                      push     es                             
  0x0106D16F  0002                    add      byte ptr [edx], al             
  0x0106D171  0000                    add      byte ptr [eax], al             
  0x0106D173  0000                    add      byte ptr [eax], al             
  0x0106D175  58                      pop      eax                            
  0x0106D176  44                      inc      esp                            
  0x0106D177  0000                    add      byte ptr [eax], al             
  0x0106D17B  00d0                    add      al, dl                         
  0x0106D17F  00d2                    add      dl, dl                         
  0x0106D183  00d2                    add      dl, dl                         
  0x0106D185  f066000e                lock add byte ptr [esi], cl             
  0x0106D189  0000                    add      byte ptr [eax], al             
  0x0106D18B  0020                    add      byte ptr [eax], ah             
  0x0106D18D  1d0c000066              sbb      eax, 0x6600000c                
  0x0106D192  50                      push     eax                            
  0x0106D193  0000                    add      byte ptr [eax], al             
  0x0106D196  57                      push     edi                            
  0x0106D197  000400                  add      byte ptr [eax + eax], al       
  0x0106D19A  0000                    add      byte ptr [eax], al             
  0x0106D19C  0b00                    or       eax, dword ptr [eax]           
  0x0106D19E  2000                    and      byte ptr [eax], al             
  0x0106D1A0  13a4050000f462          adc      esp, dword ptr [ebp + eax + 0x62f40000] 
  0x0106D1A7  000b                    add      byte ptr [ebx], cl             
  0x0106D1A9  0000                    add      byte ptr [eax], al             
  0x0106D1AB  0000                    add      byte ptr [eax], al             
  0x0106D1AD  f4                      hlt                                     
  0x0106D1AE  660010                  add      byte ptr [eax], dl             
  0x0106D1B1  0d0000004e              or       eax, 0x4e000000                
  0x0106D1B6  2200                    and      al, byte ptr [eax]             
  0x0106D1B8  10f4                    adc      ah, dh                         
  0x0106D1BA  44                      inc      esp                            
  0x0106D1BB  00050000008c            add      byte ptr [0x8c000000], al      
  0x0106D1C1  42                      inc      edx                            
  0x0106D1C2  0100                    add      dword ptr [eax], eax           
  0x0106D1C4  3ed021                  shl      byte ptr ds:[ecx], 1           
  0x0106D1C7  0010                    add      byte ptr [eax], dl             
  0x0106D1C9  cd06                    int      6                              
  0x0106D1CB  0002                    add      byte ptr [edx], al             
  0x0106D1CD  0000                    add      byte ptr [eax], al             
  0x0106D1CF  0000                    add      byte ptr [eax], al             
  0x0106D1D1  58                      pop      eax                            
  0x0106D1D2  44                      inc      esp                            
  0x0106D1D3  0000                    add      byte ptr [eax], al             
  0x0106D1D7  00d0                    add      al, dl                         
  0x0106D1DB  00d2                    add      dl, dl                         
  0x0106D1DD  f066000f                lock add byte ptr [edi], cl             
  0x0106D1E1  0000                    add      byte ptr [eax], al             
  0x0106D1E3  0020                    add      byte ptr [eax], ah             
  0x0106D1E5  1d0c000066              sbb      eax, 0x6600000c                
  0x0106D1EA  50                      push     eax                            
  0x0106D1EB  000c00                  add      byte ptr [eax + eax], cl       
  0x0106D1EE  0000                    add      byte ptr [eax], al             
  0x0106D1F0  00f0                    add      al, dh                         
  0x0106D1F2  6200                    bound    eax, qword ptr [eax]           
  0x0106D1F4  55                      push     ebp                            
  0x0106D1F5  0b00                    or       eax, dword ptr [eax]           
  0x0106D1F7  0022                    add      byte ptr [edx], ah             
  0x0106D1FA  0500470b00              add      eax, 0xb4700                   
  0x0106D1FF  0000                    add      byte ptr [eax], al             
  0x0106D202  57                      push     edi                            
  0x0106D203  00570b                  add      byte ptr [edi + 0xb], dl       
  0x0106D206  0000                    add      byte ptr [eax], al             
  0x0106D208  00f0                    add      al, dh                         
  0x0106D20A  45                      inc      ebp                            
  0x0106D20B  00560b                  add      byte ptr [esi + 0xb], dl       
  0x0106D20E  0000                    add      byte ptr [eax], al             
  0x0106D210  00f4                    add      ah, dh                         
  0x0106D212  61                      popal                                   
  0x0106D213  007f0b                  add      byte ptr [edi + 0xb], bh       
  0x0106D216  0000                    add      byte ptr [eax], al             
  0x0106D218  00f0                    add      al, dh                         
  0x0106D21A  7100                    jno      0x106d21c                      
                                        ; XREF: 0x0106D21A (cond_jump)
  0x0106D21C  97                      xchg     edi, eax                       
  0x0106D21D  0b00                    or       eax, dword ptr [eax]           
  0x0106D21F  0000                    add      byte ptr [eax], al             
  0x0106D221  0138                    add      dword ptr [eax], edi           
  0x0106D223  006f03                  add      byte ptr [edi + 3], ch         
  0x0106D226  0d0000f461              or       eax, 0x61f40000                
  0x0106D22B  00840b000000f0          add      byte ptr [ebx + ecx - 0x10000000], al 
  0x0106D232  7100                    jno      0x106d234                      
                                        ; XREF: 0x0106D232 (cond_jump)
  0x0106D234  97                      xchg     edi, eax                       
  0x0106D235  0b00                    or       eax, dword ptr [eax]           
  0x0106D237  0000                    add      byte ptr [eax], al             
  0x0106D239  0138                    add      dword ptr [eax], edi           
  0x0106D23B  006f03                  add      byte ptr [edi + 3], ch         
  0x0106D23E  0d0000f461              or       eax, 0x61f40000                
  0x0106D243  004a0b                  add      byte ptr [edx + 0xb], cl       
  0x0106D246  0000                    add      byte ptr [eax], al             
  0x0106D248  0001                    add      byte ptr [ecx], al             
  0x0106D24A  3800                    cmp      byte ptr [eax], al             
  0x0106D24C  93                      xchg     ebx, eax                       
  0x0106D24D  030d0000f056            add      ecx, dword ptr [0x56f00000]    
  0x0106D253  004a0b                  add      byte ptr [edx + 0xb], cl       
  0x0106D256  0000                    add      byte ptr [eax], al             
  0x0106D258  0300                    add      eax, dword ptr [eax]           
  0x0106D25A  2000                    and      byte ptr [eax], al             
  0x0106D25C  05a4050000              add      eax, 0x5a4                     
  0x0106D261  f4                      hlt                                     
  0x0106D262  61                      popal                                   
  0x0106D263  004b0b                  add      byte ptr [ebx + 0xb], cl       
  0x0106D266  0000                    add      byte ptr [eax], al             
  0x0106D268  0008                    add      byte ptr [eax], cl             
  0x0106D26A  3800                    cmp      byte ptr [eax], al             
  0x0106D26C  93                      xchg     ebx, eax                       
  0x0106D26D  030d00130020            add      ecx, dword ptr [0x20001300]    
  0x0106D273  0000                    add      byte ptr [eax], al             
  0x0106D275  7056                    jo       0x106d2cd                      
  0x0106D277  001e                    add      byte ptr [esi], bl             
  0x0106D279  0000                    add      byte ptr [eax], al             
  0x0106D27B  0000                    add      byte ptr [eax], al             
  0x0106D27D  f4                      hlt                                     
  0x0106D27E  61                      popal                                   
  0x0106D27F  00890b000000            add      byte ptr [ecx + 0xb], cl       
  0x0106D285  0138                    add      dword ptr [eax], edi           
  0x0106D287  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106D28D  f9                      stc                                     
  0x0106D28E  56                      push     esi                            
  0x0106D28F  0003                    add      byte ptr [ebx], al             
  0x0106D291  0020                    add      byte ptr [eax], ah             
  0x0106D293  0005a4050000            add      byte ptr [0x5a4], al           
  0x0106D299  f4                      hlt                                     
  0x0106D29A  61                      popal                                   
  0x0106D29B  001e                    add      byte ptr [esi], bl             
  0x0106D29D  0000                    add      byte ptr [eax], al             
  0x0106D29F  0000                    add      byte ptr [eax], al             
  0x0106D2A1  0138                    add      dword ptr [eax], edi           
  0x0106D2A3  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106D2AA  56                      push     esi                            
  0x0106D2AB  007d0b                  add      byte ptr [ebp + 0xb], bh       
  0x0106D2AE  0000                    add      byte ptr [eax], al             
  0x0106D2B0  c54001                  lds      eax, ptr [eax + 1]             
  0x0106D2B3  0002                    add      byte ptr [edx], al             
  0x0106D2B5  0000                    add      byte ptr [eax], al             
  0x0106D2B7  0012                    add      byte ptr [edx], dl             
  0x0106D2B9  2405                    and      al, 5                          
  0x0106D2BB  0000                    add      byte ptr [eax], al             
  0x0106D2BD  f4                      hlt                                     
  0x0106D2BE  44                      inc      esp                            
  0x0106D2BF  0010                    add      byte ptr [eax], dl             
  0x0106D2C1  0000                    add      byte ptr [eax], al             
  0x0106D2C3  0000                    add      byte ptr [eax], al             
  0x0106D2C5  7044                    jo       0x106d30b                      
  0x0106D2C7  001e                    add      byte ptr [esi], bl             
  0x0106D2C9  0000                    add      byte ptr [eax], al             
  0x0106D2CB  0000                    add      byte ptr [eax], al             
  0x0106D2CE  56                      push     esi                            
  0x0106D2CF  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106D2D2  0000                    add      byte ptr [eax], al             
  0x0106D2D4  0300                    add      eax, dword ptr [eax]           
  0x0106D2D6  2000                    and      byte ptr [eax], al             
  0x0106D2D8  06                      push     es                             
  0x0106D2D9  2405                    and      al, 5                          
  0x0106D2DB  0000                    add      byte ptr [eax], al             
  0x0106D2DD  f4                      hlt                                     
  0x0106D2DE  61                      popal                                   
  0x0106D2DF  001e                    add      byte ptr [esi], bl             
  0x0106D2E1  0000                    add      byte ptr [eax], al             
  0x0106D2E3  0000                    add      byte ptr [eax], al             
  0x0106D2E5  0538009303              add      eax, 0x3930038                 
  0x0106D2EA  0d00050c05              or       eax, 0x50c0500                 
  0x0106D2EF  0000                    add      byte ptr [eax], al             
  0x0106D2F1  f4                      hlt                                     
  0x0106D2F2  61                      popal                                   
  0x0106D2F3  001e                    add      byte ptr [esi], bl             
  0x0106D2F5  0000                    add      byte ptr [eax], al             
  0x0106D2F7  0000                    add      byte ptr [eax], al             
  0x0106D2F9  0138                    add      dword ptr [eax], edi           
  0x0106D2FB  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106D301  f4                      hlt                                     
  0x0106D302  61                      popal                                   
  0x0106D303  008a0b000000            add      byte ptr [edx + 0xb], cl       
  0x0106D30A  7100                    jno      0x106d30c                      
                                        ; XREF: 0x0106D30A (cond_jump)
  0x0106D30C  97                      xchg     edi, eax                       
  0x0106D30D  0b00                    or       eax, dword ptr [eax]           
  0x0106D30F  0000                    add      byte ptr [eax], al             
  0x0106D311  0238                    add      bh, byte ptr [eax]             
  0x0106D313  006f03                  add      byte ptr [edi + 3], ch         
  0x0106D316  0d0000f056              or       eax, 0x56f00000                
  0x0106D31B  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x0106D31E  0000                    add      byte ptr [eax], al             
  0x0106D320  0300                    add      eax, dword ptr [eax]           
  0x0106D322  2000                    and      byte ptr [eax], al             
  0x0106D324  05a4050000              add      eax, 0x5a4                     
  0x0106D329  f4                      hlt                                     
  0x0106D32A  61                      popal                                   
  0x0106D32B  008f0b000000            add      byte ptr [edi + 0xb], cl       
  0x0106D331  0138                    add      dword ptr [eax], edi           
  0x0106D333  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106D339  0036                    add      byte ptr [esi], dh             
  0x0106D33B  0000                    add      byte ptr [eax], al             
  0x0106D33E  44                      inc      esp                            
  0x0106D33F  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x0106D345  c406                    les      eax, ptr [esi]                 
  0x0106D347  0011                    add      byte ptr [ecx], dl             
  0x0106D349  0000                    add      byte ptr [eax], al             
  0x0106D34B  0000                    add      byte ptr [eax], al             
  0x0106D34D  f4                      hlt                                     
  0x0106D34E  56                      push     esi                            
  0x0106D34F  008a0b000000            add      byte ptr [edx + 0xb], cl       
  0x0106D355  c422                    les      esp, ptr [edx]                 
  0x0106D357  004000                  add      byte ptr [eax], al             
  0x0106D35A  2000                    and      byte ptr [eax], al             
  0x0106D35C  0091210000e1            add      byte ptr [ecx - 0x1effffdf], dl 
  0x0106D362  56                      push     esi                            
  0x0106D363  0003                    add      byte ptr [ebx], al             
  0x0106D365  0020                    add      byte ptr [eax], ah             
  0x0106D367  0008                    add      byte ptr [eax], cl             
  0x0106D369  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106D36A  050000f456              add      eax, 0x56f40000                
  0x0106D36F  00a00b000000            add      byte ptr [eax + 0xb], ah       
  0x0106D375  c422                    les      esp, ptr [edx]                 
  0x0106D377  004000                  add      byte ptr [eax], al             
  0x0106D37A  2000                    and      byte ptr [eax], al             
  0x0106D37C  009121000006            add      byte ptr [ecx + 0x6000021], dl 
  0x0106D382  3800                    cmp      byte ptr [eax], al             
  0x0106D384  93                      xchg     ebx, eax                       
  0x0106D385  030d00005e20            add      ecx, dword ptr [0x205e0000]    
  0x0106D38B  0000                    add      byte ptr [eax], al             
  0x0106D38D  0036                    add      byte ptr [esi], dh             
  0x0106D38F  0000                    add      byte ptr [eax], al             
  0x0106D392  44                      inc      esp                            
  0x0106D393  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x0106D399  c406                    les      eax, ptr [esi]                 
  0x0106D39B  0023                    add      byte ptr [ebx], ah             
  0x0106D39D  0000                    add      byte ptr [eax], al             
  0x0106D39F  0000                    add      byte ptr [eax], al             
  0x0106D3A1  f4                      hlt                                     
  0x0106D3A2  56                      push     esi                            
  0x0106D3A3  008a0b000000            add      byte ptr [edx + 0xb], cl       
  0x0106D3A9  c422                    les      esp, ptr [edx]                 
  0x0106D3AB  004000                  add      byte ptr [eax], al             
  0x0106D3AE  2000                    and      byte ptr [eax], al             
  0x0106D3B0  0091210000e1            add      byte ptr [ecx - 0x1effffdf], dl 
  0x0106D3B6  56                      push     esi                            
  0x0106D3B7  0003                    add      byte ptr [ebx], al             
  0x0106D3B9  0020                    add      byte ptr [eax], ah             
  0x0106D3BB  001a                    add      byte ptr [edx], bl             
  0x0106D3BD  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106D3BE  050000c422              add      eax, 0x22c40000                
  0x0106D3C3  0000                    add      byte ptr [eax], al             
  0x0106D3C5  f4                      hlt                                     
  0x0106D3C6  46                      inc      esi                            
  0x0106D3C7  001f                    add      byte ptr [edi], bl             
  0x0106D3C9  0000                    add      byte ptr [eax], al             
  0x0106D3CB  00d0                    add      al, dl                         
  0x0106D3CD  f4                      hlt                                     
  0x0106D3CE  44                      inc      esp                            
  0x0106D3CF  0000                    add      byte ptr [eax], al             
  0x0106D3D1  0000                    add      byte ptr [eax], al             
  0x0106D3D3  002e                    add      byte ptr [esi], ch             
  0x0106D3D5  1d0c004000              sbb      eax, 0x40000c                  
  0x0106D3DA  2000                    and      byte ptr [eax], al             
  0x0106D3DC  009121000004            add      byte ptr [ecx + 0x4000021], dl 
  0x0106D3E2  3800                    cmp      byte ptr [eax], al             
  0x0106D3E4  a3030d0000              mov      dword ptr [0xd03], eax         
  0x0106D3E9  f4                      hlt                                     
  0x0106D3EA  56                      push     esi                            
  0x0106D3EB  00910b000000            add      byte ptr [ecx + 0xb], dl       
  0x0106D3F1  c422                    les      esp, ptr [edx]                 
  0x0106D3F3  004000                  add      byte ptr [eax], al             
  0x0106D3F6  2000                    and      byte ptr [eax], al             
  0x0106D3F8  0090210000e0            add      byte ptr [eax - 0x1fffffdf], dl 
  0x0106D3FE  7100                    jno      0x106d400                      
                                        ; XREF: 0x0106D3FE (cond_jump)
  0x0106D400  0007                    add      byte ptr [edi], al             
  0x0106D402  3800                    cmp      byte ptr [eax], al             
  0x0106D404  81030d0000f4            add      dword ptr [ebx], 0xf400000d    
  0x0106D40A  56                      push     esi                            
  0x0106D40B  00610b                  add      byte ptr [ecx + 0xb], ah       
  0x0106D40E  0000                    add      byte ptr [eax], al             
  0x0106D410  00c4                    add      ah, al                         
  0x0106D412  2200                    and      al, byte ptr [eax]             
  0x0106D414  40                      inc      eax                            
  0x0106D415  0020                    add      byte ptr [eax], ah             
  0x0106D417  0000                    add      byte ptr [eax], al             
  0x0106D419  91                      xchg     ecx, eax                       
  0x0106D41A  2100                    and      dword ptr [eax], eax           
  0x0106D41C  0002                    add      byte ptr [edx], al             
  0x0106D41E  3800                    cmp      byte ptr [eax], al             
  0x0106D420  93                      xchg     ebx, eax                       
  0x0106D421  030d00005e20            add      ecx, dword ptr [0x205e0000]    
  0x0106D427  0000                    add      byte ptr [eax], al             
  0x0106D42A  56                      push     esi                            
  0x0106D42B  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x0106D42E  0000                    add      byte ptr [eax], al             
  0x0106D430  0300                    add      eax, dword ptr [eax]           
  0x0106D432  2000                    and      byte ptr [eax], al             
  0x0106D434  0ca4                    or       al, 0xa4                       
  0x0106D436  050000f056              add      eax, 0x56f00000                
  0x0106D43B  008f0b000003            add      byte ptr [edi + 0x300000b], cl 
  0x0106D441  0020                    add      byte ptr [eax], ah             
  0x0106D443  0008                    add      byte ptr [eax], cl             
  0x0106D445  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106D446  050000f461              add      eax, 0x61f40000                
  0x0106D44B  009b00000000            add      byte ptr [ebx], bl             
  0x0106D451  0438                    add      al, 0x38                       
  0x0106D453  00a3030d0000            add      byte ptr [ebx + 0xd03], ah     
  0x0106D459  0239                    add      bh, byte ptr [ecx]             
  0x0106D45B  0000                    add      byte ptr [eax], al             
  0x0106D45D  07                      pop      es                             
  0x0106D45E  3800                    cmp      byte ptr [eax], al             
  0x0106D460  81030d0000f4            add      dword ptr [ebx], 0xf400000d    
  0x0106D466  61                      popal                                   
  0x0106D467  00900b000000            add      byte ptr [eax + 0xb], dl       
  0x0106D46D  0138                    add      dword ptr [eax], edi           
  0x0106D46F  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106D475  f9                      stc                                     
  0x0106D476  56                      push     esi                            
  0x0106D477  0003                    add      byte ptr [ebx], al             
  0x0106D479  0020                    add      byte ptr [eax], ah             
  0x0106D47B  0049a4                  add      byte ptr [ecx - 0x5c], cl      
  0x0106D47E  050000f456              add      eax, 0x56f40000                
  0x0106D483  0002                    add      byte ptr [edx], al             
  0x0106D485  0000                    add      byte ptr [eax], al             
  0x0106D487  0000                    add      byte ptr [eax], al             
  0x0106D489  7056                    jo       0x106d4e1                      
  0x0106D48B  001e                    add      byte ptr [esi], bl             
  0x0106D48D  0000                    add      byte ptr [eax], al             
  0x0106D48F  0000                    add      byte ptr [eax], al             
  0x0106D491  f4                      hlt                                     
  0x0106D492  61                      popal                                   
  0x0106D493  001e                    add      byte ptr [esi], bl             
  0x0106D495  0000                    add      byte ptr [eax], al             
  0x0106D497  0000                    add      byte ptr [eax], al             
  0x0106D499  0238                    add      bh, byte ptr [eax]             
  0x0106D49B  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106D4A1  f4                      hlt                                     
  0x0106D4A2  56                      push     esi                            
  0x0106D4A3  0001                    add      byte ptr [ecx], al             
  0x0106D4A5  0000                    add      byte ptr [eax], al             
  0x0106D4A7  0000                    add      byte ptr [eax], al             
  0x0106D4A9  7056                    jo       0x106d501                      
  0x0106D4AB  001e                    add      byte ptr [esi], bl             
  0x0106D4AD  0000                    add      byte ptr [eax], al             
  0x0106D4AF  0000                    add      byte ptr [eax], al             
  0x0106D4B1  f4                      hlt                                     
  0x0106D4B2  61                      popal                                   
  0x0106D4B3  001e                    add      byte ptr [esi], bl             
  0x0106D4B5  0000                    add      byte ptr [eax], al             
  0x0106D4B7  0000                    add      byte ptr [eax], al             
  0x0106D4B9  0238                    add      bh, byte ptr [eax]             
  0x0106D4BB  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106D4C1  f4                      hlt                                     
  0x0106D4C2  56                      push     esi                            
  0x0106D4C3  0001                    add      byte ptr [ecx], al             
  0x0106D4C5  0000                    add      byte ptr [eax], al             
  0x0106D4C7  0000                    add      byte ptr [eax], al             
  0x0106D4C9  7056                    jo       0x106d521                      
  0x0106D4CB  001e                    add      byte ptr [esi], bl             
  0x0106D4CD  0000                    add      byte ptr [eax], al             
  0x0106D4CF  0000                    add      byte ptr [eax], al             
  0x0106D4D1  f4                      hlt                                     
  0x0106D4D2  61                      popal                                   
  0x0106D4D3  001e                    add      byte ptr [esi], bl             
  0x0106D4D5  0000                    add      byte ptr [eax], al             
  0x0106D4D7  0000                    add      byte ptr [eax], al             
  0x0106D4D9  0238                    add      bh, byte ptr [eax]             
  0x0106D4DB  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
                                        ; XREF: 0x0106D489 (cond_jump)
  0x0106D4E1  f4                      hlt                                     
  0x0106D4E2  56                      push     esi                            
  0x0106D4E3  0002                    add      byte ptr [edx], al             
  0x0106D4E5  0000                    add      byte ptr [eax], al             
  0x0106D4E7  0000                    add      byte ptr [eax], al             
  0x0106D4E9  7056                    jo       0x106d541                      
  0x0106D4EB  001e                    add      byte ptr [esi], bl             
  0x0106D4ED  0000                    add      byte ptr [eax], al             
  0x0106D4EF  0000                    add      byte ptr [eax], al             
  0x0106D4F1  f4                      hlt                                     
  0x0106D4F2  61                      popal                                   
  0x0106D4F3  001e                    add      byte ptr [esi], bl             
  0x0106D4F5  0000                    add      byte ptr [eax], al             
  0x0106D4F7  0000                    add      byte ptr [eax], al             
  0x0106D4F9  0238                    add      bh, byte ptr [eax]             
  0x0106D4FB  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
                                        ; XREF: 0x0106D4A9 (cond_jump)
  0x0106D501  f4                      hlt                                     
  0x0106D502  56                      push     esi                            
  0x0106D503  0007                    add      byte ptr [edi], al             
  0x0106D505  0000                    add      byte ptr [eax], al             
  0x0106D507  0000                    add      byte ptr [eax], al             
  0x0106D509  7056                    jo       0x106d561                      
  0x0106D50B  001e                    add      byte ptr [esi], bl             
  0x0106D50D  0000                    add      byte ptr [eax], al             
  0x0106D50F  0000                    add      byte ptr [eax], al             
  0x0106D511  f4                      hlt                                     
  0x0106D512  61                      popal                                   
  0x0106D513  001e                    add      byte ptr [esi], bl             
  0x0106D515  0000                    add      byte ptr [eax], al             
  0x0106D517  0000                    add      byte ptr [eax], al             
  0x0106D519  0338                    add      edi, dword ptr [eax]           
  0x0106D51B  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
                                        ; XREF: 0x0106D4C9 (cond_jump)
  0x0106D521  f4                      hlt                                     
  0x0106D522  61                      popal                                   
  0x0106D523  006f0b                  add      byte ptr [edi + 0xb], ch       
  0x0106D526  0000                    add      byte ptr [eax], al             
  0x0106D528  0001                    add      byte ptr [ecx], al             
  0x0106D52A  3800                    cmp      byte ptr [eax], al             
  0x0106D52C  93                      xchg     ebx, eax                       
  0x0106D52D  030d0000f956            add      ecx, dword ptr [0x56f90000]    
  0x0106D533  0003                    add      byte ptr [ebx], al             
  0x0106D535  0020                    add      byte ptr [eax], ah             
  0x0106D537  004aa4                  add      byte ptr [edx - 0x5c], cl      
  0x0106D53A  050000f461              add      eax, 0x61f40000                
  0x0106D53F  00730b                  add      byte ptr [ebx + 0xb], dh       
  0x0106D542  0000                    add      byte ptr [eax], al             
  0x0106D544  0006                    add      byte ptr [esi], al             
  0x0106D546  3800                    cmp      byte ptr [eax], al             
  0x0106D548  93                      xchg     ebx, eax                       
  0x0106D549  030d00000036            add      ecx, dword ptr [0x36000000]    
  0x0106D54F  0000                    add      byte ptr [eax], al             
  0x0106D552  44                      inc      esp                            
  0x0106D553  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x0106D559  c406                    les      eax, ptr [esi]                 
  0x0106D55B  0011                    add      byte ptr [ecx], dl             
  0x0106D55D  0000                    add      byte ptr [eax], al             
  0x0106D55F  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x0106D509 (cond_jump)
  0x0106D561  f4                      hlt                                     
  0x0106D562  56                      push     esi                            
  0x0106D563  00740b00                add      byte ptr [ebx + ecx], dh       
  0x0106D567  0000                    add      byte ptr [eax], al             
  0x0106D569  c422                    les      esp, ptr [edx]                 
  0x0106D56B  004000                  add      byte ptr [eax], al             
  0x0106D56E  2000                    and      byte ptr [eax], al             
  0x0106D570  009121000004            add      byte ptr [ecx + 0x4000021], dl 
  0x0106D576  3800                    cmp      byte ptr [eax], al             
  0x0106D578  93                      xchg     ebx, eax                       
  0x0106D579  030d0000f456            add      ecx, dword ptr [0x56f40000]    
  0x0106D57F  000400                  add      byte ptr [eax + eax], al       
  0x0106D582  0000                    add      byte ptr [eax], al             
  0x0106D584  007056                  add      byte ptr [eax + 0x56], dh      
  0x0106D587  001e                    add      byte ptr [esi], bl             
  0x0106D589  0000                    add      byte ptr [eax], al             
  0x0106D58B  0000                    add      byte ptr [eax], al             
  0x0106D58D  f4                      hlt                                     
  0x0106D58E  61                      popal                                   
  0x0106D58F  001e                    add      byte ptr [esi], bl             
  0x0106D591  0000                    add      byte ptr [eax], al             
  0x0106D593  0000                    add      byte ptr [eax], al             
  0x0106D595  0338                    add      edi, dword ptr [eax]           
  0x0106D597  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106D59D  5e                      pop      esi                            
  0x0106D59E  2000                    and      byte ptr [eax], al             
  0x0106D5A0  00f0                    add      al, dh                         
  0x0106D5A2  56                      push     esi                            
  0x0106D5A3  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x0106D5A6  0000                    add      byte ptr [eax], al             
  0x0106D5A8  0300                    add      eax, dword ptr [eax]           
  0x0106D5AA  2000                    and      byte ptr [eax], al             
  0x0106D5AC  0da4050000              or       eax, 0x5a4                     
  0x0106D5B1  f4                      hlt                                     
  0x0106D5B2  61                      popal                                   
  0x0106D5B3  00790b                  add      byte ptr [ecx + 0xb], bh       
  0x0106D5B6  0000                    add      byte ptr [eax], al             
  0x0106D5B8  000438                  add      byte ptr [eax + edi], al       
  0x0106D5BB  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106D5C1  f4                      hlt                                     
  0x0106D5C2  56                      push     esi                            
  0x0106D5C3  000400                  add      byte ptr [eax + eax], al       
  0x0106D5C6  0000                    add      byte ptr [eax], al             
  0x0106D5C8  007056                  add      byte ptr [eax + 0x56], dh      
  0x0106D5CB  001e                    add      byte ptr [esi], bl             
  0x0106D5CD  0000                    add      byte ptr [eax], al             
  0x0106D5CF  0000                    add      byte ptr [eax], al             
  0x0106D5D1  f4                      hlt                                     
  0x0106D5D2  61                      popal                                   
  0x0106D5D3  001e                    add      byte ptr [esi], bl             
  0x0106D5D5  0000                    add      byte ptr [eax], al             
  0x0106D5D7  0000                    add      byte ptr [eax], al             
  0x0106D5D9  0338                    add      edi, dword ptr [eax]           
  0x0106D5DB  0093030d0013            add      byte ptr [ebx + 0x13000d03], dl 
  0x0106D5E1  f4                      hlt                                     
  0x0106D5E2  61                      popal                                   
  0x0106D5E3  001e                    add      byte ptr [esi], bl             
  0x0106D5E5  0000                    add      byte ptr [eax], al             
  0x0106D5E7  0000                    add      byte ptr [eax], al             
  0x0106D5E9  61                      popal                                   
  0x0106D5EA  56                      push     esi                            
  0x0106D5EB  0000                    add      byte ptr [eax], al             
  0x0106D5ED  0138                    add      dword ptr [eax], edi           
  0x0106D5EF  0093030d0001            add      byte ptr [ebx + 0x1000d03], dl 
  0x0106D5F5  0c05                    or       al, 5                          
  0x0106D5F7  0000                    add      byte ptr [eax], al             
  0x0106D5FA  56                      push     esi                            
  0x0106D5FB  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106D5FE  0000                    add      byte ptr [eax], al             
  0x0106D600  854301                  test     dword ptr [ebx + 1], eax       
  0x0106D603  005524                  add      byte ptr [ebp + 0x24], dl      
  0x0106D606  0500004e22              add      eax, 0x224e0000                
  0x0106D60B  0000                    add      byte ptr [eax], al             
  0x0106D60E  44                      inc      esp                            
  0x0106D60F  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106D612  0000                    add      byte ptr [eax], al             
  0x0106D614  44                      inc      esp                            
  0x0106D615  f4                      hlt                                     
  0x0106D616  46                      inc      esi                            
  0x0106D617  0010                    add      byte ptr [eax], dl             
  0x0106D619  0000                    add      byte ptr [eax], al             
  0x0106D61B  0000                    add      byte ptr [eax], al             
  0x0106D61E  2100                    and      dword ptr [eax], eax           
  0x0106D620  00ee                    add      dh, ch                         
  0x0106D622  2100                    and      dword ptr [eax], eax           
  0x0106D624  36f4                    hlt                                     
  0x0106D626  44                      inc      esp                            
  0x0106D627  0010                    add      byte ptr [eax], dl             
  0x0106D629  0000                    add      byte ptr [eax], al             
  0x0106D62B  004000                  add      byte ptr [eax], al             
  0x0106D62E  2000                    and      byte ptr [eax], al             
  0x0106D630  00c4                    add      ah, al                         
  0x0106D632  2100                    and      dword ptr [eax], eax           
  0x0106D634  b0f0                    mov      al, 0xf0                       
                                        ; XREF: 0x0106D644 (cond_jump)
  0x0106D636  47                      inc      edi                            
  0x0106D637  009d0b00002e            add      byte ptr [ebp + 0x2e00000b], bl 
  0x0106D63D  1d0c004000              sbb      eax, 0x40000c                  
  0x0106D642  2000                    and      byte ptr [eax], al             
  0x0106D644  70f0                    jo       0x106d636                      
  0x0106D646  44                      inc      esp                            
  0x0106D647  00670b                  add      byte ptr [edi + 0xb], ah       
  0x0106D64A  0000                    add      byte ptr [eax], al             
  0x0106D64C  41                      inc      ecx                            
  0x0106D64E  2100                    and      dword ptr [eax], eax           
  0x0106D650  06                      push     es                             
  0x0106D651  1d0c0000b0              sbb      eax, 0xb000000c                
  0x0106D656  1800                    sbb      byte ptr [eax], al             
  0x0106D658  9e                      sahf                                    
  0x0106D659  0b00                    or       eax, dword ptr [eax]           
  0x0106D65B  0054f044                add      byte ptr [eax + esi*8 + 0x44], dl 
  0x0106D65F  007a0b                  add      byte ptr [edx + 0xb], bh       
  0x0106D662  0000                    add      byte ptr [eax], al             
  0x0106D664  44                      inc      esp                            
  0x0106D665  0020                    add      byte ptr [eax], ah             
  0x0106D667  00740020                add      byte ptr [eax + eax + 0x20], dh 
  0x0106D66B  0003                    add      byte ptr [ebx], al             
  0x0106D66D  0020                    add      byte ptr [eax], ah             
  0x0106D66F  001a                    add      byte ptr [edx], bl             
  0x0106D671  f4                      hlt                                     
  0x0106D672  0500804701              add      eax, 0x1478000                 
  0x0106D677  0000                    add      byte ptr [eax], al             
  0x0106D67A  44                      inc      esp                            
  0x0106D67B  00670b                  add      byte ptr [edi + 0xb], ah       
  0x0106D67E  0000                    add      byte ptr [eax], al             
  0x0106D680  06                      push     es                             
  0x0106D681  1c0c                    sbb      al, 0xc                        
  0x0106D683  0041c4                  add      byte ptr [ecx - 0x3c], al      
  0x0106D686  2100                    and      dword ptr [eax], eax           
  0x0106D688  40                      inc      eax                            
  0x0106D689  0020                    add      byte ptr [eax], ah             
  0x0106D68B  0000                    add      byte ptr [eax], al             
  0x0106D68D  7056                    jo       0x106d6e5                      
  0x0106D68F  00670b                  add      byte ptr [edi + 0xb], ah       
  0x0106D692  0000                    add      byte ptr [eax], al             
  0x0106D694  c54001                  lds      eax, ptr [eax + 1]             
  0x0106D697  00ff                    add      bh, bh                         
  0x0106D699  0100                    add      dword ptr [eax], eax           
  0x0106D69B  0002                    add      byte ptr [edx], al             
  0x0106D69D  f4                      hlt                                     
  0x0106D69E  05000c0000              add      eax, 0xc00                     
  0x0106D6A3  0000                    add      byte ptr [eax], al             
  0x0106D6A6  56                      push     esi                            
  0x0106D6A7  00710b                  add      byte ptr [ecx + 0xb], dh       
  0x0106D6AA  0000                    add      byte ptr [eax], al             
  0x0106D6AC  41                      inc      ecx                            
  0x0106D6AD  c421                    les      esp, ptr [ecx]                 
  0x0106D6AF  0006                    add      byte ptr [esi], al             
  0x0106D6B1  1d0c0041c4              sbb      eax, 0xc441000c                
  0x0106D6B6  2100                    and      dword ptr [eax], eax           
  0x0106D6B8  40                      inc      eax                            
  0x0106D6B9  0020                    add      byte ptr [eax], ah             
  0x0106D6BB  0000                    add      byte ptr [eax], al             
  0x0106D6BD  7056                    jo       0x106d715                      
  0x0106D6BF  00710b                  add      byte ptr [ecx + 0xb], dh       
  0x0106D6C2  0000                    add      byte ptr [eax], al             
  0x0106D6C4  00f4                    add      ah, dh                         
  0x0106D6C6  60                      pushal                                  
  0x0106D6C7  006c0b00                add      byte ptr [ebx + ecx], ch       
  0x0106D6CB  0000                    add      byte ptr [eax], al             
  0x0106D6CD  e056                    loopne   0x106d725                      
  0x0106D6CF  00440020                add      byte ptr [eax + eax + 0x20], al 
  0x0106D6D3  0000                    add      byte ptr [eax], al             
  0x0106D6D5  60                      pushal                                  
  0x0106D6D6  56                      push     esi                            
  0x0106D6D7  0000                    add      byte ptr [eax], al             
  0x0106D6D9  f4                      hlt                                     
  0x0106D6DA  61                      popal                                   
  0x0106D6DB  00660b                  add      byte ptr [esi + 0xb], ah       
  0x0106D6DE  0000                    add      byte ptr [eax], al             
  0x0106D6E0  0001                    add      byte ptr [ecx], al             
  0x0106D6E2  3800                    cmp      byte ptr [eax], al             
  0x0106D6E4  93                      xchg     ebx, eax                       
                                        ; XREF: 0x0106D68D (cond_jump)
  0x0106D6E5  030d0000f956            add      ecx, dword ptr [0x56f90000]    
  0x0106D6EB  0003                    add      byte ptr [ebx], al             
  0x0106D6ED  0020                    add      byte ptr [eax], ah             
  0x0106D6EF  0001                    add      byte ptr [ecx], al             
  0x0106D6F1  a5                      movsd    dword ptr es:[edi], dword ptr [esi] 
  0x0106D6F2  050000f461              add      eax, 0x61f40000                
  0x0106D6F7  00670b                  add      byte ptr [edi + 0xb], ah       
  0x0106D6FA  0000                    add      byte ptr [eax], al             
  0x0106D6FC  0009                    add      byte ptr [ecx], cl             
  0x0106D6FE  3800                    cmp      byte ptr [eax], al             
  0x0106D700  93                      xchg     ebx, eax                       
  0x0106D701  030d0000f056            add      ecx, dword ptr [0x56f00000]    
  0x0106D707  00700b                  add      byte ptr [eax + 0xb], dh       
  0x0106D70A  0000                    add      byte ptr [eax], al             
  0x0106D70C  0300                    add      eax, dword ptr [eax]           
  0x0106D70E  2000                    and      byte ptr [eax], al             
  0x0106D710  9f                      lahf                                    
  0x0106D711  f4                      hlt                                     
  0x0106D712  050000f444              add      eax, 0x44f40000                
  0x0106D717  0001                    add      byte ptr [ecx], al             
  0x0106D719  0000                    add      byte ptr [eax], al             
  0x0106D71B  0000                    add      byte ptr [eax], al             
  0x0106D71D  7044                    jo       0x106d763                      
  0x0106D71F  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x0106D722  0000                    add      byte ptr [eax], al             
  0x0106D724  13f4                    adc      esi, esp                       
  0x0106D726  61                      popal                                   
  0x0106D727  001e                    add      byte ptr [esi], bl             
  0x0106D729  0000                    add      byte ptr [eax], al             
  0x0106D72B  0000                    add      byte ptr [eax], al             
  0x0106D72D  61                      popal                                   
  0x0106D72E  56                      push     esi                            
  0x0106D72F  0000                    add      byte ptr [eax], al             
  0x0106D731  0138                    add      dword ptr [eax], edi           
  0x0106D733  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106D739  002400                  add      byte ptr [eax + eax], ah       
  0x0106D73C  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106D73F  001e                    add      byte ptr [esi], bl             
  0x0106D741  0000                    add      byte ptr [eax], al             
  0x0106D743  0000                    add      byte ptr [eax], al             
  0x0106D745  f4                      hlt                                     
  0x0106D746  61                      popal                                   
  0x0106D747  001e                    add      byte ptr [esi], bl             
  0x0106D749  0000                    add      byte ptr [eax], al             
  0x0106D74B  0000                    add      byte ptr [eax], al             
  0x0106D74D  0138                    add      dword ptr [eax], edi           
  0x0106D74F  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106D756  56                      push     esi                            
  0x0106D757  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x0106D75A  0000                    add      byte ptr [eax], al             
  0x0106D75C  80410100                add      byte ptr [ecx + 1], 0          
  0x0106D760  007056                  add      byte ptr [eax + 0x56], dh      
                                        ; XREF: 0x0106D71D (cond_jump)
  0x0106D763  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x0106D766  0000                    add      byte ptr [eax], al             
  0x0106D768  00f0                    add      al, dh                         
  0x0106D76A  56                      push     esi                            
  0x0106D76B  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106D76E  0000                    add      byte ptr [eax], al             
  0x0106D770  854301                  test     dword ptr [ebx + 1], eax       
  0x0106D773  004124                  add      byte ptr [ecx + 0x24], al      
  0x0106D776  0500000024              add      eax, 0x24000000                
  0x0106D77B  0000                    add      byte ptr [eax], al             
  0x0106D77D  7044                    jo       0x106d7c3                      
  0x0106D77F  001e                    add      byte ptr [esi], bl             
  0x0106D781  0000                    add      byte ptr [eax], al             
  0x0106D783  0000                    add      byte ptr [eax], al             
  0x0106D785  ee                      out      dx, al                         
  0x0106D786  2100                    and      dword ptr [eax], eax           
  0x0106D788  855001                  test     dword ptr [eax + 1], edx       
  0x0106D78B  000b                    add      byte ptr [ebx], cl             
  0x0106D78D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106D78E  050000f044              add      eax, 0x44f00000                
  0x0106D793  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x0106D796  0000                    add      byte ptr [eax], al             
  0x0106D798  40                      inc      eax                            
  0x0106D799  0020                    add      byte ptr [eax], ah             
  0x0106D79B  0000                    add      byte ptr [eax], al             
  0x0106D79D  e421                    in       al, 0x21                       
  0x0106D79F  0000                    add      byte ptr [eax], al             
  0x0106D7A1  7056                    jo       0x106d7f9                      
  0x0106D7A3  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x0106D7A6  0000                    add      byte ptr [eax], al             
  0x0106D7A8  00f4                    add      ah, dh                         
  0x0106D7AA  61                      popal                                   
  0x0106D7AB  001e                    add      byte ptr [esi], bl             
  0x0106D7AD  0000                    add      byte ptr [eax], al             
  0x0106D7AF  0000                    add      byte ptr [eax], al             
  0x0106D7B1  98                      cwde                                    
  0x0106D7B2  2000                    and      byte ptr [eax], al             
  0x0106D7B4  93                      xchg     ebx, eax                       
  0x0106D7B5  030d00004e22            add      ecx, dword ptr [0x224e0000]    
  0x0106D7BB  0000                    add      byte ptr [eax], al             
  0x0106D7BD  7056                    jo       0x106d815                      
  0x0106D7BF  00590b                  add      byte ptr [ecx + 0xb], bl       
  0x0106D7C2  0000                    add      byte ptr [eax], al             
  0x0106D7C4  00f4                    add      ah, dh                         
  0x0106D7C6  61                      popal                                   
  0x0106D7C7  001e                    add      byte ptr [esi], bl             
  0x0106D7C9  0000                    add      byte ptr [eax], al             
  0x0106D7CB  0000                    add      byte ptr [eax], al             
  0x0106D7CD  1038                    adc      byte ptr [eax], bh             
  0x0106D7CF  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106D7D5  f4                      hlt                                     
  0x0106D7D6  61                      popal                                   
  0x0106D7D7  001e                    add      byte ptr [esi], bl             
  0x0106D7D9  0000                    add      byte ptr [eax], al             
  0x0106D7DB  0000                    add      byte ptr [eax], al             
  0x0106D7DD  1038                    adc      byte ptr [eax], bh             
  0x0106D7DF  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106D7E6  56                      push     esi                            
  0x0106D7E7  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x0106D7EA  0000                    add      byte ptr [eax], al             
  0x0106D7EC  80600100                and      byte ptr [eax + 1], 0          
  0x0106D7F0  007056                  add      byte ptr [eax + 0x56], dh      
  0x0106D7F3  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x0106D7F6  0000                    add      byte ptr [eax], al             
  0x0106D7F8  0000                    add      byte ptr [eax], al             
  0x0106D7FA  2400                    and      al, 0                          
  0x0106D7FC  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106D7FF  001e                    add      byte ptr [esi], bl             
  0x0106D801  0000                    add      byte ptr [eax], al             
  0x0106D803  0000                    add      byte ptr [eax], al             
  0x0106D806  56                      push     esi                            
  0x0106D807  00700b                  add      byte ptr [eax + 0xb], dh       
  0x0106D80A  0000                    add      byte ptr [eax], al             
  0x0106D80C  06                      push     es                             
  0x0106D80D  1d0c0000f0              sbb      eax, 0xf000000c                
  0x0106D812  44                      inc      esp                            
  0x0106D813  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x0106D816  0000                    add      byte ptr [eax], al             
  0x0106D818  44                      inc      esp                            
  0x0106D819  0020                    add      byte ptr [eax], ah             
  0x0106D81B  0006                    add      byte ptr [esi], al             
                                        ; XREF: 0x010681C0 (jump)
  0x0106D81D  1c0c                    sbb      al, 0xc                        
  0x0106D81F  0010                    add      byte ptr [eax], dl             
  0x0106D821  cc                      int3                                    
  0x0106D822  06                      push     es                             
  0x0106D823  000a                    add      byte ptr [edx], cl             
  0x0106D825  0000                    add      byte ptr [eax], al             
  0x0106D827  0000                    add      byte ptr [eax], al             
  0x0106D829  f4                      hlt                                     
  0x0106D82A  61                      popal                                   
  0x0106D82B  001e                    add      byte ptr [esi], bl             
  0x0106D82D  0000                    add      byte ptr [eax], al             
  0x0106D82F  0000                    add      byte ptr [eax], al             
  0x0106D831  0838                    or       byte ptr [eax], bh             
  0x0106D833  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106D83A  56                      push     esi                            
  0x0106D83B  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x0106D83E  0000                    add      byte ptr [eax], al             
  0x0106D840  80480100                or       byte ptr [eax + 1], 0          
  0x0106D844  007056                  add      byte ptr [eax + 0x56], dh      
  0x0106D847  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x0106D84A  0000                    add      byte ptr [eax], al             
  0x0106D84C  00f0                    add      al, dh                         
  0x0106D84E  56                      push     esi                            
  0x0106D84F  00700b                  add      byte ptr [eax + 0xb], dh       
  0x0106D852  0000                    add      byte ptr [eax], al             
  0x0106D854  06                      push     es                             
  0x0106D855  1d0c0000f0              sbb      eax, 0xf000000c                
  0x0106D85A  44                      inc      esp                            
  0x0106D85B  005b0b                  add      byte ptr [ebx + 0xb], bl       
  0x0106D85E  0000                    add      byte ptr [eax], al             
  0x0106D860  44                      inc      esp                            
  0x0106D861  0020                    add      byte ptr [eax], ah             
  0x0106D863  0000                    add      byte ptr [eax], al             
  0x0106D865  f4                      hlt                                     
  0x0106D866  61                      popal                                   
  0x0106D867  001e                    add      byte ptr [esi], bl             
  0x0106D869  0000                    add      byte ptr [eax], al             
  0x0106D86B  0000                    add      byte ptr [eax], al             
  0x0106D86D  98                      cwde                                    
  0x0106D86E  2100                    and      dword ptr [eax], eax           
  0x0106D870  93                      xchg     ebx, eax                       
  0x0106D871  030d0000f056            add      ecx, dword ptr [0x56f00000]    
  0x0106D877  00670b                  add      byte ptr [edi + 0xb], ah       
  0x0106D87A  0000                    add      byte ptr [eax], al             
  0x0106D87C  00f0                    add      al, dh                         
  0x0106D87E  44                      inc      esp                            
  0x0106D87F  00700b                  add      byte ptr [eax + 0xb], dh       
  0x0106D882  0000                    add      byte ptr [eax], al             
  0x0106D884  44                      inc      esp                            
  0x0106D885  0020                    add      byte ptr [eax], ah             
  0x0106D887  000f                    add      byte ptr [edi], cl             
  0x0106D889  0c05                    or       al, 5                          
  0x0106D88B  0000                    add      byte ptr [eax], al             
  0x0106D88E  56                      push     esi                            
  0x0106D88F  00670b                  add      byte ptr [edi + 0xb], ah       
  0x0106D892  0000                    add      byte ptr [eax], al             
  0x0106D894  0300                    add      eax, dword ptr [eax]           
  0x0106D896  2e000b                  add      byte ptr cs:[ebx], cl          
  0x0106D899  f4                      hlt                                     
  0x0106D89A  0500000024              add      eax, 0x24000000                
  0x0106D89F  0000                    add      byte ptr [eax], al             
  0x0106D8A1  7044                    jo       0x106d8e7                      
  0x0106D8A3  001e                    add      byte ptr [esi], bl             
  0x0106D8A5  0000                    add      byte ptr [eax], al             
  0x0106D8A7  0000                    add      byte ptr [eax], al             
  0x0106D8A9  f4                      hlt                                     
  0x0106D8AA  61                      popal                                   
  0x0106D8AB  001e                    add      byte ptr [esi], bl             
  0x0106D8AD  0000                    add      byte ptr [eax], al             
  0x0106D8AF  0000                    add      byte ptr [eax], al             
  0x0106D8B1  0838                    or       byte ptr [eax], bh             
  0x0106D8B3  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106D8BA  56                      push     esi                            
  0x0106D8BB  00670b                  add      byte ptr [edi + 0xb], ah       
  0x0106D8BE  0000                    add      byte ptr [eax], al             
  0x0106D8C0  844101                  test     byte ptr [ecx + 1], al         
  0x0106D8C3  0003                    add      byte ptr [ebx], al             
  0x0106D8C5  0020                    add      byte ptr [eax], ah             
  0x0106D8C7  000b                    add      byte ptr [ebx], cl             
  0x0106D8C9  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106D8CA  050010cc06              add      eax, 0x6cc1000                 
  0x0106D8CF  0009                    add      byte ptr [ecx], cl             
  0x0106D8D1  0000                    add      byte ptr [eax], al             
  0x0106D8D3  0013                    add      byte ptr [ebx], dl             
  0x0106D8D5  0020                    add      byte ptr [eax], ah             
  0x0106D8D7  0000                    add      byte ptr [eax], al             
  0x0106D8D9  7056                    jo       0x106d931                      
  0x0106D8DB  0010                    add      byte ptr [eax], dl             
  0x0106D8DD  0000                    add      byte ptr [eax], al             
  0x0106D8DF  0000                    add      byte ptr [eax], al             
  0x0106D8E1  f4                      hlt                                     
  0x0106D8E2  61                      popal                                   
  0x0106D8E3  0010                    add      byte ptr [eax], dl             
  0x0106D8E5  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x0106D8A1 (cond_jump)
  0x0106D8E7  0000                    add      byte ptr [eax], al             
  0x0106D8E9  0838                    or       byte ptr [eax], bh             
  0x0106D8EB  006103                  add      byte ptr [ecx + 3], ah         
  0x0106D8EE  0d00000000              or       eax, 0                         
  0x0106D8F3  0000                    add      byte ptr [eax], al             
  0x0106D8F5  7045                    jo       0x106d93c                      
  0x0106D8F7  00560b                  add      byte ptr [esi + 0xb], dl       
  0x0106D8FA  0000                    add      byte ptr [eax], al             
  0x0106D8FC  007057                  add      byte ptr [eax + 0x57], dh      
  0x0106D8FF  00570b                  add      byte ptr [edi + 0xb], dl       
  0x0106D902  0000                    add      byte ptr [eax], al             
  0x0106D904  007062                  add      byte ptr [eax + 0x62], dh      
  0x0106D907  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x0106D90A  0000                    add      byte ptr [eax], al             
  0x0106D90C  22f4                    and      dh, ah                         
  0x0106D90E  0500ffff00              add      eax, 0xffff00                  
  0x0106D913  000c00                  add      byte ptr [eax + eax], cl       
  0x0106D916  0000                    add      byte ptr [eax], al             
  0x0106D918  0001                    add      byte ptr [ecx], al             
  0x0106D91A  3900                    cmp      dword ptr [eax], eax           
  0x0106D91C  007071                  add      byte ptr [eax + 0x71], dh      
  0x0106D91F  0002                    add      byte ptr [edx], al             
  0x0106D921  0000                    add      byte ptr [eax], al             
  0x0106D923  0000                    add      byte ptr [eax], al             
  0x0106D925  7071                    jo       0x106d998                      
  0x0106D927  0003                    add      byte ptr [ebx], al             
  0x0106D929  0000                    add      byte ptr [eax], al             
  0x0106D92B  0000                    add      byte ptr [eax], al             
  0x0106D92D  7071                    jo       0x106d9a0                      
  0x0106D92F  000400                  add      byte ptr [eax + eax], al       
  0x0106D932  0000                    add      byte ptr [eax], al             
  0x0106D934  0000                    add      byte ptr [eax], al             
  0x0106D936  360000                  add      byte ptr ss:[eax], al          
  0x0106D93A  44                      inc      esp                            
  0x0106D93B  00970b000010            add      byte ptr [edi + 0x1000000b], dl 
  0x0106D941  c406                    les      eax, ptr [esi]                 
  0x0106D943  001d00000000            add      byte ptr [0], bl               
  0x0106D949  f4                      hlt                                     
  0x0106D94A  56                      push     esi                            
  0x0106D94B  00a50b000000            add      byte ptr [ebp + 0xb], ah       
  0x0106D951  c422                    les      esp, ptr [edx]                 
  0x0106D953  004000                  add      byte ptr [eax], al             
  0x0106D956  2000                    and      byte ptr [eax], al             
  0x0106D958  0090210000e0            add      byte ptr [eax - 0x1fffffdf], dl 
  0x0106D95E  7000                    jo       0x106d960                      
                                        ; XREF: 0x0106D95E (cond_jump)
  0x0106D960  00c4                    add      ah, al                         
  0x0106D962  2200                    and      al, byte ptr [eax]             
  0x0106D964  00f4                    add      ah, dh                         
  0x0106D966  46                      inc      esi                            
  0x0106D967  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x0106D96D  f4                      hlt                                     
  0x0106D96E  44                      inc      esp                            
  0x0106D96F  0000                    add      byte ptr [eax], al             
  0x0106D971  0100                    add      dword ptr [eax], eax           
  0x0106D973  002e                    add      byte ptr [esi], ch             
  0x0106D975  1d0c004000              sbb      eax, 0x40000c                  
  0x0106D97A  2000                    and      byte ptr [eax], al             
  0x0106D97C  0090210000c4            add      byte ptr [eax - 0x3bffffdf], dl 
  0x0106D982  2200                    and      al, byte ptr [eax]             
  0x0106D984  00f4                    add      ah, dh                         
  0x0106D986  46                      inc      esi                            
  0x0106D987  00b5000000d0            add      byte ptr [ebp - 0x30000000], dh 
  0x0106D98E  44                      inc      esp                            
  0x0106D98F  00720b                  add      byte ptr [edx + 0xb], dh       
  0x0106D992  0000                    add      byte ptr [eax], al             
  0x0106D994  2e1d0c004000            sbb      eax, 0x40000c                  
  0x0106D99A  2000                    and      byte ptr [eax], al             
  0x0106D99C  009521000070            add      byte ptr [ebp + 0x70000021], dl 
  0x0106D9A2  6600410b                add      byte ptr [ecx + 0xb], al       
  0x0106D9A6  0000                    add      byte ptr [eax], al             
  0x0106D9A8  8b040d0000f066          mov      eax, dword ptr [ecx + 0x66f00000] 
  0x0106D9AF  00410b                  add      byte ptr [ecx + 0xb], al       
  0x0106D9B2  0000                    add      byte ptr [eax], al             
  0x0106D9B4  005e20                  add      byte ptr [esi + 0x20], bl      
  0x0106D9B7  0000                    add      byte ptr [eax], al             
  0x0106D9BA  56                      push     esi                            
  0x0106D9BB  007e0b                  add      byte ptr [esi + 0xb], bh       
  0x0106D9BE  0000                    add      byte ptr [eax], al             
  0x0106D9C0  0300                    add      eax, dword ptr [eax]           
  0x0106D9C2  2000                    and      byte ptr [eax], al             
  0x0106D9C4  07                      pop      es                             
  0x0106D9C5  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106D9C6  0500000738              add      eax, 0x38070000                
  0x0106D9CB  0000                    add      byte ptr [eax], al             
  0x0106D9CD  f4                      hlt                                     
  0x0106D9CE  60                      pushal                                  
  0x0106D9CF  008904000000            add      byte ptr [ecx + 4], cl         
  0x0106D9D5  f4                      hlt                                     
  0x0106D9D6  650039                  add      byte ptr gs:[ecx], bh          
  0x0106D9D9  0b00                    or       eax, dword ptr [eax]           
  0x0106D9DB  008b040d000c            add      byte ptr [ebx + 0xc000d04], cl 
  0x0106D9E1  0000                    add      byte ptr [eax], al             
  0x0106D9E3  0000                    add      byte ptr [eax], al             
  0x0106D9E6  6200                    bound    eax, qword ptr [eax]           
  0x0106D9E8  55                      push     ebp                            
  0x0106D9E9  0b00                    or       eax, dword ptr [eax]           
  0x0106D9EB  0022                    add      byte ptr [edx], ah             
  0x0106D9EE  0500470b00              add      eax, 0xb4700                   
  0x0106D9F3  0000                    add      byte ptr [eax], al             
  0x0106D9F6  57                      push     edi                            
  0x0106D9F7  00570b                  add      byte ptr [edi + 0xb], dl       
  0x0106D9FA  0000                    add      byte ptr [eax], al             
  0x0106D9FC  00f0                    add      al, dh                         
  0x0106D9FE  45                      inc      ebp                            
  0x0106D9FF  00560b                  add      byte ptr [esi + 0xb], dl       
  0x0106DA02  0000                    add      byte ptr [eax], al             
  0x0106DA04  0000                    add      byte ptr [eax], al             
  0x0106DA06  2400                    and      al, 0                          
  0x0106DA08  007044                  add      byte ptr [eax + 0x44], dh      
  0x0106DA0B  001e                    add      byte ptr [esi], bl             
  0x0106DA0D  0000                    add      byte ptr [eax], al             
  0x0106DA0F  0000                    add      byte ptr [eax], al             
  0x0106DA12  56                      push     esi                            
  0x0106DA13  006e0b                  add      byte ptr [esi + 0xb], ch       
  0x0106DA16  0000                    add      byte ptr [eax], al             
  0x0106DA18  855001                  test     dword ptr [eax + 1], edx       
  0x0106DA1B  0009                    add      byte ptr [ecx], cl             
  0x0106DA1D  94                      xchg     esp, eax                       
  0x0106DA1E  0500845001              add      eax, 0x1508400                 
  0x0106DA23  0000                    add      byte ptr [eax], al             
  0x0106DA25  7054                    jo       0x106da7b                      
  0x0106DA27  006e0b                  add      byte ptr [esi + 0xb], ch       
  0x0106DA2A  0000                    add      byte ptr [eax], al             
  0x0106DA2C  00f4                    add      ah, dh                         
  0x0106DA2E  61                      popal                                   
  0x0106DA2F  001e                    add      byte ptr [esi], bl             
  0x0106DA31  0000                    add      byte ptr [eax], al             
  0x0106DA33  0000                    add      byte ptr [eax], al             
  0x0106DA35  1038                    adc      byte ptr [eax], bh             
  0x0106DA37  0093030d00d5            add      byte ptr [ebx - 0x2afff2fd], dl 
  0x0106DA3D  0f05                    syscall                                 
  0x0106DA3F  0003                    add      byte ptr [ebx], al             
  0x0106DA41  0020                    add      byte ptr [eax], ah             
  0x0106DA43  0005a4050000            add      byte ptr [0x5a4], al           
  0x0106DA49  f4                      hlt                                     
  0x0106DA4A  61                      popal                                   
  0x0106DA4B  001e                    add      byte ptr [esi], bl             
  0x0106DA4D  0000                    add      byte ptr [eax], al             
  0x0106DA4F  0000                    add      byte ptr [eax], al             
  0x0106DA51  98                      cwde                                    
  0x0106DA52  2100                    and      dword ptr [eax], eax           
  0x0106DA54  93                      xchg     ebx, eax                       
  0x0106DA55  030d00130020            add      ecx, dword ptr [0x20001300]    
  0x0106DA5B  0000                    add      byte ptr [eax], al             
  0x0106DA5D  7056                    jo       0x106dab5                      
  0x0106DA5F  0001                    add      byte ptr [ecx], al             
  0x0106DA61  0000                    add      byte ptr [eax], al             
  0x0106DA63  0000                    add      byte ptr [eax], al             
  0x0106DA65  7056                    jo       0x106dabd                      
  0x0106DA67  001e                    add      byte ptr [esi], bl             
  0x0106DA69  0000                    add      byte ptr [eax], al             
  0x0106DA6B  0000                    add      byte ptr [eax], al             
  0x0106DA6D  f4                      hlt                                     
  0x0106DA6E  61                      popal                                   
  0x0106DA6F  001e                    add      byte ptr [esi], bl             
  0x0106DA71  0000                    add      byte ptr [eax], al             
  0x0106DA73  0000                    add      byte ptr [eax], al             
  0x0106DA75  0138                    add      dword ptr [eax], edi           
  0x0106DA77  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106DA7D  f4                      hlt                                     
  0x0106DA7E  61                      popal                                   
  0x0106DA7F  0001                    add      byte ptr [ecx], al             
  0x0106DA81  0000                    add      byte ptr [eax], al             
  0x0106DA83  0000                    add      byte ptr [eax], al             
  0x0106DA85  0138                    add      dword ptr [eax], edi           
  0x0106DA87  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106DA8D  f4                      hlt                                     
  0x0106DA8E  61                      popal                                   
  0x0106DA8F  001e                    add      byte ptr [esi], bl             
  0x0106DA91  0000                    add      byte ptr [eax], al             
  0x0106DA93  0000                    add      byte ptr [eax], al             
  0x0106DA95  1038                    adc      byte ptr [eax], bh             
  0x0106DA97  0093030d0000            add      byte ptr [ebx + 0xd03], dl     
  0x0106DA9D  7045                    jo       0x106dae4                      
  0x0106DA9F  00560b                  add      byte ptr [esi + 0xb], dl       
  0x0106DAA2  0000                    add      byte ptr [eax], al             
  0x0106DAA4  007057                  add      byte ptr [eax + 0x57], dh      
  0x0106DAA7  00570b                  add      byte ptr [edi + 0xb], dl       
  0x0106DAAA  0000                    add      byte ptr [eax], al             
  0x0106DAAC  007062                  add      byte ptr [eax + 0x62], dh      
  0x0106DAAF  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x0106DAB2  0000                    add      byte ptr [eax], al             
  0x0106DAB4  22f4                    and      dh, ah                         
  0x0106DAB6  0500ffff00              add      eax, 0xffff00                  
  0x0106DABB  0000                    add      byte ptr [eax], al             
  0x0106DABE  56                      push     esi                            
  0x0106DABF  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x0106DAC2  0000                    add      byte ptr [eax], al             
  0x0106DAC4  00f0                    add      al, dh                         
  0x0106DAC6  44                      inc      esp                            
  0x0106DAC7  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106DACA  0000                    add      byte ptr [eax], al             
  0x0106DACC  44                      inc      esp                            
  0x0106DACD  0020                    add      byte ptr [eax], ah             
  0x0106DACF  0000                    add      byte ptr [eax], al             
  0x0106DAD1  c421                    les      esp, ptr [ecx]                 
  0x0106DAD3  0000                    add      byte ptr [eax], al             
  0x0106DAD5  f4                      hlt                                     
  0x0106DAD6  45                      inc      ebp                            
  0x0106DAD7  0010                    add      byte ptr [eax], dl             
  0x0106DAD9  0000                    add      byte ptr [eax], al             
  0x0106DADB  00a00020002e            add      byte ptr [eax + 0x2e002000], ah 
  0x0106DAE1  1d0c0000f0              sbb      eax, 0xf000000c                
  0x0106DAE6  44                      inc      esp                            
  0x0106DAE7  009d0b000040            add      byte ptr [ebp + 0x4000000b], bl 
  0x0106DAED  0020                    add      byte ptr [eax], ah             
  0x0106DAEF  0000                    add      byte ptr [eax], al             
  0x0106DAF1  7056                    jo       0x106db49                      
  0x0106DAF3  009d0b00000c            add      byte ptr [ebp + 0xc00000b], bl 
  0x0106DAF9  0000                    add      byte ptr [eax], al             
  0x0106DAFB  0000                    add      byte ptr [eax], al             
  0x0106DAFE  56                      push     esi                            
  0x0106DAFF  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106DB02  0000                    add      byte ptr [eax], al             
  0x0106DB04  854001                  test     dword ptr [eax + 1], eax       
  0x0106DB07  0010                    add      byte ptr [eax], dl             
  0x0106DB09  2405                    and      al, 5                          
  0x0106DB0B  0000                    add      byte ptr [eax], al             
  0x0106DB0E  60                      pushal                                  
  0x0106DB0F  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106DB12  0000                    add      byte ptr [eax], al             
  0x0106DB14  005820                  add      byte ptr [eax + 0x20], bl      
  0x0106DB17  0020                    add      byte ptr [eax], ah             
  0x0106DB1A  0500470b00              add      eax, 0xb4700                   
  0x0106DB1F  0000                    add      byte ptr [eax], al             
  0x0106DB22  56                      push     esi                            
  0x0106DB23  00580b                  add      byte ptr [eax + 0xb], bl       
  0x0106DB26  0000                    add      byte ptr [eax], al             
  0x0106DB28  844101                  test     byte ptr [ecx + 1], al         
  0x0106DB2B  001b                    add      byte ptr [ebx], bl             
  0x0106DB2D  d821                    fsub     dword ptr [ecx]                
  0x0106DB2F  00b3030d0000            add      byte ptr [ebx + 0xd03], dh     
  0x0106DB35  7055                    jo       0x106db8c                      
  0x0106DB37  005a0b                  add      byte ptr [edx + 0xb], bl       
  0x0106DB3A  0000                    add      byte ptr [eax], al             
  0x0106DB3C  20f4                    and      ah, dh                         
  0x0106DB3E  0500ffff00              add      eax, 0xffff00                  
  0x0106DB43  00da                    add      dl, bl                         
  0x0106DB45  0c05                    or       al, 5                          
  0x0106DB47  008541010003            add      byte ptr [ebp + 0x3000141], al 
  0x0106DB4D  a4                      movsb    byte ptr es:[edi], byte ptr [esi] 
  0x0106DB4E  0500854201              add      eax, 0x1428500                 
  0x0106DB53  000f                    add      byte ptr [edi], cl             
  0x0106DB55  2405                    and      al, 5                          
  0x0106DB57  0000                    add      byte ptr [eax], al             
  0x0106DB5A  60                      pushal                                  
  0x0106DB5B  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106DB5E  0000                    add      byte ptr [eax], al             
  0x0106DB60  20f0                    and      al, dh                         
  0x0106DB62  0500470b00              add      eax, 0xb4700                   
  0x0106DB67  001b                    add      byte ptr [ebx], bl             
  0x0106DB6A  7000                    jo       0x106db6c                      
                                        ; XREF: 0x0106DB6A (cond_jump)
  0x0106DB6C  58                      pop      eax                            
  0x0106DB6D  0b00                    or       eax, dword ptr [eax]           
  0x0106DB6F  0000                    add      byte ptr [eax], al             
  0x0106DB72  55                      push     ebp                            
  0x0106DB73  005a0b                  add      byte ptr [edx + 0xb], bl       
  0x0106DB76  0000                    add      byte ptr [eax], al             
  0x0106DB78  b303                    mov      bl, 3                          
  0x0106DB7A  0d00007055              or       eax, 0x55700000                
  0x0106DB7F  005a0b                  add      byte ptr [edx + 0xb], bl       
  0x0106DB82  0000                    add      byte ptr [eax], al             
  0x0106DB84  20f4                    and      ah, dh                         
  0x0106DB86  0500ffff00              add      eax, 0xffff00                  
  0x0106DB8B  00c8                    add      al, cl                         
  0x0106DB8D  0c05                    or       al, 5                          
  0x0106DB8F  008543010082            add      byte ptr [ebp - 0x7dfffebd], al 
  0x0106DB95  2405                    and      al, 5                          
  0x0106DB97  0000                    add      byte ptr [eax], al             
  0x0106DB9A  56                      push     esi                            
  0x0106DB9B  00590b                  add      byte ptr [ecx + 0xb], bl       
  0x0106DB9E  0000                    add      byte ptr [eax], al             
  0x0106DBA0  00f0                    add      al, dh                         
  0x0106DBA2  44                      inc      esp                            
  0x0106DBA3  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106DBA6  0000                    add      byte ptr [eax], al             
  0x0106DBA8  44                      inc      esp                            
  0x0106DBA9  0020                    add      byte ptr [eax], ah             
  0x0106DBAB  008041010000            add      byte ptr [eax + 0x141], al     
  0x0106DBB1  d821                    fsub     dword ptr [ecx]                
  0x0106DBB3  0000                    add      byte ptr [eax], al             
  0x0106DBB5  90                      nop                                     
  0x0106DBB6  2000                    and      byte ptr [eax], al             
  0x0106DBB8  20f0                    and      al, dh                         
  0x0106DBBA  0500470b00              add      eax, 0xb4700                   
  0x0106DBBF  0000                    add      byte ptr [eax], al             
  0x0106DBC2  55                      push     ebp                            
  0x0106DBC3  005a0b                  add      byte ptr [edx + 0xb], bl       
  0x0106DBC6  0000                    add      byte ptr [eax], al             
  0x0106DBC8  b303                    mov      bl, 3                          
  0x0106DBCA  0d00911e0c              or       eax, 0xc1e9100                 
  0x0106DBCF  0000                    add      byte ptr [eax], al             
  0x0106DBD2  61                      popal                                   
  0x0106DBD3  00590b                  add      byte ptr [ecx + 0xb], bl       
  0x0106DBD6  0000                    add      byte ptr [eax], al             
  0x0106DBD8  006155                  add      byte ptr [ecx + 0x55], ah      
  0x0106DBDB  00911c0c0000            add      byte ptr [ecx + 0xc1c], dl     
  0x0106DBE2  44                      inc      esp                            
  0x0106DBE3  009d0b000000            add      byte ptr [ebp + 0xb], bl       
  0x0106DBE9  082500a00020            or       byte ptr [0x2000a000], ah      
  0x0106DBEF  0000                    add      byte ptr [eax], al             
  0x0106DBF2  44                      inc      esp                            
  0x0106DBF3  009b0b000041            add      byte ptr [ebx + 0x4100000b], bl 
  0x0106DBF9  c421                    les      esp, ptr [ecx]                 
  0x0106DBFB  00440020                add      byte ptr [eax + eax + 0x20], al 
  0x0106DBFF  0000                    add      byte ptr [eax], al             
  0x0106DC01  0423                    add      al, 0x23                       
  0x0106DC03  00440020                add      byte ptr [eax + eax + 0x20], al 
  0x0106DC07  0000                    add      byte ptr [eax], al             
  0x0106DC09  9a200000d82100          lcall    0x21, 0xd8000020               
  0x0106DC10  00f0                    add      al, dh                         
  0x0106DC12  56                      push     esi                            
  0x0106DC13  00590b                  add      byte ptr [ecx + 0xb], bl       
  0x0106DC16  0000                    add      byte ptr [eax], al             
  0x0106DC18  80410100                add      byte ptr [ecx + 1], 0          
  0x0106DC1C  00d0                    add      al, dl                         
  0x0106DC1E  2100                    and      dword ptr [eax], eax           
  0x0106DC20  ca030d                  retf     0xd03                          
  0x0106DC23  0000                    add      byte ptr [eax], al             
  0x0106DC26  56                      push     esi                            
  0x0106DC27  00590b                  add      byte ptr [ecx + 0xb], bl       
  0x0106DC2A  0000                    add      byte ptr [eax], al             
  0x0106DC2C  80410100                add      byte ptr [ecx + 1], 0          
  0x0106DC30  00d0                    add      al, dl                         
  0x0106DC32  2100                    and      dword ptr [eax], eax           
  0x0106DC34  91                      xchg     ecx, eax                       
  0x0106DC35  1e                      push     ds                             
  0x0106DC36  0c00                    or       al, 0                          
  0x0106DC38  006055                  add      byte ptr [eax + 0x55], ah      
  0x0106DC3B  00911c0c0000            add      byte ptr [ecx + 0xc1c], dl     
  0x0106DC42  56                      push     esi                            
  0x0106DC43  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x0106DC46  0000                    add      byte ptr [eax], al             
  0x0106DC48  00f0                    add      al, dh                         
  0x0106DC4A  44                      inc      esp                            
  0x0106DC4B  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106DC4E  0000                    add      byte ptr [eax], al             
  0x0106DC50  44                      inc      esp                            
  0x0106DC51  0020                    add      byte ptr [eax], ah             
  0x0106DC53  0000                    add      byte ptr [eax], al             
  0x0106DC55  44                      inc      esp                            
  0x0106DC56  2300                    and      eax, dword ptr [eax]           
  0x0106DC58  44                      inc      esp                            
  0x0106DC59  0020                    add      byte ptr [eax], ah             
  0x0106DC5B  0000                    add      byte ptr [eax], al             
  0x0106DC5D  0423                    add      al, 0x23                       
  0x0106DC5F  00440020                add      byte ptr [eax + eax + 0x20], al 
  0x0106DC63  0000                    add      byte ptr [eax], al             
  0x0106DC65  d821                    fsub     dword ptr [ecx]                
  0x0106DC67  0000                    add      byte ptr [eax], al             
  0x0106DC6A  56                      push     esi                            
  0x0106DC6B  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106DC6E  0000                    add      byte ptr [eax], al             
  0x0106DC70  40                      inc      eax                            
  0x0106DC71  0020                    add      byte ptr [eax], ah             
  0x0106DC73  0000                    add      byte ptr [eax], al             
  0x0106DC75  44                      inc      esp                            
  0x0106DC76  2300                    and      eax, dword ptr [eax]           
  0x0106DC78  40                      inc      eax                            
  0x0106DC79  0020                    add      byte ptr [eax], ah             
  0x0106DC7B  0000                    add      byte ptr [eax], al             
  0x0106DC7D  d021                    shl      byte ptr [ecx], 1              
  0x0106DC7F  001b                    add      byte ptr [ebx], bl             
  0x0106DC81  0020                    add      byte ptr [eax], ah             
  0x0106DC83  00b3030d0000            add      byte ptr [ebx + 0xd03], dh     
  0x0106DC89  7055                    jo       0x106dce0                      
  0x0106DC8B  005a0b                  add      byte ptr [edx + 0xb], bl       
  0x0106DC8E  0000                    add      byte ptr [eax], al             
  0x0106DC90  20f4                    and      ah, dh                         
  0x0106DC92  0500ffff00              add      eax, 0xffff00                  
  0x0106DC97  00450c                  add      byte ptr [ebp + 0xc], al       
  0x0106DC9A  0500854401              add      eax, 0x1448500                 
  0x0106DC9F  000f                    add      byte ptr [edi], cl             
  0x0106DCA1  2405                    and      al, 5                          
  0x0106DCA3  0020                    add      byte ptr [eax], ah             
  0x0106DCA6  0500470b00              add      eax, 0xb4700                   
  0x0106DCAB  0000                    add      byte ptr [eax], al             
  0x0106DCAE  60                      pushal                                  
  0x0106DCAF  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106DCB2  0000                    add      byte ptr [eax], al             
  0x0106DCB4  00f0                    add      al, dh                         
  0x0106DCB6  7000                    jo       0x106dcb8                      
                                        ; XREF: 0x0106DCB6 (cond_jump)
  0x0106DCB8  58                      pop      eax                            
  0x0106DCB9  0b00                    or       eax, dword ptr [eax]           
  0x0106DCBB  0000                    add      byte ptr [eax], al             
  0x0106DCBE  57                      push     edi                            
  0x0106DCBF  005a0b                  add      byte ptr [edx + 0xb], bl       
  0x0106DCC2  0000                    add      byte ptr [eax], al             
  0x0106DCC4  b303                    mov      bl, 3                          
  0x0106DCC6  0d00007055              or       eax, 0x55700000                
  0x0106DCCB  005a0b                  add      byte ptr [edx + 0xb], bl       
  0x0106DCCE  0000                    add      byte ptr [eax], al             
  0x0106DCD0  20f4                    and      ah, dh                         
  0x0106DCD2  0500ffff00              add      eax, 0xffff00                  
  0x0106DCD7  00150c050085            add      byte ptr [0x8500050c], dl      
  0x0106DCDD  45                      inc      ebp                            
  0x0106DCDE  0100                    add      dword ptr [eax], eax           
                                        ; XREF: 0x0106DC89 (cond_jump)
  0x0106DCE0  1324050020f005          adc      esp, dword ptr [eax + 0x5f02000] 
  0x0106DCE7  00470b                  add      byte ptr [edi + 0xb], al       
  0x0106DCEA  0000                    add      byte ptr [eax], al             
  0x0106DCEC  00f0                    add      al, dh                         
  0x0106DCEE  60                      pushal                                  
  0x0106DCEF  00450b                  add      byte ptr [ebp + 0xb], al       
  0x0106DCF2  0000                    add      byte ptr [eax], al             
  0x0106DCF4  00f0                    add      al, dh                         
  0x0106DCF6  7000                    jo       0x106dcf8                      
                                        ; XREF: 0x0106DCF6 (cond_jump)
  0x0106DCF8  58                      pop      eax                            
  0x0106DCF9  0b00                    or       eax, dword ptr [eax]           
  0x0106DCFB  0000                    add      byte ptr [eax], al             
  0x0106DCFE  57                      push     edi                            
  0x0106DCFF  005a0b                  add      byte ptr [edx + 0xb], bl       
  0x0106DD02  0000                    add      byte ptr [eax], al             
  0x0106DD04  b303                    mov      bl, 3                          
  0x0106DD06  0d0000f056              or       eax, 0x56f00000                
  0x0106DD0B  00550b                  add      byte ptr [ebp + 0xb], dl       
  0x0106DD0E  0000                    add      byte ptr [eax], al             
  0x0106DD10  844101                  test     byte ptr [ecx + 1], al         
  0x0106DD13  0000                    add      byte ptr [eax], al             
  0x0106DD15  d021                    shl      byte ptr [ecx], 1              
  0x0106DD17  00911e0c0000            add      byte ptr [ecx + 0xc1e], dl     
  0x0106DD1D  60                      pushal                                  
  0x0106DD1E  55                      push     ebp                            
  0x0106DD1F  00911c0c0020            add      byte ptr [ecx + 0x20000c1c], dl 
  0x0106DD25  f4                      hlt                                     
  0x0106DD26  0500ffff00              add      eax, 0xffff00                  
  0x0106DD2B  000c00                  add      byte ptr [eax + eax], cl       
  0x0106DD2E  0000                    add      byte ptr [eax], al             
  0x0106DD30  00f4                    add      ah, dh                         
  0x0106DD32  56                      push     esi                            
  0x0106DD33  001500000000            add      byte ptr [0], dl               
  0x0106DD39  f4                      hlt                                     
  0x0106DD3A  57                      push     edi                            
  0x0106DD3B  0001                    add      byte ptr [ecx], al             
  0x0106DD3D  0000                    add      byte ptr [eax], al             
  0x0106DD3F  0000                    add      byte ptr [eax], al             
  0x0106DD41  f4                      hlt                                     
  0x0106DD42  7000                    jo       0x106dd44                      
                                        ; XREF: 0x0106DD42 (cond_jump)
  0x0106DD44  90                      nop                                     
  0x0106DD45  0300                    add      eax, dword ptr [eax]           
  0x0106DD47  0000                    add      byte ptr [eax], al             
  0x0106DD49  0039                    add      byte ptr [ecx], bh             
  0x0106DD4B  0000                    add      byte ptr [eax], al             
  0x0106DD4D  f4                      hlt                                     
  0x0106DD4E  60                      pushal                                  
  0x0106DD4F  0000                    add      byte ptr [eax], al             
  0x0106DD51  0100                    add      dword ptr [eax], eax           
  0x0106DD53  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x0106DD59  0100                    add      dword ptr [eax], eax           
  0x0106DD5B  0003                    add      byte ptr [ebx], al             
  0x0106DD5D  0020                    add      byte ptr [eax], ah             
  0x0106DD5F  0000                    add      byte ptr [eax], al             
  0x0106DD61  2405                    and      al, 5                          
  0x0106DD63  000c00                  add      byte ptr [eax + eax], cl       
  0x0106DD66  0000                    add      byte ptr [eax], al             
  0x0106DD68  007054                  add      byte ptr [eax + 0x54], dh      
  0x0106DD6B  00fd                    add      ch, bh                         
  0x0106DD6D  0000                    add      byte ptr [eax], al             
  0x0106DD6F  0000                    add      byte ptr [eax], al             
  0x0106DD71  7044                    jo       0x106ddb7                      
  0x0106DD73  00fe                    add      dh, bh                         
  0x0106DD75  0000                    add      byte ptr [eax], al             
  0x0106DD77  0000                    add      byte ptr [eax], al             
  0x0106DD79  7060                    jo       0x106dddb                      
  0x0106DD7B  00ff                    add      bh, bh                         
  0x0106DD7D  0000                    add      byte ptr [eax], al             
  0x0106DD7F  0003                    add      byte ptr [ebx], al             
  0x0106DD81  0020                    add      byte ptr [eax], ah             
  0x0106DD83  0010                    add      byte ptr [eax], dl             
  0x0106DD85  2405                    and      al, 5                          
  0x0106DD87  0000                    add      byte ptr [eax], al             
  0x0106DD89  f4                      hlt                                     
  0x0106DD8A  56                      push     esi                            
  0x0106DD8B  000c00                  add      byte ptr [eax + eax], cl       
  0x0106DD8E  0000                    add      byte ptr [eax], al             
  0x0106DD90  00f4                    add      ah, dh                         
  0x0106DD92  7000                    jo       0x106dd94                      
                                        ; XREF: 0x0106DD92 (cond_jump)
  0x0106DD94  da0500000000            fiadd    dword ptr [0]                  
  0x0106DD9A  3900                    cmp      dword ptr [eax], eax           
  0x0106DD9C  80f00b                  xor      al, 0xb                        
  0x0106DD9F  008001000003            add      byte ptr [eax + 0x3000001], al 
  0x0106DDA5  0020                    add      byte ptr [eax], ah             
  0x0106DDA7  0000                    add      byte ptr [eax], al             
  0x0106DDA9  2405                    and      al, 5                          
  0x0106DDAB  0000                    add      byte ptr [eax], al             
  0x0106DDAE  56                      push     esi                            
  0x0106DDAF  00fd                    add      ch, bh                         
  0x0106DDB1  0000                    add      byte ptr [eax], al             
  0x0106DDB3  0000                    add      byte ptr [eax], al             
  0x0106DDB6  60                      pushal                                  
                                        ; XREF: 0x0106DD71 (cond_jump)
  0x0106DDB7  00ff                    add      bh, bh                         
  0x0106DDB9  0000                    add      byte ptr [eax], al             
  0x0106DDBB  0000                    add      byte ptr [eax], al             
  0x0106DDBE  44                      inc      esp                            
  0x0106DDBF  00fe                    add      dh, bh                         
  0x0106DDC1  0000                    add      byte ptr [eax], al             
  0x0106DDC3  0003                    add      byte ptr [ebx], al             
  0x0106DDC5  f4                      hlt                                     
  0x0106DDC6  45                      inc      ebp                            
  0x0106DDC7  00da                    add      dl, bl                         
  0x0106DDC9  0500000324              add      eax, 0x24030000                
  0x0106DDCE  0500007045              add      eax, 0x45700000                
  0x0106DDD3  00480b                  add      byte ptr [eax + 0xb], cl       
  0x0106DDD6  0000                    add      byte ptr [eax], al             
  0x0106DDD8  0098200000f0            add      byte ptr [eax - 0xfffffe0], bl 
  0x0106DDDE  56                      push     esi                            
  0x0106DDDF  00480b                  add      byte ptr [eax + 0xb], cl       
  0x0106DDE2  0000                    add      byte ptr [eax], al             
  0x0106DDE4  40                      inc      eax                            
  0x0106DDE5  99                      cdq                                     
  0x0106DDE6  2100                    and      dword ptr [eax], eax           
  0x0106DDE8  007054                  add      byte ptr [eax + 0x54], dh      
  0x0106DDEB  00480b                  add      byte ptr [eax + 0xb], cl       
  0x0106DDEE  0000                    add      byte ptr [eax], al             
  0x0106DDF0  00f4                    add      ah, dh                         
  0x0106DDF2  56                      push     esi                            
  0x0106DDF3  0009                    add      byte ptr [ecx], cl             
  0x0106DDF5  0000                    add      byte ptr [eax], al             
  0x0106DDF7  0000                    add      byte ptr [eax], al             
  0x0106DDF9  f4                      hlt                                     
  0x0106DDFA  57                      push     edi                            
  0x0106DDFB  0002                    add      byte ptr [edx], al             
  0x0106DDFD  0000                    add      byte ptr [eax], al             
  0x0106DDFF  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x0106DE05  0100                    add      dword ptr [eax], eax           
  0x0106DE07  0003                    add      byte ptr [ebx], al             
  0x0106DE09  0020                    add      byte ptr [eax], ah             
  0x0106DE0B  0000                    add      byte ptr [eax], al             
  0x0106DE0D  2405                    and      al, 5                          
  0x0106DE0F  0000                    add      byte ptr [eax], al             
  0x0106DE12  56                      push     esi                            
  0x0106DE13  00fd                    add      ch, bh                         
  0x0106DE15  0000                    add      byte ptr [eax], al             
  0x0106DE17  008545010009            add      byte ptr [ebp + 0x9000145], al 
  0x0106DE1D  2405                    and      al, 5                          
  0x0106DE1F  0000                    add      byte ptr [eax], al             
  0x0106DE21  f4                      hlt                                     
  0x0106DE22  56                      push     esi                            
  0x0106DE23  000c00                  add      byte ptr [eax + eax], cl       
  0x0106DE26  0000                    add      byte ptr [eax], al             
  0x0106DE28  00f4                    add      ah, dh                         
  0x0106DE2A  7000                    jo       0x106de2c                      
                                        ; XREF: 0x0106DE2A (cond_jump)
  0x0106DE2C  2201                    and      al, byte ptr [ecx]             
  0x0106DE2E  0000                    add      byte ptr [eax], al             
  0x0106DE30  00f4                    add      ah, dh                         
  0x0106DE32  7100                    jno      0x106de34                      
                                        ; XREF: 0x0106DE32 (cond_jump)
  0x0106DE34  de0a                    fimul    word ptr [edx]                 
  0x0106DE36  0000                    add      byte ptr [eax], al             
  0x0106DE38  80f00b                  xor      al, 0xb                        
  0x0106DE3B  008001000000            add      byte ptr [eax + 1], al         
  0x0106DE41  f4                      hlt                                     
  0x0106DE42  56                      push     esi                            
  0x0106DE43  0019                    add      byte ptr [ecx], bl             
  0x0106DE45  0000                    add      byte ptr [eax], al             
  0x0106DE47  0000                    add      byte ptr [eax], al             
  0x0106DE49  f4                      hlt                                     
  0x0106DE4A  57                      push     edi                            
  0x0106DE4B  0002                    add      byte ptr [edx], al             
  0x0106DE4D  0000                    add      byte ptr [eax], al             
  0x0106DE4F  0000                    add      byte ptr [eax], al             
  0x0106DE51  0039                    add      byte ptr [ecx], bh             
  0x0106DE53  0000                    add      byte ptr [eax], al             
  0x0106DE55  f4                      hlt                                     
  0x0106DE56  7000                    jo       0x106de58                      
                                        ; XREF: 0x0106DE56 (cond_jump)
  0x0106DE58  800000                  add      byte ptr [eax], 0              
  0x0106DE5B  0000                    add      byte ptr [eax], al             
  0x0106DE5D  f4                      hlt                                     
  0x0106DE5E  60                      pushal                                  
  0x0106DE5F  00400b                  add      byte ptr [eax + 0xb], al       
  0x0106DE62  0000                    add      byte ptr [eax], al             
  0x0106DE64  80f00b                  xor      al, 0xb                        
  0x0106DE67  008001000003            add      byte ptr [eax + 0x3000001], al 
  0x0106DE6D  0020                    add      byte ptr [eax], ah             
  0x0106DE6F  0000                    add      byte ptr [eax], al             
  0x0106DE71  2405                    and      al, 5                          
  0x0106DE73  000c00                  add      byte ptr [eax + eax], cl       
  0x0106DE76  0000                    add      byte ptr [eax], al             
  0x0106DE78  00f4                    add      ah, dh                         
  0x0106DE7A  56                      push     esi                            
  0x0106DE7B  0019                    add      byte ptr [ecx], bl             
  0x0106DE7D  0000                    add      byte ptr [eax], al             
  0x0106DE7F  0000                    add      byte ptr [eax], al             
  0x0106DE81  f4                      hlt                                     
  0x0106DE82  57                      push     edi                            
  0x0106DE83  0000                    add      byte ptr [eax], al             
  0x0106DE85  0000                    add      byte ptr [eax], al             
  0x0106DE87  0000                    add      byte ptr [eax], al             
  0x0106DE89  f4                      hlt                                     
  0x0106DE8A  7000                    jo       0x106de8c                      
                                        ; XREF: 0x0106DE8A (cond_jump)
  0x0106DE8C  800000                  add      byte ptr [eax], 0              
  0x0106DE8F  0080f00b0080            add      byte ptr [eax - 0x7ffff410], al 
  0x0106DE95  0100                    add      dword ptr [eax], eax           
  0x0106DE97  0003                    add      byte ptr [ebx], al             
  0x0106DE99  0020                    add      byte ptr [eax], ah             
  0x0106DE9B  0000                    add      byte ptr [eax], al             
  0x0106DE9D  2405                    and      al, 5                          
  0x0106DE9F  000c00                  add      byte ptr [eax + eax], cl       
  0x0106DEA2  0000                    add      byte ptr [eax], al             
  0x0106DEA4  0000                    add      byte ptr [eax], al             
  0x0106DEA6  0000                    add      byte ptr [eax], al             
  0x0106DEA8  40                      inc      eax                            
  0x0106DEA9  1bd0                    sbb      edx, eax                       
  0x0106DEAB  00bc0000007201          add      byte ptr [eax + eax + 0x1720000], bh 
  0x0106DEB2  0500265e7d              add      eax, 0x7d5e2600                
  0x0106DEB7  0000                    add      byte ptr [eax], al             
  0x0106DEB9  7060                    jo       0x106df1b                      
  0x0106DEBB  0000                    add      byte ptr [eax], al             
  0x0106DEBD  07                      pop      es                             
  0x0106DEBE  0000                    add      byte ptr [eax], al             
  0x0106DEC0  00f4                    add      ah, dh                         
  0x0106DEC2  56                      push     esi                            
  0x0106DEC3  0007                    add      byte ptr [edi], al             
  0x0106DEC5  0000                    add      byte ptr [eax], al             
  0x0106DEC7  0000                    add      byte ptr [eax], al             
  0x0106DEC9  f4                      hlt                                     
  0x0106DECA  60                      pushal                                  
  0x0106DECB  0000                    add      byte ptr [eax], al             
  0x0106DECD  0000                    add      byte ptr [eax], al             
  0x0106DECF  0000                    add      byte ptr [eax], al             
  0x0106DED1  f4                      hlt                                     
  0x0106DED2  7000                    jo       0x106ded4                      
                                        ; XREF: 0x0106DED2 (cond_jump)
  0x0106DED4  0001                    add      byte ptr [ecx], al             
  0x0106DED6  0000                    add      byte ptr [eax], al             
  0x0106DED8  0000                    add      byte ptr [eax], al             
  0x0106DEDA  3900                    cmp      dword ptr [eax], eax           
  0x0106DEDC  80010d                  add      byte ptr [ecx], 0xd            
  0x0106DEDF  0000                    add      byte ptr [eax], al             
  0x0106DEE1  f4                      hlt                                     
  0x0106DEE2  56                      push     esi                            
  0x0106DEE3  0007                    add      byte ptr [edi], al             
  0x0106DEE5  0000                    add      byte ptr [eax], al             
  0x0106DEE7  0000                    add      byte ptr [eax], al             
  0x0106DEE9  f4                      hlt                                     
  0x0106DEEA  60                      pushal                                  
  0x0106DEEB  0000                    add      byte ptr [eax], al             
  0x0106DEED  0100                    add      dword ptr [eax], eax           
  0x0106DEEF  0000                    add      byte ptr [eax], al             
  0x0106DEF1  f4                      hlt                                     
  0x0106DEF2  7000                    jo       0x106def4                      
                                        ; XREF: 0x0106DEF2 (cond_jump)
  0x0106DEF4  0001                    add      byte ptr [ecx], al             
  0x0106DEF6  0000                    add      byte ptr [eax], al             
  0x0106DEF8  0001                    add      byte ptr [ecx], al             
  0x0106DEFA  3900                    cmp      dword ptr [eax], eax           
  0x0106DEFC  80010d                  add      byte ptr [ecx], 0xd            
  0x0106DEFF  0000                    add      byte ptr [eax], al             
  0x0106DF01  f4                      hlt                                     
  0x0106DF02  56                      push     esi                            
  0x0106DF03  0007                    add      byte ptr [edi], al             
  0x0106DF05  0000                    add      byte ptr [eax], al             
  0x0106DF07  0000                    add      byte ptr [eax], al             
  0x0106DF09  f4                      hlt                                     
  0x0106DF0A  60                      pushal                                  
  0x0106DF0B  0000                    add      byte ptr [eax], al             
  0x0106DF0D  0200                    add      al, byte ptr [eax]             
  0x0106DF0F  0000                    add      byte ptr [eax], al             
  0x0106DF11  f4                      hlt                                     
  0x0106DF12  7000                    jo       0x106df14                      
                                        ; XREF: 0x0106DF12 (cond_jump)
  0x0106DF14  0001                    add      byte ptr [ecx], al             
  0x0106DF16  0000                    add      byte ptr [eax], al             
  0x0106DF18  0002                    add      byte ptr [edx], al             
  0x0106DF1A  3900                    cmp      dword ptr [eax], eax           
  0x0106DF1C  80010d                  add      byte ptr [ecx], 0xd            
  0x0106DF1F  0000                    add      byte ptr [eax], al             
  0x0106DF21  f4                      hlt                                     
  0x0106DF22  56                      push     esi                            
  0x0106DF23  0007                    add      byte ptr [edi], al             
  0x0106DF25  0000                    add      byte ptr [eax], al             
  0x0106DF27  0000                    add      byte ptr [eax], al             
  0x0106DF29  f4                      hlt                                     
  0x0106DF2A  60                      pushal                                  
  0x0106DF2B  0000                    add      byte ptr [eax], al             
  0x0106DF2D  0300                    add      eax, dword ptr [eax]           
  0x0106DF2F  0000                    add      byte ptr [eax], al             
  0x0106DF31  f4                      hlt                                     
  0x0106DF32  7000                    jo       0x106df34                      
                                        ; XREF: 0x0106DF32 (cond_jump)
  0x0106DF34  0001                    add      byte ptr [ecx], al             
  0x0106DF36  0000                    add      byte ptr [eax], al             
  0x0106DF38  0003                    add      byte ptr [ebx], al             
  0x0106DF3A  3900                    cmp      dword ptr [eax], eax           
  0x0106DF3C  80010d                  add      byte ptr [ecx], 0xd            
  0x0106DF3F  0000                    add      byte ptr [eax], al             
  0x0106DF41  f4                      hlt                                     
  0x0106DF42  56                      push     esi                            
  0x0106DF43  0007                    add      byte ptr [edi], al             
  0x0106DF45  0000                    add      byte ptr [eax], al             
  0x0106DF47  0000                    add      byte ptr [eax], al             
  0x0106DF49  f4                      hlt                                     
  0x0106DF4A  60                      pushal                                  
  0x0106DF4B  0000                    add      byte ptr [eax], al             
  0x0106DF4D  0400                    add      al, 0                          
  0x0106DF4F  0000                    add      byte ptr [eax], al             
  0x0106DF51  f4                      hlt                                     
  0x0106DF52  7000                    jo       0x106df54                      
                                        ; XREF: 0x0106DF52 (cond_jump)
  0x0106DF54  0001                    add      byte ptr [ecx], al             
  0x0106DF56  0000                    add      byte ptr [eax], al             
  0x0106DF58  000439                  add      byte ptr [ecx + edi], al       
  0x0106DF5B  0080010d0000            add      byte ptr [eax + 0xd01], al     
  0x0106DF61  f4                      hlt                                     
  0x0106DF62  44                      inc      esp                            
  0x0106DF63  0000                    add      byte ptr [eax], al             
  0x0106DF65  004000                  add      byte ptr [eax], al             
  0x0106DF68  00704c                  add      byte ptr [eax + 0x4c], dh      
  0x0106DF6B  0000                    add      byte ptr [eax], al             
  0x0106DF6D  0000                    add      byte ptr [eax], al             
  0x0106DF6F  0000                    add      byte ptr [eax], al             
  0x0106DF71  f4                      hlt                                     
  0x0106DF72  44                      inc      esp                            
  0x0106DF73  007982                  add      byte ptr [ecx - 0x7e], bh      
  0x0106DF76  5a                      pop      edx                            
  0x0106DF77  0000                    add      byte ptr [eax], al             
  0x0106DF79  704c                    jo       0x106dfc7                      
  0x0106DF7B  0001                    add      byte ptr [ecx], al             
  0x0106DF7D  0000                    add      byte ptr [eax], al             
  0x0106DF7F  0000                    add      byte ptr [eax], al             
  0x0106DF81  f4                      hlt                                     
  0x0106DF82  44                      inc      esp                            
  0x0106DF83  0000                    add      byte ptr [eax], al             
  0x0106DF85  004000                  add      byte ptr [eax], al             
  0x0106DF88  00704c                  add      byte ptr [eax + 0x4c], dh      
  0x0106DF8B  0002                    add      byte ptr [edx], al             
  0x0106DF8D  0000                    add      byte ptr [eax], al             
  0x0106DF8F  0000                    add      byte ptr [eax], al             
  0x0106DF91  f4                      hlt                                     
  0x0106DF92  44                      inc      esp                            
  0x0106DF93  003c41                  add      byte ptr [ecx + eax*2], bh     
  0x0106DF96  2d0000704c              sub      eax, 0x4c700000                
  0x0106DF9B  0003                    add      byte ptr [ebx], al             
  0x0106DF9D  0000                    add      byte ptr [eax], al             
  0x0106DF9F  0000                    add      byte ptr [eax], al             
  0x0106DFA1  f4                      hlt                                     
  0x0106DFA2  44                      inc      esp                            
  0x0106DFA3  003c41                  add      byte ptr [ecx + eax*2], bh     
  0x0106DFA6  2d0000704c              sub      eax, 0x4c700000                
  0x0106DFAB  000400                  add      byte ptr [eax + eax], al       
  0x0106DFAE  0000                    add      byte ptr [eax], al             
  0x0106DFB0  00f0                    add      al, dh                         
  0x0106DFB2  6200                    bound    eax, qword ptr [eax]           
  0x0106DFB4  0007                    add      byte ptr [edi], al             
  0x0106DFB6  0000                    add      byte ptr [eax], al             
  0x0106DFB8  0000                    add      byte ptr [eax], al             
  0x0106DFBA  0000                    add      byte ptr [eax], al             
  0x0106DFBC  0000                    add      byte ptr [eax], al             
  0x0106DFBE  0000                    add      byte ptr [eax], al             
  0x0106DFC0  d542                    aad      0x42                           
  0x0106DFC2  0200                    add      al, byte ptr [eax]             
  0x0106DFC4  9e                      sahf                                    
  0x0106DFC5  42                      inc      edx                            
  0x0106DFC6  0200                    add      al, byte ptr [eax]             
  0x0106DFC8  0300                    add      eax, dword ptr [eax]           
  0x0106DFCA  2000                    and      byte ptr [eax], al             
  0x0106DFCC  0ba4050000f460          or       esp, dword ptr [ebp + eax + 0x60f40000] 
  0x0106DFD3  0000                    add      byte ptr [eax], al             
  0x0106DFD5  0000                    add      byte ptr [eax], al             
  0x0106DFD7  0000                    add      byte ptr [eax], al             
  0x0106DFD9  0138                    add      dword ptr [eax], edi           
  0x0106DFDB  0000                    add      byte ptr [eax], al             
  0x0106DFDE  4e                      dec      esi                            
  0x0106DFDF  0000                    add      byte ptr [eax], al             
  0x0106DFE1  0000                    add      byte ptr [eax], al             
  0x0106DFE3  009005060004            add      byte ptr [eax + 0x4000605], dl 
  0x0106DFE9  0000                    add      byte ptr [eax], al             
  0x0106DFEB  00e1                    add      cl, ah                         
  0x0106DFED  0020                    add      byte ptr [eax], ah             
  0x0106DFEF  0000                    add      byte ptr [eax], al             
  0x0106DFF1  e84e000058              call     0x5906e044                     
  0x0106DFF6  5e                      pop      esi                            
  0x0106DFF7  0000                    add      byte ptr [eax], al             
  0x0106DFF9  f4                      hlt                                     
  0x0106DFFA  6200                    bound    eax, qword ptr [eax]           
  0x0106DFFC  0005000000f4            add      byte ptr [0xf4000000], al      
  0x0106E002  660000                  add      byte ptr [eax], al             
  0x0106E005  06                      push     es                             
  0x0106E006  0000                    add      byte ptr [eax], al             
  0x0106E008  00f4                    add      ah, dh                         
  0x0106E00A  7000                    jo       0x106e00c                      
                                        ; XREF: 0x0106E00A (cond_jump)
  0x0106E00C  0001                    add      byte ptr [ecx], al             
  0x0106E00E  0000                    add      byte ptr [eax], al             
  0x0106E010  00f4                    add      ah, dh                         
  0x0106E012  60                      pushal                                  
  0x0106E013  0000                    add      byte ptr [eax], al             
  0x0106E015  0000                    add      byte ptr [eax], al             
  0x0106E017  0000                    add      byte ptr [eax], al             
  0x0106E019  f4                      hlt                                     
  0x0106E01A  640000                  add      byte ptr fs:[eax], al          
  0x0106E01D  0000                    add      byte ptr [eax], al             
  0x0106E01F  0000                    add      byte ptr [eax], al             
  0x0106E021  1522009100              adc      eax, 0x910022                  
  0x0106E026  06                      push     es                             
  0x0106E027  000c00                  add      byte ptr [eax + eax], cl       
  0x0106E02A  0000                    add      byte ptr [eax], al             
  0x0106E02C  0088f000d088            add      byte ptr [eax - 0x772fff10], cl 
  0x0106E033  00d2                    add      dl, dl                         
  0x0106E035  88f0                    mov      al, dh                         
  0x0106E037  00d2                    add      dl, dl                         
  0x0106E039  88f0                    mov      al, dh                         
  0x0106E03B  00d2                    add      dl, dl                         
  0x0106E03D  80c000                  add      al, 0                          
  0x0106E040  d3dd                    rcr      ebp, cl                        
  0x0106E042  4e                      dec      esi                            
  0x0106E043  0000                    add      byte ptr [eax], al             
  0x0106E045  b022                    mov      al, 0x22                       
  0x0106E047  0000                    add      byte ptr [eax], al             
  0x0106E049  f4                      hlt                                     
  0x0106E04A  640000                  add      byte ptr fs:[eax], al          
  0x0106E04D  0000                    add      byte ptr [eax], al             
  0x0106E04F  0000                    add      byte ptr [eax], al             
  0x0106E051  5a                      pop      edx                            
  0x0106E052  56                      push     esi                            
  0x0106E053  0000                    add      byte ptr [eax], al             
  0x0106E055  5e                      pop      esi                            
  0x0106E056  56                      push     esi                            
  0x0106E057  0013                    add      byte ptr [ebx], dl             
  0x0106E059  f4                      hlt                                     
  0x0106E05A  6200                    bound    eax, qword ptr [eax]           
  0x0106E05C  000500001b00            add      byte ptr [0x1b0000], al        
  0x0106E062  2000                    and      byte ptr [eax], al             
  0x0106E064  91                      xchg     ecx, eax                       
  0x0106E065  0006                    add      byte ptr [esi], al             
  0x0106E067  000500000000            add      byte ptr [0], al               
  0x0106E06D  da44008a                fiadd    dword ptr [eax + eax - 0x76]   
  0x0106E071  0020                    add      byte ptr [eax], ah             
  0x0106E073  004700                  add      byte ptr [edi], al             
  0x0106E076  2000                    and      byte ptr [eax], al             
  0x0106E078  40                      inc      eax                            
  0x0106E079  90                      nop                                     
  0x0106E07A  0200                    add      al, byte ptr [eax]             
  0x0106E07C  260020                  add      byte ptr es:[eax], ah          
  0x0106E07F  00911c0c0000            add      byte ptr [ecx + 0xc1c], dl     
  0x0106E085  7056                    jo       0x106e0dd                      
  0x0106E087  0001                    add      byte ptr [ecx], al             
  0x0106E089  07                      pop      es                             
  0x0106E08A  0000                    add      byte ptr [eax], al             
  0x0106E08C  00a721000026            add      byte ptr [edi + 0x26000021], ah 
  0x0106E092  2100                    and      dword ptr [eax], eax           
  0x0106E094  13402f                  adc      eax, dword ptr [eax + 0x2f]    
  0x0106E097  009017060009            add      byte ptr [eax + 0x9000617], dl 
  0x0106E09D  0000                    add      byte ptr [eax], al             
  0x0106E09F  0010                    add      byte ptr [eax], dl             
  0x0106E0A1  c521                    lds      esp, ptr [ecx]                 
  0x0106E0A3  0000                    add      byte ptr [eax], al             
  0x0106E0A5  0000                    add      byte ptr [eax], al             
  0x0106E0A7  0000                    add      byte ptr [eax], al             
  0x0106E0A9  c421                    les      esp, ptr [ecx]                 
  0x0106E0AB  00840020003000          add      byte ptr [eax + eax + 0x300020], al 
  0x0106E0B2  2000                    and      byte ptr [eax], al             
  0x0106E0B4  00ae20001021            add      byte ptr [esi + 0x21100020], ch 
  0x0106E0BA  2000                    and      byte ptr [eax], al             
  0x0106E0BC  2a00                    sub      al, byte ptr [eax]             
  0x0106E0BE  2000                    and      byte ptr [eax], al             
  0x0106E0C0  007056                  add      byte ptr [eax + 0x56], dh      
  0x0106E0C3  0003                    add      byte ptr [ebx], al             
  0x0106E0C5  07                      pop      es                             
  0x0106E0C6  0000                    add      byte ptr [eax], al             
  0x0106E0C8  13f4                    adc      esi, esp                       
  0x0106E0CA  6200                    bound    eax, qword ptr [eax]           
  0x0106E0CC  0006                    add      byte ptr [esi], al             
  0x0106E0CE  0000                    add      byte ptr [eax], al             
  0x0106E0D0  1b00                    sbb      eax, dword ptr [eax]           
  0x0106E0D2  2000                    and      byte ptr [eax], al             
  0x0106E0D4  91                      xchg     ecx, eax                       
  0x0106E0D5  0006                    add      byte ptr [esi], al             
  0x0106E0D7  000500000000            add      byte ptr [0], al               
                                        ; XREF: 0x0106E085 (cond_jump)
  0x0106E0DD  da44008a                fiadd    dword ptr [eax + eax - 0x76]   
  0x0106E0E1  0020                    add      byte ptr [eax], ah             
  0x0106E0E3  004700                  add      byte ptr [edi], al             
  0x0106E0E6  2000                    and      byte ptr [eax], al             
  0x0106E0E8  40                      inc      eax                            
  0x0106E0E9  90                      nop                                     
  0x0106E0EA  0200                    add      al, byte ptr [eax]             
  0x0106E0EC  260020                  add      byte ptr es:[eax], ah          
  0x0106E0EF  00911c0c0000            add      byte ptr [ecx + 0xc1c], dl     
  0x0106E0F5  7056                    jo       0x106e14d                      
  0x0106E0F7  0002                    add      byte ptr [edx], al             
  0x0106E0F9  07                      pop      es                             
  0x0106E0FA  0000                    add      byte ptr [eax], al             
  0x0106E0FC  00a721000026            add      byte ptr [edi + 0x26000021], ah 
  0x0106E102  2100                    and      dword ptr [eax], eax           
  0x0106E104  13402f                  adc      eax, dword ptr [eax + 0x2f]    
  0x0106E107  009017060009            add      byte ptr [eax + 0x9000617], dl 
  0x0106E10D  0000                    add      byte ptr [eax], al             
  0x0106E10F  0010                    add      byte ptr [eax], dl             
  0x0106E111  c521                    lds      esp, ptr [ecx]                 
  0x0106E113  0000                    add      byte ptr [eax], al             
  0x0106E115  0000                    add      byte ptr [eax], al             
  0x0106E117  0000                    add      byte ptr [eax], al             
  0x0106E119  c421                    les      esp, ptr [ecx]                 
  0x0106E11B  00840020003000          add      byte ptr [eax + eax + 0x300020], al 
  0x0106E122  2000                    and      byte ptr [eax], al             
  0x0106E124  00ae20001021            add      byte ptr [esi + 0x21100020], ch 
  0x0106E12A  2000                    and      byte ptr [eax], al             
  0x0106E12C  2a00                    sub      al, byte ptr [eax]             
  0x0106E12E  2000                    and      byte ptr [eax], al             
  0x0106E130  007056                  add      byte ptr [eax + 0x56], dh      
  0x0106E133  000407                  add      byte ptr [edi + eax], al       
  0x0106E136  0000                    add      byte ptr [eax], al             
  0x0106E138  00f4                    add      ah, dh                         
  0x0106E13A  56                      push     esi                            
  0x0106E13B  0008                    add      byte ptr [eax], cl             
  0x0106E13D  0000                    add      byte ptr [eax], al             
  0x0106E13F  0000                    add      byte ptr [eax], al             
  0x0106E141  f4                      hlt                                     
  0x0106E142  60                      pushal                                  
  0x0106E143  0000                    add      byte ptr [eax], al             
  0x0106E145  05000000f4              add      eax, 0xf4000000                
  0x0106E14A  7000                    jo       0x106e14c                      
                                        ; XREF: 0x0106E14A (cond_jump)
  0x0106E14C  0001                    add      byte ptr [ecx], al             
  0x0106E14E  0000                    add      byte ptr [eax], al             
  0x0106E150  0000                    add      byte ptr [eax], al             
  0x0106E152  3900                    cmp      dword ptr [eax], eax           
  0x0106E154  80010d                  add      byte ptr [ecx], 0xd            
  0x0106E157  0000                    add      byte ptr [eax], al             
  0x0106E159  f4                      hlt                                     
  0x0106E15A  56                      push     esi                            
  0x0106E15B  0008                    add      byte ptr [eax], cl             
  0x0106E15D  0000                    add      byte ptr [eax], al             
  0x0106E15F  0000                    add      byte ptr [eax], al             
  0x0106E161  f4                      hlt                                     
  0x0106E162  60                      pushal                                  
  0x0106E163  0000                    add      byte ptr [eax], al             
  0x0106E165  06                      push     es                             
  0x0106E166  0000                    add      byte ptr [eax], al             
  0x0106E168  00f4                    add      ah, dh                         
  0x0106E16A  7000                    jo       0x106e16c                      
                                        ; XREF: 0x0106E16A (cond_jump)
  0x0106E16C  0001                    add      byte ptr [ecx], al             
  0x0106E16E  0000                    add      byte ptr [eax], al             
  0x0106E170  0001                    add      byte ptr [ecx], al             
  0x0106E172  3900                    cmp      dword ptr [eax], eax           
  0x0106E174  80010d                  add      byte ptr [ecx], 0xd            
  0x0106E177  0000                    add      byte ptr [eax], al             
  0x0106E179  f4                      hlt                                     
  0x0106E17A  56                      push     esi                            
  0x0106E17B  000f                    add      byte ptr [edi], cl             
  0x0106E17D  0000                    add      byte ptr [eax], al             
  0x0106E17F  0000                    add      byte ptr [eax], al             
  0x0106E181  f4                      hlt                                     
  0x0106E182  60                      pushal                                  
  0x0106E183  0001                    add      byte ptr [ecx], al             
  0x0106E185  07                      pop      es                             
  0x0106E186  0000                    add      byte ptr [eax], al             
  0x0106E188  000438                  add      byte ptr [eax + edi], al       
  0x0106E18B  0000                    add      byte ptr [eax], al             
  0x0106E18D  0039                    add      byte ptr [ecx], bh             
  0x0106E18F  0080010d000c            add      byte ptr [eax + 0xc000d01], al 
  0x0106E195  0000                    add      byte ptr [eax], al             
  0x0106E197  00401b                  add      byte ptr [eax + 0x1b], al      
  0x0106E19A  d000                    rol      byte ptr [eax], 1              
  0x0106E19C  c9                      leave                                   
  0x0106E19D  0000                    add      byte ptr [eax], al             
  0x0106E19F  007201                  add      byte ptr [edx + 1], dh         
  0x0106E1A2  06                      push     es                             
  0x0106E1A3  00b0c4870000            add      byte ptr [eax + 0x87c4], dh    
  0x0106E1A9  7060                    jo       0x106e20b                      
  0x0106E1AB  0000                    add      byte ptr [eax], al             
  0x0106E1AD  07                      pop      es                             
  0x0106E1AE  0000                    add      byte ptr [eax], al             
  0x0106E1B0  00f4                    add      ah, dh                         
  0x0106E1B2  56                      push     esi                            
  0x0106E1B3  0007                    add      byte ptr [edi], al             
  0x0106E1B5  0000                    add      byte ptr [eax], al             
  0x0106E1B7  0000                    add      byte ptr [eax], al             
  0x0106E1B9  f4                      hlt                                     
  0x0106E1BA  60                      pushal                                  
  0x0106E1BB  0000                    add      byte ptr [eax], al             
  0x0106E1BD  0000                    add      byte ptr [eax], al             
  0x0106E1BF  0000                    add      byte ptr [eax], al             
  0x0106E1C1  f4                      hlt                                     
  0x0106E1C2  7000                    jo       0x106e1c4                      
                                        ; XREF: 0x0106E1C2 (cond_jump)
  0x0106E1C4  0001                    add      byte ptr [ecx], al             
  0x0106E1C6  0000                    add      byte ptr [eax], al             
  0x0106E1C8  0000                    add      byte ptr [eax], al             
  0x0106E1CA  3900                    cmp      dword ptr [eax], eax           
  0x0106E1CC  80010d                  add      byte ptr [ecx], 0xd            
  0x0106E1CF  0000                    add      byte ptr [eax], al             
  0x0106E1D1  f4                      hlt                                     
  0x0106E1D2  56                      push     esi                            
  0x0106E1D3  0007                    add      byte ptr [edi], al             
  0x0106E1D5  0000                    add      byte ptr [eax], al             
  0x0106E1D7  0000                    add      byte ptr [eax], al             
  0x0106E1D9  f4                      hlt                                     
  0x0106E1DA  60                      pushal                                  
  0x0106E1DB  0000                    add      byte ptr [eax], al             
  0x0106E1DD  0100                    add      dword ptr [eax], eax           
  0x0106E1DF  0000                    add      byte ptr [eax], al             
  0x0106E1E1  f4                      hlt                                     
  0x0106E1E2  7000                    jo       0x106e1e4                      
                                        ; XREF: 0x0106E1E2 (cond_jump)
  0x0106E1E4  0001                    add      byte ptr [ecx], al             
  0x0106E1E6  0000                    add      byte ptr [eax], al             
  0x0106E1E8  0001                    add      byte ptr [ecx], al             
  0x0106E1EA  3900                    cmp      dword ptr [eax], eax           
  0x0106E1EC  80010d                  add      byte ptr [ecx], 0xd            
  0x0106E1EF  0000                    add      byte ptr [eax], al             
  0x0106E1F1  f4                      hlt                                     
  0x0106E1F2  56                      push     esi                            
  0x0106E1F3  0007                    add      byte ptr [edi], al             
  0x0106E1F5  0000                    add      byte ptr [eax], al             
  0x0106E1F7  0000                    add      byte ptr [eax], al             
  0x0106E1F9  f4                      hlt                                     
  0x0106E1FA  60                      pushal                                  
  0x0106E1FB  0000                    add      byte ptr [eax], al             
  0x0106E1FD  0200                    add      al, byte ptr [eax]             
  0x0106E1FF  0000                    add      byte ptr [eax], al             
  0x0106E201  f4                      hlt                                     
  0x0106E202  7000                    jo       0x106e204                      
                                        ; XREF: 0x0106E202 (cond_jump)
  0x0106E204  0001                    add      byte ptr [ecx], al             
  0x0106E206  0000                    add      byte ptr [eax], al             
  0x0106E208  0002                    add      byte ptr [edx], al             
  0x0106E20A  3900                    cmp      dword ptr [eax], eax           
  0x0106E20C  80010d                  add      byte ptr [ecx], 0xd            
  0x0106E20F  0000                    add      byte ptr [eax], al             
  0x0106E211  f4                      hlt                                     
  0x0106E212  56                      push     esi                            
  0x0106E213  0007                    add      byte ptr [edi], al             
  0x0106E215  0000                    add      byte ptr [eax], al             
  0x0106E217  0000                    add      byte ptr [eax], al             
  0x0106E219  f4                      hlt                                     
  0x0106E21A  60                      pushal                                  
  0x0106E21B  0000                    add      byte ptr [eax], al             
  0x0106E21D  0300                    add      eax, dword ptr [eax]           
  0x0106E21F  0000                    add      byte ptr [eax], al             
  0x0106E221  f4                      hlt                                     
  0x0106E222  7000                    jo       0x106e224                      
                                        ; XREF: 0x0106E222 (cond_jump)
  0x0106E224  0001                    add      byte ptr [ecx], al             
  0x0106E226  0000                    add      byte ptr [eax], al             
  0x0106E228  0003                    add      byte ptr [ebx], al             
  0x0106E22A  3900                    cmp      dword ptr [eax], eax           
  0x0106E22C  80010d                  add      byte ptr [ecx], 0xd            
  0x0106E22F  0000                    add      byte ptr [eax], al             
  0x0106E231  f4                      hlt                                     
  0x0106E232  56                      push     esi                            
  0x0106E233  0007                    add      byte ptr [edi], al             
  0x0106E235  0000                    add      byte ptr [eax], al             
  0x0106E237  0000                    add      byte ptr [eax], al             
  0x0106E239  f4                      hlt                                     
  0x0106E23A  60                      pushal                                  
  0x0106E23B  0000                    add      byte ptr [eax], al             
  0x0106E23D  0400                    add      al, 0                          
  0x0106E23F  0000                    add      byte ptr [eax], al             
  0x0106E241  f4                      hlt                                     
  0x0106E242  7000                    jo       0x106e244                      
                                        ; XREF: 0x0106E242 (cond_jump)
  0x0106E244  0001                    add      byte ptr [ecx], al             
  0x0106E246  0000                    add      byte ptr [eax], al             
  0x0106E248  000439                  add      byte ptr [ecx + edi], al       
  0x0106E24B  0080010d0000            add      byte ptr [eax + 0xd01], al     
  0x0106E251  f4                      hlt                                     
  0x0106E252  44                      inc      esp                            
  0x0106E253  00ff                    add      bh, bh                         
  0x0106E256  7f00                    jg       0x106e258                      
                                        ; XREF: 0x0106E256 (cond_jump)
  0x0106E258  00704c                  add      byte ptr [eax + 0x4c], dh      
  0x0106E25B  0000                    add      byte ptr [eax], al             
  0x0106E25D  0000                    add      byte ptr [eax], al             
  0x0106E25F  0000                    add      byte ptr [eax], al             
  0x0106E261  704c                    jo       0x106e2af                      
  0x0106E263  000500000000            add      byte ptr [0], al               
  0x0106E269  f4                      hlt                                     
  0x0106E26A  44                      inc      esp                            
  0x0106E26B  007982                  add      byte ptr [ecx - 0x7e], bh      
  0x0106E26E  5a                      pop      edx                            
  0x0106E26F  0000                    add      byte ptr [eax], al             
  0x0106E271  704c                    jo       0x106e2bf                      
  0x0106E273  0002                    add      byte ptr [edx], al             
  0x0106E275  0000                    add      byte ptr [eax], al             
  0x0106E277  0000                    add      byte ptr [eax], al             
  0x0106E279  704c                    jo       0x106e2c7                      
  0x0106E27B  0003                    add      byte ptr [ebx], al             
  0x0106E27D  0000                    add      byte ptr [eax], al             
  0x0106E27F  0000                    add      byte ptr [eax], al             
  0x0106E281  f4                      hlt                                     
  0x0106E282  44                      inc      esp                            
  0x0106E283  007982                  add      byte ptr [ecx - 0x7e], bh      
  0x0106E286  5a                      pop      edx                            
  0x0106E287  0000                    add      byte ptr [eax], al             
  0x0106E289  704c                    jo       0x106e2d7                      
  0x0106E28B  0006                    add      byte ptr [esi], al             
  0x0106E28D  0000                    add      byte ptr [eax], al             
  0x0106E28F  0000                    add      byte ptr [eax], al             
  0x0106E291  704c                    jo       0x106e2df                      
  0x0106E293  0009                    add      byte ptr [ecx], cl             
  0x0106E295  0000                    add      byte ptr [eax], al             
  0x0106E297  0000                    add      byte ptr [eax], al             
  0x0106E299  f4                      hlt                                     
  0x0106E29A  44                      inc      esp                            
  0x0106E29B  0000                    add      byte ptr [eax], al             
  0x0106E29D  0000                    add      byte ptr [eax], al             
  0x0106E29F  0000                    add      byte ptr [eax], al             
  0x0106E2A1  704c                    jo       0x106e2ef                      
  0x0106E2A3  000400                  add      byte ptr [eax + eax], al       
  0x0106E2A6  0000                    add      byte ptr [eax], al             
  0x0106E2A8  00704c                  add      byte ptr [eax + 0x4c], dh      
  0x0106E2AB  0008                    add      byte ptr [eax], cl             
  0x0106E2AD  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x0106E261 (cond_jump)
  0x0106E2AF  0000                    add      byte ptr [eax], al             
  0x0106E2B1  704c                    jo       0x106e2ff                      
  0x0106E2B3  0001                    add      byte ptr [ecx], al             
  0x0106E2B5  0000                    add      byte ptr [eax], al             
  0x0106E2B7  0000                    add      byte ptr [eax], al             
  0x0106E2B9  704c                    jo       0x106e307                      
  0x0106E2BB  0007                    add      byte ptr [edi], al             
  0x0106E2BD  0000                    add      byte ptr [eax], al             
                                        ; XREF: 0x0106E271 (cond_jump)
  0x0106E2BF  0000                    add      byte ptr [eax], al             
  0x0106E2C2  6200                    bound    eax, qword ptr [eax]           
  0x0106E2C4  0007                    add      byte ptr [edi], al             
  0x0106E2C6  0000                    add      byte ptr [eax], al             
  0x0106E2C8  0000                    add      byte ptr [eax], al             
  0x0106E2CA  0000                    add      byte ptr [eax], al             
  0x0106E2CC  0000                    add      byte ptr [eax], al             
  0x0106E2CE  0000                    add      byte ptr [eax], al             
  0x0106E2D0  d542                    aad      0x42                           
  0x0106E2D2  0200                    add      al, byte ptr [eax]             
  0x0106E2D4  9e                      sahf                                    
  0x0106E2D5  42                      inc      edx                            
  0x0106E2D6  0200                    add      al, byte ptr [eax]             
  0x0106E2D8  0300                    add      eax, dword ptr [eax]           
  0x0106E2DA  2000                    and      byte ptr [eax], al             
  0x0106E2DC  0ba4050000f460          or       esp, dword ptr [ebp + eax + 0x60f40000] 
  0x0106E2E3  0000                    add      byte ptr [eax], al             
  0x0106E2E5  0000                    add      byte ptr [eax], al             
  0x0106E2E7  0000                    add      byte ptr [eax], al             
  0x0106E2E9  0138                    add      dword ptr [eax], edi           
  0x0106E2EB  0000                    add      byte ptr [eax], al             
  0x0106E2EE  4e                      dec      esi                            
                                        ; XREF: 0x0106E2A1 (cond_jump)
  0x0106E2EF  0000                    add      byte ptr [eax], al             
  0x0106E2F1  0000                    add      byte ptr [eax], al             
  0x0106E2F3  00900a060004            add      byte ptr [eax + 0x400060a], dl 
  0x0106E2F9  0000                    add      byte ptr [eax], al             
  0x0106E2FB  00e1                    add      cl, ah                         
  0x0106E2FD  0020                    add      byte ptr [eax], ah             
                                        ; XREF: 0x0106E2B1 (cond_jump)
  0x0106E2FF  0000                    add      byte ptr [eax], al             
  0x0106E301  e84e000058              call     0x5906e354                     
  0x0106E306  5e                      pop      esi                            
                                        ; XREF: 0x0106E2B9 (cond_jump)
  0x0106E307  0000                    add      byte ptr [eax], al             
  0x0106E309  f4                      hlt                                     
  0x0106E30A  6200                    bound    eax, qword ptr [eax]           
  0x0106E30C  0005000000f4            add      byte ptr [0xf4000000], al      
  0x0106E312  660000                  add      byte ptr [eax], al             
  0x0106E315  06                      push     es                             
  0x0106E316  0000                    add      byte ptr [eax], al             
  0x0106E318  00f4                    add      ah, dh                         
  0x0106E31A  7000                    jo       0x106e31c                      
                                        ; XREF: 0x0106E31A (cond_jump)
  0x0106E31C  0001                    add      byte ptr [ecx], al             
  0x0106E31E  0000                    add      byte ptr [eax], al             
  0x0106E320  00f4                    add      ah, dh                         
  0x0106E322  60                      pushal                                  
  0x0106E323  0000                    add      byte ptr [eax], al             
  0x0106E325  0000                    add      byte ptr [eax], al             
  0x0106E327  0000                    add      byte ptr [eax], al             
  0x0106E329  f4                      hlt                                     
  0x0106E32A  640000                  add      byte ptr fs:[eax], al          
  0x0106E32D  0000                    add      byte ptr [eax], al             
  0x0106E32F  0000                    add      byte ptr [eax], al             
  0x0106E331  1522009100              adc      eax, 0x910022                  
  0x0106E336  06                      push     es                             
  0x0106E337  0011                    add      byte ptr [ecx], dl             
  0x0106E339  0000                    add      byte ptr [eax], al             
  0x0106E33B  0000                    add      byte ptr [eax], al             
  0x0106E33D  88f0                    mov      al, dh                         
  0x0106E33F  00d0                    add      al, dl                         
  0x0106E341  dc4e00                  fmul     qword ptr [esi]                
  0x0106E344  d888f000d2dc            fmul     dword ptr [eax - 0x232dff10]   
  0x0106E34A  4e                      dec      esi                            
  0x0106E34B  00da                    add      dl, bl                         
  0x0106E34D  88f0                    mov      al, dh                         
  0x0106E34F  00d2                    add      dl, dl                         
  0x0106E351  dc4e00                  fmul     qword ptr [esi]                
  0x0106E354  da88f000d2dc            fimul    dword ptr [eax - 0x232dff10]   
  0x0106E35A  4e                      dec      esi                            
  0x0106E35B  00da                    add      dl, bl                         
  0x0106E35D  88f0                    mov      al, dh                         
  0x0106E35F  00d3                    add      bl, dl                         
  0x0106E361  dc4e00                  fmul     qword ptr [esi]                
  0x0106E364  dbdd                    fcmovnu  st(0), st(5)                   
  0x0106E366  4e                      dec      esi                            
  0x0106E367  0000                    add      byte ptr [eax], al             
  0x0106E369  b022                    mov      al, 0x22                       
  0x0106E36B  0000                    add      byte ptr [eax], al             
  0x0106E36D  f4                      hlt                                     
  0x0106E36E  640000                  add      byte ptr fs:[eax], al          
  0x0106E371  0000                    add      byte ptr [eax], al             
  0x0106E373  0000                    add      byte ptr [eax], al             
  0x0106E375  5a                      pop      edx                            
  0x0106E376  56                      push     esi                            
  0x0106E377  0000                    add      byte ptr [eax], al             
  0x0106E379  5e                      pop      esi                            
  0x0106E37A  57                      push     edi                            
  0x0106E37B  0013                    add      byte ptr [ebx], dl             
  0x0106E37D  f4                      hlt                                     
  0x0106E37E  6200                    bound    eax, qword ptr [eax]           
  0x0106E380  000500001b00            add      byte ptr [0x1b0000], al        
  0x0106E386  2000                    and      byte ptr [eax], al             
  0x0106E388  91                      xchg     ecx, eax                       
  0x0106E389  0006                    add      byte ptr [esi], al             
  0x0106E38B  000500000000            add      byte ptr [0], al               
  0x0106E391  da44008a                fiadd    dword ptr [eax + eax - 0x76]   
  0x0106E395  0020                    add      byte ptr [eax], ah             
  0x0106E397  004700                  add      byte ptr [edi], al             
  0x0106E39A  2000                    and      byte ptr [eax], al             
  0x0106E39C  40                      inc      eax                            
  0x0106E39D  90                      nop                                     
  0x0106E39E  0200                    add      al, byte ptr [eax]             
  0x0106E3A0  260020                  add      byte ptr es:[eax], ah          
  0x0106E3A3  00911c0c0000            add      byte ptr [ecx + 0xc1c], dl     
  0x0106E3A9  7056                    jo       0x106e401                      
  0x0106E3AB  0001                    add      byte ptr [ecx], al             
  0x0106E3AD  07                      pop      es                             
  0x0106E3AE  0000                    add      byte ptr [eax], al             
  0x0106E3B0  00a721000026            add      byte ptr [edi + 0x26000021], ah 
  0x0106E3B6  2100                    and      dword ptr [eax], eax           
  0x0106E3B8  13402f                  adc      eax, dword ptr [eax + 0x2f]    
  0x0106E3BB  009017060009            add      byte ptr [eax + 0x9000617], dl 
  0x0106E3C1  0000                    add      byte ptr [eax], al             
  0x0106E3C3  0010                    add      byte ptr [eax], dl             
  0x0106E3C5  c521                    lds      esp, ptr [ecx]                 
  0x0106E3C7  0000                    add      byte ptr [eax], al             
  0x0106E3C9  0000                    add      byte ptr [eax], al             
  0x0106E3CB  0000                    add      byte ptr [eax], al             
  0x0106E3CD  c421                    les      esp, ptr [ecx]                 
  0x0106E3CF  00840020003000          add      byte ptr [eax + eax + 0x300020], al 
  0x0106E3D6  2000                    and      byte ptr [eax], al             
  0x0106E3D8  00ae20001021            add      byte ptr [esi + 0x21100020], ch 
  0x0106E3DE  2000                    and      byte ptr [eax], al             
  0x0106E3E0  2a00                    sub      al, byte ptr [eax]             
  0x0106E3E2  2000                    and      byte ptr [eax], al             
  0x0106E3E4  007056                  add      byte ptr [eax + 0x56], dh      
  0x0106E3E7  0003                    add      byte ptr [ebx], al             
  0x0106E3E9  07                      pop      es                             
  0x0106E3EA  0000                    add      byte ptr [eax], al             
  0x0106E3EC  13f4                    adc      esi, esp                       
  0x0106E3EE  6200                    bound    eax, qword ptr [eax]           
  0x0106E3F0  0006                    add      byte ptr [esi], al             
  0x0106E3F2  0000                    add      byte ptr [eax], al             
  0x0106E3F4  1b00                    sbb      eax, dword ptr [eax]           
  0x0106E3F6  2000                    and      byte ptr [eax], al             
  0x0106E3F8  91                      xchg     ecx, eax                       
  0x0106E3F9  0006                    add      byte ptr [esi], al             
  0x0106E3FB  000500000000            add      byte ptr [0], al               
                                        ; XREF: 0x0106E3A9 (cond_jump)
  0x0106E401  da44008a                fiadd    dword ptr [eax + eax - 0x76]   
  0x0106E405  0020                    add      byte ptr [eax], ah             
  0x0106E407  004700                  add      byte ptr [edi], al             
  0x0106E40A  2000                    and      byte ptr [eax], al             
  0x0106E40C  40                      inc      eax                            
  0x0106E40D  90                      nop                                     
  0x0106E40E  0200                    add      al, byte ptr [eax]             
  0x0106E410  260020                  add      byte ptr es:[eax], ah          
  0x0106E413  00911c0c0000            add      byte ptr [ecx + 0xc1c], dl     
  0x0106E419  7056                    jo       0x106e471                      
  0x0106E41B  0002                    add      byte ptr [edx], al             
  0x0106E41D  07                      pop      es                             
  0x0106E41E  0000                    add      byte ptr [eax], al             
  0x0106E420  00a721000026            add      byte ptr [edi + 0x26000021], ah 
  0x0106E426  2100                    and      dword ptr [eax], eax           
  0x0106E428  13402f                  adc      eax, dword ptr [eax + 0x2f]    
  0x0106E42B  009017060009            add      byte ptr [eax + 0x9000617], dl 
  0x0106E431  0000                    add      byte ptr [eax], al             
  0x0106E433  0010                    add      byte ptr [eax], dl             
  0x0106E435  c521                    lds      esp, ptr [ecx]                 
  0x0106E437  0000                    add      byte ptr [eax], al             
  0x0106E439  0000                    add      byte ptr [eax], al             
  0x0106E43B  0000                    add      byte ptr [eax], al             
  0x0106E43D  c421                    les      esp, ptr [ecx]                 
  0x0106E43F  00840020003000          add      byte ptr [eax + eax + 0x300020], al 
  0x0106E446  2000                    and      byte ptr [eax], al             
  0x0106E448  00ae20001021            add      byte ptr [esi + 0x21100020], ch 
  0x0106E44E  2000                    and      byte ptr [eax], al             
  0x0106E450  2a00                    sub      al, byte ptr [eax]             
  0x0106E452  2000                    and      byte ptr [eax], al             
  0x0106E454  007056                  add      byte ptr [eax + 0x56], dh      
  0x0106E457  000407                  add      byte ptr [edi + eax], al       
  0x0106E45A  0000                    add      byte ptr [eax], al             
  0x0106E45C  00f4                    add      ah, dh                         
  0x0106E45E  56                      push     esi                            
  0x0106E45F  0008                    add      byte ptr [eax], cl             
  0x0106E461  0000                    add      byte ptr [eax], al             
  0x0106E463  0000                    add      byte ptr [eax], al             
  0x0106E465  f4                      hlt                                     
  0x0106E466  60                      pushal                                  
  0x0106E467  0000                    add      byte ptr [eax], al             
  0x0106E469  05000000f4              add      eax, 0xf4000000                
  0x0106E46E  7000                    jo       0x106e470                      
                                        ; XREF: 0x0106E46E (cond_jump)
  0x0106E470  0001                    add      byte ptr [ecx], al             
  0x0106E472  0000                    add      byte ptr [eax], al             
  0x0106E474  0000                    add      byte ptr [eax], al             
  0x0106E476  3900                    cmp      dword ptr [eax], eax           
  0x0106E478  80010d                  add      byte ptr [ecx], 0xd            
  0x0106E47B  0000                    add      byte ptr [eax], al             
  0x0106E47D  f4                      hlt                                     
  0x0106E47E  56                      push     esi                            
  0x0106E47F  0008                    add      byte ptr [eax], cl             
  0x0106E481  0000                    add      byte ptr [eax], al             
  0x0106E483  0000                    add      byte ptr [eax], al             
  0x0106E485  f4                      hlt                                     
  0x0106E486  60                      pushal                                  
  0x0106E487  0000                    add      byte ptr [eax], al             
  0x0106E489  06                      push     es                             
  0x0106E48A  0000                    add      byte ptr [eax], al             
  0x0106E48C  00f4                    add      ah, dh                         
  0x0106E48E  7000                    jo       0x106e490                      
                                        ; XREF: 0x0106E48E (cond_jump)
  0x0106E490  0001                    add      byte ptr [ecx], al             
  0x0106E492  0000                    add      byte ptr [eax], al             
  0x0106E494  0001                    add      byte ptr [ecx], al             
  0x0106E496  3900                    cmp      dword ptr [eax], eax           
  0x0106E498  80010d                  add      byte ptr [ecx], 0xd            
  0x0106E49B  0000                    add      byte ptr [eax], al             
  0x0106E49D  f4                      hlt                                     
  0x0106E49E  56                      push     esi                            
  0x0106E49F  000f                    add      byte ptr [edi], cl             
  0x0106E4A1  0000                    add      byte ptr [eax], al             
  0x0106E4A3  0000                    add      byte ptr [eax], al             
  0x0106E4A5  f4                      hlt                                     
  0x0106E4A6  60                      pushal                                  
  0x0106E4A7  0001                    add      byte ptr [ecx], al             
  0x0106E4A9  07                      pop      es                             
  0x0106E4AA  0000                    add      byte ptr [eax], al             
  0x0106E4AC  000438                  add      byte ptr [eax + edi], al       
  0x0106E4AF  0000                    add      byte ptr [eax], al             
  0x0106E4B1  0039                    add      byte ptr [ecx], bh             
  0x0106E4B3  0080010d000c            add      byte ptr [eax + 0xc000d01], al 
  0x0106E4B9  0000                    add      byte ptr [eax], al             
  0x0106E4BB  0000                    add      byte ptr [eax], al             
  0x0106E4BD  0000                    add      byte ptr [eax], al             
  0x0106E4BF  0018                    add      byte ptr [eax], bl             
  0x0106E4C1  0000                    add      byte ptr [eax], al             
  0x0106E4C3  0001                    add      byte ptr [ecx], al             
  0x0106E4C5  0000                    add      byte ptr [eax], al             
  0x0106E4C7  0001                    add      byte ptr [ecx], al             
  0x0106E4C9  0000                    add      byte ptr [eax], al             
  0x0106E4CB  0000                    add      byte ptr [eax], al             
  0x0106E4CD  0000                    add      byte ptr [eax], al             
  0x0106E4CF  0000                    add      byte ptr [eax], al             
  0x0106E4D1  0000                    add      byte ptr [eax], al             
  0x0106E4D3  0007                    add      byte ptr [edi], al             
  0x0106E4D5  0000                    add      byte ptr [eax], al             
  0x0106E4D7  0001                    add      byte ptr [ecx], al             
  0x0106E4D9  0000                    add      byte ptr [eax], al             
  0x0106E4DB  001f                    add      byte ptr [edi], bl             
  0x0106E4DD  0000                    add      byte ptr [eax], al             
  0x0106E4DF  0009                    add      byte ptr [ecx], cl             
  0x0106E4E1  0000                    add      byte ptr [eax], al             
  0x0106E4E3  0000                    add      byte ptr [eax], al             
  0x0106E4E5  0000                    add      byte ptr [eax], al             
  0x0106E4E7  0001                    add      byte ptr [ecx], al             
  0x0106E4E9  0000                    add      byte ptr [eax], al             
  0x0106E4EB  0001                    add      byte ptr [ecx], al             
  0x0106E4ED  0000                    add      byte ptr [eax], al             
  0x0106E4EF  0000                    add      byte ptr [eax], al             
  0x0106E4F1  0000                    add      byte ptr [eax], al             
  0x0106E4F3  0000                    add      byte ptr [eax], al             
  0x0106E4F5  0000                    add      byte ptr [eax], al             
  0x0106E4F7  0001                    add      byte ptr [ecx], al             
  0x0106E4F9  0000                    add      byte ptr [eax], al             
  0x0106E4FB  00ef                    add      bh, ch                         
  0x0106E4FD  0000                    add      byte ptr [eax], al             
  0x0106E4FF  0000                    add      byte ptr [eax], al             
  0x0106E501  0000                    add      byte ptr [eax], al             
  0x0106E503  008cac65000200          add      byte ptr [esp + ebp*4 + 0x20065], cl 
  0x0106E50A  0000                    add      byte ptr [eax], al             
