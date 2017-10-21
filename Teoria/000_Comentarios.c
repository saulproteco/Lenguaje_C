/*==========================*
 * Inserción de comentarios *
 *==========================*/

/**
 * Autor: Martínez Ortíz Saúl Axel
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

// Esto es un comentario de línea proveniente de c99. Además en el      \
   compilador de GNU, se puede continuar el comentario situando una     \
   antidiagonal al final de la línea. Como esta última característica   \
   no es C estandar, se menciona básicamente para estar advertidos      \
   y evitar usar esta característica por accidente.

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
    return EXIT_SUCCESS;
}
