#include<iostream>
#include<vector>
#include "robot.h"


Robot::Robot(std::string i):Joueur(i){
}
void Robot::printh(){

    this -> Joueur::printj();
}

void Robot::setAchats(int a){
    this-> Joueur::setAchats(a);
}
void Robot::setActions(int a){
    this-> Joueur::setActions(a);
}
void Robot::setDeck(std::vector<Carte> d){
    this-> Joueur::setDeck(d);
}
