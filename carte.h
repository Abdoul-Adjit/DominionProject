#ifndef CARTE_H
#define CARTE_H
#include<iostream>
#include "enumTypeC.h"


class Carte{
    private:
        std::string nom;
        int cout;
     
        // Type de la carte (Action, Argent, Victoire, etc.)
        TypeCarte typeC;
        // Indicateur de disponibilité de la carte (présente ou non dans le jeu)
        bool dispo;
    
    public:
   
        
        // Constructeur
        Carte(std::string name, int cost, TypeCarte type);
        // Accesseur en lecture pour le nom de la carte
        std::string getNom();
        // Accesseur en lecture pour le coût de la carte en argent
        int getCout();
        // Accesseur en lecture pour le type de la carte
        TypeCarte getType();
        // Accesseur en lecture pour l'indicateur de disponibilité de la carte
        bool getDispo();
        // Accesseur en écriture pour l'indicateur de disponibilité de la carte
        void setDispo(bool available);
        // Méthode virtuelle pure permettant d'exécuter l'effet de la carte
        virtual void play() = 0;
        


};

#endif