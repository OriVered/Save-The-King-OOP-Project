#include "ResourceManager.h"


//makes an instance and is created only once
ResourceManager& ResourceManager::instance()
{
	static ResourceManager instance;
	return instance;
}


sf::Texture* ResourceManager::getTexture(const Type_t name)
{
	return &(m_textures[name]);
}

sf::Font* ResourceManager::getFont(const Type_f name)
{
	return &(m_fonts[name]);
}

sf::SoundBuffer& ResourceManager::getSound(const Type_s name)
{
	return m_soundBuff[name];
}

//Constructor
ResourceManager::ResourceManager()
{
	/* Load Textures */
	for(int i = 0; i < numOfTextures; i++)
		loadTexture(TextureFiles[i], (Type_t)i);

	/* Load Fonts */
	for (int i = 0; i < numOfFonts; i++)
		loadFont(FontFiles[i], (Type_f)i);

	/* load Sounds */
	for (int i = 0; i < numOfSounds; i++)
		loadSound(SoundFiles[i], (Type_s)i);

	setSounds();
}

void ResourceManager::loadTexture(const std::string path, const Type_t name)
{
	sf::Texture temp;
	temp.loadFromFile(path);
	m_textures[name] = temp;
}

void ResourceManager::loadFont(const std::string path, const Type_f name)
{
	sf::Font temp;
	temp.loadFromFile(path);
	m_fonts[name] = temp;
}

void ResourceManager::loadSound(const std::string path, const Type_s name)
{
	sf::SoundBuffer temp;
	temp.loadFromFile(path);
	m_soundBuff[name] = temp;
}

void ResourceManager::setSounds()
{
	for(int i = 0; i < numOfSounds; i++)
	{
		m_sounds.push_back(sf::Sound(getSound(Type_s(i))));
		m_sounds[i].setVolume(m_volume);
	}
}

void ResourceManager::stopAllSongs()
{
	for (auto& sound:m_sounds)
		sound.stop();
}

void ResourceManager::playSFX(Type_s sound)
{
	m_sounds[int(sound)].play();
}

void ResourceManager::playSong()
{
	stopAllSongs();
	m_sounds[int(m_playing)].play();
	m_sounds[int(m_playing)].setVolume(30);
}

void ResourceManager::setSong(const int song)
{
	m_playing = (Type_s)song;
	playSong();
}

void ResourceManager::volUp()
{
	if(m_volume+ volStep <volMax)
		m_volume += volStep;
	setVolumeAll();
}

void ResourceManager::volDown()
{
	if(m_volume-volStep >= volMin)
		m_volume -= volStep;
	setVolumeAll();
}

void ResourceManager::setVolumeAll()
{
	for (auto& sound:m_sounds)
		sound.setVolume(m_volume);
}

void ResourceManager::setVolumeSong(const Type_s name, const int volume)
{
	m_sounds[int(m_playing)].setVolume(volume);
}