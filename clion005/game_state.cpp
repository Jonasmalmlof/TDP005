#include "game_state.h"
#include "game.h"

Game_State::Game_State() : levels{3}, player_level {1},
                           player_experience{}, player_score {} {}

void Game_State::run(sf::RenderWindow &window)
{
    for (int l{1}; l<=levels; ++l)
    {
        Game g{l, player_level, player_experience, player_score};

        /**
         * If Game::run returns false it means that the player has died or
         * if the user has tried to close the window, which tells
         * Game_State that the next level shouldn't be loaded
         */
        if(!g.run(window))
        {
            break;
        }

        /**
         * If the level is completed Game_State saves the
         * player stats and loads them into the next level
         */
        player_level = g.getPlayer().getLevel();
        player_experience = g.getPlayer().getExperiencePoints();
        player_score = g.getPlayer().getScore();
    }
}

