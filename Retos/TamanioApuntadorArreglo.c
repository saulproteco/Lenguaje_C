/*==========================================*
 * Indique la secuencia completa de salida  *
 *          del siguiente código.           *
 *==========================================*/

#include <stdio.h>

int main(void)
{
    int arr[] = { 5, 5, 5 };

    int *pt = arr;
    int (*ap)[sizeof(long)][sizeof(double)];

    printf("%zu\n", sizeof(pt));
    printf("%zu\n", sizeof(*pt));
    printf("%zu\n", sizeof(ap));
    printf("%zu\n", sizeof(*ap));

    return 0;
}
