;64bit program to create subroutine

section .data
	hello db 'Hello Print Function!',10
	helloLen: equ $-hello

section .text
global _start
_start:
	
	call _print
	
	mov rax,60
	xor rdi,rdi
	syscall
  
_print:
	mov rax,1
	mov rdi,1
	mov rsi,hello
	mov rdx,helloLen
	syscall
	ret
	
;Output----------------------------
;student@IOE-HWLAB:~/AB02SE2B$ nasm -f elf64 SubRouteProgram.asm -o hello.o
;student@IOE-HWLAB:~/AB02SE2B$ ld -o hello hello.o
;student@IOE-HWLAB:~/AB02SE2B$ ./hello
;Hello Print Function!
