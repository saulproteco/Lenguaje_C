/*=================================*
 * Reserva dinAmica de estructuras *
 *=================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ESTRUCTURAS 5

int main(void)
{
    /* Las funciones para reservar memoria del montIculo solamente  *
     * reservan memoria de manera genErica, por lo que no hay gran  *
     * diferencia entre reservar una estructura o reservar otra     *
     * variable cualquiera.                                         *
     * Estas operaciones van casi siempre acompaniadas del operador *
     * sizeof que indica el espacio en memoria ocupado por un tipo  *
     * de dato o variable, evitando asI entrar en conflicto con el  *
     * espacio ocupado por una estructura sobre una plataforma en   *
     * concreto.                                                    */

    // Ejemplos
    struct unaEstructura {
        int a;
        float b;
    };

    // Se reserva solo una variable
    struct unaEstructura * apt_estructura =
        malloc(sizeof(struct unaEstructura)); // El casteo se considera
                                             // redundante en C pero si
                                             // este cOdigo se quisiera
                                             // portar a C++ serIa
                                             // necesario.

    apt_estructura->a = 10;
    apt_estructura->b = 5.5;

    printf("Los datos son: %d %f\n",
            apt_estructura->a, apt_estructura->b);

    free(apt_estructura); // Se libera la memoria
    putchar('\n');

    // Se reservan multiples estructura, el apuntador anterior
    // se puede reutilizar.
    apt_estructura = malloc( NUM_ESTRUCTURAS * sizeof(struct unaEstructura) );

    for (int i = 0; i < NUM_ESTRUCTURAS; i++) {
        apt_estructura[i].a = 1;
        apt_estructura[i].b = 1.1 * i;

        printf("Los datos de %d son: %d %f\n",
                i + 1, apt_estructura[i].a, apt_estructura[i].b);
    }

    free(apt_estructura); // Se libera la memoria
    putchar('\n');

    apt_estructura = calloc(NUM_ESTRUCTURAS, sizeof(struct unaEstructura));

    for (int i = 0; i < NUM_ESTRUCTURAS; i++) {
        printf("Los datos %d incializados a 0 son: %d %f\n",
                i + 1, apt_estructura[i].a, apt_estructura[i].b);
    }

    free(apt_estructura);
    putchar('\n');
    apt_estructura = NULL; // La referencia se dejarA de usar

    getchar();

    /* C99 permite que el Ultimo miembro de las estructuras sea un  *
     * arreglo de tamanio no especificado. Este recibe el nombre de *
     * arreglo flexible y estA pensado justamente para ser usado    *
     * junto con memoria dinAmica para contener una cantidad        *
     * variable de dAtos.                                           *
     *                                                              *
     * El operador sizeof se comporta ligeramente diferente en      *
     * estructuras que contengan arreglos flexibles dado que en     *
     * lugar de indicarnos el espacio que ocupa en memoria la       *
     * estructura nos dirA el desplazamiento entre el primer dato   *
     * de la estructura y el arreglo flexible de manera que podamos *
     * usar esa informaciOn para reservar memoria al Ultimo elemento*/

    typedef struct {
        int largo;
        char bytes[];   // Arreglo flexible
    } Cadena; // Se simularA una cadena que no requiere carActer nulo al final

    Cadena * cad1 = malloc(sizeof(Cadena) + sizeof("Hola\n"));
    cad1->largo = sizeof("Hola\n");
    memcpy(cad1->bytes, "Hola\n", cad1->largo);

    Cadena * cad2 = malloc(sizeof(Cadena) + sizeof("ejemplo de arreglo flexible\n"));
    cad2->largo = sizeof("ejemplo de arreglo flexible\n");
    memcpy(cad2->bytes, "ejemplo de arreglo flexible\n", cad2->largo);

    puts("Las cadenas son:");
    fwrite(cad1->bytes, sizeof(char), cad1->largo, stdout);
    fwrite(cad2->bytes, sizeof(char), cad2->largo, stdout);

    puts("Alterando la cadena uno");
    cad1->bytes[3] = 'o';
    puts("Alterando la cadena dos");
    cad2->bytes[1] = 's';

    puts("Las cadenas son:");
    fwrite(cad1->bytes, sizeof(char), cad1->largo, stdout);
    fwrite(cad2->bytes, sizeof(char), cad2->largo, stdout);

    // Liberando las cadenas
    free(cad1); cad1 = NULL;
    free(cad2); cad2 = NULL;

    getchar();

    /* Por Ultimo hace falta mencionar que tambiEn se pueden usar    *
     * arreglos de longitud dinAmica (caracterIstica de c99) junto   *
     * con estructuras, para crear una sintaxis de manejo mAs        *
     * sencilla y obtener mayor velocidad en ejecuciOn.              *
     *                                                               *
     * Como siempre, es necesario recordar que los arreglos de       *
     * longitud dinAmica toman su espacio de la pila del programa    *
     * la cual tiene un espacio mucho mAs limitado que el montIculo. *
     * Si llegas a sobrepasar el lImite de memoria disponible en la  *
     * pila es probable que tu programa muera al instante.           */

    srand(time(NULL));

    int tamanio = rand() % 100 + 10;
    struct unaEstructura arreglo_dinamico[tamanio];

    printf("El tamanio aleatorio es: %d\n", tamanio);

    for (int i = 0; i < tamanio; i++) {
        arreglo_dinamico[i].a = 1;
        arreglo_dinamico[i].b = 1.1 * i;

        printf("Los datos de %d son: %d %f\n",
                i + 1, arreglo_dinamico[i].a, arreglo_dinamico[i].b);
    }

    /* Como ya sabemos, la memoria dinAmica de la pila se libera sola *
     * cuando termina la funciOn en que se hizo uso de la misma.      */

    return EXIT_SUCCESS;
}
