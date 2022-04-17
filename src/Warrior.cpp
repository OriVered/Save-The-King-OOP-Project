#include"Warrior.h"

Warrior::Warrior( const sf::Vector2f& CenterPos )
	:Player( CenterPos, warrior )
{}

void Warrior::handleCollision(MovingObject& movingObject)
{
	if (&movingObject == this) return;
	movingObject.handleCollision(*this);
}

void Warrior::handleCollision(StaticObject& staticObject)
{
	staticObject.handleCollision(*this);
}

void Warrior::handleCollision(King& king)
{
	ResourceManager::instance().playSFX(collisionSound);
	king.moveBack();
}

void Warrior::handleCollision(Mage& mage)
{
	ResourceManager::instance().playSFX(collisionSound);
	mage.moveBack();
}

void Warrior::handleCollision(Thief& warrior)
{
	ResourceManager::instance().playSFX(collisionSound);
	warrior.moveBack();
}

void Warrior::handleCollision(Dwarf& dwarf)
{
	dwarf.moveBack();
}