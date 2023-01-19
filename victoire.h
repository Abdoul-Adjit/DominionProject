#ifndef VICTOIRE_H
#define VICTOIRE_H
#include "carte.h" 
#include "enumTypeC.h"
class victoire : public Carte
{
private:
    int valeur;
public:
    int getValeur();
    // Constructeur
    victoire(std::string name, int   cost, int money, bool d):Carte(name,cost, TypeCarte::Victory,d),valeur(money){};
    // Méthode d'exécution de l'effet de la carte
    ~victoire();
    void play();
    void printc();
    void description();
};


#endif