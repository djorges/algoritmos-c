/*
    Descripción
    La función int strcmp(const char *str1, const char *str2) compara la cadena apuntada por str1
    con la cadena apuntada por str2    

    Parámetros
    str1 − Es la primer cadena usada en la comparación.
    str2 − Es la segunda cadena usada en la comparación.
    
    Valor de Retorno
    Esta función retorna valores enteros según los siguientes casos:
    si el valor de retorno < 0 entonces str1 es menor a str2.
    si el valor de retorno > 0 entonces str1 es mayor a str2.
    si el valor de retorno = 0 entonces str1 es igual a str2.

*/
#include <stdio.h> 
#include <string.h> 

int main () { 
    char str1[15] = "abcdef"; 
    char str2[15] = "ABCDEF"; 
    int retorno;

    retorno = strcmp(str1, str2);

    if(retorno < 0){
        printf("str1 is less than str2"); 
    } else if(retorno > 0) { 
        printf("str1 is greater than str2"); 
    } else { 
        printf("str1 is equal to str2"); 
    } 

    return 0;
} 