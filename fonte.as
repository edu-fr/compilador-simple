
fonte.o:     format de fichier elf64-x86-64


Déassemblage de la section .interp :

00000000004002a8 <.interp>:
  4002a8:	2f                   	(bad)  
  4002a9:	6c                   	insb   (%dx),%es:(%rdi)
  4002aa:	69 62 36 34 2f 6c 64 	imul   $0x646c2f34,0x36(%rdx),%esp
  4002b1:	2d 6c 69 6e 75       	sub    $0x756e696c,%eax
  4002b6:	78 2d                	js     4002e5 <_init-0xd1b>
  4002b8:	78 38                	js     4002f2 <_init-0xd0e>
  4002ba:	36 2d 36 34 2e 73    	ss sub $0x732e3436,%eax
  4002c0:	6f                   	outsl  %ds:(%rsi),(%dx)
  4002c1:	2e 32 00             	xor    %cs:(%rax),%al

Déassemblage de la section .note.gnu.build-id :

00000000004002c4 <.note.gnu.build-id>:
  4002c4:	04 00                	add    $0x0,%al
  4002c6:	00 00                	add    %al,(%rax)
  4002c8:	14 00                	adc    $0x0,%al
  4002ca:	00 00                	add    %al,(%rax)
  4002cc:	03 00                	add    (%rax),%eax
  4002ce:	00 00                	add    %al,(%rax)
  4002d0:	47                   	rex.RXB
  4002d1:	4e 55                	rex.WRX push %rbp
  4002d3:	00 19                	add    %bl,(%rcx)
  4002d5:	16                   	(bad)  
  4002d6:	10 ca                	adc    %cl,%dl
  4002d8:	e4 28                	in     $0x28,%al
  4002da:	59                   	pop    %rcx
  4002db:	e0 71                	loopne 40034e <_init-0xcb2>
  4002dd:	cc                   	int3   
  4002de:	6c                   	insb   (%dx),%es:(%rdi)
  4002df:	15 ab 5c 55 42       	adc    $0x42555cab,%eax
  4002e4:	ff 07                	incl   (%rdi)
  4002e6:	f0 d6                	lock (bad) 

Déassemblage de la section .note.ABI-tag :

00000000004002e8 <.note.ABI-tag>:
  4002e8:	04 00                	add    $0x0,%al
  4002ea:	00 00                	add    %al,(%rax)
  4002ec:	10 00                	adc    %al,(%rax)
  4002ee:	00 00                	add    %al,(%rax)
  4002f0:	01 00                	add    %eax,(%rax)
  4002f2:	00 00                	add    %al,(%rax)
  4002f4:	47                   	rex.RXB
  4002f5:	4e 55                	rex.WRX push %rbp
  4002f7:	00 00                	add    %al,(%rax)
  4002f9:	00 00                	add    %al,(%rax)
  4002fb:	00 03                	add    %al,(%rbx)
  4002fd:	00 00                	add    %al,(%rax)
  4002ff:	00 02                	add    %al,(%rdx)
  400301:	00 00                	add    %al,(%rax)
  400303:	00 00                	add    %al,(%rax)
  400305:	00 00                	add    %al,(%rax)
	...

Déassemblage de la section .gnu.hash :

0000000000400308 <.gnu.hash>:
  400308:	01 00                	add    %eax,(%rax)
  40030a:	00 00                	add    %al,(%rax)
  40030c:	01 00                	add    %eax,(%rax)
  40030e:	00 00                	add    %al,(%rax)
  400310:	01 00                	add    %eax,(%rax)
	...

Déassemblage de la section .dynsym :

0000000000400328 <.dynsym>:
	...
  400340:	0b 00                	or     (%rax),%eax
  400342:	00 00                	add    %al,(%rax)
  400344:	12 00                	adc    (%rax),%al
	...
  400356:	00 00                	add    %al,(%rax)
  400358:	12 00                	adc    (%rax),%al
  40035a:	00 00                	add    %al,(%rax)
  40035c:	12 00                	adc    (%rax),%al
	...
  40036e:	00 00                	add    %al,(%rax)
  400370:	30 00                	xor    %al,(%rax)
  400372:	00 00                	add    %al,(%rax)
  400374:	20 00                	and    %al,(%rax)
	...

Déassemblage de la section .dynstr :

0000000000400388 <.dynstr>:
  400388:	00 6c 69 62          	add    %ch,0x62(%rcx,%rbp,2)
  40038c:	63 2e                	movslq (%rsi),%ebp
  40038e:	73 6f                	jae    4003ff <_init-0xc01>
  400390:	2e 36 00 70 72       	cs add %dh,%ss:0x72(%rax)
  400395:	69 6e 74 66 00 5f 5f 	imul   $0x5f5f0066,0x74(%rsi),%ebp
  40039c:	6c                   	insb   (%dx),%es:(%rdi)
  40039d:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%rdx),%esp
  4003a4:	72 74                	jb     40041a <_init-0xbe6>
  4003a6:	5f                   	pop    %rdi
  4003a7:	6d                   	insl   (%dx),%es:(%rdi)
  4003a8:	61                   	(bad)  
  4003a9:	69 6e 00 47 4c 49 42 	imul   $0x42494c47,0x0(%rsi),%ebp
  4003b0:	43 5f                	rex.XB pop %r15
  4003b2:	32 2e                	xor    (%rsi),%ch
  4003b4:	32 2e                	xor    (%rsi),%ch
  4003b6:	35 00 5f 5f 67       	xor    $0x675f5f00,%eax
  4003bb:	6d                   	insl   (%dx),%es:(%rdi)
  4003bc:	6f                   	outsl  %ds:(%rsi),(%dx)
  4003bd:	6e                   	outsb  %ds:(%rsi),(%dx)
  4003be:	5f                   	pop    %rdi
  4003bf:	73 74                	jae    400435 <_init-0xbcb>
  4003c1:	61                   	(bad)  
  4003c2:	72 74                	jb     400438 <_init-0xbc8>
  4003c4:	5f                   	pop    %rdi
  4003c5:	5f                   	pop    %rdi
	...

Déassemblage de la section .gnu.version :

00000000004003c8 <.gnu.version>:
  4003c8:	00 00                	add    %al,(%rax)
  4003ca:	02 00                	add    (%rax),%al
  4003cc:	02 00                	add    (%rax),%al
	...

Déassemblage de la section .gnu.version_r :

00000000004003d0 <.gnu.version_r>:
  4003d0:	01 00                	add    %eax,(%rax)
  4003d2:	01 00                	add    %eax,(%rax)
  4003d4:	01 00                	add    %eax,(%rax)
  4003d6:	00 00                	add    %al,(%rax)
  4003d8:	10 00                	adc    %al,(%rax)
  4003da:	00 00                	add    %al,(%rax)
  4003dc:	00 00                	add    %al,(%rax)
  4003de:	00 00                	add    %al,(%rax)
  4003e0:	75 1a                	jne    4003fc <_init-0xc04>
  4003e2:	69 09 00 00 02 00    	imul   $0x20000,(%rcx),%ecx
  4003e8:	24 00                	and    $0x0,%al
  4003ea:	00 00                	add    %al,(%rax)
  4003ec:	00 00                	add    %al,(%rax)
	...

Déassemblage de la section .rela.dyn :

00000000004003f0 <.rela.dyn>:
  4003f0:	f0 3f                	lock (bad) 
  4003f2:	40 00 00             	add    %al,(%rax)
  4003f5:	00 00                	add    %al,(%rax)
  4003f7:	00 06                	add    %al,(%rsi)
  4003f9:	00 00                	add    %al,(%rax)
  4003fb:	00 02                	add    %al,(%rdx)
	...
  400405:	00 00                	add    %al,(%rax)
  400407:	00 f8                	add    %bh,%al
  400409:	3f                   	(bad)  
  40040a:	40 00 00             	add    %al,(%rax)
  40040d:	00 00                	add    %al,(%rax)
  40040f:	00 06                	add    %al,(%rsi)
  400411:	00 00                	add    %al,(%rax)
  400413:	00 03                	add    %al,(%rbx)
	...

Déassemblage de la section .rela.plt :

0000000000400420 <.rela.plt>:
  400420:	18 40 40             	sbb    %al,0x40(%rax)
  400423:	00 00                	add    %al,(%rax)
  400425:	00 00                	add    %al,(%rax)
  400427:	00 07                	add    %al,(%rdi)
  400429:	00 00                	add    %al,(%rax)
  40042b:	00 01                	add    %al,(%rcx)
	...

Déassemblage de la section .init :

0000000000401000 <_init>:
  401000:	f3 0f 1e fa          	endbr64 
  401004:	48 83 ec 08          	sub    $0x8,%rsp
  401008:	48 8b 05 e9 2f 00 00 	mov    0x2fe9(%rip),%rax        # 403ff8 <__gmon_start__>
  40100f:	48 85 c0             	test   %rax,%rax
  401012:	74 02                	je     401016 <_init+0x16>
  401014:	ff d0                	callq  *%rax
  401016:	48 83 c4 08          	add    $0x8,%rsp
  40101a:	c3                   	retq   

Déassemblage de la section .plt :

0000000000401020 <.plt>:
  401020:	ff 35 e2 2f 00 00    	pushq  0x2fe2(%rip)        # 404008 <_GLOBAL_OFFSET_TABLE_+0x8>
  401026:	ff 25 e4 2f 00 00    	jmpq   *0x2fe4(%rip)        # 404010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401030 <printf@plt>:
  401030:	ff 25 e2 2f 00 00    	jmpq   *0x2fe2(%rip)        # 404018 <printf@GLIBC_2.2.5>
  401036:	68 00 00 00 00       	pushq  $0x0
  40103b:	e9 e0 ff ff ff       	jmpq   401020 <.plt>

Déassemblage de la section .text :

0000000000401040 <_start>:
  401040:	f3 0f 1e fa          	endbr64 
  401044:	31 ed                	xor    %ebp,%ebp
  401046:	49 89 d1             	mov    %rdx,%r9
  401049:	5e                   	pop    %rsi
  40104a:	48 89 e2             	mov    %rsp,%rdx
  40104d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  401051:	50                   	push   %rax
  401052:	54                   	push   %rsp
  401053:	49 c7 c0 30 12 40 00 	mov    $0x401230,%r8
  40105a:	48 c7 c1 c0 11 40 00 	mov    $0x4011c0,%rcx
  401061:	48 c7 c7 80 11 40 00 	mov    $0x401180,%rdi
  401068:	ff 15 82 2f 00 00    	callq  *0x2f82(%rip)        # 403ff0 <__libc_start_main@GLIBC_2.2.5>
  40106e:	f4                   	hlt    
  40106f:	90                   	nop

0000000000401070 <_dl_relocate_static_pie>:
  401070:	f3 0f 1e fa          	endbr64 
  401074:	c3                   	retq   
  401075:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
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
  40109c:	ff e0                	jmpq   *%rax
  40109e:	66 90                	xchg   %ax,%ax
  4010a0:	c3                   	retq   
  4010a1:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
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
  4010de:	ff e0                	jmpq   *%rax
  4010e0:	c3                   	retq   
  4010e1:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  4010e8:	00 00 00 00 
  4010ec:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004010f0 <__do_global_dtors_aux>:
  4010f0:	f3 0f 1e fa          	endbr64 
  4010f4:	80 3d 35 2f 00 00 00 	cmpb   $0x0,0x2f35(%rip)        # 404030 <__TMC_END__>
  4010fb:	75 13                	jne    401110 <__do_global_dtors_aux+0x20>
  4010fd:	55                   	push   %rbp
  4010fe:	48 89 e5             	mov    %rsp,%rbp
  401101:	e8 7a ff ff ff       	callq  401080 <deregister_tm_clones>
  401106:	c6 05 23 2f 00 00 01 	movb   $0x1,0x2f23(%rip)        # 404030 <__TMC_END__>
  40110d:	5d                   	pop    %rbp
  40110e:	c3                   	retq   
  40110f:	90                   	nop
  401110:	c3                   	retq   
  401111:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  401118:	00 00 00 00 
  40111c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401120 <frame_dummy>:
  401120:	f3 0f 1e fa          	endbr64 
  401124:	eb 8a                	jmp    4010b0 <register_tm_clones>
  401126:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40112d:	00 00 00 

0000000000401130 <funcao2>:
  401130:	50                   	push   %rax
  401131:	bf 03 00 00 00       	mov    $0x3,%edi
  401136:	be 04 00 00 00       	mov    $0x4,%esi
  40113b:	e8 10 00 00 00       	callq  401150 <funcao>
  401140:	59                   	pop    %rcx
  401141:	c3                   	retq   
  401142:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  401149:	00 00 00 
  40114c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401150 <funcao>:
  401150:	48 83 ec 18          	sub    $0x18,%rsp
  401154:	89 7c 24 10          	mov    %edi,0x10(%rsp)
  401158:	89 74 24 14          	mov    %esi,0x14(%rsp)
  40115c:	89 7c 24 0c          	mov    %edi,0xc(%rsp)
  401160:	e8 2b 00 00 00       	callq  401190 <imprimei>
  401165:	8b 7c 24 0c          	mov    0xc(%rsp),%edi
  401169:	e8 22 00 00 00       	callq  401190 <imprimei>
  40116e:	48 83 c4 18          	add    $0x18,%rsp
  401172:	c3                   	retq   
  401173:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40117a:	00 00 00 
  40117d:	0f 1f 00             	nopl   (%rax)

0000000000401180 <main>:
  401180:	50                   	push   %rax
  401181:	e8 aa ff ff ff       	callq  401130 <funcao2>
  401186:	59                   	pop    %rcx
  401187:	c3                   	retq   
  401188:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  40118f:	00 

0000000000401190 <imprimei>:
  401190:	55                   	push   %rbp
  401191:	48 89 e5             	mov    %rsp,%rbp
  401194:	48 83 ec 10          	sub    $0x10,%rsp
  401198:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  40119c:	48 8b 75 f8          	mov    -0x8(%rbp),%rsi
  4011a0:	48 bf 04 20 40 00 00 	movabs $0x402004,%rdi
  4011a7:	00 00 00 
  4011aa:	b0 00                	mov    $0x0,%al
  4011ac:	e8 7f fe ff ff       	callq  401030 <printf@plt>
  4011b1:	48 83 c4 10          	add    $0x10,%rsp
  4011b5:	5d                   	pop    %rbp
  4011b6:	c3                   	retq   
  4011b7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4011be:	00 00 

00000000004011c0 <__libc_csu_init>:
  4011c0:	f3 0f 1e fa          	endbr64 
  4011c4:	41 57                	push   %r15
  4011c6:	4c 8d 3d 43 2c 00 00 	lea    0x2c43(%rip),%r15        # 403e10 <__frame_dummy_init_array_entry>
  4011cd:	41 56                	push   %r14
  4011cf:	49 89 d6             	mov    %rdx,%r14
  4011d2:	41 55                	push   %r13
  4011d4:	49 89 f5             	mov    %rsi,%r13
  4011d7:	41 54                	push   %r12
  4011d9:	41 89 fc             	mov    %edi,%r12d
  4011dc:	55                   	push   %rbp
  4011dd:	48 8d 2d 34 2c 00 00 	lea    0x2c34(%rip),%rbp        # 403e18 <__do_global_dtors_aux_fini_array_entry>
  4011e4:	53                   	push   %rbx
  4011e5:	4c 29 fd             	sub    %r15,%rbp
  4011e8:	48 83 ec 08          	sub    $0x8,%rsp
  4011ec:	e8 0f fe ff ff       	callq  401000 <_init>
  4011f1:	48 c1 fd 03          	sar    $0x3,%rbp
  4011f5:	74 1f                	je     401216 <__libc_csu_init+0x56>
  4011f7:	31 db                	xor    %ebx,%ebx
  4011f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  401200:	4c 89 f2             	mov    %r14,%rdx
  401203:	4c 89 ee             	mov    %r13,%rsi
  401206:	44 89 e7             	mov    %r12d,%edi
  401209:	41 ff 14 df          	callq  *(%r15,%rbx,8)
  40120d:	48 83 c3 01          	add    $0x1,%rbx
  401211:	48 39 dd             	cmp    %rbx,%rbp
  401214:	75 ea                	jne    401200 <__libc_csu_init+0x40>
  401216:	48 83 c4 08          	add    $0x8,%rsp
  40121a:	5b                   	pop    %rbx
  40121b:	5d                   	pop    %rbp
  40121c:	41 5c                	pop    %r12
  40121e:	41 5d                	pop    %r13
  401220:	41 5e                	pop    %r14
  401222:	41 5f                	pop    %r15
  401224:	c3                   	retq   
  401225:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  40122c:	00 00 00 00 

0000000000401230 <__libc_csu_fini>:
  401230:	f3 0f 1e fa          	endbr64 
  401234:	c3                   	retq   

Déassemblage de la section .fini :

0000000000401238 <_fini>:
  401238:	f3 0f 1e fa          	endbr64 
  40123c:	48 83 ec 08          	sub    $0x8,%rsp
  401240:	48 83 c4 08          	add    $0x8,%rsp
  401244:	c3                   	retq   

Déassemblage de la section .rodata :

0000000000402000 <_IO_stdin_used>:
  402000:	01 00                	add    %eax,(%rax)
  402002:	02 00                	add    (%rax),%al
  402004:	25 6c 64 0a 00       	and    $0xa646c,%eax

Déassemblage de la section .eh_frame_hdr :

000000000040200c <__GNU_EH_FRAME_HDR>:
  40200c:	01 1b                	add    %ebx,(%rbx)
  40200e:	03 3b                	add    (%rbx),%edi
  402010:	50                   	push   %rax
  402011:	00 00                	add    %al,(%rax)
  402013:	00 09                	add    %cl,(%rcx)
  402015:	00 00                	add    %al,(%rax)
  402017:	00 14 f0             	add    %dl,(%rax,%rsi,8)
  40201a:	ff                   	(bad)  
  40201b:	ff 94 00 00 00 34 f0 	callq  *-0xfcc0000(%rax,%rax,1)
  402022:	ff                   	(bad)  
  402023:	ff 6c 00 00          	ljmp   *0x0(%rax,%rax,1)
  402027:	00 64 f0 ff          	add    %ah,-0x1(%rax,%rsi,8)
  40202b:	ff 80 00 00 00 24    	incl   0x24000000(%rax)
  402031:	f1                   	icebp  
  402032:	ff                   	(bad)  
  402033:	ff                   	(bad)  
  402034:	bc 00 00 00 44       	mov    $0x44000000,%esp
  402039:	f1                   	icebp  
  40203a:	ff                   	(bad)  
  40203b:	ff d4                	callq  *%rsp
  40203d:	00 00                	add    %al,(%rax)
  40203f:	00 74 f1 ff          	add    %dh,-0x1(%rcx,%rsi,8)
  402043:	ff                   	(bad)  
  402044:	ec                   	in     (%dx),%al
  402045:	00 00                	add    %al,(%rax)
  402047:	00 84 f1 ff ff 04 01 	add    %al,0x104ffff(%rcx,%rsi,8)
  40204e:	00 00                	add    %al,(%rax)
  402050:	b4 f1                	mov    $0xf1,%ah
  402052:	ff                   	(bad)  
  402053:	ff 24 01             	jmpq   *(%rcx,%rax,1)
  402056:	00 00                	add    %al,(%rax)
  402058:	24 f2                	and    $0xf2,%al
  40205a:	ff                   	(bad)  
  40205b:	ff 6c 01 00          	ljmp   *0x0(%rcx,%rax,1)
	...

Déassemblage de la section .eh_frame :

0000000000402060 <__FRAME_END__-0x12c>:
  402060:	14 00                	adc    $0x0,%al
  402062:	00 00                	add    %al,(%rax)
  402064:	00 00                	add    %al,(%rax)
  402066:	00 00                	add    %al,(%rax)
  402068:	01 7a 52             	add    %edi,0x52(%rdx)
  40206b:	00 01                	add    %al,(%rcx)
  40206d:	78 10                	js     40207f <__GNU_EH_FRAME_HDR+0x73>
  40206f:	01 1b                	add    %ebx,(%rbx)
  402071:	0c 07                	or     $0x7,%al
  402073:	08 90 01 00 00 10    	or     %dl,0x10000001(%rax)
  402079:	00 00                	add    %al,(%rax)
  40207b:	00 1c 00             	add    %bl,(%rax,%rax,1)
  40207e:	00 00                	add    %al,(%rax)
  402080:	c0 ef ff             	shr    $0xff,%bh
  402083:	ff 2f                	ljmp   *(%rdi)
  402085:	00 00                	add    %al,(%rax)
  402087:	00 00                	add    %al,(%rax)
  402089:	44 07                	rex.R (bad) 
  40208b:	10 10                	adc    %dl,(%rax)
  40208d:	00 00                	add    %al,(%rax)
  40208f:	00 30                	add    %dh,(%rax)
  402091:	00 00                	add    %al,(%rax)
  402093:	00 dc                	add    %bl,%ah
  402095:	ef                   	out    %eax,(%dx)
  402096:	ff                   	(bad)  
  402097:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 40209d <__GNU_EH_FRAME_HDR+0x91>
  40209d:	00 00                	add    %al,(%rax)
  40209f:	00 24 00             	add    %ah,(%rax,%rax,1)
  4020a2:	00 00                	add    %al,(%rax)
  4020a4:	44 00 00             	add    %r8b,(%rax)
  4020a7:	00 78 ef             	add    %bh,-0x11(%rax)
  4020aa:	ff                   	(bad)  
  4020ab:	ff 20                	jmpq   *(%rax)
  4020ad:	00 00                	add    %al,(%rax)
  4020af:	00 00                	add    %al,(%rax)
  4020b1:	0e                   	(bad)  
  4020b2:	10 46 0e             	adc    %al,0xe(%rsi)
  4020b5:	18 4a 0f             	sbb    %cl,0xf(%rdx)
  4020b8:	0b 77 08             	or     0x8(%rdi),%esi
  4020bb:	80 00 3f             	addb   $0x3f,(%rax)
  4020be:	1a 3b                	sbb    (%rbx),%bh
  4020c0:	2a 33                	sub    (%rbx),%dh
  4020c2:	24 22                	and    $0x22,%al
  4020c4:	00 00                	add    %al,(%rax)
  4020c6:	00 00                	add    %al,(%rax)
  4020c8:	14 00                	adc    $0x0,%al
  4020ca:	00 00                	add    %al,(%rax)
  4020cc:	6c                   	insb   (%dx),%es:(%rdi)
  4020cd:	00 00                	add    %al,(%rax)
  4020cf:	00 60 f0             	add    %ah,-0x10(%rax)
  4020d2:	ff                   	(bad)  
  4020d3:	ff 12                	callq  *(%rdx)
  4020d5:	00 00                	add    %al,(%rax)
  4020d7:	00 00                	add    %al,(%rax)
  4020d9:	41 0e                	rex.B (bad) 
  4020db:	10 50 0e             	adc    %dl,0xe(%rax)
  4020de:	08 00                	or     %al,(%rax)
  4020e0:	14 00                	adc    $0x0,%al
  4020e2:	00 00                	add    %al,(%rax)
  4020e4:	84 00                	test   %al,(%rax)
  4020e6:	00 00                	add    %al,(%rax)
  4020e8:	68 f0 ff ff 23       	pushq  $0x23fffff0
  4020ed:	00 00                	add    %al,(%rax)
  4020ef:	00 00                	add    %al,(%rax)
  4020f1:	44 0e                	rex.R (bad) 
  4020f3:	20 5e 0e             	and    %bl,0xe(%rsi)
  4020f6:	08 00                	or     %al,(%rax)
  4020f8:	14 00                	adc    $0x0,%al
  4020fa:	00 00                	add    %al,(%rax)
  4020fc:	9c                   	pushfq 
  4020fd:	00 00                	add    %al,(%rax)
  4020ff:	00 80 f0 ff ff 08    	add    %al,0x8fffff0(%rax)
  402105:	00 00                	add    %al,(%rax)
  402107:	00 00                	add    %al,(%rax)
  402109:	41 0e                	rex.B (bad) 
  40210b:	10 46 0e             	adc    %al,0xe(%rsi)
  40210e:	08 00                	or     %al,(%rax)
  402110:	1c 00                	sbb    $0x0,%al
  402112:	00 00                	add    %al,(%rax)
  402114:	b4 00                	mov    $0x0,%ah
  402116:	00 00                	add    %al,(%rax)
  402118:	78 f0                	js     40210a <__GNU_EH_FRAME_HDR+0xfe>
  40211a:	ff                   	(bad)  
  40211b:	ff 27                	jmpq   *(%rdi)
  40211d:	00 00                	add    %al,(%rax)
  40211f:	00 00                	add    %al,(%rax)
  402121:	41 0e                	rex.B (bad) 
  402123:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  402129:	62                   	(bad)  
  40212a:	0c 07                	or     $0x7,%al
  40212c:	08 00                	or     %al,(%rax)
  40212e:	00 00                	add    %al,(%rax)
  402130:	44 00 00             	add    %r8b,(%rax)
  402133:	00 d4                	add    %dl,%ah
  402135:	00 00                	add    %al,(%rax)
  402137:	00 88 f0 ff ff 65    	add    %cl,0x65fffff0(%rax)
  40213d:	00 00                	add    %al,(%rax)
  40213f:	00 00                	add    %al,(%rax)
  402141:	46 0e                	rex.RX (bad) 
  402143:	10 8f 02 49 0e 18    	adc    %cl,0x180e4902(%rdi)
  402149:	8e 03                	mov    (%rbx),%es
  40214b:	45 0e                	rex.RB (bad) 
  40214d:	20 8d 04 45 0e 28    	and    %cl,0x280e4504(%rbp)
  402153:	8c 05 44 0e 30 86    	mov    %es,-0x79cff1bc(%rip)        # ffffffff86702f9d <_end+0xffffffff862fef65>
  402159:	06                   	(bad)  
  40215a:	48 0e                	rex.W (bad) 
  40215c:	38 83 07 47 0e 40    	cmp    %al,0x400e4707(%rbx)
  402162:	6e                   	outsb  %ds:(%rsi),(%dx)
  402163:	0e                   	(bad)  
  402164:	38 41 0e             	cmp    %al,0xe(%rcx)
  402167:	30 41 0e             	xor    %al,0xe(%rcx)
  40216a:	28 42 0e             	sub    %al,0xe(%rdx)
  40216d:	20 42 0e             	and    %al,0xe(%rdx)
  402170:	18 42 0e             	sbb    %al,0xe(%rdx)
  402173:	10 42 0e             	adc    %al,0xe(%rdx)
  402176:	08 00                	or     %al,(%rax)
  402178:	10 00                	adc    %al,(%rax)
  40217a:	00 00                	add    %al,(%rax)
  40217c:	1c 01                	sbb    $0x1,%al
  40217e:	00 00                	add    %al,(%rax)
  402180:	b0 f0                	mov    $0xf0,%al
  402182:	ff                   	(bad)  
  402183:	ff 05 00 00 00 00    	incl   0x0(%rip)        # 402189 <__GNU_EH_FRAME_HDR+0x17d>
  402189:	00 00                	add    %al,(%rax)
	...

000000000040218c <__FRAME_END__>:
  40218c:	00 00                	add    %al,(%rax)
	...

Déassemblage de la section .init_array :

0000000000403e10 <__frame_dummy_init_array_entry>:
  403e10:	20 11                	and    %dl,(%rcx)
  403e12:	40 00 00             	add    %al,(%rax)
  403e15:	00 00                	add    %al,(%rax)
	...

Déassemblage de la section .fini_array :

0000000000403e18 <__do_global_dtors_aux_fini_array_entry>:
  403e18:	f0 10 40 00          	lock adc %al,0x0(%rax)
  403e1c:	00 00                	add    %al,(%rax)
	...

Déassemblage de la section .dynamic :

0000000000403e20 <_DYNAMIC>:
  403e20:	01 00                	add    %eax,(%rax)
  403e22:	00 00                	add    %al,(%rax)
  403e24:	00 00                	add    %al,(%rax)
  403e26:	00 00                	add    %al,(%rax)
  403e28:	01 00                	add    %eax,(%rax)
  403e2a:	00 00                	add    %al,(%rax)
  403e2c:	00 00                	add    %al,(%rax)
  403e2e:	00 00                	add    %al,(%rax)
  403e30:	0c 00                	or     $0x0,%al
  403e32:	00 00                	add    %al,(%rax)
  403e34:	00 00                	add    %al,(%rax)
  403e36:	00 00                	add    %al,(%rax)
  403e38:	00 10                	add    %dl,(%rax)
  403e3a:	40 00 00             	add    %al,(%rax)
  403e3d:	00 00                	add    %al,(%rax)
  403e3f:	00 0d 00 00 00 00    	add    %cl,0x0(%rip)        # 403e45 <_DYNAMIC+0x25>
  403e45:	00 00                	add    %al,(%rax)
  403e47:	00 38                	add    %bh,(%rax)
  403e49:	12 40 00             	adc    0x0(%rax),%al
  403e4c:	00 00                	add    %al,(%rax)
  403e4e:	00 00                	add    %al,(%rax)
  403e50:	19 00                	sbb    %eax,(%rax)
  403e52:	00 00                	add    %al,(%rax)
  403e54:	00 00                	add    %al,(%rax)
  403e56:	00 00                	add    %al,(%rax)
  403e58:	10 3e                	adc    %bh,(%rsi)
  403e5a:	40 00 00             	add    %al,(%rax)
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
  403e79:	3e 40 00 00          	add    %al,%ds:(%rax)
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
  403e97:	00 08                	add    %cl,(%rax)
  403e99:	03 40 00             	add    0x0(%rax),%eax
  403e9c:	00 00                	add    %al,(%rax)
  403e9e:	00 00                	add    %al,(%rax)
  403ea0:	05 00 00 00 00       	add    $0x0,%eax
  403ea5:	00 00                	add    %al,(%rax)
  403ea7:	00 88 03 40 00 00    	add    %cl,0x4003(%rax)
  403ead:	00 00                	add    %al,(%rax)
  403eaf:	00 06                	add    %al,(%rsi)
  403eb1:	00 00                	add    %al,(%rax)
  403eb3:	00 00                	add    %al,(%rax)
  403eb5:	00 00                	add    %al,(%rax)
  403eb7:	00 28                	add    %ch,(%rax)
  403eb9:	03 40 00             	add    0x0(%rax),%eax
  403ebc:	00 00                	add    %al,(%rax)
  403ebe:	00 00                	add    %al,(%rax)
  403ec0:	0a 00                	or     (%rax),%al
  403ec2:	00 00                	add    %al,(%rax)
  403ec4:	00 00                	add    %al,(%rax)
  403ec6:	00 00                	add    %al,(%rax)
  403ec8:	3f                   	(bad)  
  403ec9:	00 00                	add    %al,(%rax)
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
  403efa:	40 00 00             	add    %al,(%rax)
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
  403f27:	00 20                	add    %ah,(%rax)
  403f29:	04 40                	add    $0x40,%al
  403f2b:	00 00                	add    %al,(%rax)
  403f2d:	00 00                	add    %al,(%rax)
  403f2f:	00 07                	add    %al,(%rdi)
  403f31:	00 00                	add    %al,(%rax)
  403f33:	00 00                	add    %al,(%rax)
  403f35:	00 00                	add    %al,(%rax)
  403f37:	00 f0                	add    %dh,%al
  403f39:	03 40 00             	add    0x0(%rax),%eax
  403f3c:	00 00                	add    %al,(%rax)
  403f3e:	00 00                	add    %al,(%rax)
  403f40:	08 00                	or     %al,(%rax)
  403f42:	00 00                	add    %al,(%rax)
  403f44:	00 00                	add    %al,(%rax)
  403f46:	00 00                	add    %al,(%rax)
  403f48:	30 00                	xor    %al,(%rax)
  403f4a:	00 00                	add    %al,(%rax)
  403f4c:	00 00                	add    %al,(%rax)
  403f4e:	00 00                	add    %al,(%rax)
  403f50:	09 00                	or     %eax,(%rax)
  403f52:	00 00                	add    %al,(%rax)
  403f54:	00 00                	add    %al,(%rax)
  403f56:	00 00                	add    %al,(%rax)
  403f58:	18 00                	sbb    %al,(%rax)
  403f5a:	00 00                	add    %al,(%rax)
  403f5c:	00 00                	add    %al,(%rax)
  403f5e:	00 00                	add    %al,(%rax)
  403f60:	fe                   	(bad)  
  403f61:	ff                   	(bad)  
  403f62:	ff 6f 00             	ljmp   *0x0(%rdi)
  403f65:	00 00                	add    %al,(%rax)
  403f67:	00 d0                	add    %dl,%al
  403f69:	03 40 00             	add    0x0(%rax),%eax
  403f6c:	00 00                	add    %al,(%rax)
  403f6e:	00 00                	add    %al,(%rax)
  403f70:	ff                   	(bad)  
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
  403f87:	00 c8                	add    %cl,%al
  403f89:	03 40 00             	add    0x0(%rax),%eax
	...

Déassemblage de la section .got :

0000000000403ff0 <.got>:
	...

Déassemblage de la section .got.plt :

0000000000404000 <_GLOBAL_OFFSET_TABLE_>:
  404000:	20 3e                	and    %bh,(%rsi)
  404002:	40 00 00             	add    %al,(%rax)
	...
  404015:	00 00                	add    %al,(%rax)
  404017:	00 36                	add    %dh,(%rsi)
  404019:	10 40 00             	adc    %al,0x0(%rax)
  40401c:	00 00                	add    %al,(%rax)
	...

Déassemblage de la section .data :

0000000000404020 <__data_start>:
	...

0000000000404028 <__dso_handle>:
	...

Déassemblage de la section .bss :

0000000000404030 <completed.8061>:
	...

Déassemblage de la section .comment :

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp (%r8),%spl
   5:	28 55 62             	sub    %dl,0x62(%rbp)
   8:	75 6e                	jne    78 <_init-0x400f88>
   a:	74 75                	je     81 <_init-0x400f7f>
   c:	20 39                	and    %bh,(%rcx)
   e:	2e 34 2e             	cs xor $0x2e,%al
  11:	30 2d 31 75 62 75    	xor    %ch,0x75627531(%rip)        # 75627548 <_end+0x75223510>
  17:	6e                   	outsb  %ds:(%rsi),(%dx)
  18:	74 75                	je     8f <_init-0x400f71>
  1a:	31 7e 32             	xor    %edi,0x32(%rsi)
  1d:	30 2e                	xor    %ch,(%rsi)
  1f:	30 34 2e             	xor    %dh,(%rsi,%rbp,1)
  22:	31 29                	xor    %ebp,(%rcx)
  24:	20 39                	and    %bh,(%rcx)
  26:	2e 34 2e             	cs xor $0x2e,%al
  29:	30 00                	xor    %al,(%rax)
  2b:	63 6c 61 6e          	movslq 0x6e(%rcx,%riz,2),%ebp
  2f:	67 20 76 65          	and    %dh,0x65(%esi)
  33:	72 73                	jb     a8 <_init-0x400f58>
  35:	69 6f 6e 20 31 30 2e 	imul   $0x2e303120,0x6e(%rdi),%ebp
  3c:	30 2e                	xor    %ch,(%rsi)
  3e:	30 2d 34 75 62 75    	xor    %ch,0x75627534(%rip)        # 75627578 <_end+0x75223540>
  44:	6e                   	outsb  %ds:(%rsi),(%dx)
  45:	74 75                	je     bc <_init-0x400f44>
  47:	31 20                	xor    %esp,(%rax)
	...
