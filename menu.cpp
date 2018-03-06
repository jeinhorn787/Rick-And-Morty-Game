/***********************************************************************************************
** Name: Final (Game)
** Author: Jeremy Einhorn
** Date: August 15th, 2017
** Description: This is the implementation file for my menu function.  The use has 2 options.
************************************************************************************************/

#include"menu.hpp"
#include"input_validation.hpp"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int menu()
{
	//integer to hold users choice
	int choice;

	cout << "1: Play Game" << endl;
	cout << "2: Quit" << endl;

	cout << "Please enter a number, either 1 or 2, for you choice." << endl;
	//input validation for a positive integer
	choice = getUnsignedInt();

	//while the user does not enter 1 or 2, they must re-enter
	while (choice != 1 && choice != 2)
	{
		cout << "Error.  Please enter either only 1 or 2 for your choice." << endl;
		choice = getUnsignedInt();
	}

	
	switch (choice)
	{
	case 1:
		return 1;

	case 2:
		return 2;

	}

	return 2;
}