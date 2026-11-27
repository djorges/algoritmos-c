/*
10) Utilizar memoria dinámica para almacenar una cierta cantidad de n palabras
ingresadas por el usuario. Crear una estructura de datos dinámica de dos
dimensiones que permita almacenar esta información. Mostrar toda la
información de la estructura luego de haber sido cargada. Liberar toda la
memoria al finalizar el programa.

typedef char* t_palabra;
typedef t_palabra* t_vec;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 100
typedef char t_palabra[MAX_CHAR];
typedef char* t_palabra_dinamica;
typedef t_palabra_dinamica* t_texto_dinamico;


// INPUT
void ingresar_num(const char msg[], int *num){
    printf("%s", msg);
    scanf("%d", num);
    getchar();
}


void ingresar_string(const char msg[], t_palabra palabra){
    printf("%s", msg);
    fgets(palabra, MAX_CHAR, stdin);
    palabra[strlen(palabra) - 1] = '\0';
}


t_palabra_dinamica ingresar_palabra_dinamica(){
    
    t_palabra aux_palabra;
    t_palabra_dinamica palabra = NULL;

    ingresar_string("- Ingrese palabra: ", aux_palabra);
    palabra = malloc(strlen(aux_palabra) * sizeof(char) + 1);

    if (palabra != NULL)
        strcpy(palabra, aux_palabra);

    return palabra;
}


t_texto_dinamico ingresar_texto_dinamico(int cantidad_palabras){
    int i;
    t_texto_dinamico texto = NULL;
    
    texto = malloc(cantidad_palabras * sizeof(t_palabra));

    if (texto != NULL){
        for (i = 0; i < cantidad_palabras; i++)
            texto[i] = ingresar_palabra_dinamica();
    }

    return texto;
}


void liberar_texto_dinamico(t_texto_dinamico texto, int cantidad_palabras){
    int i;
    for (i = 0; i < cantidad_palabras; i++)
        free(texto[i]);
}

// OUTPUT
void mostrar_texto(t_texto_dinamico texto, int cantidad_palabras){
    int i;
    for (i = 0; i < cantidad_palabras; i++)
        printf("- Palabra nº%d: '%s', %p\n", i + 1, texto[i], texto + i);
}



int main(){
    int cantidad_palabras;
    t_texto_dinamico texto = NULL;

    ingresar_num("[+] Ingresar cantidad de palabras a cargar: ", &cantidad_palabras);
    texto = ingresar_texto_dinamico(cantidad_palabras);

    if (texto != NULL){
        printf("***Texto ingresado***\n");
        mostrar_texto(texto, cantidad_palabras);
    }
    else
        printf("[!] No se pudo crear texto!!!");

    // liberar las palabras antes del texto
    liberar_texto_dinamico(texto, cantidad_palabras);
    // liberar texto puntero de punteros (array de punteros)
    free(texto);

    return 0;
}