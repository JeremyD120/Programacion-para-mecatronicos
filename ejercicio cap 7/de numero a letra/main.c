#include <stdio.h>
#include <stdlib.h>

void convertirUnidades(int numero, char *texto);
void convertirDecenas(int numero, char *texto);
void convertirCentenas(int numero, char *texto);
void convertirNumero(float numero, char *resultado);
void mostrarMenu();

int main() {
    int opcion = 0;
    float numero;
    char resultado[200];

    do {
        mostrarMenu();
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Introduce el número: ");
                scanf("%f", &numero);
                convertirNumero(numero, resultado);
                printf("Número en letras: %s\n", resultado);
                break;
            case 2:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Inténtalo de nuevo.\n");
        }
    } while (opcion != 2);

    return 0;
}

void mostrarMenu() {
    printf("\n===== Conversión de Números a Letras =====\n");
    printf("1. Convertir número a letras\n");
    printf("2. Salir\n");
    printf("===========================================\n");
}

void convertirUnidades(int numero, char *texto) {
    switch (numero) {
        case 1: strcat(texto, "uno "); break;
        case 2: strcat(texto, "dos "); break;
        case 3: strcat(texto, "tres "); break;
        case 4: strcat(texto, "cuatro "); break;
        case 5: strcat(texto, "cinco "); break;
        case 6: strcat(texto, "seis "); break;
        case 7: strcat(texto, "siete "); break;
        case 8: strcat(texto, "ocho "); break;
        case 9: strcat(texto, "nueve "); break;
        case 0: strcat(texto, "cero "); break;
    }
}

void convertirDecenas(int numero, char *texto) {
    if (numero >= 10 && numero < 20) {
        switch (numero) {
            case 10: strcat(texto, "diez "); break;
            case 11: strcat(texto, "once "); break;
            case 12: strcat(texto, "doce "); break;
            case 13: strcat(texto, "trece "); break;
            case 14: strcat(texto, "catorce "); break;
            case 15: strcat(texto, "quince "); break;
            case 16: strcat(texto, "dieciséis "); break;
            case 17: strcat(texto, "diecisiete "); break;
            case 18: strcat(texto, "dieciocho "); break;
            case 19: strcat(texto, "diecinueve "); break;
        }
    } else {
        int decenas = numero / 10;
        int unidades = numero % 10;
        switch (decenas) {
            case 2: strcat(texto, "veinte "); break;
            case 3: strcat(texto, "treinta "); break;
            case 4: strcat(texto, "cuarenta "); break;
            case 5: strcat(texto, "cincuenta "); break;
            case 6: strcat(texto, "sesenta "); break;
            case 7: strcat(texto, "setenta "); break;
            case 8: strcat(texto, "ochenta "); break;
            case 9: strcat(texto, "noventa "); break;
        }
        if (unidades > 0) {
            strcat(texto, "y ");
            convertirUnidades(unidades, texto);
        }
    }
}

void convertirCentenas(int numero, char *texto) {
    int centenas = numero / 100;
    int resto = numero % 100;

    switch (centenas) {
        case 1:
            if (resto == 0)
                strcat(texto, "cien ");
            else
                strcat(texto, "ciento ");
            break;
        case 2: strcat(texto, "doscientos "); break;
        case 3: strcat(texto, "trescientos "); break;
        case 4: strcat(texto, "cuatrocientos "); break;
        case 5: strcat(texto, "quinientos "); break;
        case 6: strcat(texto, "seiscientos "); break;
        case 7: strcat(texto, "setecientos "); break;
        case 8: strcat(texto, "ochocientos "); break;
        case 9: strcat(texto, "novecientos "); break;
    }
    if (resto > 0) {
        convertirDecenas(resto, texto);
    }
}

void convertirNumero(float numero, char *resultado) {
    int parteEntera = (int)numero;
    int centavos = (int)((numero - parteEntera) * 100);

    char textoNumero[100] = "";

    if (parteEntera == 0) {
        strcat(textoNumero, "cero ");
    } else {
        convertirCentenas(parteEntera, textoNumero);
    }

    sprintf(resultado, "%scon %d centavos", textoNumero, centavos);
}
