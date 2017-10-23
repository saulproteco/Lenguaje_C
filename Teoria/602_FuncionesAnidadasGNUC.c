/*====================*
 * Funciones anidadas *
 *====================*/

/**
 * Autor: Martínez Ortíz Saúl Axel
 * Dificultad: Intermedio.
 * Requisitos: Funciones, apuntadores a funciones..
 * Estilo de código: Linux modificado (4 espacios por tab).
 */


/* Las funciones anidadas son una característica extendida de C que provee *
 * el compilador de GNU. Gracias a esta característica es posible trabajar *
 * funciones con alcance como si de variables se tratara.                  *
 * Si la compatibilidad entre plataformas es indispensable, hay que        *
 * prescindir completamente de esta técnica.                               *
 *                                                                         *
 * Una vez que se decide que es viable hacer uso de esta extensión del     *
 * lenguaje, realmente habrá pocas cosas interesantes que hacer con ella   *
 * o que no se puedan hacer igualmente usando C estándar. En otros         *
 * lenguajes hay constructos mucho más interesantes que se pueden realizar *
 * con funciones anidadas, tales como los 'cierres' o 'closures' de los    *
 * lenguajes funcionales. Sin embargo realizar este tipo de cosas con las  *
 * funciones anidadas de gcc resulta bastante complicado o incluso podría  *
 * ser imposible. Si quiere observar un proyecto basado en GNU-C que hace  *
 * cosas como esas revise el repositorio: Leushenko/C99-Lambda en github.  */

#include <stdio.h>  // puts, printf
#include <stdlib.h> // srand, rand, EXIT_SUCCESS
#include <time.h>   // time

void funcion_normal(void);

int main(void)
{
    srand(time(NULL));

    // Las funciones anidadas se pueden declarar y usar de manera idéntica
    // a las normales, a excepción de que no puedes declarar su prototipo
    // en el mismo bloque. En todo caso se puede hacer en un bloque externo
    // y escribir el cuerpo de la función en un bloque interno.
    int funcion_anidada1(int (*funcion_parametro)(void))
    {
        puts("Esta es una funciOn que recibe como argumento"
             "a otra funciOn con retorno entero y sin parAmetros\n");

        printf("La direcciOn de otra_fun es: %p\n\n", funcion_parametro);

        return funcion_parametro();
    }

    int funcion_anidada2(char letra, int tamanio, int arreglo[tamanio], void (*funcion)())
    {
        printf("La letra es: %c\n", letra);

        puts("El arreglo es:");
        for (int i = 0; i < tamanio; i++)
            printf(" %2d", arreglo[i]);
        puts("\n");

        puts("Llamando a la funciOn");
        funcion();

        return rand();
    }


    // Quizás de las pocas cosas interesantes que se pueden hacer por medio
    // de las funciones anidadas es hacer la definición de la función sobre
    // la marcha para pasarla como argumento y que esta no se vuelva a usar.
    // Esto viene a ser una especie de construcción de una "lambda" con la
    // excepción de que aún hace falta darle nombre a la función. De cualquier
    // forma, como el nombre de la función no podrá ser referenciado tras
    // llamar la función el resultado es prácticamente el mismo.
    int resultado = funcion_anidada1(({
        // Función más anidada aún, está declarada justo al pasarle el
        // argumento a 'funcion_anidada1'.
        int hola(void) {
            printf("Esta es una función declarada donde es usada"
                   ", dejará de existir en la siguiente línea");
        } hola;
    }));

    printf("El resultado de la función anidada es: %d\n", resultado);

    int resultado2 = funcion_anidada2(
        'A',                                // Letra
        6,                                  // Tamanio del arreglo
        (int []) { 5, 3, 1, -1, -3, -5 },   // Elementos del arreglo
        ({ void casi_anonima(void) { printf("Holii\n"); } casi_anonima; })   // Otra función declarada sobre la marcha
    );

    printf("El resultado dos es: %d\n", resultado2);

    int arreglo_normal[] = { 1, 2, 3 };
    int resultado3 = funcion_anidada2('B', 3, arreglo_normal, funcion_normal);

    printf("El resultado normal es: %d\n\n", resultado3);

    return EXIT_SUCCESS;
}

void funcion_normal(void)
{
    printf("Si se descomenta la siguiente línea habrá un error de compilación");
    //funcion_anidada2(); // Esta llamada daría un error de compilación.
                           // 'funcion_anidada2' solo existe en el bloque o
                           // función en que se declaró (main en este caso).
}
