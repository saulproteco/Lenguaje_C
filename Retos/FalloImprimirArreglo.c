/*================================*
 * Encuentre el error al imprimir *
 * el arreglo y expliquelo.       *
 *================================*/

#include <stdio.h>

#define l(z) (sizeof(z) / sizeof(*z))

int main(void)
{
    int a[] = { 1, 2, 4, 5, 6, 7, 8 };

    for (int i = -1; i < l(a) - 1; ++i)
        printf("%d\n", a[i + 1]);

    return 0;
}
