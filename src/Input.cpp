#include "Input.h"

#include <SFML/Graphics.hpp>
#include <iostream>

auto Input::update() -> void {
    lastFrameKeys.setMask(thisFrameKeys);

    thisFrameKeys.setBit(static_cast<int>(Key::Up), sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
    thisFrameKeys.setBit(static_cast<int>(Key::Down), sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
    thisFrameKeys.setBit(static_cast<int>(Key::Left), sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
    thisFrameKeys.setBit(static_cast<int>(Key::Right), sf::Keyboard::isKeyPressed(sf::Keyboard::Right));

    thisFrameKeys.setBit(static_cast<int>(Key::Esc), sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
}

auto Input::isKeyPressed(Key keycode) -> bool {
    return thisFrameKeys.getBit(static_cast<int>(keycode));
}

auto Input::isKeyDown(Key keycode) -> bool {
    auto lastFrame = lastFrameKeys.getBit(static_cast<int>(keycode));
    auto thisFrame = thisFrameKeys.getBit(static_cast<int>(keycode));

    return thisFrame && !lastFrame;
}

auto Input::isKeyUp(Key keycode) -> bool {
    auto lastFrame = lastFrameKeys.getBit(static_cast<int>(keycode));
    auto thisFrame = thisFrameKeys.getBit(static_cast<int>(keycode));

    return !thisFrame && lastFrame;
}