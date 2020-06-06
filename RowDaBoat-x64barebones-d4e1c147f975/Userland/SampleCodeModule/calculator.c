#include <calculator.h>
#include <lib.h>

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
int CANT_DECIMALES=1000000;

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

static int operate(double num1, double num2, char operator){
    double resp;
    switch (operator){
        case '+':resp = num1 + num2;break;
        case '-':resp = num1 - num2;break;
        case '/':resp = num1 / num2;break;
        case '*':resp = num1 * num2;break;
        default: break;//cambiar
    }
    return (int) (resp * CANT_DECIMALES); 
}

//devuelve 1 si c es un numero, 0 si no
static int is_number(char c){
    if(c < '0' || c > '9'){
        return 0;
    }
    return 1;
}

static int numChar(char * c, int entero, int decimal){
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

    for(double aux = 10; i- entero < decimal && i < entero + 6; i++){
        if(!is_number(c[i])){
            return -2;//cambiar
        }
        resp = resp + (c[i] - '0') / aux;
        aux = aux * 10;
    }
    return (int) (resp * CANT_DECIMALES); 
}

static int evaluator(char * c){
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
                num[itNum] = (double) numChar(resp,cantEnt,cantDec) / CANT_DECIMALES;
            }
            else{
                num[itNum] = -1 * ((double) numChar(resp,cantEnt,cantDec) / CANT_DECIMALES);
            }
            itNum++;
            for(int i =0;i<itResp;i++){
                resp[i] = 0;
            }
            itResp = 0;
           

                
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
                    double resp = (double) operate(num[itNum-2],num[itNum-1],op[itOp-1]) / CANT_DECIMALES;
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
        else if(c[i] == '='){
            i--;
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
        double resp = (double) operate(num[itNum-2],num[itNum-1],op[itOp-1]) / CANT_DECIMALES;
        num[itNum-2] = resp;
        itOp--;
        itNum--;
    }
    if(itNum > 1){
        return -10; //cambiar
    }

   
    int v = num[0] * CANT_DECIMALES;
   
   
    return v;
}

static char buffer[70] = {0};
static int n = 0;
int calculator(){

	char text[10] = {0};
	
    while(text[0]!= '='){
        getChar(text);
        if(text[0] == 8 && n > 0){
            n--;
            buffer[n] = 0;
            deleteChar();
        }
        else if(text[0] == -2){
            changeApp();
            
            return 1;
        }
        
        else if(is_number(text[0]) || numOp(text[0]) != -1 || text[0] == ' ' || text[0] == '=')
        {
            buffer[n] = text[0];
            n++;
            print(text);
        }
    }
    double v = evaluator(buffer) / 1000000.0;
    char t[40];
    numToChar(v, t);
    //print(buffer);
    print(" ");
    print(t);
    buffer[n] = 0;
    n = 0;
    newLine();
    return 0;
    
}

static void reStart(){
    buffer[n] = 0;
    n = 0;
}
