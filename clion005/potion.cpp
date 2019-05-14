#include "potion.h"

Potion::Potion(int x_val, int y_val, int wid, int val,
               sf::Texture &tex, sf::IntRect rect)
        : Treasure(x_val, y_val, wid, val, tex, rect) {}

void Potion::collect(Player &player)
{
    player.heal();
    collected = true;
}
