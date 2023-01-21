#ifndef JOUEUR_H
#define JOUEUR_H
#include "carte.h"
#include "enumPhase.h"
class Joueur{
    private:
        static int idc;
        int id;
        std::string nom;
        int achats;
        int actions;
        int argent;
        PhaseJeu phaseJoueur;
        std::vector<Carte*> deck;
        std::vector<Carte*> main;
        std::vector<Carte*> defausse;
        int victoryPoints;
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
        Joueur() = default;
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
        std::vector<Carte*> getDeck();
        std::vector<Carte> getDefausse();
        std::vector<Carte*> getMain();
        void setAchats(int);
        void jouerAI();
        void jouerJoueur();
        void setActions(int);
        void setDeck(std::vector<Carte*>);
        void setDefausse(std::vector<Carte>);
        void setMain(std::vector<Carte*>);
        void commencerPartie();
        void shuffle();
        void playTurn();
        void defausser(Carte* c);
        void acheterADeck();
        void piocher();                    // Méthode permettant au joueur de piocher des cartes
        void trierDeck();
        void jouerCarte(Carte* c, Joueur* j);
        void piocherCarte();
        PhaseJeu getPhase();
        void setPhase(PhaseJeu);

        


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

