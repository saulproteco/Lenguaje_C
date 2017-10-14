/*========================================*
 * Operaciones bAsicas mediante recursiOn *
 * DescripciOn:                           *
 * AplicaciOn de la recursividad para     *
 * hacer las operaciones de suma,         *
 * resta, multiplicaciOn y divisiOn.      *
 *========================================*/

#include <stdio.h>  // printf
#include <stdlib.h> // EXIT_SUCCESS
#include <string.h> // strlen
#include <ctype.h>  // isdigit
#include <stdint.h> // Enteros tamanio fijo
#include <assert.h> // macro assert

// Prototipos de funciOn
static int64_t suma(int32_t n, int32_t m);
static int64_t resta(int32_t n, int32_t m);
static int64_t mult(int32_t n, int32_t m);
static int64_t divi(int32_t n, int32_t m);
static int64_t div_auxiliar(int32_t n, int32_t m);
static _Noreturn void mensaje_error(const char * const mensaje);

int main(int argc, const char * const * const argv)
{
    long long numero1, numero2;

    /* Para asegurar la consistencia de las operaciones aritmEticas *
     * sobre los diferentes sistemas operativos y arquitecturas,    *
     * es recomendable realizar esta mediante los enteros definidos *
     * en stdint, que nos provee de alias que nos permiten          *
     * especificar el espacio en bits que requerimos sobre una      *
     * variable entera y nos aseguran que ese tamanio se va a       *
     * mantener en todas las plataformas.                           *
     *                                                              *
     * La utilizaciOn de dichos alias genera un cOdigo menos        *
     * propenso a tener bugs extranios sobre una computadora y no   *
     * sobre otra, lo cual facilita el trabajo de depuraciOn.       *
     *                                                              *
     * La dificultad es que estos enteros no deben ser usados en    *
     * operaciones de entrada y salida o de conversiOn que trabejen *
     * con tipos bAsicos, dado que estas esperan siempre un valor   *
     * la longitud definida por el sistema, y un entero de tamanio  *
     * fijo, por ejemplo int32_t, puede estar asociado a un int en  *
     * cierto sistema mientras que en otro puede estar asociado a   *
     * long. Aunque la lOgica y las operaciones se calculen usando  *
     * estos enteros, a la hora de manejar operaciones de entrada y *
     * salida se deben usar los tipos normales.                     */

    if ( argc == 3 ) { // Se recibieron los argumentos por consola

        // Se comprueba que la primera cadena este compuesta por
        // valores numEricos
        for (int_fast32_t i = 0; i < strlen(argv[1]); i++) {
            if ( !isdigit(argv[1][i]) )
                mensaje_error("Datos invAlidos");
        }

        // Se comprueba la segunda cadena
        for (int_fast32_t i = 0; i < strlen(argv[2]); i++) {
            if ( !isdigit(argv[2][i])  )
                mensaje_error("Datos invAlidos");
        }

        numero1 = atoll(argv[1]); // atoll es c99 dado que antes
        numero2 = atoll(argv[2]); // el tipo long long no era estandar

        if ( numero2 == 0 )
            mensaje_error("No se puede dividid por 0");

    } else {
        printf("Ingresa dos nUmeros: ");

        if ( scanf("%lld %lld", &numero1, &numero2) != 2 )
            mensaje_error("Datos invAlidos");

    }


    printf("La suma de los nUmeros es: %lld\n",
            (long long) suma(numero1, numero2));
    printf("La resta de los nUmeros es: %lld\n",
            (long long) resta(numero1, numero2));
    printf("La multiplicaciOn de los nUmeros es: %lld\n",
            (long long) mult(numero1, numero2));
    printf("La divisiOn entera de los nUmeros es: %lld\n",
            (long long) div_auxiliar(numero1, numero2));

    return EXIT_SUCCESS;
}

int64_t suma(int32_t n, int32_t m)
{
    if (m < 0) return resta(n, -m);

    if (m == 0) return n;

    return suma(n, m - 1) + 1;
}

int64_t resta(int32_t n, int32_t m) {
    if (m < 0) return (suma(n, -m));

    if (m == 0) return n;

    return resta(n, m - 1) - 1;
}

int64_t mult(int32_t n, int32_t m)
{
    int8_t signo = m < 0 ? -1 : 1;

    if (m == 0)
        return 0;

    return signo * mult(n, signo * m - 1) + n;
}

int64_t div_auxiliar(int32_t n, int32_t m)
{
    int8_t signo; // Entero de 1 byte

    if ( n > 0 ) {
        signo = 1;
    } else {
        signo = -1;
        n *= -1;
    }

    if ( m < 0 ) {
        signo *= -1;
        m *= -1;
    }

    return signo * divi(n, m);
}

int64_t divi(int32_t n, int32_t m)
{
    assert( m != 0 );

    if ( n < 0 )
        return -1;
    if ( n == 0 )
        return 0;

    return divi(n - m, m) + 1;
}

_Noreturn void mensaje_error(const char * const mensaje)
{
    fprintf(stderr, "%s\n", mensaje);
    exit(EXIT_FAILURE);
}
