/**  scanf - for
Generar un dibujo por pantalla con el siguiente patrón
solicitando al usuario la altura.

(ejemplo altura=5)

Dibujo por pantalla:

*
**
***
****
*****

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j;
    int altura;
    
    printf("Dibujo: \n");
    scanf("%d", altura);

    for(i = 1; i <= altura; i++ ){
        for(j = 1; j <= i; j++){
            printf("*");
        }

        printf("\n");
    }

    system("PAUSE");

    return 0;
}