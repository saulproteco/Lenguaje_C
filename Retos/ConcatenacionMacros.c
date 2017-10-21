/*==============================*
 * Explique el siguiente código *
 *==============================*/

#include <stdio.h>

#define construir(c,u,s,t,o,d,i,a) c ## u ## t ## s

#define iniciar construir(m,a,n,i,f,e,s,t)

#define imprimir construir(p,u,s,t,u,l,a,s)

int iniciar(void)
{
    imprimir("Hola mundo");

    return 0;
}
