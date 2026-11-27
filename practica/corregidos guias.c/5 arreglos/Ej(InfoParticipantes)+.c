/*
En una competencia de salto en largo, se presentaron 5 participantes. De
cada uno se ingresa:
    Número de participante
    Fecha de nacimiento (aaaammdd)
    Distancias de sus 3 saltos expresados en metros.
El mejor de los 3 saltos se considera como la mejor marca obtenida.

Se pide:
a) Para cada participante mostrar por pantalla el número de participante, la
edad y la marca obtenida.
b) Informar el número del participante del atleta que obtuvo la mejor marca.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define CANTIDAD_PARTICIPANTES 5
#define FECHA_NACIMIENTO 8
#define CANTIDAD_SALTOS 3

typedef int t_participantes[CANTIDAD_PARTICIPANTES];
typedef char t_fecha[FECHA_NACIMIENTO];
typedef t_fecha t_fechas[CANTIDAD_PARTICIPANTES];
typedef int t_salto[CANTIDAD_PARTICIPANTES];

void ingresar_numero_participante(int *nro_participante){
    printf("Ingrese número de participante: ");
    scanf("%d", nro_participante);
    fflush(stdin);
}

void ingresar_fecha(t_fecha fecha){
    printf("Ingresar fecha (aaaammdd): ");
    fgets(fecha, FECHA_NACIMIENTO, stdin);

    //ultima pos colocar fin de cadena
    fecha[strlen(fecha)-1] = '\0';
}

void ingresar_salto(int *salto){
    int i;
    int temp_maximo = 0;
    for(i = 0; i< CANTIDAD_SALTOS; i++){
        //ingresar salto
        printf("Ingrese salto '%d': ", i);
        scanf("%d", *salto);

        //Chequear temp_maximo
        if(*salto > temp_maximo){
            temp_maximo = *salto;
        }
    }
    //solo queda el salto máximo
    *salto = temp_maximo;
}

void ingresar_usuarios(t_participantes participantes, t_fechas fechas, t_salto saltos){
    int i;

    for(i = 0; i< CANTIDAD_PARTICIPANTES; i++){
        ingresar_numero_participante(&participantes[i]);
        ingresar_fecha(fechas[i]);
        ingresar_saltos(&saltos[i]);
    }
}

int main(){
    t_participantes participantes;
    t_fechas fechas;
    t_salto saltos;

    ingresar_usuarios(participantes, fechas, saltos);
    imprimir_usuarios(participantes, fechas, saltos);

    return 0;
}