#include"King.h"

King::King( const sf::Vector2f& CenterPos )
	:Player( CenterPos, king ), m_endLevel(false)
{}

void King::handleCollision(MovingObject& movingObject)
{
	if (&movingObject == this) return;
	movingObject.handleCollision(*this);
}

void King::handleCollision(StaticObject& staticObject)
{
	staticObject.handleCollision(*this);
}

void King::handleCollision(Mage& mage)
{
	mage.moveBack();
}

void King::handleCollision(Warrior& warrior)
{
	ResourceManager::instance().playSFX(collisionSound);
	warrior.moveBack();
}


void King::handleCollision(Thief& thief)
{
	ResourceManager::instance().playSFX(collisionSound);
	thief.moveBack();
}

void King::handleCollision(Dwarf& dwarf)
{
	dwarf.moveBack();
}

void King::endLevel()
{
	m_endLevel = true;
}

bool King::levelEnd()
{
	return m_endLevel;
}
