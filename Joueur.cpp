#include<iostream>
#include<vector>
#include <random>
#include <algorithm>
#include "joueur.h"
#include "victoire.h"
#include "tresor.h"
#include "royaume_action.h"
#include "enumPhase.h"
#include "plateaudejeu.h"
int Joueur::idc=0;

Joueur::Joueur(std::string i){
    id=idc;
    nom = i;
    achats = 61;
    actions = 1;
    argent = 60;
    victoryPoints = 3;
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
void Joueur::setIdc(){
    this->idc=0;
}
void Joueur::setVictoryPoints(int a){
    this->victoryPoints=a;
}
int Joueur::getVictoryPoints(){
    return this->victoryPoints;
}
void Joueur::setArgent(int a){
    this->argent = a;
}

int Joueur::getArgent(){
    return this->argent;
}

int Joueur::getIdj(){
    return id;
}
void Joueur::gainVictoryPoints(int a){
    setVictoryPoints((this->victoryPoints)+a);
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


void Joueur::jouerAI(){
    //TODO
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
void Joueur::suppDeMain(Carte* c){
    auto it = std::find(begin(this->main),end(this->main),c);
    if(it!=this->main.end()){
        this->main.erase(it);
    }

    
}
void Joueur::piocher(){
    
    for(size_t i=0;i<this->main.size();i++){
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
std::vector<Carte*> Joueur::getDefausse(){
    return this->defausse;
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
void Joueur::piocherCarte(Carte* c){
    this->main.push_back(c);
}
void Joueur::addToDeck(Carte* c){
    this->deck.push_back(c);
}

void Joueur::trierDeck(){
    //TODO
}


void Joueur::jouerCarteFunc(Carte* c, Joueur* j, PlateauDeJeu* P){
    if(c->getType()==TypeCarte::Money){
        tresor* d = static_cast<tresor*>(c);
        j->gainMoney(d->getValeur());
    }
    if(c->getType()==TypeCarte::Action){
        royaume_action* ra = static_cast<royaume_action*>(c);
        j->gainActions(-1);
        j->gainAchats(ra->getbuyBonus());
        j->gainActions(ra->getactionBonus());
        j->gainMoney(ra->getmoneyBonus());
        int stock = ra->getcardBonus();
        if(stock>0){
            for(int i = 0;i<stock;i++){
                j->piocherCarte();
            }
        }
        ra->play(j,P);
        
       
    }
}