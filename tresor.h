#ifndef TRESOR_H
#define TRESOR_H
#include "carte.h" 

class tresor : public Carte
{
private:
    int valeur;
public:
    tresor(/* args */);
    ~tresor();
    int getValeur();
    /* 
    // Constructeur
    MoneyCard(string name, int cost, int money);
    // Méthode d'exécution de l'effet de la carte
    void play();
    */
};


#endif
