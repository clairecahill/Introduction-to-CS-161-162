/**************************
 * Program: elf.cpp
 * Author: claire cahill
 * Date: 5/17/2017
 * Description: carries out elf functions
 * Input: none
 * Output: hitpoints after damage
 * ************************/

#include "elf.h"

/*************************
 * Function: default constructor
 * Description: sets values
 * Parameters: none
 * Pre-Conditions: creature must exist
 * Post-Conditions: none
 * *********************/

Elf::Elf(){

   type = 1;
   strength = 30;
   hitpoints = 150;
   name = "Elf";
   payoff = 200;
   cost = 30;
}

/*************************
 * Function: elf assignment operator
 * Description: assigns values
 * Parameters: const Elf other
 * Pre-Conditions: creature must exist
 * Post-Conditions: none
 * *********************/

void Elf::operator = (const Elf &other){

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

string Elf::getSpecies(){

   return "Elf";
}

/*************************
 * Function: getDamage
 * Description: inherets creature getDamage and adds
 * Parameters: none
 * Pre-Conditions: creature must exist
 * Post-Conditions: none
 * *********************/

int Elf::getDamage(){

   int damage = 0;

   damage = Creature::getDamage();

   cout << name << " attacks for " << damage << " hitpoints!" << endl; 
   
   if( (rand() % 10) == 0 ){
      cout << "Magical attack inflicts " << damage << " extra hitpoints ";
      cout << "for a total of " << damage * 2 << " hitpoints!" << endl;
      damage = damage * 2;
   }

   return damage;
}
