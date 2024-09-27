#include <stdio.h>
#include <stdlib.h>

/* Pares e impares.
El programa, al recibir como datos N números enteros, obtiene la suma de los
números pares y calcula el promedio de los impares.

I, N, NUM, SPA, SIM, CIM: variables de tipo entero. */

void main(void)  // Función principal del programa.
{
    int I, N, NUM, SPA = 0, SIM = 0, CIM = 0;  // Variables de control y acumulación.

    printf("Ingrese el numero de datos que se van a procesar:\t");
    scanf("%d", &N);  // Se solicita el número de datos a procesar.

    if (N > 0)  // Verifica que el número de datos sea positivo.
    {
        for (I = 1; I <= N; I++)  // Bucle que recorre cada uno de los N números.
        {
            printf("\nIngrese el número %d: ", I);
            scanf("%d", &NUM);  // Se solicita un número entero.

            if (NUM != 0)  // Se asegura de que el número no sea cero.
            {
                if (NUM % 2 == 0)  // Verifica si el número es par.
                {
                    SPA = SPA + NUM;  // Acumula la suma de los números pares.
                }
                else  // Si el número es impar.
                {
                    SIM = SIM + NUM;  // Acumula la suma de los números impares.
                    CIM++;  // Incrementa el contador de números impares.
                }
            }
        }

        printf("\nLa suma de los números pares es: %d", SPA);  // Imprime la suma de los pares.

        if (CIM > 0)  // Verifica que haya al menos un número impar para calcular el promedio.
        {
            printf("\nEl promedio de números impares es: %5.2f", (float)SIM / CIM);  // Imprime el promedio de los impares.
        }
        else
        {
            printf("\nNo se ingresaron números impares.");  // Mensaje si no hay números impares.
        }
    }
    else
    {
        printf("\nEl valor de N es incorrecto");  // Mensaje de error si N no es válido.
    }
}
