extern atan

section .rodata
    RAD_TO_DEG dq 57.2957795

section .text
    global scratchx_atan

scratchx_atan:
    sub rsp, 8
    call atan
    mulsd xmm0, [rel RAD_TO_DEG]
    add rsp, 8
    ret