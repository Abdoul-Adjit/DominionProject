#include<iostream>
#include<vector>
#include<string>
#include "joueur.h"
#include "carte.h"
#include "plateaudejeu.h"



    
int main()
{
    Joueur j1("Joueur 1");
    j1.printj();
    Carte c1("Cartetest", 4);
    c1.printc();
    PlateauDeJeu p1= PlateauDeJeu();
    p1.printp();
    PlateauDeJeu p2= PlateauDeJeu();
    p2.printp();
    




return 0;
}