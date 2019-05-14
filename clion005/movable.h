#ifndef _MOVABLE_H_
#define _MOVABLE_H_

#include "object.h"

class Movable : public Object
{
public:
    Movable();
    /**
     * An abstract class for Movable objects
     * @param x_val X coordinate to spawn the Movable at
     * @param y_val Y coordinate to spawn the Movable at
     * @param wid Width of the Movable
     * @param tex Texture used to create the Movable sprite
     * @param rect Area of the texture to create the Movable sprite from
     * @param max_hp Max health points of the Movable object
     * @param min_att Minimum attack value of the Movable object
     * @param max_att Maximum attack value of the Movable object
     */
    Movable(int x_val, int y_val, int wid, sf::Texture &tex,
            sf::IntRect &rect, int max_hp, int min_att, int max_att);

    virtual ~Movable() = default;

    virtual void attack(Movable&) = 0;
    /**
     * Decreases current_health by damage - the value of the variable equipment_bonus
     * @param damage The value to decrease current_health by
     */
    void decreaseHp(int damage);
    /**
     * Sets current_health to the value of max_health
     */
    void heal();
    /**
     * Checks if current_health is greater than 0
     * @return current_health > 0
     */
    virtual bool active() const override;

    /**
     * Moves the Movable x_move times its width on the X axis
     * and y_move times its width on the Y axis
     * @param x_move The amount of steps to move on the X axis
     * @param y_move The amount of steps to move on the Y axis
     */
    void move(int x_move, int y_move);

protected:
    int equipment_bonus{};
    int max_health{};
    int current_health{};
    int min_attack{};
    int max_attack{};
};

#endif
