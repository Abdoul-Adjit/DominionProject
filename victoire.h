#ifndef VICTOIRE_H
#define VICTOIRE_H
#include "carte.h" 
#include "enumTypeC.h"
class victoire : public Carte
{
private:
    int valeur;
public:
    ~victoire();
    int getValeur();
    // Constructeur
    victoire(std::string name, int   cost, int money):Carte(name,cost, TypeCarte::Victory){
        valeur = money;
    }
    // Méthode d'exécution de l'effet de la carte
    void play();

};


#endif