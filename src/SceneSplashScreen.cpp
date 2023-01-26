#include "SceneSplashScreen.h"

SceneSplashScreen::SceneSplashScreen(WorkingDirectory& workingDirectory, SceneStateMachine& sceneStateMachine, Window& window)
: workingDirectory(workingDirectory), sceneStateMachine(sceneStateMachine), window(window), switchToState(0), showForSeconds(3.F), currentSeconds(0.F) {}

auto SceneSplashScreen::onCreate() -> void {
    splashTexture.loadFromFile(workingDirectory.get() + "/resources/splash.png");
    splashSprite.setTexture(splashTexture);
    
    auto spriteSize = splashSprite.getLocalBounds();
    splashSprite.setOrigin(spriteSize.width * 0.5f, spriteSize.height * 0.5f);
    
    auto windowCentre = window.getCentre();
    splashSprite.setPosition(windowCentre.x, windowCentre.y);
}

auto SceneSplashScreen::onDestroy() -> void {

}

auto SceneSplashScreen::onActivate() -> void {
    currentSeconds = 0.F;
}

auto SceneSplashScreen::setSwitchToScene(unsigned int id) -> void {
    switchToState = id;
}

auto SceneSplashScreen::update(float deltaTime) -> void {
    currentSeconds += deltaTime;

    if (currentSeconds >= showForSeconds) {
        sceneStateMachine.switchTo(switchToState);
    }
}

auto SceneSplashScreen::draw(Window& window) -> void {
    window.draw(splashSprite);
}