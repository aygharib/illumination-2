#include <SFML/Window.hpp>

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

auto main() -> int {
    sf::Window window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Hello world!");

    sf::sleep(sf::seconds(3));

    return 0;
}
