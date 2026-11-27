/*
    Escritura de una cadena a un archivo de texto usando fputs().
    La funcion fputs(), recibe la cadena a agregar y el puntero de tipo FILE.
    Devuelve un 0 si el agregado fue exitoso, de lo contrario devolvera un valor negati
*/

#include <stdio.h>

#define MAX 100

void cargar_datos(FILE *archivo){
    char cadena[MAX];

    printf("Texto a agregar al archivo:");
    fgets(cadena, MAX, stdin);

    if(fputs(cadena, archivo) == 0){
        printf("El archivo fue actualizado");
    }else{
        printf("No fue posible agregar el texto al archivo.");
    }
}

void main(){
    FILE *archivo;

    archivo = fopen("texto2.txt", "a");

    if(archivo == NULL){
        printf("Error de apertura del archivo. \n");
    }else{
        //
        cargar_datos(archivo);

        fclose(archivo);
    }

    return;
}