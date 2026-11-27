#include <stdio.h>

void cargar_datos(int *a, int *b){
    do{
        printf("%s \n", "Ingrese un numero positivo:");
        scanf("%d", a);

        printf("%s \n", "Ingrese otro numero positivo:");
        scanf("%d", b);

    }while(*a < 0 || *b < 0);
}

int mcd(int a, int b){
    int aux;

    if(a<0) a = -a;
    if(b<0) b = -b;

    while(b != 0){
        aux = b;
        b = a % b;
        a = aux;
    }

    return a;
}

int mcm(int a, int b){
    return (a*b) / mcd(a,b);
}

int main(){
    int a, b;
    int resultado;

    cargar_datos(&a, &b);
    resultado = mcm(a, b);

    return 0;
}