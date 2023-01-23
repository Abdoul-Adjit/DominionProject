#include<iostream>
#include<vector>
#include "carte.h"

Carte::Carte(std::string n, int c, TypeCarte t, bool d){
    nom=n;
    cout=c;
    type =t;
    dispo=d;
 }

int Carte::getCout(){
    return this->cout;
}
std::string Carte::getNom(){
    return this-> nom;
}


TypeCarte Carte::getType(){
    return type;
}

int Carte::getCarteRestante(){
    return this->carteRestante;
}
void Carte::setCarteRestante(int a){
    this->carteRestante=a;
}