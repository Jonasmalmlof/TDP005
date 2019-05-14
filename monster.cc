#include <random>

#include "monster.h"

Monster::Monster(int x_val, int y_val, int wid, sf::Texture &tex,
                 sf::IntRect &rect, int max_hp, int min_att, int max_att,
                 std::vector<std::pair<int, int>> route)
        : Movable(x_val, y_val, wid, tex, rect, max_hp, min_att, max_att),
          patrol_route{route} {}

void Monster::move()
{
    /**
     * Step is the variable for which part of the patrol the monster is on,
     * if the monster has completed its route step is set to 0 and the patrol
     * resets
     */
    if(step < int(patrol_route.size()))
    {
        Movable::move(patrol_route[step].first, patrol_route[step].second);
        ++step;
    }
    else
    {
        step=0;
        Movable::move(patrol_route[step].first, patrol_route[step].second);
        ++step;
    }
}

sf::FloatRect Monster::getSightBox() const
{
    return sf::FloatRect(x-width, y-width, width*3, width*3);
}

void Monster::attack(Movable &mov)
{
    int crit_modifier {1};
    std::random_device rd;
    std::uniform_int_distribution<> critical_roll(1,100);

    // Monsters have a 5% chance to critically hit, which doubles the damage
    if(critical_roll(rd) > 94)
    {
        crit_modifier=2;
    }

    std::uniform_int_distribution<> attack_values(min_attack, max_attack);

    mov.decreaseHp(attack_values(rd)*crit_modifier);
}