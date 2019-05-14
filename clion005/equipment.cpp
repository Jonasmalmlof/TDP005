#include "equipment.h"

Equipment::Equipment(int x_val, int y_val, int wid, int val,
                     sf::Texture &tex, sf::IntRect rect)
        : Treasure(x_val, y_val, wid, val, tex, rect) {}

void Equipment::collect(Player &player)
{
    player.equipTreasure(value);
    collected = true;
}
