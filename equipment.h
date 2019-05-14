#ifndef TDP005_EQUIPMENT_H
#define TDP005_EQUIPMENT_H


#include "treasure.h"

class Equipment : public Treasure {
public:
    /**
     * Equipment the player can collect to increase damage given
     * and decrease damage taken
     * @param x_val X coordinate of the equipment
     * @param y_val Y coordinate of the equipment
     * @param wid Width of the equipment object
     * @param val Value used to increase/decrease damage
     * @param tex Tileset texture to create the sprite from
     * @param rect Area of the tileset to create the sprite from
     */
    Equipment(int x_val, int y_val, int wid, int val,
              sf::Texture &tex, sf::IntRect rect);

    /**
     * Calls on player's equipTreasure function with
     * the equipment object's value variable as its parameter
     * @param player The player object that collects the equipment
     */
    virtual void collect(Player &player) override;
};


#endif //TDP005_EQUIPMENT_H
