#include "Dice.h"
#include "Creature.h"
#include "Reptile.h"
#include "BlueM.h"
#include "Barbarian.h"
#include "Goblin.h"
#include "Shadow.h"

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


/***************************************************************************************************************************************
 * void fight(Creature* one, Creature* two,  std::vector<Creature*> &v, std::vector<Creature*> &v2, std::vector<Creature*> &losers, int &game)
 *
 * Purpose: Performs the fight sequence between classes. Changes who is fighting based off both turns and
 * game number. 
 * Entry: Two contestants, two vectors for lineups, one vector for losers, and game number.
 * Exit: Returns vectors by reference to the main function for match determinations
 * ***************************************************************************************************************************************/

void fight(Creature* one, Creature* two, std::vector<Creature*> &v, std::vector<Creature*> &v2, std::vector<Creature*> &losers, int &game)
{
	int val;
	int turn = 0;
	bool over = false;
	bool flagTwo = false;
	bool flag = false;
	std::string player;

	if(game % 2 == 0){
		do{
			if(turn % 2 == 0){
				player = "one";
				std::cout << "\n";
				std::cout << one->getType() << " " << one->getName() << " is attacking" << std::endl;
				if(one->getType() == "Goblin" && two->getType() != "Goblin")
					one->attack(flag);
				else
					one->attack();
				two->defense();

				// test for a hit and set damage
				if(one->getAttVal() <= two->getDefVal()){
					std::cout << "The attack is a miss!" << std::endl;
					one->setDmg(0);}
				else{
					std::cout << "The attack is successful!" << std::endl;
					if(flagTwo == false)
						val = one->getAttVal() - two->getDefVal();
					else
						val = (one->getAttVal() / 2) - two->getDefVal();
					two->setDmg(val);
					if(two->getDmg() == 0)
						std::cout << "Armor absorbed the attack!" << std::endl;
					else
						std::cout << two->getDmg() << " points of damage!" << std::endl;
					two->setSP();
					if(two->getSP() <= 0 )
						std::cout << "GAME OVER!" << std::endl;
					else
						std::cout << "Only " << two->getSP() << " Strength Points left!" << std::endl;}

				// Check for end game
				if(one->getSP() <= 0 || two->getSP() <= 0){
					over = true;
					one->fillSP();						//restore health to the winner
					std::rotate(v.begin(), v.begin()+1, v.end());		//rotating the winning teams lineup
					losers.push_back(two);					//add the loser to the loser lineup
					std::rotate(v2.begin(), v2.begin()+1, v2.end());	//rotate the losing teams lineup
					v2.pop_back();						//get rid of the one added to the losing pile
					one->setWins(1);}					//track winner
				turn++;}



			else{
				player = "two";
				std::cout << "\n";
				std::cout << two->getType() << " " << two->getName() << " is attacking" << std::endl;
				if(two->getType() == "Goblin" && one->getType() != "Goblin")
					two->attack(flagTwo);
				else
					two->attack();
				one->defense();

				// test for a hit and set damage
				if(two->getAttVal() <= one->getDefVal()){
					std::cout << "The attack is a miss!" << std::endl;
					two->setDmg(0);}
				else{
					std::cout << "The attack is successful!" << std::endl;
					if(flag == false)
						val = two->getAttVal() - one->getDefVal();
					else
						val = (two->getAttVal() / 2) - one->getDefVal();
					one->setDmg(val);
					if(one->getDmg() == 0)
						std::cout << "Armor absorbed the attack!" << std::endl;
					else
						std::cout << one->getDmg() << " points of damage!" << std::endl;
					one->setSP();
					if(one->getSP() <= 0 )
						std::cout << "GAME OVER!" << std::endl;
					else
						std::cout << "Only " << one->getSP() << " Strength Points left!" << std::endl;}

				// Check for end game
				if(one->getSP() <= 0 || two->getSP() <= 0){
					over = true;
					two->fillSP();							//restore health to the winner
					std::rotate(v2.begin(), v2.begin()+1, v2.end());		//rotate the winning teams lineup
					losers.push_back(one);						//add the loser to the loser lineup
					std::rotate(v.begin(), v.begin()+1, v.end());			//rotate the losing teams lineup
					v.pop_back();							//get ride of the loser from the losing team lineup
					two->setWins(1);}						//track the winner
				turn++;}
		}while(over == false);
		game++;}



	else{
		do{
			if(turn % 2 == 0){
				player = "two";
				std::cout << "\n";
				std::cout << two->getType() << " " << two->getName() << " is attacking" << std::endl;
				if(two->getType() == "Goblin" && one->getType() != "Goblin")
					two->attack(flagTwo);
				else
					two->attack();
				one->defense();

				// test for a hit and set damage
				if(two->getAttVal() <= one->getDefVal()){
					std::cout << "The attack is a miss!" << std::endl;
					two->setDmg(0);}
				else{
					std::cout << "The attack is successful!" << std::endl;
					if(flag == false)
						val = two->getAttVal() - one->getDefVal();
					else
						val = (two->getAttVal() / 2) - one->getDefVal();
					one->setDmg(val);
					if(one->getDmg() == 0)
						std::cout << "Armor absorbed the attack!" << std::endl;
					else
						std::cout << one->getDmg() << " points of damage!" << std::endl;
					one->setSP();
					if(one->getSP() <= 0 )
						std::cout << "GAME OVER!" << std::endl;
					else
						std::cout << "Only " << one->getSP() << " Strength Points left!" << std::endl;}

				// Check for end game
				if(one->getSP() <= 0 || two->getSP() <= 0){
					over = true;
					two->fillSP();							//restore health to the winner
					std::rotate(v2.begin(), v2.begin()+1, v2.end());		//rotate the winning teams lineup
					losers.push_back(one);						//add loser to losing lineup
					std::rotate(v.begin(), v.begin()+1, v.end());			//rotate the losing teams lineup
					v.pop_back();							//get rid of the loser from the losing teams lineup
					two->setWins(1);}						//track winner
				turn++;}


			else{
				player = "one";
				std::cout << "\n";
				std::cout << one->getType() << " " << one->getName() << " is attacking" << std::endl;
				if(one->getType() == "Goblin" && two->getType() != "Goblin")
					one->attack(flag);
				else
					one->attack();
				two->defense();

				// test for a hit and set damage
				if(one->getAttVal() <= two->getDefVal()){
					std::cout << "The attack is a miss!" << std::endl;
					one->setDmg(0);}
				else{
					std::cout << "The attack is successful!" << std::endl;
					if(flagTwo == false)
						val = one->getAttVal() - two->getDefVal();
					else
						val = (one->getAttVal() / 2) - two->getDefVal();
					two->setDmg(val);
					if(two->getDmg() == 0)
						std::cout << "Armor absorbed the attack!" << std::endl;
					else
						std::cout << two->getDmg() << " points of damage!" << std::endl;
					two->setSP();
					if(two->getSP() <= 0 )
						std::cout << "GAME OVER!" << std::endl;
					else
						std::cout << "Only " << two->getSP() << " Strength Points left!" << std::endl;}

				// Check for end game
				if(one->getSP() <= 0 || two->getSP() <= 0){
					over = true;
					one->fillSP();						//restore health to winner
					std::rotate(v.begin(), v.begin()+1, v.end());		//rotate winning teams lineup
					losers.push_back(two);					//add loser to losing lineup
					std::rotate(v2.begin(), v2.begin()+1, v2.end());	//rotate losing team's lineup
					v2.pop_back();						//get rid of the loser from losing team's lineup
					one->setWins(1);}					//track winner
				turn++;}
	}while(over == false);
	game++;}
}





