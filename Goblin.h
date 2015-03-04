#ifndef GOBLIN_H
#define GOBLIN_H

#include "Creature.h"
#include "Dice.h"
#include<iostream>
#include<string>


class Goblin : public Creature
{
private:
	int total;
	int roll;
	Dice goblinDice;	

public:
	Goblin() : Creature(3, 8){};
	
	std::string getType();

	void indAttack();

	int attack(bool &achilles);

	void fillSP();

};

#endif


