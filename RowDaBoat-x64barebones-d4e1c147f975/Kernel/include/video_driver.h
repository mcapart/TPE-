#ifndef _VIDEO_DRIVER_H_
#define _VIDEO_DRIVER_H_

int writePixel(int x, int y, double size, int color[3]);

void writeChar(char c,int x,int y,double size, int color[3]);

void writeWord(char * c,double size, int color[3]);

void newLine();

void clear();

void deleteChar();

void deleteLine();


#endif