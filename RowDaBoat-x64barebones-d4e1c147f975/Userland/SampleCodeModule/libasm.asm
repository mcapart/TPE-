GLOBAL print 
GLOBAL getChar 
GLOBAL changeApp
EXTERN int_80h
section .text

; void print(char *)
print:
    push rbp
    mov rbp, rsp

    mov rax, 2
    mov rsi, rdi
    call int_80h
    
    mov rsp, rbp
    pop rbp
    ret
           
;void getChar(char *);
getChar:
    push rbp
    mov rbp, rsp

    mov rax, 1
    mov rsi, rdi 
    mov rdx, 1   
    call int_80h

    mov rsp, rbp
    pop rbp
    ret

;void changeApp();
    push rbp
    mov rbp, rsp

    mov rax, 3  
    call int_80h

    mov rsp, rbp
    pop rbp
    ret



