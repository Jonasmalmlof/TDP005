#include "gold.h"

Gold::Gold(int x_val, int y_val, int wid, int val,
           sf::Texture &tex, sf::IntRect rect)
        : Treasure(x_val, y_val, wid, val, tex, rect) {}

void Gold::collect(Player &player)
{
    player.increaseScore(value);
    collected = true;
}