section .rodata
    align 16
    SIGN_MASK dq 0x7FFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF

section .text
    global scratchx_abs

scratchx_abs:
    andpd xmm0, [rel SIGN_MASK]
    ret