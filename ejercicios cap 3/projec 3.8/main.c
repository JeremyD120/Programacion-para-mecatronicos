#include <stdio.h>
#include <stdlib.h>

/* Factorial.
El programa calcula el factorial de un número entero positivo.

FAC, I, NUM: variables de tipo entero. */

void main(void)  // Función principal del programa.
{
    int I, NUM;      // I es un contador para el bucle, NUM es el número ingresado.
    long FAC;        // FAC almacenará el valor del factorial calculado.

    printf("\nIngrese el numero: ");
    scanf("%d", &NUM);  // Se solicita al usuario que ingrese un número entero.

    if (NUM >= 0)  // Condición para verificar que el número ingresado sea no negativo.
    {
        FAC = 1;  // Inicialización del factorial en 1.

        for (I = 1; I <= NUM; I++)  // Bucle para calcular el factorial.
        {
            FAC *= I;  // Se multiplica FAC por el contador I en cada iteración.
        }

        printf("\nEl factorial de %d es: %ld", NUM, FAC);  // Se muestra el resultado del factorial.
    }
    else
    {
        printf("\nError en el dato ingresado");  // Mensaje de error si el número es negativo.
    }
}
