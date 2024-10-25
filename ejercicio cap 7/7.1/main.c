#include <stdio.h>

/*Funciones para el manejo de caracteres de la biblioteca stdio.h */

void main(void)
{
char P1, P2, P3 = '$';
	/*Declaracion de variables tipo caracter P1, P2, P3. Observa que a P3 se le asigna el simbolo $. */
	printf("\nIngrese un caracter: ");
	P1=getchar();		/* Se utiliza la funcion getchar para leer un caracter. */
	putchar(P1); 		/* Se utiliza la funcionj putchar para escribir un caracter. */
	printf("\n");
	fflush(stdin);
printf("\nEl caracter P3 ES: ");
putchar (P3);
/* Se utiliza la funcion putchar para escribir el caracter almacenado en P3. */
printf("\n");
printf("\nIngrese otro caracter: ");
fflush(stdin);
scanf("%c", &P2);
/* Se puede uilizar scanf con el formato de variable %c para leer un caracter. */
printf("%c, P2");
/* Se puede utilizar printf con el formato de variable %c para escribir un caracter. */
}
