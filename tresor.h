#ifndef TRESOR_H
#define TRESOR_H
#include "carte.h" 
#include "enumTypeC.h"
class tresor : public Carte
{
private:
    int valeur;
public:
    
    int getValeur();
    // Constructeur
    tresor(std::string name, int cost, int money, bool d):Carte(name,cost, TypeCarte::Money,d),valeur(money){};
    // Méthode d'exécution de l'effet de la carte
    ~tresor()=default;
    void printc();
    void description();
    int getCout();
};


#endif
