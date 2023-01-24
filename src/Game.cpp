#include "Game.h"

Game::Game() : window("Illumination") {
    vikingTexture.loadFromFile(workingDirectory.get() + "resources/viking.png");
    vikingSprite.setTexture(vikingTexture);
}

auto Game::update() -> void {
    window.update();
}

auto Game::lateUpdate() -> void {
    
}

auto Game::draw() -> void {
    window.beginDraw();

    window.draw(vikingSprite);

    window.endDraw();
}

auto Game::isRunning() -> bool {
    return window.isOpen();
}