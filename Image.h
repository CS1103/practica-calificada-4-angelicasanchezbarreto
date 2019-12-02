//
// Created by lica-pc on 12/2/19.
//

#ifndef PC4_IMAGE_H
#define PC4_IMAGE_H

#include "extras.h"


struct Image {

    Image()=default;

    vector<unsigned char> decode(string_view filename, unsigned int& width, unsigned int& height);
    void encode(string_view filename, vector<unsigned char>& image, unsigned width, unsigned height);
    vector<unsigned char> filter(vector<unsigned char> &image, colores color, unsigned int w, unsigned int h);
    vector<vector<unsigned char>> convertir_a_matriz(vector<unsigned char> new_image, unsigned int w, unsigned h);
    vector<unsigned char> obtenerVector(vector<unsigned char> image, unsigned int w, unsigned h);
    void imprimir(vector<unsigned char> image, unsigned int w, unsigned int h);
    vector<unsigned char> rotateImage(vector<unsigned char> &image2, unsigned int w, unsigned int h);

    };


#endif //PC4_IMAGE_H
