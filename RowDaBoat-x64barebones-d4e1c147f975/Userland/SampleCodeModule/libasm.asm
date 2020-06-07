GLOBAL print 
GLOBAL getChar 
GLOBAL changeApp
GLOBAL start
GLOBAL deleteChar
GLOBAL newLine
GLOBAL getHour
GLOBAL getMin
GLOBAL getSec
GLOBAL getCpuVendor
GLOBAL getTemp
GLOBAL saveReg
GLOBAL getReg
GLOBAL actReg
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

getCpuVendor:
    push rbp
    mov rbp, rsp

    mov rax, 10
    int 80h

    mov rsp, rbp
    pop rbp
    ret

getTemp:
    push rbp
    mov rbp, rsp

    mov rax, 11
    int 80h

    mov rsp, rbp
    pop rbp
    ret

saveReg:
    push rbp
    mov rbp, rsp

    mov rax, 12
    int 80h

    mov rsp, rbp
    pop rbp
    ret

getReg:
    push rbp
    mov rbp, rsp

    mov rax, 13
    int 80h
    
    mov rsp, rbp
    pop rbp
    ret

actReg:
    push rbp
    mov rbp, rsp

    mov rbx, 2
    mov rcx, 3
    mov rdx, 4

    mov rdi, 5
    mov rsi, 6
    mov r8, 7
    mov r9, 8
    mov r10, 9
    mov r11, 10
	mov r12, 11
	mov r13, 12
	mov r14, 13
	mov r15, 14
    mov rax, 1

    mov rsp, rbp
    pop rbp
    ret
