#ifndef ROYAUMEACTION_H
#define ROYAUMEACTION_H
#include "royaume.h"
#include "royaume_effet.h"
#include "plateaudejeu.h"
class royaume_action : public royaume
{
private:
    
    // Nombre d'actions supplémentaires accordées par la carte
    int actionBonus;
    // Nombre de points de victoire accordés par la carte
    int victoryPointBonus;
    // Nombre d'achats supplémentaires accordés par la carte
    int buyBonus;
    // Nombre de cartes supplémentaires accordées par la carte
    int cardBonus;
    // Nombre d'argent supplémentaire accordé par la carte
    int moneyBonus;
   
public:

    
    // Constructeur
    royaume_action(std::string name, int cost,bool d, int action, int victory,
                int buy, int card, int money):royaume(name, cost,d),actionBonus(action), victoryPointBonus(victory),buyBonus(buy),cardBonus(card),moneyBonus(money){};
    // Méthode d'exécution de l'effet de la carte
    virtual void play(Joueur* j, PlateauDeJeu* P){j->getAchats(); P->getCartesDeJeu();};
    int getactionBonus();
    int getvictoryPointBonus();
    int getbuyBonus();
    int getcardBonus();
    int getmoneyBonus();
    ~royaume_action()=default;


};


#endif