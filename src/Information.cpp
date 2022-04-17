#include "Information.h"


Information::Information()
    : m_key(false), m_character(king), m_levelNum (1)
{

    restart();
}


void Information::restart()
{
    m_clock.restart();

    for (int i = 0; i < numOfCharacters; i++)
        m_player.push_back(Image(infoPlayer, (Type_t)i, infoFactor));

    srand(time(NULL));
    m_timer = (double)((rand() % endRandTimer) + startRandTimer);

}
double Information::getTimer() const
{
    return m_timer;
}


void Information::changeTime(int time)
{
    m_timer += time;
}

void Information::setLevelNum(const int levelNum)
{
    m_levelNum = levelNum;
}

sf::Text Information::getTimerText() const
{
    std::ostringstream convert;
    std::string timerString = "Time left: ";
    std::string sentence;
    std::stringstream sstm;
    sstm << timerString << (int)m_timer;
    sentence = sstm.str();
    sf::Text timerText;

    //convert << (int)m_timer;
    //timerString.append(convert.str());
    sf::Font* font = ResourceManager::instance().getFont(algertxt);


    timerText.setFont(*font);
    timerText.setString(sentence);
    timerText.setPosition(infoTimer);
    timerText.setCharacterSize(40);

    return timerText;
}


sf::Text Information::getKeyText() const
{
    sf::Text keyText;
    std::string keyString;

    if (m_key)
        keyString = "you have a key";
    else
        keyString = "you don't have a key";

    sf::Font* font = ResourceManager::instance().getFont(algertxt);


    keyText.setFont(*font);
    keyText.setString(keyString);
    keyText.setPosition(infoKey);
    //keyText.setColor(sf::Color::Black);
    keyText.setCharacterSize(charSize);

    return keyText;

}

sf::Text Information::getLevelNumText() const
{
    sf::Text levelText;
    std::string levelString = "Level: ";
    std::ostringstream convert;
    sf::Font* font = ResourceManager::instance().getFont(algertxt);

    convert << m_levelNum;
    levelString.append(convert.str());

    levelText.setFont(*font);
    levelText.setString(levelString);
    levelText.setPosition(infoLevel);
    levelText.setCharacterSize(40);

    return levelText;
    
}
int Information::getCountDown() const
{
    return (int)m_timer;
}

void Information::updateKey(const bool& key)
{
    m_key = key;
}

void Information::update(const bool& key, const int activePlayer)
{
    
    auto elpaseTime = m_clock.restart().asSeconds();
    m_timer -= elpaseTime;

    updateKey(key);
    updatePlayer(activePlayer);

}

void Information::updatePlayer(const int activePlayer)
{
    m_character = activePlayer;
}

void Information::draw(sf::RenderWindow& window)
{
    drawPlayer(window);
    window.draw(getTimerText());
    window.draw(getLevelNumText());
    window.draw(getKeyText());
    

}

void Information::drawPlayer(sf::RenderWindow& window)
{
    
    m_player[m_character].draw(window);

}

bool Information::levelStopped() const
{
    return true;
}

