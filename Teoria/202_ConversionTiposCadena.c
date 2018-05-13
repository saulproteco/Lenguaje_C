/*=======================*
 * Conversión de cadenas *
 *=======================*/

/**
 * Autor: Martínez Ortiz Saúl Axel
 * Dificultad: Intermedio.
 * Requisitos: Cadenas, especificadores de formato, apuntadores;
 * Estilo de código: Microsoft.
 */

#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS
#include <ctype.h>
#include <stdbool.h>

bool EsNumerica(const char * cadena);
bool EsSigno(int caracter);

int main(int argc, const char *argv[])
{
    /* Para convertir entre cadenas y tipos aritméticos se tiene que    *
     * hacer uso de funciones, la mayoría de ellas se podrán encontrar  *
     * en stdlib y también hay un par en stdio.                         */

    /* Para conversión simple de cadena a número se puede usar el grupo *
     * de funciones atoX, donde X es el prefijo correspondiente al tipo *
     * aritmético al que se quiere convertir:                           *
     *  > i -> int                                                      *
     *  > l -> long                                                     *
     *  > ll-> long long (C99)                                          *
     *  > f -> double                                                   *
     * Todas esas funciones reciben la cadena numérica y regresan el    *
     * valor aritmético correspondiente. La cadena de entrada se        *
     * procesa mientras haya caracteres numéricos y se ignora el resto. *
     * En caso de no encontrar un número válido la función regresa 0    *
     * y no hay forma de corroborar errores de conversión.              */

    // Ejemplo de uso de las funciones atoX
    puts("\nEjemplo afof");
    if ( argc > 1 )
    {
        while (argc > 0)
        {
            printf("El argumento como número es: %f\n", atof(*argv));

            argc--, argv++;
        }
    }

    /* Las funciones del tipo stdtoX reciben un apuntador a cadena y un *
     * doble apuntador a cadena respectivamente. Se puede conseguir un  *
     * resultado similar al de las funciones atoX si se usa NULL como   *
     * segundo argumento (quitando el soporte para algunos tipos). En   *
     * caso de proporcionar el segundo argumento este se establecerá    *
     * con el apuntador del carácter en que continúa la cadena tras la  *
     * conversión, lo cual permite procesar la cadena de manera         *
     * progresiva y también hacer revisión de errores.                  */

    // Ejemplo de uso de las funcioens strtoX
    puts("\nEjemplo strtof");
    char * posicion_nueva = NULL;

    printf("La parte numérica de 10.5hola es: %f\n",
            strtof("10.5hola", &posicion_nueva));

    printf("La parte restante es: %s\n", posicion_nueva);

    /* Si se conoce el formato de la cadena de entrada la función       *
     * sscanf proporciona una forma más flexible de interpretar valores *
     * dentro de una cadena (no límitado a tipos aritméticos). Para     *
     * ello se require saber sobre los especificadores de conversión de *
     * entrada, los cuales se explican en el capitulo de entrada/salida */

    puts("\nEjemplo de sscanf");
    double b = 0.0;
    int a    = 0;

    puts("\nEjemplo sscanf");
    sscanf("Cadena,10.73,caracteres,125",   // Cadena de entrada
            // Cadena de formato
            "%*[^,]"    // Se lee hasta la coma y se descarta
            ","         // Se lee la coma y se descarta
            "%lf"       // Se lee el double y se guarda en el primer argumento
            ","         // Se lee la coma y se descarta
            "%*[^,]"    // Se lee la cadena entre comas y se descarta
            ","         // Se lee la coma y se descarta
            "%d",       // Se lee el segundo número y se guarda en el segundo argumento
            &b, &a);    // Argumentos

    printf("Los valores son %f %d\n", b, a);

    /* C no cuenta con funciones directas para hacer hacer la conversión    *
     * inversa (valor a cadena), pero siempre se puede contar con la        *
     * indirecta forma de usar sprintf, con la grán flexibilidad del printf *
     * pero que manda su salida a una cadena en lugar de hacerlo a la       *
     * salida estandar.                                                     *
     * Nuevamente se recomienda echar un vistazo al capitulo de entrada y   *
     * salida para darse una mejor idea de como funcionan las cadenas de    *
     * formato de salida.                                                   */

    puts("\nEjemplo de sprintf");

    char buffer[100];

    sprintf(buffer,
            "%d + %d*i",    // Formato para un complejo
            105, -45);

    printf("La cadena resultante es: %s\n", buffer);

    return EXIT_SUCCESS;
}
