#ifndef SHADOW_H
#define SHADOW_H

#include "Creature.h"
//#include "Dice.h"
#include<iostream>
#include<string>


class Shadow : public Creature
{
private:
	int total;
	int roll;
	Dice shadDice;
	Dice special;	

public:
	Shadow() : Creature(0, 12){};	
	
	std::string getType();

	void indAttack();

	int attack();

	int defense();


};

#endif
