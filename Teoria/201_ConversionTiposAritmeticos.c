/*==========================*
 * Conversiones aritméticas *
 *==========================*/

/**
 * Autor: Martínez Ortiz Saúl Axel
 * Dificultad: Básico.
 * Requisitos: Apuntadores básicos, funciones.
 * Estilo de código: Linux.
 */

#include <stdio.h>  // printf
#include <stdlib.h> // EXIT_SUCCESS

void func(_Complex double complejo);

#define IGNORAR_DESUSO(a, b, c) (void)(a), (void)(b), (void)(c)

int main(void)
{
/* Las conversiones entre tipos aritméticos son las más sencillas de hacer  *
 * puesto que no requieren del uso de funciones. Es más, la mayoría de las  *
 * veces se hace de forma implícita al realizar operaciones aritméticas o   *
 * pasar argumentos a funciones. Las conversiones implícitas se realizan    *
 * de manera que siempre se preserve el tipo que pueda representar la mayor *
 * cantidad de valores, las operaciones entre enteros sin signo y enteros   *
 * con signo se preserva el sin signo ya que puede representar más valores  *
 * positivos y al operar enteros y números de punto flotante la expresión   *
 * toma el tipo double. Dichas conversiones implícitas también se hacen     *
 * al asignar valores o al pasar argumentos a funciones que tengan          *
 * definido un prototipo en la misma unidad de traducción.                  */

        char a = 10;

        int b = a + 10; // a se convierte implícitamente a entero antes de operar

        double c = b / 6;   // La expresión no se convierte pues los dos
                            // operandos son enteros, pero el resultado si
                            // se convierte implícitamente cuando se asigna.

        func(c);    // El double se convierte implícitamente a _Complex
                    // por que la función tiene un prototipo visible, en caso
                    // contrario se conserva el tipo.

/* Por el contrario, si una conversión implica perdida de datos el          *
 * compilador emitirá advertencias que se tendrán que suprimir mediante     *
 * conversiones explicitas. Aunque en ese caso no son necesarias, ese tipo  *
 * de conversiones son necesarias antes de realizar divisiones entre enteros*
 * en los que se requiera conservar la parte decimal para guardarla, cuando *
 * se pasa argumentos a funciones estilo K&R (o no se tiene prototipo de    *
 * función que muchas veces es lo mismo) o con argumentos variables.        */

        c = (double) b / 6; // Se convierte b explícitamente a double
                            // y luego para hacer la operación de
                            // división el compilador convierte el 6
                            // de manera implícita a double para
                            // poder operar.

        a = (char)c + 2;    // Se hace la conversión a char antes de operar.

/* No se puede hacer conversión ni implícita ni explicita entre tipos       *
 * derivados pero si entre sus apuntadores, la cual requiere ser explicita  *
 * a menos que la conversión se haga desde o hacia un apuntador a void      */

        int  * ptrint  = &b;
        char * ptrchar = (char *) ptrint;   // Requiere conversión explicita
                                            // porque no involucra apuntadores
                                            // a void

        void * ptrvoid = ptrchar;   // Si el origen o el destino es un
                                    // apuntador a void no se requiere
                                    // conversión explicita. Sin embargo esta
                                    // puede ser necesaria si se quiere que
                                    // el código sea portable a c++.

        IGNORAR_DESUSO(a, b, c);
        IGNORAR_DESUSO(ptrint, ptrchar, ptrvoid);
        return EXIT_SUCCESS;
}

void func(_Complex double complejo) { (void) complejo; }

