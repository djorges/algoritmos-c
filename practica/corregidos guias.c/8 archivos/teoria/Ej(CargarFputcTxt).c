/*
    Escritura de caracter en caracter a un archivo de texto usando fputc().
    La funcion recibe el caracter a escribir y el puntero de tipo FILE, y
    devuelve el caracter escrito si la operacion pudo ser realizada, caso 
    contrario devuelve EOF
*/

#include <stdio.h>

void cargar_datos(FILE *archivo){
    char caracter;

    printf("\n Texto a agregar al archivo:");

    caracter = getchar();
    while(caracter != '\n'){ //agregara caracter a caracter hasta que se de enter
        fputc(caracter, archivo);
            
        caracter = getchar();
    }
}

void main(){
    FILE *archivo;
    archivo = fopen("texto1.txt","a");

    if(archivo == NULL){
        printf("\n Error de apertura del archivo. \n\n");
    }else{
        //cargar datos
        cargar_datos(archivo);

        fclose(archivo);
    }

    return;
}