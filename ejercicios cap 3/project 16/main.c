#include <stdio.h>
#include <stdlib.h>

/* Calificaciones.
El programa, al recibir un grupo de calificaciones de un alumno, obtiene el promedio
de calificaciones de cada uno de ellos y, adem�s, identifica a los alumnos con el mejor
y peor promedio.

I, MAT, MAMAT y MEMAT: variables de tipo entero.
- I: �ndice para iterar a trav�s de las calificaciones.
- MAT: Matr�cula del alumno actual.
- MAMAT: Matr�cula del alumno con el mejor promedio.
- MEMAT: Matr�cula del alumno con el peor promedio.

CAL, SUM, PRO, MAPRO y MEPRO: variables de tipo real.
- CAL: Calificaci�n individual de una materia.
- SUM: Suma total de las calificaciones de un alumno.
- PRO: Promedio de calificaciones de un alumno.
- MAPRO: Mejor promedio registrado.
- MEPRO: Peor promedio registrado. */

void main(void)  // Funci�n principal del programa.
{
    int I, MAT, MAMAT = 0, MEMAT = 0;  // Inicializaci�n de las variables de matr�cula.
    float SUM, PRO, CAL, MAPRO = 0.0, MEPRO = 11.0;  // Inicializaci�n de las variables de calificaciones.

    printf("Ingrese la matr�cula del primer alumno:\t");  // Solicita la matr�cula del primer alumno.
    scanf("%d", &MAT);  // Lee la matr�cula del alumno.

    while (MAT)  // Bucle que se ejecuta mientras se ingresen matr�culas v�lidas (no cero).
    {
        SUM = 0;  // Inicializa la suma de calificaciones para el alumno actual.

        for (I = 1; I <= 5; I++)  // Bucle para ingresar las calificaciones de las 5 materias.
        {
            printf("\tIngrese la calificaci�n %d del alumno: ", I);  // Solicita la calificaci�n de la materia I.
            scanf("%f", &CAL);  // Lee la calificaci�n ingresada.
            SUM += CAL;  // Suma la calificaci�n al total.
        }

        PRO = SUM / 5;  // Calcula el promedio de calificaciones del alumno.

        // Actualiza el mejor promedio y la matr�cula asociada si el promedio actual es mayor.
        if (PRO > MAPRO)
        {
            MAPRO = PRO;
            MAMAT = MAT;
        }

        // Actualiza el peor promedio y la matr�cula asociada si el promedio actual es menor.
        if (PRO < MEPRO)
        {
            MEPRO = PRO;
            MEMAT = MAT;
        }

        // Solicita la matr�cula del siguiente alumno.
        printf("\n\nIngrese la matr�cula del siguiente alumno: ");
        scanf("%d", &MAT);
    }

    // Imprime los resultados del mejor y peor promedio.
    printf("\n\nAlumno con mejor promedio:\t%d\t%5.2f", MAMAT, MAPRO);
    printf("\n\nAlumno con peor promedio:\t%d\t%5.2f", MEMAT, MEPRO);
}
