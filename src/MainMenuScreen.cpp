#include "MainMenuScreen.h"

auto MainMenuScreen::show() -> void {
    std::cout << "Showing MainMenuScreen\n";
}

auto MainMenuScreen::hide() -> void {
    std::cout << "Hiding MainMenuScreen\n";
}

auto MainMenuScreen::update(float deltaTime) -> void {
    std::cout << "Updating MainMenuScreen\n";
}

auto MainMenuScreen::draw(sf::RenderWindow& window) -> void {
    std::cout << "Drawing MainMenuScreen\n";
}