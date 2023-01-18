#include<iostream>
#include<vector>
#include "joueur.h"

int Joueur::idc=0;

Joueur::Joueur(std::string i){
    id=idc;
    nom = i;
    achats = 1;
    actions = 1;
    argent = 0;
    victoryPoints = 0;
    idc++;
}
std::string Joueur::getNom(){
    return nom;
}

void Joueur::setVictoryPoints(int a){
    victoryPoints=a;
}
int Joueur::getVictoryPoints(){
    return victoryPoints;
}
void Joueur::setArgent(int a){
    argent = a;
}

int Joueur::getArgent(){
    return argent;
}

int Joueur::getIdj(){
    return id;
}
void Joueur::gainVictoryPoints(int a){
    setVictoryPoints(victoryPoints+a);
    //setVictoryPoints(getVictoryPoints()+a);
}
void Joueur::gainMoney(int a){
    setArgent(argent+a);
    //setArgent(getArgent()+a);
}
void Joueur::gainActions(int a){
    setActions(actions+a);
    //setActions(getActions()+a);
}
void Joueur::gainAchats(int a){
    setAchats(achats+a);
    //setAchats(getAchats()+a);
}

void Joueur::printj(){
    std::cout<< "Joueur : " << getIdj() << "\n";
    std::cout<< "Achats : " << getAchats() << "\n";
    std::cout<< "Actions : " << getActions() << "\n";
    /*
    std::cout<< "Joueur : " << id << "\n";
    std::cout<< "Achats : " << achats << "\n";
    std::cout<< "Actions : " << actions << "\n";
    std::cout<< "Deck : \n";
    for(int i = 0; i < deck.size(); i++){
        deck[i].print();
    }
    std::cout<< "Main : \n";
    main.print();
    std::cout<< "Defausse : \n";
    for(int i = 0; i < defausse.size(); i++){
        defausse[i].print();
    }
    std::cout<< "Plateaux : \n ";
    for(int i = 0; i < plateaux.size(); i++){
        plateaux[i].print();
    }
    */
}
int Joueur::getAchats(){
    return achats;
}
int Joueur::getActions(){
    return actions;
}

std::vector<Carte> Joueur::getDeck(){
    return deck;
}
std::vector<Carte> Joueur::getDefausse(){
    return defausse;
}
MainDeCartes Joueur::getMain(){
    return main;
}
/*std::vector<PlateauDeJeu> Joueur::getPlateaux(){
    return plateaux;

}
*/
void Joueur::setDeck(std::vector<Carte> d){
    deck = d;
}
void Joueur::setDefausse(std::vector<Carte> d){
    defausse = d;
}
void Joueur::setMain(MainDeCartes m){
    main = m;
}
void Joueur::setAchats(int a){
    achats = a;
}
void Joueur::setActions(int a){
    actions = a;
}
void Joueur::commencerPartie(){
    /*
std::cout<< "Voulez vous jouer : 1- contre un AI ou 2- contre un autre joueur ? \n";
int choix;
    std::cin>>choix;
    switch(choix){
        case 1:
            this.jouerAI();
            break;
        case 2:
            this.jouerJoueur();
            break;
        default:
            std::cout<< "Choix invalide \n";
            this.commencerPartie();
            break;
    }
    */
   
}


void Joueur::jouerAI(){
    //TODO
}
/*
void Joueur::setPlateaux(std::vector<PlateauDeJeu> n){
    plateaux = n;
}
*/
void Joueur::jouerJoueur(){
    /*
    std::cout<< "Voici la liste des plateau de jeux : \n";
    for(int i = 0; i < plateaux.size(); i++){
        std::cout<< i+1 << " : " << plateaux[i].getNom() << "\n";
    }
    std::cout<< "Choisissez un plateau de jeu : \n";
    int choix;
    std::cin>>choix;
    //gerer exception
    plateau = plateaux[choix-1];
    std::cout<< "Vous avez choisi le plateau de jeu : " << plateau.getNom() << "\n";
    std::cout<< "Vous avez " << actions << " actions et " << achats << " achats. \n";
    std::cout<< "Voici votre main : \n";
    main.afficher();
    this.jouer();
    */
}
void Joueur::playTurn(){
    /*
    std::cout<< "Que voulez-vous faire ? \n";
    std::cout<< "1 : Jouer une carte \n";
    std::cout<< "2 : Acheter une carte \n";
    std::cout<< "3 : Terminer le tour \n";
    int choix;
    std::cin>>choix;
    switch(choix){
        case 1:
            std::cout<< "Quelle carte voulez-vous jouer ? \n";
            main.afficher();
            int choixCarte;
            std::cin>>choixCarte;
            this.jouerCarte(main.getCarte(choixCarte));
            break;
        case 2:
            std::cout<< "Quelle carte voulez-vous acheter ? \n";
            plateau.afficher();
            int choixCarte;
            std::cin>>choixCarte;
            this.acheterADeck(plateau.getCarte(choixCarte));
            break;
        case 3:
            this.finirTour();
            break;
        default:
            std::cout<< "Choix invalide \n";
            this.jouer();
            break;
    }
    */
}
void Joueur::finirTour(){
    //TODO
}
void Joueur::jouerCarte(Carte c){
    //TODO
}
void Joueur::defausser(){
    //TODO
}
void Joueur::acheterADeck(){
    //TODO
}
void Joueur::piocher(){
    //TODO
}
void Joueur::trierDeck(){
    //TODO
}


