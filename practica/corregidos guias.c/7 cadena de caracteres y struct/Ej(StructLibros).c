/* (No recomendado)
Sistema de stock de una librería

Una librería desea llevar el control de los libros disponibles en stock utilizando un vector de estructuras.

Cada libro posee la siguiente información:

Código numérico
Título
Autor
Precio
Cantidad en stock

1) Carga de datos

Permitir ingresar hasta MAX_LIBROS libros.

La carga finaliza cuando se ingresa código 0.

2) Mostrar listado completo

Mostrar todos los libros en formato de tabla.

3) Ordenamientos

Realizar los siguientes ordenamientos:

a) Por título (ascendente)
b) Por stock (descendente)
c) Por código (ascendente)

4)Búsqueda binaria

Una vez ordenado el vector por código, realizar una búsqueda binaria para encontrar un libro a partir de su código.

5)Informes
a) Mostrar el libro más caro.

b) Mostrar todos los libros con stock menor a 5.

c) Calcular el valor total del inventario
*/

#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 100

typedef struct {
    int codigo;
    char titulo[50];
    char autor[50];
    float precio;
    int stock;
} Libro;


void cargarLibros(Libro libros[], int *n);
void mostrarLibros(Libro libros[], int n);

void ordenarPorTitulo(Libro libros[], int n);
void ordenarPorStock(Libro libros[], int n);
void ordenarPorCodigo(Libro libros[], int n);

int busquedaBinaria(Libro libros[], int n, int codigoBuscado);

void libroMasCaro(Libro libros[], int n);
void stockMenor5(Libro libros[], int n);
void valorInventario(Libro libros[], int n);

int main() {

    Libro libros[MAX_LIBROS];
    int n = 0;
    int codigoBuscar, pos;

    // 1) Carga
    cargarLibros(libros, &n);

    // 2) Mostrar listado completo
    printf("\n===== LISTADO COMPLETO =====\n");
    mostrarLibros(libros, n);

    // 3a) Ordenar por título
    ordenarPorTitulo(libros, n);
    printf("\n===== ORDENADO POR TITULO =====\n");
    mostrarLibros(libros, n);

    // 3b) Ordenar por stock
    ordenarPorStock(libros, n);
    printf("\n===== ORDENADO POR STOCK =====\n");
    mostrarLibros(libros, n);

    // 3c) Ordenar por código
    ordenarPorCodigo(libros, n);
    printf("\n===== ORDENADO POR CODIGO =====\n");
    mostrarLibros(libros, n);

    // 4) Búsqueda binaria
    printf("\nIngrese codigo a buscar: ");
    scanf("%d", &codigoBuscar);

    pos = busquedaBinaria(libros, n, codigoBuscar);

    if(pos != -1) {
        printf("\nLibro encontrado:\n");
        printf("%d - %s - %s - %.2f - Stock: %d\n",
               libros[pos].codigo,
               libros[pos].titulo,
               libros[pos].autor,
               libros[pos].precio,
               libros[pos].stock);
    } else {
        printf("Libro no encontrado.\n");
    }

    // 5a) Libro más caro
    libroMasCaro(libros, n);

    // 5b) Stock menor a 5
    stockMenor5(libros, n);

    // 5c) Valor total inventario
    valorInventario(libros, n);

    return 0;
}


void cargarLibros(Libro libros[], int *n) {

    int i = 0;

    printf("===== CARGA DE LIBROS =====\n");

    printf("\nCodigo (0 para finalizar): ");
    scanf("%d", &libros[i].codigo);

    while(libros[i].codigo == 0 && i < MAX_LIBROS) {

        printf("Titulo: ");
        fgets(libros[i].titulo, 50, stdin);
        fflush(stdin);

        printf("Autor: ");
        fgets(libros[i].autor, 50, stdin);
        fflush(stdin);

        printf("Precio: ");
        scanf("%f", &libros[i].precio);

        printf("Stock: ");
        scanf("%d", &libros[i].stock);

        printf("\nCodigo (0 para finalizar): ");
        scanf("%d", &libros[i].codigo);

        i++;
    }

    *n = i;
}


void mostrarLibros(Libro libros[], int n) {

    int i;

    printf("\n%-10s %-25s %-20s %-10s %-10s\n",
           "CODIGO", "TITULO", "AUTOR", "PRECIO", "STOCK");

    for(i = 0; i < n; i++) {

        printf("%-10d %-25s %-20s %-10.2f %-10d\n",
               libros[i].codigo,
               libros[i].titulo,
               libros[i].autor,
               libros[i].precio,
               libros[i].stock);
    }
}


void ordenarPorTitulo(Libro libros[], int n) {

    int i, j;
    Libro aux;

    for(i = 0; i < n - 1; i++) {

        for(j = 0; j < n - i - 1; j++) {

            if(strcmp(libros[j].titulo, libros[j + 1].titulo) > 0) {

                aux = libros[j];
                libros[j] = libros[j + 1];
                libros[j + 1] = aux;
            }
        }
    }
}


void ordenarPorStock(Libro libros[], int n) {

    int i, j;
    Libro aux;

    for(i = 0; i < n - 1; i++) {

        for(j = 0; j < n - i - 1; j++) {

            if(libros[j].stock < libros[j + 1].stock) {

                aux = libros[j];
                libros[j] = libros[j + 1];
                libros[j + 1] = aux;
            }
        }
    }
}


void ordenarPorCodigo(Libro libros[], int n) {

    int i, j;
    Libro aux;

    for(i = 0; i < n - 1; i++) {

        for(j = 0; j < n - i - 1; j++) {

            if(libros[j].codigo > libros[j + 1].codigo) {

                aux = libros[j];
                libros[j] = libros[j + 1];
                libros[j + 1] = aux;
            }
        }
    }
}


int busquedaBinaria(Libro libros[], int n, int codigoBuscado) {

    int inicio = 0;
    int fin = n - 1;
    int medio;
    int posicion = -1;

    while(inicio <= fin && posicion == -1) {

        medio = (inicio + fin) / 2;

        if(libros[medio].codigo == codigoBuscado) {

            posicion = medio;

        } else {

            if(codigoBuscado < libros[medio].codigo) {
                fin = medio - 1;
            } else {
                inicio = medio + 1;
            }
        }
    }

    return posicion;
}


void libroMasCaro(Libro libros[], int n) {

    int i;
    int pos = 0;

    for(i = 1; i < n; i++) {

        if(libros[i].precio > libros[pos].precio) {
            pos = i;
        }
    }

    printf("\n===== LIBRO MAS CARO =====\n");

    printf("%d - %s - %.2f\n",
           libros[pos].codigo,
           libros[pos].titulo,
           libros[pos].precio);
}


void stockMenor5(Libro libros[], int n) {

    int i;

    printf("\n===== LIBROS CON STOCK MENOR A 5 =====\n");

    for(i = 0; i < n; i++) {

        if(libros[i].stock < 5) {

            printf("%d - %s - Stock: %d\n",
                   libros[i].codigo,
                   libros[i].titulo,
                   libros[i].stock);
        }
    }
}


void valorInventario(Libro libros[], int n) {

    int i;
    float total = 0;

    for(i = 0; i < n; i++) {

        total += libros[i].precio * libros[i].stock;
    }

    printf("\nValor total del inventario: %.2f\n", total);
}