#include <stdio.h>
#include <stdlib.h>

/* Cálculo de P.
El programa obtiene el valor de P aplicando una serie determinada.

I: variable de tipo entero que se utiliza como índice en la serie.
B: variable de tipo entero utilizada como bandera para alternar entre suma y resta.
C: variable de tipo entero que cuenta el número de términos utilizados en la aproximación.
RES: variable de tipo real de doble precisión que almacena el resultado de la serie. */

void main(void)  // Función principal del programa.
{
    int I = 1, B = 0, C;  // Inicialización de las variables.
    double RES;  // Declaración de la variable de resultado.

    RES = 4.0 / I;  // Inicializa RES con el primer término de la serie (4/I cuando I=1).
    C = 1;  // Inicializa el contador de términos utilizados.

    // Bucle que continúa hasta que la diferencia entre PI y RES sea menor que 0.0005.
    while ((fabs(3.1415 - RES)) > 0.0005)
    {
        I += 2;  // Incrementa I en 2 para considerar el siguiente término de la serie.

        // Alterna entre sumar y restar el siguiente término.
        if (B)  // Si B es verdadero (1), suma el término.
        {
            RES += (double)(4.0 / I);  // Suma el siguiente término de la serie.
            B = 0;  // Cambia B a falso (0) para la siguiente iteración.
        }
        else  // Si B es falso (0), resta el término.
        {
            RES -= (double)(4.0 / I);  // Resta el siguiente término de la serie.
            B = 1;  // Cambia B a verdadero (1) para la siguiente iteración.
        }
        C++;  // Incrementa el contador de términos utilizados.
    }

    // Imprime el número de términos utilizados en la aproximación.
    printf("\nNumero de términos: %d", C);
}
