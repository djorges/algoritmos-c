#include <stdio.h>
#include <string.h>

typedef struct{
    int codigo;    
    char descripcion[30];
    float cantidad;
} t_regProducto;

void cargar_datos(FILE *arProductos){
    t_regProducto regProducto;

    printf("Ingrese codigo de articulo: ");
    scanf("%d", &regProducto.codigo);
    fflush(stdin);

    while (regProducto.codigo != 0)
    {
        printf("Descripción: ");
        scanf("%30[^\n]s", regProducto.descripcion);
        fflush(stdin);

        printf("Cantidad en stock: ");
        scanf("%f", &regProducto.cantidad);
        fflush(stdin);

        //Escribir datos
        fwrite(&regProducto, sizeof(t_regProducto), 1, arProductos);

        printf("\n Ingrese otro codigo de articulo: ");
        scanf("%d", &regProducto.codigo);
        fflush(stdin);
    }
}

void main(){
    FILE *arProductos;

    //abrir archivo
    arProductos = fopen("productos.dat", "wb");
    
    if(arProductos == NULL){
        printf("\nNo se pudo crear el archivo!\n");
    }else{
        cargar_datos(arProductos);

        //cerrar archivo
        fclose(arProductos);
    }

    return;
}