extern memmem

section .text
    global str_contains

str_contains:
    sub rsp, 8
    call memmem
    add rsp, 8
    test rax, rax
    jz not_found
    mov rax, 1
    ret
not_found:
    xor rax, rax
    ret
