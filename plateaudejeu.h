#ifndef PLATEAUDEJEU_H
#define PLATEAUDEJEU_H
#include<map>
#include "Joueur.h"
#include "carte.h"

// Le Systeme d'id unique pour les joueurs est a faire
class PlateauDeJeu{
    private:
        static int idcount;
        int idp=0;
        Carte* derniereCarteJoue;
        std::vector<Joueur*> ordreDeJeu;
        std::vector<Carte*> cartesDeJeu;
        std::vector<int> cartesRestanteJeu;
        std::vector<Carte*> cartesVicTre; //std::vector<Pilecarte> pilecarteList; (Collection de piles de cartes du jeu)
        std::vector<int> cartesRestanteVicTre;
        std::vector<Carte> cartesJoues;  // Collection de cartes jouees par les joueurs
        std::vector<Carte*> rebut;   // Collection de cartes dans le rebut
        bool gameOver;   // Indicateur de fin de partie
        Joueur winner;   // Gagnant de la partie

    public:
        PlateauDeJeu();
        ~PlateauDeJeu()=default;
        int getIdp();
        void setOrdreDeJeu(std::vector<Joueur*>);
        std::vector<Joueur*> getOrdreDeJeu();
        void setCartesDeJeu(std::vector<Carte*>);
        std::vector<Carte*> getCartesDeJeu();
        void ajouterJoueur(Joueur);
        void ajouterCarteDeJeu(std::string, int);
        void decrementerCarteDeJeu(std::string);
        void lancer();
        void playGame();  // Méthode permettant de jouer une partie
        void endGame();
        void setGameOver(bool);
        bool getGameOver();
        void setWinner(Joueur);
        Joueur getWinner();
        int getId();
        void setOrdreDeJeu(std::vector<std::string>);
        void ajouterJoueur(std::string);
        void ajouterCarte(Carte);
        std::vector<Carte*> getCartesVicTre();
        void setCartesVicTre(std::vector<Carte*>);
        //std::vector<int> getCartesRestantesVicTre();
        //void setCartesRestantesVicTre(std::vector<int>);
        //std::vector<int> getCartesRestantesJeu();
        //void setCartesRestantesJeu(std::vector<int>);
        bool veriferVictoire();
        int quiVictoire();
        void setderniereCarteJoue(Carte* c);
        Carte* getderniereCarteJoue();
        std::vector<Carte*> getrebut(); 
        void addCarteRebut(Carte* c);
        /* 
        // Constructeur
        Dominion(int numPlayers);
        // Méthode permettant de démarrer une partie
        void startGame();
        // Méthode permettant de jouer une partie
        void playGame();
        // Méthode permettant de terminer une partie
        void endGame();
        // Accesseur en lecture pour le gagnant de la partie
        Player getWinner();
        */
        

};

#endif