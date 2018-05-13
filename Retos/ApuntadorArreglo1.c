/*==============================================*
 * El ataque de los apuntadores a arreglo ninja *
 *==============================================*/

// *** Código sujeto a comportamiento indefinido ***

#include <stdio.h>

/*
 * ¿El válido el código a continuación?
 * En caso de serlo indique cual será su salida
 */

int main(void)
{
    int arr[] = { [1] = 1, [3] = 3, [5] = 5, [7] = 5, [9] = 3 , [11] = 1 };
    const int * const apt = (int *) (&arr + 1);

    printf("%d %d %d %d %d %d\n",
            *(arr + 1), *(arr + 3), *(arr + 5),
            *(apt - 1), *(apt - 3), *(apt - 5));
}
