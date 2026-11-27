/**
 * 5) Cargar un conjunto de números de documento en un vector. No se conoce la
cantidad de datos válidos. Informar el número de documento más alto del
conjunto y la posición que ocupa. Puede haber repetición, en este caso
informar todas las posiciones que ocupa.
*/
#include <stdio.h>
#define MF 8

typedef int v_dni[MF];
typedef int v_aux[MF];

void cargar_datos(v_dni vector, int *ml){
    int numero;
    int i = 0;

    printf("%s \n","Ingrese un dni(o finalice en 0):");
    scanf("%d", &numero);

    while(i<MF && numero != 0){

        if(numero > 0){
            vector[i] = numero;
            i++;
        }

        scanf("%d", &numero);
    };

    *ml = i;
}

int calcular_mayor(v_dni vector, int ml, v_aux posiciones){
    int i;
    int maximo = 0;
    
    for(i=0; i<ml ;i++){
        if(vector[i] > maximo){ // maximo cambia, guardo pos.
            maximo = vector[i]; 
            posiciones[i] = maximo; 
        }
        else if(vector[i] == maximo){ //maximo no cambia, guardo pos.
            posiciones[i] = maximo;
        }
    }
    return maximo;
}

void mostrar_mayor(v_aux posiciones, int ml, int maximo){
    int i;
    //recorrer aux
    for(i=0; i<ml ;i++){
        if(maximo == posiciones[i]){
            printf("El número mas álto %d está en la posicion %d\n", maximo, i);
        }
    }
}

int main(){
    v_dni vector;
    int ml;
    v_aux posiciones;
    int maximo;

    cargar_datos(vector, &ml);
    maximo = calcular_mayor(vector, ml, posiciones);
    mostrar_mayor(posiciones, ml, maximo);

    return 0;
}