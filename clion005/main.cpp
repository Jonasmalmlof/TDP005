#include <SFML/Graphics.hpp>

#include "game_state.h"

using sf::RenderWindow;
using sf::VideoMode;

int main() {
    RenderWindow window{VideoMode(1024,768), "Douglas the Dungeoneer"};
    Game_State g{};
    g.run(window);
    return 0;
}