extern exp

section .text
    global scratchx_exp

scratchx_exp:
    sub rsp, 8
    call exp
    add rsp, 8
    ret