#include "Screen.h"

class MainMenuScreen : public Screen {
public:
    auto show() -> void override;
    auto hide() -> void override;
    auto update(float deltaTime) -> void override;
    auto draw(sf::RenderWindow& window) -> void override;
};