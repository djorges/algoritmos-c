/**
 * Escribir una función que reciba dos valores enteros, y devuelva el máximo
común divisor entre ambos números
 * 
*/
#include <stdio.h>

void cargar_datos(int *a, int *b){
    *a = -1;
    *b = -1;

    while(*a < 0 || *b < 0){

        printf("Ingrese un numero positivo:\n");
        scanf("%d", a);

        printf("Ingrese otro numero positivo:\n");
        scanf("%d", b);
    }
}

int mcd(int a, int b) { // a = -1, b = 4
    int aux;
    //Solo positivos
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0){ // 4 != 0                  1 != 0 
        aux = b; // aux = 4             aux = 1
        b = a % b; // b = 1 % 4 = 1           b = 4 % 1 = 0
        a = aux; // 4                        a = 1
    }

    return a;
}

void mostrar_datos(int resultado){
    printf("%s %d \n", "El resultado es: ", resultado);    
}

int main(){
    int a, b;
    int resultado;

    cargar_datos(&a, &b);
    resultado = mcd(a, b);
    mostrar_datos(resultado);

    return 0;
}