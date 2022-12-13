1. Save The King - project

=================================================
2.Written by: 
	Damian Tissembaum, 
	Ori Vered

*********** General program description***********

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


 **********input file format*********

The input format of the file is one file where every level is preceded by the num of rows and
columns that the level will have. In order to add another level, you just have to add the number
of rows and columns that the level will have and put the map itself.

    

