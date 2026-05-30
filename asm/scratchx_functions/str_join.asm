extern malloc

section .text
    global str_join

str_join:
    push r12
    push r13
    push r14
    push r15
    push rbx

    mov r12, rdi
    mov r13, rsi
    mov r14, rdx
    mov r15, rcx

    add rsi, rcx
    mov rdi, rsi
    call malloc
    mov rbx, rax

    mov rdi, rax
    mov rsi, r12
    mov rcx, r13
    rep movsb

    mov rsi, r14
    mov rcx, r15
    rep movsb

    mov rax, rbx
    add r13, r15
    mov rdx, r13

    pop rbx
    pop r15
    pop r14
    pop r13
    pop r12

    ret