#pragma once

#include <iostream>

class Screen {
public:
    virtual auto show() -> void = 0;
    virtual auto hide() -> void = 0;
    virtual auto update(float deltaTime) -> void = 0;
    virtual auto draw(float deltaTime) -> void = 0;
};
