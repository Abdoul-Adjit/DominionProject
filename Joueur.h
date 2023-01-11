#ifndef JOUEUR_H
#define JOUEUR_H
#include "carte.h"
#include "maindecartes.h"

class Joueur{
    private:
        static int idc;
        int id;
        std::string nom;
        int achats;
        int actions;
        int argent;
        std::vector<Carte> deck;
        MainDeCartes main;
        std::vector<Carte> defausse;
        int victoryPoints;
    public:
        Joueur(std::string);
        int getIdj();
        void setArgent(int);
        int getArgent();
        void printj();
        std::string getNom();
        void gainVictoryPoints(int);   // Méthode permettant au joueur de gagner des points de victoire
        void gainMoney(int);           // Méthode permettant au joueur de gagner de l'argent
        void gainActions(int);         // Méthode permettant au joueur de gagner des actions
        void gainAchats(int);          // Méthode permettant au joueur de gagner des achats
        void piocher(int);            
        void finirTour();
        int getAchats();
        int getActions();
        void setVictoryPoints(int);
        int getVictoryPoints();
        std::vector<Carte> getDeck();
        std::vector<Carte> getDefausse();
        MainDeCartes getMain();
        void setAchats(int);
        void jouerAI();
        void jouerJoueur();
        void setActions(int);
        void setDeck(std::vector<Carte>);
        void setDefausse(std::vector<Carte>);
        void setMain(MainDeCartes);
        void commencerPartie();
        void jouerCarte(Carte);
        void playTurn();
        void defausser();
        void acheterADeck();
        void piocher();                    // Méthode permettant au joueur de piocher des cartes
        void trierDeck();

        



};

#endif

