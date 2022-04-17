#include "GiftDwarf.h"

GiftDwarf::GiftDwarf( const sf::Vector2f& CenterPos )
    :Gift( CenterPos )
{
    srand(time(NULL));
    m_delDwarf = rand() % 3;
}

int GiftDwarf::getGift()
{
    return m_delDwarf;
}