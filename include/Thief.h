#pragma once

#include "Player.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Dwarf.h"

class Thief : public Player
{
public:
    /*Constructor / Distructor */
    Thief( const sf::Vector2f& CenterPos);
        
    bool getKey() ;
    void setKey(const bool key);

    /* Handle Collision */
    void handleCollision(MovingObject&) override;
    void handleCollision(StaticObject&) override;
    void handleCollision(King&) override;
    void handleCollision(Mage&) override;
    void handleCollision(Warrior&) override;
    void handleCollision(Thief&) override{}
    void handleCollision(Dwarf&) override;
private:
    bool m_key;
};