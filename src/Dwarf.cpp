#include"Dwarf.h"

Dwarf::Dwarf( const sf::Vector2f& CenterPos)
	:MovingObject( CenterPos, dwarf )
{}

void Dwarf::handleCollision(MovingObject& movingObject)
{
	if ( &movingObject == this ) return;
	movingObject.handleCollision(*this);
}

void Dwarf::handleCollision(StaticObject& staticObject)
{
	staticObject.handleCollision(*this);
}

void Dwarf::handleCollision(King& king)
{
	ResourceManager::instance().playSFX(collisionSound);
	king.moveBack();
}

void Dwarf::handleCollision(Mage& mage)
{
	ResourceManager::instance().playSFX(collisionSound);
	mage.moveBack();
}

void Dwarf::handleCollision(Warrior& warrior)
{
	ResourceManager::instance().playSFX(collisionSound);
	warrior.moveBack();
}

void Dwarf::handleCollision(Thief& thief)
{
	ResourceManager::instance().playSFX(collisionSound);
	thief.moveBack();
}


void Dwarf::move( const sf::Time& deltaTime )
{
	
	auto random = rand();
	m_lastPosition = m_sprite.getPosition();
    m_sprite.move( randomDirection(random) * dwarfSpeed * deltaTime.asSeconds() );
}

sf::Vector2f Dwarf::randomDirection(const int random)
{
	auto dir = random % 5;
    
	switch (dir)
	{
	case 1:
		return sf::Vector2f(1, 0); break;
	case 2:
		return sf::Vector2f(-1, 0); break;
	case 3:
		return sf::Vector2f(0, -1); break;
	case 4:
		return sf::Vector2f(0, 1); break;
	default://reset direction
		return sf::Vector2f(0, 0); break;
	}
}