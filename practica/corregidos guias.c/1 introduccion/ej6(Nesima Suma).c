
/*
La idea es aplicar la formula de la n-ésima suma parcial: (n * (n+1)) / 2. Por lo que no habria que aplicar 
ningún tipo de iteración. pero en el caso que quieras iterar de 1 hasta n e ir sumando deberia ser un for directo.
6) Calcular la suma de los n primeros números naturales.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int maximo, suma = 0;

    //Init
    printf("%s \n","Ingrese maximo:");
    scanf("%d", &maximo); //maximo = 10

    //Logic
    for(size_t i = 1; i <= maximo; i++){ //i=1                     i=2;suma=1 
        suma += (i * (i+1)) / 2;    // suma = 0 + (1*2)/2 = 1 ;    suma = 1 +(2*3)/2 = 4
        //sumas parciales printf("%s %d\n","La suma es:",suma);
    }
    //Print
    printf("%s %d\n","La suma total es:",suma);

    system("PAUSE");

    return EXIT_SUCCESS;
}