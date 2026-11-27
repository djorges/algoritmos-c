/* mostrar x numeros naturales*/

#include <stdio.h>

void mostrar(int x){
    if(x>0){
        printf("%d",x);
        mostrar(x-1);
    }
}