#include<iostream>
#include<vector>
#include<string>
<<<<<<< HEAD
#include "joueur.h"
#include "carte.h"
#include "plateaudejeu.h"


=======
#include "Joueur.h"
>>>>>>> 7f1ab773c99cf3de5361c7c980c05707b0f743c1

    
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