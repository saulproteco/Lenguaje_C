#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "Spanish_Mexico");
    puts("Hola, ¿Qué hace?");
    return 0;
}
