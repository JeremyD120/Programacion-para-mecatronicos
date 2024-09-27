#include <stdio.h>
#include <stdlib.h>

/* Suma pagos.
El programa, al recibir como datos un conjunto de pagos realizados en el ultimo
mes, obtiene la suma de los mismos.

PAG Y SPA: variables de tipo real. */

void main(void)
{
	float PAG, SPA; son variable de tipo flotante
	SPA = 0; se inicializa la variable spa a 0 para empezar a acumular los pagos
	printf("Ingrese el primer pago:\t");
	scanf("%f", &PAG); se le pide al usuario que ingrese el primer pago, que almacenala variable
	while (PAG)
	/* Observa que la condicion es verdadera mientras el pago es diferente de cero. */
	{
		SPA = SPA + PAG; se suma el pago acual (pag)a la variable spa que alamacena la suma total de los pagos
		printf("Ingrese el siguiente pago:\t "); ingrese el pago
		scanf("%f", &PAG); se alamcena el nuevo pago en la variable

		/* Observa que la proposicion que modifica la condicion es una lectura. */
	}

	printf("\nEl total de pagos del mes es: %2f", SPA); imprime el valor final de la spa, que es la suma total de los pagos ingresados

	}
