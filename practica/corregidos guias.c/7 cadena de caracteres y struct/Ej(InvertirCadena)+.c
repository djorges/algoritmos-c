/**
 * Ejercicio:
 * Escribir una función en C que, reciba como primer parámetro, una cadena de tipo t_cadena, y 
devuelva como segundo parámetro, la misma cadena pero invertida, sin considerar los blancos. 
Sólo se deben invertir las posiciones con caracteres ciertos, y no aquellas posiciones 
potenciales a ser utilizadas pero que podrían contener caracteres inciertos.
Recorrer la cadena a lo sumo una vez.
Declare un tipo t_cadena acorde.
Escribir el programa que incluya a la función y las invocaciones con los siguientes casos y 
las impresiones para comprobar que devuelven lo correcto. 

invertir_cadena("Hola, me llamo Ana.", cad_invertida) ==> cad_invertida: ".anAomallem,aloH"
invertir_cadena("234561", cad_invertida) ==> cad_invertida: "165432"
invertir_cadena("    ", cad_invertida) ==> cad_invertida:  ""
invertir_cadena("Somos o No somos", cad_invertida) ==> cad_invertida:  "somosoNsomoS"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MF 50

typedef char t_cadena[MF];

void invertir_cadena(t_cadena cadena, int ml, t_cadena cadena2){
    char aux;
    int i;

    for(i=0; i< ml / 2; i++){
        //validar que no sea espacio
        if(cadena[i] != ' '){
            aux = cadena[i];
            cadena[i] = cadena[ml -1 -i];
            cadena[ml -1 -i] = aux;
        }
    }
    
    //copiar cadena ya invertida
    strcpy(cadena2,cadena);
}

int main(){
    t_cadena cadena = "HOLA MUNDO";
    int longitud = strlen(cadena);
    t_cadena invertida;

    invertir_cadena(cadena, longitud, invertida);

    printf("Cadena Invertida: %s \n", invertida);
    
    return EXIT_SUCCESS;
}