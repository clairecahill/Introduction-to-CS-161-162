/*********************************
 * Program: human.cpp
 * Author: claire cahill
 * Date: 5/17/2017
 * Description: has all human functions
 * Input: none
 * Output: damage points
 * ******************************/

#include "human.h"

/*************************
 * Function: default contructor
 * Description: sets value
 * Parameters: none
 * Pre-Conditions: creature must exist
 * Post-Conditions: none
 * *********************/

Human::Human(){

   type = 0;
   strength = 10;
   hitpoints = 50;
   name = "Human";
   payoff = 300;
   cost = 20;

}

/*************************
 * Function: assignment operator
 * Description: assigns values
 * Parameters: const Human &other
 * Pre-Conditions: creature must exist
 * Post-Conditions: none
 * *********************/

void Human::operator = (const Human &other){

   type = other.type;
   strength = other.strength;
   hitpoints = other.hitpoints;
   name = other.name;
   payoff = other.payoff;
   cost = other.cost;

}

/*************************
 * Function: getSpecies
 * Description: returns string
 * Parameters: none
 * Pre-Conditions: creature must exist
 * Post-Conditions: none
 * *********************/

string Human::getSpecies(){

   return "Human";
}

/*************************
 * Function: getDamage
 * Description: inherets creature getDamage
 * Parameters: none
 * Pre-Conditions: creature must exist
 * Post-Conditions: none
 * *********************/

int Human::getDamage(){

   int damage = 0;

   damage = Creature::getDamage();

   cout << name << " attacks for " << damage << " hitpoints!" << endl;

   return damage;
}

















