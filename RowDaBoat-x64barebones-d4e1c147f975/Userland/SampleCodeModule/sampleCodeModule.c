/* sampleCodeModule.c */
#include <lib.h>
#include <calculator.h>
#include <shell.h>

char * v = (char*)0xB8000 + 79 * 2;


int main() {
	

	start();
	int app = 0; 
	
	while(1){
		
		switch (app)
		{
		case 0 : app = calculator();
			break;	
		case 1 : app = shell();
			break;
		default:
			break;
		}
		
		
		
	}

	return 0;

	
	


}