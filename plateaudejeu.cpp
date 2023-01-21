#include<iostream>
#include<vector>
#include "plateaudejeu.h"
#include "joueur.h"

int PlateauDeJeu::idcount=0;

PlateauDeJeu::PlateauDeJeu(){
    gameOver=false;
}


int PlateauDeJeu::getIdp(){
    return idp;
}


std::vector<Carte*> PlateauDeJeu::getCartesDeJeu(){
    return this->cartesDeJeu;
}

std::vector<Joueur*> PlateauDeJeu::getOrdreDeJeu(){
    return this->ordreDeJeu;
}
void PlateauDeJeu::setCartesDeJeu(std::vector<Carte*> c){
    this->cartesDeJeu=c;
}
void PlateauDeJeu::setOrdreDeJeu(std::vector<Joueur*> j){
    this->ordreDeJeu=j;
}

void PlateauDeJeu::lancer(){
}




/*mettrejoueurdansplateau(joueur j)
{
    this.addJoueur(j);
}
*/