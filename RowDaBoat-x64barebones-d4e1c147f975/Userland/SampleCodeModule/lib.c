#include <lib.h>

static void reverse(char * c, int l){
    int start = 0; 
    int end = l -1; 
    while (start < end) 
    { 
        char aux = c[start];
        c[start] = c [end];
        c[end] = aux;
        start++; 
        end--; 
    } 
}

void numToChar(double num, char * c){
    int entera = num;
    double decimal = num - entera;
    int i = 0;
    if(num < 0){
        entera = entera * -1;
        decimal = decimal * -1;
    }
    if(entera == 0){
        c[i] = '0';
        i++;
    }
    for(; i < 99 && entera > 0; i++){
        int valor = entera % 10;
        c[i] = valor + '0';
        entera = entera/10;
    }
    if(num < 0){
        c[i] = '-';
        i++;
    }
    reverse(c,i);
    if(decimal != 0){
        c[i] = '.';
      	i++;
        for(int j = 0;i < 100 && j < 4; i++, j++){
            int aux = decimal * 10;
            c[i] = (aux % 10) + '0';
            decimal = decimal * 10;
        }
    }
    c[i] = 0;
}