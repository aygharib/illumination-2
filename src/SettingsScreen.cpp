#include "SettingsScreen.h"

auto SettingsScreen::show() -> void {
    std::cout << "Showing SettingsScreen\n";
}

auto SettingsScreen::hide() -> void {
    std::cout << "Hiding SettingsScreen\n";
}

auto SettingsScreen::update(float deltaTime) -> void {
    std::cout << "Updating SettingsScreen\n";
}

auto SettingsScreen::draw(sf::RenderWindow& window) -> void {
    std::cout << "Drawing SettingsScreen\n";
}