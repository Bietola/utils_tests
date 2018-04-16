#include <iostream>

#include <SFML/Graphics.hpp>

#include "utils.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "test");

    sf::Texture catTexture;
    sf::Font    font;
    catTexture .loadFromFile("assets/cat.jpg");
    font       .loadFromFile("assets/aposiopesis.ttf");

    while(window.isOpen()) {

        sf::Event e;
        if(window.pollEvent(e)) {
            if(e.type == sf::Event::Closed ||
               e.type == sf::Event::KeyPressed) {
                window.close();
            }
        }

        window.clear();
        window.draw([&catTexture] {
            sf::Sprite sprt(catTexture);
            sprt.scale(0.5, 0.5);
            return sprt;
        }());
        window.draw([&font, &window] {
            auto text = sf::Text(greet("world"), font);
            auto ws = window.getSize();
            auto tb = text.getGlobalBounds();
            text.setPosition(ws.x / 2.f - tb.width  / 2.f,
                             ws.y / 2.f - tb.height / 2.f);
            text.setFillColor(sf::Color::Yellow);
            return text;
        }());
        window.display();
    }

    return 0;
}
