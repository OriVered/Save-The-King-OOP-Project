#pragma once

#include "StaticObject.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "Dwarf.h"

class Wall : public StaticObject
{
public:
    /*Constructor / Distructor */
    Wall( const sf::Vector2f& centerPos );

    /* Handle Collision */
    void handleCollision(King&) override;
    void handleCollision(Mage&) override;
    void handleCollision(Warrior&) override;
    void handleCollision(Thief&) override;
    void handleCollision(Dwarf&) override {}
};
