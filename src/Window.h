#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include <SFML/Graphics/Drawable.hpp>

class Window {
public:
    Window(const std::string& name);

    auto update() -> void;
    auto beginDraw() -> void;
    auto draw(sf::Drawable& draw) -> void;
    auto endDraw() -> void;
    auto isOpen() -> bool;
private:
    sf::RenderWindow window;
};