/**
 * Ejercicio: Ordenamiento Seleccion
 * Ingresar los padrones y las notas de los alumnos 
del curso de Algoritmos y programación 1, luego 
mostrar padron y nota de forma descendiente según notas de aquellos que aprobaron.

Como máximo se cargaran 50 alumnos.

Agregar un módulo que permita la busqueda, dado un padrón ingresado por el usuario
    indicar que nota obtuvo el alumno.  
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MF 50
#define NOTAMINIMA 4
typedef int tPadrones[MF];
typedef int tNotas[MF];

int main(){
    int ml;
    tPadrones padronAlumnos;
    tNotas vecNotas;
	int padron = 100203;

    ml = ingresoPadron(padronAlumnos, vecNotas);
    ordenar(padronAlumnos, vecNotas, ml);
    mostrarPadron(padronAlumnos, vecNotas, ml);
    buscarNotaPorPadron(padron,padronAlumnos, vecNotas, ml);

    system("pause");
	
	return 0;
}

int ingresoPadron(tPadrones padronAlumnos, tNotas vecNotas){
    int padron;
    int nota;
    int i = 0;
    char respuesta;
    bool seguir = true;

    while(seguir){
        printf("Ingrese el padrón del alumno \n");
        scanf("%i", &padron);
        fflush(stdin);
        padronAlumnos[i] = padron;

        printf("Ingrese la nota del alumno \n");
        scanf("%i", &nota);
        fflush(stdin);
        vecNotas[i] = nota;

        printf("Desea ingresar otro padron (S/N)?:");
        scanf("%c", &respuesta);

        if(respuesta != 'S'){
            seguir = false;
        }
    }

    return i;
}

void ordenar(tPadrones padronAlumnos, tNotas vecNotas, int ml){
    int i;
    int j;
    int aux;
    int auxNotas;

    for(i=0;i<ml-1;i++){      
        for(j=i+1;j<ml;j++){ 
            if(vecNotas[i] < vecNotas[j]){
                auxNotas = vecNotas[j];
                vecNotas[j] = vecNotas[i];
                vecNotas[i] = auxNotas;

                aux = padronAlumnos[j];
                padronAlumnos[j] = padronAlumnos[i];
                padronAlumnos[i] = aux;
            }
        }
    }
}

void mostrarPadron(tPadrones padronAlumnos, tNotas vecNotas, int ml){
    int i;
    
    for(i = 0; i < ml; i++){
        if(vecNotas[i] >= NOTAMINIMA){
            printf("Padron: %d ,nota del alumno: %d \n", padronAlumnos[i], vecNotas[i]);
        }
    }
}

int buscarNotaPorPadron(int padron,tPadrones vecPadrones,tNotas vecNotas, int ml){
    int i = 0;
    int nota = -1;
    bool seguir = true;

    while(seguir && i<ml){
        if(padron == vecPadrones[i]){
            nota == vecNotas[i];
            seguir = false;
        }
        i++;
    }

    return nota;
}