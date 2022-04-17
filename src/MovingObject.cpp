#include "MovingObject.h"

MovingObject::MovingObject( const sf::Vector2f& CenterPos, Type_t objectTex)
	:GameObject( CenterPos, objectTex ), m_direction(sf::Vector2f(0, 0)), m_lastPosition(sf::Vector2f(0, 0))
{}

bool MovingObject::collidesWith( const GameObject& gameObject )
{
	if ( &gameObject == this ) 
		return false;
	else 
		return getGlobalBounds().intersects(gameObject.getGlobalBounds());
}

void  MovingObject::setDirection(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Key::Right:
		m_direction = sf::Vector2f(1, 0); break;
	case sf::Keyboard::Key::Left:
		m_direction = sf::Vector2f(-1, 0); break;
	case sf::Keyboard::Key::Up:
		m_direction = sf::Vector2f(0, -1); break;
	case sf::Keyboard::Key::Down:
		m_direction = sf::Vector2f(0, 1); break;
	default://reset direction
		m_direction = sf::Vector2f(0, 0); break;
	}
}

sf::Vector2f& MovingObject::getDirection()
{
	return m_direction;
}

void MovingObject::moveBack()
{
	m_sprite.setPosition(m_lastPosition);
}