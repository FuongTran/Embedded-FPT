/*===Author: Tran Khanh Phuong===*/
#define _CRT_SECURE_NO_DEPRECATE

/*******************************************************************************
* Include
*******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>

/*******************************************************************************
* Prototype
*******************************************************************************/

/*
    @brief: this funtion is how run the program
    @param[in]: none
    @param[out]: none
    @return: none
*/
void help();

/*
    @brief: this funtion is check prime number
    @param[in]: number to check
    @param[out]: none
    @return: True or False
*/
bool is_prime(uint32_t num);

/*******************************************************************************
* Function
*******************************************************************************/
bool is_prime(uint32_t num) {
    uint32_t index;
    bool returnVal = true;
    if (num <= 1) {
        returnVal = false;
    }
    if (num == 2) {
        returnVal = true;
    }
    for (index = 2; index * index <= num; index++) {
        if (num % index == 0) {
            returnVal = false;
        }
    }
    return returnVal;
}

void help() {
    printf("This program checks if two input integers are prime numbers.\n");
    printf("Usage: <integer1> <integer2>\n");
    printf("Press <Enter> to end input\n");
    printf("Example: 7 13<Enter>\n");
}
/*******************************************************************************
* Main
*******************************************************************************/
int main() {
    uint32_t num[100];
    uint32_t index = 0;
    uint32_t count = 0;
    uint8_t chars;

    help();
    while (((scanf("%u%c", &num[index], &chars) == 2) && (chars != '\n'))) {
        index++;
        count++;
    }

    if ((count != 1) || (isdigit(num[0])) || (isdigit(num[1]))) {
        printf("Erro: Pleas enter exactly two intergers");
    }
    else {
        if (is_prime(num[0])) {
            printf("%u is Prime\n", num[0]);
        }
        else {
            printf("%u is not Prime\n", num[0]);
        }

        if (is_prime(num[1])) {
            printf("%u is Prime\n", num[1]);
        }
        else {
            printf("%u is not Prime\n", num[1]);
        }
    }


    return 0;
}
/*******************************************************************************
* EOF
*******************************************************************************/