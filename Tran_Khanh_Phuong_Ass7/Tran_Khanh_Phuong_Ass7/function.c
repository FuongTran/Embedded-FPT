#define _CRT_SECURE_NO_DEPRECATE    
/*******************************************************************************
* Includes
*******************************************************************************/

#include "function.h"
#include <stdio.h>

uint8_t assignment4[SIZE] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                              0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                              0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                              0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
uint8_t next[SIZE];
uint8_t head = UNUSED;

/*******************************************************************************
* Function
*******************************************************************************/
void initializeList() {
    for (uint8_t i = 0; i < SIZE; i++) {
        next[i] = UNUSED;
    }
}

void printListSorted() {
    printf("Positions: ");
    uint8_t current = head;
    while (current != UNUSED) {
        printf("%d ", current);
        current = next[current];
    }
    printf("\nValues:    ");
    current = head;
    while (current != UNUSED) {
        printf("%d ", assignment4[current]);
        current = next[current];
    }
    printf("\n");
}

void printArrayUnsorted() {
    printf("Positions: ");
    for (uint8_t i = 0; i < SIZE; i++) {
        if (assignment4[i] != 0xFF) {
            printf("%d ", i);
        }
    }
    printf("\nValues:    ");
    for (uint8_t i = 0; i < SIZE; i++) {
        if (assignment4[i] != 0xFF) {
            printf("%d ", assignment4[i]);
        }
    }
    printf("\n");
}

int8_t findValueIndex(uint8_t value) {
    for (uint8_t i = 0; i < SIZE; i++) {
        if (assignment4[i] == value) {
            return i;
        }
    }
    return -1;
}

void insertValue() {
    uint8_t index;
    uint8_t value;

    printf("Enter index (0-19): ");
    scanf("%hhu", &index);
    if (index >= SIZE) {
        printf("Index out of range!\n");
        return;
    }
    if (assignment4[index] != 0xFF) {
        printf("Index already occupied!\n");
        return;
    }

    printf("Enter value (0-100): ");
    scanf("%hhu", &value);
    if (value > 100) {
        printf("Value out of range!\n");
        return;
    }
    if (findValueIndex(value) != -1) {
        printf("Value already exists in the array!\n");
        return;
    }

    assignment4[index] = value;

    if (head == UNUSED || assignment4[head] > value) {
        next[index] = head;
        head = index;
    }
    else {
        uint8_t current = head;
        while (next[current] != UNUSED && assignment4[next[current]] < value) {
            current = next[current];
        }
        next[index] = next[current];
        next[current] = index;
    }
}

void deleteValue() {
    uint8_t value;
    printf("Enter value to delete (0-100): ");
    scanf("%hhu", &value);
    if (value > 100) {
        printf("Value out of range!\n");
        return;
    }

    int8_t index = findValueIndex(value);
    if (index == -1) {
        printf("Value not found in array!\n");
        return;
    }

    if (head == index) {
        head = next[index];
    }
    else {
        uint8_t current = head;
        while (next[current] != index) {
            current = next[current];
        }
        next[current] = next[index];
    }
    assignment4[index] = 0xFF;
    next[index] = UNUSED;
}

void printMenu() {
    printf("1. Insert value\n");
    printf("2. Delete value\n");
    printf("3. Print values\n");
    printf("4. Exit\n");
}

/*******************************************************************************
* EOF
*******************************************************************************/