#include "Throne.h"

Throne::Throne( const sf::Vector2f& CenterPos )
	:StaticObject( CenterPos, throne )
{}

void Throne::handleCollision(King& king)
{
	//end level sound
	king.endLevel();
}

void Throne::handleCollision(Mage& mage)
{
	ResourceManager::instance().playSFX(collisionSound);
	mage.moveBack();
}

void Throne::handleCollision(Warrior& warrior)
{
	ResourceManager::instance().playSFX(collisionSound);
	warrior.moveBack();
}

void Throne::handleCollision(Thief& thief)
{
	ResourceManager::instance().playSFX(collisionSound);
	thief.moveBack();
}