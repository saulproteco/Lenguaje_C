/*=====================*
 * Efectos colaterales *
 *=====================*/

// *** Código sujeto a comportamiento indefinido ***
// *** Código con comportamiento definido por la implementación ***
// *** Código específico de gcc y clang ***

#include <stdio.h>

/*
 * Indique que imprime el siguiente código en caso de que:
 *  - Los argumentos de función se evalúen de izquierda a derecha
 *  - Los argumentos de función'se evalúen de derecha a izquierda
 *
 * ¿Que imprime en tu caso particular?
 */

int main(void)
{
    int a = 0b11; // Las literales binarias son una extensión de gcc y clang
    int b = 012;
    int c = 0x13;

    printf("%d %d %d\n", a /= 2, b = a + c, c--);
}
