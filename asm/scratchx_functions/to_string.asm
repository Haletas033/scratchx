extern snprintf
extern malloc

section .rodata
    format db "%g", 0

section .text
    global to_string

to_string:
    push r12
    push r13
    sub rsp, 8

    movq r12, xmm0 ; Save the double

    ; Allocate a 24 byte buffer for the string version of the double
    mov rdi, 24
    call malloc
    mov r13, rax ; Save the buffer

    ; Gete the string version of the double
    mov rdi, r13
    mov rsi, 24
    lea rdx, [rel format]
    movq xmm0, r12
    xor eax, eax
    mov al, 1
    call snprintf

    ; Prepare return values
    mov rdx, rax ; length
    mov rax, r13 ; string buffer

    ; Cleanup
    add rsp, 8
    pop r13
    pop r12

    ret