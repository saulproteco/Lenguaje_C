/*=========================*
 * El tipo especial "void" *
 *=========================*/

#include <stdio.h>  // printf, getchar
#include <stdlib.h> // EXIT_SUCCESS

int main(void)
{
    /* El tipo void es un tipo de dato especial que no entra dentro de  *
     * la clasificación del resto. Esto se debe a que es un tipo del    *
     * cual no se puden declarar variables.                             *
     *                                                                  *
     * Su uso es principalmente como como requisito semántico para      *
     * indicar una lista de parámetros vacía o una función que no tiene *
     * valor de retorno. Sin embargo también puede ser usado para       *
     * anular el resultado de operaciones y para hacer uso de punteros  *
     * genéricos.                                                       */

    // Las variables de tipo void no existen, por lo que la siguiente línea
    // es semanticamente incorrecta. Descomente para corroborar.

    /*void variable;*/

    // Sin embargo, resulta que el tipo de dato void tiene un tamaño, el
    // cual corresponde con la mínima resolución referenciable en la
    // computadora o "resolución mínima" (1 byte). Aún así, es probable
    // que el tratar obtener su tamaño cause un poco de inconformidad por
    // parte del compilador el cual puede responder con alguna
    // advertencia.

    printf("El tamaño de \"void\" es: %zu\n", sizeof(void));

    // Esa última caracteristica permite que, aunque una variable void
    // no pueda ser usada, el crear y manipular punteros a void sea
    // posible. Dichos punteros, conocidos como punteros universales,
    // son capaces de referenciar cualquier dirección de memoria dado que
    // trabajan a la resolución mínima.
    // Vea la sección de teoría de apuntadores para mas información sobre
    // el uso de dichos punteros.


    // En C, el uso de la palabra void no suele ser implicito como en otros
    // lenguales (en los que se incluye C++). Por ejemplo, cuando queremos
    // declarar el prototipo de una función que no reciba argumentos, si
    // no usamos la palabra void explicitamente lo que el compilador
    // realmente entiende es que no debe hacer ninguna revisión sobre las
    // llamadas a la función. Ejemplo:
    //  Si declaramos:
    //      int funcion();
    //
    //  Podriamos llamar dicha función como:
    //      funcion(10)
    //
    //          ó
    //
    //      funcion("¿Y mis 50,000 pesos qué?\n");
    //
    // Por otro lado si no ponemos la palabra void para indicar que una
    // función no regresa nada, el tipo de retorno será por defecto un
    // entero por lo que:
    //
    //      funcion()
    //
    //  es lo mismo que:
    //
    //      int funcion()
    //
    // Moraleja, siempre usar explicitamente la palabra void en donde
    // esta sea requerida (al menos en C).


    // El último uso que se mencionaba de la palabra void es el suprimir
    // el valor de algúna expresión. Lo cuál se hace mediante la
    // sintaxis de una conversión de tipos, situando la palabra void entre
    // parénntesis justo antes de la expresión cuyo valor se quiere
    // suprimir.

    (void) printf("El retorno del printf se va a ignorar\n");

    // Suprimir valores hace imposible usarlos en una expresión pero
    // también silencia las advertencias del compilador sugiriendonos hacer
    // uso del valor de retorno de una función.

    return EXIT_SUCCESS;
}
