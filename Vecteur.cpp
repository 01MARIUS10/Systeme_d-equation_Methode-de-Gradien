#include <vector>
#include <cmath>
#include "Vecteur.hpp"
#include "File.hpp"

using namespace std;

Vecteur::Vecteur(){
    int n;
    cout<<endl<<endl<<"creation d'une vecteur "<<endl;
    cout<<"veuillez entrer la taille:";
    cin>>n;
    lenth=n;
    double tmp(0);
    cout<<"entrer la valeur du vecteur X";
    for(int i=0;i<n;i++){
        cout<<"X"<<i<<" = ";
        cin>>tmp;
        b.push_back(tmp);
        tmp=0;
    }
    cout<<endl;
}
Vecteur::Vecteur(int n){
    lenth=n;
    for(int i=0;i<n;i++){
        b.push_back(0);
    }
}
Vecteur::Vecteur(vector<double> v){
    b = v;
    lenth = (int)v.size();
};
Vecteur::Vecteur(File f,int n){
   lenth=n;
    b = f.getVectorFromFile(lenth);
};
Vecteur::~Vecteur(){};
vector<double> Vecteur::getVecteur(){
    return b;
};
double Vecteur::getValue(int i){
    return b[i];
};
int Vecteur::getSize(){
    return (int)b.size();
}
void Vecteur::setVecteur(int i,double val){
    b[i] = val; 
};
void Vecteur::setDimension(int n){
    lenth = n;
};
void Vecteur::set(){
    int n = (int)b.size();
    cout<<"set du vecteur "<<endl;
    double tmp(0);
    cout<<"entrer la valeur du vecteur X"<<endl;
    for(int i=0;i<n;i++){
        cout<<"X"<<i<<" = ";
        cin>>tmp;
        setVecteur(i,tmp);
        tmp=0;
    }
}
void Vecteur::clear(){
    for(int i=0;i<lenth;i++){
        b[i]=0;;
    }
};

double Vecteur::module(){
    double m(0);
    for(int i=0;i<lenth;i++){
        m+=pow(this->getValue(i),2);
    }
    return sqrt(m);
}


void Vecteur::display(){
    cout<<"----Display vector --------"<<endl;
    cout<<"( ";
    for(int i=0;i<lenth;i++){
        cout<<b[i]<<" ";
    }
    cout<<")"<<endl;
}