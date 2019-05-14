#ifndef TDP005_LEVEL_H
#define TDP005_LEVEL_H

#include <SFML/Graphics.hpp>

#include "monster.h"
#include "player.h"
#include "wall.h"
#include "goal.h"
#include "gold.h"
#include "equipment.h"
#include "potion.h"

using sf::Event;
using sf::RenderWindow;
using sf::VideoMode;
using sf::Keyboard;
using sf::Texture;
using sf::Sprite;
using sf::IntRect;
using std::vector;

class Level {
public:
    /**
     * Loads the tilesets and then calls on readLevel with the parameter l
     * @param l The number of the level to generate
     */
    Level(int lvl);

    /**
     * @return The background sprite of the level
     */
    Sprite getBg() const;

    /**
     * @return The Goal object of the level
     */
    Goal getGoal() const;

    /**
     * @return The Player object of the level
     */
    Player getPlayer() const;

    /**
     * @return The status box sprite of the level
     */
    Sprite getStatus() const;

    /**
     * @return The vector of all the walls of the level
     */
    vector<Wall> getWalls() const;

    /**
     * @return The vector of all the monsters of the level
     */
    vector<Monster> getMonsters() const;

    /**
     * @return The vector of all of the treasures of the level
     */
    vector<Treasure*> getTreasures() const;

private:
    /**
     * Generates and adds a Monster object to the vector monsters
     * based on the information provided in the parameter line
     * @param line The information used to generate the Monster object
     */
    void addMonster(std::string line);

    /**
     * Generates and adds objects to the level
     * based on the characters in the parameter line
     * @param line The information used to generate objects
     * @param y The line number, used to generate the
     * y coordinate of the created objects
     */
    void addObjects(std::string line, int y);

    /**
     * Generates a level from a .map file
     */
    void readLevel();

    int level {};
    Goal goal;
    Player player;
    Texture tileset;
    Texture i_tiles;
    Sprite background;
    Sprite player_status;
    vector<Wall> walls;
    vector<Monster> monsters;
    vector<Treasure*> treasures;
};


#endif //TDP005_LEVEL_H
