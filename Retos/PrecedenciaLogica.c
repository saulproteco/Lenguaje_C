/*====================================================*
 * ¿Conoces la precedencia de los operadores lógicos? *
 *====================================================*/

#include <stdio.h>

/*
 * Indica la salida del siguiente código
 */

int main(void)
{
    _Bool a = 1;
    _Bool b = 2;
    _Bool c = 0;

    if (c && !b || a)  { printf("Es verdad\n");  }
    else               { printf("Es mentira\n"); }
}
