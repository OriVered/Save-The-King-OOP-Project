#include"Rules.h"

Rules::Rules()
	:State(gameRules, ruleState)
{}

Rules::~Rules()
{}

void Rules::pollEvents(sf::RenderWindow& window, const sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::Closed:
    {
        window.close();
        break;
    }
    case sf::Event::KeyPressed:
    case sf::Event::MouseButtonReleased:
        m_screen = menuButton;
    }

}

void Rules::draw(sf::RenderWindow& window)
{
    //draw background
    m_background.draw(window);
}