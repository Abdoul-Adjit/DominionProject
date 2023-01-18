
#include<iostream>
#include<vector>
#include "humain.h"



Humain::Humain(std::string i):Joueur(i){
}


void Humain::printh(){

    this -> Joueur::printj();
}

void Humain::setAchats(int a){
    this-> Joueur::setAchats(a);
}
void Humain::setActions(int a){
    this-> Joueur::setActions(a);
}
void Humain::setDeck(std::vector<Carte> d){
    this-> Joueur::setDeck(d);
}
void Humain::setDefausse(std::vector<Carte> d){
    this-> Joueur::setDefausse(d);
}
void Humain::setMain(MainDeCartes m){
    this-> Joueur::setMain(m);
}






