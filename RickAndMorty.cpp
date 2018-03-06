/***********************************************************************************************
** Name: Final (Game)
** Author: Jeremy Einhorn
** Date: August 15th, 2017
** Description: This is the implementation file for the class RickAndMorty. It is responsible
for all of the users actions.
************************************************************************************************/

#include"RickAndMorty.hpp"
#include"Dimension7031.hpp"
#include<iostream>
using std::cout;
using std::endl;

//sets the Space pointer in this class
RickAndMorty::RickAndMorty(Space* s)
{
	position = s;
}

//adds passed string to item vector
void RickAndMorty::addItem(string i)
{
	//steps through items vector
	for (int index = 0; index < items.size(); index++)
	{
		//if the passed string matches a string in the item vector
		//the user is told the item is already in the vector
		if (i == items[index])
		{
			cout << "This item is already in your bag!" << endl;
			return;
		}
	}
	
	//if the passed string is not in the item vector already
	items.push_back(i);
}

//removes the last item from the item vector
void RickAndMorty::removeItem()
{
	//if there are 0 elements in the item vector, the user is told
	//that it is alreay empty
	if (items.size() == 0)
	{
		cout << "Item bag is empty." << endl;
		return;
	}
	
	cout << "Removing last item in bag." << endl;
	
	//last element in vector is removed
	items.pop_back();
}

//returns the items vector
vector<string> RickAndMorty::getItems()
{
	return items;
}

//prints the items in the item vector
void RickAndMorty::displayItems()
{
	//if the items vector has 0 elements in it
	if (items.size() == 0)
	{
		cout << "Item bag is empty." << endl;
		return;
	}

	//steps through the items vector and prints its elements
	for (int item = 0; item < items.size(); item++)
		cout << items[item] << "  ";

	cout << endl;
}

//access' the Spaces unique interaction and returns the string it returns
string RickAndMorty::interact()
{
	return position->spaceInteract();
}

//moves the user to a different Dimension using the set pointers
void RickAndMorty::move()
{
	//for every move the user makes, they get 1 step added to the counter
	steps += 1;

	//integer to hold user choice
	int choice;

	cout << "Which direction would you like to move?  Please enter the corresponding"
		" integer of the direction you want to move in." << endl;
	cout << "1: Up" << endl;
	cout << "2: Down" << endl;
	cout << "3: Left" << endl;
	cout << "4: Right" << endl;
	//input validation for positive integer
	choice = getUnsignedInt();

	//while the user enter lower than 1 or higher than 4, they must re-enter
	while (choice < 1 || choice > 4)
	{
		cout << "Error. Please enter only 1 to 4 for your choice." << endl;
		choice = getUnsignedInt();
	}

	//while the user chooses a pointer that points to nothing, they must re-enter
	while (position->getSpace(choice) == nullptr)
	{
		cout << "Believe it or not, there is no dimension in that direction!"
			"  Please choose a different direction." << endl;

		choice = getUnsignedInt();

		//checks for out of range choice again
		while (choice < 1 || choice > 4)
		{
			cout << "Error. Please enter only 1 to 4 for your choice." << endl;
			choice = getUnsignedInt();
		}
	}

	//the Space pointer in RickAndMorty now points to the Dimension that the user
	//moved to
	position = position->getSpace(choice);
}

//returns the number of steps
int RickAndMorty::getSteps()
{
	return steps;
}

//returns the info of the current Dimension
void RickAndMorty::getCurrentInfo()
{
	position->getInfo();
}

//returns the name of the current Dimension
string RickAndMorty::getCurrentName()
{
	return position->getName();
}