/*================*
 * Funciones en C *
 *================*/

/**
 * Autor: Martínez Ortíz Saúl Axel
 * Dificultad: Intermedio-Avanzado.
 * Requisitos: Arreglos, estructuras de control.
 * Estilo de código: Linux modificado (4 espacios por tab).
 */

#include <stdio.h>    // printf, puts
#include <stdlib.h>   // srand, rand, calloc
#include <stdbool.h>  // true, false
#include <time.h>     // time

// Nota: El presente código hace uso extensivo de una característica
// específica de GNU-C (funciones anidadas) con fines de que la lectura sea
// estructurada en lugar de hacer saltos constantes entre prototipo,
// declaración y uso de la función a lo largo del programa.
// A causa de esto no se posible compilarlo sin gcc.
// En caso de usar otro compilador, copie los ejemplos uno por uno y
// mueva ĺas declaraciones y contenidos de las funciones fuera del main.


// ##### Declaración de funciones (prototipo) #####

/* Mediante el prototipo se le indica al compilador la estructura de *
 * las funciones que se encontrará en el código. Con base en ello    *
 * se harán revisiones de los argumentos con que es llamada una      *
 * función. Es posible definir y hacer uso de una función sin crear  *
 * su prototipo pero en dicho caso estamos condicionados a escribir  *
 * la función antes de cualquier punto del código donde la susodicha *
 * función sea usada.                                                *
 *                                                                   *
 * La sintaxis del prototipo de función es:                          *
 *  <valor_retorno> <nombre_función>(<lista_parámetros>);            */

void saluda(void);      // Prototipo de una función llamada 'saluda'

// ##### Definición de funciones (cuerpo) #####

/* En correspondencia al prototipo que define la estructura, el cuerpo *
 * define la funcionalidad. El cuerpo de la función es una porción de  *
 * código re-utilizable, toda llamada a la misma será enlazada ya sea  *
 * de forma estática o dinámica a la dirección inicial de dicho código *
 * para poder ejecutarse.                                              *
 *                                                                     *
 * La sintaxis del cuerpo de la función es:                            *
 *  <valor_retorno> <nombre_función>(<lista_parámetros>)               *
 *  {                                                                  *
 *      <Código>                                                       *
 *  }                                                                  */

void saluda(void)   // Cuerpo de la función 'saluda'
{
    puts("¡Hola, estoy dentro de una función!");
}

int main(void)
{

    srand(time(NULL));

    // ##### Llamada a la función #####

    /* Corresponde al uso de la función dentro del programa. Una llamada    *
     * causa que el flujo del programa de un salto hacia la primera         *
     * instrucción de la función que acaba de ser llamada y empiece a       *
     * ejecutar sus instrucciones. Una vez que se termine con las           *
     * instrucciones se retoma el flujo original.                           *
     * Si la función tiene valor de retorno, este sustituirá a el código    *
     * correspondiente a la llamada de la función.                          *
     *                                                                      *
     * La sintaxis de la llamada a la función es:                           *
     *  <nombre_función>(<lista_argumentos>);                               */

    puts("\n\nPrimer ejemplo de función:\n");
    saluda(); // Se llama a la función saluda

    getchar();


    // ##### Argumentos de la función #####

    /* La sintaxis de la lista de argumentos cambia ligeramente entre   *
     * el prototipo y el cuerpo de la función.                          *
     * En el primero no hace falta especificar los nombres de cada      *
     * parámetro, solo se requiere de los tipos y todo nombre que se    *
     * escriba será ignorado por el compilador. Mientras tanto en el    *
     * cuerpo, siempre se debe definir tanto tipo como nombre de cada   *
     * parámetro a fin de poder referenciarlo en el código.             *
     *                                                                  *
     * Un detalle más que diferencia la lista de argumentos entre el    *
     * prototipo y el cuerpo es la declaración de una lista vacía de    *
     * parámetros: en el prototipo de función se debe usar la palabra   *
     * reservada void para indicar que una función no recibe nada,      *
     * siendo que si simplemente dejamos los paréntesis vacíos, será    *
     * interpretado por el compilador como "suprime la revisión de los  *
     * argumentos". Por su parte en la cabecera de la definición el uso *
     * de la palabra void no tiene ningún significado y será ignorada   *
     * por el compilador, con el simple hecho de dejar vacíos los       *
     * paréntesis estamos indicando que la función no recibe nada.      */

    puts("\n\nArgumentos de función:\n");

    // Prototipos de dos funciones con la misma firma, una escribe nombres
    // para los parámetros y la otra no.
    void recibe_argumentos1(int, float);
    void recibe_argumentos2(int esto_sera, float ignorado);

    { /* Bloque anónimo 1 */

        // Cuerpos de las funciones, aquí es donde se deben definir los
        // nombres de los parámetros.
        void recibe_argumentos1(int entero, float flotante)
        {
            printf("Mi primer argumento es: %d\n", entero);
            printf("Mi segundo argumento es: %f\n", flotante);
        }

        recibe_argumentos1(10, 11.1);

        // Nótese que a pesar de que en el prototipo de función de
        // 'recibe_argumentos2' los parámetros se llamaban 'esto_sera' y
        // 'ignorado' respectivamente, en el cuerpo se pueden renombrar
        // estos sin que haya ningún error.
        void recibe_argumentos2(int este_nombre_no, float sera_ignorado)
        {
            printf("Yo también recibo argumentos: %d %f\n",
                    este_nombre_no, sera_ignorado);
        }

        recibe_argumentos2(-2, 5.4);

    } /* Fin Bloque anónimo 1 */

    getchar();

    // Prototipo de función con paréntesis vacíos (no hay revisión de la
    // lista de argumentos).
    void recibe_lo_que_sea();

    // Todas las funciones a continuación son compatibles con este
    // prototipo

    { /* Bloque anónimo */

        void recibe_lo_que_sea(int a, char b, float c)
        {
            printf("He recibido: %d %c %f\n", a, b, c);
        }

        recibe_lo_que_sea(10, 'a', 5e2);

    }

    { /* Bloque anónimo */

        void recibe_lo_que_sea(double * apt, int numero)
        {
            printf("He recibido: ");

            for (int i = 0; i < numero; i++)
                printf("%lf ", apt[i]);

            putchar('\n');
        }

        recibe_lo_que_sea((double []) { 1.1, 2.2, 3.3, 4.4, 5.5 }, 5);
    }

    { /* Bloque anónimo */
        void recibe_lo_que_sea() {
            printf("No recibo nada\n");
        }

        recibe_lo_que_sea();
    }
    getchar();

    // Prototipo de función void ( no recibe nada )
    void no_recibo_nada(void);

    // Los siguientes dos cuerpos son compatibles con este prototipo:
    { /* Bloque anónimo */
        void no_recibo_nada()
        {
            printf("Literalmente no recibo nada\n");
        }

        no_recibo_nada();
    }

    { /* Bloque anónimo */
        void no_recibo_nada(void)
        {
            printf("La palabra void es ignorada en el cuerpo,\n"
                    "aunque, como ya se puede observar es de vital\n"
                    "importancia en el prototipo\n");
        }

        no_recibo_nada();
    }

    // Este último cuerpo de función no es compatible con el prototipo
    { /* Bloque anónimo */
        /*no_recibo_nada(10);*/

        /*void no_recibo_nada(int a) {*/
            /*printf("Me comentaron por tratar de romper las reglas D:\n");*/
        /*}*/
    }

    getchar();

    // ##### Valor de retorno de la función #####

    /* En principio regresar valores desde una función es algo bastante *
     * sencillo, simplemente se escribe el tipo de dato que se quiere   *
     * regresar antes del nombre de la función como se estipulaba al    *
     * hablar de los prototipos.                                        *
     * Esto es, hasta que intentamos regresar elementos más excéntricos *
     * como apuntadores a arreglos o apuntadores a función los cuales   *
     * nos hacen romper la estructura antes mentada. Se podría decir    *
     * que la estructura que se dio previamente es falsa (en realidad   *
     * es una versión simplificada) pero generalmente se ve así dado    *
     * que se puede aplicar en la gran mayoría de los casos.            *
     *                                                                  *
     * La forma general para escribir el valor de retorno de la función *
     * requiere de observar como es declarado el tipo de dato que se    *
     * pretende regresar, por ejemplo:                                  *
     *  - entero   : int <nombre_variable>                              *
     *  - flotante : float <nombre_variable>                            *
     *  - apuntador a arreglo de enteros :                              *
     *      int (*<nombre_variable>)[<tamaño_arreglo_a_apuntar>]        *
     *  - apuntador a función que no regresa ni recibe nada             *
     *      void (*<nombre_variable>)(void);                            *
     * A toda la estructura que no sea el nombre de la variable le      *
     * llamaremos 'extremidades'.                                       *
     *                                                                  *
     * En segundo lugar necesitamos separar el resto del prototipo de   *
     * función como si fuese una unidad por si sola, a la que           *
     * llamaremos simplemente 'torso'. Ejemplos:                        *
     * - función llamada 'f' que recibe un entero 'x' : f(int x)        *
     * - función llamada 'hacer_algo' que no recibe nada :              *
     *              hacer_algo(void)                                    *
     * - función llamada 'suma' que recibe un doble 'a' y un doble 'b': *
     *              suma(double a, double b)                            *
     *                                                                  *
     * Ahora para formar la función completa se debe tomar el 'torso'   *
     * sustituirlo en el lugar de <nombre_variable>  sobre la           *
     * estructura de las 'extremidades'.                                *
     *                                                                  *
     * Con eso ya tenemos nuestra cabecera de función con el valor de   *
     * retorno correcto aunque en la mayoría de los casos este método   *
     * puede dar como resultado una cabecera confundible con la         *
     * declaración de un apuntador a función. Si el resultado resulta   *
     * confuso, intente colocar unos paréntesis alrededor del 'torso'   *
     * y deje unos espacios para vislumbrar más claramente la forma.    */

    puts("\n\nValor de retorno de la función:\n");
    // Ejemplo 1: función llamada 'división' que recibe dos enteros y
    // regresa un doble.
    //
    // torso: division(int a, int b)
    //
    // extremidades : double <nombre_variable>
    //
    // Sustituyendo el torso en <nombre_variable>:
    //      double division(int a, int b)

    // Por último aplicando el resultado en el prototipo y el cuerpo
    double division(int a, int b);

    { // Bloque anónimo
        double division(int a, int b)
        {
            return (double) a / b;
        }

        printf("La división 8/6 es: %f\n", division(8, 6));

    }

    // Ejemplo 2: función llamada 'reservar_matriz' que recibe el número
    //            de filas y de columnas y regresa un apuntador a la 
    //            primera de las filas de la matriz reservada.
    //
    // torso: reservar_matriz(int filas, int columnas)
    //
    // extremidades : int (*<nombre_variable>)[columnas]
    //
    // Sustituyendo el torso en <nombre_variable>:
    //      int (*reservar_matriz(int filas, int columnas))[columnas]
    //
    // En este caso, el resultado parece un apuntador a función, para
    // aclarár las cosas vamos a añadir unos paréntesis alrededor del
    // torso:
    //      int (* (reservar_matriz(int filas, int columnas)) )[columnas]
    //
    // Como la variable "columnas" no existe realmente no se puede usar su
    // nombre en el valor de retorno, simplemente lo quitaremos y dejaremos
    // los corchetes vacíos:
    //      int (* (reservar_matriz(int filas, int columnas)) )[]

    int (* (reservar_matriz(int filas, int columnas)) )[];

    { // Bloque anónimo
        int (* (reservar_matriz(int filas, int columnas)) )[]
        {
            int (*matriz)[columnas] = calloc(filas, sizeof(*matriz));

            if ( !matriz )
                fprintf(stderr, "No se pudo reservar memoria\n");

            return matriz;
        }

        int filas = 12, columnas = 25;
        int (*matriz)[columnas] = reservar_matriz(filas, columnas);

        // Inicializando la matriz:
        for (int j = 0; j < filas; j++)
            for (int i = 0; i < columnas; i++)
                matriz[j][i] = j - i;

        // Imprimiendo la matriz
        puts("La matriz es:\n");
        for (int j = 0; j < filas; j++) {
            for (int i = 0; i < columnas; i++) {
                printf("%3d ", matriz[j][i]);
            }
            puts("\n");
        }

        // Liberando la matriz:
        free(matriz);
    }

    // Ejemplo 3: Función llamada 'obtener_adivino' que reciba un argumento
    //            numérico correspondiente a la fortuna, donde un 1
    //            representa buena fortuna cualquier otro valor representa
    //            mala fortuna.
    //            La función debe regresar un apuntador a función que no
    //            reciba argumentos y que regrese una mensaje aleatorio que
    //            con solo mensajes positivos o negativos según sea el caso.
    //
    // torso: obtener_adivino(int fortuna)
    //
    // extremidades: const char * (*<nombre_variable>)(void)
    //
    // Sustituyendo el torso en <nombre_variable> y añadiendo paréntesis
    // para evitar ambigüedad:
    //          const char * (* (obtener_adivino(int fortuna)) )(void)
    //
    const char * (* (obtener_adivino(int fortuna)) )(void);

    { // Bloque anónimo

        const char * adivino_de_la_buena_fortuna(void)
        {
            static const char * mensajes_positivos[] = {
                "Conseguirás lo que más anhelas",
                "Descubrirás lo especial que eres",
                "Conocerás a tu pareja ideal",
                "La gente empezará a valorar tu esfuerzo",
                "El éxito solo se mide en torno a los obstáculos que superas",
                "Se fuerte, pronto el universo te lo compensará",
                "No permitas que nadie te arruine el día",
                "Ser sencillo es lo que te hace grande",
                "Comienza tu día con una sonrisa",
                "Una persona positiva convierte los problemas en retos"
            };

            return mensajes_positivos[rand() % 10];
        }

        const char * adivino_de_la_mala_fortuna(void)
        {
            static const char * mensajes_negativos[] = {
                "Si la vida no te quiere, ¿para qué estas aquí?",
                "Ni que todo tu esfuerzo te fuera a salvar de la tumba",
                "¿Sabes que me sorprendería?, que digas algo inteligente",
                "Todo el mundo sabe que eres idiota, por favor deja de probarlo",
                "Este nuevo año la comida sustituirá tu cuello por otra barbilla",
                "Aún cuando pases los cursos de selección te seguirán llamando prebe",
                "La gente hablará mal de ti a tus espaldas",
                "¿Cuántas sonrisas fingiste hoy?",
                "Esa persona no se fijará nunca en ti",
                "Desaparecer no sería una mala idea sabes"
            };

            return mensajes_negativos[rand() % 10];
        }

        const char * (* (obtener_adivino(int fortuna)) )(void)
        {

            if ( fortuna == true )
                return adivino_de_la_buena_fortuna;
            else
                return adivino_de_la_mala_fortuna;
        }

        const char * (*adivino_bueno)(void) = obtener_adivino(true);

        puts("\nMensaje positivos:");
        for (int i = 0; i < 5; i++) {
            printf("\t%s", adivino_bueno());
            getchar();
        }

        const char * (*adivino_malo)(void) = obtener_adivino(false);

        puts("\nMensajes negativos:");
        for (int i = 0; i < 5; i++) {
            printf("\t%s", adivino_malo());
            getchar();
        }
    }

    getchar();

    //  ##### Especificadores de clases de almacenamiento #####

    /* Las clases de almacenamiento son atributos asignados a variables *
     * pero hay un par de ellas que son válidas también para funciones. *
     * Definen la forma en que una función es enlazada sobre el         *
     * conjunto de unidades de traducción que forman un proyecto. Estas *
     * palabras no tienen repercusión al trabajar con un solo archivo   *
     * fuente (como es el caso en este momento) por lo que solo se      *
     * explicarán sin poner ejemplos.                                   *
     *                                                                  *
     *  - extern : Clase de almacenamiento por defecto de las funciones.*
     *             No restringe el momento en que una referencia es     *
     *             enlazada con su dirección de memoria correspondiente,*
     *             es decir, que la palabra extern permite enlazado     *
     *             tanto estático como dinámico de funciones sin        *
     *             importar en que archivo se encuentren.               *
     *             Similitud con POO: función pública                   *
     *                                                                  *
     *  - static : Restringe a que los enlaces y referencias a la       *
     *             función sean enlazadas en la etapa de traducción. En *
     *             esta etapa se generan los códigos objeto de cada     *
     *             unidad por separado por lo que no es posible enlazar *
     *             funciones fuera de las mismas. En palabras simples   *
     *             la palabra static restringe la visibilidad de una    *
     *             función al archivo en que es declarada.              *
     *             Similitud con POO: función privada o interna         *
     *                                                                  *
     * La forma de colocar dichas clases de almacenamiento es añadirlas *
     * en el prototipo de una función de la siguiente manera:           *
     *  <clase_almacenamiento> <prototipo_función>                      *
     *                                                                  *
     * No es necesario usar la clase de almacenamiento también en la    *
     * definición de la función, con el prototipo basta aunque hacerlo  *
     * tampoco es un error.                                             */

    // ##### Especificadores de función #####

    /* Los especificadores de función son palabras clave orientadas     *
     * específicamente para optimizar el código correspondiente a una   *
     * función.                                                         *
     * Los especificadores de función en lenguaje C son:                *
     *                                                                  *
     *  - inline : Es una petición al compilador para que en lugar de   *
     *             tener una función en un solo lugar y llamarla        *
     *             constantemente, se hagan múltiples copias del código *
     *             de la función en donde esta es llamada para no       *
     *             desperdiciar tiempo en los constantes saltos.        *
     *             Este especificador tiene el potencial de mejorar el  *
     *             tiempo de ejecución del programa a cambio de         *
     *             sacrificar espacio. El compilador puede ignorar esta *
     *             palabra si decide que no es conveniente.             *
     *             Otro detalle sobre las funciones declaradas inline   *
     *             es que son las únicas cuyo prototipo no tiene        *
     *             visivilidad 'extern' por defecto y tenemos que       *
     *             especificarla nosotros mismos.                       *
     *                                                                  *
     *  - _Noreturn : Indica al compilador que una función nunca acaba  *
     *             su función con normalidad (tal vez por que dicha     *
     *             función llama a exit() o a longjmp()), información   *
     *             que le sirve al compilador para generar algunas      *
     *             optimizaciones. En caso de que una función _Noreturn *
     *             retorne, se produce un comportamiento indefinido.    */

    puts("\n\nEspecificadores de función:\n");

    extern void funcion_en_linea(void); // Se usa extern por que las funciones
                                        // inline no lo son por defecto.

    { /* Bloque anónimo */

        inline void funcion_en_linea(void)
        {
            puts("Si el compilador decide aceptar la petición 'inline'\n"
                 "entonces se generará una copia de mi código cada\n"
                 "vez que me manden a llamar\n");
        }

        funcion_en_linea();
    }


    _Noreturn void funcion_que_nunca_continua(void)
    {
        puts("Esta función está marcada con _Noreturn\n"
             "Lo cual le indica al compilador que esta función\n"
             "termina por algún otro medio, en este caso ese medio\n"
             "es la función exit() que termina el programa\n");

        exit(EXIT_SUCCESS);
    }

    funcion_que_nunca_continua();   // Bye byte

    return EXIT_FAILURE;
}
