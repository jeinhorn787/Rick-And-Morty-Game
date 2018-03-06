/***********************************************************************************************
** Name: Final (Game)
** Author: Jeremy Einhorn
** Date: August 15th, 2017
** Description: This is the header file for the class Earth.  It inherits Space.
************************************************************************************************/

#ifndef EARTH_HPP
#define EARTH_HPP
#include"Space.hpp"
#include"Dimension1337.hpp"
#include"Dimension2035.hpp"
#include"Dimension7031.hpp"

class Earth : public Space
{
public:
	void getInfo();
	string spaceInteract();
	string getName();
};

#endif