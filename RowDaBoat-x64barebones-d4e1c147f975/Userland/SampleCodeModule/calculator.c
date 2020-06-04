#include <calculator.h>

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

char * numToChar(double num, char * c){
    int entera = num;
    double decimal = num - entera;
    int i = 0;
    if(num < 0){
        entera = entera * -1;
        decimal = decimal * -1;
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
        for(int j = 0;i < 100 && j < 8; i++, j++){
            int aux = decimal * 10;
            c[i] = (aux % 10) + '0';
            decimal = decimal * 10;
        }
    }
  	c[i] = 0;
    return c;
}

static int numOp(char c){
    switch (c)
    {
    case '+':
        return 0;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 3;
    case '(':
        return 4;
    case ')':
        return 5;
    default:
        return -1;
    }
}

static int precedenceMatriz[5][6]={
                {1, 1,0,0,0,1},
                {1,1,0,0,0,1},
                {1,1,1,1,0,1},
                {1,1,1,1,0,1},
                {0,0,0,0,0,0}
        };


static int getPrecendence(char tope,char current){
    int topeIndex, currentIndex;
    topeIndex = numOp(tope);
    currentIndex = numOp(current);
    if (topeIndex == -1 || currentIndex == -1)
    {
        return -1;
    }
    return precedenceMatriz[topeIndex][currentIndex];
}

static double operate(double num1, double num2, char operator){
    double resp;
    switch (operator){
        case '+':resp = num1 + num2;break;
        case '-':resp = num1 - num2;break;
        case '/':resp = num1 / num2;break;
        case '*':resp = num1 * num2;break;
        default: break;//cambiar
    }
    return resp;
}

//devuelve 1 si c es un numero, 0 si no
static int is_number(char c){
    if(c < '0' || c > '9'){
        return 0;
    }
    return 1;
}

static double numChar(char * c, int entero, int decimal){
    double resp = 0;
    int i = 0;
    for(; i < entero; i++)
    {
        if(!is_number(c[i])){
            return -1;//cambiar
        }
        resp += c[i] - '0';
        resp = resp * 10;
    }

    resp = resp / 10;

    for(double aux = 10; i- entero < decimal && i < entero + 4; i++){
        if(!is_number(c[i])){
            return -2;//cambiar
        }
        resp = resp + (c[i] - '0') / aux;
        aux = aux * 10;
    }
    return resp;
}

double calculator(char * c){
    char op[100]= {0};
    int itOp = 0;
    double num[100]= {0};
    int itNum = 0;
    for(int i = 0; c[i] != '='; i++){
        while(c[i] == ' '){
            i++;
        }
        if(is_number(c[i]) || (numOp(c[i])== 1 && is_number(c[i+1]))){
            int punto = 0;
            char resp[20];
            int itResp = 0;
            int cantEnt = 0;
            int cantDec = 0;
            int negativo = 0;
            if(c[i] == '-'){
                negativo = 1;
                i++;
            }
            while(c[i] != ' '){
                if(is_number(c[i])){
                    resp[itResp] = c[i];
                    if(punto){
                        cantDec++;
                    }
                    else{
                        cantEnt++;
                    }
                    itResp++;
                }
                else if(c[i] == '.' && !punto){
                    punto = 1;
                }
                else{
                    return -3;//cambiar
                }
                i++;
            }
           if(!negativo){
                    num[itNum] = numChar(resp,cantEnt,cantDec);
                }
                else{
                    num[itNum] = -1 * numChar(resp,cantEnt,cantDec);
                }
                itNum++;
        }
        else if(numOp(c[i]) != -1){
            if(c[i+1] != ' '){
                return -4; //cambiar
            }
            if(itOp == 0){
                op[itOp] = c[i];
                itOp++;
            }
            else
            {
                while(itOp != 0 && getPrecendence(op[itOp-1], c[i])){
                    if(itNum < 2){
                        return -5; //cambiar
                    }
                    double resp = operate(num[itNum-2],num[itNum-1],op[itOp-1]);
                    num[itNum-2] = resp;
                    itOp--;
                    itNum--;
                }
                if(c[i] == ')'){
                    if(itOp == 0 || op[itOp-1] != '('){
                        return -6;//cambiar
                    }
                    itOp--;
                }
                else
                {
                    op[itOp++] = c[i];
                }
            }

        }
        else{
            return -7;//cambiar
        }
    }
    while(itOp > 0){
        if(op[itOp-1] == '('){
            return -8;//cambiar
        }
         if(itNum < 2){
            return -9; //cambiar
        }
        double resp = operate(num[itNum-2],num[itNum-1],op[itOp-1]);
        num[itNum-2] = resp;
        itOp--;
        itNum--;
    }
    if(itNum > 1){
        return -10; //cambiar
    }
  	
    return num[0];
}
