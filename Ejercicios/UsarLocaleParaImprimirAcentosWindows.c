/*==============================================*
 * Uso de locale.h para cambiar configuraciones *
 *            de idioma y región.               *
 *==============================================*/

#include <stdio.h>  // puts
#include <stdlib.h> // EXIT_SUCCESS
#include <locale.h> // setlocale

int main(void)
{
    // Se establece la configuración de todas las variables regionales
    // Español de Mexico. Esta es una forma común y sencilla de imprimir
    // caracteres hispanos en Windows. En linux generalmente no es
    // necesario para tal proposito pero aun si puede afectar formatos
    // de moneda y de fecha.

    setlocale(LC_ALL, "Spanish_Mexico");

    // Notesé que para visualizar correctamente el resultado, el documento
    // no debe estar guardado en UTF-8 dado que las consolas de cmd (y
    // posiblemente las de powershell) no son compatibles con esta
    // codificación. Es necesario que se guarde este documento en la
    // misma codificación que usa el sistema windows.
    puts("Hola, ¿Qué hace?");

    return EXIT_SUCCESS;
}
