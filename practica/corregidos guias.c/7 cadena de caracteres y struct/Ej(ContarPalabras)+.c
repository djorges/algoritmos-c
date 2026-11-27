/**
 * Ejercicio: 
 * Escribir una función en C, que reciba como parámetro una cadena de tipo t_cadena, y devuelva 
la cantidad de palabras que hay en la cadena.
Considerar que una palabra está separada de otra, por uno ó más blancos.

No recorrer la cadena más de una vez.
Declare un tipo t_cadena acorde.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef char t_cadena[100];


/* IMPORTANTE */
int contarPalabras(t_cadena cadena)
{
    int i = 0;
    int cantidad = 0;
    bool enPalabra = false;

    while (cadena[i] != '\0'){
        //validar su está en palabra
        if (cadena[i] != ' ' && cadena[i] != '\n'){
            if (!enPalabra){ //solo incrementa cuando comienza una letra luego del espacio.{
                cantidad++;
                enPalabra = true;
            }
        }else{
            enPalabra = false;
        }

        i++;
    }

    return cantidad;
}


int main(){
    t_cadena texto;

    printf("Ingrese una cadena: ");
    fgets(texto, sizeof(texto), stdin);

    printf("Cantidad de palabras: %d\n", texto);

    return 0;
}