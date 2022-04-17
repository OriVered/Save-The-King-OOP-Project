#pragma once

#include <vector>
#include <algorithm>
#include <utility>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "macros.h"
#include "State.h"
#include "LevelMap.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "Fire.h"
#include "Key.h"
#include "Orc.h"
#include "Gate.h"
#include "Throne.h"
#include "Wall.h"
#include "Teleporter.h"
#include "Gift.h"
#include "GiftTime.h"
#include "GiftDwarf.h"
#include "Information.h"

class LevelController: public State
{
public:
	/* Constructor / Distructor */
	LevelController();

	/* Window Functions */
	virtual void pollEvents(sf::RenderWindow& window, const sf::Event& event) override;
	virtual void update() override;
	virtual void draw(sf::RenderWindow& window) override;

private:
	//Level Map
	LevelMap m_levelMap;
	int m_LevelNum;
	
	//Level Controller Objects
	std::vector<std::unique_ptr<MovingObject>> m_movingObject;
	std::vector<std::unique_ptr<StaticObject>> m_tiles;
	std::vector<std::pair<std::unique_ptr<StaticObject>, std::unique_ptr<StaticObject>>> m_teleporters;
	int m_player;//current Player sign

	//level information
	Information m_info;
	sf::Clock m_clock;
	
	/* Game Functions */
	// Draw Objects
	void drawObjects(sf::RenderWindow& window);
	void checkEndOfLevel(sf::RenderWindow& window);
	void gameWin(sf::RenderWindow& window);
	void gameOver(sf::RenderWindow& window);
	void levelUp(sf::RenderWindow& window);
	void endLevelImage(sf::RenderWindow& window, Type_t image, Type_s sound);

	//Update
	void handleKeyPressed(const sf::Keyboard::Key& key);
	void move();
	void dwarfMove();
	void updateTiles();
	void randomizeTeleporters();
	void addGift();
	void updateInfo();
	void deleteDwarf(int numDwarfToDel);

	/* Accesors */
	sf::Time getDelteTime() const;
	bool OutsideBoard(int movingObject) const;
	bool levelWin() const;
	void checkCollision() const;
	void checkAddingGifts();

	/* Mutator */
	void initLevel();
	void initCharacters();
	void initObject(const int charNum, const sf::Vector2f& position);
	sf::Vector2f initPosition(const int row, const int col);
	sf::Vector2f randPos();
	void setLevel();


};