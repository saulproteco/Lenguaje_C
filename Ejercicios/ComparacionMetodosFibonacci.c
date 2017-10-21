/* =========================== *
 * Sucesion de fibonacci       *
 *  Diferentes métodos para    *
 *  calcular los términos de   *
 *  la serie de fibonacci.     *
 * =========================== */

#include <stdio.h>  // printf
#include <stdlib.h> // EXIT_SUCCESS
#include <time.h>   // clock_t, clock
#include <math.h>   // pow
#include <assert.h> // assert

#define MAXIMO          1000
#define REPETICIONES    50
#define RAIZ_CINCO      2.2360679774997899

/*
 * La definiciOn recursiva de la serie de fibonacci implica
 * un crecimiento exponencial en uso de espacio y de tiempo que se sale
 * de control facilmente.
 * Se usa un arreglo estAtico para recordar los números previamente
 * calculados para permitir incluso a la función recursiva tener
 * un rendimiento considerablemente bueno.
 */
long long unsigned fibonacci_recursivo(int x)
{
    static long long numeros_fibo[MAXIMO] = { 0 , 1 };

    assert( x >= 0 && x <= MAXIMO );

    if ( x == 0 )
        return 0;

    if ( !numeros_fibo[x] )
        numeros_fibo[x] = fibonacci_recursivo(x - 1) + fibonacci_recursivo(x - 2);

    return numeros_fibo[x];
}

/*
 * Forma iterativa de calcular los nUmeros de fibonacci.
 * Esta forma es sencilla y lineal.
 */
long long unsigned fibonacci_iterativo(int x)
{
    long long unsigned n = 0, m = 1;
    long long unsigned resultado;

    assert( x >= 0 && x <= MAXIMO );

    if ( x == n || x == m ) {
        return x;
    }

    for (int i = 2; i <= x; i++) {
        resultado = n + m;

        n = m;
        m = resultado;
    }

    return resultado;
}

/*
 * Formula matemAtica proveniente de la caracterizaciOn polinomial
 * de la serie de fibonacci. Igualmente es una funciOn lineal debido
 * a las potencias implicadas, sin embargo el hecho de delegar el
 * trabajo a funciones estandar la hace ligeramente mAs rApida que
 * la versiOn iterativa.
 */
long long unsigned fibonacci_formula(int x)
{
    static double a = (1 + RAIZ_CINCO) / 2;
    static double b = (1 - RAIZ_CINCO) / 2;

    assert( x >= 0 && x <= MAXIMO );

    return (pow(a, x) - pow(b, x)) / (RAIZ_CINCO);
}

int main(void)
{
    clock_t tiempo1, tiempo2, tiempo3;

    // Se mide el tiempo de las distintas versiones de la funciOn
    tiempo1 = clock();
    for (int i = 1; i <= REPETICIONES; i++) {
        printf("El fibonacci %d es: %llu\n",
                i, fibonacci_recursivo(i));

    }
    tiempo1 = clock() - tiempo1;

    tiempo2 = clock();
    for (int i = 1; i <= REPETICIONES; i++) {
        printf("El fibonacci %d es: %llu\n",
                i, fibonacci_iterativo(i));
    }
    tiempo2 = clock() - tiempo2;

    tiempo3 = clock();
    for (int i = 1; i <= REPETICIONES; i++) {
        printf("El fibonacci %d es: %llu\n",
                i, fibonacci_formula(i));
    }
    tiempo3 = clock() - tiempo3;

    printf("Fibonacci recursivo tarda: %ld\n", tiempo1);
    printf("Fibonacci iterativo tarda: %ld\n", tiempo2);
    printf("Fibonacci de a formulazo tarda: %ld\n", tiempo3);

    return EXIT_SUCCESS;
}
