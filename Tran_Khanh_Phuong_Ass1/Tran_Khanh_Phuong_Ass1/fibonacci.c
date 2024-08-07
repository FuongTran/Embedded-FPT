#include "fibonacci.h"

unsigned long long fibonacci(int n) {
    unsigned long long result = 0;

    if (n == 1) {
        result = 1;
    }
    else {
        unsigned long long fib1 = 0;
        unsigned long long fib2 = 1;

        for (int i = 2; i <= n; ++i) {
            result = fib1 + fib2;
            fib1 = fib2;
            fib2 = result;
        }
    }

    return result;
}


