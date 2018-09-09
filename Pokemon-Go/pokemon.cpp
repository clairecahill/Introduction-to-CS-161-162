/**************************
 * Program: pokemon.cpp
 * Author: claire cahill
 * Date: 5/22/17
 * Description: class for each type of pokemon
 * Input: none
 * Output: message when close to location
 * **********************/

#include "pokemon.h"

/************************
 * Function: constructor
 * Description: initializes values
 * Parameters: none
 * Pre-Conditions: variables declared in .h file
 * Post-Conditions: none
 * ********************/

Pokemon::Pokemon(){

   name = "Pokemon";
   type = "Rock";
   num_capture = 0;
   chance = .75;
   stage = 0;

}

/************************
 * Function: non default constructor
 * Description: initializes values
 * Parameters: none
 * Pre-Conditions: variables declared in .h file
 * Post-Conditions: none
 * ********************/

Pokemon::Pokemon(string n, string t, int num, float c, int s){

   name = n;
   type = t;
   num_capture = num;
   chance = c; 
   stage = s;

}

/****************************
 * Function: copy constructor
 * Description: copies values 
 * Parameters: const Pokemon &other
 * Pre-Conditions: none
 * Post-Conditions: none
 * *****************************/

Pokemon::Pokemon(const Pokemon &other){

   name = other.name;
   type = other.type;
   num_capture = other.num_capture;
   chance = other.chance;
   stage = other.stage;
}

/****************************
 * Function: assign op overload
 * Description: copies values 
 * Parameters: const Pokemon &other
 * Pre-Conditions: none
 * Post-Conditions: none
 * *****************************/

void Pokemon::operator = (const Pokemon &other){

   cout << "enter pokemon assignment overload" << endl;
   name = other.name;
   type = other.type;
   num_capture = other.num_capture;
   chance = other.chance;
   stage = other.stage;
}

/****************************
 * Function: destructor
 * Description: no dynamic memory
 * Parameters: const Pokemon &other
 * Pre-Conditions: none
 * Post-Conditions: none
 * *****************************/

Pokemon::~Pokemon(){

}

/*********************
 * Function: set_name
 * Description: name modifier
 * Parameters: string s
 * Pre-Conditions: pokemon class must exist
 * Post-Conditions: none
 * ******************/

void Pokemon::set_name(string s){

   name = s;

}

/*********************
 * Function: set_type
 * Description: type modifier
 * Parameters: string s
 * Pre-Conditions: pokemon must exist
 * Post-Conditions: none
 * ******************/

void Pokemon::set_type(string s){

   type = s;

}

/*********************
 * Function: set_num_capture
 * Description: num_capture modifier
 * Parameters: int x
 * Pre-Conditions: pokemon must exist
 * Post-Conditions: none
 * ******************/

void Pokemon::set_num_capture(int x){

   num_capture = x;

}

/*********************
 * Function: set_chance
 * Description: chance modifier
 * Parameters: float f
 * Pre-Conditions: pokemon must exist
 * Post-Conditions: none
 * ******************/

void Pokemon::set_chance(float f){

   chance = f;

}

/*********************
 * Function: set_stage
 * Description: stage modifier
 * Parameters: int x
 * Pre-Conditions: pokemon must exist
 * Post-Conditions: none
 * ******************/

void Pokemon::set_stage(int x){

   stage = x;

}

/*********************
 * Function: get_name
 * Description: name getter
 * Parameters: none
 * Pre-Conditions: pokemon class must exist
 * Post-Conditions: none
 * ******************/

string Pokemon::get_name(){

   return name;

}

/*********************
 * Function: get_type
 * Description: type getter
 * Parameters: none
 * Pre-Conditions: type must exist in pokemon
 * Post-Conditions: none
 * ******************/

string Pokemon::get_type(){

   return type;

}

/*********************
 * Function: get_num_capture
 * Description: num_capture getter
 * Parameters: none
 * Pre-Conditions: variable must exist in pokemon class
 * Post-Conditions: none
 * ******************/

int Pokemon::get_num_capture(){

   return num_capture;

}

/*********************
 * Function: get_chance
 * Description: chance getter 
 * Parameters: none
 * Pre-Conditions: chance must exist in pokemon class
 * Post-Conditions: none
 * ******************/

float Pokemon::get_chance(){

   return chance;

}

/*********************
 * Function: get_stage
 * Description: stage getter
 * Parameters: none
 * Pre-Conditions: stage must exist in pokemon class
 * Post-Conditions: none
 * ******************/

int Pokemon::get_stage(){

   return stage;

}

/*********************
 * Function: message
 * Description: prints statement
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * ******************/

void Pokemon::message(){

   cout << "Capture the " << name << " nearby." << endl;

}

