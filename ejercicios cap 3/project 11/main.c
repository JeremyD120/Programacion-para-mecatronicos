#include <stdio.h>
#include <stdlib.h>

/* Examen de admisión.
El programa, al recibir como datos una serie de calificaciones de un examen,
obtiene el rango en que se encuentran estas.

R1, R2, R3, R4 y R5: variables de tipo entero para contar las calificaciones en cada rango.
CAL: variable de tipo real para almacenar cada calificación ingresada. */

void main(void)  // Función principal del programa.
{
    int R1 = 0, R2 = 0, R3 = 0, R4 = 0, R5 = 0;  // Inicialización de los contadores para cada rango.
    float CAL;  // Variable para almacenar la calificación ingresada.

    printf("Ingresa la calificacion del alumno (-1 para terminar): ");
    scanf("%f", &CAL);  // Se solicita la primera calificación.

    while (CAL != -1)  // El bucle continúa mientras no se ingrese -1.
    {
        // Clasificación de la calificación en el rango correspondiente.
        if (CAL < 4)
            R1++;  // Incrementa el contador de calificaciones en el rango 0..3.99.
        else if (CAL < 6)
            R2++;  // Incrementa el contador de calificaciones en el rango 4..5.99.
        else if (CAL < 8)
            R3++;  // Incrementa el contador de calificaciones en el rango 6..7.99.
        else if (CAL < 9)
            R4++;  // Incrementa el contador de calificaciones en el rango 8..8.99.
        else
            R5++;  // Incrementa el contador de calificaciones en el rango 9..10.

        printf("Ingresa la calificación del alumno (-1 para terminar): ");
        scanf("%f", &CAL);  // Se solicita la siguiente calificación.
    }

    // Impresión de los resultados: el número de calificaciones en cada rango.
    printf("\n0..3.99 = %d", R1);
    printf("\n4..5.99 = %d", R2);
    printf("\n6..7.99 = %d", R3);
    printf("\n8..8.99 = %d", R4);
    printf("\n9..10   = %d", R5);
}
