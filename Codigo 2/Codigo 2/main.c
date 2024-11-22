#include <stdio.h>
#include <stdlib.h>
// Bibliotecas est�ndar necesarias para manejo de entrada/salida y memoria din�mica

void crearArreglo(int **arr, int size) {
    // Funci�n para asignar memoria din�mica a un arreglo y llenarlo con valores iniciales

    *arr = (int *)malloc(size * sizeof(int)); // Asigna memoria din�mica para un arreglo de tama�o dado
    if (*arr == NULL) {
        // Verifica si la asignaci�n de memoria fall�
        printf("Error al asignar memoria\n");
        exit(1); // Finaliza el programa en caso de error
    }

    // Llena el arreglo con valores consecutivos (1, 2, 3, ...)
    for (int i = 0; i < size; i++) {
        (*arr)[i] = i + 1; // Asigna el valor "i + 1" a cada posici�n del arreglo
    }
}

int main() {
    int *arreglo = NULL; // Inicializa un puntero a entero como NULL
    int tamano; // Variable para almacenar el tama�o del arreglo

    printf("Ingrese el tamano del arreglo: "); // Solicita al usuario el tama�o del arreglo
    scanf("%d", &tamano); // Lee el tama�o ingresado por el usuario

    crearArreglo(&arreglo, tamano); // Llama a la funci�n para crear e inicializar el arreglo

    printf("Elementos del arreglo: "); // Imprime un mensaje antes de mostrar los elementos
    for (int i = 0; i < tamano; i++) {
        printf("%d ", arreglo[i]); // Imprime cada elemento del arreglo
    }
    printf("\n"); // Salto de l�nea al final de la impresi�n

    free(arreglo); // Libera la memoria din�mica asignada al arreglo

    return 0; // Finaliza el programa exitosamente
}

