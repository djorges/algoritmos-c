/**
 * No Recomendado.Programa para cargar archivos de números enteros positivos
 * - El usuario ingresa nombre de archivo a crear
 * - El usuario ingresa cantidad de números a ingresar
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NOMBRE_LARGO 20

typedef char t_string[MAX_NOMBRE_LARGO];

void ingresar_string(t_string str){
    
    printf("%s\n", "Ingrese nombre del archivo a generar (modo binario): ");
    fgets(str, MAX_NOMBRE_LARGO, stdin);
    fflush(stdin);

    str[strlen(str) - 1] = '\0';
}

int main(){
    FILE *archivo;
    t_string nombre_archivo;
    int cantidad_enteros;
    int max_num;

    ingresar_string(nombre_archivo);
}