/**
 * Ejercicio: Nivel Medio 
 * 
 * Nota muy ineficiente
 * Nota los elementos de n-i siempre estan ordenados(desde ultima hasta n-i). 
 * Nota se ordena de forma ascendente un arreglo de enteros.
 * 
*/
#include <stdio.h>
#include <stdlib.h>

#define MF 5

typedef int tvector[MF];

void ordenar_burbujeo(tvector vector, int n){
    int i, j, aux;

    for(i=1; i<n; i++){
         for(j=0; j<n-i;j++){ //i se le resta a n.
            if(vector[j] > vector[j+1]){ //si posicion j es mayor al j+1,se intercambia.
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
}

int main(){
    tvector vec = {4,3,2,5,6};

    printf("VECTOR ORIGINAL\n");
    mostrar(vec, MF);

    ordenar_burbujeo(vec, MF);

    printf("VECTOR FINAL\n");
    mostrar(vec, MF);

    system("PAUSE");

    return 0;
}