#ifndef ROBOT_H
#define ROBOT_H
#include "joueur.h"

class Robot : public Joueur{
    
private:
    /* data */
public:
    Robot::Robot(std::string);
    void Robot::printh();
    void Robot::setAchats(int);
    void Robot::setActions(int);
    void Robot::setDeck(std::vector<Carte>);
    void Robot::setDefausse(std::vector<Carte>);
    void Robot::setMain(MainDeCartes);
};
#endif


