/* Ej 7 (No recomendado)
Escribir una función que dados a y b devuelva el cociente de la división
entera, sin utilizar el operador correspondiente del lenguaje.
Para esta resolución deben considerar la utilización de restas sucesivas.

*/
#include <stdio.h>

int division_entera(int a, int b) {
    int cociente = 0;
    int positivo = 1;

    if (b != 0) {
        // Manejo de signos
        if (a < 0) {
            a = -a;
            positivo = !positivo;
        }
        if (b < 0) {
            b = -b;
            positivo = !positivo;
        }

        // Restas sucesivas
        while (a >= b) {
            a -= b;
            cociente++;
        }

        // Ajustar signo
        if (!positivo) {
            cociente = -cociente;
        }
    }

    return cociente;
}
int main() {
    int a = 17, b = 3;

    if (b == 0) {
        printf("Error");
    } else {
        printf("Cociente: %d\n", division_entera(a, b));
    }
    
    return 0;
}