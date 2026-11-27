/*
6) Escribir una función en C, que reciba:
a) como primer parámetro un vector de números enteros;
b) como segundó parámetro, la cantidad de elementos en el vector;
c) como tercer parámetro deberá devolver la cantidad de valores negativos que
hay en el vector recibido;
d) como cuarto parámetro, la cantidad de elementos positivos que hay en el
vector recibido.

Escribir el programa que incluya a la función y las invocaciones con los
siguientes ejemplos, y la respectiva impresión de los valores devueltos:

Probar el programa con los siguiente casos:
v1 = [2,8,1,-5,4] -> Negativos: 1 Positivos: 4
v2 = [-2,-15,-3] -> Negativos: 3 Positivos: 0
v3 = [0,0,10,12,23,55,1] -> Negativos: 0 Positivos: 5
*/
#include <stdio.h>

#define MAX_FISICO 20

typedef int t_vec[MAX_FISICO];

void clasificar_numeros(t_vec arreglo, int ml, int *positivos, int *negativos){
    int i;

    *positivos = 0;
    *negativos = 0;

    for(i=0; i<ml; i++){
        if(arreglo[i]>0){
            (*positivos)++;
        }else{
            if(arreglo[i]<0){
                (*negativos)++;
            }
        }
    }
}
