/*=======================================*
 * Palabras modificadoras de apuntadores *
 *=======================================*/

/**
 * Autor: Martínez Ortiz Saúl Axel
 * Dificultad: Básico.
 * Requisitos: Memoria dinámica.
 * Estilo de código: Google.
 */

#include <stdio.h>  // printf
#include <stdlib.h> // EXIT_SUCCESS, malloc

int main(void) {
    /* Al igual que el resto de tipos de datos, los apuntadores pueden  *
     * modificarse con palabras como 'const' que impiden modificar una  *
     * variable (lo cual sigue el principio de mínimo privilegio).      *
     *
     * Sin embargo, los apuntadores son algo más complicados que eso y  *
     * puede que estas palabras no tengan el efecto deseado. Por otro   *
     * lado, existen nuevas palabras modificadoras solo aplicables en   *
     * apuntadores tales como 'restrict'                                */

    // ##### ¿Apuntador constante a datos constantes? #####

    // Las variables con 'const' no pueden modificarse
    const int val = 10;

    /*val++; // Des-comente esta línea para obtener un error*/

    // Hagamos la declaración de un apuntador 'const' y para un pequeño
    // experimento
    int a = 10;
    const int * apt = &a;

    // Si se comportara como las variables normales, no deberíamos poder
    // hacer un incremente sobre este apuntador, vamos a observar

    apt++; // ¡No da error, el 'const' es mentira!

    // Bueno, parece que podemos hacer lo que queramos, entonces simplemente
    // vamos a modificar el valor al que 'apt' está apuntando.

    // (*apt)++;  // ¡Ahora si da error! (des-comentar para comprobarlo)

    // El asunto aquí es que la si aparece la palabra 'const' antes del
    // asterisco, esta será interpretada como "No se pueden cambiar a los
    // que estoy apuntando". Para conseguir el resultado deseado (que no
    // se pueda modificar el apuntador) se debe usar la palabra en frente
    // del asterisco.

    int * const apt2 = &a;

    // apt2++; // ¡Ahora si es un error!

    // Incluso se pueden usar ambos modificadores para tener una variable
    // apuntador constante que apunte a datos constantes.

    const int * const apt3 = &a;

    // apt3++;    // Ambos son un error
    // (*apt3)++;

    // ##### ¿Apuntadores restringidos por quién? #####

    // Hay un modificador más aplicable solo a los apuntadores que
    // a simple vista no parece tener un efecto sobre la forma de
    // programar.
    //
    // La palabra reservada restrict sirve para indicar al compilador
    // que un apuntador es el único capaz de acceder a la dirección de
    // memoria a la que referencian, sin embargo a diferencia de const
    // el propio compilador no hará nada para obligarnos a cumplir dicha
    // condición. Es decir, solo hay una restricción autoimpuesta o
    // 'promesa' que le hacemos al compilador de que para cierto dato
    // solo tenemos una referencia, habilitando así algunas
    // optimizaciones que normalmente no se pueden realizar.
    //
    // Si cumplimos bien nuestra restricción el resultado será un código
    // un poco más optimo de lo normal, pero si no la cumplimos
    // el programa puede tener un comportamiento indefinido.

    int * restrict nuevoDato = malloc(sizeof(int));

    // La asignación y el uso son idénticos (de hecho todo es igual)
    *nuevoDato = 100;
    printf("El dato es: %d\n", *nuevoDato);

    // El código que sigue es lo que NO se debe hacer dado el riesgo
    // de generar comportamiento indefinidos.
    int * otraReferenciaAlNuevoDato = nuevoDato;

    *otraReferenciaAlNuevoDato = 20;

    free(nuevoDato);
    return EXIT_SUCCESS;
}
