#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Screen {
protected:
    virtual auto update(float deltaTime) -> void = 0;
    virtual auto draw(sf::RenderWindow& window) -> void = 0;
};
