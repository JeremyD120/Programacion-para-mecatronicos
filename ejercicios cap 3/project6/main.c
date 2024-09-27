#include <stdio.h>
#include <stdlib.h>

/* Nómina de profesor.
El programa, al recibir como datos los salarios de los profesores de una
universidad, obtiene la nómina y el promedio de los salarios.

I: variable de tipo entero que cuenta el número de profesores.
SAL, NOM y PRO: variables de tipo real para almacenar el salario,
la nómina total, y el promedio de salarios, respectivamente. */

void main(void)  // Función principal del programa.
{
    int I = 0;            // Variable para contar el número de profesores.
    float SAL, PRO, NOM = 0;  // Variables para el salario, nómina total y promedio.

    printf("Ingrese el salario del profesor:\t");

    /* Se solicita el salario de un profesor. Es necesario ingresar al menos un salario
       para evitar errores de ejecución debido a la división entre cero más adelante. */
    scanf("%f", &SAL);

    while (SAL != 0)  // El bucle continúa mientras el salario ingresado sea diferente de 0.
    {
        NOM = NOM + SAL;  // Se acumula el salario en la nómina total.
        I = I + 1;        // Se incrementa el contador de profesores.

        printf("Ingrese el salario del profesor -0 para terminar-:\t");
        scanf("%f", &SAL);  // Se solicita otro salario al usuario para continuar o terminar.
    }

    if (I > 0)  // Se asegura de que al menos se haya ingresado un salario para evitar división por cero.
    {
        PRO = NOM / I;  // Se calcula el promedio de salarios.
        printf("\nNómina: %.2f \t Promedio de salarios: %.2f", NOM, PRO);  // Se muestran la nómina y el promedio.
    }
    else
    {
        printf("\nNo se ingresaron salarios.");  // Mensaje si no se ingresó ningún salario.
    }
}
