extern fmod

section .text
    global scratchx_mod

scratchx_mod:
    sub rsp, 8
    call fmod
    add rsp, 8
    ret