#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Librer�as est�ndar necesarias para entrada/salida, manejo de memoria y cadenas

main() {
    // Funci�n principal del programa

    char frase[100]; // Cadena para almacenar la frase ingresada por el usuario
    int key;         // Variable para la clave de cifrado o descifrado
    int i, salto = 0; // Contadores y ajuste para el rango de cifrado/descifrado

    while (1) { // Bucle infinito para permitir m�ltiples operaciones sin reiniciar el programa
        system("cls"); // Limpia la pantalla en cada iteraci�n
        printf("Ingresa la frase a cifrar o descifrar: ");
        gets(frase); // Captura la frase del usuario (Nota: inseguro, usar fgets es preferible)

        // Solicita la clave de cifrado dentro de un rango permitido
        do {
            printf("Inserte la clave de cifrado (1-10): ");
            scanf("%d", &key); // Captura la clave ingresada por el usuario
        } while (key < 1 || key > 10); // Asegura que la clave est� entre 1 y 10

        // Solicita al usuario elegir entre cifrar o descifrar
        printf("\nSeleccione una opci�n:\n1. Cifrar\n2. Descifrar\n");
        int opcion; // Variable para almacenar la opci�n seleccionada
        scanf("%d", &opcion); // Captura la opci�n ingresada

        if (opcion == 1) { // Si elige cifrar
            printf("\n\n----------------------------------\nFrase cifrada:\n");
            for (i = 0; i < strlen(frase); i++, salto = 0) { // Recorre cada car�cter de la frase
                if (frase[i] > 126 - key) { // Verifica si el car�cter excede el rango ASCII imprimible superior
                    salto = 95; // Ajusta el rango volviendo al inicio del conjunto imprimible
                }
                printf("%c", frase[i] + key - salto); // Aplica el cifrado y muestra el car�cter resultante
            }
        } else if (opcion == 2) { // Si elige descifrar
            printf("\n\n----------------------------------\nFrase descifrada:\n");
            for (i = 0; i < strlen(frase); i++, salto = 0) { // Recorre cada car�cter de la frase
                if (frase[i] < 32 + key) { // Verifica si el car�cter excede el rango ASCII imprimible inferior
                    salto = 95; // Ajusta el rango volviendo al final del conjunto imprimible
                }
                printf("%c", frase[i] - key + salto); // Aplica el descifrado y muestra el car�cter resultante
            }
        } else { // Si la opci�n ingresada no es v�lida
            printf("Opci�n no v�lida. Intente de nuevo.\n");
            continue; // Reinicia el bucle sin procesar m�s
        }

        printf("\n\n");
        system("pause"); // Pausa la ejecuci�n para que el usuario pueda ver los resultados
    }
}
