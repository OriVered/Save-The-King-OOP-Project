//this class is singleton class
#pragma once

#include <unordered_map>
#include <string>
#include "macros.h"


class ResourceManager
{
public:
	//make the static event so we wont load the textures multiple times
	static ResourceManager& instance();
	sf::Texture* getTexture(const Type_t);
	sf::Font* getFont (const Type_f name);
	void setSong(const int);
	void volUp();
	void volDown();
	void playSFX(Type_s sound);
	sf::SoundBuffer& getSound(const Type_s name);
	void setVolumeSong(const Type_s name, const int volume);
private:

	ResourceManager(); //private ctor for singleton
	void loadTexture(const std::string, const Type_t);
	void loadFont(const std::string path, const Type_f name);
	void loadSound(const std::string path, const Type_s name);
	void setSounds();
	void stopAllSongs();
	void playSong();
	void setVolumeAll();

	std::unordered_map<Type_t, sf::Texture> m_textures;
	std::unordered_map<Type_f, sf::Font> m_fonts;
	std::unordered_map<Type_s, sf::SoundBuffer> m_soundBuff;
	
	std::vector <sf::Sound> m_sounds;
	Type_s m_playing;
	int m_volume = mediumVol;
};