#ifndef CARTE_H
#define CARTE_H

class Carte{
    private:
        std::string nom;
        int cout;

    public:
        Carte(std::string, int);
        std::string getNom();
        int getCout();
        void print();



};

#endif