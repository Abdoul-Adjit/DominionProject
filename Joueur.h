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



};

#endif

