#include <stdio.h>
#include <stdlib.h>
// Bibliotecas estándar necesarias para manejo de entrada/salida y memoria dinámica

void crearArreglo(int **arr, int size) {
    // Función para asignar memoria dinámica a un arreglo y llenarlo con valores iniciales

    *arr = (int *)malloc(size * sizeof(int)); // Asigna memoria dinámica para un arreglo de tamaño dado
    if (*arr == NULL) {
        // Verifica si la asignación de memoria falló
        printf("Error al asignar memoria\n");
        exit(1); // Finaliza el programa en caso de error
    }

    // Llena el arreglo con valores consecutivos (1, 2, 3, ...)
    for (int i = 0; i < size; i++) {
        (*arr)[i] = i + 1; // Asigna el valor "i + 1" a cada posición del arreglo
    }
}

int main() {
    int *arreglo = NULL; // Inicializa un puntero a entero como NULL
    int tamano; // Variable para almacenar el tamaño del arreglo

    printf("Ingrese el tamano del arreglo: "); // Solicita al usuario el tamaño del arreglo
    scanf("%d", &tamano); // Lee el tamaño ingresado por el usuario

    crearArreglo(&arreglo, tamano); // Llama a la función para crear e inicializar el arreglo

    printf("Elementos del arreglo: "); // Imprime un mensaje antes de mostrar los elementos
    for (int i = 0; i < tamano; i++) {
        printf("%d ", arreglo[i]); // Imprime cada elemento del arreglo
    }
    printf("\n"); // Salto de línea al final de la impresión

    free(arreglo); // Libera la memoria dinámica asignada al arreglo

    return 0; // Finaliza el programa exitosamente
}

