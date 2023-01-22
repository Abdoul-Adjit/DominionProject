#include<iostream>
#include<vector>
#include "adventurer.h"

void adventurer::play(Joueur* j, PlateauDeJeu* P){
    int stock=0;
    while(stock<2){
        j->piocherCarte();
        if(j->getMain().at(j->getMain().size()-1)->getType()==TypeCarte::Victory){
            stock++;
        }else{
            j->defausser(j->getMain().at(j->getMain().size()-1));
            j->suppDeMain(j->getMain().at(j->getMain().size()-1));
        }
    }

};