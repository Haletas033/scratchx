extern strtod
extern malloc
extern free

section .text
    global to_number

to_number:
    cmp rsi, 256
    jl small_string

    jmp heap_string

    ret

small_string:
    sub rsp, 264 ; Create a buffer for the null-terminated string 256 bytes + alignment

    mov rcx, rsi
    mov rdx, rcx ; Save length

    ; Fill the buffer
    mov rsi, rdi
    mov rdi, rsp
    rep movsb

    mov byte [rsp + rdx], 0 ; Null-terminate

    ; Get the double version of the string
    mov rdi, rsp
    xor esi, esi
    call strtod

    ; Cleanup
    add rsp, 264
    ret

heap_string:
    push r12
    push r13
    push r14

    mov r12, rsi ; Save length
    mov r13, rdi ; Save data

    ; Create the buffer for the null-terminated string
    inc rsi
    mov rdi, rsi

    call malloc

    mov r14, rax ; Save the malloced buffer
    mov rdi, rax

    ; Move the string into the buffer
    mov rcx, r12
    mov rsi, r13
    rep movsb

    mov byte [rdi], 0 ; Null-terminate

    ; Get the double version of the string
    mov rdi, r14 ; string
    xor esi, esi ; Endptr
    call strtod

    sub rsp, 16
    movsd [rsp], xmm0 ; Save xmm0 from being clobbered by free
    mov rdi, r14

    ; Clean up
    call free

    movsd xmm0, [rsp]
    add rsp, 16

    pop r12
    pop r13
    pop r14

    ret