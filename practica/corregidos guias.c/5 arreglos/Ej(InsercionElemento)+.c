/**
 * Dado un vector a ordenado ascendente de longitud ml y un elemento p del
    mismo tipo que los elementos del vector, insertar p en el vector a de modo
    que siga ordenado. Validar previamente que en el vector haya espacio libre para
    guardar el nuevo dato.
    Se solicita resolver lo solicitado recorriendo una sola vez el vector y sin utilizar
    un arreglo auxiliar.
    Ejemplo:
    nuevo elemento p=14
 */
#include <stdio.h>
#include <stdbool.h>

#define MF 10

typedef float t_vec[MF];

/*float ingresar_num(){
    float num;
    do{
        printf("Ingrese número positivo mayor a 0: ");
        scanf("%f", &num);
        if(num<0){
            printf("El numero es negativo");
        }
    }while(num<0);

    return num;
}*/

void ingresar_vector(t_vec vector, int *ml){
    int i = 0;
    char seguir = 's';

    while(i < MF && seguir == 's'){
        //Agregar elemento
        printf("Ingrese número: ");
        scanf("%f", &vector[i]);
        i++;

        //Validar seguir
        printf("¿Seguir? (s/n): ");
        scanf(" %c", &seguir);
    }

    *ml = i;
}

void shiftear_vec(t_vec vector, int indx, int ml){
    for(int i = ml; i > indx; i--){
        vector[i] = vector[i - 1];
    }
}

void insertar_num(t_vec vector, int *ml, int num){

    if(*ml<MF){
        int i = 0;
        //buscar pos
        while(i < *ml && num > vector[i]){
            i++;
        }
        //shiftear derecha vec desde la posicion i
        shiftear_vec(vector, i, *ml);

        //insertar elemento
        vector[i] = num;
        (*ml)++;
    }else{
        printf("No hay Espacio para añadir");
    }
}

int main(){
    t_vec vector;
    int ml;
    float num;

    ingresar_vector(vector, &ml);
    //suponer vector ya ordenado
    insertar_num(vector, &ml, num);
    
    return 0;
}