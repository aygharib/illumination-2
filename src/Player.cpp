#include "Player.h"

#include <iostream>

Player::Player() {
    square = sf::RectangleShape{sf::Vector2f{50.F, 50.F}};
    square.setFillColor(sf::Color::White);
}

auto Player::update(float deltaTime) -> void {
    x += speed * deltaTime;
}

auto Player::draw(sf::RenderWindow& window) -> void {
    square.setPosition(x, y);
    window.draw(square);
    std::cout << "pos: (" << x << ", " << y << ")\n";
}