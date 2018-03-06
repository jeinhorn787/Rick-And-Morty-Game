/***********************************************************************************************
** Name: Final (Game)
** Author: Jeremy Einhorn
** Date: August 15th, 2017
** Description: This is the header file for the class RickAndMorty.
************************************************************************************************/

#ifndef RICK_AND_MORTY_HPP
#define RICK_AND_MORTY_HPP
#include"Space.hpp"
#include"input_validation.hpp"
#include<vector>
using std::vector;

class RickAndMorty
{
private:
	vector<string> items;
	int steps = 0;
	Space* position;

public:
	RickAndMorty(Space*);
	void addItem(string);
	void removeItem();
	vector<string> getItems();
	void displayItems();
	string interact();
	void move();
	int getSteps();
	void getCurrentInfo();
	string getCurrentName();
};

#endif