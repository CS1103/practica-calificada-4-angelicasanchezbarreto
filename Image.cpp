//
// Created by lica-pc on 12/2/19.
//

#include "Image.h"
#include "lodepng.h"
#include <iostream>
#include <vector>
#include <thread>
#include <cmath>
#include <iomanip>

vector<unsigned char> Image::decode(string_view filename, unsigned int& width, unsigned int& height) {

    vector<unsigned char> result;
    unsigned error = lodepng::decode(result, width, height, filename.data());
    if (error) {
        cerr << "decoder error " << error << ": " << lodepng_error_text(error) << endl;
    }
    return result;
}

void Image::encode(string_view filename, vector<unsigned char>& image, unsigned width, unsigned height) {
    unsigned error = lodepng::encode(filename.data(), image, width, height);
    if (error) {
        cout << "encoder error " << error << ": " << lodepng_error_text(error) << endl;
    }
}


vector<unsigned char> Image::filter(vector<unsigned char> &image, colores color, unsigned int w, unsigned int h) {
    vector<unsigned char> new_image;
    int r,g,b,a;
    for (unsigned int i = 0; i < h; i++) {
        for (unsigned int j = 0; j < w * 4; j += 4) {
            r = image[i * w * 4 + j + 0]; // Red component
            g = image[i * w * 4 + j + 1]; // Green component
            b = image[i * w * 4 + j + 2]; // Blue component
            a = image[i * w * 4 + j + 3]; // Alpha component
            switch(color){
                case 0:
                    g = image[0]; // Green component
                    b = image[0]; // Blue component
                    break;
                case 1:
                    r = image[0]; // Red component
                    b = image[0]; // Blue component
                    break;
                case 2:
                    r = image[0]; // Red component
                    g = image[0]; // Green component
                    break;
            }
            new_image.push_back(r);
            new_image.push_back(g);
            new_image.push_back(b);
            new_image.push_back(a);
        }
    }
    return new_image;
}



vector<vector<unsigned char>> Image::convertir_a_matriz(vector<unsigned char> new_image, unsigned int w, unsigned h){
    vector<vector<unsigned char>> lab;
    for (auto it = new_image.begin() ; it < new_image.end();){
        for(unsigned int i=0;i<h;i++){
            vector<unsigned char> vec;
            for(unsigned int j=0;j<w;j++){
                vec.push_back(*it);
                it++;
            }
            lab.push_back(vec);
        }
    }
    return lab;
}


vector<unsigned char> Image::obtenerVector(vector<unsigned char> image, unsigned int w, unsigned h){
    vector<unsigned char> new_image;
    int r,g,b,a;
    for (unsigned int i = 0; i < h; i++) {
        for (unsigned int j = 0; j < w * 4; j += 4) {
            r = image[i * w * 4 + j + 0]; // Red component
            g = image[i * w * 4 + j + 1]; // Green component
            b = image[i * w * 4 + j + 2]; // Blue component
            a = image[i * w * 4 + j + 3]; // Alpha component
            new_image.push_back(r);
            new_image.push_back(g);
            new_image.push_back(b);
            new_image.push_back(a);
        }
    }
    return new_image;
}


vector<unsigned char> Image::rotateImage(vector<unsigned char> &image2, unsigned int w, unsigned int h) {
    vector<unsigned char> image = obtenerVector(image2, w, h);

    vector<Matriz> vecMatriz;
    Matriz matrix;
    for (auto it = image.begin(); it != image.end();) {
        matrix.r = *it;
        matrix.g = *it + 1;
        matrix.b = *it + 2;
        matrix.a = *it + 3;
        it = it + 4;
        vecMatriz.push_back(matrix);
    }

    vector<unsigned char> resultado;
    int r, g, b, a;
    rotate(vecMatriz.begin(), vecMatriz.begin() + 5, vecMatriz.end());
    for (auto it = vecMatriz.begin(); it != vecMatriz.end();) {
        r = it->r;
        g = it->g;
        b = it->b;
        a = it->a;
        resultado.push_back(r);
        resultado.push_back(g);
        resultado.push_back(b);
        resultado.push_back(a);
        it++;
    }
    return resultado;
}

void Image::imprimir(vector<unsigned char> image, unsigned int w, unsigned int h){
    for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w * 4; j += 4) {
            int r = image[i * w * 4 + j + 0]; // Red component
            int g = image[i * w * 4 + j + 1]; // Green component
            int b = image[i * w * 4 + j + 2]; // Blue component
            int a = image[i * w * 4 + j + 3]; // Alpha component
            std::cout << right << setw(4) << r << " ";
            std::cout << right << setw(4) << g << " ";
            std::cout << right << setw(4) << b << " ";
            std::cout << right << setw(4) << a << "|";
        }
        std::cout << endl;
    }
}




