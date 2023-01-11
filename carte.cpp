#include<iostream>
#include<vector>
#include "carte.h"


Carte::Carte(std::string n, int c){
    nom = n;
    cout = c;
}

std::string Carte::getNom(){
    return nom;
}
int Carte::getCout(){
    return cout;
}
void Carte::printc(){
    std::cout<< "Carte : " << nom << " Cout : " << cout << "\n";
}