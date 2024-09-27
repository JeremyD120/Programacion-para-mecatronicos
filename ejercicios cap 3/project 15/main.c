#include <stdio.h>
#include <stdlib.h>

/* C�lculo de P.
El programa obtiene el valor de P aplicando una serie determinada.

I: variable de tipo entero que se utiliza como �ndice en la serie.
B: variable de tipo entero utilizada como bandera para alternar entre suma y resta.
C: variable de tipo entero que cuenta el n�mero de t�rminos utilizados en la aproximaci�n.
RES: variable de tipo real de doble precisi�n que almacena el resultado de la serie. */

void main(void)  // Funci�n principal del programa.
{
    int I = 1, B = 0, C;  // Inicializaci�n de las variables.
    double RES;  // Declaraci�n de la variable de resultado.

    RES = 4.0 / I;  // Inicializa RES con el primer t�rmino de la serie (4/I cuando I=1).
    C = 1;  // Inicializa el contador de t�rminos utilizados.

    // Bucle que contin�a hasta que la diferencia entre PI y RES sea menor que 0.0005.
    while ((fabs(3.1415 - RES)) > 0.0005)
    {
        I += 2;  // Incrementa I en 2 para considerar el siguiente t�rmino de la serie.

        // Alterna entre sumar y restar el siguiente t�rmino.
        if (B)  // Si B es verdadero (1), suma el t�rmino.
        {
            RES += (double)(4.0 / I);  // Suma el siguiente t�rmino de la serie.
            B = 0;  // Cambia B a falso (0) para la siguiente iteraci�n.
        }
        else  // Si B es falso (0), resta el t�rmino.
        {
            RES -= (double)(4.0 / I);  // Resta el siguiente t�rmino de la serie.
            B = 1;  // Cambia B a verdadero (1) para la siguiente iteraci�n.
        }
        C++;  // Incrementa el contador de t�rminos utilizados.
    }

    // Imprime el n�mero de t�rminos utilizados en la aproximaci�n.
    printf("\nNumero de t�rminos: %d", C);
}
