#include <random>

#include "player.h"

Player::Player() : Movable() {}

Player::Player(int x_val, int y_val, int wid, sf::Texture &tex,
               sf::IntRect &rect, int max_hp, int min_att, int max_att)
        : Movable(x_val, y_val, wid, tex, rect, max_hp, min_att, max_att) {}

void Player::increaseScore(int s)
{
    score+=s;
}

void Player::increaseExperience(int e)
{
    experience_points+=e;

    // Experience points needed to level up increase by every level
    // and the level cap is set to 10
    if (experience_points > (50 + level*30) && level < 10)
    {
        experience_points -= (50 + level*30);
        max_health+=10;
        current_health+=10;
        ++level;
    }
}

void Player::changeSprite()
{
    sprite.setTextureRect(sf::IntRect(180,183,20,18));
}

void Player::equipTreasure(int val)
{
    equipment_bonus+=val;
    changeSprite();
}

int Player::getScore() const
{
    return score;
}

int Player::getHealth() const
{
    return current_health;
}

int Player::getMaxHealth() const
{
    return max_health;
}

void Player::attack(Movable &mov)
{
    int crit_modifier {1};
    std::random_device rd;
    std::uniform_int_distribution<> critical_roll(1,100);

    //Checks if the attack is a critical hit,
    // the chance increases by 2% for every player level
    if(critical_roll(rd) > 92-level*2)
    {
        crit_modifier=2;
    }

    std::uniform_int_distribution<> attack_values(min_attack, max_attack);
    int dmg {(attack_values(rd)+equipment_bonus+(level-1)*5)*crit_modifier};

    mov.decreaseHp(dmg);
}

int Player::getExperiencePoints() const {
    return experience_points;
}

int Player::getLevel() const {
    return level;
}

void Player::setLevel(int val)
{
    level = val;
    max_health = 90 + val*10;
    current_health = 90 + val*10;
}

void Player::setExperience(int exp)
{
    experience_points=exp;
}

void Player::setScore(int sco)
{
    score=sco;
}