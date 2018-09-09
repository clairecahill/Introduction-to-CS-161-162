/***********************************
 * Program: location.cpp
 * Author: claire cahill
 * Date: 5/22/17
 * Description: used in main to keep track of
 * the locations on the pokemon game board
 * Input: none
 * Output: creates game board
 * ********************************/

#include "location.h"

/***********************
 * Function: default constructor
 * Description: initializes all values
 * Parameters: none
 * Pre-Conditions: event class must exist
 * Post-Conditions: none
 * *********************/

Location::Location(){

   height = 0;
   width = 0;
   e = NULL;

}

/*********************
 * Function: copy constructor
 * Description: copies all objects for
 * the dymanic memory for event array
 * Parameters: const Location &other
 * Pre-Conditions: original Location must exist
 * Post-Conditions: none
 * *********************/

Location::Location(const Location &other){

   height = other.height;
   width = other.width;
   e = other.e;

}

/*********************
 * Function: assignment operator overload
 * Description: copies all objects for
 * the dymanic memory for event array
 * Parameters: const Location &other
 * Pre-Conditions: original Location must exist
 * Post-Conditions: none
 * *********************/

void Location::operator = (const Location &other){

   if(e != NULL){
      delete [] e;
   }
   height = other.height;
   width = other.width;
   e = other.e;
}

/*********************
 * Function: destructor
 * Description: deletes dynamic memory
 * Parameters: none
 * Pre-Conditions: location must be deleted
 * to be called
 * Post-Conditions: cannot access array again
 * ***********************/

Location::~Location(){

   if(e != NULL){
      delete [] e;
   }

}

/************************
 * Function: set_height
 * Description: height modifier
 * Parameters: int x
 * Pre-Conditions: a location must exist
 * Post-Conditions: none
 * *********************/

void Location::set_height(int x){

   height = x;

}

/*********************
 * Function: set_width
 * Description: width modifier
 * Parameters: int x
 * Pre-Conditions: location must exist
 * Post-Conditions: none
 * *********************/

void Location::set_width(int x){

   width = x;

}

/**********************
 * Function: set_event
 * Description: event modifier
 * Parameters: event a
 * Pre-Conditions: must have big three
 * Post-Conditions: none
 * *********************/

void Location::set_event(string type){

   if(type == "cave"){
      e = new Cave;
      e->set_type("Cave");
   }
   else if(type == "pokestop"){
      e = new Pokestop;
      e->set_type("Pokestop");
   }
   else if(type == "geodude"){
      e = new Rock("Geodude", "Rock", 0, .75, 0);
      e->set_type("Geodude");
   }
   else if(type == "onix"){
      e = new Rock("Onix", "Rock", 0, .75, 0);
      e->set_type("Onix");
   }
   else if(type == "charizard"){
      e = new Flying("Charizard", "Flying", 0, .50, 0);
      e->set_type("Charizard");
   }
   else if(type == "rayquaza"){
      e = new Flying("Rayquaza", "Flying", 0, .50, 0);
      e->set_type("Rayquaza");
   }
   else if(type == "mewtwo"){
      e = new Psychic("Mewtwo", "Psychic", 0, .25, 0);
      e->set_type("Mewtwo");
   }
   else if(type == "espeon"){
      e = new Psychic("Espeon", "Psychic", 0, .25, 0);
      e->set_type("Espeon");
   }
   else{
      e = NULL;
   }
   
}

/**************************
 * Function: get_height
 * Description: height accessor
 * Parameters: none
 * Pre-Conditions: location must exist
 * Post-Conditions: none
 * **********************/

int Location::get_height(){

   return height;

}

/**************************
 * Function: get_width
 * Description: width accessor
 * Parameters: none
 * Pre-Conditions: location must exist
 * Post-Conditions: none
 * ***************************/

int Location::get_width(){

   return width;

}

/***************************
 * Function: get_event
 * Description: event accessor
 * Parameters: none
 * Pre-Conditions: location must exist
 * Post-Conditions: none
 * ************************/

Event* Location::get_event(){
   
   return e;

}

