#ifndef TDP005_GOAL_H
#define TDP005_GOAL_H

#include "object.h"

class Goal : public Object
{
public:
    Goal();
    /**
     * Creates a goal object that knows if the
     * @param x_val
     * @param y_val
     * @param wid
     * @param tex
     * @param rect
     */
    Goal(int x_val, int y_val, int wid, sf::Texture &tex, sf::IntRect rect);

    /**
     * Checks if the level has been completed, either by the player dying
     * or the player completing the level
     * @return The value of finished
     */
    virtual bool active() const override;

    /**
     * Sets the finished variable to true
     */
    void endGame();

    /**
     * Changes the sprite to the open door sprite when
     * the level is cleared of monsters and treasures
     */
    void changeSprite();

private:
    bool finished{false};
};


#endif //TDP005_GOAL_H
