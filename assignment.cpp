/***************************************************************************************
 * Author: Tara Massey
 * Date: 2/28/2015
 * File Name: assignment.cpp
 *
 * Program: The program's purpose is to create a tournament. The tournament has two
 * equal teams, size selected by the user. Each user can select what class of fighter
 * will fight. The program then fights the first fighter from the two lineups. The loser
 * is sent to a losing lineup. The fights continue in rotating order until one team has
 * no fighters left. Points are awarded for each win. The program will tell the user
 * which team still had fighters left at the end, which team had more points, and which
 * three fighters won the most rounds. The tournament can be repeated, if the user chooses,
 * with new fighters.
 *
 * Input: User inputs the team amount, the class for each fighter, the name of each fighter.
 * The user can select to fight another tournament, or to end the game.
 *
 * Output: Program prints team that still had members standing, team with the most points,
 * and the top three scoring fighters. During the fights, prints who is attacking and 
 * defending, dice roll amount, and damage amount (if any).
 *
 * Please Note: Bubble Sort was used. Example for sort was taken from the text, C++ Early
 * Objects, page 618.
 * *************************************************************************************/

#include "Dice.h"
#include "Creature.h"
#include "Barbarian.h"
#include "Shadow.h"
#include "Goblin.h"
#include "BlueM.h"
#include "Reptile.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int createTeams(std::vector<Creature*>&v, std::vector<Creature*>&v2);
void fight(Creature* one, Creature* two, std::vector<Creature*> &oneWin, std::vector<Creature*> &twoWin, std::vector<Creature*> &losers, int &game);

int main()
{

	Creature* fighter;
	Creature* fighter2;
	Creature* temp;
	std::vector<Creature*> losers;
	std::vector<Creature*>v;
	std::vector<Creature*>v2;
	std::string pause;
	char playAgain = 'Y';
	int amount;
	int game;
	int oneTotal = 0;
	int twoTotal = 0;
	bool match = false;
	bool swap;

	game = 0;
	while(playAgain == 'Y')
	{
		std::cout << "\n" << std::endl;
		amount = createTeams(v, v2);
		
		while(v.size() != 0 && v2.size() != 0){
			fighter = v[0];
			fighter2 = v2[0];
			std::cout << "Battle beginning!" << std::endl;
			std::cout << "Fighter one is " << fighter->getType() << std::endl;
			std::cout << "Fighter two is " << fighter2->getType() << std::endl;
			fight(fighter, fighter2, v, v2, losers, game);
			std::cout << "\nPlease hit ENTER to continue to the next round" << std::endl;	
			std::getline(std::cin, pause);}

			//put all in same pile to determine winner
			if(v.size() != 0){
				std::cout << "\nTeam One is the last standing!" << std::endl;
				for(int i = 0; i < v.size(); i++)
					losers.push_back(v[i]);}
			if(v2.size() != 0){
				std::cout << "\nTeam Two is the last standing!" << std::endl;
				for(int i = 0; i < v2.size(); i++)
					losers.push_back(v2[i]);}


			//determine which team scored more points
			for(int i = 0; i < losers.size(); i++){
				fighter2 = losers[i];
				if(fighter2->getTeam() == 1)
					oneTotal = fighter2->getWins() + oneTotal;
				if(fighter2->getTeam() == 2)
					twoTotal = fighter2->getWins() + twoTotal;}

			std::cout << "\nTeam One had " << oneTotal << " points." << std::endl;
			std::cout << "Team Two had " << twoTotal << " points." << std::endl;
			if(oneTotal > twoTotal)
				std::cout << "Team One is the winner based off points!" << std::endl;
			if(twoTotal > oneTotal)
				std::cout << "Team Two is the winner based off points!" << std::endl;
			if(twoTotal == oneTotal)
				std::cout << "Tie!" << std::endl;

			//sort based off wins
			do{
				swap = false;
				for(int k =0; k < (losers.size() -1); k++){
					if(losers[k]->getWins() > losers[k+1]->getWins()){
						temp = losers[k];
						losers[k] = losers[k+1];
						losers[k+1] = temp;
						swap = true;}}
			}while(swap);


			//announce winners
			std::reverse(losers.begin(), losers.end());
			std::cout << "\nFinal Rankings: " << std::endl;
			if(losers.size() < 3){
				for(int i = 0; i < losers.size(); i++){
					fighter = losers[i];
					std::cout << fighter->getType() << " " << fighter->getName() << " with " << fighter->getWins()<< " points " << std::endl;}}
			else{
				for(int i = 0; i < 3; i++){
					fighter = losers[i];
					std::cout << fighter->getType() << " " << fighter->getName() << " with " << fighter->getWins() << " points " << std::endl;}}
		
		v.clear();
		v2.clear();
		losers.clear();	
		oneTotal = 0;
		twoTotal = 0;
		std::cout << "Play Again?" << std::endl;
		std::getline(std::cin, pause);
		while(pause != "Y" && pause != "y" && pause != "n" && pause != "N"){
			std::cout << "Please enter Y or N:   ";
			std::getline(std::cin, pause);}
			
		if(pause == "N" || pause == "n"){
			playAgain = 'n';}
	}
	delete fighter;
	delete fighter2;
	return 0;
}

/*******************************************************************
 * int createTeams()
 *
 * Purpose: Displays the available fighters the user can select
 * from and prompts for fighter amount and fighter choices. Allows
 * the user to name the fighters.
 *
 * Entry: Takes in two empty vectors, one for each time, and fills them
 * with the creatures of the user's selection.
 *
 * Exit: Returns the amount of of fighters the two teams will have
 * *****************************************************************/
int createTeams(std::vector<Creature*>&v, std::vector<Creature*>&v2)
{
	int choice;
	std::string name;
	std::string option;
	Creature* fighter;
	Creature* fighter2;

	// get team amount and check for valid input
	std::cout << "\n" << std::endl;
	std::cout << "Please enter the number of fighters on each team in the tournament:  " << std::endl;
	std::getline(std::cin, option);
	for(int i = 0; i < option.length(); i++){
		while(!(isdigit(option.at(i)))){
			std::cout << "Invalid. Please enter a number: "; 
			std::getline(std::cin, option);}}
	choice = atoi(option.c_str());
	while(choice == 0){
		std::cout << "Invalid. Please enter a positive number: ";
		std::getline(std::cin, option);
		for(int i = 0; i < option.length(); i++){
			while(!(isdigit(option.at(i)))){
				std::cout << "Invalid. Please enter a number: "; 
				std::getline(std::cin, option);}}
		choice = atoi(option.c_str());}
	
	// player one team
	std::cout << "\nPlayer One, you have the following fighter options: " << std::endl;
	std::cout << "Barbarian" << std::endl;
	std::cout << "Shadow" << std::endl;
	std::cout << "Reptile Man " << std::endl;
	std::cout << "Blue Men" << std::endl;
	std::cout << "Goblin" << std::endl;
	
	for(int i = 0; i < choice; i++){
		std::cout << "\nPlease enter the fighter type for Fighter " << i+1 << ": ";
		std::getline(std::cin, option);
		if(option == "Barbarian"){
			fighter = new Barbarian;
			fighter->setTeam(1);
			std::cout << "Please give this fighter a name:  ";
			std::getline(std::cin, name);
			fighter->setName(name);
			v.push_back(fighter);}
		if(option == "Shadow"){
			fighter = new Shadow;
			fighter->setTeam(1);
			std::cout << "Please give this fighter a name:  ";
			std::getline(std::cin, name);
			fighter->setName(name);
			v.push_back(fighter);}
		if(option == "Reptile Man"){
			fighter = new Reptile;
			fighter->setTeam(1);
			std::cout << "Please give this fighter a name:  ";
			std::getline(std::cin, name);
			fighter->setName(name);
			v.push_back(fighter);}
		if(option == "Blue Men"){
			fighter = new BlueM;
			fighter->setTeam(1);
			std::cout << "Please give this fighter a name:  ";
			std::getline(std::cin, name);
			fighter->setName(name);
			v.push_back(fighter);}
		if(option == "Goblin"){
			fighter = new Goblin;
			fighter->setTeam(1);
			std::cout << "Please give this fighter a name:  ";
			std::getline(std::cin, name);
			fighter->setName(name);
			v.push_back(fighter);}} 


	// player two team
	std::cout << "\nPlayer Two, you have the following fighter options: " << std::endl;
	std::cout << "Barbarian" << std::endl;
	std::cout << "Shadow" << std::endl;
	std::cout << "Reptile Man " << std::endl;
	std::cout << "Blue Men" << std::endl;
	std::cout << "Goblin" << std::endl;


	for(int i = 0; i < choice; i++){
		std::cout << "\nPlease enter the fighter type for Fighter " << i+1 << ": ";
		std::getline(std::cin, option);
		if(option == "Barbarian"){
			fighter2 = new Barbarian;
			fighter2->setTeam(2);
			std::cout << "Please give this fighter a name:  ";
			std::getline(std::cin, name);
			fighter2->setName(name);
			v2.push_back(fighter2);}
		if(option == "Shadow"){
			fighter2 = new Shadow;
			fighter2->setTeam(2);
			std::cout << "Please give this fighter a name:  ";
			std::getline(std::cin, name);
			fighter2->setName(name);
			v2.push_back(fighter2);}
		if(option == "Reptile Man"){
			fighter2 = new Reptile;
			fighter2->setTeam(2);
			std::cout << "Please give this fighter a name:  ";
			std::getline(std::cin, name);
			fighter2->setName(name);
			v2.push_back(fighter2);}
		if(option == "Blue Men"){
			fighter2 = new BlueM;
			fighter2->setTeam(2);
			std::cout << "Please give this fighter a name:  ";
			std::getline(std::cin, name);
			fighter2->setName(name);
			v2.push_back(fighter2);}
		if(option == "Goblin"){
			fighter2 = new Goblin;
			fighter2->setTeam(2);
			std::cout << "Please give this fighter a name:  ";
			std::getline(std::cin, name);
			fighter2->setName(name);
			v2.push_back(fighter2);}}  


	return choice;
}



