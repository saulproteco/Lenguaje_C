/*======================================================*
 * Principios de la modularidad                         *
 * Para compilar este grupo de archivos escriba         *
 *  $ gcc principal.c modulo.c -o programa_unido        *
 *                                                      *
 * Para mantener un programa lo suficientemente         *
 * ordenado para poder extenderlo es necesario          *
 * tener una buena organizaciOn en el.                  *
 *                                                      *
 * En principio, esto se logra con el simple hecho      *
 * de separar la funcionalidad en funciones pero esta   *
 * mira se queda corta cuando se empieza a trabajar con *
 * proyectos medianamente grandes.                      *
 *                                                      *
 * En programas mAs grandes, la separaciOn no se harA   *
 * solo entre funciones, sino tambiEn en componentes    *
 * del programa.                                        *
 *                                                      *
 * Por ejemplo, si programaramos un juego, podriamos    *
 * identificar unos cuantos componentes mayores que     *
 * se deberian realizar para elaborarlo por completo:   *
 * - Manejo de los grAficos.                            *
 * - Manejo de los eventos.                             *
 * - LOgica interna del juego.                          *
 * - Sistema de guardado y serializaciOn de datos.      *
 *                                                      *
 * Cada uno de esos componentes seria separado en un    *
 * subprograma llamado modulo. Este modulo no realiza   *
 * una sola tarea demasiados especifica como lo hacen   *
 * las funciones, por ello, deberA contener una         *
 * variedad de estas asI como su conjunto de variables  *
 * etc, etc.                                            *
 *======================================================*/

/* Las cabeceras se incluyen en todo lugar que requera las definiciones */
#include <stdio.h>
#include "cabecera.h" // Incluye prototipos y variables externas

/*
 * Las variables globales sin modificador pueden potencialmente
 * ser vistas desde otros archivos si estos hacen una definiciOn extern
 */
int variable_global;

/* Las variables globales con el modificador static solo pueden ser
 * vistos en la unidad de traducciOn en que son declaradas. La unidad
 * de traducciOn es generalmente sinonimo del archivo excepto cuando
 * se usa la directiva #include para copiar el contenido de un
 * archivo en otro. Sin embargo, poner cOdigo o variables en archivos
 * de cabecera es mala prActica y por ello volvemos a la situaciOn
 * en que es los conceptos de "unidad de traducciOn" y "archivo" son
 * equivalentes.
 */

static int variable_de_archivo;

int regresa_valor(void) {
    // La razOn de que las variables estAticas no se vean fuera del
    // archivo es que se restringe que su espacio sea reservado por
    // todo el tiempo de vida del programa y que las referencias a
    // estas sean fijadas en tiempo de traducciOn.
    // Dado que la traducciOn de archivos se hace individualmente no
    // es posible enlazar variables de otros archivos si dichas variables
    // son estAticas.

    // La siguiente declaraciOn hace que i sea una variable persistente
    // a travEz de las diversas llamadas a la funciOn y hace que la
    // inicializaciOn a 0 se ejecute solo una vez cuando dicha variable
    // es creada.
    static int i = 0;

    return ++i;
}

int main(void) {

    // La variable var es externa, es decir, no es de este archivo.
    // Para poder ver una variable externa es necesaria una definiciOn
    // como la que sigue:
    //  extern int var;
    // Dicha definiciOn suele estar en un archivo de cabecera para que
    // todos los archivos que requieran compartir esa variable puedan
    // hacerlo.
    //
    // El uso de variables globales compartidas por muchos archivos
    // puede resultar en modificaciones inesperadas al valor de la
    // misma lo cual suele generar problemas inesperados. En general,
    // solo deben usarse cuando sea estrictamente necesario.
    printf("La variable es: %d\n", var);

    var = 20;

    imprimir_variable_externa();

    funcion_inline();

    // Probando la variable estAtica
    for (int i = 0; i < 100; i++) {
        printf("El valor es %d\n", regresa_valor());
    }
    return 0;
}
