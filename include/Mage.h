#pragma once

#include "Player.h"
#include "King.h"
#include "Warrior.h"
#include "Thief.h"
#include "Dwarf.h"

class Mage : public Player
{
public:
    /*Constructor / Distructor */
    Mage( const sf::Vector2f& CenterPos );

    /* Handle Collision */
    void handleCollision(MovingObject&) override;
    void handleCollision(StaticObject&) override;
    void handleCollision(King&) override;
    void handleCollision(Mage&) override{}
    void handleCollision(Warrior&) override;
    void handleCollision(Thief&) override;
    void handleCollision(Dwarf&) override;

private:
};