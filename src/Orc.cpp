#include "Orc.h"

Orc::Orc( const sf::Vector2f& CenterPos )
	:StaticObject( CenterPos, orc )
{}

void Orc::handleCollision(King& king)
{
	ResourceManager::instance().playSFX(collisionSound);
	king.moveBack();
}

void Orc::handleCollision(Mage& mage)
{
	ResourceManager::instance().playSFX(collisionSound);
	mage.moveBack();
}

void Orc::handleCollision(Warrior& warrior)
{
	toDelete();
	ResourceManager::instance().playSFX(keyShowSound);
}

void Orc::handleCollision(Thief& thief)
{
	ResourceManager::instance().playSFX(collisionSound);
	thief.moveBack();
}