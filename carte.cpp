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

