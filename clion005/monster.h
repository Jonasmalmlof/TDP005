#ifndef _MONSTER_H_
#define _MONSTER_H_

#include <utility>
#include <vector>

#include "movable.h"

class Monster : public Movable
{
public:
    /**
     * A Monster object that patrols the level after a set cyclic route
     * @param x_val X coordinate to spawn the player at
     * @param y_val Y coordinate to spawn the player at
     * @param wid Width of the player object
     * @param tex Texture used to create the player sprite
     * @param rect Area of the texture to create the player sprite from
     * @param max_hp Max health points of the player object
     * @param min_att Minimum attack value of the player object
     * @param max_att Maximum attack value of the player object
     * @param route The route the Monster will patrol
     */
    Monster(int x_val, int y_val, int wix, sf::Texture &tex,
          sf::IntRect &rect, int max_hp, int min_att, int max_att,
          std::vector<std::pair<int, int>> route);

    /**
     * Moves the Monster to the next step of its patrol route unless
     * the player intersects with the Monster's sight box.
     * The Monster's sight box reaches one time the Monster object's width
     * in all 8 directions.
     */
    void move();

    /**
     * Returns a FloatRect 3 times the Monster's size surrounding it.
     * Simple illustration, S is a part of the sight box while M is the Monster
     * itself:
     * SSS
     * SMS
     * SSS
     * @return A FloatRect representing the Monster object's sight box
     */
    sf::FloatRect getSightBox() const;

    /**
     * Generates a value based on the Monster's min_attack and max_attack
     * variables. This value is doubled if a critical hit is
     * generated, the value is then passed to mov's decreaseHP function.
     * @param mov Movable attacked by the Monster.
     */
    virtual void attack(Movable &mov) override;

private:
    int step{};
    std::vector<std::pair<int, int>> patrol_route;
};

#endif
