#pragma once

#include "StaticObject.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "Dwarf.h"

class Gift : public StaticObject
{
public:
    /*Constructor / Distructor */
    Gift( const sf::Vector2f& CenterPos );

    /* Accessors */
    virtual int getGift() = 0;

    /* Handle Collision */
    void handleCollision(King&) override;
    void handleCollision(Mage&) override;
    void handleCollision(Warrior&) override;
    void handleCollision(Thief&) override;
    void handleCollision(Dwarf&) override {}
};
