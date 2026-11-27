/*
    Solicitar al usuario un numero natural positivo entre 1 y 1000.
    Solicitarlo multiples veces hasta que sea válido.
    Luego si el número ingresado es primo se pide mostrar como resultado
    el factorial del mismo, en el caso que no sea prime se
    pide mostrar como resultado la suma n-esima parcial del numero -> (n*(n+1))/2
*/
#include <stdio.h>
#include <stdbool.h>


void solicitar_valor(int *valor){
    do{
        printf("Ingrese un valor entero positivo entre 1-1000: ");
        scanf("%d",valor);
    }while(*valor < 1 || *valor > 1000);
} 

int calcular(int value){
    int resultado = 0;

    if(es_primo(value)){
        resultado = factorial(value);
    }else{
        resultado = suma_n(value);
    }

    return resultado;
}

bool es_primo(int num){
    bool primo = true;
    int divisor = 2;

    while(primo && divisor <= num / 2){ //numero dividido por divisor hasta que el ultimo sea la mitad del numero
        if(num % divisor == 0){
            primo = false;
        }
        divisor++;
    }

    return primo;
}

int factorial(int num){
    int fact;
    int i;

    if(num == 0 || num == 1){
        fact = 1;
    }else{
        fact = 1;
        for(i = 1; i <= num; i++){
            fact = fact * i;
        }
    }

    return fact;
}

int suma_n(int n){
    return (n*(n+1))/2;
}


int main(){
    int valor;
    int resultado;

    solicitar_valor(&valor);

    resultado = calcular(valor);

    //mostrar
    printf("El resultado es: %d \n", resultado);

    return 0;
}