#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <SFML/Graphics.hpp>

class Object : public sf::Drawable
{
public:
    Object();
    /**
     * Creates an object with a position, width and sprite
     * @param x_val X coordinate for the object
     * @param y_val Y coordinate for the object
     * @param wid Width of the object
     * @param tex Texture used to create the sprite
     * @param rect The area of the texture to create the sprite from
     */
    Object(int x_val, int y_val, int wid, sf::Texture &tex, sf::IntRect rect);
    virtual ~Object() = default;

    virtual bool active() const = 0;
    /**
     * @return The sprite variable of the Object
     */
    sf::Sprite getSprite() const;

    /**
     * Draws the Ovject's sprite in the target,
     * implementing this function has the effect that
     * all objects of classes derived from Object
     * can be sent to a sf::RenderWindow's draw function
     * directly and be drawn correctly in the window
     * @param target The RenderTarget to draw to
     */
    virtual void draw(sf::RenderTarget &target, sf::RenderStates) const override;

protected:
    int x{};
    int y{};
    int width{};
    sf::Sprite sprite{};
};

#endif
