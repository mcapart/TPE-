GLOBAL getTemperature

section .text

getTemperature:
    push rbp
    mov rbp, rsp

    push rcx
    push rdx
    push rax

    mov ecx, 418
    RDMSR

    mov [rdi] , edx
    mov [rdi + 4] , eax

    mov ecx, 412
    RDMSR

    mov [rsi], edx
    mov [rsi + 4] , eax

    pop rax
    pop rdx
    pop rcx
    
	mov rsp, rbp
	pop rbp
    ret



