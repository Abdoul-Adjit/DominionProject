#ifndef PLATEAUDEJEU_H
#define PLATEAUDEJEU_H
#include "joueur.h"
#include "carte.h"



class PlateauDeJeu{
    private:
        //static int idcount;
        int idp=0;
        std::vector<std::string> ordreDeJeu;
        std::vector<Carte> cartesDeJeu;
    public:
        PlateauDeJeu();
        int getId();
        void setOrdreDeJeu(std::vector<std::string>);
        std::vector<std::string> getOrdreDeJeu();
        void setCartesDeJeu(std::vector<Carte>);
        std::vector<Carte> getCartesDeJeu();
        void ajouterJoueur(std::string);
        void ajouterCarte(Carte);
        //void print();
        

};

#endif

