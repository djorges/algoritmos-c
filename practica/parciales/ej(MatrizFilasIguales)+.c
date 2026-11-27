/*
Dadas las siguientes declaraciones de constantes y tipos
 * #define cantcols 40
 * #define cantfilas 30
 * 
 * typedef char Tmatriz[cantfilas][cantcols];
Desarrollar una función en lenguaje C que reciba como parámetros la estructura ya cargada y sus
máximos lógicos(de filas y de columnas), e informe al módulo invocante si en dicha matriz hay al menos
dos filas consecutivas que contengan los mismos valores. Escribir las declaraciones y/o
definiciones necesarias para poder utilizar valores booleanos. Se deben evitar ciclos innecesarios.

*/
#include <stdio.h>
#include <stdbool.h>

#define FILAS 3
#define COLS 3

typedef char Tmatriz[FILAS][COLS];

bool filas_iguales(Tmatriz matriz, int mlf, int mlc){
    int fil = 0;
    int col;
    bool filas_iguales=false;
    bool desigualdad_en_fila;

    while(!filas_iguales && fil<(mlf-1)){ // estado y contador(hasta anteultima fila).
        col = 0;
        desigualdad_en_fila = false;

        while(!desigualdad_en_fila && col<mlc){
            //valido desigualdad col por col
            if(matriz[fil][col] != matriz[fil+1][col]){ //col en fila actual DISTINTO a col en siguiente fila
                desigualdad_en_fila = true;
            }
            col++;
        }

        //No ocurrió desigualdad en col, entonces las filas son iguales.
        if(col == mlc){
            filas_iguales = true;
        }

        fil++;
    }

    return filas_iguales;
}