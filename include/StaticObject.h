#pragma once
#include "GameObject.h"
class King;
class Mage;
class Warrior;
class Thief;
class Dwarf;
class Player;

class StaticObject : public GameObject
{
public:
    /*Constructor / Distructor */
    StaticObject( const sf::Vector2f& CenterPos, Type_t objectTex );
	virtual ~StaticObject() = default;
	
    /* Accesors */
    bool isErase();

    /* Mutator */
    void toDelete();

    /* Handle Collision */
    virtual void handleCollision(King&) = 0;
    virtual void handleCollision(Mage&) = 0;
    virtual void handleCollision(Warrior&) = 0;
    virtual void handleCollision(Thief&) = 0;
    virtual void handleCollision(Dwarf&) = 0;

protected:
    bool m_delete;
};
