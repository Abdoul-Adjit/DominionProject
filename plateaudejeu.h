#ifndef PLATEAUDEJEU_H
#define PLATEAUDEJEU_H
#include<map>
#include "joueur.h"
#include "carte.h"
include <sfml>

// Le Systeme d'id unique pour les joueurs est a faire
class PlateauDeJeu{
    private:
        static int idcount;
        int idp=0;
        std::vector<Joueur> ordreDeJeu;
        std::map<std::string, int> cartesDeJeu; //std::vector<Pilecarte> pilecarteList; (Collection de piles de cartes du jeu)
        std::vector<Carte> cartesJoues;  // Collection de cartes jouees par les joueurs
        std::vector<Carte> rebut;   // Collection de cartes dans le rebut
        bool gameOver;   // Indicateur de fin de partie
        Joueur winner;   // Gagnant de la partie

    public:

        PlateauDeJeu();
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

        
        

};

#endif