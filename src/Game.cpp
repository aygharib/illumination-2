#include "Game.h"

Game::Game() : window("Illumination") {}

auto Game::update() -> void {
    window.update();
}

auto Game::lateUpdate() -> void {
    
}

auto Game::draw() -> void {
    window.beginDraw();
    window.endDraw();
}

auto Game::isRunning() -> bool {
    return window.isOpen();
}