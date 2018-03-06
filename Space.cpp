/***********************************************************************************************
** Name: Final (Game)
** Author: Jeremy Einhorn
** Date: August 15th, 2017
** Description: This is the implementation file for the Space class.  The only defined functions
are the non-purely virtual functions.
************************************************************************************************/

#include"Space.hpp"

//undefined virtual destructor
Space::~Space()
{
	//left undefined
}

//returns one of the 4 Space pointers in this class depending on
//the integer passed in
Space* Space::getSpace(int dir)
{
	//1 = up
	if (dir == 1)
		return up;

	//2 = down
	else if (dir == 2)
		return down;

	//3 = left
	else if (dir == 3)
		return left;

	//4 = right
	else if (dir == 4)
		return right;
}

//using similar format as getSpace(), the integer passed in
//determines what pointer will be accessed.  that pointer is
//then set to the passed in Space pointer
void Space::setPointers(Space* s, int dir)
{
	//1 = up
	if (dir == 1)
		up = s;

	//2 = down
	else if (dir == 2)
		down = s;

	//3 = left
	else if (dir == 3)
		left = s;

	//4 = right
	else if (dir == 4)
		right = s;
}