#include "Background.h"

 Background::Background(const Type_t background)
	:Image( (sf::Vector2f)centerScreen, background , backgroundFactor)
{
	m_sprite.scale((WindowWidth / m_sprite.getGlobalBounds().width), (WindowHeight / m_sprite.getGlobalBounds().height));
}