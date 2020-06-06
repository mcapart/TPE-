#include <lib.h>
#include <stdint.h>
#include <shell.h>
#define CANT_FUNC 2

char fun[CANT_FUNC][20] = {"get time","get cpu info"};
static char buffer[70] = {0};
static int n = 0;

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

static void cpuInfo(){
    char text[70];
    char text2[70];
    uint32_t num;
    getCpuVendor(text, &num);
    int aux = (num | 0x78) / 8;
    numToChar(aux, text2);
    print(text);
    newLine();
    print(text2);
    newLine();
}

int strComp(char * c1, char * c2){
    int i = 0;
    for(; c1[i] != 0 && c2[i] != 0; i++){
        if(c1[i] != c2[i]){
            return c1[i] - c2[i];
        }
    }
    if (c1[i])
    {
        return 1;
    }
    if (c2[i])
    {
        return -1;
    }
    return 0;
}

int getFunction(char * c){
    for(int i = 0; i < CANT_FUNC; i++){
        if(strComp(c,fun[i]) == 0){
            newLine();
            return i;
        }
    }
    return -1;
}

int startFunction(char * c){
    int i = getFunction(c);
    switch (i)
    {
    case 0: printTime();
            return 1;
    case 1: cpuInfo();
            return 1;
    default:
        return 0;
    }
}


int shell(){
    char text[10] = {0};
    while(text[0]!= 10 && n < 70){
        getChar(text);
        if(text[0] == 8 && n > 0){
            n--;
            buffer[n] = 0;
            deleteChar();
        }
        else if(text[0] == -2){
            changeApp();
            return 0;
        }
        else
        {
            buffer[n] = text[0];
            n++;
            print(text);
        }
    }
    newLine();
	buffer[n-1] = 0;
    int flag = startFunction(buffer);
    if(!flag){
        print("no existe pa");
        newLine();
    }
    n = 0;
    buffer[0] = 0;
    return 1;
}

