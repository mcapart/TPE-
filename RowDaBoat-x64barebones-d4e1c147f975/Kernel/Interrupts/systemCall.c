#include <stdint.h>
#include <video_driver.h>
#include <keyboardDriver.h> 
#include <lib.h>


extern uint8_t getHou();
extern uint8_t getMin();
extern uint8_t getSec();



void sys_read(uint64_t rdi, char * rsi, uint64_t rdx);//rax = 1 => syscall read 
void sys_write(uint64_t rdi, char * rsi, uint64_t rdx);//rax = 2 => syscall wirte
void sys_changeApp();//rax = 3 => syscall changeApp
void sys_start(); //rax = 4 => syscall start
void sys_delete(); //rax = 5 => syscall delete
void sys_newLine(); //rax = 6 => syscall newLine
void sys_currentHour(uint64_t * value);
void sys_currentMin(uint64_t * value);
void sys_currentSec(uint64_t * value);
void sys_cpuInfo(char * vendor, uint32_t * version); //rax = 10 => syscall cpuInfo
void sys_getTemperature(uint64_t * targetTemp, uint64_t * statusTemp ); // rax = 11 => syscall temperature
void sys_saveReg(); 
void sys_getReg(uint64_t * v);

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
        case 6: sys_newLine();
                break;
        case 7: sys_currentHour((uint64_t *) rdi);
                break;
        case 8: sys_currentMin((uint64_t *) rdi);
                break;
        case 9: sys_currentSec((uint64_t *) rdi);
                break;
        case 10: sys_cpuInfo((char *) rdi, (uint32_t *) rsi);
                break;
        case 11: sys_getTemperature((uint64_t *) rdi, (uint64_t *) rsi);
                break;
        case 12: sys_saveReg();
                break;
        case 13: sys_getReg((uint64_t *) rdi);
                break;
    }
}


void sys_read(uint64_t rdi, char * rsi, uint64_t rdx){
    getNChar(rsi, rdx);

}
void sys_write(uint64_t rdi, char * rsi, uint64_t rdx){
    int color[3] = {255, 255, 255};
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

void sys_newLine(){
    newLine();
}

void sys_currentHour(uint64_t * value){
    value[0] = getHou();
}

void sys_currentMin(uint64_t * value){
    value[0] = getMin();
}

void sys_currentSec(uint64_t  * value){
    value[0] = getSec();
}
            
void sys_cpuInfo(char * vendor , uint32_t * version){
    cpuVendor(vendor);
    cpuVersion(version);
}

void sys_getTemperature(uint64_t * targetTemp, uint64_t * statusTemp){
    getTemperature(targetTemp, statusTemp);
}

void sys_saveReg(){
    saveReg();
}


void sys_getReg(uint64_t * v){
  getReg(v);
}