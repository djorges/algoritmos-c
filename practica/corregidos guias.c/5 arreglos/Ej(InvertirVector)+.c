/*
4) Cargar una serie de números reales positivos en un vector. No se conoce la
cantidad exacta de datos, pero se sabe que no superan los 100. La serie finaliza
cuando se ingresa cero. Utilizar una función que invierta el contenido del vector.
Informar el contenido del vector indicando la posición ocupada por cada
número a partir de la primera posición
*/
#include <stdio.h>

#define MF 1000

typedef float t_vec[MF];

void ingresar_vector(t_vec vector, int *ml){
    float num;
    int i = 0;

    printf("Ingrese numeros positivos (0 para finalizar):\n");
    scanf("%f", &num);

    while(i < MF && num != 0){ //&& num != 0 es solo porque 0 para finalizar
        //validar positivo
        if(num > 0){
            vector[i] = num;
            i++;
        }else{
            printf("Solo se permiten positivos\n");
        }
        
        scanf("%f", &num);
    }
    *ml = i;
}

void invertir_vector(t_vec vec, int ml){
    int i;
    float aux;

    for(i = 0; i < ml/2; i++){
        aux = vec[i];
        vec[i] = vec[ml-1-i];//vec[0] = vec[ml-1]
        vec[ml-1-i] = aux;
    }
}

int main(){
    t_vec arreglo;
    int ml;

    ingresar_vector(arreglo, &ml);
    invertir_vector(arreglo, ml);

    return 0;
}