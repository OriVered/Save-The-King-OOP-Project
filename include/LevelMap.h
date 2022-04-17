#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "StaticObject.h"


class LevelMap
{
public:
	LevelMap();
	~LevelMap();
	
	size_t getnumOfLevel() const;
	std::vector<std::string> operator[](int levelNum) const;

private:
	void readMapsFile();
	std::vector<std::vector<std::string>> m_levelMap;
};

