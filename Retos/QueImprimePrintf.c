/*=========================================*
 * ¿Qué va a imprimir el siguiente código? *
 *=========================================*/

#include <stdio.h>

int main(void)
{
    int a = 0b11;
    int b = 012;
    int c = 0x13;

    printf("%d %d %d\n", a /= 2, b = a + c, c--);
    return 0;
}
