/*===================================*
 * Respuesta tarea 1                 *
 * Imprimir 50 términos de fibonacci *
 *===================================*/

#include <stdio.h>
#include <inttypes.h>

/* Se puede definir la cantidad de números a imprimir en tiempo de  *
 * compilación. Para ello tiene que usar la bandera -D al momento   *
 * de llamar a gcc de la forma que sigue:                           *
 *  $ gcc <nombre_de_este_archivo> -D CANTIDAD_NUMEROS=<valor>      *
 *                                                                  *
 * La línea anterior define una macro llamada CANTIDAD_NUMEROS con  *
 * el valor especificado la cual será válida para todas las         *
 * unidades de traducción compiladas juntas.                        *
 *                                                                  *
 * La macro condicional que viene a continuación revisa si hay      *
 * una definición de la macro CANTIDAD_NUMEROS (si la hay, lo más   *
 * seguro es que se haya pasado como argumento al compilador) y en  *
 * caso de que no haya ninguna usa el número por defecto (50)       */

#ifndef CANTIDAD_NUMEROS
#   define CANTIDAD_NUMEROS 50
#endif


// Se causa un error de compilación si la cantidad especificada en tiempo
// de compilación es menor o igual a 0. También se puede usar:
// _Static_assert(CANTIDAD_NUMEROS, "La cantidad debe ser mayor a 0");
#if CANTIDAD_NUMEROS <= 0
#   error "La cantidad debe ser mayor a 0"
#elif CANTIDAD_NUMEROS <= 93
    // Se usa un entero de 64 bits si la cantidad de números a calcular es
    // menor a 93, en cualquier otro caso se usa un long double
#   define TIPO_DATO uint64_t
#   define FORMATO_IMPRESION PRIu64
#else
#   define TIPO_DATO long double
#   define FORMATO_IMPRESION "Lf"
#endif

// Un par de macros para convertir otra macro a cadena
#define A_CADENA(x)  EVALUA(x)
#define EVALUA(num)  #num

int main(void)
{
    TIPO_DATO a = 1, b = 1;
    TIPO_DATO fibo = 0;

    puts("Los primeros " A_CADENA(CANTIDAD_NUMEROS) " términos de fibonacci:");

    // Operaciones de corto circuito :D
    (void)(puts("  1. 1") && CANTIDAD_NUMEROS > 1 && puts("  2. 1"));

    // Se imprimen los valores
    for (int i = 3; i <= CANTIDAD_NUMEROS; i++) {
        fibo = a + b;

        printf("%3d. %.0" FORMATO_IMPRESION "\n", i, fibo);

        a = b;
        b = fibo;
    }

    return 0;
}
