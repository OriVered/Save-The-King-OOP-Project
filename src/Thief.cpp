#include"Thief.h"

Thief::Thief( const sf::Vector2f& CenterPos )
	:Player( CenterPos, thief ), m_key( false )
{}

void Thief::handleCollision(MovingObject& movingObject)
{
	if (&movingObject == this) return;
	movingObject.handleCollision(*this);
}

void Thief::handleCollision(StaticObject& staticObject)
{
	staticObject.handleCollision(*this);
}

void Thief::handleCollision(King& king)
{
	ResourceManager::instance().playSFX(collisionSound);
	king.moveBack();
}

void Thief::handleCollision(Mage& mage)
{
	ResourceManager::instance().playSFX(collisionSound);
	mage.moveBack();
}

void Thief::handleCollision(Warrior& warrior)
{
	ResourceManager::instance().playSFX(collisionSound);
	warrior.moveBack();
}

void Thief::handleCollision(Dwarf& dwarf)
{
	dwarf.moveBack();
}

bool Thief::getKey()
{
	return m_key;
}

void Thief::setKey(const bool key)
{
	m_key = key;
}