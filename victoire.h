#ifndef VICTOIRE_H
#define VICTOIRE_H
#include "carte.h" 

class victoire : public Carte
{
private:
    int valeur;
public:
    victoire(/* args */);
    ~victoire();
    int getValeur();
    /* 
    // Constructeur
    VictoryCard(string name, int cost, int victoryPoints);
    // Méthode d'exécution de l'effet de la carte
    void play();
    */
};





#endif