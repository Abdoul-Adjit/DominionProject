#ifndef PLATEAUDEJEU_H
#define PLATEAUDEJEU_H
#include "Joueur.h"
#include "carte.h"



class PlateauDeJeu{
    private:
        //static int idcount;
        int idp=0;
        std::vector<std::string> ordreDeJeu;
        std::vector<Carte> cartesDeJeu;
        /*
        // Collection de joueurs du jeu
         vector<Player> players;
        // Collection de piles de cartes du jeu
        vector<CardStack> cardStacks;
        // Collection de piles de défausse de chaque joueur
        vector<DiscardPile> discardPiles;
        // Collection de piles de réserve de chaque joueur
        vector<ReservePile> reservePiles;
        // Collection de piles de main de chaque joueur
        vector<Hand> hands;
        // Collection de piles de pioche de chaque joueur
        vector<DrawPile> drawPiles;
        // Index du joueur actuellement en train de jouer
        int currentPlayerIndex;
        // Indicateur de fin de partie
        bool gameOver;
        // Gagnant de la partie
        Player winner;
        */


    public:
        PlateauDeJeu();
        int getId();
        void setOrdreDeJeu(std::vector<std::string>);
        std::vector<std::string> getOrdreDeJeu();
        void setCartesDeJeu(std::vector<Carte>);
        std::vector<Carte> getCartesDeJeu();
        void ajouterJoueur(std::string);
        void ajouterCarte(Carte);
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

