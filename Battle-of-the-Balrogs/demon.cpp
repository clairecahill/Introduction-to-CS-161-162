/****************************
 * Program: demon.cpp
 * Author: claire cahill
 * Date: 5/17/2017
 * Description: adds 50 damage points
 * for demon attacks
 * Input: none
 * Output: getDamage when attacks
 * *************************/

#include "demon.h"

/****************************
 * Function: default constructor
 * Description: sets values for demons
 * Parameters: none
 * Pre-Conditions: creature must have values
 * Post-Conditions: none
 * *************************/

Demon::Demon(){

   type = 2;
   strength = 50;
   hitpoints = 300;
   name = "Balrog";
   payoff = 150;
   cost = 35;
}

/****************************
 * Function: getDamage
 * Description: adds 50 hitpoints for demon
 * attacks
 * Parameters: creature getDamage must exist
 * Pre-Conditions: none
 * Post-Conditions: none
 * *************************/

int Demon::getDamage(){

   int damage = 0;

   damage = Creature::getDamage();

   if( (rand() % 100) < 5){
      damage = damage + 50;
      cout << "Demon attack inflicts 50 additional damage points!" << endl;
   }

   return damage;

}
