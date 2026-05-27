extern tan

section .rodata
    DEG_TO_RAD dq 0.0174533

section .text
    global scratchx_tan

scratchx_tan:
    sub rsp, 8
    mulsd xmm0, [rel DEG_TO_RAD]
    call tan
    add rsp, 8
    ret