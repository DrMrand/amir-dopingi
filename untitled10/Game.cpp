#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"

Platform map;
Player mario;

int main() {
    sf::RenderWindow window(sf::VideoMode(1400,800),"Player");
    sf::Clock gclock;
    sf::View view = window.getDefaultView();

    mario = Player(map.LoadFromImageFile(mario.path("map")));
    mario.init();


    gclock.restart();

    while (window.isOpen()) {
        sf::Event e{};
        while (window.pollEvent(e)) {
            if(e.type == sf::Event::Closed)
                window.close();
        }
        mario.Update(gclock.getElapsedTime().asSeconds());
        gclock.restart();
        view.setCenter(mario.rect.left,mario.rect.top);
        window.setView(view);
        window.clear(sf::Color(135,206,235));
        map.Draw(window);
        mario.Draw(window);
        window.display();
    }
}