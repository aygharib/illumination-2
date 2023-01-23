#pragma once
#include <SFML/Graphics.hpp>

struct Player {
public:
    Player();
    auto update(float deltaTime) -> void;
    auto draw(sf::RenderWindow& window) -> void;
private:
    float x{0.F};
    float y{0.F};
    float speed{250.F};
    sf::RectangleShape square;
};