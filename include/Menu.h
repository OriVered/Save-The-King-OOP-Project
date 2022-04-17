#pragma once
#include "State.h"


class Menu : public State
{
public:
	Menu();
	~Menu();

	virtual void pollEvents(sf::RenderWindow& window, const sf::Event& event) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void update() override {}

private:
	std::vector<Image> m_buttons;
	Image m_menuImage;
	int m_click;

	//Menu functions
	void handleClick(sf::RenderWindow& window);
	void checkClick(const sf::Vector2f& location);

	void initMenu();
	void initButtons();
};