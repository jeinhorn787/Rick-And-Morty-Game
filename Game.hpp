/***********************************************************************************************
** Name: Final (Game)
** Author: Jeremy Einhorn
** Date: August 15th, 2017
** Description: This is the header file for the class Game. It is responsible for running the 
game and creating the game "board".
************************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include"RickAndMorty.hpp"
#include"Space.hpp"
#include"Earth.hpp"
#include"Dimension1337.hpp"
#include"Dimension2035.hpp"
#include"Dimension7031.hpp"

class Game
{
private:
	RickAndMorty* ram;
	Space* e;
	Space* d1;
	Space* d2;
	Space* d7;
	string status;

public:
	~Game();
	void setRickAndMorty(RickAndMorty*);
	Space* createGrid();
	void menuChoice(int);
	bool checkForDice();
	bool checkForWin();
	bool checkForLose();
};
#endif