#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdint.h>

#define ARRAY_SIZE 100

extern uint8_t array[ARRAY_SIZE];
extern int array_length;


void clearArray();
void printArray();
void insertElement(int value, int position);
void deleteElement(int position);
void sortArrayUp();
void sortArrayDown();
int searchElement(int value);
int findMax();
int findMin();

#endif /* FUNCTION_H */ 
