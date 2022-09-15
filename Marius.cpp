#include <iostream>
#include <cmath>
#include "Math.hpp"
#include "File.hpp"
#include "Matrice.hpp"
#include "Vecteur.hpp"
#include "Equation.hpp"

#define EPS 0.000001

using namespace std;


int main(){

    cout<<"Veuillez bien verifier que les donnees de la matrice soit dans le matrice.txt "<<endl;
    cout<<"Et aussi que les donnees de la matrice colonne du second membre soit dans le vecteur.txt "<<endl;
    
    // gestion des fichier
    File f1("matrice.txt");
    File f2("vecteur.txt");

    // la dimension du systemes
    int n;
    cout<<"Entrer la taille du systeme d'equation = ";
    cin>>n;
    
    // importation des Matrices et Vecteurs depuis les fichiers
    Matrice A(f1,n);
    Vecteur b(f2,n);

    // Affichage de la matrice et du vecteur en  Systemes d'equations
    Equation::EquationDisplay(A,b);

    //debut de l'algorithme ,descente du gradient
    // declaration des variables
    Vecteur X(n);  /*la valeur de la suite Xn au  n eme iteration*/
    Vecteur AX(n); /*une variable temporaire pour stoquer le produit de la matrice A par X*/
    Vecteur R(n);  /*le vecteur Residus ,a reduire*/
    Vecteur tmp(n);/**/
    Vecteur Z(n); /* le vecteur Z=-AR */

    // demander la valeur initiale pour la suite X
    X.set();

    AX = Math::multiplication(A,X);
    R = Math::soustract(b,AX);
    
    double alpha(0);

    while(abs(R.module())>EPS){
        
        alpha=0;
        Z.clear();
        // Z = A*R
        Z = Math::multiplication(A,R);
        // Z = -Z
        Z = Math::multiplication(-1,Z);
        
        alpha = (pow(R.module(),2))/ Math::multiplication(Z,R);
      
        // X = X - alpha*R
        X = Math::soustract(X,  Math::multiplication(alpha,R));
        // R = R - alpha*R
        R = Math::soustract(R,  Math::multiplication(alpha,Z));
        
    }
    cout<<endl<<endl<<endl;
    cout<<"La solution est X:"<<endl;
    X.display();
    return 0;
}