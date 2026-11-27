/*
ENUNCIADO EJERCICIO: Inserción de elemento en vector
 
Dadas las siguientes declaraciones de constantes y tipos:
#define MAX 100
typedef int t_vector[MAX]

Desarrollar una funcion en lenguaje C que reciba tres parámetros, un vector del tipo t_vector ya cargado con datos que se encuentran en ORDEN ASCENDENTE, su máximo
lógico y un número entero que debe ser intercalado en el vector, de modo que siga ordenado.

Se espera que la funcion devuelva al módulo invocante true si pudo realizar lo solicitado y false si no pudo hacerlo.
Tanto el vector como el máximo lógico actualizados deben devolverse sobre los parámetros recibidos.

Se solicita resolver lo solicitado recorriendo una sola vez el vector y sin utilizar un arreglo auxiliar.
Esccribir un programa que invoque dicha funcion.


vector -> 1, 2, 5, 9
ml = 4
mf = 5
numero -> 4

------
vector -> 1, 2, 4, 5, 9
ml = 5
mf = 10

*/
#include <stdio.h>
#include <stdbool.h>

#define MAX 100
typedef int t_vector[MAX];

bool insertarOrdenado(t_vector vec, int *ml, int num){
    bool resultado = false;
    int i;

    if(*ml < MAX){
        i = *ml - 1; //5-1 = 4
        while(i >= 0 && vec[i] > num){ // 0 >= 0 && 2 > 4 
            vec[i+1] = vec[i];
            i--;
        }
        
        vec[i+1] = num;
        *ml++;
        
        resultado = true;
    }

    return resultado;
}


void mostrarVector(t_vector vec, int ml)
{
    int i;

    for (i = 0; i < ml; i++)
    {
        printf("%d ", vec[i]);
    }

    printf("\n");
}


int main(){
    t_vector vec = {2, 5, 8, 12, 20};
    int ml = 5;
    int numero = -1;
    bool resultado;

    resultado = insertarOrdenado(vec, &ml, numero);

    if(resultado){
        printf("\nNumero insertado correctamente.\n");
        mostrarVector(vec, ml);
    }else{
        printf("\nNo se pudo insertar el numero. Vector lleno.\n");
    }

    return 0;
}
