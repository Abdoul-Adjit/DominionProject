#include<iostream>
#include<vector>
#include <random>
#include <algorithm>
#include "joueur.h"
#include "victoire.h"
#include "tresor.h"
#include "royaume_action.h"
#include "enumPhase.h"

int Joueur::idc=0;

Joueur::Joueur(std::string i){
    id=idc;
    nom = i;
    achats = 1;
    actions = 1;
    argent = 0;
    victoryPoints = 0;
    idc++;
    std::vector<Carte*> m;
    this->main = m;
    phaseJoueur=PhaseJeu::Attente;
}
std::string Joueur::getNom(){
    return nom;
}
PhaseJeu Joueur::getPhase(){
    return this->phaseJoueur;
}
void Joueur::setPhase(PhaseJeu PJ){
    this->phaseJoueur=PJ;
}

void Joueur::setVictoryPoints(int a){
    victoryPoints=a;
}
int Joueur::getVictoryPoints(){
    return victoryPoints;
}
void Joueur::setArgent(int a){
    this->argent = a;
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
    setArgent((this->argent)+a);
    //setArgent(getArgent()+a);
}
void Joueur::gainActions(int a){
    setActions((this->actions)+a);
    //setActions(getActions()+a);
}
void Joueur::gainAchats(int a){
    setAchats((this->achats)+a);
    //setAchats(getAchats()+a);
}
void Joueur::jouerCarte(Carte* c, Joueur* j){
    if(c->getType()==TypeCarte::Money){
        tresor* d = static_cast<tresor*>(c);
        j->gainMoney(d->getValeur());
    }
    if(c->getType()==TypeCarte::Action){
        royaume_action* ra = static_cast<royaume_action*>(c);
        j->gainAchats(ra->getbuyBonus());
        j->gainActions(ra->getactionBonus());
        j->gainMoney(ra->getmoneyBonus());
        int stock = ra->getcardBonus();
        if(stock>0){
            for(int i = 0;i<stock;i++){
                j->piocherCarte();
            }
        }
    }

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

std::vector<Carte*> Joueur::getDeck(){
    return this->deck;
}

std::vector<Carte*> Joueur::getMain(){
    return this->main;
}
/*std::vector<PlateauDeJeu> Joueur::getPlateaux(){
    return plateaux;

}
*/
void Joueur::shuffle() {
    static std::random_device rd;
    static auto rng = std::default_random_engine { rd() };
    std::shuffle(this->deck.begin(), this->deck.end(), rng);
}

void Joueur::setDeck(std::vector<Carte*> d){
    this-> deck = d;
}

void Joueur::setMain(std::vector<Carte*> m){
    this->main=m;
}
void Joueur::setAchats(int a){
    this->achats = a;
}
void Joueur::setActions(int a){
    this->actions = a;
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

void Joueur::defausser(Carte* c){
    this->defausse.push_back(c);
}
void Joueur::acheterADeck(){
    //TODO
}
void Joueur::piocher(){
    
    for(int i=0;i<this->main.size();i++){
        defausser(this->main.at(i));
    }
    this->main.clear();
    for(int i=0;i<5;i++){
        if(this->deck.size()>0){
            this->main.push_back(*this->deck.begin());
            this->deck.erase(this->deck.begin());
        }else{
            this->deck.clear();
            this->deck=this->defausse;
            this->defausse.clear();
            this->shuffle();
            if(this->deck.size()>0){
                this->main.push_back(*this->deck.begin());
                this->deck.erase(this->deck.begin());
            }
        }
    
    }
}

void Joueur::piocherCarte(){

        if(this->deck.size()>0){
            this->main.push_back(*this->deck.begin());
            this->deck.erase(this->deck.begin());
        }else{
            this->deck.clear();
            this->deck=this->defausse;
            this->defausse.clear();
            this->shuffle();
            if(this->deck.size()>0){
                this->main.push_back(*this->deck.begin());
                this->deck.erase(this->deck.begin());
            }
        }
     
}
void Joueur::trierDeck(){
    //TODO
}


