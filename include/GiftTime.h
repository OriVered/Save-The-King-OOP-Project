#pragma once

#include "Gift.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "Dwarf.h"

class GiftTime : public Gift
{
public:
    /*Constructor / Distructor */
    GiftTime( const sf::Vector2f&);

    /* Accessors */
    virtual int getGift() override;

private:
    int m_time;
};
