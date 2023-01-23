
#include<iostream>
#include<vector>
#include "humain.h"



Humain::Humain(std::string i):Joueur(i){
}



void Humain::setAchats(int a){
    this-> Joueur::setAchats(a);
}
void Humain::setActions(int a){
    this-> Joueur::setActions(a);
}






