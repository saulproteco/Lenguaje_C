/*===================*
 * Respuesta Tarea 1 *
 *===================*/

// ##### Bibliotecas #####

#include <stdio.h>    // fputs, printf, puts, fgets, sscanf
#include <stdlib.h>   // atoi, exit, EXIT_SUCCESS, EXIT_FAILURE, rand, system
#include <math.h>     // ceil, floor, log, fabs
#include <stdbool.h>  // bool
#include <time.h>     // time

#ifdef _WIN32       // Si estamos en windows
#   define LIMPIAR_PANTALLA "cls"
#else
#   define LIMPIAR_PANTALLA "clear"
#endif

// ##### Prototipos de función #####
static void jugar(int maximo);
static void imprimir_estado(int , int , int, int , int );
static void imprimir_instrucciones(void);
static int leer_numero(int maximo);

// ##### Funciones #####

/*
 * main : int, char * [] -> int
 * Recibe argumentos de la línea de comandos, se espera recibir
 * 0 o 1 argumento, en caso de recibirlo se interpretará como el valor
 * límite para el juego.
 */
int main(int argc, char * restrict argv[])
{
    int maximo = 100;

    if ( argc == 2 ) /* Recibimos un argumento */ {

        if ( (maximo = atoi(argv[1])) <= 1 ) {
            fputs("En maximo debe ser al emnos 2", stderr);
            exit(EXIT_FAILURE);
        }

    } else if ( argc >= 2 ) {
        imprimir_instrucciones();
    }

    jugar(maximo);

    return EXIT_SUCCESS;
}

/*
 * jugar : int -> void
 *
 * Recibe el valor máximo que pueden tomar los números secretos
 * y con base en ello lleva a cabo el juego.
 */
static
void jugar(int maximo)
{
    int respuesta = rand() % maximo + 1; // 1 - maximo
    int eleccion_usuario = -1;

    int vidas_max = ceil(log(maximo) / log(2)) - 1;
    int vidas_actuales = vidas_max;

    enum { JUGANDO, GANADO, PERDIDO } estado = JUGANDO;

    srand(time(NULL));

    while ( estado != GANADO ) {
        imprimir_estado(maximo, eleccion_usuario, respuesta,
                        vidas_max, vidas_actuales);

        if ( estado == PERDIDO )
            break;

        eleccion_usuario = leer_numero(maximo);

        vidas_actuales--;

        if ( eleccion_usuario == respuesta )
            estado = GANADO;
        else if ( vidas_actuales <= 0 )
            estado = PERDIDO;
    }

    switch ( estado ) {
        case GANADO:
            printf("¡¡Felicidades!!, ¡Has ganado el juego!\n");
            break;

        case PERDIDO:
            printf("Lo sentimos :(, el valor era: %d\n", respuesta);
            break;

        default:
            fprintf(stderr, "Estado desconocido\n");
            break;
    }
}

/*
 * imprimir_estado -> int, int, int, int, int -> void
 * Recibe las variables del juego, se basa en ellas para imprimir
 * representaciones visuales que sirvan de ayuda.
 */
static
void imprimir_estado(
        int max,
        int eleccion, int res,      // Lo que ingreso vs la respuesta
        int vidas_max, int vidas    // El máximo y las actuales
) {

    // Cantidad de partes del monigote
    int partes = floor(8 * (1 - ((double)vidas / vidas_max)));

    if ( system(LIMPIAR_PANTALLA) == -1 )
        puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    puts("================================================================================");

    printf("| %-3.*s %22s Adivine el número secreto %23s |\n",
            partes > 1 ? 2 : 0, " |",
            "", "");
    printf("| %-3.*s %21s Es un número entre 1 y %-27d |\n",
            partes > 2 ? 2 : 0, " o",
            "", max);
    printf("| %-3.*s %26s Te quedan %2d vidas %26s |\n",
            partes > 3 ? partes - 3 : 0, "/|\\",
            "", vidas, "");

    if ( vidas < vidas_max ) {
        printf("| %-3.*s %21s El número es %15.*s %21s |\n",
                partes > 5 ? partes - 5 : 0, "/ \\",
                "",
                (int)(ceil( 15 * (fabs(eleccion - res) / max) )),
                eleccion > res ? ">>>>>>>>>>>>>>>" : "<<<<<<<<<<<<<<<",
                "");

        printf("| %24s            %15s %24s |\n",
                "", eleccion > res ? "(mayor)" : "(menor)", "");
    }

    puts("================================================================================");
}

/*
 * leer_numero : int -> int
 *
 * Lee de la entrada estandar hasta recibir un número
 * válido para el juego en cuestión.
 */
static int leer_numero(int maximo)
{
    char linea[100];
    int valor;
    bool se_pudo_leer_algo;

    do {

        printf("Ingrese el número: ");

        se_pudo_leer_algo = (bool) fgets(linea, 100, stdin);

        if ( se_pudo_leer_algo )
            sscanf(linea, "%d", &valor);

    } while( valor <= 1 || valor >= maximo );

    return valor;
}

/*
 * imprimir_instrucciones : void -> void
 *
 * Da indicios si se reciben argumentos erroneos.
 */
_Noreturn static
void imprimir_instrucciones(void)
{
    puts("                -*-*Numero Magico*-*-              \n"
         "El programa solo debe recibir 0 o 1 argumento(s),  \n"
         "en caso de recibir alguno, este debe ser numérico  \n"
         "y al menos mayor que 1. Dicho número será usado en \n"
         "como valor límite en la elección aleatoria de un   \n"
         "valor \"secreto\" que el usuario deberá adivinar   \n"
         "para ganar\n");

    exit(EXIT_SUCCESS);
}
