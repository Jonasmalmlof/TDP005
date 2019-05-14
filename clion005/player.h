#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SFML/Graphics/Sprite.hpp>

#include "movable.h"

class Player : public Movable
{
public:
    Player();

    /**
     * The player object that the player can control
     * @param x_val X coordinate to spawn the player at
     * @param y_val Y coordinate to spawn the player at
     * @param wid Width of the player object
     * @param tex Texture used to create the player sprite
     * @param rect Area of the texture to create the player sprite from
     * @param max_hp Max health points of the player object
     * @param min_att Minimum attack value of the player object
     * @param max_att Maximum attack value of the player object
     */
    Player(int x_val, int y_val, int wid, sf::Texture &tex,
         sf::IntRect &rect, int max_hp, int min_att, int max_att);

    /**
     * Generates a value based on the player's min_attack, max_attack
     * and level variables. This value is doubled if a critical hit is
     * generated, the value is then passed to mov's decreaseHP function.
     * @param mov Movable attacked by the player.
     */
    virtual void attack(Movable &mov) override;

    /**
     * Increases the score variable with the value of sco
     * @param sco The value used to increase the score variable
     */
    void increaseScore(int sco);

    /**
     * Increases the experience_points variable with the value of exp
     * @param exp The value used to increase the experience_points variable
     */
    void increaseExperience(int exp);

    /**
     * Increases the equipment_bonus variable with the value of val
     * @param val The value used to increase the equipment_bonus variable
     */
    void equipTreasure(int val);

    /**
     * @return The Player score variable
     */
    int getScore() const;

    /**
     * @return The Player experience_points variable
     */
    int getExperiencePoints() const;

    /**
     * @return The Player current_health variable
     */
    int getHealth() const;

    /**
     * @return The Player max_health variable
     */
    int getMaxHealth() const;

    /**
     * @return The Player level variable
     */
    int getLevel() const;

    /**
     * Sets the player level to val, and
     * current_health and max_health to 90 + 10 * val
     * @param val Value used to set the player level
     */
    void setLevel(int val);

    /**
     * Sets the experience_points variable to exp
     * @param exp Value used to set the value of experience_points
     */
    void setExperience(int exp);

    /**
     * Sets the score variable to sco
     * @param sco Value used to set the value of score
     */
    void setScore(int sco);

private:
    /**
     * Changes the player sprite, called on by equipTreasure()
     */
    void changeSprite();

    int experience_points {};
    int score{};
    int level{1};
};

#endif
