#include <stdio.h>

int fib(int n) {
    // Base cases
    if (n <= 1) return n;
    
    // Recursive case
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", fib(n));
    return 0;
}