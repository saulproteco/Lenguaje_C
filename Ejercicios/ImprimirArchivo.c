/*==================================================*
 * Programa para imprimir el contenido un archivo a *
 * la salida estandar carácter por carácter.        *
 *==================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOMBRE 100

void imprimir_archivo(FILE * archivo);

int main(int argc, const char ** argv) {
    char nombre[TAM_NOMBRE];
    FILE * archivo = NULL;

    // ##### Estableciendo el archivo a imprimir #####
    if ( argc != 2 ) /* Nombre del programa + nombre del archivo */ {

        printf("Ingresa el nombre del archivo con todo y extensión: ");
        fgets(nombre, TAM_NOMBRE, stdin);

        if ( nombre[strlen(nombre) - 1] == '\n' ) // Se quita el salto de línea
            nombre[strlen(nombre) - 1] = '\0';
    } else {
        strncpy(nombre, argv[1], 100);
    }


    // ##### Abriendo el archivo #####
    archivo = fopen(nombre, "r");

    if ( archivo == NULL ) {
        fprintf(stderr, "Error al abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    // ##### Imprimiendo el archivo #####
    puts("Los contenidos del archivo son:");
    puts("\n============================= INICIO DE ARCHIVO ================================\n");

    imprimir_archivo(archivo);
    puts("\n\n============================= FINAL DE ARCHIVO =================================\n");

    // ##### Cerrando el archivo #####
    fclose(archivo);
    return EXIT_SUCCESS;
}

void imprimir_archivo(FILE * archivo) {
    int lineas = 1;
    char caracter = fgetc(archivo);

    printf("%3d. ", lineas);

    while ( caracter != EOF ) {
        putchar(caracter);

        if ( caracter == '\n' ) {

            if ( lineas % 22 == 0 )
                getchar();

            printf("%3d. ", ++lineas);
        }


        caracter = fgetc(archivo);
    }

}
