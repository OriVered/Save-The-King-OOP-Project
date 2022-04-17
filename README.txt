1. Save The King - project

=================================================
2.Written by: 
	Damian Tissembaum, id= 340888122, login= damianti
	Ori Vered,	   id = 315545400, login = orive

3.*********** General program description***********

This program is the game "Save the king".

The program will read the all the levels from one file,
and will create an interface using SFML graphics and sound

When the user runs the program he will meet the Menu: there he will choose between
three options: Play - to play the game; Rules - to see the rules of the game; 
Exit - to exit the game.

The goal of the game is to put the king in his throne in a period of time (shown in the window of the game).
In order to do that, the user will move the player with the arrows and will change the player that is playing by pressing 'p'

There are four players that the user can move:
- King: His power is to win the game by placing it in the throne tile.
- Mage: His power is to turn off the fire.
- Thief: His power is to take a key and open a gate.
- Warrior: His power is to kill the orc.

Every key is left by every orc killed.
Some important tiles:
- Fire: Only the Mage can turns it off (erase it)
- Orc: They hide a key that can open a gate. Only the warrior can kill it
- Gate: Only a thief with a key can open a gate (erase it)
- Dwarf: They move randomly by the board, nothing can stop them. If the player is not 
        moving and a dwarf passes by his position, that player can not be moved until the dwarf leaves that position

- Teleporters: they will transport the player that is playing to another teleporter of the game. If the place that the player will be
taken is already taken by another object, the player will go back to the last position that he was before.
- Gifts: They will appear randomly on the board. There are two kinds of gifts:
        * Orc gifts: each gift kills a dwarf
        * Time gifts: each gift gives/ takes a randomly num of seconds from 0 to 5

If the user press escape, the program goes back to the menu and the user can start the game from the first levels
If there is no more time, the user program goes back to the menu and the user can start the game from the level he could not end
If the user wins the game, the program goes back to the menu and the user can start the game from the first levels

While playing, the user can see wich level he is playing in, if the thief has a key,
how much time is left to win the level and a picture of the player he is playing with on the moment


4.*********** Design ***********
The design program is:

The hole program will be controlled and runned by an object of the class Controller. it controlls 
the game by State vector, each Controller inheritance from class State:
Menu, Game - Level Controller, Rules;

In the Controller only one object of this type State, and inside it everything occurs.
it Mangae the States by vector push and pull to the vector by selection:

There are 3 States:
    -MenuState: it will show the features produced by the class Menu (that is a member of Controller and only one object of it is created), 
                and the events produced by the user in this screen will be handled by this class too
    
    -GameState: When the Level Controller create also the only object of the class levelMap,
                is created. This object will read from the file "Board.txt" the map (in chars) of 
                every level and will upload it to the member of the class m_levelMap that is a vector of Levels

                Level Controller:
                it will show the features produced by the class LevelController. Only one object 
                of this class will be created. When there is a change of level(at win Level), 
                The correspondent level will be load by operator[] from member LevelMap by member (int)m_levelNum.

    -rulesState: a simple screen that shows an image of the rules of the game and the image
                 of each character of the game. By a click or by pressing a key, the controller
                returns the screen to menuScreen.
    -exit: the program is closed

When a level is started, the object of the class Level reads a board and creates all the characters
of the game. Each character is an object of a different class. There are base classes that 
are virtual: gameObject is the base class. staticObject and movingObject are its inheritance. Player
is the class that every character that the user can move and it inherits from movingObject.


    -The moving characters are hold in a vector of unique_ptr of Moving object (the base class that 
    every moving character including dwarfs inherit from it) called m_movingObject
    -The teleporters are hold in a vector of pair of unique_ptr of StaticObject (the base class that
    all the static characters of the game inherit from it) called m_teleporters
    -The rest of the character that don't move are hold in a vector of unique_ptr of StaticObject called m_tiles
    -The information is hold in a class called Information. It also has only one object and for each
    level, this object is restarted




5.  **********input file format*********
    
The input format of the file is one file where every level is preceded by the num of rows and
columns that the level will have. In order to add another level, you just have to add the number
of rows and columns that the level will have and put the map itself.

    


6.***********  Files ***********


main.cpp - the main program Controller class is run

macros.h - has all the global and consts values that all the files use 

Controller.cpp - the file that creates the class that controls the game and is in charge of all the other files
Controller.h - Signature of Controller class and functions related to it

State.h - the file that has base class of states game(Menu, Levelcontroller, Rules) 
State.cpp -  Signature of State class and functions related to it

Background.h - the file that has the background pictures object it inheritance from Image
Background.cpp -  Signature of Background class and functions related to it

Menu.cpp - the file that has the buttons that the user can press at the beggining
Menu.h - Signature of Menu class and functions related to it

LevelController.cpp - The file that controls everything when the user is playing a level
LevelController.h - Signature of LevelController class and functions related to it

Rules.h - The file that show the rules of the game
Rules.cpp - Signature of Rules class and functions related to it

LevelMap.cpp - The file that has reads the file and represents the graphics of the level itself
LevelMap.h - Signature of LevelMap class and functions related to it

Information.cpp - The file that has the information of the level including timer,
                player playing, actual level and if the thief has a key
Information.h - Signature of Information class and functions related to it

GameObject.cpp - The file that has the functions definition of the base class GameObject. This class
                only has a member sf::Sprite so the functions of the class are related to the space of the Sprite
GameObject.h - Signature of GameObject class and functions related to it

MovingObject.cpp - The file has the functions definition of the class MovingObject (inherits from GameObject). This is an 
                intermediate class that has the functions related to the direction of the moving of the character
MovingObject.h - Signature of MovingObject class and functions related to it

StaticObject.cpp - The file has the functions definition of the class StaticObject (inherits from GameObject). This is an 
                intermediate class that has a bool member m_delete and its set/get functions
StaticObject.h - Signature of StaticObject class and functions related to it

Player.cpp - The file that has the function definition of the class Player (inherits from movingObject). This is also an 
            intermediate class that only has the move different from the othe movingObject
Player.h - Signature of Player class and functions related to it

King.cpp - The file that has the functions definition of the class King (inherits from Player). It 
        has the functions related to handleColission with other characters of the game and the
        particular function ending the game 
King.h - Signature of King class and functions related to it

Mage.cpp - The file that has the functions definition of the class Mage (inherits from Player). It 
        has the functions related to handleColission with other characters of the game 
Mage.h - Signature of Mage class and functions related to it

Thief.cpp - The file that has the functions definition of the class Thief (inherits from Player). It 
        has the functions related to handleColission with other characters of the game and the 
        particular function of getting a key 
Thief.h - Signature of Thief class and functions related to it

Warrior.cpp - The file that has the functions definition of the class Warrior (inherits from Player). It 
        has the functions related to handleColission with other characters of the game
Warrior.h - Signature of Warrior class and functions related to it

Dwarf.cpp - The file that has the functions definition of the class Dwarf (inherits from MovingObject). It
            has the functions related to handleColission and move (they move randomly)
Dwarf.h - Signature of Dwarf class and functions related to it

Gift.cpp - The file that has the functions definition (handleColission functions) of the class Gift 
        (inherits from StaticObject) and is an intermediate class
Gift.h - Signature of Gift class and functions related to it

GiftDwarf.cpp - The file that has the functions definition of the class GiftDwarf (inherits from Gift)
GiftDwarf.h - Signature of GiftDwarf class and functions related to it

GiftTime.cpp - The file that has the functions definition of the class GiftTime (inherits from Gift)
GiftTime.h - Signature of GiftTime class and functions related to it

Fire.cpp - The file that has the functions definition of the class Fire (inherits from StaticObject)
                All of these function are the handleColission with the different movingObject
Fire.h- Signature of Fire class and functions related to it

Gate.cpp - The file that has the functions definition of the class Gate (inherits from StaticObject)
                All of these function are the handleColission with the different movingObject
Gate.h- Signature of Gate class and functions related to it

Key.cpp - The file that has the functions definition of the class Key (inherits from StaticObject)
                All of these function are the handleColission with the different movingObject
Key.h- Signature of Key class and functions related to it

Orc.cpp - The file that has the functions definition of the class Orc (inherits from StaticObject)
                All of these function are the handleColission with the different movingObject
Orc.h- Signature of Orc class and functions related to it

Teleporter.cpp - The file that has the functions definition of the class Teleporter (inherits from StaticObject)
                All of these function are the handleColission with the different movingObject
Teleporter.h- Signature of Teleporter class and functions related to it

Throne.cpp - The file that has the functions definition of the class Throne (inherits from StaticObject)
                All of these function are the handleColission with the different movingObject
Throne.h- Signature of Throne class and functions related to it

Wall.cpp - The file that has the functions definition of the class Wall (inherits from StaticObject)
                All of these function are the handleColission with the different movingObject
Wall.h- Signature of Wall class and functions related to it

ResourceManager.cpp - singatue fo ResourcesManager and the functions of the singelton
ResourceManager.h - The file that has the functions definition of the singleton resourceManager


7. **********data structures***********

All the levels boards are structured in a vector of vector of strings

In LevelController:
        - All the moving objects are structured in a vector of unique_ptr of MovingObject
        - All the Teleporters are structured in a vector of pair of unique_ptr of StaticObject
        --All the other static objects are structured in a vector of unique_ptr of StaticObject

Using Singleton the program load all the textures/sounds/fonts into a vector of textures/sounds/fonts
so the loading is been done only once in the hole program


8. **********remarkable algorithms***********

Using Singleton (ResourceManager) we have been made the program an easier one to run because the
files are loaded to the program only once

In the Teleporters, we use a vector of pair of unique_ptr, and then we randomize which are the pair
of Teleporters (we do only once the randomize)


   
8. ******bugs******
unkowns bugs.

9.*****comments*****
no comments
