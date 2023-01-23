#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen() {
    font.loadFromFile("./fonts/Lato-Light.ttf");

    text.setString("Main Menu");
    text.setFont(font);
    text.setCharacterSize(24);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::White);
    text.setPosition(0, 0);
}

auto MainMenuScreen::update(float deltaTime) -> void {
    std::cout << "Updating MainMenuScreen\n";
}

auto MainMenuScreen::draw(sf::RenderWindow& window) -> void {
    std::cout << "Drawing MainMenuScreen\n";
    window.draw(text);
}