/*=================*
 * Hola mundo en C *
 *=================*/

#include <stdio.h>      // puts, getchar
#include <stdlib.h>     // EXIT_SUCCESS (macro con valor 0)

/**
 * Autor: Martínez Ortiz Saúl Axel
 * Dificultad: Básico.
 * Requisitos: Bases de programación.
 * Estilo de código: GNU.
 */

// La función main es el punto de entrada del programa,
// y por tanto es la que cumple la labor de interfaz entre
// el proceso que lo mandó a llamar (generalmente la consola)
// y el programa en si.
//
// La posible comunicación entre consola y programa consiste en:
//      Mensajes que le mandó el proceso padre:
//          - contador_argumentos(normalmente llamado argc): Un entero
//              que cuente el número de cadenas que fueron mandadas al main.
//          - vector_argumentos(normalmente llamado argv): Un arreglo
//              de cadenas que almacenara los argumentos.
//      Mensaje que retorna el programa al proceso padre:
//          - Un entero que indica el estado de finalización del programa.
//            (por convención, 0 significa éxito y cualquier otro número
//            significa fallo).
//
// El estándar de C también acepta otra forma para el main la cual no
// recibe argumentos. También hay otras formas alternativas del main
// main que no van acordes con el estándar y que dependen del compilador
// o de la plataforma, por ejemplo, el compilador de GNU puede recibir un
// argumento extra que es un apuntador a las variables de entorno del
// sistema, generalmente llamado "envp".

#define IGNORAR_ADVERTENCIA_DE_VARIABLE_SIN_USAR(x) (void) x

int // Tipo de retorno entero por defecto, se puede omitir en C89
main (
        int contador_argumentos,
        char * vector_argumentos[]
#ifdef __GNUC__     // El tercer argumento solo es válido en gcc
        , char * apuntador_variables_entorno[]
#endif
     )
{

    IGNORAR_ADVERTENCIA_DE_VARIABLE_SIN_USAR(contador_argumentos);
    IGNORAR_ADVERTENCIA_DE_VARIABLE_SIN_USAR(vector_argumentos);
#ifdef __GNUC__
    IGNORAR_ADVERTENCIA_DE_VARIABLE_SIN_USAR(apuntador_variables_entorno);
#endif

    puts ("¡Hola mundo!"); // Imprime el mensaje.
    getchar (); // Espera a que se presione enter antes de salir.

    return EXIT_SUCCESS;    // Regresa 0, es decir éxito
}
