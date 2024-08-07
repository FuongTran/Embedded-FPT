#include "function.h"
#include <stdio.h>

uint8_t array[ARRAY_SIZE];
int array_length = 0;

void clearArray() {
    array_length = 0;
    int value;
    printf("Nhap cac phan tu cua mang (Nhap -1 de ket thuc):\n");
    while (array_length < ARRAY_SIZE) {
        scanf_s("%d", &value);
        if (value == -1) {
            break;
        }
        if (value < 0 || value > 100) {
            printf("Gia tri khong hop le, hay nhap lai");
            continue;
        }
        array[array_length++] = value;
    }
}

void printArray() {
    if (array_length == 0) {
        printf("Day khong co phan tu nao\n");
        return;
    }
    printf("Day so: ");
    for (int i = 0; i < array_length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertElement(int value, int position) {
    if (position < 0 || position >= ARRAY_SIZE) {
        printf("Vi tri khong hop le\n");
    }
    if (array_length >= ARRAY_SIZE) {
        printf("Mang da day\n");
    }
    if (position < array_length&& array[position] != 0) {
        printf("Phan tu da co gia tri\n");
    }
    for (int i = array_length; i > position; i--) {
        array[i] = array[i - 1];
    }
    array[position] = value;
    array_length++;
}

void deleteElement(int position) {
    if (position < 0 || position >= array_length) {
        printf("Không có phần tử tại vị trí %d.\n", position);
        return;
    }
    for (int i = position; i < array_length - 1; i++) {
        array[i] = array[i + 1];
    }
    array_length--;
}

void sortArrayDown() {
    for (int i = 0; i < array_length - 1; i++) {
        for (int j = i + 1; j < array_length; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void sortArrayUp() {
    for (int i = 0; i < array_length - 1; i++) {
        for (int j = i + 1; j < array_length; j++) {
            if (array[i] < array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int searchElement(int value) {
    for (int i = 0; i < array_length; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

int findMax() {
    int max = array[0];
    for (int i = 1; i < array_length; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int findMin() {
    int min = array[0];
    for (int i = 1; i < array_length; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}
