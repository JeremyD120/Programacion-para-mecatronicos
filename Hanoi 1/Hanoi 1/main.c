#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Imprime el estado actual del tablero de las Torres de Han�i
void imprime(int *tab, int fil, int col, int ultNum) {
    int f, c;  // �ndices para filas y columnas
    int i, esp;  // Variables para impresi�n gr�fica y c�lculo de espacios

    for (c = col - 1; c >= 0; c--) {  // Recorre las columnas desde la superior hasta la inferior
        for (f = 0; f < fil; f++) {  // Recorre cada fila
            esp = (ultNum - tab[col * f + c]) / 2;  // Calcula espacios para centrar discos visualmente
            for (i = 0; i < esp; i++) printf(" ");  // Espacios a la izquierda del disco
            for (i = 0; i < tab[col * f + c]; i++) printf("*");  // Representaci�n del disco
            for (i = 0; i < esp; i++) printf(" ");  // Espacios a la derecha del disco

            printf("\t");  // Tabulaci�n entre torres
        }
        printf("\n");  // Salto de l�nea despu�s de imprimir una fila completa
    }
}

// Mueve un disco de una torre a otra en el tablero
void mueveDisco(int *tab, int fil, int col, int ultNum, int filOrig, int filDest) {
    int cO = col - 1, cD = col - 1;  // Variables para las posiciones m�s altas en origen y destino

    // Encuentra el disco m�s alto en la torre origen
    while (cO >= 0 && tab[col * filOrig + cO] == 0) cO--;
    if (cO < 0) cO = 0;  // Asegura que no haya �ndices negativos

    // Encuentra la primera posici�n vac�a en la torre destino
    while (cD >= 0 && tab[col * filDest + cD] == 0) cD--;

    // Mueve el disco desde la torre origen a la torre destino
    tab[col * filDest + cD + 1] = tab[col * filOrig + cO];
    tab[col * filOrig + cO] = 0;

    // Imprime el tablero actualizado despu�s de mover el disco
    imprime(tab, fil, col, ultNum);
}

// Resuelve las Torres de Han�i de forma recursiva
void hanoi(int *tab, int fil, int col, int disc, int ultNum, int O, int A, int D) {
    if (disc == 1) {  // Caso base: si solo hay un disco
        system("cls");  // Limpia la pantalla
        mueveDisco(tab, fil, col, ultNum, O, D);  // Mueve el �nico disco de O a D
    } else {  // Caso recursivo: m�s de un disco
        // Mueve los n-1 discos superiores de la torre origen a la auxiliar
        hanoi(tab, fil, col, disc - 1, ultNum, O, D, A);

        system("cls");  // Limpia la pantalla
        // Mueve el disco m�s grande de la torre origen a la torre destino
        mueveDisco(tab, fil, col, ultNum, O, D);

        // Mueve los n-1 discos de la torre auxiliar a la torre destino
        hanoi(tab, fil, col, disc - 1, ultNum, A, O, D);
    }
}

// Introduce una pausa para ralentizar la ejecuci�n
void delay(int tiempo) {
    int c, d;
    while (tiempo >= 0) {  // Repite hasta que el tiempo llegue a cero
        for (c = 1; c <= 10000; c++)  // Iteraci�n para consumir tiempo
            for (d = 1; d <= 10000; d++);  // Bucle anidado para m�s retardo
        tiempo--;  // Reduce el tiempo restante
    }
}

int main() {
    int fil = 3;  // N�mero de torres
    int col;  // N�mero de discos
    int *tablero = NULL;  // Puntero para el tablero din�mico
    int f, c, disc = 1, ultNum;  // Variables auxiliares

    // Solicita al usuario el n�mero de discos
    printf("Indique el numero de discos: ");
    scanf("%i", &col);

    // Reserva memoria para el tablero (matriz)
    tablero = (int *)malloc(sizeof(int) * fil * col);

    // Inicializa el tablero colocando los discos en la torre inicial
    for (f = 0; f < fil; f++) {
        for (c = col - 1; c >= 0; c--) {
            if (f == 0) {  // Torre inicial
                tablero[col * f + c] = disc;
                disc += 2;  // Incrementa el tama�o de los discos
            } else {
                tablero[col * f + c] = 0;  // Torres vac�as
            }
        }
    }

    ultNum = disc;  // Almacena el tama�o del disco m�s grande

    system("cls");  // Limpia la pantalla inicial
    imprime(tablero, fil, col, ultNum);  // Imprime el estado inicial del tablero
    delay(6);  // Introduce un retraso antes de comenzar

    // Resuelve las Torres de Han�i
    hanoi(tablero, fil, col, col, ultNum, 0, 1, 2);

    free(tablero);  // Libera la memoria din�mica utilizada
    return 0;  // Termina el programa
}
