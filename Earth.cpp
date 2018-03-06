/***********************************************************************************************
** Name: Final (Game)
** Author: Jeremy Einhorn
** Date: August 15th, 2017
** Description: This is the implementation file for the class Earth.  It's getInfo holds
unique info from the other Spaces.  It also has a different interaction.
************************************************************************************************/

#include"Earth.hpp"
#include<iostream>
using std::cout;
using std::endl;


//prints the info for Earth
void Earth::getInfo()
{
	cout << "Earth:  Plain old boring Earth.  Although, it is worth mentioning that Rick and Morty's family lives here." << endl;
	cout << "Maybe you should collect them to save them from certain death... maybe?  It's not necessary." << endl;
}

//the user has 2 choices, both of which return a string that
//will be added to the item vector
string Earth::spaceInteract()
{
	//integer to hold user choice
	int choice;

	cout << "Earth is in extreme danger, there is about a 97.99, repeating of course, percent chance it blows up." << endl; 
	cout << "Aww man but I guess"
		" you should conisder taking Rick and Morty's family along to save them... or maybe you don't have to.  The choice is yours!" << endl;
	cout << "Enter 1 to find Rick and Morty's family, 2 to let them deal with it on their own." << endl;
	//input validation for a positive integer
	choice = getUnsignedInt();

	//while the user does not enter 1 or 2, they must re-enter
	while (choice != 1 && choice != 2)
	{
		cout << "Error.  Please enter either 1 or 2 for your choice." << endl;
		choice = getUnsignedInt();
	}

	//if the user chooses 1, they get Family
	if (choice == 1)
	{
		cout << "You find Rick and Morty's family just sitting on the couch together like nothing is going on... typical.  Hope"
			" they don't slow you down!" << endl;
		cout << "Family will be added to your item bag." << endl;
		return "Family";
	}

	//if the user chooses 2, they still get Family
	else
	{
		cout << "Honestly, it was probably the right choice, you guys are better off without- wait a minute...." << endl;
		cout << "What is that........... no........ NO!!!" << endl;
		cout << "THE FAMILY SECRETLY JUMPED IN YOUR SPACE VEHICLE!! Ugh, you're stuck with them... Sorry :(" << endl;
		cout << "Family will be added to your item bag." << endl;
		return "Family";
	}
}

//returns the name of the Dimension
string Earth::getName()
{
	return "Earth";
}