/* Las cabeceras son incluidas por todos los archivos que requieran *
 * usar las funciones u objetos de una biblioteca. Es necesario     *
 * encerrar sus declaraciones entre macros condicionales para       *
 * evitar que las definiciones se repitan y colisionen en un        *
 * proyecto.                                                        */
#ifndef CABECERA_H
#define CABECERA_H

extern int var;     // La declaraciOn extern hace que la variable
                    // var sea visible y modificable por todos los
                    // archivos que incluyan la cabecera.

void imprimir_variable_externa(void); // Los prototipos de funciOn son
                                      // extern por defecto excepto por un
                                      // tipo de funciOn.

// Los prototipos de las funciones inline no son extern por defecto
// por lo que se tiene que indicar explicitamente.
extern void funcion_inline(void);
#endif /* CABECERA_H */
