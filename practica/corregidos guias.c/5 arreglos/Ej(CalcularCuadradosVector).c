/* No recomendado 
Declarando un arreglo unidimensional de enteros y modificando su contenido
*/

#include <stdio.h>
#include <stdlib.h>
#define LENGTH 5

typedef int t_vec[LENGTH];

void calcular_cuadrados(t_vec v_nros, int ult_pos){
    int i;
    for(i=0; i<ult_pos; i++)
        v_nros[i] = v_nros[i] * v_nros[i];
}

void mostrar_datos(t_vec v_nros, int ult_pos){
    int i;
    for(i=0; i<ult_pos; i++)
        printf("\t%4i \n", v_nros[i]);
}

void main(){
    t_vec v_nros = {2,4,6,8,10};

    printf("\n %s \n","Vector Original");
    mostrar_datos(v_nros,LENGTH);

    calcular_cuadrados(v_nros,LENGTH);

    printf("\n %s \n","Vector Modificado");
    mostrar_datos(v_nros,LENGTH);

    system("PAUSE");
    return;
}