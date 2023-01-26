#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Scene.h"
#include "SceneStateMachine.h"
#include "Window.h"
#include "WorkingDirectory.h"

class SceneSplashScreen : public Scene {
public:
    SceneSplashScreen(WorkingDirectory& workingDirectory, SceneStateMachine& sceneStateMachine, Window& window);

    auto onCreate() -> void override;
    auto onDestroy() -> void override;

    auto onActivate() -> void override;

    auto setSwitchToScene(unsigned int id) -> void;

    auto update(float deltaTime) -> void override;
    auto draw(Window& window) -> void override;
private:
    sf::Texture splashTexture;
    sf::Sprite splashSprite;

    WorkingDirectory& workingDirectory;
    SceneStateMachine& sceneStateMachine;
    Window& window;

    float showForSeconds;
    float currentSeconds;

    unsigned int switchToState;
};