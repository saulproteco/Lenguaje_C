/*===================*
 * Tipos incompletos *
 *===================*/

/**
 * Autor: Martínez Ortiz Saúl Axel
 * Dificultad: Básico.
 * Requisitos: Bases de lenguaje C y funcionamiento de la RAM.
 * Estilo de código: Microsoft
 */

#include <stdlib.h> // EXIT_SUCCESS


int main(void)
{
    /* Los tipos incompletos tienen una estrecha relación con los tipos *
     * derivados (arreglos, estructuras, uniones) los cuales tendrán su *
     * propio capitulo.                                                 *
     *                                                                  *
     * Lo principal que hay que saber sobre los tipos incompletos es    *
     * que no pueden usarse hasta ser completados en el mismo u en otro *
     * archivo fuente. No puede haber tipos incompletos como miembros   *
     * de estructuras o uniones (aunque los arreglos flexibles se       *
     * asemejen) y en ocasiones se usan para esconder la implementación *
     * interna de alguna variable o estructura y crear "tipos opacos",  *
     * concepto similar a las variables "privadas" en otros lenguajes.  */

    /* Para crear una estructura o unión incompleta hay que hacer una   *
     * declaración anticipada de la misma o declarar una variable       *
     * externa o un apuntador a un tipo estructura que no haya sido     *
     * definida aún.                                                    */

    extern struct EstructuraIncompleta es1;
    struct EstructuraIncompleta * es2;

    /* Para completar la estructura simplemente hace falta definir la  *
     * estructura.                                                     */

    struct EstructuraIncompleta
    {
        int a;
        int b;
    };

    /* Para crear un arreglo incompleto no se especifique la longitud   *
     * del arreglo que no tenga una lista de inicialización en el       *
     * ámbito global o declararla en cualquier bloque con la palabra    *
     * extern.                                                          */
    extern int arr[];

    /* El tipo se debe completar en otro contexto */
    return EXIT_SUCCESS;
}
