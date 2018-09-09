/****************************
 * Program: creature.cpp
 * Author: claire cahill
 * Date: 5/17/2017
 * Description: base class for 
 * all creatures
 * Input: none
 * Output: prints out damage points
 * ***************************/

#include "creature.h"


/****************************
 * Function: default constructor
 * Description: sets values
 * Parameters: none
 * Pre-Conditions: non default constructor
 * must not be called
 * Post-Conditions: none
 * *************************/

Creature::Creature(){

   type = 0;
   strength = 10;
   hitpoints = 10;
   name = "Name";
   payoff = 10;
   cost = 10;
}

/****************************
 * Function: non default constructor
 * Description: sets values based on user input
 * Parameters: int, int, int, string, double, double
 * Pre-Conditions: none
 * Post-Conditions: none
 * *************************/

Creature::Creature(int a, int b, int c, string d, double e, double f) {

   type = a;
   strength = b;
   hitpoints = c;
   name = d;
   payoff = e;
   cost = f;
}

/****************************
 * Function: assignment operator
 * Description: copies over the values
 * Parameters: const Creature &other
 * Pre-Conditions: assignment must be called
 * Post-Conditions: none
 * *************************/

void Creature::operator = (const Creature &other){

   type = other.type;
   strength = other.strength;
   hitpoints = other.hitpoints;
   name = other.name;
   payoff = other.payoff;
   cost = other.cost;
   
}

/****************************
 * Function: creature mutators
 * Description: sets private member variables 
 * based on parameters
 * Parameters: based on data type
 * Pre-Conditions: must have parameter
 * Post-Conditions: holds value
 * *************************/

void Creature::setType(int t){
   type = t;
}

void Creature::setStrength(int s){
   strength = s;
}

void Creature::setHitpoints(int h){
   hitpoints = h;
}

void Creature::setName(string n){
   name = n;
}

void Creature::setPayoff(double p){
   payoff = p;
}

void Creature::setCost(double c){
   cost = c;
}

/****************************
 * Function: creature accessors
 * Description: allows private member variables
 * to be accessed
 * Parameters: none
 * Pre-Conditions: values must exist
 * Post-Conditions: none
 * *************************/

int Creature::getType(){
   return type;
}

int Creature::getStrength(){
   return strength;
}

int Creature::getHitpoints(){
   return hitpoints;
}

string Creature::getName(){
   return name;
}

double Creature::getPayoff(){
   return payoff;
}

double Creature::getCost(){
   return cost;
}

/****************************
 * Function: getSpecies()
 * Description: returns string based on type
 * and allows access to private function
 * Parameters: none
 * Pre-Conditions: must have type
 * Post-Conditions: none
 * *************************/

string Creature::getSpecies(){

   switch(type){
   
      case 0:
	return "Human";
      case 1:
	return "Elf";
      case 2:
	return "Balrog";
      case 3:
	return "Cyberdemon";
   }
   return "Unknown";
}

/****************************
 * Function: getDamage
 * Description: parent function for all creatures
 * to inheret
 * Parameters: none
 * Pre-Conditions: strength value must exist
 * Post-Conditions: none
 * *************************/

int Creature::getDamage(){

   int damage = 0;

   srand(time(NULL));
   damage = (rand() % strength ) + 1;

   return damage;
}
