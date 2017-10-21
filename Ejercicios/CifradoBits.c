/*===================*
 * Respuesta Tarea 2 *
 * Calculadora bits  *
 *===================*/

#include <stdio.h>      // fprintf
#include <stdlib.h>     // exit
#include <string.h>     // strlen
#include <stdbool.h>    // bool

int codificar(const char * nombre_archivo, const char * clave_cifrado);
char * pedir_cadena(const char * const mensaje);
void liberar_memoria(void);

static char * nombre_archivo = NULL;
static char * clave_cifrado = NULL;

int main(int argc, char * restrict argv[]) {

    if ( argc == 3 ) {
        nombre_archivo = argv[1];
        clave_cifrado = argv[2];
    } else if ( argc >= 3 ) {
        fprintf(stderr, "Número de argumentos incorrecto\n");
        exit(EXIT_FAILURE);
    } else {
        nombre_archivo = pedir_cadena("Dame el nombre del archivo: ");
        clave_cifrado = pedir_cadena("Dame la clave de cifrado/descifrado: ");

        // Unicamente se necesita establecer una función para liberar
        // memoria si hemos leido y asignado esta dinamicamente.
        atexit(liberar_memoria);
    }

    return codificar(nombre_archivo, clave_cifrado);
}

int codificar(const char * nombre_archivo, const char * clave_cifrado) {
    FILE * ap_archivo = fopen(nombre_archivo, "r+");
    int caracter;

    if ( ap_archivo == NULL ) {
        fputs("No se pudo abrir el archivo", stderr);
        return(EXIT_FAILURE);
    }

    while ( (caracter = fgetc(ap_archivo)) != EOF ) {
        for (int clave = 0; clave_cifrado[clave]; clave++)
            caracter ^= clave;

        fseek(ap_archivo, -1, SEEK_CUR);    // Regresamos un lugar.
        fputc(caracter, ap_archivo);        // Reescribimos el byte.
        fseek(ap_archivo, 0, SEEK_CUR);     // Esta línea es por compatibilidad.
    }

    fclose(ap_archivo);

    return(EXIT_SUCCESS);
}

char * pedir_cadena(const char * const mensaje) {
    char espacio[100];
    char * nueva_cadena;

    fputs(mensaje, stdout);
    fgets(espacio, 100, stdin);

    nueva_cadena = malloc( (strlen(espacio) + 1) * sizeof(char));

    strcpy(nueva_cadena, mensaje);

    return nueva_cadena;
}

void liberar_memoria(void) {
    free(nombre_archivo);
    free(clave_cifrado);
}
