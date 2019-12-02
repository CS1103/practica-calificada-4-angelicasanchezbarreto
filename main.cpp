
#include <algorithm>
#include "Image.cpp"

int main(){
    unsigned int w;
    unsigned int h;
    Image imagen;
    auto image = imagen.decode("../in.png", w, h);
    auto imageRed = imagen.filter(image, Red, w, h);
    auto imageGreen = imagen.filter(image, Green, w, h);
    auto imageBlue = imagen.filter(image, Blue, w, h);
    auto rotacion = imagen.rotarMatriz(image,w,h);

    imagen.imprimir(image,w,h);

    imagen.encode("../red_filter.png", imageRed, w, h);
    imagen.encode("../green_filter.png", imageGreen, w, h);
    imagen.encode("../blue_filter.png", imageBlue, w, h);
    imagen.encode("../rotate.png", rotacion, w, h);
    return 0;
}
