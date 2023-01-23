#pragma once

#include "Player.h"

class Game {
public:
    auto update(float deltaTime) -> void;
    auto draw(sf::RenderWindow& window) -> void;
private:
    Player player;
};