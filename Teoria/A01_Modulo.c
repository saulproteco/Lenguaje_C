#include <stdio.h>

// En un modulo pueden ir tamto variables como cOdigo, la Unica
// restricciOn que hay es que entre todos los archivos fuente debe
// haber uno solo que contenga a la funciOn principal.

// Los mOdulos, al igual que los archivos que los usan comparten
// algunas definiciones contenidas en su cabecera correspondiente.
// En este archivo tambiEn se incluye dicha cabecera para no repetir
// las definiciones.
#include "cabecera.h"

// Sin embargo, la cabecera no contiene todas las definiciones,
// hay algunas que solo corresponden a elementos internos tales
// como el siguiente prototipo de funciOn.
static void funcion_interna(void);

// Variable global que es usada en otros archivos por medio de
// definiciones extern.
int var = 10;

// Variable interna al mOdulo, en general todas las funciones deben
// declararse de esta forma a menos que sea estrictamente necesario
// que su valor se comparta.
static int var2 = 20;

void imprimir_variable_externa(void) {
    printf("El valor de var es: %d\n", var);
}

extern void funcion_inline(void) {
    printf("Esta funciOn es normalmente estAticas a menos\n"
           "que se use un prototipo de función con 'extern'\n");
    funcion_interna();
}

static void funcion_interna(void) {
    printf("Esta función no serA llamada desde fuera de forma directa\n");
    printf("La variable interna es: %d\n", var2);
}
