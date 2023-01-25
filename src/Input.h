#pragma once

#include "Bitmask.h"

class Input {
public:
    enum class Key {
        None,
        Up,
        Down,
        Left,
        Right,
        Esc
    };
    
    auto update() -> void;

    auto isKeyPressed(Key keycode) -> bool;
    auto isKeyDown(Key keycode) -> bool;
    auto isKeyUp(Key keycode) -> bool;
private:
    Bitmask thisFrameKeys;
    Bitmask lastFrameKeys;
};