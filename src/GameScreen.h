#pragma once

#include "Game.h"
#include "Screen.h"

class GameScreen : public Screen {
public:
    auto show() -> void override;
    auto hide() -> void override;
    auto update(float deltaTime) -> void override;
    auto draw(sf::RenderWindow& window) -> void override;
private:
    Game game;
};