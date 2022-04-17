#include "Gate.h"

Gate::Gate( const sf::Vector2f& CenterPos )
	:StaticObject( CenterPos, gate )
{}

void Gate::handleCollision(King& king)
{
	ResourceManager::instance().playSFX(collisionSound);
	king.moveBack();
}

void Gate::handleCollision(Mage& mage)
{
	ResourceManager::instance().playSFX(collisionSound);
	mage.moveBack();
}

void Gate::handleCollision(Warrior& warrior)
{
	ResourceManager::instance().playSFX(collisionSound);
	warrior.moveBack();
}

void Gate::handleCollision( Thief& thief)
{
	
    if(thief.getKey())
	{
		ResourceManager::instance().playSFX(deleteSound);
        toDelete();
		thief.setKey(false);
	}
	else
		ResourceManager::instance().playSFX(collisionSound);
		thief.moveBack();
}