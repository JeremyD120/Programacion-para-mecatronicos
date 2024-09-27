#include <stdio.h>

/* Suma de pagos.
El programa obtiene la suma de los pagos realizados el �ltimo mes.

PAG y SPA: variables de tipo real.*/

void main(void)  // Funci�n principal del programa.
{
    float PAG, SPA = 0;  // PAG almacena el pago ingresado, SPA acumula la suma total de pagos.

    printf("Ingrese el primer pago:\t");
    scanf("%f", &PAG);  // Se solicita al usuario que ingrese el primer pago.

    /* Observa que al utilizar la estructura while, el ciclo se repetir�
       mientras el pago ingresado sea diferente de 0. */

    while (PAG != 0)  // El bucle contin�a mientras el pago ingresado sea diferente de 0.
    {
        SPA = SPA + PAG;  // Se acumula el pago en la suma total.

        printf("Ingrese el siguiente pago -0 para terminar-:\t");
        scanf("%f", &PAG);  // Se solicita otro pago al usuario para continuar o terminar.
    }

    printf("\nEl total de pagos del mes es: %.2f", SPA);  // Se muestra la suma total de los pagos.
}
