/***********************************************************************************************
** Name: Final (Game)
** Author: Jeremy Einhorn
** Date: August 15th, 2017
** Description: This is the header file for the class Dimension1337.  It inherits Space.
************************************************************************************************/

#ifndef DIMENSION1337_HPP
#define DIMENSION1337_HPP
#include"Space.hpp"
#include"Dimension2035.hpp"
#include"Earth.hpp"

class Dimension1337 : public Space
{
public:
	void getInfo();
	string spaceInteract();
	string getName();

};

#endif