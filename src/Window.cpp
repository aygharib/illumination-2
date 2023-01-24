#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>

#include "Window.h"

Window::Window(const std::string& name) : window(sf::VideoMode(1280, 720), name) {
    window.setVerticalSyncEnabled(true);
}

auto Window::update() -> void {
    sf::Event event{};
    if (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

auto Window::beginDraw() -> void {
    window.clear(sf::Color::Black);
}

auto Window::draw(sf::Drawable& drawable) -> void {
    window.draw(drawable);
}

auto Window::endDraw() -> void {
    window.display();
}

auto Window::isOpen() -> bool {
    return window.isOpen();
}