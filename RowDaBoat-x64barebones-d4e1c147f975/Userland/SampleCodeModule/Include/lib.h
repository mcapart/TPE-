#ifndef LIB_H
#define LIB_H

#include <stdint.h>


void print(char * c);

void getChar(char * c);

void changeApp();

void start();
 
void deleteChar();

void newLine();

void numToChar(double num, char * c);

void getHour(uint64_t * v);

void getMin(uint64_t * v);

void getSec(uint64_t * v);

void getCpuVendor(char * c, uint32_t * v);

void getTemp(uint64_t * temp);

#endif