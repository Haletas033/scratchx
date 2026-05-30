extern drand48
extern lrand48

section .text
    global scratchx_random

scratchx_random:
    cmp rdi, 0
    je int_rand
    jne double_rand
int_rand:
    push r12
    push r13
    sub rsp, 8

    cvtsd2si r12, xmm0
    cvtsd2si r13, xmm1

    call lrand48

    sub r13, r12
    add r13, 1

    xor rdx, rdx
    idiv r13

    add rdx, r12

    mov rax, rdx
    cvtsi2sd xmm0, rax

    add rsp, 8
    pop r13
    pop r12

    ret
double_rand:
    push r12
    push r13
    sub rsp, 8

    movq r12, xmm0
    movq r13, xmm1

    call drand48

    movq xmm1, r12
    movq xmm2, r13

    subsd xmm2, xmm1
    mulsd xmm0, xmm2
    addsd xmm0, xmm1

    add rsp, 8
    pop r13
    pop r12

    ret