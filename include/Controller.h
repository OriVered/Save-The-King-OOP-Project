#pragma once

#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include "macros.h"
#include "Menu.h"
#include "LevelController.h"
#include "Rules.h"


class Controller
{
public:
	/*constructor Distructor */
	Controller();
	~Controller();

	/* Window Functions */
	void update();
	void render();
	void pollEvents();
	void run();

private:
	/* Window members */
	sf::RenderWindow* m_window = nullptr;
	sf::VideoMode m_videoMode;
	sf::Event m_event;
	sf::Music m_music;

	/* Game members */
	std::vector<std::unique_ptr<State>> m_state;
	int stateNum = 0;	
	
	/* Private Functions */
	void updateStates();
	void initWindow();
	void initMenu();
};
