/*===================================*
 * ¡No seas genérico!, ¡Sé concreto! *
 *===================================*/

#include <stdio.h>

/*
 * Indique el tipo de dato por defecto qué
 * tienen las distintas literales del lenguaje
 */

int main(void)
{

    char * tipo = _Generic(10,
                           int     : "entero",
                           float   : "flotante de precisión simple",
                           double  : "flotante de precisión doble",
                           char    : "carácter",
                           char *  : "cadena",
                           default : "No se de que tipo de dato se trata");

    printf("El tipo de dato de 10 es: %s\n", tipo);

           tipo = _Generic(5.5,
                           int     : "entero",
                           float   : "flotante de precisión simple",
                           double  : "flotante de precisión doble",
                           char    : "carácter",
                           char *  : "cadena",
                           default : "No se de que tipo de dato se trata");

    printf("El tipo de dato de 5.5 es: %s\n", tipo);

           tipo = _Generic('a',
                           int     : "entero",
                           float   : "flotante de precisión simple",
                           double  : "flotante de precisión doble",
                           char    : "carácter",
                           char *  : "cadena",
                           default : "No se de que tipo de dato se trata");

    printf("El tipo de dato de 'a' es: %s\n", tipo);

           tipo = _Generic("hola que hace",
                           int     : "entero",
                           float   : "flotante de precisión simple",
                           double  : "flotante de precisión doble",
                           char    : "carácter",
                           char *  : "cadena",
                           default : "No se de que tipo de dato se trata");

    printf("El tipo de dato de \"hola que hace\" es: %s\n", tipo);

           tipo = _Generic(10000000000,
                           int     : "entero",
                           float   : "flotante de precisión simple",
                           double  : "flotante de precisión doble",
                           char    : "carácter",
                           char *  : "cadena",
                           default : "No se de que tipo de dato se trata");

    printf("El tipo de dato de \"10000000000\" es: %s\n", tipo);

}
