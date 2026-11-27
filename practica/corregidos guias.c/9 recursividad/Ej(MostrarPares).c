/*mostrar numeros pares entre 1 y x*/
#include <stdio.h>

void mostrar_pares_recursivo(int x){
    if(x>1){
        if(x%2 == 0){
            mostrar_pares_recursivo(x-2);
            printf("\n%i", x);
        }else{
            mostrar_pares_recursivo(x-1);
        }
    }
}

int main(){
    int num = 9;

    mostrar_pares_recursivo(num);

    return 0;
}