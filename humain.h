
#ifndef HUMAIN_H
#define HUMAIN_H
#include "joueur.h"


class Humain : public Joueur{
    private:
        //TODOs
    public:
        Humain::Humain(std::string);
        void Humain::printh();
        void Humain::setAchats(int);
        void Humain::setActions(int);
        void Humain::setDeck(std::vector<Carte>);
        void Humain::setDefausse(std::vector<Carte>);
        void Humain::setMain(MainDeCartes);

};

#endif

