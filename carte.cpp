#include<iostream>
#include<vector>
#include "carte.h"


Carte::Carte(std::string n, int c, TypeCarte type){
    nom = n;
    cout = c;
    typeC = type;
}

std::string Carte::getNom(){
    return nom;
}
int Carte::getCout(){
    return cout;
}
<<<<<<< HEAD
void Carte::printc(){
    std::cout<< "Carte : " << nom << " Cout : " << cout << "\n";
}
=======

>>>>>>> 7f1ab773c99cf3de5361c7c980c05707b0f743c1
