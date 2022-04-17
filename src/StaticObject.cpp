#include "StaticObject.h"

StaticObject::StaticObject( const sf::Vector2f& CenterPos, Type_t objectTex)
	: GameObject( CenterPos, objectTex ), m_delete(false)
{}

void StaticObject::toDelete()
{
	m_delete = true;
}

bool StaticObject::isErase()
{
	return m_delete;
}
