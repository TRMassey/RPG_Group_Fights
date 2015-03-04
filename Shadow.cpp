#include "Shadow.h"
#include "Creature.h"
#include<iostream>
#include<string>

/****************************************************************************
 * void Shadow::getType()
 *
 * Purpose: Returns name of creature
 * Entry: None
 * Exit: None
 * ***********************************************************************/

std::string Shadow::getType(){
	return "Shadow";}




/****************************************************************************
 * void Shadow::indAttack()
 *
 * Purpose: Returns unique attack type
 * Entry: None
 * Exit: None
 * ***********************************************************************/

void Shadow::indAttack(){
	std::cout << "The Shadow swirls toward their oppoenent, stabbing with a small blade";}



/****************************************************************************
 * int Shadow::attack()
 *
 * Purpose: Overrides base attack fuction
 * Entry: None
 * Exit: Returns attack value
 * ***********************************************************************/

int Shadow::attack(){
	total = 0;
		
	shadDice.setSides(10);
	for(int i = 0; i < getRoll(); i++){
		indAttack();
		roll = shadDice.rollDice();
		std::cout << "\nRolls: " << roll << std::endl;
		total = total + roll;}
	setAttVal(total);
	return total;}




/****************************************************************************
 * int Shadow::defense()
 *
 * Purpose: Overrides base defense for use of special ability
 * Entry: None
 * Exit: returns defense roll, maxing out beyond dice amount 50% of time
 * ***********************************************************************/

int Shadow::defense(){
	total = 0;
		
	special.setSides(50);
	if(special.rollDice() % 2 == 0){
		std::cout << "Shadow uses special ability! No damage!" << std::endl;
		setDefVal(100);
		return 100;}
	else{
		for(int i = 0; i < 1; i++){
			std::cout << "Shadow defends! Rolls: ";
			roll= shadDice.rollDice();
			std::cout << roll << std::endl;
			total = total + roll;}
		setDefVal(total);
		return total;}}




