/*============================*
 * Recordando tiempos pasados *
 *============================*/

// *** Código sujeto a comportamiento indefinido ***

#include <stdio.h>

/*
 * Aparentemente el siguiente código debería
 * generar un error de compilación pero no lo hace.
 * Explique por qué
 */
void funcion()
{
    puts("Dentro de la función");
}

int main(void)
{
    funcion("Argumento", 10.5, 'a');
}
