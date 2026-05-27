extern cos

section .rodata
    DEG_TO_RAD dq 0.0174533

section .text
    global scratchx_cos

scratchx_cos:
    sub rsp, 8
    mulsd xmm0, [rel DEG_TO_RAD]
    call cos
    add rsp, 8
    ret