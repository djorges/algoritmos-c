/*(No recomendado)
Escribir un programa modular en lenguaje C, que solicite el ingreso de 10 numeros y 
luego muestre el promedio y todos los numeros superiores al promedio calculado.
*/
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef int v_nums[LENGTH];

void ingresar_valores(v_nums arreglo, int length){
    int i;
    for(i=0; i<length; i++){
        int numero;
        printf("%s \n", "Ingrese un numero");
        scanf("%d", &numero);
        
        arreglo[i] = numero;
    }
}

float calcular_promedio(v_nums arreglo, int length){
    int i, suma = 0;

    for(i=0; i<length; i++){
        suma += arreglo[i];
    }

    return (float) suma / (float) LENGTH;
}

void calcular_mayores_promedio(v_nums arreglo, int length,float promedio){
    int i;
    for(i = 0; i <= length; i++){
        if(promedio<arreglo[i]){
            printf("%d \n", arreglo[i]);
        }
    }
}


int main(){
    v_nums arreglo;
    float promedio;

    ingresar_valores(arreglo, LENGTH);
    promedio = calcular_promedio(arreglo, LENGTH);
    printf("%s %.3f \n","El promedio es:", promedio);
    printf("%s \n", "Los números mayores al promedio son:");
    calcular_mayores_promedio(arreglo, LENGTH, promedio);

    system("PAUSE");
    return EXIT_SUCCESS;
}