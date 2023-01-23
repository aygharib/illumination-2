#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

#include "MainMenuScreen.h"
#include "Player.h"

const std::string WINDOW_NAME{"Illumination"};

constexpr unsigned int SCREEN_WIDTH{1280};
constexpr unsigned int SCREEN_HEIGHT{720};
constexpr unsigned int FRAME_LIMIT{144};

auto main() -> int {
    MainMenuScreen screen{};

    sf::RenderWindow window{
        sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
        WINDOW_NAME
    };
    window.setFramerateLimit(FRAME_LIMIT);

    Player player{};

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

        window.clear(sf::Color::Black);

        player.update();
        player.draw(window);

        window.display();
    }

    return 0;
}
