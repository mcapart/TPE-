#include <lib.h>
#include <stdint.h>

void printTime(){
    uint64_t h;
    uint64_t m;
    uint64_t s;
    getHour(&h);
    getMin(&m);
    getSec(&s);
    h-=3;
    char * ch;
    char * cm;
    char * cs;
    numToChar(h, ch);
    print(ch);
    print(":");
    numToChar(m, cm);
    numToChar(s, cs);
   
    print(cm);
    print(":");
    print(cs);
    newLine();
   

}

int shell(){
    print("entre al shell");
    newLine();
    printTime();
    print("termine");
    changeApp();
    return 0;
}