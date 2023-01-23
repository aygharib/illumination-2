#pragma once

#include <iostream>

class Screen {
public:
    virtual void show() = 0;
    virtual void hide() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void draw(float deltaTime) = 0;
};
