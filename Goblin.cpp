#include "Goblin.h"
#include "Creature.h"
#include<iostream>
#include<string>

/****************************************************************************
 * void Goblin::getType()
 *
 * Purpose: Returns name of creature
 * Entry: None
 * Exit: None
 * ***********************************************************************/

std::string Goblin::getType(){
	return "Goblin";}



/****************************************************************************
 * void Goblin::intAttack()
 *
 * Purpose: Returns unique attack
 * Entry: None
 * Exit: None
 * ***********************************************************************/

void Goblin::indAttack(){
	std::cout << "The hoard lunges forward. Watch those ankles.";}



/****************************************************************************
 * void Goblin::attack()
 *
 * Purpose: Overrides base class attack for special ability use
 * Entry: None
 * Exit: None
 * ***********************************************************************/

int Goblin::attack(bool &achilles){			
	total = 0;

	for(int i = 0; i < getRoll(); i++){
		indAttack();
		std::cout << "\nRolls: ";
		roll = goblinDice.rollDice();
		std::cout << roll << std::endl;
		total = roll + total;}
		
	if(total == 12){
		achilles = true;
		std::cout << "The Goblins have sliced their opponent's achilles tendon! Ouch!" << std::endl;}
	setAttVal(total);
	return total;}


/****************************************************************************
 * void Goblin::fillSP()
 *
 * Purpose: Overrides base class fillSP, sets SP to 8
 * Entry: None
 * Exit: None
 * ***********************************************************************/

void Goblin::fillSP(){
	setSP(8);}
