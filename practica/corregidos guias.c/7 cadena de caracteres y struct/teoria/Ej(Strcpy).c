#include <stdio.h> 
#include <string.h> 
int main () { 
    char src[40]; 
    char dest[100]; 

    strcpy(src, "Ejemplo de uso de string copy"); 
    strcpy(dest, src); 
    
    printf("Final copied string : %s\n", dest); 

    return(0); 
} 