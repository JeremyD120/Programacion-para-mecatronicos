#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos la estructura del alumno
typedef struct
{
    char nombre[50];
    float promedio;
    char carrera[50];
} Alumno;

// Variables globales
Alumno alumnos[100]; // Máximo 100 registros
int totalAlumnos = 0;

// Funciones principales
void crearArchivo(const char *nombreArchivo);
void abrirArchivo(const char *nombreArchivo);
void guardarArchivo(const char *nombreArchivo);
void buscarRegistro(const char *nombreBuscado);
void agregarRegistro();

int main()
{
    int opcion;
    char nombreArchivo[50], nombreBuscado[50];

    while (1)
    {
        printf("\n--- Menú Principal ---\n");
        printf("1. Crear nuevo archivo\n");
        printf("2. Abrir archivo existente\n");
        printf("3. Guardar archivo\n");
        printf("4. Buscar registro por nombre\n");
        printf("5. Agregar nuevo registro\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer

        switch (opcion)
        {
        case 1:
            printf("Ingrese el nombre del archivo a crear: ");
            scanf("%s", nombreArchivo);
            crearArchivo(nombreArchivo);
            break;
        case 2:
            printf("Ingrese el nombre del archivo a abrir: ");
            scanf("%s", nombreArchivo);
            abrirArchivo(nombreArchivo);
            break;
        case 3:
            printf("Ingrese el nombre del archivo a guardar: ");
            scanf("%s", nombreArchivo);
            guardarArchivo(nombreArchivo);
            break;
        case 4:
            printf("Ingrese el nombre a buscar: ");
            scanf("%s", nombreBuscado);
            buscarRegistro(nombreBuscado);
            break;
        case 5:
            agregarRegistro();
            break;
        case 6:
            printf("Saliendo del programa...\n");
            exit(0);
        default:
            printf("Opcion invalida. Intente de nuevo.\n");
        }
    }
    return 0;
}

// Implementación de funciones
void crearArchivo(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL)
    {
        printf("Error al crear el archivo.\n");
        return;
    }
    fclose(archivo);
    printf("Archivo '%s' creado con exito.\n", nombreArchivo);
}

void abrirArchivo(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }
    totalAlumnos = fread(alumnos, sizeof(Alumno), 100, archivo);
    fclose(archivo);
    printf("Archivo '%s' cargado con exito. Total de registros: %d\n", nombreArchivo, totalAlumnos);
}

void guardarArchivo(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL)
    {
        printf("Error al guardar el archivo.\n");
        return;
    }
    fwrite(alumnos, sizeof(Alumno), totalAlumnos, archivo);
    fclose(archivo);
    printf("Archivo '%s' guardado con éxito.\n", nombreArchivo);
}

void buscarRegistro(const char *nombreBuscado)
{
    int encontrado = 0;
    for (int i = 0; i < totalAlumnos; i++)
    {
        if (strcmp(alumnos[i].nombre, nombreBuscado) == 0)
        {
            printf("\nRegistro encontrado:\n");
            printf("Nombre: %s\n", alumnos[i].nombre);
            printf("Promedio: %.2f\n", alumnos[i].promedio);
            printf("Carrera: %s\n", alumnos[i].carrera);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado)
    {
        printf("No se encontro ningun registro con el nombre '%s'.\n", nombreBuscado);
    }
}

void agregarRegistro()
{
    if (totalAlumnos >= 100)
    {
        printf("No se pueden agregar mas registros. Limite alcanzado.\n");
        return;
    }
    printf("\n--- Agregar nuevo registro ---\n");
    printf("Ingrese el nombre: ");
    scanf("%s", alumnos[totalAlumnos].nombre);
    printf("Ingrese el promedio: ");
    scanf("%f", &alumnos[totalAlumnos].promedio);
    getchar(); // Limpiar buffer
    printf("Ingrese la carrera: ");
    fgets(alumnos[totalAlumnos].carrera, 50, stdin);
    alumnos[totalAlumnos].carrera[strcspn(alumnos[totalAlumnos].carrera, "\n")] = '\0'; // Quitar salto de línea
    totalAlumnos++;
    printf("Registro agregado con exito.\n");
}
