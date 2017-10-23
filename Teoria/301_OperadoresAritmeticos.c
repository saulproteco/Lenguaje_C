/*============================================*
 * Demostración de los operadores aritméticos *
 * en lenguaje C así como de la revisión del  *
 * valor de retorno del scanf para comprobar  *
 * la validez de los datos ingresados         *
 *============================================*/

/**
 * Autor: Martínez Ortíz Saúl Axel
 * Dificultad: Básico.
 * Requisitos: Manejo de entrada/salida, funciones.
 * Estilo de código: Miscelaneo.
 */

#include <stdio.h>  // puts, printf, getchar, scanf
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

static _Noreturn void imprime_error(const char * const);

int main(void)
{
    int a, b;
    _Bool exito;

    puts("Operadores aritméticos en los enteros:");

    puts("Ingrese dos números enteros para operar con ellos:");

    exito = scanf("%d", &a);                // Se lee a
    exito = exito && scanf("\n%d", &b);     // Se lee b

    if ( !exito ) // Si alguna de las lecturas falló
        imprime_error("Los números ingresados no son válidos");

    if ( 0 == b ) // El dividendo entero no puede ser 0
        imprime_error("No puede haber división entera por 0");

    puts("Los enteros tiene 5 operadores aritméticos:\n"
            "\t1. suma -> +\n"
            "\t2. resta -> -\n"
            "\t3. multiplicación -> *\n"
            "\t4. división entera (trunca resultados) -> /\n"
            "\t5. residuo -> %\n");

    printf("\t\t a = %d, b = %d\n", a, b);

    int suma_entera;
    int resta_entera;
    int multi_entera;
    struct { int cociente, residuo; } div_entera;

    suma_entera         = a + b;
    resta_entera        = a - b;
    multi_entera        = a * b;
    div_entera.cociente = a / b;
    div_entera.residuo  = a % b;

    printf("La suma es: %d\n", suma_entera);
    printf("La resta es: %d\n", resta_entera);
    printf("La multiplicación es: %d\n", multi_entera);
    printf("La división es: %d + %d/%d\n",
            div_entera.cociente, div_entera.residuo, b);

    getchar();

    puts("\n============================================================");

    puts("Operadores aritméticos en la flotantes:");
    double f, g;

    puts("Ingrese dos números reales para operar con ellos");

    exito = scanf("%lf", &f);            // Se lee f
    exito = exito && scanf("%lf", &g);   // Se lee g

    if ( !exito ) // Si algún número se ingresó erróneamente
        imprime_error("Los números ingresados no son válidos");

    // Si se puede dividir por 0 en aritmética flotante por lo que
    // no se pone ninguna restricción para el denominador.

    puts("Los flotantes tiene 4 operadores (no tienen residuo):\n"
            "\t1. suma -> +\n"
            "\t2. resta -> -\n"
            "\t3. multiplicación -> *\n"
            "\t4. division (no trunca resultados) -> /\n");

    printf("\t\t f = %f, g = %f\n", f, g);

    double suma_flotante;
    double resta_flotante;
    double multi_flotante;
    double div_flotante;

    suma_flotante  = f + g;
    resta_flotante = f - g;
    multi_flotante = f * g;
    div_flotante   = f / g;

    printf("La suma es: %f\n", suma_flotante);
    printf("La resta es: %f\n", resta_flotante);
    printf("La multiplicación es: %f\n", multi_flotante);
    printf("La división es: %f ", div_flotante);

    puts("\n============================================================");

    puts("Operadores aritméticos en la complejos:");

    _Complex z1, z2;
    double * apt;

    puts("Ingrese dos números complejos en forma a+bi para operar con ellos");

    apt = (double *) &z1;
    exito = scanf("%lf%lfi", apt, apt + 1);

    apt = (double *) &z2;
    exito = exito && scanf("\n%lf%lfi", apt, apt + 1);

    if ( !exito )
        imprime_error("Valores inválidos");

    // Se usan 4 especificadores de formato (%f) en este printf pero solo
    // se pasan dos variables, si aún así la impresión muestra los valores
    // correctos es pura coincidencia.
    printf("\t\t z1 = %f%+f*i \t z2 = %f%+f*i\n", z1, z2);

    _Complex suma_compleja;
    _Complex resta_compleja;
    _Complex multi_compleja;
    _Complex div_compleja;

    suma_compleja  = z1 + z2;
    resta_compleja = z1 - z2;
    multi_compleja = z1 * z2;
    div_compleja   = z1 / z2;

    // Igualmente se están usando dos especificadores de formato pero se
    // provee de una sola variable al printf. Si ves resultados correctos
    // seguramente estas alucinando. Quizás leer sobre argumentos variables
    // en C te aclare que está pasando y porque no deberías usar esta forma
    // tan ñera de imprimir complejos pues no siempre va a funcionar.
    printf("La suma es:             %f%+f*i\n", suma_compleja);
    printf("La resta es:            %f%+f*i\n", resta_compleja);
    printf("La multiplicación es:   %f%+f*i\n", multi_compleja);
    printf("La división es:         %f%+f*i\n", div_compleja);

    return EXIT_SUCCESS;
}

static _Noreturn
void imprime_error(const char * const mensaje)
{
    fprintf(stderr, "%s\n", mensaje);

    exit(EXIT_FAILURE);
}
