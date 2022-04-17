#pragma once
#include "MovingObject.h"


class Player : public MovingObject
{
public:
    /* Constructor / Distructor */
    Player( const sf::Vector2f& CenterPos, Type_t objectTex);
    virtual ~Player() = default;

    /* Mutator */
    void move( const sf::Time& deltaTime ) override;
    
};
