/*
    Indicar si un numero es palindromo
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    int aux;
    int ult_digito;
    int num_inverso = 0;

    printf("Ingrese un numero positivo:");
    scanf("%d", &num);


    //Hallar inverso
    aux = num; //Ej aux = num = 10

    while(aux > 0){
        ult_digito = aux % 10; //ult_digito = 0
        num_inverso = (num_inverso * 10) + ult_digito; // num_inverso = 0 + 0
        aux = aux / 10;  // aux = 10 / 10 = 1
    }

    
    if(num == num_inverso){
        printf("Es palindromo");
    }else{
        printf("No es palindromo");
    }
    
    system("PAUSE");

    return 0;
}
