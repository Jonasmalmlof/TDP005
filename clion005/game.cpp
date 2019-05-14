#include "game.h"

Game::Game(int lvl, int play_level, int play_exp, int play_score) : level{lvl}
{
    monsters = level.getMonsters();

    player = level.getPlayer();
    player.setLevel(play_level);
    player.setExperience(play_exp);
    player.setScore(play_score);

    treasures = level.getTreasures();

    goal = level.getGoal();

    background = level.getBg();

    walls = level.getWalls();

    status = level.getStatus();

    font.loadFromFile("Ubuntu-R.ttf");

    score_text.setFont(font);
    score_text.setPosition(25,722);
    score_text.setCharacterSize(22);
    score_text.setColor(sf::Color::Red);

    health_text.setFont(font);
    health_text.setPosition(25,639);
    health_text.setCharacterSize(22);
    health_text.setColor(sf::Color::Red);

    experience_text.setFont(font);
    experience_text.setPosition(25,695);
    experience_text.setCharacterSize(22);
    experience_text.setColor(sf::Color::Red);

    level_text.setFont(font);
    level_text.setPosition(25,668);
    level_text.setCharacterSize(22);
    level_text.setColor(sf::Color::Red);
}

void Game::removeInactiveObjects()
{
    int step{};
    bool dead{false};

    for ( Monster &m : monsters )
    {
        if (!m.active())
        {
            dead = true;
            break;
        }
        ++step;
    }

    if (dead)
    {
        monsters.erase(monsters.begin()+step);
        player.increaseExperience(50);
        player.increaseScore(10);
        dead = false;
    }

    step = 0;

    for ( Treasure* t : treasures )
    {
        if(!t->active())
        {
            delete t;
            dead = true;
            break;
        }
        ++step;
    }

    if (dead)
    {
        treasures.erase(treasures.begin()+step);
    }

    //If the player is dead, end the level
    if (!player.active())
    {
        goal.endGame();
    }
}

void Game::moveMovables(int mov_x, int mov_y)
{
    player.move(mov_x, mov_y);

    //If the player collides with the goal
    if(player.getSprite().getGlobalBounds().intersects(
            goal.getSprite().getGlobalBounds()))
    {
        //If all monsters are dead and all treasures
        // are collected, end the level
        if( monsters.size() == 0 && treasures.size() == 0)
        {
            goal.endGame();
        }
        else
        {
            //move the player back to the previous position
            player.move(-mov_x, -mov_y);
        }
    }

    //If the player collides with a wall,
    // move the player back to the previous position
    for ( Wall& w : walls )
    {
        if(player.getSprite().getGlobalBounds().intersects(
                w.getSprite().getGlobalBounds()))
        {
            player.move(-mov_x, -mov_y);
        }
    }

    for ( Monster& m : monsters)
    {
        //If the Monster is alive and the player isn't within
        // the Monster's sight, move the Monster
        if (m.active() && !m.getSightBox().intersects(
                player.getSprite().getGlobalBounds())) {
            m.move();
        }

        //If the Player collides with a Monster, move the player to
        // its previous position and have the player attack the Monster
        if (player.getSprite().getGlobalBounds().intersects(
                m.getSprite().getGlobalBounds()))
        {
            player.attack(m);
            player.move(-mov_x, -mov_y);

            //If the Monster survived the attack,
            // have the Monster attack the Player
            if (m.active()) {
                m.attack(player);
            }
        }
    }

    //If the Player collides with a Treasure, collect the Treasure
    for ( Treasure* t : treasures)
    {
        if(player.getSprite().getGlobalBounds().intersects(
                t->getSprite().getGlobalBounds()))
        {
            t->collect(player);
            break;
        }
    }

    removeInactiveObjects();

    //If all Treasures are collected and all Monsters are dead
    // change the sprite of the goal
    if (treasures.size() == 0 && monsters.size() == 0)
    {
        goal.changeSprite();
    }
}

void Game::processEvent(Event e)
{
    if ((e.type == Event::KeyReleased) && (e.key.code == Keyboard::W))
    {
        moveMovables(0, -1);
    }
    else if ((e.type == Event::KeyReleased) && (e.key.code == Keyboard::A))
    {
        moveMovables(-1, 0);
    }
    else if ((e.type == Event::KeyReleased) && (e.key.code == Keyboard::S))
    {
        moveMovables(0, 1);
    }
    else if ((e.type == Event::KeyReleased) && (e.key.code == Keyboard::D))
    {
        moveMovables(1, 0);
    }
}

void Game::update(RenderWindow &window)
{
    window.clear();
    window.draw(background);

    for ( Wall& wall : walls)
    {
        window.draw(wall);
    }

    for ( Monster& m : monsters)
    {
        window.draw(m);
    }

    for ( Treasure* t : treasures)
    {
        window.draw(*t);
    }

    window.draw(player);
    window.draw(goal);
    window.draw(status);

    score_text.setString("Score: " + std::to_string(player.getScore()));
    window.draw(score_text);

    health_text.setString("Health: " +
                          std::to_string(player.getHealth()) + "/" +
                                  std::to_string(player.getMaxHealth()));
    window.draw(health_text);

    experience_text.setString("Experience: " +
                              std::to_string(player.getExperiencePoints()));
    window.draw(experience_text);

    level_text.setString("Level: " + std::to_string(player.getLevel()));
    window.draw(level_text);

    window.display();
}

bool Game::run(RenderWindow &window)
{
    while (!goal.active())
    {
        Event event;

        while (window.pollEvent(event))
        {
            processEvent(event);
        }

        update(window);

        if(event.type == Event::Closed)
        {
            break;
        }
    }

    return player.active() && goal.active();
}

Player Game::getPlayer() const
{
    return player;
}