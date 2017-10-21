/*====================*
 * Respuesta Tarea 3  *
 * Argumentos Defecto *
 *====================*/

#include <stdio.h>  // printf
#include <stdlib.h> // EXIT_SUCCESS

struct argVolumen {
    double largo;
    double ancho;
    double alto;
};

// Haciendo una macro para esconder el uso de esctructuras
#define volumenPrisma(...) validaArgumentos( (struct argVolumen) {__VA_ARGS__} )
static double validaArgumentos(struct argVolumen);

// Función que hace el verdadero trabajo, la función validaArgumentos
// se encarga de pasarle los argumentos por defecto.
double calculo_volumen(double largo, double ancho, double alto);

int main(void) {
    // Probando la función para calcular volumen.

    printf("Volumen con largo = %f, ancho y alto por defecto: %f\n",
            10.0, volumenPrisma(10));

    printf("Volumen con largo = %f, ancho  = %f y alto por defecto: %f\n",
            5.0, 10.0, volumenPrisma(10, 5));

    printf("Volumen con largo = %f, ancho  = %f y alto = %f: %f\n",
            5.0, 10.0, 7.0, volumenPrisma(10, 5, 7));

    printf("Volumen con ancho = %f, alto = %f y largo por defecto: %f\n",
            25.0, 12.0, volumenPrisma( .ancho = 25, .largo = 12));

    printf("Lo que pasa con datos inválidos (%f, %f, %f): %f\n"
            "(Los datos inválidos pasan a ser el valor por defecto -1-)",
            4.0, -1000.0, -50.0,
            volumenPrisma(.largo = 4, .ancho = -1000, .alto = -50));

    return EXIT_SUCCESS;
}

static double validaArgumentos(struct argVolumen dimensiones) {
    return calculo_volumen( dimensiones.largo > 0 ? dimensiones.largo : 1,
                            dimensiones.ancho > 0 ? dimensiones.ancho : 1,
                            dimensiones.alto  > 0 ? dimensiones.alto  : 1  );
}

double calculo_volumen(double largo, double ancho, double alto) {
    return largo * ancho * alto;
}
