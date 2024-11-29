#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1) // Evita el padding en las estructuras para que coincidan con el formato BMP
typedef struct
{
    unsigned char  bfType[2];  // Tipo de archivo, debe ser "BM" para identificar un BMP
    unsigned int   bfSize;     // Tama�o total del archivo en bytes
    unsigned short bfReserved1; // Reservado, debe ser 0
    unsigned short bfReserved2; // Reservado, debe ser 0
    unsigned int   bfOffBits;  // Desplazamiento desde el inicio del archivo hasta los datos de imagen
} BITMAPFILEHEADER;

typedef struct
{
    unsigned int   biSize;         // Tama�o de esta estructura
    int            biWidth;        // Ancho de la imagen en p�xeles
    int            biHeight;       // Alto de la imagen en p�xeles
    unsigned short biPlanes;       // Siempre debe ser 1
    unsigned short biBitCount;     // Bits por p�xel, debe ser 24 para este programa
    unsigned int   biCompression;  // Tipo de compresi�n, 0 para BMP sin comprimir
    unsigned int   biSizeImage;    // Tama�o de los datos de imagen
    int            biXPelsPerMeter; // Resoluci�n horizontal en p�xeles por metro
    int            biYPelsPerMeter; // Resoluci�n vertical en p�xeles por metro
    unsigned int   biClrUsed;      // N�mero de colores usados
    unsigned int   biClrImportant; // N�mero de colores importantes
} BITMAPINFOHEADER;
#pragma pack(pop)

// Funci�n para convertir un p�xel en color (BGR) a escala de grises
unsigned char convertirAGris(unsigned char b, unsigned char g, unsigned char r)
{
    // F�rmula para calcular la intensidad en escala de grises
    return (unsigned char)(0.3 * r + 0.59 * g + 0.11 * b);
}

// Funci�n principal
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

    // Leer el encabezado de informaci�n BMP
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

    // Procesar cada fila de p�xeles de la imagen
    for (int i = 0; i < infoHeader.biHeight; i++)
    {
        for (int j = 0; j < infoHeader.biWidth; j++)
        {
            unsigned char bgr[3]; // Buffer para un p�xel (B, G, R)
            fread(bgr, 3, 1, input_file); // Leer el p�xel del archivo original

            // Convertir el p�xel a escala de grises
            unsigned char gris = convertirAGris(bgr[0], bgr[1], bgr[2]);

            // Escribir el p�xel convertido en el archivo de salida
            unsigned char gris_pixel[3] = {gris, gris, gris};
            fwrite(gris_pixel, 3, 1, output_file);
        }

        // Saltar el relleno del archivo de entrada
        fseek(input_file, padding, SEEK_CUR);

        // A�adir el relleno al archivo de salida
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

    // Llamar a la funci�n de conversi�n
    convertirBMPBlancoNegro(archivo_entrada, archivo_salida);

    return 0; // Salir del programa
}
