/*!
 * @file image.h
 * @brief Cabecera para la clase Image
 */

#ifndef _IMAGEN_H_
#define _IMAGEN_H_


#include <cstdlib>
#include "imageIO.h"


typedef unsigned char byte;

enum LoadResult: unsigned char {
    SUCCESS,
    NOT_PGM,
    READING_ERROR
};


/**
  @brief T.D.A. Imagen

  Una instancia del tipo de dato abstracto Imagen nos permite almacenar imágenes de intensidades.

  El TDA Imagen proporciona además distintas herramientas para la manipulación de dichas imágenes.

  Para poder usar el TDA Imagen se debe incluir el fichero

  \#include <Imagen.h>

  @author Javier Abad
  @author Guillermo Gómez
  @date Septiembre 2021

**/

class Image{
    /**
      @page repImagen Representación del TDA Imagen .

      @section invImagen Invariante de representación.

      El invariante de representación (I.R) es una expresión lógica que
      indica si un objeto del tipo rep es un objteto abstracto o no.

      Cualquier objeto de la clase Imagen, debe cumplir:

      > rows >= 0

      > cols >= 0

      @section faImagen Función de abstracción


      La función de abstracción es una aplicación que establece una
      relación formal entre un objeto rep y  un objeto abstracto:

      > ***f_A: rep --> A***

      Es una aplicación sobreyectiva.


      Función de abstracción:

      > fA: rep  --->  Imagen

      > {byte ** img, rows, cols} ---> Imagen = {img[i][j] / 0<=i<rows, 0<=j<cols}

    **/

private :

    /**
      @brief Puntero a la imagen almacenada

      img apunta a un array-2D dinámico de bytes que contiene la imagen en sí. Almacena tantos bytes como pixeles tenga la imagen.

    **/
    byte **img;

    /**
      @brief Número de filas de la imagen.
    **/
    int rows;


    /**
      @brief Número de columnas de la imagen.
    **/
    int cols;


    /**
      @brief Initialize una imagen.
      @param nrows Número de filas que tendrá la imagen. Por defecto, 0
      @param ncols Número de colwnnas que tendrá la imagen. Por defecto, 0
      @param buffer Puntero a un buffer de datos con los que rellenar los píxeles de la imagen. Por defecto, 0.
      @pre filas >= O y columnas >= O
      @post Reserva memoria para almacenar la imagen y la prepara para usarse.
    **/
    void Initialize (int nrows= 0, int ncols= 0, byte *buffer= 0);

    /**
      @brief Lee una imagen PGM desde un archivo.
      @param file_path Ruta del archivo a leer
      @return LoadResult
    **/
    LoadResult LoadFromPGM(const char * file_path);

    /**
      @brief Copy una imagen .
      @param orig Referencia a la imagen original que vamos a copiar
      @pre Asume que no hay memoria reservada o se ha llamado antes a Destroy()
      @pre Asume this != &orig
    **/
    void Copy(const Image &orig);

    /**
      @brief Reserva o copia en memoria una imagen.
      @param nrows Número de filas que tendrá la imagen.
      @param ncols Número de colwnnas que tendrá la imagen.
      @param buffer Puntero a un buffer de datos con los que rellenar los píxeles de la imagen. Por defecto, 0.
      @pre nrows >= O y ncols >= O
      @post Reserva memoria para almacenar la imagen y la prepara para usarse.
    **/
    void Allocate(int nrows, int ncols, byte * buffer = 0);

    /**
      * @brief Destroy una imagen
      *
      * Libera la memoria reservada en la que se almacenaba la imagen que llama a la función.
      * Si la imagen estaba vacía no hace nada .
      */
    void Destroy();

public :

    /**
      * @brief Constructor por defecto .
      * @post Genera una instancia de la clase Imagen con O filas y O colunmas.
      * @return Imagen, el objeto imagen creado.
      */
    Image();

    /**
      * @brief Constructor con parámetros.
      * @param nrows Número de filas de la imagen.
      * @param ncols Número de columnas de la imagen.
      * @param value defecto Valor con el que inicializar los píxeles de la imagen . Por defecto O.
      * @pre n fils > O Y n_cols > O
      * @post La imagen creada es de n_fils y n_cols columnas. Estará inicializada al valor por defecto.
      * @return Imagen, el objeto imagen creado.
      */
    Image(int nrows, int ncols, byte value=0);

    /**
      * @brief Constructor de copias.
      * @param orig Referencia a la imagen original que se quiere copiar.
      * @return Imagen, el objeto imagen creado.
      */
    Image (const Image & orig);

    /**
      * @brief Operador de tipo destructor.
      * @return void
      * @post El objeto Imagen destruido no puede usarse salvo que se haga sobre él una operacion Imagen().
      */
    ~Image() ;

    /**
      * @brief Operador de asignación .
      * @param orig Referencia a la imagen original que desea copiarse.
      * @return Una referencia al objeto imagen modificado.
      * @post Destroy cualquier información que contuviera previamente la imagen que llama al operador de asignación.
      */
    Image & operator= (const Image & orig);

    /**
      * @brief Funcion para conocer si una imagen está vacía.
      * @return Si la imagen está vacía
      * @post la imagen no se modifica.
      */
    bool Empty() const;

    /**
      * @brief Filas de la imagen .
      * @return El número de filas de la imagen.
      * @post la imagen no se modifica.
      */
    int get_rows() const;

    /**
      * @brief Columnas de la imagen.
      * @return El número de columnas de la imagen.
      * @post la imagen no se modifica.
      */
    int get_cols() const;

    /**
      * @brief Devuelve el número de píxeles de la imagen.
      * @return número de píxeles de la imagen.
      * @post la imagen no se modifica.
      */
    int size() const;

    /**
      * @brief Asigna el valor valor al píxel (fil, col) de la imagen.
      * @param i Fila de la imagen en la que se encuentra el píxel a escribir .
      * @param j Columna de la imagen en la que se encuentra el píxel a escribir.
      * @param value Valor que se escribirá en el píxel (fil, col) .
      * @pre O <= fil < I . get_rows() II O <= col < I.get_cols() II O <= valor <= 255
      * @return void
      * @post El píxel (fil, col) de la imagen se modificará y contendrá valor.
      * Los demás píxeles permanecerán iguales.
      */
    void set_pixel (int i, int j, byte value);

    /**
      * @brief Consulta el valor del píxel (fil, col) de la imagen.
      * @param i Fila de la imagen en la que se encuentra el píxel a consultar.
      * @param j Columna de la imagen en la que se encuentra el píxel a consultar.
      * @pre O <= fil < I.Num_ Filas() II O <= col < I.Num Columnas()
      * @return el valor del píxel contenido en (fil,col)
      * @post La imagen no se modifica.
      */
    byte get_pixel (int i, int j) const;

    /**
      * @brief Consulta el valor del píxel k de la imagen desenrrollada.
      * @param k Índice del píxel
      * @pre 0 <= k < filas*columnas
      * @return el valor del píxel contenido en (k/filas,k%filas)
      * @post La imagen no se modifica.
      */
    byte get_pixel (int k) const;

    /**
      * @brief Asigna el valor valor al píxel k de la imagen desenrollada.
      * @param k Índice del píxel a escribir .
      * @param value Valor que se escribirá en el píxel k.
      * @pre 0 <= k < filas*columnas && O <= valor <= 255
      * @post El píxel k se modificará con el valor de value.
      */
    void set_pixel (int k, byte value);

    /**
      * @brief Almacena imágenes en disco.
      * @param file_path Ruta donde se almacenará la imagen.
      * @pre file path debe ser una ruta válida donde almacenar el fichero de salida.
      * @return Devuelve true si la imagen se almacenó con éxito y false en caso contrario.
      * @post La imagen no se modifica.
      */
    bool Save (const char * file_path) const;

    /**
      * @brief Carga en memoria una imagen de disco .
      * @param file_path path Ruta donde se encuentra el archivo desde el que cargar la imagen.
      * @pre file path debe ser una ruta válida que contenga un fichero . pgm
      * @return Devuelve true si la imagen se carga con éxito y false en caso contrario.
      * @post La imagen previamente almacenada en el objeto que llama a la función se destruye.
      */
    bool Load (const char * file_path);

    /**
     * @brief Invierte la imagen original.
     *
     * > Modifica los pixeles asignándoles el resultado de trasladar el pixel desde la posición p que ocupa a la que viene dada por la misma posición pero empezando desde el extremo contrario, 255 - p
     * @post La imagen ímplícita aparecerá invertda
     */
    void Invert();

    /**
     * @brief Modifica el contraste de una imagen
     * > Modifica el contraste de una imagen generando una imagen de niveles de gris con más contraste que la original. Para ello, se aplica lo que se conoce como: *estiramiento del histograma*, que consiste en la aplicación de una transformación lineal a trozos sobre los valores de los píxeles de la imagen. Dicha transformación lineal depende del valor de cada uno de los píxeles y se ha deducido su implementación de una gráfica aportada por el profesorado (se puede ver en mainpage.dox) a patir de la cual se han calculado las ecuaciones de las rectas de los trozos de la gráfica que, en función de los parámetros de entrada, determinarán los valores de los nuevos píxeles.
     * @param in1 Umbral inferior de la imagen de entrada
     * @param in2 Umbral superior de la imagen de entrada
     * @param out1 Umbral inferior de la imagen de salida
     * @param out2 Umbral superior de la imagen de salida
     * @pre 0 <= (in1, in2, out1, out2) <= 255
     * @pre in1 < in2
     * @pre out1 < out2
     * @post El objeto que llama a la función es modificado
     * */
    void AdjustContrast (byte in1, byte in2, byte out1, byte out2);

    /**
     * @brief  Calcula la media de los píxeles de una imagen entera o de un fragmento de esta.
     * @param i Fila inicial para hacer la media (esquina superior izquierda)
     * @param i Columna inicial para hacer la media (esquina superior izquierda)
     * @param height Número de filas
     * @param width Número de columnas
     * @pre 0 <= nrow < rows, 0 <= ncol < cols
     * @pre  0 < height <= rows - i, 0 < width <= cols - j
     * @returns La media de los pixeles redondeada por exceso
     * @post La media ha de ser un real positivo
     * */
    double Mean (int i, int j, int height, int width) const;

    /**
     * @brief Genera un icono como reducción de una imagen
     * > Obtenemos una nueva imagen con el tamaño del icono y modificamos sus pixeles de forma que cada pixel se obtiene como la media de los factor*factor pixeles que se obtienen al recorrer la matriz original.
     * @param factor Factor de reduccion
     * @pre factor > 0
     * @returns La imagen iconizada
     * @post La imagen no se modifica
     * @post La imagen resultante tendra tamaño int(rows/fcator) x int(cols/factor)
     */
    Image Subsample(int factor) const;

    /**
     * @brief Genera una subimagen, de tamaño menor o igual que la original
     * > Obtenemos una nueva imagen del tamaño especificado y asignamos a cada pixel de la nueva imagen el pixel correspondiente de la imagen implicita empezando desde la posición que se indica
     * @param nrow Fila inicial para recortar (esquina superior izquierda)
     * @param ncol Columna inicial para recortar (esquina superior izquierda)
     * @param height Número de filas
     * @param width Número de columnas
     * @pre 0 <= nrow < rows, 0 <= ncol < cols
     * @pre  0 < height <= rows - nrow, 0 < width <= cols - ncol
     * @returns Imagen con el recorte
     * @post El objeto que llama a la función no se modifica
     * */
    Image Crop(int nrow, int ncol, int height, int width) const;

    /**
     * @brief Genera una imagen aumentada 2x de una parte de la imagen original
     * > Obtenemos una nueva imagen del doble de tamaño, y asignamos a la nueva imagen los pixeles de la imagen anterior pero en una nueva posición (la correspondiente a duplicar la posición anterior). Posteriormente realizamos una primera interpolación por columnas asigando a los pixeles de las filas pares y columnas impares la media de los elementos que tienen a la derecha e izquierda. Luego hacemos una segunda interpolación por filas asignando a los pixeles de las filas impares y columnas pares la media de los elementos que tienen justo encima y debajo. Por último, nos encargamos de rellenar los elementos de las filas impares y columnas impares (centrales) con la media de los elementos que tienen en sus esquinas.
     * @param nrow Fila incial para ampliar (esquina superior izquierda)
     * @param ncol Columan incial para ampliar (esquina superior izquierda)
     * @param side lado de la imagen aumentada
     * @pre La matriz original debe ser cuadrada (rows == cols)
     * @pre 0 <= nrow < rows, 0 <= ncol < cols
     * @pre 0 < lado <= rows - nrow
     * @returns Imagen aumentada 2x
     * @post El objeto que llama a la función no se modifica
     * */
    Image Zoom2X(int nrow, int ncol, int side) const;

    // Copia el contenido de la imagen pasada como parámetro a la imagen que llama en la posición indicada.
    // void PaintIn(Image & in, int i, int j);

    /**
     * @brief Baraja las filas de una imagen
     * > Trabajamos con la representación interna. Contruimos un nuevo puntero a puntero a byte de tamaño rows en el que vamos asignando la posición de la fila correspondiente a la nueva posición que calculamos.
     * @post  La imagen implícita se modifica segun dicho barajado de las filas
     */

    void ShuffleRows();
} ;


#endif // _IMAGEN_H_

