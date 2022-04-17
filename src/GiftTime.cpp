#include "GiftTime.h"

GiftTime::GiftTime( const sf::Vector2f& CenterPos )
    :Gift( CenterPos )
{
    srand(time(NULL));
    m_time = (rand() % 10) - 5;
    
}

int GiftTime::getGift()
{
    return m_time;
}