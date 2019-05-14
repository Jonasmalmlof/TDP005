#include <fstream>
#include <sstream>

#include "level.h"

Level::Level(int lvl) : level{lvl}
{
    /**
     * This tileset is made by the user Buch,
     * http://opengameart.org/users/buch, from
     * opengameart.org and is available for download at:
     * http://opengameart.org/content/dungeon-tileset
     *
     * License: Public Domain
     * https://creativecommons.org/publicdomain/zero/1.0/
     */
    tileset.loadFromFile("img/dungeon_tiles.png");

    /**
     * This tileset is made by the user Buch,
     * http://opengameart.org/users/buch, from
     * opengameart.org and is available for download at:
     * http://opengameart.org/content/rpg-items
     *
     * License: Public Domain
     * https://creativecommons.org/publicdomain/zero/1.0/
     */
    i_tiles.loadFromFile("img/items.png");

    IntRect bg_rect{38, 38, 67, 67};
    background.setTexture(tileset);
    background.setTextureRect(bg_rect);
    background.setScale(1024 / float(bg_rect.width),
                        768 / float(bg_rect.height));

    IntRect status_rect{225,137,38,38};
    player_status.setTexture(i_tiles);
    player_status.setTextureRect(status_rect);
    player_status.setScale(240/float(38), 144/float(38));
    player_status.setPosition(0,624);

    readLevel();
}

void Level::addMonster(std::string line)
{
    vector<std::pair<int, int>> route;
    std::stringstream stream(line);
    std::string junk;
    int x_{};
    int y_{};
    std::string direction{};

    /** The first character in the line indicates that this is a
     * line that should be passed to addMonster and is thus not necessary
     * anymore, which is why we read it to a variable named junk
     */
    stream>>junk;

    stream>>x_;
    stream>>y_;

    while(true)
    {
        stream>>direction;
        if(!stream)
        {
            break;
        }
        if ( direction == "up" )
        {
            route.push_back(std::make_pair(0, -1));
        }
        else if ( direction == "down" )
        {
            route.push_back(std::make_pair(0, 1));
        }
        else if ( direction == "left" )
        {
            route.push_back(std::make_pair(-1, 0));
        }
        else if ( direction == "right" )
        {
            route.push_back(std::make_pair(1, 0));
        }
    }

    IntRect monster_rect{217,160,17,19};

    monsters.push_back(Monster(x_*48, y_*48, 48, tileset,
                               monster_rect, 100, 10, 30, route));
}

void Level::addObjects(std::string line, int y)
{
    IntRect player_rect{167, 162, 23, 18};
    IntRect boss_rect{206, 182, 17, 19};
    IntRect wall_rect{88, 208, 16, 16};
    IntRect door_rect{156, 212, 16, 16};
    IntRect gold_r{142, 112, 16, 16};
    IntRect equip_r{96, 54, 29, 29};
    IntRect potion_r{52, 143, 29, 25};

    int x{};

    for(char c : line )
    {
        if ( c == '#')
        {
            walls.push_back(Wall(x*48, y*48, 48, tileset, wall_rect));
        }
        else if ( c == 'P')
        {
            player = Player(x*48, y*48, 48, tileset,
                            player_rect, 100, 50, 90);
        }
        else if ( c == 'G')
        {
            treasures.push_back(new Gold(x*48, y*48, 48, 100,
                                         tileset, gold_r));
        }
        else if ( c == 'H')
        {
            treasures.push_back(new Potion(x*48, y*48, 48, 0,
                                           i_tiles, potion_r));
        }
        else if ( c == 'E')
        {
            treasures.push_back(new Equipment(x*48, y*48, 48, 10,
                                              i_tiles, equip_r));
        }
        else if ( c == 'B' )
        {
            vector<std::pair<int, int>> route;
            route.push_back(std::make_pair(0,0));

            monsters.push_back(Monster(x*48, y*48, 96, tileset,
                                       boss_rect, 200, 20, 60, route));
        }
        else if ( c == 'X')
        {
            goal = Goal(48*x, 48*y, 48, tileset, door_rect);
        }
        x++;
    }
}

void Level::readLevel()
{
    std::string line;
    std::ifstream current_level ("levels/" + std::to_string(level) + ".map");

    if (current_level)
    {
        int y {};

        while (getline (current_level, line))
        {
            if (line[0] == '<')
            {
                addMonster(line);
            }
            else
            {
                addObjects(line, y);
                y++;
            }
        }
        current_level.close();
    }
}

Sprite Level::getBg() const
{
    return background;
}

Player Level::getPlayer() const
{
    return player;
}

Goal Level::getGoal() const
{
    return goal;
}

vector<Treasure *> Level::getTreasures() const
{
    return treasures;
}

vector<Wall> Level::getWalls() const
{
    return walls;
}

vector<Monster> Level::getMonsters() const
{
    return monsters;
}

Sprite Level::getStatus() const
{
    return player_status;
}