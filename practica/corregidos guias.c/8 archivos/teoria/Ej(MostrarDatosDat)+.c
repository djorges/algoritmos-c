#include <stdio.h>

typedef struct{   
    int codigo;  
    char descripcion[30];
    float cantidad;
} t_regProducto;

void mostrar_datos(FILE *arProductos){
    t_regProducto rProducto;

    //leer linea
    fread(&rProducto,sizeof(t_regProducto),1,arProductos);

    printf("\nCodigo \tDescripcion \t\t\tCantidad");

    while(!feof(arProductos))
    {
        printf("\n %d \t%-30s %8.2f", rProducto.codigo, rProducto.descripcion, rProducto.cantidad);
            
        //leer linea
        fread(&rProducto,sizeof(t_regProducto),1,arProductos);
    }
}

void main(){
    FILE *arProductos;

    // abrimos el archivo en modo lectura
    arProductos = fopen("productos.dat", "rb");

    if(arProductos == NULL)
        printf("\nNo se pudo abrir el archivo!\n");
    else{
        mostrar_datos(arProductos);

        //cerrar archivo
        fclose(arProductos);
    }

}