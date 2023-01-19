#include<iostream>
#include<vector>
#include "plateaudejeu.h"
#include "joueur.h"

int PlateauDeJeu::idcount=0;



int PlateauDeJeu::getIdp(){
    return idp;
}





std::map<std::string, int> PlateauDeJeu::getCartesDeJeu(){
    return cartesDeJeu;
}




void PlateauDeJeu::ajouterCarteDeJeu(std::string c, int i){
    cartesDeJeu.insert(std::make_pair(c, i));
}
void PlateauDeJeu::decrementerCarteDeJeu(std::string c){
    std::map<std::string,int>::iterator it = cartesDeJeu.find(c);
    if (it != cartesDeJeu.end())
    {
        it->second--;
    }
  //  std::cout<< "Il reste " << it->second << " cartes " << c << " \n";
}
void PlateauDeJeu::lancer(){
}



void PlateauDeJeu::printp(){
    std::cout<< "Plateau de jeu : " << idp << "\n";
    std::cout<< "Ordre de jeu : \n";
    for(std::size_t i = 0; i < ordreDeJeu.size(); i++){
        ordreDeJeu[i].printj();
    }
    std::cout<< "Cartes de jeu : \n";
    for (std::map<std::string, int>::iterator it = cartesDeJeu.begin(); it != cartesDeJeu.end(); ++it){
        std::cout << it->first << " : " << it->second << "\n";
    }
}


/*mettrejoueurdansplateau(joueur j)
{
    this.addJoueur(j);
}
*/