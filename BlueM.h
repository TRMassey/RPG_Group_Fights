#ifndef BLUEM_H
#define BLUEM_H

#include "Creature.h"
#include "Dice.h"
#include<iostream>
#include<string>


class BlueM : public Creature
{
private:
	Dice blueDice;
	int total;
	int roll;

public:
	BlueM() : Creature(3, 12){};
	
	std::string getType();

	void indAttack();

	int attack();

	int getDefRoll();

};

#endif
