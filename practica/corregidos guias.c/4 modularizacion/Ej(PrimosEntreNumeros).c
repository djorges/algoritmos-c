/*
 Escribir un programa que solicite el ingreso de dos numeros,
 y luego informe los numeros primos que hay entre esos 2 numero.
 Se debe validar que los numeros ingresados sean enteros positivos y
 además que el primer número sea menor o igual que el segundo
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int num1, num2;

    solicitar_datos(&num1, &num2);
    procesar_secuencia(num1, num2);

    system("PAUSE");
    return 0;
}

void solicitar_datos(int *num1, int *num2){
    do{
        printf("Ingrese primer numero positivo");
        *num1 = solicitar_positivo();
        printf("Ingrese segundo numero, mayor al primero");
        *num2 = solicitar_positivo();
        if(*num1 >= *num2)
            printf("Los valores ingresados son incorrectos");
    }while(*num1 >= *num2);
}

int solicitar_positivo(){
    int num;

    do{
        scanf("%d", &num);
        if(num<=0)
            printf("El numero debe ser positivo, reingrese el valor");
    }while(num <= 0);

    return num;
}

void procesar_secuencia(int num1, int num2){
    int i;

    printf("Los numeros primos en rango son: \n");
    for(i=num1; i<=num2; i++){
        if(es_primo(i))
            print(" %d", i);
    }
    printf("\n");
}

bool es_primo(int num){
    bool primo = true;
    int divisor=2;

    while(primo && divisor <= num/2){
        if(num%divisor == 0)
            primo = false;
        divisor++;
    }

    return primo;
}
