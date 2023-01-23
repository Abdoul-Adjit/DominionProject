#ifndef ADVENTURER_H
#define ADVENTURER_H
#include "../royaume_action.h"
#include "../Joueur.h"
#include "../plateaudejeu.h"

class adventurer : public royaume_action
{
private:
    
public:
    void play(Joueur* j, PlateauDeJeu* P);
    adventurer(std::string name, int cost,bool d, int action, int victory,
                int buy, int card, int money):royaume_action(name, cost,d,action,victory,buy,card,money){};
    ~adventurer()=default;
};





#endif