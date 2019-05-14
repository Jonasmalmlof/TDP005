#ifndef TDP005_GAME_STATE_H
#define TDP005_GAME_STATE_H


#include <SFML/Graphics/RenderWindow.hpp>

class Game_State {
public:
    /**
     * Creates a Game_State that starts on level 1 and currently a total of 3 levels
     */
    Game_State();

    /**
     * Starts the game loop, creating Game objects
     * until the player dies or the player has completed all available levels
     * @param window The window where the game is run
     */
    void run(sf::RenderWindow &window);

private:
    int levels{};
    int player_level{};
    int player_experience{};
    int player_score{};
};


#endif //TDP005_GAME_STATE_H
