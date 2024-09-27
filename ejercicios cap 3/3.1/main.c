#include <stdio.h>
#include <stdlib.h>

/*Nomina.
El programa, al recibir los salarios de 15 profesores, obtiene el total de la
nomina de la universidad.

I: Variable de tipo entero.
SAL y NOM: variables de tipo real. */

void main (void)
{
    int I; variable I
    float SAL, NOM; variable SAL almacena el salario de un profesor, NOM variable que acumula el total de la nomina
    NOM = 0; inicializa la variable de NOM en 0, que servira para acumular la suma del salario
    for (I=1; I<=15; I++) se ejecuta 15 veces, una por cada profesor
{

    printf("\Ingrese el salario del profesor%d:\t",I); solicita al usuario que ingrese el salario de profesor correspodiente
    scanf("%f",&SAL); Lee el slario ingresado por el usuario y lo almacena en la variable
    NOM = NOM + SAL; suma al salario recien ingresado a la variable, NOM, acumula el total de la nomina
}
printf("\nEl total de la nomina es : %.2f", NOM); imprime el total acumulado de la nomina, y reiniciado para mostrar dos decimales
}
