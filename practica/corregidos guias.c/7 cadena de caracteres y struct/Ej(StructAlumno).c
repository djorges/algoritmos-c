/**
 * Ejercicio: "struct","cadena de caracteres",""
 * Crear un programa que permita el ingreso de:
 *  Nombre, Padron, Email, Notas( de 2 parciales)
 * Calcular promedio y luego mostrar los datos de cada estudiante.
 * 
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NOMBRE 30
#define MAX_EMAIL 50
#define MAX_NOTAS 2

#define TAMANIO 3

typedef struct
{
    char nombre[MAX_NOMBRE];
    int padron;
    char email[MAX_EMAIL];
    int notas[MAX_NOTAS];
    float promedio;
} alumno;

void cargar(alumno vec[TAMANIO])
{
    int i;
    for(i=0;i<TAMANIO;i++)
    {
        printf("\nIngrese el nombre:\n");
        fgets(vec[i].nombre, MAX_NOMBRE,stdin);

        printf("Ingrese el padron:\n");
        scanf("%d",&vec[i].padron);

        printf("\nIngrese el email:\n");
        fgets(vec[i].email, MAX_EMAIL,stdin);

        printf("Ingrese la nota del Parcial 1:\n");
        scanf("%d",&vec[i].notas[0]);

        printf("Ingrese la nota del Parcial 2:\n");
        scanf("%d",&vec[i].notas[1]);

        vec[i].promedio = (float)(vec[i].notas[0] + vec[i].notas[1])/2;
    }
}

void mostrar(alumno vec[TAMANIO])
{
    int i;
    for(i=0;i<TAMANIO;i++)
    {
        printf("\n\n Alumno[%d]",i);
        printf("\n nombre: %s ", vec[i].nombre);
        printf("\n padron: %d ", vec[i].padron);	
        printf("\n email: %s ", vec[i].email);
        printf("\n Nota Parcial 1: %d Nota Parcial 2: %d", vec[i].notas[0],vec[i].notas[1]);
        printf("\n promedio Cd: %.2f ", vec[i].promedio);
    }
}

int main(){
    alumno alumnos[TAMANIO];

    cargar(alumnos);
    mostrar(alumnos);

    return 0;
}