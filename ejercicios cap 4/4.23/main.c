#include <stdio.h>

void trueque(int *x, int *y)
{
	int tem;
	tem = *x;
	*x = *y;
	*y = tem;
}

int suma(int x)
{
	return (x + x);
}
int main(void)
{
    int a = 5, b = 10;

    printf("Antes del trueque: a = %d, b = %d\n", a, b);
    trueque(&a, &b);
    printf("Después del trueque: a = %d, b = %d\n", a, b);

    int result = suma(3);
    printf("La suma de 3 es: %d\n", result);

    return 0;
}
