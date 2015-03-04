#ifndef CREATURE_H
#define CREATURE_H

#include "Dice.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>


/***************************************************************
 * Abstract Creature Class
 * ************************************************************/

class Creature
{
private:
	int armor;
	int strPnt;
	std::string type;
	std::string name;
	int dmg;
	int roll;
	int defRoll;
	int attRoll;
	int total;
	int attVal;
	int defVal;
	int wins;
	int team;
	Dice general;

public:
	Creature(int a, int sP);

	virtual int attack();

	virtual int attack(bool &achilles);

	virtual int defense();
	
	virtual void fillSP();
	
	virtual std::string getType() = 0;

	virtual void indAttack() = 0;

	int getDmg();

	void setDmg(int hurt);

	virtual	int getRoll();

	virtual int getDefRoll();

	void setRoll(int num);

	void setAttVal(int val);

	int getAttVal();

	void setDefVal(int val);

	int getDefVal();

	void setSP();
	
	void setSP(int num);

	int getSP();
	
	void setWins(int tally);

	int getWins();

	void setTeam(int num);

	int getTeam();

	void setName(std::string input);
	
	std::string getName();

	~Creature();
};

#endif

