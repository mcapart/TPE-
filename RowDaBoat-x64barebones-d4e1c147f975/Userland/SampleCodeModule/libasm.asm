GLOBAL print 
GLOBAL getChar 
GLOBAL changeApp
GLOBAL start
section .text

; void print(char *)
print:
    push rbp
    mov rbp, rsp

    mov rax, 2
    mov rsi, rdi
    int 80h
    
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
    int 80h

    mov rsp, rbp
    pop rbp
    ret

;void changeApp();
changeApp:
    push rbp
    mov rbp, rsp

    mov rax, 3  
    int 80h

    mov rsp, rbp
    pop rbp
    ret
;void start();
start:
    push rbp
    mov rbp, rsp

    mov rax, 4  
    int 80h

    mov rsp, rbp
    pop rbp
    ret



