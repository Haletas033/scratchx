extern log10

section .text
    global scratchx_log

scratchx_log:
    sub rsp, 8
    call log10
    add rsp, 8
    ret