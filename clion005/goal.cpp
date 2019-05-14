#include "goal.h"

Goal::Goal() : Object() { finished = false; }

Goal::Goal(int x_val, int y_val, int wid, sf::Texture &tex, sf::IntRect rect)
        : Object(x_val, y_val, wid, tex, rect) {}

void Goal::endGame()
{
    finished = true;
}

bool Goal::active() const
{
    return finished;
}

void Goal::changeSprite()
{
    sprite.setTextureRect(sf::IntRect(140,212,16,16));
}
