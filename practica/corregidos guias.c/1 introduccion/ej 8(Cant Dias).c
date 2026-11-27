/*
8) Dado un mes escribir la cantidad de días de dicho mes.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int mes, anio, cant_dias;

    //Ingresar
    printf("%s \n","Ingresar un mes:");
    scanf("%d", &mes);

    printf("%s \n","Ingresar un año:");
    scanf("%d", &anio);

    //Calcular
    if(1<= mes <=12){
        //tipo mes
        if(mes == 2){ //Febrero
            if(anio % 4 == 0 || (anio % 100 == 0 && anio % 400 == 0)){
                cant_dias = 29; // bisiesto
            }else{
                cant_dias = 28; //no bisiesto
            }
        }else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){ //Abril, Junio, Septiembre y Noviembre
            cant_dias = 30; 
        }else{   //Enero, Marzo, Mayo, Julio, Agosto, Octubre y Diciembre
            cant_dias = 31; 
        }
    }else{
        cant_dias = -1;
    }

    //Mostrar
    if(cant_dias != -1){
        printf("%s %d %s \n","El mes tiene ", cant_dias," días.");
    }else{
        printf("%s \n","Mes Ingresado: Inválido");
    }

    system("PAUSE");

    return EXIT_SUCCESS;
}