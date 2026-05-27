extern log

section .text
    global scratchx_ln

scratchx_ln:
    sub rsp, 8
    call log
    add rsp, 8
    ret