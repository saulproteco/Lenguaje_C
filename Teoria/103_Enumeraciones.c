/*==================*
 * Tipos enumerados *
 * (Enumeraciones)  *
 *==================*/

/**
 * Autor: Martínez Ortíz Saúl Axel
 * Dificultad: Básico.
 * Requisitos: Bases del lenguaje C.
 * Estilo de código: Google.
 */

/* Los tipos enumerados son, junto con las estructuras y las uniones,   *
 * tipos de datos definidos por el programador. Se trata de un conjunto *
 * de constantes simbólicas enteras similares a un conjunto de          *
 * directivas #define, pero que por defecto tienen un valor ascendente  *
 * comenzando en 0 a menos que se les de un valor de manera explicita.  *
 * La forma de definir las uniones es similar a la de las estructuras:  *
 *  enum [nombre_union] {                                               *
 *          CONSTANTE1 [ = valor ] [,]   Se usa ',' en lugar de ';'     *
 *          [CONSTANTE2 [ = valor2 ] [,]...]                            *
 *  } [ variable_enumeracion = [ constante ]...];                       *
 *                                                                      *
 * La diferencia con las estructuras y uniones es que las entidades     *
 * definidas entre la declaración de la enumeración se encuentran en el *
 * mismo espacio de nombres de los identificadores, lo que significa    *
 * que el no se pueden declarar variables o funciones con el mismo      *
 * nombre en el mismo bloque (o en el contexto global), aunque siempre  *
 * se pueden declarar en un bloque más interno en donde el objeto local *
 * escondería al global.                                                */

#include <stdio.h>  // printf
#include <stdlib.h> // EXIT_SUCCESS

#define imprimirEnum(en) printf(#en " = %d\n", en);

enum /* enumeracionGlobal */ { // No es necesario poner nombre a la enumeración
                               // si solo se quieren usar las constantes.
                               // Require la etiqueta si se quieren declarar
                               // variables con dicho tipo.
    A = 1,
    B = 0,
    C,      // Se enumeran de forma ascendente, por lo que C vale 1
    D = 5,  // Se puede omitir la coma final
};


int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;

    printf("Los valores de la enumeración global: \n");
    imprimirEnum(A);
    imprimirEnum(B);
    imprimirEnum(C);
    imprimirEnum(D);

    enum enumeracionLocal {
        A,  // 0
        B,  // 1
        C,  // 2
        D,  // 3
    };

    /*int A;*/  // No se puede declarar esta variable

    printf("Los valores de la enumeración local: \n");
    imprimirEnum(A);
    imprimirEnum(B);
    imprimirEnum(C);
    imprimirEnum(D);

/* Las enumeraciones facilitan la modificación del programa y aumentan la   *
 * verbosidad del código, no obstante siguen bastante limitadas en lenguaje *
 * C a comparación de otros lenguajes. Algunas de las ventajas que pueden   *
 * tener es que a diferencia de multiples #define's el compilador puede     *
 * advertir que no estamos tratando todos los casos de la enumeración en un *
 * switch cuando usamos la bandera -Wall                                    */

    // Se declara una variable de tipo enumeracionLocal
    enum enumeracionLocal variable_enumeracion = B;

    switch (variable_enumeracion) {
      case A:
        printf("La variable era A\n");
        break;

      case B:
        printf("La variable era B\n");
        break;
    }

    return EXIT_SUCCESS;
}
