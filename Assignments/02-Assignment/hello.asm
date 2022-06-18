section .data
hello: db '.'
helloLen: equ $-hello       ;length of the string

section .text
global _start

_start:
mov ecx, 500000

l1:
    mov esi, ecx
    mov eax, 4              ; The system call for write (sys_write)
    mov ebx, 1              ; File descriptor 1- standard output
    mov ecx, hello          ; Put the offset of hello in ecx
    mov edx, helloLen       ; helloLen is a constant
    int 80h                 ; ??

    mov ecx, esi
loop l1

mov eax, 1
mov ebx, 0
int 80h
