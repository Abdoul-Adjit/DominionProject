
#ifndef HUMAIN_H
#define HUMAIN_H
#include "joueur.h"


class Humain : public Joueur{
    private:
        //TODOs
    public:
       Humain(std::string);
        void printh();
        void setAchats(int);
        void setActions(int);
    

};

#endif

