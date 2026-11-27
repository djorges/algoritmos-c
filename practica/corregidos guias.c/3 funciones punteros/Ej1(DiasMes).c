/** do-while  -  
 * Escribir una función que reciba un mes y un año; y devuelva la cantidad de días
del mes, considerando los años bisiestos.
Tenga en cuenta que un año bisiesto es aquel divisible por 4, salvo que sea
divisible por 100, en cuyo caso también debe ser divisible por 400.
 * 
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int mes, anio;
    int resultado;

    ingresar(&mes, &anio);

    resultado = procesar(mes, anio);

    mostrar(resultado);

    system("PAUSE");

    return 0;
}

void ingresar(int *mes, int *anio){
    int status_mes, status_anio;

    do{
        printf("%s \n", "Ingresar un mes:");
        status_mes = scanf("%d", mes);

        printf("%s \n", "Ingresar un año:");
        status_anio = scanf("%d", anio);
    }while((status_mes != 0 || status_mes != EOF) && (status_anio != 0 || status_anio != EOF));

}

int procesar(int mes, int anio){
    int cant_dias;

    if(1<=mes<=12){
        if (mes == 2){
            if (anio % 4 == 0 || (anio % 100 == 0 && anio % 400 == 0)){
                cant_dias = 29;//Febrero Bisiesto
            }else{
                cant_dias = 28;//Febrero No Bisiesto
            }
        }else if( mes == 4 || mes == 6 || mes == 9 || mes == 11){
            cant_dias = 30; //Abril, Junio, Septiembre y Noviembre
        }else{
            cant_dias = 31; //Enero, Marzo, Mayo, Julio, Agosto, Octubre y Diciembre
        }
    }else{
        cant_dias = -1;
    }

    cant_dias;
}

void mostrar(resultado){
    if(resultado != -1){
        printf("%s %s \n","El mes tiene ", resultado," días.");
    }else{
        printf("%s \n","Mes Ingresado: Inválido");
    }
}
