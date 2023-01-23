#pragma once

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "Screen.h"

class SettingsScreen : public Screen {
public:
    SettingsScreen();
    auto update(float deltaTime) -> void override;
    auto draw(sf::RenderWindow& window) -> void override;
private:
    sf::Font font;
    sf::Text text;
};