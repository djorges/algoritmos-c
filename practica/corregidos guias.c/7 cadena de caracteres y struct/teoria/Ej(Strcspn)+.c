/*
    Parecido a Substring

    Descripción
    La función size_t strcspn(const char *str1, const char *str2) calcula el largo sobre el segmento
    inicial de la cadena apuntada por str1 que consiste puramente de caracteres no contenidos en la
    cadena apuntada por str2

    Declaración
    Declaración de la función strcspn().
    size_t strcspn(const char *str1, const char *str2) 
    
    Parámetros
    str1 − Es la cadena principal que será analizada.
    str2 − Es la cadena que contiene los caracteres a ser buscados en la cadena principal

    Valor de Retorno
    Esta función retorna la cantidad de caracteres del segmento inicial de la cadena str1 que no están
    contenidos en str2
*/

//Ejemplo 1:

#include <stdio.h> 
#include <string.h> 


int main () { 
    char string1[20] = "ABCDEF4960910"; 
    char substring1[10] = "013";

    int pos;

    pos = strcspn(string1, substring1);

    printf("Primera coincidencia encontrada en pos = %d\n", pos); 
    
    return 0;
}

// Primera coincidencia encontrada en pos = 9 

//Ejemplo 2
int main(){
    char string1[20] = "ABCDEF4960910\n"; 
    char substring1[2] = "\n";
    int pos;

    pos = strcspn(string1, substring1);
    string1[pos] = '\0'; //reemplazo posicion por caracter de fin de string

    printf("Cadena sin salto de linea: %s\n", string1); 

    return 0;
}
//Cadena sin salto de linea: ABCDEF4960910 
