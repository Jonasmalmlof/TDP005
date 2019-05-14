#ifndef TDP005_WALL_H
#define TDP005_WALL_H


#include "object.h"

class Wall : public Object {
public:
    /**
     * Generic wall object on the level
     * @param x_val X coordinate of the wall
     * @param y_val Y coordinate of the wall
     * @param wid Width of the wall
     * @param tex Tileset texture to create the sprite from
     * @param rect Area of the tileset to create the sprite from
     */
    Wall(int x_val, int y_val, int wid, sf::Texture& tex, sf::IntRect rect);

private:
    /**
     * Set to always return true, since walls always are
     * active objects as long as the level is active
     * @return true
     */
    virtual bool active() const override;
};


#endif //TDP005_WALL_H
