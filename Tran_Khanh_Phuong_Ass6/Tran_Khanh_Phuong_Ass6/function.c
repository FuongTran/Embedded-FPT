#define _CRT_SECURE_NO_DEPRECATE

/*******************************************************************************
* Include
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "function.h"

/*******************************************************************************
* Global Variables
*******************************************************************************/
Student* head = NULL;

/*******************************************************************************
* Function Definitions
*******************************************************************************/
Student* create_student(uint8_t* name, uint8_t id, float32 MathScore) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    if (new_student != NULL) {
        strcpy((char*)new_student->name, (char*)name);
        new_student->id = id;
        new_student->MathScore = MathScore;
        new_student->next = NULL;
    }
    else {
        printf("-----Error: Memory allocation failed-----\n");
    }
    return new_student;
}

void add_student(uint8_t* name, uint8_t id, float32 MathScore) {
    Student* new_student = NULL;
    if (find_student(id) == NULL) {
        new_student = create_student(name, id, MathScore);
        if (new_student != NULL) {
            new_student->next = head;
            head = new_student;
            printf("-----Student added successfully-----\n");
        }
    }
    else {
        printf("-----Student already exists with ID: %u-----\n", id);
    }
}

void remove_student(uint8_t id) {
    Student* temp = head;
    Student* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL) {
            head = temp->next;
        }
        else {
            prev->next = temp->next;
        }
        free(temp);
        printf("-----Student removed successfully.-----\n");
    }
    else {
        printf("-----Student not found with ID: %u-----\n", id);
    }
}

Student* find_student(uint8_t id) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void print_student(Student* student) {
    if (student != NULL) {
        printf("-----Name: %s\n", student->name);
        printf("-----ID: %u\n", student->id);
        printf("-----Math Score: %.2f\n", student->MathScore);
    }
    else {
        printf("-----Student not found.\n");
    }
}

void print_all_students(void) {
    Student* temp = head;
    while (temp != NULL) {
        print_student(temp);
        temp = temp->next;
    }
}

void input_full_name(uint8_t* fullName) {
    printf("Enter full name: ");
    fgets((char*)fullName, 50, stdin);
    // Remove newline character at the end of the string
    fullName[strcspn((char*)fullName, "\n")] = 0;
}

/*******************************************************************************
* EOF
*******************************************************************************/
