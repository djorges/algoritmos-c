/*

Escribir una función en C que reciba como parámetro un numero entero y devuelva al modulo invocante los siguientes valores:
- el resultado de multiplicar sus digitos pares y
- la cantidad de digitos que cumplieron la condicion y fueron procesados. 

Por ejemplo: 

-> el número con el que se invoca la funcion es 25831 
-> los digitos pares son 2 y 8 
-> La funcion debe devolver los valores: 16 y 2. El 16 por el producto, y el 2 por la cantidad de dígitos.

Nota: para la resolucion de este ejercicio no se pueden utilizar arreglos.
*/

#include <stdio.h>

void procesar(int num, int *multi_pares, int *cant_pares){
    int digito;
    *multi_pares = 1;
    *cant_pares = 0;

    while(num != 0){
        digito = num % 10;
        //verifico par
        if(digito % 2 == 0){
            *multi_pares = *multi_pares * digito;
            (*cant_pares)++;
        }
        
        num = num / 10;
    }

    if(*cant_pares == 0){
        *multi_pares = 0;
    }
}

int main(){
    int multi_pares;
    int cant_pares;
    int numero = 25831;

    procesar(numero, &multi_pares, &cant_pares);

    printf("Producto de digitos pares: %d\n", multi_pares);
    printf("Cantidad de digitos pares: %d\n", cant_pares);


    return 0;
}

