#include <stdio.h>
#include <stdlib.h>

/* Fibonacci.
El programa calcula y escribe los primeros 50 números de Fibonacci.

I: variable de tipo entero utilizada como contador.
PRI: primer número de Fibonacci (0).
SEG: segundo número de Fibonacci (1).
SIG: variable para almacenar el siguiente número de Fibonacci. */

void main(void)  // Función principal del programa.
{
    int I, PRI = 0, SEG = 1, SIG;  // Inicialización de las variables.

    // Imprime los dos primeros números de la serie de Fibonacci.
    printf("\t%d\t%d", PRI, SEG);

    // Bucle para calcular los siguientes 48 números de Fibonacci (total 50).
    for (I = 3; I <= 50; I++)
    {
        SIG = PRI + SEG;  // Calcula el siguiente número en la serie.
        PRI = SEG;       // Actualiza PRI al segundo número.
        SEG = SIG;       // Actualiza SEG al nuevo número calculado.

        printf("\t%d", SIG);  // Imprime el siguiente número de Fibonacci.
    }

    printf("\n");  // Añade un salto de línea al final para una mejor legibilidad.
}
