#ifndef ROYAUMEACTION_H
#define ROYAUMEACTION_H
#include "royaume.h"
#include "royaume_effet.h"
class royaume_action : public royaume, public royaume_effet
{
private:
    /* 
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
   */
public:
    royaume_action(/* args */);
    ~royaume_action();
    /*
    // Constructeur
    ActionCard(string name, int cost, int actionBonus, int victoryPointBonus,
                int buyBonus, int cardBonus, int moneyBonus);
    // Méthode d'exécution de l'effet de la carte
    void play();

    */
};


#endif