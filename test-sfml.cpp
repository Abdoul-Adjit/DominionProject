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
int windowX = 1280.f;
int windowY=720.f;

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

std::vector<sf::RectangleShape*> loadPlateau(std::vector<sf::Texture*> textures)
{
    std::vector<sf::RectangleShape*> cards;
    float x=(windowX/2)-((110)*2.5f)-20;
    float y=(windowY/2)-290;
    int i=0;
    for(std::vector<sf::Texture*>::iterator it = textures.begin() ; it != textures.end() ; ++it)
    {
        if(i==5){
            x=(windowX/2)-((110)*2.5f)-20; 
            y=(windowY/2)-100;   
        }
        i++;
        sf::RectangleShape* s = new sf::RectangleShape(sf::Vector2f(110,180)); 
        s->setPosition(sf::Vector2f(x,y));
        x+=120;
        s->setTexture(*it);
        cards.push_back(s);
    }
    return cards;
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

void initButtons(std::vector<sf::RectangleShape> &buttons)
{
    sf::Vector2f buttonSize(150.f, 50.f);

    sf::RectangleShape newGameButton(buttonSize);
    newGameButton.setPosition(sf::Vector2f(100.f, 100.f));
    newGameButton.setFillColor(sf::Color::Blue);
    buttons.push_back(newGameButton);

    sf::RectangleShape loadGameButton(buttonSize);
    loadGameButton.setPosition(sf::Vector2f(100.f, 200.f));
    loadGameButton.setFillColor(sf::Color::Blue);
    buttons.push_back(loadGameButton);

    sf::RectangleShape optionsButton(buttonSize);
    optionsButton.setPosition(sf::Vector2f(100.f, 300.f));
    optionsButton.setFillColor(sf::Color::Blue);
    buttons.push_back(optionsButton);

    sf::RectangleShape exitButton(buttonSize);
    exitButton.setPosition(sf::Vector2f(100.f, 400.f));
    exitButton.setFillColor(sf::Color::Red);
    buttons.push_back(exitButton);
  
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
    Carte* c1 = new victoire("copper",1,1,true);
    Carte* c2 = new tresor("silver",1,1,true);
    for(int i=0;i<7;i++){
        cardsAdd.push_back(c1);
    }
      for(int i=0;i<3;i++){
        cardsAdd.push_back(c2);
    }
    return cardsAdd;
}

int main()
{  

    std::vector<sf::RectangleShape> buttons;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    initButtons(buttons); 
    std::vector<std::string> filesBack {"back"};
    std::vector<std::string> filesPlateau {"silver","copper","back","back","back","back","back","back","back","back"};
    std::vector<std::string> filesMV {"copper","silver","back","back","back","back","back"};
    std::vector<std::string> allFiles {"back","copper","silver"};
    Humain* joueur1 = new Humain("1");
    Humain* joueur2= new Humain("1");
    joueur1->setDeck(initDeck());
    joueur2->setDeck(initDeck());;
    joueur1->shuffle();
    joueur1->piocher();
    std::vector<Joueur*> listeJoueurs {joueur1,joueur2};

    std::vector<sf::Texture*> allTextures = openImages(allFiles);
    std::vector<sf::Texture*> texturesMainJ2 = openImages(filesBack);
    std::vector<sf::Texture*> texturesP = openImages(filesPlateau);
    std::vector<sf::Texture*> texturesMV = openImages(filesMV);
    std::vector<sf::Texture*> texturesJC = openImages(filesBack);
    std::vector<sf::RectangleShape*> plateau = loadPlateau(texturesP);
    std::vector<sf::RectangleShape*> moneyVictory = loadMoneyVictory(texturesMV);
    std::vector<sf::CircleShape*> circlesStack = loadCirclesStack(); 
    Carte* nC = new Carte("back",0,TypeCarte::Action,true);
    std::vector<sf::RectangleShape*> mainCarte = loadMain2(joueur1->getMain(),allTextures,allFiles);
    sf::RectangleShape* jouerCarte = loadJouerCarte(nC,allTextures,allFiles);
    sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Dominion Menu");
    sf::Text newgame("New Game",font,20);
    sf::Text loadgame("Load Game",font,20);
    sf::Text options("Options",font,20);
    sf::Text exit("Exit",font,20);
    
    newgame.setPosition(sf::Vector2f(110.f, 110.f));
    loadgame.setPosition(sf::Vector2f(110.f, 210.f) );
    options.setPosition(sf::Vector2f(110.f, 310.f));
    exit.setPosition(sf::Vector2f(110.f, 410.f));
    newgame.setFillColor(sf::Color::White);
    loadgame.setFillColor(sf::Color::White);
    options.setFillColor(sf::Color::White);
    exit.setFillColor(sf::Color::White);
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
                        for (int i = 0; i < buttons.size(); i++){
                            if (buttons[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
                                if (i == 0) // New Game button
                                {
                                    onMenu=false;
                                    onGame=true;
                                }
                                else if (i == 1) // Load Game button
                                {
                                    // code to load a game
                                }
                                else if (i == 2) // Options button
                                {
                                    // code to open options menu
                                }
                                else if (i == 3) // Exit button
                                {
                                    
                                    window.close();
                                }
                            }
                        }
                    }
                }
            }
            if(onGame){
                if(hover && !lefthover){
                    mainCarte[stocki]->setPosition(sf::Vector2f(mainCarte[stocki]->getPosition().x,mainCarte[stocki]->getPosition().y-20));
                    hover=false;
                }
                if(lefthover){
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
                            SX= card->getPosition().x;
                            SY= card->getPosition().y+20;
                            OX = sf::Mouse::getPosition(window).x - card->getPosition().x;
                            OY = sf::Mouse::getPosition(window).y - card->getPosition().y;
                            drag=true;
                            dragCarte = card;

                        }
                    }
                }
                if(event.type == sf::Event::MouseButtonReleased )
                {  
                    drag = false;
                    lefthover=true;
                    if(jouerCarte->getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
                        dragCarte->setPosition(sf::Vector2f(jouerCarte->getPosition().x,jouerCarte->getPosition().y));   
                        // mainCarte.erase(std::find(begin(mainCarte),end(mainCarte),dragCarte));
                        std::vector<Carte*> cstock = joueur1->getMain();
                        auto it = std::find(begin(mainCarte),end(mainCarte),dragCarte);
                        int index = it - mainCarte.begin();
                        cstock.erase(begin(cstock)+index);
                        joueur1->setMain(cstock);
                        mainCarte.clear();
                        mainCarte = loadMain2(joueur1->getMain(),allTextures,allFiles);
                    }
                    else{
                        dragCarte->setPosition(sf::Vector2f(SX,SY));
                    }
                }
            }
           
        }
        window.clear(sf::Color::White);
        if(onMenu){
            for (int i = 0; i < buttons.size(); i++)
            {
                window.draw(buttons[i]);
            }
            window.draw(newgame);
            window.draw(loadgame);
            window.draw(options);
            window.draw(exit);
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
        }
       
        window.display();
    }
    return 0;
}