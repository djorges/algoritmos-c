/*
Escritura de una cadena a un archivo de texto usando fprintf().
La funcion fprintf(), el puntero de tipo FILE y la cadena a agregar al archivo.
Devuelve la cantidad de bytes agregados al archivo.

*/
#include <stdio.h>

#define MAX 100

void cargar_datos(FILE *archivo){
    char cadena[MAX];
    int cant_caracteres = 0;

    printf("Texto a agregar al archivo: ");
    fgets(cadena, MAX, stdin);
    fflush(stdin);

    cant_caracteres = fprintf(archivo, "\n%s", cadena); //deja un salto de linea y luego la cadena
    printf("\n Se escribieron %i caracteres \n", cant_caracteres);
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