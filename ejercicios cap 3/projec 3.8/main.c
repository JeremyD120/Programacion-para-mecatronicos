#include <stdio.h>
#include <stdlib.h>

/* Factorial.
El programa calcula el factorial de un n�mero entero positivo.

FAC, I, NUM: variables de tipo entero. */

void main(void)  // Funci�n principal del programa.
{
    int I, NUM;      // I es un contador para el bucle, NUM es el n�mero ingresado.
    long FAC;        // FAC almacenar� el valor del factorial calculado.

    printf("\nIngrese el numero: ");
    scanf("%d", &NUM);  // Se solicita al usuario que ingrese un n�mero entero.

    if (NUM >= 0)  // Condici�n para verificar que el n�mero ingresado sea no negativo.
    {
        FAC = 1;  // Inicializaci�n del factorial en 1.

        for (I = 1; I <= NUM; I++)  // Bucle para calcular el factorial.
        {
            FAC *= I;  // Se multiplica FAC por el contador I en cada iteraci�n.
        }

        printf("\nEl factorial de %d es: %ld", NUM, FAC);  // Se muestra el resultado del factorial.
    }
    else
    {
        printf("\nError en el dato ingresado");  // Mensaje de error si el n�mero es negativo.
    }
}
