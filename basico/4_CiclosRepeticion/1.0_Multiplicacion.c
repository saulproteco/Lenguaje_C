/*
 * Formas de hacer una multiplicaciOn sin el operador
 * asterisco
 */
#include <stdio.h>

int main(void) {
    int a, b;
    int multi;

    printf("Ingrese dos nUmeros: ");
    scanf("%d%d", &a, &b);

    int i, j;
    multi = 0;
    // MultiplicaciOn de orden a x b (Tremendamente ineficiente)
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            multi++;
        }
    }
    printf("La multiplicaciOn mAs ineficiente es: %d\n", multi);

    // MultiplicaciOn de orden a (Aun sigue siendo ineficiente)
    multi = 0;
    for (i = 0; i < a; i++) {
        multi += b;
    }
    printf("La multiplicaciOn mAs o menos eficiente es: %d\n", multi);

    return 0;
}
