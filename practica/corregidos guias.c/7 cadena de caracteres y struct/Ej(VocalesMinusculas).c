/**
 * Ejercicio:
 * Escribir un programa modular en C, que solicite el ingreso de 1 oracion, de no más de 100 caracteres. 
Luego informar la cantidad de vocales minusculas, no acentuadas, que hay en la oracion.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MF 100

typedef char t_cadena[MF];

void ingresar_datos(t_cadena cadena){
    printf("%s \n","Ingrese la frase a evaluar:");
    fgets(cadena, MF, stdin);
    fflush(stdin);
}

int evaluar_cadena(t_cadena cadena){
    int i, cant_vocales = 0;

    for(i=0; i<strlen(cadena); i++){
        if(validar_vocal(cadena[i])){
            cant_vocales++;
        }
    }

    return cant_vocales;
}

bool validar_vocal(char caracter){
    bool es_vocal = false;

    if(caracter == 'a' || caracter == 'e' || caracter == 'i' ||caracter == 'o' || caracter == 'u'){
        es_vocal = true;
    }

    return es_vocal;
}

int main(){
    int resultado;
    t_cadena cadena;

    ingresar_datos(cadena);
    resultado = evaluar_cadena(cadena);
    printf("Total vocales: %d \n", resultado);

    system("pause");

    return EXIT_SUCCESS;
}