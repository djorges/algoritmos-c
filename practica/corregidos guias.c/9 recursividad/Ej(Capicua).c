#include <stdio.h>
#include <stdbool.h>

#define MAX 30

//funcion recursiva auxiliar
bool esCapicuaRec(int v[], int inicio, int fin){
    if(inicio >= fin) //caso base 1. terminó de recorrer el vector(es capicua)
        return true;
    if(v[inicio] != v[fin]) //caso base 2. un elemento es distinto de otro.(no es capicua)
        return false;
    
    return esCapicuaRec(v, inicio + 1, fin - 1);
}

bool esCapicua(int vec[], int ml){
    return esCapicuaRec(vec, 0, ml - 1);
}

int main(){
    int vector[MAX] = {1,2,3,4,5,6,5,4,3,2,1};
    int ml = 11;

    if(esCapicua(vector, ml)){
        printf("El vector es capicua \n");
    }else{
        printf("El vector no es capicua \n");
    }

    return 0;
}