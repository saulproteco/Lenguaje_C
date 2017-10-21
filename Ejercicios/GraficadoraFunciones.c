/*================================================*
 * Graficadora de funciones                       *
 *                                                *
 * Las funciones son reglas de asociaciOn entre   *
 * valores que deben cumplir tener un Unico       *
 * valor de retorno dado cierto valor de          *
 * entrada.                                       *
 * Por ello, no se pueden graficar expresiones    *
 * tales como un circulo completo que para un     *
 * valor de entrada tienen dos de salida.         *
 *                                                *
 *================================================*/


#include <stdio.h>
#include <math.h>

#define PUNTOS 50       // NUmero de puntos a graficar, ajustar segUn tu pantalla
#define ESCALA 1.7      // Para tratar de igualar el largo de los caracteres con su ancho

void graficar(double (*f)(double));

double parabola(double x)
{
    return (x * x) / 25;
}

#define RADIO 50
double semi_circulo(double x)
{
    return RADIO - sqrt(RADIO * RADIO - x * x);
}

double recta(double x)
{
    return x;
}

int main(void)
{
    printf("Ejemplo de parAbola:\n");
    graficar(parabola);

    getchar();

    printf("Ejemplo de circulo:\n");
    graficar(semi_circulo);

    getchar();

    printf("Ejemplo de recta:\n");
    graficar(recta);
    getchar();

    return 0;
}

/*
 * Funcion graficar: Recibe una funciOn f(x) creciente y la grafica
 * vecticalmente volteada.
 *
 * El detalle de ser una funciOn creciente aplica solo para esta
 * funciOn graficadora sencilla, sin embargo ese detalle puede ser
 * facilmente sobrepasado con un poco mAs de cOdigo.
 */
void graficar(double (*f)(double x))
{
    int y = 0;

    for (int x = 0; x < PUNTOS; x++) {

        while (y < f(x) / ESCALA) {

#ifndef _WIN32      // Arreglando las cosas para windows :S
            putchar('\v');
#endif // _WIN32

            y++;        //
        }

#ifdef _WIN32       // Lo mismo que el anterior #if
        printf("%*s\n", x, "");
#endif  // _WIN32

        putchar('*');
    }
}
