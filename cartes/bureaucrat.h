#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include "../royaume_action.h"
#include "../Joueur.h"
#include "../plateaudejeu.h"
#include "../tresor.h"
class bureaucrat : public royaume_action
{
private:
    
public:
    void play(Joueur* j, PlateauDeJeu* P);
    bureaucrat(std::string name, int cost,bool d, int action, int victory,
                int buy, int card, int money):royaume_action(name, cost,d,action,victory,buy,card,money){};
};





#endif