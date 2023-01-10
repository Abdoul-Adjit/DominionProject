#ifndef CARTE_H
#define CARTE_H
#include<iostream>
class Carte{
    private:
        std::string nom;
        int cout;
        /* 
        // Nom de la carte
        string name;
        // Coût de la carte en argent
        int cost;
        // Type de la carte (Action, Argent, Victoire, etc.)
        CardType type;
        // Indicateur de disponibilité de la carte (présente ou non dans le jeu)
        bool available;
        */
    public:
        Carte(std::string, int);
        virtual std::string getNom();
        virtual int getCout();
        virtual void print();
        /*
        // Constructeur
        Card(string name, int cost, CardType type);
        // Accesseur en lecture pour le nom de la carte
        string getName();
        // Accesseur en lecture pour le coût de la carte en argent
        int getCost();
        // Accesseur en lecture pour le type de la carte
        CardType getType();
        // Accesseur en lecture pour l'indicateur de disponibilité de la carte
        bool isAvailable();
        // Accesseur en écriture pour l'indicateur de disponibilité de la carte
        void setAvailable(bool available);
        // Méthode virtuelle pure permettant d'exécuter l'effet de la carte
        virtual void play() = 0;
        */


};

#endif