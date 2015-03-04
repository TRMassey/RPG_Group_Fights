#ifndef REPTILE_H
#define REPTILE_H
#include "Creature.h"
#include "Dice.h"
#include<iostream>
#include<string>

/******************************************************
 * Reptile class
 * **************************************************/
class Reptile : public Creature
{

public:
	Reptile() : Creature(7, 18){};

	std::string getType();

	void indAttack();

	int getRoll();

	void fillSP();
};


#endif
