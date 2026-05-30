section .text
    global char_at

char_at:
    test rdx, rdx
    jz out_of_bounds

    cmp rdx, rsi
    ja out_of_bounds

    lea rax, [rdi + rdx - 1]
    mov rdx, 1
    ret
out_of_bounds:
    xor rax, rax
    xor rdx, rdx
    ret