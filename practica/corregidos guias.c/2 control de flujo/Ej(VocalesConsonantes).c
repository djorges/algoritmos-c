/*

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int contador_vocales = 0;
    int contador_consonantes = 0;
    char car;

    //Ingresar
    printf("Ingrese un texto terminado en '.': ");
 	scanf("%c", &car);

    //Calcular
    while(car != '.'){
        //valido vocal o si está en abecedario.
        if((car == 'a' || car =='e' || car == 'i' || car == 'o' || car == 'u') ||
        (car == 'A' || car =='E' || car == 'I' || car == 'O' || car == 'U'))
            contador_vocales++;
        else if((car >= 'a' && car <= 'z') || (car>= 'A' && car<='Z'))
            contador_consonantes++;
        
        scanf("%c", &car);
    }

    //Mostrar
    printf("La cantidad de vocales es: %d \n", contador_vocales);
    printf("La cantidad de consonantes es: %d \n", contador_consonantes);
    
    system("PAUSE");
    return 0;
}