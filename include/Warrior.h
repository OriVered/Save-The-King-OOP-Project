#pragma once

#include "Player.h"
#include "King.h"
#include "Mage.h"
#include "Thief.h"
#include "Dwarf.h"

class Warrior : public Player
{
public:
    /*Constructor / Distructor */
    Warrior(const sf::Vector2f& CenterPos);

    /* Handle Collision */
    void handleCollision(MovingObject&) override;
    void handleCollision(StaticObject&) override;
    void handleCollision(King&) override;
    void handleCollision(Mage&) override;
    void handleCollision(Warrior&) override {}
    void handleCollision(Thief&) override;
    void handleCollision(Dwarf&) override;

};