#include <stdio.h> 
#include <string.h> 
int main () { 
    char str[20] = "EjemploDeStrcpm";
    int len;  

    len = strlen(str); 
    printf("Length of |%s| is |%d|\n", str, len);
    
    return(0);
}