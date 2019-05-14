#include "treasure.h"

Treasure::Treasure(int x_val, int y_val, int wid, int val,
                   sf::Texture &tex, sf::IntRect rect)
        : Object(x_val, y_val, wid, tex, rect), value{val} {}

bool Treasure::active() const
{
    return !collected;
}