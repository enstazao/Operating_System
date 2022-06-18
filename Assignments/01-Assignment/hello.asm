section .data
hello: db 'Hello World!',10     ;'Hello world!' plus a linefeed character
helloLen: equ $-hello           ; Length of the 'Hello World!' string

section .text
global _start

_start:
mov eax, 4                  ; This system call for write (sys_write)
mov ebx, 1                  ; File descriptor 1 - standard output
mov ecx, hello              ; Put the offset of hello in ecx
mov edx, helloLen           ; helloLen is a constand
int 80h                     ; invoke the system call 
                            ; int is the assembly mnemonic for "interrupt",                              
                            ; processor was running in ring 3 protection level,                    
                            ; processor shift to ring 0(hardware protection disabled) now os checks what            
                            ; we want from it when these values in these 4                                          
                            ; registers os will display value on console present in ecx register and number of          
                            ; characters are in edx register.
                            ; (80h/0x80 or 128 in decimal is the Unix System Call interrupt) 

mov eax, 1
mov ebx, 0
int 80h