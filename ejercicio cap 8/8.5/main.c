#include <stdio.h>
#include <string.h>

/* Uniones. El programa muestra la manera como se declara una uni�n, as� como la forma de
?acceso a los campos de las variables de tipo uni�n tanto para asignaci�n
?de valores como para lectura y escritura. */

union datos
{
    char celular[15];
    char correo[20];
};

typedef struct
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    union datos personales;
} alumno;

void Lectura(alumno *a); /* Prototipo de funci�n. */

int main(void)
{
    alumno a1 = {120, "Maria", "Contabilidad", 8.9, {"5-158-40-50"}}, a2, a3;

    /* Para que puedas observar las diferentes formas en que los campos de las
    ?variables de tipo estructura alumnoreciben valores, ingresamos los valores
    ?de los campos de tres formas diferentes. Los campos de a1reciben valores
    ?directamente, los campos de a2se leen en el programa principal, y los campos
    ?de a3reciben valores a trav�s de una funci�n. */

    printf("Alumno 2\n");
    printf("Ingrese la matricula: ");
    scanf("%d", &a2.matricula);
    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(a2.nombre);
    fflush(stdin);
    printf("Ingrese la carrera: ");
    gets(a2.carrera);
    printf("Ingrese el promedio: ");
    scanf("%f", &a2.promedio);
    fflush(stdin);

    printf("Ingrese el correo electronico: ");
    gets(a2.personales.correo);

    printf("Alumno 3\n");
    Lectura(&a3); /* Se llama a una funci�n para leer los campos de la variable a3. */

    /* Impresi�n de resultados. */
    printf("\nDatos del alumno 1\n");
    printf("%d\n", a1.matricula);
    puts(a1.nombre);
    puts(a1.carrera);
    printf("%.2f\n", a1.promedio);
    puts(a1.personales.celular);

    printf("\nDatos del alumno 2\n");
    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    puts(a2.personales.celular);

    printf("\nDatos del alumno 3\n");
    printf("%d\n", a3.matricula);
    puts(a3.nombre);
    puts(a3.carrera);
    printf("%.2f\n", a3.promedio);
    puts(a3.personales.celular);

    return 0;
}

void Lectura(alumno *a)
{
    printf("\nIngrese la matricula: ");
    scanf("%d", &(a->matricula));
    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets(a->nombre);
    fflush(stdin);
    printf("Ingrese la carrera: ");
    gets(a->carrera);
    printf("Ingrese el promedio: ");
    scanf("%f", &(a->promedio));
    fflush(stdin);
    printf("Ingrese el telefono celular: ");
    gets(a->personales.celular);
}
