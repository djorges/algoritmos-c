#include <stdio.h> 
#include <string.h> 
int main () { 
    char src[50] = "Esta es la cadena a ser concatenada";  
    char dest[90] = "Esta es la cadena destino"; 
    
    strcat(dest, src); 
    printf("Final destination string : |%s|", dest); 
    
    return(0); 
} 