/****************************
 * Program: balrog.cpp
 * Author: claire cahill
 * Date: 5/17/2017
 * Description: has balrog functions, 
 * inherets from creature
 * Input: none
 * Output: damage points
 * **************************/

#include "balrog.h"

/****************************
 * Function: default constructor
 * Description: sets values
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * *************************/

Balrog::Balrog(){

   type = 2;
   strength = 50;
   hitpoints = 300;
   name = "Balrog";
   payoff = 150;
   cost = 35;
}

/****************************
 * Function: getSpecies
 * Description: returns balrog
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * *************************/

string Balrog::getSpecies(){

   return "Balrog";
}

/****************************
 * Function: getDamage
 * Description: inherets demon getDamage
 * and attacks twice
 * Parameters: none
 * Pre-Conditions: getDamage in Demon must exist
 * Post-Conditions: none
 * *************************/

int Balrog::getDamage(){

   int damage = 0, damage2 = 0;

   damage = Demon::getDamage();

   damage2 = (rand() % strength) + 1;

   damage = damage + damage2;

   cout << name << " attacks twice for a total of " << damage << " hitpoints!" << endl;
   
   return damage;
}
