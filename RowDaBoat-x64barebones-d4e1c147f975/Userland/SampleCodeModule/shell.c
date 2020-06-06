#include <lib.h>
#include <stdint.h>
#include <shell.h>

static void printTime(){
    uint64_t h;
    uint64_t m;
    uint64_t s;
    getHour(&h);
    getMin(&m);
    getSec(&s);
    if(h < 3){
        switch (h)
        {
        case 0: h = 21;
            break;
        case 1: h = 22;
            break;
        case 2: h = 23;
            break;
        case 3: h = 24;
            break;
        
        default:
            break;
        }
    }
    else
    {
        h-=3;
    }
    char ch[3];
    char cm[3];
    char cs[3];
    numToChar(h, ch);
    numToChar(m, cm);
    numToChar(s, cs);
    print(ch);
    print(":");
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