#include <stdio.h>
#include <stdlib.h>

/* Cuenta caracteres.
El programa, al recibir como dato un archivo de texto y un caracter, cuenta el numero de veces que se encuentra el caracter en el
archivo. */

int cuenta(char); /* Prototipo de funci�n. */
void main(void)
{
    int res;
    char car;
    printf("\nIngrese el caracter que se va a buscar en el archivo: ");
    car = getchar();
    res = cuenta(car);
    if (res != -1)
    printf("\n\nEl caracter %c se encuentra en el archivo %d veces", car, res);
    else
        printf("No se pudo abrir el archivo");
}

int cuenta(char car)/* Esta funci�n determina cu�ntas veces se encuentra el caracter en el archivo. */
{
    int res, con = 0;
    char p;
    FILE *ar;
    if ((ar = fopen("arc.txt", "r")) != NULL) /* Se abre el archivo para lectura. */
    {
        while (p = getc(ar)) /* Se trabaja con el archivo mientras no se llegue al fin de este. */
        {
            p = getc(ar);
            if (p == car) /* Se realiza la comparacion de los caracteres. */
                con++;
        }
        fclose(ar);
        res = con;
    }
    else
        res = -1;
    return res;
}
