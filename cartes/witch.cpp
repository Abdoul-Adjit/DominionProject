#include<iostream>
#include<vector>
#include "witch.h"

void witch::play(Joueur* j, PlateauDeJeu* p){
    for(int i=0;i<p->getOrdreDeJeu().size();i++){
        if(p->getOrdreDeJeu().at(i)->getIdj()!=j->getIdj()){
            for(Carte* c : p->getCartesVicTre()){
                if(c->getType()==TypeCarte::Victory){
                    if(c->getNom()=="curse"){
                        p->getOrdreDeJeu().at(i)->defausser(c);
                        c->setCarteRestante(c->getCarteRestante()-1);
                        break;
                    }
                    
                }
            }
        }
    }
};