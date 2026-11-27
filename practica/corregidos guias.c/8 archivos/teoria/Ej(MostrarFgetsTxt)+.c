/*
    Lectura de cadenas de caracteres desde un archivo, usando fgets().
    char *fgets(char *buffer, int tamaño, FILE *archivo);
    Recibe la referencia a la cadena en donde dejar los datos leidos, la cantidad de by
    el puntero de tipo FILE.
    Lee n-1 caracteres, o hasta el fin de linea, o hasta el fin de archivo.
*/
#include <stdio.h>
#define MAX 80

typedef char tCaracteres[MAX];

void mostrar_caracteres(FILE *archivo){
    tCaracteres caracteres;

    while(!feof(archivo))
    {
        fgets(caracteres, MAX, archivo);
        printf("%s\n", caracteres);
    }
}

void main(){
    FILE *archivo;
    archivo = fopen("texto1.txt","r");

    if(archivo == NULL){
        printf("\n Error de apertura del archivo. \n\n");
    }else{
        //mostrar caracteres
        mostrar_caracteres(archivo);

        fclose(archivo);
    }

    return;
}