#include<stdio.h>
#include<stdlib.h>

#define MF 5

typedef int tvector[MF];

void mostrar(tvector vector, int n)
{
  int k;    
  for(k=0; k<n; k++)
    printf("%d ",vector[k]);
}

void ordenar_insercion(tvector vector, int n)
{
    int j, i, aux;

    for(j=1; j<n; j++){
        aux = vector[j]; //tomo vector[1]
        i = j-1;         //tomo anterior vector[0]

        while(i >= 0 && vector[i] > aux){
            vector[i+1] = vector[i];      // desplazo para la derecha el dato de vector[i] 
            i--;                          // desplazo indice 
        }

        vector[i+1] = aux;   //coloco aux en su lugar(que es donde quedo el indice i+1)
    }
}

int main(){
    tvector vec={4,3,5,2,1};

    printf("\n\nMETODO DE INSERCION\n");
    ordenar_insercion(vec, MF);

    return EXIT_SUCCESS;
}