/*======================*
 * Identificadores de C *
 *======================*/

/**
 * Autor: Martínez Ortiz Saúl Axel
 * Dificultad: Básico.
 * Requisitos: Bases de lenguaje C.
 * Estilo de código: Misceláneo.
 */

#include <stdio.h>  // printf
#include <stdlib.h> // EXIT_SUCCESS

#define IMPRIME_VAR(var)                                            \
        printf("La variable " #var " tiene el valor: %d\n", var);

int main(void)
{
    /* Los identificadores son símbolos por medio de los cuales el  |
     | programador hace referencia a las variables y a datos con    |
     | los que hace operaciones y procesos. En C, están formados    |
     | por una secuencia de letras, números, guiones bajos y        |
     | y nombres de carácter universal que no puede comenzar con un |
     | número. La expresión regular para los identificadores es:    |
     |                                                              |
    (<letra>|<nombre_universal>|_)(<letra>|<nombre-universal>|[0-9]|_)*
     |                                                              |
     | Algunas variables válidas son:                               */
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

    /* ANSI X3.159-1989 (C89 para los amigos), especifica un        |
     | mínimo de caracteres que debe poder soportar un compilador   |
     | para los identificadores. Concretamente dicta que los        |
     | símbolos locales deben poder tener al menos 63 caracteres de |
     | longitud mientras que los globales al menos 31. No obstante  |
     | la mayoría de los compiladores soportan identificadores de   |
     | longitud mucho mayor que la mínima especificada por el       |
     | estándar. Si la portabilidad es prioridad, no debe usar      |
     | identificadores con longitud mayor a la dictada previamente. |
     | ## Estándares posteriores pueden definir una cantidad mayor  |
     | ## de símbolos por identificador, sin embargo, la            |
     | ## especificación de C89 sigue siendo la más portable.       */

    /* Si las dos variables siguientes fueran globales, algunos     |
     | compiladores que sigan el estándar C89 podrían               |
     | interpretarlas de manera idéntica.                           */
    int esta_variable_mide_mas_de_la_longitud_segura_segun_ansiA = 100;
    int esta_variable_mide_mas_de_la_longitud_segura_segun_ansiB = 101;

    IMPRIME_VAR(esta_variable_mide_mas_de_la_longitud_segura_segun_ansiA);
    IMPRIME_VAR(esta_variable_mide_mas_de_la_longitud_segura_segun_ansiB);

    /* Los nombres de carácter universal son símbolos que            |
     | representan un carácter de la especificación Unicode. Se      |
     | forman anteponiendo la secuencia de escape '\u' al valor      |
     | correspondiente a un carácter Unicode expresado en 4 dígitos  |
     | hexadecimales o la secuencia '\U' seguida del valor expresado |
     | en 8 dígitos hexadecimales. En resumen, se escriben:          |
     |                                                               |
     |                 \u0xxxx o \Uxxxxxxxx                          |
     |                                                               |
     | Donde los símbolos 'x' representan ĺos dígitos hexadecimales  |
     | del punto de código.                                          |
     | Los nombres de carácter universal se introducen en C99.       |
     | Si usas un compilador bastante viejo es posible que no        |
     | esta característica. Para versiones viejas de GCC, por        |
     | ejemplo, se tiene que habilitar su uso por medio de la        |
     | bandera de compilación: -fextended-identifiers.               |
     |                                                               |
     | A continuación algunos identificadores que incluyen símbolos  |
     | universales.                                                  */

#if defined(__STDC_UTF_16__) || defined(__STDC_UTF_32__)
    int a\u00F1o = 1996;    // \u00F1 = ñ, a\u00F1o = año
    IMPRIME_VAR(a\u00F1o);

    // \u304B = か
    // \u308F = わ
    // \u3044 = い
    // \u3044 = い
    // \u304B\u308F\u3044\u3044 = かわいい = kawaii
    int \u304B\u308F\u3044\u3044 = ':' + 'D';
    IMPRIME_VAR(\u304B\u308F\u3044\u3044);
#else
#warning Es posible que su compilador sea viejo para soportar caracteres universales
#endif

    /* En identificadores globales las secuencias de carácter universal |
     | con valor menor o igual a 0000FFFF cuentan como 6 caracteres sin |
     | importar la longitud que ocupen en el código (incluso si se usa  |
     | el formato \U0000xxxx en el que ocuparían 10 símbolos de         |
     | longitud en el código fuente) mientras que las secuencias        |
     | mayores o iguales a 00010000 se consideran como 10 caracteres.   |
     | Por lo tanto si la variable かわいい escrita anteriormente fuera |
     | global tendría una longitud de 24 caracteres y estaría cerca del |
     | límite permitido.                                                */

    /* Los punto de código universales son una forma indirecta de       |
     | colocar símbolos no ASCII en el código fuente. Sin embargo hay   |
     | lenguajes que pueden colocar esos símbolos directamente.         |
     | Si una función de C es llamada desde uno de esos lenguajes, se   |
     | puede usar el nombre real en lugar de enmascarar el              |
     | identificador con secuencias de escape.                          |
     |                                                                  |
     | Ejemplo: Desde C#, la función 'obtenerA\00F1o()' (que estaría    |
     | presumiblemente hecha en C) se podría invocar simplemente como:  |
     |  'obtenerAño()'                                                  */

    return EXIT_SUCCESS;
}
