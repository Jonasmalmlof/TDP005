#ifndef TDP005_TREASURE_H
#define TDP005_TREASURE_H


#include "object.h"
#include "player.h"

class Treasure : public Object {
public:
    /**
     * Abstract class for treasure objects
     * @param x_val X coordinate of the treasure
     * @param y_val Y coordinate of the treasure
     * @param wid Width of the treasure object
     * @param tex Tileset texture to create the sprite from
     * @param rect Area of the tileset to create the sprite from
     */
    Treasure(int x_val, int y_val, int wid, int val,
             sf::Texture &tex, sf::IntRect rect);
    virtual ~Treasure() = default;

    /**
     * Function for collecting a treasure object
     * @param player The player object that collects the treasure
     */
    virtual void collect(Player &player) = 0;

    /**
     * Returns if the object is active or should be deleted,
     * it determines this by looking at the collected variable
     * and returning the opposite of it, since all collected
     * treasures should be removed from the playing field
     * @return !collected
     */
    virtual bool active() const override;

protected:
    int value{};
    bool collected{false};
};


#endif //TDP005_TREASURE_H
