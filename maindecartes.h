#ifndef MAINDECARTES_H
#define MAINDECARTES_H
#include "carte.h"

class MainDeCartes{
    private:
        std::vector<Carte*> cartesEnMain;
    public:
        MainDeCartes(std::vector<Carte*> c);
        void setCards(std::vector<Carte*> );
};

#endif

