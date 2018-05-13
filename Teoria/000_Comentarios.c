/*==========================*
 * Inserción de comentarios *
 *==========================*/

/**
 * Autor: Martínez Ortiz Saúl Axel
 * Dificultad: Básico.
 * Requisitos: Bases de programación y cadenas.
 * Estilo de código: Personalizado.
 */

#include <stdio.h>  // printf
#include <stdlib.h> // EXIT_SUCCESS

/*
   Esto es un comentario de bloque,
   se puede continuar en las siguientes
   líneas siempre y cuando no se encuentre
   la secuencia de terminación del comentario.
*/

// Esto es un comentario de línea proveniente de c99.

#ifdef __GNUC__

// Además en el compilador de GNU, se puede continuar el comentario     \
   situando una antidiagonal al final de la línea. Como esta última     \
   característica no es C estándar, se menciona básicamente para estar  \
   advertidos y evitar usar esta característica por accidente.

#endif // __GNUC__

int main(void)
{
/* El comentario de línea sigue hasta el infinito (o salto de línea)
                                |
                                v   ----------------------->>>>>>>>>>>>>  */
    printf("Esto es código\n"); // Esto es comentario sin importar nada

/* Está delimitado:
                  |                                       |
                  v <-----------------------------------> v                */
    printf("Esto" /* es comentario en medio de una cadena */ " es más código");

#if 0   // Una macro condicional cuya condición es falsa
    Esta sección no es realmente un comentario, es código que será
    removido por el preprocesador antes de la "compilación efectiva".
    Este tipo de macros condicionales son útiles cuando se quieren remover
    trozos de código que tienen comentarios multi-línea.
    Sin embargo, las directivas condicionales son mucho más poderosas
    usadas junto con el resto de directivas de preprocesador, vea la
    sección C para más información.
#endif
    return EXIT_SUCCESS;
}
