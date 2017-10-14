/*========================================*
 * Encuentre el error lógico y expliquelo *
 *========================================*/

#include <stdio.h>

int main(void)
{
    unsigned int n = 1;

    if ( -1 > n ) {
        printf("Menos uno es mayor a uno\n");
    } else {
        printf("Uno es mayor o igual que menos uno\n");
    }

    return 0;
}
