#include <stdio.h>
#include <stdlib.h>

/* N�meros perfectos.
El programa, al recibir como dato un n�mero entero positivo como l�mite, obtiene
los n�meros perfectos que hay entre 1 y ese n�mero, y adem�s imprime cu�ntos n�meros
perfectos hay en el intervalo.

I, J, NUM, SUM, C: variables de tipo entero.
- I: Iterador principal que recorre los n�meros desde 1 hasta el l�mite (NUM).
- J: Iterador secundario que recorre los posibles divisores de I.
- NUM: L�mite superior para buscar n�meros perfectos.
- SUM: Suma de los divisores de un n�mero.
- C: Contador de n�meros perfectos encontrados. */

void main(void)  // Funci�n principal del programa.
{
    int I, J, NUM, SUM, C = 0;  // Declaraci�n e inicializaci�n de variables.

    printf("\nIngrese el n�mero limite: ");  // Solicita al usuario que ingrese el n�mero l�mite.
    scanf("%d", &NUM);  // Lee el n�mero l�mite ingresado.

    // Bucle principal que recorre todos los n�meros desde 1 hasta NUM.
    for (I = 1; I <= NUM; I++)
    {
        SUM = 0;  // Inicializa la suma de divisores para el n�mero I.

        // Bucle que calcula la suma de los divisores propios de I.
        for (J = 1; J <= (I / 2); J++)
        {
            if (I % J == 0)  // Si J es un divisor de I...
            {
                SUM += J;  // ...se suma a la variable SUM.
            }
        }

        // Si la suma de los divisores es igual a I, entonces I es un n�mero perfecto.
        if (SUM == I)
        {
            printf("\n%d es un n�mero perfecto", I);  // Imprime que I es un n�mero perfecto.
            C++;  // Incrementa el contador de n�meros perfectos.
        }
    }

    // Imprime la cantidad total de n�meros perfectos encontrados en el intervalo.
    printf("\nEntre 1 y %d hay %d n�meros perfectos", NUM, C);
}
