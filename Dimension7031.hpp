/***********************************************************************************************
** Name: Final (Game)
** Author: Jeremy Einhorn
** Date: August 15th, 2017
** Description: This is the header file for the class Dimension7031.  It inherits Space.
************************************************************************************************/

#ifndef DIMENSION7031_HPP
#define DIMENSION7031_HPP
#include"Space.hpp"
#include"Earth.hpp"
#include"Dimension1337.hpp"
#include"Dimension2035.hpp"

class Dimension7031 : public Space
{
public:
	void getInfo();
	string spaceInteract();
	string getName();
};

#endif