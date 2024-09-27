#include <stdio.h>
#include <stdlib.h>

/* Lanzamiento de martillo.
El programa, al recibir como dato N lanzamientos de martillo, calcula
el promedio de los lanzamientos de la atleta cubana.

I, N: variables de tipo entero.
LAN, SLA: variables de tipo real. */

void main(void)  // Función principal del programa.
{
    int I, N;             // I para contar los lanzamientos, N para la cantidad total de lanzamientos.
    float LAN, SLA = 0;   // LAN para cada lanzamiento individual, SLA para la suma total de los lanzamientos.

    do
    {
        printf("Ingrese el número de lanzamientos:\t");
        scanf("%d", &N);  // Se solicita el número de lanzamientos.
    }
    while (N < 1 || N > 11);  // Se asegura que N esté en el rango válido de 1 a 11.

    /* Se utiliza la estructura do-while para verificar que el valor de N sea correcto.
       El programa repetirá la solicitud hasta que N esté en el rango de 1 a 11. */

    for (I = 1; I <= N; I++)  // Bucle para ingresar cada lanzamiento.
    {
        printf("\nIngrese el lanzamiento %d: ", I);
        scanf("%f", &LAN);  // Se solicita la distancia del lanzamiento.

        SLA = SLA + LAN;  // Se suma la distancia del lanzamiento a la suma total.
    }

    SLA = SLA / N;  // Se calcula el promedio de los lanzamientos.
    printf("\nEl promedio de lanzamientos es: %.2f", SLA);  // Se muestra el promedio.
}
