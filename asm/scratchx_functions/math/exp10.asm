extern exp10

section .text
    global scratchx_exp10

scratchx_exp10:
    sub rsp, 8
    call exp10
    add rsp, 8
    ret