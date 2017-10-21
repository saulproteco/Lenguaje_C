/*=========================*
 *    Respuesta Tarea 3    *
 * Interprete de Brainfuck *
 *=========================*/

// ##### Bibliotecas y definiciones #####
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef _WIN32
#   include <windows.h>
#   include <conio.h>
#   define LIMPIAR "cls"
    void dormir(int milis) { Sleep(milis); }
#else
#   include <unistd.h>
#   include <termios.h>
#   define LIMPIAR "clear"
    void dormir(int milis) { usleep(1000 * milis); }
#endif

// ##### Prototipos de función #####
void interpretar(char * restrict programa);

void imprimir_estado(
        const char * programa,
        const char * memoria,
        uint16_t posicion,
        const char * entrada,
        const char * salida
);

void estado_memoria(const char * memoria, uint16_t posicion);
char * leer_archivo(const char * const nombre_archivo);
char obtener_caracter(void);

// ##### Variables de configuración #####
static bool modo_interactivo = true;

// ##### Función principal #####
int main(int argc, char * restrict * argv) {

    char * programa = NULL;

    if ( argc > 2 ) {
        printf("El programa solo recibe como argumento el programa en brainfuck a realizar o nungún argumento\n");
        exit(EXIT_FAILURE);
    } else if ( argc == 2 ) {
        modo_interactivo = false;
        programa = leer_archivo(argv[1]);
        interpretar(programa);
    } else {
        programa = calloc(sizeof(char), 10000);
        if ( !programa )
            exit(EXIT_FAILURE);
        interpretar(programa);
    }


    return EXIT_SUCCESS;
}

// ##### Otras funciones #####

void interpretar(char * restrict programa) {
    static int8_t memoria[1u << 16 - 1] = { 0 };
    static uint16_t apuntador = 0;

    static char salida[1u << 16 -1] = { 0 };
    static uint16_t longitud_salida = 0;

    static char entrada[1u << 16 - 1] = { 0 };
    static uint16_t longitud_entrada = 0;

    int apt_interactivo = 0;
    char * inicio = programa;
    int anidacion = 0;
    bool bloqueado;

    if ( modo_interactivo )
        inicio[apt_interactivo++] = obtener_caracter();

    system(LIMPIAR);
    imprimir_estado(
            modo_interactivo ? inicio + 80 * ((int) (programa - inicio) / 80)
            : programa, memoria, apuntador, entrada, salida);

    while ( *programa ) {

        switch ( *programa ) {
            // Aritmética
            case '+': ++memoria[apuntador]; break;
            case '-': --memoria[apuntador]; break;

                      // Recorrido sobre la memoria
            case '>': ++apuntador; break;
            case '<': --apuntador; break;

                      // Entrada/Salida
            case '.':
                      salida[longitud_salida++] = memoria[apuntador];
                      break;

            case ',':
                      memoria[apuntador] = getchar();
                      if ( memoria[apuntador] == -1 )
                          memoria[apuntador] = 0;

                      entrada[longitud_entrada++] = memoria[apuntador];
                      break;

                      // Ciclos
            case '[':
                      if ( memoria[apuntador] == 0 ) {
                          int parentesis = 1;

                          while ( parentesis > 0 ) {
                              programa++;

                              if ( *programa == '[' )
                                  parentesis++;
                              if ( *programa == ']' )
                                  parentesis--;
                          }
                      } else {
                          anidacion++;
                      }
                      break;

            case ']':
                      if ( memoria[apuntador] != 0 ) {
                          int parentesis = 1;

                          while ( parentesis > 0 ) {
                              programa--;

                              if ( *programa == ']' )
                                  parentesis++;

                              if ( *programa == '[' )
                                  parentesis--;
                          }
                      } else {
                          anidacion--;
                          if (anidacion == 0)
                              bloqueado = false;
                      }
        }

        ++programa;

        system(LIMPIAR);
        imprimir_estado(
                modo_interactivo ? inicio + 80 * ((int) (programa - inicio) / 80)
                : programa, memoria, apuntador, entrada, salida);

        if ( modo_interactivo && !bloqueado ) {
            inicio[apt_interactivo++] = obtener_caracter();

            // No continúa ejecutando hasta que se ecuentra el
            // corchete gemelo.
            if ( inicio[apt_interactivo - 1] == '[' ) {
                int paridad = 1;
                bloqueado = true;

                while ( paridad > 0 ) {
                    system(LIMPIAR);
                    imprimir_estado(
                            modo_interactivo ? inicio + 80 * ((int) (programa - inicio) / 80)
                            : programa, memoria, apuntador, entrada, salida);

                    inicio[apt_interactivo++] = obtener_caracter();

                    if ( inicio[apt_interactivo - 1] == '[' )
                        paridad++;
                    else if ( inicio[apt_interactivo - 1] == ']' )
                        paridad--;
                }
            }
        }

        dormir(40);
    }

    if ( !modo_interactivo )
        free(inicio);
}

void imprimir_cadena(const char * cadena) {
    int maximo = 160;
    while (*cadena && maximo >= 0)
        putchar(*cadena++), maximo--;
}

void imprimir_estado(
        const char * programa,
        const char * memoria,
        uint16_t posicion,
        const char * entrada,
        const char * salida
) {
    puts("\e[1;31mAvance del programa:\e[0m");
    imprimir_cadena(programa);

    puts("\n\n\e[1;31mEstado de las celdas de memoria:\e[0m");
    estado_memoria(memoria, posicion);

    puts("\n\n\e[1;31mSalida del programa:\e[0m");
    imprimir_cadena(salida);
    puts("\n\n\e[1;31mEntrada del programa:\e[0m");
    imprimir_cadena(entrada);
    fflush(stdout);
}

void estado_memoria(const char * memoria, uint16_t posicion) {
    const int largo = 10;
    int partida = posicion - posicion % largo;

    printf("    ");
    for (int i = 0; i < posicion % largo; i++)
        printf("%8s", "");

    puts("|");

    printf("    ");
    for (int i = 0; i < posicion % largo; i++)
        printf("%8s", "");
    puts("v");

    for (int i = 0; i < largo; i++)
        printf("[ %+4d ]", memoria[(partida + i) % (1 << 16)]);

    putchar('\n');
}

char * leer_archivo(const char * const nombre_archivo) {
    FILE * ap_archivo;
    int maximo = 1000;
    char * contenido = malloc(maximo);
    int pos = 0;
    int caracter;

    ap_archivo = fopen(nombre_archivo, "r");
    if ( !ap_archivo ) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    if ( !contenido ) {
        perror("Error al reservar memoria");
        exit(EXIT_FAILURE);
    }

    while ( (caracter = fgetc(ap_archivo)) != EOF ) {
        contenido[pos++] = caracter;

        if ( pos == maximo ) {
            maximo += 1000;
            contenido = realloc(contenido, maximo);

            if ( !contenido ) {
                free(contenido);
                perror("Error al reservar memoria");
                exit(EXIT_FAILURE);
            }
        }
    }

    return contenido;
}

char obtener_caracter(void) {
#ifdef _WIN32
    return getch();
#else
    struct termios normal, alterada;
    char c;

    tcgetattr(0, &normal);

    alterada = normal;
    normal.c_lflag &= ~( ICANON | ECHO );
    tcsetattr(0, TCSANOW, &alterada);

    c = getchar();

    tcsetattr(0, TCSANOW, &normal);

    return c == 4 ? 0 : c;
#endif
}
