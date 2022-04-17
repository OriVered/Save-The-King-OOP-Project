#include "Gift.h"

Gift::Gift( const sf::Vector2f& CenterPos )
	:StaticObject( CenterPos, gift )
{}

void Gift::handleCollision( King& king)
{
    ResourceManager::instance().playSFX(giftDeleteSound);
	toDelete();
}

void Gift::handleCollision( Mage& mage)
{
    ResourceManager::instance().playSFX(giftDeleteSound);
    toDelete();
}

void Gift::handleCollision( Warrior& warrior)
{
    ResourceManager::instance().playSFX(giftDeleteSound);
    toDelete();
}

void Gift::handleCollision( Thief& thief)
{
    ResourceManager::instance().playSFX(giftDeleteSound);
    toDelete();
}