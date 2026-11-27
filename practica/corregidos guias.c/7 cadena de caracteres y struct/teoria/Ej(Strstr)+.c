/*
    Substring

    Descripción
    La función char *strstr(const char *haystack, const char *needle) encuentra la primer ocurrencia
    de la subcadena needle en la cadena haystack. Los caracteres de fin de cadena '\0' no son
    comparados.

    Declaración
    Declaración de la función strstr().
    char *strstr(const char *haystack, const char *needle) 
    
    Parámetros
    haystack o string1 − Es la cadena principal sobre la cual se buscará.
    needle o substring1 − Es la pequeña cadena que será buscada sobre la cadena principal.
    
    Valor de Retorno
    Esta función retorna un puntero a la primer ocurrencia sobre la cadena principal en donde hubo
    coincidencia con la pequeña cadena, caso contrario retorna null
*/

#include <stdio.h>
#include <string.h>

int main(){
    const char string1[] = "UsoDeFuncionStrsrtParaBuscarStrings"; 
    const char substring1[10] = "Funcion"; 
    char *ret;

    ret = strstr(string1, substring1);

    printf("The substring is: %s\n", ret);

    return 0;
}
//The substring is: FuncionStrsrtParaBuscarStrings 
