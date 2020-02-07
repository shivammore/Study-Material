;Without String Block Transfer Overlapping
;***********************************************************
section .data

	blk_bfrmsg db 10,10,'Block contents before Overlap'
	blk_bfrmsg_len equ $-blk_bfrmsg

	blk_afrmsg db 10,'Block contents after Overlap',10
	blk_afrmsg_len equ $-blk_afrmsg

	srcmsg db 10,'Source block contents::'
	srcmsg_len equ $-srcmsg

	posmsg db 10,10,10,'Enter position to overlap::'
	posmsg_len equ $-posmsg

	spacechar db 20h
	spchlength equ $-spacechar

	srcblk db 01h,02h,03h,04h,05h,00h,00h,00h,00h,00h
	
;**********.bss Section**********************

section .bss

	optionbuff resb 02
	dispbuff resb 02
	numascii resb 03

	pos resb 00

	%macro display 2
		mov rax,01
		mov rdi,01
		mov rsi,%1
		mov rdx,%2
		syscall
	%endmacro

	%macro accept 2
		mov rax,00
		mov rdi,00
		mov rsi,%1
		mov rdx,%2
		syscall
	%endmacro

;**********Text Section**********************
section .text

global _start

_start:


	display blk_bfrmsg,blk_bfrmsg_len
	call disp_src_blk_proc

	display posmsg,posmsg_len
	accept numascii,3

	call packnum_proc
	mov rsi,srcblk+4

	mov rdi,rsi
	add rdi,[pos]
	mov rcx,05

	blkup1:

	mov al,[rsi]
	mov [rdi],al
	dec rsi
	dec rdi

	loop blkup1

	display blk_afrmsg,blk_afrmsg_len
	call disp_src_blk_proc



	mov rax,60
	mov rbx,00
	syscall


;**********Display Block Procedure**********************


disp_src_blk_proc:

	display srcmsg,srcmsg_len

	mov rsi,srcblk
	mov rcx,05h
	add cl,[pos]

up1:

	push rcx
	mov bl,[rsi]
	push rsi
	call disp8_proc

	display spacechar,spchlength
	pop rsi
	inc rsi
	pop rcx
	loop up1
	ret


;************Display Procedure********************

disp8_proc:
mov ecx,2

mov edi,dispbuff

dup1:

rol bl,4
mov dl,bl
and dl,0fh
cmp dl,09
jbe dskip
add dl,07h

dskip: 

add dl,30h
mov [edi],dl
inc edi
loop dup1

display dispbuff,2
ret


;************Packnum Procedure********************
packnum_proc:

mov bx,0
mov ecx,2
mov esi,numascii

up2:

rol bl,4

mov al,[esi]
sub al,30h
cmp al,09h
jbe skip5
sub al,07h


skip5:

add bl,al

inc esi
loop up2

mov [pos],bl
ret



;***********************Output*************************
;student@IOE-HWLAB:~/Micro/Lab2$ nasm -f elf64 wosov.asm -o obj.o
;student@IOE-HWLAB:~/Micro/Lab2$ ld -o obj obj.o
;student@IOE-HWLAB:~/Micro/Lab2$ ./obj

;Block contents before Overlap
;Source block contents::01 02 03 04 05 
;Enter position to overlap::03
;Block contents after Overlap
;Source block contents::01 02 03 01 02 03 04 05 
;student@IOE-HWLAB:~/Micro/Lab2$ ./obj
;Block contents before Overlap
;Source block contents::01 02 03 04 05 
;Enter position to overlap::06
;Block contents after Overlap
;Source block contents::01 02 03 04 05 00 01 02 03 04 05 
;student@IOE-HWLAB:~/Micro/Lab2$ ./obj
;Block contents before Overlap
;Source block contents::01 02 03 04 05 
;Enter position to overlap::05
;Block contents after Overlap
;Source block contents::01 02 03 04 05 01 02 03 04 05

