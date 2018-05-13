/*===================*
 * Orden por defecto *
 *===================*/

#include <stdio.h>

// ¿El programa imprime A o B? ¿Por qué?

int main(void)
{
    int x = 1;

    switch (x) {
        default: puts("B"); break;
        case  1: puts("A"); break;
    }
}
