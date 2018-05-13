/*========================================*
 * Especificadores de formato de salida C *
 *========================================*/

/**
 * Autor: Martínez Ortíz Saúl Axel
 * Dificultad: Intermedio.
 * Requisitos: Bases del lenguaje C.
 * Estilo de código: Microsoft.
 */

#include <stdio.h>  // printf, scanf, getchar
#include <stdlib.h> // EXIT_SUCCESS

/* En la labor de darle cierta apariencia u orden a nuestros resultados *
 * nos encontramos con los especificadores de conversión o de formato,  *
 * los cuales nos proveen de una sintaxis concisa para hacer            *
 * manipulaciones a la representación textual de los tipos básicos.     *
 *                                                                      *
 * Los especificadores de formato aparecen enmedio de una cadena de     *
 * caracteres y tienen el siguiente siguiente formato:                  *
 *      %[modificador]*[ancho|\*]?(\.[precisión|\*])?[indicador_tipo]   *
 *                                                                      *
 *     --no confundir el asterisco suelto que representa "una o mas     *
 *     veces" con el asterisco escapado que representa el carácter      *
 *     literal--                                                        *
 *                                                                      *
 * De donde:                                                            *
 *  - % =>  Carácter especial que indica el comienzo del especificador. *
 *          En caso de que se requiera poner un signo de porcentaje     *
 *          literal sobre la cadena basta con repetir el símbolo dos    *
 *          veces.                                                      *
 *                                                                      *
 * - [modificador] => Un carácter que funge el papel de bandera para    *
 *          alterar de algún modo la cadena resultante.                 *
 *                  ¬ + (signo más) => Siempre mostrar signo.           *
 *                  ¬   (espacio)   => Dejar un espacio en positivos.   *
 *                  ¬ 0 (cero)      => Rellenar un número con ceros.    *
 *                  ¬ # (numeral)   => Usar representación alternativa. *
 *                  ¬ - (menos)     => Justificar a la izquierda.       *
 *          La expresión regular de los especificadores nos indica que  *
 *          puede haber más de un carácter modificador y estos pueden   *
 *          encontrarse en cualquier orden además de que puede          *
 *          repetirse el mismo modificador varias veces, caso en el que *
 *          el resultado se comportará de la misma forma que si dicho   *
 *          modificador hubiera aparecido una sola vez.                 *
 *          No todos los modificadores se aplican a todos los tipos     *
 *          básicos y aunque no ocurre un error si usas un modificador  *
 *          en un dato inválido si puede generar un par de advertencias *
 *          por parte del compilador. Además, hay ocasiones en que      *
 *          tiene más sentido usarlos en cierto orden que en otro.      *
 *          Algunos de estos modificadores son mutuamente excluyentes:  *
 *          el signo '+' hace que se ignore el espacio y el signo '-'   *
 *          hace que se ignore el '0'.                                  *
 *                                                                      *
 * - [ancho] => Un número indicando la cantidad de caracteres mínimos   *
 *          que tiene que ocupar a la salida la representación del      *
 *          dato. Si dicha representación por si sola ocupaba una       *
 *          longitud mayor que el ancho no se altera el comportamiento  *
 *          pero en caso de que no pudiera cubrir el ancho se colocará  *
 *          relleno hasta cubrir el ancho. Este valor depende de dos    *
 *          banderas: la bandera '-' cambia el lado al que se acomoda   *
 *          el relleno de izquierda (por defecto) a derecha, mientras   *
 *          que '0' cambia el carácter de relleno de ' ' (espacio)      *
 *          a cero.                                                     *
 *          La expresión regular indica que este valor es opcional, en  *
 *          caso de no ponerlo se comportará como si el ancho mínimo    *
 *          fuese 0.                                                    *
 *          En caso de que en lugar de un número se especifica un       *
 *          asterisco el ancho será definido por una variable entera    *
 *          que tiene que aparecer justo antes del valor a imprimir.    *
 *                                                                      *
 * - (\.[precisión]) => Un punto seguido de otro entero se interpreta   *
 *          como la precisión de la representación. Dicha precisión     *
 *          tiene un significado distinto dependiendo del tipo de dato  *
 *          en que se esté usando. El uso más común de este dato es     *
 *          indicar el número de decimales que queremos imprimir de un  *
 *          valor de punto flotante.                                    *
 *          El único modificador que afecta el significado de la        *
 *          precisión es el numeral (#).                                *
 *          Nuevamente se trata de un apartado opcional.                *
 *          Si en lugar de un número se especifica un asterisco el      *
 *          ancho se determinará con una variable que debe aparecer     *
 *          antes del valor a imprimir.                                 *
 *                                                                      *
 * - [indicador_tipo] => Uno o varios caracteres que sirven para        *
 *          identificar el tipo de variable que se va a convertir y con *
 *          ello identificar el comportamiento deseado para todos los   *
 *          demás atributos.                                            *
 *          A continuación la lista de indicadores de tipo el tipo al   *
 *          que pertenecen:                                             *
 *                  ¬ c => signed char y unsigned char (caracteres)     *
 *                  ¬ s => char * y unsigned char *                     *
 *                  ¬ d => int (formato decimal)                        *
 *                      ¬ hd  => short int                              *
 *                      ¬ ld  => long int                               *
 *                      ¬ lld => long long int                          *
 *                  ¬ u => unsigned (formato decimal)                   *
 *                      ¬ hu  => short unsigned                         *
 *                      ¬ lu  => long unsigned                          *
 *                      ¬ llu => long long unsigned                     *
 *                      ¬ zu  => size_t                                 *
 *                  ¬ o => unsigned (formato octal)                     *
 *                  ¬ x => unsigned (formato hexadecimal minuscula)     *
 *                  ¬ X => unsigned (formato hexadecimal mayuscula)     *
 *                  ¬ p => void * (formato hexadecimal minúscula)       *
 *                  ¬ f, lf => double (decimal expandido)               *
 *                      ¬ Lf => long double                             *
 *                  ¬ e, le => double (decimal exponencial minuscula)   *
 *                      ¬ Le => long double                             *
 *                  ¬ E, lE => double (decimal exponencial mayuscula)   *
 *                      ¬ LE => long double                             *
 *                  ¬ g, lg => double (elige entre f o e según convenga)*
 *                      ¬ Lg => long double                             *
 *                  ¬ G, lG => double (elige entre f o E según convenga)*
 *                      ¬ LG => long double                             *
 *                                                                      *
 * Nota: En la lectura con formato se distingue entre las secuencias    *
 * 'f', 'e', 'g' con respecto a sus analogas 'lf', 'le' y 'lg' por que  *
 * las primeras trabajan con tipos 'float' mientras que las segundas lo *
 * hacen con 'double'.                                                  *
 * Esto no es válido, sin embargo cuando hacemos impresión con formato  *
 * puesto que en funciones con argumentos variables, todos los 'float'  *
 * son promovidos a 'double'. En este tipo de dato en específico, las   *
 * versiones sin 'l' significan lo mismo que las versiones con dicha    *
 * letra.                                                               */

int main(void)
{
    /* Los especificadores de formato para la salida se pueden usar con *
     * una variedad de funciones, todas con una 'f' de "formato" en el  *
     * nombre, cada una recibiendo la cadena de formato enmedio de la   *
     * cual habrá incrustados los especificadores a modo de 'aparta     *
     * lugares' (del inglés "placeholder") los cuales serán expandidos  *
     * con los argumentos extra de la función.                          *
     * Cada una de las funciones trabaja sobre una salida distinta:     *
     *  - printf -> Manda el resultado a la salida estándar.            *
     *  - fprintf -> Manda el resultado a un archivo.                   *
     *  - sprintf -> Manda el resultado a un arreglo de caracteres.     *
     *                                                                  *
     * El comportamiento es idéntico sin importar la salida por lo que  *
     * en los ejemplos solamente estaremos usando "printf" de modo que  *
     * observemos los resultados en pantalla. De igual forma, el        *
     * comportamiento de todos los especificadores que trabajan con     *
     * enteros decimales signados se comportan igual a excepción del    *
     * rango válido por lo que no haremos ejemplos de cada tipo de      *
     * forma individual.                                                */

    // Nota: Se usaran las secuencias de caracteres "<[" y "]>" para
    // representar inicio y final de la impresión con formato
    // respectivamente. Esto se hace para poder visualizar el relleno.

    // Impresión de caracteres:
    //  El único modificador válido es el signo de menos (para cambiar la
    //  dirección en que se justifica). El ancho funciona normalmente y
    //  la precisión no tiene significado:
    puts("\n\n========== Impresión de caracteres ==========\n\n");

    puts("Caracteres sueltos:");
    printf(" <[%c]>\n", 'a');          // Solo ocupa un espacio
    printf(" <[%25c]>\n", 'b');        // Ocupa 25 espacios con relleno a la izquierda
    printf(" <[%-10c]>\n", 'c');       // Ocupa 10 espacios con relleno a la derecha

    int largo, precision;
    printf("Indique una longitud para los siguientes caracteres: ");
    scanf("\n%d", &largo);

    printf(" <[%*c]\n", largo, 'd');    // Ocupa el espacio especificado
    printf(" <[%-*c]\n", largo, 'e');   // por el usuario

    getchar(); getchar();

    // Impresión de cadenas:
    //  El único modificador válido sigue siendo '-'.
    //  El significado del ancho es tomado como longitud mínima.
    //  La precisión en cambio, significa que una palabra debe
    //  cortarse hasta tener como máximo, el valor especificado.
    puts("Secuencias de caracteres:");
    printf(" <[%s]>\n", "solen'ya");       // Ocupa los caracteres justos
    printf(" <[%10s]>\n", "palabra");      // Ocupa al menos 10 espacios
    printf(" <[%-10s]>\n", "mencion");
    printf(" <[%.5s]>\n", "sentencia");  // Solo se muestran 5 caracteres
    printf(" <[%10.5s]>\n", "sentencia");// Se muestran 5 caracteres que
                                         // ocupan 10 espacios

    printf("Indique cuantas letras de \"Que agradable día\" "
            "quiere ver: ");
    scanf("%d", &largo);

    printf(" <[%.*s]>\n", largo, "Que agradable día");

    getchar(); getchar();

    // Impresión de enteros decimales signados:
    //  Todos los modificadores son válidos a excepción del numeral (#).
    //  El ancho funciona normalmente y la precisión tiene el mismo
    //  significado que usar conjuntamente la bandea '0' y el [ancho] con
    //  la excepción de que la especificar una precisión hace que la bandera
    //  '-' sea ignorada mientras que si usas '0' junto con un ancho lo que
    //  se ignora es la bandera '0'.
    puts("\n\n========== Impresión de enteros ==========\n\n");

    puts("\nProbando el ancho");
    printf(" <[%d]>\n", 123);          // Ocupa su longitud normal
    printf(" <[%9d]>\n", 456);         // Ocupa al menos 9 caracteres con relleno a la izquierda
    printf(" <[%-9d]>\n", 789);        // Ocupa al menos 9 caracteres con relleno a la derecha
    printf(" <[%-9d]>\n", (int) 1e9);  // Lo mismo que el anterior con la diferencia de que
                                       // este número se pasa del ancho mínimo.
    printf("Indique el largo del siguiente número: ");
    scanf("%d", &largo);
    printf(" <[%*d]>\n", largo, 100);
    printf(" <[%-*d]>\n", largo, 100);

    getchar(); getchar();

    puts("\nImprimir o no imprimir signo");
    puts("No alineados");
    printf(" <[%d]>\n", -10);           // Los primeros dos solo imprimen el signo menos
    printf(" <[%d]>\n", +10);
    puts("Alineados");
    printf(" <[%+d]>\n", -15);          // Los siguientes imprimen ambos signos lo
    printf(" <[%+d]>\n", +15);          // lo cual permite alinear valores

    getchar();

    puts("\nImprimir espacio en vez de signo");
    puts("No alineados");
    printf(" <[%d]>\n", -10);           // Funciona como la bandera '+' completando
    printf(" <[%d]>\n", +10);           // con un carácter para alinear positivos
    puts("Alineados");
    printf(" <[% d]>\n", -15);          // y negativos, con la diferencia de que
    printf(" <[% d]>\n", +15);          // a los positivos les pone espacio en lugar de '+'.

    getchar();

    puts("\nRellenar con ceros en lugar de espacios");
    // Por obvias razones se requiere especificar un acho de modo que
    // se requiera relleno.

    puts("Sin bandera '+'");
    printf(" <[%010d]>\n", +99);        // No se confunde entre la bandera '0'
    printf(" <[%010d]>\n", -99);        // y el ancho porque el segundo debe
    puts("Con bandera '+'");            // ir siempre después de la primera.
    printf(" <[%+010d]>\n", +99);
    printf(" <[%+010d]>\n", -99);

    getchar();

    puts("\nProbando la precisión");
    puts("Solo precisión");
    printf(" <[%.10d]>\n", +987);        // Usando la precisión se obtienen un
    printf(" <[%.10d]>\n", -987);        // relleno de '0' a la izquierda
    printf(" <[%+.10d]>\n", +987);       // hasta completar la longitud
    printf(" <[%+.10d]>\n", -987);       // especificada.
    puts("Precisión y ancho");
    printf(" <[%15.10d]>\n", +987);        // La diferencia es que usando precisión
    printf(" <[%15.10d]>\n", -987);        // más ancho se puede obtener un
    printf(" <[%+15.10d]>\n", +987);       // relleno en parte de ceros y en parte
    printf(" <[%+15.10d]>\n", -987);       // de espacios.

    getchar();

    // Impresión de enteros decimales no signados:
    //  Solo el modificador '0' y el '-' son válidos.
    //  El ancho y la precisión funcionan de manera idéntica a los enteros
    //  signados.
    //  Aparte de nunca imprimir signos, la gran diferencia que tiene la
    //  impresión de los enteros sin signo es que si le pasas un número
    //  negativo lo representará como un número positivo muy grande

    puts("\nMandando negativos a la impresión de enteros sin signo");
    printf(" <[%u]>\n", -99999); // El resultado aparecerá como un
    printf(" <[%u]>\n", -666);   // positivo de gran tamaño.
    printf(" <[%u]>\n", -1);

    getchar();

    // Impresión de enteros octales (solo se pueden imprimir no signados):
    //  Los modificadores '#', '0' y '-' son válidos.
    //  El modificador numeral sirve para añadir al principio del número
    //  un 0 que haga de indicador de que se trata de un número octal. A
    //  diferencia del modificador '0', '#' se puede usar con números
    //  justificados a la izquierda.
    //  El '0' hace que se rellene con ceros el número a su izquierda
    //  dependiendo del valor del ancho.
    //  El ancho y la precisión nuevamente funcionan como en los enteros.

    puts("\nImprimiendo números octales");
    printf(" <[%10o]>\n", 5555);
    printf(" <[%10o]>\n", 05555);
    printf(" <[%#10o]>\n", 01532);
    printf(" <[%010o]>\n", 03333);
    printf(" <[%-#10o]>\n", 03423);

    getchar();

    // Impresión de enteros hexadecimales (solo no signados):
    //  Los modificadores '#', '0' y '-' son válidos.
    //  El modificador numeral añade un "0x" al principio del número para
    //  indicar que se trata de un hexadecimal.
    //  El '0' hace que se rellene con ceros la parte izquierda del número
    //  después del "0x" en caso de que se active la bandera '#'.
    //  En esta ocasión la precisión no es un equivalente de las banderas
    //  '0' más el ancho si se usa la bandera numeral. Si se especifica
    //  ancho más la bandera '0' la secuencia "0x" se contabiliza en el
    //  ancho mientras que cuando se especifica el punto y la precisión
    //  el "0x" no se contabiliza en el ancho.
    puts("\nImprimiendo números hexadecimales");
    printf(" <[%10x]\n", 0xAAAA);
    printf(" <[%010x]\n", 0xBBBB);
    printf(" <[%#010X]\n", 0x159D);
    printf(" <[%#.10x]\n", 0x26AE); // Los dos últimos serán mas largos
    printf(" <[%#.10X]\n", 0x37BF); // por que "0x" no se contabiliza en
                                    // la longitud.

    printf("Indique largo y precisión del siguiente número: ");
    scanf("%d %d", &largo, &precision);

    printf("%*.*X\n", largo, precision, 0xABCD);

    getchar(); getchar();

    puts("\n\n========== Impresión de números de punto flotante  ==========\n\n");

    // Impresión en formato expandido (%f):
    //  Todos los modificadores son válidos en la impresión de con %f
    //  El modificador numeral cambia el comportamiento de la precisión cero
    //  asegurándose de que se imprima siempre un punto decimal.
    //  El modificador '+', ' ', '0' y '-' funcionan de manera idéntica a los
    //  enteros, no se pondrá mucho empeño en los ejemplos.
    //  Cabe aclarar que al especificar la longitud se toma en cuenta el
    //  número completo (contando puntos y decimales).
    //  La precisión indica el número de decimales a imprimir.
    puts("\nImprimiendo en formato expandido");
    printf(" <[%f]>\n", -5.5);   // Imprime sin relleno y con 5 decimales
    printf(" <[%.2f]>\n", 7.2);  // Imprime sin relleno y sin decimales
    printf(" <[%8.2f]>\n", -2.1);// Rellena hasta completar 8 caracteres
    printf(" <[%-8.2f]>\n", 2.1);// Rellena hasta completar 8 caracteres
    printf(" <[%.f]>\n", 10.5);  // Imprime número sin decimales
    printf(" <[%#+.f]>\n", 10.5);// Siempre imprime tanto signo como punto
                                 // decimal
    printf(" <[% .f]>\n", 1e2);  // Si el número positivo imprime un espacio


    // Impresión en formato exponencial (%e):
    //  Los modificadores hacen exactamente lo mismo que en el formato
    //  no expandido. El número de decimales especificados se aplican
    //  a la base.
    puts("\nImprimiendo en formato exponencial");
    printf(" <[%10.2e]>\n", 100.0); // Rellena hasta 10 caracteres con 2 decimales
    printf(" <[%10.2E]>\n", 100.0); // Usa la letra 'E' mayúscula
    printf(" <[%#.E]>\n", 40.5);    // No imprime decimales pero si el punto

    getchar();

    // Impresión de flotantes "inteligente" (%g):
    //  Este tipo de impresión es la mas rara de todas. Se trata de un
    //  especificador que elige entre las dos representaciones anteriormente
    //  mencionadas. Cuando los números son pequeños, se imprime como si se
    //  tratara de %f y cuando son grandes se imprime como con %e.
    //  Por otro lado, cuando se especifica la precisión mediante %g
    //  esta no representa el número de decimales a imprimir, sino la
    //  cantidad de valores que usar en la base (cuyo mínimo es uno y su
    //  valor por defecto es 6). Si en la cantidad de valores especificada
    //  no caben todos los enteros y decimales estos se redondearán para
    //  que aparezcan solo los enteros, en caso de que la cantidad no sea
    //  suficiente para los enteros se forzara a imprimir el formato
    //  exponencial.
    puts("\nImprimiendo en formato inteligente");
    printf(" <[%g]>\n", -123.456);  // La impresión con %g solo muestra los
    printf(" <[%g]>\n", 5.45);      // decimales necesarios.
    printf(" <[%10.1g]>\n", 5.456); // Solo se va a imprimir un dígito en la base
    printf(" <[%10.1g]>\n", 545.6); // si ese dígito no alcanza para los enteros
                                    // entonces se forzará a que el número se
                                    // imprima en formato exponencial

    printf(" <[%20g]>\n", -8.88e+8);  // Con números muy grandes o muy
    printf(" <[%-20g]>\n", 8.88e-8);  // pequeños usa el formato exponencial.

    getchar();

    return EXIT_SUCCESS;
}
