#include<iostream>
#include<vector>
#include "bureaucrat.h"

void bureaucrat::play(Joueur* j, PlateauDeJeu* p){
    for(int i =0;i<p->getCartesVicTre().size();i++){
        if(p->getCartesVicTre().at(i)->getType()==TypeCarte::Money){
            if(p->getCartesVicTre().at(i)->getCout()==3 && p->getCartesVicTre().at(i)->getCarteRestante()>0){
                p->getCartesVicTre().at(i)->setCarteRestante(p->getCartesVicTre().at(i)->getCarteRestante()-1);
                j->addToDeck(p->getCartesVicTre().at(i));
            }
        }
    }
    for(int i=0;i<p->getOrdreDeJeu().size();i++){
        if(p->getOrdreDeJeu().at(i)->getIdj()!=j->getIdj()){
            for(Carte* c : p->getOrdreDeJeu().at(i)->getMain()){
                if(c->getType()==TypeCarte::Victory){
                    p->getOrdreDeJeu().at(i)->addToDeck(c);
                    p->getOrdreDeJeu().at(i)->suppDeMain(c);
                    break;
                }
            }
        }
    }
};