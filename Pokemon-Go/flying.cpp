/***************************
 * Program flying.cpp
 * Author: claire cahill
 * Date: 5/22/17
 * Description: used for pokemon of flying type
 * Input: constructor
 * Output: message when nearby
 * ************************/

#include "flying.h"

/*************************
 * Function: non default constructor
 * Description: initializes values
 * Parameters: n, t, num, c, s
 * Pre-Conditions: pokemon and flying classes
 * Post-Conditions: values exist for pokemon
 * **********************/

Flying::Flying(string n, string t, int num, float c, int s){

   name = n;
   type = t;
   num_capture = num;
   chance = c;
   stage = s;

}

/*************************
 * Function: assign op overload
 * Desription: assigns values
 * Parameters: &other
 * Pre-Conditions: none
 * Post-Conditions: none
 * **********************/

void Flying::operator = (const Flying &other){

   name = other.name;
   type = other.type;
   num_capture = other.num_capture;
   chance = other.chance;
   stage = other.stage;
}

/************************
 * Function: message
 * Description: inherited pokemon function
 * Parameters: none
 * Pre-Conditions: location class
 * Post-Conditions: none
 * *********************/

void Flying::message(){

   cout << "Capture the " << name << " nearby." << endl;

}
