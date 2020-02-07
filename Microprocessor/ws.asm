;With String Block Transfer
;***************************************************************
section .data
	
	blk_bfrmsg db 10,'Block contents before transfer'
	blk_bfrmsg_len equ $-blk_bfrmsg

	blk_afrmsg db 10,'Block contents after transfer'
	blk_afrmsg_len equ $-blk_afrmsg

	srcmsg db 10,'Source block contents::'
	srcmsg_len equ $-srcmsg

	dstmsg db 10,'Destination block contents::'
	dstmsg_len equ $-dstmsg

	srcblk db 01h,02h,03h,04h,05h
	dstblk db 00,00,00,00,00

	spacechar db 20h
	spchlength equ $-spacechar

;****************.bss Section***************************
section .bss

	
	dispbuff resb 02

	%macro display 2
		mov rax,01
		mov rdi,01
		mov rsi,%1
		mov rdx,%2
		syscall
	%endmacro
	
	
	
;*******************.text Section**************************

section .text
	global _start
_start:

	display blk_bfrmsg,blk_bfrmsg_len

	call dispsrc_blk_proc

	call dispdest_blk_proc

	mov rsi,srcblk
	mov rdi,dstblk
	mov rcx,05

	cld
	rep movsb
	display blk_afrmsg,blk_afrmsg_len
	call dispsrc_blk_proc
	call dispdest_blk_proc


	mov rax,60	                                                  ;Exit
	mov rbx,00
	syscall

;**************Display Source Block Procedure****************
dispsrc_blk_proc:

	display srcmsg,srcmsg_len
	mov rsi,srcblk
	mov rcx,05h
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
	
;**************Display Destination Block Procedure*************
dispdest_blk_proc:
	
	display dstmsg,dstmsg_len
	mov rdi,dstblk
	mov rcx,05
up2:
	push rcx
	mov bl,[rdi]
	push rdi
	call disp8_proc
	display spacechar,spchlength
	pop rdi
	inc rdi
	pop rcx
	loop up2
	ret

;************Display Procedure********************
disp8_proc:
	mov rsi,dispbuff
	mov rcx,02

        dup1:
	        rol bl,4
	        mov dl,bl
	        and dl,0Fh
	        cmp dl,09H
        jbe dskip
	        add dl,07h

        dskip:
	        add dl,30h
	        mov [rsi],dl
	        inc rsi
	        loop dup1

	        display dispbuff,02
	        ret
	
	
;************Output********************	
	
;student@IOE-HWLAB:~/Micro/Lab2$ nasm -f elf64 ws.asm -o obj.o
;student@IOE-HWLAB:~/Micro/Lab2$ ld -o obj obj.o
;student@IOE-HWLAB:~/Micro/Lab2$ ./obj
;
;Block contents before transfer
;Source block contents::01 02 03 04 05 
;Destination block contents::00 00 00 00 00 
;Block contents after transfer
;Source block contents::01 02 03 04 05 
;Destination block contents::01 02 03 04 05 
