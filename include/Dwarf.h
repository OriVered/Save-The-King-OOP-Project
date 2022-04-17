#pragma once

#include <time.h>
#include "MovingObject.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"

class Dwarf : public MovingObject
{
public:
    Dwarf( const sf::Vector2f& CenterPos);
    void move(const sf::Time& deltaTime) override;
    sf::Vector2f randomDirection(const int random);

    /* Handle Collision */
     void handleCollision(MovingObject&) override;
     void handleCollision(StaticObject&) override;
     void handleCollision(King&) override;
     void handleCollision(Mage&) override;
     void handleCollision(Warrior&) override;
     void handleCollision(Thief&) override;
     void handleCollision(Dwarf&) override{}
private:
};