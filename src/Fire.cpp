#include"Fire.h"

Fire::Fire( const sf::Vector2f& CenterPos)
	:StaticObject( CenterPos, fire )
{}

void Fire::handleCollision(King& king)
{
	ResourceManager::instance().playSFX(collisionSound);
	king.moveBack();
}


void Fire::handleCollision(Mage& mage)
{
	ResourceManager::instance().playSFX(deleteSound);
	toDelete();
}

void Fire::handleCollision(Warrior& warrior)
{
	ResourceManager::instance().playSFX(collisionSound);
	warrior.moveBack();
}

void Fire::handleCollision(Thief& thief)
{
	ResourceManager::instance().playSFX(collisionSound);
	thief.moveBack();
}