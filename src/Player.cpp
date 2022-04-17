#include "Player.h"

Player::Player( const sf::Vector2f& CenterPos, Type_t objectTex )
	:MovingObject( CenterPos, objectTex )
{}


void Player::move(const sf::Time& deltaTime)
{
	m_lastPosition = m_sprite.getPosition();
	m_sprite.move(m_direction * CharacterSpeed * deltaTime.asSeconds());
}

