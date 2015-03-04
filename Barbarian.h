#ifndef BARBARIAN_H
#define BARBARIAN_H
#include "Creature.h"
#include "Dice.h"
#include<iostream>
#include<string>

/******************************************************
 * Barbarian class
 * **************************************************/
class Barbarian : public Creature
{
private:
	int barbRoll;
public:
	Barbarian() : Creature(0, 12){};

	std::string getType();
	void indAttack();
	
	void setBarbRoll();

	int getDefRoll();

};


#endif
