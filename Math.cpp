#include <vector>
#include <cmath>
#include "Math.hpp"

using namespace std;

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
    int n = (int)V.getVecteur().size();
    Vecteur B(n);
    for(int i=0;i<n;i++){
        B.setVecteur(i, Math::multiplication(A.getVectorLign(i),V));
    }
    return B;
}
