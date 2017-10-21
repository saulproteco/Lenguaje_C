/*======================*
 * Identificadores de C *
 *======================*/

/**
 * Autor: Martínez Ortíz Saúl Axel
 * Dificultad: Básico.
 * Requisitos: Bases de lenguaje C.
 * Estilo de código: Miscelaneo.
 */

#include <stdio.h>  // printf
#include <stdlib.h> // EXIT_SUCCESS

#define IMPRIME_VAR(var)                                            \
        printf("La variable " #var " tiene el valor: %d\n", var);

int main(void)
{
    /* Los identificadores son símbolos por medio de los cuales el  *
     * programador se refiere a las direcciones de memoria de las   *
     * mismas para realizar procesos y operaciones. Los             *
     * identificadores se conforman por una secuencia de letras,    *
     * números y guiones bajos, que no puede comenzar con un número.*
     * La expresión regular para los identificadores es la          *
     * siguiente:                                                   *
     *                                                              *
     *  (<letra>|_)(<letra>|[0-9]|_)*                               *
     *                                                              *
     * A continuación, la declaración de algunas variables para     *
     * demostrar lo anterior.                                       */
    int esteEsElUnNombreDeVariable = 1;
    int este_es_otro = 20;
    int var1 = -1;
    int var5312 = 5312;
    // int 123hola; // Identificador inválido
    int _ = 10; // Solo un guión bajo es un identificador válido
    int a1b2c3d4 = 0xa1b2c3d4;
    // int 2z; // Identificador inválido

    IMPRIME_VAR(esteEsElUnNombreDeVariable);
    IMPRIME_VAR(este_es_otro);
    IMPRIME_VAR(var1);
    IMPRIME_VAR(var5312);
    IMPRIME_VAR(_);
    IMPRIME_VAR(a1b2c3d4);

    /* ANSI X3.159-1989 (Ansi C para los amigos), especifica un     *
     * minimo de caracteres que debe poder soportar un compilador   *
     * para los identificadores. Concretamente dicta que los        *
     * símbolos locales deben poder tener al menos 63 caracteres de *
     * longitud mientras que los globales al menos 31. No obstante  *
     * la mayoría de los compiladores soportan identificadores de   *
     * longitud mucho mayor que la mínima especificada por el       *
     * estandar. Simplemente recuerde que si la portabilidad es una *
     * prioridad, no debe usar identificadores más largos de los    *
     * especificados dada la posibilidad de que haya compiladores   *
     * que tan solo interpretan correctamente los mínimos           *
     * caracteres necesarios.                                       *
     * Por ejemplo, si las variables a continuación fueran globales *
     * podría haber conflictos sobre algunos compiladores, lo cual  *
     * comprobará si al compilar este programa le aparece un error  *
     * que diga "redeclaration of variable" o algo similar.         */

    int esta_variable_mide_mas_de_la_longitud_segura_segun_ansiA = 100;
    int esta_variable_mide_mas_de_la_longitud_segura_segun_ansiB = 101;

    IMPRIME_VAR(esta_variable_mide_mas_de_la_longitud_segura_segun_ansiA);
    IMPRIME_VAR(esta_variable_mide_mas_de_la_longitud_segura_segun_ansiB);

    /* Como quizas notó, la expresión regular de los identificadores *
     * descrita anteriormente no definió el patrón "<letra>". Se     *
     * trata de un acto completamente deliberado tomando en cuenta   *
     * que la definición de <letra> de hecho se ha alterado con el   *
     * tiempo.                                                       *
     *                                                               *
     * Originalmente <letra> se referia solo a las letras del        *
     * conjunto de símbolos del idioma inglés, por lo que si se está *
     * trabajando con C-89 ó alguna versión previa el patrón letra   *
     * sería definido como sigue:                                    *
     *                                                               *
     *      [A-Z-a-z]                                                *
     *                                                               *
     * Una vez introducida la especificación de los caracteres       *
     * universales al lenguaje en el estandar C-99 se amplió         *
     * enormemente el conjunto de símbolos que eran considerados     *
     * letras. No obstante, sigue sin ser posible incrustar dichos   *
     * caracteres directamente en el código fuente sino que se       *
     * estos se espeficican mediante la secuencia de caracter        *
     * universal con el formato \uxxxx o \Uxxxxxxxx donde los        *
     * marcados con una 'x' representan digitos hexadecimales        *
     * que corresponden a un código de punto cuyo símbolo se puede   *
     * identificar en una tabla con los símbolos unicode.            *
     *                                                               *
     * A continuación algunos identificadores que incluyen simbolos  *
     * universales.                                                  */

    int a\u00F1o = 1996;    // \u00F1 = ñ, año = 1996
    IMPRIME_VAR(a\u00F1o);

    // \u304B = か
    // \u308F = わ
    // \u3044 = い
    // \u3044 = い
    // \u304B\u308F\u3044\u3044 = かわいい = kawaii :D
    int \u304B\u308F\u3044\u3044 = ':' + 'D';
    IMPRIME_VAR(\u304B\u308F\u3044\u3044);

    /* Las secuencias de caracter universal con valor menor o igual a   *
     * 0000FFFF cuentan como 6 caracteres sin importar la longitud que  *
     * ocupen internamente (incluso si se usa el formato \U0000xxxx en  *
     * el que ocuparian 10 símbolos de lontitud en el código fuente)    *
     * mientras que las secuencias mayores o iguales a 00010000 se      *
     * consideran como 10 caracteres. Por lo tanto la palabra かわいい  *
     * escrita anteriormente seria contabilizada por el compilador como *
     * un identificadore de 24 caracteres.                              */

    return EXIT_SUCCESS;
}
