/*
    ENUNCIADO EJERCICIO: Matriz Numeros Existentes

    Implementar la función ejercicio_3 que reciba una matriz cargada con números enteros entre 0 y 100, y el máximo lógico de filas y el de columnas de ésta.
    La función debe mostrar por pantalla los numeros que se encuentran presentes en la matriz y la cantidad de apariciones de cada uno de ellos.

    Considerar que solo se puede recorrer una vez la matriz. Está permitida la utilización de un vector auxiliar.

    Por ejemplo:
    se tiene la siguiente matriz de 3x3
    {
    {56, 89, 56},
    {78, 23, 11},
    {75, 56, 11}
    }

    El resultado debe ser:
    11 -> 2
    23 -> 1
    56 -> 3
    75 -> 1
    78 -> 1
    89 -> 1
*/
#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3
#define MAX_NUM 101

typedef int t_mat[FILAS][COLUMNAS];
typedef int t_aux[MAX_NUM];

void mostrarCantApariciones(t_mat matriz, int fil, int col){
    t_aux aux = {0};
    int i;
    int j;
    int k;

    for (i = 0; i < fil; i++)
    {
        for (j = 0; j < col; j++)
        {
            aux[matriz[i][j]]++;
        }
    }

    //mostrar vec contador
    printf("Numeros presentes y cantidad de apariciones:\n\n");
    for(k= 0; k<MAX_NUM; k++){
        if(aux[k] > 0){
            printf("%d -> %d \n", k, aux[k]);
        }
    }
}

int main(){
    t_mat mat = {
        {56, 89, 56},
        {78, 23, 11},
        {75, 56, 11}
    };

    mostrarCantApariciones(mat, FILAS, COLUMNAS);

    return 0;
}