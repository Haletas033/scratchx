extern acos

section .rodata
    RAD_TO_DEG dq 57.2957795

section .text
    global scratchx_acos

scratchx_acos:
    sub rsp, 8
    call acos
    mulsd xmm0, [rel RAD_TO_DEG]
    add rsp, 8
    ret