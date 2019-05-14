#include <utility>

#include "object.h"

Object::Object() : x{}, y{}, width{} {}

Object::Object(int x_val, int y_val, int wid,
               sf::Texture &tex, sf::IntRect rect)
        : x{x_val}, y{y_val}, width{wid}, sprite{tex, rect}
{
    sprite.setPosition(x, y);

    //Scales the sprite to be the same size on the screen as the object
    // is in the game's logic
    sprite.setScale(width/float(rect.width), width/float(rect.height));
}

void Object::draw(sf::RenderTarget &target, sf::RenderStates) const
{
    target.draw(sprite);
}

sf::Sprite Object::getSprite() const
{
    return sprite;
}