/*===Author: Tran Khanh Phuong===*/
#define _CRT_SECURE_NO_DEPRECATE

/*******************************************************************************
* Include
*******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "function.h"

/*******************************************************************************
* Function Prototypes
*******************************************************************************/
void display_menu(void);

/*******************************************************************************
* Main Function
*******************************************************************************/
int main() {
    uint8_t choice;
    uint8_t id;
    float32 MathScore;
    uint8_t name[50];

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // Consume newline character left in buffer

        switch (choice) {
        case 1:
            input_full_name(name);
            printf("Enter student's ID: ");
            scanf("%d", &id);
            printf("Enter student's Math score: ");
            scanf("%f", &MathScore);
            add_student(name, id, MathScore);
            break;

        case 2:
            printf("Enter student's ID to remove: ");
            scanf("%hhu", &id);
            remove_student(id);
            break;

        case 3:
            printf("Enter student's ID to find: ");
            scanf("%hhu", &id);
            Student* student = find_student(id);
            print_student(student);
            break;

        case 4:
            print_all_students();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid choice. Please try again.\n");

        }
    }

    return 0;
}

/*******************************************************************************
* Display Menu Function
*******************************************************************************/
void display_menu(void) {
    printf("\nStudent Management System\n");
    printf("1. Add student\n");
    printf("2. Remove student\n");
    printf("3. Find student\n");
    printf("4. Display all students\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

/*******************************************************************************
* EOF
*******************************************************************************/
