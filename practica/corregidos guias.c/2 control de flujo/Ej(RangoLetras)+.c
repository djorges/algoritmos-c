/** scanf - fflush - for - char
Ingresar dos letras minúsculas en cualquier orden y
mostrar todas las letras entre las indicadas.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    char letra1, letra2, aux;
    char i;

    printf("Ingrese primer letra: ");
    scanf("%c", &letra1);
    fflush(stdin);

    printf("Ingrese segunda letra: ");
    scanf("%c", &letra2);
    fflush(stdin);

    //si segunda letra es menor a primer
    if(letra2 < letra1){
        aux = letra1;
        letra1 = letra2;
        letra2 = aux;
    }

    printf("Secuencia: ");
    for(i = letra1; i <= letra2; i++){
        printf("%c", i);
    }

    system("PAUSE");

    return 0;   
}