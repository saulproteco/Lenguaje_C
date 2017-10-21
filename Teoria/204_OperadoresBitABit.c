/*================================================*
 * Operadores de bit a bit                        *
 *                                                *
 * Descripción:                                   *
 *  VisualizaciOn de las operaciones de bit a bit *
 *  por medio de la representaciOn binaria de los *
 *  caracteres                                    *
 *================================================*/

/**
 * Autor: Martínez Ortíz Saúl Axel
 * Dificultad: Basico.
 * Requisitos: Funciones, estructuras de control.
 * Estilo de código: Google.
 */

#include <stdio.h>  // puts, printf
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

static void imprimeByte(unsigned char c);

int main(void) {
    // Con el prefijo 0b se pueden especificar constantes
    // binarias en GNU-C, estas líneas pueden ser incompatibles
    // con otras versiones de C.
    unsigned char a = 0b00001111;   // 15
    unsigned char b = 0b00001010;   // 10;

    puts("Los números son: ");

    printf("a = %d = ", a);
    imprimeByte(a);

    printf("\nb = %d = ", b);
    imprimeByte(b);

    /* Los operadores bit a bit funcionan escencialmente como los *
     * operadores lógicos excepto porque los primeros operan      *
     * sobre cada elemento del entero y los operadores lOgicos    *
     * operan "globalmente" regresando solo un valor de verdad.   *
     *                                                            *
     * Otra diferencia es que los operadores lOgicos pueden       *
     * asumir resultados tales como "en una secuencia de valores  *
     * de verdad separados por el operador || me basta con        *
     * encontrar un valor que sea verdad para asumir que toda la  *
     * sentencia serA verdad", asumpciOn que se conoce como       *
     * calculos de corto circuito. Como la finalidad de los       *
     * operadores de bits es obtener un resultado completo y no   *
     * solo el valor de verdad no se pueden parar en medio de una *
     * sentencia para optimizar el calculo.                       */

    puts("\n\nLas operaciones bit a bit son:");

    printf("\n a & b = ");  // Prevalecen los 0's
    imprimeByte(a & b);
    printf("\n a | b = ");  // Prevalecen los 1's
    imprimeByte(a | b);
    printf("\n a ^ b = ");
    imprimeByte(a ^ b);
    printf("\n ~a = ");
    imprimeByte(~a);
    printf(" y ~b = ");
    imprimeByte(~b);
    printf("\n a << 2 = ");
    imprimeByte(a << 2);
    printf("\n b >> 2 = ");
    imprimeByte(b >> 2);

    /* Un comportamiento curioso de las operaciones de bits es que *
     * tanto el AND como el OR tienen un elemento envolvente       *
     * que pareciera prevalecer a pesar del lo que valga el otro   *
     * operando. Por ejemplo, en el caso del AND si uno de los bits*
     * es 0 no importa el valor del otro pues igualmente el        *
     * resultado serA 0 y en caso del OR si uno de los bits es 1   *
     * el resultado en definitiva serA 1. En ambos casos el        *
     * elemento contrario al envolvente es el elemento neutro cuyo *
     * valor hace que se conserve el resultado anterior.           *
     * En cuanto a los dos operadores restantes hay que enfatizar  *
     * que el repetir una operaciOn revierte las acciones de la    *
     * primera de manera que se obtiene el valor original.         */
    puts("\n");

    return EXIT_SUCCESS;
}

void imprimeByte(unsigned char c) {
    // Se usa una máscara de un solo bit (i)
    // el cual se va recorriendo hacia la derecha
    // para imprimir los unos y ceros que conforman
    // nuestro bit
    for (int i = (1 << 7); i >= 1; i >>= 1) {
        putchar( i & c ? '1' : '0' );
    }
}
