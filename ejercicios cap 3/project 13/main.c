#include <stdio.h>
#include <stdlib.h>

/* Fibonacci.
El programa calcula y escribe los primeros 50 n�meros de Fibonacci.

I: variable de tipo entero utilizada como contador.
PRI: primer n�mero de Fibonacci (0).
SEG: segundo n�mero de Fibonacci (1).
SIG: variable para almacenar el siguiente n�mero de Fibonacci. */

void main(void)  // Funci�n principal del programa.
{
    int I, PRI = 0, SEG = 1, SIG;  // Inicializaci�n de las variables.

    // Imprime los dos primeros n�meros de la serie de Fibonacci.
    printf("\t%d\t%d", PRI, SEG);

    // Bucle para calcular los siguientes 48 n�meros de Fibonacci (total 50).
    for (I = 3; I <= 50; I++)
    {
        SIG = PRI + SEG;  // Calcula el siguiente n�mero en la serie.
        PRI = SEG;       // Actualiza PRI al segundo n�mero.
        SEG = SIG;       // Actualiza SEG al nuevo n�mero calculado.

        printf("\t%d", SIG);  // Imprime el siguiente n�mero de Fibonacci.
    }

    printf("\n");  // A�ade un salto de l�nea al final para una mejor legibilidad.
}
