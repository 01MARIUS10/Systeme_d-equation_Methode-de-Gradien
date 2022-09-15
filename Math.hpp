#ifndef MATH_HPP
#define MATH_HPP

#include <iostream>
#include <vector>
#include "Vecteur.cpp"
#include "Matrice.cpp"

using namespace std;

class Math
{
public:
    Math();
    ~Math();
    static Vecteur soustract(Vecteur A, Vecteur B);
    static double multiplication(Vecteur A, Vecteur B);
    static Vecteur multiplication(double alpha, Vecteur B);
    static Vecteur multiplication(Matrice A, Vecteur V);
};

#endif;