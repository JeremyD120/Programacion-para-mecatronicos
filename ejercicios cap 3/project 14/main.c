#include <stdio.h>
#include <stdlib.h>

/* Elección.
El programa obtiene el total de votos de cada candidato y el porcentaje
correspondiente. También considera votos nulos.

VOT: variable de tipo entero que almacena el voto ingresado.
C1, C2, C3, C4, C5: contadores para cada candidato.
NU: contador de votos nulos.
SVO: variable que almacena el total de votos.
PO1, PO2, PO3, PO4, PO5, PON: variables de tipo real para almacenar los porcentajes. */

void main(void)  // Función principal del programa.
{
    int VOT, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0, NU = 0, SVO;  // Inicialización de las variables.
    float PO1, PO2, PO3, PO4, PO5, PON;  // Inicialización de las variables para porcentajes.

    printf("Ingrese el primer voto: ");  // Solicita el primer voto.
    scanf("%d", &VOT);  // Lee el voto ingresado.

    while (VOT)  // El bucle continúa mientras VOT no sea cero.
    {
        switch (VOT)  // Evalúa el voto ingresado.
        {
            case 1: C1++; break;  // Incrementa el contador del candidato 1.
            case 2: C2++; break;  // Incrementa el contador del candidato 2.
            case 3: C3++; break;  // Incrementa el contador del candidato 3.
            case 4: C4++; break;  // Incrementa el contador del candidato 4.
            case 5: C5++; break;  // Incrementa el contador del candidato 5.
            default: NU++; break;  // Incrementa el contador de votos nulos.
        }
        printf("Ingrese el siguiente voto -0 para terminar-: ");  // Solicita el siguiente voto.
        scanf("%d", &VOT);  // Lee el nuevo voto ingresado.
    }

    // Calcula el total de votos.
    SVO = C1 + C2 + C3 + C4 + C5 + NU;

    // Calcula los porcentajes de votos.
    PO1 = ((float) C1 / SVO) * 100;
    PO2 = ((float) C2 / SVO) * 100;
    PO3 = ((float) C3 / SVO) * 100;
    PO4 = ((float) C4 / SVO) * 100;
    PO5 = ((float) C5 / SVO) * 100;
    PON = ((float) NU / SVO) * 100;

    // Imprime el total de votos y los resultados.
    printf("\nTotal de votos: %d", SVO);
    printf("\nCandidato 1: %d votos -- porcentaje: %5.2f", C1, PO1);
    printf("\nCandidato 2: %d votos -- porcentaje: %5.2f", C2, PO2);
    printf("\nCandidato 3: %d votos -- porcentaje: %5.2f", C3, PO3);
    printf("\nCandidato 4: %d votos -- porcentaje: %5.2f", C4, PO4);
    printf("\nCandidato 5: %d votos -- porcentaje: %5.2f", C5, PO5);
    printf("\nNulos: %d votos -- porcentaje: %5.2f", NU, PON);  // Corregido el formato.
}
