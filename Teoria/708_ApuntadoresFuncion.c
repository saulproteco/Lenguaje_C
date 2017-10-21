/*================================================*
 * Conceptos para el uso de apuntadores a funciOn
 * en lenguaje C                                  *
 *================================================*/

/* El siguiente cOdigo hace uso extensivo de una caracterIstica especIfica *
 * de GNU-C (funciones anidadas) con fines de que la lectura sea           *
 * estructurada y no se tenga que alternar eltre el flujo de cOdigo y      *
 * el lugar en que estAn declaradas las funciones. Tomen en cuenta que     *
 * no se trata de una caracterIstica portable a ningUn otro compilador de  *
 * C                                                                       */

#include <stdio.h>

int main(int argc, char *argv[])
{

    /* ##### DECLARACION Y USO BASICO ##### */
    // Los apuntadores a funciones son variables que se declaran
    // de manera similar a como escribimos un prototipo de funciOn.
    // La diferencia es la necesidad de poner el nombre de la variable
    // entre parEntesis y antecedida de un asterisco que indica que
    // dicha variable es de tipo apuntador (a funciOn).

    int funcion(int x) // Una funciOn llamada 'funcion'
    {
        return -x + 5;
    };

    int funcion2(int x, double y) // funcion2 recibe dos arguemtos
    {
        return x + (int)y;
    }

    // Tal como en el prototipo de funciOn, no tiene ningUn fin especificar
    // los nombre asociados a la lista de argumentos puesto que el
    // compilador los ignora. Sin embargo se pueden poner con fines
    // documentativos.
    int (*apuntador_funcion)(int x); // Un apuntador a funciOn int -> int
    int (*apuntador_funcion2)(int, double); // Un apuntador int, double -> int

    apuntador_funcion = funcion; // Al primer apuntador le asignamos la
                                 // direcciOn de memoria de la funciOn
                                 // 'funcion'
    // Los nombres de las funciones son un apuntador a la primera de
    // sus instrucciones, luego entonces no es necesario usar el
    // operador de referencia (&) para obtener su direcciOn. No obstante
    // usarlo en general no deberia de ser un error.
    apuntador_funcion2 = &funcion2;

    // Por la misma razOn (un nombre de funciOn ya es un apuntador), no
    // es necesario usar el operador de desreferencia (*) al llamar a
    // la funciOn mediante un apuntador a esta. Nuevamente, usarlo no
    // representa un error y en un par de ocaciones si serA necesario.
    // Dada la presedencia de operadores, el asterisco tiene que ir
    // encerrado entre parEntesis junto al nombre de la funciOn.

    printf("El resultado de llamar la funciOn 1: %d\n",
            apuntador_funcion(10)); // Sin usar asterisco

    printf("El resultado de llamar la funciOn 2: %d\n",
            (*apuntador_funcion2)(10, 5.5)); // Usando asterisco

    getchar();

    /* ##### RECORDANDO EL SIGNIFICADO DE LOS PROTOTIPOS ##### */

    // Aunque en general no tiene ningUn sentido, se puede convertir
    // la referencia de una funciOn con cierto prototipo a una referencia
    // con otro prototipo tal como se puede hacer conversiones entre
    // diferentes tipos de apuntadores.

    // Se castea una funcion "int, double -> int" a una funciOn "int -> int"
    apuntador_funcion = (int (*)(int))funcion2;

    // Se castea una funciOn "int -> int" a una funciOn "int, double -> int"
    apuntador_funcion2 = (int (*)(int, double)) funcion;

    // Las llamadas se harAn pero pueden resultar en errores. El compilador
    // se basa en los prototipos para revisar la lIsta de argumentos.
    apuntador_funcion(10);
    apuntador_funcion2(4, 4.4);

    getchar();

    // Igual que pasa con los prototipos de funciOn, cuando especificamos
    // una lista de argumentos vacIa le indicamos al compilador que no
    // haga revisiOn de la lista de argumentos por lo que con ello podemos
    // hacer un apuntador a funcioens de cualquier nUmero de argumentos.

    int (*cualquier_argumento)() = main; // Main recibe 2 argumentos, sin
                                         // embargo la lista vacIa desactiva
                                         // la revisiOn por parte del
                                         // compilador

    // Las siguientes llamadas no causan error de compilaciOn aunque
    // se comentan por que causan recursividad infinita.
    /*cualquier_argumento("Pepe"); // Se le mandan menos argumentos*/
    /*cualquier_argumento(5.5, 4.4, 3.3, 2.2, 1.1); // Se le mandan mas argumentos*/
    /*cualquier_argumento("argc", "argv"); // NUmero correcto de argumentos pero los tipos son incorrectos*/
    /*cualquier_argumento(2, (char *[]) { "San", "Chrisostomo" });  // Esta es la Unica llamada correcta*/

    getchar();

    // Tal como se puede observar, poner la lista de argumentos vacIa es
    // comodo pero potencialmente peligroso. Es recomendable siempre
    // especificar la lista completa de argumentos. Recordando una vez
    // mAs el funcionamiento de los prototipos de funciOn, si queremos
    // especificar que una funciOn no recibe argumentos escribimos
    // entre parEntesis la palabra reservada 'void'.

    void funcion_sin_argumentos(void)
    {
        printf("No recibo nada\n");
    }

    void (*sin_argumentos)(void) = funcion_sin_argumentos;

    //funcion_sin_argumentos(10); // Si descomentas esto hay error

    funcion_sin_argumentos();

    /* ##### ARREGLOS DE FUNCIONES ##### */
    // Como en el caso de cualquier otra variable, los apuntadores
    // a funciOn pueden agruparse en un arreglo.
    // Por cuestiones de precedencia, vuelve a ser necesario que los
    // corchetes que especifican el tamanio del arreglo se escriben
    // entre parEntesis al lado derecho del identificador del arreglo.

    void f1(void) { printf("Soy la función uno\n"); }
    void f2(void) { printf("Soy la función dos\n"); }
    void f3(void) { printf("Soy la función tres\n"); }
    void f4(void) { printf("Soy la función cuatro\n"); }
    void f5(void) { printf("Soy la función cinco\n"); }

    void (*arreglo_funciones[5])(void) = { f1, f2, f3, f4, f5 };

    printf("Recorriendo el arreglo de funciones para llamar a cada una\n");

    for (int i = 0; i < 5; i++) {
        printf("Llamando a la funciOn %d\n", i);
        // Los parEntesis son necesarios por la precedencia del corchete
        (arreglo_funciones[i])();
    }

    /* ##### USO COMO PARAMETRO / VALOR DE RETORNO ##### */
    // Como los apuntadores a funciones son variables al final del dIa
    // es posible usarlos como argumentos y tambiEn como valores de
    // retorno en funciones.

    void argumento() { printf("Soy un argumento para otra función\n"); }

    void recibe_apuntador_funcion(void (*funapt)(void)) {
        printf("Llamando a la función recibida: \n");

        funapt();
    }

    recibe_apuntador_funcion(argumento);

    getchar();

    // FunciOn que regresa una funciOn que regresa una funciOn que
    // regresa una funciOn que regresa un entero.

    int regresa_entero(int a)
    {
        return 10 * a;
    }

    int (*regresa_funcion_que_regresa_entero(void))(int)
    {
        return regresa_entero;
    }


    int (*(*regresa_funcion_que_regresa_funcion_que_regresa_entero(void))(void))(int)
    {
        return regresa_funcion_que_regresa_entero;
    }

    int (*(*(*regresa_funcion_que_regresa_funcion_que_regresa_funcion_que_regresa_entero(void))(void))(void))(int)
    {
        return regresa_funcion_que_regresa_funcion_que_regresa_entero;
    }

    printf("Obteniendo el entero: %d",
        // WTFFFFF??????? Tengan piedad y jamAs hagan esto.
        regresa_funcion_que_regresa_funcion_que_regresa_funcion_que_regresa_entero()()()(5)
    );

    getchar();

    int (*(*(*esto(int x))(int))(int))(int)
    {
        int (*(*no(int y))(int))(int)
        {
            int (*tiene(int z))(int)
            {
                int sentido(int w) {
                    return x * y * z * w;
                }

                return sentido;
            }

            return tiene;
        }

        return no;
    }

    // La sintaxis anterior es similar a la forma de una clausura (closure)
    // en otros lenguajes de programaciOn, sin embargo en C no se puede
    // aplicar lOgica similar (¿¿o si se puede???, revisar el proyecto titulado
    // C99-Lambda en github del usuario Leushenko)
    // por lo que la funciOn siguiente no tendrA un resultado previsible.
    printf("Llamando consecutivamente a las funciones D: es: %d\n",
            esto(2)(3)(4)(5));

    /* ##### ALIAS DE PROTOTIPOS DE FUNCION #####*/
    // Una sentencia similar a la de un prototipo de funciOn o declaraciOn
    // de un apuntador a funciOn pero precedido de la palabra typedef
    // funge como la declaraciOn de un alias de un prototipo o de un
    // tipo de apuntador a funciOn respectivamente.

    // 'alias_prototipo' es un alias para el prototipo de funciones que reciben
    // un entero y que regresan entero.
    typedef int alias_prototipo(int);

    // 'alias_apuntador_funcion' es un alias para el tipo de dato que apuntador
    // que apunta a funcioens que reciben un entero y que regresan un entero.
    typedef int (*alias_apuntador_funcion)(int);

    // Lo siguiente es equivalente a definir dos prototipos:
    //  int funcion_1(int);
    //  int funcion_2(int);
    alias_prototipo funcion_1, funcion_2;

    // Lo siguiente es equivalente a declarar un apuntador a funcion
    // y un arreglo de apuntadores a funcione.
    //  int (*apt_funcion)(int);
    //  int (*arreglo_apt_funcion[2])(int);
    alias_prototipo *apt_funcion, *arreglo_apt_funcion[2];

    // tambien se pueden declarar apundadores a funciOn y arreglos a los
    // mismos mediante alias_apuntador_funcion.
    alias_apuntador_funcion apt_funcion2, arreglo_apt_funcion2[5];
    return 0;
}
