#pragma once
#include <vector>
#include "macros.h"
#include "Background.h"
#include "ResourceManager.h"
#include "Image.h"

class State
{
public:
	State(Type_t background,int screen);
	virtual ~State() = default;

	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void pollEvents( sf::RenderWindow& window, const sf::Event& event) = 0;

	void setBackground(const Background& background);
	int getScreen() const;
	void setScreen(int screen);

protected:
	int m_screen;
	Background m_background;
};