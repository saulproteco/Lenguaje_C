#include <stdio.h>

// En un modulo pueden ir tanto variables como código, la única
// restricción que hay es que entre todos los archivos fuente debe
// haber uno solo que contenga a la función principal.

// Los módulos, al igual que los archivos que los usan comparten
// algunas definiciones contenidas en su cabecera correspondiente.
// En este archivo también se incluye dicha cabecera para no repetir
// las definiciones.
#include "cabecera.h"

// Sin embargo, la cabecera no contiene todas las definiciones,
// hay algunas que solo corresponden a elementos internos tales
// como el siguiente prototipo de función.
static void funcion_interna(void);

// Variable global que es usada en otros archivos por medio de
// definiciones extern.
int var = 10;

// Variable interna al módulo, en general todas las funciones deben
// declararse de esta forma a menos que sea estrictamente necesario
// que su valor se comparta.
static int var2 = 20;

void imprimir_variable_externa(void) {
    printf("El valor de var es: %d\n", var);
}

extern void funcion_inline(void) {
    printf("Esta función es normalmente estáticas a menos\n"
           "que se use un prototipo de función con 'extern'\n");
    funcion_interna();
}

static void funcion_interna(void) {
    printf("Esta función no será llamada desde fuera de forma directa\n");
    printf("La variable interna es: %d\n", var2);
}
