
fonte.o: formato do arquivo elf64-x86-64


Desmontagem da seção .interp:

0000000000400318 <.interp>:
  400318:	2f                   	(bad)  
  400319:	6c                   	insb   (%dx),%es:(%rdi)
  40031a:	69 62 36 34 2f 6c 64 	imul   $0x646c2f34,0x36(%rdx),%esp
  400321:	2d 6c 69 6e 75       	sub    $0x756e696c,%eax
  400326:	78 2d                	js     400355 <__abi_tag-0x27>
  400328:	78 38                	js     400362 <__abi_tag-0x1a>
  40032a:	36 2d 36 34 2e 73    	ss sub $0x732e3436,%eax
  400330:	6f                   	outsl  %ds:(%rsi),(%dx)
  400331:	2e 32 00             	cs xor (%rax),%al

Desmontagem da seção .note.gnu.property:

0000000000400338 <.note.gnu.property>:
  400338:	04 00                	add    $0x0,%al
  40033a:	00 00                	add    %al,(%rax)
  40033c:	10 00                	adc    %al,(%rax)
  40033e:	00 00                	add    %al,(%rax)
  400340:	05 00 00 00 47       	add    $0x47000000,%eax
  400345:	4e 55                	rex.WRX push %rbp
  400347:	00 02                	add    %al,(%rdx)
  400349:	80 00 c0             	addb   $0xc0,(%rax)
  40034c:	04 00                	add    $0x0,%al
  40034e:	00 00                	add    %al,(%rax)
  400350:	01 00                	add    %eax,(%rax)
  400352:	00 00                	add    %al,(%rax)
  400354:	00 00                	add    %al,(%rax)
	...

Desmontagem da seção .note.gnu.build-id:

0000000000400358 <.note.gnu.build-id>:
  400358:	04 00                	add    $0x0,%al
  40035a:	00 00                	add    %al,(%rax)
  40035c:	14 00                	adc    $0x0,%al
  40035e:	00 00                	add    %al,(%rax)
  400360:	03 00                	add    (%rax),%eax
  400362:	00 00                	add    %al,(%rax)
  400364:	47                   	rex.RXB
  400365:	4e 55                	rex.WRX push %rbp
  400367:	00 ce                	add    %cl,%dh
  400369:	13 90 38 f0 24 08    	adc    0x824f038(%rax),%edx
  40036f:	62                   	(bad)  
  400370:	ab                   	stos   %eax,%es:(%rdi)
  400371:	65 46 cf             	gs rex.RX iret 
  400374:	b6 f3                	mov    $0xf3,%dh
  400376:	08 7b 54             	or     %bh,0x54(%rbx)
  400379:	d8 ef                	fsubr  %st(7),%st
  40037b:	68                   	.byte 0x68

Desmontagem da seção .note.ABI-tag:

000000000040037c <__abi_tag>:
  40037c:	04 00                	add    $0x0,%al
  40037e:	00 00                	add    %al,(%rax)
  400380:	10 00                	adc    %al,(%rax)
  400382:	00 00                	add    %al,(%rax)
  400384:	01 00                	add    %eax,(%rax)
  400386:	00 00                	add    %al,(%rax)
  400388:	47                   	rex.RXB
  400389:	4e 55                	rex.WRX push %rbp
  40038b:	00 00                	add    %al,(%rax)
  40038d:	00 00                	add    %al,(%rax)
  40038f:	00 03                	add    %al,(%rbx)
  400391:	00 00                	add    %al,(%rax)
  400393:	00 02                	add    %al,(%rdx)
  400395:	00 00                	add    %al,(%rax)
  400397:	00 00                	add    %al,(%rax)
  400399:	00 00                	add    %al,(%rax)
	...

Desmontagem da seção .gnu.hash:

00000000004003a0 <.gnu.hash>:
  4003a0:	01 00                	add    %eax,(%rax)
  4003a2:	00 00                	add    %al,(%rax)
  4003a4:	01 00                	add    %eax,(%rax)
  4003a6:	00 00                	add    %al,(%rax)
  4003a8:	01 00                	add    %eax,(%rax)
	...

Desmontagem da seção .dynsym:

00000000004003c0 <.dynsym>:
	...
  4003d8:	01 00                	add    %eax,(%rax)
  4003da:	00 00                	add    %al,(%rax)
  4003dc:	12 00                	adc    (%rax),%al
	...
  4003ee:	00 00                	add    %al,(%rax)
  4003f0:	13 00                	adc    (%rax),%eax
  4003f2:	00 00                	add    %al,(%rax)
  4003f4:	12 00                	adc    (%rax),%al
	...
  400406:	00 00                	add    %al,(%rax)
  400408:	3b 00                	cmp    (%rax),%eax
  40040a:	00 00                	add    %al,(%rax)
  40040c:	20 00                	and    %al,(%rax)
	...

Desmontagem da seção .dynstr:

0000000000400420 <.dynstr>:
  400420:	00 5f 5f             	add    %bl,0x5f(%rdi)
  400423:	6c                   	insb   (%dx),%es:(%rdi)
  400424:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%rdx),%esp
  40042b:	72 74                	jb     4004a1 <__abi_tag+0x125>
  40042d:	5f                   	pop    %rdi
  40042e:	6d                   	insl   (%dx),%es:(%rdi)
  40042f:	61                   	(bad)  
  400430:	69 6e 00 70 72 69 6e 	imul   $0x6e697270,0x0(%rsi),%ebp
  400437:	74 66                	je     40049f <__abi_tag+0x123>
  400439:	00 6c 69 62          	add    %ch,0x62(%rcx,%rbp,2)
  40043d:	63 2e                	movsxd (%rsi),%ebp
  40043f:	73 6f                	jae    4004b0 <__abi_tag+0x134>
  400441:	2e 36 00 47 4c       	cs ss add %al,0x4c(%rdi)
  400446:	49                   	rex.WB
  400447:	42                   	rex.X
  400448:	43 5f                	rex.XB pop %r15
  40044a:	32 2e                	xor    (%rsi),%ch
  40044c:	32 2e                	xor    (%rsi),%ch
  40044e:	35 00 47 4c 49       	xor    $0x494c4700,%eax
  400453:	42                   	rex.X
  400454:	43 5f                	rex.XB pop %r15
  400456:	32 2e                	xor    (%rsi),%ch
  400458:	33 34 00             	xor    (%rax,%rax,1),%esi
  40045b:	5f                   	pop    %rdi
  40045c:	5f                   	pop    %rdi
  40045d:	67 6d                	insl   (%dx),%es:(%edi)
  40045f:	6f                   	outsl  %ds:(%rsi),(%dx)
  400460:	6e                   	outsb  %ds:(%rsi),(%dx)
  400461:	5f                   	pop    %rdi
  400462:	73 74                	jae    4004d8 <__abi_tag+0x15c>
  400464:	61                   	(bad)  
  400465:	72 74                	jb     4004db <__abi_tag+0x15f>
  400467:	5f                   	pop    %rdi
  400468:	5f                   	pop    %rdi
	...

Desmontagem da seção .gnu.version:

000000000040046a <.gnu.version>:
  40046a:	00 00                	add    %al,(%rax)
  40046c:	02 00                	add    (%rax),%al
  40046e:	03 00                	add    (%rax),%eax
  400470:	01 00                	add    %eax,(%rax)

Desmontagem da seção .gnu.version_r:

0000000000400478 <.gnu.version_r>:
  400478:	01 00                	add    %eax,(%rax)
  40047a:	02 00                	add    (%rax),%al
  40047c:	1a 00                	sbb    (%rax),%al
  40047e:	00 00                	add    %al,(%rax)
  400480:	10 00                	adc    %al,(%rax)
  400482:	00 00                	add    %al,(%rax)
  400484:	00 00                	add    %al,(%rax)
  400486:	00 00                	add    %al,(%rax)
  400488:	75 1a                	jne    4004a4 <__abi_tag+0x128>
  40048a:	69 09 00 00 03 00    	imul   $0x30000,(%rcx),%ecx
  400490:	24 00                	and    $0x0,%al
  400492:	00 00                	add    %al,(%rax)
  400494:	10 00                	adc    %al,(%rax)
  400496:	00 00                	add    %al,(%rax)
  400498:	b4 91                	mov    $0x91,%ah
  40049a:	96                   	xchg   %eax,%esi
  40049b:	06                   	(bad)  
  40049c:	00 00                	add    %al,(%rax)
  40049e:	02 00                	add    (%rax),%al
  4004a0:	30 00                	xor    %al,(%rax)
  4004a2:	00 00                	add    %al,(%rax)
  4004a4:	00 00                	add    %al,(%rax)
	...

Desmontagem da seção .rela.dyn:

00000000004004a8 <.rela.dyn>:
  4004a8:	f0 3f                	lock (bad) 
  4004aa:	40 00 00             	rex add %al,(%rax)
  4004ad:	00 00                	add    %al,(%rax)
  4004af:	00 06                	add    %al,(%rsi)
  4004b1:	00 00                	add    %al,(%rax)
  4004b3:	00 01                	add    %al,(%rcx)
	...
  4004bd:	00 00                	add    %al,(%rax)
  4004bf:	00 f8                	add    %bh,%al
  4004c1:	3f                   	(bad)  
  4004c2:	40 00 00             	rex add %al,(%rax)
  4004c5:	00 00                	add    %al,(%rax)
  4004c7:	00 06                	add    %al,(%rsi)
  4004c9:	00 00                	add    %al,(%rax)
  4004cb:	00 03                	add    %al,(%rbx)
	...

Desmontagem da seção .rela.plt:

00000000004004d8 <.rela.plt>:
  4004d8:	18 40 40             	sbb    %al,0x40(%rax)
  4004db:	00 00                	add    %al,(%rax)
  4004dd:	00 00                	add    %al,(%rax)
  4004df:	00 07                	add    %al,(%rdi)
  4004e1:	00 00                	add    %al,(%rax)
  4004e3:	00 02                	add    %al,(%rdx)
	...

Desmontagem da seção .init:

0000000000401000 <_init>:
  401000:	f3 0f 1e fa          	endbr64 
  401004:	48 83 ec 08          	sub    $0x8,%rsp
  401008:	48 8b 05 e9 2f 00 00 	mov    0x2fe9(%rip),%rax        # 403ff8 <__gmon_start__@Base>
  40100f:	48 85 c0             	test   %rax,%rax
  401012:	74 02                	je     401016 <_init+0x16>
  401014:	ff d0                	call   *%rax
  401016:	48 83 c4 08          	add    $0x8,%rsp
  40101a:	c3                   	ret    

Desmontagem da seção .plt:

0000000000401020 <printf@plt-0x10>:
  401020:	ff 35 e2 2f 00 00    	push   0x2fe2(%rip)        # 404008 <_GLOBAL_OFFSET_TABLE_+0x8>
  401026:	ff 25 e4 2f 00 00    	jmp    *0x2fe4(%rip)        # 404010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401030 <printf@plt>:
  401030:	ff 25 e2 2f 00 00    	jmp    *0x2fe2(%rip)        # 404018 <printf@GLIBC_2.2.5>
  401036:	68 00 00 00 00       	push   $0x0
  40103b:	e9 e0 ff ff ff       	jmp    401020 <_init+0x20>

Desmontagem da seção .text:

0000000000401040 <_start>:
  401040:	f3 0f 1e fa          	endbr64 
  401044:	31 ed                	xor    %ebp,%ebp
  401046:	49 89 d1             	mov    %rdx,%r9
  401049:	5e                   	pop    %rsi
  40104a:	48 89 e2             	mov    %rsp,%rdx
  40104d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  401051:	50                   	push   %rax
  401052:	54                   	push   %rsp
  401053:	45 31 c0             	xor    %r8d,%r8d
  401056:	31 c9                	xor    %ecx,%ecx
  401058:	48 c7 c7 50 11 40 00 	mov    $0x401150,%rdi
  40105f:	ff 15 8b 2f 00 00    	call   *0x2f8b(%rip)        # 403ff0 <__libc_start_main@GLIBC_2.34>
  401065:	f4                   	hlt    
  401066:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
  40106d:	00 00 00 

0000000000401070 <_dl_relocate_static_pie>:
  401070:	f3 0f 1e fa          	endbr64 
  401074:	c3                   	ret    
  401075:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
  40107c:	00 00 00 
  40107f:	90                   	nop

0000000000401080 <deregister_tm_clones>:
  401080:	b8 30 40 40 00       	mov    $0x404030,%eax
  401085:	48 3d 30 40 40 00    	cmp    $0x404030,%rax
  40108b:	74 13                	je     4010a0 <deregister_tm_clones+0x20>
  40108d:	b8 00 00 00 00       	mov    $0x0,%eax
  401092:	48 85 c0             	test   %rax,%rax
  401095:	74 09                	je     4010a0 <deregister_tm_clones+0x20>
  401097:	bf 30 40 40 00       	mov    $0x404030,%edi
  40109c:	ff e0                	jmp    *%rax
  40109e:	66 90                	xchg   %ax,%ax
  4010a0:	c3                   	ret    
  4010a1:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
  4010a8:	00 00 00 00 
  4010ac:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004010b0 <register_tm_clones>:
  4010b0:	be 30 40 40 00       	mov    $0x404030,%esi
  4010b5:	48 81 ee 30 40 40 00 	sub    $0x404030,%rsi
  4010bc:	48 89 f0             	mov    %rsi,%rax
  4010bf:	48 c1 ee 3f          	shr    $0x3f,%rsi
  4010c3:	48 c1 f8 03          	sar    $0x3,%rax
  4010c7:	48 01 c6             	add    %rax,%rsi
  4010ca:	48 d1 fe             	sar    %rsi
  4010cd:	74 11                	je     4010e0 <register_tm_clones+0x30>
  4010cf:	b8 00 00 00 00       	mov    $0x0,%eax
  4010d4:	48 85 c0             	test   %rax,%rax
  4010d7:	74 07                	je     4010e0 <register_tm_clones+0x30>
  4010d9:	bf 30 40 40 00       	mov    $0x404030,%edi
  4010de:	ff e0                	jmp    *%rax
  4010e0:	c3                   	ret    
  4010e1:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
  4010e8:	00 00 00 00 
  4010ec:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004010f0 <__do_global_dtors_aux>:
  4010f0:	f3 0f 1e fa          	endbr64 
  4010f4:	80 3d 35 2f 00 00 00 	cmpb   $0x0,0x2f35(%rip)        # 404030 <__TMC_END__>
  4010fb:	75 13                	jne    401110 <__do_global_dtors_aux+0x20>
  4010fd:	55                   	push   %rbp
  4010fe:	48 89 e5             	mov    %rsp,%rbp
  401101:	e8 7a ff ff ff       	call   401080 <deregister_tm_clones>
  401106:	c6 05 23 2f 00 00 01 	movb   $0x1,0x2f23(%rip)        # 404030 <__TMC_END__>
  40110d:	5d                   	pop    %rbp
  40110e:	c3                   	ret    
  40110f:	90                   	nop
  401110:	c3                   	ret    
  401111:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
  401118:	00 00 00 00 
  40111c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401120 <frame_dummy>:
  401120:	f3 0f 1e fa          	endbr64 
  401124:	eb 8a                	jmp    4010b0 <register_tm_clones>
  401126:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
  40112d:	00 00 00 

0000000000401130 <funcao>:
  401130:	48 83 ec 18          	sub    $0x18,%rsp
  401134:	89 7c 24 0c          	mov    %edi,0xc(%rsp)
  401138:	89 74 24 10          	mov    %esi,0x10(%rsp)
  40113c:	89 7c 24 14          	mov    %edi,0x14(%rsp)
  401140:	e8 2b 00 00 00       	call   401170 <imprimei>
  401145:	48 83 c4 18          	add    $0x18,%rsp
  401149:	c3                   	ret    
  40114a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000401150 <main>:
  401150:	50                   	push   %rax
  401151:	bf 14 00 00 00       	mov    $0x14,%edi
  401156:	e8 15 00 00 00       	call   401170 <imprimei>
  40115b:	bf 03 00 00 00       	mov    $0x3,%edi
  401160:	be 04 00 00 00       	mov    $0x4,%esi
  401165:	e8 c6 ff ff ff       	call   401130 <funcao>
  40116a:	59                   	pop    %rcx
  40116b:	c3                   	ret    
  40116c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401170 <imprimei>:
  401170:	55                   	push   %rbp
  401171:	48 89 e5             	mov    %rsp,%rbp
  401174:	48 83 ec 10          	sub    $0x10,%rsp
  401178:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  40117c:	48 8b 75 f8          	mov    -0x8(%rbp),%rsi
  401180:	48 bf 04 20 40 00 00 	movabs $0x402004,%rdi
  401187:	00 00 00 
  40118a:	b0 00                	mov    $0x0,%al
  40118c:	e8 9f fe ff ff       	call   401030 <printf@plt>
  401191:	48 83 c4 10          	add    $0x10,%rsp
  401195:	5d                   	pop    %rbp
  401196:	c3                   	ret    

Desmontagem da seção .fini:

0000000000401198 <_fini>:
  401198:	f3 0f 1e fa          	endbr64 
  40119c:	48 83 ec 08          	sub    $0x8,%rsp
  4011a0:	48 83 c4 08          	add    $0x8,%rsp
  4011a4:	c3                   	ret    

Desmontagem da seção .rodata:

0000000000402000 <_IO_stdin_used>:
  402000:	01 00                	add    %eax,(%rax)
  402002:	02 00                	add    (%rax),%al
  402004:	25 6c 64 0a 00       	and    $0xa646c,%eax

Desmontagem da seção .eh_frame_hdr:

000000000040200c <__GNU_EH_FRAME_HDR>:
  40200c:	01 1b                	add    %ebx,(%rbx)
  40200e:	03 3b                	add    (%rbx),%edi
  402010:	38 00                	cmp    %al,(%rax)
  402012:	00 00                	add    %al,(%rax)
  402014:	06                   	(bad)  
  402015:	00 00                	add    %al,(%rax)
  402017:	00 14 f0             	add    %dl,(%rax,%rsi,8)
  40201a:	ff                   	(bad)  
  40201b:	ff                   	(bad)  
  40201c:	7c 00                	jl     40201e <__GNU_EH_FRAME_HDR+0x12>
  40201e:	00 00                	add    %al,(%rax)
  402020:	34 f0                	xor    $0xf0,%al
  402022:	ff                   	(bad)  
  402023:	ff 54 00 00          	call   *0x0(%rax,%rax,1)
  402027:	00 64 f0 ff          	add    %ah,-0x1(%rax,%rsi,8)
  40202b:	ff 68 00             	ljmp   *0x0(%rax)
  40202e:	00 00                	add    %al,(%rax)
  402030:	24 f1                	and    $0xf1,%al
  402032:	ff                   	(bad)  
  402033:	ff a4 00 00 00 44 f1 	jmp    *-0xebc0000(%rax,%rax,1)
  40203a:	ff                   	(bad)  
  40203b:	ff                   	(bad)  
  40203c:	bc 00 00 00 64       	mov    $0x64000000,%esp
  402041:	f1                   	icebp  
  402042:	ff                   	(bad)  
  402043:	ff d4                	call   *%rsp
  402045:	00 00                	add    %al,(%rax)
	...

Desmontagem da seção .eh_frame:

0000000000402048 <__FRAME_END__-0xb8>:
  402048:	14 00                	adc    $0x0,%al
  40204a:	00 00                	add    %al,(%rax)
  40204c:	00 00                	add    %al,(%rax)
  40204e:	00 00                	add    %al,(%rax)
  402050:	01 7a 52             	add    %edi,0x52(%rdx)
  402053:	00 01                	add    %al,(%rcx)
  402055:	78 10                	js     402067 <__GNU_EH_FRAME_HDR+0x5b>
  402057:	01 1b                	add    %ebx,(%rbx)
  402059:	0c 07                	or     $0x7,%al
  40205b:	08 90 01 00 00 10    	or     %dl,0x10000001(%rax)
  402061:	00 00                	add    %al,(%rax)
  402063:	00 1c 00             	add    %bl,(%rax,%rax,1)
  402066:	00 00                	add    %al,(%rax)
  402068:	d8 ef                	fsubr  %st(7),%st
  40206a:	ff                   	(bad)  
  40206b:	ff 26                	jmp    *(%rsi)
  40206d:	00 00                	add    %al,(%rax)
  40206f:	00 00                	add    %al,(%rax)
  402071:	44 07                	rex.R (bad) 
  402073:	10 10                	adc    %dl,(%rax)
  402075:	00 00                	add    %al,(%rax)
  402077:	00 30                	add    %dh,(%rax)
  402079:	00 00                	add    %al,(%rax)
  40207b:	00 f4                	add    %dh,%ah
  40207d:	ef                   	out    %eax,(%dx)
  40207e:	ff                   	(bad)  
  40207f:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 402085 <__GNU_EH_FRAME_HDR+0x79>
  402085:	00 00                	add    %al,(%rax)
  402087:	00 24 00             	add    %ah,(%rax,%rax,1)
  40208a:	00 00                	add    %al,(%rax)
  40208c:	44 00 00             	add    %r8b,(%rax)
  40208f:	00 90 ef ff ff 20    	add    %dl,0x20ffffef(%rax)
  402095:	00 00                	add    %al,(%rax)
  402097:	00 00                	add    %al,(%rax)
  402099:	0e                   	(bad)  
  40209a:	10 46 0e             	adc    %al,0xe(%rsi)
  40209d:	18 4a 0f             	sbb    %cl,0xf(%rdx)
  4020a0:	0b 77 08             	or     0x8(%rdi),%esi
  4020a3:	80 00 3f             	addb   $0x3f,(%rax)
  4020a6:	1a 3b                	sbb    (%rbx),%bh
  4020a8:	2a 33                	sub    (%rbx),%dh
  4020aa:	24 22                	and    $0x22,%al
  4020ac:	00 00                	add    %al,(%rax)
  4020ae:	00 00                	add    %al,(%rax)
  4020b0:	14 00                	adc    $0x0,%al
  4020b2:	00 00                	add    %al,(%rax)
  4020b4:	6c                   	insb   (%dx),%es:(%rdi)
  4020b5:	00 00                	add    %al,(%rax)
  4020b7:	00 78 f0             	add    %bh,-0x10(%rax)
  4020ba:	ff                   	(bad)  
  4020bb:	ff 1a                	lcall  *(%rdx)
  4020bd:	00 00                	add    %al,(%rax)
  4020bf:	00 00                	add    %al,(%rax)
  4020c1:	44 0e                	rex.R (bad) 
  4020c3:	20 55 0e             	and    %dl,0xe(%rbp)
  4020c6:	08 00                	or     %al,(%rax)
  4020c8:	14 00                	adc    $0x0,%al
  4020ca:	00 00                	add    %al,(%rax)
  4020cc:	84 00                	test   %al,(%rax)
  4020ce:	00 00                	add    %al,(%rax)
  4020d0:	80 f0 ff             	xor    $0xff,%al
  4020d3:	ff 1c 00             	lcall  *(%rax,%rax,1)
  4020d6:	00 00                	add    %al,(%rax)
  4020d8:	00 41 0e             	add    %al,0xe(%rcx)
  4020db:	10 5a 0e             	adc    %bl,0xe(%rdx)
  4020de:	08 00                	or     %al,(%rax)
  4020e0:	1c 00                	sbb    $0x0,%al
  4020e2:	00 00                	add    %al,(%rax)
  4020e4:	9c                   	pushf  
  4020e5:	00 00                	add    %al,(%rax)
  4020e7:	00 88 f0 ff ff 27    	add    %cl,0x27fffff0(%rax)
  4020ed:	00 00                	add    %al,(%rax)
  4020ef:	00 00                	add    %al,(%rax)
  4020f1:	41 0e                	rex.B (bad) 
  4020f3:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  4020f9:	62                   	(bad)  
  4020fa:	0c 07                	or     $0x7,%al
  4020fc:	08 00                	or     %al,(%rax)
	...

0000000000402100 <__FRAME_END__>:
  402100:	00 00                	add    %al,(%rax)
	...

Desmontagem da seção .init_array:

0000000000403e10 <__frame_dummy_init_array_entry>:
  403e10:	20 11                	and    %dl,(%rcx)
  403e12:	40 00 00             	rex add %al,(%rax)
  403e15:	00 00                	add    %al,(%rax)
	...

Desmontagem da seção .fini_array:

0000000000403e18 <__do_global_dtors_aux_fini_array_entry>:
  403e18:	f0 10 40 00          	lock adc %al,0x0(%rax)
  403e1c:	00 00                	add    %al,(%rax)
	...

Desmontagem da seção .dynamic:

0000000000403e20 <_DYNAMIC>:
  403e20:	01 00                	add    %eax,(%rax)
  403e22:	00 00                	add    %al,(%rax)
  403e24:	00 00                	add    %al,(%rax)
  403e26:	00 00                	add    %al,(%rax)
  403e28:	1a 00                	sbb    (%rax),%al
  403e2a:	00 00                	add    %al,(%rax)
  403e2c:	00 00                	add    %al,(%rax)
  403e2e:	00 00                	add    %al,(%rax)
  403e30:	0c 00                	or     $0x0,%al
  403e32:	00 00                	add    %al,(%rax)
  403e34:	00 00                	add    %al,(%rax)
  403e36:	00 00                	add    %al,(%rax)
  403e38:	00 10                	add    %dl,(%rax)
  403e3a:	40 00 00             	rex add %al,(%rax)
  403e3d:	00 00                	add    %al,(%rax)
  403e3f:	00 0d 00 00 00 00    	add    %cl,0x0(%rip)        # 403e45 <_DYNAMIC+0x25>
  403e45:	00 00                	add    %al,(%rax)
  403e47:	00 98 11 40 00 00    	add    %bl,0x4011(%rax)
  403e4d:	00 00                	add    %al,(%rax)
  403e4f:	00 19                	add    %bl,(%rcx)
  403e51:	00 00                	add    %al,(%rax)
  403e53:	00 00                	add    %al,(%rax)
  403e55:	00 00                	add    %al,(%rax)
  403e57:	00 10                	add    %dl,(%rax)
  403e59:	3e 40 00 00          	ds rex add %al,(%rax)
  403e5d:	00 00                	add    %al,(%rax)
  403e5f:	00 1b                	add    %bl,(%rbx)
  403e61:	00 00                	add    %al,(%rax)
  403e63:	00 00                	add    %al,(%rax)
  403e65:	00 00                	add    %al,(%rax)
  403e67:	00 08                	add    %cl,(%rax)
  403e69:	00 00                	add    %al,(%rax)
  403e6b:	00 00                	add    %al,(%rax)
  403e6d:	00 00                	add    %al,(%rax)
  403e6f:	00 1a                	add    %bl,(%rdx)
  403e71:	00 00                	add    %al,(%rax)
  403e73:	00 00                	add    %al,(%rax)
  403e75:	00 00                	add    %al,(%rax)
  403e77:	00 18                	add    %bl,(%rax)
  403e79:	3e 40 00 00          	ds rex add %al,(%rax)
  403e7d:	00 00                	add    %al,(%rax)
  403e7f:	00 1c 00             	add    %bl,(%rax,%rax,1)
  403e82:	00 00                	add    %al,(%rax)
  403e84:	00 00                	add    %al,(%rax)
  403e86:	00 00                	add    %al,(%rax)
  403e88:	08 00                	or     %al,(%rax)
  403e8a:	00 00                	add    %al,(%rax)
  403e8c:	00 00                	add    %al,(%rax)
  403e8e:	00 00                	add    %al,(%rax)
  403e90:	f5                   	cmc    
  403e91:	fe                   	(bad)  
  403e92:	ff 6f 00             	ljmp   *0x0(%rdi)
  403e95:	00 00                	add    %al,(%rax)
  403e97:	00 a0 03 40 00 00    	add    %ah,0x4003(%rax)
  403e9d:	00 00                	add    %al,(%rax)
  403e9f:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 403ea5 <_DYNAMIC+0x85>
  403ea5:	00 00                	add    %al,(%rax)
  403ea7:	00 20                	add    %ah,(%rax)
  403ea9:	04 40                	add    $0x40,%al
  403eab:	00 00                	add    %al,(%rax)
  403ead:	00 00                	add    %al,(%rax)
  403eaf:	00 06                	add    %al,(%rsi)
  403eb1:	00 00                	add    %al,(%rax)
  403eb3:	00 00                	add    %al,(%rax)
  403eb5:	00 00                	add    %al,(%rax)
  403eb7:	00 c0                	add    %al,%al
  403eb9:	03 40 00             	add    0x0(%rax),%eax
  403ebc:	00 00                	add    %al,(%rax)
  403ebe:	00 00                	add    %al,(%rax)
  403ec0:	0a 00                	or     (%rax),%al
  403ec2:	00 00                	add    %al,(%rax)
  403ec4:	00 00                	add    %al,(%rax)
  403ec6:	00 00                	add    %al,(%rax)
  403ec8:	4a 00 00             	rex.WX add %al,(%rax)
  403ecb:	00 00                	add    %al,(%rax)
  403ecd:	00 00                	add    %al,(%rax)
  403ecf:	00 0b                	add    %cl,(%rbx)
  403ed1:	00 00                	add    %al,(%rax)
  403ed3:	00 00                	add    %al,(%rax)
  403ed5:	00 00                	add    %al,(%rax)
  403ed7:	00 18                	add    %bl,(%rax)
  403ed9:	00 00                	add    %al,(%rax)
  403edb:	00 00                	add    %al,(%rax)
  403edd:	00 00                	add    %al,(%rax)
  403edf:	00 15 00 00 00 00    	add    %dl,0x0(%rip)        # 403ee5 <_DYNAMIC+0xc5>
	...
  403eed:	00 00                	add    %al,(%rax)
  403eef:	00 03                	add    %al,(%rbx)
	...
  403ef9:	40                   	rex
  403efa:	40 00 00             	rex add %al,(%rax)
  403efd:	00 00                	add    %al,(%rax)
  403eff:	00 02                	add    %al,(%rdx)
  403f01:	00 00                	add    %al,(%rax)
  403f03:	00 00                	add    %al,(%rax)
  403f05:	00 00                	add    %al,(%rax)
  403f07:	00 18                	add    %bl,(%rax)
  403f09:	00 00                	add    %al,(%rax)
  403f0b:	00 00                	add    %al,(%rax)
  403f0d:	00 00                	add    %al,(%rax)
  403f0f:	00 14 00             	add    %dl,(%rax,%rax,1)
  403f12:	00 00                	add    %al,(%rax)
  403f14:	00 00                	add    %al,(%rax)
  403f16:	00 00                	add    %al,(%rax)
  403f18:	07                   	(bad)  
  403f19:	00 00                	add    %al,(%rax)
  403f1b:	00 00                	add    %al,(%rax)
  403f1d:	00 00                	add    %al,(%rax)
  403f1f:	00 17                	add    %dl,(%rdi)
  403f21:	00 00                	add    %al,(%rax)
  403f23:	00 00                	add    %al,(%rax)
  403f25:	00 00                	add    %al,(%rax)
  403f27:	00 d8                	add    %bl,%al
  403f29:	04 40                	add    $0x40,%al
  403f2b:	00 00                	add    %al,(%rax)
  403f2d:	00 00                	add    %al,(%rax)
  403f2f:	00 07                	add    %al,(%rdi)
  403f31:	00 00                	add    %al,(%rax)
  403f33:	00 00                	add    %al,(%rax)
  403f35:	00 00                	add    %al,(%rax)
  403f37:	00 a8 04 40 00 00    	add    %ch,0x4004(%rax)
  403f3d:	00 00                	add    %al,(%rax)
  403f3f:	00 08                	add    %cl,(%rax)
  403f41:	00 00                	add    %al,(%rax)
  403f43:	00 00                	add    %al,(%rax)
  403f45:	00 00                	add    %al,(%rax)
  403f47:	00 30                	add    %dh,(%rax)
  403f49:	00 00                	add    %al,(%rax)
  403f4b:	00 00                	add    %al,(%rax)
  403f4d:	00 00                	add    %al,(%rax)
  403f4f:	00 09                	add    %cl,(%rcx)
  403f51:	00 00                	add    %al,(%rax)
  403f53:	00 00                	add    %al,(%rax)
  403f55:	00 00                	add    %al,(%rax)
  403f57:	00 18                	add    %bl,(%rax)
  403f59:	00 00                	add    %al,(%rax)
  403f5b:	00 00                	add    %al,(%rax)
  403f5d:	00 00                	add    %al,(%rax)
  403f5f:	00 fe                	add    %bh,%dh
  403f61:	ff                   	(bad)  
  403f62:	ff 6f 00             	ljmp   *0x0(%rdi)
  403f65:	00 00                	add    %al,(%rax)
  403f67:	00 78 04             	add    %bh,0x4(%rax)
  403f6a:	40 00 00             	rex add %al,(%rax)
  403f6d:	00 00                	add    %al,(%rax)
  403f6f:	00 ff                	add    %bh,%bh
  403f71:	ff                   	(bad)  
  403f72:	ff 6f 00             	ljmp   *0x0(%rdi)
  403f75:	00 00                	add    %al,(%rax)
  403f77:	00 01                	add    %al,(%rcx)
  403f79:	00 00                	add    %al,(%rax)
  403f7b:	00 00                	add    %al,(%rax)
  403f7d:	00 00                	add    %al,(%rax)
  403f7f:	00 f0                	add    %dh,%al
  403f81:	ff                   	(bad)  
  403f82:	ff 6f 00             	ljmp   *0x0(%rdi)
  403f85:	00 00                	add    %al,(%rax)
  403f87:	00 6a 04             	add    %ch,0x4(%rdx)
  403f8a:	40 00 00             	rex add %al,(%rax)
	...

Desmontagem da seção .got:

0000000000403ff0 <.got>:
	...

Desmontagem da seção .got.plt:

0000000000404000 <_GLOBAL_OFFSET_TABLE_>:
  404000:	20 3e                	and    %bh,(%rsi)
  404002:	40 00 00             	rex add %al,(%rax)
	...
  404015:	00 00                	add    %al,(%rax)
  404017:	00 36                	add    %dh,(%rsi)
  404019:	10 40 00             	adc    %al,0x0(%rax)
  40401c:	00 00                	add    %al,(%rax)
	...

Desmontagem da seção .data:

0000000000404020 <__data_start>:
	...

0000000000404028 <__dso_handle>:
	...

Desmontagem da seção .bss:

0000000000404030 <completed.0>:
	...

Desmontagem da seção .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp (%r8),%spl
   5:	28 55 62             	sub    %dl,0x62(%rbp)
   8:	75 6e                	jne    78 <__abi_tag-0x400304>
   a:	74 75                	je     81 <__abi_tag-0x4002fb>
   c:	20 31                	and    %dh,(%rcx)
   e:	31 2e                	xor    %ebp,(%rsi)
  10:	32 2e                	xor    (%rsi),%ch
  12:	30 2d 37 75 62 75    	xor    %ch,0x75627537(%rip)        # 7562754f <_end+0x75223517>
  18:	6e                   	outsb  %ds:(%rsi),(%dx)
  19:	74 75                	je     90 <__abi_tag-0x4002ec>
  1b:	32 29                	xor    (%rcx),%ch
  1d:	20 31                	and    %dh,(%rcx)
  1f:	31 2e                	xor    %ebp,(%rsi)
  21:	32 2e                	xor    (%rsi),%ch
  23:	30 00                	xor    %al,(%rax)
  25:	55                   	push   %rbp
  26:	62                   	(bad)  
  27:	75 6e                	jne    97 <__abi_tag-0x4002e5>
  29:	74 75                	je     a0 <__abi_tag-0x4002dc>
  2b:	20 63 6c             	and    %ah,0x6c(%rbx)
  2e:	61                   	(bad)  
  2f:	6e                   	outsb  %ds:(%rsi),(%dx)
  30:	67 20 76 65          	and    %dh,0x65(%esi)
  34:	72 73                	jb     a9 <__abi_tag-0x4002d3>
  36:	69 6f 6e 20 31 33 2e 	imul   $0x2e333120,0x6e(%rdi),%ebp
  3d:	30 2e                	xor    %ch,(%rsi)
  3f:	30                   	.byte 0x30
  40:	2d                   	.byte 0x2d
  41:	32 00                	xor    (%rax),%al
