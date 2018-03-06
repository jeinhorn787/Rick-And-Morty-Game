/***********************************************************************************************
** Name: Final (Game)
** Author: Jeremy Einhorn
** Date: August 15th, 2017
** Description: This is the implementation file for Game class.  It allocates 4 Spaces using the
Space pointers in Game.  It handles the choices the user makes for the in-game menu.
************************************************************************************************/

#include"Game.hpp"
#include<iostream>
using std::cout;
using std::endl;

//destructor properly frees the 4 Space pointers in Game
//that hold the allocated Space objects
Game::~Game()
{
	delete e;
	delete d1;
	delete d2;
	delete d7;
}

//sets the RickAndMorty pointer in Game
void Game::setRickAndMorty(RickAndMorty* r)
{
	ram = r;
}

//allocates the 4 different Spaces and sets it's pointers
//returns the Earth pointer because this is always the starting point
//1 = Up, 2 = Down, 3 = Left, 4 = Right
Space* Game::createGrid()
{
	//allocation of the 4 different Spaces
	e = new Earth();
	d1 = new Dimension1337();
	d2 = new Dimension2035();
	d7 = new Dimension7031();
	
	//setting Earth's pointers
	e->setPointers(nullptr, 1);
	e->setPointers(d7, 2);
	e->setPointers(d1, 3);
	e->setPointers(nullptr, 4);

	//setting Dimension1337's pointers
	d1->setPointers(nullptr, 1);
	d1->setPointers(d2, 2);
	d1->setPointers(nullptr, 3);
	d1->setPointers(e, 4);

	//setting Dimension2035's pointers
	d2->setPointers(d1, 1);
	d2->setPointers(nullptr, 2);
	d2->setPointers(nullptr, 3);
	d2->setPointers(d7, 4);

	//setting Dimension7031's pointers
	d7->setPointers(e, 1);
	d7->setPointers(nullptr, 2);
	d7->setPointers(d2, 3);
	d7->setPointers(nullptr, 4);

	//pointer to Earth is returned
	return e;
}

//the integer passed will be used to decide which functions should be called
void Game::menuChoice(int choice)
{
	//if the user chooses to move to a Dimension
	if (choice == 1)
	{
		//if the user has already taken 8 steps, the game is over
		if (ram->getSteps() == 8)
		{
			cout << "Oh no, you're out of steps!  Game Over :(" << endl;
			status = "Lose";
		}

		//if the user has less than 8 steps, they can move
		//and the info for the new Dimension is printed
		else
		{
			ram->move();
			ram->getCurrentInfo();
		}
	}

	//if the user chooses to see how many steps they have taken
	else if (choice == 2)
	{
		cout << "You have made " << ram->getSteps() << " steps." << endl;
		cout << "You have " << (8 - ram->getSteps()) << " steps left." << endl;
	}

	//if the user wants to see the contents of the item vector
	else if (choice == 3)
		ram->displayItems();

	//if the user wants to interact with the current Dimension
	else if (choice == 4)
	{
		//if the user is currently in Dimension7031
		if (ram->getCurrentName() == "Dimension7031")
		{
			//if Dice is not in the item vector, they cannot interact with Dimension7031
			if (!checkForDice())
			{
				cout << "You must first go find the Dice to get the Portal Gun!" << endl;
				return;
			}
		}
		
		//string variable to hold string that is returned from interact()
		string temp = ram->interact();
		//integer to hold users choice if their bag is full
		int choice;

		//if Win is returned from interact(), status is changed to Win
		//and the game ends
		if (temp == "Win")
			status = temp;

		//if Lose is returned from interact(), the function exits
		//and the user can interact again if they wish
		else if (temp == "Lose")
			return;

		//if interact() returns something other than Win or Lose
		else
		{
			//if the item vector is at capacity
			if (ram->getItems().size() == 2)
			{
				cout << "Your item bag is at capacity!  Do you want to remove item from your bag"
					" and add this item?  Enter 1 for yes, 2 for no." << endl;
				//input validation for positive integer
				choice = getUnsignedInt();

				//while the user does not enter 1 or 2, they must re-enter
				while (choice != 1 && choice != 2)
				{
					cout << "Error.  Please enter either 1 or 2 for your choice." << endl;
					choice = getUnsignedInt();
				}

				//if the user chooses to remove an item then add the returned item
				if (choice == 1)
				{
					ram->removeItem();
					ram->addItem(temp);
				}

				//if the user chooses not to remove an item
				else
					return;
			}

			//if the item vector is not at capacity
			else
				ram->addItem(temp);
		}

	}

	//if user chooses to remove an item from the item vector
	else if (choice == 5)
		ram->removeItem();

	//if the user chooses to quit the game
	else if (choice == 6)
		return;
}

//checks to see if the string Dice is in the item vector
bool Game::checkForDice()
{
	//temporary vector to hold item vector
	vector<string> temp = ram->getItems();

	//steps through all items in vector
	for (int item = 0; item < temp.size(); item++)
	{
		//if the Dice is found in the vector
		if (temp[item] == "Dice")
			return true;
	}

	//if Dice is not found in the vector
	return false;
}

//checks for game Win
bool Game::checkForWin()
{
	//if status is Win
	if (status == "Win")
		return true;
	
	else
		return false;
}

//checks for game Lose
bool Game::checkForLose()
{
	//if status is Lose
	if (status == "Lose")
		return true;

	else
		return false;
}