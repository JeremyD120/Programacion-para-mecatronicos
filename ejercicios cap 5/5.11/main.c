#include <stdio.h>

#define MAX 100

void Lectura(int A[], int T);
int Binaria(int A[], int T, int E);

int main() {
    int RES, ELE, TAM, VEC[MAX];

    do {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1); /* Se verifica que el tama�o del arreglo sea correcto. */

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Binaria(VEC, TAM, ELE); /* Se llama a la funci�n que busca en el arreglo. */

    if (RES) { /* Si RES tiene un valor verdadero (diferente de 0), se escribe la posici�n en la que se encontr� el elemento. */
        printf("\nEl elemento se encuentra en la posicion: %d", RES);
    } else {
        printf("\nEl elemento no se encuentra en el arreglo");
    }

    return 0;
}

void Lectura(int A[], int T) {
    int I;

    for (I = 0; I < T; I++) {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Binaria(int A[], int T, int E) {
    int IZQ = 0, CEN, DER = T - 1, BAN = 0;

    while (IZQ <= DER && !BAN) {
        CEN = (IZQ + DER) / 2;

        if (E == A[CEN]) {
            BAN = CEN;
        } else if (E > A[CEN]) {
            IZQ = CEN + 1;
        } else {
            DER = CEN - 1;
        }
    }

    return BAN;
}
