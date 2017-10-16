/*=====================================*
 * Ejemplos de operadores relacionales *
 *=====================================*/

#include <stdio.h>  // printf
#include <stdlib.h> // EXIT_SUCCESS

// Función si_o_no que regresa las cadenas que corresponde
// al valor de verdad que reciba.
static const char * si_o_no(_Bool condicion)
{
    if (condicion) return "si";
    else           return "no";
}

int main(int argc, const char * const * const argv)
{
    int a, b;
    _Bool exito;

    // Establecemos los valores a comparar

    if ( argc == 3 ) {

        exito = sscanf(argv[1], "%d", &a);
        exito &= sscanf(argv[2], "%d", &b);

    } else {

        printf("Escriba dos números: ");
        exito = (scanf("%d %d", &a, &b) == 2);

    }

    if ( !exito )
        puts("Ingrese números válidos"), exit(EXIT_FAILURE);

    // Haciendo las comparaciones
    printf("Demostración de los operadores relacionales\n\n");

    printf("Los valores son: a = %d y b = %d\n", a, b);

    // Imprimiendo los valores de verdad
    printf("¿a > b?  %s\n", si_o_no(a > b));
    printf("¿a < b?  %s\n", si_o_no(a < b));
    printf("¿a <= b? %s\n", si_o_no(a <= b));
    printf("¿a >= b? %s\n", si_o_no(a >= b));
    printf("¿a == b? %s\n", si_o_no(a == b));
    printf("¿a != b? %s\n", si_o_no(a != b));
    getchar();

    /* Los operadores relacionales, al igual que los aritméticos, solo  *
     * son capaces de hacer operaciones entre tipos idénticos, de modo  *
     * que si se aplicamos alguno de estos operadores a tipos distintos *
     * uno de ellos será convertido implícitamente al tipo de dato más  *
     * amplio.                                                          *
     * La jerarquía de conversión es aproximadamente la que sigue:      *
     *                                                                  *
     * _Bool -> char -> unsigned char -> short -> unsigned short -> int *
     *       -> unsigned int -> long -> unsigned long -> long long      *
     *       -> unsigned long long -> float -> double -> long double.   *
     *                                                                  *
     * Cuando se realizan operaciones con apuntadores también ocurren   *
     * casteos implícitos de enteros a apuntador (que viene a ser un    *
     * entero sin signo), sin embargo no es válido combinar operadores  *
     * de punto flotante con apuntadores.                               *
     *                                                                  *
     * La lista anterior presenta el orden de las conversiones          *
     * implícitas pero obviamente uno puede hacer casi cualquier        *
     * operación de conversión si lo hace de forma explícita            */

    puts("Algunos ejemplos extra:");

    // Como no se puede comparar entre 'int' y 'float' se hace una
    // conversión implícita del 1 a 1.0.
    if ( 1 == 1.1 )
        puts("1 es igual a 1.1\n");
    else
        puts("1 no es igual a 1.1\n");

    // En caso de que se haga una conversión previa del flotante a entero
    // si se puede realizar la comparación.
    if ( 1 == (int) 1.1 )
        puts("Es igual\n");
    else
        puts("No es igual\n");

    return EXIT_SUCCESS;
}
