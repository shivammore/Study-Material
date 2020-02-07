;64bit program to take and print user input

section .data
	msgA db 'Enter MSG',10
	Alen: equ $-msgA	

section .bss
	hello resb 255

section .text
	global _start
		_start:
	
	
			mov rax,1
			mov rdi,1
			mov rsi, msgA
			mov rdx, Alen
			syscall
			
			call _get
	
			mov rax,60
			xor rdi,rdi
			syscall
  
		_get:
			mov rax,0
			mov rdi,1
			mov rsi, hello
			mov rdx, hello
			syscall
			call _print
			ret
			
		_print:
			mov rax,1
			mov rdi,1
			mov rsi, hello
			syscall
			ret
			
;output-----------------------
;student@IOE-HWLAB:~$ cd AB02SE2B
;student@IOE-HWLAB:~/AB02SE2B$ nasm -f elf64 UserInputProgram.asm -o hello.o
;student@IOE-HWLAB:~/AB02SE2B$ ld -o hello hello.o
;student@IOE-HWLAB:~/AB02SE2B$ ./hello
;Enter MSG
;Welcome To Assembly
;Welcome To Assembly
