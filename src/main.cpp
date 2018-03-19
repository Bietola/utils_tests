#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "test");
    while(window.isOpen()) {

        sf::Event e;
        if(window.pollEvent(e)) {
            if(e.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(sf::RectangleShape({200, 200}));
        window.display();
    }

    return 0;
}
