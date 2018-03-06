/***********************************************************************************************
** Name: Final (Game)
** Author: Jeremy Einhorn
** Date: August 15th, 2017
** Description: This is the main file.  It keeps the Game running until a Win, Lose, or user
quits mid-game.
************************************************************************************************/

#include"Game.hpp"
#include"Earth.hpp"
#include"menu.hpp"
#include<iostream>
#include<ctime>
using std::cout;
using std::endl;

int main()
{
	//brings up main menu
	//integer to hold main menu choice
	int menuChoice = menu();

	//while the user chooses not to quit on the main menu
	while (menuChoice != 2)
	{
		//creation of Game object as well as RickAndMorty pointer
		//that points to new RickAndMorty object.  this pointer
		//is passed to the setRickAndMorty() function in Game
		//srand for the random dice in Dimension7031's interaction
		Game game;
		RickAndMorty* ram = new RickAndMorty(game.createGrid());
		game.setRickAndMorty(ram);
		srand(time(NULL));

		cout << "Welcome to Rick And Morty's Great Adventure... Thing.  You get to be the 2 greatest herores in all the land..."
			" RICK AND MORTY!" << endl;
		cout << endl;
		cout << "The Universe is in serious danger and the only people who can save us you ask?  You guessed it, Rick and Morty." << endl;
		cout << "You must find and retreive Rick's Portal Gun hidden in one of the dimensions to portal everyone to safety!" << endl;
		cout << "But, you must first find the Dice also hidden in one of the dimensions to have access to the Portal Gun." << endl;
		cout << "You have an item bag that can only carry up to 2 things at a time, so be wary of this!" << endl;
		cout << "You can only take 8 steps to complete the game, if you run out of steps before getting the Portal Gun... good job, you "
			"killed us all." << endl;
		cout << endl;
		cout << "You start off on Earth. Plain old boring Earth.  Although, it is worth mentioning that Rick and Morty's family lives here." << endl;
		cout << "Maybe you should collect them to save them from certain death... maybe?  It's not necessary." << endl;

		//interger to hold users in game choice
		int choice;

		//while the user chooses not to quit mid-game and there is no game Win
		//and there is no game Lose
		do
		{

			cout << "		Game Options" << endl;
			cout << "1: Move To A New Dimension" << endl;
			cout << "2: Check How Many Steps You Have Taken" << endl;
			cout << "3: View the Items in your Item Bag" << endl;
			cout << "4: Interact With The Dimension to Add an Item" << endl;
			cout << "5: Remove an Item from your Item Bag" << endl;
			cout << "6: Quit to Main Menu" << endl;
			cout << "Please enter the corresponding integer of your choice." << endl;
			choice = getUnsignedInt();

			//while the user enter lower than 1 or higher than 6, they must re-enter
			while (choice < 1 || choice > 6)
			{
				cout << "Error.  Please enter 1 through 6 for you choice." << endl;
				choice = getUnsignedInt();
			}

			//users choice is used in the in game menu
			game.menuChoice(choice);

		} while (choice != 6 && !game.checkForWin() && !game.checkForLose());

		//free the RickAndMorty pointer 
		delete ram;

		//main menu pops uo again
		menuChoice = menu();
	}

	//if the user choosee to quit the program
	return 0;
}