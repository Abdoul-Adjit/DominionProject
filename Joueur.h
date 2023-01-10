#ifndef JOUEUR_H
#define JOUEUR_H
#include "carte.h"
#include "maindecartes.h"
#include "plateaudejeu.h"

class Joueur{
    private:
        std::string id;
        int achats;
        int actions;
        std::vector<Carte> deck;
        MainDeCartes main;
        std::vector<Carte> defausse;
        //std::vector<PlateauDeJeu> plateaux; //static
        /*
            // Nom du joueur
            string name;
            // Points de victoire du joueur
            int victoryPoints;
            // Argent du joueur
            int money;
            // Actions disponibles pour le joueur
            int actions;
            // Achats disponibles pour le joueur
            int buys;
        */
    public:
        Joueur(std::string);
        void print();
        std::string getId();
        void finirTour();
        int getAchats();
        int getActions();
        std::vector<Carte> getDeck();
        std::vector<Carte> getDefausse();
        MainDeCartes getMain();
        //std::vector<PlateauDeJeu> getPlateaux();
        void setAchats(int);
        void jouerAI();
        void jouerJoueur();
        void setActions(int);
        void setDeck(std::vector<Carte>);
        void setDefausse(std::vector<Carte>);
        void setMain(MainDeCartes);
        //void setPlateaux(std::vector<PlateauDeJeu>);
        void commencerPartie();
        void jouerCarte(Carte);
        void jouer();
        void defausser();
        void acheterADeck();
        void piocher();
        void trierDeck();

        /* 
         // Constructeur
        Player(string name);
        // Méthode permettant au joueur de jouer son tour
        void playTurn();
        // Méthode permettant au joueur de gagner des points de victoire
        void gainVictoryPoints(int points);
        // Méthode permettant au joueur de gagner de l'argent
        void gainMoney(int amount);
        // Méthode permettant au joueur de gagner des actions
        void gainActions(int actions);
        // Méthode permettant au joueur de gagner des achats
        void gainBuys(int buys);
        // Accesseur en lecture pour le nom du joueur
        string getName();
        // Accesseur en lecture pour les points de victoire du joueur
        int getVictoryPoints();
        // Accesseur en lecture pour l'argent du joueur
        int getMoney();
        // Accesseur en lecture pour les actions disponibles pour le joueur
        int getActions();
        // Accesseur en lecture pour les achats disponibles pour le joueur
        int getBuys();
        */

};

#endif

