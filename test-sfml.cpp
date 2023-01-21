#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include "humain.h"
#include "carte.h"
#include "tresor.h"
#include "victoire.h"
#include "maindecartes.h"
#include "royaume_action.h"
#include "plateaudejeu.h"
int windowX = 1920.f*0.9f;
int windowY=1080.f*0.9f;

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
std::vector<sf::RectangleShape*> loadMain(std::vector<sf::Texture*> textures)
{
    std::vector<sf::RectangleShape*> cards;
    float addx=120.f;
    float x=0;
    if((textures.size()/2)%2==1){
        x=(windowX/2)-(int((textures.size()/2))*110+55+int((textures.size()/2))*10);
    }else{
        x=(windowX/2)-((textures.size()/2)*110+((textures.size()/2)-1)*10);
    }
    
    for(std::vector<sf::Texture*>::iterator it = textures.begin() ; it != textures.end() ; ++it)
    {
        sf::RectangleShape* s = new sf::RectangleShape(sf::Vector2f(110,180)); 
        s->setPosition(sf::Vector2f(x,windowY-190));
        x+=addx;
        s->setTexture(*it);
        cards.push_back(s);
    }
    return cards;
}

std::vector<sf::RectangleShape*> loadMain2(std::vector<Carte*> cards, std::vector<sf::Texture*> &textures, std::vector<std::string> nameFiles )
{
    std::vector<sf::RectangleShape*> rectanglesRes;
    float addx=120.f;
    float x=0;
    if((cards.size()/2)%2==1){
        x=(windowX/2)-(int((cards.size()/2))*110+55+int((cards.size()/2))*10);
    }else{
        x=(windowX/2)-((cards.size()/2)*110+((cards.size()/2)-1)*10);
    }
    int i =0;
    for(Carte* c : cards)
    {
        sf::RectangleShape* s = new sf::RectangleShape(sf::Vector2f(110,180)); 
        s->setPosition(sf::Vector2f(x,windowY-190));
        x+=addx;
        for(int j=0;j<nameFiles.size();j++){
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
        for(int j=0;j<nameFiles.size();j++){
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

std::vector<sf::RectangleShape*> loadPlateau2(std::vector<Carte*> cards, std::map<std::string,sf::Texture*> textures )
{
    std::vector<sf::RectangleShape*> rectanglesRes;
    float x=(windowX/2)-((110)*2.5f)-20;
    float y=(windowY/2)-290;
    int i=0;
    for(int i=0;i<cards.size();i++)
    {
        if(i==5){
            x=(windowX/2)-((110)*2.5f)-20; 
            y=(windowY/2)-100;   
        }
        i++;
        sf::RectangleShape* s = new sf::RectangleShape(sf::Vector2f(110,180)); 
        s->setPosition(sf::Vector2f(x,y));
        x+=120;
        s->setTexture(textures[cards.at(i)->getNom()]);
        rectanglesRes.push_back(s);
    }
    return rectanglesRes;
}

std::vector<sf::CircleShape*> loadCirclesStack(){
    std::vector<sf::CircleShape*> circles;
    sf::Text text;
    float x=(windowX/2)-((110)*2.5f)-20;
    float y=(windowY/2)-290;
    for(int i=0;i<10;i++){
        if(i==5){
            x=(windowX/2)-((110)*2.5f)-20; 
            y=(windowY/2)-100;   
        }
        sf::CircleShape* s = new sf::CircleShape(13);
        s->setPosition(sf::Vector2f(x+90,y+160));
        s->setFillColor(sf::Color(150, 50, 250));
        x+=120;
        circles.push_back(s);
    }
    return circles;
}

std::vector<sf::RectangleShape*> loadMoneyVictory(std::vector<sf::Texture*> textures)
{
    std::vector<sf::RectangleShape*> cards;
    float x=10;
    float y=(windowY/2)-290;
    int i=0;
    for(std::vector<sf::Texture*>::iterator it = textures.begin() ; it != textures.end() ; ++it)
    {
        if(i==2 || i==4 || i==6){
            x=10;
            y+=(180.f*0.7)+5;
        }
        i++;
        sf::RectangleShape* s = new sf::RectangleShape(sf::Vector2f(110.f*0.7,180.f*0.7)); 
        s->setPosition(sf::Vector2f(x,y));
        x+=110*0.7 + 5;
        s->setTexture(*it);
        cards.push_back(s);
    }
    return cards;
}

std::vector<sf::RectangleShape*> loadMoneyVictory2(std::vector<Carte*> cards, std::map<std::string,sf::Texture*> textures )
{
    std::vector<sf::RectangleShape*> rectanglesRes;
    float x=10;
    float y=(windowY/2)-290;
    int i=0;
    for(int i=0;i<cards.size();i++)
    {
        if(i==2 || i==4 || i==6){
            x=10;
            y+=(180.f*0.7)+5;
        }
        i++;
        sf::RectangleShape* s = new sf::RectangleShape(sf::Vector2f(110.f*0.7,180.f*0.7)); 
        s->setPosition(sf::Vector2f(x,y));
        x+=110*0.7 + 5;
        s->setTexture(textures[cards.at(i)->getNom()]);
        rectanglesRes.push_back(s);
    }
    return rectanglesRes;
}


sf::RectangleShape* loadJouerCarte(Carte* card, std::vector<sf::Texture*> &textures, std::vector<std::string> nameFiles )
{
    float x=windowX-120;
    float y=windowY-190;
    sf::RectangleShape* s = new sf::RectangleShape(sf::Vector2f(110.f,180.f)); 
    s->setPosition(sf::Vector2f(x,y));
    int i = 0;
    for(int j=0;j<nameFiles.size();j++){
        if(nameFiles.at(j)==card->getNom()){
            i=j;
        }
    }
    s->setTexture(textures.at(i));
    return s;
}

std::vector<Carte*>  initDeck(){
    std::vector<Carte*> cardsAdd;
    Carte* c1 = new victoire("estate",1,1,true);
    Carte* c2 = new tresor("copper",1,1,true);
    for(int i=0;i<7;i++){
        cardsAdd.push_back(c2);
    }
      for(int i=0;i<3;i++){
        cardsAdd.push_back(c1);
    }
    Carte* c3 = new royaume_action("laboratory",5,true,1,0,0,2,0);
    cardsAdd.push_back(c3);
    return cardsAdd;
}

std::vector<Carte*> initPlateau(){
    std::vector<Carte*> cardsAdd;
    Carte* c1 = new royaume_action("workshop",3,true,1,0,0,2,0);
    cardsAdd.push_back(c1);
    Carte* c2 = new royaume_action("woodcutter",1,true,0,0,1,0,2);
    cardsAdd.push_back(c2);
    Carte* c3 = new royaume_action("cave",1,true,1,0,0,0,0);
    cardsAdd.push_back(c3);
    Carte* c4 = new royaume_action("chapelle",1,true,0,0,0,0,0);
    cardsAdd.push_back(c4);
    Carte* c5 = new royaume_action("smithy",1,true,0,0,0,3,0);
    cardsAdd.push_back(c5);
    Carte* c6 = new royaume_action("market",1,true,1,0,1,1,1);
    cardsAdd.push_back(c6);
    Carte* c7 = new royaume_action("mine",1,true,0,0,0,0,0);
    cardsAdd.push_back(c7);
    Carte* c8 = new royaume_action("remodel",1,true,0,0,0,0,0);
    cardsAdd.push_back(c8);
    Carte* c9 = new royaume_action("witch",1,true,0,0,0,2,0);
    cardsAdd.push_back(c9);
    Carte* c10 = new royaume_action("village",1,true,2,0,0,1,0);
    cardsAdd.push_back(c10);
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
    PlateauDeJeu* plateaujeu = new PlateauDeJeu();
    plateaujeu->setCartesDeJeu(initPlateau());
    int indexJoueur=0;
    Joueur* joueurTour;
    
    sf::Font font;
    font.loadFromFile("arial.ttf");
    std::vector<std::string> filesBack {"back"};
    std::vector<std::string> filesPlateau {"workshop","woodcutter","cave","chapelle","smithy","market","mine","remodel","witch","village"};
    std::vector<std::string> filesMV {"province","gold","duchy","silver","estate","copper","curse"};
    std::vector<std::string> allFiles {"back","copper","silver","gold","estate","laboratory","workshop","woodcutter","cave","chapelle","smithy","market","mine","remodel","witch","village"};
    Humain* joueur1 = new Humain("1");
    Humain* joueur2= new Humain("1");
    joueur1->setDeck(initDeck());
    joueur2->setDeck(initDeck());;
    joueur1->shuffle();
    joueur1->piocher();
    joueur2->shuffle();
    joueur2->piocher();
    joueurTour=joueur1;
    joueurTour->setPhase(PhaseJeu::Action);
    std::vector<Joueur*> listeJoueurs {joueur1,joueur2};
    plateaujeu->setOrdreDeJeu(listeJoueurs);
    std::vector<sf::Texture*> allTextures = openImages(allFiles);
    std::vector<sf::Texture*> texturePileBack = openImages({"pileback"});
    std::vector<sf::Texture*> texturesMainJ2 = openImages(filesBack);
    std::vector<sf::Texture*> texturesP = openImages(filesPlateau);
    std::vector<sf::Texture*> texturesMV = openImages(filesMV);
    std::vector<sf::Texture*> texturesJC = openImages(filesBack);
    std::vector<sf::RectangleShape*> plateau = loadPlateau(plateaujeu->getCartesDeJeu(),allTextures,allFiles);
    std::vector<sf::RectangleShape*> moneyVictory = loadMoneyVictory(texturesMV);
    std::vector<sf::CircleShape*> circlesStack = loadCirclesStack(); 
    Carte* nC = new Carte("back",0,TypeCarte::Action,true);
    std::vector<sf::RectangleShape*> mainCarte = loadMain2(joueurTour->getMain(),allTextures,allFiles);
    sf::RectangleShape* jouerCarte = loadJouerCarte(nC,allTextures,allFiles);
    sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Dominion Menu");


    std::string strPasserPhase = setStringPhase(joueurTour);
    sf::Text passerTour(strPasserPhase,font,20);
    passerTour.setPosition(sf::Vector2f(windowX-200, windowY-300));
    passerTour.setFillColor(sf::Color::Black);
    
    sf::RectangleShape passerTourButton(sf::Vector2f (170.f, 50.f));
    passerTourButton.setPosition(sf::Vector2f(windowX-210, windowY-310));
    passerTourButton.setFillColor(sf::Color::Blue);




    sf::RectangleShape ArgentButton(sf::Vector2f (170.f, 50.f));
    ArgentButton.setPosition(sf::Vector2f(windowX-(windowX-10), windowY-190));
    ArgentButton.setFillColor(sf::Color::Blue);

    sf::Text Argent("Argent : "+ std::to_string(joueurTour->getArgent()),font,20);
    Argent.setPosition(sf::Vector2f(windowX-(windowX-20), windowY-180));
    Argent.setFillColor(sf::Color::Black);


    sf::RectangleShape ActionsButton(sf::Vector2f (170.f, 50.f));
    ActionsButton.setPosition(sf::Vector2f(windowX-(windowX-10), windowY-130));
    ActionsButton.setFillColor(sf::Color::Blue);

    sf::Text Actions("Actions : "+ std::to_string(joueurTour->getActions()),font,20);
    Actions.setPosition(sf::Vector2f(windowX-(windowX-20), windowY-120));
    Actions.setFillColor(sf::Color::Black);


    sf::RectangleShape AchatButton(sf::Vector2f (170.f, 50.f));
    AchatButton.setPosition(sf::Vector2f(windowX-(windowX-10), windowY-70));
    AchatButton.setFillColor(sf::Color::Blue);

    sf::Text Achat("Achats : "+ std::to_string(joueurTour->getAchats()),font,20);
    Achat.setPosition(sf::Vector2f(windowX-(windowX-20), windowY-60));
    Achat.setFillColor(sf::Color::Black);



    sf::RectangleShape TourJoueurCase(sf::Vector2f (170.f, 50.f));
    TourJoueurCase.setPosition(sf::Vector2f(windowX-190, windowY-(windowY-20)));
    TourJoueurCase.setFillColor(sf::Color::Blue);

    sf::Text TourJoueur("Tour du joueur " + std::to_string(indexJoueur+1),font,20 );
    TourJoueur.setPosition(sf::Vector2f(windowX-180, windowY-(windowY-30)));
    TourJoueur.setFillColor(sf::Color::Black);

    sf::RectangleShape deckPile((sf::Vector2f(130.f,180.f))); 
    deckPile.setPosition(sf::Vector2f(300,windowY-200));
    deckPile.setTexture(texturePileBack.at(0));

    sf::Text deckText("Deck",font,20 );
    deckText.setPosition(sf::Vector2f(350, windowY-230));
    deckText.setFillColor(sf::Color::Black);


    sf::RectangleShape defaussePile((sf::Vector2f(130.f,180.f))); 
    defaussePile.setPosition(sf::Vector2f(windowX-400,windowY-200));
    defaussePile.setTexture(texturePileBack.at(0));

    sf::Text defausseText("Defausse",font,20 );
    defausseText.setPosition(sf::Vector2f(windowX-380, windowY-230));
    defausseText.setFillColor(sf::Color::Black);

    // joueur1->gainActions(1);                                                 **Ensemble pour 
    // Actions.setString("Actions : "+ std::to_string(joueur1->getActions())); **affichage
    sf::RectangleShape* bouttontitre = new sf::RectangleShape(sf::Vector2f(500/2,500/4));
    sf::RectangleShape* bouttonjouer= new sf::RectangleShape(sf::Vector2f(500/4,500/6+10));
    sf::RectangleShape* bouttonquit= new sf::RectangleShape(sf::Vector2f(500/4,500/6+10));
    sf::RectangleShape* bouttonreprendre = new sf::RectangleShape(sf::Vector2f(500/3,500/6+10));
    sf::RectangleShape* bouttonregle = new sf::RectangleShape(sf::Vector2f(500/4,500/6+10));
    sf::Texture texture;
    texture.loadFromFile("images/ButtonDominion.png");
    bouttontitre->setTexture(&texture);
    bouttontitre->setPosition(0,40);
    bouttontitre->setScale(2,2);
    bouttonjouer->setTexture(&texture);
    bouttonjouer->setPosition(0,window.getSize().y-120);
    //bouttonjouer->setScale(0.112,0.112);
    bouttonreprendre->setTexture(&texture);
    bouttonreprendre->setPosition(bouttonjouer->getGlobalBounds().width-18,window.getSize().y-120);
    //bouttonreprendre->setScale(0.112,0.112);
    bouttonregle->setTexture(&texture);
    bouttonregle->setPosition(bouttonjouer->getGlobalBounds().width+bouttonreprendre->getGlobalBounds().width-30,window.getSize().y-120);
    //bouttonregle->setScale(0.112,0.112);
    bouttonquit->setTexture(&texture);
    bouttonquit->setPosition(bouttonjouer->getGlobalBounds().width+bouttonreprendre->getGlobalBounds().width+bouttonregle->getGlobalBounds().width-40,window.getSize().y-120);
    //bouttonquit->setScale(0.112,0.112);
    sf::Texture background;
    background.loadFromFile("images/131829.jpg");
    font.loadFromFile("EnchantedLandDS.otf");
    sf::Sprite backgroundS(background);
    backgroundS.scale(1.5,1.55);
    sf::Text titletext;
    sf::Text playtext;
    sf::Text quittext;
    sf::Text resumetext;
    sf::Text rulestext;
     titletext.setFillColor(sf::Color(50,50,50));
    titletext.setOutlineColor(sf::Color(192,192,192));
    titletext.setOutlineThickness(2);
    titletext.setFont(font);
    titletext.setString("Dominion");
    titletext.setPosition(114,138);
    titletext.setCharacterSize(60);

    playtext.setFillColor(sf::Color(50,50,50));
    playtext.setOutlineColor(sf::Color(192,192,192));
    playtext.setOutlineThickness(0.5);
    playtext.setFont(font);
    playtext.setString("Jouer");
    playtext.setPosition(37,window.getSize().y-82);
    playtext.setCharacterSize(20);
    
    quittext.setFillColor(sf::Color(50,50,50));
    quittext.setOutlineColor(sf::Color(192,192,192));
    quittext.setOutlineThickness(0.5);
    quittext.setFont(font);
    quittext.setString("Quitter");
    quittext.setPosition(354+playtext.getGlobalBounds().width+resumetext.getGlobalBounds().width+rulestext.getGlobalBounds().width,window.getSize().y-82);
    quittext.setCharacterSize(20);

    resumetext.setFillColor(sf::Color(50,50,50));
    resumetext.setOutlineColor(sf::Color(192,192,192));
    resumetext.setOutlineThickness(0.5);
    resumetext.setFont(font);
    resumetext.setString("Reprendre");
    resumetext.setPosition(87+playtext.getGlobalBounds().width,window.getSize().y-82);
    resumetext.setCharacterSize(20);

    rulestext.setFillColor(sf::Color(50,50,50));
    rulestext.setOutlineColor(sf::Color(192,192,192));
    rulestext.setOutlineThickness(0.5);
    rulestext.setFont(font);
    rulestext.setString("Regles");
    rulestext.setPosition(137+playtext.getGlobalBounds().width+resumetext.getGlobalBounds().width,window.getSize().y-82);
    rulestext.setCharacterSize(20);
    bool onMenu = true;
    bool onGame = false;
    bool hover = false;
    bool lefthover=true;
    bool drag=false;
    int stocki=0;
    float OX=0.f;
    float OY=0.f;
    float SX=0.f;
    float SY=0.f;
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
                            
                                if (bouttonjouer->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) // New Game button
                                {
                                    onMenu=false;
                                    onGame=true;
                                }
                                
                                else if (bouttonquit->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) // Exit button
                                {
                                    
                                    window.close();
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
                    for(int i = 0 ; i < mainCarte.size() ; i++){
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
                                if(joueurTour->getMain().at(index)->getType()==TypeCarte::Action && joueurTour->getPhase() == PhaseJeu::Action){
                                    SX= card->getPosition().x;
                                    SY= card->getPosition().y+20;
                                    OX = sf::Mouse::getPosition(window).x - card->getPosition().x;
                                    OY = sf::Mouse::getPosition(window).y - card->getPosition().y;
                                    drag=true;
                                    dragCarte = card;
                                }
                                
                               else if(joueurTour->getMain().at(index)->getType()==TypeCarte::Money && joueurTour->getPhase() == PhaseJeu::Achat){
                                    SX= card->getPosition().x;
                                    SY= card->getPosition().y+20;
                                    OX = sf::Mouse::getPosition(window).x - card->getPosition().x;
                                    OY = sf::Mouse::getPosition(window).y - card->getPosition().y;
                                    drag=true;
                                    dragCarte = card;
                               }  
                              }
                        }
                    }
                }
                if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                     if (passerTourButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
                        if(joueurTour->getPhase()==PhaseJeu::Achat){
                            if(indexJoueur==plateaujeu->getOrdreDeJeu().size()-1){
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
                            mainCarte = loadMain2(joueurTour->getMain(),allTextures,allFiles);
                            Actions.setString("Actions : "+ std::to_string(joueurTour->getActions()));
                            Argent.setString("Argent : "+ std::to_string(joueurTour->getArgent()));   
                            TourJoueur.setString("Tour du joueur : "+ std::to_string(indexJoueur+1));
                        }else if(joueurTour->getPhase()==PhaseJeu::Action){
                            joueurTour->setPhase(PhaseJeu::Achat);
                        }
                        strPasserPhase = setStringPhase(joueurTour);
                        passerTour.setString(strPasserPhase);
                   
        
                     }
                }
                if(event.type == sf::Event::MouseButtonReleased )
                {     
                    if(jouerCarte->getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y) && drag && !lefthover){
                        drag = false;
                        lefthover=true;
                        dragCarte->setPosition(sf::Vector2f(jouerCarte->getPosition().x,jouerCarte->getPosition().y));   
                        jouerCarte=dragCarte;
                        std::vector<Carte*> cstock = joueurTour->getMain();
                        auto it = std::find(begin(mainCarte),end(mainCarte),dragCarte);
                        int index = it - mainCarte.begin();
                        Carte* c = cstock.at(index);
                        joueurTour->defausser(cstock.at(index));                                                        
                        cstock.erase(begin(cstock)+index);                     
                        joueurTour->setMain(cstock);
                        joueurTour->jouerCarte(c,joueurTour);
                        Argent.setString("Argent : "+ std::to_string(joueurTour->getArgent()));
                        Achat.setString("Achats : "+ std::to_string(joueurTour->getAchats()));
                        Actions.setString("Actions : "+ std::to_string(joueurTour->getActions()));
                        mainCarte.clear();
                        mainCarte = loadMain2(joueurTour->getMain(),allTextures,allFiles);                
                    }
                    else if (drag){
                        drag = false;
                        lefthover=true;
                        dragCarte->setPosition(sf::Vector2f(SX,SY));
                    }
                }
            }
           
        }
        window.clear(sf::Color::White);
        if(onMenu){
           window.draw(backgroundS);
            //window.draw(shape);
            window.draw(*bouttontitre);
            window.draw(*bouttonjouer);
            window.draw(*bouttonquit);
            window.draw(*bouttonregle);
            window.draw(*bouttonreprendre);

            window.draw(titletext);
            window.draw(playtext);
            //window.draw(Quittext);
            window.draw(resumetext);
            window.draw(rulestext);
            window.draw(quittext);

        }
        if(onGame){
            if(drag){
                dragCarte->setPosition(sf::Vector2f(sf::Mouse::getPosition(window).x - OX ,sf::Mouse::getPosition(window).y - OY)); 
            }
            window.draw(*jouerCarte);
            for(int i = 0 ; i < plateau.size() ; i++)
            {
                window.draw(*plateau[i]);
            }
            for(int i = 0 ; i < moneyVictory.size() ; i++)
            {
                window.draw(*moneyVictory[i]);
            }
           
            for(int i = 0 ; i < mainCarte.size() ; i++)
            {
                window.draw(*mainCarte[i]);
            }
            for(int i = 0 ; i < circlesStack.size() ; i++)
            {
                window.draw(*circlesStack[i]);
            }
            window.draw(passerTourButton);
            window.draw(passerTour);
            window.draw(ActionsButton);
            window.draw(Actions);
            window.draw(ArgentButton);
            window.draw(Argent);
            window.draw(TourJoueurCase);
            window.draw(TourJoueur);

            window.draw(AchatButton);
            window.draw(Achat);

            window.draw(deckPile);
            window.draw(deckText);

            window.draw(defaussePile);
            window.draw(defausseText);
        }
        
        window.display();
    }
    return 0;
}