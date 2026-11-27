#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 100

int main(){
    int tabla;
    int j;

    printf("%s \n", "Tabla de multiplicaciones");
    for(tabla = 1; tabla <= 9; tabla++){
        printf("\n %s %d: \n", "Fila", tabla);
        for (j = 0; j < MAX_VALUE ; j++)
        {
            printf("%d,",tabla*j); 
        }
    }

    system("PAUSE");

    return 0;
}