/*
    Mostrar digitos impares de un numero
*/
#include <stdio.h>

void mostrarImpares(int n){
    if(n == 0){    // Caso base: cuando el número es 0, se han analizado todos los digitos, terminamos la recursividad
        return;
    }

    int digito = n % 10; // Extrae el último dígito

    mostrarImpares(n / 10); //procesamos el resto de los dígitos

    // Mostrar dígito si es impar
    if(digito % 2 != 0){ 
        printf("%d ", digito);
    }
}

int main() {
    int numero = 482915;
    
    mostrarImpares(numero);
    printf("\n");

    return 0;
}