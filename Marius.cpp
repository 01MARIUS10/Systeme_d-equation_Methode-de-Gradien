#include <iostream>
#include <cmath>
#include "Math.hpp"
#include "File.hpp"
#include "Matrice.hpp"
#include "Vecteur.hpp"

// on choisira comme epsilon
#define EPS 0.000001

// on choisira comme iteration maximal 
// on supossera que a cette limite , la suite diverge
#define MAX_ITERATION 3000

using namespace std;


int main(){

    cout<<endl<<"Veuillez bien verifier que les donnees de la matrice soit dans le 'matrice.txt' "<<endl;
    cout<<"Et aussi que les donnees du 4vecteur colonne du second membre soit dans le 'vecteur.txt' "<<endl;
    
    // gestion des fichier
    File f1("matrice.txt");
    File f2("vecteur.txt");

    // la dimension du systemes
    int n;
    cout<<endl<<"Entrer la taille du systeme d'equation = ";
    cin>>n;
    
    // importation des Matrices et Vecteurs depuis les fichiers
    Matrice A(f1,n);
    Vecteur b(f2,n);

    // Affichage de la matrice et du vecteur en  Systemes d'equations
    Math::EquationDisplay(A,b);

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
    int compter(0);

    // on supossera que a la limite de MAX_ITERATION , la suite diverge
    // et l'on sort de la boucle
    while(abs(R.module())>EPS && compter<MAX_ITERATION){
        
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

        compter++;
        
    }

    cout<<endl<<endl<<endl;

    if(compter<MAX_ITERATION){
        cout<<"La solution est X:"<<endl;
        X.display();
    }
    else{
        cout<<"A la "<<MAX_ITERATION<<" la valeur de X vaut:"<<endl;
        X.display();
    }
    
    return 0;
}