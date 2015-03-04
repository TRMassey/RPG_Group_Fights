#ifndef DICE_H
#define DICE_H

//#include "Creature.h"
#include<iostream>
#include<ctime>
#include<cstdlib>

class Dice
{
private:
	int sides;

public:
	Dice(){
		sides = 6;
		srand(time(NULL));}

	Dice(int s){
		this ->sides = s;
		srand(time(NULL));}

	int rollDice() const{
		return (rand() % sides) +1;}

	void setSides(int s){
		sides = s;}
};

#endif
