/*==========================================================*
 * Lista de las palabras reservadas en lenguaje C ordenadas *
 * por categorias.                                          *
 *==========================================================*/

/* Sentencias de control */
while
for
do
switch
case
if
else
    /* Control no estructurado */
    break
    continue
    goto
    default
    return

/* Operadores */
_Alignof
sizeof
_Static_assert

/* Tipos de datos */
void
int
float
double
_Bool
_Imaginary
_Complex
char
    /* Modificadores de longitud */
    short
    long
    _Alignas
    signed
    unsigned
        /* Modificadores de tipo */
        volatile
        const
        restrict
        _Atomic
        /* Modificadores de almacenamiento */
        auto
        register
        static
        extern

/* Tipos definidos por el programador */
struct
enum
union
    typedef

/* Modificadores de función */
inline
_Noreturn
_Thread_local

/* Macros predefinidas */
__FILE__
__LINE__
__DATE__
__TIME__
__STDC__
__STDC_VERSION__
__func__

/* Manejo de macros */
_Generic
__VA_ARGS__

/* Macros que pueden o no estar definidas */
__STDC_HOSTED__
__cplusplus
__OBJC__
__ASSEMBLER__

/* Extensiones de GCC no estandar */
    /* Tipos de datos */
    __int128
    __float128
    _Decimal32
    _Decimal64
    _Decimal128
    __complex__
        /* Modificadores de tipo */
        _Fract
        _Acum
        _Sat
        /* Modificadores de visibilidad */
        __label__
        _thread

    /* Indicaciones al compilador */
    __attribute__
    __atomic
    __asm__
    asm

    /* Operadores */
    typeof o __typeof__
    __real__
    __imag__
    _auto_type