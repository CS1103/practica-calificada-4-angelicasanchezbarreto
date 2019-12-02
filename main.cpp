
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

    // Un comment if you want to check buffer content
    /*for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w * 4; j += 4) {
            int r = image[i * w * 4 + j + 0]; // Red component
            int g = image[i * w * 4 + j + 1]; // Green component
            int b = image[i * w * 4 + j + 2]; // Blue component
            int a = image[i * w * 4 + j + 3]; // Alpha component
            std::cout << r << " ";
            std::cout << g << " ";
            std::cout << b << " ";
            std::cout << a << "|";
        }
        std::cout << endl;
    }
     */

    imagen.encode("../red_filter.png", imageRed, w, h);
    imagen.encode("../green_filter.png", imageGreen, w, h);
    imagen.encode("../blue_filter.png", imageBlue, w, h);
    imagen.encode("../rotate.png", rotacion, w, h);
    return 0;
}
