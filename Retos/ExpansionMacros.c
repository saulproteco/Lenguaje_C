
#include <stdio.h>

#define RADIANES_A_GRADOS(rad) (rad * 180 / 3.14169265)

int main(void)
{
    printf("%f\n", RADIANES_A_GRADOS(10 + 1));
}
