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
    return cout;
}

std::string Carte::getNom(){
    return this-> nom;
}
/*void Carte::printc(){
    std::cout<< "Carte : " << nom << " Cout : " << cout << "\n";
}*/
