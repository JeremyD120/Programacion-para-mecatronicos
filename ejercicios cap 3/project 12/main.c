#include <stdio.h>  // Librer�a est�ndar de entrada y salida.
#include <math.h>   // Librer�a para funciones matem�ticas.

/* Serie de ULAM.
El programa, al recibir como dato un entero positivo, obtiene y escribe
la serie de ULAM.

NUM: variable de tipo entero para almacenar el n�mero ingresado. */

void main(void)  // Funci�n principal del programa.
{
    int NUM;  // Variable que almacenar� el n�mero ingresado por el usuario.

    printf("Ingresa el numero para calcular la serie: ");
    scanf("%d", &NUM);  // Se solicita al usuario que ingrese un n�mero entero.

    if (NUM > 0)  // Verifica que el n�mero ingresado sea positivo.
    {
        printf("\nSerie de ULAM:\n");  // Imprime el encabezado de la serie.
        printf("%d \t", NUM);  // Imprime el primer n�mero de la serie.

        while (NUM != 1)  // El bucle contin�a hasta que NUM sea igual a 1.
        {
            // Se verifica si NUM es par o impar.
            if (NUM % 2 == 0)  // Condici�n para determinar si NUM es par.
            {
                NUM = NUM / 2;  // Si es par, se divide entre 2.
            }
            else  // Si NUM es impar.
            {
                NUM = NUM * 3 + 1;  // Si es impar, se multiplica por 3 y se suma 1.
            }
            printf("%d \t", NUM);  // Imprime el siguiente n�mero en la serie.
        }
    }
    else
    {
        printf("\nNUM debe ser un entero positivo");  // Mensaje de error si el n�mero no es positivo.
    }
}
