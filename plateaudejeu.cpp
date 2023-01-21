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

void PlateauDeJeu::setCartesVicTre(std::vector<Carte*> c){
    this->cartesVicTre=c;
}

std::vector<Carte*> PlateauDeJeu::getCartesVicTre(){
    return this->cartesVicTre;
}

bool PlateauDeJeu::veriferVictoire(){
    int a=0;
    for(Carte* c : this->getCartesVicTre()){
        if(c->getNom()=="province"){
            if(c->getCarteRestante()==0){
                return true;
            }
        }
        if(c->getCarteRestante()==0){
            a+=1;
        }
    }
    for(Joueur* j : this->getOrdreDeJeu()){
        if(j->getVictoryPoints()>=30){
            return true;
        }
    }  
    if(a>=3){
        return true;
    }
    return false;
}

/*mettrejoueurdansplateau(joueur j)
{
    this.addJoueur(j);
}
*/