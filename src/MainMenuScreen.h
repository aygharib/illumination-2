#pragma once

#include "Screen.h"

class MainMenuScreen : public Screen {
public:
    MainMenuScreen();
    auto update(float deltaTime) -> void override;
    auto draw(sf::RenderWindow& window) -> void override;
private:
    sf::Font font;
    sf::Text text;
};