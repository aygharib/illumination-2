#include "Game.h"

auto main() -> int {
    Game game;

    while (game.isRunning()) {
        game.update();
        game.lateUpdate();
        game.draw();
        game.calculateDeltaTime();
    }

    return 0;
}