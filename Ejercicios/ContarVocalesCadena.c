/*==============================================*
 * Programa para hacer el conteo de las vocales *
 * de una cadena leida desde el teclado.        *
 *==============================================*/

#include <stdio.h>  // puts, printf, fgets -> Entrada/salida
#include <stdlib.h> // EXIT_SUCCESS -> 0
#include <string.h> // strlen   -> Largo cadenas
#include <ctype.h>  // tolower  -> Mayúsculas y minúsculas

#define LARGO_LINEA 100

enum vocales {
    A, E, I, O, U,
    NUMERO_VOCALES
};

const char representacion[NUMERO_VOCALES] = {
    'a', 'e', 'i', 'o', 'u'
};

int main(void)
{
    extern const char representacion[]; // La variable global "representación"
                                        // Esta declaración podria omitirse
                                        // ya que dicha variable se
                                        // encuentra en la misma unidad
                                        // de traducción.

    int conteo[NUMERO_VOCALES] = { 0 };

    char cadena_entrada[LARGO_LINEA];
    int largo_cadena;

    puts("   Contando el número de vocales ");
    puts("_______ _______ _______ _______ _______\n");

    printf("Ingrese una cadena: ");
    fgets(cadena_entrada, LARGO_LINEA, stdin);

    largo_cadena = strlen(cadena_entrada);

    for (int j = 0; j < largo_cadena; j++) {
        char caracter = tolower(cadena_entrada[j]);

        for (int vocal = A; vocal <= U; vocal++) {
            if ( caracter == representacion[vocal] )
                conteo[vocal]++;
        }

    }

    puts("    Conteo de vocales:");
    puts("_____ _____ _____ _____ _____");

    for (int vocal = A; vocal <= U; vocal++) {
        printf("La vocal %c apareció: %d\n",
                representacion[vocal], conteo[vocal]);
    }

    return EXIT_SUCCESS;
}
