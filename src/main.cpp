#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>

#include <chrono>
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

enum class Options {
    MainMenu,
    Settings,
    Game
};

auto main() -> int {
    sf::RenderWindow window{
        sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
        WINDOW_NAME
    };
    window.setFramerateLimit(FRAME_LIMIT);

    auto selected = Options::MainMenu;

    MainMenuScreen mainMenuScreen;
    SettingsScreen settingsScreen;
    GameScreen gameScreen;
    
    auto t1 = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    while (window.isOpen()) {
        auto t2 = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        auto deltaTime = (t2 - t1) / 1000000000.F;
        std::cout << deltaTime << '\n';
        t1 = t2;

        // Check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                    selected = Options::MainMenu;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                    selected = Options::Settings;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                    selected = Options::Game;
                }
            }

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        if (selected == Options::MainMenu) {
            mainMenuScreen.update(1);
            mainMenuScreen.draw(window);
        }
        else if (selected == Options::Settings) {
            settingsScreen.update(1);
            settingsScreen.draw(window);
        }
        else if (selected == Options::Game) {
            gameScreen.update(deltaTime);
            gameScreen.draw(window);
        }

        window.display();
    }

    return 0;
}
