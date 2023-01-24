#pragma once

#include "Window.h"

class Game {
public:
    Game();

    auto update() -> void;
    auto lateUpdate() -> void;
    auto draw() -> void;
    auto isRunning() -> bool;
private:
    Window window;
};