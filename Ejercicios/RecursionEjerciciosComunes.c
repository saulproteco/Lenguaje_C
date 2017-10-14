/*===================================*
 * Ejercicios varios sobre recursion *
 *===================================*/
#include <stdio.h>      // printf
#include <stdint.h>     // unit8_t, uint32_t, uint64_t
#include <stdlib.h>     // EXIT_SUCCESS
#include <math.h>       // pow, floor, log10

static uint64_t factorial_recursivo(uint8_t n)
{
    return (n <= 1) ? 1 : n * factorial_recursivo(n - 1);
}

static uint64_t fibonacci_recursivo(uint8_t n)
{
    return (n <= 1) ? n : fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}

static uint32_t invertir(uint32_t n)
{
    if (n % 10 == 0)
        return n / 10;

    int mod = pow(10, floor(log10(n)));

    return invertir(n % mod) * 10 + n / mod;
}

static uint32_t sumar_digitos(uint32_t n)
{
    if ( n == 0 )
        return 0;

    return sumar_digitos(n / 10) + n % 10;
}

int main(void)
{
    printf("Fibonacci de 10: %llu\n",
            (long long unsigned)fibonacci_recursivo(10));

    printf("Factorial de 11: %llu\n",
            (long long unsigned)factorial_recursivo(10));

    printf("1234 invertido: %lu\n",
            (long unsigned)invertir(1234));

    printf("La suma de los digitos de 729 es: %lu\n",
            (long unsigned)sumar_digitos(729));
    return EXIT_SUCCESS;
}
