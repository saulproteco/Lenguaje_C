/*=====================================================*
 * Programa para graficar ecuaciones                   *
 *                                                     *
 * DescripciOn:                                        *
 *  Programa que usa secuencias de escape de           *
 *  terminales unix.                                   *
 *                                                     *
 *  Una funciOn real de variable suele tener una       *
 *  ecuaciOn asociada sin embargo una ecuaciOn no      *
 *  siempre representa una funciOn.                    *
 *  Tal es el caso de la ecuaciOn de la elipse o de la *
 *  mayoria de las ecuaciones diferenciales que no     *
 *  pueden representar una funciOn dado que por la     *
 *  propia definiciOn de esta, cada valor del dominio  *
 *  debe estar asociada a un solo valor del codominio  *
 *  y las ecuaciones mencionadas tienen generan varios *
 *  valores.                                           *
 *  La forma de representar de manera funcional dichas *
 *  ecuaciones es separarlas en cuantas funciones con  *
 *  un solo valor de retorno haya falta.               *
 *=====================================================*/

// ##### Bibliotecas y definiciones #####
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef double (*funcionRealDeVariableReal)(double);

#define ESCALA 2.0
#define ever (/*O*/; ;/*O*/) // Te estoy viendo

enum opciones {
    IDENTIDAD = 1,
    CIRCULO,
    PARABOLA,
    HIPERBOLA,
    SENOIDAL,
    SALIR
};

// Se comprueba el sistema operativo para elegir el comando
// correcto
#ifdef _WIN32
#   define CLEAR "cls"
#else
#   define CLEAR "clear"
#endif


// ##### Protipos de funciOn #####
void menu_graficadora(void);
int leer_entero(int min, int max);
void graficar(double (*arr_funciones[])(double), int num_funciones);

// Los prototipos de funciOn son extern por defecto, excepto en las
// funciones inline
extern double recta(double x);
extern double semicirculo_superior(double x);
extern double semicirculo_inferior(double x);
extern double parabola(double x);
extern double hiperbola_superior(double x);
extern double hiperbola_inferior(double x);
extern double senoidal(double x);

// ##### Variables globales (solo en el archivo)
static int ancho;
static int alto;

int main(int argc, char * argv[]) {

    system(CLEAR);
    if (argc != 3) {

        fprintf(stderr,
                "Hace falta que escribas las dimensiones de tu pantalla\n"
                "como argumentos del programa tal como sigue:\n"
                "\t\t<programa> <ancho> <alto>\n");
        return EXIT_FAILURE;
    }

    ancho = atoi(argv[1]);
    alto  = atoi(argv[2]);

    if (alto <= 0 || ancho <= 0)
        fprintf(stderr, "Dimensiones inválidas\n");

    menu_graficadora();
    return 0;
}

void menu_graficadora(void) {

    for ever {

        puts("Elija la funciOn que quiere graficar:");
        puts("1. Recta identidad");
        puts("2. Circulo");
        puts("3. Parábola");
        puts("4. Hipérbola");
        puts("5. Senoidal");
        puts("6. Salír");

        int opcion = leer_entero(1, SALIR);

        system(CLEAR);

        switch (opcion) {
            case IDENTIDAD:
                graficar(
                        // Se crea un arreglo anonimo de apuntadores a
                        // funciOn con la funciOn recta
                        (double (*[])(double)) { recta },
                        1  // Una sola funciOn a recorrer
                        );
                break;

            case CIRCULO:
                graficar(
                        // Se crea un arreglo con las dos mitades del
                        // circulo
                        (double (*[])(double)) { semicirculo_superior, semicirculo_inferior },
                        2  // Dos funciones a recorrer
                        );
                break;

            case PARABOLA:
                graficar(
                        // Se crea el arreglo de funciones mediante el
                        // alias que se asigno al prototipo de funciones.
                        //
                        // Esta forma una vez entendida suele ser bastante
                        // mAs clara.
                        (funcionRealDeVariableReal []) { parabola },
                        1
                        );
                break;

            case HIPERBOLA:
                graficar(
                        (funcionRealDeVariableReal []) { hiperbola_superior, hiperbola_inferior },
                        2
                        );
                break;

            case SENOIDAL:
                graficar(
                        (funcionRealDeVariableReal []) { senoidal },
                        1
                        );
                break;

            case SALIR:
                system(CLEAR);
                puts("¡¡Adiós!!");
                getchar();

                exit(EXIT_SUCCESS);
                break;

            default:
                fprintf(stderr, "It was at that moment that he knew, he fucked up");
                break;
        }

        getchar();
        system(CLEAR);
    }
}

void graficar(
        double (*arr_funciones[])(double), // Arreglo de funciones
        int num_funciones                  // Longitud del arreglo
) {
    // Recorre todas las funciones a graficar
    int ordenada_actual = 0;

    printf("\033[%dB", alto / 2);

    for (int funcion = 0; funcion < num_funciones; funcion++) {

        printf("\033[%dD", ancho); // Regresamos el cursor al inicio

        // Recorre los puntos que hay que dibujar
        for (int punto = 0; punto < ancho; punto++) {
            int ordenada_deseada = (arr_funciones[funcion])(punto) / ESCALA;

            if ( ordenada_deseada < -alto / 2 ||
                 ordenada_deseada >  alto / 2 )
            {
                // El punto se sale de la pantalla, hay que saltar
                // a la siguiente iteraciOn pero no sin antes
                // avanzar en el eje X
                putchar(' ');

                continue;
            }

            // Nos movemos al la ordenada correcta (con secuencias de escape
            // de linux)
            if (ordenada_deseada > ordenada_actual)
                printf("\033[%dA", ordenada_deseada - ordenada_actual);

            if (ordenada_actual > ordenada_deseada)
                printf("\033[%dB", ordenada_actual - ordenada_deseada);

            // Actualizamos la abscisa e imprimimos el asterisco
            ordenada_actual = ordenada_deseada;

            putchar('*');
        }
    }
}

inline double recta(double x) {
    return x - ancho / 2; // Se desplaza media pantalla hacia la derecha
}

inline double semicirculo_superior(double x) {
    x -= ancho / 2; // Se desplaza media pantalla hacia la derecha
    return sqrt(alto * alto - x * x - 2 * alto);
}

inline double semicirculo_inferior(double x) {
    return - semicirculo_superior(x);
}

inline double parabola(double x) {
    x -= ancho / 2;
    return x * x / 15;
}

inline double hiperbola_superior(double x) {
    x -= ancho / 2; // Se desplaza media pantalla hacia la derecha
    return sqrt(2 * alto + x * x);
}

inline double hiperbola_inferior(double x) {
    return - hiperbola_superior(x);
}

inline double senoidal(double x) {
    return alto * sin(6 * x / ancho) / 1.5;
}

int leer_entero(int min, int max) {
    int d;
    bool valor_valido;

    valor_valido = scanf("%d", &d) && d >= min && d <= max;
    while (getchar() != '\n');

    while (!valor_valido) {
        printf("Valor fuera de rango, ingrese otro\n");

        valor_valido = scanf("%d", &d) && d >= min && d <= max;

        while (getchar() != '\n');
    }

    return d;
}
