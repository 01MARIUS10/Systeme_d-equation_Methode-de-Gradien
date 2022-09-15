#ifndef MATRICE_HPP
#define MATRICE_HPP

#include <iostream>
#include <vector>
#include "File.hpp"
#include "Vecteur.hpp"

using namespace std;

class Matrice {
    private :
        vector<vector<double>> matrice;
        int dim;
    public :
        Matrice(int n);
        Matrice(vector<vector<double>>M);
        Matrice(File f,int n);
        ~Matrice();
        vector<vector<double>> getMatrice();
        double getValueOfMatrice(int i,int j);
        Vecteur getVectorLign(int i);
        void setMatrice(int i,int j,double val);
        void setDimension(int n);
        Matrice transposer();
        
        void display();
};
#endif
