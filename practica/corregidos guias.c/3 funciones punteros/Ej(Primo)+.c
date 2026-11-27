/** primo - do-while - bool -
    Escribir una función que reciba un número y devuelva un valor booleano
    indicando si el número recibido es ó no primo. Si desconoce como devolver un
    valor booleano, puede devolver 0, en caso de No ser primo; y 1, si lo es.

    Definicion primo:
    Un número primo es un número natural mayor que 1 que tiene exactamente dos divisores positivos distintos:
   solo se puede dividir de forma exacta por 1 y por sí mismo.

    Ejemplos:
    2 → primo (solo divisible por 1 y 2)
    3 → primo
    5 → primo
    7 → primo
    No son primos:
    4 → (divisible por 1, 2 y 4)
    6 → (divisible por 1, 2, 3 y 6)
*/
#include <stdio.h>
#include <stdbool.h>

void cargar_datos(int *numero){
    do{
        printf("%s \n", "Ingrese un numero positivo:");
        scanf("%d", numero);
    }while(*numero < 0);
}

bool procesar_datos(int numero){ // numero = 1 , 2 , 6
    bool primo = true;
    int divisor = 2;

    while(primo && divisor <= numero / 2){ //true && 2 <= 1 / 2 = false , true && 2 <= 2 / 2 = false, true && 2 <= 6 / 2 = true
        if(numero % divisor == 0) // 6 % 2 == 0
            primo = false;  
        divisor++; // 2, 3, 4
    }

    return primo; //true , true , false
}

void mostrar_datos(bool es_primo){
    if(es_primo){
        printf("%s \n", "Primo");
    }else{
        printf("%s \n", "No primo");
    }
}

int main(){
    int numero;
    bool es_primo;

    cargar_datos(&numero);
    es_primo = procesar_datos(numero);
    mostrar_datos(es_primo);

    return 0;
}