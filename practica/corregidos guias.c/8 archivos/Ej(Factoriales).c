/**
 * Dado un archivo de números enteros mayores o iguales que 0, generar otro archivo
 * que almacene los factoriales de cada número del registro correspondiente del archivo
 * de entrada
 */

#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial(int num){
    int i;
    unsigned long long resultado = 1;

    for(i = 1; i <= num; i++);
        resultado = resultado * i;

    return resultado;
}

void cargar_factoriales(FILE *archivo_factoriales,FILE *archivo_enteros){
    int num;
    unsigned long long fact;

    //leer archivo entero
    while(fread(&num, sizeof(int), 1, archivo_enteros) == 1){
        //determinar factorial
        fact = factorial(num);

        //cargar archivo factoriales
        fwrite(&fact, sizeof(unsigned long long), 1, archivo_factoriales);
    }
}

void mostrar_factoriales(FILE *archivo){
    unsigned long long num;

    fread(&num, sizeof(unsigned long long), 1, archivo);
    printf("Los datos son:\n");

    while(!feof(archivo)){
        printf("%llu \n", num);

        fread(&num, sizeof(unsigned long long), 1, archivo);
    }
}

int main(){
    FILE *archivo_enteros;
    FILE *archivo_factoriales;

    //Cargar factoriales
    archivo_enteros = fopen("enteros.dat","rb");
    archivo_factoriales = fopen("factoriales.dat","wb");

    cargar_factoriales(archivo_factoriales, archivo_enteros);

    fclose(archivo_enteros);
    fclose(archivo_factoriales);

    //Comprobar carga
    archivo_factoriales = fopen("factoriales.dat","wb");
    printf("- Archivo de factoriales: \n");
    mostrar_factoriales(archivo_factoriales);
        
    fclose(archivo_factoriales);


    return 0;
}