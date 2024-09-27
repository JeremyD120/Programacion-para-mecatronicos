#include <stdio.h>
#include <stdlib.h>

/* Números perfectos.
El programa, al recibir como dato un número entero positivo como límite, obtiene
los números perfectos que hay entre 1 y ese número, y además imprime cuántos números
perfectos hay en el intervalo.

I, J, NUM, SUM, C: variables de tipo entero.
- I: Iterador principal que recorre los números desde 1 hasta el límite (NUM).
- J: Iterador secundario que recorre los posibles divisores de I.
- NUM: Límite superior para buscar números perfectos.
- SUM: Suma de los divisores de un número.
- C: Contador de números perfectos encontrados. */

void main(void)  // Función principal del programa.
{
    int I, J, NUM, SUM, C = 0;  // Declaración e inicialización de variables.

    printf("\nIngrese el número limite: ");  // Solicita al usuario que ingrese el número límite.
    scanf("%d", &NUM);  // Lee el número límite ingresado.

    // Bucle principal que recorre todos los números desde 1 hasta NUM.
    for (I = 1; I <= NUM; I++)
    {
        SUM = 0;  // Inicializa la suma de divisores para el número I.

        // Bucle que calcula la suma de los divisores propios de I.
        for (J = 1; J <= (I / 2); J++)
        {
            if (I % J == 0)  // Si J es un divisor de I...
            {
                SUM += J;  // ...se suma a la variable SUM.
            }
        }

        // Si la suma de los divisores es igual a I, entonces I es un número perfecto.
        if (SUM == I)
        {
            printf("\n%d es un número perfecto", I);  // Imprime que I es un número perfecto.
            C++;  // Incrementa el contador de números perfectos.
        }
    }

    // Imprime la cantidad total de números perfectos encontrados en el intervalo.
    printf("\nEntre 1 y %d hay %d números perfectos", NUM, C);
}
