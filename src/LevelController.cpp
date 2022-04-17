#include "LevelController.h"

/* Constructor / Distructor */
LevelController::LevelController()
	:State(backgroundGame, gameState), m_levelMap(), m_LevelNum(0)
{
	setLevel();
}

/* init Level Controller functions */
void LevelController::setLevel()
{
	if (!m_movingObject.empty()) m_movingObject.clear();
	if (!m_tiles.empty()) m_tiles.clear();
	if (!m_teleporters.empty()) m_teleporters.clear();

	m_info.setLevelNum (m_LevelNum+1);
	initLevel();
}


void LevelController::initLevel()
{
	initCharacters();

	for (int i = 0; i < m_levelMap[m_LevelNum].size(); i++)
		for (int j = 0; j < m_levelMap[m_LevelNum][i].size(); j++)
			initObject(m_levelMap[m_LevelNum][i][j], initPosition(i, j));

	randomizeTeleporters();
	m_player = king;
	m_clock.restart();
	m_info.restart();
}

void LevelController::initCharacters()
{
	m_movingObject.push_back(std::make_unique < King >(startBoard));
	m_movingObject.push_back(std::make_unique < Mage >(startBoard));
	m_movingObject.push_back(std::make_unique < Warrior >(startBoard));
	m_movingObject.push_back(std::make_unique < Thief >(startBoard));
}

void LevelController::initObject(const int charNum, const sf::Vector2f& position)
{
	switch (charNum)
	{
	case kingNum:
		m_movingObject[king]->setPosition(position);
		break;
	case mageNum:
		m_movingObject[mage]->setPosition(position);
		break;
	case warriorNum:
		m_movingObject[warrior]->setPosition(position);
		break;
	case thiefNum:
		m_movingObject[thief]->setPosition(position);
		break;
	case wallNum:
		m_tiles.push_back(std::make_unique < Wall >(position));
		break;
	case gateNum:
		m_tiles.push_back(std::make_unique < Gate >(position));
		break;
	case fireNum:
		m_tiles.push_back(std::make_unique < Fire >(position));
		break;
	case orcNum:
		m_tiles.push_back(std::make_unique < Orc >(position));
		break;
	case keyNum:
		m_tiles.push_back(std::make_unique < Key >(position));
		break;
	case throneNum:
		m_tiles.push_back(std::make_unique <Throne >(position));
		break;
	case giftDwarfNum:
		m_tiles.push_back(std::make_unique < GiftDwarf >(position));
		break;
	case giftTimeNum:
		m_tiles.push_back(std::make_unique < GiftTime >(position));
		break;
	case dwarfNum:
		m_movingObject.push_back(std::make_unique <Dwarf >(position));
		break;
	case teleporterNum:
		if (m_teleporters.size() && m_teleporters[m_teleporters.size() - 1].second->getPosition() == telFirstPos)
			m_teleporters[m_teleporters.size() - 1].second->setPosition(position);
		else
			m_teleporters.push_back(std::make_pair(std::make_unique <Teleporter>(position), std::make_unique <Teleporter>(telFirstPos)));
		break;
	}
}

sf::Vector2f LevelController::initPosition(const int row, const int col)
{
	return sf::Vector2f(startBoard.x + (col * ObjectFactor.x * ObjectSpace), startBoard.y + (row * ObjectFactor.y * ObjectSpace));
}

void LevelController::randomizeTeleporters()
{
	for (int i = 0; i < m_teleporters.size(); i++)
	{
		int one = rand() % m_teleporters.size();
		int two = rand() % m_teleporters.size();

		std::unique_ptr temp = std::move(m_teleporters[one].first);

		m_teleporters[one].first = std::move(m_teleporters[two].second);
		m_teleporters[two].second = std::move(temp);
	}

}

//-----------------------------------------------------------------------------
/* Update Function */
void LevelController::update()
{
	move();

	checkCollision();

	m_clock.restart();

	updateTiles();

	updateInfo();
}

void LevelController::pollEvents(sf::RenderWindow& window, const sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::Closed:
	{
		window.close();
		break;
	case sf::Event::KeyPressed:
	{
		if (event.key.code == sf::Keyboard::Escape)
			m_screen = menuButton;
		handleKeyPressed(event.key.code);
		break;
	}
	case sf::Event::KeyReleased:
	{
		//reset direction
		handleKeyPressed(sf::Keyboard::Space);
		break;
	}
	default:
		break;
	}
	}
}

void LevelController::handleKeyPressed(const sf::Keyboard::Key& key)
{
	if (key == sf::Keyboard::Key::P)
		m_player = (m_player + 1) % 4;

	m_movingObject[m_player]->setDirection(key);

}

//-----------------------------------------------------------------------------
/* Accesors */
sf::Time LevelController::getDelteTime() const
{
	return m_clock.getElapsedTime();
}

//-----------------------------------------------------------------------------
/* Game Functions */
/* Movment Functions */
void LevelController::move()
{
	//Player Move
	m_movingObject[m_player]->move(getDelteTime());

	dwarfMove();
}

void LevelController::dwarfMove()
{
	srand(time(NULL));
	for(int i = numOfCharacters; i < m_movingObject.size(); i++)
	{
		m_movingObject[i]->move(getDelteTime());
		if (OutsideBoard(i))
			m_movingObject[i]->moveBack();
		else
			for (int j = 0; j < numOfCharacters; j++)
				if(m_movingObject[i]->collidesWith(*m_movingObject[j]))
					m_movingObject[i]->handleCollision(*m_movingObject[j]);
	}
}


bool LevelController::OutsideBoard(int movingObject) const
{
	return(m_movingObject[movingObject]->getGlobalBounds().left < startBoard.x
		|| m_movingObject[movingObject]->getGlobalBounds().top < startBoard.y
		|| m_movingObject[movingObject]->getGlobalBounds().left + TexturSize * ObjectFactor.x > startBoard.x + (ObjectSpace * ObjectFactor.x * m_levelMap[m_LevelNum][0].size())
		|| m_movingObject[movingObject]->getGlobalBounds().top + TexturSize * ObjectFactor.x > startBoard.y + (ObjectSpace * ObjectFactor.y * m_levelMap[m_LevelNum].size()));
}

void LevelController::checkCollision() const
{
	//check with teleporters obppjects
	for (auto& teleport : m_teleporters)
	{
		if (m_movingObject[m_player]->collidesWith(*teleport.first))
			m_movingObject[m_player]->handleCollision(*teleport.second);
		else if (m_movingObject[m_player]->collidesWith(*teleport.second))
			m_movingObject[m_player]->handleCollision(*teleport.first);
	}

	//check with charecters
	for (auto& moving : m_movingObject)
		if (m_movingObject[m_player]->collidesWith(*moving))
			m_movingObject[m_player]->handleCollision(*moving);

	//check with static objects
	for (auto& tile : m_tiles)
		if (m_movingObject[m_player]->collidesWith(*tile))
			m_movingObject[m_player]->handleCollision(*tile);
	//check board borders
	if (OutsideBoard(m_player))
		m_movingObject[m_player]->moveBack();
}

//-----------------------------------------------------------------------------
/* Draw Functions*/
void LevelController::draw( sf::RenderWindow& window )
{
	m_background.draw(window);

	drawObjects(window);

	m_info.draw(window);
}

void LevelController::drawObjects( sf::RenderWindow& window)
{
	//drawObject with charecters
	for (auto& moving :m_movingObject)
		moving->draw(window);

	//drawObject static objects\Board
	for (auto& tile :m_tiles)
		tile->draw(window);

	//drawObject teleporters
	for (auto& teleporter :m_teleporters)
	{
		teleporter.first->draw(window);
		teleporter.second->draw(window);
	}

	checkEndOfLevel(window);
}
//-----------------------------------------------------------------------------
/* information Functions */
void LevelController::updateInfo()
{
	if(auto thiefPlayer = dynamic_cast<Thief*>(m_movingObject[thief].get()))		
		m_info.update(thiefPlayer->getKey(), m_player);
}

/* Statics Functions */

void LevelController::updateTiles()
{
	checkAddingGifts();

	for (auto& tile :m_tiles)
	{
		if (tile->isErase())
		{
			if (auto orc = dynamic_cast<Orc*>(tile.get()))
				initObject(keyNum, tile->getPosition());
			
			if (auto giftTime = dynamic_cast<GiftTime*>(tile.get()))
				m_info.changeTime(giftTime->getGift());
			if (auto giftDwarf = dynamic_cast<GiftDwarf*>(tile.get()))
				deleteDwarf(giftDwarf->getGift());
		}
	}
	std::erase_if(m_tiles, [](const auto& tile) { return tile->isErase(); });
}

void LevelController::checkAddingGifts()
{
	static int giftShowTime = 5;
	if ( std::fmod(m_info.getTimer(), double(giftShowTime)) <= verySmallNum )
	{
		giftShowTime = (rand() % 10) + 5;
		addGift();
		ResourceManager::instance().playSFX(giftShowSound);
	}

}
void LevelController::addGift()
{
	static int numOfGifts = 0;
	numOfGifts++;
	srand(time(NULL));
	auto random = rand();
	srand(random);
	initObject(giftDwarfNum, randPos());
	srand(random* random);
	initObject(giftTimeNum, randPos());
}

sf::Vector2f LevelController::randPos()
{
	
	int x = rand() % m_levelMap[m_LevelNum][0].size();
	int y = rand() % m_levelMap[m_LevelNum].size();

	while(m_levelMap[m_LevelNum][y][x] != spaceNum)
	{
		x = rand() % m_levelMap[m_LevelNum][0].size();
		y = rand() % m_levelMap[m_LevelNum].size();
	}

	return initPosition(y, x);
}

void LevelController::deleteDwarf(int numDwarfToDel)
{
	int size = std::min((int)m_movingObject.size() - numOfCharacters, numDwarfToDel);
	m_movingObject.resize(m_movingObject.size() - size);
}



//-----------------------------------------------------------------------------
/* End Level Functions */
void LevelController::checkEndOfLevel(sf::RenderWindow& window)
{
	if (m_info.getCountDown() <= 0)
		gameOver(window);

	else if (levelWin())
	{
		m_LevelNum++;
		if (m_LevelNum == m_levelMap.getnumOfLevel())
			gameWin(window);
		else
			levelUp(window);
	}
}

bool LevelController::levelWin() const
{
	if (auto kingplayer = dynamic_cast<King*>(m_movingObject[king].get()))
		return kingplayer->levelEnd();

	return false;
}

void LevelController::gameOver(sf::RenderWindow& window)
{
	endLevelImage(window, gameOverImage, gameOverSound);
	m_screen = menuState;
}

void LevelController::levelUp(sf::RenderWindow& window)
{
	setLevel();
	endLevelImage(window, levelUpImage, levelUpSound);
}

void LevelController::gameWin(sf::RenderWindow& window)
{
	endLevelImage(window, gameWinImage, gameWinSound);
	m_screen = menuState;
}

void LevelController::endLevelImage(sf::RenderWindow& window, Type_t image, Type_s sound)
{
	auto sprite = Image(menuImagePosition, image, menuFactor);
	sprite.setSize(menuSize);
	sf::Clock clock;
	clock.restart();
	ResourceManager::instance().setVolumeSong(mainTrack, (int)mute);
	ResourceManager::instance().playSFX(sound);
	while ((double)clock.getElapsedTime().asSeconds() < 3)
	{
		window.clear();
		m_background.draw(window);
		sprite.draw(window);
		window.display();
	}
	ResourceManager::instance().setVolumeSong(mainTrack, (int)musicVolume);
}
