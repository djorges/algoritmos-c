#include <stdio.h>

int factorial(int n){
    if(n == 0) return 1; //caso base

    return n * factorial(n -1);
}

int main(){
    int num = 5;

    printf("Factorial de %d = %d \n", num, factorial(num));

    return 0;
}