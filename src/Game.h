#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>

#include "Window.h"
#include "WorkingDirectory.h"
#include "Input.h"

class Game {
public:
    Game();

    auto captureInput() -> void;
    auto update() -> void;
    auto lateUpdate() -> void;
    auto draw() -> void;
    auto calculateDeltaTime() -> void;
    auto isRunning() -> bool;
private:
    Window window;
    WorkingDirectory workingDirectory;
    Input input;

    sf::Texture vikingTexture;
    sf::Sprite vikingSprite;

    sf::Clock clock;
    float deltaTime;
};