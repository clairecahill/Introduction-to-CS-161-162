/***************************************
 * Program: trainer.cpp
 * Author: claire cahill
 * Date 5/26/17
 * Description: has all functionality for trainer
 * Input: none
 * Output: game is played
 * ***********************************/
#include "trainer.h"

/************************************
 * Function: default constructor
 * Description: assigns values when object is created
 * Parameters: none
 * Pre-Conditions: trainer.h
 * Post-Conditions: none
 ***********************************/

Trainer::Trainer(){

   num_pokeballs = 0;
   p = NULL;
}

/************************************
 * Function: copy constructor
 * Description: copies values when = is used 
 * Parameters: const Trainer &other
 * Pre-Conditions: trainer.h
 * Post-Conditions: none
 ***********************************/

Trainer::Trainer(const Trainer &other){

   l = other.l;
   num_pokeballs = other.num_pokeballs;
   p = new Pokemon*[6];
   for(int i = 0; i < 6; i++){
      p[i] = other.p[i];
   }

}

/************************************
 * Function: assignment operator overload
 * Description: copies over values
 * Parameters: const Trainer &other
 * Pre-Conditions: trainer.h
 * Post-Conditions: none
 ***********************************/

void Trainer::operator = (const Trainer &other){

   if(p != NULL){
      delete [] p;
   }
   l = other.l;
   num_pokeballs = other.num_pokeballs;
   p = new Pokemon*[6];
   for(int i = 0; i < 6; i++){
      p[i] = other.p[i];
   }

}

/************************************
 * Function: destructor
 * Description: frees dynamic memory
 * Parameters: none
 * Pre-Conditions: trainer.h
 * Post-Conditions: none
 ***********************************/

Trainer::~Trainer(){

   if(p != NULL){
      for(int i = 0; i < 6; i++){
	 delete p[i];
      }
      delete [] p;
   }
}

/************************************
 * Function: set_location
 * Description: location modifier
 * Parameters: location
 * Pre-Conditions: trainer.h
 * Post-Conditions: none
 ***********************************/

void Trainer::set_location(int h, int w){

   l.set_height(h);
   l.set_width(w);
}

/****************************
 * Function:  set_megastone
 * Description: megastone setter
 * Parameters: bool m
 * Pre-Conditions: none
 * Post-Conditions: none
 * *****************************/

void Trainer::set_megastone(bool m){

   megastone = m;
}

/************************************
 * Function: set_num_pokeballs
 * Description: num_pokeballs modifier
 * Parameters: x
 * Pre-Conditions: trainer.h
 * Post-Conditions: none
 ***********************************/

void Trainer::set_num_pokeballs(int x){

   num_pokeballs = x;
}

/************************************
 * Function: set_pokemon
 * Description: assigns pokemon array specific pokemon
 * Parameters: none
 * Pre-Conditions: trainer.h
 * Post-Conditions: none
 ***********************************/

void Trainer::set_pokemon(){

   p = new Pokemon*[6];
   p[0] = new Rock("Geodude", "Rock", 0, .75, 0);
   p[1] = new Rock("Onix", "Rock", 0, .75, 0);
   p[2] = new Flying("Charizard", "Flying", 0, .50, 0);
   p[3] = new Flying("Rayquaza", "Flying", 0, .50, 0);
   p[4] = new Psychic("Mewtwo", "Psychic", 0, .25, 0);
   p[5] = new Psychic("Espeon", "Psychic", 0, .25, 0);

}

/************************************
 * Function: get_location
 * Description: location accessor
 * Parameters: none
 * Pre-Conditions: trainer.h
 * Post-Conditions: none
 ***********************************/

Location Trainer::get_location(){

   return l;
}

/************************************
 * Function: get_num_pokeballs
 * Description: num_pokeballs accessor
 * Parameters: none
 * Pre-Conditions: trainer.h
 * Post-Conditions: none
 ***********************************/

int Trainer::get_num_pokeballs(){

   return num_pokeballs;
}

/****************************
 * Function: get_megastone 
 * Description: megastone getter
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * *****************************/

bool Trainer::get_megastone(){
   
   return megastone;
}

/************************************
 * Function: get_pokemon
 * Description: pokemon accessor
 * Parameters: none
 * Pre-Conditions: trainer.h
 * Post-Conditions: none
 ***********************************/

Pokemon** Trainer::get_pokemon(){

   return p;
}

