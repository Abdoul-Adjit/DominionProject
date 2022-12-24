#ifndef JOUEUR_H
#define JOUEUR_H

class Joueur{
    private:
        int achats;
        int actions;
        vector<Carte> deck;
        MainDeCartes main;
        vector<Carte> défausse;
        static vector<PlateauDeJeu> plateaux;

    public:
        Joueur();
         
        int getAchats();
        int getActions();
        vector<Carte> getDeck();
        vector<Carte> getDéfausse();
        MainDeCartes getMain();
        PlateauDeJeu getPlateaux();
        void setAchats(int);
        void setActions(int);
        void setDeck(vector<Carte>);
        void setDéfausse(vector<Carte>);
        void setMain(MainDeCartes);
        void setPlateaux(PlateauDeJeu);
        void commencerPartie();
        void jouerCarte(Carte);
        void défausser();
        void acheterADeck();
        void piocher();
        void trierDeck();



};

#endif

