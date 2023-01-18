#include<iostream>
#include<vector>
#include<string>
#include "Joueur.h"
#include "carte.h"
#include "plateaudejeu.h"

    
int main()
{
    Joueur j1("Joueur");
    j1.printj();
    PlateauDeJeu*p1= new PlateauDeJeu();
    p1->printp();
    PlateauDeJeu *p2= new PlateauDeJeu();
    p2->printp();

return 0;
}