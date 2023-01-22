#ifndef CARTE_H
#define CARTE_H
#include<iostream>
#include<vector>
#include "enumTypeC.h"

class PlateauDeJeu;
class Joueur;
class Carte{
    protected:
        std::string nom; // Nom de la carte
        int cout;
        TypeCarte type; 
        int carteRestante;
        // Type de la carte (Action, Argent, Victoire, etc.)
        // Indicateur de disponibilité de la carte (présente ou non dans le jeu)
        bool dispo;

    public:
   
        
        Carte(std::string n, int c, TypeCarte t, bool d);
        // Accesseur en lecture pour le nom de la carte
        std::string getNom();
        int getCout();
        // Accesseur en lecture pour le coût de la carte en argent
        TypeCarte getType();
        bool getdispo();
        void setCarteRestante(int);
        int getCarteRestante();
  
};

#endif