/*La secuencia se define matemáticamente como la suma de los dos números anteriores. desde el 0.*/

#include <stdio.h>

int fibonacci(int numero){ 
    //ej num=2: 1 + 0  (corta)
    //ej num=3: 2 + 1
    if(numero <= 1) // caso base 
        return numero;
    else
        return fibonacci(numero - 1) + fibonacci(numero - 2); // a partir del 2
}