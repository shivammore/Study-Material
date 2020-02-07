%macro iomacro 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
%endmacro 



section .data

	title db "---Positive And Negative Values In Array Counter---"
	titlelen: equ $-title
	posmsg db 10,"-Positive Values In Array = "
	posmsglen: equ $-posmsg
	negmsg db 10,"-Negative Values In Array = "
	negmsglen: equ $-negmsg
	
	arr dd 1000H,-121H,0045H,34H,-12H,121H,-4543H,98H	
	arrcnt equ 8
	pcnt dw 0
	ncnt dw 0

		
section .bss
	dis_buffer resb 2

	
section .text
	global _start
	_start:
		;macro Title Display
		iomacro 1,1,title,titlelen
		syscall		
		mov rsi,arr
		mov rcx, arrcnt
		
		UP:
			bt word[rsi],15
			jnc PNEXT
			inc byte[ncnt]
			jmp PSKIP
		PNEXT:
			inc byte[pcnt]
		PSKIP:
			inc rsi
			inc rsi
			loop UP
		
						
		;macro +ve Count MSG Display--------------------------------
		iomacro 1,1,posmsg,posmsglen	
		syscall		

		mov bl, [pcnt]		
		call _HEX2ASCII
	
		
	
		;macro -ve Count MSG Display--------------------------------
		iomacro 1,1,negmsg,negmsglen
		syscall		
		
		mov bl, [ncnt]
		call _HEX2ASCII

		mov rax,60
		xor rdi,rdi
		
	_HEX2ASCII:		;------------------Hex2ASCII_Conversion--
		mov rcx,2						;
		mov rdi,dis_buffer					;
		DUP:							;
			rol bl,04					;
			mov al,bl					;
			AND al,0Fh					;
			cmp al,09h					;
			jbe next					;
			add al,07h					;
			next:						;
				add al,30h				;
			mov [rdi],al					;
			inc rdi						;
			loop DUP					;
		iomacro 1,1,dis_buffer,2				;
		syscall							;
		ret		;----------------------------------------
