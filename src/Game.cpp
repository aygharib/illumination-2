#include "Game.h"
#include "SceneGame.h"
#include "SceneSplashScreen.h"
#include <memory>

#include <iostream>

Game::Game() : window("Illumination") {
    auto splashScreen = std::make_shared<SceneSplashScreen>(workingDirectory, sceneStateMachine, window);
    auto gameScene = std::make_shared<SceneGame>(workingDirectory);

    auto splashScreenId = sceneStateMachine.add(splashScreen);
    auto gameSceneId = sceneStateMachine.add(gameScene);
    
    splashScreen->setSwitchToScene(gameSceneId);

    sceneStateMachine.switchTo(splashScreenId);

    deltaTime = clock.restart().asSeconds();
}

auto Game::captureInput() -> void {
    sceneStateMachine.processInput();
}

auto Game::update() -> void {
    window.update();

    sceneStateMachine.update(deltaTime);
}

auto Game::lateUpdate() -> void {
    sceneStateMachine.lateUpdate(deltaTime);
}

auto Game::draw() -> void {
    window.beginDraw();

    sceneStateMachine.draw(window);

    window.endDraw();
}

auto Game::calculateDeltaTime() -> void {
    deltaTime = clock.restart().asSeconds();
}

auto Game::isRunning() -> bool {
    return window.isOpen();
}