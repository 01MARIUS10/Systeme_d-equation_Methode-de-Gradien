#include "Equation.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include "math.h"

using namespace std;

void Equation::EquationDisplay(Matrice matrice , Vecteur vect){
    cout<<endl<<"-------AFFICHAGE DE L' EQUATION'----------"<<endl;
    int dim = (int)matrice.getMatrice().size();
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            cout<< matrice.getMatrice()[i][j] <<"  X"<<j<<setw(10);
        }
        cout<<setw(8)<<"= "<<setw(3)<<vect.getVecteur()[i]<<endl;
    }
    cout<<"----------------------------------------"<<endl;
};
