/*======================*
 * Declaración de alias *
 *======================*/

/**
 * Autor: Martínez Ortiz Saúl Axel
 * Dificultad: Básico.
 * Requisitos: Bases de lenguaje C y funcionamiento de la RAM.
 * Estilo de código: Personalizado.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* La definición de alias se usa para facilitar la lectura del código   *
     * cuando se usan tipos especialmente complejos o rebuscados o cuando   *
     * se quiere dar compatibilidad de tipos en distintos sistemas para     *
     * (con ayuda de directivas de preprocesador).                          *
     *                                                                      *
     * La sintaxis de la declaración de alias es idéntica a la declaración  *
     * de una variable pero añadiendo la palabra reservada typedef al       *
     * principio de la declaración. El lugar que le correspondería al       *
     * nombre de la variable será el nuevo alias del tipo referido.         */

    {
        typedef unsigned numero_natural; // numero_natural ahora es alias de "unsigned"
        numero_natural var1, var2;
    }

    /* Contrario a lo que pasaría si se usara un simple #define para        *
     * declarar un alias, el typedef se aplica a todos los elementos que    *
     * se definen.                                                          */


    #define apuntador_entero_macro int *
    typedef int * apuntador_entero_typedef;

    {
        apuntador_entero_macro ptr1, ptr2;  // Se expande a int * ptr1, ptr2
                                            // por lo que solo el primer elemento
                                            // es un apuntador
    }

    {
        apuntador_entero_typedef ptr1, ptr2; // Se interpreta como int *ptr1, *ptr2;
    }

    /* Para declaraciones especialmente complejas se puede hacer uso de un  *
     * operador específico de GNU: typeof (no hace falta decir que no es    *
     * un operador estándar.                                                *
     * Por ejemplo, para hacer declarar un apuntador a la siguiente función *
     * se tiene que hacer una declaración algo compleja.                    */

    int funcion(int x) { return x; };
    int (*funcionQueRegresaFuncion(void))(int x) { return funcion; }
    // ## Las funciones anidadas tampoco son estándar. Son específicas de GCC

    /* Así se haría una definición sin typeof */
    {
        typedef int (*(*apFuncionQueRegresFuncion)(void))(int x);
        apFuncionQueRegresFuncion ap = &funcionQueRegresaFuncion;
    }

    /* El uso del operador typeof simplifica la definición */

    {
        typedef typeof(funcionQueRegresaFuncion) * apFuncionQueRegresFuncion;
        apFuncionQueRegresFuncion ap = &funcionQueRegresaFuncion;
    }

    /* De la misma forma se suele usar la declaración typedef para definir  *
     * apuntadores a arreglos, o para acortar la declaración de variables   *
     * de tipo estructura, unión o enumeración. En cuanto a estos últimos   *
     * sin embargo se recomienda hacerlo lo menos posible para no           *
     * enmascarar la composición de un tipo solo para escribir menos.       */
    return EXIT_SUCCESS;
}
