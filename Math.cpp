#include <vector>
#include <iostream>
#include <cmath>

#include <iomanip>
#include "Math.hpp"

using namespace std;

Math::Math(){};
Math::~Math(){};
double Math::multiplication(Vecteur A , Vecteur B){
    double s(0);
    int n = A.getSize();
    for(int i=0;i<n;i++){
        s+=A.getValue(i) * B.getValue(i);
    }
    return s;
}
Vecteur Math::multiplication(double alpha,Vecteur B){
    for(int i=0;i<B.getSize();i++){
        B.setVecteur(i,alpha*B.getValue(i));
    }
    return B;
};

Vecteur Math::soustract(Vecteur A,Vecteur B){
    int n = A.getSize();
    Vecteur V(n);
    for(int i=0;i<n;i++){
        V.setVecteur(i,A.getValue(i)-B.getValue(i));
    }
    return V;
}
Vecteur Math::multiplication(Matrice A , Vecteur V){
    int n = V.getSize();
    Vecteur B(n);
    for(int i=0;i<n;i++){
        B.setVecteur(i, Math::multiplication(A.getVectorLign(i),V));
    }
    return B;
}
void Math::EquationDisplay(Matrice matrice , Vecteur vect){
    cout<<endl<<"---------------AFFICHAGE DE L' EQUATION'------------------"<<endl;
    int dim = vect.getSize();
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            cout<< matrice.getMatrice()[i][j] <<"  X"<<j<<setw(10);
        }
        cout<<setw(8)<<"= "<<setw(3)<<vect.getVecteur()[i]<<endl;
    }
    cout<<"----------------------------------------------------------"<<endl;
};

