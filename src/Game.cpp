#include "Game.h"

Game::Game() : window("Illumination") {
    vikingTexture.loadFromFile(workingDirectory.get() + "resources/viking.png");
    vikingSprite.setTexture(vikingTexture);

    deltaTime = clock.restart().asSeconds();
}

auto Game::update() -> void {
    window.update();

    const auto& spritePosition = vikingSprite.getPosition();
    const int pixelsToMovePerSecond = 100;
    auto frameMovement = pixelsToMovePerSecond * deltaTime;
    vikingSprite.setPosition(spritePosition.x + frameMovement, spritePosition.y);
}

auto Game::lateUpdate() -> void {
    
}

auto Game::calculateDeltaTime() -> void {
    deltaTime = clock.restart().asSeconds();
}

auto Game::draw() -> void {
    window.beginDraw();

    window.draw(vikingSprite);

    window.endDraw();
}

auto Game::isRunning() -> bool {
    return window.isOpen();
}