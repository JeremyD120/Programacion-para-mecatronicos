#include <stdio.h>
#include <string.h>

char *inverso(char *); /* Prototipo de funci�n. */

void main(void) {
    char fra[50], aux[50];

    printf("\nIngrese la linea de texto: ");
    fgets(fra, sizeof(fra), stdin);
    fra[strcspn(fra, "\n")] = '\0'; // Eliminar el car�cter de nueva l�nea en fra

    strcpy(aux, inverso(fra)); /* Se copia a aux el resultado de la funci�n inverso. */

    printf("Escribe la linea de texto en forma inversa: %s\n", aux);
}

char *inverso(char *cadena) {
    int i = 0, j, lon;
    char cad;

    lon = strlen(cadena);
    j = lon - 1;

    while (i < ((lon - 1) / 2)) {
        cad = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = cad;
        i++;
        j--;
    }

    return cadena;
}
