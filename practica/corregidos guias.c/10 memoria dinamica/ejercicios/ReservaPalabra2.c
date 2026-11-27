
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdint.h>

#define MAX_CHAR 100

typedef char t_palabra[MAX_CHAR];
typedef char* t_palabra_dinamica;
typedef t_palabra_dinamica* t_texto_dinamico;

// INPUT

int ingresar_num(const char msg[], int *num) {
    char buffer[100];
    char *fin;
    long valor;

    printf("%s", msg);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        return 0;

    valor = strtol(buffer, &fin, 10);

    while (isspace((unsigned char)*fin))
        fin++;

    if (fin == buffer || *fin != '\0' ||
        valor <= 0 || valor > INT_MAX)
        return 0;

    *num = (int) valor;
    return 1;
}

int ingresar_string(const char msg[], t_palabra palabra) {
    size_t longitud;

    printf("%s", msg);

    if (fgets(palabra, MAX_CHAR, stdin) == NULL)
        return 0;

    longitud = strcspn(palabra, "\n");

    if (palabra[longitud] == '\n') {
        palabra[longitud] = '\0';
    } else if (!feof(stdin)) {
        int c;

        while ((c = getchar()) != '\n' && c != EOF);

        printf("[!] La palabra supera el limite permitido.\n");
        return 0;
    }

    return 1;
}

t_palabra_dinamica ingresar_palabra_dinamica() {
    t_palabra aux_palabra;

    if (!ingresar_string("- Ingrese palabra: ", aux_palabra))
        return NULL;

    size_t longitud = strlen(aux_palabra);

    if (longitud == 0) {
        printf("[!] La palabra no puede estar vacia.\n");
        return NULL;
    }

    t_palabra_dinamica palabra = malloc(
        (longitud + 1) * sizeof(char)
    );

    if (palabra == NULL)
        return NULL;

    strcpy(palabra, aux_palabra);

    return palabra;
}

// MEMORY

void liberar_texto_dinamico(
    t_texto_dinamico texto,
    int cantidad_palabras
) {
    if (texto == NULL)
        return;

    for (int i = 0; i < cantidad_palabras; i++)
        free(texto[i]);

    free(texto);
}

t_texto_dinamico ingresar_texto_dinamico(
    int cantidad_palabras
) {
    if (cantidad_palabras <= 0 ||
        (size_t)cantidad_palabras > SIZE_MAX / sizeof(t_palabra_dinamica))
        return NULL;

    t_texto_dinamico texto = calloc(
        (size_t)cantidad_palabras,
        sizeof(t_palabra_dinamica)
    );

    if (texto == NULL)
        return NULL;

    for (int i = 0; i < cantidad_palabras; i++) {
        texto[i] = ingresar_palabra_dinamica();

        if (texto[i] == NULL) {
            printf("[!] Error al cargar la palabra.\n");

            liberar_texto_dinamico(texto, i);
            return NULL;
        }
    }

    return texto;
}

// OUTPUT

void mostrar_texto(
    t_texto_dinamico texto,
    int cantidad_palabras
) {
    if (texto == NULL)
        return;

    for (int i = 0; i < cantidad_palabras; i++) {
        printf(
            "- Palabra %d: '%s' | Direccion: %p\n",
            i + 1,
            texto[i],
            (void *)texto[i]
        );
    }
}

void mostrar_resumen(
    t_texto_dinamico texto,
    int cantidad_palabras
) {
    if (texto == NULL)
        return;

    printf("\n*** RESUMEN DEL TEXTO ***\n");
    printf("Cantidad de palabras: %d\n", cantidad_palabras);

    for (int i = 0; i < cantidad_palabras; i++) {
        printf(
            "Palabra %d: %zu caracteres\n",
            i + 1,
            strlen(texto[i])
        );
    }
}

// MAIN

int main(void) {
    int cantidad_palabras;

    t_texto_dinamico texto = NULL;

    if (!ingresar_num(
            "[+] Ingrese cantidad de palabras: ",
            &cantidad_palabras
        )) {
        printf("[!] Cantidad invalida.\n");
        return EXIT_FAILURE;
    }

    texto = ingresar_texto_dinamico(cantidad_palabras);

    if (texto == NULL) {
        printf("[!] No se pudo cargar el texto.\n");
        return EXIT_FAILURE;
    }

    printf("\n*** TEXTO INGRESADO ***\n");

    mostrar_texto(texto, cantidad_palabras);
    mostrar_resumen(texto, cantidad_palabras);

    liberar_texto_dinamico(texto, cantidad_palabras);

    texto = NULL;

    printf("\n[+] Memoria liberada correctamente.\n");

    return EXIT_SUCCESS;
}
