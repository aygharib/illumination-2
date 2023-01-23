#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

#include "GameScreen.h"
#include "MainMenuScreen.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SettingsScreen.h"

const std::string WINDOW_NAME{"Illumination"};

constexpr unsigned int SCREEN_WIDTH{1280};
constexpr unsigned int SCREEN_HEIGHT{720};
constexpr unsigned int FRAME_LIMIT{144};

auto main() -> int {
    sf::RenderWindow window{
        sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
        WINDOW_NAME
    };
    window.setFramerateLimit(FRAME_LIMIT);

    int i = 1;

    MainMenuScreen mainMenuScreen;
    SettingsScreen settingsScreen;
    GameScreen gameScreen;

    while (window.isOpen()) {
        // Check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
                }

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                    i = 1;
                }

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                    i = 2;
                }

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                    i = 3;
                }
            }

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        if (i == 1) {
            mainMenuScreen.draw(window);
        }
        else if (i == 2) {
            settingsScreen.draw(window);
        }
        else if (i == 3) {
            gameScreen.update(1);
            gameScreen.draw(window);
        }

        window.display();
    }

    return 0;
}
