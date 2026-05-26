extern snprintf
extern malloc

section .rodata
    format db "%g", 0

section .text
    global to_string

to_string:
    push r12
    push r13
    sub rsp, 8

    movq r12, xmm0

    mov rdi, 24
    call malloc
    mov r13, rax

    mov rdi, r13
    mov rsi, 24
    lea rdx, [rel format]
    movq xmm0, r12
    xor eax, eax
    mov al, 1
    call snprintf

    mov rdx, rax
    mov rax, r13

    add rsp, 8
    pop r13
    pop r12

    ret