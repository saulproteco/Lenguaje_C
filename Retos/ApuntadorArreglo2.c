/*===================================*
 * Apuntadores a arreglo, el retorno *
 *===================================*/

// *** Código sujeto a comportamiento indefinido ***

#include <stdio.h>
#include <math.h>

/*
 * Indique la salida del siguiente código
 */

int main(void)
{
    double arr[] = { 1e-6, 1e-4, 1e-2, 1e0, 1e2, 1e4 , 1e6 };

    double (*apt)[6] = (double (*)[]) arr;

    printf("% .f % .f\n", log10((*apt)[1]), log10((*apt)[2]));

    ++apt;

    printf("% .f % .f\n", log10((*apt)[-1]), log10((*apt)[-2]));
}
