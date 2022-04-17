#pragma once
#include <vector>
#include <utility>
#include "macros.h"
#include "ResourceManager.h"

class Image
{
public:
    /* Constructor / Distructor */
    Image( const sf::Vector2f& CenterPos, Type_t objectTex, const sf::Vector2f& factor);
    virtual ~Image() = default;

    /* draw */
    void draw( sf::RenderWindow& window );
    /* Accesors */
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    float getFactor() const;
    sf::FloatRect getGlobalBounds() const;

    /* Mutator */
    void setPosition( const sf::Vector2f& pos );
    void setScale( const float scale );
    void setOrigin( const float x, const float y );
    void setSize( const sf::Vector2u size );

protected:
    sf::Sprite m_sprite;
};
