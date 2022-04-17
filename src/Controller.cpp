#include "Controller.h"

/* Constructors / Distructors */
Controller::Controller()
{
	initMenu();
	
	initWindow();

	ResourceManager::instance().setSong((int)Type_s::mainTrack);
}

Controller::~Controller()
{	
	if (m_window)
		delete m_window;
}

/* Private Functions */
void Controller::initMenu()
{
	stateNum = 0;
	m_state.push_back(std::make_unique < Menu >() );
}

void Controller::initWindow()
{
	m_videoMode.width = WindowWidth;
	m_videoMode.height = WindowHeight;
	m_window = new sf::RenderWindow(m_videoMode, "Save The King", sf::Style::Default |sf::Style::Titlebar | sf::Style::Close);
}

/* Window Functions */
void Controller::run()
{
	while (m_window->isOpen())
	{
		// Update
		update();

		// Render
		render();
	}
}

void Controller::update()
{
	pollEvents();
	
	if(m_state.back()->getScreen() != stateNum)
		updateStates();

	m_state.back()->update();
}

void Controller::updateStates()
{
	stateNum = m_state.back()->getScreen();
	m_state.pop_back();
	switch (stateNum)
	{
	case menuState:
	{
		m_state.push_back(std::make_unique < Menu >());
		stateNum = menuState;
		break;
	}
	case gameState:
	{
		
		m_state.push_back(std::make_unique < LevelController >());
		stateNum = gameState;
		break;
	}
	case ruleState:
	{

		m_state.push_back(std::make_unique < Rules >());
		stateNum = ruleState;
	}
	}
}

void Controller::pollEvents()
{
	while (m_window->pollEvent(m_event))
			m_state.back()->pollEvents(*m_window, m_event);
}

void Controller::render()
{
	m_window->clear();

	/* Draw State */
	m_state.back()->draw(*m_window);

	m_window->display();
}
