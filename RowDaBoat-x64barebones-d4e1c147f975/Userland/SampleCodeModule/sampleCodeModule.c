/* sampleCodeModule.c */
#include "libasm.h"


char * v = (char*)0xB8000 + 79 * 2;




int main() {
	
	char text[10] = {0};
	start();
	char buffer[70] = {0};
	
	int n = 0;
	while(text[0]!= 10){
		getChar(text);
		if(text[0] == 8){
			n--;
			buffer[n] = 0;
			delete();
		}
		else if(text[0] == -2){
			changeApp();
			n=0;
		}
		
		else
		{
			buffer[n] = text[0];
			n++;
			print(text);
		}
		
		
	}
	print(buffer);

	return 0;

	
	


}