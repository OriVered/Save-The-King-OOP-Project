#include "Teleporter.h"

Teleporter::Teleporter( const sf::Vector2f& CenterPos )
	:StaticObject( CenterPos, teleporter )
{}

void Teleporter::handleCollision(King& king)
{
	ResourceManager::instance().playSFX(teleporterSound);
	king.setPosition(getPosition() + (king.getFactor() * TexturSize * king.getDirection()));
}

void Teleporter::handleCollision(Warrior& warrior)
{
	ResourceManager::instance().playSFX(teleporterSound);
	warrior.setPosition(getPosition() + (warrior.getFactor() * TexturSize * warrior.getDirection()));
}

void Teleporter::handleCollision(Thief& thief)
{
	ResourceManager::instance().playSFX(teleporterSound);
	thief.setPosition(getPosition() + (thief.getFactor() * TexturSize * thief.getDirection()));
}