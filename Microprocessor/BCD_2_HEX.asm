%macro io 4
        mov rax,%1
        mov rdi,%2
        mov rsi,%3
        mov rdx,%4
        syscall
%endmacro
;----------------------------------------


section .data
        bcdmsg db 10,"Enter the BCD Equivalent : "
        bcdl equ $-bcdmsg
        hexmsg db 10,"4 Digit Hex Number = "
        hexl equ $-hexmsg
;----------------------------------------        


section .bss
        num resb 5
        buff resb 4
;----------------------------------------


section .text
global _start
_start:
        io 1, 1, bcdmsg, bcdl
        io 0, 0, num, 5
        mov rax, 0
        mov rcx, 5
        mov bx, 0Ah
        mov rsi, num
        
        l_up:
                mul bx
                mov dl, 0
                mov dl, [rsi]               
                sub dl, 30h
                add al, dl  
                inc rsi
                loop l_up
                mov rsi, buff
                mov rcx, 4   
                                            
        l_up1:
                rol ax, 4
                mov dl, al
                AND dl, 0Fh
                cmp dl, 09h
                jbe l_add30
                        add dl, 07h
                l_add30:     
                        add dl, 30h
                        mov [rsi], dl
                        inc rsi
                        loop l_up1
                io 1, 1, hexmsg, hexl
                io 1, 1, buff, 4
                mov rax, 60
                XOR rbx, rbx
        syscall                         
                                               
                                               
                                               
