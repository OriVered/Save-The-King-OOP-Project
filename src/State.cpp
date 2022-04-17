#include "State.h"

State::State(Type_t background, int screen)
	:m_background(background), m_screen(screen)
{
}

void State::setBackground(const Background& background)
{
	m_background = Background(background);
}

int State::getScreen() const
{
	return m_screen;
}

void State::setScreen(int screen)
{
	m_screen = screen;
}
