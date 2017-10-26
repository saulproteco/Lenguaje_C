/*=====================*
 * Variables booleanas *
 *=====================*/

/**
 * Autor: Martínez Ortíz Saúl Axel
 * Dificultad: Básico.
 * Requisitos: Bases de lenguaje C y funcionamiento de la RAM.
 * Estilo de código: Linux modificado (4 espacios por tab).
 */

#include <stdio.h>  // printf
#include <stdlib.h> // EXIT_SUCCESS
#include <limits.h> // INT_MAX

/* En C las condiciones son valores enteros, el valor 0 representa 'falso'  *
 * y cualquier otro valor representa 'verdadero'. Si una variable que no    *
 * sea un entero se usa en una condicional se compara implicitamente con el *
 * valor equivalente a 0 (0.0 en caso de los doubles y NULL en los          *
 * apuntadores) y dado que toda comparación mediante el operador '=='       *
 * regresa un valor entero por lo que al final, siempre es un valor entero  *
 * lo que una comparación evalua.                                           */

#define VERDAD  1
#define MENTIRA 0

int main(int argc, char *argv[])
{
/* Para guardar los resultados de una condición en C se utilizaban enteros  *
 * lo cual no era los más optimo, hasta que C99 introdujo las variables     *
 * boolenas. Estas son representadas también como enteros (no signados y de *
 * un byte) pero tiene la propiedad de evaluarse de la misma forma que una  *
 * condición.                                                               */

    int entero;
    _Bool booleano;

/* Demostraremos algunas de las propiedades de los booleanos. En primer     *
 * lugar, es inseguro comparar un entero directamente con un valor          *
 * VERDAD porque ningún entero está limitado solo a cero y a uno, por ello  *
 * un entero siempre se debe comparar por su inigualdad con un valor        *
 * MENTIRA.                                                                 */
    entero = 10;
    booleano = 10;

/* Esta comparación resulta mal si se usan enteros pero no si se usan booleanos */
    puts("Incorrecto");
    printf("El valor %ses verdad\n", entero == VERDAD ? "SI " : "NO ");  // NO
    printf("El valor %ses verdad\n", booleano == VERDAD ? "SI " : "NO ");// SI

/* La comparación correcta en enteros es la siguiente, pero dificulta la    *
 * lectura.                                                                 */
    puts("Correcto");
    printf("El valor %ses verdad\n", entero != MENTIRA ? "SI " : "NO "); // SI
    printf("El valor %ses verdad\n", booleano != MENTIRA ? "SI " : "NO "); // SI

/* Un entero siempre tiene el riesgo de volverse 0 cuando a causa del       *
 * desbordamiento de un entero, pero un booleano no tiene dicho riesgo      */
    entero   = UINT_MAX; entero++;
    booleano = UINT_MAX; booleano++;

    printf("El valor de \"entero\" es: %d\n", entero);
    printf("El valor de \"booleano\" es: %d\n", booleano);

/* Si queremos guardar variables flotantes como valores de verdad en enteros *
 * estas se castean implicitamente a enteros por lo que se pierden los       *
 * decimales. Esto puede conllevar a que el valor se vuelva falso de forma   *
 * inesperado. Este riesgo no existe con los booleanos pues como se dijo     *
 * antes, se comportan como una comparación.                                 */

    entero   = 0.4;
    booleano = 0.4;

    printf("El valor %ses verdad\n", entero != MENTIRA ? "SI " : "NO "); // NO
    printf("El valor %ses verdad\n", booleano != MENTIRA ? "SI " : "NO ");// SI

    return EXIT_SUCCESS;
}
