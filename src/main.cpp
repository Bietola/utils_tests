#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "test");

    sf::Texture catTexture;
    catTexture.loadFromFile("assets/cat.jpg");

    while(window.isOpen()) {

        sf::Event e;
        if(window.pollEvent(e)) {
            if(e.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw([&catTexture] {
            sf::Sprite sprt(catTexture);
            sprt.scale(0.5, 0.5);
            return sprt;
        }());
        window.display();
    }

    return 0;
}
