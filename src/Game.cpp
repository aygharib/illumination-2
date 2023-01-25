#include "Game.h"

Game::Game() : window("Illumination") {
    vikingTexture.loadFromFile(workingDirectory.get() + "resources/viking.png");
    vikingSprite.setTexture(vikingTexture);

    deltaTime = clock.restart().asSeconds();
}

auto Game::captureInput() -> void {
    input.update();
}

auto Game::update() -> void {
    window.update();

    const auto& spritePos = vikingSprite.getPosition();
    const int moveSpeed = 100;
    
    int xMove = 0;
    if(input.isKeyPressed(Input::Key::Left)) {
        xMove = -moveSpeed;
    }
    else if(input.isKeyPressed(Input::Key::Right)) {
        xMove = moveSpeed;
    }
    
    int yMove = 0;
    if(input.isKeyPressed(Input::Key::Up)) {
        yMove = -moveSpeed;
    }
    else if(input.isKeyPressed(Input::Key::Down)) {
        yMove = moveSpeed;
    }

    auto xFrameMove = static_cast<float>(xMove) * deltaTime;
    auto yFrameMove = static_cast<float>(yMove) * deltaTime;
    
    vikingSprite.setPosition(spritePos.x + xFrameMove, spritePos.y + yFrameMove);
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