#ifndef TDP005_GAME_H
#define TDP005_GAME_H

#include <SFML/Graphics.hpp>

#include "monster.h"
#include "treasure.h"
#include "wall.h"
#include "goal.h"
#include "player.h"
#include "level.h"

using sf::Event;
using sf::RenderWindow;
using sf::Keyboard;
using sf::Texture;
using sf::Sprite;
using sf::IntRect;
using sf::Font;
using sf::Text;
using std::vector;

class Game {
public:
    /**
     * Creates a Game object able to play a Level
     * @param lvl The level number to play
     * @param play_level The starting level of the Player
     * @param play_exp The starting experience of the Player
     * @param play_score The starting score of the Player
     */
    Game(int lvl, int play_level, int play_exp, int play_score);

    /**
     * @return The Player object of the Game
     */
    Player getPlayer() const;

    /**
     * Starts the game loop and sends events to the event handler
     * @param window The game window
     * @return If the Player is alive and the Level has been completed
     */
    bool run(RenderWindow &window);

private:
    /**
     * Removes all inactive Objects from the Game loop,
     * to stop them being drawn after becoming inactive
     */
    void removeInactiveObjects();

    /**
     * Call on the move functions for all Movables
     * @param mov_x The amount of squares the player should move on the X axis
     * @param mov_y The amount of squares the player should move on the Y axis
     */
    void moveMovables(int mov_x, int mov_y);

    /**
     * Processes all events polled from the RenderWindow
     * @param e The current Event needing to be handled
     */
    void processEvent(Event e);

    /**
     * Update the visuals of the Game
     * @param window The window to draw the visuals in
     */
    void update(RenderWindow &window);

    Level level{1};
    vector<Monster> monsters;
    vector<Treasure*> treasures;
    vector<Wall> walls;
    Goal goal;
    Player player;
    Sprite background;
    Sprite status;
    Font font;
    Text score_text;
    Text health_text;
    Text experience_text;
    Text level_text;
};


#endif //TDP005_GAME_H
