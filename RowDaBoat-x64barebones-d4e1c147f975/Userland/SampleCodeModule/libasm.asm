GLOBAL print 
GLOBAL getChar 
GLOBAL changeApp
GLOBAL start
GLOBAL deleteChar
GLOBAL newLine
GLOBAL getHour
GLOBAL getMin
GLOBAL getSec
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

;void deleteChar();
deleteChar:
    push rbp
    mov rbp, rsp

    mov rax, 5  
    int 80h

    mov rsp, rbp
    pop rbp
    ret

;void newLine();
newLine:
    push rbp
    mov rbp, rsp

    mov rax, 6  
    int 80h

    mov rsp, rbp
    pop rbp
    ret

;void getHour(uint64_t * v);
getHour:
    push rbp
    mov rbp, rsp

    mov rax, 7  
    int 80h

    mov rsp, rbp
    pop rbp
    ret

;void getMin(uint64_t * v);
getMin:
    push rbp
    mov rbp, rsp

    mov rax, 8 
    int 80h

    mov rsp, rbp
    pop rbp
    ret

;void getSec(uint64_t * v);
getSec:
  push rbp
    mov rbp, rsp

    mov rax, 9  
    int 80h

    mov rsp, rbp
    pop rbp
    ret
