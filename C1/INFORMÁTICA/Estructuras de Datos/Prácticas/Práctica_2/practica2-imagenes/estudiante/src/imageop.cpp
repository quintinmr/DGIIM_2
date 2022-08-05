/**
 * @file imageop.cpp
 * @brief Fichero con definiciones para el resto de métodos de la clase Image
 */

#include <iostream>
#include <cmath>
#include <image.h>

#include <cassert>

// Invierte
void Image::Invert()
{
    int size = this->size();;
    for (int i=0; i<size; i++)
        this->set_pixel(i,255-this->get_pixel(i));
}

// Modifica el contraste de una Imagen .
void Image::AdjustContrast (byte in1, byte in2, byte out1, byte out2)
{

    const int M    = 255;
    double m1      = (double)(out1)/(in1);
    double m2      = (double)(out2-out1)/(in2-in1);
    double m3      = (double)(M-out2)/(M-in2);
    int size       = this->size();

    byte new_pixel;

    for (int k = 0; k < size ;k++) {

        if (this->get_pixel(k) < in1) new_pixel         = (byte) round(m1*this->get_pixel(k));
        else
            if (this->get_pixel(k) <= in2) new_pixel     = (byte) round(out1 + m2*(this->get_pixel(k)-in1));
            else
                if (this->get_pixel(k) <= M) new_pixel   = (byte) round(out2 + m3*(this->get_pixel(k)-in2));

        this->set_pixel(k, new_pixel);
    }

}

// Calcula la media de los píxeles de una imagen entera o de un fragmento de ésta.
double Image::Mean (int i, int j, int height, int width) const
{
    double suma = 0;
    int a       = i+height;
    int b       = j+width;

    for (int k = i; k < a; k++){
        for (int l = j; l < b; l++){

            suma +=this->get_pixel(k,l);
        }
    }

    double media = (double) suma/(height*width);

    return media;
}

// Genera un icono como reducción de una imagen.
Image Image::Subsample(int factor) const
{

        int filas_icono = get_rows()/factor;
        int cols_icono  = get_cols()/factor;

        Image subsample (filas_icono, cols_icono);

        for (int i = 0; i < filas_icono; i++){
            for (int j = 0; j < cols_icono; j++){
                subsample.set_pixel(i,j,round((this->Mean(i*factor,j*factor,factor,factor))));

            }
        }

        return subsample;

}

// Genera una subimagen.
Image Image::Crop(int nrow, int ncol, int height, int width) const
{
    Image subimagen(height, width);

    for (int i = 0; i < height; i++){
        for(int j = 0; j < width; j++)
            subimagen.set_pixel(i,j,this->get_pixel(i+nrow,j+ncol));
    }

    return subimagen;
}

// Genera una imagen aumentada 2x.
Image Image::Zoom2X(int nrow, int ncol, int side) const
{

    int topRows = nrow+side, topCols=ncol+side, zoomSize = 2*side-1;
    Image zoom(zoomSize, zoomSize);

    // Copiamos los elementos originales
    for (int i=nrow; i < topRows; i++)
        for (int j=ncol; j < topCols; j++)
            zoom.set_pixel(i * 2 - nrow * 2, j * 2 - ncol * 2, this->get_pixel(i, j));

    // Primera interpolación por columnas
    for (int i=0; i < zoomSize; i+=2)
        for (int j=1; j < zoomSize; j+=2)
            zoom.set_pixel(i, j,  round((zoom.get_pixel(i, j - 1) + zoom.get_pixel(i, j + 1)) / 2.0));

    // Segunda interpolación por filas
    for (int i=1; i < zoomSize; i+=2)
        for (int j=0; j < zoomSize; j+=2)
            zoom.set_pixel(i, j,  round( (zoom.get_pixel(i - 1, j) + zoom.get_pixel(i + 1, j)) / 2.0));

    // Ajuste de los elementos centrales
    for (int i=1; i < zoomSize; i+=2)
        for (int j=1; j < zoomSize; j+=2)
            zoom.set_pixel(i, j, round((zoom.get_pixel(i-1,j-1)+zoom.get_pixel(i-1, j+1)+
                                        zoom.get_pixel(i+1,j-1)+zoom.get_pixel(i+1,j+1)) / 4.0));

        return zoom;



}

// Copia el contenido de la imagen pasada como parámetro a la imagen que llama en la posición indicada.
// void Image::PaintIn(Image &in, int i, int j)

// Baraja pseudoaleatoriamente las filas de una imagen.
void Image::ShuffleRows(){

    const int p = 9973;
    int topRows = this->get_rows();
    byte ** aux = new byte * [topRows];

    for (int r=0; r<topRows; r++)
        aux[r] = img[(r*p)%topRows];

    for (int r=0; r<topRows; r++)
        img[r] = aux[r];

    delete [] aux;
    aux = nullptr;

}