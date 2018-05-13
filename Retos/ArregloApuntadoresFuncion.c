/*================================*
 * Y así se ríe la O: jo jo jo jo *
 *================================*/

#include <stdio.h>

#define L(a) (sizeof(a) / sizeof(*(a)))

/*
 * Indique la salida del siguiente programa
 */

typedef void Funccion(void);

Funccion A, E, I, O, U;
Funccion * arr_funciones[5] = { A, E, I, O, U };

int main(void)
{
    for (size_t i = 0; i < L(arr_funciones); ++i)
        arr_funciones[i]();
}

void A(void) { puts("U"); }
void E(void) { puts("O"); }
void C(void) { puts("I"); }
void O(void) { puts("E"); }
void U(void) { puts("A"); }
