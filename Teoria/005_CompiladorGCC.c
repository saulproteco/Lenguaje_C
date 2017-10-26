/*========================*
 * Uso del compilador GCC *
 *========================*/

/**
 * Autor: Martínez Ortíz Saúl Axel
 * Dificultad: Intermedio.
 * Requisitos: Manejo de la terminal.
 * Estilo de código: Google.
 */

/* Las opciones de compilación mostradas funcionan gcc o en compiladores    *
 * del mismo estilo como cywin, clang, musl (que en realidad es una         *
 * envoltura de gcc).                                                       *
 *                                                                          *
 * Para compilar un proyecto con gcc se usa la siguiente sintaxis:          *
 *      gcc [comandos...] archivo_entrada [otros_archivos_entrada...]       *
 *                                                                          *
 * Un proyecto se compone de mínimo un archivo fuente y en general no hay   *
 * límites impuestos por los compiladores actuales.                         */

/* Establezcamos el siguiente proyecto hipotético como ejemplo de           *
 * compilación:                                                             */

// Archivo fuente 1.
// funcion.c

double suma(double a, double b) {
    return a + b;
}

// Archivo fuente 2.
// principal.c

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char * argv[]) {
    int num1, num2;

    if ( argc == 3 ) {
        num1 = atoi(argv[1]);
        num2 = atoi(argv[1]);

        assert(num1 != 0);
        assert(num2 != 0);
    } else {
        errno = EINVAL;

        perror("Error"); exit(errno);
    }

    printf("The sum of the nums is: %d\n", suma(num1, num2));

    return 0;
}

/* Para compilar el siguiente con el estandar C11 se puede usar el          *
 * siguiente comando:                                                       *
 *      gcc -std=c11 funcion.c principal.c -o nombre_proyecto               *
 *                                                                          *
 * El estandar a utilizar determina las caracteristicas del lenguaje a las  *
 * que tendriamos acceso y a su vez el grado de compatibilidad con las      *
 * distintas plataformas. Por ejemplo, si se stablece la compilación para   *
 * el estandar c89 (-std=c89 ó -std=c90) se tendrá acceso a menos           *
 * caracteristicas del lenguaje pero habrá compatibilidad con casi todas    *
 * las plataformas.                                                         *
 *                                                                          *
 * Mediante la opción -o se puede establecer el nombre de que tendra el     *
 * binario de salida resultante de la compilación de todos los archivos.    */

/* Volviendo a nuestro ejemplo, el código anterior tiene un bug evidente    *
 * Ya que intenta imprimir una variable de tipo 'double' con el formato %d  *
 * en el printf. Asumiendo que dicho error no haya sido detectado aún, hay  *
 * multiples comandos que instruyen al compilador para revisar de manera    *
 * especialmente exhaustivo emitiendo más advertencias que ayudan al        *
 * programador a identificar erroes.                                        *
 * La lista completa se puede encontrar viendo el manual de gcc             *
 * pero algunos de los más útiles son:                                      *
 *      > -Wall y - Wextra: Activar todas las advertencias a la vez.        *
 *      > -pedantic : El compilador sigue de manera estricta el estandar.   *
 * Si añadimos esas opciones en la compilación nuestro comando queda como   *
 * el siguiente:                                                            *
 *                                                                          *
 *   gcc -std=c11 -Wall -Wextra funcion.c principal.c -o nombre_proyecto    */

/* Asumiendo que las advertencias del compilador ayudaron a corregir el     *
 * problema, el código ahora se veria como el que sigue:                    */

// Archivo fuente 1.
// funcion.c

double suma(double a, double b)
{
    return a + b;
}

// Archivo fuente 2.
// principal.c

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char * argv[])
{
    int num1, num2;

    if ( argc == 3 ) {
        num1 = atoi(argv[1]);
        num2 = atoi(argv[1]);

        assert(num1 != 0);
        assert(num2 != 0);
    } else {
        errno = EINVAL;

        perror("Error"); exit(errno);
    }

    printf("The sum of the nums is: %f\n", suma(num1, num2));

    return 0;
}

/* Las opciones de compilación anteriores ayudan a corregir errores         *
 * sintácticos pero ningún programa es capaz de corregir errores lógicos (al*
 * menos hasta que desarrollemos inteligencia artificial). Para corregir    *
 * ese tipo de errores, será necesario que nosotros mismos hagamos pruebas  *
 * sobre algún programa de depuración como GDB. Para ello, tenemos que      *
 * decirle al compilador que conserve información del programa original de  *
 * modo que el depurador pueda hacer uso de ella. La opción para hacer eso  *
 * es -g, con la cual la compilación se vería así.                          *
 *  gcc -std=c11 funcion.c principal.c -g -o nombre_proyecto                *
 *                                                                          *
 * Nota: Igualmente podrian resultar utiles en el proceso de depuración ver *
 *       las versiones intermedias de la traducción que genera el compilador*
 *       a travez de sus diferentes etapas, por ejemplo, la opción -E genera*
 *       el código resultante de la etapa de preprocesado, la opción -S     *
 *       genera el resultado del ensamblador (llamado igualmente código     *
 *       ensamblador). También se puede usar la opción --save-temps para    *
 *       que el compilador conserve todos los archivos intermedios.         *
 *                                                                          *
 * Después de usar GDB, el código resultaria similar a :                    */

// Archivo fuente 1.
// funcion.c

double suma(double a, double b)
{
    return a + b;
}

// Archivo fuente 2.
// principal.c

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char * argv[])
{
    int num1, num2;

    if ( argc == 3 ) {
        num1 = atoi(argv[1]);
        num2 = atoi(argv[2]);

        assert(num1 != 0);
        assert(num2 != 0);
    } else {
        errno = EINVAL;

        perror("Error"); exit(errno);
    }

    printf("The sum of the nums is: %f\n", suma(num1, num2));

    return 0;
}

/* Ahora sí, finalmente tenemos un código (idealmente) libre de errores que *
 * está listo para ser distribuido. Para esta etapa final hay una serie de  *
 * opciones de compilación usadas para cuando el binario está listo para    *
 * distribución como:                                                       *
 *      > -O[n] con n=0,1,2,3: Establece el grado de optimización que debe  *
 *                             aplicar el compilador al código.             *
 *      > -DNDEBUG           : Afecta las macros de la biblioteca estandar  *
 *                             que ayudan a la depuración (assert)          *
 *                             eliminando su efecto en el binario.          *
 * El comando de compilación en esta ocación resultaria:                    *
 *      gcc -std=c11 -O3 -DNDEBUG funcion.c principal.c -o nombre_proyecto  *
 *                                                                          *
 * Nota: Un grado alto de optimización no solo resulta útil cuando se       *
 *       compila el binario para distribución, también pueden ayudar en el  *
 *       diagnostico de errores en algunas ocaciones, sin embargo, alenta   *
 *       considerablemente el tiempo de compilación en proyectos grandes.   */

