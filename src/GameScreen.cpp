#include "GameScreen.h"

auto GameScreen::update(float deltaTime) -> void {
    std::cout << "Updating GameScreen\n";
    game.update(deltaTime);
}

auto GameScreen::draw(sf::RenderWindow& window) -> void {
    std::cout << "Drawing GameScreen\n";
    game.draw(window);
}