/***********************************************************************************************
** Name: Final (Game)
** Author: Jeremy Einhorn
** Date: August 15th, 2017
** Description: This is the header file for the class Space. It is abstract and has purely
virtual functions that will be overwritten in the derived classes.
************************************************************************************************/

#ifndef	SPACE_HPP
#define SPACE_HPP
#include"input_validation.hpp"
#include<string>
using std::string;

class Space
{
protected:
	Space* up;
	Space* down;
	Space* left;
	Space* right;

public:
	virtual ~Space();
	virtual void getInfo() = 0;
	virtual string spaceInteract() = 0;
	virtual string getName() = 0;
	Space* getSpace(int);
	void setPointers(Space*, int);
};

#endif