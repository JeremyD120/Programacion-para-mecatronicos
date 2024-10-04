#include <stdio.h>
#include <stdlib.h>

int cubo (int);

void main (void)

{
    int I;
    for (I = 1; I <= 10; I++)
        printf("\nEl cubo de I es: %d",cubo (I));
}
int cubo (int k)
{
    return (k*k*k);
}
