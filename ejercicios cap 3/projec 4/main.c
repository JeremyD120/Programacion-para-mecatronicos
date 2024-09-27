#include <stdio.h>
#include <stdlib.h>

/* Suma de cuadrados.
El programa, al recibir como datos un grupo de enteros positivos,
obtiene el cuadrado de los mismos y la suma correspondiente a dichos cuadrados. */

void main(void).
{
	int NUM;          // Variable para almacenar el n�mero ingresado por el usuario.
	long CUA, SUC = 0; // Variables para almacenar el cuadrado del n�mero y la suma de cuadrados.

    printf("\nIngrese un numero entero -0 para terminar-:\t");
	scanf("%d", &NUM); // Se solicita al usuario que ingrese un n�mero entero.

    while (NUM)  // El bucle contin�a mientras el n�mero ingresado sea diferente de 0.
    {
		CUA = pow(NUM, 2);  // Se calcula el cuadrado del n�mero ingresado.
		printf("%d al cuadrado es %ld", NUM, CUA);  // Se muestra el cuadrado del n�mero.

        SUC = SUC + CUA;  // Se acumula el cuadrado en la suma total.

        printf("\nIngrese un numero entero -0 para terminar-:\t");
		scanf("%d", &NUM);  // Se solicita otro n�mero al usuario para continuar o terminar.
	}

    printf("\nLa suma de los cuadrados es %ld", SUC);  // Se muestra la suma total de los cuadrados.
}
