#include"Image.h"

/* Constructor / Distructor */
Image::Image( const sf::Vector2f& CenterPos, Type_t objectTex, const sf::Vector2f& factor )
{
	sf::Texture* texture = ResourceManager::instance().getTexture( objectTex );
	m_sprite.setTexture(*texture);
	m_sprite.setOrigin( float( texture->getSize().x / 2), float(texture->getSize().y / 2) );
	m_sprite.setScale( factor );
	setPosition( CenterPos );
}

/* Accesors */
sf::FloatRect Image::getGlobalBounds() const
{
	return m_sprite.getGlobalBounds();
}

sf::Vector2f Image::getPosition() const
{
	return m_sprite.getPosition();
}

sf::Vector2f Image::getSize() const
{
	return sf::Vector2f( float( m_sprite.getTextureRect().width ), float( m_sprite.getTextureRect().height ) );
}

float Image::getFactor() const
{
	return m_sprite.getScale().x;
}

/* Mutator */
void Image::setPosition(const sf::Vector2f& pos)
{
	m_sprite.setPosition( pos );
}

void Image::setSize( const sf::Vector2u size )
{
	m_sprite.scale( ( size.x / m_sprite.getGlobalBounds().width ), ( size.y / m_sprite.getGlobalBounds().height ) );
}


void Image::setOrigin(const float x, const float y)
{
	m_sprite.setOrigin(x, y);
}

void Image::setScale( const float scale )
{
	m_sprite.setScale( sf::Vector2f( scale, scale ) );
}

/* Draw */
void Image::draw( sf::RenderWindow& window )
{
	window.draw( m_sprite );
}