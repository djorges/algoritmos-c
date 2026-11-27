/** scanf, printf
 
Dada una serie de numeros positivos ingresados de a uno, y finalizada en cero.
Indicar mayor, menor y promedio(suma/contador) de la serie.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int maximo;
    int minimo; 
    int suma = 0;
    int numero; 
    int contador = 0;

    //Ingresar
    printf("%s \n","Ingrese un número:");
    scanf("%d", &numero);

    //Calcular
    maximo = minimo = numero;  
    while(numero>0){ //2da it: numero 9, maximo = minimo = 10, suma = 
        //Acumular para promedio
        suma += numero;
        contador++;

        //max min
        if(numero > maximo){
            maximo = numero;
        }else if(numero<minimo){
            minimo = numero;
        }

        printf("%s \n","Ingrese un número:");
        scanf("%d", &numero);
    }

    //Mostrar 
    printf("%s %d\n","El máximo es:",maximo);
    printf("%s %d\n","El mínimo es:",minimo);
    printf("%s %.3f\n","El promedio es:", (float)suma/(float)contador);

    system("PAUSE");

    return 0;
}
