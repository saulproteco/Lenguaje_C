/*====================================================================*
 * Código que usa la ecuación cartesiana del circulo para imprimir su *
 * forma y se usa la función seno para imprimir una especie de ola    *
 * vertical.                                                          *
 *====================================================================*/

// Compilar con -lm para enlazar math.h

#include <stdio.h>  // putchar, getchar
#include <stdlib.h> // EXIT_SUCCESS
#include <math.h>   // sqrt

#define ANCHO 40.0

// Cambien la escala a lo que mejor se vea
#define ESCALA 2.0

int main(void)
{
    int x, y;

    // Las gráficas que hacemos tienen el eje volteado
    //
    //  +-----------------> y
    //  |
    //  |
    //  |
    //  |
    //  |
    //  |
    //  v
    //  x

    // Circulo normal
    for (x = 0; x <= ANCHO; x++) {
        // Se obtiene el radio según la ecuación del circulo despejada
        int radio = ESCALA * sqrt(x * (ANCHO - x));
        for (y = 0; y < ESCALA * ANCHO; y++) {
            putchar(y >= ANCHO / 2 * ESCALA - radio &&
                    y < ANCHO / 2 * ESCALA + radio ? '*' : ' ');
        }
        putchar('\n');
    }
    puts("Presiona una tecla para continuar . . ."); getchar();

    // Circulo invertido
    for (x = 0; x <= ANCHO; x++) {
        // Se obtiene el radio segUn la ecuación del circulo despejada
        int radio = ESCALA * sqrt(x * (ANCHO - x));
        for (y = 0; y < ESCALA * ANCHO; y++) {
            putchar(y >= ANCHO / 2 * ESCALA - radio &&
                    y < ANCHO / 2 * ESCALA + radio ? ' ' : '*');
        }
        putchar('\n');
    }

    puts("Presiona una tecla para continuar . . ."); getchar();

    return EXIT_SUCCESS;
}

/** Salida esperada **


                            ************************
                       **********************************
                   ******************************************
                ************************************************
              ****************************************************
            ********************************************************
          ************************************************************
        ****************************************************************
       ******************************************************************
      ********************************************************************
     **********************************************************************
    ************************************************************************
   **************************************************************************
  ****************************************************************************
  ****************************************************************************
 ******************************************************************************
 ******************************************************************************
 ******************************************************************************
 ******************************************************************************
********************************************************************************
 ******************************************************************************
 ******************************************************************************
 ******************************************************************************
 ******************************************************************************
  ****************************************************************************
  ****************************************************************************
   **************************************************************************
    ************************************************************************
     **********************************************************************
      ********************************************************************
       ******************************************************************
        ****************************************************************
          ************************************************************
            ********************************************************
              ****************************************************
                ************************************************
                   ******************************************
                       **********************************
                            ************************

Presiona una tecla para continuar . . .
********************************************************************************
****************************                        ****************************
***********************                                  ***********************
*******************                                          *******************
****************                                                ****************
**************                                                    **************
************                                                        ************
**********                                                            **********
********                                                                ********
*******                                                                  *******
******                                                                    ******
*****                                                                      *****
****                                                                        ****
***                                                                          ***
**                                                                            **
**                                                                            **
*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *

*                                                                              *
*                                                                              *
*                                                                              *
*                                                                              *
**                                                                            **
**                                                                            **
***                                                                          ***
****                                                                        ****
*****                                                                      *****
******                                                                    ******
*******                                                                  *******
********                                                                ********
**********                                                            **********
************                                                        ************
**************                                                    **************
****************                                                ****************
*******************                                          *******************
***********************                                  ***********************
****************************                        ****************************
********************************************************************************
Presiona una tecla para continuar . . .

 */