/*=======================================================*
 * Revisar la entrada por medio de apuntadores a funciOn *
 *=======================================================*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int leer_entero(bool (*numero_valido)(int));
void leer_cadena(char * cadena, int tamanio, bool (*es_valida)(const char *));

bool es_par(int);
bool es_potencia_de2(int);
bool es_un_digito(int);

bool es_vacia(char *);
bool es_numero_cuenta(const char *);
bool es_correo(const char *);

void limpiar_stdin(void);

int main(void) {
    printf("Ingresa un nUmero par: ");
    int par = leer_entero(es_par);

    printf("El nUmero ingresado es: %d\n\n", par);

    printf("Ingresa un nUmero que sea potencia de dos: ");
    int potencia = leer_entero(es_potencia_de2);

    printf("El nUmero ingresado es: %d\n\n", potencia);

    printf("Ingresa tu nUmero de cuenta: ");
    char numero_cuenta[14];
    leer_cadena(numero_cuenta, sizeof(numero_cuenta), es_numero_cuenta);
    printf("La cadena ingresada es: %s\n\n", numero_cuenta);

    printf("Ingresa tu correo\n");
    char correo[150];
    leer_cadena(correo, sizeof(correo), es_correo);
    printf("El correo ingreso es : %s\n\n", correo);

    return 0;
}

void leer_cadena(char * cadena, int tamanio, bool (*es_valida)(const char *)) {
    fgets(cadena, tamanio, stdin);

    while (es_vacia(cadena) || !es_valida(cadena)) {
        printf("La cadena es invAlida, ingrese otra: ");
        fgets(cadena, tamanio, stdin);
    }
}

int leer_entero(bool (*es_valido)(int)) {
    int d;
    bool valor_valido;
    valor_valido = scanf("%d", &d) && es_valido(d);

    limpiar_stdin();

    while (!valor_valido) {
        printf("Ese numero es invalido, ingrese otro: ");
        valor_valido = scanf("%d", &d) && es_valido(d);
        limpiar_stdin();
    }

    return d;
}

bool es_par(int x) {
    return x % 2 == 0;
}

bool es_potencia_de2(int x) {
    return (x != 0) && (x & ~x + 1) == x;
}

bool es_un_digito(int x) {
    return x >= 0 && x < 10;
}

bool es_vacia(char * cadena) {
    int longitud = cadena[strlen(cadena) - 1];

    if (longitud == 0)
        return true;

    if (cadena[longitud - 1] == '\n') {
        cadena[longitud - 1] = '\0';
        return longitud == 1;
    }

    return false;
}

bool es_numero_cuenta(const char * cadena) {
    if (strlen(cadena) != 9)
        return(false);

    if (cadena[0] != '3' && cadena[0] != '4')
        return false;

    for (int i = 1; i < 9; i++) {
        if (!isdigit(cadena[i]))
            return false, printf("Hola\n");
    }

    return true;
}

bool es_correo(const char * cadena) {
    bool arroba = false, punto = false, letra = false;

    if (strlen(cadena) <= 3)
        return false;

    for (int i = 0; cadena[i]; i++) {
        if (cadena[i] == '@') arroba = true;
        if (cadena[i] == '.') punto  = true;
        if (isalpha(cadena[i])) letra = true;
    }

    return arroba && punto && letra;
}

void limpiar_stdin(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

