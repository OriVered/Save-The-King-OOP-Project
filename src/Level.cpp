#include "Level.h"

/* Constructor / Distructor */
Level::Level(const std::vector<std::string>& levelMap)
{
	setLevel(levelMap, 0);
}

void Level::setLevel(const std::vector<std::string>& levelMap, const int levelNum)
{
	if (!m_movingObject.empty()) m_movingObject.clear();
	if (!m_levelMap.empty()) m_levelMap.clear();
	if (!m_tiles.empty()) m_tiles.clear();
	if (!m_teleporters.empty()) m_teleporters.clear();
	m_levelMap = levelMap;
	m_info.setLevelNum (levelNum+1);
	initLevel();
	initBackground();
}

void Level::pollEvent(const sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
	{
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

void Level::handleKeyPressed(const sf::Keyboard::Key& key)
{
	if (key == sf::Keyboard::Key::P)
		m_player = (m_player + 1) % 4;

	m_movingObject[m_player]->setDirection(key);

}

void Level::update()
{
	move();

	checkCollision();

	m_clock.restart();

	updateTiles();

	updateInfo();
}

void Level::initBackground()
{
	//background image
	//m_background.push_back(GameObject());

	//frame image
	auto frameSize = sf::Vector2u(ObjectSpace * ObjectFactor.x  * (m_levelMap[0].size() + 3), ObjectSpace * ObjectFactor.y * (m_levelMap.size()+3));
	auto framePosition = sf::Vector2f((startBoard.x + frameSize.x)/2, (startBoard.y + frameSize.y)/2);
	//m_background.push_back(GameObject(framePosition, frame, backgroundFactor));
	//m_background[0].setSize(frameSize);
}

void Level::initLevel()
{
	
	auto factor = ObjectFactor;
	m_movingObject.push_back(std::make_unique < King >(startBoard, factor));
	m_movingObject.push_back(std::make_unique < Mage >(startBoard, factor));
	m_movingObject.push_back(std::make_unique < Warrior >(startBoard, factor));
	m_movingObject.push_back(std::make_unique < Thief >(startBoard, factor));

	for (int i = 0; i < m_levelMap.size(); i++)
		for (int j = 0; j < m_levelMap[i].size(); j++)
			initObject(m_levelMap[i][j], initPosition(i, j));

	randomizeTeleporters();
	m_player = king;
	m_clock.restart();
	m_info.restart();
}

void Level::initObject(const int charNum, const sf::Vector2f& position)
{
	auto factor = ObjectFactor;
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
		m_tiles.push_back(std::make_unique < Wall >(position, factor));
		break;
	case gateNum:
		m_tiles.push_back(std::make_unique < Gate >(position, factor));
		break;
	case fireNum:
		m_tiles.push_back(std::make_unique < Fire >(position, factor));
		break;
	case orcNum:
		m_tiles.push_back(std::make_unique < Orc >(position, factor));
		break;
	case keyNum:
		m_tiles.push_back(std::make_unique < Key >(position, factor));
		break;
	case teleporterNum:
		if(m_teleporters.size() && m_teleporters[m_teleporters.size()-1].second->getPosition() == telFirstPos)
			m_teleporters[m_teleporters.size()-1].second->setPosition(position);
		else
            m_teleporters.push_back(std::make_pair(std::make_unique <Teleporter>( position , factor ), std::make_unique <Teleporter>(telFirstPos, factor)));
		break;
	case throneNum:
		m_tiles.push_back(std::make_unique <Throne >(position, factor));
		break;
	case giftDwarfNum:
		m_tiles.push_back(std::make_unique < GiftDwarf >(position, factor));
		break;
	case giftTimeNum:
		m_tiles.push_back(std::make_unique < GiftTime >(position, factor));
		break;
	case dwarfNum:
		m_movingObject.push_back(std::make_unique <Dwarf >(position, factor));
		break;

	}
}

sf::Vector2f Level::initPosition(const int row, const int col)
{
	return sf::Vector2f(startBoard.x + (col * ObjectFactor.x * ObjectSpace), startBoard.y + (row * ObjectFactor.y * ObjectSpace));
}

sf::Vector2f Level::objectFactor()
{
	double factor = boardHeight / (std::max(m_levelMap.size(), m_levelMap[0].size()) * 64);
	factor = (factor > 1.5) ? 1.5 : factor;
	factor = (factor < 0.4) ? 0.4 : factor;
	return sf::Vector2f((float)factor, (float)factor);
}

void Level::randomizeTeleporters()
{
	for (int i = 0; i < m_teleporters.size() ; i++)
	{
			int one = rand() % m_teleporters.size();
			int two = rand() % m_teleporters.size();

			auto temp = std::move( m_teleporters[one].first) ;

			m_teleporters[one].first = std::move(m_teleporters[two].second);
			m_teleporters[two].second = std::move(temp);
	}

}

/* Accesors */
sf::Time Level::getDelteTime()
{
	return m_clock.getElapsedTime();
}

/* Game Functions */
void Level::move()
{
	m_movingObject[m_player]->move(getDelteTime());

	/* DwarfMove */
	srand(time(NULL));
	for(int i = numOfCharacters; i < m_movingObject.size(); i++)
	{
		m_movingObject[i]->move(getDelteTime());
		if (!OutsideBoard(i))
			m_movingObject[i]->moveBack();
		else
			for (int j = 0; j < numOfCharacters; j++)
				if(m_movingObject[i]->collidesWith(*m_movingObject[j]))
					m_movingObject[i]->handleCollision(*m_movingObject[j]);
	}
}


bool Level::isOutsideBoard(int movingObject)
{
	return!(m_movingObject[movingObject]->getGlobalBounds().left < startBoard.x
		|| m_movingObject[movingObject]->getGlobalBounds().top < startBoard.y
		|| m_movingObject[movingObject]->getGlobalBounds().left + TexturSize * ObjectFactor.x > startBoard.x + (ObjectSpace * ObjectFactor.x * m_levelMap[0].size())
		|| m_movingObject[movingObject]->getGlobalBounds().top + TexturSize * ObjectFactor.x > startBoard.y + (ObjectSpace * ObjectFactor.y * m_levelMap.size()));
}

void Level::checkCollision()
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

void Level::draw( sf::RenderWindow& window )
{
	m_info.draw(window);

	for(auto& background: m_background)
		background.draw(window);

	drawObjects(window);
}

void Level::drawObjects( sf::RenderWindow& window)
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
}

void Level::updateInfo()
{
	if(auto thiefPlayer = dynamic_cast<Thief*>(m_movingObject[thief].get()))		
		m_info.update(thiefPlayer->getKey(), m_player);
}

void Level::updateTiles()
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

void evel::checkAddingGifts()
{
	static int giftShowTime = 5;
	if ( std::fmod(m_info.getTimer(), double(giftShowTime)) <= verySmallNum )
	{
		giftShowTime = (rand() % 10) + 5;
		addGift();
		ResourceManager::instance().playSFX(giftShowSound);
	}

}
bool Level::gameOver()
{
	if (m_info.getCountDown() <= 0)
		return true;

	return false;
}
bool Level::levelWin()
{

	if (auto kingplayer = dynamic_cast<King*>(m_movingObject[king].get()))
		return kingplayer->levelEnd();
		
	return false;
}

void Level::addGift()
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

sf::Vector2f Level::randPos()
{
	
	int x = rand() % m_levelMap[0].size();
	int y = rand() % m_levelMap.size();

	while(m_levelMap[y][x] != spaceNum)
	{
		x = rand() % m_levelMap[0].size();
		y = rand() % m_levelMap.size();
	}

	return initPosition(y, x);
}

void Level::deleteDwarf(int numDwarfToDel)
{
	int size = std::min((int)m_movingObject.size() - numOfCharacters, numDwarfToDel);
	m_movingObject.resize(m_movingObject.size() - size);
}
/* global funtion */