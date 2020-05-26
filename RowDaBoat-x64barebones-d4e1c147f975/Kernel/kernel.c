#include <stdint.h>
#include <string.h>
#include <lib.h>
#include <moduleLoader.h>
#include <naiveConsole.h>
#include <idtLoader.h>
#include <keyboardDriver.h>
#include "video_driver.h"

extern uint8_t text;
extern uint8_t rodata;
extern uint8_t data;
extern uint8_t bss;
extern uint8_t endOfKernelBinary;
extern uint8_t endOfKernel;

static const uint64_t PageSize = 0x1000;

static void * const sampleCodeModuleAddress = (void*)0x400000;
static void * const sampleDataModuleAddress = (void*)0x500000;

typedef int (*EntryPoint)();


void clearBSS(void * bssAddress, uint64_t bssSize)
{
	memset(bssAddress, 0, bssSize);
}

void * getStackBase()
{
	return (void*)(
		(uint64_t)&endOfKernel
		+ PageSize * 8				//The size of the stack itself, 32KiB
		- sizeof(uint64_t)			//Begin at the top of the stack
	);
}

void * initializeKernelBinary()
{
	char buffer[10];

	ncPrint("[x64BareBones]");
	ncNewline();

	ncPrint("CPU Vendor:");
	ncPrint(cpuVendor(buffer));
	ncNewline();

	ncPrint("[Loading modules]");
	ncNewline();
	void * moduleAddresses[] = {
		sampleCodeModuleAddress,
		sampleDataModuleAddress
	};

	loadModules(&endOfKernelBinary, moduleAddresses);
	ncPrint("[Done]");
	ncNewline();
	ncNewline();

	ncPrint("[Initializing kernel's binary]");
	ncNewline();

	clearBSS(&bss, &endOfKernel - &bss);

	ncPrint("  text: 0x");
	ncPrintHex((uint64_t)&text);
	ncNewline();
	ncPrint("  rodata: 0x");
	ncPrintHex((uint64_t)&rodata);
	ncNewline();
	ncPrint("  data: 0x");
	ncPrintHex((uint64_t)&data);
	ncNewline();
	ncPrint("  bss: 0x");
	ncPrintHex((uint64_t)&bss);
	ncNewline();

	ncPrint("[Done]");
	ncNewline();
	ncNewline();
	return getStackBase();
}

void printChar(char c){
	static int i = 0;
	char * screen = 0xb8000;
	screen[i++] = c;
	screen[i++] = 2;
}

void printFrase(char * s){
	for(int i = 0; s[i]!= 0;i++){
		printChar(s[i]);
	}
}

int main()
{	
	//load_idt();
	
	ncPrint("[Kernel Main]");
	ncNewline();
	ncPrint("  Sample code module at 0x");
	ncPrintHex((uint64_t)sampleCodeModuleAddress);
	ncNewline();
	ncPrint("  Calling the sample code module returned: ");
	ncPrintHex(((EntryPoint)sampleCodeModuleAddress)());
	ncNewline();
	ncNewline();

	ncPrint("  Sample data module at 0x");
	ncPrintHex((uint64_t)sampleDataModuleAddress);
	ncNewline();
	ncPrint("  Sample data module contents: ");
	ncPrint((char*)sampleDataModuleAddress);
	ncNewline();

	ncPrint("[Finished]");

	ncClear();


	//ncNewline();
	//printChar('a');
	//printChar('b');
	//printChar('c');
	//ncNewline();
	//printFrase("Arquitecturas de las Computadoras");
	//ncNewline();
	//currentTime();
	//ncNewline;
	//poolingKeyboard();


	//while (1);
	int color[2] = {0, 255};
	writeWord("   Trabajo Practico Especial 2020:", 1.5, color);
	newLine();
	writeWord("hola1", 1.5, color);
	newLine();
	writeWord("hola2", 1.5, color);
	writeWord("mica", 1.5, color);
	deleteLine();
	writeWord("ssssssssss", 1.5, color);
	//writeWord("18 I cloned a repository to my desktop machine using git clone sshurl. As expected, this created a folder in my desktop.Now, instead of a single file, I want to push a whole folder into git. For example, the folder that I cloned is named project_iphone. Now I add another folder called my_project into project_iphone. The my_project folder contains lots of files and folders as well.My question is, how should I push my_project folder to the server?Step-by-step instructions would be helpful.Thank You.", 4, color);
	
	return 0;
}
