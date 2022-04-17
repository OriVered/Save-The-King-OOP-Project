#pragma once
#include "Image.h"

class King;
class Mage;
class Warrior;
class Thief;
class Dwarf;

class GameObject: public Image
{
public:
    /* Constructor / Distructor */
    GameObject( const sf::Vector2f& CenterPos, Type_t objectTex);
    virtual ~GameObject() = default;
};
