/*===================*
 * Respuesta Tarea 1 *
 *     Factorial     *
 *===================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void evaluar_factorial(char * restrict * lista, int numero);
long double factorial(int valor);
void pedir_valores(char * nombre_programa);

int main(int argc, char * restrict * argv)
{
    if ( argc > 1 )
        evaluar_factorial(argv + 1, argc - 1);
    else
        pedir_valores(argv[0]);

    return EXIT_SUCCESS;
}

void evaluar_factorial(char * restrict * lista, const int numero)
{
    int valor;

    for (int i = 0; i < numero; i++) {
        valor = atoi(lista[i]);

        assert( valor >= 0 );

        printf("El factorial de %d es: %.Lf\n", valor, factorial(valor));
    }
}

long double factorial(int valor)
{
    if ( valor == 1 )
        return 1;

    // Como la función regresa un long double, se hace una conversión
    // implicita a este tipo.
    return factorial(valor - 1) * valor;
}

void pedir_valores(char * nombre_programa)
{
    puts("Ingrese una lista de enteros para calcular su factorial");
    puts("Escriba \"listo\" para terminar");

    char ** lista_argumentos = malloc(sizeof(char *));
    *lista_argumentos = nombre_programa;
    int numero = 1;

    do {
        lista_argumentos = realloc(lista_argumentos,
                (numero + 1) * sizeof(char *));

        // Reserva memoria para la cadena leída, solo linux
        scanf("%ms", &lista_argumentos[numero]);

    } while ( !strcmp(lista_argumentos[numero++], "listo") == 0 );

    free(lista_argumentos[--numero]);
    lista_argumentos = realloc(lista_argumentos, numero * sizeof(char *));

    main(numero, lista_argumentos);

    for (int i = 1; i < numero; i++)
        free(lista_argumentos[i]);

    free(lista_argumentos);
}
