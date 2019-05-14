#ifndef TDP005_GOLD_H
#define TDP005_GOLD_H


#include "treasure.h"

class Gold : public Treasure {
public:
    /**
     * Gold chests the player can collect to increase the score
     * @param x_val X coordinate of the gold chest
     * @param y_val Y coordinate of the gold chest
     * @param wid Width of the gold chest object
     * @param val The value used to increase the score
     * @param tex Tileset texture to create the sprite from
     * @param rect Area of the tileset to create the sprite from
     */
    Gold(int x_val, int y_val, int wid, int val,
         sf::Texture &tex, sf::IntRect rect);

    /**
     * Collects the treasure and increases player's score based on the
     * Gold object's value variable
     * @param player The Player collecting the Gold object
     */
    virtual void collect(Player &player) override;
};


#endif //TDP005_GOLD_H
