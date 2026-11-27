/*
    Igual que el scanf(), pero en este caso fscanf() obtiene los valores desde un archi
    Por ello, el primer parametro, es el puntero de tipo FILE.
*/

#include <stdio.h>
#define MAX 80

typedef char tCaracteres[MAX];

void mostrar_caracteres(FILE *archivo){
    tCaracteres cadena;

    fscanf(archivo, "%s", cadena);

    while(feof(archivo) == 0){
        printf("%s\n", cadena);
          
        fscanf(archivo, "%s", cadena);
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