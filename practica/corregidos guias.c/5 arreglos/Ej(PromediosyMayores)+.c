/** Modularizacion - Matrices - do-while - Validacion
 * 
 * Escribir un programa modular en lenguaje C, que solicite el ingreso de HASTA 10 nÚmeros (podrían ser menos), 
y luego muestre el promedio, y todos los nÚmeros superiores al promedio calculado.
El ingreso de datos puede terminar porque el usuario ingresó 0 o bien porque se alcanzó la cantidad máxima de elementos. 

*/

#include<stdio.h>
#include<stdbool.h>
#define MF 10

typedef int vector_t[MF];

void cargar_datos(vector_t numeros, int *ml){
    int i = 0;
    int numero;
    do{
        printf("Ingresar un numero para la posicion %d(0 para finalizar):\n", (i+1));
        scanf("%d", &numero);

        if(dato_valido(numero)){
            numeros[i] = numero;
            i++;
        }
    }while(i<MF && dato_valido(numero));

    *ml = i;
}

bool dato_valido(int numero){
    return (numero != 0);
}

float calcular_promedios(vector_t numeros, int ml){
    int i, suma = 0;
    float promedio;

    if(ml > 0){
        for(i = 0 ; i < ml; i++){
            suma += numeros[i];
        }
        promedio = (float)suma/ml;
    }else{
        promedio = 0;
    }
    
    return promedio;
}

void calcular_num_mayores(vector_t numeros, int ml, float promedio){
    int i;
    
    if(ml>0){
        printf("Los numeros mayores al promedio son: ");
        for (i=0; i<ml; i++)
            if(numeros[i]>promedio)
                printf("%d \n", numeros[i]);
    }else{
        printf("No se ingresaron numeros.");
    }
}

int main(){
    vector_t numeros;
    int ml;
    float resultado;

    //Cargar
    cargar_datos(numeros, &ml);
    
    //Calcular
    resultado = calcular_promedios(numeros, ml);
    
    //Mostrar
    printf("El promedio de los numeros es: %0.2f\n", resultado);
    calcular_num_mayores(numeros, ml, resultado);

    return 0;
}