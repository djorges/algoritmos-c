#include <stdio.h>
#include <stdbool.h>

#define DIVISOR 10

void procesar_numero(int num, int *par_mayor, int *cant_impares){
    int ult_digito;
    *par_mayor = -1;
    *cant_impares = 0;

    //caso particular.
    if(num == 0){
        *par_mayor = 0;
    }

    while(num != 0){
        ult_digito = num % DIVISOR;
        
        //verif par
        if(ult_digito % 2 == 0){
            if(ult_digito > par_mayor){
                *par_mayor = ult_digito;
            }
        }else{
            (*cant_impares)++;
        }

        num = num / DIVISOR;
    }

}

int main(){
    int num = 120;
    int par_mayor, cant_impares;

    procesar_numero(num, &par_mayor, &cant_impares);

    return 0;
}