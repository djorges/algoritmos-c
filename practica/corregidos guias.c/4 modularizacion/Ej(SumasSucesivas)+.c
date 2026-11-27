/**
 * Escribir un programa que solicite el ingreso de 2 valores enteros y luego informe
el resultado de multiplicarlos, pero mediante sumas sucesivas.
Optimizar el cálculo, realizando la menor cantidad de ciclos posibles.
Tener en cuenta que el usuario puede ingresar valores negativos.
 * 
*/

#include <stdio.h>

void cargar_datos(int *x, int *y){
    printf("%s \n","Ingrese un número:");
    scanf("%d",x);

    printf("%s \n","Ingrese otro número:");
    scanf("%d",y);
}

int calcular_absoluto(int num){
    return (num < 0)? -num : num;
}

int procesar_datos(int x, int y){
    int i, res = 0;
    int nro_menor, nro_mayor;
    int xp = calcular_absoluto(x);
    int yp = calcular_absoluto(y);

    //calcular menor
    if(xp<yp){
        nro_menor = xp;
        nro_mayor = yp;
    }else{
        nro_menor = yp;
        nro_mayor = xp;
    }


    for(i=0; i<nro_menor; i++){ //ej menor 3; mayor 5
        res += nro_mayor;
    }

    return res;
}

void mostrar_datos(int resultado){
    printf("%s %d\n","El resultado es:",resultado);
}

int main(){
    int x, y;
    int resultado;

    cargar_datos(&x, &y);

    resultado = procesar_datos(x,y);

    mostrar_datos(resultado);

    return 0;
}