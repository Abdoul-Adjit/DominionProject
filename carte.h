#ifndef CARTE_H
#define CARTE_H
#include<iostream>
#include<vector>
#include "enumTypeC.h"


class Carte{
    protected:
        std::string nom; // Nom de la carte
        int cout;
        TypeCarte type; 
     
        // Type de la carte (Action, Argent, Victoire, etc.)
        // Indicateur de disponibilité de la carte (présente ou non dans le jeu)
        bool dispo;

    public:
   
        
        Carte(std::string n, int c, TypeCarte t, bool d);
        // Accesseur en lecture pour le nom de la carte
        std::string getNom();
    
        // Accesseur en lecture pour le coût de la carte en argent
        int getCout();
  
};

#endif