#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "Window.h"
#include "WorkingDirectory.h"

class Game {
public:
    Game();

    auto update() -> void;
    auto lateUpdate() -> void;
    auto draw() -> void;
    auto isRunning() -> bool;
private:
    Window window;
    WorkingDirectory workingDirectory;

    sf::Texture vikingTexture;
    sf::Sprite vikingSprite;
};