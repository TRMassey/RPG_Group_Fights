#include "BlueM.h"
#include "Creature.h"
#include<iostream>
#include<string>


/****************************************************************************
 * void BlueM::getType()
 *
 * Purpose: Returns name of creature
 * Entry: None
 * Exit: None
 * ***********************************************************************/

std::string BlueM::getType(){
	return "Blue Men";}



/****************************************************************************
 * void BlueM::indAttack()
 *
 * Purpose: Returns unique attack
 * Entry: None
 * Exit: None
 * ***********************************************************************/

void BlueM::indAttack(){
	std::cout << "Blue men swarm over their opponent. Itty bitty biting creatures...";}



/****************************************************************************
 * int BlueM::attack()
 *
 * Purpose: Overrides attack function for unique attack
 * Entry: None
 * Exit: Returns attack value
 * ***********************************************************************/

int BlueM::attack(){		
	total = 0;
	blueDice.setSides(10);
	for(int i = 0; i < getRoll(); i++){
		indAttack();
		std::cout << "\nRolls: ";
		roll = blueDice.rollDice();
		std::cout << roll << std::endl;
		total = total + roll;}
	setAttVal(total);
	return total;}



/****************************************************************************
 * int BlueM::getDefRoll()
 *
 * Purpose: Returns amount of times Blue Men can roll defensively
 * Entry: None
 * Exit: Returns 3 rolls
 * ***********************************************************************/

int BlueM::getDefRoll(){
	return 3;}




