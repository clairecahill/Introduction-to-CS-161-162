/***********************
 * Program: cyberdemon.cpp
 * Author: claire cahill
 * Date: 5/17/2017
 * Description: performs functions for
 * cyberdemons
 * Input: none
 * Output: prints out damage hitpoints
 * ********************/

#include "cyberdemon.h"

/****************************
 * Function: default constructor
 * Description: sets values
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * *************************/

Cyberdemon::Cyberdemon(){

   type = 3;
   strength = 50;
   hitpoints = 200;
   name = "Cyberdemon";
   payoff = 150;
   cost = 35;

}

/****************************
 * Function: getSpecies
 * Description: returns string
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * *************************/

string Cyberdemon::getSpecies(){

   return "Cyberdemon";
}

/****************************
 * Function: getDamage
 * Description: inherets demons getDamage 
 * and prints out hitpoints
 * Parameters: none
 * Pre-Conditions: demon getDamage must exist
 * Post-Conditions: none
 * *************************/

int Cyberdemon::getDamage(){

   int damage = 0;

   damage = Demon::getDamage();

   cout << name << " attacks for " << damage << " hitpoints!" << endl;

   return damage;
}
