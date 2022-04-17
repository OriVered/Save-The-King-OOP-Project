#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "GameObject.h"
#include "ResourceManager.h"

class Information
{
public:
	Information();
	void draw(sf::RenderWindow& window) ;
	void updateKey(const bool& key);
	void updatePlayer(const int activePlayer);
	void setLevelNum(const int levelNum);
	void changeTime(int time);
	void update(const bool& key, const int activePlayer);
	double getTimer() const;
	int getCountDown() const;
	void restart();
	bool levelStopped() const;

private:
	sf::Clock m_clock;
	bool m_key;
	int m_character;
	std::vector<Image> m_player;
	double m_timer;
	int m_levelNum;


	sf::Text getTimerText() const;
	sf::Text getKeyText() const;
	sf::Text getLevelNumText() const;
	void drawPlayer(sf::RenderWindow& window);
};