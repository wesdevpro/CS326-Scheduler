#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;

    for(i = 1; i <= 360; i++)
    {
        printf("\n%d,", (int) rand());
    }
    return 0;
}
