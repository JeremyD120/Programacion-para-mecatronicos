#include <stdio.h>
#include <stdlib.h>

/* Suma positivos.
El programa, al recibir como datos N numeros enteros, obtiene la suma de losn
enteros positivos.

I, N, NUM, SUM: variables de tipo entero. */

void main(void)
{

	int i,n,num,sum; son variable de tipo entero
	sum = 0; acumula la suma de los numeros positivos, inicialmente se establece en 0
	printf("Ingrese el numero de datos:\t"); se le pide al usuario que ingrese los numeros que quiere procesar y almacena la cantidad de la variable
	scanf("%d",&n);
	for(i=1; i<=n; i++) este bucle se repite n, donde I empieza en 1 y en 1 hasta que alcanza n
	{
		printf("Ingrese el dato numero %d:\t", i); este solicita al usuario que ingrese el i
		scanf("%d",&num);el numero ingresado se almacena en la variable de num
		if(num>0) se agrega a la variable que suma el total de los numeros positivos
			sum=sum+num;

	}
	printf("\nLa suma de los numeros positivos es: %d",sum);imprime el valor final de sum
}
