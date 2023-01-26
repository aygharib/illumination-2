#include "SceneGame.h"
#include "WorkingDirectory.h"

SceneGame::SceneGame(WorkingDirectory& workingDirectory) : workingDirectory(workingDirectory) {}

auto SceneGame::onCreate() -> void {
    vikingTexture.loadFromFile(workingDirectory.get() + "resources/cubey.png");
    vikingSprite.setTexture(vikingTexture);
}

auto SceneGame::onDestroy() -> void {

}

auto SceneGame::processInput() -> void {
    input.update();
}

auto SceneGame::update(float deltaTime) -> void {
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

auto SceneGame::draw(Window& window) -> void {
    window.draw(vikingSprite);
}