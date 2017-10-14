/* ================================= *
 * Conversión entre bases            *
 * Descripción:                      *
 *  Algoritmos recursivos para hacer *
 *  el cambio de base decimal a      *
 *  binario, octal o hexadecimal     *
 * ================================= */

#include <stdio.h>      // printf, scanf
#include <stdlib.h>     // EXIT_FAILURE, EXIT_SUCCESS
#include <ctype.h>      // isdigit

// Prototipos de función
static void imprimir_base(int numero, int base);
static _Noreturn void instrucciones(const char * const nombre_programa);
static _Noreturn void imprimir_error(const char * const mensaje);

int main(int argc, const char ** argv)
{
    int numero, base;

    if ( argc == 3 ) {

        // Se revisa que los argumentos solo contengan numeros ( y también
        // se salta el signo si este existe)

        for (int arg = 1; arg <= 2; arg++) {
            if ( argv[arg][0] == '+' )
                argv[arg]++;
            else if ( argv[arg][0] == '-' ) {
                argv[arg]++;

                putchar('-');
            }

            for (int i = 0; argv[arg][i]; i++) {
                if ( !isdigit(argv[arg][i]) )
                    imprimir_error("Argumento inválido");
            }
        }

        numero = atoi(argv[1]);
        base = atoi(argv[2]);

        if ( base < 1 || base > 3 )
            instrucciones(argv[0]);

        base--;

    } else {
        printf("Ingrese un número decimal: ");

        if ( !scanf("%d", &numero) ) {
            puts("Formato de número incorrecto");
            exit(EXIT_FAILURE);
        }

        puts("Elije la base a la que quieres convertir:");
        puts("\t1. Binaria");
        puts("\t2. Octal");
        puts("\t3. Hexadecimal");

        if ( !scanf("%d", &base) ) {
            fprintf(stderr, "Formato de número incorrecto");
            exit(EXIT_FAILURE);
        } else if ( base < 1 || base > 3 ) {
            fprintf(stderr, "NUmero inválido");
            exit(EXIT_FAILURE);
        } else if ( numero < 0 ) {
            numero *= -1;
            putchar('-');
        }

    }

    imprimir_base(numero, base - 1);

    return EXIT_SUCCESS;
}

// FunciOn que hace la conversiOn de base
static
void imprimir_base(int numero, int opcion)
{
    const static int base_correspondiente[3] = { 2, 8, 16 };

    if (0 == numero)
        return;

    imprimir_base(numero / base_correspondiente[opcion], opcion);
    printf("%X", numero % base_correspondiente[opcion]);
}

static _Noreturn
void instrucciones(const char * const nombre_programa)
{
    puts("Llame al programa con:\n");
    printf("\t%s <numero> <base>\n\n", nombre_programa);
    puts("Donde:\n"
         "\tnumero : Valor entero decimal\n"
         "\tbase   : Valor entero entre uno 1 tres\n");

    exit(EXIT_SUCCESS);
}

static _Noreturn
void imprimir_error(const char * const mensaje)
{
    fprintf(stderr, "%s\n", mensaje);
    exit(EXIT_FAILURE);
}
