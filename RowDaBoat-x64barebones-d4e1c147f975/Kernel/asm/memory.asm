GLOBAL saveMemory
GLOBAL getMemory

section .text

saveMemory:
    push rbp
    mov rbp, rsp

    push rcx
    mov rcx, 0

ciclo:   cmp rcx, 32
    je end 
    mov rax, [rdi + rcx]
    mov [v + rcx], rax
    inc rcx
    jmp ciclo

end: pop rcx
    
    mov rsp, rbp
    pop rbp
    ret


getMemory:
 push rbp
    mov rbp, rsp

    push rcx
    mov rcx, 0

ciclo2:   cmp rcx, 32
    je end2
    mov rax, [v + rcx]
    mov [rdi + rcx], rax
    inc rcx
    jmp ciclo2

end2: pop rcx
    
    mov rsp, rbp
    pop rbp
    ret

section .bss
v resb 32