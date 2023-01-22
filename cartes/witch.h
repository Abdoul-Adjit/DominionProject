#ifndef WITCH_H
#define WITCH_H
#include "../royaume_action.h"
#include "../tresor.h"

class witch : public royaume_action
{
private:
    
public:
    
    witch(std::string name, int cost,bool d, int action, int victory,
                int buy, int card, int money):royaume_action(name, cost,d,action,victory,buy,card,money){};
            
    void play(Joueur* j, PlateauDeJeu* p){
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
   
};





#endif