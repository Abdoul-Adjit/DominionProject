#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>

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

sf::RectangleShape* loadJouerCarte(std::vector<sf::Texture*> textures)
{
    float x=windowX-120;
    float y=windowY-190;
    sf::RectangleShape* s = new sf::RectangleShape(sf::Vector2f(110.f,180.f)); 
    s->setPosition(sf::Vector2f(x,y));
    s->setTexture(textures.at(0));
    return s;
}


int main()
{  

    std::vector<sf::RectangleShape> buttons;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    initButtons(buttons); 
    std::vector<std::string> filesBack {"back"};
    std::vector<std::string> filesMain {"silver","back","copper"};
    std::vector<std::string> filesPlateau {"back","back","back","back","back","back","back","back","back","back"};
    std::vector<std::string> filesMV {"copper","silver","back","back","back","back","back"};
    std::vector<sf::Texture*> texturesM = openImages(filesMain);
    std::vector<sf::Texture*> texturesP = openImages(filesPlateau);
    std::vector<sf::Texture*> texturesMV = openImages(filesMV);
    std::vector<sf::Texture*> texturesJC = openImages(filesBack);
    std::vector<sf::RectangleShape*> mainCarte = loadMain(texturesM);
    std::vector<sf::RectangleShape*> plateau = loadPlateau(texturesP);
    std::vector<sf::RectangleShape*> moneyVictory = loadMoneyVictory(texturesMV);
    sf::RectangleShape* jouerCarte = loadJouerCarte(texturesJC);
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
                            SY= card->getPosition().y;
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
                    
                    if(jouerCarte->getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
                        dragCarte->setPosition(sf::Vector2f(jouerCarte->getPosition().x,jouerCarte->getPosition().y));   
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
        }
       
        window.display();
    }
    return 0;
}