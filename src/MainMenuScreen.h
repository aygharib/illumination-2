#include "Screen.h"

class MainMenuScreen : public Screen {
public:
    void show() override;
    void hide() override;
    void update(float deltaTime) override;
    void draw(float deltaTime) override;
};