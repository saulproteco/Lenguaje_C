/*===================*
 * Respuesta Tarea 1 *
 *    Calculadora    *
 *===================*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Use la bandera -lm para compilar la biblioteca math

// Constantes para representar el estado de salida
enum codigos_salida {
    TODO_CORRECTO,
    CANTIDAD_ARGUMENTOS_ERRONEA,
    ARGUMENTOS_DEFECTUOSOS,
    OPERACION_DESCONOCIDA
};

// Prototipos
void calcular(const char * restrict * argumentos);
void instrucciones(const char * restrict);

// Función main
int main(int argc, const char * restrict argv[])
{
    argc == 4 ? calcular(argv) : instrucciones(argv[0]);
}

// Función que hace el cálculo
void calcular(const char * restrict * argumentos)
{
    long double a, b;          // Valores a operar.
    char * indicador_posicion; // Apuntador para revisar la validez de los
                               // argumentos.

    union /* Anónima */ {
        long double suma;
        long double resta;
        long double multiplicacion;
        long double division;
        long double potencia;
        long double da_igual;
    } resultado; // En esta unión se almacenan los resultados

    // Convirtiendo los argumentos. strtold existe a partír de c99
    a = strtold(argumentos[1], &indicador_posicion);

    if ( indicador_posicion == argumentos[1] ) {
        fputs("Error de conversión", stderr);
        exit(ARGUMENTOS_DEFECTUOSOS);
    }

    b = strtold(argumentos[3], &indicador_posicion);

    if ( indicador_posicion == argumentos[3] ) {
        fputs("Error de conversión", stderr);
        exit(ARGUMENTOS_DEFECTUOSOS);
    }

    // Haciendo las operaciones.
    switch ( *argumentos[2] ) {
        case '+': resultado.suma = a + b;           break;

        case '-': resultado.resta = a - b;          break;

        case '*': resultado.multiplicacion = a * b; break;

        case '/': resultado.division = a / b;       break;

        case '^': resultado.potencia = powl(a, b);   break;
                                    /* powl existe a partír de c99 */
        default:
            fprintf(stderr, "Operación desconocida\n");
            exit(OPERACION_DESCONOCIDA);
            break;
    }

    printf("El resultado es: %Lg\n", resultado.da_igual);

    exit(TODO_CORRECTO);
}

// Función que imprime las instrucciones en caso de que no se
// proporcionen los argumentos correctos.
void instrucciones(const char * restrict nombre_programa)
{
    puts("Modo de uso:");
    printf("\t $ %s <valor1> <op> <valor2>\n", nombre_programa);

    puts("\n\t Para la operación puedes elegir entre los signos");
    puts("\t 1. + (suma)");
    puts("\t 2. - (resta)");
    puts("\t 3. * (multiplicación)");
    puts("\t 4. / (división)");
    puts("\t 4. ^ (potencia)");

    exit(CANTIDAD_ARGUMENTOS_ERRONEA);
}
