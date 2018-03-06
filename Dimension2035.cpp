/***********************************************************************************************
** Name: Final (Game)
** Author: Jeremy Einhorn
** Date: August 15th, 2017
** Description: This is the implementation file for the class Dimension2035.  It's getInfo holds
unique info from the other Spaces.  It also has a different interaction.
************************************************************************************************/

#include"Dimension2035.hpp"
#include<iostream>
using std::cout;
using std::endl;

//prints info of Dimension2035
void Dimension2035::getInfo()
{
	cout << "Dimension2035:  Home of Bird Person, land of the Schleem, Bobby Moinahan's"
		" favorite vacation spot." << endl;
}

//the user has 2 choices, both of which return a string to be added
//to the items vector
string Dimension2035::spaceInteract()
{
	//integer to hold users choice
	int choice;
	
	cout << "You can either give Bird Person a visit or you can check out the mysterious yet beautiful land of the Schleem." << endl;
	cout << "Enter 1 to visit Bird Person or 2 to head to the land of the Schleem." << endl;
	//input validation for a positive integer
	choice = getUnsignedInt();

	//while the user does not enter 1 or 2, they must re-enter
	while (choice != 1 && choice != 2)
	{
		cout << "Error.  Please enter only 1 or 2 for you choice." << endl;
		choice = getUnsignedInt();
	}

	//if the user chooses 1, they get Bird Person
	if (choice == 1)
	{
		cout << "You visit Bird Person, have a wonderful chat about life, and Bird Person actually offers his"
			" companionship for your journey, a very generous offer!" << endl;
		cout << "Bird Person will be added to your item bag." << endl;
		return "Bird Person";
	}

	//if the user chooses 2, they get Dice
	else
	{
		cout << "The land of the Schleem is an odd place to see, there is this strange gooey liquid spread all over the ground." << endl;
		cout << "Nonetheless, it is an amazing site, one of Morty's favorite places in the universe.  And what is this?!?! You have come across"
			" the Dice necessary to win the game!" << endl;
		cout << "Dice will be added to your item bag." << endl;
		return "Dice";
	}

}

//returns the name of the Dimension
string Dimension2035::getName()
{
	return "Dimension2035";
}