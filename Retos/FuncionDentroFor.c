/*==============================================*
 * Explique el siguiente código y que conceptos *
 * implica. Posteriormente simplifiquelo.       *
 *==============================================*/

#include <stdio.h>

int main(void)
{
    for (int i = 0;
            !({
            _Bool es10(int x)
            {
                if ( x == 10 )
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            } es10; })(i);
        i++)
    {
        printf("i es: %d\n", i);
    }

    return 0;
}
