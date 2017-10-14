/* ======================= *
 * Recursividad en cadenas *
 * ======================= */

/*
 * Algunas funciones tipicas de manejo de
 * cadenas implementadas con funciones
 * recursivas.
 */

#include <stdio.h>  // puts, putchar, printf, fgets
#include <stdlib.h> // EXIT_SUCCESS

#define TAMANIO_BUFF 100

#define NORMAL  0
#define REVERSA 1

// Prototipos de funciOn
void   imprimir(char * cadena, _Bool direccion);
size_t longitud(char * cadena);
char * buscar(char * cadena, char caracter);

int main(void)
{
    char cadena[TAMANIO_BUFF];

    printf("Ingrese una cadena y presione enter: ");
    fgets(cadena, TAMANIO_BUFF, stdin);

    printf("La cadena es: ");
    imprimir(cadena, NORMAL);

    printf("\nLa cadena en reversa es: ");
    imprimir(cadena, REVERSA);

    puts("\n");

    printf("La longitud de la cadena es: %zu\n", longitud(cadena) - 1); // Se le resta uno para no contar el salto de línea

    puts("\n");
    puts("Veamos que letras conforman la cadena:");

    for (char i = 'A'; i <= 'z'; i++) {
        if ( buscar(cadena, i) )
            printf("La cadena contiene %c\n", i);
        if ( i == 'Z' ) i = 'a' - 1;
    }


    return EXIT_SUCCESS;
}

void imprimir(char * cadena, _Bool direccion)
{
    // Una vez que llega al carácter nulo simplemente regresa
    if (*cadena == '\0') return;

    if ( direccion == NORMAL ) {
        // Primero imprime el carácter actual y luego el resto de la cadena
        putchar(*cadena);
        imprimir(cadena + 1, NORMAL);
    } else if ( direccion == REVERSA ) {
        // Primero imprime el resto de la cadena y luego el carácter actual
        imprimir(cadena + 1, REVERSA);
        putchar(*cadena);
    }
}

size_t longitud(char * cadena)
{
    if (*cadena == '\0') return 0;

    return longitud(cadena + 1) + 1;
}

char * buscar(char * cadena, char caracter)
{
    if ( *cadena == '\0' ) return NULL;

    if ( *cadena == caracter ) return cadena;

    return (buscar(cadena + 1, caracter));
}
