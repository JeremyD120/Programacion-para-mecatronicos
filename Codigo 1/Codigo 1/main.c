#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 3, i; // Inicializamos n con 3 y "i" como índice para los bucles
    int *arr = (int *)malloc(n * sizeof(int)); // Asignamos memoria dinámica para un arreglo de 3 enteros

    // Verificamos si la asignación de memoria fue exitosa
    if (arr == NULL) {
        printf("Error al asignar memoria\n"); // Mostramos un mensaje de error si la asignación falla
        return 1; // Terminamos el programa en caso de error
    }

    // Inicializamos el arreglo con valores del 1 al 3
    for (i = 0; i < n; i++) {
        arr[i] = i + 1; // Asignamos a cada posición el valor "i + 1"
    }

    // Redimensionamos el arreglo para contener 5 elementos
    n = 5; // Cambiamos el tamaño deseado del arreglo
    arr = (int *)realloc(arr, n * sizeof(int)); // Usamos 'realloc' para ajustar el tamaño del arreglo

    // Verificamos si la redimensión de memoria fue exitosa
    if (arr == NULL) {
        printf("Error al redimensionar memoria\n"); // Mostramos un mensaje si hay error al redimensionar
        return 1; // Terminamos el programa en caso de error
    }

    // Inicializamos las nuevas posiciones del arreglo
    for (i = 3; i < n; i++) {
        arr[i] = i + 1; // Asignamos valores del 4 al 5 en las nuevas posiciones
    }

    // Imprimimos los elementos del arreglo
    printf("Arreglo redimensionado: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Mostramos cada valor del arreglo
    }

    // Liberamos la memoria dinámica asignada al arreglo
    free(arr); // Liberamos la memoria que ya no es necesaria

    return 0; // Finalizamos el programa
}
