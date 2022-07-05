#include <stdio.h>

void fizz(int i) {
    printf("fizz\n");
}

void buzz(int i) {
    printf("buzz\n");
}

void print(int i) {
    printf("%d\n", i);
}

void fizzbuzz(int i) {
    printf("fizzbuzz\n");
}

int func1() {
    return printf("one");
}

int func2() {
    return printf("two");
}

int main() {    
    using fizzorbuzzP_t = void(*)(int);
    fizzorbuzzP_t arrP[2][2] = {&fizzbuzz, &fizz, &buzz, &print};
    fizzorbuzzP_t func_P;
    int t;
    scanf("%d", &t);
    for (int i = 1; i < t; i++) {
        func_P = arrP[i%3>0][i%5>0];
        (*func_P)(i);
    }
    return 0;
}