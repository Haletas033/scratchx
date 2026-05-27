section .text
    global scratchx_sqrt

scratchx_sqrt:
    sqrtsd xmm0, xmm0
    ret