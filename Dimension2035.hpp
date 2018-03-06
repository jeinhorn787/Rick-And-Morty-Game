/***********************************************************************************************
** Name: Final (Game)
** Author: Jeremy Einhorn
** Date: August 15th, 2017
** Description: This is the header file for the class Dimension2035.  It inherits Space.
************************************************************************************************/

#ifndef	DIMENSION2035_HPP
#define DIMENSION2035_HPP
#include"Space.hpp"
#include"Dimension1337.hpp"
#include"Earth.hpp"
#include"Dimension7031.hpp"

class Dimension2035 : public Space
{
public:
	void getInfo();
	string spaceInteract();
	string getName();
};

#endif