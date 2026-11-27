/*Sumar los digitos de un numero*/
int sumarDigitos(int n){
    if(n<10){
        return n;
    }else{
        return n % 10 + sumarDigitos(n/10);
    }
}