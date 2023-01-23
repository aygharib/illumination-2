#pragma once
#include <SFML/Graphics.hpp>

struct Player {
public:
    Player();
    auto update() -> void;
    auto draw(sf::RenderWindow& window) -> void;
private:
    float x{0};
    float y{0};
    sf::RectangleShape square;
};