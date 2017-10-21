/*====================================*
 * ImpresiOn del contenido binario de *
 * cualquier variable mediante        *
 * operaciones de bits                *
 *====================================*/

// Biblioteca entrada / salida
#include <stdio.h> // putchar

// Biblioteca de enteros de tamanio fijo (da igual la plataforma)
#include <stdint.h> // int8_t

// Constantes y macrofunciones
#define printBin(var) imprime_binario(&var, sizeof(var))

// Prototipos de funcion
void imprime_binario(void * var, int tamanio);

// FunciOn principal
int main(void)
{
    int entero = 37;
    int entero2 = -1;
    char caracter = 'A';
    float flt = 12.5;

    struct { int a; char b[4]; float c; } estructura = { 12, "ABC", 15.5 };

    printf("El entero en representación binaria es:\n");
    printBin(entero);
    printf("\nEl entero en representación binaria es:\n");
    printBin(entero2);
    printf("\nEl carácter en representación binaria es:\n");
    printBin(caracter);
    printf("\nEl flotante en representación binaria es:\n");
    printBin(flt);

    printf("\nLa estructura es:\n");
    printBin(estructura);

    return 0;
}

/*
 * imprime_binario
 *
 * argumentos:
 *  var : Un apuntador a void para recibir referencias de cualquier tipo.
 *  tamanio : La cantidad de bytes que ocupa la variable recibida.
 *
 * regresa:
 *  Vacio
 */
void imprime_binario(void * var, int tamanio) {
    // La mascara tambiEn no requiere mas de 8 bits pues esa es la
    // mAxima cantidad de bits que tiene sentido recorrer en un byte
    const int8_t mascara = 1;

    for (int bytes = tamanio - 1; bytes >= 0; bytes--) {
        // Un entero de ocho bits es un byte
        // Sería equivalente a un char
        int8_t byte = *(char*)(var + bytes);

        for (int i = 7; i >= 0; i--) {
            if ( (byte & (mascara << i)) != 0 )
                putchar('1');
            else
                putchar('0');
        }
        putchar(' ');

        // Esta parte se encarga de dar espacios cada 4
        // bytes
        if ( (tamanio - bytes) % 4  == 0 ) putchar('\n');
    }

    if (tamanio % 4) putchar('\n');
}
