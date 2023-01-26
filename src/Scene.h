#pragma once

#include "Window.h"

class Scene {
public:
    virtual auto onCreate() -> void = 0;
    virtual auto onDestroy() -> void = 0;

    virtual auto onActivate() -> void {};
    virtual auto onDeactivate() -> void {};

    virtual auto processInput() -> void {};
    virtual auto update(float deltaTime) -> void {};
    virtual auto lateUpdate(float deltaTime) -> void {};
    virtual auto draw(Window& window) -> void {};
};