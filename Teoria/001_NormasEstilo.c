/*==================================*
 *   Normas de estilo para código   *
 *   establecidas por diferentes    *
 *   proyectos u organizaciones.    *
 *==================================*/

/**
 * Autor: Martínez Ortiz Saúl Axel
 * Dificultad: Básico.
 * Requisitos: Bases de programación.
 * Estilo de código: Misceláneo.
 */

// Las normativas de estilo aquí presentadas son aplicadas al código
// para mejorar la legibilidad del mismo en la mayoría de los casos.
// Es recomendable codificar desde el inicio con alguno de los estilos
// presentados o una combinación de ellos. Igualmente se puede optar por
// un estilo propio siempre y cuando este sea lo suficientemente
// consistente

/* Casi en todas las normativas se pone
   un espacio después del include
        |
        v                              */
#include <stdio.h>

/* ##### Indentación ##### */

=> Linux (8 espacios):

   {   // Abre bloque externo

           código

           {   // Abre bloque interno

                   más código

           }   // Cierra bloque interno

   }   // Cierra bloque externo

=> GNU, google y microsoft (4 espacios):

   {   // Abre bloque externo

       código

       {   // Abre bloque interno

           más código

       }   // Cierra bloque interno

   }   // Cierra bloque externo

/* ##### Funciones ##### */

=> GNU

   tipo_retorno // Se sitúa en una línea anterior
   nombre_funcion (tipo_1 argumento1, tipo_2 argumento2,
                   tipo_3 argumento3, tipo_4 argumento4)
   {
       código
   }

=> google:

   // Todo en la misma línea
   tipoRetorno nombreFuncion(tipo1 argumento1, tipo_2 argumento2) {
       código
   }

=> Linux y Microsoft:
   // El tipo de retorno va en la misma línea
   tipo_retorno nombre_funcion(tipo_1 argumento1, tipo_2 argumento2,
                               tipo_3 argumento3, tipo_3 argumento3)
   {
       código
   }

/* ##### Sentencias de control ##### */

=> GNU:

if (condición)
    código;

    ó

if (condición)
  {
    código
  }
else
  {
    más código
  }

while (condición)
    código;

    ó

while (condición)
  {
    código
  }

do  // Se considera que no usar llaves en el do-while es confuso
  {
    código
  }
while (condición);

switch (condición)
  { // Dos espacios indentación

  case UNO: // Al mismo nivel que las llaves

    hacer_algo ();
    break;

  case DOS:
    hacer_otra_cosa (); // Espacio antes de los paréntesis
    break;

  } // Dos espacios indentación

=> google:

if (condición) {    // Siempre se deben poner llaves en el estilo de google
    código
} else {
    más código
}

while (condición) {
    código
}

do {
    código
} while (condición);

switch (condición) {
  case UNO:
    hacer_algo();   // sin espacio antes de los paréntesis
    break;

  case DOS:     // Dos espacios para las etiquetas
    hacer_otra_cosa();
    break;

}

=> Linux:

if (condición)
        código;

    ó

if (condición) {
        código
} else {
        más código
}

while (condición)
        código;

    ó

while (condición) {
        código
}

do {    // Siempre lleva llaves
        código
} while (condición);

switch (condición) {

case UNO:
        hacer_algo();   // Sin espacio antes de los paréntesis
        break;

case DOS:           // Sin indentación en las etiquetas
        hacer_otra_cosa();
        break;

}

=> Microsoft:

if (condición) // Siempre se ponen las llavez
{
    código
}

if (condición)
{
    código
}
else
{
    más código
}

while (condición)
{
    código
}

do  // No hay otra forma para el do, pues se considera que ponerlo sin llaves es confuso
{
    código
}
while (condición);

switch (condición)
{

  case UNO: // Dos niveles de indentación

    HacerAlgo();
    break;

  case DOS:
    {
      HacerOtraCosa();  // Funciones en mayúscula
      UnaCosaMas();
    }
    break;

}

/* Typedef's sobre estructuras */

=> Google:
    Siempre remarcar los tipos importantes con typedef's

   typedef struct miEstructura {

       Datos

   } miEstructura;  // Mismo nombre de alias y de estructura

   miEstructura var1;

=> GNU:

    Usar typedef añadiendo el sufijo "_t" cuando mejore la legibilidad
    del código.

   typedef struct mi_estructura
   {

       Datos

   } mi_estructura_t;

   mi_estructura_t var1;

=> Linux:
    Nunca usar typedef's a menos que se quiera explícitamente hacer uso
    de datos opacos/ocultar cosas al programador.

    struct mi_estructura {

        Datos

    };

    struct mi_estructura var1;

=> Microsoft:

    typedef struct miestructura
    {
        Datos
    } MiEstructura;

    MiEstructura var1;

/* ##### Espacios entre operadores ##### */

GNU, Linux, Google y Microsoft: (Por fin se ponen de acuerdo)
    Siempre usar espacios al rededor de los operadores binarios para
    mejorar la legibilidad. No son necesarios espacios entre paréntesis
    o corchetes.

        12 + 15
        a = 25;
        5 / 23 * (4 - 17)
        var = 5 ^ 4 % 2 - (5 && 4)

    La excepción a la regla anterior se da con los operadores de acceso,
    los cuales deben aparecer inmediatamente después del contenedor al
    que se aplican:

        estructura.dato
        apuntador->dato2
        arreglo[indice]

    Los operadores unarios no deben tener separación con respecto al
    dato al que afectan, esto permite entre otras cosas diferenciar la
    "multiplicación" de la "desreferenciación":

        indice++
        --variable
        *apuntador

/* ##### Límite de caracteres por línea ##### */
    Linux: 80 columnas por línea a menos que usar una cantidad
        ligeramente mayor pudiera mejorar la legibilidad considerablemente.

    Google: 100 columnas "" "" "".

/* ##### Criterios para romper líneas ##### */
    Google: Siempre cortar las líneas largas después de las comas o
    antes de un operador aritmético y situando el código continuado
    en una Indentación significativamente más amplia que la primera
    línea. Si la última regla propicia grandes cantidades de código
    amontonado hacia la derecha, indentar con 2 tabulaciones en su
    lugar.
