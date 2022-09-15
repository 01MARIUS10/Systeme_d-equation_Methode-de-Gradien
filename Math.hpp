#ifndef MATH_HPP
#define MATH_HPP

#include "Matrice.hpp"
using namespace std;

class Math{
public:
    Math();
    ~Math();
    static Vecteur soustract(Vecteur A, Vecteur B);
    static double multiplication(Vecteur A, Vecteur B);
    static Vecteur multiplication(double alpha, Vecteur B);
    static Vecteur multiplication(Matrice A, Vecteur V);
    static void EquationDisplay(Matrice matrice,Vecteur vect);
};
#endif