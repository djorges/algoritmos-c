/*
    Lectura de un archivo caracter a caracter usando fgetc
    char fgetc(FILE *archivo)
    Devuelve el caracter leido del archivo, apuntado por el puntero FILE, o EOF, si se 

*/

#include <stdio.h>

void mostrar_caracter(FILE *archivo){
    char caracter;

    caracter = fgetc(archivo);
    
    while(caracter != EOF){
        printf("%c", caracter);
        caracter = fgetc(archivo);
    }
}

void main(){
    FILE *archivo;
    archivo = fopen("texto1.txt","rt");

    if(archivo == NULL){
        printf("\n Error de apertura del archivo. \n\n");
    }else{
        //mostrar caracteres
        mostrar_caracter(archivo);

        fclose(archivo);
    }

    return;
}