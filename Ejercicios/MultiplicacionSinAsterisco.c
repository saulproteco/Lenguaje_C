/*====================================================*
 * Formas de hacer una multiplicación sin el operador *
 *                     asterisco                      *
 *====================================================*/

#include <stdio.h>  // printf
#include <stdlib.h> // EXIT_SUCCESS
#include <time.h>   // clock_t, clock
#include <string.h> // strcmp

#define TAMANIO_CADENA 100

// ##### Prototipos #####
void prueba_tiempos(void);

// ##### Funciones #####

int main(void)
{
    char ingreso_usuario[TAMANIO_CADENA];

    do {
        puts("\t.:Algoritmos de Multiplicación:.\n");
        prueba_tiempos();

        putchar('\n');
        puts("¿Quiere hacer la prueba con números distintos?\n"
             "(Cualquier cosa diferente de \"si\" significa no)\n");

        fgets(ingreso_usuario, TAMANIO_CADENA, stdin);


    } while ( strcmp(ingreso_usuario, "si\n") == 0 );
}

void prueba_tiempos(void)
{
    int a, b;   // Operandos
    int multi;  // Para el resultado

    clock_t inicio, final;
    _Bool valores_validos;

    printf("Ingrese dos números positivos: ");
    valores_validos = (scanf("%d%d", &a, &b) == 2);

    valores_validos = valores_validos && (a >= 0) && (b >= 0);

    if ( !valores_validos ) {
        fputs("Los valores son inválidos\n", stderr);
        exit(EXIT_FAILURE);
    }

    char c;
    while ( (c = getchar()) != '\n' && c != EOF );

    inicio = clock();
    multi = 0;
    // MultiplicaciOn de orden a x b (Tremendamente ineficiente)
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++)
            multi++;
    }
    final = clock();
    printf("La multiplicación más ineficiente es: %d y tardó: %Lf\n",
            multi, (long double) final - inicio);

    // Multiplicación de orden a (Aún sigue siendo ineficiente)
    multi = 0;
    inicio = clock();
    for (int i = 0; i < a; i++)
        multi += b;
    final = clock();

    printf("La multiplicación más o menos eficiente es: %d y tardó: %Lf\n",
            multi, (long double) final - inicio);

    // Multiplicación de orden log(a) (Eficiente)
    multi = 0;

    // En esta última forma se modificará el valor de los operandos.
    // Si los valores se tienen que conservar será necesario hacer
    // una copia de los operandos.

    inicio = clock();
    while (a != 0) {
        if ( a & 0x001 )    // Revisa si el número es impar
            multi += b;

        b <<= 1;    // Multiplica b por 2
        a >>= 1;    // Divide a por 2
    }
    final = clock();

    printf("La multiplicacíón eficiente es: %d y tardó: %Lf\n",
            multi, (long double) final - inicio);

}
