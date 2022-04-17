#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <sstream>

/* Controller Consts */
const auto WindowColor =  sf::Color(249, 231, 159);
const unsigned int WindowHeight = 1100;
const unsigned int WindowWidth = 1550;
const auto endScreen = sf::Vector2i(WindowWidth, WindowHeight);
const auto backgroundPos = sf::Vector2f(WindowWidth, WindowHeight);
const auto sizeScreen = sf::Vector2u(WindowWidth, WindowHeight);
const auto centerScreen = sf::Vector2i(WindowWidth/2, WindowHeight/2);
const auto backgroundFactor = sf::Vector2f(1.f, 1.f);
const auto startWindow = sf::Vector2f(0.f, 0.f);
const float musicVolume = 20;
const float mute = 0;

enum State_t
{
	menuState,
	gameState,
	ruleState,
};

/* Level Consts */
const auto startBoard = sf::Vector2f(400.f, 200.f);
const auto telFirstPos = sf::Vector2f(-1.f, -1.f);
const int numOfCharacters = 4;
const float ObjectSpace = 68;
const auto ObjectFactor = sf::Vector2f((float)0.5, (float)0.5);
const float TexturSize = 64;
const double verySmallNum = 0.008;

/* Textures  */
enum Type_t
{
	king, mage, warrior, thief, wall, gate, fire, orc, key, teleporter, throne, dwarf, gift, buttonGame, buttonRules, buttonExit, menu, backgroundMenu, backgroundGame, gameRules, levelUpImage, gameOverImage, gameWinImage
};
const int numOfTextures = 23;
const std::string TextureFiles[numOfTextures] = { "king.png", "mage.png", "warrior.png", "thief.png", "wall.png",
												"gate.png", "fire.png", "orc.png", "key.png", "teleporter.png",
												"throne.png", "dwarf.png",  "gift.png", "ButtonGame.png", "ButtonRules.jpeg",
												"ButtonExit.png", "menu.png", "backgroundMenu.jpg","backgroundGame.jpg", "gameRules.jpeg" ,
												"levelUp.png" , "gameOver.png" , "gameWin.png" };

/* Fonts */
enum Type_f
{
	algertxt,
};
const int numOfFonts = 1;
const std::string FontFiles[numOfFonts] = { "ALGER.TTF" };


/* Sounds  */
const int mediumVol = 56;
const int volStep = 14;
const int volMax = 100;
const int volMin = 0;
enum Type_s
{
	mainTrack,
	collisionSound,
	deleteSound,
	giftShowSound,
	giftDeleteSound,
	keyShowSound,
	teleporterSound,
	levelUpSound,
	gameOverSound,
	gameWinSound,
};
const int numOfSounds = 10;
const std::string SoundFiles[numOfSounds] = { "mainTrack.ogg", "collisionSound.ogg", "DeleteSound.ogg",
											  "giftShowSound.ogg", "giftDeleteSound.ogg","keyShowSound.ogg",
											  "teleporterSound.ogg", "levelUpSound.ogg" , "gameOverSound.ogg" , "gameWinSound.ogg" };

enum objectSign
{
	spaceNum = 32,
	kingNum = 75,
	mageNum = 77,
	warriorNum = 87,
	thiefNum = 84,
	wallNum = 61,
	gateNum = 35,
	fireNum = 42,
	orcNum = 33,
	keyNum = 70,
	teleporterNum = 88,
	throneNum = 64,
	dwarfNum = 94,
	giftDwarfNum = 555,
	giftTimeNum = 556,
};

/* Board Consts */
const double boardHeight = 700.f;
const auto BoardTxt = "Board.txt";

/* MovingObject Consts */
const float CharacterSpeed = 200.f;
const float dwarfSpeed = 90.f;

/* Menu consts */
const int numOfButton = 3;
const int firstButton = 12;
const auto spaceButtons = 150.f;
const auto startButtons = 435.f;
const auto menuFactor = sf::Vector2f(1.f, 1.f);
const auto menuImagePosition = (sf::Vector2f)centerScreen;
const auto menuSize = sf::Vector2u(700, 950);
const auto buttonSize = sf::Vector2u(400, 150);

enum buttonsType
{
	menuButton,
	gameButton,
	rulesButton,
	exitButton,
};

/* Information consts */
const auto infoPlayer = sf::Vector2f(170.f, 400.f);
const auto infoKey = sf::Vector2f(30.f, 470.f);
const auto infoTimer = sf::Vector2f(30.f, 270.f);
const auto infoLevel = sf::Vector2f(30.f, 200.f);
const auto infoGift = sf::Vector2f(30.f, 700.f);
const auto charSize = 30;
const auto startRandTimer = 60;
const auto endRandTimer = 80;
const auto infoFactor = sf::Vector2f((float)1.5,(float)1.5);

/* Rules consts*/
const auto characterFactor = sf::Vector2f((float)1.2,(float)1.2);
const float rulesCharacterSpace = 200;
