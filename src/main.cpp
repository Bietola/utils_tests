#include <iostream>

#include <SFML/Graphics.hpp>

// MAIN
int main() {
    // global window
    sf::RenderWindow window(sf::VideoMode(750, 750), "Lander");

    // main loop
    sf::Event e;
    while(window.isOpen()) {
        // handle events
        while(window.pollEvent(e)) {
            if(e.type == sf::Event::Closed)
                window.close();
        }

        // draw things
        window.clear();
        window.draw(sf::RectangleShape(sf::Vector2f(500, 500)));
        window.display();
    }

    // end
    return 0;
}
