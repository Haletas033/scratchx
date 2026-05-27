extern sin

section .rodata
    DEG_TO_RAD dq 0.0174533

section .text
    global scratchx_sin

scratchx_sin:
    sub rsp, 8
    mulsd xmm0, [rel DEG_TO_RAD]
    call sin
    add rsp, 8
    ret