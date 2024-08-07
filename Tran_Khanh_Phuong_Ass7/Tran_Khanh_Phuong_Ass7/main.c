/*===Author: Tran Khanh Phuong===*/
#define _CRT_SECURE_NO_DEPRECATE

/*******************************************************************************
* Include
*******************************************************************************/
#include "function.h"
#include <stdio.h>

/*******************************************************************************
* Main Function
*******************************************************************************/
int main() {
    initializeList();
    uint8_t choice;
    while (1) {
        printMenu();
        printf("Enter choice: ");
        scanf("%hhu", &choice);
        system("cls");
        switch (choice) {
        case 1:
            insertValue();
            break;
        case 2:
            deleteValue();
            break;
        case 3:
            printf("1. Print unsorted\n");
            printf("2. Print sorted\n");
            uint8_t subChoice;
            printf("Enter choice: ");
            scanf("%hhu", &subChoice);
            if (subChoice == 1) {
                printArrayUnsorted();
            }
            else if (subChoice == 2) {
                printListSorted();
            }
            else {
                printf("Invalid choice!\n");
            }
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

/*******************************************************************************
* EOF
*******************************************************************************/