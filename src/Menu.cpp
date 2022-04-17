#include "Menu.h"


Menu::Menu()
    :State(backgroundMenu, menuState), m_click(0), m_menuImage(menuImagePosition, menu, menuFactor)
{
    initMenu();
}
Menu::~Menu()
{}

void Menu::initMenu()
{
    m_menuImage.setSize(menuSize);
    initButtons();
}

void Menu::initButtons()
{
    for (int i = 0; i < numOfButton; i++)
    {
        m_buttons.push_back(Image( sf::Vector2f(centerScreen.x, startButtons + (i * spaceButtons)), Type_t(i + buttonGame), menuFactor));
        m_buttons[i].setSize(buttonSize);
    }
}

void Menu::pollEvents(sf::RenderWindow& window, const sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::Closed:
    {
        window.close();
        break;
    }
    case sf::Event::KeyPressed:
    {
        if (event.key.code == sf::Keyboard::Escape)
        {
            setBackground(backgroundMenu);
            m_click = 0;//reset to menu
        }
        break;
    }
    case sf::Event::MouseButtonReleased:
    {
        auto location = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
        checkClick(location);
        handleClick(window);
        break;
    }
    }
    
}

void Menu::handleClick(sf::RenderWindow& window)
{
    switch (m_click)
    {
    case gameButton:
    case menuButton:
    case rulesButton:
    {
        m_screen = m_click;
        break;
    }
    case exitButton:
    {
        window.close();
        break;
    }
    default:
        break;
    }
}

void Menu::checkClick( const sf::Vector2f& location)
{
    m_click = 0;
    for (auto i = 0; i < m_buttons.size(); ++i)
        if (m_buttons[i].getGlobalBounds().contains(location))
            m_click = i+1;
}

void Menu::draw(sf::RenderWindow& window)
{
    //deaw background
    m_background.draw(window);
    //draw Menu Image
    m_menuImage.draw(window);
    //draw Buttons
    for (int i = 0; i < m_buttons.size(); i++)
        m_buttons[i].draw(window);
}