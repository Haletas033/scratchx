extern strtod
extern malloc
extern free

section .text
    global to_number

to_number:
    cmp rsi, 256
    jl small_string

    jmp heap_string

    ret

small_string:
    sub rsp, 264
    mov rcx, rsi
    mov rdx, rcx

    mov rsi, rdi
    mov rdi, rsp
    rep movsb

    mov byte [rsp + rdx], 0

    mov rdi, rsp
    xor esi, esi
    call strtod

    add rsp, 264
    ret

heap_string:
    push r12
    push r13
    push r14

    mov r12, rsi
    mov r13, rdi

    inc rsi
    mov rdi, rsi

    call malloc

    mov r14, rax
    mov rdi, rax

    mov rcx, r12
    mov rsi, r13
    rep movsb

    mov byte [rdi], 0
    mov rdi, r14
    xor esi, esi
    call strtod

    sub rsp, 16
    movsd [rsp], xmm0

    mov rdi, r14
    call free

    movsd xmm0, [rsp]
    add rsp, 16

    pop r12
    pop r13
    pop r14

    ret