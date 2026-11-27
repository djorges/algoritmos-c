/*No recomendado */
#include <stdio.h>
#define FILAS 2
#define COLUMNAS 3

typedef int t_matriz[FILAS][COLUMNAS];

void calcular_cuadrados(t_matriz matriz, int fil, int col){
    int i, j;
    for(i=0; i<fil; i++)
        for(j=0; j<col; j++)
            matriz[i][j] = matriz[i][j] * matriz[i][j];
}

void mostrar_datos(t_matriz matriz, int fil, int col){
    int i,j;
    for(i=0; i<fil; i++)
        for(j=0; j<col; j++)
            prinf("%4i ", matriz[i][j]);
        printf("\n");
}

void main(){
    t_matriz mat_nros = {
        {1,2,3},
        {4,5,6}
    };

    mostrar_datos(mat_nros, FILAS, COLUMNAS);
    calcular_cuadrados(mat_nros, FILAS, COLUMNAS);
    
    printf("\n");
    mostrar_datos(mat_nros, FILAS, COLUMNAS);

    return;
}