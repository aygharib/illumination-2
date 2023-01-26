#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Input.h"
#include "Scene.h"
#include "WorkingDirectory.h"

class SceneGame : public Scene {
public:
    SceneGame(WorkingDirectory& workingDirectory);

    auto onCreate() -> void override;
    auto onDestroy() -> void override;

    auto processInput() -> void override;
    auto update(float deltaTime) -> void override;
    auto draw(Window& window) -> void override;
private:
    sf::Texture vikingTexture;
    sf::Sprite vikingSprite;

    WorkingDirectory& workingDirectory;
    Input input;
};