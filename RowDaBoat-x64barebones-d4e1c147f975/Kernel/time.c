#include <time.h>
#include <naiveConsole.h>

static unsigned long ticks = 0;

void timer_handler() {
	ticks++;
	//if(seconds_elapsed()%5 == 0 && ticks_elapsed()%18 == 0 ){
	//	ncNewline();
	//	ncPrint("ya pasaron 5 sec");
	//}
}

int ticks_elapsed() {
	return ticks;
}

int seconds_elapsed() {
	return ticks / 18;
}
