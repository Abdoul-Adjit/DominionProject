#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include "humain.h"
#include "carte.h"
#include "tresor.h"
#include "victoire.h"
#include "royaume_action.h"
#include "plateaudejeu.h"
#include "cartes/witch.h"
int windowX = 1280;
int windowY=720;

std::vector<sf::Texture*> openImages(std::vector<std::string> fichierImage)
{
    std::vector<sf::Texture*> vecTextu;
    for(std::string file : fichierImage)
    {
        sf::Texture* stock = new sf::Texture();
        stock->loadFromFile("images/" + file + ".jpg");
        vecTextu.push_back(stock);
    }
    
    return vecTextu;
}
/*std::vector<sf::Texture*> openImages2(std::vector<std::string> fichierImage)
{
    std::vector<sf::Texture*> vecTextu;
    for(std::string file : fichierImage)
    {
        sf::Texture* stock = new sf::Texture();
        stock->loadFromFile("images/" + file + ".jpg");
        vecTextu[file]=stock;
    }
    
    return vecTextu;
}
 */

std::vector<sf::RectangleShape*> loadMain(std::vector<Carte*> cards, std::vector<sf::Texture*> &textures, std::vector<std::string> nameFiles )
{
    std::vector<sf::RectangleShape*> rectanglesRes;
    float addx=85.f;
    float x=0;
    if((cards.size()/2)%2==1){
        x=(windowX/2)-(int((cards.size()/2))*110+55+int((cards.size()/2))*10);
    }else{
        x=(windowX/2)-((cards.size()/2)*110+((cards.size()/2)-1)*10);
    }
    int i =0;
    for(Carte* c : cards)
    {
        sf::RectangleShape* s = new sf::RectangleShape(sf::Vector2f(80.f,130.f)); 
        s->setPosition(sf::Vector2f(x,windowY-(windowY*0.201)));
        x+=addx;
        for(size_t j=0;j<nameFiles.size();j++){
            if(nameFiles.at(j)==c->getNom()){
                i = j;
            }
        }
        s->setTexture(textures.at(i));
        rectanglesRes.push_back(s);
    }
    return rectanglesRes;
}

std::vector<sf::RectangleShape*> loadPlateau(std::vector<Carte*> cards, std::vector<sf::Texture*> &textures, std::vector<std::string> nameFiles)
{
    std::vector<sf::RectangleShape*> res;
    float x=(windowX/2)-((110)*2.5f)-20;
    float y=(windowY/2)-290;
    int e=0;
    int z=0;
    for(Carte* c : cards)
    {
        if(e==5){
            x=(windowX/2)-((110)*2.5f)-20; 
            y=(windowY/2)-100;   
        }
        e++;
        for(size_t j=0;j<nameFiles.size();j++){
            if(nameFiles.at(j)==c->getNom()){
                z = j;
            }
        }
        sf::RectangleShape* s = new sf::RectangleShape(sf::Vector2f(110,180)); 
        s->setPosition(sf::Vector2f(x,y));
        x+=120;
        s->setTexture(textures.at(z));
        res.push_back(s);
    }
    return res;
}



std::vector<sf::RectangleShape*> loadMoneyVictory2(std::vector<Carte*> cards, std::vector<sf::Texture*> &textures, std::vector<std::string> nameFiles )
{
    std::vector<sf::RectangleShape*> rectanglesRes;
    float x=5;
    float y=(windowY/2.5)-290;
    int i=0;
    int z=0;
   for(Carte* c : cards)
    {
        if(i==2 || i==4 || i==6){
            x=5;
            y+=(180.f*0.6)+5;
        }
        i++;
        sf::RectangleShape* s = new sf::RectangleShape(sf::Vector2f(110.f*0.7,180.f*0.7)); 
        for(size_t j=0;j<nameFiles.size();j++){
            if(nameFiles.at(j)==c->getNom()){
                z = j;
            }
        }
        s->setPosition(sf::Vector2f(x,y));
        x+=110*0.9 + 40;
        s->setTexture(textures.at(z));
        rectanglesRes.push_back(s);
    }
    return rectanglesRes;
}

std::vector<sf::Text*> loadTextCartesRestantesVT(std::vector<Carte*> cards ,sf::Font* font )
{
    std::vector<sf::Text*> res ;
    float x=85;
    float y=75;
    int i=0;
   for(Carte* c : cards)
    {
        if(i==2 || i==4 || i==6){
            x=85;
            y+=(180.f*0.64f);
        }
        i++;
        std::string a =  std::to_string(c->getCarteRestante());
        sf::Text* s = new sf::Text();
        s->setFont(*font);
        s->setString(a);
        s->setPosition(sf::Vector2f(x,y));
        s->setFillColor(sf::Color(255,215,0));
        s->setOutlineColor(sf::Color::Black);
        s->setOutlineThickness(1);
        s->setCharacterSize(15);
        x+=110*0.9 + 40;
        res.push_back(s);
    }
    return res;
}

std::vector<sf::Text*> loadTextCartesRestantes(std::vector<Carte*> cards ,sf::Font* font ){
    std::vector<sf::Text*> res ;
    float x=(windowX/2)-((110)*2.5f)-20;
    float y=(windowY/2)-320;
    int e=0;
    for(Carte* c : cards)
    {
        if(e==5){
            x=(windowX/2)-((110)*2.5f)-20; 
            y=(windowY/2)+90;   
        }
        e++;
        std::string a =  std::to_string(c->getCarteRestante());
        sf::Text* s = new sf::Text();
        s->setFont(*font);
        s->setString(a);
        s->setPosition(sf::Vector2f(x,y));
        s->setFillColor(sf::Color(255,215,0));
        s->setOutlineColor(sf::Color::Black);
        s->setOutlineThickness(1);
        s->setCharacterSize(15);
        x+=120;
        res.push_back(s);
    }
    return res;
}

sf::RectangleShape* loadJouerCarte(Carte* card, std::vector<sf::Texture*> &textures, std::vector<std::string> nameFiles )
{
    float x=windowX-120;
    float y=windowY-190;
    sf::RectangleShape* s = new sf::RectangleShape(sf::Vector2f(80.f,130.f)); 
    s->setPosition(sf::Vector2f(x,y));
    int i = 0;
    for(size_t j=0;j<nameFiles.size();j++){
        if(nameFiles.at(j)==card->getNom()){
            i=j;
        }
    }
    s->setTexture(textures.at(i));
    return s;
}
std::vector<sf::RectangleShape*> initbuttonChoixJoueurs(){
    std::vector<sf::RectangleShape*> rectanglesRes;
    float x=windowX*0.35-25;
    float y=windowY*0.5-25;
    for(int i=0;i<4;i++){
        sf::RectangleShape* s = new sf::RectangleShape(sf::Vector2f(50.f,50.f));
        s->setPosition(sf::Vector2f(x,y));
        s->setFillColor(sf::Color::White);
        x+=windowX*0.1;
        rectanglesRes.push_back(s);
    }
    return rectanglesRes; 

}

std::vector<sf::Text*> inittextChoixJoueurs(sf::Font* font){
 std::vector<sf::Text*> textRes;
    float x=windowX*0.35-5;
    float y=windowY*0.5-12.5f;
    for(int i=0;i<4;i++){
        sf::Text* s = new sf::Text();
        s->setString(std::to_string(i+1));
        s->setPosition(sf::Vector2f(x,y));
        s->setFillColor(sf::Color::Black);
        s->setFont(*font);
        s->setCharacterSize(20);
        x+=windowX*0.1;
        textRes.push_back(s);
    }
    return textRes; 
}
std::vector<Carte*>  initDeck(PlateauDeJeu* P){
    std::vector<Carte*> cardsAdd;
    for(Carte* c : P->getCartesVicTre()){
        if(c->getNom()=="estate"){
            for(int i=0;i<3;i++){
                cardsAdd.push_back(c);
                c->setCarteRestante(c->getCarteRestante()-1);
            }
        }else if(c->getNom()=="copper"){
            for(int i=0;i<7;i++){
                cardsAdd.push_back(c);
                c->setCarteRestante(c->getCarteRestante()-1);
            }
        }
    
    }
    return cardsAdd;
}

std::vector<Carte*> initPlateau(){
    std::vector<Carte*> cardsAdd;
    Carte* c1 = new royaume_action("workshop",3,true,0,0,0,0,0);
    c1->setCarteRestante(10);
    cardsAdd.push_back(c1);
    Carte* c2 = new royaume_action("woodcutter",3,true,0,0,1,0,2);
    c2->setCarteRestante(10);
    cardsAdd.push_back(c2);
    Carte* c3 = new royaume_action("cave",2,true,1,0,0,0,0);
    c3->setCarteRestante(10);
    cardsAdd.push_back(c3);
    Carte* c4 = new royaume_action("chapelle",2,true,0,0,0,0,0);
    c4->setCarteRestante(10);
    cardsAdd.push_back(c4);
    Carte* c5 = new royaume_action("smithy",4,true,0,0,0,3,0);
    c5->setCarteRestante(10);
    cardsAdd.push_back(c5);
    Carte* c6 = new royaume_action("market",5,true,1,0,1,1,1);
    c6->setCarteRestante(10);
    cardsAdd.push_back(c6);
    Carte* c7 = new royaume_action("mine",5,true,0,0,0,0,0);
    c7->setCarteRestante(10);
    cardsAdd.push_back(c7);
    Carte* c8 = new royaume_action("remodel",4,true,0,0,0,0,0);
    c8->setCarteRestante(10);
    cardsAdd.push_back(c8);
    Carte* c9 = new witch("witch",5,true,0,0,0,2,0);
    c9->setCarteRestante(10);
    cardsAdd.push_back(c9);
    Carte* c10 = new royaume_action("village",3,true,2,0,0,1,0);
    c10->setCarteRestante(10);
    cardsAdd.push_back(c10);
    return cardsAdd;
}

std::vector<Carte*> initVicTre(){
    std::vector<Carte*> cardsAdd;
    Carte* c1 = new tresor("copper",0,1,true);
    c1->setCarteRestante(60);
    cardsAdd.push_back(c1);
    Carte* c2 = new victoire("estate",2,1,true);
    c2->setCarteRestante(18);
    cardsAdd.push_back(c2);
    Carte* c3 = new tresor("silver",3,2,true);
    c3->setCarteRestante(40);
    cardsAdd.push_back(c3);
    Carte* c4 = new victoire("duchy",5,3,true);
    c4->setCarteRestante(8);
    cardsAdd.push_back(c4);
    Carte* c5 = new tresor("gold",6,3,true);
    c5->setCarteRestante(30);
    cardsAdd.push_back(c5);
    Carte* c6 = new victoire("province",8,6,true);
    c6->setCarteRestante(8);
    cardsAdd.push_back(c6);
    Carte* c7 = new victoire("curse",0,-1,true);
    c7->setCarteRestante(10);
    cardsAdd.push_back(c7);
    
    return cardsAdd;
}

std::string setStringPhase(Joueur* J){
    if(J->getPhase()==PhaseJeu::Action){
        return "Passer a la phase Achat";
    }else{
        return "Passer son tour";
    }
}

int main()
{  
    sf::Vector2f mouseposition;
    PlateauDeJeu* plateaujeu = new PlateauDeJeu();
    plateaujeu->setCartesDeJeu(initPlateau());
    plateaujeu->setCartesVicTre(initVicTre());
    int indexJoueur=0;
    Joueur* joueurTour;
    sf::Texture texture;
    texture.loadFromFile("images/ButtonDominion.png");
    sf::Texture texturetiquette;
    texturetiquette.loadFromFile("images/etiquettejoueur.png");
    sf::Texture passerTourtexture;
    passerTourtexture.loadFromFile("images/passertourbutton.png");

    sf::Uint8 light = 100;
    sf::Font font;
    font.loadFromFile("EnchantedLandDS.otf");
    std::vector<std::string> filesBack {"back"};
    std::vector<std::string> filesPlateau {"workshop","woodcutter","cave","chapelle","smithy","market","mine","remodel","witch","village"};
    std::vector<std::string> filesMV {"province","gold","duchy","silver","estate","copper","curse"};
    std::vector<std::string> allFiles {"back","copper","silver","gold","estate","province","duchy","curse","laboratory","workshop","woodcutter","cave","chapelle","smithy","market","mine","remodel","witch","village"};
    Humain* joueur1 = new Humain("1");
    joueur1->setDeck(initDeck(plateaujeu));
    joueur1->shuffle();
    joueur1->piocher();
    Humain* joueur2 = new Humain("2");
    joueur2->setDeck(initDeck(plateaujeu));
    joueur2->shuffle();
    joueurTour=joueur1;
    joueurTour->setPhase(PhaseJeu::Action);
    std::vector<Joueur*> listeJoueurs {joueur1,joueur2};
    plateaujeu->setOrdreDeJeu(listeJoueurs);
    std::vector<sf::Texture*> allTextures = openImages(allFiles);
    std::vector<sf::Texture*> texturePileBack = openImages({"pileback"});
    std::vector<sf::Texture*> texturesMV = openImages(filesMV);
    std::vector<sf::RectangleShape*> plateau = loadPlateau(plateaujeu->getCartesDeJeu(),allTextures,allFiles);
    std::vector<sf::RectangleShape*> moneyVictory = loadMoneyVictory2(plateaujeu->getCartesVicTre(),allTextures,allFiles);
    Carte* nC = new Carte("back",0,TypeCarte::Action,true);
    std::vector<sf::RectangleShape*> mainCarte = loadMain(joueurTour->getMain(),allTextures,allFiles);
    sf::RectangleShape* jouerCarte = loadJouerCarte(nC,allTextures,allFiles);
    sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Dominion Menu");
    sf::Font* font2 = new sf::Font();
    font2->loadFromFile("EnchantedLandDS.otf");
    std::vector<sf::Text*> textesAffiCartesRestantes = loadTextCartesRestantes(plateaujeu->getCartesDeJeu(),font2);
    std::vector<sf::Text*> textesAffiCartesRestantesVT = loadTextCartesRestantesVT(plateaujeu->getCartesVicTre(),font2);

    std::string strPasserPhase = setStringPhase(joueurTour);
    sf::Text passerTour(strPasserPhase,font,15);
    passerTour.setPosition(sf::Vector2f(windowX-189, windowY-295));
    passerTour.setFillColor(sf::Color::Black);
    
   sf::RectangleShape passerTourButton(sf::Vector2f (190.f, 50.f));
    passerTourButton.setPosition(sf::Vector2f(windowX-200, windowY-310));
    passerTourButton.setTexture(&passerTourtexture);


    sf::RectangleShape ArgentButton(sf::Vector2f (170.f, 50.f));
    ArgentButton.setPosition(sf::Vector2f(windowX-(windowX-10), windowY-190));
    ArgentButton.setFillColor(sf::Color::Blue);


    sf::Text Argent(std::to_string(joueurTour->getArgent()),font,20);
    Argent.setPosition(sf::Vector2f(windowX-(windowX-3*40+3), windowY-165));
    Argent.setFillColor(sf::Color(255,215,0));
    Argent.setOutlineColor(sf::Color::Black);
    Argent.setOutlineThickness(1);
    


    sf::RectangleShape ActionsButton(sf::Vector2f (170.f, 50.f));
    ActionsButton.setPosition(sf::Vector2f(windowX-(windowX-10), windowY-130));
    ActionsButton.setFillColor(sf::Color::Blue);

    sf::Text Actions(std::to_string(joueurTour->getActions()),font,20);
    Actions.setPosition(sf::Vector2f(windowX-(windowX-5*34), windowY-165));
    Actions.setOutlineColor(sf::Color::Black);
    Actions.setOutlineThickness(1);
    Actions.setFillColor(sf::Color(255,215,0));


    sf::RectangleShape AchatButton(sf::Vector2f (170.f, 50.f));
    AchatButton.setPosition(sf::Vector2f(windowX-(windowX-10), windowY-70));
    AchatButton.setFillColor(sf::Color::Blue);

    sf::Text Achat(std::to_string(joueurTour->getAchats()),font,20);
    Achat.setPosition(sf::Vector2f(windowX-(windowX-63), windowY-165));
    Achat.setOutlineColor(sf::Color::Black);
    Achat.setOutlineThickness(1);
    Achat.setFillColor(sf::Color(255,215,0));




    sf::RectangleShape TourJoueurCase(sf::Vector2f (203.f, 55.f));
    TourJoueurCase.setPosition(sf::Vector2f(windowX-204, windowY-(windowY-20)));
    TourJoueurCase.setTexture(&texturetiquette);

    sf::Text TourJoueur("Tour du joueur : " + std::to_string(indexJoueur+1),font,20 );
    TourJoueur.setPosition(sf::Vector2f(windowX-178, windowY-(windowY-35)));
    TourJoueur.setFillColor(sf::Color::Black);

    sf::RectangleShape deckPile((sf::Vector2f(80.f,130.f))); 
    deckPile.setPosition(sf::Vector2f(windowX-(windowX*0.10f),windowY-(windowY*0.85f)));
    deckPile.setTexture(texturePileBack.at(0));

    sf::Text deckText("Deck",font,3);
    deckText.setPosition(sf::Vector2f(sf::Vector2f(windowX-(windowX*0.164f), windowY-(windowY*0.644))));
    deckText.setFillColor(sf::Color(255,215,0));
    deckText.setOutlineColor(sf::Color::Black);
    deckText.setOutlineThickness(1);
    deckText.setFont(font);
    deckText.setCharacterSize(20);


    sf::Text deckCarteRestante(std::to_string(joueurTour->getDeck().size()),font,20 );
    deckCarteRestante.setPosition(sf::Vector2f(windowX-(windowX*0.164f)+20,windowY-(windowY*0.646)+40));
    deckCarteRestante.setFillColor(sf::Color(255,215,0));
    deckCarteRestante.setOutlineColor(sf::Color::Black);
    deckCarteRestante.setOutlineThickness(1);
    deckCarteRestante.setFont(font);
    deckCarteRestante.setCharacterSize(20);


    sf::RectangleShape defaussePile((sf::Vector2f(80.f,130.f))); 
    defaussePile.setPosition(sf::Vector2f(windowX-230,windowY-(windowY*0.65f)));
    defaussePile.setTexture(texturePileBack.at(0));

    sf::Text defausseCarteRestante(std::to_string(joueurTour->getDefausse().size()),font,20 );
    defausseCarteRestante.setPosition(sf::Vector2f(windowX-(windowX*0.12f) +65,windowY-(windowY*0.84)+40));
    defausseCarteRestante.setFillColor(sf::Color(255,215,0));
    defausseCarteRestante.setOutlineColor(sf::Color::Black);
    defausseCarteRestante.setOutlineThickness(1);
    defausseCarteRestante.setFont(font);
    defausseCarteRestante.setCharacterSize(20);



    sf::Text defausseText("Defausse",font,3);
    defausseText.setPosition(sf::Vector2f(windowX-(windowX*0.087f),windowY-(windowY*0.84)));
    defausseText.setFillColor(sf::Color(255,215,0));
    defausseText.setOutlineColor(sf::Color::Black);
    defausseText.setOutlineThickness(1);
    defausseText.setFont(font);
    defausseText.setCharacterSize(20);


    sf::RectangleShape rebutPile((sf::Vector2f(80.f,130.f))); 
    rebutPile.setPosition(sf::Vector2f(windowX-(windowX*0.10f),windowY-(windowY*0.65f)));
    rebutPile.setTexture(texturePileBack.at(0));
    
    sf::Text rebutCarteRestante(std::to_string(plateaujeu->getrebut().size()),font,20 );
    rebutCarteRestante.setPosition(sf::Vector2f(windowX-(windowX*0.097f)+36,windowY-(windowY*0.648)+40));
    rebutCarteRestante.setFillColor(sf::Color(255,215,0));
    rebutCarteRestante.setOutlineColor(sf::Color::Black);
    rebutCarteRestante.setOutlineThickness(1);
    rebutCarteRestante.setFont(font);
    rebutCarteRestante.setCharacterSize(20);

    sf::Text rebutText("Rebut",font,3);
    rebutText.setPosition(sf::Vector2f(windowX-(windowX*0.097f), windowY-(windowY*0.646)));
    rebutText.setFillColor(sf::Color(255,215,0));
    rebutText.setOutlineColor(sf::Color::Black);
    rebutText.setOutlineThickness(1);
    rebutText.setFont(font);
    rebutText.setCharacterSize(20);
    
    std::vector<sf::RectangleShape*> buttonChoixJoueurs = initbuttonChoixJoueurs();
    std::vector<sf::Text*> textChoixJoueurs= inittextChoixJoueurs(font2);
 
    
   // joueur1->gainActions(1);                                                 **Ensemble pour 
    // Actions.setString("Actions : "+ std::to_string(joueur1->getActions())); **affichage
    sf::RectangleShape* bouttontitre = new sf::RectangleShape(sf::Vector2f(windowX/4,windowY/6));
    sf::RectangleShape* bouttonjouer= new sf::RectangleShape(sf::Vector2f(windowX/6,windowY/8));
    sf::RectangleShape* bouttonquit= new sf::RectangleShape(sf::Vector2f(windowX/6,windowY/8));
    sf::RectangleShape* bouttonoption = new sf::RectangleShape(sf::Vector2f(windowX/6,windowY/8));
    sf::RectangleShape* bouttonregle = new sf::RectangleShape(sf::Vector2f(windowX/6,windowY/8));
    sf::RectangleShape* bouttonretour = new sf::RectangleShape(sf::Vector2f(windowX/6,windowY/8));
    sf::RectangleShape* buttoninforules = new sf::RectangleShape(sf::Vector2f(windowX/6,windowX/10));
    sf::RectangleShape* bouttonplayerinfo = new sf::RectangleShape(sf::Vector2f(windowX/9,windowX/15));
    sf::RectangleShape* buyicon = new sf::RectangleShape(sf::Vector2f(windowX/18,windowX/18));
    sf::RectangleShape* actionicon = new sf::RectangleShape(sf::Vector2f(windowX/18,windowX/18));
    sf::RectangleShape* coinicon = new sf::RectangleShape(sf::Vector2f(windowX/18,windowX/18));
    sf::RectangleShape* bouttonnbJoueur = new sf::RectangleShape(sf::Vector2f(windowX/4+50,windowY/6));

    
    sf::Texture texture2;
    sf::Texture texture3;
    sf::Texture texture4;
    sf::Texture texture5;
    sf::Texture texture10;

    texture10.loadFromFile("images/ruleboard.png");
    buttoninforules->setTexture(&texture10);
    buttoninforules->setPosition(windowX-buttoninforules->getGlobalBounds().width*5,0);
    buttoninforules->setScale(4.01,4.01);

    texture3.loadFromFile("images/banniere.png");
    bouttonplayerinfo->setTexture(&texture3);
    bouttonplayerinfo->setPosition(sf::Vector2f(0, windowY-(windowY*0.34)));
    bouttonplayerinfo->setScale(1.4,1.4);
    
    bouttontitre->setTexture(&texture);
    bouttontitre->setPosition(windowX/2-bouttontitre->getGlobalBounds().width,windowY/2-bouttontitre->getGlobalBounds().height-windowY/6);
    bouttontitre->setScale(2,2);

    bouttonnbJoueur->setTexture(&texture);
    bouttonnbJoueur->setPosition(windowX/2-bouttonnbJoueur->getGlobalBounds().width-25,windowY/2-bouttonnbJoueur->getGlobalBounds().height-windowY/6-50);
    bouttonnbJoueur->setScale(2,2);

    texture2.loadFromFile("images/money-bag.png");
    buyicon->setTexture(&texture2);
    buyicon->setPosition(sf::Vector2f(windowX-(windowX-17), windowY-212));
    buyicon->setScale(0.7,0.7);

    texture4.loadFromFile("images/coin.png");
    coinicon->setTexture(&texture4);
    coinicon->setPosition(sf::Vector2f(windowX-(windowX-21-buyicon->getGlobalBounds().width), windowY-210));
    coinicon->setScale(0.7,0.7);

    texture5.loadFromFile("images/sword.png");
    actionicon->setTexture(&texture5);
    actionicon->setPosition(sf::Vector2f(windowX-(windowX-31-buyicon->getGlobalBounds().width-coinicon->getGlobalBounds().width), windowY-210));
    actionicon->setScale(0.7,0.7);


    bouttonjouer->setTexture(&texture);
    bouttonjouer->setPosition(0,windowY-bouttonjouer->getGlobalBounds().height-windowY/8);
    bouttonjouer->setScale(1.6,1.6);

    bouttonoption->setTexture(&texture);
    bouttonoption->setPosition(bouttonjouer->getGlobalBounds().width-15,windowY-bouttonoption->getGlobalBounds().height-windowY/8);
    bouttonoption->setScale(1.6,1.6);

    bouttonregle->setTexture(&texture);
    bouttonregle->setPosition(bouttonjouer->getGlobalBounds().width+bouttonoption->getGlobalBounds().width-40,windowY-bouttonregle->getGlobalBounds().height-windowY/8);
    bouttonregle->setScale(1.6,1.6);

    bouttonquit->setTexture(&texture);
    bouttonquit->setPosition(bouttonjouer->getGlobalBounds().width+bouttonoption->getGlobalBounds().width+bouttonregle->getGlobalBounds().width-80,windowY-bouttonquit->getGlobalBounds().height-windowY/8);
    bouttonquit->setScale(1.6,1.6);

    bouttonretour->setTexture(&texture);
    bouttonretour->setPosition(windowX-bouttonretour->getGlobalBounds().width*1.4,windowY-bouttonretour->getGlobalBounds().height-bouttonretour->getGlobalBounds().height/2);
    bouttonretour->setScale(1.6,1.6);


    sf::Texture background;
    background.loadFromFile("images/131829.jpg");
    font.loadFromFile("EnchantedLandDS.otf");
    sf::Sprite backgroundS(background);
    backgroundS.scale(1.5,1.55);
    sf::Text titletext;
    sf::Text playtext;
    sf::Text quittext;
    sf::Text optiontext;
    sf::Text rulestext;
    sf::Text retourtext;
    sf::Text inforules;
    sf::Text nbjoueurtext;

    titletext.setFillColor(sf::Color(50,50,50));
    titletext.setOutlineColor(sf::Color(192,192,192));
    titletext.setOutlineThickness(2);
    titletext.setFont(font);
    titletext.setString("Dominion");
    titletext.setPosition(windowX/2-titletext.getGlobalBounds().width,windowY/2-titletext.getGlobalBounds().height-windowY/8*1.2);
    titletext.setCharacterSize(60);

    nbjoueurtext.setFillColor(sf::Color(50,50,50));
    nbjoueurtext.setOutlineColor(sf::Color(192,192,192));
    nbjoueurtext.setOutlineThickness(2);
    nbjoueurtext.setFont(font);
    nbjoueurtext.setString("Choississez le nombre de joueur :");
    nbjoueurtext.setPosition(windowX/2-titletext.getGlobalBounds().width,windowY/2-titletext.getGlobalBounds().height-windowY/8*1.2);
    nbjoueurtext.setCharacterSize(35);

    playtext.setFillColor(sf::Color(50,50,50));
    playtext.setOutlineColor(sf::Color(192,192,192));
    playtext.setOutlineThickness(0.5);
    playtext.setFont(font);
    playtext.setString("Jouer");
    playtext.setPosition(windowX/10,windowY-playtext.getGlobalBounds().height-windowY/8*0.96);
    playtext.setCharacterSize(30);
  
    optiontext.setFillColor(sf::Color(50,50,50));
    optiontext.setOutlineColor(sf::Color(192,192,192));
    optiontext.setOutlineThickness(0.5);
    optiontext.setFont(font);
    optiontext.setString("Options");
    optiontext.setPosition(windowX/10*3.51-15,windowY-optiontext.getGlobalBounds().height-windowY/8*0.94);
    optiontext.setCharacterSize(30);

    rulestext.setFillColor(sf::Color(50,50,50));
    rulestext.setOutlineColor(sf::Color(192,192,192));
    rulestext.setOutlineThickness(0.5);
    rulestext.setFont(font);
    rulestext.setString("Regles");
    rulestext.setPosition(windowX/10*3.5*1.79-40,windowY-rulestext.getGlobalBounds().height-windowY/8*0.94);
    rulestext.setCharacterSize(30);

    quittext.setFillColor(sf::Color(50,50,50));
    quittext.setOutlineColor(sf::Color(192,192,192));
    quittext.setOutlineThickness(0.5);
    quittext.setFont(font);
    quittext.setString("Quitter");
    quittext.setPosition(windowX/10*3.5*2.47-40,windowY-quittext.getGlobalBounds().height-windowY/8*1.02);
    quittext.setCharacterSize(30);


    retourtext.setFillColor(sf::Color(50,50,50));
    retourtext.setOutlineColor(sf::Color(192,192,192));
    retourtext.setOutlineThickness(0.5);
    retourtext.setFont(font);
    retourtext.setString("Retour");
    retourtext.setPosition(windowX-retourtext.getGlobalBounds().width*1.6-30,windowY-retourtext.getGlobalBounds().height*2.1-4);
    retourtext.setCharacterSize(30);

    inforules.setFillColor(sf::Color(50,50,50));
    inforules.setOutlineColor(sf::Color(192,192,192));
    inforules.setOutlineThickness(0.5);
    inforules.setFont(font);
    inforules.setString("Dominion est un jeu de construction progressive d'un deck de cartes. Partant d'un mini-deck, vous jouerez\n des actions et acheterez de nouvelles cartes, qui permettent d'obtenir encore plus d'argent et des points\nde victoire. Le but du jeu etant de gagner le plus de points de victoire possible.\nLe jeu se deroule en 3 phases : \n1)  Action : Chaque joueur joue une/des carte(s) action(s) de son deck. Chacune de ces cartes ont un effet.\n2) Achat : Chaque joueur achete une/des carte(s) sur le plateau de jeu.\n3) Nettoyage : Chaque joueur defausse les cartes joues et les cartes non-joues de sa main et pioche 5 cartes. \nLorsqu'un joueur a termine ces 3 phases, c'est au tour du joueur suivant\n\nAstuce : Les cartes de points de victoire ne servent a rien en cours de partie, et genent donc plutot votre\n progression. Par contre, elles sont evidemment indispensables pour gagner. \nC'est donc e vous de choisir le moment ideal pour les collectionner.");
    inforules.setPosition(windowX/2-330,windowY/2-220);
    inforules.setCharacterSize(15);


    sf::RectangleShape* affiVictoire = new sf::RectangleShape(sf::Vector2f(400,500/4));
    affiVictoire->setTexture(&texture);
    affiVictoire->setPosition((windowX/2)-400,(windowY/2)-125);
    affiVictoire->setScale(2,2);
    sf::Text affiVictoireText;
    affiVictoireText.setFillColor(sf::Color(50,50,50));
    affiVictoireText.setOutlineColor(sf::Color(192,192,192));
    affiVictoireText.setOutlineThickness(0.5);
    affiVictoireText.setFont(font);
    affiVictoireText.setPosition((windowX/2)-125,(windowY/2));
    affiVictoireText.setCharacterSize(20);




    bool onMenu = true;
    bool onGame = false;
    bool onOption= false;
    bool onVictoire = false;
    bool onRules = false;
    bool hover = false;
    bool lefthover=true;
    bool drag=false;
    bool trash=false;
    int maxTrash=0;
    int trashcount=0;
    int stocki=0;
    float OX=0.f;
    float OY=0.f;
    float SX=0.f;
    float SY=0.f;
    bool chooseCard=false;
    int maxChooseCard=0;
    bool discardingInf=false;
    int nombreJoueurs = 2;
  




    sf::RectangleShape* dragCarte = new sf::RectangleShape();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                   window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed){
                if(onMenu){
                    if (event.mouseButton.button == sf::Mouse::Left){
                            
                                if (bouttonjouer->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))) // New Game button
                                {
                                    onMenu=false;
                                    onGame=true;
                                }
                                else if(bouttonoption->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))){
                                    onMenu=false;
                                    onOption=true;
                                }
                                else if(bouttonregle->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))){
                                    onMenu=false;
                                    onRules=true;
                                }
                                else if (bouttonquit->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))) // Exit button
                                {
                                    window.close();
                                }
                            
                        
                    }
                }
            }
             if(onRules){
                if (event.type == sf::Event::MouseButtonPressed){
                    if (event.mouseButton.button == sf::Mouse::Left){
                        if (bouttonretour->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))) // New Game button
                        {
                            onMenu=true;
                            onRules=false;
                        }
                    }
                }
            }
            if(onVictoire){
                 if (event.type == sf::Event::MouseButtonPressed &&  event.mouseButton.button == sf::Mouse::Left){
                    if(bouttonretour->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))){
                            onMenu=true;
                            onVictoire=false;
                        }
                 }
            }
              if(onOption){
                 if (event.type == sf::Event::MouseButtonPressed &&  event.mouseButton.button == sf::Mouse::Left){
                        if(bouttonretour->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))){
                            onMenu=true;
                            onOption=false;
                        }
                        
                        for(size_t i=0; i<buttonChoixJoueurs.size();i++){
                            if(buttonChoixJoueurs.at(i)->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))){
                                    plateaujeu->getOrdreDeJeu().clear();
                                    std::vector<Joueur*> listeJoueurs {};
                                    for(size_t j=0;j<=i;j++){
                                        Humain* joueur1 = new Humain(std::to_string(j+1));
                                        joueur1->setDeck(initDeck(plateaujeu));
                                        joueur1->shuffle();
                                        listeJoueurs.push_back(joueur1);
                                    }
                                    
                                    plateaujeu->setOrdreDeJeu(listeJoueurs);
                                    joueurTour=plateaujeu->getOrdreDeJeu().at(0);
                                    joueurTour->setPhase(PhaseJeu::Action);
                                    joueurTour->piocher();
                                    nombreJoueurs=plateaujeu->getOrdreDeJeu().size();
                                    mainCarte = loadMain(joueurTour->getMain(),allTextures,allFiles);
                            }
                        }
                }
            }
            if(onGame){
                if(hover && !lefthover){
                    mainCarte[stocki]->setPosition(sf::Vector2f(mainCarte[stocki]->getPosition().x,mainCarte[stocki]->getPosition().y-20));
                    hover=false;
                }
                if(lefthover ){
                    for(size_t i = 0 ; i < mainCarte.size() ; i++){
                        if(mainCarte[i]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))){
                          
                                lefthover=false;
                                stocki=i;
                                hover=true;
                        }
                    }
                }
                if(!hover && !lefthover && !(mainCarte[stocki]->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)))){
                    lefthover=true;
                    mainCarte[stocki]->setPosition(sf::Vector2f(mainCarte[stocki]->getPosition().x,mainCarte[stocki]->getPosition().y+20));
                }
                if(event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    for(sf::RectangleShape* card : mainCarte){
                        if(card->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))) && !drag){
                              auto it = std::find(begin(mainCarte),end(mainCarte),card);
                              int index = it - mainCarte.begin();
                              if(joueurTour->getMain().at(index)->getType()!=TypeCarte::Victory ){
                                if(joueurTour->getMain().at(index)->getType()==TypeCarte::Action && joueurTour->getPhase() == PhaseJeu::Action && joueurTour->getActions()>0){
                                    SX= card->getPosition().x;
                                    SY= card->getPosition().y;
                                    OX = sf::Mouse::getPosition(window).x - card->getPosition().x;
                                    OY = sf::Mouse::getPosition(window).y - card->getPosition().y;
                                    mouseposition=sf::Vector2f(sf::Mouse::getPosition(window));
                                    drag=true;
                                    dragCarte = card;
                                }
                                
                               else if(joueurTour->getMain().at(index)->getType()==TypeCarte::Money && joueurTour->getPhase() == PhaseJeu::Achat){
                                    SX= card->getPosition().x;
                                    SY= card->getPosition().y;
                                    OX = sf::Mouse::getPosition(window).x - card->getPosition().x;
                                    OY = sf::Mouse::getPosition(window).y - card->getPosition().y;
                                    mouseposition=sf::Vector2f(sf::Mouse::getPosition(window));
                                    drag=true;
                                    dragCarte = card;
                               }
                              }
                              if(discardingInf || trash){
                                    SX= card->getPosition().x;
                                    SY= card->getPosition().y;
                                    OX = sf::Mouse::getPosition(window).x - card->getPosition().x;
                                    OY = sf::Mouse::getPosition(window).y - card->getPosition().y;
                                    mouseposition=sf::Vector2f(sf::Mouse::getPosition(window));
                                    drag=true;
                                    dragCarte = card;
                               }  
                        }
                    }
                }
                if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                     if (passerTourButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))){
                        if(joueurTour->getPhase()==PhaseJeu::Achat){
                            if(((size_t) indexJoueur)==plateaujeu->getOrdreDeJeu().size()-1){
                                indexJoueur=0;
                            }else{
                                indexJoueur+=1;
                            };
                            joueurTour->setPhase(PhaseJeu::Attente);
                            joueurTour=plateaujeu->getOrdreDeJeu().at(indexJoueur);
                            joueurTour->setPhase(PhaseJeu::Action);
                            joueurTour->setAchats(1);
                            joueurTour->setArgent(0);
                            joueurTour->setActions(1);
                            joueurTour->piocher();
                            mainCarte = loadMain(joueurTour->getMain(),allTextures,allFiles);
                            Actions.setString(std::to_string(joueurTour->getActions()));
                            Argent.setString(std::to_string(joueurTour->getArgent())); 
                            Achat.setString( std::to_string(joueurTour->getAchats()));
                            TourJoueur.setString("Tour du joueur : "+ std::to_string(indexJoueur+1));
                        }else if(joueurTour->getPhase()==PhaseJeu::Action ){
                            joueurTour->setPhase(PhaseJeu::Achat);
                            if(chooseCard){
                                chooseCard=false;
                            }if(discardingInf){
                                discardingInf=false;
                            }if(trash){
                                trash=false;
                            }
                            
                        }
                        strPasserPhase = setStringPhase(joueurTour);
                        passerTour.setString(strPasserPhase);
                     }
                     else  if(chooseCard || (joueurTour->getPhase()==PhaseJeu::Achat) ){
                        for(sf::RectangleShape* card : plateau){
                            if(card->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))){
                         
                                auto it = std::find(begin(plateau),end(plateau),card);
                                int index = it - plateau.begin();
                                Carte* carteAchete = plateaujeu->getCartesDeJeu().at(index);
                                if(carteAchete->getCarteRestante()>0 &&  joueurTour->getPhase()==PhaseJeu::Achat){
                                    if(joueurTour->getAchats()>0 ){
                                        if(joueurTour->getArgent()>=carteAchete->getCout()){
                                            joueurTour->gainMoney(-(carteAchete->getCout()));
                                            joueurTour->defausser(carteAchete);
                                            joueurTour->gainAchats(-1);
                                            Argent.setString(std::to_string(joueurTour->getArgent()));
                                            Achat.setString(std::to_string(joueurTour->getAchats()));
                                            carteAchete->setCarteRestante(carteAchete->getCarteRestante()-1);
                                            textesAffiCartesRestantes = loadTextCartesRestantes(plateaujeu->getCartesDeJeu(),font2);
                                        }
                                    }
                                }else if(chooseCard  && maxChooseCard>=carteAchete->getCout() && !trash){
                                    if(plateaujeu->getderniereCarteJoue()->getNom()!="mine"){
                                        joueurTour->defausser(carteAchete);
                                        carteAchete->setCarteRestante(carteAchete->getCarteRestante()-1);
                                        textesAffiCartesRestantes = loadTextCartesRestantes(plateaujeu->getCartesDeJeu(),font2);
                                        
                                        chooseCard=false;
                                    }
                                }                           
                            }
                        }
                        for(sf::RectangleShape* card : moneyVictory){
                            if(card->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))){
                                auto it = std::find(begin(moneyVictory),end(moneyVictory),card);
                                int index = it - moneyVictory.begin();
                                Carte* carteAchete = plateaujeu->getCartesVicTre().at(index);
                                if(carteAchete->getCarteRestante()>0 &&  joueurTour->getPhase()==PhaseJeu::Achat){
                                    if(joueurTour->getAchats()>0 ){
                                    if(joueurTour->getArgent()>=carteAchete->getCout()){
                                            joueurTour->gainMoney(-(carteAchete->getCout()));
                                            joueurTour->defausser(carteAchete);
                                            joueurTour->gainAchats(-1);
                                            Achat.setString(std::to_string(joueurTour->getAchats()));
                                            Argent.setString(std::to_string(joueurTour->getArgent()));
                                            carteAchete->setCarteRestante(carteAchete->getCarteRestante()-1);
                                            textesAffiCartesRestantesVT = loadTextCartesRestantesVT(plateaujeu->getCartesVicTre(),font2);
                                            if(carteAchete->getType()==TypeCarte::Victory){
                                                victoire* ra = static_cast<victoire*>(carteAchete);
                                                joueurTour->gainVictoryPoints(ra->getValeur());
                                                std::cout<<joueurTour->getVictoryPoints()<<",";
                                            }
                                        }
                                    }
                                }else if(chooseCard && maxChooseCard>=carteAchete->getCout() && !trash){
                                     joueurTour->defausser(carteAchete);
                                     carteAchete->setCarteRestante(carteAchete->getCarteRestante()-1);
                                     textesAffiCartesRestantesVT = loadTextCartesRestantesVT(plateaujeu->getCartesVicTre(),font2);
                                     if(carteAchete->getType()==TypeCarte::Victory){
                                            victoire* ra = static_cast<victoire*>(carteAchete);
                                            joueurTour->gainVictoryPoints(ra->getValeur());
                                            std::cout<<joueurTour->getVictoryPoints()<<",";
                                    }
                                    chooseCard=false;
                                }
                            }
                        }
                        
                        
                        

                     }
                }
                if(event.type == sf::Event::MouseButtonReleased )
                {     
                    if((jouerCarte->getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)) && (drag) && (!lefthover)){
                            drag = false;
                            lefthover=true;
                            std::vector<Carte*> cstock = joueurTour->getMain();
                            auto it = std::find(begin(mainCarte),end(mainCarte),dragCarte);
                            int index = it - mainCarte.begin();
                            Carte* c = cstock.at(index);
                            if((c->getType()==TypeCarte::Money && joueurTour->getPhase() == PhaseJeu::Achat) 
                            || (c->getType()==TypeCarte::Action && joueurTour->getPhase() == PhaseJeu::Action)){
                                dragCarte->setPosition(sf::Vector2f(jouerCarte->getPosition().x,jouerCarte->getPosition().y));   
                                jouerCarte=dragCarte;
                                joueurTour->defausser(c);                                                        
                                cstock.erase(begin(cstock)+index);                     
                                joueurTour->setMain(cstock);
                                joueurTour->jouerCarteFunc(c,joueurTour,plateaujeu);
                                plateaujeu->setderniereCarteJoue(c);
                                if(discardingInf){
                                    discardingInf=false;
                                }
                                if(c->getNom()=="cave"){
                                    discardingInf=true;
                                }
                                if(chooseCard){
                                    chooseCard=false;
                                }
                                if(c->getNom()=="workshop"){
                                    chooseCard=true;
                                    maxChooseCard=4;
                                }
                                if(trash){
                                    trash=false;
                                }
                                if(c->getNom()=="chapelle"){
                                    trash=true;
                                    maxTrash=4;
                                }
                                if(c->getNom()=="mine"){
                                    trash=true;
                                    maxTrash=1;
                                    chooseCard=true;
                                    maxChooseCard=3;
                                }
                                if(c->getNom()=="remodel"){
                                    trash=true;
                                    maxTrash=1;
                                    chooseCard=true;
                                    maxChooseCard=2;
                                }
                                
                                Argent.setString(std::to_string(joueurTour->getArgent()));
                                Achat.setString( std::to_string(joueurTour->getAchats()));
                                Actions.setString(std::to_string(joueurTour->getActions()));
                                mainCarte.clear();
                                mainCarte = loadMain(joueurTour->getMain(),allTextures,allFiles); 
                                textesAffiCartesRestantes = loadTextCartesRestantes(plateaujeu->getCartesDeJeu(),font2);
                                textesAffiCartesRestantesVT = loadTextCartesRestantesVT(plateaujeu->getCartesVicTre(),font2);   
                            }else{
                                if(mouseposition==sf::Vector2f(sf::Mouse::getPosition(window))){
                                    drag = false;
                                    lefthover=true;
                                    dragCarte->setPosition(sf::Vector2f(SX,SY));
                                }else{
                                    drag = false;
                                    lefthover=true;
                                    dragCarte->setPosition(sf::Vector2f(SX,SY+20));
                                }
                            }
                        
                    }else if(rebutPile.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y) && drag && !lefthover && trash){
                        if(maxTrash>trashcount){
                            if(plateaujeu->getderniereCarteJoue()->getNom()=="mine"){
                                drag = false;
                                lefthover=true;
                                std::vector<Carte*> cstock = joueurTour->getMain();
                                auto it = std::find(begin(mainCarte),end(mainCarte),dragCarte);
                                int index = it - mainCarte.begin();
                                Carte* c = cstock.at(index); 
                                if(c->getType()==TypeCarte::Money){
                                    joueurTour->suppDeMain(c);
                                    plateaujeu->addCarteRebut(c);
                                    mainCarte = loadMain(joueurTour->getMain(),allTextures,allFiles);  
                                    trashcount++;
                                    maxChooseCard+=c->getCout();
                                    if(trashcount==maxTrash){
                                        trash=false;
                                        trashcount=0;
                                    }
                                }else{
                                    if(mouseposition==sf::Vector2f(sf::Mouse::getPosition(window))){ 
                                        dragCarte->setPosition(sf::Vector2f(SX,SY));
                                    }
                                    else{
                                         dragCarte->setPosition(sf::Vector2f(SX,SY+20));
                                    }
                                }
                            }else if(plateaujeu->getderniereCarteJoue()->getNom()=="remodel" ){
                                drag = false;
                                lefthover=true;
                                std::vector<Carte*> cstock = joueurTour->getMain();
                                auto it = std::find(begin(mainCarte),end(mainCarte),dragCarte);
                                int index = it - mainCarte.begin();
                                Carte* c = cstock.at(index); 
                                joueurTour->suppDeMain(c);
                                plateaujeu->addCarteRebut(c);
                                maxChooseCard+=c->getCout();
                                mainCarte = loadMain(joueurTour->getMain(),allTextures,allFiles);  
                                trashcount++;
                                if(trashcount==maxTrash){
                                    trash=false;
                                    trashcount=0;
                                }
                            }else {
                                drag = false;
                                lefthover=true;
                                std::vector<Carte*> cstock = joueurTour->getMain();
                                auto it = std::find(begin(mainCarte),end(mainCarte),dragCarte);
                                int index = it - mainCarte.begin();
                                Carte* c = cstock.at(index); 
                                joueurTour->suppDeMain(c);
                                plateaujeu->addCarteRebut(c);
                                mainCarte = loadMain(joueurTour->getMain(),allTextures,allFiles);  
                                trashcount++;
                                if(trashcount==maxTrash){
                                    trash=false;
                                    trashcount=0;
                                }
                            }
                            
                        }
                             
                    }else if(defaussePile.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y) && drag && !lefthover && discardingInf){
                            drag = false;
                            lefthover=true;
                            std::vector<Carte*> cstock = joueurTour->getMain();
                            auto it = std::find(begin(mainCarte),end(mainCarte),dragCarte);
                            int index = it - mainCarte.begin();
                            Carte* c = cstock.at(index);
                            joueurTour->defausser(c);
                            joueurTour->suppDeMain(c);
                            joueurTour->piocherCarte();
                            mainCarte = loadMain(joueurTour->getMain(),allTextures,allFiles);    
                    }
                    else if (drag){
                        
                        if(mouseposition==sf::Vector2f(sf::Mouse::getPosition(window))){
                                    drag = false;
                                    lefthover=true;
                                    dragCarte->setPosition(sf::Vector2f(SX,SY));
                                }else{
                                    drag = false;
                                    lefthover=true;
                                    dragCarte->setPosition(sf::Vector2f(SX,SY+20));
                                }
                    }
                    
                }
                
            }
          
        }
       
        if(plateaujeu->veriferVictoire()){
            affiVictoireText.setString("Le joueur " + std::to_string(plateaujeu->quiVictoire()+1) + " a gagne la partie !");
             plateaujeu = new PlateauDeJeu();
            plateaujeu->setCartesDeJeu(initPlateau());
            plateaujeu->setCartesVicTre(initVicTre());
            joueurTour->setIdc();
            Humain* joueur1 = new Humain("1");
            joueur1->setDeck(initDeck(plateaujeu));
            joueur1->shuffle();
            joueur1->piocher();
            Humain* joueur2 = new Humain("2");
            joueur2->setDeck(initDeck(plateaujeu));
            joueur2->shuffle();
            joueur2->piocher();
            joueurTour=joueur1;
            joueurTour->setPhase(PhaseJeu::Action);
            
            std::vector<Joueur*> listeJoueurs {joueur1,joueur2};
            plateaujeu->setOrdreDeJeu(listeJoueurs);
            Argent.setString(std::to_string(joueurTour->getArgent()));
            Achat.setString(std::to_string(joueurTour->getAchats()));
            Actions.setString( std::to_string(joueurTour->getActions()));
            strPasserPhase = setStringPhase(joueurTour);
            passerTour.setString(strPasserPhase);
            textesAffiCartesRestantes = loadTextCartesRestantes(plateaujeu->getCartesDeJeu(),font2);
            textesAffiCartesRestantesVT = loadTextCartesRestantesVT(plateaujeu->getCartesVicTre(),font2);   
            onVictoire=true;
            onGame=false;
            
            
        };
        window.clear(sf::Color::White);
        if(onVictoire){
            window.draw(backgroundS);
            window.draw(*bouttonretour);
            window.draw(retourtext);
            window.draw(*affiVictoire);
            window.draw(affiVictoireText);

        }
        if(onMenu){
            window.draw(backgroundS);
            //window.draw(shape);
            window.draw(*bouttontitre);
            window.draw(*bouttonjouer);
            window.draw(*bouttonquit);
            window.draw(*bouttonregle);
            window.draw(*bouttonoption);

            window.draw(titletext);
            window.draw(playtext);
            //window.draw(Quittext);
            window.draw(optiontext);
            window.draw(rulestext);
            window.draw(quittext);

        }
        if(onOption){
            window.draw(backgroundS);
            
            for(size_t i = 0 ; i < buttonChoixJoueurs.size() ; i++)
            {
                if((i+1)==((size_t)nombreJoueurs)){
                    buttonChoixJoueurs.at(i)->setFillColor(sf::Color(255,255,255));
                }else{
                    buttonChoixJoueurs.at(i)->setFillColor(sf::Color(light,light,light));
                }
                window.draw(*buttonChoixJoueurs[i]);
            }
             for(size_t i = 0 ; i < textChoixJoueurs.size() ; i++)
            {
                window.draw(*textChoixJoueurs[i]);
            }
            
            window.draw(*bouttonnbJoueur);
            window.draw(nbjoueurtext);
            window.draw(*bouttonretour);
            window.draw(retourtext);
        }
        if(onRules){
            window.draw(backgroundS);
            window.draw(*bouttonretour);
            window.draw(*buttoninforules);
            window.draw(retourtext);
            window.draw(inforules);
        }
        if(onGame){
             window.draw(backgroundS);
             if(joueurTour->getPhase()==PhaseJeu::Achat){
            for(size_t i=0; i<plateaujeu->getCartesDeJeu().size();i++){
               if((joueurTour->getArgent()<plateaujeu->getCartesDeJeu().at(i)->getCout()) || !(plateaujeu->getCartesDeJeu().at(i)->getCarteRestante()>0)){
                     plateau.at(i)->setFillColor(sf::Color(light,light,light));
               }else{
                     plateau.at(i)->setFillColor(sf::Color(255,255,255));
               }
            }
            for(size_t i=0; i<plateaujeu->getCartesVicTre().size();i++){
                if((joueurTour->getArgent()<plateaujeu->getCartesVicTre().at(i)->getCout()) || !(plateaujeu->getCartesVicTre().at(i)->getCarteRestante()>0) ){
                        moneyVictory.at(i)->setFillColor(sf::Color(light,light,light));
                }else{
                     moneyVictory.at(i)->setFillColor(sf::Color(255,255,255));
                }
                }
            }
            if(joueurTour->getPhase()==PhaseJeu::Action){
                 for(size_t i=0; i<plateaujeu->getCartesVicTre().size();i++){
                    moneyVictory.at(i)->setFillColor(sf::Color(255,255,255));
                 }
                  for(size_t i=0; i<plateaujeu->getCartesDeJeu().size();i++){
                     plateau.at(i)->setFillColor(sf::Color(255,255,255));
                  }
            }
            if(drag){
                dragCarte->setPosition(sf::Vector2f(sf::Mouse::getPosition(window).x - OX ,sf::Mouse::getPosition(window).y - OY)); 
            }
            window.draw(*jouerCarte);
            for(size_t i = 0 ; i < plateau.size() ; i++)
            {
                window.draw(*plateau[i]);
            }
            for(size_t i = 0 ; i < moneyVictory.size() ; i++)
            {
                window.draw(*moneyVictory[i]);
            }
           
            for(size_t i = 0 ; i < mainCarte.size() ; i++)
            {
                window.draw(*mainCarte[i]);
            }
          
            for(size_t i = 0 ; i < textesAffiCartesRestantes.size() ; i++)
            {
                window.draw(*textesAffiCartesRestantes.at(i));
            }
         
            
            window.draw(passerTourButton);
            window.draw(passerTour);
            //window.draw(ActionsButton);
            //window.draw(ArgentButton);
            window.draw(*bouttonplayerinfo);
            window.draw(*buyicon);
            window.draw(Achat);
            window.draw(*coinicon);
            window.draw(Argent);
            window.draw(*actionicon);
            window.draw(Actions);
            window.draw(TourJoueurCase);
            window.draw(TourJoueur);
            //window.draw(AchatButton);

            window.draw(deckPile);
            

            window.draw(defaussePile);
            window.draw(rebutPile);
            window.draw(deckText);
            window.draw(defausseText);
                for(size_t i = 0 ; i < textesAffiCartesRestantesVT.size() ; i++)
            {
                window.draw(*textesAffiCartesRestantesVT.at(i));
            }
            
             
            window.draw(rebutText);
                 deckCarteRestante.setString(std::to_string(joueurTour->getDeck().size()));
                defausseCarteRestante.setString(std::to_string(joueurTour->getDefausse().size()));
                rebutCarteRestante.setString(std::to_string(plateaujeu->getrebut().size()));
            window.draw(deckCarteRestante);
             
            window.draw(defausseCarteRestante);
           
            window.draw(rebutCarteRestante);
        }
        
        window.display();
    }
    return 0;
}
