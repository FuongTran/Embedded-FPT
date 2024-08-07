#include <stdio.h>
#include "fibonacci.h"

int main() {
    int n = 0;

    printf("Nhap so thu tu cua day Fibonacci (1 <= N <= 100): ");
    scanf_s("%d", &n);

    if (n < 1 || n > 100) {
        printf("Gia tri N phai nam trong khoang tu 1 den 100.\n");
    }
    else {
        unsigned long long fib = fibonacci(n);

        printf("So Fibonacci thu %d la: %llu\n", n, fib);
    }

    return 0;
}
