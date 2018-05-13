/*======================================================*
 * Principios de la modularidad                         *
 * Para compilar este grupo de archivos escriba         *
 *  $ gcc principal.c modulo.c -o programa_unido        *
 *                                                      *
 * Para mantener un programa lo suficientemente         *
 * ordenado para poder extenderlo es necesario          *
 * tener una buena organización en el.                  *
 *                                                      *
 * En principio, esto se logra con el simple hecho      *
 * de separar la funcionalidad en funciones pero esta   *
 * mira se queda corta cuando se empieza a trabajar con *
 * proyectos medianamente grandes.                      *
 *                                                      *
 * En programas más grandes, la separación no se hará   *
 * solo entre funciones, sino también en componentes    *
 * del programa.                                        *
 *                                                      *
 * Por ejemplo, si programáramos un juego, podríamos    *
 * identificar unos cuantos componentes mayores que     *
 * se deberían realizar para elaborarlo por completo:   *
 * - Manejo de los gráficos.                            *
 * - Manejo de los eventos.                             *
 * - Lógica interna del juego.                          *
 * - Sistema de guardado y serialización de datos.      *
 *                                                      *
 * Cada uno de esos componentes seria separado en un    *
 * subprograma llamado modulo. Este modulo no realiza   *
 * una sola tarea demasiados especifica como lo hacen   *
 * las funciones, por ello, deberá contener una         *
 * variedad de estas así como su conjunto de variables  *
 * etc, etc.                                            *
 *======================================================*/

/* Las cabeceras se incluyen en todo lugar que requiera las definiciones */
#include <stdio.h>
#include "C01_Cabecera.h" // Incluye prototipos y variables externas

/*
 * Las variables globales sin modificador pueden potencialmente
 * ser vistas desde otros archivos si estos hacen una definición extern
 */
int variable_global;

/* Las variables globales con el modificador static solo pueden ser
 * vistos en la unidad de traducción en que son declaradas. La unidad
 * de traducción es generalmente sinónimo del archivo excepto cuando
 * se usa la directiva #include para copiar el contenido de un
 * archivo en otro. Sin embargo, poner código o variables en archivos
 * de cabecera es mala práctica y por ello volvemos a la situación
 * en que es los conceptos de "unidad de traducción" y "archivo" son
 * equivalentes.
 */

static int variable_de_archivo;

int regresa_valor(void) {
    // La razón de que las variables estáticas no se vean fuera del
    // archivo es que se restringe que su espacio sea reservado por
    // todo el tiempo de vida del programa y que las referencias a
    // estas sean fijadas en tiempo de traducción.
    // Dado que la traducción de archivos se hace individualmente no
    // es posible enlazar variables de otros archivos si dichas variables
    // son estáticas.

    // La siguiente declaración hace que i sea una variable persistente
    // a través de las diversas llamadas a la función y hace que la
    // inicialización a 0 se ejecute solo una vez cuando dicha variable
    // es creada.
    static int i = 0;

    return ++i;
}

int main(void) {
    (void) variable_de_archivo;
    // La variable var es externa, es decir, no es de este archivo.
    // Para poder ver una variable externa es necesaria una definición
    // como la que sigue:
    //  extern int var;
    // Dicha definición suele estar en un archivo de cabecera para que
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

    // Probando la variable estática
    for (int i = 0; i < 100; i++) {
        printf("El valor es %d\n", regresa_valor());
    }
    return 0;
}
