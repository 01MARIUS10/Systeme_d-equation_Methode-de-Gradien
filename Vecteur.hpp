#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include <iostream>
#include <vector>
#include "File.hpp"

using namespace std;

class Vecteur {
    private :
        vector<double> b;
        int lenth;
    public :
        Vecteur();
        Vecteur(int n);
        Vecteur(vector<double> v);
        Vecteur(File f,int n);
        ~Vecteur();
        
        vector<double>getVecteur();
        double getValue(int n);
        int getSize();
        void set();
        void clear();
        void setVecteur(int i,double val);
        void setDimension(int n);
        double module();
       void display();
};

#endif