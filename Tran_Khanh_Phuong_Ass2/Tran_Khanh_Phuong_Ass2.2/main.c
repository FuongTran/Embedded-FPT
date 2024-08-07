#include <stdio.h>
#include "function.h"

int main() {
    char choice;
    int value, position;

    printf("-----Quan ly day so-----\n");
    printf("Cac tinh nang:\n");
    printf("c - Clear data mang cu va nhap mamg moi\n");
    printf("p - In day so\n");
    printf("i - Them phan tu vao day\n");
    printf("d - Xoa phan tu tai vtri k\n");
    printf("s - Sap xep tang dan\n");
    printf("x - Sap xep giam dan\n");
    printf("t - Tim kiem phan tu co gtri x trong day\n");
    printf("a - Tim max\n");
    printf("w - Tim min\n");
    printf("e - Thoat chuong trinh\n");

    while (1) {
        printf("Your choice: ");
        scanf_s(" %c", &choice);

        switch (choice) {
        case 'c':
            clearArray();
            break;
        case 'p':
            printArray();
            break;
        case 'i':
            printf("Nhap gtri va vtri: ");
            scanf_s("%d %d", &value, &position);
            insertElement(value, position);
            break;
        case 'd':
            printf("Nhap vtri can xoa ");
            scanf_s("%d", &position);
            deleteElement(position);
            break;
        case 's':
            sortArrayUp();
            printArray();
            break;
        case 'x':
            sortArrayDown();
            printArray();
            break;
        case 't':
            printf("Nhap gtri can tim: ");
            scanf_s("%d", &value);
            position = searchElement(value);
            if (position != -1) {
                printf("Phan tu o vtri %d\n", value, position);
            }
            else {
                printf("Khong tim thay phan tu co gtri %d trong day\n", value);
            }
            break;
        case 'a':
            printf("Max: %d\n", findMax());
            break;
        case 'w':
            printf("Min: %d\n", findMin());
            break;
        case 'e':
            exit(0);
        default:
            printf("KHong hop le.\n");
            break;
        }
    }
    return 0;
}
