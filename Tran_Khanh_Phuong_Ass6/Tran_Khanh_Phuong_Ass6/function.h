/*******************************************************************************
* Define
*******************************************************************************/
#ifndef FUNCTION_H
#define FUNCTION_H

/*******************************************************************************
* Include
*******************************************************************************/
#include <stdint.h>

/*******************************************************************************
* Custom Type Definition
*******************************************************************************/
typedef float float32;

/*******************************************************************************
* Prototype
*******************************************************************************/
typedef struct Student {
    uint8_t name[50];
    uint8_t id;
    float32 MathScore;
    struct Student* next;
} Student;

Student* create_student(uint8_t* name, uint8_t id, float32 MathScore);
void add_student(uint8_t* name, uint8_t id, float32 MathScore);
void remove_student(uint8_t id);
Student* find_student(uint8_t id);
void print_student(Student* student);
void print_all_students(void);
void input_full_name(uint8_t* fullName);

#endif // FUNCTION_H

/*******************************************************************************
* EOF
*******************************************************************************/
