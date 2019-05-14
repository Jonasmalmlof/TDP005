#include <random>

#include "movable.h"

Movable::Movable() : Object() {}

Movable::Movable(int x_val, int y_val, int wid, sf::Texture &tex,
                 sf::IntRect &rect, int max_hp, int min_att, int max_att)
        : Object::Object(x_val, y_val, wid, tex, rect), max_health{max_hp},
          current_health{max_hp}, min_attack{min_att}, max_attack{max_att} {}

void Movable::move(int x_move, int y_move)
{
    y += (y_move*width);
    x += (x_move*width);

    //Updates the sprite's position to the object's new position
    sprite.setPosition(x, y);
}

void Movable::decreaseHp(int damage)
{
    std::random_device rd;
    std::uniform_int_distribution<> evade_roll(1,100);

    //Gives the object a 10% chance to evade the attack
    if(evade_roll(rd) < 90)
    {
        current_health-=(damage-equipment_bonus);
    }
}

bool Movable::active() const
{
    return current_health>0;
}

void Movable::heal()
{
    current_health = max_health;
}
