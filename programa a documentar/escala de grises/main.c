#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1) // Evita el padding en las estructuras para que coincidan con el formato BMP
typedef struct
{
    unsigned char  bfType[2];  // Tipo de archivo, debe ser "BM" para identificar un BMP
    unsigned int   bfSize;     // Tamaño total del archivo en bytes
    unsigned short bfReserved1; // Reservado, debe ser 0
    unsigned short bfReserved2; // Reservado, debe ser 0
    unsigned int   bfOffBits;  // Desplazamiento desde el inicio del archivo hasta los datos de imagen
} BITMAPFILEHEADER;

typedef struct
{
    unsigned int   biSize;         // Tamaño de esta estructura
    int            biWidth;        // Ancho de la imagen en píxeles
    int            biHeight;       // Alto de la imagen en píxeles
    unsigned short biPlanes;       // Siempre debe ser 1
    unsigned short biBitCount;     // Bits por píxel, debe ser 24 para este programa
    unsigned int   biCompression;  // Tipo de compresión, 0 para BMP sin comprimir
    unsigned int   biSizeImage;    // Tamaño de los datos de imagen
    int            biXPelsPerMeter; // Resolución horizontal en píxeles por metro
    int            biYPelsPerMeter; // Resolución vertical en píxeles por metro
    unsigned int   biClrUsed;      // Número de colores usados
    unsigned int   biClrImportant; // Número de colores importantes
} BITMAPINFOHEADER;
#pragma pack(pop)

// Función para convertir un píxel en color (BGR) a escala de grises
unsigned char convertirAGris(unsigned char b, unsigned char g, unsigned char r)
{
    // Fórmula para calcular la intensidad en escala de grises
    return (unsigned char)(0.3 * r + 0.59 * g + 0.11 * b);
}

// Función principal
void convertirBMPBlancoNegro(const char *input_filename, const char *output_filename)
{
    // Abrir el archivo BMP de entrada
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL)
    {
        fprintf(stderr, "No se puede abrir el archivo %s\n", input_filename);
        return;
    }

    // Leer el encabezado del archivo BMP
    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, input_file);

    // Leer el encabezado de información BMP
    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, input_file);

    // Validar que el archivo sea un BMP de 24 bits
    if (fileHeader.bfType[0] != 'B' || fileHeader.bfType[1] != 'M' || infoHeader.biBitCount != 24)
    {
        fprintf(stderr, "El archivo no es un BMP de 24 bits\n");
        fclose(input_file);
        return;
    }

    // Abrir el archivo de salida para escribir la imagen convertida
    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL)
    {
        fprintf(stderr, "No se puede crear el archivo %s\n", output_filename);
        fclose(input_file);
        return;
    }

    // Escribir los encabezados al archivo de salida
    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, output_file);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, output_file);


    int padding = (4 - (infoHeader.biWidth * 3) % 4) % 4;

    // Procesar cada fila de píxeles de la imagen
    for (int i = 0; i < infoHeader.biHeight; i++)
    {
        for (int j = 0; j < infoHeader.biWidth; j++)
        {
            unsigned char bgr[3]; // Buffer para un píxel (B, G, R)
            fread(bgr, 3, 1, input_file); // Leer el píxel del archivo original

            // Convertir el píxel a escala de grises
            unsigned char gris = convertirAGris(bgr[0], bgr[1], bgr[2]);

            // Escribir el píxel convertido en el archivo de salida
            unsigned char gris_pixel[3] = {gris, gris, gris};
            fwrite(gris_pixel, 3, 1, output_file);
        }

        // Saltar el relleno del archivo de entrada
        fseek(input_file, padding, SEEK_CUR);

        // Añadir el relleno al archivo de salida
        unsigned char padding_bytes[3] = {0, 0, 0};
        fwrite(padding_bytes, padding, 1, output_file);
    }

    // Cerrar ambos archivos
    fclose(input_file);
    fclose(output_file);

    printf("Imagen convertida a blanco y negro y guardada en %s\n", output_filename);
}


int main(int argc, char *argv[])
{
    // Nombres de los archivos de entrada y salida
    const char *archivo_entrada = "avion.bmp";
    const char *archivo_salida = "avion_bn.bmp";

    // Llamar a la función de conversión
    convertirBMPBlancoNegro(archivo_entrada, archivo_salida);

    return 0; // Salir del programa
}
