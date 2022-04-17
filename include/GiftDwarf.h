#pragma once

#include "Gift.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "Dwarf.h"

class GiftDwarf : public Gift
{
public:
    /*Constructor / Distructor */
    GiftDwarf( const sf::Vector2f& CenterPos);

    /* Accessors */
    virtual int getGift() override;

private:
    int m_delDwarf;
};
