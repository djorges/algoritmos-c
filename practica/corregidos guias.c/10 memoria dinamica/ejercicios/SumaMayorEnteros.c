
#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD 4

void cargarEnteros(int *enteros, int cantidad);
void mostrarEnteros(const int *enteros, int cantidad);
void mostrarDirecciones(const int *enteros, int cantidad);
int calcularSuma(const int *enteros, int cantidad);
int buscarMayor(const int *enteros, int cantidad);

int main(void) {
    int *enteros = NULL;
    int cantidad = CANTIDAD;

    enteros = malloc(cantidad * sizeof(int));

    if (enteros == NULL) {
        fprintf(stderr, "Error al reservar memoria.\n");
        return EXIT_FAILURE;
    }

    printf("Memoria reservada exitosamente.\n");

    cargarEnteros(enteros, cantidad);

    mostrarEnteros(enteros, cantidad);
    mostrarDirecciones(enteros, cantidad);

    printf("Suma: %d\n", calcularSuma(enteros, cantidad));
    printf("Mayor: %d\n", buscarMayor(enteros, cantidad));

    free(enteros);
    enteros = NULL;

    printf("Memoria liberada correctamente.\n");

    return EXIT_SUCCESS;
}

void cargarEnteros(int *enteros, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese el valor %d: ", i + 1);

        if (scanf("%d", enteros + i) != 1) {
            fprintf(stderr, "Entrada invalida.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void mostrarEnteros(const int *enteros, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("Posicion %d: %d\n", i + 1, *(enteros + i));
    }
}

void mostrarDirecciones(const int *enteros, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("Posicion %d | Direccion: %p | Valor: %d\n",
               i + 1, (const void *)(enteros + i), *(enteros + i));
    }
}

int calcularSuma(const int *enteros, int cantidad) {
    int suma = 0;

    for (int i = 0; i < cantidad; i++) {
        suma += *(enteros + i);
    }

    return suma;
}

int buscarMayor(const int *enteros, int cantidad) {
    int mayor = *enteros;

    for (int i = 1; i < cantidad; i++) {
        if (*(enteros + i) > mayor) {
            mayor = *(enteros + i);
        }
    }

    return mayor;
}
