/*===========================*
 * Tipos de datos básicos en *
 *            C              *
 *===========================*/

/**
 * Autor: Martínez Ortiz Saúl Axel
 * Dificultad: Básico.
 * Requisitos: Bases de lenguaje C.
 * Estilo de código: Microsoft.
 */

#include <stdio.h>  // printf, getchar
#include <stdlib.h> // EXIT_SUCCESS

int main(void)
{
    /* Los tipos básicos se clasifican en las siguientes categorías:    *
     * enteros y números de punto flotante                              *
     * Todos los tipos básicos dependen del sistema, ya sea en tamaño o *
     * en comportamiento.                                               *
     *                                                                  *
     * Las variables enteras y de punto flotante a su vez forman el     *
     * conjunto de las variables escalares mientras que el resto (con   *
     * la excepción de los tipos enumerados) son los tipos compuestos,  *
     * es decir, aquellos que se forman en base a otros tipos.          *
     * Los enteros, flotantes (ya sean números reales o números         *
     * complejos) y los tipos enumerados forman el conjunto de los      *
     * tipos escalares [1].                                             *
     * El resto de tipos son llamados compuestos y se componen de una   *
     * combinación de los anteriores.                                   *
     *                                                                  *
     * A continuación el desglose de los varios subtipos de de cada     *
     * clasificación.                                                   */


    // ##### Variables enteras #####
    /* Los enteros se dividen en dos subtipos, los enteros con signo    *
     * que almacenan valores positivos o negativos sin decimales, y los *
     * enteros sin signo que solo almacenan positivos pero tienen el    *
     * doble de rango con el mismo espacio en memoria.                  *
     *                                                                  *
     * Los enteros sin signo dan la vuelta a su rango cuando se         *
     * desbordan, mientras que los signados can en comportamiento       *
     * indefinido.                                                      *
     *                                                                  *
     * La separación entre cada valor representado por un entero es     *
     * idéntica por lo que se trata de una representación de datos      *
     * lineal.                                                          *
     *                                                                  *
     * Sufren errores de representación tras operaciones como la        *
     * división, sin embargo son seguros en cuanto al resto de las      *
     * operaciones, incluyendo las relacionales y gracias a ello son    *
     * los valores más usados en las condiciones para estructuras de    *
     * control y ciclos.                                                */

    // Con signo:

    signed char          entero0 = -128; // Nombre corto: char.
    signed short int     entero1 = -500; // Nombre corto: short.
    signed int           entero2 = 2000; // Nombre corto: int.
    signed long int      entero3 = 990L; // Nombre corto: long.
    signed long long int entero4 = 40LL; // Nombre corto: long long.

    puts("Tamaño de los enteros signados:\n");
    printf("Tamaño char en este sistema:        %zu\n", sizeof(entero0));
    printf("Tamaño short en este sistema:       %zu\n", sizeof(entero1));
    printf("Tamaño int en este sistema:         %zu\n", sizeof(entero2));
    printf("Tamaño long en este sistema:        %zu\n", sizeof(entero3));
    printf("Tamaño long long en este sistema:   %zu\n", sizeof(entero4));
    getchar();

    /* Las literales enteras (todo número sin punto) son por defecto    *
     * de tipo "int". Si escribes un número mayor al límite de los "int"*
     * se desbordará y sus datos estarán corrompidos a pesar de que los *
     * guardes en una variable de mayor capacidad.
     * Para evitar esto se puede especificar que una constante es de    *
     * long o long long con los sufijos L y LL respectivamente.         *
     *                                                                  *
     * Otras formas de declarar literales enteros:                      *
     * 0b<numero><sufijo>? -> Declarar una constante en formato binario *
     * 0<numero><sufijo>?  -> Declarar una constante en formato octal   *
     * 0x<numero><sufijo>? -> Declarar una constante en formato hexa    *
     *                                                                  *
     *      Nota: El signo de interrogación después del sufijo indica   *
     *            que es un elemento opcional.                          */

    // Sin signo:

    _Bool                  enterob =     1; // No tiene otro nombre,
                                            // solo puede valer 0/1 y cuando
                                            // le asignas cualquier otra
                                            // cosa toma el valor de 1.
    unsigned char          entero5 =  255u; // Nombre corto: unsigned char.
    unsigned short int     entero6 = 1000u; // Nombre corto: unsigned short.
    unsigned int           entero7 = 2000u; // Nombre corto: unsigned.
    unsigned long int      entero8 = 990uL; // Nombre corto: unsigned long.
    unsigned long long int entero9 = 40uLL; // Nombre corto: unsigned long long.

    puts("Tamaño de los enteros sin signo:\n");
    printf("Tamaño _Bool en este sistema:              %zu\n", sizeof(enterob));
    printf("Tamaño unsigned char en este sistema:      %zu\n", sizeof(entero5));
    printf("Tamaño unsigned short en este sistema:     %zu\n", sizeof(entero6));
    printf("Tamaño unsigned en este sistema:           %zu\n", sizeof(entero7));
    printf("Tamaño unsigned long en este sistema:      %zu\n", sizeof(entero8));
    printf("Tamaño unsigned long long en este sistema: %zu\n", sizeof(entero9));
    getchar();

    /* El rango mayor de los enteros con signo se obtiene al usar   *
     * el bit del signo como un valor más de la representación del  *
     * número.                                                      *
     * Para las literales unsigned se requieren sufijos aunque se   *
     * pueden omitir sin corrupción de datos si el valor no supera  *
     * el rango de un "int".                                        */

    // ##### Variables de punto flotante #####
    /* Los tipos clasificados como punto flotante se dividen en reales  *
     * y complejos, siendo estos últimos una adición de C99 que es      *
     * opcional en C11.                                                 *
     * La forma más común de punto flotante es la especificado por el   *
     * estándar IEEE 754 de que clasifica los datos según la precisión: *
     * que guardan los datos:                                           *
     *  - Precisión media  / 16 bits - 4 decimales.                     *
     *  - Precisión simple /  32 bits - 7 decimales                     *
     *  - Precisión doble  /  64 bits - 15 decimales                    *
     *  - Precisión cuadruple / 128 bits  - 33 decimales                *
     *                                                                  *
     * Las tipos de datos float, double y long double o sus equivalentes*
     * complejos no tienen una longitud bien determinada ya que como    *
     * cualquier cosa en C, dependen del compilador. Lo que si tienen   *
     * es un requisito mínimo de que el tipo float y el double deben    *
     * tener una precisión equivalente o superior a un número de punto  *
     * flotante IEEE 754 de precisión media y que el float no puede ser *
     * mayor que el double.                                             *
     *                                                                  *
     * Generalmente, los flotantes no dan vuelta a sus valores como lo  *
     * hacen los enteros sin signo al desbordarse. En su lugar, llegan  *
     * a un "límite" del cual ya no pasarán por falta de precisión en   *
     * la representación.                                               *
     *                                                                  *
     * Las literales de punto flotante tiene por defecto el tipo        *
     * double y para hacer una literal 'float' se debe añadir el sufijo *
     * 'f' al final de un número flotante.                              *
     *                                                                  *
     * La separación entre cada valor representado por un flotante      *
     * va cambiando según las magnitudes representadas puesto que la    *
     * representación de datos no es lineal sino exponencial.           *
     *                                                                  *
     * Los errores de representación de este tipo de dato están menos   *
     * relacionados a las operaciones que a las propias magnitudes      *
     * que se manejan. Los flotantes pequeños suelen tener errores      *
     * igualmente pequeños mientras que cantidades grandes tiene error  *
     * absoluto más significativo (el error relativo se mantiene casi   *
     * constante). Este tipo de dato no se considera seguro para        *
     * aplicarse con comparaciones en condicionales o ciclos ni tampoco *
     * para iterar en valores muy grandes.                              */

    // Reales
    float  flotante1 = 5.5f;    // sufijo f

    double flotante2 = -7.2;    // Sin sufijo, las literales son double por defecto

    long double flotante3 = 3.141592653589793L; // Sufijo L al igual que en los enteros
                                                // long, la diferencia es que esta
                                                // literal tiene decimales.
    puts("Los tamaños de los flotantes:\n");
    printf("El tamaño del float es:       %zu\n", sizeof(flotante1));
    printf("El tamaño del double es:      %zu\n", sizeof(flotante2));
    printf("El tamaño del long double es: %zu\n", sizeof(flotante3));

#ifdef __STDC_IEC_559__
    puts("Este compilador usa el estándar IEEE 754 para la aritmética flotante\n"
         "Eso significa que el tipo \"float\" se corresponde con un número    \n"
         "flotante de precisión simple, el \"double\" se corresponde con un   \n"
         "número de doble precisión de los especificados por el mencionado    \n"
         "estándar");
#else
    puts("Este compilador no sigue el estándar IEEE 754 de aritmética flotante");
#endif
    getchar();

    /* Otras formas de declarar flotantes.                             *
     * [+-]?<número>e[+-]?<exponente>     -> El primer numero por 10   *
     *                                     al exponente                *
     * [+-]?<número>E[+-]?<exponente>     -> Lo mismo que el anterior  *
     *                                                                 *
     * Nota: Los corchetes indican opciones (signo positivo o negativo)*
     * mientras que el signo de interrogación nos informa que dicho    *
     * signo es opcional en la sintaxis.                               */

    // Complejos
    /* Como se mencionó antes, los tipos de datos compuestos están      *
     * formados por varios datos escalares. Tal es el caso de los       *
     * complejos que funcionan como un adaptador de tipo de dato y se   *
     * ajustan a las reglas del mismo (ya sea entero o flotante).       *
     * Dado lo anterior, los complejos no tiene clasificaciones ni      *
     * comportamiento por si solos, para hacerse una idea de su         *
     * funcionamiento hay que tener presente las reglas mencionadas con *
     * los demás tipos.                                                 *
     *                                                                  *
     * Si no especificamos ningún tipo al declarar una variable de tipo *
     * complejo toma por defecto el tipo 'double'. Las literales        *
     * complejas están formadas de dos valores del tipo escogido, una   *
     * escrita de manera normal y la otra acompañada de una 'i' al      *
     * final de su valor.                                               *
     *                                                                  *
     * La parte real e imaginaria dentro de un complejo se guardan      *
     * contiguas en memoria como si de un arreglo del tipo elegido se   *
     * tratara. Se puede acceder a sus partes por separado usando       *
     * aritmética de apuntadores u ocupar las macros definidas en la    *
     * cabecera complex.h.                                              *
     *                                                                  *
     * Las operaciones básicas de los complejos son manejadas por el    *
     * compilador pero no las operaciones de entrada y salida lo que    *
     * puede dificultar un poco su uso.                                 */

#ifndef __STDC_NO_COMPLEX__ // Como los números complejos son opcionales
                            // en C11, se debe revisar si la macro
                            // __STDC_NO_COMPLEX__ no está definida
#include <complex.h>

    _Complex float       complejo10 = 5.5f + 5.5f * I;
    _Complex double      complejo11 = -7.2 - 17.34e-20 * I;
    _Complex long double complejo12 = 15.5L - 123e-12L * I;

#ifdef __GNUC__
    // El lenguaje estándar tiene complejos compuestos de tipos flotantes
    // normales. Como extensión no estándar, el compilador GCC añade
    // soporte para complejos compuestos por otros tipos de datos como los
    // que siguien:
    _Complex signed char          complejo0 = +1   - 9999i;
    _Complex signed short int     complejo1 = -2   +  666i;
    _Complex signed int           complejo2 = +3   -   33i;
    _Complex signed long int      complejo3 = -5L  +   1Li;
    _Complex signed long long int complejo4 = +6LL -  2LLi;

    _Complex unsigned char          complejo5 = 1u   + 12ui;
    _Complex unsigned short int     complejo6 = 2u   + 11ui;
    _Complex unsigned int           complejo7 = 3u   + 10ui;
    _Complex unsigned long int      complejo8 = 4uL  + 9uLi;
    _Complex unsigned long long int complejo9 = 5uLL + 8uLLi;
#endif // __GNUC__

    puts("Los tamaños de los complejos deben ser el "
         "doble del tipo de dato que almacenan\n");

    printf("Tamaño de _Complex float:       %zu\n", sizeof(complejo10));
    printf("Tamaño de _Complex double:      %zu\n", sizeof(complejo11));
    printf("Tamaño de _Complex long double: %zu\n", sizeof(complejo12));
#ifdef __GNUC__
    printf("Tamaño de _Complex char:      %zu\n", sizeof(complejo0));
    printf("Tamaño de _Complex short:     %zu\n", sizeof(complejo1));
    printf("Tamaño de _Complex int:       %zu\n", sizeof(complejo2));
    printf("Tamaño de _Complex long:      %zu\n", sizeof(complejo3));
    printf("Tamaño de _Complex long long: %zu\n", sizeof(complejo4));
    putchar('\n');
    printf("Tamaño de _Complex unsigned char:      %zu\n", sizeof(complejo5));
    printf("Tamaño de _Complex unsigned short:     %zu\n", sizeof(complejo6));
    printf("Tamaño de _Complex unsigned:           %zu\n", sizeof(complejo7));
    printf("Tamaño de _Complex unsigned long:      %zu\n", sizeof(complejo8));
    printf("Tamaño de _Complex unsigned long long: %zu\n", sizeof(complejo9));
#endif // __GNUC__
    putchar('\n');
    getchar();

#endif // __STDC_NO_COMPLEX__

    return EXIT_SUCCESS;
}

/** Referencias:
 *      1. Peter Prinz Y Tony Crawford. (2016). C in a Nutshell. Gravenstein Highway North, Sebaspool CA 95472: O'Really. pp.24
 */
