#include <stdio.h>
#include <stdlib.h>


void moverDiscos(int n, int origen, int destino, int aux);/* Declaramos la funcion de mover discos */

int main() { /* almacena la cantidad de discos ingresada */
    int cantDiscos;


    printf("Ingrese la cantidad de discos a utilizar: ");
    scanf("%d", &cantDiscos);
    /* Pide la cantidad de discos */

    /* Comprueba que la cantidad de discos no supere 25 */
    if (cantDiscos > 25) {
        printf("\n\nPor favor, ingrese 25 discos o menos para su correcto funcionamiento\n\n\n");
        system("PAUSE");
        return 0;
        /* Comprueba que la cantidad de discos no supere 25 */
    }

    printf("\n");

    /* Llama a la funci�n "moverDiscos" */
    /* La funci�n recibe como datos:
       - La cantidad de discos
       - La torre origen (1)
       - La torre destino (2)
       - La torre auxiliar (3)
       */
    moverDiscos(cantDiscos, 1, 2, 3);

    printf("\n\n");
    system("PAUSE");

    /* Fin del programa */
    return 0;
}

/* DDeclaramos "moverDiscos" */
void moverDiscos(int n, int origen, int destino, int aux) {
    /* Si hay discos para mover (n > 0), realizar los pasos */
    if (n > 0) {
        /* Paso 1: Mueve los n-1 discos de la torre origen a la torre auxiliar usando la torre destino */
        moverDiscos(n - 1, origen, aux, destino);

        /* Paso 2: Mueve el disco m�s grande de la torre origen a la torre destino */
        printf("Muevo un disco de %d a %d\n", origen, destino);

        /* Paso 3: Mueve los n-1 discos de la torre auxiliar a la torre destino usando la torre origen */
        moverDiscos(n - 1, aux, destino, origen);
    }
}
