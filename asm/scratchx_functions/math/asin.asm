extern asin

section .rodata
    RAD_TO_DEG dq 57.2957795

section .text
    global scratchx_asin

scratchx_asin:
    sub rsp, 8
    call asin
    mulsd xmm0, [rel RAD_TO_DEG]
    add rsp, 8
    ret