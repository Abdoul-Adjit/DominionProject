#include<bits/stdc++.h>


Joueur::Joueur(){
    achats = 1;
    actions = 1;
    deck = new vector<Carte>();
    main = new MainDeCartes();
    défausse = new vector<Carte>();

}
int Joueur::getAchats(){
    return achats;
}
int Joueur::getActions(){
    return actions;
}

vector<Carte> Joueur::getDeck(){
    return deck;
}
vector<Carte> Joueur::getDéfausse(){
    return défausse;
}
MainDeCartes Joueur::getMain(){
    return main;
}
PlateauDeJeu Joueur::getPlateau(){
    return plateau;
}
vector<Carte> Joueur::setDeck(vector<Carte> d){
    deck = d;
}
void Joueur::setDéfausse(vector<Carte> d){
    défausse = d;
}
void Joueur::setMain(MainDeCartes m){
    main = m;
}
void Joueur::setPlateau(PlateauDeJeu p){
    plateau = p;
}
void Joueur::setAchats(int a){
    achats = a;
}
void Joueur::setActions(int a){
    actions = a;
}
void Joueur::commencerPartie(){
    
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

    

   
}
void Joueur::jouer(){
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
}
void Joueur::jouerCarte(Carte c){
    //TODO
}
void Joueur::défausser(){
    //TODO
}
void Joueur::acheterADeck(){
    //TODO
}
void Joueur::piocher(){
    //TODO
}
void Joueur::trierDeck(){
    //TODO
}


