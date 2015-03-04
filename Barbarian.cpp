#include "Barbarian.h"
#include "Creature.h"
#include<iostream>
#include<string>

/****************************************************************************
 * void Barbarian::getType()
 *
 * Purpose: Returns name of creature
 * Entry: None
 * Exit: None
 * ***********************************************************************/

std::string Barbarian::getType(){
	return "Barbarian";}	



/****************************************************************************
 * void Barbarian::indAttack()
 *
 * Purpose: Individual attack action
 * Entry: None
 * Exit: None
 * ***********************************************************************/

void Barbarian::indAttack(){
	std::cout << "Barbarian swings bastard sword";}



/****************************************************************************
 * void Barbarian::setBarbRoll()
 *
 * Purpose: Sets the times Barbarian can roll defensively
 * Entry: None
 * Exit: None
 * ***********************************************************************/

void Barbarian::setBarbRoll(){
	barbRoll = 2;}



/****************************************************************************
 * void Barbarian::getDefRoll()
 *
 * Purpose: Gets the times Barbarian can rll defensively
 * Entry: None
 * Exit: None
 * ***********************************************************************/

int Barbarian::getDefRoll(){
	return 2;}


