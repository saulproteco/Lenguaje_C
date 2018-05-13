/*===========================================*
 * Demostración de las estructuras y uniones *
 *===========================================*/

/**
 * Autor: Martínez Ortiz Saúl Axel
 * Dificultad: Intermedio.
 * Requisitos: Funciones, funcionamiento de la RAM.
 * Estilo de código: GNU.
 */

#include <stdio.h>      // printf
#include <stdlib.h>     // EXIT_SUCCESS
#include <stdint.h>
#include <stdbool.h>    // bool, false, true

#define BINARIO(estr) estructuraEnBinario((uint8_t *)&(estr), sizeof(estr))
static void estructuraEnBinario (const uint8_t * estructura, int tamanio);

int
main (void)
{
    /* Una estructura debe ocupar en memoria por lo menos la cantidad   *
     * de espacio resultante de sumar lo que ocupan sus elementos. Esto *
     * significa, que perfectamente pueden ocupar más espacio pero      *
     * nunca menos                                                      *
     * Aunque el criterio para ordenar los datos miembro puede depender *
     * del sistema en que se trabaje, la mayoría de las veces se sigue  *
     * un criterio para eficientar el tiempo a costa del espacio. El    *
     * tamaño de las estructuras se establece en múltiplos del tamaño   *
     * de los registros del procesador, de tal forma que no haya que    *
     * hacer operaciones para cargar/operar datos solo en una fracción  *
     * de registro, para lo cual se tiene que hacer operaciones de      *
     * restricción que hacen un poco más lento el proceso.              */

    // Tomemos como ejemplo la siguiente estructura:
    struct miEstructura
    {
        char dato1;      // 1 byte
        short dato2;     // 2 bytes
    };

    // Las variables correspondientes a este tipo de dato deben ocupar
    // al menos tres bytes aunque probablemente ocupen 4 bytes dado el
    // relleno generado para eficientar el uso de la estructura, por lo
    // que las variables probablemente estarán constituidas tal que así:
    //  +dato1-+ +Relleno +------dato2----+
    //  |      | |      | |               |
    //  v      v v      v v               v
    //  00000000 00000000 00000000 00000000
    //
    //  La razOn de que el relleno ocupe el segundo byte, es que
    //  generalmente los datos miembros se asocian por tipos de manera
    //  que cada tipo ocupe una cantidad potencia de 2.

    printf ("El tamaño de miEstructura es %zu\n", sizeof(struct miEstructura));

    // Vamos a comprobar si lo que dijimos es cierto imprimiendo los bits
    // de una estructura. Dato1 y dato2 se inicializan a -1 puesto que
    // la representación de dicho número son únicamente unos
    struct miEstructura var = { 0 }; // Se inicializa todo a 0
    var.dato1 = -1;
    var.dato2 = -1;

    puts ("La representación binaria de miEstructura es:");
    BINARIO (var);

    getchar ();

    /* Agrupar los datos miembro de las estructuras según su tipo de    *
     * dato promueve la asociación de las variables por grupos lo que   *
     * generalmente resultará en una menor cantidad de espacio          *
     * desperdiciado. Tomemos como ejemplo las siguientes estructuras   *
     * que contienen las mismas variables pero en diferente orden:      */

    struct sinOrden
    {
        short a;
        char b;
        short c;
        char d;
        short e;
        char f;
        short g;
        char h;
    } var_sinorden = { -1, 0, -1, 0, -1, 0, -1, 0 };

    struct enOrden
    {
        short a;
        short c;
        short e;
        short g;
        char b;
        char d;
        char f;
        char h;
    } var_enorden = { -1, -1, -1, -1, 0, 0, 0, 0 };

    printf ("El tamaño de la estructura en desorden: %zu\n",
            sizeof(struct sinOrden));
    printf ("El tamaño de la estructura en orden: %zu\n",
            sizeof(struct enOrden));

    getchar ();

    // Vamos a observar el contenido de las variables.
    // Todos los short están inicializados a -1 (solo unos) y todos
    // los char a 0 (solo ceros en la representación binaria).

    puts ("El contenido de la estructura en desorden:");
    BINARIO (var_sinorden);

    puts ("El contenido de la estructura en orden:");
    BINARIO (var_enorden);

    getchar ();

    //  Salida de ejemplo:
    // Estructura en desorden:
    // +----shorts-----+ +-char-+ Relleno que se desperdicia por cada
    // |               | |      | |      |  pareja de short y char.
    // v               v v      v v      v
    // 11111111 11111111 00000000 00000000
    // 11111111 11111111 00000000 00000000
    // 11111111 11111111 00000000 00000000
    // 11111111 11111111 00000000 00000000
    //
    // Estructura en orden:
    // 11111111 11111111 11111111 11111111 <-+ Shorts de dos bytes en
    // 11111111 11111111 11111111 11111111 <-+ dos bytes
    // 00000000 00000000 00000000 00000000 <-- Chars de un byte en un byte

    /* El comportamiento por defecto del relleno es hacer que toda      *
     * variable se 'empaquete' en un cuarteto de bytes especifico.      *
     * Cuando un tipo de dato no cabe en el espacio restante del        *
     * cuarteto inmediatamente salta la siguiente generándose un        *
     * relleno.                                                         *
     *                                                                  *
     * Existen formas de cambiar el comportamiento por defecto del      *
     * empaquetado de datos en las estructuras, una de ellas es la      *
     * famosa directiva pack de los compiladores de microsoft, a la     *
     * cual varios compiladores han decidido darle compatibilidad.      *
     * Esta directiva cambia el tamaño mínimo de empaquetado con lo     *
     * cual se puede conseguir un menor desperdicio sin necesidad de    *
     * ordenar las variables (aunque puede haber perjuicios en tiempo   *
     * de ejecución) o se puede (remotamente, aunque no lo intentes a   *
     * menos que sepas lo que haces) obtener menor desempeño a cambio   *
     * de un mayor desperdicio de espacio.                              */

    // Haremos una demostración de la directiva pack con el mismo ejemplo
    // de hace un momento

    // Si el tamaño mínimo de empaquetado es 1 byte habrá menos relleno
#pragma pack(1)
    struct SinOrden2
    {
        short a;
        char b;
        short c;
        char d;
        short e;
        char f;
        short g;
        char h;
    } var_sinorden2 = { -1, 0, -1, 0, -1, 0, -1, 0 };

    struct EnOrden2
    {
        short a;
        short c;
        short e;
        short g;
        char b;
        char d;
        char f;
        char h;
    } var_enorden2 = { -1, -1, -1, -1, 0, 0, 0, 0 };

    printf ("El tamaño de la estructura en desorden: %zu\n",
            sizeof(struct SinOrden2));
    printf ("El tamaño de la estructura en orden: %zu\n",
            sizeof(struct EnOrden2));

    puts ("El contenido de la estructura en desorden 2:");
    BINARIO (var_sinorden2);

    puts ("El contenido de la estructura en orden 2:");
    BINARIO (var_enorden2);
    getchar ();

#pragma pack(4) // Se regresa al valor por defecto
    // Salida de ejemplo:
    // Estructura en desorden: Alterna entre un short y un byte
    //                         sin dejar espacios
    // 11111111 11111111 00000000 11111111
    // 11111111 00000000 11111111 11111111
    // 00000000 11111111 11111111 00000000
    //
    // Estructura en orden:    Se mantiene igual
    // 11111111 11111111 11111111 11111111
    // 11111111 11111111 11111111 11111111
    // 00000000 00000000 00000000 00000000

    /* Las estructuras proveen una característica especial para manejar *
     * el almacenamiento de sus datos miembro: Los cambos de bits.      *
     * Un campo de bit es una variable entera cuyo espacio se ha        *
     * limitado a un número específico de bits.                         *
     *                                                                  *
     * La sintaxis para declarar un miembro como campo de bits es:      *
     *                                                                  *
     *  <tipo_dato> <identificador> : <espacio>;                        *
     *                                                                  *
     * Los campos de bits son útiles cuando los campos de una           *
     * estructura solo pueden contener valores dentro de un rango       *
     * específico por lo que es un desperdicio hacer la reserva de      *
     * todos los bits que se tienen normalmente.                        *
     * Tómese por ejemplo una variable para representar el mes de un    *
     * año, cuyo rango es únicamente de 1 a 12 el cual puede            *
     * representarse en 4 bits.                                         */

    struct noImportaElEspacio
    {
        _Bool a;        // 1 byte
        char d;         // 1 byte
        short c;        // 2 bytes
        long b;         // 4 bytes
        long long e;    // 8 bytes
    }; // La estructura completa ocupa al menos 16 bytes aunque
        // lo mas seguro es que ocupe más

    printf("Tamaño de la estructura sin campos de bits: %zu\n",
            sizeof(struct noImportaElEspacio));

    struct cadaBitCuenta
    {
        _Bool a     : 1;        // 1 bit
        char  d     : 3;        // 3 bits
        short c     : 5;        // 5 bits
        long  b     : 8;        // 8 bits
        long long e : 16;       // 16 bits
    };

    printf ("Tamaño de la estructura con campos de bits: %zu\n",
            sizeof(struct cadaBitCuenta));

    struct noImportaElEspacio var_noimporta = { -1, -1, -1, -1, -1 };
    struct cadaBitCuenta var_cadabit = { -1, -1, -1, -1, -1 };

    puts ("La representación interna de var_noimporta es:");
    BINARIO (var_noimporta);

    puts ("La representación interna de var_cadabit es:");
    BINARIO (var_cadabit);

    /* Como se puede notar, la estructura 'cadaBitCuenta' formada solo *
     * por campos de bits en total ocupa 32 bits, sin embargo es muy   *
     * posible que haya relleno entre los campos de bits dando como    *
     * resultado una estructura de mayor tamaño.                       *
     * Siempre que manejes campos de bits, trata de que sean del mismo *
     * tipo de entero y que estén agrupados de forma apartada de los   *
     * miembros normales de la estructura lo cual reducirá el espacio  *
     * necesario.                                                      *
     * De no atender esta recomendación, la estructura podría ocupar   *
     * el mismo espacio que sin hacer uso de campos de bits pero con   *
     * menor eficiencia, dado que nuevamente, el procesador tiene que  *
     * hacer operaciones extras para separar bits específicos de una *
     * unidad.                                                         */

    struct camposAcomodados
    {
        char nombre[32];    // 32 bytes

        unsigned dia_nacimiento    : 5;  // 0 - 31    <-----+
        unsigned mes_nacimiento    : 4;  // 0 - 15          |
        unsigned anio_nacimiento   : 12; // 0 - 4095        +--> 4 bytes
        unsigned hora_nacimiento   : 5;  // 0 - 31          |
        unsigned minuto_nacimiento : 6;  // 0 - 63    <-----+

        float sueldo;   // 4 bytes
    }; // Al menos 40 bytes en total si no hay desperdicio

    printf ("Tamaño de 'camposAcomodados': %zu\n",
            sizeof(struct camposAcomodados));

    /* Por último, una aclaración quizás obvia pero importante: hay que *
     * estar al pendiente de que los valores de los campos de bits no   *
     * se desborden (como en cualquier otra variable valla), pues el    *
     * hecho de estar limitados en espacio hace más común el            *
     * desbordamiento, cosa que es raro observar con las variables      *
     * normales.                                                        *
     * Si un campo de bit es usado en operaciones, será casteado al     *
     * entero más inmediato que pueda contener su valor por lo que      *
     * hacerlo es valido aunque no es recomendado hacerlo en ciclos     *
     * dado que podría representar una merma significativa en el        *
     * desempeño del programa (si es un ciclo muy importante).          */
    return EXIT_SUCCESS;
}

static void
estructuraEnBinario (
                     const uint8_t * estructura, // Dirección de la estructura
                     int tamanio )               // Tamaño del dato recibido
{
    for (int byte = 0; byte < tamanio; byte++)
        {
            char octeto = *(char *)(estructura + byte);

            for (int bit = 0b10000000; bit > 0; bit >>= 1)
                putchar(octeto & bit ? '1' : '0');

            putchar(' ');

            if ( (byte + 1) % 4 == 0 )
                putchar('\n');
        }

    putchar('\n');
}
