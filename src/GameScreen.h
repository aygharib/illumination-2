#pragma once

#include "Game.h"
#include "Screen.h"

class GameScreen : public Screen {
public:
    auto update(float deltaTime) -> void override;
    auto draw(sf::RenderWindow& window) -> void override;
private:
    Game game;
};