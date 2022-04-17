#include "Wall.h"

Wall::Wall( const sf::Vector2f& CenterPos )
	:StaticObject( CenterPos, wall )
{}

void Wall::handleCollision( King& king )
{
	ResourceManager::instance().playSFX(collisionSound);
	king.moveBack();
}

void Wall::handleCollision(Mage& mage )
{
	ResourceManager::instance().playSFX(collisionSound);
	mage.moveBack();
}

void Wall::handleCollision( Warrior& warrior )
{
	ResourceManager::instance().playSFX(collisionSound);
	warrior.moveBack();
}

void Wall::handleCollision(Thief& thief )
{
	ResourceManager::instance().playSFX(collisionSound);
	thief.moveBack();
}