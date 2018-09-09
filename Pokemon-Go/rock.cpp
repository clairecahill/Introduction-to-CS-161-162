/**************************
 * Program: rock.cpp
 * Author: claire cahill
 * Date: 5/22/17
 * Description: used for pokemon of rock type
 * Input: none
 * Output: message when close
 * ***********************/

#include "rock.h"

Rock::Rock(){

   name = "name";
   type = "Rock";
   num_capture = 0;
   chance = .75;
   stage = 0;

}
/************************
 * Function: non default constructor
 * Description: initializes values
 * Parameters: n, t, num, c, s
 * Pre-Conditions: pokemon and rock classes
 * Post-Conditions: values set
 * *********************/

Rock::Rock(string n, string t, int num, float c, int s){

   name = n;
   type = t;
   num_capture = num;
   chance = c;
   stage = s;

}

/****************************
 * Function: assign op overload
 * Description: assigns values 
 * Parameters: const Rock &other
 * Pre-Conditions: none
 * Post-Conditions: none
 * *****************************/

void Rock::operator = (const Rock &other){

   cout << "Rock assignment operator" << endl;
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

void Rock::message(){

   cout << "Capture the " << name << " nearby." << endl;

}
