#ifndef TRESOR_H
#define TRESOR_H
#include "carte.h" 
#include "enumTypeC.h"
class tresor : public Carte
{
private:
    int valeur;
public:
    ~tresor();
    int getValeur();
    // Constructeur
    tresor(std::string name, int   cost, int money):Carte(name,cost, TypeCarte::Money){
        valeur = money;
    }
    // Méthode d'exécution de l'effet de la carte
    void play();

};


#endif
