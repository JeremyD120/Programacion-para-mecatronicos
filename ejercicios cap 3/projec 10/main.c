#include <stdio.h>
#include <stdlib.h>

/* Pares e impares.
El programa, al recibir como datos N n�meros enteros, obtiene la suma de los
n�meros pares y calcula el promedio de los impares.

I, N, NUM, SPA, SIM, CIM: variables de tipo entero. */

void main(void)  // Funci�n principal del programa.
{
    int I, N, NUM, SPA = 0, SIM = 0, CIM = 0;  // Variables de control y acumulaci�n.

    printf("Ingrese el numero de datos que se van a procesar:\t");
    scanf("%d", &N);  // Se solicita el n�mero de datos a procesar.

    if (N > 0)  // Verifica que el n�mero de datos sea positivo.
    {
        for (I = 1; I <= N; I++)  // Bucle que recorre cada uno de los N n�meros.
        {
            printf("\nIngrese el n�mero %d: ", I);
            scanf("%d", &NUM);  // Se solicita un n�mero entero.

            if (NUM != 0)  // Se asegura de que el n�mero no sea cero.
            {
                if (NUM % 2 == 0)  // Verifica si el n�mero es par.
                {
                    SPA = SPA + NUM;  // Acumula la suma de los n�meros pares.
                }
                else  // Si el n�mero es impar.
                {
                    SIM = SIM + NUM;  // Acumula la suma de los n�meros impares.
                    CIM++;  // Incrementa el contador de n�meros impares.
                }
            }
        }

        printf("\nLa suma de los n�meros pares es: %d", SPA);  // Imprime la suma de los pares.

        if (CIM > 0)  // Verifica que haya al menos un n�mero impar para calcular el promedio.
        {
            printf("\nEl promedio de n�meros impares es: %5.2f", (float)SIM / CIM);  // Imprime el promedio de los impares.
        }
        else
        {
            printf("\nNo se ingresaron n�meros impares.");  // Mensaje si no hay n�meros impares.
        }
    }
    else
    {
        printf("\nEl valor de N es incorrecto");  // Mensaje de error si N no es v�lido.
    }
}
