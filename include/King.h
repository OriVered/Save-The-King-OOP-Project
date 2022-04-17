#pragma once

#include "Player.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "Dwarf.h"

class King : public Player
{
public:
    /*Constructor / Distructor */
    King( const sf::Vector2f& CenterPos );

    /* Acceesors */
    bool levelEnd();

    /* Mutator */
    void endLevel();
    
    /* Handle Collision */
    void handleCollision(MovingObject&) override;
    void handleCollision(StaticObject&) override;
    void handleCollision(King&) override {}
    void handleCollision(Mage&) override;
    void handleCollision(Warrior&) override;
    void handleCollision(Thief&) override;
    void handleCollision(Dwarf&) override;
private:
    bool m_endLevel;
};