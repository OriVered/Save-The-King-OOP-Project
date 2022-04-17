#include"GameObject.h"
GameObject::GameObject( const sf::Vector2f& CenterPos, Type_t objectTex )
	:Image(CenterPos, objectTex, ObjectFactor)
{}