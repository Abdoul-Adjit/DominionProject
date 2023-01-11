#ifndef PLATEAUDEJEU_H
#define PLATEAUDEJEU_H
<<<<<<< HEAD
#include<map>
#include "joueur.h"
=======
#include "Joueur.h"
>>>>>>> 7f1ab773c99cf3de5361c7c980c05707b0f743c1
#include "carte.h"
include <sfml>

// Le Systeme d'id unique pour les joueurs est a faire
class PlateauDeJeu{
    private:
        static int idcount;
        int idp=0;
<<<<<<< HEAD
        std::vector<Joueur> ordreDeJeu;
        std::map<std::string, int> cartesDeJeu; //std::vector<Pilecarte> pilecarteList; (Collection de piles de cartes du jeu)
        std::vector<Carte> cartesJoues;  // Collection de cartes jouees par les joueurs
        std::vector<Carte> rebut;   // Collection de cartes dans le rebut
        bool gameOver;   // Indicateur de fin de partie
        Joueur winner;   // Gagnant de la partie
=======
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

>>>>>>> 7f1ab773c99cf3de5361c7c980c05707b0f743c1

    public:

        PlateauDeJeu();
<<<<<<< HEAD
        int getIdp();
        void setOrdreDeJeu(std::vector<Joueur>);
        std::vector<Joueur> getOrdreDeJeu();
        void setCartesDeJeu(std::map<std::string, int>);
        std::map<std::string, int> getCartesDeJeu();
        void ajouterJoueur(Joueur);
        void ajouterCarteDeJeu(std::string, int);
        void decrementerCarteDeJeu(std::string);
        void printp();
        void lancer();
        void playGame();  // Méthode permettant de jouer une partie
        void endGame();
        void setGameOver(bool);c
        bool getGameOver();
        void setWinner(Joueur);
        Joueur getWinner();

        
=======
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
>>>>>>> 7f1ab773c99cf3de5361c7c980c05707b0f743c1
        

};

#endif