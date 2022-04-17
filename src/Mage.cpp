#include"Mage.h"

Mage::Mage( const sf::Vector2f& CenterPos )
	:Player( CenterPos, mage )
{}

void Mage::handleCollision(MovingObject& movingObject)
{
	if (&movingObject == this) return;
	movingObject.handleCollision(*this);
}

void Mage::handleCollision(StaticObject& staticObject)
{
	staticObject.handleCollision(*this);
}

void Mage::handleCollision(King& king)
{
	ResourceManager::instance().playSFX(collisionSound);
	king.moveBack();
}

void Mage::handleCollision(Warrior& warrior)
{
	ResourceManager::instance().playSFX(collisionSound);
	warrior.moveBack();
}

void Mage::handleCollision(Thief& thief)
{
	ResourceManager::instance().playSFX(collisionSound);
	thief.moveBack();
}

void Mage::handleCollision(Dwarf& dwarf)
{
	dwarf.moveBack();
}