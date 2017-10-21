#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define TAMANIO_NOMBRE          30
#define TAMANIO_APELLIDO_P      15
#define TAMABIO_APELLIDO_M      15

struct fecha {
    int anio;       // 1900 -
    int mes;        // 1 - 12
    int dia;        // 1 - 31
};

typedef struct estudiante Estudiante;
struct estudiante {
    char nombre[TAMANIO_NOMBRE + 1];                // MAs el carActer nulo
    char apellido_paterno[TAMANIO_APELLIDO_P + 1];
    char apellido_materno[TAMABIO_APELLIDO_M + 1];
    struct fecha fecha_nacimiento;
};

int leer_numero(int min, int max);
void leer_cadena(char * cadena, int longitud);

void imprimir(Estudiante clase[], int tamanio);

void ordenar(Estudiante clase[], int tamanio, int (*cmp)());
int comparar_fecha_ascendente();
int comparar_fecha_descendiente();
int comparar_nombre_ascendente();
int comparar_nombre_descendiente();

int main(void) {

    int num_estudiantes;
    printf("¿Cuántos estudiantes deseas registrar? (1 - 20)\n");

    num_estudiantes = leer_numero(1, 20);

    Estudiante clase[num_estudiantes];   // Arreglo de longitud variable

    for (int i = 0; i < num_estudiantes; i++) {

        printf("Ingrese los datos del estudiante %d\n", i + 1);

        printf("\tIngrese el apellido paterno: ");
        leer_cadena(clase[i].apellido_paterno, TAMANIO_APELLIDO_P + 1);

        printf("\tIngrese el apellido materno: ");
        leer_cadena(clase[i].apellido_materno, TAMABIO_APELLIDO_M + 1);

        printf("\tIngrese el nombre: ");
        leer_cadena(clase[i].nombre, TAMANIO_NOMBRE + 1);

        printf("\tIngrese el año de nacimiento: ");
        clase[i].fecha_nacimiento.anio = leer_numero(1900, 3000);

        printf("\tIngrese el mes de nacimiento: ");
        clase[i].fecha_nacimiento.mes = leer_numero(1, 12);

        printf("\tIngrese el día de nacimiento: ");
        clase[i].fecha_nacimiento.dia = leer_numero(1, 31);

        puts("\n");
    }

    bool salir = false;
    while (!salir) {
        puts("¿En qué orden deseas mostrar a los alumnos?");
        puts("\t1. Ordenados por fecha de nacimiento ascendente.");
        puts("\t2. Ordenados por fecha de nacimiento descendiente.");
        puts("\t3. Ordenados por nombre ascendente.");
        puts("\t4. Ordenados por nombre descendiente.");
        puts("\t5. Salír.");

        int opcion = leer_numero(1, 5);

        switch (opcion) {
            case 1:
                ordenar(clase, num_estudiantes, comparar_fecha_ascendente);
                break;
            case 2:
                ordenar(clase, num_estudiantes, comparar_fecha_descendiente);
                break;
            case 3:
                ordenar(clase, num_estudiantes, comparar_nombre_ascendente);
                break;
            case 4:
                ordenar(clase, num_estudiantes, comparar_nombre_descendiente);
                break;
            case 5:
                salir = true;
                break;

            default: fprintf(stderr, "Error, valor fuera de rango\n");

        }

        if (opcion >= 1 && opcion <= 4)
            imprimir(clase, num_estudiantes);
    }
    return 0;
}

void imprimir(Estudiante clase[], int tamanio) {
    puts("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    puts("\n============================= Los alumnos son: ============================\n");
    for (int i = 0; i < tamanio; i++) {
        printf("  %-15s %-15s %-30s %02d/%02d/%4d\n",
                clase[i].apellido_paterno,
                clase[i].apellido_materno,
                clase[i].nombre,
                clase[i].fecha_nacimiento.dia,
                clase[i].fecha_nacimiento.mes,
                clase[i].fecha_nacimiento.anio);
    }
    puts("\n===========================================================================\n");
}

void ordenar(Estudiante clase[], int tamanio, int (*cmp)()) {
    for (int i = 0; i < tamanio; i++) {
        for (int j = 0; j < tamanio - i - 1; j++) {
            if ( cmp(clase + j, clase + j + 1) < 0 ) {
                Estudiante aux = clase[j];

                clase[j] = clase[j + 1];
                clase[j + 1] = aux;
            }
        }
    }
}

int comparar_fecha_ascendente(Estudiante * a1, Estudiante * a2) {
    if (a1->fecha_nacimiento.anio != a2->fecha_nacimiento.anio)
        return a1->fecha_nacimiento.anio - a2->fecha_nacimiento.anio;

    if (a1->fecha_nacimiento.mes != a2->fecha_nacimiento.mes)
        return a1->fecha_nacimiento.mes - a2->fecha_nacimiento.mes;

    return a1->fecha_nacimiento.dia - a2->fecha_nacimiento.dia;
}

int comparar_fecha_descendiente(Estudiante * a1, Estudiante * a2) {
    return -comparar_fecha_ascendente(a1, a2);
}

int comparar_nombre_ascendente(Estudiante * a1, Estudiante * a2) {
    int cmp;
    cmp = strcmp(a1->apellido_paterno, a2->apellido_paterno);

    if (cmp) return cmp;

    cmp = strcmp(a1->apellido_materno, a2->apellido_materno);

    if (cmp) return cmp;

    return strcmp(a1->nombre, a2->nombre);
}

int comparar_nombre_descendiente(Estudiante * a1, Estudiante * a2) {
    return -comparar_nombre_ascendente(a1, a2);
}

int leer_numero(int min, int max) {
    bool valor_valido;
    int aux;

    valor_valido = scanf("%d", &aux) && aux >= min && aux <= max;
    while (getchar() != '\n');

    while ( !valor_valido ) {
        printf("El nUmero ingresado es invAlido, ingrese otro: ");
        valor_valido = scanf("%d", &aux) && aux >= min && aux <= max;
        while (getchar() != '\n');
    }

    return aux;
}

void leer_cadena(char * cadena, int longitud) {

    fgets(cadena, longitud, stdin);

    if ( cadena[strlen(cadena) - 1] == '\n' )
        cadena[strlen(cadena) - 1] = '\0';
    else
        while (getchar() != '\n');

}
