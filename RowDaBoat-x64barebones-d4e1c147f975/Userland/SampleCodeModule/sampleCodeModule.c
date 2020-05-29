/* sampleCodeModule.c */
#include "video_driver.h"


char * v = (char*)0xB8000 + 79 * 2;

static int var1 = 0;
static int var2 = 0;


int main() {
	//All the following code may be removed 
	//*v = 'X';
	//*(v+1) = 0x74;

	//Test if BSS is properly set up
	//if (var1 == 0 && var2 == 0)
	//	return 0xDEADC0DE;

	//return 0xDEADBEEF;
	screenLine();
	int color[2] = {0, 255};
	writeWord("Trabajo Practico Especial 2020:", 1.5, color);
	writeWord("hola1", 1.5, color);
	changeScreen();
	writeWord("hola2", 1.5, color);
	newLine();
	writeWord("mica", 1.5, color);
	newLine();
	writeWord("hola1", 1.5, color);
	newLine();
}