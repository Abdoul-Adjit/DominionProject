#include<iostream>
#include<vector>
#include<string>
#include "Joueur.h"

    
int main()
{
    Joueur j1("j1");
    j1.print();
    PlateauDeJeu p1= PlateauDeJeu();
    p1.getId();
    PlateauDeJeu p2 = PlateauDeJeu();
    p2.getId();


return 0;
}