#include <stdio.h>  // Librería estándar de entrada y salida.
#include <math.h>   // Librería para funciones matemáticas.

/* Serie de ULAM.
El programa, al recibir como dato un entero positivo, obtiene y escribe
la serie de ULAM.

NUM: variable de tipo entero para almacenar el número ingresado. */

void main(void)  // Función principal del programa.
{
    int NUM;  // Variable que almacenará el número ingresado por el usuario.

    printf("Ingresa el numero para calcular la serie: ");
    scanf("%d", &NUM);  // Se solicita al usuario que ingrese un número entero.

    if (NUM > 0)  // Verifica que el número ingresado sea positivo.
    {
        printf("\nSerie de ULAM:\n");  // Imprime el encabezado de la serie.
        printf("%d \t", NUM);  // Imprime el primer número de la serie.

        while (NUM != 1)  // El bucle continúa hasta que NUM sea igual a 1.
        {
            // Se verifica si NUM es par o impar.
            if (NUM % 2 == 0)  // Condición para determinar si NUM es par.
            {
                NUM = NUM / 2;  // Si es par, se divide entre 2.
            }
            else  // Si NUM es impar.
            {
                NUM = NUM * 3 + 1;  // Si es impar, se multiplica por 3 y se suma 1.
            }
            printf("%d \t", NUM);  // Imprime el siguiente número en la serie.
        }
    }
    else
    {
        printf("\nNUM debe ser un entero positivo");  // Mensaje de error si el número no es positivo.
    }
}
