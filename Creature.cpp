#include "Creature.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

/****************************************************************************
 * Creature::Creature(int a, int SP)
 *
 * Purpose: Constructor
 * Entry: None
 * Exit: None
 * ***********************************************************************/

Creature::Creature(int a, int sP){
	this->armor = a;
	this->strPnt = sP;
	this->attRoll = 2;
	this->defRoll = 1;
	this->name = " ";
	this->wins = 0;
	this->team = 0;}



/****************************************************************************
 * int Creature::attack()
 *
 * Purpose: attack function, generates rolls of dice and sets attack values
 * Entry: None
 * Exit: Returns total attack value
 * ***********************************************************************/

int Creature::attack(){
	total = 0;
		
	for(int i = 0; i < getRoll(); i++){
		indAttack();
		std::cout << "\nRolls: ";
		roll = general.rollDice();
		std::cout << roll << std::endl;
		total = total + roll;}
		setAttVal(total);
	return total;}



/****************************************************************************
 * int Creature::attack(bool &achilles)()
 *
 * Purpose: Basic attack function for Goblin. Returns a flag for achilles.
 * Entry: Boolean value by reference to indicate if achilles is active
 * Exit: Returns achilles
 * ***********************************************************************/

int Creature::attack(bool &achilles){
	return achilles;}




/****************************************************************************
 * Creature::defense()
 *
 * Purpose: Basic defenese. Rolls dice and generates defense value
 * Entry: None
 * Exit: Returns total defense value
 * ***********************************************************************/

int Creature::defense(){
	total = 0;

	for(int i = 0; i < getDefRoll(); i++){
		std::cout << getType() << " defends! Rolls: ";
		roll= general.rollDice();
		std::cout << roll << std::endl;
		total = total + roll;}
	setDefVal(total);
	return total;}



/****************************************************************************
 * int Creature::getDmg()
 *
 * Purpose: Returns damage
 * Entry: None
 * Exit: Returns damange
 * ***********************************************************************/

int Creature::getDmg(){
	return dmg;}




/****************************************************************************
 * void Creature::setDmg(int hurt)
 *
 * Purpose: Determines if there is damage and if so, how much
 * Entry: total amount of rolls
 * Exit: None
 * ***********************************************************************/

void Creature::setDmg(int hurt){
	if(hurt > 0)
		dmg = hurt;
	else
		dmg = 0;
	if(dmg > 0){
		dmg = dmg - armor;
		if(dmg < 0)
			dmg = 0;}}


/****************************************************************************
 * int Creature::getRoll()
 *
 * Purpose: Returns roll
 * Entry: None
 * Exit: Returns roll
 * ***********************************************************************/

int Creature::getRoll(){
	return attRoll;}


/****************************************************************************
 * int Creature::getDefRoll()
 *
 * Purpose: Returns defense roll
 * Entry: None
 * Exit: Returns defense roll
 * ***********************************************************************/

int Creature::getDefRoll(){
	return defRoll;}




/****************************************************************************
 * void Creature::setRoll()
 *
 * Purpose: Sets the number of times a player can roll die
 * Entry: number of rolls
 * Exit: None
 * ***********************************************************************/

void Creature::setRoll(int num){
	attRoll = num;}




/****************************************************************************
 * void Creature::setAttVal(int val)
 *
 * Purpose: Determines and sets attack value
 * Entry: integer that is the total of all rolls
 * Exit: None
 * ***********************************************************************/

void Creature::setAttVal(int val){
	attVal = val;}



/****************************************************************************
 * int Creature::getAttVal()
 *
 * Purpose: Returns attack value
 * Entry: None
 * Exit: Returns attack value
 * ***********************************************************************/

int Creature::getAttVal(){
	return attVal;}




/****************************************************************************
 * void Creature::setDefVal()
 *
 * Purpose: Determines and sets defense value
 * Entry: Integer that is the total of all rolls
 * Exit: None
 * ***********************************************************************/

void Creature::setDefVal(int val){
	defVal = val;}



/****************************************************************************
 * int Creature::getDefVal()
 *
 * Purpose: Returns defense value
 * Entry: None
 * Exit: Returns defense value
 * ***********************************************************************/

int Creature::getDefVal(){
	return defVal;}




/****************************************************************************
 * void Creature::setSP)
 *
 * Purpose: Determines and sets strength points
 * Entry: None
 * Exit: None
 * ***********************************************************************/

void Creature::setSP(){
	dmg = armor - dmg;
	strPnt = strPnt - (armor -dmg);
	if(strPnt < 0)
		strPnt = 0;}




/****************************************************************************
 * void Creature::setSP(int num)
 *
 * Purpose: Sets strength points based on user input
 * Entry: Strength point amount
 * Exit: None
 * ***********************************************************************/

void Creature::setSP(int num){
	strPnt = num;}




/****************************************************************************
 * int Creature::getSP()
 *
 * Purpose: Returns strength points
 * Entry: None
 * Exit: Returns strength points
 * ***********************************************************************/

int Creature::getSP(){
	return strPnt;}




/****************************************************************************
 * void Creature::fillSP()
 *
 * Purpose: Returns strength points to full starting level
 * Entry: None
 * Exit: None
 * ***********************************************************************/

void Creature::fillSP(){
	strPnt = 12;}




/****************************************************************************
 * void Creature::setName(std::string input)
 *
 * Purpose: Sets name based off user input
 * Entry: name of user choice
 * Exit: None
 * ***********************************************************************/

void Creature::setName(std::string input){
	name = input;}




/****************************************************************************
 * std::string Creature::getName()
 *
 * Purpose: Returns user name
 * Entry: None
 * Exit: Returns user name
 * ***********************************************************************/

std::string Creature::getName(){
	return name;}



/****************************************************************************
 * void Creature::setWins(int tally)
 *
 * Purpose: Determines and sets number of wins
 * Entry: Integer for win points
 * Exit: None
 * ***********************************************************************/

void Creature::setWins(int tally){
	wins = wins + tally;}




/****************************************************************************
 * int Creature::getWins()
 *
 * Purpose: Returns wins
 * Entry: None
 * Exit: Returns wins
 * ***********************************************************************/

int Creature::getWins(){
	return wins;}




/****************************************************************************
 * void Creature::setTeam(int num)
 *
 * Purpose: Assigns the creature to one of two teams
 * Entry: Team number
 * Exit: None
 * ***********************************************************************/

void Creature::setTeam(int num){
	team = num;}




/****************************************************************************
 * int Creature::getTeam()
 *
 * Purpose: Returns the team the creature is assigned to
 * Entry: None
 * Exit: Returns integer of team creature is assigned to
 * ***********************************************************************/

int Creature::getTeam(){
	return team;}




/****************************************************************************
 * Creature::~Creature()
 *
 * Purpose: Deconstructor
 * Entry: None
 * Exit: None
 * ***********************************************************************/

Creature::~Creature(){}
