#include "SettingsScreen.h"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Font.hpp"

SettingsScreen::SettingsScreen() {
    font.loadFromFile("./fonts/Lato-Light.ttf");

    text.setString("Settings");
    text.setFont(font);
    text.setCharacterSize(24);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::White);
    text.setPosition(0, 0);
}

auto SettingsScreen::update(float deltaTime) -> void {
    std::cout << "Updating SettingsScreen\n";
}

auto SettingsScreen::draw(sf::RenderWindow& window) -> void {
    std::cout << "Drawing SettingsScreen\n";
    window.draw(text);
}