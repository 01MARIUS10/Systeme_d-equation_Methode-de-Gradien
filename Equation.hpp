#ifndef EQUATION_HPP
#define EQUATION_HPP

#include <string>
#include <iostream>
#include <vector>
#include "Matrice.hpp"
#include "Vecteur.hpp"

using namespace std;

class Equation
{
    public:
        Equation();
        static void EquationDisplay(Matrice matrice,Vecteur vect);
};

#endif