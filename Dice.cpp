#include "Dice.h"
#include "Creature.h"
#include<iostream>
#include<ctime>
#include<cstdlib>


Dice::Dice{
	sides = 6;
	srand(time(NULL));}

Dice::Dice(int s){
	this ->sides = s;
	srand(time(NULL));}

int Dice::rollDice() const{
	return (rand() % sides) +1;}

void Dice::setSides(int s){
	sides = s;}
