/** (No recomendado)
 * Escribir un programa modular que solicite el ingreso de la cantidad de mililitros llovidos en la semana, de lunes a domingo, de 0 a 23hs.
El ingreso de datos es por día comenzando el lunes, y para cada día, por hora de 0 a 23.
Informar el promedio de mililitros llovidos para cada día de la semana.
 * 
 * 
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DIAS 7
#define HORAS 24

typedef int matriz_t[DIAS][HORAS];

void cargar_datos(matriz_t lluvias){
    int dia, hora;

    printf("%s \n","Ingrese los mililitros de lluvia.");
    for(dia=0; dia<DIAS; dia++){
        printf("%s %d \n", "Dia:", dia+1);
        
        for(hora=0; hora<HORAS; hora++){
            printf("%s %d:", "Ingrese los ml de la hora ", hora);
            scanf("%d", lluvias[dia][hora]);
        }
    }
}

void calcular_promedio_por_dia(matriz_t lluvias){
    int dia, hora;
    float suma;
    for(dia=0;dia<DIAS;dia++){
        suma = 0;
        for(hora=0;hora<HORAS;hora++){
            suma += lluvias[dia][hora];
        }
        printf("Dia: %d, Promedio: %0.2f \n",(dia+1), suma/(float)HORAS);
    }

}

int main(){
    matriz_t lluvias;

    cargar_datos(lluvias);

    calcular_promedio_por_dia(lluvias);

    return EXIT_SUCCESS;
}