#include "SFML/Window/Keyboard.hpp"
#include <SFML/Window.hpp>

#include <iostream>
#include <string>

const std::string WINDOW_NAME{"Illumination"};

constexpr unsigned int SCREEN_WIDTH{640};
constexpr unsigned int SCREEN_HEIGHT{480};
constexpr unsigned int FRAME_LIMIT{144};

auto main() -> int {
    sf::Window window{
        sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
        WINDOW_NAME
    };
    window.setFramerateLimit(FRAME_LIMIT);

    while (window.isOpen()) {
        // Check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
                }
            }

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.setActive();

        window.display();
    }

    return 0;
}
