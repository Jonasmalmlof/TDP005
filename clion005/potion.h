#ifndef TDP005_POTION_H
#define TDP005_POTION_H


#include "treasure.h"

class Potion : public Treasure {
public:
    /**
     * A potion the player can collect to restore themselves to full health
     * @param x_val X coordinate of the potion
     * @param y_val Y coordinate of the potion
     * @param wid Width of the potion object
     * @param val Value used to increase the score of the player object
     * @param tex Tileset texture to create the sprite from
     * @param rect Area of the tileset to create the sprite from
     */
    Potion(int x_val, int y_val, int wid, int val,
           sf::Texture &tex, sf::IntRect rect);

    /**
     * Heals the Player object player and sets
     * the Potion object's collected variable to true
     * @param player The player object that collected the potion
     */
    virtual void collect(Player &player) override;
};


#endif //TDP005_POTION_H
