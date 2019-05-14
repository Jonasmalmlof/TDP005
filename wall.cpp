#include "wall.h"

Wall::Wall(int x_val, int y_val, int wid,
           sf::Texture &tex, sf::IntRect rect)
        : Object(x_val, y_val, wid, tex, rect) {}

bool Wall::active() const {
    return true;
}
