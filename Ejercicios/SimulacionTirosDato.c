/*===================*
 * Respuesta Tarea 2 *
 *   Tiros de dado   *
 *===================*/

/* Este programa recibe argumentos para establecer el tamaño de pantalla en *
 * que se deberían de imprimir los datos. Para obtener el mejor resultado   *
 * posible, invoque al programa con las dimensiones reales de su terminal   *
 * haciendo lo siguiente:                                                   *
 *  <programa> -l $COLUMNS -a $LINES [otros argumentos]...                  *
 *                                                                          *
 * De esta forma el programa recibirá directamente los valores de las       *
 * variables de entorno que guardan las dimensiones de su terminal.         */

// Bibliotecas
#include <stdio.h>   // puts, putchar, getchar, printf
#include <stdlib.h>  // atoll
#include <string.h>  // memset
#include <ctype.h>   // isdigit
#include <time.h>    // Para obtener la semilla de los números pseudo-aleatorios
#include <unistd.h>  // Para parsear las opciones pasadas por consola.
                     // esta biblioteca es especifica de linux.
#include <stdint.h>  // uint64_t
#include <stdbool.h> // bool, true, false

/* Lel c(= */
static const char * const barra =
    "=================================================="
    "=================================================="
    "=================================================="
    "=================================================="
    "=================================================="
    "=================================================="
    "=================================================="
    "=================================================="
    "=================================================="
    "=================================================="
    "=================================================="
    "=================================================="
    "=================================================="
    "=================================================="
    "=================================================="
    "=================================================="
    "=================================================="
    "=================================================="
    "=================================================="
    "=================================================="
    "==================================================";

struct opt;         // Declaración anticipada de la estructura, tal como
                    // el prototipo de una función, esta declaración
                    // indica que en el futuro nos encontraremos la
                    // especificación de la estructura.

// Prototipos de función
bool es_valor_entero(const char * const cadena);
void crear_grafica(struct opt opciones);
void imprimir_instrucciones(const char * const nombre_programa);
void regresar_cursor(void);

// La declaración verdadera de la estructura
struct opt {
    bool     esperar_cada_pantallazo : 1;  // Solo un bit (0 o 1)
    uint64_t alto_pantalla           : 10; // Solo 9 bits (0 - 1023)
    uint64_t largo_pantalla          : 10; // Solo 9 bits (0 - 1023)
    uint64_t numero_dados            : 8;  // Solo 4 bits (0 - 255)
    uint64_t cantidad_tiros          : 35; // Solo 9 bits (0 - ...)
};

// Función principal, principalmente menaje los argumentos del programa
int main(int argc, char * argv[]) {
    char opcion;
    // Valores por defecto
    struct opt opciones = {
        .alto_pantalla = 23,
        .largo_pantalla = 80,
        .numero_dados = 1,
        .cantidad_tiros = 1000,
        .esperar_cada_pantallazo = true
    };

    printf("\e[?25l");          // Se borra el cursor

    atexit(regresar_cursor);    // Se establece una función que devuelva el
                                // cursor a su forma original cuando el
                                // programa termine.

    // Se manejan los argumentos por medio de "getopt"
    while ( (opcion = getopt(argc, argv, "a:l:n:t:p:")) != -1 ) {
        switch (opcion) {
            case 'a':
            case 'l':
            case 'n':
            case 't':
            case 'p':
                if ( !es_valor_entero(optarg) )
                    imprimir_instrucciones(argv[0]);

                uint64_t valor = atoll(optarg);

                if ( opcion == 'a' && valor <= 1024 )
                    opciones.alto_pantalla = (valor - 1);
                else if ( opcion == 'l' && valor <= 1024 )
                    opciones.largo_pantalla = (valor - 1);
                else if ( opcion == 'n' && valor <= 255 )
                    opciones.numero_dados = (valor - 1);
                else if ( opcion == 't' )
                    opciones.cantidad_tiros = (valor - 1);
                else if ( opcion == 'p' )
                    opciones.esperar_cada_pantallazo = valor;

                break;

            default:
                imprimir_instrucciones(argv[0]);
                break;
        }
    }

    // Una vez establecidas las opciones, se llama a la función graficadora.
    crear_grafica(opciones);
}

// La función que se encarga de hacer los resultados y crear su
// representación grafica por medio de asteriscos.
void crear_grafica(struct opt opciones) {
    srand(time(NULL)); // Se establece una semilla para los números
                       // pseudo-aleatorios.
    int posibilidades = 5 * (opciones.numero_dados + 1) + 1;
    int cantidad[posibilidades]; // Arreglo de tamaño dinámico (C99).
                                 // como estos arreglos no son estáticos, no
                                 // hay garantia de que la inicialización
                                 // funcione correctamente en todos los
                                 // compiladores, hay que hacer la inicialización
                                 // explicitamente.
    memset(cantidad, 0, sizeof(int) * posibilidades);
    int maximo = -1;

    // Haciendo los calculos
    printf("Calculando los valores:\n");

    for (uint64_t i = 0; i < opciones.cantidad_tiros + 1; i++) {
        int suma = 0;

        for (int j = 0; j < opciones.numero_dados + 1; j++)
            suma += rand() % 6 + 1;

        printf("%3d%%\r", (int)(100 * i / opciones.cantidad_tiros));
        cantidad[suma - opciones.numero_dados - 1]++;

        if ( cantidad[suma - opciones.numero_dados - 1] > maximo )
            maximo = cantidad[suma - opciones.numero_dados - 1];
    }

    // Imprimiendo
    printf("     0%%");
    for (int j = 1; j <= opciones.largo_pantalla - 8; j++) {
        if ( (j + 0) % ((opciones.largo_pantalla - 7) / 5) == 0 ) {
            printf("%3d%%", (int)((double)100 * j / (opciones.largo_pantalla - 8)));
            j += 4;
        } else {
            putchar(' ');
        }
    }

    printf("100%%\n");
    printf("%.*s\n", opciones.largo_pantalla, barra);

    for (int i = 0; i < posibilidades; i++) {

        int asteriscos = (double) (opciones.largo_pantalla - 7) * cantidad[i] / maximo;

        printf("       ");
        for (int j = 1; j <= opciones.largo_pantalla - 8; j++) {
            if ( j % ((opciones.largo_pantalla - 7) / 5) == 0 )
                putchar('|');
            else
                putchar(' ');
        }
        putchar('|');

        putchar('\r');

        printf("%4d | ", i + opciones.numero_dados + 1);

        for (int j = 0; j < asteriscos; j++)
            putchar('*');

        putchar('\n');

        if ( opciones.esperar_cada_pantallazo )
            if ( (i + 1) % opciones.alto_pantalla == 0 )
                getchar();
    }

    printf("%.*s\n", opciones.largo_pantalla, barra);
}

void imprimir_instrucciones(const char * const nombre_programa) {
    puts("Llame al programa de la siguiente manera");
    printf("\t%s [OPCIONES]...\n", nombre_programa);

    puts("\nLas opciones son las siguientes (todas reciben un argumento numérico):");
    puts("\ta  -  alto de la pantalla (1 - 256)");
    puts("\tl  -  largo de la pantalla (1 - 256)");
    puts("\tn  -  número de dados (1 - 16)");
    puts("\tt  -  cantidad de tiros (1 - 2048)");
    puts("\tp  -  imprimir la gráfica poco a poco (cualquier número\n"
             "\t\tque ser reciba será intepretado como booleano)");

    exit(EXIT_FAILURE);

}
bool es_valor_entero(const char * const cadena) {
    for (int i = 0; cadena[i]; i++) {
        if ( !isdigit(cadena[i]) )
            return false;
    }

    return true;
}


void regresar_cursor(void) {
    printf("\e[?25h");
}
