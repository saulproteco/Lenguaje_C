/* ======== *
 * Arreglos *
 * ======== */

/**
 * Autor: Martínez Ortíz Saúl Axel
 * Dificultad: Básico.
 * Requisitos: Funciones, macros, ciclos.
 * Estilo de código: Microsoft.
 */

#include <stdio.h>  // puts, printf
#include <stdlib.h> // EXIT_SUCCESS

// El largo del arreglo es su peso total en bytes dividido entre el peso
// de uno de sus elementos
#define TAMANIO_ARREGLO(arreglo)    ( sizeof(arreglo) / sizeof(arreglo[0]) )

// Ciclo que recorre automaticamente el arreglo pero sin definir operaciones
#define RECORRIDO_ARREGLO(arreglo)                                          \
        for (int i = 0; i < TAMANIO_ARREGLO(arreglo); i++)


// Prototipos de función
void RecibeArreglo(short arreglo[]);
void ImprimeMatriz(int matriz[3][3]);

int main(void)
{
    // Indicamos tamanio e inicializamos los elementos
    // El resultado es un arreglo de tamanio 5 con justo 5 elementos inicializado manualmente
    int arreglo1[5] = { 1, 2, 3, 4, 5 };

    RECORRIDO_ARREGLO(arreglo1)
        printf("El elemento %d es: %d\n", i, arreglo1[i]);

    puts("\n\n");

    // No indicamos el tamaño, el compilador cuenta los elementos y asigna el tamanio justo
    // El resultado es un arreglo con justo 8 letras sin un caracter de terminaciOn de cadena
    char arreglo2[] = { 'Q', 'u', 'e', ' ', 'b', 'i', 'e', 'n', '!' };
    printf("Tamanio del arreglo de caracteres: %zu\n", TAMANIO_ARREGLO(arreglo2));

    printf("El arreglo de caracteres impreso mediante un ciclo: ");
    RECORRIDO_ARREGLO(arreglo2) putchar(arreglo2[i]);

    // La siguiente impresión puede contener caracteres basura
    printf("\nEl arreglo impreso mediante el especificador de conversión de cadenas: %s\n", arreglo2);

    // Indicamos tamanio pero no inicializamos todos los elementos
    // El resultado es que el resto de los elementos son automaticamente inicializados a 0.
    float arreglo3[10] = { 1.0, 1.21, 1.44, 1.69, 1.94, 2.25 };

    printf("Los elementos del arreglo sin inicializar al completo son:\n");
    RECORRIDO_ARREGLO(arreglo3)
        printf("%.2f ", arreglo3[i]);

    // Si no indicamos el tamanio ni inicializamos elementos del arreglo
    // ocurre un error de compilación, para observaro descomente la siguiente línea.
    //_Bool arreglo4[];

    // C99: Los arreglos se pueden inicializar en desorden usando la clave
    // de acceso del elemento que queremos afectar
    _Complex arreglo5[10] = { [2] = 17.0 + 25.0i, [8] = 1 + 1e-2i, [3] = -12 - 4i, 4.5 + 777i, 12e3, 9.999e3i};

    puts("\n\nImprimiendo el arreglo de complejos:");
    RECORRIDO_ARREGLO(arreglo5)
    {
        printf("El complejo %d del arreglo es: ", i);

        printf("%8.2f %8.2f * i\n", arreglo5[i]);
    }

    // C99: Arreglos anonimos: Se pueden crear arreglos sobre la marcha y pasarlos a una
    // expresión/función que reciba alguno de los mismo. Más allá de la línea en que son
    // usados no se les podrá volver a referenciar.
    RecibeArreglo( (short[]) { 0b10, 0b100, 0b1000, 0b10000 } );

    // C99: Arreglos de longitud variable. Son arreglos cuyo espacio no es reservado en tiempo
    // de compilaciOn sino en tiempo de ejecuciOn. Se caracterizan por recibir una variable
    // dentro de los corchetes del tamanio.

    printf("Ingrese el tamanio del arreglo: ");
    int tam;

    if ( !scanf("%d", &tam) )
        exit(EXIT_FAILURE);

    long arregloLongitudVariable[tam];

    puts("El arreglo reservado dinamicamente es:");
    RECORRIDO_ARREGLO(arregloLongitudVariable)
        printf("%ld", arregloLongitudVariable[i]);

    // Al tratar con arreglos multidimensionales también hay varias formas de inicialización

    // Cuenta cuantas filas, equivalente a matriz1[3][3]
    int matriz1[][3] =
    {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    int matriz2[][3] =
    {
        9, 8, 7, 6, 5, 4, 3, 2, 1
    };

    int matriz3[][3] =
    {
        { [0] = 1 },
        { [1] = 2 },
        { [2] = 3 }
    };

    int matriz4[][3] =
    {
        [2] = { 77, 88, 99 },
        [0] = { 11, 22, 33 },
        [1] = { 44, 55, 66 }
    };

    puts("\n\nImprimiendo matrices:\n\n");

    puts("matriz1:");
    ImprimeMatriz(matriz1);

    puts("matriz2:");
    ImprimeMatriz(matriz2);

    puts("matriz3:");
    ImprimeMatriz(matriz3);

    puts("matriz4:");
    ImprimeMatriz(matriz4);

    return EXIT_SUCCESS;
}

/* Nota: El compilador ignora el 4 dentro de los corchetes
por lo que tecnicamente la funciOn puede recibir arreglos de diferente
longitud.
*/
void RecibeArreglo(short arreglo[4])
{
    printf("He recibido un arreglo, su direcciOn es: %p\n", arreglo);

    puts("Los elementos del arreglo son:");

    // No hay garantia de que el arreglo recibido tenga exactamente 4
    printf("%2hd %2hd %2hd %2hd\n", arreglo[0], arreglo[1], arreglo[2], arreglo[3]);

}

// Igual que en el caso anterior, el primer 3 es ignorado por lo que el argumento
// en realidad es visto como "int matriz[][3]" por el compilador.
// En aplicaciones reales se debe comprobar que no se reciban arreglos con la
// longitud equivocada.
void ImprimeMatriz(int matriz[3][3])
{
    puts("+-----+-----+-----+");
    for (int i = 0; i < 3; i++)
    {
        printf("| %3d | %3d | %3d |\n",
               matriz[i][0], matriz[i][1], matriz[i][2]);
        puts("+-----+-----+-----+");
    }
}
