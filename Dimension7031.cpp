/***********************************************************************************************
** Name: Final (Game)
** Author: Jeremy Einhorn
** Date: August 15th, 2017
** Description: This is the implementation file for the class Dimension7031.  It's getInfo holds
unique info from the other Spaces.  It also has a different interaction.
************************************************************************************************/

#include"Dimension7031.hpp"
#include<iostream>
#include<algorithm>
using std::cout;
using std::endl;

//prints the info for Dimension7031
void Dimension7031::getInfo()
{
	cout << "Dimension7031: IT'S HERE!  The Portal Gun, it's here!!! You need this to win, go get it!" << endl;
	cout << "HOWEVER, be warned... you must go find the Dice in one of the other dimensions to win the Portal Gun!" << endl;
}

//the user plays a game of War using 2 random dice, one for the user and one for the computer
//best of 3, if the user wins, the game is over and program quits to main menu
//if comp wins, user has to interact with this space again
string Dimension7031::spaceInteract()
{
	cout << "Rick's Portal Gun... the most advanced piece of technology in the universe.  You must first beat Garmanarnar is a"
		" game of War using the Dice you obtained!" << endl;
	cout << "Whoever has the higher roll wins the round, best of 3!" << endl;

	//3 integer variables to hold the number of player wins, the number
	//of comp wins and the number of ties
	int playerWin = 0;
	int compWin = 0;
	int round = 0;

	//while both players do not reach 2 wins
	while (playerWin != 2 && compWin != 2)
	{
		//increment round by 1 and print it out
		round++;
		cout << "		Round " << round << endl;
		
		//2 random integers for 2 random die
		int die1 = (rand() % 6) + 1;
		int die2 = (rand() % 6) + 1;
		
		cout << "You rolled a " << die1 << endl;
		cout << "Garmanarnar rolled a " << die2 << endl;

		//if the users integer is higher than the comps, player wins round
		if (die1 > die2)
		{
			cout << "YOU WIN THE ROUND!" << endl;
			playerWin++;
		}

		//if the comps integer is higher than the comps, comp wins round
		else if (die2 > die1)
		{
			cout << "Garmanarnar won the round :(" << endl;
			compWin++;
		}

		//if both random integers are the same
		else
			cout << "It's a tie! We go again!" << endl;
	}

	//if players win count is 2, they win the game
	if (playerWin == 2)
	{
		cout << "CONGRATULATIONS!  You got the Portal Gun and have saved the universe!  Thanks for playing!" << endl;
		return "Win";
	}

	//if comps win count is 2, the user loses the game but can
	//interact with Dimension7031 again
	else if (compWin == 2)
	{
		cout << "Oh no!  Garmanarnar beat you, you did not get the Portal Gun!" << endl;
		cout << "Luckily for you, Garmanarnar loves playing War so try playing him again!" << endl;
		return "Lose";
	}
}

//returns the name of the Dimension
string Dimension7031::getName()
{
	return "Dimension7031";
}