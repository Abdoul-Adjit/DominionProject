#include<iostream>
#include<vector>
#include "plateaudejeu.h"


PlateauDeJeu::PlateauDeJeu()
{
    //idp=idcount++;
    ordreDeJeu=std::vector<std::string>();
    cartesDeJeu=std::vector<Carte>();
    std::cout<< "Plateau de jeu n° "<< this -> getId()<< " a été créé \n";
    idp++;
}

int PlateauDeJeu::getId(){
    return idp;
}

void PlateauDeJeu::setOrdreDeJeu(std::vector<std::string> o){
    ordreDeJeu = o;
}

std::vector<std::string> PlateauDeJeu::getOrdreDeJeu(){
    return ordreDeJeu;
}

void PlateauDeJeu::setCartesDeJeu(std::vector<Carte> c){
    cartesDeJeu = c;
}

std::vector<Carte> PlateauDeJeu::getCartesDeJeu(){
    return cartesDeJeu;
}

void PlateauDeJeu::ajouterJoueur(std::string j){
    ordreDeJeu.push_back(j);
}

void PlateauDeJeu::ajouterCarte(Carte c){
    cartesDeJeu.push_back(c);
}

/*
void PlateauDeJeu::print(){
    std::cout<< "Plateau de jeu : " << idp << "\n";
    std::cout<< "Ordre de jeu : \n";
    for(int i = 0; i < ordreDeJeu.size(); i++){
        ordreDeJeu[i].print();
    }
    std::cout<< "Cartes de jeu : \n";
    for(int i = 0; i < cartesDeJeu.size(); i++){
        cartesDeJeu[i].print();
    }
}
*/