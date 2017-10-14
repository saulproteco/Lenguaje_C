/*==============================*
 * Indique lo que va a imprimir *
 * el siguiente código.         *
 *==============================*/

#include <stdio.h>

int main(void)
{
    int a = 1, b = 1, c = 0;


    for (; a != 0; c % b ? : (a > 0? a-- : a++))
        c += (a > 0) ? (b > 0) ? 1 : -1 : (b > 0) ? -1 : 1;

    printf("%d\n", c);
    return 0;
}
