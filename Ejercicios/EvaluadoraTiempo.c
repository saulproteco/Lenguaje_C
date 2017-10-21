/*===================*
 * Respuesta Tarea 4 *
 * Evaluador tiempo  *
 *===================*/

#include <stdio.h>      // printf, putchar
#include <stdlib.h>     // malloc
#include <math.h>       // pow, fabs
#include <time.h>       // clock

#define TAM_ARREGLO(_x) (sizeof(_x) / sizeof(_x[0]))

#define COLUMNAS_MATRIZ 30
#define FILAS_MATRIZ    20

clock_t evaluarTiempo(void (*funcion)(void), int repeticiones);

void funcion1(void);
void funcion2(void);
void funcion3(void);
void funcion4(void);
void funcion5(void);

void (*arregloFunciones[]) = {
    funcion1,
    funcion2,
    funcion3,
    funcion4,
    funcion5
};

int main(int argc, char * restrict argv[]) {
    int repeticiones = 1000;
    clock_t tiempo[TAM_ARREGLO(arregloFunciones)];

    if ( argc == 2 ) {
        if ( !sscanf(argv[1], "%d", &repeticiones) )
            fprintf(stderr, "El argumento es inválido\n"), exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < TAM_ARREGLO(arregloFunciones); i++)
        tiempo[i] = evaluarTiempo(arregloFunciones[i], repeticiones);

    for (size_t i = 0; i < TAM_ARREGLO(arregloFunciones); i++)
        printf("El tiempo de ejecución de la función %d "
               "es: %ld\n", i + 1, tiempo[i]);

    return EXIT_SUCCESS;
}

clock_t evaluarTiempo(void (*funcion)(void), int repeticiones) {
    clock_t inicio, fin;

    puts("Ejecutando la función:");
    inicio = clock();

    for (int i = 0; i < repeticiones; i++)
        funcion();

    fin = clock();

    return fin - inicio;
}

void funcion1(void) {
    // Reservar y usar matriz de 50 * 20 con un ciclo.
    int ** matriz;

    // Reservando las filas.
    matriz = (int **) malloc(sizeof(int *) * FILAS_MATRIZ);

    for (int i = 0; i < FILAS_MATRIZ; i++)
        matriz[i] = malloc(sizeof(int) * COLUMNAS_MATRIZ);

    // Usando la matriz.
    for (int f = 0; f < FILAS_MATRIZ; f++) {
        for (int c = 0; c < COLUMNAS_MATRIZ; c++) {
            matriz[f][c] = f - c;
        }
    }

    // Imprimiendo la matriz
    for (int f = 0; f < FILAS_MATRIZ; f++) {
        for (int c = 0; c < COLUMNAS_MATRIZ; c++) {
            printf("%+3d ", matriz[f][c]);
        }
        putchar('\n');
    }

    // Liberando la matriz
    for (int f = 0; f < FILAS_MATRIZ; f++)
        free(matriz[f]);

    free(matriz);
}

void funcion2(void) {
    // Reservar y usar una 20 filas de 50 de largo.
    int (*matriz)[COLUMNAS_MATRIZ];

    // Reservando las filas.
    matriz = (int (*)[COLUMNAS_MATRIZ]) malloc(sizeof(*matriz) * FILAS_MATRIZ);

    // Usando la matriz.
    for (int f = 0; f < FILAS_MATRIZ; f++) {
        for (int c = 0; c < COLUMNAS_MATRIZ; c++) {
            matriz[f][c] = f - c;
        }
    }

    // Imprimiendo la matriz.
    for (int f = 0; f < FILAS_MATRIZ; f++) {
        for (int c = 0; c < COLUMNAS_MATRIZ; c++) {
            printf("%+3d ", matriz[f][c]);
        }
        putchar('\n');
    }

    // Liberando la matriz.
    free(matriz);
}

void funcion3(void) {
    printf("Hola\n");
}

void funcion4(void) {
    int p = rand(), q = rand(), r = rand();
    int i = fabs(pow(p, q)) / r;

    printf("%d\n", i);
}

void funcion5(void) {
    static int cosa = 0;

    if ( cosa == 1000 ) {
        cosa = 0;
        return;
    }

    cosa++;
    funcion5();
}
