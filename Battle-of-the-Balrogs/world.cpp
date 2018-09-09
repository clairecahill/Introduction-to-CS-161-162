/**************************
 * Program: world.cpp
 * Author: claire cahill
 * Date: 5/17/2017
 * Description: has world class function
 * Input: none
 * Output: none
*****************************/

#include "world.h"

/*************************
 * Function: default constructor
 * Description: sets values
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * *********************/

World::World(){

   bank = 100;
   h = NULL;
   e = NULL;
   b = NULL;
   c = NULL;
   num_humans = 0;
   num_elves = 0;
   num_balrogs = 0;
   num_cyberdemons = 0;
}

//Big Three


/*************************
 * Function: copy constructor
 * Description: assigns values
 * Parameters: const other
 * Pre-Conditions: none
 * Post-Conditions: none
 * *********************/

World::World(const World &other){

   bank = other.bank;
   int t = 0;
   num_humans = other.num_humans;
   h = new Human[num_humans];
   for(int i = 0; i < num_humans + 1; i++){
      h[i] = other.h[i];
   }
   e = new Elf[num_elves];
   for(int i = 0; i < num_elves + 1; i++){
      e[i] = other.e[i];
   }
   b = new Balrog[num_balrogs];
   for(int i = 0; i < num_balrogs + 1; i++){
      b[i] = other.b[i];
   }
   c = new Cyberdemon[num_cyberdemons];
   for(int i = 0; i < num_cyberdemons + 1; i++){
      c[i] = other.c[i];
   }
}

/*************************
 * Function: assigment operator
 * Description: assigns values
 * Parameters: const other
 * Pre-Conditions: none
 * Post-Conditions: none
 * *********************/

void World::operator = (const World &other){

   delete [] h;
   delete [] e;
   delete [] b;
   delete [] c;
   h = NULL;
   e = NULL;
   b = NULL;
   c = NULL;

   bank = other.bank;
   h = new Human[num_humans];
   for(int i = 0; i < num_humans; i++){
      h[i] = other.h[i];
   }
   e = new Elf[num_elves];
   for(int i = 0; i < num_elves; i++){
      e[i] = other.e[i];
   }
   b = new Balrog[num_balrogs];
   for(int i = 0; i < num_balrogs; i++){
      b[i] = other.b[i];
   }
   c = new Cyberdemon[num_cyberdemons];
   for(int i = 0; i < num_cyberdemons; i++){
      c[i] = other.c[i];
   }
}

/*************************
 * Function: destructor
 * Description: deletes dynamic memory
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * *********************/

World::~World(){

   delete [] h;
   delete [] e;
   delete [] b;
   delete [] c;
}

/*************************
 * Function: world class mutators
 * Description: allows private variables 
 * to be changed
 * Parameters: data type of variable
 * Pre-Conditions: variables must exist
 * Post-Conditions: none
 * *********************/

void World::setBank(double x){
   bank = x;
}

void World::setHuman(int num){
   
   Human *temp = new Human[num + num_humans];
   for(int i = 0; i < num_humans; i++){
      temp[i] = h[i];
   }

   if(h != NULL){
      delete [] h;
   }

   h = temp;
}

void World::setElf(int num){
   
   Elf *temp = new Elf[num + num_elves];
   for(int i = 0; i < num_elves; i++){
      temp[i] = e[i];
   }

   if(e != NULL){
      delete [] e;
   }

   e = temp;
}

void World::setBalrog(int num){
   
   Balrog *temp = new Balrog[num + num_balrogs];
   for(int i = 0; i < num_balrogs; i++){
      temp[i] = b[i];
   }

   if(b != NULL){
      delete [] b;
   }

   b = temp;
}

void World::setCyberdemon(int num){
   
   Cyberdemon *temp = new Cyberdemon[num + num_cyberdemons];
   for(int i = 0; i < num_cyberdemons; i++){
      temp[i] = c[i];
   }

   if(c != NULL){
      delete [] c;
   }

   c = temp;
}

void World::setNumhumans(int num){
   num_humans = num;
}

void World::setNumelves(int num){
   num_elves = num;
}

void World::setNumbalrogs(int num){
   num_balrogs = num;
}

void World::setNumcyberdemons(int num){
   num_cyberdemons = num;
}

/*************************
 * Function: world class accessors
 * Description: allows private member variables 
 * to be accessed outside of the class
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * *********************/

double World::getBank(){
   return bank;
}

Human* World::getHuman(){
   return h;
}

Elf* World::getElf(){
   return e;
}

Balrog* World::getBalrog(){
   return b;
}

Cyberdemon* World::getCyberdemon(){
   return c;
}

int World::getNumhumans(){
   return num_humans;
}

int World::getNumelves(){
   return num_elves;
}

int World::getNumbalrogs(){
   return num_balrogs;
}

int World::getNumcyberdemons(){
   return num_cyberdemons;
}
