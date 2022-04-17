#include"Key.h"

Key::Key( const sf::Vector2f& CenterPos )
	:StaticObject(CenterPos, key)
{}

void Key::handleCollision(Thief& thief)
{
	if (!thief.getKey())
	{
		toDelete();
		thief.setKey(true);
		ResourceManager::instance().playSFX(deleteSound);
	}
}