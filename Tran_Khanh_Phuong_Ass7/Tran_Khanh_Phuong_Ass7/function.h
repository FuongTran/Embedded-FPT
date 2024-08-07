/*******************************************************************************
* Definitions
*******************************************************************************/

#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdint.h>

#define SIZE 20
#define UNUSED 0xFF


/*******************************************************************************
* Extern variable
*******************************************************************************/
extern uint8_t assignment4[SIZE];
extern uint8_t next[SIZE];
extern uint8_t head;

/*******************************************************************************
* Prorotype
*******************************************************************************/

void initializeList();
/*
*   @brief: Make a Array with Node type with value = 0xFF & next = 0xFF
*/

void insertValue();
/*
*   @brief: Insert Value to Array & Sort LinkedList
*   @param[in]: index of Num & Value
*/

void deleteValue();
/*
*   @brief: Delete Value from Array & LinkedList
*   @param[in]: Value
*/

void printArrayUnsorted();
/*
*   @brief: printArray  Unsort
*
*/

void printListSorted();
/*
*   @brief: printArray Sorted
*
*/

void printMenu();
/*
*   @brief: print menu for user
*/

#endif // FUNCTION_H
/*******************************************************************************
* EOF
*******************************************************************************/