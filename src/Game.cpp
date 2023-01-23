#include "Game.h"

auto Game::update(float deltaTime) -> void {
    player.update(deltaTime);
}

auto Game::draw(sf::RenderWindow& window) -> void {
    player.draw(window);
}