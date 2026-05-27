section .text
    global scratchx_round
    global scratchx_floor
    global scratchx_ceiling

scratchx_round:
    roundsd xmm0, xmm0, 0
    ret

scratchx_floor:
    roundsd xmm0, xmm0, 1
    ret

scratchx_ceiling:
    roundsd xmm0, xmm0, 2
    ret