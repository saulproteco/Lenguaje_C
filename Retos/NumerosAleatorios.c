/*==============================================*
 * Ejecute el siguiente código y luego explique *
 *                  su salida                   *
 *==============================================*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef _WIN32
static int valores[] = { 324, 179, 335, 18, 155, 100, 181, 22, 19, 179, 145 };
#else // !_WIN32
static int valores[] = { 31, 10, 138, 65, 95, 41, 695, 521, 108, 10 , 589 };
#endif // Fin _WIN32

int main(void)
{
    int * apt = valores;
    char c;

    do {
        srand(*apt++);
        c = rand();
    } while ( putchar(c) );

    return EXIT_SUCCESS;
}
