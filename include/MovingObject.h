#pragma once

#include "GameObject.h"
#include "StaticObject.h"


class MovingObject : public GameObject
{
public:
    /* Constructor / Distructor */
    MovingObject( const sf::Vector2f& CenterPos, Type_t objectTex );
    virtual ~MovingObject() = default;

    /* Handle Collision */
    virtual void handleCollision(MovingObject&) = 0;
    virtual void handleCollision(StaticObject&) = 0;
    virtual void handleCollision(King&) = 0;
    virtual void handleCollision(Mage&) = 0;
    virtual void handleCollision(Warrior&) = 0;
    virtual void handleCollision(Thief&) = 0;
    virtual void handleCollision(Dwarf&) = 0;
    
    /* Mutator */
    virtual void move( const sf::Time& deltaTime ) = 0;
    virtual  void setDirection(sf::Keyboard::Key key = sf::Keyboard::Key::Space);
    void moveBack();
    /* Accesors */
    bool collidesWith( const GameObject& obj );
    sf::Vector2f& getDirection();
    
protected:
    
    sf::Vector2f m_direction;
    sf::Vector2f m_lastPosition;

};
