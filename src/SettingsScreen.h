#include "Screen.h"

class SettingsScreen : public Screen {
public:
    auto show() -> void override;
    auto hide() -> void override;
    auto update(float deltaTime) -> void override;
    auto draw(float deltaTime) -> void override;
};