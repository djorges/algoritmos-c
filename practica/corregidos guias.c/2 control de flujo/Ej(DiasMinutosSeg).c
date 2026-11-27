/*
Escribir una función que dado un tiempo expresado en segundos, devuelva
por parámetros el equivalente en días, horas, minutos y segundos.
 
Utilizar esta función dentro de un programa que solicite el valor al usuario.
 
Se debe validar que el valor ingresado sea entero positivo, de lo contrario,
deberá mostrarse el mensaje: “Valor ingresado inválido”.

Ejemplo:
Valor ingresado representando una cantidad de segundos: 1234567
Resultado: Días: 14, Horas: 6, Minutos: 56, Segundos 7

Para verificar el resultado pueden ir a la siguiente web:
https://www.satsig.net/training/seconds-days-hours-minutes-calculator.htm

*/

#include <stdio.h>

#define DIA_SEGUNDOS 86400
#define HORA_SEGUNDOS 3600
#define MINUTO_SEGUNDOS 60

void convertirTiempo(long totalSegundos, int *dias, int *horas, int *minutos, int *segundos) {
    //quito dias
    *dias = totalSegundos / DIA_SEGUNDOS;
    //guardo resto
    totalSegundos = totalSegundos % DIA_SEGUNDOS; 

    *horas = totalSegundos / HORA_SEGUNDOS;
    totalSegundos = totalSegundos % HORA_SEGUNDOS;

    *minutos = totalSegundos / MINUTO_SEGUNDOS; //ej 122 / 60 
    *segundos = totalSegundos % MINUTO_SEGUNDOS;
}

long solicitarSegundos(){
    long totalSegundos;
    do{
        printf("Ingrese el tiempo en segundos: ");
        scanf("%ld", &totalSegundos);
        if (totalSegundos < 0)
        {
            printf("Error: valor debe ser positivo ");
        }
        
    }while(totalSegundos < 0);
   
    return totalSegundos;
}

int main() {
    long totalSegundos;
    int dias, horas, minutos, segundos;


    totalSegundos = solicitarSegundos();

    convertirTiempo(totalSegundos, &dias, &horas, &minutos, &segundos);

    printf("Equivalente:\n");
    printf("Dias: %d\n", dias);
    printf("Horas: %d\n", horas);
    printf("Minutos: %d\n", minutos);
    printf("Segundos: %d\n", segundos);

    return 0;
}