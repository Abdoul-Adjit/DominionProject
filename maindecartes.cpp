#include<iostream>
#include<vector>
#include "maindecartes.h"

MainDeCartes::MainDeCartes(std::vector<Carte*> c){
    cartesEnMain=c;
}
void MainDeCartes::setCards(std::vector<Carte*> c){
    cartesEnMain=c;
}

