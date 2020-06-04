#include <stdint.h>
#include <video_driver.h>
#include <keyboardDriver.h> 



void sys_read(uint64_t rdi, char * rsi, uint64_t rdx);//rax = 1 => syscall read 
void sys_write(uint64_t rdi, char * rsi, uint64_t rdx);//rax = 2 => syscall wirte
void sys_changeApp();//rax = 3 => syscall changeApp
void sys_start(); //rax = 4 => syscall start
void sys_delete(); //rax = 5 => syscall delete

void systemCall(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rax){
    switch(rax){
        case 1: sys_read(rdi, (char *) rsi, rdx);
                break;
        case 2: sys_write(rdi,(char *) rsi, rdx);
                break;
        case 3: sys_changeApp();  
                break;
        case 4: sys_start();
                break;
        case 5: sys_delete();
                break;

    }
}


void sys_read(uint64_t rdi, char * rsi, uint64_t rdx){
    getNChar(rsi, rdx);

}
void sys_write(uint64_t rdi, char * rsi, uint64_t rdx){
    int color[3] = {125, 125, 125};
    writeWord(rsi, 1.5, color);

}
void sys_changeApp(){
    changeScreen();
    changeBuffer();
}
void sys_start(){
    screenLine();
}
void sys_delete(){
    deleteChar();
}
