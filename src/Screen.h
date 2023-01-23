#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Screen {
protected:
    virtual auto show() -> void = 0;
    virtual auto hide() -> void = 0;
    virtual auto update(float deltaTime) -> void = 0;
    virtual auto draw(sf::RenderWindow& window) -> void = 0;
};
