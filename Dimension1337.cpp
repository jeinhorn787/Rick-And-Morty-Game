/***********************************************************************************************
** Name: Final (Game)
** Author: Jeremy Einhorn
** Date: August 15th, 2017
** Description: This is the implementation file for the class Dimension1337.  It's getInfo holds
unique info from the other Spaces.  It also has a different interaction.
************************************************************************************************/

#include"Dimension1337.hpp"
#include<iostream>
using std::cout;
using std::endl;

//prints the info of Dimension1337
void Dimension1337::getInfo()
{
	cout << "Dimension1337: A vast amount of Plumbus' (Plumbii?) found here for all your Plumbus needs." << endl;
		cout << "Also, this dimension carries the hotest item in existence toady, Real Fake Doors!  Only the highest quality Real Fake Doors"
		" are sold here." << endl;
}

//the user has 2 choices, both of which end up returning a string that will be added
//to the item vector in RickAndMorty
string Dimension1337::spaceInteract()
{
	//integer to hold users choice
	int choice;

	cout << "You may want to go find a Plumbus because we all know just how valuable these are." << endl;
	cout << "Or you can make one of the"
		" best investements of your life by buying a Real Fake Door sold by the infamous Ant's In My Eyes Johnson!" << endl;
	cout << "Enter 1 to go find a Plumbus or 2 to meet up with Ant's in My Eyes Johnson so he can sell you a great Real Fake Door!" << endl;

	//input validation for a positive integer
	choice = getUnsignedInt();

	//while the user did not choose 1 or 2, they must re-enter
	while (choice != 1 && choice != 2)
	{
		cout << "Error.  Please only enter either 1 or 2 for your choice." << endl;
		choice = getUnsignedInt();
	}

	//if the user chooses 1, they got a Plumbus
	if (choice == 1)
	{
		cout << "You don't have to go very far to find a Plumbus as they grow naturally in Dimension1337." << endl;
		cout << "Plumbus will be added to your item bag." << endl;

		return "Plumbus";
	}

	//if the user chooses 2, they got a Real Fake Door
	else
	{
		cout << "Ant's In My Eyes Johnson has a hard time seeing as you can imagine." << endl;
		cout << "While it does take a lot of time"
			" he eventually comes out with the most beautiful Real Fake Door you have ever seen!  Who needs a real door anyway?" << endl;
		cout << "Real Fake Door will be added to your item bag." << endl;

		return "Real Fake Door";
	}
	
}

//returns the name of the Dimension
string Dimension1337::getName()
{
	return "Dimension1337";
}