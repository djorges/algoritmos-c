#include <stdio.h>

int buscar(int numeros[], int numero, int inicio, int fin){
    int centro = (inicio + fin) / 2;


    if(fin < inicio)
        return -1;
    else    
        if(numero < numeros[centro])
            return buscar(numeros, numero, inicio, centro -1);
        else
            if(numero > numeros[centro])
                return buscar(numeros, numero, centro + 1, fin);
            else
                if(numero == numeros[centro])
                    return centro;
}

int main(){
    int v[] = {2, 5, 8, 12, 15, 20};

    int pos = buscar(v, 12, 0, 5);
    // devuelve 3

    printf("%d\n", pos);
    
    return 0;
}