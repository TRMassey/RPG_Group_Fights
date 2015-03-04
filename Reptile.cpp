#include "Reptile.h"
#include "Creature.h"
#include<iostream>
#include<string>

/****************************************************************************
 * void Reptile::getType()
 *
 * Purpose: Returns name of creature
 * Entry: None
 * Exit: None
 * ***********************************************************************/

std::string Reptile::getType(){
	return "Reptile Men";}



/****************************************************************************
 * void Reptile::inAttack()
 *
 * Purpose: Returns unique attack type
 * Entry: None
 * Exit: None
 * ***********************************************************************/

void Reptile::indAttack(){
	std::cout << "The Reptile Men slowly lumber forward, and swing a giant sword";}



/****************************************************************************
 * int Reptile::getRoll()
 *
 * Purpose: Returns number of defensive rolls
 * Entry: None
 * Exit: 3 rolls
 * ***********************************************************************/

int Reptile::getRoll(){
	return 3;}



/****************************************************************************
 * void Reptile::fillSP()
 *
 * Purpose: Returns Reptile's SP to 18. Overrides base class.
 * Entry: None
 * Exit: None
 * ***********************************************************************/

void Reptile::fillSP(){
	setSP(18);}
