#include <stdio.h>
#include <stdlib.h>

/* Serie.
El programa imprime los t�rminos y obtiene la suma de una determinada serie.

I: Contador para los t�rminos de la serie.
SSE: Suma acumulada de los t�rminos de la serie.
CAM: Variable de control para alternar el incremento entre 5 y 3. */

void main(void)  // Funci�n principal del programa.
{
    int I = 2, CAM = 1;  // I inicia en 2, CAM controla el incremento alternante.
    long SSE = 0;        // SSE almacena la suma acumulada de la serie.

    while (I <= 2500)  // El bucle contin�a mientras I sea menor o igual a 2500.
    {
        SSE = SSE + I;  // Se suma el valor actual de I a la suma total SSE.
        printf("\t%d", I);  // Se imprime el t�rmino actual de la serie.

        if (CAM)  // Si CAM es 1, se incrementa I en 5 y CAM se reduce a 0.
        {
            I += 5;
            CAM--;  // CAM cambia a 0 para el pr�ximo incremento.
        }
        else  // Si CAM es 0, se incrementa I en 3 y CAM se incrementa a 1.
        {
            I += 3;
            CAM++;  // CAM cambia a 1 para el pr�ximo incremento.
        }
    }

    printf("\nLa suma de la serie es: %ld", SSE);  // Se imprime la suma total de la serie.
}
